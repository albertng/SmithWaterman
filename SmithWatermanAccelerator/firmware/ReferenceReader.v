/*  File Name        : ReferenceReader.v
 *  Description      : Reference Sequence Reader
 *
 *                     Unit that sends DRAM read requests to the AXI bus
 *                     arbiter and buffers reference sequence blocks read
 *                     from DRAM.
 *
 *                     A reference info buffer is filled with the next ref
 *                     info when ref_info_valid_in is asserted by the engine
 *                     controller. This allows the engine controller to send
 *                     the next alignment's ref info before the last alignment's
 *                     ref seq is fully read out, so that the next alignment's
 *                     DRAM reads can be queued before the start of the next
 *                     alignment.
 *
 *                     An FSM generates the DRAM read addresses, lengths, and IDs.
 *                     When the reference info buffer contains new ref info, the
 *                     FSM clears the buffer and begins sending DRAM read addresses
 *                     to the AXI bus arbiter starting with the address stored in
 *                     the ref info. It continues sending addresses until it hits
 *                     the reference length. While it sends addresses, the ref info
 *                     buffer can be filled with the next alignment's ref info.
 *
 *                     A small FIFO buffers the DRAM read data and generates the
 *                     handshaking signals with the engine.
 *          
 *
 *  Revision History :
 *      Albert Ng   Jul 10 2013     Initial Revision
 *      Albert Ng   Jul 11 2013     Fixed initial revision bugs
 *                                  Changed default ref length to 128
 *      Albert Ng   Aug 06 2013     Removed latches
 *      Albert Ng   Aug 07 2013     Changed address width to 33
 *      Albert Ng   Aug 09 2013     Changed ref_addr and ref_len to 28 bits
 *
 */
 
module ReferenceReader(
    input         clk,                    // System clock
    input         rst,                    // System reset
    
    // Engine controller interface
    input [27:0] ref_addr_in,             // DRAM starting address for reference sequence
    input [27:0] ref_length_in,           // Number of blocks in the reference sequence
    input        ref_info_valid_in,       // Reference sequence info output valid
    output [2*REF_LENGTH - 1:0] ref_seq_block_out, // Reference sequence block read from DRAM
    output       ref_seq_block_valid_out, // Reference sequence block input valid
    input        ref_seq_block_rdy_in,    // Reference sequence block input acknowledged
    
    // AXI bus arbiter interface
    output [C0_C_S_AXI_ID_WIDTH-5:0]   rd_id_out, // Read burst ID
    output [32:0]  rd_addr_out,         // Read burst address
    output [7:0]   rd_len_out,          // Read burst length (in terms of 256 bit blocks)
    output         rd_info_valid_out,   // Read info valid
    input          rd_info_rdy_in,      // Read request acknowledged 
    input  [255:0] rd_data_in,          // DRAM read data
    input          rd_data_valid_in,    // DRAM read data valid    
    output         rd_data_rdy_out      // DRAM read data acknowledged    
    );

    parameter C0_C_S_AXI_ID_WIDTH = 8;
    parameter REF_LENGTH = 128;
    
    // FSM states
    localparam WAIT_REF_INFO_VALID = 3'b001,
               SEND_RD_INFO        = 3'b010,
               WAIT_RD_INFO_RDY  = 3'b100;
    reg[2:0] state;
    reg[2:0] next_state;
    
    // Reference sequence block buffer signals
    wire [255:0] rsbb_din;
    wire rsbb_wr_en;
    wire rsbb_rd_en;
    wire [255:0] rsbb_dout;
    wire rsbb_full;
    wire rsbb_empty;

    reg [32:0] cur_addr;
    reg [32:0] next_cur_addr;
    reg [32:0] end_addr;
    reg [32:0] next_end_addr;
    reg [C0_C_S_AXI_ID_WIDTH-5:0] rd_id;
    reg [C0_C_S_AXI_ID_WIDTH-5:0] next_rd_id;
    reg rd_info_valid;
    
    // Reference info buffer
    reg [27:0] ref_addr_buf;
    reg [27:0] ref_length_buf;
    reg ref_info_valid;
    reg clear_ref_info_valid;
    
    // Reference info buffer
    always @(posedge clk) begin
        if (rst) begin
            ref_addr_buf <= 0;
            ref_length_buf <= 0;
            ref_info_valid <= 0;
        end else begin
            if (ref_info_valid_in) begin
                ref_addr_buf <= ref_addr_in;
                ref_length_buf <= ref_length_in;
                ref_info_valid <= 1;
            end else if (clear_ref_info_valid) begin
                ref_info_valid <= 0;
            end
        end
    end

    // AXI bus arbiter interface
    assign rd_id_out = rd_id;
    assign rd_addr_out = cur_addr;
    assign rd_len_out = 0;
    assign rd_info_valid_out = rd_info_valid;
    
    // Reference sequence buffer and associated logic
    ref_seq_block_buffer rsbb (
        .clk(clk),
        .rst(rst),
        .din(rsbb_din),
        .wr_en(rsbb_wr_en),
        .rd_en(rsbb_rd_en),
        .dout(rsbb_dout),
        .full(rsbb_full),
        .empty(rsbb_empty)
    );
    assign rsbb_wr_en = !rsbb_full & rd_data_valid_in;
    assign rsbb_din = rd_data_in;
    assign rd_data_rdy_out = rsbb_wr_en;
    assign ref_seq_block_valid_out = !rsbb_empty;
    assign rsbb_rd_en = ref_seq_block_rdy_in;
    assign ref_seq_block_out = rsbb_dout[2*REF_LENGTH - 1 : 0];
    
    // FSM
    always @(posedge clk) begin
        if (rst) begin
            state <= WAIT_REF_INFO_VALID;
            cur_addr <= 0;
            end_addr <= 0;
            rd_id <= 0;
        end else begin
            state <= next_state;
            cur_addr <= next_cur_addr;
            end_addr <= next_end_addr;
            rd_id <= next_rd_id;
        end
    end
    
    always @(*) begin
        case(state)
            WAIT_REF_INFO_VALID: begin
                if (ref_info_valid) begin
                    next_state = SEND_RD_INFO;
                end else begin
                    next_state = WAIT_REF_INFO_VALID;
                end
            end
            
            SEND_RD_INFO: begin
                if (!rd_info_rdy_in) begin
                    next_state = WAIT_RD_INFO_RDY;
                end else if (cur_addr != end_addr) begin
                    next_state = SEND_RD_INFO;
                end else begin
                    next_state = WAIT_REF_INFO_VALID;
                end
            end
            
            WAIT_RD_INFO_RDY: begin
                if (!rd_info_rdy_in) begin
                    next_state = WAIT_RD_INFO_RDY;
                end else if (cur_addr != end_addr) begin
                    next_state = SEND_RD_INFO;
                end else begin
                    next_state = WAIT_REF_INFO_VALID;
                end
            end
            
            default: begin  // Shouldn't get here
                next_state = WAIT_REF_INFO_VALID;
            end
        endcase
    end
    
    always @(*) begin
        case(state)
            WAIT_REF_INFO_VALID: begin
                next_cur_addr = {ref_addr_buf, 5'b0};
                next_end_addr = {ref_addr_buf + ref_length_buf - 1, 5'b0};
                if (ref_info_valid) begin
                    clear_ref_info_valid = 1;
                end else begin
                    clear_ref_info_valid = 0;
                end
                next_rd_id = rd_id;
                rd_info_valid = 0;
            end
            
            SEND_RD_INFO: begin
                if (rd_info_rdy_in) begin
                    next_cur_addr = cur_addr + 33'b100000;
                    next_rd_id = rd_id + 1;
                end else begin
                    next_cur_addr = cur_addr;
                    next_rd_id = rd_id;
                end
                next_end_addr = end_addr;
                clear_ref_info_valid = 0;
                rd_info_valid = 1;
            end
            
            WAIT_RD_INFO_RDY: begin
                next_end_addr = end_addr;
                clear_ref_info_valid = 0;
                rd_info_valid = 1;
                if (rd_info_rdy_in) begin
                    next_cur_addr = cur_addr + 33'b100000;
                    next_rd_id = rd_id + 1;
                end else begin
                    next_cur_addr = cur_addr;
                    next_rd_id = rd_id;
                end
            end
            
            default: begin  // Shouldn't get here
                next_cur_addr = 0;
                next_end_addr = 0;
                clear_ref_info_valid = 0;
                next_rd_id = rd_id;
                rd_info_valid = 0;
            end
        endcase
    end

endmodule
