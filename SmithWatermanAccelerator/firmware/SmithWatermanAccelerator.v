/*  File Name        : SmithWatermanAccelerator.v
 *  Description      : User logic block in Pico framework for
 *                     Smith Waterman accelerator
 *
 *  Revision History :
 *      Albert Ng   Jul 31 2013     Initial Revision
 *      Albert Ng   Aug 06 2013     Finished initial revision w/ 1 arbiter, 1 engine
 *      Albert Ng   Aug 21 2013     Fixed sys_rst to hold for 100 sys_clks
 */
 
`include "axi_defines.v" 
`include "PicoDefines.v"
 
module SmithWatermanAccelerator #(
    parameter C0_C_S_AXI_ID_WIDTH   = 8,
    parameter C0_C_S_AXI_ADDR_WIDTH = 33,
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
    input                           s2i_valid,
    input [`STREAM2_IN_WIDTH-1:0]   s2i_data,
    output                          s2i_rdy,
    output                          s2o_valid,
    output [`STREAM2_OUT_WIDTH-1:0] s2o_data,
    input                           s2o_rdy,
    input                           s3i_valid,
    input [`STREAM3_IN_WIDTH-1:0]   s3i_data,
    output                          s3i_rdy,
    output                          s3o_valid,
    output [`STREAM3_OUT_WIDTH-1:0] s3o_data,
    input                           s3o_rdy,
    input                           s4i_valid,
    input [`STREAM4_IN_WIDTH-1:0]   s4i_data,
    output                          s4i_rdy,
    output                          s4o_valid,
    output [`STREAM4_OUT_WIDTH-1:0] s4o_data,
    input                           s4o_rdy,
    input                           s5i_valid,
    input [`STREAM5_IN_WIDTH-1:0]   s5i_data,
    output                          s5i_rdy,
    output                          s5o_valid,
    output [`STREAM5_OUT_WIDTH-1:0] s5o_data,
    input                           s5o_rdy,
    input                           s6i_valid,
    input [`STREAM6_IN_WIDTH-1:0]   s6i_data,
    output                          s6i_rdy,
    output                          s6o_valid,
    output [`STREAM6_OUT_WIDTH-1:0] s6o_data,
    input                           s6o_rdy,
    /*input                           s7i_valid,
    input [`STREAM7_IN_WIDTH-1:0]   s7i_data,
    output                          s7i_rdy,
    output                          s7o_valid,
    output [`STREAM7_OUT_WIDTH-1:0] s7o_data,
    input                           s7o_rdy,
    input                           s8i_valid,
    input [`STREAM8_IN_WIDTH-1:0]   s8i_data,
    output                          s8i_rdy,
    output                          s8o_valid,
    output [`STREAM8_OUT_WIDTH-1:0] s8o_data,
    input                           s8o_rdy,
    input                           s9i_valid,
    input [`STREAM9_IN_WIDTH-1:0]   s9i_data,
    output                          s9i_rdy,
    output                          s9o_valid,
    output [`STREAM9_OUT_WIDTH-1:0] s9o_data,
    input                           s9o_rdy,
    input                           s10i_valid,
    input [`STREAM10_IN_WIDTH-1:0]   s10i_data,
    output                          s10i_rdy,
    output                          s10o_valid,
    output [`STREAM10_OUT_WIDTH-1:0] s10o_data,
    input                           s10o_rdy,
    input                           s11i_valid,*/
/*    input [`STREAM11_IN_WIDTH-1:0]   s11i_data,
    output                          s11i_rdy,
    output                          s11o_valid,
    output [`STREAM11_OUT_WIDTH-1:0] s11o_data,
    input                           s11o_rdy,*/

    
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
    
    // AXI port 2
    /*output                                 c0_s2_axi_clk,     // Clock for master 2
    
    // AXI write address channel signals
    input                                  c0_s2_axi_awready, // Indicates slave is ready to accept a
    output [C0_C_S_AXI_ID_WIDTH-1:0]       c0_s2_axi_awid,    // Write address ID
    output reg [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s2_axi_awaddr,  // Write address, byte-addressable
    output reg [7:0]                       c0_s2_axi_awlen,   // Write burst length
    output [2:0]                           c0_s2_axi_awsize,  // Write burst size
    output [1:0]                           c0_s2_axi_awburst, // Write burst type
    output                                 c0_s2_axi_awlock,  // Write lock type
    output [3:0]                           c0_s2_axi_awcache, // Write cache type
    output [2:0]                           c0_s2_axi_awprot,  // Write protection type
    output [3:0]                           c0_s2_axi_awqos,   // Write quality of service signaling
    output reg                             c0_s2_axi_awvalid, // Write address valid
    
    // AXI write data channel signals
    input                                  c0_s2_axi_wready,  // Write data ready
    output [C0_C_S_AXI_DATA_WIDTH-1:0]     c0_s2_axi_wdata,   // Write data
    output [C0_C_S_AXI_DATA_WIDTH/8-1:0]   c0_s2_axi_wstrb,   // Write strobes
    output                                 c0_s2_axi_wlast,   // Last write transaction
    output                                 c0_s2_axi_wvalid,  // Write valid
    
    // AXI write response channel signals
    input [C0_C_S_AXI_ID_WIDTH-1:0]        c0_s2_axi_bid,     // Response ID
    input [1:0]                            c0_s2_axi_bresp,   // Write response
    input                                  c0_s2_axi_bvalid,  // Write response valid
    output                                 c0_s2_axi_bready,  // Response ready
    
    // AXI read address channel signals
    input                                  c0_s2_axi_arready, // Read address ready
    output [C0_C_S_AXI_ID_WIDTH-1:0]       c0_s2_axi_arid,    // Read ID
    output reg [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s2_axi_araddr,  // Read address, byte-addressable
    output reg [7:0]                       c0_s2_axi_arlen,   // Read burst length
    output [2:0]                           c0_s2_axi_arsize,  // Read burst size
    output [1:0]                           c0_s2_axi_arburst, // Read burst type
    output                                 c0_s2_axi_arlock,  // Read lock type
    output [3:0]                           c0_s2_axi_arcache, // Read cache type
    output [2:0]                           c0_s2_axi_arprot,  // Read protection type
    output reg                             c0_s2_axi_arvalid, // Read address valid
    output [3:0]                           c0_s2_axi_arqos,   // Read quality of service signaling
    
    // AXI read data channel signals
    input [C0_C_S_AXI_ID_WIDTH-1:0]        c0_s2_axi_rid,     // Response ID
    input [1:0]                            c0_s2_axi_rresp,   // Read response
    input                                  c0_s2_axi_rvalid,  // Read response valid
    input [C0_C_S_AXI_DATA_WIDTH-1:0]      c0_s2_axi_rdata,   // Read data
    input                                  c0_s2_axi_rlast,   // Read last
    output                                 c0_s2_axi_rready,  // Read response ready
    
    // AXI port 3
    output                                 c0_s3_axi_clk,     // Clock for master 3
    
    // AXI write address channel signals
    input                                  c0_s3_axi_awready, // Indicates slave is ready to accept a
    output [C0_C_S_AXI_ID_WIDTH-1:0]       c0_s3_axi_awid,    // Write address ID
    output reg [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s3_axi_awaddr,  // Write address, byte-addressable
    output reg [7:0]                       c0_s3_axi_awlen,   // Write burst length
    output [2:0]                           c0_s3_axi_awsize,  // Write burst size
    output [1:0]                           c0_s3_axi_awburst, // Write burst type
    output                                 c0_s3_axi_awlock,  // Write lock type
    output [3:0]                           c0_s3_axi_awcache, // Write cache type
    output [2:0]                           c0_s3_axi_awprot,  // Write protection type
    output [3:0]                           c0_s3_axi_awqos,   // Write quality of service signaling
    output reg                             c0_s3_axi_awvalid, // Write address valid
    
    // AXI write data channel signals
    input                                  c0_s3_axi_wready,  // Write data ready
    output [C0_C_S_AXI_DATA_WIDTH-1:0]     c0_s3_axi_wdata,   // Write data
    output [C0_C_S_AXI_DATA_WIDTH/8-1:0]   c0_s3_axi_wstrb,   // Write strobes
    output                                 c0_s3_axi_wlast,   // Last write transaction
    output                                 c0_s3_axi_wvalid,  // Write valid
    
    // AXI write response channel signals
    input [C0_C_S_AXI_ID_WIDTH-1:0]        c0_s3_axi_bid,     // Response ID
    input [1:0]                            c0_s3_axi_bresp,   // Write response
    input                                  c0_s3_axi_bvalid,  // Write response valid
    output                                 c0_s3_axi_bready,  // Response ready
    
    // AXI read address channel signals
    input                                  c0_s3_axi_arready, // Read address ready
    output [C0_C_S_AXI_ID_WIDTH-1:0]       c0_s3_axi_arid,    // Read ID
    output reg [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s3_axi_araddr,  // Read address, byte-addressable
    output reg [7:0]                       c0_s3_axi_arlen,   // Read burst length
    output [2:0]                           c0_s3_axi_arsize,  // Read burst size
    output [1:0]                           c0_s3_axi_arburst, // Read burst type
    output                                 c0_s3_axi_arlock,  // Read lock type
    output [3:0]                           c0_s3_axi_arcache, // Read cache type
    output [2:0]                           c0_s3_axi_arprot,  // Read protection type
    output reg                             c0_s3_axi_arvalid, // Read address valid
    output [3:0]                           c0_s3_axi_arqos,   // Read quality of service signaling
   
    // AXI read data channel signals
    input [C0_C_S_AXI_ID_WIDTH-1:0]        c0_s3_axi_rid,     // Response ID
    input [1:0]                            c0_s3_axi_rresp,   // Read response
    input                                  c0_s3_axi_rvalid,  // Read response valid
    input [C0_C_S_AXI_DATA_WIDTH-1:0]      c0_s3_axi_rdata,   // Read data
    input                                  c0_s3_axi_rlast,   // Read last
    output                                 c0_s3_axi_rready   // Read response ready*/
    );

    localparam NUM_PES = 64;
    localparam REF_LENGTH = 128;
    //localparam WIDTH = 10;
    localparam WIDTH = 18;
    localparam MATCH_REWARD = 2;
    localparam MISMATCH_PEN = -2;
    localparam GAP_OPEN_PEN = -2;
    localparam GAP_EXTEND_PEN = -1;
    localparam PES_PER_FIFO = 4;   
    localparam NUM_ENGINES = 6;
    //localparam NUM_ENGINES = 10;
    //localparam NUM_ENGINES = 2;

    wire [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s1_axi_araddr_net;
    wire [7:0] c0_s1_axi_arlen_net;
    wire c0_s1_axi_arvalid_net;
    /*wire [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s2_axi_araddr_net;
    wire [7:0] c0_s2_axi_arlen_net;
    wire c0_s2_axi_arvalid_net;
    wire [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s3_axi_araddr_net;
    wire [7:0] c0_s3_axi_arlen_net;
    wire c0_s3_axi_arvalid_net;*/
    
    wire stream_clk;
    wire stream_rst;
    wire sys_clk; 
    reg sys_rst;
    reg [7:0] sys_rst_cnt;
    wire locked;
    
    wire si_valid[NUM_ENGINES-1:0];
    wire [`STREAM1_IN_WIDTH-1:0] si_data[NUM_ENGINES-1:0];
    wire si_rdy[NUM_ENGINES-1:0];
    wire so_valid[NUM_ENGINES-1:0];
    wire [`STREAM1_IN_WIDTH-1:0] so_data[NUM_ENGINES-1:0];
    wire so_rdy[NUM_ENGINES-1:0];

    wire [(C0_C_S_AXI_ID_WIDTH-4)*NUM_ENGINES-1:0] rd_id;
    wire [33*NUM_ENGINES-1:0] rd_addr;
    wire [8*NUM_ENGINES-1:0] rd_len;
    wire [NUM_ENGINES-1:0] rd_info_valid;
    wire [NUM_ENGINES-1:0] rd_info_rdy;
    wire [256*NUM_ENGINES-1:0] rd_data;
    wire [NUM_ENGINES-1:0] rd_data_valid;
    wire [NUM_ENGINES-1:0] rd_data_rdy;

    
    // Dummy DRAM signals
    /*wire axi0_clk;
    wire axi0_arready;
    wire [7:0]   axi0_arid;
    wire [32:0]  axi0_araddr;
    wire [7:0]   axi0_arlen;
    wire         axi0_arvalid;
    wire [7:0]   axi0_rid;
    wire         axi0_rvalid;
    wire [255:0] axi0_rdata;
    wire         axi0_rready;
    wire axi1_clk;
    wire axi1_arready;
    wire [7:0]   axi1_arid;
    wire [32:0]  axi1_araddr;
    wire [7:0]   axi1_arlen;
    wire         axi1_arvalid;
    wire [7:0]   axi1_rid;
    wire         axi1_rvalid;
    wire [255:0] axi1_rdata;
    wire         axi1_rready;
    wire axi2_clk;
    wire axi2_arready;
    wire [7:0]   axi2_arid;
    wire [32:0]  axi2_araddr;
    wire [7:0]   axi2_arlen;
    wire         axi2_arvalid;
    wire [7:0]   axi2_rid;
    wire         axi2_rvalid;
    wire [255:0] axi2_rdata;
    wire         axi2_rready;*/
    
    // System clock and reset generation
    assign stream_clk = clk;
    assign stream_rst = rst;
    system_clk_gen scg (
        .CLK_IN1(stream_clk),
        .CLK_OUT1(sys_clk),
        .RESET(stream_rst),
        .LOCKED(locked)
    );
    always @(posedge sys_clk or posedge stream_rst) begin
        if (stream_rst) begin
            sys_rst <= 1;
            sys_rst_cnt <= 0;
        end else begin
            if (sys_rst_cnt <= 100) begin
                sys_rst_cnt <= sys_rst_cnt + 1;
                sys_rst <= 1;
            end else begin
                sys_rst <= 0;
            end
        end
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
    /*assign c0_s2_axi_awlock = `NORMAL_ACCESS;         // Write lock type
    assign c0_s2_axi_awcache = `NON_CACHE_NON_BUFFER; // Write cache type
    assign c0_s2_axi_awprot = `DATA_SECURE_NORMAL;    // Write protection type
    assign c0_s2_axi_awburst = `INCREMENTING;         // Address should increment
    assign c0_s2_axi_awqos = `NOT_QOS_PARTICIPANT;    // Not participating in QoS
    assign c0_s2_axi_awsize = `THIRTY_TWO_BYTES;      // # bytes per transfer
    assign c0_s2_axi_wstrb = ~0;                      // Byte write enable signals
    assign c0_s2_axi_arlock = `NORMAL_ACCESS;         // Read lock type
    assign c0_s2_axi_arcache = `NON_CACHE_NON_BUFFER; // Read cache type
    assign c0_s2_axi_arprot = `DATA_SECURE_NORMAL;    // Read protection type
    assign c0_s2_axi_arburst = `INCREMENTING;         // Address should increment
    assign c0_s2_axi_arqos = `NOT_QOS_PARTICIPANT;    // Not participating in QoS
    assign c0_s2_axi_arsize = `THIRTY_TWO_BYTES;      // # bytes per transfer
    assign c0_s3_axi_awlock = `NORMAL_ACCESS;         // Write lock type
    assign c0_s3_axi_awcache = `NON_CACHE_NON_BUFFER; // Write cache type
    assign c0_s3_axi_awprot = `DATA_SECURE_NORMAL;    // Write protection type
    assign c0_s3_axi_awburst = `INCREMENTING;         // Address should increment
    assign c0_s3_axi_awqos = `NOT_QOS_PARTICIPANT;    // Not participating in QoS
    assign c0_s3_axi_awsize = `THIRTY_TWO_BYTES;      // # bytes per transfer
    assign c0_s3_axi_wstrb = ~0;                      // Byte write enable signals
    assign c0_s3_axi_arlock = `NORMAL_ACCESS;         // Read lock type
    assign c0_s3_axi_arcache = `NON_CACHE_NON_BUFFER; // Read cache type
    assign c0_s3_axi_arprot = `DATA_SECURE_NORMAL;    // Read protection type
    assign c0_s3_axi_arburst = `INCREMENTING;         // Address should increment
    assign c0_s3_axi_arqos = `NOT_QOS_PARTICIPANT;    // Not participating in QoS
    assign c0_s3_axi_arsize = `THIRTY_TWO_BYTES;      // # bytes per transfer2*/
    
    // Unused memory interface output
    assign c0_s1_axi_awready = 0;
    assign c0_s1_axi_awid = 0;
    always @(*) begin
        c0_s1_axi_awaddr = 0;
        c0_s1_axi_awlen = 0;
        c0_s1_axi_awvalid = 0;
    end
    assign c0_s1_axi_wdata = 0;
    assign c0_s1_axi_wlast = 0;
    assign c0_s1_axi_wvalid = 0;
    assign c0_s1_axi_bready = 0;
    /*assign c0_s2_axi_awready = 0;
    assign c0_s2_axi_awid = 0;
    always @(*) begin
        c0_s2_axi_awaddr = 0;
        c0_s2_axi_awlen = 0;
        c0_s2_axi_awvalid = 0;
    end
    assign c0_s2_axi_wdata = 0;
    assign c0_s2_axi_wlast = 0;
    assign c0_s2_axi_wvalid = 0;
    assign c0_s2_axi_bready = 0;
    assign c0_s3_axi_awready = 0;
    assign c0_s3_axi_awid = 0;
    always @(*) begin
        c0_s3_axi_awaddr = 0;
        c0_s3_axi_awlen = 0;
        c0_s3_axi_awvalid = 0;
    end
    assign c0_s3_axi_wdata = 0;
    assign c0_s3_axi_wlast = 0;
    assign c0_s3_axi_wvalid = 0;
    assign c0_s3_axi_bready = 0;*/

    // Dummy DRAM
    /*Dummy_DRAM dd (
        .clk(sys_clk),
        .rst(sys_rst),
        .axi0_clk_in(axi0_clk),
        .axi0_arready_out(axi0_arready),
        .axi0_arid_in(axi0_arid),
        .axi0_araddr_in(axi0_araddr),
        .axi0_arlen_in(axi0_arlen),
        .axi0_arvalid_in(axi0_arvalid),
        .axi0_rid_out(axi0_rid),
        .axi0_rvalid_out(axi0_rvalid),
        .axi0_rdata_out(axi0_rdata),
        .axi0_rready_in(axi0_rready),
        .axi1_clk_in(axi1_clk),
        .axi1_arready_out(axi1_arready),
        .axi1_arid_in(axi1_arid),
        .axi1_araddr_in(axi1_araddr),
        .axi1_arlen_in(axi1_arlen),
        .axi1_arvalid_in(axi1_arvalid),
        .axi1_rid_out(axi1_rid),
        .axi1_rvalid_out(axi1_rvalid),
        .axi1_rdata_out(axi1_rdata),
        .axi1_rready_in(axi1_rready),
        .axi2_clk_in(axi2_clk),
        .axi2_arready_out(axi2_arready),
        .axi2_arid_in(axi2_arid),
        .axi2_araddr_in(axi2_araddr),
        .axi2_arlen_in(axi2_arlen),
        .axi2_arvalid_in(axi2_arvalid),
        .axi2_rid_out(axi2_rid),
        .axi2_rvalid_out(axi2_rvalid),
        .axi2_rdata_out(axi2_rdata),
        .axi2_rready_in(axi2_rready)
    );*/

    AXIArbiter4 #(NUM_ENGINES, C0_C_S_AXI_ID_WIDTH) aa (
        .clk(sys_clk),
        .rst(sys_rst),
        .axi_clk_out(c0_s1_axi_clk),
        .axi_arready_in(c0_s1_axi_arready),
        .axi_arid_out(c0_s1_axi_arid),
        .axi_araddr_out(c0_s1_axi_araddr_net),
        .axi_arlen_out(c0_s1_axi_arlen_net),
        .axi_arvalid_out(c0_s1_axi_arvalid_net),
        .axi_rid_in(c0_s1_axi_rid),
        .axi_rvalid_in(c0_s1_axi_rvalid),
        .axi_rdata_in(c0_s1_axi_rdata),
        .axi_rready_out(c0_s1_axi_rready),
        /*.axi_clk_out(axi0_clk),
        .axi_arready_in(axi0_arready),
        .axi_arid_out(axi0_arid),
        .axi_araddr_out(axi0_araddr),
        .axi_arlen_out(axi0_arlen),
        .axi_arvalid_out(axi0_arvalid),
        .axi_rid_in(axi0_rid),
        .axi_rvalid_in(axi0_rvalid),
        .axi_rdata_in(axi0_rdata),
        .axi_rready_out(axi0_rready),*/
        .rd_id_in(rd_id),
        .rd_addr_in(rd_addr),
        .rd_len_in(rd_len),
        .rd_info_valid_in(rd_info_valid),
        .rd_info_rdy_out(rd_info_rdy),
        .rd_data_out(rd_data),
        .rd_data_valid_out(rd_data_valid),
        .rd_data_rdy_in(rd_data_rdy)
    );
    always @(*) begin
        c0_s1_axi_araddr = c0_s1_axi_araddr_net;
        c0_s1_axi_arlen = c0_s1_axi_arlen_net;
        c0_s1_axi_arvalid = c0_s1_axi_arvalid_net;
    end
    
    assign si_valid[0] = s1i_valid;
    assign si_data[0] = s1i_data;
    assign s1i_rdy = si_rdy[0];
    assign s1o_valid = so_valid[0];
    assign s1o_data = so_data[0];
    assign so_rdy[0] = s1o_rdy;
    assign si_valid[1] = s2i_valid;
    assign si_data[1] = s2i_data;
    assign s2i_rdy = si_rdy[1];
    assign s2o_valid = so_valid[1];
    assign s2o_data = so_data[1];
    assign so_rdy[1] = s2o_rdy;
    assign si_valid[2] = s3i_valid;
    assign si_data[2] = s3i_data;
    assign s3i_rdy = si_rdy[2];
    assign s3o_valid = so_valid[2];
    assign s3o_data = so_data[2];
    assign so_rdy[2] = s3o_rdy;
    assign si_valid[3] = s4i_valid;
    assign si_data[3] = s4i_data;
    assign s4i_rdy = si_rdy[3];
    assign s4o_valid = so_valid[3];
    assign s4o_data = so_data[3];
    assign so_rdy[3] = s4o_rdy;
    assign si_valid[4] = s5i_valid;
    assign si_data[4] = s5i_data;
    assign s5i_rdy = si_rdy[4];
    assign s5o_valid = so_valid[4];
    assign s5o_data = so_data[4];
    assign so_rdy[4] = s5o_rdy;
    assign si_valid[5] = s6i_valid;
    assign si_data[5] = s6i_data;
    assign s6i_rdy = si_rdy[5];
    assign s6o_valid = so_valid[5];
    assign s6o_data = so_data[5];
    assign so_rdy[5] = s6o_rdy;
    /*assign si_valid[6] = s7i_valid;
    assign si_data[6] = s7i_data;
    assign s7i_rdy = si_rdy[6];
    assign s7o_valid = so_valid[6];
    assign s7o_data = so_data[6];
    assign so_rdy[6] = s7o_rdy;
    assign si_valid[7] = s8i_valid;
    assign si_data[7] = s8i_data;
    assign s8i_rdy = si_rdy[7];
    assign s8o_valid = so_valid[7];
    assign s8o_data = so_data[7];
    assign so_rdy[7] = s8o_rdy;
    assign si_valid[8] = s9i_valid;
    assign si_data[8] = s9i_data;
    assign s9i_rdy = si_rdy[8];
    assign s9o_valid = so_valid[8];
    assign s9o_data = so_data[8];
    assign so_rdy[8] = s9o_rdy;
    assign si_valid[9] = s10i_valid;
    assign si_data[9] = s10i_data;
    assign s10i_rdy = si_rdy[9];
    assign s10o_valid = so_valid[9];
    assign s10o_data = so_data[9];
    assign so_rdy[9] = s10o_rdy;*/
    /*assign si_valid[10] = s11i_valid;
    assign si_data[10] = s11i_data;
    assign s11i_rdy = si_rdy[10];
    assign s11o_valid = so_valid[10];
    assign s11o_data = so_data[10];
    assign so_rdy[10] = s11o_rdy;*/
    genvar i;
    generate
        for (i = 0; i < NUM_ENGINES; i = i + 1) begin: engine_gen
            Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng0 (
                .clk(sys_clk),
                .rst(sys_rst),
                .si_clk(stream_clk),
                .si_valid_in(si_valid[i]),
                .si_data_in(si_data[i]),
                .si_rdy_out(si_rdy[i]),
                /*.rd_id_out(rd_id0_0),
                .rd_addr_out(rd_addr0_0),
                .rd_len_out(rd_len0_0),
                .rd_info_valid_out(rd_info_valid0_0),
                .rd_info_rdy_in(rd_info_rdy0_0),
                .rd_data_in(rd_data0_0),
                .rd_data_valid_in(rd_data_valid0_0),
                .rd_data_rdy_out(rd_data_rdy0_0),*/
                .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(i+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*i]),
                .rd_addr_out(rd_addr[33*(i+1)-1:33*i]),
                .rd_len_out(rd_len[8*(i+1)-1:8*i]),
                .rd_info_valid_out(rd_info_valid[i]),
                .rd_info_rdy_in(rd_info_rdy[i]),
                .rd_data_in(rd_data[256*(i+1)-1:256*i]),
                .rd_data_valid_in(rd_data_valid[i]),
                .rd_data_rdy_out(rd_data_rdy[i]),
                .so_clk(stream_clk),
                .so_valid_out(so_valid[i]),
                .so_data_out(so_data[i]),
                .so_rdy_in(so_rdy[i])
            );
        end
    endgenerate

    
    // Engine unit 0
    /*Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng0 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s1i_valid),
        .si_data_in(s1i_data),
        .si_rdy_out(s1i_rdy),
        .rd_id_out(rd_id0_0),
        .rd_addr_out(rd_addr0_0),
        .rd_len_out(rd_len0_0),
        .rd_info_valid_out(rd_info_valid0_0),
        .rd_info_rdy_in(rd_info_rdy0_0),
        .rd_data_in(rd_data0_0),
        .rd_data_valid_in(rd_data_valid0_0),
        .rd_data_rdy_out(rd_data_rdy0_0),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(0+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*0]),
        .rd_addr_out(rd_addr[33*(0+1)-1:33*0]),
        .rd_len_out(rd_len[8*(0+1)-1:8*0]),
        .rd_info_valid_out(rd_info_valid[0]),
        .rd_info_rdy_in(rd_info_rdy[0]),
        .rd_data_in(rd_data[256*(0+1)-1:256*0]),
        .rd_data_valid_in(rd_data_valid[0]),
        .rd_data_rdy_out(rd_data_rdy[0]),
        .so_clk(stream_clk),
        .so_valid_out(s1o_valid),
        .so_data_out(s1o_data),
        .so_rdy_in(s1o_rdy)
    );
    
    // Engine unit 1
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng1 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s2i_valid),
        .si_data_in(s2i_data),
        .si_rdy_out(s2i_rdy),
        .rd_id_out(rd_id0_1),
        .rd_addr_out(rd_addr0_1),
        .rd_len_out(rd_len0_1),
        .rd_info_valid_out(rd_info_valid0_1),
        .rd_info_rdy_in(rd_info_rdy0_1),
        .rd_data_in(rd_data0_1),
        .rd_data_valid_in(rd_data_valid0_1),
        .rd_data_rdy_out(rd_data_rdy0_1),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(1+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*1]),
        .rd_addr_out(rd_addr[33*(1+1)-1:33*1]),
        .rd_len_out(rd_len[8*(1+1)-1:8*1]),
        .rd_info_valid_out(rd_info_valid[1]),
        .rd_info_rdy_in(rd_info_rdy[1]),
        .rd_data_in(rd_data[256*(1+1)-1:256*1]),
        .rd_data_valid_in(rd_data_valid[1]),
        .rd_data_rdy_out(rd_data_rdy[1]),
        .so_clk(stream_clk),
        .so_valid_out(s2o_valid),
        .so_data_out(s2o_data),
        .so_rdy_in(s2o_rdy)
    );
    
    // Engine unit 2
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng2 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s3i_valid),
        .si_data_in(s3i_data),
        .si_rdy_out(s3i_rdy),
        .rd_id_out(rd_id0_2),
        .rd_addr_out(rd_addr0_2),
        .rd_len_out(rd_len0_2),
        .rd_info_valid_out(rd_info_valid0_2),
        .rd_info_rdy_in(rd_info_rdy0_2),
        .rd_data_in(rd_data0_2),
        .rd_data_valid_in(rd_data_valid0_2),
        .rd_data_rdy_out(rd_data_rdy0_2),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(2+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*2]),
        .rd_addr_out(rd_addr[33*(2+1)-1:33*2]),
        .rd_len_out(rd_len[8*(2+1)-1:8*2]),
        .rd_info_valid_out(rd_info_valid[2]),
        .rd_info_rdy_in(rd_info_rdy[2]),
        .rd_data_in(rd_data[256*(2+1)-1:256*2]),
        .rd_data_valid_in(rd_data_valid[2]),
        .rd_data_rdy_out(rd_data_rdy[2]),
        .so_clk(stream_clk),
        .so_valid_out(s3o_valid),
        .so_data_out(s3o_data),
        .so_rdy_in(s3o_rdy)
    );
    
    // Engine unit 3
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng3 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s4i_valid),
        .si_data_in(s4i_data),
        .si_rdy_out(s4i_rdy),
        .rd_id_out(rd_id0_3),
        .rd_addr_out(rd_addr0_3),
        .rd_len_out(rd_len0_3),
        .rd_info_valid_out(rd_info_valid0_3),
        .rd_info_rdy_in(rd_info_rdy0_3),
        .rd_data_in(rd_data0_3),
        .rd_data_valid_in(rd_data_valid0_3),
        .rd_data_rdy_out(rd_data_rdy0_3),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(3+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*3]),
        .rd_addr_out(rd_addr[33*(3+1)-1:33*3]),
        .rd_len_out(rd_len[8*(3+1)-1:8*3]),
        .rd_info_valid_out(rd_info_valid[3]),
        .rd_info_rdy_in(rd_info_rdy[3]),
        .rd_data_in(rd_data[256*(3+1)-1:256*3]),
        .rd_data_valid_in(rd_data_valid[3]),
        .rd_data_rdy_out(rd_data_rdy[3]),
        .so_clk(stream_clk),
        .so_valid_out(s4o_valid),
        .so_data_out(s4o_data),
        .so_rdy_in(s4o_rdy)
    );
    
    // Engine unit 4
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng4 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s5i_valid),
        .si_data_in(s5i_data),
        .si_rdy_out(s5i_rdy),
        .rd_id_out(rd_id1_0),
        .rd_addr_out(rd_addr1_0),
        .rd_len_out(rd_len1_0),
        .rd_info_valid_out(rd_info_valid1_0),
        .rd_info_rdy_in(rd_info_rdy1_0),
        .rd_data_in(rd_data1_0),
        .rd_data_valid_in(rd_data_valid1_0),
        .rd_data_rdy_out(rd_data_rdy1_0),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(4+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*4]),
        .rd_addr_out(rd_addr[33*(4+1)-1:33*4]),
        .rd_len_out(rd_len[8*(4+1)-1:8*4]),
        .rd_info_valid_out(rd_info_valid[4]),
        .rd_info_rdy_in(rd_info_rdy[4]),
        .rd_data_in(rd_data[256*(4+1)-1:256*4]),
        .rd_data_valid_in(rd_data_valid[4]),
        .rd_data_rdy_out(rd_data_rdy[4]),
        .so_clk(stream_clk),
        .so_valid_out(s5o_valid),
        .so_data_out(s5o_data),
        .so_rdy_in(s5o_rdy)
    );
    
    // Engine unit 5
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng5 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s6i_valid),
        .si_data_in(s6i_data),
        .si_rdy_out(s6i_rdy),
        .rd_id_out(rd_id1_1),
        .rd_addr_out(rd_addr1_1),
        .rd_len_out(rd_len1_1),
        .rd_info_valid_out(rd_info_valid1_1),
        .rd_info_rdy_in(rd_info_rdy1_1),
        .rd_data_in(rd_data1_1),
        .rd_data_valid_in(rd_data_valid1_1),
        .rd_data_rdy_out(rd_data_rdy1_1),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(5+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*5]),
        .rd_addr_out(rd_addr[33*(5+1)-1:33*5]),
        .rd_len_out(rd_len[8*(5+1)-1:8*5]),
        .rd_info_valid_out(rd_info_valid[5]),
        .rd_info_rdy_in(rd_info_rdy[5]),
        .rd_data_in(rd_data[256*(5+1)-1:256*5]),
        .rd_data_valid_in(rd_data_valid[5]),
        .rd_data_rdy_out(rd_data_rdy[5]),     
        .so_clk(stream_clk),
        .so_valid_out(s6o_valid),
        .so_data_out(s6o_data),
        .so_rdy_in(s6o_rdy)
    );
    
    // Engine unit 6
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng6 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s7i_valid),
        .si_data_in(s7i_data),
        .si_rdy_out(s7i_rdy),
        .rd_id_out(rd_id1_2),
        .rd_addr_out(rd_addr1_2),
        .rd_len_out(rd_len1_2),
        .rd_info_valid_out(rd_info_valid1_2),
        .rd_info_rdy_in(rd_info_rdy1_2),
        .rd_data_in(rd_data1_2),
        .rd_data_valid_in(rd_data_valid1_2),
        .rd_data_rdy_out(rd_data_rdy1_2),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(6+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*6]),
        .rd_addr_out(rd_addr[33*(6+1)-1:33*6]),
        .rd_len_out(rd_len[8*(6+1)-1:8*6]),
        .rd_info_valid_out(rd_info_valid[6]),
        .rd_info_rdy_in(rd_info_rdy[6]),
        .rd_data_in(rd_data[256*(6+1)-1:256*6]),
        .rd_data_valid_in(rd_data_valid[6]),
        .rd_data_rdy_out(rd_data_rdy[6]),
        .so_clk(stream_clk),
        .so_valid_out(s7o_valid),
        .so_data_out(s7o_data),
        .so_rdy_in(s7o_rdy)
    );
    
    // Engine unit 7
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng7 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s8i_valid),
        .si_data_in(s8i_data),
        .si_rdy_out(s8i_rdy),
        .rd_id_out(rd_id1_3),
        .rd_addr_out(rd_addr1_3),
        .rd_len_out(rd_len1_3),
        .rd_info_valid_out(rd_info_valid1_3),
        .rd_info_rdy_in(rd_info_rdy1_3),
        .rd_data_in(rd_data1_3),
        .rd_data_valid_in(rd_data_valid1_3),
        .rd_data_rdy_out(rd_data_rdy1_3),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(7+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*7]),
        .rd_addr_out(rd_addr[33*(7+1)-1:33*7]),
        .rd_len_out(rd_len[8*(7+1)-1:8*7]),
        .rd_info_valid_out(rd_info_valid[7]),
        .rd_info_rdy_in(rd_info_rdy[7]),
        .rd_data_in(rd_data[256*(7+1)-1:256*7]),
        .rd_data_valid_in(rd_data_valid[7]),
        .rd_data_rdy_out(rd_data_rdy[7]),
        .so_clk(stream_clk),
        .so_valid_out(s8o_valid),
        .so_data_out(s8o_data),
        .so_rdy_in(s8o_rdy)
    );
    
    // Engine unit 8
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng8 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s9i_valid),
        .si_data_in(s9i_data),
        .si_rdy_out(s9i_rdy),
        .rd_id_out(rd_id2_0),
        .rd_addr_out(rd_addr2_0),
        .rd_len_out(rd_len2_0),
        .rd_info_valid_out(rd_info_valid2_0),
        .rd_info_rdy_in(rd_info_rdy2_0),
        .rd_data_in(rd_data2_0),
        .rd_data_valid_in(rd_data_valid2_0),
        .rd_data_rdy_out(rd_data_rdy2_0),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(8+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*8]),
        .rd_addr_out(rd_addr[33*(8+1)-1:33*8]),
        .rd_len_out(rd_len[8*(8+1)-1:8*8]),
        .rd_info_valid_out(rd_info_valid[8]),
        .rd_info_rdy_in(rd_info_rdy[8]),
        .rd_data_in(rd_data[256*(8+1)-1:256*8]),
        .rd_data_valid_in(rd_data_valid[8]),
        .rd_data_rdy_out(rd_data_rdy[8]),
        .so_clk(stream_clk),
        .so_valid_out(s9o_valid),
        .so_data_out(s9o_data),
        .so_rdy_in(s9o_rdy)
    );
    
    // Engine unit 9
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng9 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s10i_valid),
        .si_data_in(s10i_data),
        .si_rdy_out(s10i_rdy),
        .rd_id_out(rd_id2_1),
        .rd_addr_out(rd_addr2_1),
        .rd_len_out(rd_len2_1),
        .rd_info_valid_out(rd_info_valid2_1),
        .rd_info_rdy_in(rd_info_rdy2_1),
        .rd_data_in(rd_data2_1),
        .rd_data_valid_in(rd_data_valid2_1),
        .rd_data_rdy_out(rd_data_rdy2_1),
        .rd_id_out(rd_id[(C0_C_S_AXI_ID_WIDTH-4)*(9+1)-1:(C0_C_S_AXI_ID_WIDTH-4)*9]),
        .rd_addr_out(rd_addr[33*(9+1)-1:33*9]),
        .rd_len_out(rd_len[8*(9+1)-1:8*9]),
        .rd_info_valid_out(rd_info_valid[9]),
        .rd_info_rdy_in(rd_info_rdy[9]),
        .rd_data_in(rd_data[256*(9+1)-1:256*9]),
        .rd_data_valid_in(rd_data_valid[9]),
        .rd_data_rdy_out(rd_data_rdy[9]),
        .so_clk(stream_clk),
        .so_valid_out(s10o_valid),
        .so_data_out(s10o_data),
        .so_rdy_in(s10o_rdy)
    );*/
    
    
endmodule
