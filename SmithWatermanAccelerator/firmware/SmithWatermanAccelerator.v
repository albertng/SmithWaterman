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
    input                           s7i_valid,
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
    input                           s11i_valid,
    input [`STREAM11_IN_WIDTH-1:0]   s11i_data,
    output                          s11i_rdy,
    output                          s11o_valid,
    output [`STREAM11_OUT_WIDTH-1:0] s11o_data,
    input                           s11o_rdy,
    input                           s12i_valid,
    input [`STREAM12_IN_WIDTH-1:0]   s12i_data,
    output                          s12i_rdy,
    output                          s12o_valid,
    output [`STREAM12_OUT_WIDTH-1:0] s12o_data,
    input                           s12o_rdy,

    
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
    output                                 c0_s1_axi_rready,  // Read response ready
    
    // AXI port 2
    output                                 c0_s2_axi_clk,     // Clock for master 2
    
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
    output                                 c0_s3_axi_rready   // Read response ready
    );

    localparam NUM_PES = 64;
    localparam REF_LENGTH = 128;
    localparam WIDTH = 10;
    localparam MATCH_REWARD = 2;
    localparam MISMATCH_PEN = -2;
    localparam GAP_OPEN_PEN = -2;
    localparam GAP_EXTEND_PEN = -1;
    localparam PES_PER_FIFO = 4;   

    wire [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s1_axi_araddr_net;
    wire [7:0] c0_s1_axi_arlen_net;
    wire c0_s1_axi_arvalid_net;
    wire [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s2_axi_araddr_net;
    wire [7:0] c0_s2_axi_arlen_net;
    wire c0_s2_axi_arvalid_net;
    wire [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s3_axi_araddr_net;
    wire [7:0] c0_s3_axi_arlen_net;
    wire c0_s3_axi_arvalid_net;
    
    wire stream_clk;
    wire stream_rst;
    wire sys_clk; 
    reg sys_rst;
    reg [7:0] sys_rst_cnt;
    wire locked;

    wire [3:0] active_ports0;
    wire [5:0] rd_id0_0;
    wire [32:0] rd_addr0_0;
    wire [7:0] rd_len0_0;
    wire rd_info_valid0_0;
    wire rd_info_rdy0_0;
    wire [255:0] rd_data0_0;
    wire rd_data_valid0_0;
    wire rd_data_rdy0_0;
    wire [5:0] rd_id0_1;
    wire [32:0] rd_addr0_1;
    wire [7:0] rd_len0_1;
    wire rd_info_valid0_1;
    wire rd_info_rdy0_1;
    wire [255:0] rd_data0_1;
    wire rd_data_valid0_1;
    wire rd_data_rdy0_1;
    wire [5:0] rd_id0_2;
    wire [32:0] rd_addr0_2;
    wire [7:0] rd_len0_2;
    wire rd_info_valid0_2;
    wire rd_info_rdy0_2;
    wire [255:0] rd_data0_2;
    wire rd_data_valid0_2;
    wire rd_data_rdy0_2;
    wire [5:0] rd_id0_3;
    wire [32:0] rd_addr0_3;
    wire [7:0] rd_len0_3;
    wire rd_info_valid0_3;
    wire rd_info_rdy0_3;
    wire [255:0] rd_data0_3;
    wire rd_data_valid0_3;
    wire rd_data_rdy0_3;
    wire [3:0] active_ports1;
    wire [5:0] rd_id1_0;
    wire [32:0] rd_addr1_0;
    wire [7:0] rd_len1_0;
    wire rd_info_valid1_0;
    wire rd_info_rdy1_0;
    wire [255:0] rd_data1_0;
    wire rd_data_valid1_0;
    wire rd_data_rdy1_0;
    wire [5:0] rd_id1_1;
    wire [32:0] rd_addr1_1;
    wire [7:0] rd_len1_1;
    wire rd_info_valid1_1;
    wire rd_info_rdy1_1;
    wire [255:0] rd_data1_1;
    wire rd_data_valid1_1;
    wire rd_data_rdy1_1;
    wire [5:0] rd_id1_2;
    wire [32:0] rd_addr1_2;
    wire [7:0] rd_len1_2;
    wire rd_info_valid1_2;
    wire rd_info_rdy1_2;
    wire [255:0] rd_data1_2;
    wire rd_data_valid1_2;
    wire rd_data_rdy1_2;
    wire [5:0] rd_id1_3;
    wire [32:0] rd_addr1_3;
    wire [7:0] rd_len1_3;
    wire rd_info_valid1_3;
    wire rd_info_rdy1_3;
    wire [255:0] rd_data1_3;
    wire rd_data_valid1_3;
    wire rd_data_rdy1_3;
    wire [3:0] active_ports2;
    wire [5:0] rd_id2_0;
    wire [32:0] rd_addr2_0;
    wire [7:0] rd_len2_0;
    wire rd_info_valid2_0;
    wire rd_info_rdy2_0;
    wire [255:0] rd_data2_0;
    wire rd_data_valid2_0;
    wire rd_data_rdy2_0;
    wire [5:0] rd_id2_1;
    wire [32:0] rd_addr2_1;
    wire [7:0] rd_len2_1;
    wire rd_info_valid2_1;
    wire rd_info_rdy2_1;
    wire [255:0] rd_data2_1;
    wire rd_data_valid2_1;
    wire rd_data_rdy2_1;
    wire [5:0] rd_id2_2;
    wire [32:0] rd_addr2_2;
    wire [7:0] rd_len2_2;
    wire rd_info_valid2_2;
    wire rd_info_rdy2_2;
    wire [255:0] rd_data2_2;
    wire rd_data_valid2_2;
    wire rd_data_rdy2_2;
    wire [5:0] rd_id2_3;
    wire [32:0] rd_addr2_3;
    wire [7:0] rd_len2_3;
    wire rd_info_valid2_3;
    wire rd_info_rdy2_3;
    wire [255:0] rd_data2_3;
    wire rd_data_valid2_3;
    wire rd_data_rdy2_3;
    
    // Dummy DRAM signals
    /*wire axi_clk;
    wire axi_arready;
    wire [7:0]   axi_arid;
    wire [32:0]  axi_araddr;
    wire [7:0]   axi_arlen;
    wire         axi_arvalid;
    wire [7:0]   axi_rid;
    wire         axi_rvalid;
    wire [255:0] axi_rdata;
    wire         axi_rready;*/
    
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
    assign c0_s2_axi_awlock = `NORMAL_ACCESS;         // Write lock type
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
    assign c0_s3_axi_arsize = `THIRTY_TWO_BYTES;      // # bytes per transfer2
    
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
    assign c0_s2_axi_awready = 0;
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
    assign c0_s3_axi_bready = 0;

    // Dummy DRAM
    /*Dummy_DRAM dd (
        .clk(sys_clk),
        .rst(sys_rst),
        .axi_clk_in(axi_clk),
        .axi_arready_out(axi_arready),
        .axi_arid_in(axi_arid),
        .axi_araddr_in(axi_araddr),
        .axi_arlen_in(axi_arlen),
        .axi_arvalid_in(axi_arvalid),
        .axi_rid_out(axi_rid),
        .axi_rvalid_out(axi_rvalid),
        .axi_rdata_out(axi_rdata),
        .axi_rready_in(axi_rready)
    );*/


    // AXI Arbiter unit 0
    assign active_ports0 = 4'b1111;
    AXIArbiter #(C0_C_S_AXI_ID_WIDTH) aa0 (
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
        /*.axi_clk_out(axi_clk),
        .axi_arready_in(axi_arready),
        .axi_arid_out(axi_arid),
        .axi_araddr_out(axi_araddr),
        .axi_arlen_out(axi_arlen),
        .axi_arvalid_out(axi_arvalid),
        .axi_rid_in(axi_rid),
        .axi_rvalid_in(axi_rvalid),
        .axi_rdata_in(axi_rdata),
        .axi_rready_out(axi_rready),*/
        .active_ports_in(active_ports0),
        .rd_id_0_in(rd_id0_0),
        .rd_addr_0_in(rd_addr0_0),
        .rd_len_0_in(rd_len0_0),
        .rd_info_valid_0_in(rd_info_valid0_0),
        .rd_info_rdy_0_out(rd_info_rdy0_0),
        .rd_data_0_out(rd_data0_0),
        .rd_data_valid_0_out(rd_data_valid0_0),
        .rd_data_rdy_0_in(rd_data_rdy0_0),
        .rd_id_1_in(rd_id0_1),
        .rd_addr_1_in(rd_addr0_1),
        .rd_len_1_in(rd_len0_1),
        .rd_info_valid_1_in(rd_info_valid0_1),
        .rd_info_rdy_1_out(rd_info_rdy0_1),
        .rd_data_1_out(rd_data0_1),
        .rd_data_valid_1_out(rd_data_valid0_1),
        .rd_data_rdy_1_in(rd_data_rdy0_1),
        .rd_id_2_in(rd_id0_2),
        .rd_addr_2_in(rd_addr0_2),
        .rd_len_2_in(rd_len0_2),
        .rd_info_valid_2_in(rd_info_valid0_2),
        .rd_info_rdy_2_out(rd_info_rdy0_2),
        .rd_data_2_out(rd_data0_2),
        .rd_data_valid_2_out(rd_data_valid0_2),
        .rd_data_rdy_2_in(rd_data_rdy0_2),
        .rd_id_3_in(rd_id0_3),
        .rd_addr_3_in(rd_addr0_3),
        .rd_len_3_in(rd_len0_3),
        .rd_info_valid_3_in(rd_info_valid0_3),
        .rd_info_rdy_3_out(rd_info_rdy0_3),
        .rd_data_3_out(rd_data0_3),
        .rd_data_valid_3_out(rd_data_valid0_3),
        .rd_data_rdy_3_in(rd_data_rdy0_3)
    );
    always @(*) begin
        c0_s1_axi_araddr = c0_s1_axi_araddr_net;
        c0_s1_axi_arlen = c0_s1_axi_arlen_net;
        c0_s1_axi_arvalid = c0_s1_axi_arvalid_net;
    end
    /*assign rd_id0_1 = 0;
    assign rd_addr0_1 = 0;
    assign rd_len0_1 = 0;
    assign rd_info_valid0_1 = 0;
    assign rd_data_rdy0_1 = 0;
    assign rd_id0_2 = 0;
    assign rd_addr0_2 = 0;
    assign rd_len0_2 = 0;
    assign rd_info_valid0_2 = 0;
    assign rd_data_rdy0_2 = 0;
    assign rd_id0_3 = 0;
    assign rd_addr0_3 = 0;
    assign rd_len0_3 = 0;
    assign rd_info_valid0_3 = 0;
    assign rd_data_rdy0_3 = 0;*/
    
    // AXI Arbiter unit 1
    assign active_ports1 = 4'b1111;
    AXIArbiter #(C0_C_S_AXI_ID_WIDTH) aa1 (
        .clk(sys_clk),
        .rst(sys_rst),
        .axi_clk_out(c0_s2_axi_clk),
        .axi_arready_in(c0_s2_axi_arready),
        .axi_arid_out(c0_s2_axi_arid),
        .axi_araddr_out(c0_s2_axi_araddr_net),
        .axi_arlen_out(c0_s2_axi_arlen_net),
        .axi_arvalid_out(c0_s2_axi_arvalid_net),
        .axi_rid_in(c0_s2_axi_rid),
        .axi_rvalid_in(c0_s2_axi_rvalid),
        .axi_rdata_in(c0_s2_axi_rdata),
        .axi_rready_out(c0_s2_axi_rready),
        .active_ports_in(active_ports1),
        .rd_id_0_in(rd_id1_0),
        .rd_addr_0_in(rd_addr1_0),
        .rd_len_0_in(rd_len1_0),
        .rd_info_valid_0_in(rd_info_valid1_0),
        .rd_info_rdy_0_out(rd_info_rdy1_0),
        .rd_data_0_out(rd_data1_0),
        .rd_data_valid_0_out(rd_data_valid1_0),
        .rd_data_rdy_0_in(rd_data_rdy1_0),
        .rd_id_1_in(rd_id1_1),
        .rd_addr_1_in(rd_addr1_1),
        .rd_len_1_in(rd_len1_1),
        .rd_info_valid_1_in(rd_info_valid1_1),
        .rd_info_rdy_1_out(rd_info_rdy1_1),
        .rd_data_1_out(rd_data1_1),
        .rd_data_valid_1_out(rd_data_valid1_1),
        .rd_data_rdy_1_in(rd_data_rdy1_1),
        .rd_id_2_in(rd_id1_2),
        .rd_addr_2_in(rd_addr1_2),
        .rd_len_2_in(rd_len1_2),
        .rd_info_valid_2_in(rd_info_valid1_2),
        .rd_info_rdy_2_out(rd_info_rdy1_2),
        .rd_data_2_out(rd_data1_2),
        .rd_data_valid_2_out(rd_data_valid1_2),
        .rd_data_rdy_2_in(rd_data_rdy1_2),
        .rd_id_3_in(rd_id1_3),
        .rd_addr_3_in(rd_addr1_3),
        .rd_len_3_in(rd_len1_3),
        .rd_info_valid_3_in(rd_info_valid1_3),
        .rd_info_rdy_3_out(rd_info_rdy1_3),
        .rd_data_3_out(rd_data1_3),
        .rd_data_valid_3_out(rd_data_valid1_3),
        .rd_data_rdy_3_in(rd_data_rdy1_3)
    );
    always @(*) begin
        c0_s2_axi_araddr = c0_s2_axi_araddr_net;
        c0_s2_axi_arlen = c0_s2_axi_arlen_net;
        c0_s2_axi_arvalid = c0_s2_axi_arvalid_net;
    end
    
    // AXI Arbiter unit 2
    assign active_ports2 = 4'b1111;
    AXIArbiter #(C0_C_S_AXI_ID_WIDTH) aa2 (
        .clk(sys_clk),
        .rst(sys_rst),
        .axi_clk_out(c0_s3_axi_clk),
        .axi_arready_in(c0_s3_axi_arready),
        .axi_arid_out(c0_s3_axi_arid),
        .axi_araddr_out(c0_s3_axi_araddr_net),
        .axi_arlen_out(c0_s3_axi_arlen_net),
        .axi_arvalid_out(c0_s3_axi_arvalid_net),
        .axi_rid_in(c0_s3_axi_rid),
        .axi_rvalid_in(c0_s3_axi_rvalid),
        .axi_rdata_in(c0_s3_axi_rdata),
        .axi_rready_out(c0_s3_axi_rready),
        .active_ports_in(active_ports2),
        .rd_id_0_in(rd_id2_0),
        .rd_addr_0_in(rd_addr2_0),
        .rd_len_0_in(rd_len2_0),
        .rd_info_valid_0_in(rd_info_valid2_0),
        .rd_info_rdy_0_out(rd_info_rdy2_0),
        .rd_data_0_out(rd_data2_0),
        .rd_data_valid_0_out(rd_data_valid2_0),
        .rd_data_rdy_0_in(rd_data_rdy2_0),
        .rd_id_1_in(rd_id2_1),
        .rd_addr_1_in(rd_addr2_1),
        .rd_len_1_in(rd_len2_1),
        .rd_info_valid_1_in(rd_info_valid2_1),
        .rd_info_rdy_1_out(rd_info_rdy2_1),
        .rd_data_1_out(rd_data2_1),
        .rd_data_valid_1_out(rd_data_valid2_1),
        .rd_data_rdy_1_in(rd_data_rdy2_1),
        .rd_id_2_in(rd_id2_2),
        .rd_addr_2_in(rd_addr2_2),
        .rd_len_2_in(rd_len2_2),
        .rd_info_valid_2_in(rd_info_valid2_2),
        .rd_info_rdy_2_out(rd_info_rdy2_2),
        .rd_data_2_out(rd_data2_2),
        .rd_data_valid_2_out(rd_data_valid2_2),
        .rd_data_rdy_2_in(rd_data_rdy2_2),
        .rd_id_3_in(rd_id2_3),
        .rd_addr_3_in(rd_addr2_3),
        .rd_len_3_in(rd_len2_3),
        .rd_info_valid_3_in(rd_info_valid2_3),
        .rd_info_rdy_3_out(rd_info_rdy2_3),
        .rd_data_3_out(rd_data2_3),
        .rd_data_valid_3_out(rd_data_valid2_3),
        .rd_data_rdy_3_in(rd_data_rdy2_3)
    );
    always @(*) begin
        c0_s3_axi_araddr = c0_s3_axi_araddr_net;
        c0_s3_axi_arlen = c0_s3_axi_arlen_net;
        c0_s3_axi_arvalid = c0_s3_axi_arvalid_net;
    end
    
    // Engine unit 0
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng0 (
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
        .so_clk(stream_clk),
        .so_valid_out(s2o_valid),
        .so_data_out(s2o_data),
        .so_rdy_in(s2o_rdy)
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
        .so_clk(stream_clk),
        .so_valid_out(s10o_valid),
        .so_data_out(s10o_data),
        .so_rdy_in(s10o_rdy)
    );
    
    // Engine unit 10
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng10 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s11i_valid),
        .si_data_in(s11i_data),
        .si_rdy_out(s11i_rdy),
        .rd_id_out(rd_id2_2),
        .rd_addr_out(rd_addr2_2),
        .rd_len_out(rd_len2_2),
        .rd_info_valid_out(rd_info_valid2_2),
        .rd_info_rdy_in(rd_info_rdy2_2),
        .rd_data_in(rd_data2_2),
        .rd_data_valid_in(rd_data_valid2_2),
        .rd_data_rdy_out(rd_data_rdy2_2),
        .so_clk(stream_clk),
        .so_valid_out(s11o_valid),
        .so_data_out(s11o_data),
        .so_rdy_in(s11o_rdy)
    );
    
    // Engine unit 11
    Engine #(C0_C_S_AXI_ID_WIDTH, NUM_PES, REF_LENGTH, WIDTH, MATCH_REWARD, MISMATCH_PEN, GAP_OPEN_PEN, GAP_EXTEND_PEN, PES_PER_FIFO) eng11 (
        .clk(sys_clk),
        .rst(sys_rst),
        .si_clk(stream_clk),
        .si_valid_in(s12i_valid),
        .si_data_in(s12i_data),
        .si_rdy_out(s12i_rdy),
        .rd_id_out(rd_id2_3),
        .rd_addr_out(rd_addr2_3),
        .rd_len_out(rd_len2_3),
        .rd_info_valid_out(rd_info_valid2_3),
        .rd_info_rdy_in(rd_info_rdy2_3),
        .rd_data_in(rd_data2_3),
        .rd_data_valid_in(rd_data_valid2_3),
        .rd_data_rdy_out(rd_data_rdy2_3),
        .so_clk(stream_clk),
        .so_valid_out(s12o_valid),
        .so_data_out(s12o_data),
        .so_rdy_in(s12o_rdy)
    );
    
endmodule
