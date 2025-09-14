`ifndef ALU_INPUT_LOGIC_SV
`define ALU_INPUT_LOGIC_SV

module alu_input_logic #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (
    input logic [ADDR_WIDTH-1:0] pc_i,
    input rv32i_base_instr opcode_i,
    input rv32i_base_instr_type instr_type_i,
    input logic [DATA_WIDTH-1:0] rs1_data_i,
    input logic [DATA_WIDTH-1:0] rs2_data_i,
    input logic [DATA_WIDTH-1:0] imm_value_i,
    output logic [DATA_WIDTH-1:0] alu_src_a_o,
    output logic [DATA_WIDTH-1:0] alu_src_b_o
) ;

    logic alu_imm_source ;
    assign alu_imm_source = instr_type_i inside {I, S, U, J} ; // B uses imm data, but not in the ALU

    assign alu_src_a_o = (opcode_i == AUIPC) ? pc_i : rs1_data_i ;
    assign alu_src_b_o = alu_imm_source ? imm_value_i : rs2_data_i ;

endmodule : alu_input_logic

`endif