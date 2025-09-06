`ifndef PC_LOGIC_SV
`define PC_LOGIC_SV

module pc_logic #(parameter int ADDR_WIDTH = 32, DATA_WIDTH = 32) (

    input logic [ADDR_WIDTH-1:0] pc ,
    input rv32i_base_instr opcode_e ,
    input logic [DATA_WIDTH-1:0] imm_value ,
    input logic [DATA_WIDTH-1:0] alu_result ,
    input logic alu_eq ,
    input logic alu_lt ,
    input logic alu_ltu ,

    output logic [ADDR_WIDTH-1:0] pc_final ,
    output logic [ADDR_WIDTH-1:0] pc_next 

) ;

    assign pc_next = pc + 'd4 ;

    always @(*) begin
        if (opcode_e == JAL) begin
            pc_final = pc + imm_value;
        end else if (opcode_e == JALR) begin
            pc_final = alu_result;
        end else if ((opcode_e == BEQ) && (alu_eq == 1'b1)) begin
            pc_final = pc + imm_value;
        end else if ((opcode_e == BNE) && (alu_eq == 1'b0)) begin
            pc_final = pc + imm_value;
        end else if ((opcode_e == BLT) && (alu_lt == 1'b1)) begin
            pc_final = pc + imm_value;
        end else if ((opcode_e == BGE) && (alu_lt == 1'b0)) begin
            pc_final = pc + imm_value;
        end else if ((opcode_e == BLTU) && (alu_ltu == 1'b1)) begin
            pc_final = pc + imm_value;
        end else if ((opcode_e == BGEU) && (alu_ltu == 1'b0)) begin
            pc_final = pc + imm_value;
        end else begin
            pc_final = pc_next;
        end
    end

endmodule : pc_logic

`endif