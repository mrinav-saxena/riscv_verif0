`ifndef DMEM_INPUT_AND_CTRL_LOGIC_SV
`define DMEM_INPUT_AND_CTRL_LOGIC_SV

module dmem_input_and_ctrl_logic #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (
    input rv32i_base_instr opcode_e,
    input rv32i_base_instr_type instr_type,
    input logic [DATA_WIDTH-1:0] rs2_data,
    input logic [DATA_WIDTH-1:0] alu_result,

    output logic [DATA_WIDTH-1:0] dmem_addr,
    output logic dmem_read,
    output logic dmem_write,
    output logic [DATA_WIDTH-1:0] dmem_wdata,
    output logic [DATA_WIDTH/8-1:0] dmem_wstrb
) ;

    assign dmem_addr = alu_result;

    assign dmem_read = (opcode_e inside {LB, LH, LW, LBU, LHU}) ;

    assign dmem_write = (instr_type == S) ;
    assign dmem_wstrb =
        (opcode_e == SB) ? (1'b1 << alu_result[1:0]) :
        (opcode_e == SH) ? (2'b11 << (alu_result[1]*2)) : 
        (opcode_e == SW) ? {DATA_WIDTH/8{1'b1}} :
        {DATA_WIDTH/8{1'b0}}
    ;
    assign dmem_wdata = rs2_data << (
        opcode_e == SB ? (alu_result[1:0] * 8) :
        opcode_e == SH ? (alu_result[1] * 16) :
        0 // for SW or otherwise
    );

endmodule : dmem_input_and_ctrl_logic

`endif