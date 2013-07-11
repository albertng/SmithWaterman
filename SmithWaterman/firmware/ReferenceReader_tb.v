/*  File Name        : ReferenceReader_tb.v
 *  Description      : Reference reader test bench
 *
 *  Revision History :
 *      Albert Ng   Jul 11 2013     Initial Revision
 *
 */

module ReferenceReader_tb;

	// Inputs
	reg clk;
	reg rst;
	reg [24:0] ref_addr_in;
	reg [24:0] ref_length_in;
	reg ref_info_valid_in;
	reg ref_seq_block_rdy_in;
	reg rd_info_rdy_in;
	reg [511:0] rd_data_in;
	reg rd_data_valid_in;

	// Outputs
	wire [511:0] ref_seq_block_out;
	wire ref_seq_block_valid_out;
	wire [5:0] rd_id_out;
	wire [31:0] rd_addr_out;
	wire [7:0] rd_len_out;
	wire rd_info_valid_out;
	wire rd_data_rdy_out;

    reg [24:0] ref_addr1;
    reg [24:0] ref_length1;
    reg [511:0] rd_data1[3:0];
    
    reg [24:0] ref_addr2;
    reg [24:0] ref_length2;
    reg [511:0] rd_data2[2:0];
    
    reg [24:0] ref_addr3;
    reg [24:0] ref_length3;
    reg [511:0] rd_data3[0:0];
    
    reg [24:0] ref_addr4;
    reg [24:0] ref_length4;
    reg [511:0] rd_data4[18:0];
    
	// Instantiate the Unit Under Test (UUT)
	ReferenceReader uut (
		.clk(clk), 
		.rst(rst), 
		.ref_addr_in(ref_addr_in), 
		.ref_length_in(ref_length_in), 
		.ref_info_valid_in(ref_info_valid_in), 
		.ref_seq_block_out(ref_seq_block_out), 
		.ref_seq_block_valid_out(ref_seq_block_valid_out), 
		.ref_seq_block_rdy_in(ref_seq_block_rdy_in), 
		.rd_id_out(rd_id_out), 
		.rd_addr_out(rd_addr_out), 
		.rd_len_out(rd_len_out), 
		.rd_info_valid_out(rd_info_valid_out), 
		.rd_info_rdy_in(rd_info_rdy_in), 
		.rd_data_in(rd_data_in), 
		.rd_data_valid_in(rd_data_valid_in), 
		.rd_data_rdy_out(rd_data_rdy_out)
	);

    integer i;
	initial begin
        ref_addr1 <= 255;
        ref_length1 <= 4;
        rd_data1[0] <= 0;
        rd_data1[1] <= 1;
        rd_data1[2] <= 2;
        rd_data1[3] <= 3;
    
        ref_addr2 <= 511;
        ref_length2 <= 3;
        rd_data2[0] <= 4;
        rd_data2[1] <= 5;
        rd_data2[2] <= 6;
   
        ref_addr3 <= 767;
        ref_length3 <= 1;
        rd_data3[0] <= 7;
   
        ref_addr4 <= 1023;
        ref_length4 <= 19;
        for (i = 0; i < 19; i = i + 1) begin
            rd_data4[i] <= i + 8;
        end
   
		// Initialize Inputs
		clk <= 0;
		rst <= 1;
		ref_addr_in <= 0;
		ref_length_in <= 0;
		ref_info_valid_in <= 0;
		ref_seq_block_rdy_in <= 0;
		rd_info_rdy_in <= 0;
		rd_data_in <= 0;
		rd_data_valid_in <= 0;
        #20;
        rst <= 0;

        // Wait_ref_info_valid
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_addr_in <= ref_addr1;
        ref_length_in <= ref_length1;
        ref_info_valid_in <= 1;
        #10;
        
        // Wait_ref_info_valid, ref info buffer loaded
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_info_valid_in <= 0;
        #10;

        // Send_rd_info
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 0)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        #10;
        
        // Wait_rd_info_rdy
        for (i = 0; i < 3; i = i + 1) begin
            if (ref_seq_block_valid_out != 0)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (rd_info_valid_out != 1)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_addr_out != {7'b0, ref_addr1})
                $display("@%0dns rd_addr_out error", $time);
            if (rd_id_out != 0)
                $display("@%0dns rd_id_out error", $time);
            if (rd_len_out != 2)
                $display("@%0dns rd_len_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            #10;
        end
        
        // Wait_rd_info_rdy
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 0)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

        // Send_rd_info
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1 + 1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 1)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 0;
        #10;
        
        // Wait_rd_info_rdy
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1 + 1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 1)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

        // Send_rd_info
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1 + 2})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 2)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 0;
        #10;
        
        // Wait_rd_info_rdy
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1 + 2})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 2)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

        // Send_rd_info
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1 + 3})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 3)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 0;
        #10;
        
        // Wait_rd_info_rdy
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1 + 3})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 3)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

        // Wait_ref_info_valid
        for (i = 0; i < 2; i = i + 1) begin
            if (ref_seq_block_valid_out != 0)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            #10;
        end
        
        // Wait_ref_info_valid
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_addr_in <= ref_addr2;
        ref_length_in <= ref_length2;
        ref_info_valid_in <= 1;
        #10;
        
        // Wait_ref_info_valid, ref info buffer loaded
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_info_valid_in <= 0;
        #10;
        
        // Send_rd_info
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 4)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        #10;
        
        // Wait_rd_info_rdy
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 4)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

        // Send_rd_info, latch new ref info
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2 + 1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 5)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 0;
        ref_addr_in <= ref_addr3;
        ref_length_in <= ref_length3;
        ref_info_valid_in <= 1;
        #10;
        
        // Wait_rd_info_rdy, ref info buffer loaded
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2 + 1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 5)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 1;
        ref_info_valid_in <= 0;
        #10;

        // Send_rd_info
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2 + 2})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 6)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 0;
        #10;
        
        // Wait_rd_info_rdy
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2 + 2})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 6)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

        // Wait_ref_info_valid
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        #10;

        // Send_rd_info
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr3})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 7)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        #10;
        
        // Wait_rd_info_rdy
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr3})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 7)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 2)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

        // Wait_ref_info_valid
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        rd_info_rdy_in <= 0;
        #10;

        // Send read data
        rd_data_in <= rd_data1[0];
        rd_data_valid_in <= 1;
        #1;
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        #9;
        
        // Wait 2 clock FIFO empty latency
        for (i = 0; i < 2; i = i + 1) begin
            rd_data_valid_in <= 0;
            #1;
            if (ref_seq_block_valid_out != 0)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            #9;
        end
        
        // Check read data valid
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[0])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        #10;
            
        // Send read data without dequeuing
        rd_data_in <= rd_data1[1];
        rd_data_valid_in <= 1;
        #1;
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[0])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        #9;
        
        // Send read data without dequeuing
        rd_data_in <= rd_data1[2];
        rd_data_valid_in <= 1;
        #1;
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[0])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        #9;
        
        // Dequeue
        rd_data_valid_in <= 0;
        #1;
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[0])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 1;
        #9;
        
        // Acknowledge dequeue
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[1])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 0;
        #10;
        
        // Dequeue
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[1])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 1;
        #10;

        // Acknowledge Dequeue
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[2])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 0;
        #10;

        // Dequeue
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[2])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 1;
        #10;

        // Acknowledge dequeue, empty
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 0;
        #10;

        // Send rest of read data
        rd_data_in <= rd_data1[3];
        rd_data_valid_in <= 1;
        #1;
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        #9;

        for (i = 0; i < 2; i = i + 1) begin
            rd_data_in <= rd_data2[i];
            rd_data_valid_in <= 1;
            #1;
            if (ref_seq_block_valid_out != 0)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 1)
                $display("@%0dns rd_data_rdy_out error", $time);
            #9;
        end

        rd_data_in <= rd_data2[2];
        rd_data_valid_in <= 1;
        #1;
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[3])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        #9;

        for (i = 0; i < 1; i = i + 1) begin
            rd_data_in <= rd_data3[i];
            rd_data_valid_in <= 1;
            #1;
            if (ref_seq_block_valid_out != 1)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (ref_seq_block_out != rd_data1[3])
                $display("@%0dns ref_seq_block_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 1)
                $display("@%0dns rd_data_rdy_out error", $time);
            #9;
        end
        
        // Dequeue rest of read data
        rd_data_valid_in <= 0;
        #1;
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data1[3])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 1;
        #9;
        
        for (i = 0; i < 3; i = i + 1) begin
            if (ref_seq_block_valid_out != 1)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (ref_seq_block_out != rd_data2[i])
                $display("@%0dns ref_seq_block_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            ref_seq_block_rdy_in <= 1;
            #10;
        end
        
        for (i = 0; i < 1; i = i + 1) begin
            if (ref_seq_block_valid_out != 1)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (ref_seq_block_out != rd_data3[i])
                $display("@%0dns ref_seq_block_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            ref_seq_block_rdy_in <= 1;
            #10;
        end
        
        // Acknowledge dequeue, empty
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 0;
        #10;

        // Send lots of read requests
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_addr_in <= ref_addr4;
        ref_length_in <= ref_length4;
        ref_info_valid_in <= 1;
        #10;

        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_info_valid_in <= 0;
        #10;

        for (i = 0; i < 19; i = i + 1) begin
            if (ref_seq_block_valid_out != 0)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (rd_info_valid_out != 1)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_addr_out != {7'b0, ref_addr4 + i})
                $display("@%0dns rd_addr_out error", $time);
            if (rd_id_out != i + 8)
                $display("@%0dns rd_id_out error", $time);
            if (rd_len_out != 2)
                $display("@%0dns rd_len_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            rd_info_rdy_in <= 0;
            #10;
            
            if (ref_seq_block_valid_out != 0)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (rd_info_valid_out != 1)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_addr_out != {7'b0, ref_addr4 + i})
                $display("@%0dns rd_addr_out error", $time);
            if (rd_id_out != i + 8)
                $display("@%0dns rd_id_out error", $time);
            if (rd_len_out != 2)
                $display("@%0dns rd_len_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            rd_info_rdy_in <= 1;
            #10;
        end
        
        // Fill ref info buffer
        rd_info_rdy_in <= 0;
        rd_data_in <= rd_data4[0];
        rd_data_valid_in <= 1;
        #1;
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        #9;
        
        for (i = 1; i < 3; i = i + 1) begin
            rd_data_in <= rd_data4[i];
            rd_data_valid_in <= 1;
            #1;
            if (ref_seq_block_valid_out != 0)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 1)
                $display("@%0dns rd_data_rdy_out error", $time);
            #9;
        end
        
        for (i = 3; i < 18; i = i + 1) begin
            rd_data_in <= rd_data4[i];
            rd_data_valid_in <= 1;
            #1;
            if (ref_seq_block_valid_out != 1)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (ref_seq_block_out != rd_data4[0])
                $display("@%0dns ref_seq_block_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 1)
                $display("@%0dns rd_data_rdy_out error", $time);
            #9;
        end
        
        // Check buffer full, not accepting more read data
        rd_data_in <= rd_data4[18];
        rd_data_valid_in <= 1;
        #1;
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data4[0])
            $display("@%0dns ref_seq_block_out error", $time);            
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        #9;
        
        // Dequeue
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data4[0])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 1;
        #10;
        
        rd_data_in <= rd_data4[18];
        rd_data_valid_in <= 1;
        #1;
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data4[1])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 0;
        #9;
        
        rd_data_valid_in <= 0;
        #1;
        if (ref_seq_block_valid_out != 1)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (ref_seq_block_out != rd_data4[1])
            $display("@%0dns ref_seq_block_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 1;
        #9;
        
        for (i = 2; i < 19; i = i + 1) begin
            if (ref_seq_block_valid_out != 1)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (ref_seq_block_out != rd_data4[i])
                $display("@%0dns ref_seq_block_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            ref_seq_block_rdy_in <= 0;
            #10;
            
            if (ref_seq_block_valid_out != 1)
                $display("@%0dns ref_seq_block_valid_out error", $time);
            if (ref_seq_block_out != rd_data4[i])
                $display("@%0dns ref_seq_block_out error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            ref_seq_block_rdy_in <= 1;
            #10;
        end
        
        if (ref_seq_block_valid_out != 0)
            $display("@%0dns ref_seq_block_valid_out error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        ref_seq_block_rdy_in <= 0;
        #10;
        
		// Wait 100 ns
		#100;
        $display("Tests complete!");
        $finish;
	end
    always begin
        #5 clk = !clk;
    end
endmodule

