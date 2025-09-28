module tb # (
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int DMEM_DEPTH = 1024,
    parameter int CACHE_DEPTH = 4
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
        /*
        cache_mem_fh = $fopen("cache_mem.hex", "w");
        if (cache_mem_fh == 0) begin
            $display("[TB] Failed to open cache_mem.hex");
            $finish;
        end else begin
            $fdisplay(cache_mem_fh, "// Cache memory!");
        end
        $fclose(cache_mem_fh);
        */
    end

    initial begin

        cycle_count = 0 ;
        tc_addr[0] = 32'h00000000;
        tc_addr[1] = 32'h01000000;
        tc_addr[2] = 32'h00000004;
        tc_addr[3] = 32'h01000004;

        core_addr = tc_addr[0];
        core_wdata = 32'ha5a5a5a5;
        core_write = 1'b0 ;
        core_wstrb = 4'hf;
        core_read = 1'b0 ;
        cleanup = 1'b0 ;

        repeat (4) @(negedge clk) ;
        // #200ps ;

        core_write = 1'b1 ;
        @(negedge clk) ;
        core_write = 1'b0 ;

        repeat (8) @(negedge clk) ;
        repeat (2) @(negedge clk) ;

        core_wdata = 32'h5a5a5a5a ;
        core_wstrb = 4'h6;
        core_write = 1'b1 ;
        @(negedge clk) ;
        core_write = 1'b0 ;

        repeat (15) @(negedge clk) ;
        
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
            $fdisplay(cache_mem_fh, "index[%0d] : tag = %h ; data = 0x%h ; valid = %b ; dirty = %b", i, i_dcache.tag[i], i_dcache.mem_array[i], i_dcache.valid[i], i_dcache.dirty[i]);
        end
        $fclose(cache_mem_fh);
        // $writememh("cache_mem.hex", i_dcache.mem_array, 0, CACHE_DEPTH) ;

        $finish;


    end

endmodule

