/*  File Name        : AXIArbiter.v
 *  Description      : AXI Bus Arbiter
 *
 *                     Arbitrates between the AXI bus port and 4 reference
 *                     reader ports.
 *
 *                     The arbiter round-robin selects the next port to service,
 *                     if any. When selecting a port, it connects the handshaking
 *                     lines between the AXI bus and the selected port, while
 *                     enqueueing the port number into an outstanding requests FIFO.
 *
 *                     When data is valid on the AXI data bus, the arbiter connects
 *                     the AXI bus handshaking lines to the port whos number is
 *                     indicated in the top bits of the rd_id of the AXI bus.
 *
 *  Revision History :
 *      Albert Ng   Aug 30 2013     Copied from unfair AXI Arbiter
 *
 */
 
module AXIArbiter2(
    input         clk,                   // System clock
    input         rst,                   // System reset
    
    // AXI Bus Interface
    output        axi_clk_out,           // AXI bus clock
    input         axi_arready_in,        // AXI bus address ready
    output [C0_C_S_AXI_ID_WIDTH-1:0] axi_arid_out, // AXI bus address request ID
    output [32:0] axi_araddr_out,        // AXI bus address
    output [7:0]  axi_arlen_out,         // AXI bus address read length    
    output        axi_arvalid_out,       // AXI bus address valid
    input [C0_C_S_AXI_ID_WIDTH-1:0] axi_rid_in,    // AXI bus read data request ID
    input         axi_rvalid_in,         // AXI bus read data valid
    input [255:0] axi_rdata_in,          // AXI bus read data
    output        axi_rready_out,        // AXI bus read data ready

    // Reference Reader 0
    input  [C0_C_S_AXI_ID_WIDTH-3:0]   rd_id_0_in, // Read burst ID
    input  [32:0]  rd_addr_0_in,         // Read burst address
    input  [7:0]   rd_len_0_in,          // Read burst length (in terms of 256 bit blocks)
    input          rd_info_valid_0_in,   // Read info valid
    output         rd_info_rdy_0_out,    // Read request acknowledged 
    output [255:0] rd_data_0_out,        // DRAM read data
    output         rd_data_valid_0_out,  // DRAM read data valid    
    input          rd_data_rdy_0_in,     // DRAM read data acknowledged  
    
    // Reference Reader 1
    input  [C0_C_S_AXI_ID_WIDTH-3:0]   rd_id_1_in, // Read burst ID
    input  [32:0]  rd_addr_1_in,         // Read burst address
    input  [7:0]   rd_len_1_in,          // Read burst length (in terms of 256 bit blocks)
    input          rd_info_valid_1_in,   // Read info valid
    output         rd_info_rdy_1_out,    // Read request acknowledged 
    output [255:0] rd_data_1_out,        // DRAM read data
    output         rd_data_valid_1_out,  // DRAM read data valid    
    input          rd_data_rdy_1_in,     // DRAM read data acknowledged  
    
    // Reference Reader 2
    input  [C0_C_S_AXI_ID_WIDTH-3:0]   rd_id_2_in, // Read burst ID
    input  [32:0]  rd_addr_2_in,         // Read burst address
    input  [7:0]   rd_len_2_in,          // Read burst length (in terms of 256 bit blocks)
    input          rd_info_valid_2_in,   // Read info valid
    output         rd_info_rdy_2_out,    // Read request acknowledged 
    output [255:0] rd_data_2_out,        // DRAM read data
    output         rd_data_valid_2_out,  // DRAM read data valid    
    input          rd_data_rdy_2_in,     // DRAM read data acknowledged  
    
    // Reference Reader 3
    input  [C0_C_S_AXI_ID_WIDTH-3:0]   rd_id_3_in, // Read burst ID
    input  [32:0]  rd_addr_3_in,         // Read burst address
    input  [7:0]   rd_len_3_in,          // Read burst length (in terms of 256 bit blocks)
    input          rd_info_valid_3_in,   // Read info valid
    output         rd_info_rdy_3_out,    // Read request acknowledged 
    output [255:0] rd_data_3_out,        // DRAM read data
    output         rd_data_valid_3_out,  // DRAM read data valid    
    input          rd_data_rdy_3_in      // DRAM read data acknowledged  
    );

    parameter C0_C_S_AXI_ID_WIDTH = 8;
    
    // FSM states
    localparam WAIT_PORT_VALID = 3'b001,
               CONNECT_PORT    = 3'b010;
    reg [2:0] state;
    reg [2:0] next_state;
    
    // Port select signals
    reg [3:0] cur_port;
    reg [3:0] next_port;
    reg disconnect_port;
    
    // AXI bus interface output signals
    reg [C0_C_S_AXI_ID_WIDTH-1:0]  axi_arid;
    reg [32:0] axi_araddr;
    reg [7:0]  axi_arlen;
    reg        axi_arvalid;
    reg        axi_rready;  

    // Reference reader output signals
    reg rd_info_rdy_0;
    reg rd_info_rdy_1;
    reg rd_info_rdy_2;
    reg rd_info_rdy_3;
    reg [255:0] rd_data_0;
    reg [255:0] rd_data_1;
    reg [255:0] rd_data_2;
    reg [255:0] rd_data_3;
    reg rd_data_valid_0;
    reg rd_data_valid_1;
    reg rd_data_valid_2;
    reg rd_data_valid_3;
    
    wire [3:0] rd_info_valids;
    
    // AXI bus interface
    assign axi_clk_out     = clk;
    assign axi_arid_out    = axi_arid;
    assign axi_araddr_out  = axi_araddr;
    assign axi_arlen_out   = axi_arlen;
    assign axi_arvalid_out = axi_arvalid;
    assign axi_rready_out  = axi_rready;
    
    // Reference reader interface
    assign rd_info_rdy_0_out = rd_info_rdy_0;
    assign rd_info_rdy_1_out = rd_info_rdy_1;
    assign rd_info_rdy_2_out = rd_info_rdy_2;
    assign rd_info_rdy_3_out = rd_info_rdy_3;
    assign rd_data_0_out = rd_data_0;
    assign rd_data_1_out = rd_data_1;
    assign rd_data_2_out = rd_data_2;
    assign rd_data_3_out = rd_data_3;
    assign rd_data_valid_0_out = rd_data_valid_0;
    assign rd_data_valid_1_out = rd_data_valid_1;
    assign rd_data_valid_2_out = rd_data_valid_2;
    assign rd_data_valid_3_out = rd_data_valid_3;

    // Read info valid signal rename
    assign rd_info_valids = {rd_info_valid_3_in, rd_info_valid_2_in, rd_info_valid_1_in, rd_info_valid_0_in};

    // Address handshake port connection
    always @(*) begin
        if (!disconnect_port) begin
            if (cur_port[0]) begin
                axi_arid[C0_C_S_AXI_ID_WIDTH-1 -: 2] = 2'b00;
                axi_arid[C0_C_S_AXI_ID_WIDTH-3:0] = rd_id_0_in;
                axi_araddr = rd_addr_0_in;
                axi_arlen = rd_len_0_in;
                axi_arvalid = rd_info_valid_0_in;
                rd_info_rdy_0 = axi_arready_in;
                rd_info_rdy_1 = 0;
                rd_info_rdy_2 = 0;
                rd_info_rdy_3 = 0;
            end else if (cur_port[1]) begin
                axi_arid[C0_C_S_AXI_ID_WIDTH-1 -: 2] = 2'b01;
                axi_arid[C0_C_S_AXI_ID_WIDTH-3:0] = rd_id_1_in;
                axi_araddr = rd_addr_1_in;
                axi_arlen = rd_len_1_in;
                axi_arvalid = rd_info_valid_1_in;
                rd_info_rdy_0 = 0;
                rd_info_rdy_1 = axi_arready_in;
                rd_info_rdy_2 = 0;
                rd_info_rdy_3 = 0;
            end else if (cur_port[2]) begin
                axi_arid[C0_C_S_AXI_ID_WIDTH-1 -: 2] = 2'b10;
                axi_arid[C0_C_S_AXI_ID_WIDTH-3:0] = rd_id_2_in;
                axi_araddr = rd_addr_2_in;
                axi_arlen = rd_len_2_in;
                axi_arvalid = rd_info_valid_2_in;
                rd_info_rdy_0 = 0;
                rd_info_rdy_1 = 0;
                rd_info_rdy_2 = axi_arready_in;
                rd_info_rdy_3 = 0;
            end else begin
                axi_arid[C0_C_S_AXI_ID_WIDTH-1 -: 2] = 2'b11;
                axi_arid[C0_C_S_AXI_ID_WIDTH-3:0] = rd_id_3_in;
                axi_araddr = rd_addr_3_in;
                axi_arlen = rd_len_3_in;
                axi_arvalid = rd_info_valid_3_in;
                rd_info_rdy_0 = 0;
                rd_info_rdy_1 = 0;
                rd_info_rdy_2 = 0;
                rd_info_rdy_3 = axi_arready_in;
            end
        end else begin
            axi_arid = 0;
            axi_araddr = 0;
            axi_arlen = 0;
            axi_arvalid = 0;
            rd_info_rdy_0 = 0;
            rd_info_rdy_1 = 0;
            rd_info_rdy_2 = 0;
            rd_info_rdy_3 = 0;
        end
    end
    
    // FSM
    always @(posedge clk) begin
        if (rst) begin
            state <= WAIT_PORT_VALID;
            cur_port <= 4'b0001;
        end else begin
            state <= next_state;
            cur_port <= next_port;
        end
    end
    always @(*) begin
        case(state)
            WAIT_PORT_VALID: begin
                if (|(rd_info_valids)) begin
                    next_state = CONNECT_PORT;
                end else begin
                    next_state = WAIT_PORT_VALID;
                end
            end
            
            CONNECT_PORT: begin
                // Handshake complete
                if (axi_arready_in) begin
                    // Still another port requesting
                    if (|((~cur_port) & rd_info_valids)) begin
                        next_state = CONNECT_PORT;
                    // No more ports requesting
                    end else begin
                        next_state = WAIT_PORT_VALID;
                    end
                // Handshake not yet complete
                end else begin
                    next_state = CONNECT_PORT;
                end
            end
        endcase
    end
    always @(*) begin
        case(state)
            WAIT_PORT_VALID: begin
                if (|({cur_port[0], cur_port[3], cur_port[2], cur_port[1]} & rd_info_valids)) begin
                    next_port = {cur_port[0], cur_port[3], cur_port[2], cur_port[1]};
                end else if (|({cur_port[1], cur_port[0], cur_port[3], cur_port[2]} & rd_info_valids)) begin
                    next_port = {cur_port[1], cur_port[0], cur_port[3], cur_port[2]};
                end else if (|({cur_port[2], cur_port[1], cur_port[0], cur_port[3]} & rd_info_valids)) begin
                    next_port = {cur_port[2], cur_port[1], cur_port[0], cur_port[3]};
                end else begin
                    next_port = cur_port;
                end
                disconnect_port = 1;
            end
            
            CONNECT_PORT: begin
                // Move to next requesting port when current handshake complete
                if ((|(cur_port & rd_info_valids)) & axi_arready_in) begin
                    if (|({cur_port[0], cur_port[3], cur_port[2], cur_port[1]} & rd_info_valids)) begin
                        next_port = {cur_port[0], cur_port[3], cur_port[2], cur_port[1]};
                    end else if (|({cur_port[1], cur_port[0], cur_port[3], cur_port[2]} & rd_info_valids)) begin
                        next_port = {cur_port[1], cur_port[0], cur_port[3], cur_port[2]};
                    end else if (|({cur_port[2], cur_port[1], cur_port[0], cur_port[3]} & rd_info_valids)) begin
                        next_port = {cur_port[2], cur_port[1], cur_port[0], cur_port[3]};
                    end else begin
                        next_port = cur_port;
                    end
                end else begin
                    next_port = cur_port;
                end
                disconnect_port = 0;
            end
        endcase
    end
        
    // Data handshaking
    always @(*) begin
        axi_rready = 0;
        rd_data_0 = axi_rdata_in;
        rd_data_1 = axi_rdata_in;
        rd_data_2 = axi_rdata_in;
        rd_data_3 = axi_rdata_in;
        
        if (axi_rid_in[C0_C_S_AXI_ID_WIDTH-1 -: 2] == 0) begin
            axi_rready = rd_data_rdy_0_in;
            rd_data_valid_0 = axi_rvalid_in;
            rd_data_valid_1 = 0;
            rd_data_valid_2 = 0;
            rd_data_valid_3 = 0;
        end else if (axi_rid_in[C0_C_S_AXI_ID_WIDTH-1 -: 2] == 1) begin
            axi_rready = rd_data_rdy_1_in;
            rd_data_valid_0 = 0;
            rd_data_valid_1 = axi_rvalid_in;
            rd_data_valid_2 = 0;
            rd_data_valid_3 = 0;
        end else if (axi_rid_in[C0_C_S_AXI_ID_WIDTH-1 -: 2] == 2) begin
            axi_rready = rd_data_rdy_2_in;
            rd_data_valid_0 = 0;
            rd_data_valid_1 = 0;
            rd_data_valid_2 = axi_rvalid_in;
            rd_data_valid_3 = 0;
        end else begin
            axi_rready = rd_data_rdy_3_in;
            rd_data_valid_0 = 0;
            rd_data_valid_1 = 0;
            rd_data_valid_2 = 0;
            rd_data_valid_3 = axi_rvalid_in;
        end
    end
endmodule
