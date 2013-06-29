/*  File Name        : Engine_Ctrl.v
 *  Description      : Smith Waterman Engine Controller
 *
 *                     Handles timing and communication with the PCIe handler, the DRAM handler,
 *                     and the Smith Waterman systolic array.
 *
 *                     Reference sequences are stored in DRAM. Multiple references can be stored
 *                     at a time so independent engines can align to different references. Each
 *                     query sequence comes with some bookkeeping info, including the reference
 *                     sequence DRAM start address, the number of blocks in the reference sequence,
 *                     and the number of blocks in the query sequence. All pieces of bookkeeping
 *                     info are expected to be synchronous to bookkeeping_info_valid, which latches
 *                     the values to the appropriate buffer.
 *
 *                     The query sequence is stored in a BRAM double buffer. The double buffer is
 *                     there to prevent long query sequence write latencies to kill the
 *                     performance. One buffer is written to with query sequence data streamed
 *                     from PCIe, while the other buffer is read from to shift into the 
 *                     SW engine. The write buffer is written just once per query, while the read 
 *                     buffer is read N times, where N is the number of blocks in the reference
 *                     sequence. After the write buffer is fully written and the read buffer is
 *                     fully read, the two buffers swap, starting the alignment for the next
 *                     query sequence. The bookkeeping info that comes along with the query
 *                     sequence data is double buffered as well.
 *
 *                     The next query sequence block is read into
 *
 *                     TODO: (fake) DRAM interface
 *
 *  Revision History :
 *      Albert Ng   Jun 25 2013     Initial Revision
 *
 */
 
module Engine_Ctrl(
    input         clk,                      // System clock
    input         rst,                      // System reset
    input         stall,                    // Pipeline stall
    
    // PCIe handler interface
    input [24:0]  num_ref_blocks_in,        // Number of blocks in the reference sequence
    input [24:0]  ref_seq_start_addr_in,    // DRAM starting address for reference sequence
    input [15:0]  num_query_blocks_in,      // Number of blocks in the query sequence
    input         bookkeeping_info_valid,   // Store bookkeeping info for the query sequence
    input [127:0] query_seq_block_in,       // 64 nucleotide block of query sequence
    input         query_seq_block_valid,    // Query sequence block input valid
    output        query_seq_block_rdy,      // Query sequence block input acknowledged
    
    // DRAM reference reader interface
    output [24:0] ref_addr,                 // Address of reference sequence block
    output        ref_addr_valid,           // Reference sequence block address output valid
    input         ref_addr_rdy,             // Reference sequence block address output acknowledged
    input [511:0] ref_seq_block_in,         // 256 nucleotide block of reference sequence
    input         ref_seq_block_valid,      // Reference sequence block input valid
    output        ref_seq_block_rdy,        // Reference sequence block input acknowledged
    
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
    
    // Reference sequence block
    reg [1:0] T_sreg [REF_LENGTH-1:0];

    // Double buffer write select
    reg wr_buffer_sel;

    // Buffer swapping
    reg wr_buffer_rdy;
    reg rd_buffer_rdy;
    reg swap_d;
    reg swap_q;
    reg swapped;
    
    // Bookkeeping signals
    reg [24:0] num_ref_blocks0;
    reg [24:0] num_ref_blocks1;
    reg [24:0] ref_seq_start_addr0;
    reg [24:0] ref_seq_start_addr1;
    reg [9:0] num_query_blocks0;
    reg [9:0] num_query_blocks1;

    // Query sequence BRAM double buffer signals
    reg [9:0]   qsbram_wr_addr;
    reg         qsbram_wr_en0;
    reg         qsbram_wr_en1;
    reg [9:0]   qsbram_rd_addr;
    reg [127:0] qsbram_rd_out0;
    reg [127:0] qsbram_rd_out1;

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
    

    // SW Engine interface
    always @(*) begin
        if (!wr_buffer_sel) begin
            S_out = qsbram_rd_out1;
        end else begin
            S_out = qsbram_rd_out0;
        end

        first_query_block_out = first_query_block;
        next_first_ref_block_out = next_first_ref_block;
        first_ref_block_out = first_ref_block;
        last_ref_block_out = last_ref_block;
        last_block_char_out = last_block_char;
        
        if ((!wr_buffer_sel && (num_query_blocks1 == 0)) ||
            ( wr_buffer_sel && (num_query_blocks0 == 0))) begin
            bypass_fifo_out = 1;
        end else begin
            bypass_fifo_out = 0;
        end
        
        store_S_out = store_S;
        init_out = init;
        T_out = T_sreg[0];
    end
    
    // Bookkeeping info storage
    always @(posedge clk) begin
        if (rst) begin
            num_ref_blocks0 <= 0;
            num_ref_blocks1 <= 0;
            ref_seq_start_addr0 <= 0;
            ref_seq_start_addr1 <= 0;
            num_query_blocks0 <= 0;
            num_query_blocks1 <= 0;
        end else if (!stall) begin
            // Latch bookkeeping info for next query sequence after
            //   the buffers swapped
            if (bookkeeping_info_valid && !wr_buffer_rdy) begin
                if (!wr_buffer_sel) begin
                    num_ref_blocks0 <= num_ref_blocks_in;
                    ref_seq_start_addr0 <= ref_seq_start_addr_in;
                    num_query_blocks0 <= num_query_blocks_in;
                end else begin
                    num_ref_blocks1 <= num_ref_blocks_in;
                    ref_seq_start_addr1 <= ref_seq_start_addr_in;
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
        end else begin
            // Increment write address after writing
            if (query_seq_block_valid && !wr_buffer_rdy) begin
                qsbram_wr_addr <= qsbram_wr_addr + 1;
            end else begin
                // Reset write address when swapping buffers
                //   Wait until stall cleared before swapping
                if (wr_buffer_rdy && rd_buffer_rdy && !stall) begin
                    qsbram_wr_addr <= 0;
                end
            end
        end
    end
    
    // Buffers ready to swap
    always @(posedge clk) begin
        if (rst) begin
            wr_buffer_rdy <= 0;
            rd_buffer_rdy <= 0;
        end else begin
            // Write buffer ready to swap when write buffer address is at the
            //   total number of query blocks
            if (swapped) begin
                wr_buffer_rdy <= 0;
            end else if ((!wr_buffer_sel && (qsbram_wr_addr == num_query_blocks0)) ||
                         ( wr_buffer_sel && (qsbram_wr_addr == num_query_blocks1))) begin
                wr_buffer_rdy <= 1;
            end
        
            // Read buffer ready to swap when all query blocks have been read in
            //   the last reference block
            if (swapped) begin
                rd_buffer_rdy <= 0;
            end else if (last_ref_block && last_query_block && query_block_done) begin
                rd_buffer_rdy <= 1;
            end
        end
    end
    
    // Swap detector
    always @(posedge clk) begin
        if (rst) begin
            swap_q <= 0;
        end else if (!stall) begin
            swap_q <= swap_d;
        end
    end
    always @(*) begin
        swap_d = wr_buffer_rdy && rd_buffer_rdy && !stall;
        swapped = swap_d & (!swap_q);
    end
    
    // Buffer swapping
    always @(posedge clk) begin
        if (rst) begin
            wr_buffer_sel <= 0;
        end else begin
            // Swap buffers when ready
            //   Wait until stall cleared before swapping
            if (wr_buffer_rdy && rd_buffer_rdy && !stall) begin
                wr_buffer_sel <= !wr_buffer_sel;
            end
        end
    end
    
    // Ref block and query block counter logic
    always @(posedge clk) begin
        if (rst) begin
            ref_block_cnt <= 0;
            query_block_cnt <= 0;
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
        
        if (ref_block_cnt == 0) begin
            first_ref_block = 1;
        end
        
        if ((first_ref_block && !(last_block_char && last_query_block)) ||
            (last_ref_block && (last_block_char && last_query_block))) begin
            next_first_ref_block = 1;
        end
                
        if (( wr_buffer_sel && (ref_block_cnt == (num_ref_blocks0 - 1))) ||
            (!wr_buffer_sel && (ref_block_cnt == (num_ref_blocks1 - 1)))) begin
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
    end
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // Block char counter FSM
    always @(posedge clk) begin
        if (rst) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end
    
    always @(*) begin
        next_state = 0;
        case(state)
            IDLE:begin
                if (wr_buffer_rdy) begin
                    next_state = SEND_FIRST_T;
                end else begin
                    next_state = IDLE;
                end
            end
            
            SEND_FIRST_T:begin
                if (ref_seq_valid) begin
                    next_state = ACK_FIRST_T;
                end else begin
                    next_state = SEND_FIRST_T;
                end
            end
   
            ACK_FIRST_T:begin
                next_state = ALIGN_BLOCK;
            end
            
            ALIGN_BLOCK:begin
                if (last_block_char && last_query_block && last_ref_block) begin
                    next_state = IDLE;
                end else if (last_block_char) begin
                    next_state = CHECK_NEXT_T;
                end else begin
                    next_state = ALIGN_BLOCK;
                end
            end
            
            CHECK_NEXT_T:begin
                if (ref_seq_valid) begin
                    next_state = ALIGN_BLOCK;
                end else begin
                    next_state = CHECK_NEXT_T;
                end
            end
        endcase
    end
    always @(posedge clk) begin
        if (rst) begin
            block_char_cnt <= -1;
        end else begin
            case(state)
                IDLE:begin
                    block_char_cnt <= -1;
                end
                
                SEND_FIRST_T:begin
                    block_char_cnt <= -1;
                end
                
                ACK_FIRST_T:begin
                    block_char_cnt <= 0;
                end
                
                ALIGN_BLOCK:begin
                    if (!last_block_char && !rd_buffer_rdy) begin
                        block_char_cnt <= block_char_cnt + 1;
                    end else if (last_block_char) begin
                        block_char_cnt <= -1;
                    end
                end
                
                CHECK_NEXT_T:begin
                    block_char_cnt <= -1;
                end
                    
            endcase
        end
    end
endmodule
