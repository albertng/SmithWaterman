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
 *                     between alignments. The next alignment cannot begin until the
 *                     first query has been completely stored into the systolic
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
 *                     For multiple reference block alignments, the intermediate values of
 *                     V (and V_diag) and E must be stored in FIFOs to pass between
 *                     iterations. Each group of PEs shares one FIFO for each parameter.
 *                     Fewer PEs per FIFO reduces multiplexer routing, but increases the
 *                     number of BRAMs and FIFO control logic needed. At the last character
 *                     of each block, the PE writes its intermediate values to the FIFOs if
 *                     the block is not a last reference block. In addition, the PE reads the
 *                     next intermediate value from the FIFO to initialize the next block if
 *                     the next block is not a first reference block, in which case the 
 *                     parameters are initialized with their default values.
 *
 *                     If a query sequence is shorter than the number of PE's (i.e. no
 *                     inter-query blocking is needed), then no inter-reference block FIFOing
 *                     is needed. In this case, the inter-reference block values are simply kept
 *                     from the last block. Essentially, we are forwarding the PE's output
 *                     values back in as the initialization values, bypassing the FIFOs. Forwarding
 *                     must be done, as opposed to FWFT FIFOing, because the value is needed on
 *                     the same clock that we do the write, and there is a one clock latency for 
 *                     FIFO writes.
 *
 *                     Timing between blocks works as follows. On the last clock of the block
 *                     for a PE (score not output until next rising edge), last_block_char_in
 *                     is asserted, asserting rd_en. On the next rising edge, init_in is deasserted
 *                     and the intermediate value is read out of the FIFO to initialize the next
 *                     block. Also, the last_block_char shift reg is updated, wr_en is asserted, 
 *                     and the intermediate value is output by the PE to be written into the FIFO
 *                     on the next rising edge. 
 *
 *                     TODO: The current design does not handle multiple query blocks of
 *                           an alignment with a reference block length of less than
 *                           NUM_PES-1 (I think), because the shift register is of a fixed 
 *                           length. This can be fixed by implementing a FIFO instead of a 
 *                           shift register, which would be slightly more complicated.
 *
 *  Revision History :
 *      Albert Ng   May 02 2013     Initial Revision
 *      Albert Ng   May 06 2013     Added query sequence shift register
 *      Albert Ng   May 13 2013     Added all cell scores to output port
 *                                  Changed module name to SmithWatermanArray
 *      Albert Ng   May 15 2013     Added bubble documentation in file description
 *                                  Added inter-query-block intermediate value shiftregs
 *                                      and first_query_block input
 *      Albert Ng   Jun 05 2013     Inter-ref-block intermediate value handling, untested
 *      Albert Ng   Jun 06 2013     Variable number of PEs per FIFO
 *      Albert Ng   Jun 07 2013     Changed next_first_ref_block, first_ref_block, last_ref_block,
 *                                      and bypass_fifo to shift registers
 *      Albert Ng   Jun 24 2013     Fixed minor bug with bypass_fifo
 *                                  Added stall signal
 *      Albert Ng   Jun 26 2013     Removed S shift register buffer
 *                                  Changed S_in port from single nucleotide to NUM_PEs nucleotides
 *                                  First_ref_block and Next_first_ref_block shift regs reset to 1
 *      Albert Ng   Jun 27 2013     Stopped FIFO read/write when stalling 
 *      Albert Ng   Jul 08 2013     Stopped shift register shifting when stalling 
 *
 */

module SmithWatermanArray(
    input clk,                              // System clock
    input rst,                              // System reset
    input stall,                            // Pipeline stall
    input [(NUM_PES * 2) - 1:0] S_in,       // Query sequence
    input [1:0] T_in,                       // Reference sequence shift in
    input store_S_in,                       // Load systolic array with new query seq
    input init_in,                          // Computation active shift in
    input first_query_block,                // Computing first block of the query
    input next_first_ref_block_in,          // Next block is a first block of the reference
    input first_ref_block_in,               // Computing a first block of the reference
    input last_ref_block_in,                // Computing a last block of the reference
    input last_block_char_in,               // Computing last char in the reference block
    input bypass_fifo_in,                   // Bypass inter-ref-block FIFOs
    output [NUM_PES * WIDTH - 1:0] V_out    // Cell score outputs
    );

    parameter NUM_PES = 64;
    parameter REF_LENGTH = 256;
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;
    parameter PES_PER_FIFO = 4;

    wire [WIDTH - 1:0] V[NUM_PES:0];
    wire [WIDTH - 1:0] E[NUM_PES:0];
    wire [WIDTH - 1:0] F[NUM_PES:0];
    reg [WIDTH - 1:0] init_E[NUM_PES-1:0];
    reg [WIDTH - 1:0] init_V[NUM_PES-1:0];
    wire [1:0] T[NUM_PES:0];
    wire store_S[NUM_PES:0];
    wire init[NUM_PES:0];
    
    wire [17:0] din_V[NUM_PES/PES_PER_FIFO - 1:0];
    wire [17:0] dout_V[NUM_PES/PES_PER_FIFO - 1:0];
    wire full_V[NUM_PES/PES_PER_FIFO - 1:0];
    wire empty_V[NUM_PES/PES_PER_FIFO - 1:0];
    wire [17:0] din_E[NUM_PES/PES_PER_FIFO - 1:0];
    wire [17:0] dout_E[NUM_PES/PES_PER_FIFO - 1:0];
    wire full_E[NUM_PES/PES_PER_FIFO - 1:0];
    wire empty_E[NUM_PES/PES_PER_FIFO - 1:0];
    reg wr_en[NUM_PES/PES_PER_FIFO - 1:0];
    reg rd_en[NUM_PES/PES_PER_FIFO - 1:0];
    
    reg [NUM_PES - 1:0] next_first_ref_block;
    reg [NUM_PES - 1:0] first_ref_block;
    reg [NUM_PES - 1:0] last_ref_block;
    reg [NUM_PES - 1:0] last_block_char;
    reg [NUM_PES - 1:0] bypass_fifo;
    reg [WIDTH - 1:0] V_interm[REF_LENGTH - NUM_PES:0];
    reg [WIDTH - 1:0] F_interm[REF_LENGTH - NUM_PES:0];
       
    wire [PES_PER_FIFO*WIDTH - 1:0] fifo_mux_input_V[NUM_PES/PES_PER_FIFO - 1:0];
    wire [PES_PER_FIFO*WIDTH - 1:0] fifo_mux_input_E[NUM_PES/PES_PER_FIFO - 1:0];
    
    // Cell score inter-query block intermediate values buffer
    genvar i, j;
    always @(posedge clk) begin
        if (rst) begin
            V_interm[0] <= 0;
            F_interm[0] <= 0;
        end else if (!stall) begin
            V_interm[0] <= V[NUM_PES];
            F_interm[0] <= F[NUM_PES];
        end
    end
    generate
        for (i = 1; i < REF_LENGTH - NUM_PES + 1; i = i + 1) begin:inter_query_block_interm_gen
            always @(posedge clk) begin
                if (rst) begin
                    V_interm[i] <= 0;
                    F_interm[i] <= 0;
                end else if (!stall) begin
                    V_interm[i] <= V_interm[i-1];
                    F_interm[i] <= F_interm[i-1];
                end
            end
        end
    endgenerate

    // Cell score inter-reference block intermediate values buffer
    generate
        for (i = 0; i < NUM_PES/PES_PER_FIFO; i = i + 1) begin:inter_ref_block_fifo_gen
            // FIFO input muxes
            for (j = 0; j < PES_PER_FIFO; j = j + 1) begin:fifo_mux_input_gen
                assign fifo_mux_input_V[i][(j+1)*WIDTH - 1 -: WIDTH] = V[i*PES_PER_FIFO + j + 1];
                assign fifo_mux_input_E[i][(j+1)*WIDTH - 1 -: WIDTH] = E[i*PES_PER_FIFO + j + 1];
            end
            one_hot_mux #(PES_PER_FIFO, WIDTH) fifo_in_mux_V (
                .data_in(fifo_mux_input_V[i]),
                .select(last_block_char[(i+1)*PES_PER_FIFO-1 -: PES_PER_FIFO]),
                .data_out(din_V[i][WIDTH-1 : 0])
            );
            one_hot_mux #(PES_PER_FIFO, WIDTH) fifo_in_mux_E (
                .data_in(fifo_mux_input_E[i]),
                .select(last_block_char[(i+1)*PES_PER_FIFO-1 -: PES_PER_FIFO]),
                .data_out(din_E[i][WIDTH-1 : 0])
            );
            
            inter_ref_block_fifo irbf_V (
                .clk(clk),
                .rst(rst),
                .din(din_V[i]),
                .wr_en(wr_en[i]),
                .rd_en(rd_en[i]),
                .dout(dout_V[i]),
                .full(full_V[i]),
                .empty(empty_V[i])
            );
            inter_ref_block_fifo irbf_E (
                .clk(clk),
                .rst(rst),
                .din(din_E[i]),
                .wr_en(wr_en[i]),
                .rd_en(rd_en[i]),
                .dout(dout_E[i]),
                .full(full_E[i]),
                .empty(empty_E[i])
            );
        end
    endgenerate
    
    always @(*) begin
        // Write to inter-reference block FIFO at the end of all blocks if 
        //   they are not a last reference block
        if ((|(last_block_char[PES_PER_FIFO-1 : 0] &
              ~last_ref_block[PES_PER_FIFO-1 : 0] & 
              ~bypass_fifo[PES_PER_FIFO-1 : 0])) && !stall) begin
            wr_en[0] <= 1;
        end else begin
            wr_en[0] <= 0;
        end
        
        // Read from inter-reference block FIFO at the end of all blocks if
        //   the next block is not a first reference block
        if ((|({last_block_char[PES_PER_FIFO-2 : 0], last_block_char_in} & 
              {~next_first_ref_block[PES_PER_FIFO-2 : 0], !next_first_ref_block_in})) && !stall) begin
            rd_en[0] <= 1;
        end else begin
            rd_en[0] <= 0;
        end
    end
    generate
        for (i = 1; i < NUM_PES/PES_PER_FIFO; i = i + 1) begin: inter_ref_block_fifo_ctrl_gen
            always @(*) begin
                // Write to inter-reference block FIFO at the end of all blocks if 
                //   they are not a last reference block
                if ((|(last_block_char[(i+1)*PES_PER_FIFO-1 -: PES_PER_FIFO] &
                      ~last_ref_block[(i+1)*PES_PER_FIFO-1 -: PES_PER_FIFO] &
                      ~bypass_fifo[(i+1)*PES_PER_FIFO-1 -: PES_PER_FIFO])) && !stall) begin
                    wr_en[i] <= 1;
                end else begin
                    wr_en[i] <= 0;
                end
                
                // Read from inter-reference block FIFO at the end of all blocks if
                //   the next block is not a first reference block
                if ((|(last_block_char[(i+1)*PES_PER_FIFO-2 -: PES_PER_FIFO] & 
                      ~next_first_ref_block[(i+1)*PES_PER_FIFO-2 -: PES_PER_FIFO])) && !stall) begin
                    rd_en[i] <= 1;
                end else begin
                    rd_en[i] <= 0;
                end
            end
        end
    endgenerate
    
    generate
        always @(*) begin
            if (!bypass_fifo) begin
                init_V[0] <= (first_ref_block_in) ? 0 : dout_V[0][WIDTH - 1:0];
                init_E[0] <= (first_ref_block_in) ? 0 : dout_E[0][WIDTH - 1:0];
            end else begin
                init_V[0] <= (first_ref_block_in) ? 0 : V[1]; // Bypass FIFOs when no inter-query blocking is needed
                init_E[0] <= (first_ref_block_in) ? 0 : E[1];
            end
        end
        for (i = 1; i < NUM_PES; i = i + 1) begin:inter_ref_block_interm_gen
            always @(*) begin
                if (!bypass_fifo) begin
                    init_V[i] <= (first_ref_block[i-1]) ? 0 : dout_V[i/PES_PER_FIFO][WIDTH - 1:0];
                    init_E[i] <= (first_ref_block[i-1]) ? 0 : dout_E[i/PES_PER_FIFO][WIDTH - 1:0];
                end else begin
                    init_V[i] <= (first_ref_block[i-1]) ? 0 : V[i+1]; // Bypass FIFOs when no inter-query blocking is needed
                    init_E[i] <= (first_ref_block[i-1]) ? 0 : E[i+1];
                end
            end
        end
    endgenerate
    
    // Last reference block char shift register
    always @(posedge clk) begin
        if (rst) begin
            next_first_ref_block[0] <= 0;
            first_ref_block[0] <= 0;
            last_ref_block[0] <= 0;
            last_block_char[0] <= 0;
            bypass_fifo[0] <= 0;
        end else if (!stall) begin
            next_first_ref_block[0] <= next_first_ref_block_in;
            first_ref_block[0] <= first_ref_block_in;
            last_ref_block[0] <= last_ref_block_in;
            last_block_char[0] <= last_block_char_in;
            bypass_fifo[0] <= bypass_fifo_in;
        end
    end
    generate
        for (i = 1; i < NUM_PES; i = i + 1) begin:last_block_char_gen
            always @(posedge clk) begin
                if (rst) begin
                    next_first_ref_block[i] <= 1;
                    first_ref_block[i] <= 1;
                    last_ref_block[i] <= 0;
                    last_block_char[i] <= 0;
                    bypass_fifo[i] <= 0;
                end else if (!stall) begin
                    next_first_ref_block[i] <= next_first_ref_block[i-1];
                    first_ref_block[i] <= first_ref_block[i-1];
                    last_ref_block[i] <= last_ref_block[i-1];
                    last_block_char[i] <= last_block_char[i-1];
                    bypass_fifo[i] <= bypass_fifo[i-1];
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
                .stall(stall),
                .V_in(V[i]), 
                .F_in(F[i]), 
                .T_in(T[i]), 
                .S_in(S_in[i*2 + 1 -: 2]), 
                .store_S_in(store_S[i]), 
                .init_in(init[i]),
                .init_E(init_E[i]),
                .init_V(init_V[i]),
                .V_out(V[i+1]),
                .E_out(E[i+1]),
                .F_out(F[i+1]), 
                .T_out(T[i+1]), 
                .S_out(),
                .store_S_out(store_S[i+1]),
                .init_out(init[i+1])
            );
        end
    endgenerate
endmodule
