`ifndef STALL_FOR_MEM_CORE_SV
`define STALL_FOR_MEM_CORE_SV

module stall_for_mem_core #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (

    input  logic clk ,
    input  logic rst_n ,

    output logic [ADDR_WIDTH-1:0] pc ,
    output logic read_instr ,
    input  logic [DATA_WIDTH-1:0] instr_i ,
    input  logic instr_ready_i ,

    output logic [ADDR_WIDTH-1:0] dmem_addr ,
    output logic [DATA_WIDTH-1:0] dmem_wdata ,
    output logic dmem_write ,
    output logic [DATA_WIDTH/8-1:0] dmem_wstrb ,
    output logic dmem_read ,
    input  logic [DATA_WIDTH-1:0] dmem_rdata ,
    input  logic dmem_ready

) ;

    typedef enum {ReqInstr, Wait4Instr, ReqReadData, Wait4ReadData, ReqDataWrite, Wait4DataWrite} mem_state_e ;
    mem_state_e curr_state, next_state ;

    logic [ADDR_WIDTH-1:0] pc_final ;
    logic [ADDR_WIDTH-1:0] pc_next ;

    logic latch_instr ;
    logic [DATA_WIDTH-1:0] instr_r ;

    rv32i_base_instr opcode_e ;
    rv32i_base_instr_type instr_type ;

    assign opcode_e = instr_enum_from_val (instr_ready_i ? instr_i : instr_r) ;
    assign instr_type = instr_type_enum_from_instr (opcode_e) ;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= 'h0;
            instr_r <= 'h0 ;
            curr_state <= ReqInstr ;
        end else begin
            curr_state <= next_state ;
            if (latch_instr == 1'b1) begin
                instr_r <= instr_i ;
            end // else nothing
        end
    end

    always @(*) begin
        next_state = curr_state ;
        case (curr_state)
            ReqInstr : begin
                read_instr = 1'b1 ;
                next_state = Wait4Instr ;
            end
            Wait4Instr : begin
                read_instr = 1'b0 ;
                latch_instr = 1'b1 ;
                if (instr_ready_i == 1'b1) begin
                    if (opcode_e inside {LB, LH, LW, LBU, LHU, SB, SH, SW}) begin
                        next_state = ReqReadData ;
                    end else if (instr_type == S) begin
                        next_state = ReqDataWrite ;
                    end else begin
                        next_state = ReqInstr ;
                    end
                end
            end
        endcase
    end

    pc_logic #(
        .ADDR_WIDTH(ADDR_WIDTH) ,
        .DATA_WIDTH(DATA_WIDTH)
    ) pc_logic_inst (
        .pc(pc) ,
        .opcode_e(opcode_e) ,
        .imm_value(0) ,
        .alu_result(0) ,
        .alu_eq(0) ,
        .alu_lt(0) ,
        .alu_ltu(0) ,
        .pc_final(pc_final) ,
        .pc_next(pc_next)
    ) ;

endmodule : stall_for_mem_core

`endif