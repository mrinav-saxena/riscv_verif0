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
    logic wait4regfile_write_r, wait4dmem_ready_r ;
    logic operands_ready_r ;
    logic instruction_complete ;
    logic ifidex_complete ; 
    
    rv32i_base_instr opcode_e ;
    rv32i_base_instr_type instr_type ;

    assign instr_forwarded = instr_ready_i ? instr_i : instr_r ;
    assign opcode_e = instr_enum_from_val (instr_forwarded) ;
    assign instr_type = instr_type_enum_from_instr (opcode_e) ;

    typedef enum {ReqInstr, Wait4Instr, StallInstr} ifidex_state_e ;
    ifidex_state_e curr_ifidex_state, next_ifidex_state ;
    logic stall_ifidex ;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= 'h0;
            instr_r <= 'h0 ;
            curr_ifidex_state <= ReqInstr ;
            wait4regfile_write_r <= 1'b0 ;
            operands_ready_r <= 1'b0 ;
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

    typedef enum {group_UJ, group_B, group_RI_nonload, group_I_load, group_S, group_UNKNOWN} instr_group_e ;
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
        instruction_complete = 1'b0 ;
        next_ifidex_state = curr_ifidex_state ;
        stall_ifidex = 1'b0 ;

        case (instr_group)
            group_UJ : begin
                stall_ifidex = (wait4regfile_write_r) ;
            end
            group_B : begin
                stall_ifidex = (!operands_ready_r) ;
            end
            group_RI_nonload : begin
                stall_ifidex = (!operands_ready_r) || (wait4regfile_write_r) ;
            end
            group_I_load, group_S : begin
                stall_ifidex = (!operands_ready_r) || (wait4dmem_ready_r) ;
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
        instruction_complete = (next_ifidex_state == ReqInstr) && (instr_group inside {group_UJ, group_B, group_RI_nonload, group_I_load, group_S});

    end

    // typedef enum {ReqInstr, Wait4Instr/*, Wait4ReadData, Wait4DataWrite*/} ifidex_state_e ;
    // ifidex_state_e curr_ifidex_state, next_ifidex_state ;

    // typedef enum {Wait4DataWrite, Wait4ReadData} dmem_state_e ;
    // dmem_state_e curr_dmem_state, next_dmem_state ;

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
    logic regfile_wen, regfile_wen_r ;

    regfile #(.DATA_WIDTH(32), .N_REGS(32)) rf_main (
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

    typedef enum {Idle, Wait4DataWrite, Wait4ReadData} dmem_state_e ;
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
    logic writeback_buffer_valid_r ;
    logic [4:0] buffered_rd ;
    logic [DATA_WIDTH-1:0] buffered_alu_result ;
    rv32i_base_instr_type buffered_instr_type ;
    rv32i_base_instr buffered_opcode ;
    logic [DATA_WIDTH-1:0] buffered_dmem_rdata ;
    logic buffer_write ;    // signal to indicate that the regfile write will be done with the wb buffer

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            writeback_buffer_valid_r <= 1'b0 ;
            buffered_rd <= 'h0 ;
            buffered_alu_result <= 'h0 ;
            buffered_instr_type <= UNKNOWN ;
            buffered_opcode <= NOP ;
            buffered_dmem_rdata <= 'h0 ;
        end else begin
            if (dmem_read_o == 1'b1) begin
                writeback_buffer_valid_r <= 1'b1 ;
                buffered_rd <= instr_rd ;
                buffered_alu_result <= alu_result ;
                buffered_instr_type <= instr_type ;
                buffered_opcode <= opcode_e ;
            end else if (dmem_ready_i == 1'b1) begin
                writeback_buffer_valid_r <= 1'b0 ;
                buffered_dmem_rdata <= dmem_rdata_i ;
                // buffered_rd <= 'h0 ;
                // buffered_alu_result <= 'h0 ;
                // buffered_instr_type <= instr_type ;
                // buffered_opcode <= opcode_e ;
                // buffered_dmem_rdata <= 'h0 ;
            end
        end
    end

    always @ (posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            operands_ready_r <= 1'b1 ;
            wait4regfile_write_r <= 1'b0 ;
        end else begin
            if (curr_ifidex_state == ReqInstr) begin
                operands_ready_r <= 1'b1 ;
            end else if (writeback_buffer_valid_r == 1'b1) begin
                if (instr_ready_i == 1'b1) begin
                    case (instr_type)
                        I :         operands_ready_r <= !(buffered_rd == instr_rs1) ;
                        R, B, S :   operands_ready_r <= !((buffered_rd == instr_rs1) || (buffered_rd == instr_rs2)) ;
                        default :   operands_ready_r <= 1'b1 ;
                    endcase
                end else begin

                end 
            end else begin
                operands_ready_r <= 1'b1 ;
            end
        end
    end

    writeback_logic #(
        .DATA_WIDTH(DATA_WIDTH)
    ) writeback_logic_inst (
        .alu_result_i(alu_result),
        .instr_type_i(instr_type),
        .opcode_i(opcode_e),
        .pc_next_i(pc_next),
        .imm_value_i(imm_value),
        .dmem_rdata_i(dmem_rdata_i),
        .regfile_wen_o(regfile_wen),
        .regfile_wdata_o(regfile_wdata)
    ) ;

    assign regfile_wen_r = (instruction_complete == 1'b1) ? regfile_wen : 1'b0 ;

endmodule : stall4mem_pip_core

`endif