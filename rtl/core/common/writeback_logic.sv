`ifndef WRITEBACK_LOGIC_SV
`define WRITEBACK_LOGIC_SV

module writeback_logic #(
    parameter int DATA_WIDTH = 32
) (
    input logic [DATA_WIDTH-1:0] alu_result_i,
    input rv32i_base_instr_type instr_type_i,
    input rv32i_base_instr opcode_i,
    input logic [DATA_WIDTH-1:0] pc_next_i,
    input logic [DATA_WIDTH-1:0] imm_value_i,
    input logic [DATA_WIDTH-1:0] dmem_rdata_i,
    output logic regfile_wen_o,
    output logic [DATA_WIDTH-1:0] regfile_wdata_o
) ;

    logic [DATA_WIDTH-1:0] shifted_mem_rdata;

    assign shifted_mem_rdata =
        (opcode_i inside {LB, LBU}) ? dmem_rdata_i >> (alu_result_i[1:0] * 8) : 
        (opcode_i inside {LH, LHU}) ? dmem_rdata_i >> (alu_result_i[1] * 16) :
        dmem_rdata_i
    ;

    assign regfile_wen_o = instr_type_i inside {R, I, U, J} ;
    assign regfile_wdata_o =
        instr_type_i == R ? alu_result_i :
        instr_type_i == I ?
            (opcode_i == JALR) ? pc_next_i :
            (opcode_i == LB) ? {{(DATA_WIDTH-8){shifted_mem_rdata[7]}}, shifted_mem_rdata[7:0]} :
            (opcode_i == LH) ? {{(DATA_WIDTH-16){shifted_mem_rdata[15]}}, shifted_mem_rdata[15:0]} :
            (opcode_i == LW) ? shifted_mem_rdata :
            (opcode_i == LBU) ? {{(DATA_WIDTH-8){1'b0}}, shifted_mem_rdata[7:0]} : 
            (opcode_i == LHU) ? {{(DATA_WIDTH-16){1'b0}}, shifted_mem_rdata[15:0]} :
            alu_result_i :
        (opcode_i == JAL) ? pc_next_i :
        (opcode_i == LUI) ? imm_value_i :
        (opcode_i == AUIPC) ? alu_result_i :
        'd0
    ;

endmodule : writeback_logic

`endif