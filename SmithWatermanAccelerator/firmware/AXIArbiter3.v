/*  File Name        : AXIArbiter.v
 *  Description      : AXI Bus Arbiter
 *
 *                     Arbitrates between the AXI bus port and a parameterized number
 *                     of reference reader ports.
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
 *      Albert Ng   Aug 31 2013     Copied from fair, 4-way AXI Arbiter
 *
 */
module AXIArbiter3 #(
    parameter NUM_PORTS = 4,
    parameter C0_C_S_AXI_ID_WIDTH = 8
    )
    (
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
    
    // Reference Reader Interfaces
    input [(C0_C_S_AXI_ID_WIDTH-4)*NUM_PORTS-1:0] rd_id_in,
    input [33*NUM_PORTS-1:0] rd_addr_in,
    input [8*NUM_PORTS-1:0] rd_len_in,
    input [NUM_PORTS-1:0] rd_info_valid_in,
    output [NUM_PORTS-1:0] rd_info_rdy_out,
    output [256*NUM_PORTS-1:0] rd_data_out,
    output [NUM_PORTS-1:0] rd_data_valid_out,
    input [NUM_PORTS-1:0] rd_data_rdy_in
    );

    // FSM states
    localparam WAIT_PORT_VALID = 2'b01,
               CONNECT_PORT    = 2'b10;
    reg [1:0] state;
    reg [1:0] next_state;
    
    // Port select signals
    reg [NUM_PORTS-1:0] cur_port;
    wire [2*NUM_PORTS-1:0] cur_port_double;
    reg [NUM_PORTS-1:0] next_port;
    reg disconnect_port;
    
    // AXI bus interface output signals
    wire [C0_C_S_AXI_ID_WIDTH-1:0]  axi_arid;
    wire [32:0] axi_araddr;
    wire [7:0]  axi_arlen;
    wire        axi_arvalid;
    wire        axi_rready;
    
    // Reference reader output signals
    wire [NUM_PORTS-1:0] rd_info_rdy;
    wire [256*NUM_PORTS-1:0] rd_data;
    wire [NUM_PORTS-1:0] rd_data_valid;
    
    // AXI bus interface intermediate signals
    wire [3:0] axi_arid_high_intermediate [NUM_PORTS-1:0];
    wire [C0_C_S_AXI_ID_WIDTH-5:0] axi_arid_low_intermediate [NUM_PORTS-1:0];
    wire [32:0] axi_araddr_intermediate [NUM_PORTS-1:0];
    wire [7:0] axi_arlen_intermediate [NUM_PORTS-1:0];
    wire axi_arvalid_intermediate [NUM_PORTS-1:0];
    wire axi_rready_intermediate [NUM_PORTS-1:0];

    // Next port logic signals
    wire [NUM_PORTS-1:0] cur_port_rotate [NUM_PORTS-1:0];
    wire [NUM_PORTS-1:0] cur_port_rotate_valid;
    wire [NUM_PORTS-1:0] port_selected;
    wire [NUM_PORTS-1:0] next_port_intermediate [NUM_PORTS-1:0];

    // AXI bus interface
    assign axi_clk_out     = clk;
    assign axi_arid_out    = axi_arid;
    assign axi_araddr_out  = axi_araddr;
    assign axi_arlen_out   = axi_arlen;
    assign axi_arvalid_out = axi_arvalid;
    assign axi_rready_out  = axi_rready;
    
    // Reference reader interface
    assign rd_info_rdy_out = rd_info_rdy;
    assign rd_data_out = rd_data;
    assign rd_data_valid_out = rd_data_valid;
    
    // Address handshake port connections
    genvar i;
    assign axi_arid_high_intermediate[0] = 0 & {4{cur_port[0]}};
    assign axi_arid_low_intermediate[0] = rd_id_in[C0_C_S_AXI_ID_WIDTH-5:0] & {(C0_C_S_AXI_ID_WIDTH-4){cur_port[0]}};
    assign axi_araddr_intermediate[0] = rd_addr_in[32:0] & {33{cur_port[0]}};
    assign axi_arlen_intermediate[0] = rd_len_in[7:0] & {8{cur_port[0]}};
    assign axi_arvalid_intermediate[0] = rd_info_valid_in[0] & cur_port[0];
    assign rd_info_rdy[0] = (!disconnect_port & cur_port[0]) ? axi_arready_in : 0;
    generate
        for (i=1; i<NUM_PORTS; i=i+1) begin: address_handshake_gen
            assign axi_arid_high_intermediate[i] = axi_arid_high_intermediate[i-1] |( i & {4{cur_port[i]}});
            assign axi_arid_low_intermediate[i] = axi_arid_low_intermediate[i-1] | (rd_id_in[(C0_C_S_AXI_ID_WIDTH-4)*(i+1)-1 -: (C0_C_S_AXI_ID_WIDTH-4)] & {(C0_C_S_AXI_ID_WIDTH-4){cur_port[i]}});
            assign axi_araddr_intermediate[i] = axi_araddr_intermediate[i-1] | (rd_addr_in[33*(i+1)-1 -: 33] & {33{cur_port[i]}});
            assign axi_arlen_intermediate[i] = axi_arlen_intermediate[i-1] | (rd_len_in[8*(i+1)-1 -: 8] & {8{cur_port[i]}});
            assign axi_arvalid_intermediate[i] = axi_arvalid_intermediate[i-1] | (rd_info_valid_in[i] & cur_port[i]);
            assign rd_info_rdy[i] = (!disconnect_port & cur_port[i]) ? axi_arready_in : 0;
        end
    endgenerate
    assign axi_arid[C0_C_S_AXI_ID_WIDTH-1 -: 4] = disconnect_port ? 0 : axi_arid_high_intermediate[NUM_PORTS-1];
    assign axi_arid[C0_C_S_AXI_ID_WIDTH-5:0] = disconnect_port ? 0 : axi_arid_low_intermediate[NUM_PORTS-1];
    assign axi_araddr = disconnect_port ? 0 : axi_araddr_intermediate[NUM_PORTS-1];
    assign axi_arlen = disconnect_port ? 0 : axi_arlen_intermediate[NUM_PORTS-1];
    assign axi_arvalid = disconnect_port ? 0 : axi_arvalid_intermediate[NUM_PORTS-1];

    // Data handshake port connections
    assign axi_rready_intermediate[0] = (axi_rid_in[C0_C_S_AXI_ID_WIDTH-1 -: 4] == 0) ? rd_data_rdy_in[0] : 0;
    assign rd_data_valid[0] = (axi_rid_in[C0_C_S_AXI_ID_WIDTH-1 -: 4] == 0) ? axi_rvalid_in : 0; 
    generate
        for (i = 1; i < NUM_PORTS; i = i + 1) begin: data_handshake_gen
            assign axi_rready_intermediate[i] = (axi_rid_in[C0_C_S_AXI_ID_WIDTH-1 -: 4] == i) ? rd_data_rdy_in[i] : axi_rready_intermediate[i-1];
            assign rd_data_valid[i] = (axi_rid_in[C0_C_S_AXI_ID_WIDTH-1 -: 4] == i) ? axi_rvalid_in : 0;
        end
    endgenerate
    assign axi_rready = axi_rready_intermediate[NUM_PORTS-1];
    generate
        for (i = 0; i < NUM_PORTS; i = i + 1) begin: rd_data_gen
            assign rd_data[256*(i+1)-1 -: 256] = axi_rdata_in;
        end
    endgenerate

    // Next port logic
    assign cur_port_double = {cur_port, cur_port};
    generate
        for (i = 0; i < NUM_PORTS; i = i + 1) begin: cur_port_rotate_gen
            assign cur_port_rotate[i] = cur_port_double[i + NUM_PORTS -: NUM_PORTS];
            //assign cur_port_rotate[i] = {cur_port[i:0], cur_port[NUM_PORTS-1 -: ]};
        end
    endgenerate
    generate
        for (i = 0; i < NUM_PORTS; i = i + 1) begin: cur_port_rotate_valid_gen
            assign cur_port_rotate_valid[i] = |(cur_port_rotate[i] & rd_info_valid_in);
        end
    endgenerate
    assign port_selected[0] = 0;
    generate
        for (i = 1; i < NUM_PORTS; i = i + 1) begin: port_select_gen
            assign port_selected[i] = port_selected[i-1] | cur_port_rotate_valid[i-1];
        end
    endgenerate
    assign next_port_intermediate[0] = cur_port_rotate_valid[0] ? cur_port_rotate[0] : 0;
    generate
        for (i = 1; i < NUM_PORTS; i = i + 1) begin: next_port_gen
            assign next_port_intermediate[i] = (cur_port_rotate_valid[i] & !port_selected[i]) ? cur_port_rotate[i] : next_port_intermediate[i-1];
        end
    endgenerate
    
    // FSM
    always @(posedge clk) begin
        if (rst) begin
            state <= WAIT_PORT_VALID;
            cur_port[0] <= 1;
            cur_port[NUM_PORTS-1:1] <= 0;
        end else begin
            state <= next_state;
            cur_port <= next_port;
        end
    end
    always @(*) begin
        case(state)
            WAIT_PORT_VALID: begin
                if (|(rd_info_valid_in)) begin
                    next_state = CONNECT_PORT;
                end else begin
                    next_state = WAIT_PORT_VALID;
                end
            end
            
            CONNECT_PORT: begin
                // Handshake complete
                if (axi_arready_in) begin
                    // Still another port requesting
                    if (|((~cur_port) & rd_info_valid_in)) begin
                        next_state = CONNECT_PORT;
                    // No more ports requesting
                    end else begin
                        next_state = WAIT_PORT_VALID;
                    end
                end else begin
                    next_state = CONNECT_PORT;
                end
             end
             
             default: begin     // Should never get here
                next_state = WAIT_PORT_VALID;
             end
         endcase
     end
     always @(*) begin
        case(state)
            WAIT_PORT_VALID: begin
                if (next_port_intermediate[NUM_PORTS-1] != 0) begin
                    next_port = next_port_intermediate[NUM_PORTS-1];
                end else begin
                    next_port = cur_port;
                end
                disconnect_port = 1;
            end
            
            CONNECT_PORT: begin
                if ((|(cur_port & rd_info_valid_in)) & axi_arready_in) begin
                    if (next_port_intermediate[NUM_PORTS-1] != 0) begin
                        next_port = next_port_intermediate[NUM_PORTS-1];
                    end else begin
                        next_port = cur_port;
                    end
                end else begin
                    next_port = cur_port;
                end
                disconnect_port = 0;
            end
            
            default: begin      // Should never get here
                next_port = cur_port;
                disconnect_port = 0;
            end
        endcase
    end
endmodule
