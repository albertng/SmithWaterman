/*  File Name        : SmithWatermanAccelerator.v
 *  Description      : User logic block in Pico framework for
 *                     Smith Waterman accelerator
 *
 *  Revision History :
 *      Albert Ng   Jul 31 2013     Initial Revision
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
    input c0_axi_clk,       // AXI input clk
    input c0_phy_init_done, // Initialization completed
    input c0_axi_rst,       // Active high AXI reset signal
    
    // AXI port 1
    output c0_s1_axi_clk,   // Clock for master 1
    
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

    
    
    
    
    
    
    
    
    


endmodule
