`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:28:05 06/05/2013
// Design Name:   fifotest
// Module Name:   /afs/cs.stanford.edu/group/evodevo/u/albertng/SmithWaterman/SmithWaterman/firmware/fifotest_tb.v
// Project Name:  m505lx325
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: fifotest
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module fifotest_tb;

	// Inputs
	reg clk;
	reg rst;
	reg [17:0] din;
	reg wr_en;
	reg rd_en;

	// Outputs
	wire [17:0] dout;
	wire full;
	wire empty;

	// Instantiate the Unit Under Test (UUT)
	fifotest uut (
		.clk(clk), 
		.rst(rst), 
		.din(din), 
		.wr_en(wr_en), 
		.rd_en(rd_en), 
		.dout(dout), 
		.full(full), 
		.empty(empty)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 1;
		din = 0;
		wr_en = 0;
		rd_en = 0;
		#100;
        rst <= 0;
        #100;
        din <= 5;
        wr_en <= 1;
        #10;
        wr_en <= 0;
        #10;
        rd_en <= 1;
        #100;
        $finish;

	end
    
    always begin
        #5 clk = !clk;
    end
    
endmodule

