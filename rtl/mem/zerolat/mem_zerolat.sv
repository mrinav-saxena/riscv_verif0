// mem_zerolat.sv
`ifndef MEM_ZEROLAT_SV
`define MEM_ZEROLAT_SV

module mem_zerolat #(
    parameter int DATA_WIDTH = 32,
    parameter int DEPTH = 1024,
    localparam int ADDR_WIDTH = $clog2(DEPTH)
)(
    input  logic clk,
    input  logic rst_n,
    input  logic [ADDR_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH-1:0] wdata,
    input  logic [DATA_WIDTH/8-1:0] wstrb,
    input  logic write,
    input  logic read,
    output logic [DATA_WIDTH-1:0] rdata
);

    logic [DATA_WIDTH-1:0] mem_array [DEPTH-1:0];
  
    assign rdata = read ? mem_array[addr] : {DATA_WIDTH{1'b0}};

    always @(posedge clk) begin
        if (!rst_n) begin
            for (int i = 0; i < DEPTH; i++) begin : i_reset_block
                mem_array[i] <= '0;
            end
        end else if (write) begin
            for (int i = 0; i < DATA_WIDTH/8; i++) begin : i_write_block
                if (wstrb[i]) begin
                    mem_array[addr][i*8 +: 8] <= wdata[i*8 +: 8];
                end
            end
        end
    end

endmodule

`endif // MEM_ZEROLAT_SV
