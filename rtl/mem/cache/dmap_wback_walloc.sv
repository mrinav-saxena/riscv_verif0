`ifndef CACHE_DMAP_WB_WALLOC_SV
`define CACHE_DMAP_WB_WALLOC_SV

module dmap_wback_walloc #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int DEPTH = 32
) (
    input logic clk,
    input logic rst_n

    input logic [ADDR_WIDTH-1:0] core_addr_i ,
    input logic [DATA_WIDTH-1:0] core_wdata_i ,
    input logic core_write_i,
    input logic [DATA_WIDTH/8-1:0] core_wstrb_i ,
    input logic core_read_i ,
    output  logic [DATA_WIDTH-1:0] core_rdata_o ,
    output  logic core_ready_o,

    output logic [ADDR_WIDTH-1:0] dmem_addr_o ,
    output logic [DATA_WIDTH-1:0] dmem_wdata_o ,
    output logic dmem_write_o,
    output logic [DATA_WIDTH/8-1:0] dmem_wstrb_o ,
    output logic dmem_read_o ,
    input  logic [DATA_WIDTH-1:0] dmem_rdata_i ,
    input  logic dmem_ready_i

) ;

    logic valid [DEPTH-1:0] ;
    logic dirty [DEPTH-1:0] ;
    logic [ADDR_WIDTH-1:$clog2(DEPTH)+2] tag [DEPTH-1:0]  ;
    logic [DATA_WIDTH-1:0] mem_array [DEPTH-1:0] ;

    logic [$clog(DEPTH)+1:2] index ;
    logic in_cache ;

    assign index = core_addr_i[$clog(DEPTH)+1:2] ;
    assign in_cache = (core_addr_i[ADDR_WIDTH-1:$clog2(DEPTH)+2] == tag[index]) && (valid[index]) ;


endmodule : dmap_wback_walloc

`endif