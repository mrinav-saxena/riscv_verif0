`ifndef DMEM_INPUT_AND_CTRL_LOGIC_SV
`define DMEM_INPUT_AND_CTRL_LOGIC_SV

module dmem_input_and_ctrl_logic #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (
    input rv32i_base_instr opcode_i,
    input rv32i_base_instr_type instr_type_i,
    input logic [DATA_WIDTH-1:0] rs2_data_i,
    input logic [DATA_WIDTH-1:0] alu_result_i,

    output logic [DATA_WIDTH-1:0] dmem_addr_o,
    output logic dmem_read_o,
    output logic dmem_write_o,
    output logic [DATA_WIDTH-1:0] dmem_wdata_o,
    output logic [DATA_WIDTH/8-1:0] dmem_wstrb_o
) ;

    assign dmem_addr_o = alu_result_i;

    assign dmem_read_o = (opcode_i inside {LB, LH, LW, LBU, LHU}) ;

    assign dmem_write_o = (instr_type_i == S) ;
    assign dmem_wstrb_o =
        (opcode_i == SB) ? (1'b1 << alu_result_i[1:0]) :
        (opcode_i == SH) ? (2'b11 << (alu_result_i[1]*2)) : 
        (opcode_i == SW) ? {DATA_WIDTH/8{1'b1}} :
        {DATA_WIDTH/8{1'b0}}
    ;
    assign dmem_wdata_o = rs2_data_i << (
        opcode_i == SB ? (alu_result_i[1:0] * 8) :
        opcode_i == SH ? (alu_result_i[1] * 16) :
        0 // for SW or otherwise
    );

endmodule : dmem_input_and_ctrl_logic

`endif