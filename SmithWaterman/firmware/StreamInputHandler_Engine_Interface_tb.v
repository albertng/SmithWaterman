/*  File Name        : StreamInputHandler_Engine_Interface_tb.v
 *  Description      : Testbench for stream input handler interfaced with Smith Waterman engine
 *
 *  Revision History :
 *      Albert Ng   Jul 10 2013     Initial Revision
 *      Albert Ng   Jul 15 2013     Added query ID #
 *                                  Added cell score threshold
 *
 */

module StreamInputHandler_Engine_Interface_tb;

    // Inputs
    reg clk;
    reg rst;
    reg stall;
    reg si_clk;
    reg si_valid;
    reg [127:0] si_data;
    reg [7:0] ref_seq_block_in;
    reg ref_seq_block_valid_in;

    // Outputs
    wire si_rdy;
    wire [24:0] ref_addr_out;
    wire [24:0] ref_length_out;
    wire ref_info_valid_out;
    wire ref_seq_block_rdy_out;
    wire [29:0] V_out;

    reg [31:0] ref_length1;
    reg [31:0] ref_addr1;
    reg [15:0] num_query_blocks1;
    reg [15:0] query_id1;
    reg [31:0] cell_score_threshold1;
    reg [127:0] query1[1:0];
    reg [7:0] ref1[1:0];

    reg [31:0] ref_length2;
    reg [31:0] ref_addr2;
    reg [15:0] num_query_blocks2;
    reg [15:0] query_id2;
    reg [31:0] cell_score_threshold2;
    reg [127:0] query2[0:0];
    reg [7:0] ref2[1:0];

    reg [9:0] V_out_expected[32:0][2:0];

    // Instantiate the Unit Under Test (UUT)
    StreamInputHandler_Engine_Interface #(3, 4, 10, 10, -2, -2, -1, 3) uut (
        .clk(clk), 
        .rst(rst), 
        .stall(stall), 
        .si_clk(si_clk), 
        .si_valid(si_valid), 
        .si_data(si_data), 
        .si_rdy(si_rdy), 
        .ref_addr_out(ref_addr_out), 
        .ref_length_out(ref_length_out), 
        .ref_info_valid_out(ref_info_valid_out), 
        .ref_seq_block_in(ref_seq_block_in), 
        .ref_seq_block_valid_in(ref_seq_block_valid_in), 
        .ref_seq_block_rdy_out(ref_seq_block_rdy_out), 
        .V_out(V_out)
    );

    integer i, j;
    initial begin
        query1[0] = 128'b110100;    // ACTAGC
        query1[1] = 128'b011000;
        ref1[0] = 8'b10001100;      // ATAGTCAT
        ref1[1] = 8'b11000111;
        ref_length1 = 2;
        ref_addr1 = 5;
        num_query_blocks1 = 2;
        query_id1 = 1;
        cell_score_threshold1 = 10;
        
        query2[0] = 128'b011000;    // AGC
        ref2[0] = 8'b10001100;      // ATAGTCAC
        ref2[1] = 8'b01000111;
        ref_length2 = 2;
        ref_addr2 = 10;
        num_query_blocks2 = 1;
        query_id2 = 2;
        cell_score_threshold2 = 20;
        
        V_out_expected[0][0] = 10;
        V_out_expected[0][1] = 0;
        V_out_expected[0][2] = 0;
        V_out_expected[1][0] = 8;
        V_out_expected[1][1] = 8;
        V_out_expected[1][2] = 0;
        V_out_expected[2][0] = 10;
        V_out_expected[2][1] = 8;
        V_out_expected[2][2] = 7;
        V_out_expected[3][0] = 8;
        V_out_expected[3][1] = 8;
        V_out_expected[3][2] = 18;
        V_out_expected[4][0] = 0;
        V_out_expected[4][1] = 8;
        V_out_expected[4][2] = 16;
        V_out_expected[5][0] = 10;
        V_out_expected[5][1] = 0;
        V_out_expected[5][2] = 15;
        V_out_expected[6][0] = 16;
        V_out_expected[6][1] = 8;
        V_out_expected[6][2] = 0;
        V_out_expected[7][0] = 28;
        V_out_expected[7][1] = 15;
        V_out_expected[7][2] = 7;
        V_out_expected[8][0] = 26;
        V_out_expected[8][1] = 26;
        V_out_expected[8][2] = 14;
        V_out_expected[9][0] = 8;
        V_out_expected[9][1] = 38;
        V_out_expected[9][2] = 25;
        V_out_expected[10][0] = 7;
        V_out_expected[10][1] = 8;
        V_out_expected[10][2] = 36;
        V_out_expected[11][0] = 6;
        V_out_expected[11][1] = 6;
        V_out_expected[11][2] = 15;
        V_out_expected[12][0] = 10;
        V_out_expected[12][1] = 17;
        V_out_expected[12][2] = 18;
        V_out_expected[13][0] = 8;
        V_out_expected[13][1] = 15;
        V_out_expected[13][2] = 16;
        V_out_expected[14][0] = 26;
        V_out_expected[14][1] = 14;
        V_out_expected[14][2] = 15;
        V_out_expected[15][0] = 25;
        V_out_expected[15][1] = 38;
        V_out_expected[15][2] = 25;
        V_out_expected[16][0] = 24;
        V_out_expected[16][1] = 36;
        V_out_expected[16][2] = 36;
        V_out_expected[17][0] = 26;
        V_out_expected[17][1] = 35;
        V_out_expected[17][2] = 36;
        V_out_expected[18][0] = 24;
        V_out_expected[18][1] = 34;
        V_out_expected[18][2] = 46;
        V_out_expected[19][0] = 0;
        V_out_expected[19][1] = 33;
        V_out_expected[19][2] = 44;
        V_out_expected[20][0] = 0;
        V_out_expected[20][1] = 0;
        V_out_expected[20][2] = 43;
        V_out_expected[21][0] = 0;
        V_out_expected[21][1] = 0;
        V_out_expected[21][2] = 0;
        V_out_expected[22][0] = 10;
        V_out_expected[22][1] = 0;
        V_out_expected[22][2] = 0;
        V_out_expected[23][0] = 8;
        V_out_expected[23][1] = 8;
        V_out_expected[23][2] = 0;
        V_out_expected[24][0] = 10;
        V_out_expected[24][1] = 8;
        V_out_expected[24][2] = 7;
        V_out_expected[25][0] = 8;
        V_out_expected[25][1] = 8;
        V_out_expected[25][2] = 6;
        V_out_expected[26][0] = 8;
        V_out_expected[26][1] = 20;
        V_out_expected[26][2] = 7;
        V_out_expected[27][0] = 7;
        V_out_expected[27][1] = 20;
        V_out_expected[27][2] = 18;      
        V_out_expected[28][0] = 6;
        V_out_expected[28][1] = 18;
        V_out_expected[28][2] = 18;
        V_out_expected[29][0] = 10;
        V_out_expected[29][1] = 17;
        V_out_expected[29][2] = 18;
        V_out_expected[30][0] = 8;
        V_out_expected[30][1] = 16;
        V_out_expected[30][2] = 28;
        V_out_expected[31][0] = 0;
        V_out_expected[31][1] = 15;
        V_out_expected[31][2] = 26;
        V_out_expected[32][0] = 0;
        V_out_expected[32][1] = 0;
        V_out_expected[32][2] = 26;
    
        // Initialize Inputs
        clk = 0;
        rst = 1;
        stall = 0;
        si_clk = 0;
        si_valid = 0;
        si_data = 0;
        ref_seq_block_in = 0;
        ref_seq_block_valid_in = 0;
        #20;
        rst <= 0;

        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
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
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #9;
    
        si_data <= query1[0];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #9;
    
        si_data <= query1[1];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #9;
    
        si_data[31:0] <= ref_length2;
        si_data[63:32] <= ref_addr2;
        si_data[79:64] <= num_query_blocks2;
        si_data[95:80] <= query_id2;
        si_data[127:96] <= cell_score_threshold2;
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #9;
        
        si_data <= query2[0];
        #1;
        if (si_rdy != 1)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #9;
    
        // Wait_query_info_valid        /   Wait_wr_rdy
        for (i = 0; i < 4; i = i + 1) begin
            si_valid <= 0;
            #1;
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns ref_seq_block_rdy_out error", $time);
            #9;
        end
        
        // Send_ref_addr                /   Wait_wr_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 1)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_addr_out != ref_addr1)
            $display("@%0dns ref_addr_out error", $time);
        if (ref_length_out != ref_length1)
            $display("@%0dns ref_length_out error"< $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;
    
        // Wait_query_seq_block_valid   /   Wait_wr_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;
        
        // Latch_query_seq_block        /   Wait_wr_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;
        
        // Wait_query_seq_block_valid   /   Wait_wr_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;
        
        // Latch_query_seq_block        /   Wait_wr_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;
        
        // Wait_rd_rdy                  /   Wait_wr_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;
        
        // Wait_query_info_valid        /   Wait_ref_seq_block_valid
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;

        // Send_ref_addr                /   Wait_ref_seq_block_valid
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 1)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_addr_out != ref_addr2)
            $display("@%0dns ref_addr_out error", $time);
        if (ref_length_out != ref_length2)
            $display("@%0dns ref_length_out error"< $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;

        // Wait_query_seq_block_valid   /   Wait_ref_seq_block_valid
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;
        
        // Latch_query_seq_block        /   Wait_ref_seq_block_valid
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        ref_seq_block_valid_in <= 1;
        ref_seq_block_in <= ref1[0];
        #10;
        
        // Wait_rd_rdy                  /   Latch_ref
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        #10;
        
        // Wait_rd_rdy                  /   Advance_BCC
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        ref_seq_block_in <= ref1[1];
        #10;
        
        // Wait_rd_rdy                  /   Advance_BCC
        for (i = 0; i < 8; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);        
            if (ref_info_valid_out != 0)
                $display("@%0dns ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end

        // Wait_rd_rdy                  /   Latch_ref
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[8][j]) begin
                $display("@%0dns Latch_ref: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[8][j]);
            end
        end
        #10;

        // Wait_rd_rdy                  /   Advance_BCC
        ref_seq_block_in <= ref2[0];
        for (i = 9; i < 18; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
        // Wait_rd_rdy                  /   Wait_wr_rdy
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[18][j]) begin
                $display("@%0dns Latch_ref: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[18][j]);
            end
        end
        #10;
        
        // Wait_query_info_valid        /   Wait_ref_seq_block_valid
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 0)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[19][j]) begin
                $display("@%0dns Latch_ref: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[19][j]);
            end
        end
        #10;
        
        // Wait_query_info_valid        /   Latch_ref
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[20][j]) begin
                $display("@%0dns Latch_ref: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[20][j]);
            end
        end
        #10;
        
        // Wait_query_info_valid        /   Advance_BCC
        ref_seq_block_in <= ref2[1];
        for (i = 21; i < 25; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
        // Wait_query_info_valid        /   Latch_ref
        if (si_rdy != 0)
            $display("@%0dns si_rdy error", $time);
        if (ref_info_valid_out != 0)
            $display("@%0dns ref_info_valid_out error", $time);
        if (ref_seq_block_rdy_out != 1)
            $display("@%0dns ref_seq_block_rdy_out error", $time);
        $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
        for (j = 0; j < 3; j = j + 1) begin
            if (V_out[j*10+9 -: 10] != V_out_expected[25][j]) begin
                $display("@%0dns Latch_ref: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[25][j]);
            end
        end
        #10;
        
        // Wait_query_info_valid        /   Advance_BCC
        ref_seq_block_valid_in <= 0;
        for (i = 26; i < 30; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
        // Wait_query_info_valid        /   Wait_wr_rdy
        for (i = 30; i < 33; i = i + 1) begin
            if (si_rdy != 0)
                $display("@%0dns si_rdy error", $time);
            if (ref_info_valid_out != 0)
                $display("@%0dns ref_info_valid_out error", $time);
            if (ref_seq_block_rdy_out != 0)
                $display("@%0dns ref_seq_block_rdy_out error", $time);
            $display("%d %d %d", V_out[9:0], V_out[19:10], V_out[29:20]);
            for (j = 0; j < 3; j = j + 1) begin
                if (V_out[j*10+9 -: 10] != V_out_expected[i][j]) begin
                    $display("@%0dns Advance_BCC: V_out error, PE %d: Got %d expected %d", $time, j, V_out[j*10+9 -: 10], V_out_expected[i][j]);
                end
            end
            #10;
        end
        
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

