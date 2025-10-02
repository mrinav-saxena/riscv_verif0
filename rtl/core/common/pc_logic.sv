`ifndef PC_LOGIC_SV
`define PC_LOGIC_SV

module pc_logic #(parameter int ADDR_WIDTH = 32, DATA_WIDTH = 32) (

    input logic [ADDR_WIDTH-1:0] pc_i ,
    input rv32i_base_instr opcode_i ,
    input logic [DATA_WIDTH-1:0] imm_value_i ,
    input logic [DATA_WIDTH-1:0] alu_result_i ,
    input logic alu_eq_i ,
    input logic alu_lt_i ,
    input logic alu_ltu_i ,

    output logic [ADDR_WIDTH-1:0] pc_final_o ,
    output logic [ADDR_WIDTH-1:0] pc_next_o 

) ;

    logic branch_taken;

    assign pc_next_o = pc_i + 'd4 ;
    assign branch_taken = 
        ((opcode_i == BEQ) && (alu_eq_i == 1'b1)) ||
        ((opcode_i == BNE) && (alu_eq_i == 1'b0)) ||
        ((opcode_i == BLT) && (alu_lt_i == 1'b1)) ||
        ((opcode_i == BGE) && (alu_lt_i == 1'b0)) ||
        ((opcode_i == BLTU) && (alu_ltu_i == 1'b1)) ||
        ((opcode_i == BGEU) && (alu_ltu_i == 1'b0))
    ;

    always @(*) begin
        if (opcode_i == JAL) begin
            pc_final_o = pc_i + imm_value_i;
        end else if (opcode_i == JALR) begin
            pc_final_o = alu_result_i;
        end else if (branch_taken) begin
            pc_final_o = pc_i + imm_value_i;
        end else begin
            pc_final_o = pc_next_o;
        end
    end

endmodule : pc_logic

`endif