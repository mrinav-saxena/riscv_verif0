// single_cycle_core.sv
`ifndef SINGLE_CYCLE_CORE_SV
`define SINGLE_CYCLE_CORE_SV

// TBD : instruction is always 32 bits?

module single_cycle_core #(
    parameter int ADDR_WIDTH = 32 ,
    parameter int DATA_WIDTH = 32
)(

    input  logic clk ,
    input  logic rst_n ,

    output logic [ADDR_WIDTH-1:0] pc ,
    input  logic [DATA_WIDTH-1:0] instr ,

    output logic [ADDR_WIDTH-1:0] dmem_addr ,
    output logic [DATA_WIDTH-1:0] dmem_wdata ,
    output logic dmem_write ,
    output logic [DATA_WIDTH/8-1:0] dmem_wstrb ,
    output logic dmem_read ,
    input  logic [DATA_WIDTH-1:0] dmem_rdata

) ;

    logic [ADDR_WIDTH-1:0] pc_final ;
    logic [ADDR_WIDTH-1:0] pc_next ; 

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

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pc <= '0;
        end else begin
            pc <= pc_final;
        end
    end

    rv32i_base_instr opcode_e ;
    rv32i_base_instr_type instr_type ;

    assign opcode_e = instr_enum_from_val (instr) ;
    assign instr_type = instr_type_enum_from_instr (opcode_e) ;

    logic [4:0] instr_rs1 ;
    logic [4:0] instr_rs2 ;
    logic [4:0] instr_rd ;

    logic [DATA_WIDTH-1:0] rs1_data ;
    logic [DATA_WIDTH-1:0] rs2_data ;

    logic [DATA_WIDTH-1:0] regfile_wdata ;
    logic regfile_wen ;

    assign instr_rs1 = instr [19:15] ;
    assign instr_rs2 = instr [24:20] ;
    assign instr_rd = instr [11:7] ;

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
        .instr(instr),
        .imm_out(imm_value)
    ) ;

    logic [DATA_WIDTH-1:0] alu_src_a ;
    logic [DATA_WIDTH-1:0] alu_src_b ;
    logic [DATA_WIDTH-1:0] alu_result ;

    alu_input_logic #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) alu_input_logic_inst (
        .pc(pc),
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

endmodule

`endif // SINGLE_CYCLE_CORE_SV
