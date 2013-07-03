/*  File Name        : Engine_Ctrl.v
 *  Description      : Smith Waterman Engine Controller
 *
 *                     Handles timing and communication with the PCIe handler, the reference 
 *                     reader, and the Smith Waterman systolic array.
 *
 *                     The query sequence is stored in a BRAM double buffer. The double buffer is
 *                     there to prevent long query sequence write latencies to kill the
 *                     performance. One buffer is written to with query sequence data streamed
 *                     from PCIe, while the other buffer is read from to shift into the 
 *                     SW engine. The write buffer is written just once per query, while the read 
 *                     buffer is read N times, where N is the number of blocks in the reference
 *                     sequence. After the write buffer is fully written and the read buffer is
 *                     fully read, the two buffers swap, starting the alignment for the next
 *                     query sequence. Each query sequence comes with some bookkeeping info, 
 *                     including the reference sequence DRAM start address, the number of blocks 
 *                     in the reference sequence, and the number of blocks in the query sequence. 
 *                     All pieces of bookkeeping info are expected to be synchronous to , 
 *                     bookkeeping_info_valid which latches the values to the appropriate buffer.
 *
 *                     The engine controller communicates with a reference reader to grab the 
 *                     reference sequence blocks to shift into the systolic array. At the start 
 *                     the alignment for each query sequence, the engine sends the reference
 *                     sequence starting address and reference sequence length (in number of 256
 *                     bp blocks) to the reference reader, synchronous to the ref_info_valid
 *                     signal. It expects a ref_seq_block_valid signal from the reference reader
 *                     to indicate whenever there is a new reference sequence block to process.
 *                     The engine controller latches the reference sequence block and asserts a
 *                     ref_seq_block_rdy signal to pop off the next reference sequence block.
 *
 *                     The Smith Waterman systolic array control signals, as well as others, are
 *                     generated off of a FSM and three counters: a block character counter, a
 *                     query block counter, and reference block counter. The reference sequence
 *                     block is stored in a rotating shift register to shift in the next reference
 *                     sequence nucleotide into the systolic array. This shift register is updated
 *                     with the next reference sequence block once all query blocks have been 
 *                     aligned.
 *                      
 *
 *
 *  Revision History :
 *      Albert Ng   Jun 25 2013     Initial Revision
 *      Albert Ng   Jul 02 2013     Finished initial revision, untested
 *
 */
 
module Engine_Ctrl(
    input         clk,                      // System clock
    input         rst,                      // System reset
    input         stall,                    // Pipeline stall
    
    // PCIe handler interface
    input [24:0]  ref_length_in,            // Number of 256 bp blocks in the reference sequence
    input [24:0]  ref_addr_in,              // DRAM starting address for reference sequence
    input [15:0]  num_query_blocks_in,      // Number of blocks in the query sequence
    input         bookkeeping_info_valid,   // Store bookkeeping info for the query sequence
    input [127:0] query_seq_block_in,       // 64 bp block of query sequence
    input         query_seq_block_valid,    // Query sequence block input valid
    output        query_seq_block_rdy_out,  // Query sequence block input acknowledged
    
    // DRAM reference reader interface
    output [24:0] ref_addr_out,             // DRAM starting address for reference sequence
    output [24:0] ref_length_out,           // Number of blocks in the reference sequence
    output        ref_info_valid_out,       // Reference sequence info output valid
    input [511:0] ref_seq_block_in,         // 256 nucleotide block of reference sequence
    input         ref_seq_block_valid,      // Reference sequence block input valid
    output        ref_seq_block_rdy_out,    // Reference sequence block input acknowledged
    
    // SW Engine interface
    output [(NUM_PES * 2) - 1:0] S_out,     // Query sequence
    output [1:0] T_out,                     // Reference sequence shift
    output store_S_out,                     // Load systolic array with new query seq
    output init_out,                        // Computation active shift in
    output first_query_block_out,           // Computing first block of the query
    output next_first_ref_block_out,        // Next block is a first block of the reference
    output first_ref_block_out,             // Computing a first block of the reference
    output last_ref_block_out,              // Computing a last block of the reference
    output last_block_char_out,             // Computing last char in the reference block
    output bypass_fifo_out                  // Bypass inter-ref-block FIFOs
    );

    parameter NUM_PES = 64;
    parameter REF_LENGTH = 256;
    
    // FSM states
    parameter WAIT_WR_RDY = 5'b00001, SEND_REF_ADDR = 5'b00010, 
              WAIT_REF_SEQ_BLOCK_VALID = 5'b00100, LATCH_REF = 5'b01000, 
              ADVANCE_BLOCK_CHAR_CNT = 5'b10000;
    reg [4:0] state;
    reg [4:0] next_state;
    
    // FSM outputs
    reg next_block_char_cnt;
    reg rd_buffer_rdy;                
    reg ref_addr;
    reg ref_length;
    reg ref_info_valid;
    reg ref_seq_block_rdy;
    reg latch_T;
    reg shift_T;
    
    // Counters
    reg [24:0] ref_block_cnt;
    reg [9:0] query_block_cnt;
    reg [9:0] block_char_cnt;
    
    // Signals based off of counters
    reg first_query_block;
    reg last_query_block;
    reg first_ref_block;
    reg next_first_ref_block;
    reg last_ref_block;
    reg last_block_char;
    reg store_S;
    reg init;
    reg bypass_fifo;
    
    // Reference sequence block rotating shift register
    reg [1:0] T_sreg [REF_LENGTH-1:0];
    
    // Bookkeeping signals
    reg [24:0] ref_length0;
    reg [24:0] ref_length1;
    reg [24:0] ref_addr0;
    reg [24:0] ref_addr1;
    reg [9:0] num_query_blocks0;
    reg [9:0] num_query_blocks1;

    // Query sequence BRAM double buffer signals
    reg wr_buffer_sel;
    reg wr_buffer_rdy;
    reg [9:0]   qsbram_wr_addr;
    reg         qsbram_wr_en0;
    reg         qsbram_wr_en1;
    wire [9:0]  qsbram_rd_addr;
    reg [127:0] qsbram_rd_out0;
    reg [127:0] qsbram_rd_out1;
    reg [(NUM_PES * 2) - 1:0] S;
    reg query_seq_block_rdy;

    // Query sequence BRAM double buffer
    query_seq_bram qsbram0 (
        clka(clk),
        wea(qsbram_wr_en0),
        addra(qsbram_wr_addr),
        dina(query_seq_block_in),
        clkb(clk),
        addrb(qsbram_rd_addr),
        doutb(qsbram_rd_out0)
    );
    query_seq_bram qsbram1 (
        clka(clk),
        wea(qsbram_wr_en1),
        addra(qsbram_wr_addr),
        dina(query_seq_block_in),
        clkb(clk),
        addrb(qsbram_rd_addr),
        doutb(qsbram_rd_out1)
    );
    always @(*) begin
        if (!wr_buffer_sel) begin
            S = qsbram_rd_out1;
        end else begin
            S = qsbram_rd_out0;
        end
    end
    
    // Output signal wiring interface 
    assign S_out = S;
    assign first_query_block_out = first_query_block;
    assign next_first_ref_block_out = next_first_ref_block;
    assign first_ref_block_out = first_ref_block;
    assign last_ref_block_out = last_ref_block;
    assign last_block_char_out = last_block_char;
    assign bypass_fifo_out = bypass_fifo;
    assign store_S_out = store_S;
    assign init_out = init;
    assign T_out = T_sreg[0];
    assign query_seq_block_rdy_out = query_seq_block_rdy;
    assign ref_addr_out = ref_addr;
    assign ref_info_valid_out = ref_info_valid;
    assign ref_length_out = ref_length;
    assign ref_seq_block_rdy_out = ref_seq_block_rdy;
    
    // Reference sequence block rotating shift register
    genvar i;
    always @(posedge clk) begin
        if (rst) begin
            T_sreg[REF_LENGTH - 1] <= 0;
        end else if (!stall) begin
            if (latch_T) begin
                T_sreg[REF_LENGTH - 1] <= ref_seq_block_in[2*REF_LENGTH - 1 -: 2];
            end else if (shift_T) begin
                T_sreg[REF_LENGTH - 1] <= T_sreg[0];
            end
        end
    end   
    generate
        for (i = 0; i < REF_LENGTH - 1; i = i + 1) begin:t_sreg_gen
            always @(posedge clk) begin
                if (rst) begin
                    T_sreg[i] <= 0;
                end else if (!stall) begin
                    if (latch_T) begin
                        T_sreg[i] <= ref_seq_block_in[i*2 + 1 -: 2];
                    end else if (shift_T) begin
                        T_sreg[i] <= T_sreg[i + 1];
                    end
                end
            end
        end
    endgenerate
    
    // Bookkeeping info storage
    always @(posedge clk) begin
        if (rst) begin
            ref_length0 <= 0;
            ref_length1 <= 0;
            ref_addr0 <= 0;
            ref_addr1 <= 0;
            num_query_blocks0 <= 0;
            num_query_blocks1 <= 0;
        end else if (!stall) begin
            // Latch bookkeeping info for next query sequence after
            //   the buffers swapped
            if (bookkeeping_info_valid && !wr_buffer_rdy) begin
                if (!wr_buffer_sel) begin
                    ref_length0 <= ref_length_in;
                    ref_addr0 <= ref_addr_in;
                    num_query_blocks0 <= num_query_blocks_in;
                end else begin
                    ref_length1 <= ref_length_in;
                    ref_addr1 <= ref_addr_in;
                    num_query_blocks1 <= num_query_blocks_in;
                end
            end
        end
    end
    
    // Query sequence BRAM buffer write control
    always @(*) begin
        query_seq_block_rdy = 0;
        qsbram_wr_en0 = 0;
        qsbram_wr_en1 = 0;
    
        // New query sequence block is available to write and haven't
        //   finished writing the full query sequence yet. Acknowledge
        //   the sender and store the query block.
        if (query_seq_block_valid && !wr_buffer_rdy) begin
            query_seq_block_rdy = 1;

            if (!wr_buffer_sel) begin
                qsbram_wr_en0 = 1;
            end else begin
                qsbram_wr_en1 = 1;
            end
        end
    end
    always @(posedge clk) begin
        if (rst) begin
            qsbram_wr_addr <= 0;
            wr_buffer_rdy <= 0;
        end else if (!stall) begin
            // Increment write address after writing
            if (query_seq_block_valid && !wr_buffer_rdy) begin
                qsbram_wr_addr <= qsbram_wr_addr + 1;
            end else begin
                // Reset write address when swapping buffers
                //   Wait until stall cleared before swapping
                if (wr_buffer_rdy && rd_buffer_rdy) begin
                    qsbram_wr_addr <= 0;
                end
            end
            
            // Write buffer ready to swap when write buffer address is at the
            //   total number of query blocks
            if (!wr_buffer_rdy && 
                ((!wr_buffer_sel && (qsbram_wr_addr == num_query_blocks0)) ||
                ( wr_buffer_sel && (qsbram_wr_addr == num_query_blocks1)))) begin
                wr_buffer_rdy <= 1;
            end else if (wr_buffer_rdy && rd_buffer_rdy) begin
                wr_buffer_rdy <= 0;
            end
        end
    end
    
    // Buffer swapping
    always @(posedge clk) begin
        if (rst) begin
            wr_buffer_sel <= 0;
        end else if (!stall) begin
            // Swap buffers when ready
            if (wr_buffer_rdy && rd_buffer_rdy) begin
                wr_buffer_sel <= !wr_buffer_sel;
            end
        end
    end
    
    // Counter logic
    always @(posedge clk) begin
        if (rst) begin
            ref_block_cnt <= 0;
            query_block_cnt <= 0;
            block_char_cnt <= 0;
        end else if (!stall) begin
            // Increment reference block counter at the last character of the
            //   last query block, wrapping back to 0 after the last reference
            //   block
            if (last_block_char && last_query_block && !last_ref_block) begin
                ref_block_cnt <= ref_block_cnt + 1;
            end else if (last_block_char && last_query_block && last_ref_block) begin
                ref_block_cnt <= 0;
            end 
            
            // Increment query block counter at the last character of the block,
            //   wrapping back to 0 after the last query block
            if (last_block_char && !last_query_block) begin
                query_block_cnt <= query_block_cnt + 1;
            end else if (last_block_char && last_query_block) begin
                query_block_cnt <= 0;
            end
            
            block_char_cnt <= next_block_char_cnt;
        end
    end
    
    // Logic based off of counters
    assign qsbram_rd_addr = query_block_cnt;
    always @(*) begin
        first_query_block = 0;
        last_query_block = 0;
        first_ref_block = 0;
        last_ref_block = 0;
        next_first_ref_block = 0;
        last_block_char = 0;
        store_S = 0;
        init = 0;
        bypass_fifo = 0;
        
        if (ref_block_cnt == 0) begin
            first_ref_block = 1;
        end
        
        if ((first_ref_block && !(last_block_char && last_query_block)) ||
            (last_ref_block && (last_block_char && last_query_block))) begin
            next_first_ref_block = 1;
        end
                
        if (( wr_buffer_sel && (ref_block_cnt == (ref_length0 - 1))) ||
            (!wr_buffer_sel && (ref_block_cnt == (ref_length1 - 1)))) begin
            last_ref_block = 1;
        end

        if (query_block_cnt == 0) begin
            first_query_block = 1;
        end
        
        if (( wr_buffer_sel && (query_block_cnt == (num_query_blocks0 - 1))) ||
            (!wr_buffer_sel && (query_block_cnt == (num_query_blocks1 - 1)))) begin
            last_query_block = 1;
        end

        if (block_char_cnt == (REF_LENGTH - 1)) begin
            last_block_char = 1;
        end
        
        if (block_char_cnt == -1) begin
            store_S = 1;
        end
        
        if (block_char_cnt != -1) begin
            init = 1;
        end
        
        if ((!wr_buffer_sel && (num_query_blocks1 == 0)) ||
            ( wr_buffer_sel && (num_query_blocks0 == 0))) begin
            bypass_fifo = 1;
        end
    end
    

    // Block char counter FSM
    always @(posedge clk) begin
        if (rst) begin
            state <= WAIT_WR_RDY;
        end else if (!stall) begin
            state <= next_state;
        end
    end
    
    always @(*) begin
        next_state = 0;
        case(state)
            WAIT_WR_RDY:begin
                if (wr_buffer_rdy) begin
                    next_state = SEND_REF_ADDR;
                end else begin
                    next_state = WAIT_WR_RDY;
                end
            end
            
            SEND_REF_ADDR:begin
                next_state = WAIT_REF_SEQ_BLOCK_VALID;
            end
   
            WAIT_REF_SEQ_BLOCK_VALID:begin
                if (ref_seq_block_valid) begin
                    next_state = LATCH_REF;
                end else begin
                    next_state = WAIT_REF_SEQ_BLOCK_VALID;
                end
            end
            
            LATCH_REF:begin
                next_state = ADVANCE_BLOCK_CHAR_CNT;
            end
            
            ADVANCE_BLOCK_CHAR_CNT:begin
                if (last_ref_block && last_query_block && last_block_char) begin
                    next_state = WAIT_WR_RDY;
                end else if (!last_ref_block && last_query_block && last_block_char &&
                             !ref_seq_block_valid) begin
                    next_state = WAIT_REF_SEQ_BLOCK_VALID;
                end else if (!last_ref_block && last_query_block && last_block_char &&
                             ref_seq_block_valid) begin
                    next_state = LATCH_REF;
                end else begin
                    next_state = ADVANCE_BLOCK_CHAR_CNT;
                end
            end
        endcase
    end
    
    always @(*) begin
        case(state)
            WAIT_WR_RDY:begin
                next_block_char_cnt = -1;
                rd_buffer_rdy = 1;                
                ref_addr = 0;
                ref_length = 0;
                ref_info_valid = 0;
                ref_seq_block_rdy = 0;
                latch_T = 0;
                shift_T = 0;
            end
            
            SEND_REF_ADDR:begin
                next_block_char_cnt = -1;
                rd_buffer_rdy = 0;
                if (wr_buffer_sel) begin
                    ref_addr = ref_addr0;
                    ref_length = ref_length0;
                end else begin
                    ref_addr = ref_addr1;
                    ref_length = ref_length1;
                end
                ref_info_valid = 1;
                ref_seq_block_rdy = 0;
                latch_T = 0;
                shift_T = 0;
            end
            
            WAIT_REF_SEQ_BLOCK_VALID:begin
                next_block_char_cnt = -1;
                rd_buffer_rdy = 0;
                ref_addr = 0;
                ref_length = 0;
                ref_info_valid = 0;
                ref_seq_block_rdy = 0;
                latch_T = 0;
                shift_T = 0;
            end
            
            LATCH_REF:begin
                next_block_char_cnt = -1;
                rd_buffer_rdy = 0;
                ref_addr = 0;
                ref_length = 0;
                ref_info_valid = 0;
                ref_seq_block_rdy = 1;
                latch_T = 1;
                shift_T = 0;
            end
            
            ADVANCE_BLOCK_CHAR_CNT:begin
                if (!last_block_char) begin
                    next_block_char_cnt = block_char_cnt + 1;
                end else begin
                    next_block_char_cnt = -1;
                end
                rd_buffer_rdy = 0;
                ref_addr = 0;
                ref_length = 0;
                ref_info_valid = 0;
                ref_seq_block_rdy = 0;
                latch_T = 0;
                if (block_char_cnt != -1) begin
                    shift_T = 1;
                end
            end
                
        endcase
    end
endmodule
