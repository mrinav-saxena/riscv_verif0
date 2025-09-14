// imm_gen.sv
`ifndef IMM_GEN_SV
`define IMM_GEN_SV

module imm_gen #(
    parameter int DATA_WIDTH = 32
)(
    input  logic [31:0] instr_i,
    output logic [DATA_WIDTH-1:0] imm_out_o
);

    logic [DATA_WIDTH-1:0] i_imm;  // I-type immediate (12 bits, sign-extended)
    logic [DATA_WIDTH-1:0] s_imm;  // S-type immediate (12 bits, sign-extended)
    logic [DATA_WIDTH-1:0] b_imm;  // B-type immediate (13 bits, sign-extended, LSB=0)
    logic [DATA_WIDTH-1:0] u_imm;  // U-type immediate (20 bits, sign-extended)
    logic [DATA_WIDTH-1:0] j_imm;  // J-type immediate (21 bits, sign-extended, LSB=0)

    assign i_imm = {{20{instr_i[31]}}, instr_i[31:20]};
    assign s_imm = {{20{instr_i[31]}}, instr_i[31:25], instr_i[11:7]};
    assign b_imm = {{19{instr_i[31]}}, instr_i[31], instr_i[7], instr_i[30:25], instr_i[11:8], 1'b0};
    assign u_imm = {instr_i[31:12], 12'b0};
    assign j_imm = {{11{instr_i[31]}}, instr_i[31], instr_i[19:12], instr_i[20], instr_i[30:21], 1'b0};

    always @(*) begin
        if ((instr_i[6:0] == 7'b1100111) || (instr_i[6:0] == 7'b0000011) || (instr_i[6:0] == 7'b0010011)) begin
            imm_out_o = i_imm;
        end else if (instr_i[6:0] == 7'b0100011) begin
            imm_out_o = s_imm;
        end else if (instr_i[6:0] == 7'b1100011) begin
            imm_out_o = b_imm;
        end else if ((instr_i[6:0] == 7'b0110111) || (instr_i[6:0] == 7'b0010111)) begin
            imm_out_o = u_imm;
        end else if (instr_i[6:0] == 7'b1101111) begin
            imm_out_o = j_imm;
        end else begin
            imm_out_o = {DATA_WIDTH{1'b0}};
        end
    end

endmodule

`endif // IMM_GEN_SV
