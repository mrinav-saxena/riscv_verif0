// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing declarations
#include "verilated_fst_c.h"


void Vtb___024root__traceDeclTypesSub0(VerilatedFst* tracep) {
    {
        const char* __VenumItemNames[]
        = {"NOP", "LUI", "AUIPC", "JAL", "JALR", "BEQ", 
                                "BNE", "BLT", "BGE", 
                                "BLTU", "BGEU", "LB", 
                                "LH", "LW", "LBU", 
                                "LHU", "SB", "SH", 
                                "SW", "ADDI", "SLTI", 
                                "SLTIU", "XORI", "ORI", 
                                "ANDI", "SLLI", "SRLI", 
                                "SRAI", "ADD", "SUB", 
                                "SLL", "SLT", "SLTU", 
                                "XOR", "SRL", "SRA", 
                                "OR", "AND", "FENCE", 
                                "FENCE_TSO", "PAUSE", 
                                "ECALL", "EBREAK"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111", "1000", "1001", 
                                "1010", "1011", "1100", 
                                "1101", "1110", "1111", 
                                "10000", "10001", "10010", 
                                "10011", "10100", "10101", 
                                "10110", "10111", "11000", 
                                "11001", "11010", "11011", 
                                "11100", "11101", "11110", 
                                "11111", "100000", 
                                "100001", "100010", 
                                "100011", "100100", 
                                "100101", "100110", 
                                "100111", "101000", 
                                "101001", "101010"};
        tracep->declDTypeEnum(1, "$unit::rv32i_base_instr", 43, 32, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"R", "I", "S", "B", "U", "J", "MEM_ORD", 
                                "SYSTEM", "UNKNOWN"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111", "1000"};
        tracep->declDTypeEnum(2, "$unit::rv32i_base_instr_type", 9, 32, __VenumItemNames, __VenumItemValues);
    }
    {
        const char* __VenumItemNames[]
        = {"ALU_ADD", "ALU_SUB", "ALU_AND", "ALU_OR", 
                                "ALU_XOR", "ALU_SHFT_L", 
                                "ALU_SHFT_R_LG", "ALU_SHFT_R_AR"};
        const char* __VenumItemValues[]
        = {"0", "1", "10", "11", "100", "101", "110", 
                                "111"};
        tracep->declDTypeEnum(3, "$unit::alu_op_type", 8, 32, __VenumItemNames, __VenumItemValues);
    }
}

void Vtb___024root__trace_decl_types(VerilatedFst* tracep) {
    Vtb___024root__traceDeclTypesSub0(tracep);
}
