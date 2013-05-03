/*  File Name        : SmithWatermanArray_SequentialLoad.v
 *  Description      : Fixed implementation of Smith Waterman systolic array with
 *                     affine gap penalty.
 *                     Query sequence S loading is routed sequentially as a shift
 *                     register. This causes N-1 bubbles in the pipeline between
 *                     iterations, where N is the number of PEs.
 *
 *  Revision History :
 *      Albert Ng   May 02 2013     Initial Revision
 *
 */

module SmithWatermanArray_SequentialLoad(
    input clk,
    input rst,
    input [1:0] S_in,
    input [1:0] T_in,
    input store_S_in,
    input init_in,
    output [WIDTH - 1:0] V_out
    );

    parameter NUM_PES = 10;
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;

    wire [WIDTH - 1:0] V[NUM_PES:0];
    wire [WIDTH - 1:0] F[NUM_PES:0];
    wire [1:0] S[NUM_PES:0];
    wire [1:0] T[NUM_PES:0];
    wire store_S[NUM_PES:0];
    wire init[NUM_PES:0];
    
    assign V[0] = 0;
    assign F[0] = 0;
    assign S[0] = S_in;
    assign T[0] = T_in;
    assign store_S[0] = store_S_in;
    assign init[0] = init_in;
    assign V_out = V[NUM_PES];
    
    genvar i;
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
                .S_out(S[i+1]),
                .store_S_out(store_S[i+1]),
                .init_out(init[i+1])
            );
        end
    endgenerate
endmodule
