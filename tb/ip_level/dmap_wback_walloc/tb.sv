module tb # (
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int IMEM_DEPTH = 1024,
    parameter int DMEM_DEPTH = 1024
) (
    input logic clk,
    input logic rst_n
) ;

    bit deadbeef_written = 1'b0;
    integer cycle_count ;

    mem_nzlat #(
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(IMEM_DEPTH),
        .READ_LATENCY(5),
        .WRITE_LATENCY(5)
    ) i_imem (
        .clk    (),
        .rst_n  (),
        .addr   (),
        .wdata  (),
        .wstrb  (),
        .write  (),
        .read   (),
        .rdata  (),
        .ready  ()
    );

endmodule

