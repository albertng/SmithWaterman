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
 *      Albert Ng   Sep 02 2013     Copied from N-way fair AXI Arbiter
 *
 */
module AXIArbiter4 #(
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
    reg [NUM_PORTS-1:0] next_port;
    reg disconnect_port;
    wire [NUM_PORTS-1:0] cur_data_port;
    
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
    wire [4*NUM_PORTS-1:0] axi_arid_high_mux_din;
    wire [3:0] axi_arid_high_intermediate;
    wire [C0_C_S_AXI_ID_WIDTH-5:0] axi_arid_low_intermediate;
    wire [32:0] axi_araddr_intermediate;
    wire [7:0] axi_arlen_intermediate;
    wire axi_arvalid_intermediate;

    // Next port logic signals
    wire [2*NUM_PORTS-1:0] double_next_rd_info_valid;
    wire [2*NUM_PORTS-1:0] double_next_port_val;
    wire [NUM_PORTS-1:0] next_port_val;

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
    generate
        for (i = 0; i < NUM_PORTS; i = i + 1) begin: mux_din_gen
            assign axi_arid_high_mux_din[(i+1)*4-1 -: 4] = i;
        end
    endgenerate
    one_hot_mux #(NUM_PORTS, 4) axi_arid_high_mux (
        .data_in(axi_arid_high_mux_din),
        .select(cur_port),
        .data_out(axi_arid_high_intermediate)
    );
    one_hot_mux #(NUM_PORTS, C0_C_S_AXI_ID_WIDTH-4) axi_arid_low_mux (
        .data_in(rd_id_in),
        .select(cur_port),
        .data_out(axi_arid_low_intermediate)
    );
    one_hot_mux #(NUM_PORTS, 33) axi_araddr_mux (
        .data_in(rd_addr_in),
        .select(cur_port),
        .data_out(axi_araddr_intermediate)
    );
    one_hot_mux #(NUM_PORTS, 8) axi_arlen_mux (
        .data_in(rd_len_in),
        .select(cur_port),
        .data_out(axi_arlen_intermediate)
    );
    one_hot_mux #(NUM_PORTS, 1) axi_arvalid_mux (
        .data_in(rd_info_valid_in),
        .select(cur_port),
        .data_out(axi_arvalid_intermediate)
    );
    assign axi_arid[C0_C_S_AXI_ID_WIDTH-1 -: 4] = disconnect_port ? 0 : axi_arid_high_intermediate;
    assign axi_arid[C0_C_S_AXI_ID_WIDTH-5:0] = disconnect_port ? 0 : axi_arid_low_intermediate;
    assign axi_araddr = disconnect_port ? 0 : axi_araddr_intermediate;
    assign axi_arlen = disconnect_port ? 0 : axi_arlen_intermediate;
    assign axi_arvalid = disconnect_port ? 0 : axi_arvalid_intermediate;
    generate
        for (i = 0; i < NUM_PORTS; i = i + 1) begin: rd_info_rdy_gen
            assign rd_info_rdy[i] = (!disconnect_port & cur_port[i]) ? axi_arready_in : 0;
        end
    endgenerate

    // Data handshake port connections
    generate
        for (i = 0; i < NUM_PORTS; i = i + 1) begin: cur_data_port_gen
            assign cur_data_port[i] = axi_rid_in[C0_C_S_AXI_ID_WIDTH-1 -: 4] == i;
            assign rd_data_valid[i] = cur_data_port[i] ? axi_rvalid_in : 0;
            assign rd_data[256*(i+1)-1 -: 256] = axi_rdata_in;
        end
    endgenerate
    one_hot_mux #(NUM_PORTS, 1) axi_rready_mux (
        .data_in(rd_data_rdy_in),
        .select(cur_data_port),
        .data_out(axi_rready)
    );

    // Next port logic
    assign double_next_rd_info_valid = {rd_info_valid_in & ~cur_port, rd_info_valid_in & ~cur_port};
    assign double_next_port_val = double_next_rd_info_valid & ~(double_next_rd_info_valid - cur_port);
    assign next_port_val = double_next_port_val[NUM_PORTS-1:0] | double_next_port_val[2*NUM_PORTS-1:NUM_PORTS];
    
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
                if (next_port_val != 0) begin
                    next_port = next_port_val;
                end else begin
                    next_port = cur_port;
                end
                disconnect_port = 1;
            end
            
            CONNECT_PORT: begin
                if ((|(cur_port & rd_info_valid_in)) & axi_arready_in) begin
                    if (next_port_val != 0) begin
                        next_port = next_port_val;
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
