`ifndef IFIDEX_STAGE_SV
`define IFIDEX_STAGE_SV

module ifidex_stage #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (

    input  logic clk ,
    input  logic rst_n ,

    output logic [ADDR_WIDTH-1:0] pc_o ,
    output logic read_instr_o ,
    input  logic [DATA_WIDTH-1:0] instr_i ,
    input  logic instr_ready_i ,

) ;



endmodule : ifidex_stage

`endif