/*  File Name        : Engine.v
 *  Description      : Smith Waterman Engine
 *
 *                     An engine unit, including a Smith Waterman systolic array 
 *                     and its controller.
 *
 *
 *  Revision History :
 *      Albert Ng   Jul 06 2013     Initial Revision
 *
 */
module Engine(
    input         clk,                      // System clock
    input         rst,                      // System reset
    input         stall,                    // Pipeline stall

    // PCIe handler interface
    input [24:0]  ref_length_in,            // Number of blocks in the reference sequence
    input [24:0]  ref_addr_in,              // DRAM starting address for reference sequence
    input [15:0]  num_query_blocks_in,      // Number of blocks in the query sequence
    input         query_info_valid,         // Store bookkeeping info for the query sequence
    output        query_info_rdy_out,       // Bookkeeping info input acknowledged
    input [(NUM_PES * 2) - 1:0] query_seq_block_in, // Query sequence block
    input         query_seq_block_valid,    // Query sequence block input valid
    output        query_seq_block_rdy_out,  // Query sequence block input acknowledged

    // DRAM reference reader interface
    output [24:0] ref_addr_out,             // DRAM starting address for reference sequence
    output [24:0] ref_length_out,           // Number of blocks in the reference sequence
    output        ref_info_valid_out,       // Reference sequence info output valid
    input [2*REF_LENGTH - 1:0] ref_seq_block_in, // Reference sequence block read from DRAM
    input         ref_seq_block_valid,      // Reference sequence block input valid
    output        ref_seq_block_rdy_out,    // Reference sequence block input acknowledged

    // Smith Waterman systolic array output
    output [NUM_PES * WIDTH - 1:0] V_out    // Cell score outputs
    );

    parameter NUM_PES = 64;
    parameter REF_LENGTH = 256;
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;
    parameter PES_PER_FIFO = 4;

    wire [(NUM_PES * 2) - 1:0] S;
    wire [1:0] T;
    wire store_S;
    wire init;
    wire first_query_block;
    wire next_first_ref_block;
    wire first_ref_block;
    wire last_ref_block;
    wire last_block_char;
    wire bypass_fifo;

    Engine_Ctrl #(NUM_PES, REF_LENGTH) eng_ctrl (
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
        .S_out(S),
        .T_out(T),
        .store_S_out(store_S),
        .init_out(init),
        .first_query_block_out(first_query_block),
        .next_first_ref_block_out(next_first_ref_block),
        .first_ref_block_out(first_ref_block),
        .last_ref_block_out(last_ref_block),
        .last_block_char_out(last_block_char),
        .bypass_fifo_out(bypass_fifo)
    );

    SmithWatermanArray#(NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) swarray (
        .clk(clk),
        .rst(rst),
        .stall(stall),
        .S_in(S),
        .T_in(T),
        .store_S_in(store_S),
        .init_in(init),
        .first_query_block(first_query_block),
        .next_first_ref_block_in(next_first_ref_block),
        .first_ref_block_in(first_ref_block),
        .last_ref_block_in(last_ref_block),
        .last_block_char_in(last_block_char),
        .bypass_fifo_in(bypass_fifo),
        .V_out(V_out)
    );


endmodule
