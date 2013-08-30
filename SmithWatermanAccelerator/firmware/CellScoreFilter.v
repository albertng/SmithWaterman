/*  File Name        : CellScoreFilter.v
 *  Description      : Cell Score Filter
 *
 *                     Unit that filters the cell scores computed by the systolic
 *                     array and queues up (query id, ref seq block) results to
 *                     be returned to the host PC.
 *          
 *                     Each alignment block requires tracking info (ref seq block,
 *                     query id, cell score threshold). Up to two different
 *                     alignment blocks can be computed at the same time by the
 *                     systolic array, on ref seq block boundaries. The tracking
 *                     info of the two alignment blocks are stored in two buffers.
 *                     A shift reg with one bit per PE indicates which buffer holds
 *                     each PE's cell score's tracking info.
 *
 *                     The "currently used" buffer is the buffer that the first PE uses.
 *                     When the engine controller passes new tracking info (indicated
 *                     by tracking_info_valid), the buffer that's not currently being
 *                     used is updated. The currently used buffer is then toggled to
 *                     the newly written buffer. The old buffer retains its values while
 *                     the pipeline completes the computations for the remainder of that
 *                     ref seq block, and gets updated on the next ref seq block boundary.
 *
 *                     There are two FSM's, one for each buffer. Each FSM makes sure that
 *                     a ref seq block is only stored at most once into the output FIFO.
 *                     In addition, each FSM ensures that writing to the FIFO occurs after
 *                     all of the cell scores of the previous block have been computed.
 *                     This makes sure that the results in the output FIFO are always in
 *                     order.
 *
 *                     The stall signal is asserted when the output FIFO is full.
 *
 *  Revision History :
 *      Albert Ng   Jul 24 2013     Initial Revision
 *      Albert Ng   Jul 27 2013     Added end of query tagging
 *      Albert Ng   Jul 29 2013     Changed to single independent clk domain output FIFO
 *      Albert Ng   Aug 06 2013     Removed latches
 *      Albert Ng   Aug 07 2013     Changed ref_block_cnt to 26 bits
 *      Albert Ng   Aug 09 2013     Changed ref_block_cnt to 28 bits
 *                                  Changed output packet to {query_id, ref_block_cnt}
 *      Albert Ng   Aug 23 2013     Added end_of_refblock checks
 *      Albert Ng   Aug 30 2013     Added last_query_block_len
 */
 
module CellScoreFilter(
    input         clk,                      // System clock
    input         rst,                      // System reset
    output        stall_out,                // Stall signal
    
    // Engine controller interface
    input [27:0] ref_block_cnt_in,          // Current ref seq block
    input [15:0] query_id_in,               // Current query ID
    input [31:0] cell_score_threshold_in,   // Current cell score threshold
    input [5:0]  last_query_block_len_in,   // Current query's last query block length (in bp)
    input tracking_info_valid_in,           // Tracking info is valid (1 clk)
    
    // Systolic Array interface
    input [NUM_PES * WIDTH - 1:0] V_out_in, // Cell scores    
    input [NUM_PES - 1:0] V_out_valid_in,   // Cell scores valid
    input end_of_query_in,                  // Last PE score is end of query
    input end_of_refblock_in,               // Last PE score is end of ref block
    input [NUM_PES - 1:0] last_query_block_in, // Cell score outputs in last query block
    
    // Output stream interface
    input  so_clk,                          // Stream output clock
    output so_valid_out,                    // Stream output valid
    output [127:0] so_data_out,             // Stream output data
    input  so_rdy_in                        // Stream output ready   
    );

    parameter NUM_PES = 64;
    parameter WIDTH = 10;
    localparam EOQ = 32'hFFFFFFFF;

    // FSM states
    localparam INIT = 5'b00001,
               HIGH_SCORE_WAIT_ALL_SEL = 5'b00010,
               HIGH_SCORE = 5'b00100,
               NO_HIGH_SCORE = 5'b01000,
               END_OF_QUERY = 5'b10000;
    reg [4:0] state0;
    reg [4:0] next_state0;
    reg [4:0] state1;
    reg [4:0] next_state1;
    
    // Tracking info buffers
    wire tracking_info_valid0;
    wire tracking_info_valid1;
    reg [27:0] ref_block_cnt0;
    reg [27:0] ref_block_cnt1;
    reg [15:0] query_id0;
    reg [15:0] query_id1;
    reg [WIDTH - 1:0] cell_score_threshold0;
    reg [WIDTH - 1:0] cell_score_threshold1;
    reg [5:0] last_query_block_len0;
    reg [5:0] last_query_block_len1;
    reg buffer_valid0;
    reg buffer_valid1;
    reg write_buffer;
    
    // Buffer select signals
    reg [NUM_PES - 1:0] buffer_sel;
    wire all_sel0;
    wire all_sel1;
    
    // Stall signal
    reg stall;
   
    // End of query signals
    reg end_of_query_sel0;
    reg end_of_query_sel1;
    wire end_of_query0;
    wire end_of_query1;
    
    // End of ref block signals
    wire end_of_refblock0;
    wire end_of_refblock1;
 
    // High score logic signals
    reg [WIDTH - 1:0] cell_score_threshold [NUM_PES - 1:0];
    reg [5:0] last_query_block_len [NUM_PES - 1:0];
    reg [NUM_PES - 1:0] last_query_block_mask;
    reg [NUM_PES - 1:0] V_out_cmp;
    reg [NUM_PES - 1:0] V_out_cmp0;
    reg [NUM_PES - 1:0] V_out_cmp1;
    reg high_score0;
    reg high_score1;
    
    // Output FIFO signals
    reg fifo_din_sel;
    reg next_fifo_din_sel;
    wire [47:0] fifo_din0;
    wire [47:0] fifo_din1;
    wire [47:0] fifo_din;
    reg         fifo_wr_en0;
    reg         fifo_wr_en1;
    wire        fifo_wr_en;
    wire        fifo_rd_en;
    wire [47:0] fifo_dout;
    wire        fifo_full;
    wire        fifo_empty;

    genvar i;    

    // End of query logic
    assign end_of_query0 = end_of_query_in & !buffer_sel[NUM_PES - 1];
    assign end_of_query1 = end_of_query_in & buffer_sel[NUM_PES - 1];
    
    // End of ref block logic
    assign end_of_refblock0 = end_of_refblock_in & !buffer_sel[NUM_PES - 1];
    assign end_of_refblock1 = end_of_refblock_in & buffer_sel[NUM_PES - 1];
    
    // High score logic
    generate
        for (i = 0; i < NUM_PES; i = i + 1) begin:v_out_cmp_gen
            always @(*) begin
                if (!buffer_sel[i]) begin
                    cell_score_threshold[i] = cell_score_threshold0;
                    last_query_block_len[i] = last_query_block_len0;
                end else begin
                    cell_score_threshold[i] = cell_score_threshold1;
                    last_query_block_len[i] = last_query_block_len1;
                end
                
                if ((last_query_block_len[i] == 0) | !last_query_block_in[i]) begin
                    last_query_block_mask[i] = 1;
                end else begin
                    if (i < last_query_block_len[i]) begin
                        last_query_block_mask[i] = 1;
                    end else begin
                        last_query_block_mask[i] = 0;
                    end
                end
            
                if (V_out_valid_in[i] && last_query_block_mask[i] && 
                    ($signed(V_out_in[(i*WIDTH)+WIDTH-1 -: WIDTH]) >= $signed(cell_score_threshold[i]))) begin
                    V_out_cmp[i] = 1;
                end else begin
                    V_out_cmp[i] = 0;
                end
                
                if (!buffer_sel[i]) begin
                    V_out_cmp0[i] = V_out_cmp[i];
                    V_out_cmp1[i] = 0;
                end else begin
                    V_out_cmp0[i] = 0;
                    V_out_cmp1[i] = V_out_cmp[i];
                end
            end
        end
    endgenerate
    always @(*) begin
        high_score0 = |(V_out_cmp0);
        high_score1 = |(V_out_cmp1);
    end
                
    // Buffer select shift register
    always @(*) begin
        buffer_sel[0] = !write_buffer;
    end
    generate
        for (i = 1; i < NUM_PES; i = i + 1) begin:buffer_sel_gen
            always @(posedge clk) begin
                if (rst) begin
                    buffer_sel[i] <= 0;
                end else if (!stall) begin
                    buffer_sel[i] <= buffer_sel[i-1];
                end
            end
        end
    endgenerate
    assign all_sel0 = ~|(buffer_sel);
    assign all_sel1 = &(buffer_sel);
    
    // Tracking info buffer
    assign tracking_info_valid0 = tracking_info_valid_in & !write_buffer;
    assign tracking_info_valid1 = tracking_info_valid_in & write_buffer;
    always @(posedge clk) begin
        if (rst) begin
            write_buffer <= 0;
            ref_block_cnt0 <= 0;
            ref_block_cnt1 <= 0;
            query_id0 <= 0;
            query_id1 <= 0;
            cell_score_threshold0 <= 0;
            cell_score_threshold1 <= 0;
            last_query_block_len0 <= 0;
            last_query_block_len1 <= 0;
            buffer_valid0 <= 0;
            buffer_valid1 <= 0;
        end else begin
            if (tracking_info_valid0) begin
                ref_block_cnt0 <= ref_block_cnt_in;
                query_id0 <= query_id_in;
                cell_score_threshold0 <= cell_score_threshold_in;
                last_query_block_len0 <= last_query_block_len_in;
                buffer_valid0 <= 1;
            end else if (end_of_refblock0) begin
                buffer_valid0 <= 0;
            end
            
            if (tracking_info_valid1) begin
                ref_block_cnt1 <= ref_block_cnt_in;
                query_id1 <= query_id_in;
                cell_score_threshold1 <= cell_score_threshold_in;
                last_query_block_len1 <= last_query_block_len_in;
                buffer_valid1 <= 1;
            end else if (end_of_refblock1) begin
                buffer_valid1 <= 0;
            end
            
            if (tracking_info_valid_in) begin
                write_buffer <= !write_buffer;
            end
        end
    end
            
    // FSM 0
    always @(posedge clk) begin
        if (rst) begin
            state0 <= INIT;
        end else if (!stall) begin
            state0 <= next_state0;
        end
    end
    always @(*) begin
        case (state0)
            INIT: begin
                if (high_score0 && !all_sel0 && buffer_valid0) begin
                    next_state0 = HIGH_SCORE_WAIT_ALL_SEL;
                end else if (high_score0 && all_sel0 && buffer_valid0) begin
                    next_state0 = HIGH_SCORE;
                end else if (!high_score0 && all_sel0 && buffer_valid0) begin
                    next_state0 = NO_HIGH_SCORE;
                end else begin
                    next_state0 = INIT;
                end
            end
            
            HIGH_SCORE_WAIT_ALL_SEL: begin
                if (all_sel0) begin
                    next_state0 = HIGH_SCORE;
                end else begin
                    next_state0 = HIGH_SCORE_WAIT_ALL_SEL;
                end
            end
            
            HIGH_SCORE: begin
                if (end_of_refblock0 && !end_of_query0) begin
                //if (tracking_info_valid0) begin
                    next_state0 = INIT;
                end else if (end_of_query0) begin
                    next_state0 = END_OF_QUERY;
                end else begin
                    next_state0 = HIGH_SCORE;
                end
            end
    
            NO_HIGH_SCORE: begin
                if (end_of_refblock0 && !end_of_query0) begin
                    next_state0 = INIT;
                end else if (high_score0 && !end_of_query0) begin
                    next_state0 = HIGH_SCORE;
                end else if (!high_score0 && !end_of_query0) begin
                    next_state0 = NO_HIGH_SCORE;
                end else begin
                    next_state0 = END_OF_QUERY;
                end
            end
            
            END_OF_QUERY: begin
                next_state0 = INIT;
            end

            default: begin // Shouldn't get here
                next_state0 = INIT;
            end
        endcase
    end
    always @(*) begin
        case (state0)
            INIT: begin
                if (high_score0 && all_sel0 && !stall) begin
                    fifo_wr_en0 = 1;
                end else begin
                    fifo_wr_en0 = 0;
                end
                end_of_query_sel0 = 0;
            end
            
            HIGH_SCORE_WAIT_ALL_SEL: begin
                if (all_sel0 && !stall) begin
                    fifo_wr_en0 = 1;
                end else begin
                    fifo_wr_en0 = 0;
                end
                end_of_query_sel0 = 0;
            end
            
            HIGH_SCORE: begin
                fifo_wr_en0 = 0;
                end_of_query_sel0 = 0;
            end
    
            NO_HIGH_SCORE: begin
                if (high_score0 && !stall) begin
                    fifo_wr_en0 = 1;
                end else begin
                    fifo_wr_en0 = 0;
                end
                end_of_query_sel0 = 0;
            end
            
            END_OF_QUERY: begin
                if (!stall) begin
                    fifo_wr_en0 = 1;
                end else begin
                    fifo_wr_en0 = 0;
                end
                end_of_query_sel0 = 1;
            end
            
            default: begin  // Shouldn't get here
                fifo_wr_en0 = 0;
                end_of_query_sel0 = 0;
            end
        endcase
    end
    
    // FSM 1
    always @(posedge clk) begin
        if (rst) begin
            state1 <= INIT;
        end else if (!stall) begin
            state1 <= next_state1;
        end
    end
    always @(*) begin
        case (state1)
            INIT: begin
                if (high_score1 && !all_sel1 && buffer_valid1) begin
                    next_state1 = HIGH_SCORE_WAIT_ALL_SEL;
                end else if (high_score1 && all_sel1 && buffer_valid1) begin
                    next_state1 = HIGH_SCORE;
                end else if (!high_score1 && all_sel1 && buffer_valid1) begin
                    next_state1 = NO_HIGH_SCORE;
                end else begin
                    next_state1 = INIT;
                end
            end
            
            HIGH_SCORE_WAIT_ALL_SEL: begin
                if (all_sel1) begin
                    next_state1 = HIGH_SCORE;
                end else begin
                    next_state1 = HIGH_SCORE_WAIT_ALL_SEL;
                end
            end
            
            HIGH_SCORE: begin
                if (end_of_refblock1 && !end_of_query1) begin
                //if (tracking_info_valid1) begin
                    next_state1 = INIT;
                end else if (end_of_query1) begin
                    next_state1 = END_OF_QUERY;
                end else begin
                    next_state1 = HIGH_SCORE;
                end
            end
    
            NO_HIGH_SCORE: begin
                if (end_of_refblock1 && !end_of_query1) begin
                    next_state1 = INIT;
                end else if (high_score1 && !end_of_query1) begin
                    next_state1 = HIGH_SCORE;
                end else if (!high_score1 && !end_of_query1) begin
                    next_state1 = NO_HIGH_SCORE;
                end else begin
                    next_state1 = END_OF_QUERY;
                end
            end
            
            END_OF_QUERY: begin
                next_state1 = INIT;
            end
            
            default: begin  // Shouldn't get here
                next_state1 = INIT;
            end
        endcase
    end
    always @(*) begin
        case (state1)
            INIT: begin
                if (high_score1 && all_sel1 && !stall) begin
                    fifo_wr_en1 = 1;
                end else begin
                    fifo_wr_en1 = 0;
                end
                end_of_query_sel1 = 0;
            end
            
            HIGH_SCORE_WAIT_ALL_SEL: begin
                if (all_sel1 && !stall) begin
                    fifo_wr_en1 = 1;
                end else begin
                    fifo_wr_en1 = 0;
                end
                end_of_query_sel1 = 0;
            end
            
            HIGH_SCORE: begin
                fifo_wr_en1 = 0;
                end_of_query_sel1 = 0;
            end
    
            NO_HIGH_SCORE: begin
                if (high_score1 && !stall) begin
                    fifo_wr_en1 = 1;
                end else begin
                    fifo_wr_en1 = 0;
                end
                end_of_query_sel1 = 0;
            end
            
            END_OF_QUERY: begin
                if (!stall) begin
                    fifo_wr_en1 = 1;
                end else begin
                    fifo_wr_en1 = 0;
                end
                end_of_query_sel1 = 1;
            end   
            
            default: begin  // Shouldn't get here
                fifo_wr_en1 = 0;
                end_of_query_sel1 = 0;
            end
        endcase
    end
    
    // Output FIFO
    cellscorefilter_fifo output_fifo (
        .rst(rst),
        .wr_clk(clk),
        .rd_clk(so_clk),
        .din(fifo_din),
        .wr_en(fifo_wr_en),
        .rd_en(fifo_rd_en),
        .dout(fifo_dout),
        .full(fifo_full),
        .empty(fifo_empty)
    );
    assign fifo_din0 = end_of_query_sel0 ? {query_id0, EOQ} : {query_id0, 4'b0, ref_block_cnt0};
    assign fifo_din1 = end_of_query_sel1 ? {query_id1, EOQ} : {query_id1, 4'b0, ref_block_cnt1};
    assign fifo_din = next_fifo_din_sel ? fifo_din1 : fifo_din0;
    always @(posedge clk) begin
        if (rst) begin
            fifo_din_sel <= 0;
        end else begin
            fifo_din_sel <= next_fifo_din_sel;
        end
    end
    always @(*) begin
        if (fifo_din_sel && all_sel0) begin
            next_fifo_din_sel = 0;
        end else if (!fifo_din_sel && all_sel1) begin
            next_fifo_din_sel = 1;
        end else begin
            next_fifo_din_sel = fifo_din_sel;
        end
    end
    assign fifo_wr_en = fifo_wr_en0 | fifo_wr_en1;
    
    // Stall signal
    assign stall_out = stall;
    always @(*) begin
        stall = fifo_full;
    end
    
    // Stream Output Handler interface
    assign so_data_out[127:48] = 0;
    assign so_data_out[47:0] = fifo_dout;
    assign so_valid_out = !fifo_empty;
    assign fifo_rd_en = so_rdy_in;                    
endmodule
