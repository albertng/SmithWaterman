/*  File Name        : SmithWatermanPE_tb.v
 *  Description      : Testbench for fixed implementation of Smith Waterman systolic array PE with
 *                     affine gap penalty.
 *
 *  Revision History :
 *      Albert Ng   May 01 2013     Initial Revision
 *      Albert Ng   May 02 2013     Added store_S_in and store_S_out signals
 *                                  Added S_out signal
 *      Albert Ng   Jun 05 2013     Added init_E, init_V, init_V_diag
 *      Albert Ng   Jun 09 2013     Removed init_V_diag
 *      Albert Ng   Jun 24 2013     Added stall
 *      Albert Ng   Jul 15 2013     Added cell score threshold comparison
 *
 */

module SmithWatermanPE_tb;
    // Inputs
    reg clk;
    reg rst;
    reg stall;
    reg [9:0] V_in;
    reg [9:0] F_in;
    reg [1:0] T_in;
    reg [1:0] S_in;
    reg store_S_in;
    reg init_in;
    reg [9:0] init_E;
    reg [9:0] init_V;
    reg [9:0] cell_score_threshold_in;

    // Outputs
    wire [9:0] V_out;
    wire [9:0] E_out;
    wire [9:0] F_out;
    wire [1:0] S_out;
    wire [1:0] T_out;
    wire store_S_out;
    wire init_out;
    wire [9:0] cell_score_threshold_out;
    wire high_score_out;

    reg [1:0] short_read [5:0];
    reg [1:0] reference  [7:0];
    reg [9:0] V_out_expected [7:0];

    // Instantiate the Unit Under Test (UUT)
    SmithWatermanPE #(10, 10, -2, -2, -1) uut (
        .clk(clk), 
        .rst(rst), 
        .stall(stall),
        .V_in(V_in), 
        .F_in(F_in), 
        .T_in(T_in), 
        .S_in(S_in), 
        .store_S_in(store_S_in), 
        .init_in(init_in),
        .init_V(init_V),
        .init_E(init_E),
        .cell_score_threshold_in(cell_score_threshold_in),
        .V_out(V_out),
        .E_out(E_out),
        .F_out(F_out),
        .S_out(S_out),
        .T_out(T_out), 
        .store_S_out(store_S_out),
        .init_out(init_out),
        .cell_score_threshold_out(cell_score_threshold_out),
        .high_score_out(high_score_out)
    );

    integer i;
    initial begin
        // Initialize short read and reference sequences
        short_read[0] = 2'b00;
        short_read[1] = 2'b01;
        short_read[2] = 2'b00;
        short_read[3] = 2'b01;
        short_read[4] = 2'b11;
        short_read[5] = 2'b00;
        
        reference[0] = 2'b00;
        reference[1] = 2'b01;
        reference[2] = 2'b00;
        reference[3] = 2'b10;
        reference[4] = 2'b00;
        reference[5] = 2'b01;
        reference[6] = 2'b11;
        reference[7] = 2'b00;
        
        // Initialize inputs, variables, and wait for reset
        clk = 0;
        rst = 1;
        stall = 0;
        V_in = 0;
        F_in = 0;
        T_in = 0;
        S_in = 0;
        store_S_in = 0;
        init_in = 0;
        init_E = 0;
        init_V = 0;
        cell_score_threshold_in = 0;
        i = 0;
        #20
        rst = 0;
        
        // Generate stimulus
        
        // Test 1
        V_out_expected[0] = 10'd10;
        V_out_expected[1] = 10'd8;
        V_out_expected[2] = 10'd10;
        V_out_expected[3] = 10'd8;
        V_out_expected[4] = 10'd10;
        V_out_expected[5] = 10'd8;
        V_out_expected[6] = 10'd7;
        V_out_expected[7] = 10'd10;        
        $display("V=0, F=0, S='A' test");
        S_in = short_read[0];   // Store short read sequence
        store_S_in = 1;
        #10;
        if (init_out) begin
            $display("Init_out error: Got 1 expected 0");
            $finish;
        end
        if (!store_S_out) begin
            $display("store_S_out error: Got 0 expected 1");
            $finish;
        end
        if (S_out != short_read[0]) begin
            $display("S_out error: Got %d expected %d", S_out, short_read[0]);
            $finish;
        end
        if (cell_score_threshold_out != 0) begin
            $display("cell_score_threshold_out error");
            $finish;
        end
        if (high_score_out != 0) begin
            $display("high_score_out error");
            $finish;
        end
        store_S_in = 0;
        for(i = 0; i < 8; i = i + 1) begin
            T_in = reference[i];
            init_in = 1;
            cell_score_threshold_in = 9;
            #10;
            $display("%d %d %d %d", V_out, F_out, T_out, init_out);
            if (V_out != V_out_expected[i]) begin
                $display("V_out error: Got %d expected %d", V_out, V_out_expected[i]);
                $finish;
            end
            if (F_out != -10'b1) begin
                $display("F_out error: Got %d expected -1", F_out);
                $finish;
            end
            if (T_out != reference[i]) begin
                $display("T_out error: Got %d expected %d", T_out, reference[i]);
                $finish;
            end
            if (!init_out) begin
                $display("Init_out error: Got 0 expected 1");
                $finish;
            end
            if (store_S_out) begin
                $display("store_S_out error: Got 1 expected 0");
                $finish;
            end
            if (cell_score_threshold_out != 9) begin
                $display("cell_score_threshold_out error");
                $finish;
            end
            if (high_score_out != ($signed(V_out) >= $signed(cell_score_threshold_out))) begin
                $display("high_score_out error");
                $finish;
            end
        end
        
        // Test 2
        V_out_expected[0] = 10'd0;
        V_out_expected[1] = 10'd10;
        V_out_expected[2] = 10'd8;
        V_out_expected[3] = 10'd7;
        V_out_expected[4] = 10'd6;
        V_out_expected[5] = 10'd10;
        V_out_expected[6] = 10'd8;
        V_out_expected[7] = 10'd7;   
        $display("V=0, F=0, S='C' test");
        S_in = short_read[1];
        store_S_in = 1;
        init_in = 0;
        #10
        if (init_out) begin
            $display("Init_out error: Got 1 expected 0");
            $finish;
        end
        if (!store_S_out) begin
            $display("store_S_out error: Got 0 expected 1");
            $finish;
        end
        if (S_out != short_read[1]) begin
            $display("S_out error: Got %d expected %d", S_out, short_read[1]);
            $finish;
        end
        if (high_score_out != 0) begin
            $display("high_score_out error");
            $finish;
        end
        store_S_in = 0;
        for(i = 0; i < 8; i = i + 1) begin
            T_in = reference[i];
            init_in = 1;
            cell_score_threshold_in = 8;
            #10;
            $display("%d %d %d %d", V_out, F_out, T_out, init_out);
            if (V_out != V_out_expected[i]) begin
                $display("V_out error: Got %d expected %d", V_out, V_out_expected[i]);
                $finish;
            end
            if (F_out != -10'b1) begin
                $display("F_out error: Got %d expected -1", F_out);
                $finish;
            end
            if (T_out != reference[i]) begin
                $display("T_out error: Got %d expected %d", T_out, reference[i]);
                $finish;
            end
            if (!init_out) begin
                $display("Init_out error: Got 0 expected 1");
                $finish;
            end
            if (store_S_out) begin
                $display("store_S_out error: Got 1 expected 0");
                $finish;
            end
            if (cell_score_threshold_out != 8) begin
                $display("cell_score_threshold_out error");
                $finish;
            end
            if (high_score_out != ($signed(V_out) >= $signed(cell_score_threshold_out))) begin
                $display("high_score_out error");
                $finish;
            end
        end
        
        // Test 3
        V_out_expected[0] = 10'd8;
        V_out_expected[1] = 10'd8;
        V_out_expected[2] = 10'd8;
        V_out_expected[3] = 10'd8;
        V_out_expected[4] = 10'd8;
        V_out_expected[5] = 10'd8;
        V_out_expected[6] = 10'd20;
        V_out_expected[7] = 10'd18;  
        $display("V=10, F=-4, S='T' test");
        V_in = 10;
        F_in = -4;
        S_in = short_read[4];
        store_S_in = 1;
        init_in = 0;
        #10
        if (init_out) begin
            $display("Init_out error: Got 1 expected 0");
            $finish;
        end
        if (!store_S_out) begin
            $display("store_S_out error: Got 0 expected 1");
            $finish;
        end
        if (S_out != short_read[4]) begin
            $display("S_out error: Got %d expected %d", S_out, short_read[4]);
            $finish;
        end
        if (high_score_out != 0) begin
            $display("high_score_out error");
            $finish;
        end
        store_S_in = 0;
        for(i = 0; i < 8; i = i + 1) begin
            T_in = reference[i];
            init_in = 1;
            cell_score_threshold_in = 15;
            #10;
            $display("%d %d %d %d", V_out, F_out, T_out, init_out);
            if (V_out != V_out_expected[i]) begin
                $display("V_out error: Got %d expected %d", V_out, V_out_expected[i]);
                $finish;
            end
            if (F_out != 10'd8) begin
                $display("F_out error: Got %d expected -1", F_out);
                $finish;
            end
            if (T_out != reference[i]) begin
                $display("T_out error: Got %d expected %d", T_out, reference[i]);
                $finish;
            end
            if (!init_out) begin
                $display("Init_out error: Got 0 expected 1");
                $finish;
            end
            if (store_S_out) begin
                $display("store_S_out error: Got 1 expected 0");
                $finish;
            end
            if (cell_score_threshold_out != 15) begin
                $display("cell_score_threshold_out error");
                $finish;
            end
            if (high_score_out != ($signed(V_out) >= $signed(cell_score_threshold_out))) begin
                $display("high_score_out error");
                $finish;
            end
        end
        
        #100;
        $finish;
    end
    
    always begin
        #5 clk = !clk;
    end
      
endmodule

