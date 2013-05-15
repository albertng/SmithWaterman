/*  File Name        : SmithWatermanArray.v
 *  Description      : Fixed implementation of Smith Waterman systolic array with
 *                     affine gap penalty.
 *
 *                     There is a shift register holding the next query sequence
 *                     to be loaded into the systolic array. This shift register
 *                     is loaded with the next sequence during the computation of 
 *                     the previous iteration, on the shift_S signal.
 *
 *                     At the end of the previous iteration, store_S_in is passed
 *                     through the pipeline, storing the query sequence from the
 *                     loaded shift register into the systolic array. This allows
 *                     multiple iterations to be stitched together seemlessly
 *                     without any bubbles in the pipeline.
 *
 *  Revision History :
 *      Albert Ng   May 02 2013     Initial Revision
 *      Albert Ng   May 06 2013     Added query sequence shift register
 *      Albert Ng   May 13 2013     Added all cell scores to output port
 *                                  Changed module name to SmithWatermanArray
 *
 */

module SmithWatermanArray(
    input clk,                              // System clock
    input rst,                              // System reset
    input [1:0] S_in,                       // Query sequence shift in
    input [1:0] T_in,                       // Reference sequence shift in
    input store_S_in,                       // Load systolic array with new query seq
    input shift_S,                          // Load next query seq shift register
    input init_in,                          // Computation active shift in
    output [NUM_PES * WIDTH - 1:0] V_out    // Cell score outputs
    );

    parameter NUM_PES = 10;
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;

    wire [WIDTH - 1:0] V[NUM_PES:0];
    wire [WIDTH - 1:0] F[NUM_PES:0];
    wire [1:0] T[NUM_PES:0];
    wire store_S[NUM_PES:0];
    wire init[NUM_PES:0];
    
    reg [1:0] S[NUM_PES-1:0];    
    
    assign V[0] = 0;
    assign F[0] = 0;
    assign T[0] = T_in;
    assign store_S[0] = store_S_in;
    assign init[0] = init_in;
    
    // Query sequence buffer
    genvar i;
    generate
        for (i = 0; i < NUM_PES; i = i + 1) begin:shift_s_gen
            always @(posedge clk) begin
                if (rst) begin
                    S[i] <= 0;
                end else begin
                    if (shift_S) begin
                        if (i == 0) begin
                            S[i] <= S_in;
                        end else begin
                            S[i] <= S[i-1];
                        end
                    end
                end
            end
        end
    endgenerate
    
    // Connect cell scores to output port
    generate
        for (i = 0; i < NUM_PES; i = i + 1) begin:v_out_gen
            assign V_out[(i*WIDTH)+WIDTH-1 -: WIDTH] = V[i+1];
        end
    endgenerate
    
    // Instantiate and connect systolic array
    generate
        for (i = 0; i < NUM_PES; i = i + 1) begin:swpe_gen
            SmithWatermanPE #(WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN) swpe (
                .clk(clk), 
                .rst(rst), 
                .V_in(V[i]), 
                .F_in(F[i]), 
                .T_in(T[i]), 
                .S_in(S[i]), 
                .store_S_in(store_S[i]), 
                .init_in(init[i]), 
                .V_out(V[i+1]), 
                .F_out(F[i+1]), 
                .T_out(T[i+1]), 
                .S_out(),
                .store_S_out(store_S[i+1]),
                .init_out(init[i+1])
            );
        end
    endgenerate
endmodule
