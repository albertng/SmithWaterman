/*  File Name        : SmithWatermanPE.v
 *  Description      : Fixed implementation of Smith Waterman systolic array PE with
 *                     affine gap penalty.
 *
 *  Revision History :
 *      Albert Ng   Apr 30 2013     Initial Revision
 *
 */
module SmithWatermanPE(
    input  clk,            // System clock
    input  rst,            // System reset
    input  [9:0] V_in,     // Score from previous PE
    input  [9:0] F_in,     // Left gap penalty of previous PE
    input  [1:0] T_in,     // Reference seq shift in
    input  [1:0] S_in,     // Query seq input
    input        store_S,  // Store query seq
    input        init_in,  // Computation active shift in
    output [9:0] V_out,    // Score of this PE
    output [9:0] F_out,    // Left gap penalty of this cell
    output [1:0] T_out,    // Reference seq shift out
    output       init_out  // Computation active shift out
    );
    
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;

    reg [1:0] T;
    reg [1:0] S;
    reg signed [9:0] V_diag;
    reg signed [9:0] V;
    reg signed [9:0] E;
    reg signed [9:0] F;
    reg init;
    
    wire [9:0] V_gap_open;
    wire [9:0] E_gap_extend;
    wire [9:0] leftV_gap_open;
    wire [9:0] leftF_gap_extend;
    wire [9:0] match_score;
    wire [9:0] new_E;
    wire [9:0] new_F;
    
    assign V_out = V;
    assign F_out = F;
    assign T_out = T;
    assign init_out = init;
    
    assign V_gap_open = V + GAP_OPEN_PEN;
    assign E_gap_extend = E + GAP_EXTEND_PEN;
    assign leftV_gap_open = V_in + GAP_OPEN_PEN;
    assign leftF_gap_extend = F_in + GAP_EXTEND_PEN;
    assign match_score = (S == T) ? V_diag + MATCH_REWARD : V_diag + MISMATCH_PEN;
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
            init <= 0;
        end else begin
            init <= init_in;
            T <= T_in;
            if (store_S)
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
