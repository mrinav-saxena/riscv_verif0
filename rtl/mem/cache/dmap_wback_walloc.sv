`ifndef CACHE_DMAP_WB_WALLOC_SV
`define CACHE_DMAP_WB_WALLOC_SV

module dmap_wback_walloc #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32,
    parameter int DEPTH = 32
) (
    input  logic clk,
    input  logic rst_n ,

    input  logic [ADDR_WIDTH-1:0] core_addr_i ,
    input  logic [DATA_WIDTH-1:0] core_wdata_i ,
    input  logic core_write_i,
    input  logic [DATA_WIDTH/8-1:0] core_wstrb_i ,
    input  logic core_read_i ,
    output logic [DATA_WIDTH-1:0] core_rdata_o ,
    output logic core_ready_o,

    input  logic cleanup_i ,

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

    logic [$clog2(DEPTH)-1:0] index ;
    logic cache_hit ;
    logic perform_write ;

    assign index = core_addr_i[$clog2(DEPTH)+1:2] ;
    assign cache_hit = (core_addr_i[ADDR_WIDTH-1:$clog2(DEPTH)+2] == tag[index]) && (valid[index]) ;

    logic [ADDR_WIDTH-1:$clog2(DEPTH)+2] latched_core_tag ;
    logic [$clog2(DEPTH)-1:0] latched_core_index ;
    logic [DATA_WIDTH-1:0] latched_core_wdata ;
    logic [DATA_WIDTH/8-1:0] latched_core_wstrb ;
    logic latched_core_write ;

    logic [ADDR_WIDTH-1:0] writeback_buffer_addr ;
    logic [DATA_WIDTH-1:0] writeback_buffer_wdata ;
    logic [DATA_WIDTH/8-1:0] writeback_buffer_wstrb ;
    logic writeback_buffer_valid_r, writeback_buffer_valid_next ;

    typedef enum {CacheReady, Wait4ReadData, Wait4WriteData, Stall4WB, Cleanup} cache_state_e ;
    cache_state_e curr_cache_state, next_cache_state ;

    typedef enum {WBReady, Wait4WB} wb_state_e ;
    wb_state_e curr_wb_state, next_wb_state ;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            curr_cache_state <= CacheReady ;
            curr_wb_state <= WBReady ;
        end else begin
            curr_cache_state <= next_cache_state ;
            curr_wb_state <= next_wb_state ;
            if ((core_write_i == 1'b1) && (cache_hit == 1'b0)) begin
                latched_core_tag = core_addr_i[ADDR_WIDTH-1:$clog2(DEPTH)+2] ;
                latched_core_index = index ;
                latched_core_wdata = core_wdata_i ;
                latched_core_wstrb = core_wstrb_i ;
                latched_core_write = core_write_i ;
            end
            if (perform_write == 1'b1) begin
                if (cache_hit == 1'b1) begin
                    // valid must already be set
                    dirty[latched_core_index] = 1'b1 ;
                    tag[index] = core_addr_i[ADDR_WIDTH-1:$clog2(DEPTH)+2] ;
                    for (int j_byte = 0; j_byte < DATA_WIDTH/8; j_byte++) begin
                        if (core_wstrb_i[j_byte]) begin
                            mem_array[latched_core_index][j_byte*8 +: 8] <= core_wdata_i[j_byte*8 +: 8] ;
                        end // else nothing
                    end
                end else begin
                    valid[latched_core_index] = 1'b1 ;
                    dirty[latched_core_index] = 1'b1 ;
                    tag[latched_core_index] = latched_core_tag ;
                    for (int j_byte = 0; j_byte < DATA_WIDTH/8; j_byte++) begin
                        if (latched_core_wstrb[j_byte]) begin
                            mem_array[latched_core_index][j_byte*8 +: 8] <= latched_core_wdata[j_byte*8 +: 8] ;
                        end else begin
                            mem_array[latched_core_index][j_byte*8 +: 8] <= dmem_rdata_i[j_byte*8 +: 8] ;
                        end
                    end
                end
            end
            if (writeback_buffer_valid_next == 1'b1) begin
                // 
            end
        end
    end

    always @(*) begin

        next_cache_state = curr_cache_state ;
        next_wb_state = curr_wb_state ;

        perform_write = 1'b0 ;
        writeback_buffer_valid_next = writeback_buffer_valid_r ;

        core_ready_o = 1'b0 ;
        core_rdata_o = 'h0 ;

        dmem_addr_o = 'h0 ;
        dmem_wdata_o = 'h0 ;
        dmem_wstrb_o = 'h0 ;
        dmem_read_o = 1'b0 ;
        dmem_write_o = 1'b0 ;

        case (curr_cache_state)
            CacheReady : begin
                if (core_write_i == 1'b1) begin
                    if (cache_hit == 1'b1) begin
                        next_cache_state = CacheReady ;
                        perform_write = 1'b1 ;
                        core_ready_o = 1'b1 ;
                    end else begin
                        if (dirty[index] == 1'b1) begin
                            if (curr_wb_state == WBReady) begin
                                next_cache_state = Wait4WriteData ;
                                writeback_buffer_valid_next = 1'b1 ;
                                dmem_addr_o = core_addr_i ;
                                dmem_read_o = 1'b1 ;
                            end else begin
                                next_cache_state = Stall4WB ;
                            end
                        end else begin
                            next_cache_state = Wait4WriteData ;
                            dmem_addr_o = core_addr_i ;
                            dmem_read_o = 1'b1 ;
                        end
                    end
                end else if (core_read_i == 1'b1) begin

                end else if (cleanup_i == 1'b1) begin

                end
            end
            Wait4WriteData : begin
                if (dmem_ready_i == 1'b1) begin
                    // need to refine bw WMF and WMD
                    next_cache_state = CacheReady ;
                    core_ready_o = 1'b1 ;
                    perform_write = 1'b1 ;
                end
            end
            Stall4WB : begin
                if (curr_wb_state == WBReady) begin
                    next_cache_state = Wait4WriteData ;
                    writeback_buffer_valid_next = 1'b1 ;
                    dmem_addr_o = core_addr_i ;
                    dmem_read_o = 1'b1 ;
                end
            end
        endcase

        case (curr_wb_state)
            WBReady : begin
                if (writeback_buffer_valid_r == 1'b1) begin
                    if (curr_cache_state == CacheReady) begin
                        next_wb_state = Wait4WB ;
                        dmem_addr_o = writeback_buffer_addr ;
                        dmem_wdata_o = writeback_buffer_wdata ;
                        dmem_wstrb_o = writeback_buffer_wstrb ;
                        dmem_write_o = 1'b1 ;
                    end
                end
            end
            Wait4WB : begin
                if (dmem_ready_i == 1'b1) begin
                    next_wb_state = WBReady ;
                    writeback_buffer_valid_next = 1'b0 ;
                end
            end
        endcase

    end


endmodule : dmap_wback_walloc

`endif