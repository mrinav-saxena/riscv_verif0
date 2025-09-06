`ifndef ALU_INPUT_LOGIC_SV
`define ALU_INPUT_LOGIC_SV

module alu_input_logic #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (
    input logic [ADDR_WIDTH-1:0] pc,
    input rv32i_base_instr opcode_e,
    input rv32i_base_instr_type instr_type,
    input logic [DATA_WIDTH-1:0] rs1_data,
    input logic [DATA_WIDTH-1:0] rs2_data,
    input logic [DATA_WIDTH-1:0] imm_value,
    output logic [DATA_WIDTH-1:0] alu_src_a,
    output logic [DATA_WIDTH-1:0] alu_src_b
) ;

    logic alu_imm_source ;
    assign alu_imm_source = instr_type inside {I, S, U, J} ; // B uses imm data, but not in the ALU

    assign alu_src_a = (opcode_e == AUIPC) ? pc : rs1_data ;
    assign alu_src_b = alu_imm_source ? imm_value : rs2_data ;

endmodule : alu_input_logic

`endif