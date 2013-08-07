/*  File Name        : Engine.v
 *  Description      : Smith Waterman Engine
 *
 *                     A Smith Waterman engine unit. Consists of the
 *                     stream input handler, engine controller, reference
 *                     reader, Smith Waterman array, and cell score filter.
 *
 *  Revision History :
 *      Albert Ng   Jul 31 2013     Initial Revision
 *
 */
module Engine(
    input          clk,                                // Engine clock 
    input          rst,                                // System reset
    
    // Input stream interface
    input          si_clk,                             // Stream input clock
    input          si_valid_in,                        // Stream input valid
    input  [127:0] si_data_in,                         // Stream input data
    output         si_rdy_out,                         // Stream input ready
   
    // AXI bus arbiter interface
    output [5:0]   rd_id_out,           // Read burst ID
    output [32:0]  rd_addr_out,         // Read burst address
    output [7:0]   rd_len_out,          // Read burst length (in terms of 256 bit blocks)
    output         rd_info_valid_out,   // Read info valid
    input          rd_info_rdy_in,      // Read request acknowledged 
    input  [255:0] rd_data_in,          // DRAM read data
    input          rd_data_valid_in,    // DRAM read data valid    
    output         rd_data_rdy_out,     // DRAM read data acknowledged
    
    // Output stream interface
    input  so_clk,                          // Stream output clock
    output so_valid_out,                    // Stream output valid
    output [127:0] so_data_out,             // Stream output data
    input  so_rdy_in                        // Stream output ready  
    );

    parameter NUM_PES = 64;
    parameter REF_LENGTH = 128;
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;
    parameter PES_PER_FIFO = 4;
    
    // Stream input handler - engine controller interface
    wire [25:0] ref_length_sih2ec;
    wire [25:0] ref_addr_sih2ec;
    wire [15:0] num_query_blocks_sih2ec;
    wire [15:0] query_id_sih2ec;
    wire [31:0] cell_score_threshold_sih2ec;
    wire query_info_valid_sih2ec;
    wire query_info_rdy_ec2sih;
    wire [(NUM_PES * 2) - 1:0] query_seq_block_sih2ec;
    wire query_seq_block_valid_sih2ec;
    wire query_seq_block_rdy_ec2sih;
    
    // Engine controller - reference reader interface
    wire [25:0] ref_addr_ec2rr;
    wire [25:0] ref_length_ec2rr;
    wire ref_info_valid_ec2rr;
    wire [2*REF_LENGTH - 1:0] ref_seq_block_rr2ec;
    wire ref_seq_block_valid_rr2ec;
    wire ref_seq_block_rdy_ec2rr;
    
    // Engine controller - Smith Waterman array interface
    wire [(NUM_PES * 2) - 1:0] S_ec2swa;
    wire [1:0] T_ec2swa;
    wire store_S_ec2swa;
    wire init_ec2swa;
    wire first_query_block_ec2swa;
    wire next_first_ref_block_ec2swa;
    wire first_ref_block_ec2swa;
    wire last_ref_block_ec2swa;
    wire last_query_block_ec2swa;
    wire last_block_char_ec2swa;
    wire bypass_fifo_ec2swa;
    
    // Engine controller - cell score filter interface
    wire [25:0] ref_block_cnt_ec2csf;
    wire [15:0] query_id_ec2csf;
    wire [31:0] cell_score_threshold_ec2csf;
    wire tracking_info_valid_ec2csf;
    
    // Smith Waterman array - cell score filter interface
    wire [NUM_PES * WIDTH - 1:0] V_out_swa2csf;
    wire [NUM_PES - 1:0] V_out_valid_swa2csf;
    wire end_of_query_swa2csf;
    
    // Stall signal
    wire stall;
    
    StreamInputHandler #(NUM_PES) sih (
        .rst(rst),
        .si_clk(si_clk),
        .si_valid(si_valid_in),
        .si_data(si_data_in),
        .si_rdy(si_rdy_out),
        .clk(clk),
        .ref_length_out(ref_length_sih2ec),
        .ref_addr_out(ref_addr_sih2ec),
        .num_query_blocks_out(num_query_blocks_sih2ec),
        .query_id_out(query_id_sih2ec),
        .cell_score_threshold_out(cell_score_threshold_sih2ec),
        .query_info_valid_out(query_info_valid_sih2ec),
        .query_info_rdy_in(query_info_rdy_ec2sih),
        .query_seq_block_out(query_seq_block_sih2ec),
        .query_seq_block_valid_out(query_seq_block_valid_sih2ec),
        .query_seq_block_rdy_in(query_seq_block_rdy_ec2sih)
    );
        
    Engine_Ctrl #(NUM_PES, REF_LENGTH) ec (
        .clk(clk),
        .rst(rst),
        .stall(stall),
        .ref_length_in(ref_length_sih2ec),
        .ref_addr_in(ref_addr_sih2ec),
        .num_query_blocks_in(num_query_blocks_sih2ec),
        .query_id_in(query_id_sih2ec),
        .cell_score_threshold_in(cell_score_threshold_sih2ec),
        .query_info_valid_in(query_info_valid_sih2ec),
        .query_info_rdy_out(query_info_rdy_ec2sih),
        .query_seq_block_in(query_seq_block_sih2ec),
        .query_seq_block_valid_in(query_seq_block_valid_sih2ec),
        .query_seq_block_rdy_out(query_seq_block_rdy_ec2sih),
        .ref_addr_out(ref_addr_ec2rr),
        .ref_length_out(ref_length_ec2rr),
        .ref_info_valid_out(ref_info_valid_ec2rr),
        .ref_seq_block_in(ref_seq_block_rr2ec),
        .ref_seq_block_valid_in(ref_seq_block_valid_rr2ec),
        .ref_seq_block_rdy_out(ref_seq_block_rdy_ec2rr),
        .S_out(S_ec2swa),
        .T_out(T_ec2swa),
        .store_S_out(store_S_ec2swa),
        .init_out(init_ec2swa),
        .first_query_block_out(first_query_block_ec2swa),
        .next_first_ref_block_out(next_first_ref_block_ec2swa),
        .first_ref_block_out(first_ref_block_ec2swa),
        .last_ref_block_out(last_ref_block_ec2swa),
        .last_query_block_out(last_query_block_ec2swa),
        .last_block_char_out(last_block_char_ec2swa),
        .bypass_fifo_out(bypass_fifo_ec2swa),
        .ref_block_cnt_out(ref_block_cnt_ec2csf),
        .query_id_out(query_id_ec2csf),
        .cell_score_threshold_out(cell_score_threshold_ec2csf),
        .tracking_info_valid_out(tracking_info_valid_ec2csf)
    );
    
    ReferenceReader #(REF_LENGTH) rr (
        .clk(clk),
        .rst(rst),
        .ref_addr_in(ref_addr_ec2rr),
        .ref_length_in(ref_length_ec2rr),
        .ref_info_valid_in(ref_info_valid_ec2rr),
        .ref_seq_block_out(ref_seq_block_rr2ec),
        .ref_seq_block_valid_out(ref_seq_block_valid_rr2ec),
        .ref_seq_block_rdy_in(ref_seq_block_rdy_ec2rr),
        .rd_id_out(rd_id_out),
        .rd_addr_out(rd_addr_out),
        .rd_len_out(rd_len_out),
        .rd_info_valid_out(rd_info_valid_out),
        .rd_info_rdy_in(rd_info_rdy_in),
        .rd_data_in(rd_data_in),
        .rd_data_valid_in(rd_data_valid_in),
        .rd_data_rdy_out(rd_data_rdy_out)
    );
    
    SmithWatermanArray #(NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) swa (
        .clk(clk),
        .rst(rst),
        .stall(stall),
        .S_in(S_ec2swa),
        .T_in(T_ec2swa),
        .store_S_in(store_S_ec2swa),
        .init_in(init_ec2swa),
        .first_query_block(first_query_block_ec2swa),
        .next_first_ref_block_in(next_first_ref_block_ec2swa),
        .first_ref_block_in(first_ref_block_ec2swa),
        .last_ref_block_in(last_ref_block_ec2swa),
        .last_query_block_in(last_query_block_ec2swa),
        .last_block_char_in(last_block_char_ec2swa),
        .bypass_fifo_in(bypass_fifo_ec2swa),
        .V_out(V_out_swa2csf),
        .V_out_valid(V_out_valid_swa2csf),
        .end_of_query_out(end_of_query_swa2csf)
    );
    
    CellScoreFilter #(NUM_PES, WIDTH) csf (
        .clk(clk),
        .rst(rst),
        .stall_out(stall),
        .ref_block_cnt_in(ref_block_cnt_ec2csf),
        .query_id_in(query_id_ec2csf),
        .cell_score_threshold_in(cell_score_threshold_ec2csf),
        .tracking_info_valid_in(tracking_info_valid_ec2csf),
        .V_out_in(V_out_swa2csf),
        .V_out_valid_in(V_out_valid_swa2csf),
        .end_of_query_in(end_of_query_swa2csf),
        .so_clk(so_clk),
        .so_valid_out(so_valid_out),
        .so_data_out(so_data_out),
        .so_rdy_in(so_rdy_in)
    );
        
endmodule
