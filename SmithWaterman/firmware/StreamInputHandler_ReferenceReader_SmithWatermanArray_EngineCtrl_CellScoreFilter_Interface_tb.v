/*  File Name        : StreamInputHandler_ReferenceReader_SmithWatermanArray_EngineCtrl_CellScoreFilter_Interface_tb.v
 *  Description      : Testbench for stream input handler, reference reader,
 *                     Smith Waterman Array, Engine Controller and Cell Score Filter 
 *                     interfaced together.
 *
 *  Revision History :
 *      Albert Ng   Jul 26 2013     Initial Revision
 *      Albert Ng   Jul 29 2013     Added end of query tagging tests
 */

module StreamInputHandler_ReferenceReader_SmithWatermanArray_EngineCtrl_CellScoreFilter_Interface_tb;

	// Inputs
	reg clk;
	reg rst;
	reg si_clk;
	reg si_valid;
	reg [127:0] si_data;
	reg rd_info_rdy_in;
	reg [255:0] rd_data_in;
	reg rd_data_valid_in;
	reg result_0_rdy_in;
	reg result_1_rdy_in;

	// Outputs
	wire si_rdy;
	wire [5:0] rd_id_out;
	wire [31:0] rd_addr_out;
	wire [7:0] rd_len_out;
	wire rd_info_valid_out;
	wire rd_data_rdy_out;
	wire [40:0] result_0_data_out;
	wire result_0_valid_out;
	wire [40:0] result_1_data_out;
	wire result_1_valid_out;

    reg [31:0] ref_length1;
    reg [31:0] ref_addr1;
    reg [15:0] num_query_blocks1;
    reg [15:0] query_id1;
    reg [31:0] cell_score_threshold1;
    reg [127:0] query1[1:0];
    reg [255:0] ref1[1:0];

    reg [31:0] ref_length2;
    reg [31:0] ref_addr2;
    reg [15:0] num_query_blocks2;
    reg [15:0] query_id2;
    reg [31:0] cell_score_threshold2;
    reg [127:0] query2[0:0];
    reg [255:0] ref2[1:0];

    reg [24:0] EOQ;

	// Instantiate the Unit Under Test (UUT)
	StreamInputHandler_ReferenceReader_SmithWatermanArray_EngineCtrl_CellScoreFilter_Interface  #(3, 4, 10, 10, -2, -2, -1, 3) uut (
		.clk(clk), 
		.rst(rst), 
		.si_clk(si_clk), 
		.si_valid(si_valid), 
		.si_data(si_data), 
		.si_rdy(si_rdy), 
		.rd_id_out(rd_id_out), 
		.rd_addr_out(rd_addr_out), 
		.rd_len_out(rd_len_out), 
		.rd_info_valid_out(rd_info_valid_out), 
		.rd_info_rdy_in(rd_info_rdy_in), 
		.rd_data_in(rd_data_in), 
		.rd_data_valid_in(rd_data_valid_in), 
		.rd_data_rdy_out(rd_data_rdy_out), 
		.result_0_data_out(result_0_data_out), 
		.result_0_valid_out(result_0_valid_out), 
		.result_0_rdy_in(result_0_rdy_in), 
		.result_1_data_out(result_1_data_out), 
		.result_1_valid_out(result_1_valid_out), 
		.result_1_rdy_in(result_1_rdy_in)
	);

    integer i;
	initial begin
        EOQ = 25'b1111111111111111111111111;
        query1[0] = 128'b110100;    // ACTAGC
        query1[1] = 128'b011000;
        ref1[0] = 256'b10001100;    // ATAGTCAT
        ref1[1] = 256'b11000111;
        ref_length1 = 2;
        ref_addr1 = 5;
        num_query_blocks1 = 2;
        query_id1 = 1;
        cell_score_threshold1 = 40;
        
        query2[0] = 128'b011000;    // AGC
        ref2[0] = 256'b10001100;    // ATAGTCAC
        ref2[1] = 256'b01000111;
        ref_length2 = 2;
        ref_addr2 = 10;
        num_query_blocks2 = 1;
        query_id2 = 2;
        cell_score_threshold2 = 20;

		// Initialize Inputs
		clk <= 0;
		rst <= 1;
		si_clk <= 0;
		si_valid <= 0;
		si_data <= 0;
		rd_info_rdy_in <= 0;
		rd_data_in <= 0;
		rd_data_valid_in <= 0;
		result_0_rdy_in <= 0;
		result_1_rdy_in <= 0;
        #20;
        rst <= 0;

        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
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
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;

        si_data <= query1[0];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;

        si_data <= query1[1];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;

        si_data[31:0] <= ref_length2;
        si_data[63:32] <= ref_addr2;
        si_data[79:64] <= num_query_blocks2;
        si_data[95:80] <= query_id2;
        si_data[127:96] <= cell_score_threshold2;
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;
      
        si_data <= query2[0];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;

        // Wait_query_info_valid / Wait_wr_rdy / Wait_ref_info_valid
        for (i = 0; i < 4; i = i + 1) begin
            si_valid <= 0;
            #1;
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            if (result_0_valid_out != 0)
                $display("@%0dns result_0_valid_out error", $time);
            if (result_1_valid_out != 0)
                $display("@%0dns result_1_valid_out error", $time);
            #9;
        end
      
        // Send_ref_addr / Wait_wr_rdy / Wait_ref_info_valid
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;

      
        // Wait_query_seq_block_valid / Wait_wr_rdy / Wait_ref_info_valid (ref info buffer filled)
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;
      
        // Latch_query_seq_block / Wait_wr_rdy / Send_rd_info
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 0)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 0)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;
      
        // Wait_query_seq_block_valid / Wait_wr_rdy / Wait_rd_info_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 0)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 0)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

        // Latch_query_seq_block / Wait_wr_rdy / Send_rd_info
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1 + 1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 1)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 0)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        rd_info_rdy_in <= 0;
        #10;
      
        // Wait_rd_rdy / Wait_wr_rdy / Wait_rd_info_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr1 + 1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 1)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 0)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

        // Wait_query_info_valid / Wait_ref_seq_block_valid / Wait_ref_info_valid
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        rd_info_rdy_in <= 0;
        #10;

        // Send_ref_addr / Wait_ref_seq_block_valid / Wait_ref_info_valid
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;

        // Wait_ref_seq_block_valid / Wait_ref_info_valid, ref info buffer loaded
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;

        // Wait_ref_seq_block_valid / Send_rd_info
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 2)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 0)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;

      
        // Wait_ref_seq_block_valid / Wait_rd_info_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 2)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 0)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        rd_info_rdy_in <= 1;
        #10;

      
        // Wait_ref_seq_block_valid / Send_rd_info
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2 + 1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 3)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 0)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        rd_info_rdy_in <= 0;
        #10;

        // Wait_ref_seq_block_valid / Wait_rd_info_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 1)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_addr_out != {7'b0, ref_addr2 + 1})
            $display("@%0dns rd_addr_out error", $time);
        if (rd_id_out != 3)
            $display("@%0dns rd_id_out error", $time);
        if (rd_len_out != 0)
            $display("@%0dns rd_len_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        rd_info_rdy_in <= 1;
        #10;
      
        // Wait_ref_seq_block_valid / Wait_ref_info_valid
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        rd_info_rdy_in <= 0;
        #10;

        // Wait_ref_seq_block_valid, Send read data
        rd_data_in <= ref1[0];
        rd_data_valid_in <= 1;
        #1;
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;
      
        // Wait_ref_seq_block_valid, wait FIFO empty latency clk #1, send read data
        rd_data_in <= ref1[1];
        #1;
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;

        // Wait_ref_seq_block_valid, wait FIFO empty latency clk #2, send read data
        rd_data_in <= ref2[0];
        #1;
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;
      
        // Wait_ref_seq_block_valid, ref seq block valid, send read data
        rd_data_in <= ref2[1];
        #1;
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 1)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;

      
        // Latch_ref
        rd_data_valid_in <= 0;
        #1;
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #9;

      
        // Advance_BCC
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;

      
        // Advance_BCC
        for (i = 0; i < 8; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);        
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            if (result_0_valid_out != 0)
                $display("@%0dns result_0_valid_out error", $time);
            if (result_1_valid_out != 0)
                $display("@%0dns result_1_valid_out error", $time);
            #10;
        end

        // Latch_ref
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;
      
        // Advance_BCC
        for (i = 9; i < 18; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);        
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            if (result_0_valid_out != 0)
                $display("@%0dns result_0_valid_out error", $time);
            if (result_1_valid_out != 0)
                $display("@%0dns result_1_valid_out error", $time);
            #10;
        end

         // Wait_wr_rdy / High Score 1
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;

        // Wait_ref_seq_block_valid / High Score 1 latency 1
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;

        // Latch_ref / High Score 1 latency 2 / EOQ 1
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        #10;

        
        // Advance_BCC / High Score 1 ready / EOQ 1 latency 1
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        #10;  

        // Advance_BCC / EOQ 1 latency 2
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        #10;  


        // Advance_BCC / EOQ 1 ready
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        #10;  

        // Advance_BCC
        for (i = 24; i < 25; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);        
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            if (result_0_valid_out != 0)
                $display("@%0dns result_0_valid_out error", $time);
            if (result_1_valid_out != 1)
                $display("@%0dns result_1_valid_out error", $time);
            if (result_1_data_out[40:16] != 1)
                $display("@%0dns result_1_data_out ref_block_cnt error", $time);
            if (result_1_data_out[15:0] != 1)
                $display("@%0dns result_1_data_out query_id error", $time);
            #10;
        end
        
        // Latch_ref
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        #10;
        
        // Advance_BCC / High Score 0
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        #10;

        // Advance_BCC / High Score 0 latency 1
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        #10;

        // Advance_BCC / High Score 0 latency 2
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        #10;


        // Advance_BCC / High Score 0 ready
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 1)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_0_data_out[40:16] != 0)
            $display("@%0dns result_0_data_out ref_block_cnt error", $time);
        if (result_0_data_out[15:0] != 2)
            $display("@%0dns result_0_data_out query_id error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        #10;

        // Wait_wr_rdy / High Score 1 / EOQ 1
        for (i = 30; i < 33; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);        
            if (rd_info_valid_out != 0)
                $display("@%0dns rd_info_valid_out error", $time);
            if (rd_data_rdy_out != 0)
                $display("@%0dns rd_data_rdy_out error", $time);
            if (result_0_valid_out != 1)
                $display("@%0dns result_0_valid_out error", $time);
            if (result_0_data_out[40:16] != 0)
                $display("@%0dns result_0_data_out ref_block_cnt error", $time);
            if (result_0_data_out[15:0] != 2)
                $display("@%0dns result_0_data_out query_id error", $time);
            if (result_1_valid_out != 1)
                $display("@%0dns result_1_valid_out error", $time);
            if (result_1_data_out[40:16] != 1)
                $display("@%0dns result_1_data_out ref_block_cnt error", $time);
            if (result_1_data_out[15:0] != 1)
                $display("@%0dns result_1_data_out query_id error", $time);
            #10;
        end

        // Read high score 1
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 1)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_0_data_out[40:16] != 0)
            $display("@%0dns result_0_data_out ref_block_cnt error", $time);
        if (result_0_data_out[15:0] != 2)
            $display("@%0dns result_0_data_out query_id error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        result_1_rdy_in <= 1;
        #10;

        // Read EOQ 1
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 1)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_0_data_out[40:16] != 0)
            $display("@%0dns result_0_data_out ref_block_cnt error", $time);
        if (result_0_data_out[15:0] != 2)
            $display("@%0dns result_0_data_out query_id error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != EOQ)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 1)
            $display("@%0dns result_1_data_out query_id error", $time);
        result_1_rdy_in <= 1;
        #10;

        // Read high score 0
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 1)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_0_data_out[40:16] != 0)
            $display("@%0dns result_0_data_out ref_block_cnt error", $time);
        if (result_0_data_out[15:0] != 2)
            $display("@%0dns result_0_data_out query_id error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 2)
            $display("@%0dns result_1_data_out query_id error", $time);
        result_1_rdy_in <= 0;
        result_0_rdy_in <= 1;
        #10;

        // Read high score 1
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != 1)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 2)
            $display("@%0dns result_1_data_out query_id error", $time);
        result_1_rdy_in <= 1;
        result_0_rdy_in <= 0;
        #10;

        // Read EOQ 1
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 1)
            $display("@%0dns result_1_valid_out error", $time);
        if (result_1_data_out[40:16] != EOQ)
            $display("@%0dns result_1_data_out ref_block_cnt error", $time);
        if (result_1_data_out[15:0] != 2)
            $display("@%0dns result_1_data_out query_id error", $time);
        result_1_rdy_in <= 1;
        #10;

        // No more high scores
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (rd_info_valid_out != 0)
            $display("@%0dns rd_info_valid_out error", $time);
        if (rd_data_rdy_out != 0)
            $display("@%0dns rd_data_rdy_out error", $time);
        if (result_0_valid_out != 0)
            $display("@%0dns result_0_valid_out error", $time);
        if (result_1_valid_out != 0)
            $display("@%0dns result_1_valid_out error", $time);
        result_1_rdy_in <= 0;
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
