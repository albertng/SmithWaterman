/*  File Name        : StreamInputHandler_SmithWatermanArray_EngineCtrl_Interface.v
 *  Description      : A stream input handler interfaced with a Smith Waterman Array
 *                     and Engine Controller
 *
 *  Revision History :
 *      Albert Ng   Jul 10 2013     Initial Revision
 *      Albert Ng   Jul 11 2013     Changed default ref length to 128
 *      Albert Ng   Jul 15 2013     Added query ID #
 *                                  Added cell score threshold
 *      Albert Ng   Jul 24 2013     Changed Engine to SmithWatermanArray_EngineCtrl_Interface
 *
 */
 
module StreamInputHandler_SmithWatermanArray_EngineCtrl_Interface(
    input          clk,                                // Engine clock 
    input          rst,                                // System reset
    input          stall,                              // Pipeline stall
    
    // Stream input handler interface
    input          si_clk,                             // Stream input clock
    input          si_valid,                           // Stream input valid
    input  [127:0] si_data,                            // Stream input data
    output         si_rdy,                             // Stream input ready
   
    // DRAM reference reader interface
    output [24:0] ref_addr_out,             // DRAM starting address for reference sequence
    output [24:0] ref_length_out,           // Number of blocks in the reference sequence
    output        ref_info_valid_out,       // Reference sequence info output valid
    input [2*REF_LENGTH - 1:0] ref_seq_block_in, // Reference sequence block read from DRAM
    input         ref_seq_block_valid_in,   // Reference sequence block input valid
    output        ref_seq_block_rdy_out,    // Reference sequence block input acknowledged

    // Smith Waterman systolic array output
    output [NUM_PES * WIDTH - 1:0] V_out    // Cell score outputs
    );

    parameter NUM_PES = 64;
    parameter REF_LENGTH = 128;
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;
    parameter PES_PER_FIFO = 4;
    
    wire [24:0] ref_length;
    wire [24:0] ref_addr;
    wire [15:0] num_query_blocks;
    wire [15:0] query_id;
    wire [31:0] cell_score_threshold;
    wire query_info_valid;
    wire query_info_rdy;
    wire [(NUM_PES * 2) - 1:0] query_seq_block;
    wire query_seq_block_valid;
    wire query_seq_block_rdy;
    
    StreamInputHandler #(NUM_PES) sih (
        .rst(rst),
        .si_clk(si_clk),
        .si_valid(si_valid),
        .si_data(si_data),
        .si_rdy(si_rdy),
        .clk(clk),
        .ref_length_out(ref_length),
        .ref_addr_out(ref_addr),
        .num_query_blocks_out(num_query_blocks),
        .query_id_out(query_id),
        .cell_score_threshold_out(cell_score_threshold),
        .query_info_valid_out(query_info_valid),
        .query_info_rdy_in(query_info_rdy),
        .query_seq_block_out(query_seq_block),
        .query_seq_block_valid_out(query_seq_block_valid),
        .query_seq_block_rdy_in(query_seq_block_rdy)
    );
    
	SmithWatermanArray_EngineCtrl_Interface #(NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) uut (
		.clk(clk), 
		.rst(rst), 
		.stall(stall), 
		.ref_length_in(ref_length), 
		.ref_addr_in(ref_addr), 
		.num_query_blocks_in(num_query_blocks), 
        .query_id_in(query_id),
        .cell_score_threshold_in(cell_score_threshold),
		.query_info_valid_in(query_info_valid), 
		.query_info_rdy_out(query_info_rdy), 
		.query_seq_block_in(query_seq_block), 
		.query_seq_block_valid_in(query_seq_block_valid), 
		.query_seq_block_rdy_out(query_seq_block_rdy), 
		.ref_addr_out(ref_addr_out), 
		.ref_length_out(ref_length_out), 
		.ref_info_valid_out(ref_info_valid_out), 
		.ref_seq_block_in(ref_seq_block_in), 
		.ref_seq_block_valid_in(ref_seq_block_valid_in), 
		.ref_seq_block_rdy_out(ref_seq_block_rdy_out), 
		.V_out(V_out)
	);
        
        
endmodule
