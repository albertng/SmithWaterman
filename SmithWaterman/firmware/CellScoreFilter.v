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
 *                     The currently used buffer is the buffer that the first PE uses.
 *                     When the engine controller passes new tracking info (indicated
 *                     by tracking_info_valid), the buffer that's not currently being
 *                     used is updated. The currently used buffer is also toggled to
 *                     the newly written buffer. The old buffer retains its values while
 *                     the pipeline completes the computations for the remainder of that
 *                     ref seq block, and gets updated on the next ref seq block boundary.
 *
 *                     There are two FSM's, one for each buffer. Each FSM makes sure that
 *                     a ref seq block is only stored at most once into the corresponding
 *                     output FIFO.
 *
 *                     There are two output FIFO's, one for each buffer. The output FIFO's
 *                     pass the results to the stream output handler. If either of the
 *                     output FIFO's are full, the stall signal is asserted to pause
 *                     the systolic array
 *
 *  Revision History :
 *      Albert Ng   Jul 24 2013     Initial Revision
 *      Albert Ng   Jul 27 2013     Added end of query tagging
 */
 
module CellScoreFilter(
    input         clk,                      // System clock
    input         rst,                      // System reset
    output        stall_out,                // Stall signal
    
    // Engine controller interface
    input [24:0] ref_block_cnt_in,          // Current ref seq block
    input [15:0] query_id_in,               // Current query ID
    input [31:0] cell_score_threshold_in,   // Current cell score threshold
    input tracking_info_valid_in,           // Tracking info is valid (1 clk)
    
    // Systolic Array interface
    input [NUM_PES * WIDTH - 1:0] V_out_in, // Cell scores    
    input [NUM_PES - 1:0] V_out_valid_in,   // Cell scores valid
    input end_of_query_in,                  // Last PE score is end of query
    
    // Stream output handler interface
    output [40:0] result_0_data_out,        // Buffer 0 results
    output result_0_valid_out,              // Buffer 0 results valid
    input result_0_rdy_in,                  // Buffer 0 results acknowledge
    output [40:0] result_1_data_out,        // Buffer 1 results
    output result_1_valid_out,              // Buffer 1 results valid
    input result_1_rdy_in                   // Buffer 1 results acknowledge
    );

    parameter NUM_PES = 64;
    parameter WIDTH = 10;
    localparam EOQ = 25'b1111111111111111111111111;

    // FSM states
    localparam NO_HIGH_SCORE0 = 3'b001,
               HIGH_SCORE0    = 3'b010,
               END_OF_QUERY0  = 3'b100,
               NO_HIGH_SCORE1 = 3'b001,
               HIGH_SCORE1    = 3'b010,
               END_OF_QUERY1  = 3'b100;
    reg [2:0] state0;
    reg [2:0] next_state0;
    reg [2:0] state1;
    reg [2:0] next_state1;
    
    // Tracking info buffers
    wire tracking_info_valid0;
    wire tracking_info_valid1;
    reg [24:0] ref_block_cnt0;
    reg [24:0] ref_block_cnt1;
    reg [15:0] query_id0;
    reg [15:0] query_id1;
    reg [WIDTH - 1:0] cell_score_threshold0;
    reg [WIDTH - 1:0] cell_score_threshold1;
    reg write_buffer;
    
    // Buffer select signals
    reg [NUM_PES - 1:0] buffer_sel;
    
    // Stall signal
    reg stall;
   
    // End of query signals
    reg end_of_query_sel0;
    reg end_of_query_sel1;
    wire end_of_query0;
    wire end_of_query1;
 
    // High score logic signals
    reg [WIDTH - 1:0] cell_score_threshold [NUM_PES - 1:0];
    reg [NUM_PES - 1:0] V_out_cmp;
    reg [NUM_PES - 1:0] V_out_cmp0;
    reg [NUM_PES - 1:0] V_out_cmp1;
    reg high_score0;
    reg high_score1;
    
    // Output FIFO signals
    wire [40:0] csff0_din;
    reg         csff0_wr_en;
    wire        csff0_rd_en;
    wire [40:0] csff0_dout;
    wire        csff0_full;
    wire        csff0_empty;
    wire [40:0] csff1_din;
    reg         csff1_wr_en;
    wire        csff1_rd_en;
    wire [40:0] csff1_dout;
    wire        csff1_full;
    wire        csff1_empty;

    genvar i;    

    // End of query logic
    assign end_of_query0 = end_of_query_in & !buffer_sel[NUM_PES - 1];
    assign end_of_query1 = end_of_query_in & buffer_sel[NUM_PES - 1];
    
    // High score logic
    generate
        for (i = 0; i < NUM_PES; i = i + 1) begin:v_out_cmp_gen
            always @(*) begin
                if (!buffer_sel[i]) begin
                    cell_score_threshold[i] = cell_score_threshold0;
                end else begin
                    cell_score_threshold[i] = cell_score_threshold1;
                end
            
                if (V_out_valid_in[i] && 
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
        end else begin
            if (tracking_info_valid0) begin
                ref_block_cnt0 <= ref_block_cnt_in;
                query_id0 <= query_id_in;
                cell_score_threshold0 <= cell_score_threshold_in;
            end
            if (tracking_info_valid1) begin
                ref_block_cnt1 <= ref_block_cnt_in;
                query_id1 <= query_id_in;
                cell_score_threshold1 <= cell_score_threshold_in;
            end
            if (tracking_info_valid_in) begin
                write_buffer <= !write_buffer;
            end
        end
    end
            
    // FSM 0
    always @(posedge clk) begin
        if (rst) begin
            state0 <= NO_HIGH_SCORE0;
        end else if (!stall) begin
            state0 <= next_state0;
        end
    end
    always @(*) begin
        case(state0)
            NO_HIGH_SCORE0: begin
                if (high_score0 && !end_of_query0) begin
                    next_state0 <= HIGH_SCORE0;
                end else if (!high_score0 && !end_of_query0) begin
                    next_state0 <= NO_HIGH_SCORE0;
                end else begin
                    next_state0 <= END_OF_QUERY0;
                end
            end
            
            HIGH_SCORE0: begin
                if (tracking_info_valid0) begin
                    next_state0 <= NO_HIGH_SCORE0;
                end else if (end_of_query0) begin
                    next_state0 <= END_OF_QUERY0;
                end else begin
                    next_state0 <= HIGH_SCORE0;
                end
            end

            END_OF_QUERY0: begin
                next_state0 <= NO_HIGH_SCORE0;
            end
        endcase
    end
    always @(*) begin
        case(state0)
            NO_HIGH_SCORE0: begin
                if (high_score0 && !stall) begin
                    csff0_wr_en <= 1;
                end else begin
                    csff0_wr_en <= 0;
                end
                end_of_query_sel0 <= 0;
            end
            
            HIGH_SCORE0: begin
                csff0_wr_en <= 0;
                end_of_query_sel0 <= 0;
            end

            END_OF_QUERY0: begin
                if (!stall) begin
                    csff0_wr_en <= 1;
                end else begin
                    csff0_wr_en <= 0;
                end
                end_of_query_sel0 <= 1;
            end
        endcase
    end
    
    // FSM 1
    always @(posedge clk) begin
        if (rst) begin
            state1 <= NO_HIGH_SCORE1;
        end else if (!stall) begin
            state1 <= next_state1;
        end
    end
    always @(*) begin
        case(state1)
            NO_HIGH_SCORE1: begin
                if (high_score1 && !end_of_query1) begin
                    next_state1 <= HIGH_SCORE1;
                end else if (!high_score1 && !end_of_query1) begin
                    next_state1 <= NO_HIGH_SCORE1;
                end else begin
                    next_state1 <= END_OF_QUERY1;
                end
            end
            
            HIGH_SCORE1: begin
                if (tracking_info_valid1) begin
                    next_state1 <= NO_HIGH_SCORE1;
                end else if (end_of_query1) begin
                    next_state1 <= END_OF_QUERY1;
                end else begin
                    next_state1 <= HIGH_SCORE1;
                end
            end

            END_OF_QUERY1: begin
                next_state1 <= NO_HIGH_SCORE1;
            end
        endcase
    end
    always @(*) begin
        case(state1)
            NO_HIGH_SCORE1: begin
                if (high_score1 && !stall) begin
                    csff1_wr_en <= 1;
                end else begin
                    csff1_wr_en <= 0;
                end
                end_of_query_sel1 <= 0;
            end
            
            HIGH_SCORE1: begin
                csff1_wr_en <= 0;
                end_of_query_sel1 <= 0;
            end

            END_OF_QUERY1: begin
                if (!stall) begin
                    csff1_wr_en <= 1;
                end else begin
                    csff1_wr_en <= 0;
                end
                end_of_query_sel1 <= 1;
            end
        endcase
    end
    
    // Output FIFOs
    cellscorefilter_fifo csff0 (
        .clk(clk),
        .rst(rst),
        .din(csff0_din),
        .wr_en(csff0_wr_en),
        .rd_en(csff0_rd_en),
        .dout(csff0_dout),
        .full(csff0_full),
        .empty(csff0_empty)
    );
    cellscorefilter_fifo csff1 (
        .clk(clk),
        .rst(rst),
        .din(csff1_din),
        .wr_en(csff1_wr_en),
        .rd_en(csff1_rd_en),
        .dout(csff1_dout),
        .full(csff1_full),
        .empty(csff1_empty)
    );
    assign csff0_din = end_of_query_sel0 ? {EOQ, query_id0} : {ref_block_cnt0, query_id0};
    assign csff1_din = end_of_query_sel1 ? {EOQ, query_id1} : {ref_block_cnt1, query_id1};
    
    // Stall signal
    assign stall_out = stall;
    always @(*) begin
        stall = csff0_full | csff1_full;
    end
    
    // Stream Output Handler interface
    assign result_0_data_out = csff0_dout;
    assign result_0_valid_out = !csff0_empty;
    assign csff0_rd_en = result_0_rdy_in;
    assign result_1_data_out = csff1_dout;
    assign result_1_valid_out = !csff1_empty;
    assign csff1_rd_en = result_1_rdy_in;
                    
endmodule
