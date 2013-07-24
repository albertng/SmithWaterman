/*  File Name        : StreamInputHandler_ReferenceReader_Engine_Interface.v
 *  Description      : A stream input handler, reference reader, and engine
 *                     all interfaced together
 *
 *  Revision History :
 *      Albert Ng   Jul 11 2013     Initial Revision
 *      Albert Ng   Jul 16 2013     Added high score output
 *
 */
 
module StreamInputHandler_ReferenceReader_Engine_Interface(
    input          clk,                                // Engine clock 
    input          rst,                                // System reset
    input          stall,                              // Pipeline stall
    
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

    // Smith Waterman systolic array output
    output [NUM_PES * WIDTH - 1:0] V_out,   // Cell score outputs
    output [NUM_PES - 1:0] high_score_out   // Cell score is a high score
    );

    parameter NUM_PES = 64;
    parameter REF_LENGTH = 128;
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;
    parameter PES_PER_FIFO = 4;
       
    // Reference Reader, Engine interface
    wire [24:0] ref_addr;
    wire [24:0] ref_length;
    wire ref_info_valid;
    wire [2*REF_LENGTH - 1:0] ref_seq_block;
    wire ref_seq_block_valid;
    wire ref_seq_block_rdy;
    
    StreamInputHandler_Engine_Interface #(NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) sihe (
        .clk(clk),
        .rst(rst),
        .stall(stall),
        .si_clk(si_clk),
        .si_valid(si_valid),
        .si_data(si_data),
        .si_rdy(si_rdy),
        .ref_addr_out(ref_addr),
        .ref_length_out(ref_length),
        .ref_info_valid_out(ref_info_valid),
        .ref_seq_block_in(ref_seq_block),
        .ref_seq_block_valid_in(ref_seq_block_valid),
        .ref_seq_block_rdy_out(ref_seq_block_rdy),
        .V_out(V_out),
        .high_score_out(high_score_out)
    );
    
    ReferenceReader #(REF_LENGTH) rr (
        .clk(clk),
        .rst(rst),
        .ref_addr_in(ref_addr),
        .ref_length_in(ref_length),
        .ref_info_valid_in(ref_info_valid),
        .ref_seq_block_out(ref_seq_block),
        .ref_seq_block_valid_out(ref_seq_block_valid),
        .ref_seq_block_rdy_in(ref_seq_block_rdy),
        .rd_id_out(rd_id_out),
        .rd_addr_out(rd_addr_out),
        .rd_len_out(rd_len_out),
        .rd_info_valid_out(rd_info_valid_out),
        .rd_info_rdy_in(rd_info_rdy_in),
        .rd_data_in(rd_data_in),
        .rd_data_valid_in(rd_data_valid_in),
        .rd_data_rdy_out(rd_data_rdy_out)
    );
        
endmodule
