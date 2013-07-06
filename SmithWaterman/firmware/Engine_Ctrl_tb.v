/*  File Name        : Engine_Ctrl_tb.v
 *  Description      : Testbench for systolic array engine controller
 *
 *  Revision History :
 *      Albert Ng   Jul 03 2013     Initial Revision
 *
 */

module Engine_Ctrl_tb;

	// Inputs
	reg clk;
	reg rst;
	reg stall;
	reg [24:0] ref_length_in;
	reg [24:0] ref_addr_in;
	reg [15:0] num_query_blocks_in;
	reg query_info_valid;
	reg [7:0] query_seq_block_in;
	reg query_seq_block_valid;
	reg [15:0] ref_seq_block_in;
	reg ref_seq_block_valid;

	// Outputs
    wire query_info_rdy_out;
	wire query_seq_block_rdy_out;
	wire [24:0] ref_addr_out;
	wire [24:0] ref_length_out;
	wire ref_info_valid_out;
	wire ref_seq_block_rdy_out;
	wire [7:0] S_out;
	wire [1:0] T_out;
	wire store_S_out;
	wire init_out;
	wire first_query_block_out;
	wire next_first_ref_block_out;
	wire first_ref_block_out;
	wire last_ref_block_out;
	wire last_block_char_out;
	wire bypass_fifo_out;

	// Instantiate the Unit Under Test (UUT)
	Engine_Ctrl #(4, 8) uut (
		.clk(clk), 
		.rst(rst), 
		.stall(stall), 
		.ref_length_in(ref_length_in), 
		.ref_addr_in(ref_addr_in), 
		.num_query_blocks_in(num_query_blocks_in), 
		.query_info_valid(query_info_valid), 
        .query_info_rdy_out(query_info_rdy_out),
		.query_seq_block_in(query_seq_block_in), 
		.query_seq_block_valid(query_seq_block_valid), 
		.query_seq_block_rdy_out(query_seq_block_rdy_out), 
		.ref_addr_out(ref_addr_out), 
		.ref_length_out(ref_length_out), 
		.ref_info_valid_out(ref_info_valid_out), 
		.ref_seq_block_in(ref_seq_block_in), 
		.ref_seq_block_valid(ref_seq_block_valid), 
		.ref_seq_block_rdy_out(ref_seq_block_rdy_out), 
		.S_out(S_out), 
		.T_out(T_out), 
		.store_S_out(store_S_out), 
		.init_out(init_out), 
		.first_query_block_out(first_query_block_out), 
		.next_first_ref_block_out(next_first_ref_block_out), 
		.first_ref_block_out(first_ref_block_out), 
		.last_ref_block_out(last_ref_block_out), 
		.last_block_char_out(last_block_char_out), 
		.bypass_fifo_out(bypass_fifo_out)
	);

    reg [7:0] query1 [2:0];
    reg [15:0] ref1[2:0];
    reg [24:0] ref_length1;
    reg [24:0] ref_addr1;
    reg [15:0] num_query_blocks1;
    
    reg [7:0] query2 [1:0];
    reg [15:0] ref2[0:0];
    reg [24:0] ref_length2;
    reg [24:0] ref_addr2;
    reg [15:0] num_query_blocks2;
    
    reg [7:0] query3 [0:0];
    reg [15:0] ref3[1:0];
    reg [24:0] ref_length3;
    reg [24:0] ref_addr3;
    reg [15:0] num_query_blocks3;
    
    integer i, j;
	initial begin
        stall <= 0;
        
        $display("3 query blocks, 2 ref blocks test");
        query1[0] <= 8'b00011011;
        query1[1] <= 8'b01101001;
        query1[2] <= 8'b01110100;
        ref1[0] <= 16'b0110100100110001;
        ref1[1] <= 16'b1010101011110010;
        ref1[2] <= 16'b0101000111101011;
        ref_length1 <= 3;
        ref_addr1 <= 0;
        num_query_blocks1 <= 3;
        
		// Initialize Inputs
		clk <= 0;
		rst <= 1;
		stall <= 0;
		ref_length_in <= 0;
		ref_addr_in <= 0;
		num_query_blocks_in <= 0;
		query_info_valid <= 0;
		query_seq_block_in <= 0;
		query_seq_block_valid <= 0;
		ref_seq_block_in <= 0;
		ref_seq_block_valid <= 0;
        #20;
        rst <= 0;
        #10;
        
        for (i = 0; i < 2; i = i + 1) begin
            // Wait_query_info_valid
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 1)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 0)
                $display("@%0dns Test 1: init_out error", $time);
            if (first_query_block_out != 1)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 1)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 1)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 0)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        
        // Wait_query_info_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        ref_length_in <= ref_length1;
        ref_addr_in <= ref_addr1;
        num_query_blocks_in <= num_query_blocks1;
        query_info_valid <= 1;
        #10;
        
        // Latch_query_info
        if (query_info_rdy_out != 1)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        
        // Wait_query_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        query_info_valid <= 0;
        query_seq_block_in <= query1[0];
        query_seq_block_valid <= 1;
        #10;
        
        // Latch_query_seq_block
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 1)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        
        // Wait_query_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        query_seq_block_valid <= 0;
        #10;
        
        // Wait_query_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        query_seq_block_in <= query1[1];
        query_seq_block_valid <= 1;
        #10;
        
        // Latch_query_seq_block
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 1)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        
        // Wait_query_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        query_seq_block_in <= query1[2];
        #10;
        
        // Latch_query_seq_block
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 1)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        
        // Wait_rd_rdy
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        query_seq_block_valid <= 0;  
        #10;
        
        // Send_ref_addr
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_addr_out != ref_addr1)
            $display("@%0dns Test 1: ref_addr_out error", $time);
        if (ref_length_out != 3)
            $display("@%0dns Test 1: ref_length_out error", $time);
        if (ref_info_valid_out != 1)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        
        // Wait_ref_seq_block_valid
        for (i = 0; i < 5; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 1)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 0)
                $display("@%0dns Test 1: init_out error", $time);
            if (first_query_block_out != 1)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 1)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 1)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 0)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        
        // Wait_ref_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        ref_seq_block_in = ref1[0];
        ref_seq_block_valid = 1;
        #10;
        
        // Latch_ref
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        ref_seq_block_valid = 0;
        #10;

        // Advance_BCC
        // Query block 0, Ref block 0
        for (i = 0; i < 7; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 0)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 1)
                $display("@%0dns Test 1: init_out error", $time);
            if (first_query_block_out != 1)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 1)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 1)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 0)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 0)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 1)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 1)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        
        // Advance_BCC
        // Query block 1, Ref block 0
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        for (i = 0; i < 7; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 0)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 1)
                $display("@%0dns Test 1: init_out error", $time);
            if (first_query_block_out != 0)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 1)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 1)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 0)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 0)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 1)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 1)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        ref_seq_block_valid = 1;
        ref_seq_block_in = ref1[1];
        #10;    
        
        // Advance_BCC
        // Query block 2, Ref block 0
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        for (i = 0; i < 7; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 0)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 1)
                $display("@%0dns Test 1: init_out error", $time);
            if (first_query_block_out != 0)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 1)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 1)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 0)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 0)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 1)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 1)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;    
        
        // Latch_ref
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;

        
        // Advance_BCC
        // Query block 0, Ref block 1
        ref_seq_block_in = ref1[2];
        for (i = 0; i < 7; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 0)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 1)
                $display("@%0dns Test 1: init_out error", $time);
            if (T_out != ref1[1][i*2 + 1 -: 2])
                $display("@%0dns Test 1: T_out error", $time);
            if (first_query_block_out != 1)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 0)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 0)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 0)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 0)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 1)
            $display("@%0dns Test 1: init_out error", $time);
        if (T_out != ref1[1][15:14])
            $display("@%0dns Test 1: T_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 1)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        
        // Advance_BCC
        // Query block 1, Ref block 1
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        for (i = 0; i < 7; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 0)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 1)
                $display("@%0dns Test 1: init_out error", $time);
            if (T_out != ref1[1][i*2 + 1 -: 2])
                $display("@%0dns Q1R1 Test 1: T_out error %d", $time, i);
            if (first_query_block_out != 0)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 0)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 0)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 0)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 0)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 1)
            $display("@%0dns Test 1: init_out error", $time);
        if (T_out != ref1[1][15:14])
            $display("@%0dns Q1R1 End Test 1: T_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 1)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;    
        
        // Advance_BCC
        // Query block 2, Ref block 1
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        for (i = 0; i < 7; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 0)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 1)
                $display("@%0dns Test 1: init_out error", $time);
            if (T_out != ref1[1][i*2 + 1 -: 2])
                $display("@%0dns Test 1: T_out error", $time);
            if (first_query_block_out != 0)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 0)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 0)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 0)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 0)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 1)
            $display("@%0dns Test 1: init_out error", $time);
        if (T_out != ref1[1][15:14])
            $display("@%0dns Test 1: T_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 1)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;    
        
        // Latch_ref
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 1)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;

        
        // Advance_BCC
        // Query block 0, Ref block 2
        ref_seq_block_valid = 0;
        for (i = 0; i < 7; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 0)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 1)
                $display("@%0dns Test 1: init_out error", $time);
            if (T_out != ref1[2][i*2 + 1 -: 2])
                $display("@%0dns Test 1: T_out error", $time);
            if (first_query_block_out != 1)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 0)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 0)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 1)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 0)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 1)
            $display("@%0dns Test 1: init_out error", $time);
        if (T_out != ref1[2][15:14])
            $display("@%0dns Test 1: T_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 1)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 1)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        
        // Advance_BCC
        // Query block 1, Ref block 2
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 1)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        for (i = 0; i < 7; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 0)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 1)
                $display("@%0dns Test 1: init_out error", $time);
            if (T_out != ref1[2][i*2 + 1 -: 2])
                $display("@%0dns Test 1: T_out error", $time);
            if (first_query_block_out != 0)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 0)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 0)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 1)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 0)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 1)
            $display("@%0dns Test 1: init_out error", $time);
        if (T_out != ref1[2][15:14])
            $display("@%0dns Test 1: T_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 1)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 1)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;    
        
        // Advance_BCC
        // Query block 2, Ref block 2
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 1: init_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 0)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 1)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;
        for (i = 0; i < 7; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 0)
                $display("@%0dns Test 1: store_S_out error", $time);
            if (init_out != 1)
                $display("@%0dns Test 1: init_out error", $time);
            if (T_out != ref1[2][i*2 + 1 -: 2])
                $display("@%0dns Test 1: T_out error", $time);
            if (first_query_block_out != 0)
                $display("@%0dns Test 1: first_query_block_out error", $time);
            if (next_first_ref_block_out != 0)
                $display("@%0dns Test 1: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 0)
                $display("@%0dns Test 1: first_ref_block_out error", $time);
            if (last_ref_block_out != 1)
                $display("@%0dns Test 1: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 1: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 1: bypass_fifo_out error", $time);
            #10;
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 0)
            $display("@%0dns Test 1: store_S_out error", $time);
        if (init_out != 1)
            $display("@%0dns Test 1: init_out error", $time);
        if (T_out != ref1[2][15:14])
            $display("@%0dns Test 1: T_out error", $time);
        if (first_query_block_out != 0)
            $display("@%0dns Test 1: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 1: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 0)
            $display("@%0dns Test 1: first_ref_block_out error", $time);
        if (last_ref_block_out != 1)
            $display("@%0dns Test 1: last_ref_block_out error", $time);
        if (last_block_char_out != 1)
            $display("@%0dns Test 1: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 1: bypass_fifo_out error", $time);
        #10;    
        
        // Stall waiting for next query
        // Wait_query_info_valid
        for (i = 0; i < 5; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 2, Waiting for next query: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 2, Waiting for next query: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 2, Waiting for next query: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 2, Waiting for next query: ref_seq_block_rdy_out error", $time);
            if (store_S_out != 1)
                $display("@%0dns Test 2, Waiting for next query: store_S_out error", $time);
            if (init_out != 0)
                $display("@%0dns Test 2, Waiting for next query: init_out error", $time);
            if (first_query_block_out != 1)
                $display("@%0dns Test 2, Waiting for next query: first_query_block_out error", $time);
            if (next_first_ref_block_out != 1)
                $display("@%0dns Test 2, Waiting for next query: next_first_ref_block_out error", $time);
            if (first_ref_block_out != 1)
                $display("@%0dns Test 2, Waiting for next query: first_ref_block_out error", $time);
            if (last_ref_block_out != 0)
                $display("@%0dns Test 2, Waiting for next query: last_ref_block_out error", $time);
            if (last_block_char_out != 0)
                $display("@%0dns Test 2, Waiting for next query: last_block_char_out error", $time);
            if (bypass_fifo_out != 0)
                $display("@%0dns Test 2, Waiting for next query: bypass_fifo_out error", $time);
            #10;  
        end
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 2, Waiting for next query: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 2, Waiting for next query: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 2, Waiting for next query: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 2, Waiting for next query: ref_seq_block_rdy_out error", $time);
        if (store_S_out != 1)
            $display("@%0dns Test 2, Waiting for next query: store_S_out error", $time);
        if (init_out != 0)
            $display("@%0dns Test 2, Waiting for next query: init_out error", $time);
        if (first_query_block_out != 1)
            $display("@%0dns Test 2, Waiting for next query: first_query_block_out error", $time);
        if (next_first_ref_block_out != 1)
            $display("@%0dns Test 2, Waiting for next query: next_first_ref_block_out error", $time);
        if (first_ref_block_out != 1)
            $display("@%0dns Test 2, Waiting for next query: first_ref_block_out error", $time);
        if (last_ref_block_out != 0)
            $display("@%0dns Test 2, Waiting for next query: last_ref_block_out error", $time);
        if (last_block_char_out != 0)
            $display("@%0dns Test 2, Waiting for next query: last_block_char_out error", $time);
        if (bypass_fifo_out != 0)
            $display("@%0dns Test 2, Waiting for next query: bypass_fifo_out error", $time);
        ref_length_in <= ref_length2;
        ref_addr_in <= ref_addr2;
        num_query_blocks_in <= num_query_blocks2;
        query_info_valid <= 1;
        #10;  
        
		// Wait 100 ns for global reset to finish
		#100;
        $finish;

	end
    
    always begin
        #5 clk = !clk;
    end
    
endmodule

