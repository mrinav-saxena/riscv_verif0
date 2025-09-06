`ifndef MEM_NZLAT_SV
`define MEM_NZLAT_SV

module mem_nzlat #(
    parameter int DATA_WIDTH = 32 ,
    parameter int DEPTH = 1024 ,
    parameter int READ_LATENCY = 5 ,
    parameter int WRITE_LATENCY = 5 ,
    localparam int ADDR_WIDTH = $clog2(DEPTH)
)(
    // !!! write takes priority over read if both are asserted simultaneously
    input  logic clk,
    input  logic rst_n,
    input  logic [ADDR_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH-1:0] wdata,
    input  logic [DATA_WIDTH/8-1:0] wstrb,
    input  logic write,
    input  logic read,
    output logic [DATA_WIDTH-1:0] rdata,
    output logic ready
);

    typedef enum {Idle, GettingRdata, ProcessingWdata, Ready} state_e ;
    state_e curr_state, next_state ;

    // TODO : check if counter widths are okay with one set of values in sim
    logic [DATA_WIDTH-1:0] mem_array [DEPTH-1:0] ;
    logic [$clog2(READ_LATENCY+1):0] read_counter, read_counter_next ;
    logic [$clog2(WRITE_LATENCY+1):0] write_counter, write_counter_next ;

    logic [ADDR_WIDTH-1:0] latched_addr ;
    logic [DATA_WIDTH-1:0] latched_wdata ;
    logic [DATA_WIDTH/8-1:0] latched_wstrb ;
    logic latched_operation ;   // 0 -> write, 1 -> read
  
    // sequential update logic 
    always @(posedge clk or negedge rst_n) begin

        if (!rst_n) begin

            curr_state <= Idle ;
            for (int i = 0; i < DEPTH; i++) begin : i_reset_block
                mem_array[i] <= '0 ;
            end
            write_counter <= 'h0 ;
            read_counter <= 'h0 ;
            latched_addr <= 'h0 ;
            latched_wdata <= 'h0 ;
            latched_wstrb <= 'h0 ;
            latched_operation <= 1'b0 ;
            rdata <= 'h0 ;

        end else begin

            // always do these updates
            curr_state <= next_state ;
            read_counter <= read_counter_next ;
            write_counter <= write_counter_next ;

            // capture latched inputs upon a write or read pulse (but not when busy)
            if (curr_state == Idle) begin
                if (write == 1'b1) begin
                    latched_operation <= 1'b0 ;
                    latched_addr <= addr ;
                    latched_wdata <= wdata ;
                    latched_wstrb <= wstrb ;
                end else if (read == 1'b1) begin
                    latched_operation <= 1'b1 ;
                    latched_addr <= addr ;
                end else begin
                    latched_operation <= 1'b0 ;
                    latched_addr <= 'h0 ;
                    latched_wdata <= 'h0 ;
                    latched_wstrb <= 'h0 ;
                end
            end

            // update memory upon a write
            if ((curr_state == ProcessingWdata) && (write_counter == 1)) begin
                for (int i = 0; i < DATA_WIDTH/8; i++) begin
                    if (latched_wstrb[i]) begin
                        mem_array[latched_addr][i*8 +: 8] <= latched_wdata[i*8 +: 8];
                    end
                end
            end else if ((curr_state == GettingRdata) && (read_counter == 1)) begin
                rdata <= mem_array[latched_addr] ;
            end else begin
                rdata <= 'h0 ;
            end
            

        end

    end

    always @(*) begin
        
        // default values
        ready = 1'b0 ;
        write_counter_next = write_counter ;
        read_counter_next = read_counter ;
        next_state = curr_state ;

        case (curr_state)

            Idle : begin
                if (write == 1'b1) begin
                    write_counter_next = WRITE_LATENCY ;
                    next_state = WRITE_LATENCY != 0 ? ProcessingWdata : Ready ;
                end else if (read == 1'b1) begin
                    read_counter_next = READ_LATENCY ;
                    next_state = READ_LATENCY != 0 ? GettingRdata : Ready ;
                end else begin
                    next_state = Idle ;
                end
            end

            ProcessingWdata : begin
                if (write_counter > 1) begin
                    write_counter_next = write_counter - 1 ;
                    next_state = curr_state ;
                end else if (write_counter == 1) begin
                    write_counter_next = 0 ;
                    next_state = Ready ;
                end
            end

            GettingRdata : begin
                if (read_counter > 1) begin
                    read_counter_next = read_counter - 1 ;
                    next_state = curr_state ;
                end else if (read_counter == 1) begin
                    read_counter_next = 0 ;
                    next_state = Ready ;
                end
            end

            Ready : begin
                ready = 1'b1 ;
                next_state = Idle ;
            end

        endcase
    end

endmodule

`endif // MEM_NZLAT_SV
