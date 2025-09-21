`ifndef STALL_FOR_MEM_CORE_SV
`define STALL_FOR_MEM_CORE_SV

module stall4mem_pip_core #(
    parameter int ADDR_WIDTH = 32,
    parameter int DATA_WIDTH = 32
) (

    input  logic clk ,
    input  logic rst_n ,

    output logic [ADDR_WIDTH-1:0] pc ,
    output logic read_instr_o ,
    input  logic [DATA_WIDTH-1:0] instr_i ,
    input  logic instr_ready_i ,

    output logic [ADDR_WIDTH-1:0] dmem_addr_o ,
    output logic [DATA_WIDTH-1:0] dmem_wdata_o ,
    output logic dmem_write_o,
    output logic [DATA_WIDTH/8-1:0] dmem_wstrb_o ,
    output logic dmem_read_o ,
    input  logic [DATA_WIDTH-1:0] dmem_rdata_i ,
    input  logic dmem_ready_i

) ;

    logic [DATA_WIDTH-1:0] instr_r ;            // latched on cycle after instr_ready_i == 1
    logic [DATA_WIDTH-1:0] instr_forwarded ;    // available combinationally from the time instr_ready_i == 1
    logic wait4dmem_ready_r ;
    logic wait4regfile_write, waw_dependence, wait4regfile_write_r ;
    logic operands_ready, raw_dependence, operands_ready_r ;

    logic ifidex_complete ; 
    
    rv32i_base_instr opcode_e ;
    rv32i_base_instr_type instr_type ;

    assign instr_forwarded = instr_ready_i ? instr_i : instr_r ;
    assign opcode_e = instr_enum_from_val (instr_forwarded) ;
    assign instr_type = instr_type_enum_from_instr (opcode_e) ;

    ifidex_state_e curr_ifidex_state, next_ifidex_state ;
    logic stall_ifidex ;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= 'h0;
            instr_r <= 'h0 ;
            curr_ifidex_state <= ReqInstr ;
        end else begin
            curr_ifidex_state <= next_ifidex_state ;
            if (instr_ready_i == 1'b1) begin
                instr_r <= instr_i ;
            end
            if (ifidex_complete == 1'b1) begin
                pc <= pc_final ;
            end
        end
    end

    instr_group_e instr_group ;

    assign instr_group = 
        (instr_type inside {U, J}) ? group_UJ :
        (instr_type == B) ? group_B :
        ((instr_type == R) || (instr_forwarded[6:0] inside {7'b1100111, 7'b0010011})) ? group_RI_nonload :
        (instr_type == I) ? group_I_load :
        (instr_type == S) ? group_S :
        group_UNKNOWN
    ;

    always @(*) begin

        ifidex_complete = 1'b0 ;
        next_ifidex_state = curr_ifidex_state ;
        stall_ifidex = 1'b0 ;

        case (instr_group)
            group_UJ : begin
                stall_ifidex = (wait4regfile_write) ;
            end
            group_B : begin
                stall_ifidex = (!operands_ready) ;
            end
            group_RI_nonload : begin
                stall_ifidex = (!operands_ready) || (wait4regfile_write) ;
            end
            group_I_load, group_S : begin
                stall_ifidex = (!operands_ready) || (wait4dmem_ready_r) ;
            end
            // nothing for group_UNKNOWN and default - defaults
        endcase
        
        case (curr_ifidex_state)
            ReqInstr : begin
                next_ifidex_state = Wait4Instr ;
            end
            Wait4Instr : begin
                if (instr_ready_i == 1'b1) begin
                    next_ifidex_state = stall_ifidex ? StallInstr : ReqInstr ;
                end // else nothing - defaults
            end
            StallInstr : begin
                next_ifidex_state = stall_ifidex ? StallInstr : ReqInstr ;
            end
        endcase
        ifidex_complete = (next_ifidex_state == ReqInstr) ;
        
    end

    logic [ADDR_WIDTH-1:0] pc_final ;
    logic [ADDR_WIDTH-1:0] pc_next ;

    assign read_instr_o = (curr_ifidex_state == ReqInstr) ;

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
    logic regfile_wen, regfile_wen_pulse ;

    regfile #(.DATA_WIDTH(32), .N_REGS(32)) rf_main (
        .clk(clk),
        .rst_n(rst_n),
        .rs1_i(instr_rs1),
        .rs2_i(instr_rs2),
        .rd_i(wb_rd),
        .wdata_i(regfile_wdata),
        .wen_i(regfile_wen_pulse),
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

    dmem_state_e curr_dmem_state, next_dmem_state ;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            curr_dmem_state <= Idle ;
        end else begin
            curr_dmem_state <= next_dmem_state ;
        end
    end

    always @(*) begin
        next_dmem_state = curr_dmem_state ;
        buffer_write = 1'b0 ;
        case (curr_dmem_state)
            Idle : begin
                if (dmem_read_o == 1'b1) begin
                    next_dmem_state = Wait4ReadData ;
                end else if (dmem_write_o == 1'b1) begin
                    next_dmem_state = Wait4DataWrite ;
                end else begin
                    next_dmem_state = Idle ;
                end
            end
            Wait4ReadData : begin
                if (dmem_ready_i == 1'b1) begin
                    next_dmem_state = Idle ;
                    buffer_write = 1'b1 ;
                end
            end
            Wait4DataWrite : begin
                if (dmem_ready_i == 1'b1) begin
                    next_dmem_state = Idle ;
                end
            end
        endcase
    end

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

    logic [ADDR_WIDTH-1:0] dmem_addr ;
    logic dmem_read;
    logic dmem_write;
    logic [DATA_WIDTH-1:0] dmem_wdata;
    logic [DATA_WIDTH/8-1:0] dmem_wstrb;

    assign dmem_addr_o = ifidex_complete ? dmem_addr : 'h0 ;
    assign dmem_wdata_o = ifidex_complete ? dmem_wdata : 'h0 ;
    assign dmem_write_o = ifidex_complete ? dmem_write : 1'b0 ;
    assign dmem_wstrb_o = ifidex_complete ? dmem_wstrb : 'h0 ;
    assign dmem_read_o = ifidex_complete ? dmem_read : 1'b0 ;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wait4dmem_ready_r <= 'h0 ;
        end else begin
            if ((ifidex_complete == 1'b1) && (instr_group inside {group_I_load, group_S})) begin
                wait4dmem_ready_r <= 1'b1 ;
            end
            if (dmem_ready_i == 1'b1) begin
                wait4dmem_ready_r <= 1'b0 ;
            end
        end
    end

    // writeback buffer
    logic writeback_buffer_valid ;
    logic [4:0] buffered_rd, wb_rd ;
    logic [DATA_WIDTH-1:0] buffered_alu_result, wb_alu_result  ;
    rv32i_base_instr_type buffered_instr_type, wb_instr_type ;
    rv32i_base_instr buffered_opcode, wb_opcode ;
    logic buffer_write ;    // signal to indicate that the regfile write will be done with the wb buffer
    
    assign writeback_buffer_valid = (curr_dmem_state == Wait4ReadData) ;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            buffered_rd <= 'h0 ;
            buffered_alu_result <= 'h0 ;
            buffered_instr_type <= UNKNOWN ;
            buffered_opcode <= NOP ;
        end else begin
            if (dmem_read_o == 1'b1) begin
                buffered_rd <= instr_rd ;
                buffered_alu_result <= alu_result ;
                buffered_instr_type <= instr_type ;
                buffered_opcode <= opcode_e ;
            end else if (dmem_ready_i == 1'b1) begin
                buffered_rd <= 'h0 ;
                buffered_alu_result <= 'h0 ;
                buffered_instr_type <= UNKNOWN ;
                buffered_opcode <= NOP ;
            end
        end
    end

    assign raw_dependence = (instr_ready_i || (curr_ifidex_state == StallInstr)) && (buffered_rd != 'h0) && (writeback_buffer_valid == 1'b1) && (
        (instr_type == I) ? (buffered_rd == instr_rs1) :
        (instr_type inside {R, B, S}) ? ((buffered_rd == instr_rs1) || (buffered_rd == instr_rs2)) :
        1'b0
    ) ;

    assign waw_dependence = (instr_ready_i || (curr_ifidex_state == StallInstr)) && (buffered_rd != 'h0) && (writeback_buffer_valid == 1'b1) && (
        instr_type inside {U, J, R, I} ? (buffered_rd == instr_rd) : 0
    ) ;

    always @ (posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            operands_ready_r <= 1'b1 ;
            wait4regfile_write_r <= 1'b0 ;
        end else begin
            if (curr_ifidex_state == ReqInstr) begin
                operands_ready_r <= 1'b1 ;
                wait4regfile_write_r <= 1'b0 ;
            end else if ((instr_ready_i == 1'b1) && (buffer_write != 1'b1)) begin
                operands_ready_r <= !raw_dependence ;
                wait4regfile_write_r <= waw_dependence ;
            end else if (buffer_write == 1'b1) begin
                operands_ready_r <= 1'b1 ;
                wait4regfile_write_r <= 1'b0 ;
            end // nothing, maintain value
        end
    end

    assign operands_ready = !(raw_dependence || (!operands_ready_r));
    assign wait4regfile_write = wait4regfile_write_r || waw_dependence || buffer_write ;
    // ^buffer_write takes priority over other instructions that write to regfile when ifidex_complete => stall em for 1 cycle

    assign wb_rd = buffer_write ? buffered_rd : instr_rd ;
    assign wb_alu_result = buffer_write ? buffered_alu_result : alu_result ;
    assign wb_instr_type = buffer_write ? buffered_instr_type : instr_type ;
    assign wb_opcode = buffer_write ? buffered_opcode : opcode_e ;

    writeback_logic #(
        .DATA_WIDTH(DATA_WIDTH)
    ) writeback_logic_inst (
        .alu_result_i(wb_alu_result),
        .instr_type_i(wb_instr_type),
        .opcode_i(wb_opcode),
        .pc_next_i(pc_next),
        .imm_value_i(imm_value),
        .dmem_rdata_i(dmem_rdata_i),
        .regfile_wen_o(regfile_wen),
        .regfile_wdata_o(regfile_wdata)
    ) ;

    assign regfile_wen_pulse = buffer_write || (regfile_wen && (next_ifidex_state == ReqInstr) && (instr_group != group_I_load)) ;
    
    /*
    writeback_buffer_valid ? buffer_write :
        (instr_group inside {group_UJ, group_RI_nonload}) ? ifidex_complete :
        1'b0 
    ;
    */

endmodule : stall4mem_pip_core

`endif