// single_cycle_core.sv
`ifndef SINGLE_CYCLE_CORE_SV
`define SINGLE_CYCLE_CORE_SV

module single_cycle_core #(
  parameter int ADDR_WIDTH = 32,
  parameter int DATA_WIDTH = 32
)(
  input  logic clk,
  input  logic rst_n
  // TODO: Add more port declarations
  // output logic [ADDR_WIDTH-1:0] pc,
  // output logic [ADDR_WIDTH-1:0] mem_addr,
  // output logic [DATA_WIDTH-1:0] mem_wdata,
  // output logic mem_write,
  // output logic mem_read,
  // input  logic [DATA_WIDTH-1:0] mem_rdata,
  // input  logic mem_ready
);

  logic [31:0] pc ;
  logic [31:0] pc_next ; 

  assign pc_next = pc + 32'h4 ;

  always @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
      pc <= '0;
    end else begin
      if (opcode_e == JAL) begin
        pc <= pc + imm_value;
      end else if (opcode_e == JALR) begin
        pc <= alu_result;
      end else if ((opcode_e == BEQ) && (alu_eq == 1'b1)) begin
        pc <= pc + imm_value;
      end else if ((opcode_e == BNE) && (alu_eq == 1'b0)) begin
        pc <= pc + imm_value;
      end else if ((opcode_e == BLT) && (alu_lt == 1'b1)) begin
        pc <= pc + imm_value;
      end else if ((opcode_e == BGE) && (alu_lt == 1'b0)) begin
        pc <= pc + imm_value;
      end else if ((opcode_e == BLTU) && (alu_ltu == 1'b1)) begin
        pc <= pc + imm_value;
      end else if ((opcode_e == BGEU) && (alu_ltu == 1'b0)) begin
        pc <= pc + imm_value;
      end else begin
        pc <= pc_next;
      end
    end
  end

  // instr fetch

  logic [31:0] instr_reg;

  mem_zerolat #(
    .DATA_WIDTH(DATA_WIDTH),
    .DEPTH(1024)
  ) i_imem (
    .clk    (clk),
    .rst_n  (rst_n),
    .addr   (pc[31:2]),
    .wdata  ({DATA_WIDTH{1'b0}}),
    .wstrb  ({DATA_WIDTH/8{1'b0}}),
    .write  (1'b0),
    .read   (1'b1),
    .rdata  (instr_reg)
  );

  // instr decode

  rv32i_base_instr opcode_e ;
  rv32i_base_instr_type instr_type ;

  assign opcode_e = instr_enum_from_val (instr_reg) ;
  assign instr_type = instr_type_enum_from_instr (opcode_e) ;

  logic [4:0] instr_rs1 ;
  logic [4:0] instr_rs2 ;
  logic [4:0] instr_rd ;

  logic [DATA_WIDTH-1:0] rs1_data ;
  logic [DATA_WIDTH-1:0] rs2_data ;

  logic [DATA_WIDTH-1:0] regfile_wdata ;
  logic regfile_wen ;

  assign instr_rs1 = instr_reg [19:15] ;
  assign instr_rs2 = instr_reg [24:20] ;
  assign instr_rd = instr_reg [11:7] ;

  assign regfile_wen = instr_type inside {R, I, U, J} ;
  assign regfile_wdata =
    instr_type == R ? alu_result :
    instr_type == I ?
      (opcode_e == JALR) ? pc_next :
      (instr_reg[6:0] == 7'b0000011) ?
        (instr_reg[14:12] == 3'b000) ? {{(DATA_WIDTH-8){mem_rdata[7]}}, mem_rdata[7:0]} : // LB
        (instr_reg[14:12] == 3'b001) ? {{(DATA_WIDTH-16){mem_rdata[15]}}, mem_rdata[15:0]} : // LH
        (instr_reg[14:12] == 3'b010) ? mem_rdata : // LW
        (instr_reg[14:12] == 3'b100) ? {{(DATA_WIDTH-8){1'b0}}, mem_rdata[7:0]} : // LBU
        (instr_reg[14:12] == 3'b101) ? {{(DATA_WIDTH-16){1'b0}}, mem_rdata[15:0]} : // LHU
        'd0 :
      (instr_reg[6:0] == 7'b0010011) ? alu_result : // arith/logic immediate instructions
      'd0 :
    (opcode_e == JAL) ? pc_next :
    (opcode_e == LUI) ? imm_value :
    (opcode_e == AUIPC) ? alu_result :
    'd0
  ;

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

  // Immediate generation
  logic [DATA_WIDTH-1:0] imm_value;
  logic alu_imm_source ;

  assign alu_imm_source = instr_type inside {I, S, U, J} ; // removed B (imm is valid, but not used in the ALU)

  imm_gen #(
    .DATA_WIDTH(DATA_WIDTH)
  ) imm_gen_inst (
    .instr(instr_reg),
    .imm_out(imm_value)
  );

  // execute

  logic [DATA_WIDTH-1:0] alu_result ;
  logic alu_eq ;
  logic alu_lt ;
  logic alu_ltu ;

  logic [DATA_WIDTH-1:0] alu_src_a ;
  logic [DATA_WIDTH-1:0] alu_src_b ;

  assign alu_src_a = (opcode_e == AUIPC) ? pc : rs1_data ;
  assign alu_src_b = alu_imm_source ? imm_value : rs2_data ;

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

  logic [DATA_WIDTH/8-1:0] mem_wstrb ;
  logic mem_write ;
  logic mem_read ;
  logic [DATA_WIDTH-1:0] mem_rdata ;
  logic [DATA_WIDTH-1:0] mem_wdata ;

  assign mem_write = (instr_type == S) ;
  assign mem_wstrb =
    (opcode_e == SB) ? (1'b1 << alu_result[1:0]) :
    (opcode_e == SH) ? (2'b11 << (alu_result[1]+1)) : 
    (opcode_e == SW) ? {DATA_WIDTH/8{1'b1}} :
    {DATA_WIDTH/8{1'b0}}
  ;
  assign mem_wdata = rs2_data << (
    opcode_e == SB ? (alu_result[1:0] * 8) :
    opcode_e == SH ? (alu_result[1] * 16) :
    0 // for SW or otherwise
  );

  assign mem_read = (instr_reg[6:0] == 7'b0000011) ;

  // TODO: Add memory access logic
  mem_zerolat #(
    .DATA_WIDTH(DATA_WIDTH),
    .DEPTH(1024)
  ) i_dmem (
    .clk    (clk),
    .rst_n  (rst_n),
    .addr   (alu_result[11:2]),
    .wdata  (mem_wdata),
    .wstrb  (mem_wstrb),
    .write  (mem_write),
    .read   (mem_read),
    .rdata  (mem_rdata)
  );

endmodule

`endif // SINGLE_CYCLE_CORE_SV
