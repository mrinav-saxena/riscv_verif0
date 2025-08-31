`ifndef REGFILE_SV
`define REGFILE_SV

module regfile #(parameter int DATA_WIDTH = 32, parameter int N_REGS = 32) (
    input logic clk,
    input logic rst_n,
    input logic [4:0] rs1,
    input logic [4:0] rs2,
    input logic [4:0] rd,
    input logic [DATA_WIDTH-1:0] wdata,
    input logic wen,
    input logic [DATA_WIDTH/8 - 1:0] wstrb,
    output logic [DATA_WIDTH-1:0] rs1_data,
    output logic [DATA_WIDTH-1:0] rs2_data
) ;

    logic [DATA_WIDTH-1:0] regs [31:0];

    // reset logic
    genvar i_reg ;
    generate
        for (i_reg = 1 ; i_reg < N_REGS ; i_reg++) begin : i_reg_block
            always @(posedge clk or negedge rst_n) begin
                if (!rst_n) begin
                    regs[i_reg] <= 32'h0;
                end
            end
        end
    endgenerate

    // write logic
    always @(posedge clk) begin
        if (rst_n == 1'b1) begin
            if (wen && (rd != 5'b0)) begin
                regs[rd] <= wdata ;
            end
        end
    end

    // read logic
    assign rs1_data = (rs1 == 5'b0) ? {DATA_WIDTH{1'b0}} : regs[rs1];
    assign rs2_data = (rs2 == 5'b0) ? {DATA_WIDTH{1'b0}} : regs[rs2];

endmodule

`endif
