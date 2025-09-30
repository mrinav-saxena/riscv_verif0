interface cache_core_if (input logic clk, input logic rst_n) ;

    logic [31:0] core_addr ;
    logic [31:0] core_wdata ;
    logic core_write ;
    logic [3:0] core_wstrb ;
    logic core_read ;
    logic [31:0] core_rdata ;
    logic core_ready ;

endinterface : cache_core_if
