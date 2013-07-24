/*  File Name        : SmithWatermanArray_ReferenceBlocks_tb.v
 *  Description      : Testbench for fixed implementation of Smith Waterman systolic array with
 *                     affine gap penalty. Tests reference blocking.             
 *
 *  Revision History :
 *      Albert Ng   Jun 06 2013     Initial Revision
 *                                  Completed multiple query block, multiple ref block
 *                                      test
 *      Albert Ng   Jun 24 2013     Completed single query block, multiple ref block 
 *                                      test
 *                                  Added stall
 *      Albert Ng   Jun 26 2013     Changed to sending in full S sequence in parallel
 *      Albert Ng   Jul 24 2013     Added V_out_valid tests
 *
 */

module SmithWatermanArray_ReferenceBlocks_tb;

    // Inputs
    reg clk;
    reg rst;
    reg stall;
    reg [5:0] S_in1;
    reg [7:0] S_in2;
    reg [1:0] T_in;
    reg store_S_in;
    reg init_in;
    reg first_query_block;
    reg next_first_ref_block_in;
    reg first_ref_block_in;
    reg last_ref_block_in;
    reg last_block_char_in;
    reg bypass_fifo_in;

    // Outputs
    wire [29:0] V_out1;
    wire [2:0]  V_out_valid1;
    wire [39:0] V_out2;
    wire [3:0]  V_out_valid2;

    // Multiple query block, multiple reference block, 3 PEs per FIFO test
    reg [1:0] short_read1 [5:0];
    reg [1:0] reference1  [7:0];
    reg [9:0] V_out_expected1 [20:0][2:0];
    reg V_out_valid_expected1 [20:0][2:0];
    SmithWatermanArray #(3, 4, 10, 10, -2, -2, -1, 3) uut1 (
        .clk(clk), 
        .rst(rst),
        .stall(stall),
        .S_in(S_in1), 
        .T_in(T_in), 
        .store_S_in(store_S_in),  
        .init_in(init_in), 
        .first_query_block(first_query_block), 
        .next_first_ref_block_in(next_first_ref_block_in), 
        .first_ref_block_in(first_ref_block_in), 
        .last_ref_block_in(last_ref_block_in), 
        .last_block_char_in(last_block_char_in), 
        .bypass_fifo_in(bypass_fifo_in), 
        .V_out(V_out1),
        .V_out_valid(V_out_valid1)
    );

    // Single query block, multiple reference block, 2 PEs per FIFO, multiple FIFOs test
    reg [1:0] short_read2 [3:0];
    reg [1:0] reference2  [15:0];
    reg [9:0] V_out_expected2 [20:0][3:0];
    reg V_out_valid_expected2 [20:0][3:0];
    SmithWatermanArray #(4, 8, 10, 10, -2, -2, -1, 2) uut2 (
        .clk(clk), 
        .rst(rst),
        .stall(stall),
        .S_in(S_in2), 
        .T_in(T_in), 
        .store_S_in(store_S_in), 
        .init_in(init_in), 
        .first_query_block(first_query_block), 
        .next_first_ref_block_in(next_first_ref_block_in), 
        .first_ref_block_in(first_ref_block_in), 
        .last_ref_block_in(last_ref_block_in), 
        .last_block_char_in(last_block_char_in), 
        .bypass_fifo_in(bypass_fifo_in), 
        .V_out(V_out2),
        .V_out_valid(V_out_valid2)
    );

    integer i;
    integer j;
    initial begin
        $display("Multiple query block, multiple reference block, 3 PEs per FIFO test");
        short_read1[0] = 2'b00;   // ACTAGC
        short_read1[1] = 2'b01;
        short_read1[2] = 2'b11;
        short_read1[3] = 2'b00;
        short_read1[4] = 2'b10;
        short_read1[5] = 2'b01;
        reference1[0] = 2'b00;    // ATAGTCAT
        reference1[1] = 2'b11;
        reference1[2] = 2'b00;
        reference1[3] = 2'b10;
        reference1[4] = 2'b11;
        reference1[5] = 2'b01;
        reference1[6] = 2'b00;
        reference1[7] = 2'b11;
        V_out_expected1[0][0] = 10;
        V_out_expected1[0][1] = 0;
        V_out_expected1[0][2] = 0;
        V_out_expected1[1][0] = 8;
        V_out_expected1[1][1] = 8;
        V_out_expected1[1][2] = 0;
        V_out_expected1[2][0] = 10;
        V_out_expected1[2][1] = 8;
        V_out_expected1[2][2] = 7;
        V_out_expected1[3][0] = 8;
        V_out_expected1[3][1] = 8;
        V_out_expected1[3][2] = 18;
        V_out_expected1[4][0] = 0;
        V_out_expected1[4][1] = 8;
        V_out_expected1[4][2] = 16;
        V_out_expected1[5][0] = 10;
        V_out_expected1[5][1] = 0;
        V_out_expected1[5][2] = 15;
        V_out_expected1[6][0] = 16;
        V_out_expected1[6][1] = 8;
        V_out_expected1[6][2] = 0;
        V_out_expected1[7][0] = 28;
        V_out_expected1[7][1] = 15;
        V_out_expected1[7][2] = 7;
        V_out_expected1[8][0] = 26;
        V_out_expected1[8][1] = 26;
        V_out_expected1[8][2] = 14;
        V_out_expected1[9][0] = 8;
        V_out_expected1[9][1] = 38;
        V_out_expected1[9][2] = 25;
        V_out_expected1[10][0] = 7;
        V_out_expected1[10][1] = 8;
        V_out_expected1[10][2] = 36;
        V_out_expected1[11][0] = 6;
        V_out_expected1[11][1] = 6;
        V_out_expected1[11][2] = 15;
        V_out_expected1[12][0] = 10;
        V_out_expected1[12][1] = 17;
        V_out_expected1[12][2] = 18;
        V_out_expected1[13][0] = 8;
        V_out_expected1[13][1] = 15;
        V_out_expected1[13][2] = 16;
        V_out_expected1[14][0] = 26;
        V_out_expected1[14][1] = 14;
        V_out_expected1[14][2] = 15;
        V_out_expected1[15][0] = 25;
        V_out_expected1[15][1] = 38;
        V_out_expected1[15][2] = 25;
        V_out_expected1[16][0] = 24;
        V_out_expected1[16][1] = 36;
        V_out_expected1[16][2] = 36;
        V_out_expected1[17][0] = 26;
        V_out_expected1[17][1] = 35;
        V_out_expected1[17][2] = 36;
        V_out_expected1[18][0] = 24;
        V_out_expected1[18][1] = 34;
        V_out_expected1[18][2] = 46;
        V_out_expected1[19][0] = 0;
        V_out_expected1[19][1] = 33;
        V_out_expected1[19][2] = 44;
        V_out_expected1[20][0] = 0;
        V_out_expected1[20][1] = 0;
        V_out_expected1[20][2] = 43;
        V_out_valid_expected1[0][0] = 1;
        V_out_valid_expected1[0][1] = 0;
        V_out_valid_expected1[0][2] = 0;
        V_out_valid_expected1[1][0] = 1;
        V_out_valid_expected1[1][1] = 1;
        V_out_valid_expected1[1][2] = 0;
        V_out_valid_expected1[2][0] = 1;
        V_out_valid_expected1[2][1] = 1;
        V_out_valid_expected1[2][2] = 1;
        V_out_valid_expected1[3][0] = 1;
        V_out_valid_expected1[3][1] = 1;
        V_out_valid_expected1[3][2] = 1;
        V_out_valid_expected1[4][0] = 0;
        V_out_valid_expected1[4][1] = 1;
        V_out_valid_expected1[4][2] = 1;
        V_out_valid_expected1[5][0] = 1;
        V_out_valid_expected1[5][1] = 0;
        V_out_valid_expected1[5][2] = 1;
        V_out_valid_expected1[6][0] = 1;
        V_out_valid_expected1[6][1] = 1;
        V_out_valid_expected1[6][2] = 0;
        V_out_valid_expected1[7][0] = 1;
        V_out_valid_expected1[7][1] = 1;
        V_out_valid_expected1[7][2] = 1;
        V_out_valid_expected1[8][0] = 1;
        V_out_valid_expected1[8][1] = 1;
        V_out_valid_expected1[8][2] = 1;
        V_out_valid_expected1[9][0] = 0;
        V_out_valid_expected1[9][1] = 1;
        V_out_valid_expected1[9][2] = 1;
        V_out_valid_expected1[10][0] = 1;
        V_out_valid_expected1[10][1] = 0;
        V_out_valid_expected1[10][2] = 1;
        V_out_valid_expected1[11][0] = 1;
        V_out_valid_expected1[11][1] = 1;
        V_out_valid_expected1[11][2] = 0;
        V_out_valid_expected1[12][0] = 1;
        V_out_valid_expected1[12][1] = 1;
        V_out_valid_expected1[12][2] = 1;
        V_out_valid_expected1[13][0] = 1;
        V_out_valid_expected1[13][1] = 1;
        V_out_valid_expected1[13][2] = 1;
        V_out_valid_expected1[14][0] = 0;
        V_out_valid_expected1[14][1] = 1;
        V_out_valid_expected1[14][2] = 1;
        V_out_valid_expected1[15][0] = 1;
        V_out_valid_expected1[15][1] = 0;
        V_out_valid_expected1[15][2] = 1;
        V_out_valid_expected1[16][0] = 1;
        V_out_valid_expected1[16][1] = 1;
        V_out_valid_expected1[16][2] = 0;
        V_out_valid_expected1[17][0] = 1;
        V_out_valid_expected1[17][1] = 1;
        V_out_valid_expected1[17][2] = 1;
        V_out_valid_expected1[18][0] = 1;
        V_out_valid_expected1[18][1] = 1;
        V_out_valid_expected1[18][2] = 1;
        V_out_valid_expected1[19][0] = 0;
        V_out_valid_expected1[19][1] = 1;
        V_out_valid_expected1[19][2] = 1;
        V_out_valid_expected1[20][0] = 0;
        V_out_valid_expected1[20][1] = 0;
        V_out_valid_expected1[20][2] = 1;
        
        // Initialize Inputs
        clk <= 0;
        rst <= 1;
        stall <= 0;
        S_in1 <= 0;
        T_in <= 0;
        init_in <= 0;
        store_S_in <= 0;
        first_query_block <= 0;
        next_first_ref_block_in <= 0;
        first_ref_block_in <= 0;
        last_ref_block_in <= 0;
        last_block_char_in <= 0;
        bypass_fifo_in <= 0;
        #20;
        rst <= 0;
        
        // Generate the stimulus
        for (i = 0; i < 3; i = i + 1) begin
            S_in1[i*2+1 -: 2] <= short_read1[i];
        end
        init_in <= 0;
        store_S_in <= 1;
        first_query_block <= 1;
        next_first_ref_block_in <= 1;
        first_ref_block_in <= 1;
        last_ref_block_in <= 0;
        last_block_char_in <= 0;
        bypass_fifo_in <= 0;
        #10;
        for (i = 0; i < 2; i = i + 1) begin
            T_in <= reference1[i];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end
        
        for (i = 2; i < 3; i = i + 1) begin
            T_in <= reference1[i];
            for (j = 0; j < 3; j = j + 1) begin
                S_in1[j*2+1 -: 2] <= short_read1[j+3];
            end
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 3; i < 4; i = i + 1) begin
            T_in <= reference1[i];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 1;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 4; i < 5; i = i + 1) begin
            init_in <= 0;
            store_S_in <= 1;
            first_query_block <= 0;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 5; i < 7; i = i + 1) begin
            T_in <= reference1[i-5];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 0;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 7; i < 8; i = i + 1) begin
            T_in <= reference1[i-5];
            for (j = 0; j < 3; j = j + 1) begin
                S_in1[j*2+1 -: 2] <= short_read1[j];
            end
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 0;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 8; i < 9; i = i + 1) begin
            T_in <= reference1[i-5];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 0;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 1;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 9; i < 10; i = i + 1) begin
            init_in <= 0;
            store_S_in <= 1;
            first_query_block <= 1;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 10; i < 12; i = i + 1) begin
            T_in <= reference1[i-6];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 12; i < 13; i = i + 1) begin
            T_in <= reference1[i-6];
            for (j = 0; j < 3; j = j + 1) begin
                S_in1[j*2+1 -: 2] <= short_read1[j+3];
            end
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 13; i < 14; i = i + 1) begin
            T_in <= reference1[i-6];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 1;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 14; i < 15; i = i + 1) begin
            init_in <= 0;
            store_S_in <= 1;
            first_query_block <= 0;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 15; i < 18; i = i + 1) begin
            T_in <= reference1[i-11];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 0;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 18; i < 19; i = i + 1) begin
            T_in <= reference1[i-11];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 0;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 1;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 19; i < 20; i = i + 1) begin
            init_in <= 0;
            store_S_in <= 0;
            first_query_block <= 0;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 20; i < 21; i = i + 1) begin
            init_in <= 0;
            store_S_in <= 0;
            first_query_block <= 0;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d", V_out1[9:0], V_out1[19:10], V_out1[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out1[j*10+9 -: 10] != V_out_expected1[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out1[j*10+9 -: 10], V_out_expected1[i][j]);
                end
                if (V_out_valid1[j] != V_out_valid_expected1[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end
        
        
        $display("Single query block, multiple reference block, 2 PEs per FIFO, multiple FIFOs test");
        short_read2[0] = 2'b00;   // AGCA
        short_read2[1] = 2'b10;
        short_read2[2] = 2'b01;
        short_read2[3] = 2'b00;
        reference2[0] = 2'b01;    // CAGCAGTAAGCAGTAA
        reference2[1] = 2'b00;
        reference2[2] = 2'b10;
        reference2[3] = 2'b01;
        reference2[4] = 2'b00;
        reference2[5] = 2'b10;
        reference2[6] = 2'b11;
        reference2[7] = 2'b00;
        reference2[8] = 2'b00;
        reference2[9] = 2'b10;
        reference2[10] = 2'b01;
        reference2[11] = 2'b00;
        reference2[12] = 2'b10;
        reference2[13] = 2'b11;
        reference2[14] = 2'b00;
        reference2[15] = 2'b00;
        V_out_expected2[0][0] = 0;
        V_out_expected2[0][1] = 0;
        V_out_expected2[0][2] = 0;
        V_out_expected2[0][3] = 0;
        V_out_expected2[1][0] = 10;
        V_out_expected2[1][1] = 0;
        V_out_expected2[1][2] = 0;
        V_out_expected2[1][3] = 0;
        V_out_expected2[2][0] = 8;
        V_out_expected2[2][1] = 8;
        V_out_expected2[2][2] = 10;
        V_out_expected2[2][3] = 0;
        V_out_expected2[3][0] = 7;
        V_out_expected2[3][1] = 20;
        V_out_expected2[3][2] = 8;
        V_out_expected2[3][3] = 8;
        V_out_expected2[4][0] = 10;
        V_out_expected2[4][1] = 18;
        V_out_expected2[4][2] = 18;
        V_out_expected2[4][3] = 20;
        V_out_expected2[5][0] = 8;
        V_out_expected2[5][1] = 17;
        V_out_expected2[5][2] = 30;
        V_out_expected2[5][3] = 18;
        V_out_expected2[6][0] = 7;
        V_out_expected2[6][1] = 20;
        V_out_expected2[6][2] = 28;
        V_out_expected2[6][3] = 28;
        V_out_expected2[7][0] = 10;
        V_out_expected2[7][1] = 18;
        V_out_expected2[7][2] = 27;
        V_out_expected2[7][3] = 40;
        V_out_expected2[8][0] = 10;     // Keep last value 
        V_out_expected2[8][1] = 17;
        V_out_expected2[8][2] = 26;
        V_out_expected2[8][3] = 38;
        V_out_expected2[9][0] = 10;
        V_out_expected2[9][1] = 17;     // Keep last value
        V_out_expected2[9][2] = 25;
        V_out_expected2[9][3] = 37;
        V_out_expected2[10][0] = 8;
        V_out_expected2[10][1] = 16;
        V_out_expected2[10][2] = 25;    // Keep last value
        V_out_expected2[10][3] = 36;    
        V_out_expected2[11][0] = 7;
        V_out_expected2[11][1] = 20;
        V_out_expected2[11][2] = 24;
        V_out_expected2[11][3] = 36;    // Keep last value
        V_out_expected2[12][0] = 10;
        V_out_expected2[12][1] = 18;
        V_out_expected2[12][2] = 23;
        V_out_expected2[12][3] = 35;
        V_out_expected2[13][0] = 8;
        V_out_expected2[13][1] = 17;
        V_out_expected2[13][2] = 30;
        V_out_expected2[13][3] = 34;
        V_out_expected2[14][0] = 7;
        V_out_expected2[14][1] = 20;
        V_out_expected2[14][2] = 28;
        V_out_expected2[14][3] = 33;
        V_out_expected2[15][0] = 10;
        V_out_expected2[15][1] = 18;
        V_out_expected2[15][2] = 27;
        V_out_expected2[15][3] = 40;
        V_out_expected2[16][0] = 10;
        V_out_expected2[16][1] = 17;
        V_out_expected2[16][2] = 26;
        V_out_expected2[16][3] = 38;
        V_out_expected2[17][0] = 0;
        V_out_expected2[17][1] = 16;
        V_out_expected2[17][2] = 25;
        V_out_expected2[17][3] = 37;
        V_out_expected2[18][0] = 0;
        V_out_expected2[18][1] = 0;
        V_out_expected2[18][2] = 24;
        V_out_expected2[18][3] = 36;
        V_out_expected2[19][0] = 0;
        V_out_expected2[19][1] = 0;
        V_out_expected2[19][2] = 0;
        V_out_expected2[19][3] = 35;
        V_out_valid_expected2[0][0] = 1;
        V_out_valid_expected2[0][1] = 0;
        V_out_valid_expected2[0][2] = 0;
        V_out_valid_expected2[0][3] = 0;
        V_out_valid_expected2[1][0] = 1;
        V_out_valid_expected2[1][1] = 1;
        V_out_valid_expected2[1][2] = 0;
        V_out_valid_expected2[1][3] = 0;
        V_out_valid_expected2[2][0] = 1;
        V_out_valid_expected2[2][1] = 1;
        V_out_valid_expected2[2][2] = 1;
        V_out_valid_expected2[2][3] = 0;
        V_out_valid_expected2[3][0] = 1;
        V_out_valid_expected2[3][1] = 1;
        V_out_valid_expected2[3][2] = 1;
        V_out_valid_expected2[3][3] = 1;
        V_out_valid_expected2[4][0] = 1;
        V_out_valid_expected2[4][1] = 1;
        V_out_valid_expected2[4][2] = 1;
        V_out_valid_expected2[4][3] = 1;
        V_out_valid_expected2[5][0] = 1;
        V_out_valid_expected2[5][1] = 1;
        V_out_valid_expected2[5][2] = 1;
        V_out_valid_expected2[5][3] = 1;
        V_out_valid_expected2[6][0] = 1;
        V_out_valid_expected2[6][1] = 1;
        V_out_valid_expected2[6][2] = 1;
        V_out_valid_expected2[6][3] = 1;
        V_out_valid_expected2[7][0] = 1;
        V_out_valid_expected2[7][1] = 1;
        V_out_valid_expected2[7][2] = 1;
        V_out_valid_expected2[7][3] = 1;
        V_out_valid_expected2[8][0] = 0;     // Keep last value 
        V_out_valid_expected2[8][1] = 1;
        V_out_valid_expected2[8][2] = 1;
        V_out_valid_expected2[8][3] = 1;
        V_out_valid_expected2[9][0] = 1;
        V_out_valid_expected2[9][1] = 0;     // Keep last value
        V_out_valid_expected2[9][2] = 1;
        V_out_valid_expected2[9][3] = 1;
        V_out_valid_expected2[10][0] = 1;
        V_out_valid_expected2[10][1] = 1;
        V_out_valid_expected2[10][2] = 0;    // Keep last value
        V_out_valid_expected2[10][3] = 1;    
        V_out_valid_expected2[11][0] = 1;
        V_out_valid_expected2[11][1] = 1;
        V_out_valid_expected2[11][2] = 1;
        V_out_valid_expected2[11][3] = 0;    // Keep last value
        V_out_valid_expected2[12][0] = 1;
        V_out_valid_expected2[12][1] = 1;
        V_out_valid_expected2[12][2] = 1;
        V_out_valid_expected2[12][3] = 1;
        V_out_valid_expected2[13][0] = 1;
        V_out_valid_expected2[13][1] = 1;
        V_out_valid_expected2[13][2] = 1;
        V_out_valid_expected2[13][3] = 1;
        V_out_valid_expected2[14][0] = 1;
        V_out_valid_expected2[14][1] = 1;
        V_out_valid_expected2[14][2] = 1;
        V_out_valid_expected2[14][3] = 1;
        V_out_valid_expected2[15][0] = 1;
        V_out_valid_expected2[15][1] = 1;
        V_out_valid_expected2[15][2] = 1;
        V_out_valid_expected2[15][3] = 1;
        V_out_valid_expected2[16][0] = 1;
        V_out_valid_expected2[16][1] = 1;
        V_out_valid_expected2[16][2] = 1;
        V_out_valid_expected2[16][3] = 1;
        V_out_valid_expected2[17][0] = 0;
        V_out_valid_expected2[17][1] = 1;
        V_out_valid_expected2[17][2] = 1;
        V_out_valid_expected2[17][3] = 1;
        V_out_valid_expected2[18][0] = 0;
        V_out_valid_expected2[18][1] = 0;
        V_out_valid_expected2[18][2] = 1;
        V_out_valid_expected2[18][3] = 1;
        V_out_valid_expected2[19][0] = 0;
        V_out_valid_expected2[19][1] = 0;
        V_out_valid_expected2[19][2] = 0;
        V_out_valid_expected2[19][3] = 1;
        
        // Initialize inputs, variables, and wait for reset
        clk <= 0;
        rst <= 1;
        S_in2 <= 0;
        T_in <= 0;
        store_S_in <= 0;
        init_in <= 0;
        first_query_block <= 0;
        next_first_ref_block_in <= 0;
        first_ref_block_in <= 0;
        last_ref_block_in <= 0;
        last_block_char_in <= 0;
        bypass_fifo_in <= 0;
        #20;
        rst <= 0;
        
        for (i = 0; i < 4; i = i + 1) begin
            S_in2[i*2+1 -: 2] <= short_read2[i]; // Shift in reverse
        end
        init_in <= 0;
        store_S_in <= 1;
        first_query_block <=1;
        next_first_ref_block_in <= 1;
        first_ref_block_in <= 1;
        last_ref_block_in <= 0;
        last_block_char_in <= 0;
        bypass_fifo_in <= 1;
        #10;
        for (i = 0; i < 3; i = i + 1) begin
            T_in <= reference2[i];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 1;
            #10;
            $display("%d %d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20], V_out2[39:30]);
            for (j = 0; j < 4; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out2[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (V_out_valid2[j] != V_out_valid_expected2[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 3; i < 4; i = i + 1)begin
            T_in <= reference2[i];
            for (j = 0; j < 4; j = j + 1) begin
                S_in2[j*2+1 -: 2] <= short_read2[j];
            end
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 1;
            #10;
            $display("%d %d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20], V_out2[39:30]);
            for (j = 0; j < 4; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out2[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (V_out_valid2[j] != V_out_valid_expected2[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end

        for (i = 4; i < 7; i = i + 1) begin
            T_in <= reference2[i];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 1;
            #10;
            $display("%d %d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20], V_out2[39:30]);
            for (j = 0; j < 4; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out2[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (V_out_valid2[j] != V_out_valid_expected2[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
           end
        end
        
        for (i = 7; i < 8; i = i + 1) begin
            T_in <= reference2[i];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 1;
            bypass_fifo_in <= 1;
            #10;
            $display("%d %d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20], V_out2[39:30]);
            for (j = 0; j < 4; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out2[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (V_out_valid2[j] != V_out_valid_expected2[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end
        
        for (i = 8; i < 9; i = i + 1) begin
            init_in <= 0;
            store_S_in <= 1;
            first_query_block <= 1;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 0;
            bypass_fifo_in <= 1;
            #10;
            $display("%d %d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20], V_out2[39:30]);
            for (j = 0; j < 4; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out2[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (V_out_valid2[j] != V_out_valid_expected2[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end
        
        for (i = 9; i < 16; i = i + 1) begin
            T_in <= reference2[i-1];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 0;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 0;
            bypass_fifo_in <= 1;
            #10;
            $display("%d %d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20], V_out2[39:30]);
            for (j = 0; j < 4; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out2[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (V_out_valid2[j] != V_out_valid_expected2[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end
        
        for (i = 16; i < 17; i = i + 1) begin
            T_in <= reference2[i-1];
            init_in <= 1;
            store_S_in <= 0;
            first_query_block <= 1;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 0;
            last_ref_block_in <= 1;
            last_block_char_in <= 1;
            bypass_fifo_in <= 1;
            #10;
            $display("%d %d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20], V_out2[39:30]);
            for (j = 0; j < 4; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out2[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (V_out_valid2[j] != V_out_valid_expected2[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end
        
        for (i = 17; i < 20; i = i + 1) begin
            init_in <= 0;
            store_S_in <= 0;
            first_query_block <= 0;
            next_first_ref_block_in <= 1;
            first_ref_block_in <= 1;
            last_ref_block_in <= 0;
            last_block_char_in <= 0;
            bypass_fifo_in <= 0;
            #10;
            $display("%d %d %d %d", V_out2[9:0], V_out2[19:10], V_out2[29:20], V_out2[39:30]);
            for (j = 0; j < 4; j = j + 1) begin
                if (V_out2[j*10+9 -: 10] != V_out_expected2[i][j]) begin
                    $display("V_out error, Cycle %d PE %d: Got %d expected %d", i, j, V_out2[j*10+9 -: 10], V_out_expected2[i][j]);
                end
                if (V_out_valid2[j] != V_out_valid_expected2[i][j]) begin
                    $display("@%0dns V_out_valid error, Cycle %d PE %d", $time, i, j);
                end
            end
        end
        
        #100;
        $display("Tests complete!");
        $finish;
    end
    always begin
        #5 clk = !clk;
    end
endmodule

