/*  File Name        : SmithWatermanAccelerator.v
 *  Description      : User logic block in Pico framework for
 *                     Smith Waterman accelerator
 *
 *  Revision History :
 *      Albert Ng   Jul 31 2013     Initial Revision
 *      Albert Ng   Aug 06 2013     Finished initial revision w/ 1 arbiter, 1 engine
 */
 
`include "axi_defines.v" 
`include "PicoDefines.v"
 
module SmithWatermanAccelerator #(
    parameter C0_C_S_AXI_ID_WIDTH   = 8,
    parameter C0_C_S_AXI_ADDR_WIDTH = 32,
    parameter C0_C_S_AXI_DATA_WIDTH = 256
    )
    (
    
    //////////////////////
    // STREAM INTERFACE //
    //////////////////////
    input                           clk,      // stream clk
    input                           rst,      // synchronous reset for the stream clk
    input                           s1i_valid,
    input [`STREAM1_IN_WIDTH-1:0]   s1i_data,
    output                          s1i_rdy,
    output                          s1o_valid,
    output [`STREAM1_OUT_WIDTH-1:0] s1o_data,
    input                           s1o_rdy,
    
    ////////////////////
    // DDR3 INTERFACE //
    ////////////////////
    // Input control signals
    input                                  c0_axi_clk,        // AXI input clk
    input                                  c0_phy_init_done,  // Initialization completed
    input                                  c0_axi_rst,        // Active high AXI reset signal
    
    // AXI port 1
    output                                 c0_s1_axi_clk,     // Clock for master 1
    
    // AXI write address channel signals
    input                                  c0_s1_axi_awready, // Indicates slave is ready to accept a
    output [C0_C_S_AXI_ID_WIDTH-1:0]       c0_s1_axi_awid,    // Write address ID
    output reg [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s1_axi_awaddr,  // Write address, byte-addressable
    output reg [7:0]                       c0_s1_axi_awlen,   // Write burst length
    output [2:0]                           c0_s1_axi_awsize,  // Write burst size
    output [1:0]                           c0_s1_axi_awburst, // Write burst type
    output                                 c0_s1_axi_awlock,  // Write lock type
    output [3:0]                           c0_s1_axi_awcache, // Write cache type
    output [2:0]                           c0_s1_axi_awprot,  // Write protection type
    output [3:0]                           c0_s1_axi_awqos,   // Write quality of service signaling
    output reg                             c0_s1_axi_awvalid, // Write address valid
    
    // AXI write data channel signals
    input                                  c0_s1_axi_wready,  // Write data ready
    output [C0_C_S_AXI_DATA_WIDTH-1:0]     c0_s1_axi_wdata,   // Write data
    output [C0_C_S_AXI_DATA_WIDTH/8-1:0]   c0_s1_axi_wstrb,   // Write strobes
    output                                 c0_s1_axi_wlast,   // Last write transaction
    output                                 c0_s1_axi_wvalid,  // Write valid
    
    // AXI write response channel signals
    input [C0_C_S_AXI_ID_WIDTH-1:0]        c0_s1_axi_bid,     // Response ID
    input [1:0]                            c0_s1_axi_bresp,   // Write response
    input                                  c0_s1_axi_bvalid,  // Write response valid
    output                                 c0_s1_axi_bready,  // Response ready
    
    // AXI read address channel signals
    input                                  c0_s1_axi_arready, // Read address ready
    output [C0_C_S_AXI_ID_WIDTH-1:0]       c0_s1_axi_arid,    // Read ID
    output reg [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s1_axi_araddr,  // Read address, byte-addressable
    output reg [7:0]                       c0_s1_axi_arlen,   // Read burst length
    output [2:0]                           c0_s1_axi_arsize,  // Read burst size
    output [1:0]                           c0_s1_axi_arburst, // Read burst type
    output                                 c0_s1_axi_arlock,  // Read lock type
    output [3:0]                           c0_s1_axi_arcache, // Read cache type
    output [2:0]                           c0_s1_axi_arprot,  // Read protection type
    output reg                             c0_s1_axi_arvalid, // Read address valid
    output [3:0]                           c0_s1_axi_arqos,   // Read quality of service signaling
    
    // AXI read data channel signals
    input [C0_C_S_AXI_ID_WIDTH-1:0]        c0_s1_axi_rid,     // Response ID
    input [1:0]                            c0_s1_axi_rresp,   // Read response
    input                                  c0_s1_axi_rvalid,  // Read response valid
    input [C0_C_S_AXI_DATA_WIDTH-1:0]      c0_s1_axi_rdata,   // Read data
    input                                  c0_s1_axi_rlast,   // Read last
    output                                 c0_s1_axi_rready   // Read response ready
    );

    parameter NUM_PES = 64;
    parameter REF_LENGTH = 128;
    parameter WIDTH = 10;
    parameter MATCH_REWARD = 2;
    parameter MISMATCH_PEN = -2;
    parameter GAP_OPEN_PEN = -2;
    parameter GAP_EXTEND_PEN = -1;
    parameter PES_PER_FIFO = 4;   

    wire stream_clk;
    wire stream_rst;
    wire sys_clk; 
    reg sys_rst_q;
    reg sys_rst;
    wire locked;

    wire [3:0] active_ports;
    wire [5:0] rd_id_0;
    wire [31:0] rd_addr_0;
    wire [7:0] rd_len_0;
    wire rd_info_valid_0;
    wire rd_info_rdy_0;
    wire [255:0] rd_data_0;
    wire rd_data_valid_0;
    wire rd_data_rdy_0;
    
    // System clock and reset generation
    assign stream_clk = clk;
    assign stream_rst = rst;
    system_clk_gen scg (
        .CLK_IN1(stream_clk),
        .CLK_OUT1(sys_clk),
        .RESET(stream_rst),
        .LOCKED(locked)
    );
    always @(posedge sys_clk) begin
        sys_rst_q <= stream_rst;
        sys_rst   <= sys_rst_q;
    end 

    // Memory interface constants
    assign c0_s1_axi_awlock = `NORMAL_ACCESS;         // Write lock type
    assign c0_s1_axi_awcache = `NON_CACHE_NON_BUFFER; // Write cache type
    assign c0_s1_axi_awprot = `DATA_SECURE_NORMAL;    // Write protection type
    assign c0_s1_axi_awburst = `INCREMENTING;         // Address should increment
    assign c0_s1_axi_awqos = `NOT_QOS_PARTICIPANT;    // Not participating in QoS
    assign c0_s1_axi_awsize = `THIRTY_TWO_BYTES;      // # bytes per transfer
    assign c0_s1_axi_wstrb = ~0;                      // Byte write enable signals
    assign c0_s1_axi_arlock = `NORMAL_ACCESS;         // Read lock type
    assign c0_s1_axi_arcache = `NON_CACHE_NON_BUFFER; // Read cache type
    assign c0_s1_axi_arprot = `DATA_SECURE_NORMAL;    // Read protection type
    assign c0_s1_axi_arburst = `INCREMENTING;         // Address should increment
    assign c0_s1_axi_arqos = `NOT_QOS_PARTICIPANT;    // Not participating in QoS
    assign c0_s1_axi_arsize = `THIRTY_TWO_BYTES;      // # bytes per transfer

    // Unused memory interface outputs
    assign c0_s1_axi_awready = 0;
    assign c0_s1_axi_awid = 0;
    assign c0_s1_axi_awaddr = 0;
    assign c0_s1_axi_awlen = 0;
    assign c0_s1_axi_awvalid = 0;
    assign c0_s1_axi_wdata = 0;
    assign c0_s1_axi_wlast = 0;
    assign c0_s1_axi_wvalid = 0;
    assign c0_s1_axi_bready = 0;

    // AXI Arbiter unit
    assign active_ports = 4'b0001;
    AXIArbiter aa (
        .clk(sys_clk),
        .rst(sys_rst),
        .axi_clk_out(c0_s1_axi_clk),
        .axi_arready_in(c0_s1_axi_arready),
        .axi_arid_out(c0_s1_axi_arid),
        .axi_araddr_out(c0_s1_axi_araddr),
        .axi_arlen_out(c0_s1_axi_arlen),
        .axi_arvalid_out(c0_s1_axi_arvalid),
        .axi_rdata_in(c0_s1_axi_rdata),
        .axi_rready_out(c0_s1_axi_rready),
        .active_ports_in(active_ports),
        .rd_id_0_in(rd_id_0),
        .rd_addr_0_in(rd_addr_0),
        .rd_len_0_in(rd_len_0),
        .rd_info_valid_0_in(rd_info_valid_0),
        .rd_info_rdy_0_out(rd_info_rdy_0),
        .rd_data_0_out(rd_data_0),
        .rd_data_valid_0_out(rd_data_valid_0),
        .rd_data_rdy_0_in(rd_data_rdy_0)
    );
    
    // Engine unit
    Engine #(NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s1i_valid),
        .si_data_in(s1i_data),
        .si_rdy_out(s1i_rdy),
        .rd_id_out(rd_id_0),
        .rd_addr_out(rd_addr_0),
        .rd_len_out(rd_len_0),
        .rd_info_valid_out(rd_info_valid_0),
        .rd_info_rdy_in(rd_info_rdy_0),
        .rd_data_in(rd_data_0),
        .rd_data_valid_in(rd_data_valid_0),
        .rd_data_rdy_out(rd_data_rdy_0),
        .so_clk(stream_clk),
        .so_valid_out(s1o_valid),
        .so_data_out(s1o_data),
        .so_rdy_in(s1o_rdy)
    );
    
endmodule
