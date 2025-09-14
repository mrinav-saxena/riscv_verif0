`ifndef IFIDEX_STAGE_SV
`define IFIDEX_STAGE_SV

module ifidex_stage #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (

    input  logic clk ,
    input  logic rst_n ,

    output logic [ADDR_WIDTH-1:0] pc_o ,
    output logic read_instr_o ,
    input  logic [DATA_WIDTH-1:0] instr_i ,
    input  logic instr_ready_i , 

) ;

    logic [DATA_WIDTH-1:0] instr_r ;
    logic instr_ready_r ;
    logic ifidex_complete ;
    logic latch_instr ;
    rv32i_base_instr opcode_e ;
    rv32i_base_instr_type instr_type ;

    typedef enum {ReqInstr, Wait} ifidex_state_e ;
    ifidex_state_e curr_ifidex_state, next_ifidex_state ;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc_o <= 'h0;
            instr_r <= 'h0 ;
            curr_ifidex_state <= ReqInstr ;
        end else begin
            curr_ifidex_state <= next_ifidex_state ;
            if (latch_instr == 1'b1) begin
                instr_r <= instr_i ;
            end 
            if (ifidex_complete == 1'b1) begin
                pc_o <= pc_final ;
            end
        end
    end

    always @(*) begin
        next_ifidex_state = curr_ifidex_state ;
        ifidex_complete = 1'b0 ;
        latch_instr = 1'b0 ;
        case (curr_ifidex_state)
            ReqInstr : begin
                next_ifidex_state = Wait ;
            end
            Wait : begin
                if (instr_ready_i == 1'b1) begin
                    instr_ready_r = 1'b1 ;
                    // latch_instr = 1'b1 ;
                    // if (opcode_e inside {LB, LH, LW, LBU, LHU}) begin
                    //     // data read request
                    // end else if (instr_type == S) begin
                    //     // data write request
                    // end else begin
                    //     ifidex_complete = 1'b1 ;
                    //     next_ifidex_state = ReqInstr ;
                    // end
                end
            end
        endcase
    end

    logic [ADDR_WIDTH-1:0] pc_final ;
    logic [ADDR_WIDTH-1:0] pc_next ;

    pc_logic #(
        .ADDR_WIDTH(ADDR_WIDTH) ,
        .DATA_WIDTH(DATA_WIDTH)
    ) pc_logic_inst (
        .pc_i(pc_o) ,
        .opcode_i(opcode_e) ,
        .imm_value_i(imm_value) ,
        .alu_result_i(alu_result) ,
        .alu_eq_i(alu_eq) ,
        .alu_lt_i(alu_lt) ,
        .alu_ltu_i(alu_ltu) ,
        .pc_final_o(pc_final) ,
        .pc_next_o(pc_next)
    ) ;

endmodule : ifidex_stage

`endif