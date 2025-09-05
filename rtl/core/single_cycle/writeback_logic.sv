`ifndef WRITEBACK_LOGIC_SV
`define WRITEBACK_LOGIC_SV

module writeback_logic #(
    parameter int DATA_WIDTH = 32
) (
    input logic [DATA_WIDTH-1:0] alu_result,
    input rv32i_base_instr_type instr_type,
    input rv32i_base_instr opcode_e,
    input logic [DATA_WIDTH-1:0] pc_next,
    input logic [DATA_WIDTH-1:0] imm_value,
    input logic [DATA_WIDTH-1:0] dmem_rdata,
    output logic regfile_wen,
    output logic [DATA_WIDTH-1:0] regfile_wdata
) ;

    logic [DATA_WIDTH-1:0] shifted_mem_rdata;

    assign shifted_mem_rdata =
        (opcode_e inside {LB, LBU}) ? dmem_rdata >> (alu_result[1:0] * 8) : 
        (opcode_e inside {LH, LHU}) ? dmem_rdata >> (alu_result[1] * 16) :
        dmem_rdata
    ;

    assign regfile_wen = instr_type inside {R, I, U, J} ;
    assign regfile_wdata =
        instr_type == R ? alu_result :
        instr_type == I ?
            (opcode_e == JALR) ? pc_next :
            (opcode_e == LB) ? {{(DATA_WIDTH-8){shifted_mem_rdata[7]}}, shifted_mem_rdata[7:0]} :
            (opcode_e == LH) ? {{(DATA_WIDTH-16){shifted_mem_rdata[15]}}, shifted_mem_rdata[15:0]} :
            (opcode_e == LW) ? shifted_mem_rdata :
            (opcode_e == LBU) ? {{(DATA_WIDTH-8){1'b0}}, shifted_mem_rdata[7:0]} : 
            (opcode_e == LHU) ? {{(DATA_WIDTH-16){1'b0}}, shifted_mem_rdata[15:0]} :
            alu_result :
        (opcode_e == JAL) ? pc_next :
        (opcode_e == LUI) ? imm_value :
        (opcode_e == AUIPC) ? alu_result :
        'd0
    ;

endmodule : writeback_logic

`endif