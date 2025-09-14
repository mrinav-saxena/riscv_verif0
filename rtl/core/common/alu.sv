`ifndef ALU_SV
`define ALU_SV

module alu #(
    parameter int DATA_WIDTH = 32
) (
    input logic [DATA_WIDTH-1:0] a_i,
    input logic [DATA_WIDTH-1:0] b_i,
    input rv32i_base_instr_type instr_type_i,
    input rv32i_base_instr opcode_i,
    output logic [DATA_WIDTH-1:0] result_o,
    output logic eq_o,
    output logic lt_o,
    output logic ltu_o
) ;

    alu_op_type alu_ctrl;
    
    // ALU control logic moved from single_cycle_core
    assign alu_ctrl = 
        (instr_type_i == R || instr_type_i == I) ?
            (opcode_i == ADD || opcode_i == ADDI) ? ALU_ADD :
            (opcode_i == SUB || opcode_i == SLT || opcode_i == SLTI || opcode_i == SLTU || opcode_i == SLTIU) ? ALU_SUB :
            (opcode_i == AND || opcode_i == ANDI) ? ALU_AND :
            (opcode_i == OR || opcode_i == ORI) ? ALU_OR :
            (opcode_i == XOR || opcode_i == XORI) ? ALU_XOR :
            (opcode_i == SLL || opcode_i == SLLI) ? ALU_SHFT_L :
            (opcode_i == SRL || opcode_i == SRLI) ? ALU_SHFT_R_LG :
            (opcode_i == SRA || opcode_i == SRAI) ? ALU_SHFT_R_AR :
            ALU_ADD :
        (instr_type_i == B) ?
            (opcode_i == BEQ || opcode_i == BNE || opcode_i == BLT || opcode_i == BGE || opcode_i == BLTU || opcode_i == BGEU) ? ALU_SUB :
            ALU_ADD :
        ALU_ADD
    ;

    assign eq_o = (alu_ctrl == ALU_SUB) ? (a_i == b_i) : 1'b0;
    assign ltu_o = (alu_ctrl == ALU_SUB) ? (a_i < b_i) : 1'b0;

    always @(*) begin
        case (alu_ctrl)
            ALU_ADD: result_o = a_i + b_i;
            ALU_SUB: begin
                result_o = a_i - b_i;
                lt_o = (alu_ctrl == ALU_SUB) ? result_o[DATA_WIDTH-1] : 1'b0;
                case (opcode_i)
                    SLT, SLTI: result_o = {{(DATA_WIDTH-1){1'b0}}, lt_o};
                    SLTU, SLTIU: result_o = {{(DATA_WIDTH-1){1'b0}}, ltu_o};
                    default: ; // result_o already computed as a_i - b_i
                endcase
            end
            ALU_AND: result_o = a_i & b_i;
            ALU_OR: result_o = a_i | b_i;
            ALU_XOR: result_o = a_i ^ b_i;
            ALU_SHFT_L: result_o = a_i << b_i[$clog2(DATA_WIDTH)-1:0];
            ALU_SHFT_R_LG: result_o = a_i >> b_i[$clog2(DATA_WIDTH)-1:0];
            ALU_SHFT_R_AR: result_o = a_i >>> b_i[$clog2(DATA_WIDTH)-1:0];
            default: result_o = '0;
        endcase
    end

endmodule

`endif
