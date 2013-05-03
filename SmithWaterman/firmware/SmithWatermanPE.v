/*  File Name        : SmithWatermanPE.v
 *  Description      : Fixed implementation of Smith Waterman systolic array PE with
 *                     affine gap penalty.
 *
 *  Revision History :
 *      Albert Ng   Apr 30 2013     Initial Revision
 *      Albert Ng   May 02 2013     Added store_S_in and store_S_out
 *                                  Added S_out
 *
 */
module SmithWatermanPE(
    input  clk,                 // System clock
    input  rst,                 // System reset
    input  [WIDTH-1:0] V_in,    // Score from previous PE
    input  [WIDTH-1:0] F_in,    // Left gap penalty of previous PE
    input  [1:0] T_in,          // Reference seq shift in
    input  [1:0] S_in,          // Query seq input
    input        store_S_in,    // Store query seq
    input        init_in,       // Computation active shift in
    output [WIDTH-1:0] V_out,   // Score of this PE
    output [WIDTH-1:0] F_out,   // Left gap penalty of this cell
    output [1:0] T_out,         // Reference seq shift out
    output [1:0] S_out,         // Query seq shift out
    output       store_S_out,   // Store query seq shift out
    output       init_out       // Computation active shift out
    );
    
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;

    reg [1:0] T;
    reg [1:0] S;
    reg signed [WIDTH-1:0] V_diag;
    reg signed [WIDTH-1:0] V;
    reg signed [WIDTH-1:0] E;
    reg signed [WIDTH-1:0] F;
    reg store_S;
    reg init;
    
    wire [WIDTH-1:0] V_gap_open;
    wire [WIDTH-1:0] E_gap_extend;
    wire [WIDTH-1:0] leftV_gap_open;
    wire [WIDTH-1:0] leftF_gap_extend;
    wire [WIDTH-1:0] match_score;
    wire [WIDTH-1:0] new_E;
    wire [WIDTH-1:0] new_F;
    
    assign V_out = V;
    assign F_out = F;
    assign S_out = S;
    assign T_out = T;
    assign init_out = init;
    assign store_S_out = store_S;
    
    assign V_gap_open = V + GAP_OPEN_PEN;
    assign E_gap_extend = E + GAP_EXTEND_PEN;
    assign leftV_gap_open = V_in + GAP_OPEN_PEN;
    assign leftF_gap_extend = F_in + GAP_EXTEND_PEN;
    assign match_score = (S == T_in) ? V_diag + MATCH_REWARD : V_diag + MISMATCH_PEN;
    assign new_E = ($signed(V_gap_open) > $signed(E_gap_extend)) ? V_gap_open : E_gap_extend;
    assign new_F = ($signed(leftV_gap_open) > $signed(leftF_gap_extend)) ? leftV_gap_open : leftF_gap_extend;
    
    always @(posedge clk) begin
        if (rst) begin
            T <= 0;
            S <= 0;
            V_diag <= 0;
            V <= 0;
            E <= 0;
            F <= 0;
            store_S <= 0;
            init <= 0;
        end else begin
            store_S <= store_S_in;
            init <= init_in;
            T <= T_in;
            if (store_S_in)
                S <= S_in;
            V_diag <= V_in;
            if (init_in) begin
                E <= new_E;
                F <= new_F;
                if (0 > $signed(new_E) && 0 > $signed(new_F) && 0 > $signed(match_score))
                    V <= 0;
                else if ($signed(new_E) > $signed(new_F) && $signed(new_E) > $signed(match_score))
                    V <= new_E;
                else if ($signed(new_F) > $signed(match_score))
                    V <= new_F;
                else
                    V <= match_score;
            end else begin
                E <= 0;
                F <= 0;
                V <= 0;
            end
        end
    end
endmodule
