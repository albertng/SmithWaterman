/*  File Name        : StreamInputHandler_tb.v
 *  Description      : Test bench for PCIe stream input handler
 *
 *  Revision History :
 *      Albert Ng   Jul 09 2013     Initial Revision
 *      Albert Ng   Jul 15 2013     Added query ID #
 *
 */

module StreamInputHandler_tb;

	// Inputs
	reg rst;
	reg si_clk;
	reg si_valid;
	reg [127:0] si_data;
	reg clk;
	reg query_info_rdy_in;
	reg query_seq_block_rdy_in;

	// Outputs
	wire si_rdy;
	wire [24:0] ref_length_out;
	wire [24:0] ref_addr_out;
	wire [15:0] num_query_blocks_out;
    wire [15:0] query_id_out;
    wire [31:0] cell_score_threshold_out;
	wire query_info_valid_out;
	wire [127:0] query_seq_block_out;
	wire query_seq_block_valid_out;

    reg [31:0] ref_length1;
    reg [31:0] ref_addr1;
    reg [15:0] num_query_blocks1;
    reg [15:0] query_id1;
    reg [31:0] cell_score_threshold1;
    reg [127:0] query1[19:0];

    reg [31:0] ref_length2;
    reg [31:0] ref_addr2;
    reg [15:0] num_query_blocks2;
    reg [15:0] query_id2;
    reg [31:0] cell_score_threshold2;
    reg [127:0] query2[0:0];

	// Instantiate the Unit Under Test (UUT)
	StreamInputHandler uut (
		.rst(rst), 
		.si_clk(si_clk), 
		.si_valid(si_valid), 
		.si_data(si_data), 
		.si_rdy(si_rdy), 
		.clk(clk), 
		.ref_length_out(ref_length_out), 
		.ref_addr_out(ref_addr_out), 
		.num_query_blocks_out(num_query_blocks_out),
        .query_id_out(query_id_out), 
        .cell_score_threshold_out(cell_score_threshold_out),
		.query_info_valid_out(query_info_valid_out), 
		.query_info_rdy_in(query_info_rdy_in), 
		.query_seq_block_out(query_seq_block_out), 
		.query_seq_block_valid_out(query_seq_block_valid_out), 
		.query_seq_block_rdy_in(query_seq_block_rdy_in)
	);

    integer i;
	initial begin
        ref_length1 = 5;
        ref_addr1 = 10;
        num_query_blocks1 = 20;
        for (i = 0; i < 20; i = i + 1) begin
            query1[i] = i;
        end
        query_id1 = 1;
        cell_score_threshold1 = 1;    

        ref_length2 = 15;
        ref_addr2 = 20;
        num_query_blocks2 = 1;
        query2[0] = 255;
        query_id2 = 2;
        cell_score_threshold2 = 2;
    
		// Initialize Inputs
		rst <= 1;
		si_clk <= 0;
		si_valid <= 0;
		si_data <= 0;
		clk <= 0;
		query_info_rdy_in <= 0;
		query_seq_block_rdy_in <= 0;
        #20;
        rst <= 0;
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        #10;
        
        si_valid <= 1;
        si_data[31:0] <= ref_length1;
        si_data[63:32] <= ref_addr1;
        si_data[79:64] <= num_query_blocks1;
        si_data[95:80] <= query_id1;
        si_data[127:96] <= cell_score_threshold1;
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        #9;
        
        si_valid <= 0;
        #1;
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        #9;
        
        // Read port update as a result of write latency
        for (i = 0; i < 6; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 0)
                $display("@%0dns query_seq_block_valid_out error", $time);
            #10;
        end
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 1)
            $display("@%0dns query_info_valid_out error", $time);
        if (ref_length_out != ref_length1[24:0])
            $display("@%0dns ref_length_out error", $time);
        if (ref_addr_out != ref_addr1[24:0])
            $display("@%0dns ref_addr_out error", $time);
        if (num_query_blocks_out != num_query_blocks1)
            $display("@%0dns num_query_blocks_out error", $time);
        if (query_id_out != query_id1)
            $display("@%0dns query_id_out error", $time);
        if (cell_score_threshold_out != cell_score_threshold1)
            $display("@%0dns cell_score_threshold_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        #10;
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 1)
            $display("@%0dns query_info_valid_out error", $time);
        if (ref_length_out != ref_length1[24:0])
            $display("@0dns ref_length_out error", $time);
        if (ref_addr_out != ref_addr1[24:0])
            $display("@%0dns ref_addr_out error", $time);
        if (num_query_blocks_out != num_query_blocks1)
            $display("@%0dns num_query_blocks_out error", $time);
        if (query_id_out != query_id1)
            $display("@%0dns query_id_out error", $time);
        if (cell_score_threshold_out != cell_score_threshold1)
            $display("@%0dns cell_score_threshold_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        #10;
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 1)
            $display("@%0dns query_info_valid_out error", $time);
        if (ref_length_out != ref_length1[24:0])
            $display("@0dns ref_length_out error", $time);
        if (ref_addr_out != ref_addr1[24:0])
            $display("@%0dns ref_addr_out error", $time);
        if (num_query_blocks_out != num_query_blocks1)
            $display("@%0dns num_query_blocks_out error", $time);
        if (query_id_out != query_id1)
            $display("@%0dns query_id_out error", $time);
        if (cell_score_threshold_out != cell_score_threshold1)
            $display("@%0dns cell_score_threshold_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        query_info_rdy_in <= 1;
        #10;
            
        si_valid <= 1;
        si_data <= query1[0];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        query_info_rdy_in <= 0;
        #9;
        
        si_data <= query1[1];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        #9;
            
        si_valid <= 0;
        #1;
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        #9;

        // Read port update as a result of write latency
        for (i = 0; i < 5; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 0)
                $display("@%0dns query_seq_block_valid_out error", $time);
            #10;
        end

        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query1[0])
            $display("@%0dns query_seq_block_out error", $time);
        #10;

        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query1[0])
            $display("@%0dns query_seq_block_out error", $time);
        query_seq_block_rdy_in = 1;
        #10;

        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query1[1])
            $display("@%0dns query_seq_block_out error", $time);
        query_seq_block_rdy_in = 0;
        #10;

        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query1[1])
            $display("@%0dns query_seq_block_out error", $time);
        query_seq_block_rdy_in = 1;
        #10;

        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        query_seq_block_rdy_in = 0;
        #10;
        
        si_valid <= 1;
        si_data <= query1[2];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        #9;
            
        for (i = 3; i < 10; i = i + 1) begin
            si_valid <= 1;
            si_data <= query1[i];
            #1;
            if (si_rdy != 1)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 0)
                $display("@%0dns query_seq_block_valid_out error", $time);
            #9;
        end
        
        for (i = 10; i < 19; i = i + 1) begin
            si_valid <= 1;
            si_data <= query1[i];
            #1;
            if (si_rdy != 1)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 1)
                $display("@%0dns query_seq_block_valid_out error", $time);
            if (query_seq_block_out != query1[2])
                $display("@%0dns query_seq_block_out error", $time);
            #9;
        end
        
        si_valid <= 1;
        si_data <= query1[19];
        #1;
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query1[2])
            $display("@%0dns query_seq_block_out error", $time);
        query_seq_block_rdy_in = 1;
        #9;
        
        for (i = 3; i < 5; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 1)
                $display("@%0dns query_seq_block_valid_out error", $time);
            if (query_seq_block_out != query1[i])
                $display("@%0dns query_seq_block_out error", $time);
            query_seq_block_rdy_in = 0;
            #10;
        
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 1)
                $display("@%0dns query_seq_block_valid_out error", $time);
            if (query_seq_block_out != query1[i])
                $display("@%0dns query_seq_block_out error", $time);
            query_seq_block_rdy_in = 1;
            #10;
        end
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query1[5])
            $display("@%0dns query_seq_block_out error", $time);
        query_seq_block_rdy_in = 0;
        #10;
        
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query1[5])
            $display("@%0dns query_seq_block_out error", $time);
        query_seq_block_rdy_in = 1;
        #10;
        
        for (i = 6; i < 15; i = i + 1) begin
            si_valid <= 0;
            #1;
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 1)
                $display("@%0dns query_seq_block_valid_out error", $time);
            if (query_seq_block_out != query1[i])
                $display("@%0dns query_seq_block_out error", $time);
            query_seq_block_rdy_in = 0;
            #9;
            
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 1)
                $display("@%0dns query_seq_block_valid_out error", $time);
            if (query_seq_block_out != query1[i])
                $display("@%0dns query_seq_block_out error", $time);
            query_seq_block_rdy_in = 1;
            #10;
        end
        
        si_valid <= 1;
        si_data[31:0] <= ref_length2;
        si_data[63:32] <= ref_addr2;
        si_data[79:64] <= num_query_blocks2;
        si_data[95:80] <= query_id2;
        si_data[127:96] <= cell_score_threshold2;
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query1[15])
            $display("@%0dns query_seq_block_out error", $time);
        query_seq_block_rdy_in = 0;
        #9;
        
        si_valid <= 1;
        si_data <= query2[0];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query1[15])
            $display("@%0dns query_seq_block_out error", $time);
        query_seq_block_rdy_in = 1;
        #9;
        
        for (i = 16; i < 20; i = i + 1) begin
            si_valid <= 0;
            #1;
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 1)
                $display("@%0dns query_seq_block_valid_out error", $time);
            if (query_seq_block_out != query1[i])
                $display("@%0dns query_seq_block_out error", $time);
            query_seq_block_rdy_in = 0;
            #9;
            
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (query_info_valid_out != 0)
                $display("@%0dns query_info_valid_out error", $time);
            if (query_seq_block_valid_out != 1)
                $display("@%0dns query_seq_block_valid_out error", $time);
            if (query_seq_block_out != query1[i])
                $display("@%0dns query_seq_block_out error", $time);
            query_seq_block_rdy_in = 1;
            #10;
        end
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 1)
            $display("@%0dns query_info_valid_out error", $time);
        if (ref_length_out != ref_length2[24:0])
            $display("@%0dns ref_length_out error", $time);
        if (ref_addr_out != ref_addr2[24:0])
            $display("@%0dns ref_addr_out error", $time);
        if (num_query_blocks_out != num_query_blocks2)
            $display("@%0dns num_query_blocks_out error", $time);
        if (query_id_out != query_id2)
            $display("@%0dns query_id_out error", $time);
        if (cell_score_threshold_out != cell_score_threshold2)
            $display("@%0dns cell_score_threshold_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        query_seq_block_rdy_in = 0;
        #10;
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 1)
            $display("@%0dns query_info_valid_out error", $time);
        if (ref_length_out != ref_length2[24:0])
            $display("@%0dns ref_length_out error", $time);
        if (ref_addr_out != ref_addr2[24:0])
            $display("@%0dns ref_addr_out error", $time);
        if (num_query_blocks_out != num_query_blocks2)
            $display("@%0dns num_query_blocks_out error", $time);
        if (query_id_out != query_id2)
            $display("@%0dns query_id_out error", $time);
        if (cell_score_threshold_out != cell_score_threshold2)
            $display("@%0dns cell_score_threshold_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        query_info_rdy_in = 1;
        #10;
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query2[0])
            $display("@%0dns query_seq_block error", $time);
        query_info_rdy_in = 0;
        #10;
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 1)
            $display("@%0dns query_seq_block_valid_out error", $time);
        if (query_seq_block_out != query2[0])
            $display("@%0dns query_seq_block error", $time);
        query_seq_block_rdy_in = 1;
        #10;
        
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (query_info_valid_out != 0)
            $display("@%0dns query_info_valid_out error", $time);
        if (query_seq_block_valid_out != 0)
            $display("@%0dns query_seq_block_valid_out error", $time);
        query_seq_block_rdy_in = 0;
        #10;        
        
		// Wait 100 ns
		#100;
        $display("Tests complete!");
        $finish;
	end
    
    always begin
        #5 clk = !clk;
    end
    always begin
        #5 si_clk = !si_clk;
    end
endmodule

