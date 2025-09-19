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
    logic instr_ready;

    logic [ADDR_WIDTH-1:0] dmem_addr;
    logic [DATA_WIDTH-1:0] dmem_wdata;
    logic [DATA_WIDTH/8-1:0] dmem_wstrb;
    logic dmem_write;
    logic dmem_read;
    logic [DATA_WIDTH-1:0] dmem_rdata;
    logic dmem_ready;

    stall4mem_pip_core #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .clk       (clk),
        .rst_n     (rst_n),
        .pc        (pc),
        .read_instr_o (read_instr),
        .instr_i (instr),
        .instr_ready_i (instr_ready),
        .dmem_addr_o (dmem_addr),
        .dmem_wstrb_o (dmem_wstrb),
        .dmem_wdata_o (dmem_wdata),
        .dmem_write_o (dmem_write),
        .dmem_read_o (dmem_read),
        .dmem_rdata_i (dmem_rdata),
        .dmem_ready_i (dmem_ready)
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
        .ready  (instr_ready)
    );
    
    mem_nzlat #(
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(DMEM_DEPTH),
        .READ_LATENCY(5),
        .WRITE_LATENCY(5)
    ) i_dmem (
        .clk    (clk),
        .rst_n  (rst_n),
        .addr   (dmem_addr[$clog2(DMEM_DEPTH)+1:2]),
        .wdata  (dmem_wdata),
        .wstrb  (dmem_wstrb),
        .write  (dmem_write),
        .read   (dmem_read),
        .rdata  (dmem_rdata),
        .ready  (dmem_ready)
    );

    always @(posedge clk) begin
        if ((dut.opcode_e == SW) && (dut.rs2_data == 32'hdeadbeef)) begin
            deadbeef_written = 1'b1 ; 
            $display("[TB] 0xdeadbeef - test completed!", $time);
            @(posedge dmem_write) ;
            @(posedge dmem_ready) ;
            $writememh("res_dmem.hex", i_dmem.mem_array, 0, DMEM_DEPTH) ;
            $finish;
        end else begin
            cycle_count ++ ;
            if (cycle_count % 1000 == 0) begin
                $display("[TB] cycle_count is %0d. writing memory for debug purposes.", cycle_count);
                $writememh("res_dmem.hex", i_dmem.mem_array, 0, DMEM_DEPTH) ;
            end
        end
    end

    always @(posedge dut.ifidex_complete) begin
        pc_seq_fh = $fopen("pc_seq.hex", "a");
        if (pc_seq_fh == 0) begin
            $display("[TB] Failed to open pc_seq.hex");
            $finish;
        end
        $fdisplay(pc_seq_fh, "%h", dut.pc);
        $fclose(pc_seq_fh);
    end
  
    integer pc_seq_fh ;

    // Load instruction memory and data memory from HEX files
    initial begin
        cycle_count = 0 ;
        @ (posedge rst_n);
        $readmemh("imem.hex", i_imem.mem_array);
        $readmemh("dmem.hex", i_dmem.mem_array);
        $display("[TB] Loaded imem.hex and dmem.hex");
        pc_seq_fh = $fopen ("pc_seq.hex", "w");
        if (pc_seq_fh == 0) begin
            $display("[TB] Failed to open pc_seq.hex");
            $finish;
        end
        $fdisplay(pc_seq_fh, "// PC sequence! - stall4mem_pip");
        $fclose(pc_seq_fh);
    end

endmodule

