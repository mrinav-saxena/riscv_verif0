module tb (
  input logic clk,
  input logic rst_n
) ;

  bit deadbeef_written = 1'b0;
  integer cycle_count ;

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

  always @(posedge clk) begin
    if ((dut.opcode_e == SW) && (dut.rs2_data == 32'hdeadbeef)) begin
      deadbeef_written = 1'b1 ; 
      $display("[TB] 0xdeadbeef - test completed!", $time);
      repeat(5) @(posedge clk);
      $writememh("res_dmem.hex", dut.i_dmem.mem_array, 0, dut.i_dmem.DEPTH) ;
      $finish;
    end else begin
      cycle_count ++ ;
      if (cycle_count % 100 == 0) begin
        $display("[TB] cycle_count is %0d. writing memory for debug purposes.", cycle_count);
        $writememh("res_dmem.hex", dut.i_dmem.mem_array, 0, dut.i_dmem.DEPTH) ;
      end
    end
  end
  

  // Load instruction memory and data memory from HEX files
  initial begin
    cycle_count = 0 ;
    @ (posedge rst_n);
    $readmemh("imem.hex", dut.i_imem.mem_array);
    $readmemh("dmem.hex", dut.i_dmem.mem_array);
    $display("[TB] Loaded imem.hex and dmem.hex");
  end

endmodule

