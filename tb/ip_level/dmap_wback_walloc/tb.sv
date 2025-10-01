module tb # (
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int CACHE_DEPTH = 4,
    parameter int DMEM_DEPTH = 1024
) (
    input logic clk,
    input logic rst_n
) ;

    bit deadbeef_written = 1'b0;
    integer cycle_count ;

    logic [ADDR_WIDTH-1:0] tc_addr [4] ;

    bit [ADDR_WIDTH-1:0] core_addr;
    bit [DATA_WIDTH-1:0] core_wdata;
    bit core_write;
    bit [DATA_WIDTH/8-1:0] core_wstrb;
    bit core_read;
    bit [DATA_WIDTH-1:0] core_rdata;
    bit core_ready;

    bit cleanup;

    bit [ADDR_WIDTH-1:0] dmem_addr;
    bit [DATA_WIDTH-1:0] dmem_wdata;
    bit dmem_write;
    bit [DATA_WIDTH/8-1:0] dmem_wstrb;
    bit dmem_read;
    bit [DATA_WIDTH-1:0] dmem_rdata;
    bit dmem_ready;

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

    dmap_wback_walloc #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .DEPTH(CACHE_DEPTH)
    ) i_dcache (
        .clk    (clk),
        .rst_n  (rst_n),
        .core_addr_i (core_addr),
        .core_wdata_i (core_wdata),
        .core_write_i (core_write),
        .core_wstrb_i (core_wstrb),
        .core_read_i (core_read),
        .core_rdata_o (core_rdata),
        .core_ready_o (core_ready),
        .cleanup_i (cleanup),
        .dmem_addr_o (dmem_addr),
        .dmem_wdata_o (dmem_wdata),
        .dmem_write_o (dmem_write),
        .dmem_wstrb_o (dmem_wstrb),
        .dmem_read_o (dmem_read),
        .dmem_rdata_i (dmem_rdata),
        .dmem_ready_i (dmem_ready)
    );

    always @(posedge clk) begin
        cycle_count ++ ;
    end

    integer cache_mem_fh ;

    initial begin
        // cache_base_test_inst = new (cache_core_if_inst) ;
        @(posedge clk) ;
        // cache_base_test_inst.run() ;
    end

    initial begin

        cycle_count = 0 ;
        tc_addr[0] = 32'h00000004;
        tc_addr[1] = 32'h00000014;
        tc_addr[2] = 32'h00000008;
        tc_addr[3] = 32'h00000018;

        core_write = 1'b0 ;
        core_read = 1'b0 ;
        cleanup = 1'b0 ;

        wait_n_cycles(6);

        write_req(tc_addr[0], 32'ha5a5a5a5, 4'hf);
        wait_n_cycles(6);

        write_req(tc_addr[0], 32'h5a5a5a5a, 4'h1);
        wait_n_cycles(6);

        write_req(tc_addr[1], 32'h0f0f0f0f, 4'hf);
        wait_n_cycles(6);

        write_req(tc_addr[0], 32'h44444444, 4'h2);
        wait_n_cycles(6);
        
        write_req(tc_addr[1], 32'h08080808, 4'hf);
        wait_n_cycles(6);

        for (int i = 0; i < CACHE_DEPTH; i++) begin
            if (i == 0) begin
                cache_mem_fh = $fopen("cache_mem.hex", "w");
                if (cache_mem_fh == 0) begin
                    $display("[TB] Failed to open cache_mem.hex");
                    $finish;
                end else begin
                    $fdisplay(cache_mem_fh, "// Cache memory!");
                end
            end
            $fdisplay(cache_mem_fh, "index[0x%h] : tag = 0x%h ; data = 0x%h ; valid = %b ; dirty = %b", i[$clog2(CACHE_DEPTH)-1:0], i_dcache.tag[i], i_dcache.mem_array[i], i_dcache.valid[i], i_dcache.dirty[i]);
        end
        $fclose(cache_mem_fh);
        $writememh("res_dmem.hex", i_dmem.mem_array, 0, DMEM_DEPTH) ;

        $finish;

    end

    task write_req (input bit [ADDR_WIDTH-1:0] addr0, input bit [DATA_WIDTH-1:0] wdata0, input bit [DATA_WIDTH/8-1:0] wstrb0) ;

        core_addr = addr0;
        core_wdata = wdata0;
        core_wstrb = wstrb0;
        core_write = 1'b1;
        core_read = 1'b0;
        @(negedge clk) ;

        core_addr = 'h0;
        core_wdata = 'h0;
        core_wstrb = 'h0;
        core_write = 1'b0;
        core_read = 1'b0;
        wait(core_ready == 1'b1) ;

    endtask : write_req

    task wait_n_cycles (input integer n) ;
        repeat (n) @(negedge clk) ;
    endtask : wait_n_cycles

endmodule

