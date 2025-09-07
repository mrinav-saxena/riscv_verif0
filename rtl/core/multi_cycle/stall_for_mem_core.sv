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
    output logic dmem_write_r ,
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
            end

            if (curr_state == ReqDataWrite) begin
                dmem_write_r <= dmem_write ;
            end else begin
                dmem_write_r <= 1'b0 ;
            end

        end
    end

    always @(*) begin
        next_state = curr_state ;
        case (curr_state)
            ReqInstr : begin
                read_instr = 1'b1 ;
                next_state = Wait4Instr ;
                instruction_complete = 1'b0 ;
            end
            Wait4Instr : begin
                read_instr = 1'b0 ;
                latch_instr = 1'b1 ;
                if (instr_ready_i == 1'b1) begin
                    if (opcode_e inside {LB, LH, LW, LBU, LHU}) begin
                        next_state = ReqReadData ;
                    end else if (instr_type == S) begin
                        next_state = ReqDataWrite ;
                    end else begin
                        instruction_complete = 1'b1 ;
                        next_state = ReqInstr ;
                    end
                end
            end
            ReqDataWrite : begin
                next_state = Wait4DataWrite ;
            end
            Wait4DataWrite : begin
                if (dmem_ready == 1'b1) begin
                    instruction_complete = 1'b1 ;
                    next_state = ReqInstr ;
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
        .imm_value(imm_value) ,
        .alu_result(alu_result) ,
        .alu_eq(alu_eq) ,
        .alu_lt(alu_lt) ,
        .alu_ltu(alu_ltu) ,
        .pc_final(pc_final) ,
        .pc_next(pc_next)
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
    logic regfile_wen ;

    regfile rf_main (
        .clk(clk),
        .rst_n(rst_n),
        .rs1(instr_rs1),
        .rs2(instr_rs2),
        .rd(instr_rd),
        .wdata(regfile_wdata),
        .wen(regfile_wen),
        .wstrb({DATA_WIDTH/8{1'b1}}),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data)
    ) ;

    logic [DATA_WIDTH-1:0] imm_value;

    imm_gen #(
        .DATA_WIDTH(DATA_WIDTH)
    ) imm_gen_inst (
        .instr(instr_forwarded),
        .imm_out(imm_value)
    ) ;
    
    logic [DATA_WIDTH-1:0] alu_src_a ;
    logic [DATA_WIDTH-1:0] alu_src_b ;
    logic [DATA_WIDTH-1:0] alu_result ;

    alu_input_logic #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) alu_input_logic_inst (
        .pc(pc_final),
        .opcode_e(opcode_e),
        .instr_type(instr_type),
        .rs1_data(rs1_data),
        .rs2_data(rs2_data),
        .imm_value(imm_value),
        .alu_src_a(alu_src_a),
        .alu_src_b(alu_src_b)
    ) ;

    logic alu_eq ;
    logic alu_lt ;
    logic alu_ltu ;
    
    alu alu_main (
        .a(alu_src_a),
        .b(alu_src_b),
        .instr_type(instr_type),
        .opcode_e(opcode_e),
        .result(alu_result),
        .eq(alu_eq),
        .lt(alu_lt),
        .ltu(alu_ltu)
    ) ;

    logic dmem_read_r ;
    logic dmem_write ;

    dmem_input_and_ctrl_logic #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dmem_input_and_ctrl_logic_inst (
        .opcode_e(opcode_e),
        .instr_type(instr_type),
        .rs2_data(rs2_data),
        .alu_result(alu_result),
        .dmem_addr(dmem_addr),
        .dmem_read(dmem_read),
        .dmem_write(dmem_write),
        .dmem_wdata(dmem_wdata),
        .dmem_wstrb(dmem_wstrb)
    ) ;

    writeback_logic #(
        .DATA_WIDTH(DATA_WIDTH)
    ) writeback_logic_inst (
        .alu_result(alu_result),
        .instr_type(instr_type),
        .opcode_e(opcode_e),
        .pc_next(pc_next),
        .imm_value(imm_value),
        .dmem_rdata(dmem_rdata),
        .regfile_wen(regfile_wen),
        .regfile_wdata(regfile_wdata)
    ) ;

endmodule : stall_for_mem_core

`endif