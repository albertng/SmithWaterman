//axis_interconnect.v
// JBC This is setup for the V6 PCIe Gen 1 X8
// TODO need to change some parameters for other PCIe like the Sparten 6
// This module instantiates the upsizer and downsizer AXI Stream Modules
// from Xilinx
// NOTE if C_FIFO_MODE is set to 0 the M0*_AXIS_ACLK is not used
// Copyright 2012, Pico Computing, Inc.

`timescale 1ps/1ps

module axis_interconnect # (
   parameter         C_FAMILY                       = "virtex6",
   parameter integer C_RX_S_AXIS_TDATA_WIDTH        = 64,
   parameter integer C_RX_M_AXIS_TDATA_WIDTH        = 128,
   parameter integer C_TX_S_AXIS_TDATA_WIDTH        = 128,
   parameter integer C_TX_M_AXIS_TDATA_WIDTH        = 64,
   parameter integer C_RX_S_AXIS_TUSER_WIDTH        = 22,
   parameter integer C_RX_M_AXIS_TUSER_WIDTH        = 44,
   parameter integer C_TX_S_AXIS_TUSER_WIDTH        = 8,
   parameter integer C_TX_M_AXIS_TUSER_WIDTH        = 4,
   parameter [31:0]  C_AXIS_SIGNAL_SET              = 32'h97 , // 8'b1001_0111
   // C_AXIS_SIGNAL_SET: each bit if enabled specifies which axis optional signals are present
   //   [0] => TREADY present
   //   [1] => TDATA present
   //   [2] => TSTRB present, TDATA must be present
   //   [3] => TKEEP present, TDATA must be present
   //   [4] => TLAST present
   //   [5] => TID present
   //   [6] => TDEST present
   //   [7] => TUSER present
   parameter integer C_RATIO                        = 2,   // Should always be 1:C_RATIO (upsizer)
   parameter integer C_FIFO_DEPTH                   = 128, 
   //  Valid values 16,32,64,128,256,512,1024,2048,4096,...
   parameter integer C_MEMORY_TYPE                  = 2,
   // JBC Block RAM does not meet timing with the -1 parts
   //      that is why it is set to distributed ram
   // Values: 
   //   1=Block RAM
   //   2=Distributed RAM
   //   3=Shift RAM
   //   4=Built-in FIFO
   parameter integer C_FIFO_MODE                    = 2,
   // Values: 
   //   0 == N0 FIFO
   //   1 == Regular FIFO
   //   2 == Store and Forward FIFO (Packet Mode). Requires TLAST. 
   parameter integer C_IS_ACLK_ASYNC                = 1,
   //  Enables async clock cross when 1.
   parameter integer C_ACLKEN_CONV_MODE             = 0
   // C_ACLKEN_CONV_MODE: Determines how to handle the clock enable pins during
   // clock conversion
   // 0 -- Clock enables not converted
   // 1 -- S_AXIS_ACLKEN can toggle,  M_AXIS_ACLKEN always high.
   // 2 -- S_AXIS_ACLKEN always high, M_AXIS_ACLKEN can toggle.
   // 3 -- S_AXIS_ACLKEN can toggle,  M_AXIS_ACLKEN can toggle.
    ) (
  input                                     ARESETN,
                                            
  input                                     S00_AXIS_ACLK,
  input                                     S01_AXIS_ACLK,
  input                                     S00_AXIS_TVALID,
  input                                     S01_AXIS_TVALID,
  output                                    S00_AXIS_TREADY,
  output                                    S01_AXIS_TREADY,
  input [C_RX_S_AXIS_TDATA_WIDTH-1:0]       S00_AXIS_TDATA,
  input [C_TX_S_AXIS_TDATA_WIDTH-1:0]       S01_AXIS_TDATA,
  input [C_RX_S_AXIS_TDATA_WIDTH/8-1:0]     S00_AXIS_TSTRB,
  input [C_TX_S_AXIS_TDATA_WIDTH/8-1:0]     S01_AXIS_TSTRB,
  input                                     S00_AXIS_TLAST,
  input                                     S01_AXIS_TLAST,
  input [C_RX_S_AXIS_TUSER_WIDTH-1:0]       S00_AXIS_TUSER,
  input [C_TX_S_AXIS_TUSER_WIDTH-1:0]       S01_AXIS_TUSER,
  
  input                                     M00_AXIS_ACLK,
  input                                     M01_AXIS_ACLK,
  output                                    M00_AXIS_TVALID,
  output                                    M01_AXIS_TVALID,
  input                                     M00_AXIS_TREADY,
  input                                     M01_AXIS_TREADY,
  output [C_RX_M_AXIS_TDATA_WIDTH-1:0]      M00_AXIS_TDATA,
  output [C_TX_M_AXIS_TDATA_WIDTH-1:0]      M01_AXIS_TDATA,
  output [C_RX_M_AXIS_TDATA_WIDTH/8-1:0]    M00_AXIS_TSTRB,
  output [C_TX_M_AXIS_TDATA_WIDTH/8-1:0]    M01_AXIS_TSTRB,
  output                                    M00_AXIS_TLAST,
  output                                    M01_AXIS_TLAST,
  output [C_RX_S_AXIS_TUSER_WIDTH-1:0]      M00_AXIS_TUSER,
  output [C_TX_S_AXIS_TUSER_WIDTH-1:0]      M01_AXIS_TUSER
);

//------------------------------------------------------------//
// Wire Declarations
//------------------------------------------------------------//

    wire                                    M00_AXIS_TVALID_UP;
    wire                                    M01_AXIS_TVALID_UP;
    wire                                    M00_AXIS_TREADY_UP;
    wire                                    M01_AXIS_TREADY_UP;
    wire [C_RX_M_AXIS_TDATA_WIDTH-1:0]      M00_AXIS_TDATA_UP;
    wire [C_TX_M_AXIS_TDATA_WIDTH-1:0]      M01_AXIS_TDATA_UP;
    wire [C_RX_M_AXIS_TDATA_WIDTH/8-1:0]    M00_AXIS_TSTRB_UP;
    wire [C_TX_M_AXIS_TDATA_WIDTH/8-1:0]    M01_AXIS_TSTRB_UP;
    wire                                    M00_AXIS_TLAST_UP;
    wire                                    M01_AXIS_TLAST_UP;
    wire [C_RX_S_AXIS_TUSER_WIDTH-1:0]      M00_AXIS_TUSER_UP;
    wire [C_TX_S_AXIS_TUSER_WIDTH-1:0]      M01_AXIS_TUSER_UP;

//------------------------------------------------------------//
// Register Declarations
//------------------------------------------------------------//
    reg                 S00_AXIS_ARESETN;
    reg                 S01_AXIS_ARESETN;
    reg                 S00_AXIS_ARESET;
    reg                 S01_AXIS_ARESET;
    reg                 M00_AXIS_ARESETN;
    reg                 M01_AXIS_ARESETN;


//------------------------------------------------------------//
// Reset
//------------------------------------------------------------//
    always @ (posedge S00_AXIS_ACLK) begin
        S00_AXIS_ARESETN    <= ARESETN;
        S00_AXIS_ARESET     <= ~ARESETN;
    end
    
    always @ (posedge S01_AXIS_ACLK) begin
        S01_AXIS_ARESETN    <= ARESETN;
        S01_AXIS_ARESET     <= ~ARESETN;
    end
 
//------------------------------------------------------------//
// AXI Upsizer
//  - RX Stream 64 to 128 bits
//------------------------------------------------------------//

    axis_dwidth_converter_v1_0_axisc_upsizer #(
        .C_FAMILY                   (C_FAMILY),            
        .C_S_AXIS_TDATA_WIDTH       (C_RX_S_AXIS_TDATA_WIDTH),
        .C_M_AXIS_TDATA_WIDTH       (C_RX_M_AXIS_TDATA_WIDTH),  
        .C_S_AXIS_TUSER_WIDTH       (C_RX_S_AXIS_TUSER_WIDTH),
        .C_M_AXIS_TUSER_WIDTH       (C_RX_M_AXIS_TUSER_WIDTH),
        .C_AXIS_SIGNAL_SET          (C_AXIS_SIGNAL_SET),
        .C_RATIO                    (C_RATIO) 
    ) axi_stm_upsizer (
        .ACLK                       (S00_AXIS_ACLK),
        .ARESET                     (S00_AXIS_ARESET),
        .ACLKEN                     (1'b1),
                                    
        // Slave side               
        .S_AXIS_TVALID              (S00_AXIS_TVALID),
        .S_AXIS_TREADY              (S00_AXIS_TREADY),
        .S_AXIS_TDATA               (S00_AXIS_TDATA),
        .S_AXIS_TSTRB               (S00_AXIS_TSTRB),
        .S_AXIS_TLAST               (S00_AXIS_TLAST),
        .S_AXIS_TUSER               (S00_AXIS_TUSER),
        // Master side              
        .M_AXIS_TVALID              (M00_AXIS_TVALID_UP),
        .M_AXIS_TREADY              (M00_AXIS_TREADY_UP),
        .M_AXIS_TDATA               (M00_AXIS_TDATA_UP),
        .M_AXIS_TSTRB               (M00_AXIS_TSTRB_UP),
        .M_AXIS_TLAST               (M00_AXIS_TLAST_UP),
        .M_AXIS_TUSER               (M00_AXIS_TUSER_UP)  
    );
    
//------------------------------------------------------------//
// AXI Downsizer
//  - TX Stream 128 to 64 bits
//------------------------------------------------------------//

    axis_dwidth_converter_v1_0_axisc_downsizer #(
        .C_FAMILY                   (C_FAMILY),            
        .C_S_AXIS_TDATA_WIDTH       (C_TX_S_AXIS_TDATA_WIDTH),
        .C_M_AXIS_TDATA_WIDTH       (C_TX_M_AXIS_TDATA_WIDTH), 
        .C_S_AXIS_TUSER_WIDTH       (C_TX_S_AXIS_TUSER_WIDTH),
        .C_M_AXIS_TUSER_WIDTH       (C_TX_M_AXIS_TUSER_WIDTH),
        .C_AXIS_SIGNAL_SET          (C_AXIS_SIGNAL_SET),
        .C_RATIO                    (C_RATIO) 
    ) axi_stm_downsizer (
        .ACLK                       (S01_AXIS_ACLK),
        .ARESET                     (S01_AXIS_ARESET),
        .ACLKEN                     (1'b1),
                                    
        // Slave side               
        .S_AXIS_TVALID              (S01_AXIS_TVALID),
        .S_AXIS_TREADY              (S01_AXIS_TREADY),
        .S_AXIS_TDATA               (S01_AXIS_TDATA),
        .S_AXIS_TSTRB               (S01_AXIS_TSTRB),
        .S_AXIS_TLAST               (S01_AXIS_TLAST),
        .S_AXIS_TUSER               (S01_AXIS_TUSER),
        // Master side              
        .M_AXIS_TVALID              (M01_AXIS_TVALID_UP),
        .M_AXIS_TREADY              (M01_AXIS_TREADY_UP),
        .M_AXIS_TDATA               (M01_AXIS_TDATA_UP),
        .M_AXIS_TSTRB               (M01_AXIS_TSTRB_UP),
        .M_AXIS_TLAST               (M01_AXIS_TLAST_UP),
        .M_AXIS_TUSER               (M01_AXIS_TUSER_UP)  
    );
    
    
//------------------------------------------------------------//
// axis_data_fifo_v1_0_axis_data_fifo
//  - Calls Fifo Generator to handle AXI stream
//    cross clock domains
//  - C_FIFO_MODE must be greater than 0
//------------------------------------------------------------//
generate 
  if (C_FIFO_MODE > 0) begin : gen_fifo_generator
      
    always @ (posedge M00_AXIS_ACLK) M00_AXIS_ARESETN <= ARESETN;
    always @ (posedge M01_AXIS_ACLK) M01_AXIS_ARESETN <= ARESETN;
      
    //------------------------------------------------//
    // RX data Fifo
    //------------------------------------------------//
        axis_data_fifo_v1_0_axis_data_fifo # (
            .C_FAMILY                   (C_FAMILY),
            .C_AXIS_TDATA_WIDTH         (C_RX_M_AXIS_TDATA_WIDTH),
            .C_AXIS_TUSER_WIDTH         (C_RX_M_AXIS_TUSER_WIDTH),
            .C_AXIS_SIGNAL_SET          (C_AXIS_SIGNAL_SET),
            .C_FIFO_DEPTH               (C_FIFO_DEPTH),
            .C_FIFO_MODE                (C_FIFO_MODE),                   
            .C_IS_ACLK_ASYNC            (C_IS_ACLK_ASYNC),
            .C_ACLKEN_CONV_MODE         (C_ACLKEN_CONV_MODE),
            .C_MEMORY_TYPE              (C_MEMORY_TYPE)
        ) axis_data_fifo_rx (
            .S_AXIS_ARESETN             (S00_AXIS_ARESETN),
            .M_AXIS_ARESETN             (M00_AXIS_ARESETN),
            
            .S_AXIS_ACLK                (S00_AXIS_ACLK),
            .S_AXIS_ACLKEN              (1'b1),
            .S_AXIS_TVALID              (M00_AXIS_TVALID_UP),
            .S_AXIS_TREADY              (M00_AXIS_TREADY_UP),
            .S_AXIS_TDATA               (M00_AXIS_TDATA_UP),
            .S_AXIS_TSTRB               (M00_AXIS_TSTRB_UP),
            //.S_AXIS_TKEEP(),
            .S_AXIS_TLAST               (M00_AXIS_TLAST_UP),
            //.S_AXIS_TID(),
            //.S_AXIS_TDEST(),
            .S_AXIS_TUSER               (M00_AXIS_TUSER_UP),
            
            .M_AXIS_ACLK                (M00_AXIS_ACLK),
            .M_AXIS_ACLKEN              (1'b1),
            .M_AXIS_TVALID              (M00_AXIS_TVALID),
            .M_AXIS_TREADY              (M00_AXIS_TREADY),
            .M_AXIS_TDATA               (M00_AXIS_TDATA),
            .M_AXIS_TSTRB               (M00_AXIS_TSTRB),
            //.M_AXIS_TKEEP,
            .M_AXIS_TLAST               (M00_AXIS_TLAST),
            //.M_AXIS_TID,
            //.M_AXIS_TDEST,
            .M_AXIS_TUSER               (M00_AXIS_TUSER)
            
            // AXIS_DATA_COUNT,
            //AXIS_WR_DATA_COUNT,
            //AXIS_RD_DATA_COUNT
        );
    
    //------------------------------------------------//
    // TX data Fifo
    //------------------------------------------------//
        axis_data_fifo_v1_0_axis_data_fifo # (
            .C_FAMILY                   (C_FAMILY),
            .C_AXIS_TDATA_WIDTH         (C_TX_M_AXIS_TDATA_WIDTH),
            .C_AXIS_TUSER_WIDTH         (C_TX_M_AXIS_TUSER_WIDTH),
            .C_AXIS_SIGNAL_SET          (C_AXIS_SIGNAL_SET),
            .C_FIFO_DEPTH               (C_FIFO_DEPTH),
            .C_FIFO_MODE                (C_FIFO_MODE),                   
            .C_IS_ACLK_ASYNC            (C_IS_ACLK_ASYNC),
            .C_ACLKEN_CONV_MODE         (C_ACLKEN_CONV_MODE),
            .C_MEMORY_TYPE              (C_MEMORY_TYPE)
        ) axis_data_fifo_tx (
            .S_AXIS_ARESETN             (S01_AXIS_ARESETN),
            .M_AXIS_ARESETN             (M01_AXIS_ARESETN),
            
            .S_AXIS_ACLK                (S01_AXIS_ACLK),
            .S_AXIS_ACLKEN              (1'b1),
            .S_AXIS_TVALID              (M01_AXIS_TVALID_UP),
            .S_AXIS_TREADY              (M01_AXIS_TREADY_UP),
            .S_AXIS_TDATA               (M01_AXIS_TDATA_UP),
            .S_AXIS_TSTRB               (M01_AXIS_TSTRB_UP),
            //.S_AXIS_TKEEP(),
            .S_AXIS_TLAST               (M01_AXIS_TLAST_UP),
            //.S_AXIS_TID(),
            //.S_AXIS_TDEST(),
            .S_AXIS_TUSER               (M01_AXIS_TUSER_UP),
            
            .M_AXIS_ACLK                (M01_AXIS_ACLK),
            .M_AXIS_ACLKEN              (1'b1),
            .M_AXIS_TVALID              (M01_AXIS_TVALID),
            .M_AXIS_TREADY              (M01_AXIS_TREADY),
            .M_AXIS_TDATA               (M01_AXIS_TDATA),
            .M_AXIS_TSTRB               (M01_AXIS_TSTRB),
            //.M_AXIS_TKEEP,
            .M_AXIS_TLAST               (M01_AXIS_TLAST),
            //.M_AXIS_TID,
            //.M_AXIS_TDEST,
            .M_AXIS_TUSER               (M01_AXIS_TUSER)
            
            // AXIS_DATA_COUNT,
            //AXIS_WR_DATA_COUNT,
            //AXIS_RD_DATA_COUNT
        );
    
    
  end
//------------------------------------------------------------//
// no fifo signals are passed straight through
//------------------------------------------------------------//
  else begin : gen_fifo_passthru
    assign M00_AXIS_TREADY_UP   = M00_AXIS_TREADY ;
    assign M00_AXIS_TVALID      = M00_AXIS_TVALID_UP ;
    assign M00_AXIS_TDATA       = M00_AXIS_TDATA_UP  ;
    assign M00_AXIS_TSTRB       = M00_AXIS_TSTRB_UP  ;
    assign M00_AXIS_TLAST       = M00_AXIS_TLAST_UP  ;
    assign M00_AXIS_TUSER       = M00_AXIS_TUSER_UP  ;
    
    assign M01_AXIS_TREADY_UP   = M01_AXIS_TREADY ;
    assign M01_AXIS_TVALID      = M01_AXIS_TVALID_UP ;
    assign M01_AXIS_TDATA       = M01_AXIS_TDATA_UP  ;
    assign M01_AXIS_TSTRB       = M01_AXIS_TSTRB_UP  ;
    assign M01_AXIS_TLAST       = M01_AXIS_TLAST_UP  ;
    assign M01_AXIS_TUSER       = M01_AXIS_TUSER_UP  ;
  end
endgenerate

endmodule

