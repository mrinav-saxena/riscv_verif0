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
        .rs1_i(instr_rs1),
        .rs2_i(instr_rs2),
        .rd_i(instr_rd),
        .wdata_i(regfile_wdata),
        .wen_i(regfile_wen),
        .wstrb_i({DATA_WIDTH/8{1'b1}}),
        .rs1_data_o(rs1_data),
        .rs2_data_o(rs2_data)
    ) ;

    logic [DATA_WIDTH-1:0] imm_value;

    imm_gen #(
        .DATA_WIDTH(DATA_WIDTH)
    ) imm_gen_inst (
        .instr_i(instr),
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

endmodule

`endif // SINGLE_CYCLE_CORE_SV
