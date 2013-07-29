/*  File Name        : StreamInputHandler_ReferenceReader_SmithWatermanArray_EngineCtrl_CellScoreFilter_Interface.v
 *  Description      : A stream input handler, reference reader, Smith Waterman
 *                     Array, Engine Controller, and Cell Score Filter all interfaced together
 *
 *  Revision History :
 *      Albert Ng   Jul 26 2013     Initial Revision
 *      Albert Ng   Jul 27 2013     Added end_of_query
 */

module StreamInputHandler_ReferenceReader_SmithWatermanArray_EngineCtrl_CellScoreFilter_Interface(
    input          clk,                                // Engine clock 
    input          rst,                                // System reset
    
    // Stream input handler interface
    input          si_clk,                             // Stream input clock
    input          si_valid,                           // Stream input valid
    input  [127:0] si_data,                            // Stream input data
    output         si_rdy,                             // Stream input ready
   
    // AXI bus arbiter interface
    output [5:0]   rd_id_out,           // Read burst ID
    output [31:0]  rd_addr_out,         // Read burst address
    output [7:0]   rd_len_out,          // Read burst length (in terms of 256 bit blocks)
    output         rd_info_valid_out,   // Read info valid
    input          rd_info_rdy_in,      // Read request acknowledged 
    input  [255:0] rd_data_in,          // DRAM read data
    input          rd_data_valid_in,    // DRAM read data valid    
    output         rd_data_rdy_out,     // DRAM read data acknowledged   

    // Stream output handler interface
    output [40:0] result_0_data_out,        // Buffer 0 results
    output result_0_valid_out,              // Buffer 0 results valid
    input result_0_rdy_in,                  // Buffer 0 results acknowledge
    output [40:0] result_1_data_out,        // Buffer 1 results
    output result_1_valid_out,              // Buffer 1 results valid
    input result_1_rdy_in                   // Buffer 1 results acknowledge
    );

    parameter NUM_PES = 64;
    parameter REF_LENGTH = 128;
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;
    parameter PES_PER_FIFO = 4;

    // Cell Score Filter interface
    wire stall;
    wire [24:0] ref_block_cnt;
    wire [15:0] query_id;
    wire [31:0] cell_score_threshold;
    wire tracking_info_valid;
    wire [NUM_PES * WIDTH - 1:0] V_out;
    wire [NUM_PES-1:0] V_out_valid;
    wire end_of_query;
    

    StreamInputHandler_ReferenceReader_SmithWatermanArray_EngineCtrl_Interface #(NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) rre (
        .clk(clk), 
        .rst(rst), 
        .stall(stall), 
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
        .ref_block_cnt_out(ref_block_cnt),
        .query_id_out(query_id),
        .cell_score_threshold_out(cell_score_threshold),
        .tracking_info_valid_out(tracking_info_valid),
        .V_out(V_out),
        .V_out_valid(V_out_valid),
        .end_of_query_out(end_of_query)
    );

    CellScoreFilter #(NUM_PES, WIDTH) csf (
        .clk(clk),
        .rst(rst),
        .stall_out(stall),
        .ref_block_cnt_in(ref_block_cnt),
        .query_id_in(query_id),
        .cell_score_threshold_in(cell_score_threshold),
        .tracking_info_valid_in(tracking_info_valid),
        .V_out_in(V_out),
        .V_out_valid_in(V_out_valid),
        .end_of_query_in(end_of_query),
        .result_0_data_out(result_0_data_out),
        .result_0_valid_out(result_0_valid_out),
        .result_0_rdy_in(result_0_rdy_in),
        .result_1_data_out(result_1_data_out),
        .result_1_valid_out(result_1_valid_out),
        .result_1_rdy_in(result_1_rdy_in)
    );

endmodule
