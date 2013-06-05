/*  File Name        : SmithWatermanPE.v
 *  Description      : Fixed implementation of Smith Waterman systolic array PE with
 *                     affine gap penalty.
 *
 *                     TODO: Probably going to need a stall signal
 *
 *  Revision History :
 *      Albert Ng   Apr 30 2013     Initial Revision
 *      Albert Ng   May 02 2013     Added store_S_in and store_S_out
 *                                  Added S_out
 *      Albert Ng   Jun 05 2013     Commented out unnecessary F initialization
 *                                  Added init_V, init_E, init_V_diag
 *                                  Reorganized PE logic to be in separate always block
 *
 */
module SmithWatermanPE(
    input  clk,                     // System clock
    input  rst,                     // System reset
    input  [WIDTH-1:0] V_in,        // Score from previous PE
    input  [WIDTH-1:0] F_in,        // Gap penalty of previous PE
    input  [1:0] T_in,              // Reference seq shift in
    input  [1:0] S_in,              // Query seq input
    input  store_S_in,              // Store query seq
    input  init_in,                 // Computation active shift in
    input  [WIDTH-1:0] init_V,      // V initialization value
    input  [WIDTH-1:0] init_E,      // E initialization value
    input  [WIDTH-1:0] init_V_diag, // Diagonal V initialization value
    output [WIDTH-1:0] V_out,       // Score of this PE
    output [WIDTH-1:0] E_out,       // Left gap penalty of this cell
    output [WIDTH-1:0] F_out,       // Up Gap penalty of this cell
    output [1:0] T_out,             // Reference seq shift out
    output [1:0] S_out,             // Query seq shift out
    output store_S_out,             // Store query seq shift out
    output init_out                 // Computation active shift out
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
    
    reg [WIDTH-1:0] V_gap_open;
    reg [WIDTH-1:0] E_gap_extend;
    reg [WIDTH-1:0] upV_gap_open;
    reg [WIDTH-1:0] upF_gap_extend;
    reg [WIDTH-1:0] match_score;
    reg [WIDTH-1:0] new_E;
    reg [WIDTH-1:0] new_F;
    reg [WIDTH-1:0] new_V;
    
    assign V_out = V;
    assign E_out = E;
    assign F_out = F;
    assign S_out = S;
    assign T_out = T;
    assign init_out = init;
    assign store_S_out = store_S;
    
    always @(*) begin
        V_gap_open <= V + GAP_OPEN_PEN;
        E_gap_extend <= E + GAP_EXTEND_PEN;
        upV_gap_open <= V_in + GAP_OPEN_PEN;
        upF_gap_extend <= F_in + GAP_EXTEND_PEN;
        
        if (S == T_in)
            match_score <= V_diag + MATCH_REWARD;
        else
            match_score <= V_diag + MISMATCH_PEN;
            
            
        if ($signed(V_gap_open) > $signed(E_gap_extend))
            new_E = V_gap_open;
        else
            new_E = E_gap_extend;
        
        if ($signed(upV_gap_open) > $signed(upF_gap_extend))
            new_F = upV_gap_open;
        else
            new_F = upF_gap_extend;
            
        if (0 > $signed(new_E) && 0 > $signed(new_F) && 0 > $signed(match_score))
            new_V <= 0;
        else if ($signed(new_E) > $signed(new_F) && $signed(new_E) > $signed(match_score))
            new_V <= new_E;
        else if ($signed(new_F) > $signed(match_score))
            new_V <= new_F;
        else
            new_V <= match_score;
    end
    
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
            if (init_in) begin
                V_diag <= V_in;
                E <= new_E;
                F <= new_F;
                V <= new_V;
            end else begin
                V_diag <= init_V_diag;
                E <= init_E;
                V <= init_V;
                //F <= 0;   Not necessary
            end
        end
    end
endmodule
