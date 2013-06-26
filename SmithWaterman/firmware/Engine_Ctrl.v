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
 *                     TODO: query sequence buffer reading
 *
 *                     TODO: counters and associated signals
 *
 *                     TODO: (fake) DRAM interface
 *
 *                     TODO: handle stalls
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
    input         query_seq_block_valid,    // Store query sequence block
    output        query_seq_block_rdy,      // Query sequence block stored
    
    // SW Engine interface
    output [1:0] S_out,                     // Query sequence shift out
    output [1:0] T_out,                     // Reference sequence shift
    output store_S_out,                     // Load systolic array with new query seq
    output shift_S_out,                     // Load next query seq shift register
    output init_out,                        // Computation active shift in
    output first_query_block_out,           // Computing first block of the query
    output next_first_ref_block_out,        // Next block is a first block of the reference
    output first_ref_block_out,             // Computing a first block of the reference
    output last_ref_block_out,              // Computing a last block of the reference
    output last_block_char_out,             // Computing last char in the reference block
    output bypass_fifo_out                  // Bypass inter-ref-block FIFOs
    );

    parameter NUM_PES = 64;
    
    // Counters and associated clock labels
    reg [24:0] ref_block_cnt;
    reg [15:0] query_block_cnt;
    reg [9:0]  block_char_cnt;
    reg first_query_block;
    reg last_query_block;
    reg first_ref_block;
    reg next_first_ref_block;
    reg last_ref_block;
    reg last_block_char;
    
    // Sequence shift registers
    reg [1:0] S_sreg [NUM_PES-1:0]; // Query
    reg [1:0] T_sreg [255:0];       // Reference

    // Double buffer write select
    reg wr_buffer_sel;

    // Buffers ready to swap
    reg wr_buffer_rdy;
    reg rd_buffer_rdy;
    
    // Bookkeeping signals
    reg [24:0] num_ref_blocks0;
    reg [24:0] num_ref_blocks1;
    reg [24:0] ref_seq_start_addr0;
    reg [24:0] ref_seq_start_addr1;
    reg [15:0] num_query_blocks0;
    reg [15:0] num_query_blocks1;

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
        addra(qsbram_wr_addr0),
        dina(query_seq_block_in),
        clkb(clk),
        addrb(qsbram_rd_addr0),
        doutb(qsbram_rd_out0)
    );
    query_seq_bram qsbram1 (
        clka(clk),
        wea(qsbram_wr_en1),
        addra(qsbram_wr_addr1),
        dina(query_seq_block_in),
        clkb(clk),
        addrb(qsbram_rd_addr1),
        doutb(qsbram_rd_out1)
    );
    
    // Bookkeeping info storage
    always @(posedge clk) begin
        if (rst) begin
            num_ref_blocks0 <= 0;
            num_ref_blocks1 <= 0;
            ref_seq_start_addr0 <= 0;
            ref_seq_start_addr1 <= 0;
            num_query_blocks0 <= 0;
            num_query_blocks1 <= 0;
        end else begin
            // Latch bookkeeping info for next query sequence after
            //   the buffers swapped
            if (bookkeeping_info_valid && !wr_buffer_rdy) begin
                if (wr_buffer == 0) begin
                    num_ref_blocks0 <= num_ref_blocks_in;
                    ref_seq_start_addr0 <= ref_seq_start_addr_in;
                    num_query_blocks0 <= num_query_blocks_in;
                end else begin
                    num_ref_blocks1 <= num_ref_blocks_in;
                    ref_seq_start_addr1 <= num_ref_blocks_in;
                    num_query_blocks1 <= num_ref_blocks_in;
                end
            end
        end
    end
    
    // Query sequence BRAM buffer write control
    always @(posedge clk) begin
        if (rst) begin
            qsbram_wr_en0 <= 0;
            qsbram_wr_en1 <= 0;
            qsbram_wr_addr <= 0;
        end else begin
            // Write to the appropriate buffer when there is a new query sequence
            //   block to write and we haven't finished writing the full query
            //   sequence yet
            if (!wr_buffer_sel && query_seq_block_valid && !wr_buffer_rdy) begin
                qsbram_wr_en0 <= 1;
            end else begin
                qsbram_wr_en0 <= 0;
            end
            if (wr_buffer_sel && query_seq_block_valid && !wr_buffer_rdy) begin
                qsbram_wr_en1 <= 1;
            end else begin
                qsbram_wr_en1 <= 0;
            end

            // When writing, handshake with the PCIe handler and increment the
            //   write address
            if (query_seq_block_valid && !wr_buffer_rdy) begin
                query_seq_block_rdy <= 1;
                qsbram_wr_addr <= qsbram_wr_addr + 1;
            end else begin
                query_seq_block_rdy <= 0;
                
                // Reset write address when swapping buffers
                if (wr_buffer_rdy && rd_buffer_rdy) begin
                    qsbram_wr_addr <= 0;
                end
            end
        end
    end
    
    // Buffers ready to swap
    always @(*) begin
        // Write buffer ready to swap when all query blocks have been written
        if ((!wr_buffer_sel && (qsbram_wr_addr == num_query_blocks0)) ||
            ( wr_buffer_sel && (qsbram_wr_addr == num_query_blocks1))) begin
            wr_buffer_rdy <= 1;
        end else begin
            wr_buffer_rdy <= 0;
        end
    
        // Read buffer ready to swap when all query blocks have been read in
        //   the last reference block
        if (last_ref_block &&
            (!wr_buffer_sel && (qsbram_rd_addr == num_query_blocks1)) ||
            ( wr_buffer_sel && (qsbram_rd_addr == num_query_blocks0))) begin
            rd_buffer_rdy <= 1;
        end else begin
            rd_buffer_rdy <= 0;
        end
    end
    
    // Buffer swapping
    always @(posedge clk) begin
        if (rst) begin
            wr_buffer <= 0;
        end else begin
            // Swap buffers when both are ready
            if (wr_buffer_rdy && rd_buffer_rdy) begin
                wr_buffer <= !wr_buffer;
            end
        end
    end
    
    // Query sequence BRAM buffer read control
    always @(posedge clk) begin
        if (rst) begin
            qsbram_rd_addr <= 0;
        end else begin
            if (last_block_char && !last_query_block) begin
                qsbram_rd_addr <= qsbram_rd_addr + 1;
            end else if (last_block_char && last_query_block) begin
                qsbram_rd_addr <= 0;
            end
        end
    end
    
endmodule
