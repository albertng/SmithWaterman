/*  File Name        : SmithWatermanArray_QueryBlocks_tb.v
 *  Description      : Testbench for fixed implementation of Smith Waterman systolic array with
 *                     affine gap penalty. Tests query blocking.
 *
 *                     Consecutive alignments with bubbles test:
 *                       Tests two consecutive alignments where len(ref) < 2*len(query), causing
 *                       bubbles in the pipeline. This is because the second alignment cannot
 *                       begin until the second query is loaded into the query buffer. The second
 *                       query cannot begin to be shifted into the query buffer until the first
 *                       query is completely loaded into the systolic array.
 *
 *                     Consecutive alignments without bubbles test:
 *                       Tests two consecutive alignments where len(ref) >= 2*len(query), allowing
 *                       seamless transition between the two alignments. Only one single bubble is 
 *                       inserted into the pipeline to clear the PE's for the second alignment. Otherwise,
 *                       there are no bubbles due to shifting in the next query into the query buffer
 *                       or loading the first query into the systolic array.
 *
 *                     Multiple query blocks test:
 *                       Tests an alignment where query is split into two blocks, computed in two
 *                       iterations. Intermediate values are stored and passed between iterations.
 *                      
 *
 *  Revision History :
 *      Albert Ng   May 13 2013     Initial Revision
 *      Albert Ng   May 14 2013     Added consecutive alignments w/ bubbles test
 *                                  Added consecutive alignments w/o bubbles test
 *      Albert Ng   May 15 2013     Added multiple query blocks test
 *      Albert Ng   Jun 05 2013     Added first_ref_block, next_first_ref_block, last_ref_block, 
 *                                      last_block_char_in
 *      Albert Ng   Jun 24 2013     Added stall
 *      Albert Ng   Jun 26 2013     Changed to sending in full S sequence in parallel
 *      Albert Ng   Jul 16 2013     Added cell score threshold and high score tests
 *
 */

module SmithWatermanArray_QueryBlocks_tb;

    // Inputs
    reg clk;
    reg rst;
    reg stall;
    reg [11:0] S_in1;
    reg [5:0] S_in2;
    reg [1:0] T_in;
    reg store_S_in;
    reg init_in;
    reg [9:0] cell_score_threshold_in;
    reg first_query_block;
    reg next_first_ref_block_in;
    reg first_ref_block_in;
    reg last_ref_block_in;
    reg last_block_char_in;
    reg bypass_fifo_in;

    // Outputs
    wire [59:0] V_out1;
    wire [29:0] V_out2;
    wire [5:0] high_score_out1;
    wire [2:0] high_score_out2;

    // Consecutive alignments w/ bubbles test
    reg [1:0] short_read1 [1:0][5:0];
    reg [1:0] reference1  [7:0];
    reg [9:0] V_out_expected1 [23:0][5:0];
    reg high_score_expected1 [23:0][5:0];
    
    // Consecutive alignments w/o bubbles test
    reg [1:0] short_read2 [1:0][5:0];
    reg [1:0] reference2  [11:0];
    reg [9:0] V_out_expected2 [29:0][5:0];
    reg high_score_expected2 [29:0][5:0];
    
    // Multiple query blocks test
    reg [1:0] short_read3 [5:0];
    reg [1:0] reference3  [7:0];
    reg [9:0] V_out_expected3 [18:0][2:0];
    reg high_score_expected3 [18:0][2:0];

    // Instantiate the Unit Under Test (UUT)
    SmithWatermanArray #(6, 8, 10, 10, -2, -2, -1, 3) uut1 (
        .clk(clk), 
        .rst(rst), 
        .stall(stall),
        .S_in(S_in1), 
        .T_in(T_in), 
        .store_S_in(store_S_in),  
        .init_in(init_in),
        .cell_score_threshold_in(cell_score_threshold_in),
        .first_query_block(first_query_block),
        .next_first_ref_block_in(next_first_ref_block_in),
        .first_ref_block_in(first_ref_block_in),
        .last_ref_block_in(last_ref_block_in),
        .last_block_char_in(last_block_char_in),
        .bypass_fifo_in(bypass_fifo_in),
        .V_out(V_out1),
        .high_score_out(high_score_out1)
    );
    
    SmithWatermanArray #(3, 8, 10, 10, -2, -2, -1, 3) uut2 (
        .clk(clk), 
        .rst(rst), 
        .stall(stall),
        .S_in(S_in2), 
        .T_in(T_in), 
        .store_S_in(store_S_in),  
        .init_in(init_in), 
        .cell_score_threshold_in(cell_score_threshold_in),
        .first_query_block(first_query_block),
        .next_first_ref_block_in(next_first_ref_block_in),
        .first_ref_block_in(first_ref_block_in),
        .last_ref_block_in(last_ref_block_in),
        .last_block_char_in(last_block_char_in),
        .bypass_fifo_in(bypass_fifo_in),
        .V_out(V_out2),
        .high_score_out(high_score_out2)
    );

    integer i;
    integer j;
    initial begin
        stall = 0;
    
        // Consecutive alignments w/ bubbles test
        $display("Consecutive alignments w/ bubbles test");
        cell_score_threshold_in = 45;
        short_read1[0][0] = 2'b00;   // ACACTA
        short_read1[0][1] = 2'b01;
        short_read1[0][2] = 2'b00;
        short_read1[0][3] = 2'b01;
        short_read1[0][4] = 2'b11;
        short_read1[0][5] = 2'b00;
        short_read1[1][0] = 2'b10;   // GCAGCT
        short_read1[1][1] = 2'b01;
        short_read1[1][2] = 2'b00;
        short_read1[1][3] = 2'b10;
        short_read1[1][4] = 2'b01;
        short_read1[1][5] = 2'b11;
        reference1[0] = 2'b00;       // ACAGACTA
        reference1[1] = 2'b01;
        reference1[2] = 2'b00;
        reference1[3] = 2'b10;
        reference1[4] = 2'b00;
        reference1[5] = 2'b01;
        reference1[6] = 2'b11;
        reference1[7] = 2'b00;
        V_out_expected1[0][0] = 10;
        V_out_expected1[0][1] = 0;
        V_out_expected1[0][2] = 0;
        V_out_expected1[0][3] = 0;
        V_out_expected1[0][4] = 0;
        V_out_expected1[0][5] = 0;
        V_out_expected1[1][0] = 8;
        V_out_expected1[1][1] = 8;
        V_out_expected1[1][2] = 0;
        V_out_expected1[1][3] = 0;
        V_out_expected1[1][4] = 0;
        V_out_expected1[1][5] = 0;
        V_out_expected1[2][0] = 10;
        V_out_expected1[2][1] = 20;
        V_out_expected1[2][2] = 10;
        V_out_expected1[2][3] = 0;
        V_out_expected1[2][4] = 0;
        V_out_expected1[2][5] = 0;
        V_out_expected1[3][0] = 8;
        V_out_expected1[3][1] = 18;
        V_out_expected1[3][2] = 18;
        V_out_expected1[3][3] = 8;
        V_out_expected1[3][4] = 0;
        V_out_expected1[3][5] = 0;
        V_out_expected1[4][0] = 10;
        V_out_expected1[4][1] = 17;
        V_out_expected1[4][2] = 30;
        V_out_expected1[4][3] = 20;
        V_out_expected1[4][4] = 7;
        V_out_expected1[4][5] = 0;
        V_out_expected1[5][0] = 8;
        V_out_expected1[5][1] = 16;
        V_out_expected1[5][2] = 28;
        V_out_expected1[5][3] = 28;
        V_out_expected1[5][4] = 18;
        V_out_expected1[5][5] = 10;
        V_out_expected1[6][0] = 7;
        V_out_expected1[6][1] = 20;
        V_out_expected1[6][2] = 27;
        V_out_expected1[6][3] = 28;
        V_out_expected1[6][4] = 27;
        V_out_expected1[6][5] = 17;
        V_out_expected1[7][0] = 10;
        V_out_expected1[7][1] = 18;
        V_out_expected1[7][2] = 26;
        V_out_expected1[7][3] = 26;
        V_out_expected1[7][4] = 26;
        V_out_expected1[7][5] = 28;
        V_out_expected1[8][0] = 0;
        V_out_expected1[8][1] = 17;
        V_out_expected1[8][2] = 25;
        V_out_expected1[8][3] = 37;
        V_out_expected1[8][4] = 26;
        V_out_expected1[8][5] = 26;
        V_out_expected1[9][0] = 0;
        V_out_expected1[9][1] = 0;
        V_out_expected1[9][2] = 28;
        V_out_expected1[9][3] = 35;
        V_out_expected1[9][4] = 35;
        V_out_expected1[9][5] = 36;
        V_out_expected1[10][0] = 0;
        V_out_expected1[10][1] = 0;
        V_out_expected1[10][2] = 0;
        V_out_expected1[10][3] = 34;
        V_out_expected1[10][4] = 47;
        V_out_expected1[10][5] = 34;
        V_out_expected1[11][0] = 0;
        V_out_expected1[11][1] = 0;
        V_out_expected1[11][2] = 0;
        V_out_expected1[11][3] = 0;
        V_out_expected1[11][4] = 45;
        V_out_expected1[11][5] = 45;
        V_out_expected1[12][0] = 0;
        V_out_expected1[12][1] = 0;
        V_out_expected1[12][2] = 0;
        V_out_expected1[12][3] = 0;
        V_out_expected1[12][4] = 0;
        V_out_expected1[12][5] = 57;
        V_out_expected1[13][0] = 0;
        V_out_expected1[13][1] = 10;
        V_out_expected1[13][2] = 10;
        V_out_expected1[13][3] = 0;
        V_out_expected1[13][4] = 0;
        V_out_expected1[13][5] = 0;
        V_out_expected1[14][0] = 10;
        V_out_expected1[14][1] = 8;
        V_out_expected1[14][2] = 8;
        V_out_expected1[14][3] = 8;
        V_out_expected1[14][4] = 0;
        V_out_expected1[14][5] = 0;
        V_out_expected1[15][0] = 8;
        V_out_expected1[15][1] = 8;
        V_out_expected1[15][2] = 20;
        V_out_expected1[15][3] = 8;
        V_out_expected1[15][4] = 7;
        V_out_expected1[15][5] = 0;
        V_out_expected1[16][0] = 7;
        V_out_expected1[16][1] = 8;
        V_out_expected1[16][2] = 18;
        V_out_expected1[16][3] = 18;
        V_out_expected1[16][4] = 18;
        V_out_expected1[16][5] = 6;
        V_out_expected1[17][0] = 6;
        V_out_expected1[17][1] = 18;
        V_out_expected1[17][2] = 18;
        V_out_expected1[17][3] = 30;
        V_out_expected1[17][4] = 17;
        V_out_expected1[17][5] = 16;
        V_out_expected1[18][0] = 5;
        V_out_expected1[18][1] = 16;
        V_out_expected1[18][2] = 16;
        V_out_expected1[18][3] = 28;
        V_out_expected1[18][4] = 28;
        V_out_expected1[18][5] = 16;
        V_out_expected1[19][0] = 0;
        V_out_expected1[19][1] = 15;
        V_out_expected1[19][2] = 16;
        V_out_expected1[19][3] = 27;
        V_out_expected1[19][4] = 28;
        V_out_expected1[19][5] = 27;
        V_out_expected1[20][0] = 0;
        V_out_expected1[20][1] = 0;
        V_out_expected1[20][2] = 26;
        V_out_expected1[20][3] = 26;
        V_out_expected1[20][4] = 38;
        V_out_expected1[20][5] = 26;
        V_out_expected1[21][0] = 0;
        V_out_expected1[21][1] = 0;
        V_out_expected1[21][2] = 0;
        V_out_expected1[21][3] = 25;
        V_out_expected1[21][4] = 36;
        V_out_expected1[21][5] = 36;
        V_out_expected1[22][0] = 0;
        V_out_expected1[22][1] = 0;
        V_out_expected1[22][2] = 0;
        V_out_expected1[22][3] = 0;
        V_out_expected1[22][4] = 35;
        V_out_expected1[22][5] = 48;
        V_out_expected1[23][0] = 0;
        V_out_expected1[23][1] = 0;
        V_out_expected1[23][2] = 0;
        V_out_expected1[23][3] = 0;
        V_out_expected1[23][4] = 0;
        V_out_expected1[23][5] = 46;

        high_score_expected1[0][0] = 0;
        high_score_expected1[0][1] = 0;
        high_score_expected1[0][2] = 0;
        high_score_expected1[0][3] = 0;
        high_score_expected1[0][4] = 0;
        high_score_expected1[0][5] = 0;
        high_score_expected1[1][0] = 8;
        high_score_expected1[1][1] = 8;
        high_score_expected1[1][2] = 0;
        high_score_expected1[1][3] = 0;
        high_score_expected1[1][4] = 0;
        high_score_expected1[1][5] = 0;
        high_score_expected1[2][0] = 0;
        high_score_expected1[2][1] = 0;
        high_score_expected1[2][2] = 0;
        high_score_expected1[2][3] = 0;
        high_score_expected1[2][4] = 0;
        high_score_expected1[2][5] = 0;
        high_score_expected1[3][0] = 0;
        high_score_expected1[3][1] = 0;
        high_score_expected1[3][2] = 0;
        high_score_expected1[3][3] = 0;
        high_score_expected1[3][4] = 0;
        high_score_expected1[3][5] = 0;
        high_score_expected1[4][0] = 0;
        high_score_expected1[4][1] = 0;
        high_score_expected1[4][2] = 0;
        high_score_expected1[4][3] = 0;
        high_score_expected1[4][4] = 0;
        high_score_expected1[4][5] = 0;
        high_score_expected1[5][0] = 0;
        high_score_expected1[5][1] = 0;
        high_score_expected1[5][2] = 0;
        high_score_expected1[5][3] = 0;
        high_score_expected1[5][4] = 0;
        high_score_expected1[5][5] = 0;
        high_score_expected1[6][0] = 0;
        high_score_expected1[6][1] = 0;
        high_score_expected1[6][2] = 0;
        high_score_expected1[6][3] = 0;
        high_score_expected1[6][4] = 0;
        high_score_expected1[6][5] = 0;
        high_score_expected1[7][0] = 0;
        high_score_expected1[7][1] = 0;
        high_score_expected1[7][2] = 0;
        high_score_expected1[7][3] = 0;
        high_score_expected1[7][4] = 0;
        high_score_expected1[7][5] = 0;
        high_score_expected1[8][0] = 0;
        high_score_expected1[8][1] = 0;
        high_score_expected1[8][2] = 0;
        high_score_expected1[8][3] = 0;
        high_score_expected1[8][4] = 0;
        high_score_expected1[8][5] = 0;
        high_score_expected1[9][0] = 0;
        high_score_expected1[9][1] = 0;
        high_score_expected1[9][2] = 0;
        high_score_expected1[9][3] = 0;
        high_score_expected1[9][4] = 0;
        high_score_expected1[9][5] = 0;
        high_score_expected1[10][0] = 0;
        high_score_expected1[10][1] = 0;
        high_score_expected1[10][2] = 0;
        high_score_expected1[10][3] = 0;
        high_score_expected1[10][4] = 1;
        high_score_expected1[10][5] = 0;
        high_score_expected1[11][0] = 0;
        high_score_expected1[11][1] = 0;
        high_score_expected1[11][2] = 0;
        high_score_expected1[11][3] = 0;
        high_score_expected1[11][4] = 1;
        high_score_expected1[11][5] = 1;
        high_score_expected1[12][0] = 0;
        high_score_expected1[12][1] = 0;
        high_score_expected1[12][2] = 0;
        high_score_expected1[12][3] = 0;
        high_score_expected1[12][4] = 0;
        high_score_expected1[12][5] = 1;
        high_score_expected1[13][0] = 0;
        high_score_expected1[13][1] = 0;
        high_score_expected1[13][2] = 0;
        high_score_expected1[13][3] = 0;
        high_score_expected1[13][4] = 0;
        high_score_expected1[13][5] = 0;
        high_score_expected1[14][0] = 0;
        high_score_expected1[14][1] = 0;
        high_score_expected1[14][2] = 0;
        high_score_expected1[14][3] = 0;
        high_score_expected1[14][4] = 0;
        high_score_expected1[14][5] = 0;
        high_score_expected1[15][0] = 0;
        high_score_expected1[15][1] = 0;
        high_score_expected1[15][2] = 0;
        high_score_expected1[15][3] = 0;
        high_score_expected1[15][4] = 0;
        high_score_expected1[15][5] = 0;
        high_score_expected1[16][0] = 0;
        high_score_expected1[16][1] = 0;
        high_score_expected1[16][2] = 0;
        high_score_expected1[16][3] = 0;
        high_score_expected1[16][4] = 0;
        high_score_expected1[16][5] = 0;
        high_score_expected1[17][0] = 0;
        high_score_expected1[17][1] = 0;
        high_score_expected1[17][2] = 0;
        high_score_expected1[17][3] = 0;
        high_score_expected1[17][4] = 0;
        high_score_expected1[17][5] = 0;
        high_score_expected1[18][0] = 0;
        high_score_expected1[18][1] = 0;
        high_score_expected1[18][2] = 0;
        high_score_expected1[18][3] = 0;
        high_score_expected1[18][4] = 0;
        high_score_expected1[18][5] = 0;
        high_score_expected1[19][0] = 0;
        high_score_expected1[19][1] = 0;
        high_score_expected1[19][2] = 0;
        high_score_expected1[19][3] = 0;
        high_score_expected1[19][4] = 0;
        high_score_expected1[19][5] = 0;
        high_score_expected1[20][0] = 0;
        high_score_expected1[20][1] = 0;
        high_score_expected1[20][2] = 0;
        high_score_expected1[20][3] = 0;
        high_score_expected1[20][4] = 0;
        high_score_expected1[20][5] = 0;
        high_score_expected1[21][0] = 0;
        high_score_expected1[21][1] = 0;
        high_score_expected1[21][2] = 0;
        high_score_expected1[21][3] = 0;
        high_score_expected1[21][4] = 0;
        high_score_expected1[21][5] = 0;
        high_score_expected1[22][0] = 0;
        high_score_expected1[22][1] = 0;
        high_score_expected1[22][2] = 0;
        high_score_expected1[22][3] = 0;
        high_score_expected1[22][4] = 0;
        high_score_expected1[22][5] = 1;
        high_score_expected1[23][0] = 0;
        high_score_expected1[23][1] = 0;
        high_score_expected1[23][2] = 0;
        high_score_expected1[23][3] = 0;
        high_score_expected1[23][4] = 0;
        high_score_expected1[23][5] = 1;
    
        // Initialize inputs, variables, and wait for reset
        clk <= 0;
        rst <= 1;
        S_in1 <= 0;
        T_in <= 0;
        store_S_in <= 0;
        init_in <= 0;
        first_query_block <= 0;
        next_first_ref_block_in <= 1;
        first_ref_block_in <= 1;
        last_ref_block_in <= 0;
        last_block_char_in <= 0;
        bypass_fifo_in <= 1;
        #20;
        rst <= 0;

        // Generate stimulus
        for (i = 0; i < 6; i = i + 1) begin
            S_in1[i*2 + 1 -: 2] <= short_read1[0][i];
        end
        store_S_in <= 1;
        first_query_block <= 1;
        #10;
        for (i = 0; i < 5; i = i + 1) begin
            T_in <= reference1[i];
            init_in <= 1;
            store_S_in <= 0;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (high_score_out1[j] != high_score_expected1[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected1[i][j]);
                end
            end
        end
        
        for (i = 5; i < 6; i = i + 1) begin
            T_in <= reference1[i];
            init_in <= 1;
            for (j = 0; j < 6; j = j + 1) begin
                S_in1[j * 2 + 1 -: 2] <= short_read1[1][j];
            end
            #10
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (high_score_out1[j] != high_score_expected1[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected1[i][j]);
                end
            end
        end
        
        for (i = 6; i < 8; i = i + 1) begin
            T_in <= reference1[i];
            init_in <= 1;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (high_score_out1[j] != high_score_expected1[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected1[i][j]);
                end
            end
        end
        
        for (i = 8; i < 10; i = i + 1) begin
            init_in <= 0;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (high_score_out1[j] != high_score_expected1[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected1[i][j]);
                end
            end
        end
        
        for (i = 10; i < 11; i = i + 1) begin
            store_S_in <= 1;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (high_score_out1[j] != high_score_expected1[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected1[i][j]);
                end
            end
        end
        
        for (i = 11; i < 19; i = i + 1) begin
            T_in <= reference1[i - 11];
            init_in <= 1;
            store_S_in <= 0;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (high_score_out1[j] != high_score_expected1[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected1[i][j]);
                end
            end
        end
        
        for (i = 19; i < 24; i = i + 1) begin
            init_in <= 0;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (high_score_out1[j] != high_score_expected1[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected1[i][j]);
                end
            end
        end

        // Consecutive alignments w/o bubbles test
        $display("Consecutive alignments w/o bubbles test");
        cell_score_threshold_in = 48;
        short_read2[0][0] = 2'b10;   // GCAGCT
        short_read2[0][1] = 2'b01;
        short_read2[0][2] = 2'b00;
        short_read2[0][3] = 2'b10;
        short_read2[0][4] = 2'b01;
        short_read2[0][5] = 2'b11;
        short_read2[1][0] = 2'b00;   // ACACTA
        short_read2[1][1] = 2'b01;
        short_read2[1][2] = 2'b00;
        short_read2[1][3] = 2'b01;
        short_read2[1][4] = 2'b11;
        short_read2[1][5] = 2'b00;
        reference2[0] = 2'b00;       // ACAGACTATGCT
        reference2[1] = 2'b01;
        reference2[2] = 2'b00;
        reference2[3] = 2'b10;
        reference2[4] = 2'b00;
        reference2[5] = 2'b01;
        reference2[6] = 2'b11;
        reference2[7] = 2'b00;
        reference2[8] = 2'b11;
        reference2[9] = 2'b10;
        reference2[10] = 2'b01;
        reference2[11] = 2'b11;
        high_score_expected2[0][0] = 0;
        high_score_expected2[0][1] = 0;
        high_score_expected2[0][2] = 0;
        high_score_expected2[0][3] = 0;
        high_score_expected2[0][4] = 0;
        high_score_expected2[0][5] = 0;
        high_score_expected2[1][0] = 0;
        high_score_expected2[1][1] = 0;
        high_score_expected2[1][2] = 0;
        high_score_expected2[1][3] = 0;
        high_score_expected2[1][4] = 0;
        high_score_expected2[1][5] = 0;
        high_score_expected2[2][0] = 0;
        high_score_expected2[2][1] = 0;
        high_score_expected2[2][2] = 0;
        high_score_expected2[2][3] = 0;
        high_score_expected2[2][4] = 0;
        high_score_expected2[2][5] = 0;
        high_score_expected2[3][0] = 0;
        high_score_expected2[3][1] = 0;
        high_score_expected2[3][2] = 0;
        high_score_expected2[3][3] = 0;
        high_score_expected2[3][4] = 0;
        high_score_expected2[3][5] = 0;
        high_score_expected2[4][0] = 0;
        high_score_expected2[4][1] = 0;
        high_score_expected2[4][2] = 0;
        high_score_expected2[4][3] = 0;
        high_score_expected2[4][4] = 0;
        high_score_expected2[4][5] = 0;
        high_score_expected2[5][0] = 0;
        high_score_expected2[5][1] = 0;
        high_score_expected2[5][2] = 0;
        high_score_expected2[5][3] = 0;
        high_score_expected2[5][4] = 0;
        high_score_expected2[5][5] = 0;
        high_score_expected2[6][0] = 0;
        high_score_expected2[6][1] = 0;
        high_score_expected2[6][2] = 0;
        high_score_expected2[6][3] = 0;
        high_score_expected2[6][4] = 0;
        high_score_expected2[6][5] = 0;
        high_score_expected2[7][0] = 0;
        high_score_expected2[7][1] = 0;
        high_score_expected2[7][2] = 0;
        high_score_expected2[7][3] = 0;
        high_score_expected2[7][4] = 0;
        high_score_expected2[7][5] = 0;
        high_score_expected2[8][0] = 0;
        high_score_expected2[8][1] = 0;
        high_score_expected2[8][2] = 0;
        high_score_expected2[8][3] = 0;
        high_score_expected2[8][4] = 0;
        high_score_expected2[8][5] = 0;
        high_score_expected2[9][0] = 0;
        high_score_expected2[9][1] = 0;
        high_score_expected2[9][2] = 0;
        high_score_expected2[9][3] = 0;
        high_score_expected2[9][4] = 0;
        high_score_expected2[9][5] = 0;
        high_score_expected2[10][0] = 0;
        high_score_expected2[10][1] = 0;
        high_score_expected2[10][2] = 0;
        high_score_expected2[10][3] = 0;
        high_score_expected2[10][4] = 0;
        high_score_expected2[10][5] = 0;
        high_score_expected2[11][0] = 0;
        high_score_expected2[11][1] = 0;
        high_score_expected2[11][2] = 0;
        high_score_expected2[11][3] = 0;
        high_score_expected2[11][4] = 0;
        high_score_expected2[11][5] = 1;
        high_score_expected2[12][0] = 0;
        high_score_expected2[12][1] = 0;
        high_score_expected2[12][2] = 0;
        high_score_expected2[12][3] = 0;
        high_score_expected2[12][4] = 0;
        high_score_expected2[12][5] = 0;
        high_score_expected2[13][0] = 0;
        high_score_expected2[13][1] = 0;
        high_score_expected2[13][2] = 0;
        high_score_expected2[13][3] = 0;
        high_score_expected2[13][4] = 0;
        high_score_expected2[13][5] = 0;
        high_score_expected2[14][0] = 0;
        high_score_expected2[14][1] = 0;
        high_score_expected2[14][2] = 0;
        high_score_expected2[14][3] = 0;
        high_score_expected2[14][4] = 0;
        high_score_expected2[14][5] = 0;
        high_score_expected2[15][0] = 0;
        high_score_expected2[15][1] = 0;
        high_score_expected2[15][2] = 0;
        high_score_expected2[15][3] = 0;
        high_score_expected2[15][4] = 0;
        high_score_expected2[15][5] = 0;
        high_score_expected2[16][0] = 0;
        high_score_expected2[16][1] = 0;
        high_score_expected2[16][2] = 0;
        high_score_expected2[16][3] = 0;
        high_score_expected2[16][4] = 0;
        high_score_expected2[16][5] = 1;
        high_score_expected2[17][0] = 0;
        high_score_expected2[17][1] = 0;
        high_score_expected2[17][2] = 0;
        high_score_expected2[17][3] = 0;
        high_score_expected2[17][4] = 0;
        high_score_expected2[17][5] = 0;
        high_score_expected2[18][0] = 0;
        high_score_expected2[18][1] = 0;
        high_score_expected2[18][2] = 0;
        high_score_expected2[18][3] = 0;
        high_score_expected2[18][4] = 0;
        high_score_expected2[18][5] = 0;
        high_score_expected2[19][0] = 0;
        high_score_expected2[19][1] = 0;
        high_score_expected2[19][2] = 0;
        high_score_expected2[19][3] = 0;
        high_score_expected2[19][4] = 0;
        high_score_expected2[19][5] = 0;
        high_score_expected2[20][0] = 0;
        high_score_expected2[20][1] = 0;
        high_score_expected2[20][2] = 0;
        high_score_expected2[20][3] = 0;
        high_score_expected2[20][4] = 0;
        high_score_expected2[20][5] = 0;
        high_score_expected2[21][0] = 0;
        high_score_expected2[21][1] = 0;
        high_score_expected2[21][2] = 0;
        high_score_expected2[21][3] = 0;
        high_score_expected2[21][4] = 0;
        high_score_expected2[21][5] = 0;
        high_score_expected2[22][0] = 0;
        high_score_expected2[22][1] = 0;
        high_score_expected2[22][2] = 0;
        high_score_expected2[22][3] = 0;
        high_score_expected2[22][4] = 0;
        high_score_expected2[22][5] = 0;
        high_score_expected2[23][0] = 0;
        high_score_expected2[23][1] = 0;
        high_score_expected2[23][2] = 0;
        high_score_expected2[23][3] = 0;
        high_score_expected2[23][4] = 0;
        high_score_expected2[23][5] = 0;
        high_score_expected2[24][0] = 0;
        high_score_expected2[24][1] = 0;
        high_score_expected2[24][2] = 0;
        high_score_expected2[24][3] = 0;
        high_score_expected2[24][4] = 0;
        high_score_expected2[24][5] = 0;
        high_score_expected2[25][0] = 0;
        high_score_expected2[25][1] = 0;
        high_score_expected2[25][2] = 0;
        high_score_expected2[25][3] = 0;
        high_score_expected2[25][4] = 0;
        high_score_expected2[25][5] = 1;
        high_score_expected2[26][0] = 0;
        high_score_expected2[26][1] = 0;
        high_score_expected2[26][2] = 0;
        high_score_expected2[26][3] = 0;
        high_score_expected2[26][4] = 0;
        high_score_expected2[26][5] = 1;
        high_score_expected2[27][0] = 0;
        high_score_expected2[27][1] = 0;
        high_score_expected2[27][2] = 0;
        high_score_expected2[27][3] = 0;
        high_score_expected2[27][4] = 0;
        high_score_expected2[27][5] = 1;
        high_score_expected2[28][0] = 0;
        high_score_expected2[28][1] = 0;
        high_score_expected2[28][2] = 0;
        high_score_expected2[28][3] = 0;
        high_score_expected2[28][4] = 0;
        high_score_expected2[28][5] = 1;
        high_score_expected2[29][0] = 0;
        high_score_expected2[29][1] = 0;
        high_score_expected2[29][2] = 0;
        high_score_expected2[29][3] = 0;
        high_score_expected2[29][4] = 0;
        high_score_expected2[29][5] = 1;

        V_out_expected2[0][0] = 0;
        V_out_expected2[0][1] = 0;
        V_out_expected2[0][2] = 0;
        V_out_expected2[0][3] = 0;
        V_out_expected2[0][4] = 0;
        V_out_expected2[0][5] = 0;
        V_out_expected2[1][0] = 0;
        V_out_expected2[1][1] = 0;
        V_out_expected2[1][2] = 0;
        V_out_expected2[1][3] = 0;
        V_out_expected2[1][4] = 0;
        V_out_expected2[1][5] = 0;
        V_out_expected2[2][0] = 0;
        V_out_expected2[2][1] = 10;
        V_out_expected2[2][2] = 10;
        V_out_expected2[2][3] = 0;
        V_out_expected2[2][4] = 0;
        V_out_expected2[2][5] = 0;
        V_out_expected2[3][0] = 10;
        V_out_expected2[3][1] = 8;
        V_out_expected2[3][2] = 8;
        V_out_expected2[3][3] = 8;
        V_out_expected2[3][4] = 0;
        V_out_expected2[3][5] = 0;
        V_out_expected2[4][0] = 8;
        V_out_expected2[4][1] = 8;
        V_out_expected2[4][2] = 20;
        V_out_expected2[4][3] = 8;
        V_out_expected2[4][4] = 7;
        V_out_expected2[4][5] = 0;
        V_out_expected2[5][0] = 7;
        V_out_expected2[5][1] = 8;
        V_out_expected2[5][2] = 18;
        V_out_expected2[5][3] = 18;
        V_out_expected2[5][4] = 18;
        V_out_expected2[5][5] = 6;
        V_out_expected2[6][0] = 6;
        V_out_expected2[6][1] = 18;
        V_out_expected2[6][2] = 18;
        V_out_expected2[6][3] = 30;
        V_out_expected2[6][4] = 17;
        V_out_expected2[6][5] = 16;
        V_out_expected2[7][0] = 5;
        V_out_expected2[7][1] = 16;
        V_out_expected2[7][2] = 16;
        V_out_expected2[7][3] = 28;
        V_out_expected2[7][4] = 28;
        V_out_expected2[7][5] = 16;
        V_out_expected2[8][0] = 4;
        V_out_expected2[8][1] = 15;
        V_out_expected2[8][2] = 16;
        V_out_expected2[8][3] = 27;
        V_out_expected2[8][4] = 28;
        V_out_expected2[8][5] = 27;
        V_out_expected2[9][0] = 10;
        V_out_expected2[9][1] = 14;
        V_out_expected2[9][2] = 26;
        V_out_expected2[9][3] = 26;
        V_out_expected2[9][4] = 38;
        V_out_expected2[9][5] = 26;
        V_out_expected2[10][0] = 8;
        V_out_expected2[10][1] = 13;
        V_out_expected2[10][2] = 24;
        V_out_expected2[10][3] = 25;
        V_out_expected2[10][4] = 36;
        V_out_expected2[10][5] = 36;
        V_out_expected2[11][0] = 7;
        V_out_expected2[11][1] = 20;
        V_out_expected2[11][2] = 23;
        V_out_expected2[11][3] = 24;
        V_out_expected2[11][4] = 35;
        V_out_expected2[11][5] = 48;
        V_out_expected2[12][0] = 0;
        V_out_expected2[12][1] = 18;
        V_out_expected2[12][2] = 22;
        V_out_expected2[12][3] = 34;
        V_out_expected2[12][4] = 34;
        V_out_expected2[12][5] = 46;
        V_out_expected2[13][0] = 10;
        V_out_expected2[13][1] = 0;
        V_out_expected2[13][2] = 21;
        V_out_expected2[13][3] = 32;
        V_out_expected2[13][4] = 33;
        V_out_expected2[13][5] = 45;
        V_out_expected2[14][0] = 8;
        V_out_expected2[14][1] = 8;
        V_out_expected2[14][2] = 0;
        V_out_expected2[14][3] = 31;
        V_out_expected2[14][4] = 44;
        V_out_expected2[14][5] = 44;
        V_out_expected2[15][0] = 10;
        V_out_expected2[15][1] = 20;
        V_out_expected2[15][2] = 10;
        V_out_expected2[15][3] = 0;
        V_out_expected2[15][4] = 42;
        V_out_expected2[15][5] = 43;
        V_out_expected2[16][0] = 8;
        V_out_expected2[16][1] = 18;
        V_out_expected2[16][2] = 18;
        V_out_expected2[16][3] = 8;
        V_out_expected2[16][4] = 0;
        V_out_expected2[16][5] = 54;
        V_out_expected2[17][0] = 10;
        V_out_expected2[17][1] = 17;
        V_out_expected2[17][2] = 30;
        V_out_expected2[17][3] = 20;
        V_out_expected2[17][4] = 7;
        V_out_expected2[17][5] = 0;
        V_out_expected2[18][0] = 8;
        V_out_expected2[18][1] = 16;
        V_out_expected2[18][2] = 28;
        V_out_expected2[18][3] = 28;
        V_out_expected2[18][4] = 18;
        V_out_expected2[18][5] = 10;
        V_out_expected2[19][0] = 7;
        V_out_expected2[19][1] = 20;
        V_out_expected2[19][2] = 27;
        V_out_expected2[19][3] = 28;
        V_out_expected2[19][4] = 27;
        V_out_expected2[19][5] = 17;
        V_out_expected2[20][0] = 10;
        V_out_expected2[20][1] = 18;
        V_out_expected2[20][2] = 26;
        V_out_expected2[20][3] = 26;
        V_out_expected2[20][4] = 26;
        V_out_expected2[20][5] = 28;
        V_out_expected2[21][0] = 8;
        V_out_expected2[21][1] = 17;
        V_out_expected2[21][2] = 25;
        V_out_expected2[21][3] = 37;
        V_out_expected2[21][4] = 26;
        V_out_expected2[21][5] = 26;
        V_out_expected2[22][0] = 7;
        V_out_expected2[22][1] = 16;
        V_out_expected2[22][2] = 28;
        V_out_expected2[22][3] = 35;
        V_out_expected2[22][4] = 35;
        V_out_expected2[22][5] = 36;
        V_out_expected2[23][0] = 6;
        V_out_expected2[23][1] = 15;
        V_out_expected2[23][2] = 26;
        V_out_expected2[23][3] = 34;
        V_out_expected2[23][4] = 47;
        V_out_expected2[23][5] = 34;
        V_out_expected2[24][0] = 5;
        V_out_expected2[24][1] = 17;
        V_out_expected2[24][2] = 25;
        V_out_expected2[24][3] = 33;
        V_out_expected2[24][4] = 45;
        V_out_expected2[24][5] = 45;
        V_out_expected2[25][0] = 0;
        V_out_expected2[25][1] = 15;
        V_out_expected2[25][2] = 24;
        V_out_expected2[25][3] = 32;
        V_out_expected2[25][4] = 44;
        V_out_expected2[25][5] = 57;
        V_out_expected2[26][0] = 0;
        V_out_expected2[26][1] = 0;
        V_out_expected2[26][2] = 23;
        V_out_expected2[26][3] = 35;
        V_out_expected2[26][4] = 43;
        V_out_expected2[26][5] = 55;
        V_out_expected2[27][0] = 0;
        V_out_expected2[27][1] = 0;
        V_out_expected2[27][2] = 0;
        V_out_expected2[27][3] = 33;
        V_out_expected2[27][4] = 42;
        V_out_expected2[27][5] = 54;
        V_out_expected2[28][0] = 0;
        V_out_expected2[28][1] = 0;
        V_out_expected2[28][2] = 0;
        V_out_expected2[28][3] = 0;
        V_out_expected2[28][4] = 45;
        V_out_expected2[28][5] = 53;
        V_out_expected2[29][0] = 0;
        V_out_expected2[29][1] = 0;
        V_out_expected2[29][2] = 0;
        V_out_expected2[29][3] = 0;
        V_out_expected2[29][4] = 0;
        V_out_expected2[29][5] = 52;

        for (i = 0; i < 6; i = i + 1) begin
            S_in1[i*2 + 1 -: 2] <= short_read2[0][i];
        end
        store_S_in <= 1;
        #10;
        
        for (i = 0; i < 5; i = i + 1) begin
            T_in <= reference2[i];
            store_S_in <= 0;
            init_in <= 1;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (high_score_out1[j] != high_score_expected2[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected2[i][j]);
                end
            end
        end
        
        for (i = 5; i < 6; i = i + 1) begin
            T_in <= reference2[i];
            init_in <= 1;
            for (j = 0; j < 6; j = j + 1) begin
                S_in1[j * 2 + 1 -: 2] <= short_read2[1][j];
            end
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (high_score_out1[j] != high_score_expected2[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected2[i][j]);
                end
            end
        end
        
        for (i = 6; i < 12; i = i + 1) begin
            T_in <= reference2[i];
            init_in <= 1;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (high_score_out1[j] != high_score_expected2[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected2[i][j]);
                end
            end
        end
        
        for (i = 12; i < 13; i = i + 1) begin
            init_in <= 0;
            store_S_in <= 1;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (high_score_out1[j] != high_score_expected2[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected2[i][j]);
                end
            end
        end
        
        for (i = 13; i < 25; i = i + 1) begin
            T_in <= reference2[i - 13];
            init_in <= 1;
            store_S_in <= 0;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (high_score_out1[j] != high_score_expected2[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected2[i][j]);
                end
            end
        end
        
        for (i = 25; i < 30; i = i + 1) begin
            init_in <= 0;
            #10;
            $display("%d %d %d %d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20], V_out1[39:30], V_out1[49:40], V_out1[59:50]);
            for (j = 0; j < 6; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (high_score_out1[j] != high_score_expected2[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out1[j], high_score_expected2[i][j]);
                end
            end
        end
        
        
        // Multiple query blocks test
        $display("Multiple query blocks test");
        cell_score_threshold_in = 36;
        short_read3[0] = 2'b00;   // ACACTA
        short_read3[1] = 2'b01;
        short_read3[2] = 2'b00;
        short_read3[3] = 2'b01;
        short_read3[4] = 2'b11;
        short_read3[5] = 2'b00;
        reference3[0] = 2'b00;       // ACAGACTA
        reference3[1] = 2'b01;
        reference3[2] = 2'b00;
        reference3[3] = 2'b10;
        reference3[4] = 2'b00;
        reference3[5] = 2'b01;
        reference3[6] = 2'b11;
        reference3[7] = 2'b00;
        V_out_expected3[0][0] = 10;
        V_out_expected3[0][1] = 0;
        V_out_expected3[0][2] = 0;
        V_out_expected3[1][0] = 8;
        V_out_expected3[1][1] = 8;
        V_out_expected3[1][2] = 0;
        V_out_expected3[2][0] = 10;
        V_out_expected3[2][1] = 20;
        V_out_expected3[2][2] = 10;
        V_out_expected3[3][0] = 8;
        V_out_expected3[3][1] = 18;
        V_out_expected3[3][2] = 18;
        V_out_expected3[4][0] = 10;
        V_out_expected3[4][1] = 17;
        V_out_expected3[4][2] = 30;
        V_out_expected3[5][0] = 8;
        V_out_expected3[5][1] = 16;
        V_out_expected3[5][2] = 28;
        V_out_expected3[6][0] = 7;
        V_out_expected3[6][1] = 20;
        V_out_expected3[6][2] = 27;
        V_out_expected3[7][0] = 10;
        V_out_expected3[7][1] = 18;
        V_out_expected3[7][2] = 26;
        V_out_expected3[8][0] = 0;
        V_out_expected3[8][1] = 17;
        V_out_expected3[8][2] = 25;
        V_out_expected3[9][0] = 8;
        V_out_expected3[9][1] = 0;
        V_out_expected3[9][2] = 28;
        V_out_expected3[10][0] = 20;
        V_out_expected3[10][1] = 7;
        V_out_expected3[10][2] = 0;
        V_out_expected3[11][0] = 28;
        V_out_expected3[11][1] = 18;
        V_out_expected3[11][2] = 10;
        V_out_expected3[12][0] = 28;
        V_out_expected3[12][1] = 27;
        V_out_expected3[12][2] = 17;
        V_out_expected3[13][0] = 26;
        V_out_expected3[13][1] = 26;
        V_out_expected3[13][2] = 28;
        V_out_expected3[14][0] = 37;
        V_out_expected3[14][1] = 26;
        V_out_expected3[14][2] = 26;
        V_out_expected3[15][0] = 35;
        V_out_expected3[15][1] = 35;
        V_out_expected3[15][2] = 36;
        V_out_expected3[16][0] = 34;
        V_out_expected3[16][1] = 47;
        V_out_expected3[16][2] = 34;
        V_out_expected3[17][0] = 0;
        V_out_expected3[17][1] = 45;
        V_out_expected3[17][2] = 45;
        V_out_expected3[18][0] = 0;
        V_out_expected3[18][1] = 0;
        V_out_expected3[18][2] = 57;

        high_score_expected3[0][0] = 0;
        high_score_expected3[0][1] = 0;
        high_score_expected3[0][2] = 0;
        high_score_expected3[1][0] = 0;
        high_score_expected3[1][1] = 0;
        high_score_expected3[1][2] = 0;
        high_score_expected3[2][0] = 0;
        high_score_expected3[2][1] = 0;
        high_score_expected3[2][2] = 0;
        high_score_expected3[3][0] = 0;
        high_score_expected3[3][1] = 0;
        high_score_expected3[3][2] = 0;
        high_score_expected3[4][0] = 0;
        high_score_expected3[4][1] = 0;
        high_score_expected3[4][2] = 0;
        high_score_expected3[5][0] = 0;
        high_score_expected3[5][1] = 0;
        high_score_expected3[5][2] = 0;
        high_score_expected3[6][0] = 0;
        high_score_expected3[6][1] = 0;
        high_score_expected3[6][2] = 0;
        high_score_expected3[7][0] = 0;
        high_score_expected3[7][1] = 0;
        high_score_expected3[7][2] = 0;
        high_score_expected3[8][0] = 0;
        high_score_expected3[8][1] = 0;
        high_score_expected3[8][2] = 0;
        high_score_expected3[9][0] = 0;
        high_score_expected3[9][1] = 0;
        high_score_expected3[9][2] = 0;
        high_score_expected3[10][0] = 0;
        high_score_expected3[10][1] = 0;
        high_score_expected3[10][2] = 0;
        high_score_expected3[11][0] = 0;
        high_score_expected3[11][1] = 0;
        high_score_expected3[11][2] = 0;
        high_score_expected3[12][0] = 0;
        high_score_expected3[12][1] = 0;
        high_score_expected3[12][2] = 0;
        high_score_expected3[13][0] = 0;
        high_score_expected3[13][1] = 0;
        high_score_expected3[13][2] = 0;
        high_score_expected3[14][0] = 1;
        high_score_expected3[14][1] = 0;
        high_score_expected3[14][2] = 0;
        high_score_expected3[15][0] = 0;
        high_score_expected3[15][1] = 0;
        high_score_expected3[15][2] = 1;
        high_score_expected3[16][0] = 0;
        high_score_expected3[16][1] = 1;
        high_score_expected3[16][2] = 0;
        high_score_expected3[17][0] = 0;
        high_score_expected3[17][1] = 1;
        high_score_expected3[17][2] = 1;
        high_score_expected3[18][0] = 0;
        high_score_expected3[18][1] = 0;
        high_score_expected3[18][2] = 1;

        for (i = 0; i < 3; i = i + 1) begin
            S_in2[i*2+1 -: 2] <= short_read3[i]; // Shift in reverse
        end
        store_S_in <= 1;
        #10;
        for (i = 0; i < 2; i = i + 1) begin
            T_in <= reference3[i];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            #10;
            $display("%d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected3[i][j]) begin
                    $display("%d ns: V_out error, Cycle %d PE %d: Got %d expected %d", $time, i, j, V_out2[j*10+9 -: 10], V_out_expected3[i][j]);
                end
                if (high_score_out2[j] != high_score_expected3[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out2[j], high_score_expected3[i][j]);
                end
            end
        end
        
        for (i = 2; i < 3; i = i + 1) begin
            T_in <= reference3[i];
            init_in <= 1;
            for (j = 0; j < 3; j = j + 1) begin
                S_in2[j*2 + 1 -: 2] <= short_read3[j+3];
            end
            first_query_block <= 1;
            #10;
            $display("%d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected3[i][j]) begin
                    $display("%d ns: V_out error, Cycle %d PE %d: Got %d expected %d", $time, i, j, V_out2[j*10+9 -: 10], V_out_expected3[i][j]);
                end
                if (high_score_out2[j] != high_score_expected3[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out2[j], high_score_expected3[i][j]);
                end
            end
        end
        
        for (i = 3; i < 8; i = i + 1) begin
            T_in <= reference3[i];
            init_in <= 1;
            first_query_block <= 1;
            #10;
            $display("%d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected3[i][j]) begin
                    $display("%d ns: V_out error, Cycle %d PE %d: Got %d expected %d", $time, i, j, V_out2[j*10+9 -: 10], V_out_expected3[i][j]);
                end
                if (high_score_out2[j] != high_score_expected3[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out2[j], high_score_expected3[i][j]);
                end
            end
        end
        
        for (i = 8; i < 9; i = i + 1) begin
            init_in <= 0;
            store_S_in <= 1;
            first_query_block <= 0;
            #10;
            $display("%d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected3[i][j]) begin
                    $display("%d ns: V_out error, Cycle %d PE %d: Got %d expected %d", $time, i, j, V_out2[j*10+9 -: 10], V_out_expected3[i][j]);
                end
                if (high_score_out2[j] != high_score_expected3[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out2[j], high_score_expected3[i][j]);
                end
            end
        end
        
        for (i = 9; i < 17; i = i + 1) begin
            T_in <= reference3[i-9];
            store_S_in <= 0;
            init_in <= 1;
            first_query_block <= 0;
            #10;
            $display("%d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected3[i][j]) begin
                    $display("%d ns: V_out error, Cycle %d PE %d: Got %d expected %d", $time, i, j, V_out2[j*10+9 -: 10], V_out_expected3[i][j]);
                end
                if (high_score_out2[j] != high_score_expected3[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out2[j], high_score_expected3[i][j]);
                end
            end
        end
        
        for (i = 17; i < 19; i = i + 1) begin
            init_in <= 0;
            #10;
            $display("%d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected3[i][j]) begin
                    $display("%d ns: V_out error, Cycle %d PE %d: Got %d expected %d", $time, i, j, V_out2[j*10+9 -: 10], V_out_expected3[i][j]);
                end
                if (high_score_out2[j] != high_score_expected3[i][j]) begin
                    $display("high_score_out error, Cycle %d PE %d: Got %d expected %d", i, j, high_score_out2[j], high_score_expected3[i][j]);
                end
            end
        end
        
        #100;
        $finish;
    end
    
    always begin
        #5 clk = !clk;
    end
      
endmodule

