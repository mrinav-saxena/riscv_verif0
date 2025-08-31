`ifndef ALU_SV
`define ALU_SV

module alu #(
    parameter int DATA_WIDTH = 32
) (
    input logic [DATA_WIDTH-1:0] a,
    input logic [DATA_WIDTH-1:0] b,
    input rv32i_base_instr_type instr_type,
    input rv32i_base_instr opcode_e,
    output logic [DATA_WIDTH-1:0] result,
    output logic eq,
    output logic lt,
    output logic ltu
) ;

    alu_op_type alu_ctrl;
    
    // ALU control logic moved from single_cycle_core
    assign alu_ctrl = 
      (instr_type == R || instr_type == I) ?
        (opcode_e == ADD || opcode_e == ADDI) ? ALU_ADD :
        (opcode_e == SUB || opcode_e == SLT || opcode_e == SLTI || opcode_e == SLTU || opcode_e == SLTIU) ? ALU_SUB :
        (opcode_e == AND || opcode_e == ANDI) ? ALU_AND :
        (opcode_e == OR || opcode_e == ORI) ? ALU_OR :
        (opcode_e == XOR || opcode_e == XORI) ? ALU_XOR :
        (opcode_e == SLL || opcode_e == SLLI) ? ALU_SHFT_L :
        (opcode_e == SRL || opcode_e == SRLI) ? ALU_SHFT_R_LG :
        (opcode_e == SRA || opcode_e == SRAI) ? ALU_SHFT_R_AR :
        ALU_ADD :
      (instr_type == B) ?
        (opcode_e == BEQ || opcode_e == BNE || opcode_e == BLT || opcode_e == BGE || opcode_e == BLTU || opcode_e == BGEU) ? ALU_SUB :
        ALU_ADD :
      ALU_ADD
    ;

    assign eq = (alu_ctrl == ALU_SUB) ? (a == b) : 1'b0;
    assign ltu = (alu_ctrl == ALU_SUB) ? (a < b) : 1'b0;

    always @(*) begin
        case (alu_ctrl)
            ALU_ADD: result = a + b;
            ALU_SUB: begin
                result = a - b;
                lt = (alu_ctrl == ALU_SUB) ? result[DATA_WIDTH-1] : 1'b0;
                case (opcode_e)
                    SLT, SLTI: result = {{(DATA_WIDTH-1){1'b0}}, lt};
                    SLTU, SLTIU: result = {{(DATA_WIDTH-1){1'b0}}, ltu};
                    default: ; // result already computed as a - b
                endcase
            end
            ALU_AND: result = a & b;
            ALU_OR: result = a | b;
            ALU_XOR: result = a ^ b;
            ALU_SHFT_L: result = a << b[$clog2(DATA_WIDTH)-1:0];
            ALU_SHFT_R_LG: result = a >> b[$clog2(DATA_WIDTH)-1:0];
            ALU_SHFT_R_AR: result = a >>> b[$clog2(DATA_WIDTH)-1:0];
            default: result = '0;
        endcase
    end

endmodule

`endif
