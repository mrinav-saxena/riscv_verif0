module tb (
  input logic clk,
  input logic rst_n
) ;

  bit deadbeef_written = 0;

  // DUT
  single_cycle_core #(
    .ADDR_WIDTH(32),
    .DATA_WIDTH(32)
  ) dut (
    .clk       (clk),
    .rst_n     (rst_n)
  );

  /*
  // Wave dump
  initial begin
    $dumpfile("waves.vcd");
    $dumpvars(2, tb);
  end
  */

  // HOOK 1: Monitor for ebreak instruction (0x00100073) in instr_reg
  // This indicates the test has completed and reached the final instruction
  
  always @(posedge clk) begin
    if ((dut.opcode_e == SW) && (dut.rs2_data == 32'h00100073)) begin
      $display("[TB] 0xdeadbeef - test completed!", $time);
      // Wait a few cycles for any final writes, then finish simulation
      repeat(5) @(posedge clk);
      $finish;
    end
  end
  

  // HOOK 2: Monitor data memory completion signal
  // Monitor the test_complete location in data memory
  always @(posedge clk) begin
    // Monitor data memory location where test_complete is stored
    // Based on the C code, test_complete is at the end of the data section
    if (dut.i_dmem.mem_array[0] == 32'hDEADBEEF) begin
      deadbeef_written = 1;
      $display("[TB] Data memory completion signal detected at time %t", $time);
      repeat(5) @(posedge clk);
      $writememh("res_dmem.hex", dut.i_dmem.mem_array, 0, dut.i_dmem.DEPTH) ;
      $finish;
    end
  end

  // Load instruction memory and data memory from HEX files
  initial begin
    @ (posedge rst_n);
    $readmemh("imem.hex", dut.i_imem.mem_array);
    $readmemh("dmem.hex", dut.i_dmem.mem_array);
    $display("[TB] Loaded imem.hex and dmem.hex");
  end

endmodule

