/*  File Name        : Engine_tb.v
 *  Description      : Smith Waterman Engine testbench
 *
 *                     Test bench for Smith Waterman engine unit
 *
 *
 *  Revision History :
 *      Albert Ng   Jul 08 2013     Initial Revision
 *
 */

module Engine_tb;

	// Inputs
	reg clk;
	reg rst;
	reg stall;
	reg [24:0] ref_length_in;
	reg [24:0] ref_addr_in;
	reg [15:0] num_query_blocks_in;
	reg query_info_valid_in;
	reg [5:0] query_seq_block_in;
	reg query_seq_block_valid_in;
	reg [7:0] ref_seq_block_in;
	reg ref_seq_block_valid_in;

	// Outputs
	wire query_info_rdy_out;
	wire query_seq_block_rdy_out;
	wire [24:0] ref_addr_out;
	wire [24:0] ref_length_out;
	wire ref_info_valid_out;
	wire ref_seq_block_rdy_out;
	wire [29:0] V_out;

    reg [5:0] query1[1:0];
    reg [7:0] ref1[1:0];
    reg [24:0] ref_length1;
    reg [24:0] ref_addr1;
    reg [15:0] num_query_blocks1;
    
    reg [5:0] query2[0:0];
    reg [7:0] ref2[1:0];
    reg [24:0] ref_length2;
    reg [24:0] ref_addr2;
    reg [15:0] num_query_blocks2;
    
    reg [5:0] query3[0:0];
    reg [7:0] ref3[0:0];
    reg [24:0] ref_length3;
    reg [24:0] ref_addr3;
    reg [15:0] num_query_blocks3;
    
    reg [9:0] V_out_expected[42:0][2:0];

	// Instantiate the Unit Under Test (UUT)
	Engine #(3, 4, 10, 10, -2, -2, -1, 3) uut (
		.clk(clk), 
		.rst(rst), 
		.stall(stall), 
		.ref_length_in(ref_length_in), 
		.ref_addr_in(ref_addr_in), 
		.num_query_blocks_in(num_query_blocks_in), 
		.query_info_valid_in(query_info_valid_in), 
		.query_info_rdy_out(query_info_rdy_out), 
		.query_seq_block_in(query_seq_block_in), 
		.query_seq_block_valid_in(query_seq_block_valid_in), 
		.query_seq_block_rdy_out(query_seq_block_rdy_out), 
		.ref_addr_out(ref_addr_out), 
		.ref_length_out(ref_length_out), 
		.ref_info_valid_out(ref_info_valid_out), 
		.ref_seq_block_in(ref_seq_block_in), 
		.ref_seq_block_valid_in(ref_seq_block_valid_in), 
		.ref_seq_block_rdy_out(ref_seq_block_rdy_out), 
		.V_out(V_out)
	);

    integer i, j;
	initial begin
        // Test 1
        query1[0] = 6'b110100;  // ACTAGC
        query1[1] = 6'b011000;
        ref1[0] = 8'b10001100;  // ATAGTCAT
        ref1[1] = 8'b11000111;
        ref_length1 = 2;
        ref_addr1 = 5;
        num_query_blocks1 = 2;
        
        // Test 2
        query2[0] = 6'b011000;  // AGC
        ref2[0] = 8'b10001100;  // ATAGTCAC
        ref2[1] = 8'b01000111;
        ref_length2 = 2;
        ref_addr2 = 10;
        num_query_blocks2 = 1;
        
        // Test 3
        query3[0] = 6'b011000;  // AGC
        ref3[0] = 8'b10001100;  // ATAG
        ref_length3 = 1;
        ref_addr3 = 15;
        num_query_blocks3 = 1;
        
        V_out_expected[0][0] = 10;
        V_out_expected[0][1] = 0;
        V_out_expected[0][2] = 0;
        V_out_expected[1][0] = 8;
        V_out_expected[1][1] = 8;
        V_out_expected[1][2] = 0;
        V_out_expected[2][0] = 10;
        V_out_expected[2][1] = 8;
        V_out_expected[2][2] = 7;
        V_out_expected[3][0] = 8;
        V_out_expected[3][1] = 8;
        V_out_expected[3][2] = 18;
        V_out_expected[4][0] = 0;
        V_out_expected[4][1] = 8;
        V_out_expected[4][2] = 16;
        V_out_expected[5][0] = 10;
        V_out_expected[5][1] = 0;
        V_out_expected[5][2] = 15;
        V_out_expected[6][0] = 16;
        V_out_expected[6][1] = 8;
        V_out_expected[6][2] = 0;
        V_out_expected[7][0] = 28;
        V_out_expected[7][1] = 15;
        V_out_expected[7][2] = 7;
        V_out_expected[8][0] = 26;
        V_out_expected[8][1] = 26;
        V_out_expected[8][2] = 14;
        V_out_expected[9][0] = 8;
        V_out_expected[9][1] = 38;
        V_out_expected[9][2] = 25;
        V_out_expected[10][0] = 7;
        V_out_expected[10][1] = 8;
        V_out_expected[10][2] = 36;
        V_out_expected[11][0] = 6;
        V_out_expected[11][1] = 6;
        V_out_expected[11][2] = 15;
        V_out_expected[12][0] = 10;
        V_out_expected[12][1] = 17;
        V_out_expected[12][2] = 18;
        V_out_expected[13][0] = 8;
        V_out_expected[13][1] = 15;
        V_out_expected[13][2] = 16;
        V_out_expected[14][0] = 26;
        V_out_expected[14][1] = 14;
        V_out_expected[14][2] = 15;
        V_out_expected[15][0] = 25;
        V_out_expected[15][1] = 38;
        V_out_expected[15][2] = 25;
        V_out_expected[16][0] = 24;
        V_out_expected[16][1] = 36;
        V_out_expected[16][2] = 36;
        V_out_expected[17][0] = 26;
        V_out_expected[17][1] = 35;
        V_out_expected[17][2] = 36;
        V_out_expected[18][0] = 24;
        V_out_expected[18][1] = 34;
        V_out_expected[18][2] = 46;
        V_out_expected[19][0] = 0;
        V_out_expected[19][1] = 33;
        V_out_expected[19][2] = 44;
        V_out_expected[20][0] = 0;
        V_out_expected[20][1] = 0;
        V_out_expected[20][2] = 43;
        V_out_expected[21][0] = 0;
        V_out_expected[21][1] = 0;
        V_out_expected[21][2] = 0;
        V_out_expected[22][0] = 10;
        V_out_expected[22][1] = 0;
        V_out_expected[22][2] = 0;
        V_out_expected[23][0] = 8;
        V_out_expected[23][1] = 8;
        V_out_expected[23][2] = 0;
        V_out_expected[24][0] = 10;
        V_out_expected[24][1] = 8;
        V_out_expected[24][2] = 7;
        V_out_expected[25][0] = 8;
        V_out_expected[25][1] = 8;
        V_out_expected[25][2] = 6;
        V_out_expected[26][0] = 8;
        V_out_expected[26][1] = 20;
        V_out_expected[26][2] = 7;
        V_out_expected[27][0] = 7;
        V_out_expected[27][1] = 20;
        V_out_expected[27][2] = 18;      
        V_out_expected[28][0] = 6;
        V_out_expected[28][1] = 18;
        V_out_expected[28][2] = 18;
        V_out_expected[29][0] = 10;
        V_out_expected[29][1] = 17;
        V_out_expected[29][2] = 18;
        V_out_expected[30][0] = 8;
        V_out_expected[30][1] = 16;
        V_out_expected[30][2] = 28;
        V_out_expected[31][0] = 0;
        V_out_expected[31][1] = 15;
        V_out_expected[31][2] = 26;
        V_out_expected[32][0] = 0;
        V_out_expected[32][1] = 0;
        V_out_expected[32][2] = 26;
        V_out_expected[33][0] = 0;
        V_out_expected[33][1] = 0;
        V_out_expected[33][2] = 0;
        V_out_expected[34][0] = 10;
        V_out_expected[34][1] = 0;
        V_out_expected[34][2] = 0;
        V_out_expected[35][0] = 10;
        V_out_expected[35][1] = 0;
        V_out_expected[35][2] = 0;
        V_out_expected[36][0] = 10;
        V_out_expected[36][1] = 0;
        V_out_expected[36][2] = 0;
        V_out_expected[37][0] = 10;
        V_out_expected[37][1] = 0;
        V_out_expected[37][2] = 0;
        V_out_expected[38][0] = 8;
        V_out_expected[38][1] = 8;
        V_out_expected[38][2] = 0;
        V_out_expected[39][0] = 10;
        V_out_expected[39][1] = 8;
        V_out_expected[39][2] = 7;
        V_out_expected[40][0] = 8;
        V_out_expected[40][1] = 8;
        V_out_expected[40][2] = 6;
        V_out_expected[41][0] = 0;
        V_out_expected[41][1] = 20;
        V_out_expected[41][2] = 7;
        V_out_expected[42][0] = 0;
        V_out_expected[42][1] = 0;
        V_out_expected[42][2] = 18;



		// Initialize Inputs
        clk <= 0;
		rst <= 1;
		stall <= 0;
		ref_length_in <= 0;
		ref_addr_in <= 0;
		num_query_blocks_in <= 0;
		query_info_valid_in <= 0;
		query_seq_block_in <= 0;
		query_seq_block_valid_in <= 0;
		ref_seq_block_in <= 0;
		ref_seq_block_valid_in <= 0;
        #20;
        rst <= 0;
        
        // Wait_query_info_valid
        for (i = 0; i < 2; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1 Wait_query_info_valid: query_info_rdy_out error", $time);
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1 Wait_query_info_valid: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1 Wait_query_info_valid: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1 Wait_query_info_valid: ref_seq_block_rdy_out error", $time);
            #10;
        end
        
        // Wait_query_info_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Wait_query_info_valid: query_info_rdy_out error", $time);
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_query_info_valid: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Wait_query_info_valid: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_query_info_valid: ref_seq_block_rdy_out error", $time);
        ref_length_in <= ref_length1;
        ref_addr_in <= ref_addr1;
        num_query_blocks_in <= num_query_blocks1;
        query_info_valid_in <= 1;
        #10;
        
        // Send_ref_addr
        if (query_info_rdy_out != 1)
            $display("@%0dns Test 1 Send_ref_addr: query_info_rdy_out error", $time);
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Send_ref_addr: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 1)
            $display("@%0dns Test 1 Send_ref_addr: ref_info_valid_out error", $time);
        if (ref_addr_out != ref_addr1)
            $display("@%0dns Test 1 Send_ref_addr: ref_addr_out error", $time);
        if (ref_length_out != ref_length1)
            $display("@%0dns Test 1 Send_ref_addr: ref_length_out_error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Send_ref_addr: ref_seq_block_rdy_out error", $time);
        #10;
        
        // Wait_query_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Wait_query_seq_block_valid: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_query_seq_block_valid: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Wait_query_seq_block_valid: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_query_seq_block_valid: ref_seq_block_rdy_out error", $time);
        query_info_valid_in <= 0;
        query_seq_block_in <= query1[0];
        query_seq_block_valid_in <= 1;
        #10;
        
        // Latch_query_seq_block
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Latch_query_seq_block: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 1)
            $display("@%0dns Test 1 Latch_query_seq_block: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Latch_query_seq_block: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Latch_query_seq_block: ref_seq_block_rdy_out error", $time);
        #10;
        
        // Wait_query_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Wait_query_seq_block_valid: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_query_seq_block_valid: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Wait_query_seq_block_valid: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_query_seq_block_valid: ref_seq_block_rdy_out error", $time);
        query_seq_block_in <= query1[1];
        #10;
        
        // Latch_query_seq_block
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Latch_query_seq_block: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 1)
            $display("@%0dns Test 1 Latch_query_seq_block: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Latch_query_seq_block: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Latch_query_seq_block: ref_seq_block_rdy_out error", $time);
        #10;
        
        // Wait_rd_rdy
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Wait_rd_rdy: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_rd_rdy: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Wait_rd_rdy: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_rd_rdy: ref_seq_block_rdy_out error", $time);
        query_seq_block_valid_in <= 0;  
        #10;
        
        // Wait_ref_seq_block_valid
        for (i = 0; i < 5; i = i + 1)begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1 Wait_ref_seq_block_valid: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1 Wait_ref_seq_block_valid: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1 Wait_ref_seq_block_valid: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1 Wait_ref_seq_block_valid: ref_seq_block_rdy_out error", $time);
            #10;
        end
        
        // Wait_ref_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Wait_ref_seq_block_valid: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_ref_seq_block_valid: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Wait_ref_seq_block_valid: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Wait_ref_seq_block_valid: ref_seq_block_rdy_out error", $time);
        ref_seq_block_in = ref1[0];
        ref_seq_block_valid_in = 1;
        #10;
        
        // Latch_ref
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Latch_ref: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Latch_ref: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Latch_ref: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns Test 1 Latch_ref: ref_seq_block_rdy_out error", $time);
        #10;
        
        // Advance_BCC
        ref_seq_block_in = ref1[1];
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Advance_BCC: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC: ref_seq_block_rdy_out error", $time);
        #10;
        
        // Advance_BCC
        for (i = 0; i < 8; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1 Advance_BCC: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1 Advance_BCC: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1 Advance_BCC: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1 Advance_BCC: ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Test 1 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
        // Latch_ref
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Latch_ref: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Latch_ref: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Latch_ref: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns Test 1 Latch_ref: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[8][j]) begin
                $display("@%0dns Test 1 Latch_ref: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[8][j]);
            end
        end
        #10;
        
        // Advance_BCC, send next query
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Advance_BCC: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[9][j]) begin
                $display("@%0dns Test 1 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[9][j]);
            end
        end
        ref_seq_block_valid_in <= 0;
        ref_length_in <= ref_length2;
        ref_addr_in <= ref_addr2;
        num_query_blocks_in <= num_query_blocks2;
        query_info_valid_in <= 1;
        #10;
        
        // Advance_BCC, Send_ref_addr
        if (query_info_rdy_out != 1)
            $display("@%0dns Test 1 Advance_BCC Send_ref_addr: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC Send_ref_addr: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 1)
            $display("@%0dns Test 1 Advance_BCC Send_ref_addr: ref_info_valid_out error", $time);
        if (ref_addr_out != ref_addr2)
            $display("@%0dns Test 1 Advance_BCC Send_ref_addr: ref_addr_out error", $time);
        if (ref_length_out != ref_length2)
            $display("@%0dns Test 1 Advance_BCC Send_ref_addr: ref_length_out_error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC Send_ref_addr: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[10][j]) begin
                $display("@%0dns Test 1 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[10][j]);
            end
        end
        #10;
        
        // Advance_BCC
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Advance_BCC: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[11][j]) begin
                $display("@%0dns Test 1 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[11][j]);
            end
        end
        query_info_valid_in <= 0;
        query_seq_block_in <= query2[0];
        query_seq_block_valid_in <= 1;
        #10;
        
        // Advance_BCC, Latch_query_seq_block
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC Latch_query_seq_block: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 1)
            $display("@%0dns Test 1 Advance_BCC Latch_query_seq_block: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 1 Advance_BCC Latch_query_seq_block: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 1 Advance_BCC Latch_query_seq_block: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[12][j]) begin
                $display("@%0dns Test 1 Advance_BCC Latch_query_seq_block: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[12][j]);
            end
        end
        ref_seq_block_in <= ref2[0];
        ref_seq_block_valid_in <= 1;
        #10;
        
        // Advance_BCC
        query_seq_block_valid_in <= 0;
        for (i = 13; i < 18; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 1 Advance_BCC: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 1 Advance_BCC: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 1 Advance_BCC: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 1 Advance_BCC: ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Test 1 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
        // Wait_wr_rdy
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 2 Wait_wr_rdy: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 2 Wait_wr_rdy: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 2 Wait_wr_rdy: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 2 Wait_wr_rdy: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[18][j]) begin
                $display("@%0dns Test 2 Wait_wr_rdy: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[18][j]);
            end
        end
        #10;
        
        // Wait_ref_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 2 Wait_ref_seq_block_valid: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 2 Wait_ref_seq_block_valid: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 2 Wait_ref_seq_block_valid: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 2 Wait_ref_seq_block_valid: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[19][j]) begin
                $display("@%0dns Test 2 Wait_ref_seq_block_valid: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[19][j]);
            end
        end
        #10;
        
        // Latch_ref
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 2 Latch_ref: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 2 Latch_ref: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 2 Latch_ref: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns Test 2 Latch_ref: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[20][j]) begin
                $display("@%0dns Test 2 Latch_ref: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[20][j]);
            end
        end
        #10;
        
        // Advance_BCC
        ref_seq_block_in <= ref2[1];
        for (i = 21; i < 25; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 2 Advance_BCC: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 2 Advance_BCC: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 2 Advance_BCC: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 2 Advance_BCC: ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Test 2 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
        // Latch_ref
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 2 Latch_ref: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 2 Latch_ref: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 2 Latch_ref: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns Test 2 Latch_ref: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[25][j]) begin
                $display("@%0dns Test 2 Latch_ref: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[25][j]);
            end
        end
        #10;
        
        // Advance_BCC
        ref_seq_block_valid_in <= 0;
        for (i = 26; i < 30; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 2 Advance_BCC: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 2 Advance_BCC: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 2 Advance_BCC: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 2 Advance_BCC: ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Test 2 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
        // Wait_wr_rdy
        for (i = 30; i < 33; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 2 Wait_wr_rdy: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 2 Wait_wr_rdy: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 2 Wait_wr_rdy: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 2 Wait_wr_rdy: ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Test 2 Latch_ref: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        #10;
        
        // Wait_query_info_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 3 Wait_query_info_valid: query_info_rdy_out error", $time);
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Wait_query_info_valid: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 3 Wait_query_info_valid: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Wait_query_info_valid: ref_seq_block_rdy_out error", $time);
        ref_length_in <= ref_length3;
        ref_addr_in <= ref_addr3;
        num_query_blocks_in <= num_query_blocks3;
        query_info_valid_in <= 3;
        #10;
        
        // Send_ref_addr
        if (query_info_rdy_out != 1)
            $display("@%0dns Test 3 Send_ref_addr: query_info_rdy_out error", $time);
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Send_ref_addr: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 1)
            $display("@%0dns Test 3 Send_ref_addr: ref_info_valid_out error", $time);
        if (ref_addr_out != ref_addr3)
            $display("@%0dns Test 3 Send_ref_addr: ref_addr_out error", $time);
        if (ref_length_out != ref_length3)
            $display("@%0dns Test 3 Send_ref_addr: ref_length_out_error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Send_ref_addr: ref_seq_block_rdy_out error", $time);
        #10;
        
        // Wait_query_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 3 Wait_query_seq_block_valid: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Wait_query_seq_block_valid: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 3 Wait_query_seq_block_valid: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Wait_query_seq_block_valid: ref_seq_block_rdy_out error", $time);
        query_info_valid_in <= 0;
        query_seq_block_in <= query3[0];
        query_seq_block_valid_in <= 1;
        #10;
        
        // Latch_query_seq_block
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 3 Latch_query_seq_block: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 1)
            $display("@%0dns Test 3 Latch_query_seq_block: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 3 Latch_query_seq_block: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Latch_query_seq_block: ref_seq_block_rdy_out error", $time);
        #10;
               
        // Wait_rd_rdy
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 3 Wait_rd_rdy: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Wait_rd_rdy: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 3 Wait_rd_rdy: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Wait_rd_rdy: ref_seq_block_rdy_out error", $time);
        query_seq_block_valid_in <= 0;  
        #10;
        
        // Wait_ref_seq_block_valid
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 3 Wait_ref_seq_block_valid: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Wait_ref_seq_block_valid: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 3 Wait_ref_seq_block_valid: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Wait_ref_seq_block_valid: ref_seq_block_rdy_out error", $time);
        ref_seq_block_in = ref3[0];
        ref_seq_block_valid_in = 1;
        #10;
        
        // Latch_ref
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 3 Latch_ref: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Latch_ref: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 3 Latch_ref: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns Test 3 Latch_ref: ref_seq_block_rdy_out error", $time);
        #10;
        
        // Advance_BCC
        ref_seq_block_valid_in = 0;
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 3 Advance_BCC: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Advance_BCC: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 3 Advance_BCC: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Advance_BCC: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[33][j]) begin
                $display("@%0dns Test 3 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[33][j]);
            end
        end
        #10;
        
        // Advance_BCC
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 3 Advance_BCC: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Advance_BCC: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 3 Advance_BCC: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Advance_BCC: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[34][j]) begin
                $display("@%0dns Test 3 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[34][j]);
            end
        end
        stall <= 1;
        #10;

        // Advance_BCC stall
        for (i = 35; i < 37; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 3 Advance_BCC stall: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 3 Advance_BCC stall: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 3 Advance_BCC stall: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 3 Advance_BCC stall: ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Test 3 Advance_BCC stall: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
        // Advance_BCC stall
        if (query_info_rdy_out != 0)
            $display("@%0dns Test 3 Advance_BCC: query_info_rdy_out error", $time);     
        if (query_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Advance_BCC: query_seq_block_rdy_out error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns Test 3 Advance_BCC: ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns Test 3 Advance_BCC: ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[37][j]) begin
                $display("@%0dns Test 3 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[37][j]);
            end
        end
        stall <= 0;
        #10;

        // Advance_BCC
        for (i = 38; i < 40; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 3 Advance_BCC: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 3 Advance_BCC: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 3 Advance_BCC: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 3 Advance_BCC: ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Test 3 Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
        // Wait_wr_rdy
        for (i = 40; i < 43; i = i + 1) begin
            if (query_info_rdy_out != 0)
                $display("@%0dns Test 3 Wait_wr_rdy: query_info_rdy_out error", $time);     
            if (query_seq_block_rdy_out != 0)
                $display("@%0dns Test 3 Wait_wr_rdy: query_seq_block_rdy_out error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns Test 3 Wait_wr_rdy: ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns Test 3 Wait_wr_rdy: ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Test 3 Wait_wr_rdy: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
		// Wait 100 ns
		#100;
        $display("Tests complete!");
        $finish;
	end
    always begin
        #5 clk = !clk;
    end
endmodule


