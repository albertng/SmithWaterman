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
 *                     multiple iterations to be stitched together seamlessly
 *                     without any additional bubbles in the pipeline, if the
 *                     reference block is long enough.
 *
 *                     A single bubble is inserted to clear the PE register values
 *                     between alignments. No additional bubbles are inserted into 
 *                     the pipeline only if:
 *                         len(ref) >= 2*NUM_PES-2
 *                     This is because the next alignment cannot begin until the
 *                     next query has been loaded into the shift register. The next
 *                     query cannot begin to be loaded into the shift register until
 *                     the first query has been completely stored into the systolic
 *                     array.
 *
 *                     For multiple query block alignments, the intermediate values of
 *                     V and F must be stored in a shift register to pass between
 *                     iterations. The inputs to the shift register are the results
 *                     of the last PE, and the outputs of the shift register are the
 *                     inputs of the first PE. Assuming there are no additional bubbles
 *                     in the pipeline due to a short reference block length, the length
 *                     of the shift registers is:
 *                         len(ref) - len(NUM_PES) + 1
 *
 *                     TODO: The current design does not handle multiple query blocks of
 *                           an alignment with a reference block length of less than
 *                           2*NUM_PES-2, because the shift register is of a fixed length.
 *                           This can be fixed by implementing a FIFO instead of a shift
 *                           register, which would be more complicated and need more area.
 *
 *                     TODO: Probably going to need a stall signal
 *
 *  Revision History :
 *      Albert Ng   May 02 2013     Initial Revision
 *      Albert Ng   May 06 2013     Added query sequence shift register
 *      Albert Ng   May 13 2013     Added all cell scores to output port
 *                                  Changed module name to SmithWatermanArray
 *      Albert Ng   May 15 2013     Added bubble documentation in file description
 *                                  Added inter-query-block intermediate value shiftregs
 *                                      and first_query_block input
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
    input first_query_block,                // Computing first block of the query
    output [NUM_PES * WIDTH - 1:0] V_out    // Cell score outputs
    );

    parameter NUM_PES = 10;
    parameter REF_LENGTH = 10;
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
    reg [WIDTH - 1:0] V_interm[REF_LENGTH - NUM_PES:0];
    reg [WIDTH - 1:0] F_interm[REF_LENGTH - NUM_PES:0];
       
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
    
    // Cell score intermediate values buffer
    generate
        for (i = 0; i < REF_LENGTH - NUM_PES + 1; i = i + 1) begin:interm_gen
            always @(posedge clk) begin
                if (rst) begin
                    V_interm[i] <= 0;
                    F_interm[i] <= 0;
                end else begin
                    if (i == 0) begin
                        V_interm[i] <= V[NUM_PES];
                        F_interm[i] <= F[NUM_PES];
                    end else begin
                        V_interm[i] <= V_interm[i-1];
                        F_interm[i] <= F_interm[i-1];
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
    assign V[0] = (first_query_block == 1) ? 0 : V_interm[REF_LENGTH - NUM_PES];
    assign F[0] = (first_query_block == 1) ? 0 : F_interm[REF_LENGTH - NUM_PES];
    assign T[0] = T_in;
    assign store_S[0] = store_S_in;
    assign init[0] = init_in;
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
