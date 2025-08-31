`ifndef TYPES_SV
`define TYPES_SV

typedef enum {
    NOP,
    LUI,
    AUIPC,
    JAL,
    JALR,
    BEQ,
    BNE,
    BLT,
    BGE,
    BLTU,
    BGEU,
    LB,
    LH,
    LW,
    LBU,
    LHU,
    SB,
    SH,
    SW,
    ADDI,
    SLTI,
    SLTIU,
    XORI,
    ORI,
    ANDI,
    SLLI,
    SRLI,
    SRAI,
    ADD,
    SUB,
    SLL,
    SLT,
    SLTU,
    XOR,
    SRL,
    SRA,
    OR,
    AND,
    FENCE,
    FENCE_TSO,
    PAUSE,
    ECALL,
    EBREAK
} rv32i_base_instr ;



function automatic rv32i_base_instr instr_enum_from_val (logic [31:0] instr) ;
    case (instr[6:0])
        7'b0110111 : return LUI;
        7'b0010111 : return AUIPC;
        7'b1101111 : return JAL;
        7'b1100111 : begin
            case (instr[14:12])
                3'b000 : return JALR;
                default : return NOP;
            endcase
        end
        7'b1100011 : begin
            case (instr[14:12])
                3'b000 : return BEQ;
                3'b001 : return BNE;
                3'b100 : return BLT;
                3'b101 : return BGE;
                3'b110 : return BLTU;
                3'b111 : return BGEU;
                default : return NOP;
            endcase
        end
        7'b0000011 : begin
            case (instr[14:12])
                3'b000 : return LB;
                3'b001 : return LH;
                3'b010 : return LW;
                3'b100 : return LBU;
                3'b101 : return LHU;
                default : return NOP;
            endcase
        end
        7'b0100011 : begin
            case (instr[14:12])
                3'b000 : return SB;
                3'b001 : return SH;
                3'b010 : return SW;
                default : return NOP;
            endcase
        end
        7'b0010011 : begin
            case (instr[14:12])
                3'b000 : return ADDI;
                3'b001 : return SLLI;
                3'b010 : return SLTI;
                3'b011 : return SLTIU;
                3'b100 : return XORI;
                3'b101 : begin
                    case (instr[31:25])
                        7'b0000000 : return SRLI;
                        7'b0100000 : return SRAI;
                        default : return NOP;
                    endcase
                end
                3'b110 : return ORI;
                3'b111 : return ANDI;
                default : return NOP;
            endcase
        end
        7'b0110011 : begin
            case (instr[14:12])
                3'b000 : begin
                    case (instr[31:25])
                        7'b0000000 : return ADD;
                        7'b0100000 : return SUB;
                        default : return NOP;
                    endcase
                end
                3'b001 : begin
                    case (instr[31:25])
                        7'b0000000 : return SLL;
                        default : return NOP;
                    endcase
                end
                3'b010 : begin
                    case (instr[31:25])
                        7'b0000000 : return SLT;
                        default : return NOP;
                    endcase
                end
                3'b011 : begin
                    case (instr[31:25])
                        7'b0000000 : return SLTU;
                        default : return NOP;
                    endcase
                end
                3'b100 : begin
                    case (instr[31:25])
                        7'b0000000 : return XOR;
                        default : return NOP;
                    endcase
                end
                3'b101 : begin
                    case (instr[31:25])
                        7'b0000000 : return SRL;
                        7'b0100000 : return SRA;
                        default : return NOP;
                    endcase
                end
                3'b110 : begin
                    case (instr[31:25])
                        7'b0000000 : return OR;
                        default : return NOP;
                    endcase
                end
                3'b111 : begin
                    case (instr[31:25])
                        7'b0000000 : return AND;
                        default : return NOP;
                    endcase
                end
            endcase
        end
        7'b0001111 : begin
            case (instr[31:7])
                25'h1066000 : return FENCE_TSO;
                25'h0020000 : return PAUSE;
                default : begin
                    case (instr[14:12])
                        3'b000 : return FENCE;
                        default : return NOP;
                    endcase
                end
            endcase
        end
        7'b1110011 : begin
            case (instr[31:7])
                25'h0000000 : return ECALL;
                25'h0002000 : return EBREAK;
                default : return NOP;
            endcase
        end
        default : return NOP;
    endcase
endfunction : instr_enum_from_val

typedef enum {R, I, S, B, U, J, MEM_ORD, SYSTEM, UNKNOWN} rv32i_base_instr_type ;

function automatic rv32i_base_instr_type instr_type_enum_from_instr (rv32i_base_instr instr_opcode) ;
    case (instr_opcode)
        NOP : return UNKNOWN;
        LUI, AUIPC : return U;
        JAL : return J;
        JALR, LB, LH, LW, LBU, LHU, ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI : return I;
        BEQ, BNE, BLT, BGE, BLTU, BGEU : return B;
        ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND : return R;
        SB, SH, SW : return S;
        FENCE, FENCE_TSO, PAUSE : return MEM_ORD;
        ECALL, EBREAK : return SYSTEM;
        default : return UNKNOWN;
    endcase
endfunction : instr_type_enum_from_instr


typedef enum {
    ALU_ADD,
    ALU_SUB,
    ALU_AND,
    ALU_OR,
    ALU_XOR,
    ALU_SHFT_L,
    ALU_SHFT_R_LG,
    ALU_SHFT_R_AR
} alu_op_type ;

`endif
