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

    logic [ADDR_WIDTH-1:0] pc;
    logic read_instr;
    logic [DATA_WIDTH-1:0] instr;
    logic instr_ready_i;

    logic [ADDR_WIDTH-1:0] dmem_addr;
    logic [DATA_WIDTH-1:0] dmem_wdata;
    logic [DATA_WIDTH/8-1:0] dmem_wstrb;
    logic dmem_write;
    logic dmem_read;
    logic [DATA_WIDTH-1:0] dmem_rdata;
    logic dmem_ready;

    stall_for_mem_core #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .clk       (clk),
        .rst_n     (rst_n),
        .pc        (pc),
        .read_instr (read_instr),
        .instr_i (instr),
        .instr_ready_i (instr_ready_i),
        .dmem_addr (dmem_addr),
        .dmem_wstrb (dmem_wstrb),
        .dmem_wdata (dmem_wdata),
        .dmem_write (dmem_write),
        .dmem_read (dmem_read),
        .dmem_rdata (dmem_rdata),
        .dmem_ready (dmem_ready)
    );

    mem_nzlat #(
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(IMEM_DEPTH),
        .READ_LATENCY(5),
        .WRITE_LATENCY(5)
    ) i_imem (
        .clk    (clk),
        .rst_n  (rst_n),
        .addr   (pc[$clog2(IMEM_DEPTH)+1:2]),
        .wdata  ({DATA_WIDTH{1'b0}}),
        .wstrb  ({DATA_WIDTH/8{1'b0}}),
        .write  (1'b0),
        .read   (read_instr),
        .rdata  (instr),
        .ready  (instr_ready_i)
    );

    /*
    mem_zerolat #(
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(DMEM_DEPTH)
    ) i_dmem (
        .clk    (clk),
        .rst_n  (rst_n),
        .addr   (dmem_addr[$clog2(DMEM_DEPTH)+1:2]),
        .wdata  (dmem_wdata),
        .wstrb  (dmem_wstrb),
        .write  (dmem_write),
        .read   (dmem_read),
        .rdata  (dmem_rdata)
    );
    */

    always @(posedge clk) begin
        /*
        if ((dut.opcode_e == SW) && (dut.rs2_data == 32'hdeadbeef)) begin
            deadbeef_written = 1'b1 ; 
            $display("[TB] 0xdeadbeef - test completed!", $time);
            repeat(5) @(posedge clk);
            $writememh("res_dmem.hex", i_dmem.mem_array, 0, DMEM_DEPTH) ;
            $finish;
        end else begin
            cycle_count ++ ;
            if (cycle_count % 100 == 0) begin
                $display("[TB] cycle_count is %0d. writing memory for debug purposes.", cycle_count);
                $writememh("res_dmem.hex", i_dmem.mem_array, 0, DMEM_DEPTH) ;
            end
        end
        */
    end
  
    // Load instruction memory and data memory from HEX files
    initial begin
        cycle_count = 0 ;
        @ (posedge rst_n);
        $readmemh("imem.hex", i_imem.mem_array);
        // $readmemh("dmem.hex", i_dmem.mem_array);
        $display("[TB] Loaded imem.hex and dmem.hex");
    end

endmodule

