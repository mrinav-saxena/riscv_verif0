`ifndef STALL_FOR_MEM_CORE_SV
`define STALL_FOR_MEM_CORE_SV

module stall_for_mem_core #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (

    input  logic clk ,
    input  logic rst_n ,

    output logic [ADDR_WIDTH-1:0] pc ,
    output logic read_instr_o ,
    input  logic [DATA_WIDTH-1:0] instr_i ,
    input  logic instr_ready_i ,

    output logic [ADDR_WIDTH-1:0] dmem_addr ,
    output logic [DATA_WIDTH-1:0] dmem_wdata ,
    output logic dmem_write_o,
    output logic [DATA_WIDTH/8-1:0] dmem_wstrb ,
    output logic dmem_read_o ,
    input  logic [DATA_WIDTH-1:0] dmem_rdata ,
    input  logic dmem_ready_i

) ;

    typedef enum {ReqInstr, Wait4Instr, Wait4ReadData, Wait4DataWrite} mem_state_e ;
    mem_state_e curr_state, next_state ;

    logic [ADDR_WIDTH-1:0] pc_final ;
    logic [ADDR_WIDTH-1:0] pc_next ;

    logic latch_instr ;
    logic [DATA_WIDTH-1:0] instr_r ;
    logic [DATA_WIDTH-1:0] instr_forwarded ;
    logic instruction_complete ;

    rv32i_base_instr opcode_e ;
    rv32i_base_instr_type instr_type ;

    assign instr_forwarded = instr_ready_i ? instr_i : instr_r ;
    assign opcode_e = instr_enum_from_val (instr_forwarded) ;
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

            if (instruction_complete == 1'b1) begin
                pc <= pc_final ;
            end // else nothing

        end
    end

    always @(*) begin
        next_state = curr_state ;
        instruction_complete = 1'b0 ;
        latch_instr = 1'b0 ;
        case (curr_state)
            ReqInstr : begin
                next_state = Wait4Instr ;
            end
            Wait4Instr : begin
                if (instr_ready_i == 1'b1) begin
                    latch_instr = 1'b1 ;
                    if (opcode_e inside {LB, LH, LW, LBU, LHU}) begin
                        next_state = Wait4ReadData ;
                    end else if (instr_type == S) begin
                        next_state = Wait4DataWrite ;
                    end else begin
                        instruction_complete = 1'b1 ;
                        next_state = ReqInstr ;
                    end
                end
            end
            Wait4DataWrite : begin
                if (dmem_ready_i == 1'b1) begin
                    instruction_complete = 1'b1 ;
                    next_state = ReqInstr ;
                end
            end
            Wait4ReadData : begin
                if (dmem_ready_i == 1'b1) begin
                    instruction_complete = 1'b1 ;
                    next_state = ReqInstr ;
                end
            end
        endcase
    end

    assign read_instr_o = (curr_state == ReqInstr) ;

    pc_logic #(
        .ADDR_WIDTH(ADDR_WIDTH) ,
        .DATA_WIDTH(DATA_WIDTH)
    ) pc_logic_inst (
        .pc_i(pc) ,
        .opcode_i(opcode_e) ,
        .imm_value_i(imm_value) ,
        .alu_result_i(alu_result) ,
        .alu_eq_i(alu_eq) ,
        .alu_lt_i(alu_lt) ,
        .alu_ltu_i(alu_ltu) ,
        .pc_final_o(pc_final) ,
        .pc_next_o(pc_next)
    ) ;

    logic [4:0] instr_rs1 ;
    logic [4:0] instr_rs2 ;
    logic [4:0] instr_rd ;

    logic [DATA_WIDTH-1:0] rs1_data ;
    logic [DATA_WIDTH-1:0] rs2_data ;

    assign instr_rs1 = instr_forwarded [19:15] ;
    assign instr_rs2 = instr_forwarded [24:20] ;
    assign instr_rd = instr_forwarded [11:7] ;

    logic [DATA_WIDTH-1:0] regfile_wdata ;
    logic regfile_wen, regfile_wen_r ;

    regfile rf_main (
        .clk(clk),
        .rst_n(rst_n),
        .rs1_i(instr_rs1),
        .rs2_i(instr_rs2),
        .rd_i(instr_rd),
        .wdata_i(regfile_wdata),
        .wen_i(regfile_wen_r),
        .wstrb_i({DATA_WIDTH/8{1'b1}}),
        .rs1_data_o(rs1_data),
        .rs2_data_o(rs2_data)
    ) ;

    logic [DATA_WIDTH-1:0] imm_value;

    imm_gen #(
        .DATA_WIDTH(DATA_WIDTH)
    ) imm_gen_inst (
        .instr_i(instr_forwarded),
        .imm_out_o(imm_value)
    ) ;
    
    logic [DATA_WIDTH-1:0] alu_src_a ;
    logic [DATA_WIDTH-1:0] alu_src_b ;
    logic [DATA_WIDTH-1:0] alu_result ;

    alu_input_logic #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) alu_input_logic_inst (
        .pc_i(pc),
        .opcode_i(opcode_e),
        .instr_type_i(instr_type),
        .rs1_data_i(rs1_data),
        .rs2_data_i(rs2_data),
        .imm_value_i(imm_value),
        .alu_src_a_o(alu_src_a),
        .alu_src_b_o(alu_src_b)
    ) ;

    logic alu_eq ;
    logic alu_lt ;
    logic alu_ltu ;
    
    alu alu_main (
        .a_i(alu_src_a),
        .b_i(alu_src_b),
        .instr_type_i(instr_type),
        .opcode_i(opcode_e),
        .result_o(alu_result),
        .eq_o(alu_eq),
        .lt_o(alu_lt),
        .ltu_o(alu_ltu)
    ) ;

    logic dmem_read ;
    logic dmem_write ;

    dmem_input_and_ctrl_logic #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dmem_input_and_ctrl_logic_inst (
        .opcode_i(opcode_e),
        .instr_type_i(instr_type),
        .rs2_data_i(rs2_data),
        .alu_result_i(alu_result),
        .dmem_addr_o(dmem_addr),
        .dmem_read_o(dmem_read),
        .dmem_write_o(dmem_write),
        .dmem_wdata_o(dmem_wdata),
        .dmem_wstrb_o(dmem_wstrb)
    ) ;

    assign dmem_read_o = (dmem_read && (curr_state == Wait4Instr) && (instr_ready_i == 1'b1)) ;
    assign dmem_write_o = (dmem_write && (curr_state == Wait4Instr) && (instr_ready_i == 1'b1)) ;

    writeback_logic #(
        .DATA_WIDTH(DATA_WIDTH)
    ) writeback_logic_inst (
        .alu_result_i(alu_result),
        .instr_type_i(instr_type),
        .opcode_i(opcode_e),
        .pc_next_i(pc_next),
        .imm_value_i(imm_value),
        .dmem_rdata_i(dmem_rdata),
        .regfile_wen_o(regfile_wen),
        .regfile_wdata_o(regfile_wdata)
    ) ;

    assign regfile_wen_r = (instruction_complete == 1'b1) ? regfile_wen : 1'b0 ;

endmodule : stall_for_mem_core

`endif