#include <stdint.h>
#include <stddef.h>

#define VOL volatile

/* ---- Scratch RAM for loads/stores ------ */
VOL uint8_t  bbuf[16] = {0x78, 0x56, 0x34, 0x12, 0xaa, 0xbb, 0xcc, 0xdd};
VOL uint16_t hbuf[8]  = {0x5678, 0x1234, 0xabcd, 0x0, 0xffff, 0x8000, 0x7fff, 0x1111};
VOL uint32_t wbuf[8]  = {0x12345678u, 0xdeadbeefu, 0, 0, 0, 0, 0, 0};

/* ---- Result area (so you can inspect memory) ---- */
VOL uint32_t results[64];

/* ---- Completion signal for testbench monitoring ---- */
VOL uint32_t test_complete = 0;

/* ---- Inline asm helpers for the "hard-to-force" ops ---- */
static inline void do_fence(void)    { __asm__ __volatile__("fence" ::: "memory"); }
static inline void do_ebreak(void)   { __asm__ __volatile__("ebreak"); }
static inline void do_ecall(void)    { __asm__ __volatile__("ecall"); }
#ifdef ENABLE_ZIFENCEI
static inline void do_fence_i(void)  { __asm__ __volatile__("fence.i"); }
#endif

/* Force a raw LUI into a register (large const) */
static inline uint32_t force_lui(void) {
    uint32_t x;
    __asm__ __volatile__(
        "lui %0, 0x12345\n"
        "addi %0, %0, 0x6"    /* keep it used */
        : "=r"(x) ::);
    return x;
}

/* Indirect call to ensure JALR happens */
static int callee(int a, int b) { return (a ^ b) + (a & b) - (a | b); }

/* ---- A function that will be called to force JAL on entry, JALR on return ---- */
static int do_alu_suite(int x, int y)
{
    // R-type: add, sub, and, or, xor, sll, srl, sra, slt, sltu
    int add  = x + y;
    int sub  = x - y;
    int band = x & y;
    int bor  = x | y;
    int bxor = x ^ y;
    int sll  = x << (y & 31);
    int srl  = ((uint32_t)x) >> (y & 31);
    int sra  = x >> (y & 31);
    int slt  = (x < y) ? 1 : 0;
    int sltu = ((uint32_t)x < (uint32_t)y) ? 1 : 0;

    // I-type ALU: addi, andi, ori, xori, slli, srli, srai, slti, sltiu
    int addi  = x + 10;                // addi
    int andi  = x & 0x0F;              // andi
    int ori   = x | 0xF0;              // ori
    int xori  = x ^ 0xFF;              // xori
    int slli  = x << 2;                // slli
    int srli  = ((uint32_t)x) >> 1;    // srli
    int srai  = x >> 1;                // srai
    int slti  = (x < 20) ? 1 : 0;      // compilers commonly emit slti
    int sltiu = (((uint32_t)x) < 5U) ? 1 : 0; // commonly sltiu

    // Mix them so compiler keeps everything
    int acc = 0;
    acc += add + sub + band + bor + bxor;
    acc += sll + srl + sra + slt + sltu;
    acc += addi + andi + ori + xori + slli + srli + srai + slti + sltiu;
    return acc;
}

/* ---- Branch zoo: try to cover beq,bne,blt,bge,bltu,bgeu ---- */
static int branch_suite(uint32_t a, uint32_t b)
{
    int c = 0;
    if ((int)a == (int)b) c++;       // likely beq
    if ((int)a != (int)b) c++;       // likely bne
    if ((int)a <  (int)b) c++;       // blt
    if ((int)a >= (int)b) c++;       // bge
    if (a < b)              c++;     // bltu
    if (a >= b)             c++;     // bgeu

    // A small loop to generate backward/forward branches
    for (int i = 0; i < 4; ++i) {    // generates bne or blt as loop condition
        c += i;
    }
    return c;
}

/* ---- Loads/stores of each size + signed/unsigned ---- */
static void load_store_suite(void)
{
    // loads
    uint32_t lb  = (int8_t)  bbuf[0];
    uint32_t lh  = (int16_t) hbuf[0];
    uint32_t lw  = wbuf[0];
    uint32_t lbu = (uint8_t) bbuf[1];
    uint32_t lhu = (uint16_t)hbuf[1];

    results[0] = lb;
    results[1] = lh;
    results[2] = lw;
    results[3] = lbu;
    results[4] = lhu;

    // stores
    bbuf[2] = (uint8_t)lb;        // sb
    hbuf[2] = (uint16_t)lh;       // sh
    wbuf[2] = lw + lbu + lhu;     // sw
}

/* ---- Force AUIPC by taking the address of a nearby symbol ---- */
static uint32_t force_auipc_addi(void)
{
    extern uint8_t __here;             // local label symbol
    __asm__ __volatile__(".globl __here\n__here:\n");
    uintptr_t p = (uintptr_t)&__here;  // compilers typically emit auipc+addi for PC-rel addr
    return (uint32_t)p;
}

/* ---- Indirect call to force JALR (and returns also use JALR on RV32I) ---- */
static int call_indirect(int (*fp)(int,int), int a, int b) {
    return fp(a, b); // jalr
}

/* ---- Main: orchestrates everything and leaves breadcrumbs in results[] ---- */
int main(void)
{
    do_fence();

    // Make sure LUI appears (large const), keep the value
    uint32_t L = force_lui();
    results[10] = L;

    // AUIPC (pc-relative address acquire)
    uint32_t P = force_auipc_addi();
    results[11] = P;

#ifdef ENABLE_ZIFENCEI
    do_fence_i();
#endif

    // ALU suites
    int a = 0x12345678;
    int b = 0x00F0F00F;
    int acc = do_alu_suite(a, b);
    results[12] = (uint32_t)acc;

    // Branch zoo
    int br = branch_suite(0x80000000u, 0x7fffffffu);
    results[13] = (uint32_t)br;

    // Loads/stores
    load_store_suite();
    results[14] = wbuf[2];

    // Direct call (JAL) + indirect call (JALR)
    int d1 = callee(7, 3);                 // jal to callee
    int d2 = call_indirect(callee, 11, 5); // jalr via function pointer
    results[15] = (uint32_t)(d1 + d2);

    // A couple more ALU immediates to be safe
    int x = 42;
    results[16] = (uint32_t)((x | 0x123) ^ 0x7);   // ori/xori
    results[17] = (uint32_t)((x & 0x3f) << 1);     // andi/slli
    results[18] = (uint32_t)(((uint32_t)x) >> 2);  // srli

    // Test sign extension edge cases
    int8_t neg_byte = -1;
    uint32_t sign_ext = (int32_t)neg_byte;  // Should test lb sign extension
    results[19] = sign_ext;

    // Test unsigned comparison edge cases
    uint32_t max_u32 = 0xFFFFFFFF;
    uint32_t min_u32 = 0x00000000;
    results[20] = (max_u32 > min_u32) ? 1 : 0;  // Should test sltu

    do_ecall();   // trap to environment (place near end)
    do_ebreak();  // breakpoint (place last if your core halts on it)

    // Signal completion to testbench
    test_complete = 0xDEADBEEF;

    return 0;
}
