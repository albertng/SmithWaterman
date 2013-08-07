/*
* File Name : PicoAXIInterconnect.v
*
* Description : This file is meant to be a drop-in replacement for the AXI
*               interconnnect produced by Corgen.
*
*
*
*
*
* Hierarchy :
*               interconnect
*                   slave fifo 0
*                       readAddrFifo
*                       readDataFifo
*                       writeAddrFifo
*                       writeDataFifo
*                       writeResponseFifo
*                   slave fifo 1 
*                   ...
*                   
*                   readAddrArbiter
*                   
*                   writeAddrArbiter
*                   
*                   write data ordering fifo
*                   
*                   write data mux
*                   
*                   read data demux
*                   
*                   write response demux
*                   
*                   master fifo
*                       readAddrFifo
*                       readDataFifo
*                       writeAddrFifo
*                       writeDataFifo
*                       writeResponseFifo
*
* Creation Date : Wed 17 Aug 2011 10:54:35 AM PDT
*
* Author : Corey Olson
*
* Last Modified : Wed 17 Aug 2011 10:54:36 AM PDT
*
* Copyright 2011 Pico Computing, Inc.
*/
module PicoAXIInterconnect #(
    parameter   C_NUM_SLAVE_PORTS               = 4, 
                    // RANGE = (1:16)
                    // Number of Slave Interfaces (SI) for connecting 
                    // to master IP.
    parameter   LOG_C_NUM_SLAVE_PORTS           = 2,
                    // = ceil(log(C_NUM_SLAVE_PORTS))
    parameter   C_AXI_ID_WIDTH                  = 12, 
                    // Bits of ID signals at master port.
                    // RANGE = (4:12)
    parameter   C_AXI_ADDR_WIDTH                = 32, 
                    // RANGE = (12:32)
                    // Width of S_AXI_AWADDR, S_AXI_ARADDR, M_AXI_AWADDR and 
                    // M_AXI_ARADDR for every SI/MI.
    parameter   C_AXI_DATA_WIDTH                = 128
                    // RANGE = (128)
    )
    (
 
   // System Signals
    input                                   INTERCONNECT_ACLK,
    input                                   INTERCONNECT_ARESETN,

   // Slave Interface S00
    output                                  S00_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 00)
    input                                   S00_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S00_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S00_AXI_AWADDR,
    input   [7:0]                           S00_AXI_AWLEN,
    input   [2:0]                           S00_AXI_AWSIZE,
    input   [1:0]                           S00_AXI_AWBURST,
    input                                   S00_AXI_AWLOCK,
    input   [3:0]                           S00_AXI_AWCACHE,
    input   [2:0]                           S00_AXI_AWPROT,
    input   [3:0]                           S00_AXI_AWQOS,
    input                                   S00_AXI_AWVALID,
    output                                  S00_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S00_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S00_AXI_WSTRB,
    input                                   S00_AXI_WLAST,
    input                                   S00_AXI_WVALID,
    output                                  S00_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S00_AXI_BID,
    output  [1:0]                           S00_AXI_BRESP,
    output                                  S00_AXI_BVALID,
    input                                   S00_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S00_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S00_AXI_ARADDR,
    input   [7:0]                           S00_AXI_ARLEN,
    input   [2:0]                           S00_AXI_ARSIZE,
    input   [1:0]                           S00_AXI_ARBURST,
    input                                   S00_AXI_ARLOCK,
    input   [3:0]                           S00_AXI_ARCACHE,
    input   [2:0]                           S00_AXI_ARPROT,
    input   [3:0]                           S00_AXI_ARQOS,
    input                                   S00_AXI_ARVALID,
    output                                  S00_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S00_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S00_AXI_RDATA,
    output  [1:0]                           S00_AXI_RRESP,
    output                                  S00_AXI_RLAST,
    output                                  S00_AXI_RVALID,
    input                                   S00_AXI_RREADY,
   
   // Slave Interface S01
    output                                  S01_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 01)
    input                                   S01_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S01_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S01_AXI_AWADDR,
    input   [7:0]                           S01_AXI_AWLEN,
    input   [2:0]                           S01_AXI_AWSIZE,
    input   [1:0]                           S01_AXI_AWBURST,
    input                                   S01_AXI_AWLOCK,
    input   [3:0]                           S01_AXI_AWCACHE,
    input   [2:0]                           S01_AXI_AWPROT,
    input   [3:0]                           S01_AXI_AWQOS,
    input                                   S01_AXI_AWVALID,
    output                                  S01_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S01_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S01_AXI_WSTRB,
    input                                   S01_AXI_WLAST,
    input                                   S01_AXI_WVALID,
    output                                  S01_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S01_AXI_BID,
    output  [1:0]                           S01_AXI_BRESP,
    output                                  S01_AXI_BVALID,
    input                                   S01_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S01_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S01_AXI_ARADDR,
    input   [7:0]                           S01_AXI_ARLEN,
    input   [2:0]                           S01_AXI_ARSIZE,
    input   [1:0]                           S01_AXI_ARBURST,
    input                                   S01_AXI_ARLOCK,
    input   [3:0]                           S01_AXI_ARCACHE,
    input   [2:0]                           S01_AXI_ARPROT,
    input   [3:0]                           S01_AXI_ARQOS,
    input                                   S01_AXI_ARVALID,
    output                                  S01_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S01_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S01_AXI_RDATA,
    output  [1:0]                           S01_AXI_RRESP,
    output                                  S01_AXI_RLAST,
    output                                  S01_AXI_RVALID,
    input                                   S01_AXI_RREADY,
   
   // Slave Interface S02
    output                                  S02_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 02)
    input                                   S02_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S02_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S02_AXI_AWADDR,
    input   [7:0]                           S02_AXI_AWLEN,
    input   [2:0]                           S02_AXI_AWSIZE,
    input   [1:0]                           S02_AXI_AWBURST,
    input                                   S02_AXI_AWLOCK,
    input   [3:0]                           S02_AXI_AWCACHE,
    input   [2:0]                           S02_AXI_AWPROT,
    input   [3:0]                           S02_AXI_AWQOS,
    input                                   S02_AXI_AWVALID,
    output                                  S02_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S02_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S02_AXI_WSTRB,
    input                                   S02_AXI_WLAST,
    input                                   S02_AXI_WVALID,
    output                                  S02_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S02_AXI_BID,
    output  [1:0]                           S02_AXI_BRESP,
    output                                  S02_AXI_BVALID,
    input                                   S02_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S02_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S02_AXI_ARADDR,
    input   [7:0]                           S02_AXI_ARLEN,
    input   [2:0]                           S02_AXI_ARSIZE,
    input   [1:0]                           S02_AXI_ARBURST,
    input                                   S02_AXI_ARLOCK,
    input   [3:0]                           S02_AXI_ARCACHE,
    input   [2:0]                           S02_AXI_ARPROT,
    input   [3:0]                           S02_AXI_ARQOS,
    input                                   S02_AXI_ARVALID,
    output                                  S02_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S02_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S02_AXI_RDATA,
    output  [1:0]                           S02_AXI_RRESP,
    output                                  S02_AXI_RLAST,
    output                                  S02_AXI_RVALID,
    input                                   S02_AXI_RREADY,
   
   // Slave Interface S03
    output                                  S03_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 03)
    input                                   S03_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S03_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S03_AXI_AWADDR,
    input   [7:0]                           S03_AXI_AWLEN,
    input   [2:0]                           S03_AXI_AWSIZE,
    input   [1:0]                           S03_AXI_AWBURST,
    input                                   S03_AXI_AWLOCK,
    input   [3:0]                           S03_AXI_AWCACHE,
    input   [2:0]                           S03_AXI_AWPROT,
    input   [3:0]                           S03_AXI_AWQOS,
    input                                   S03_AXI_AWVALID,
    output                                  S03_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S03_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S03_AXI_WSTRB,
    input                                   S03_AXI_WLAST,
    input                                   S03_AXI_WVALID,
    output                                  S03_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S03_AXI_BID,
    output  [1:0]                           S03_AXI_BRESP,
    output                                  S03_AXI_BVALID,
    input                                   S03_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S03_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S03_AXI_ARADDR,
    input   [7:0]                           S03_AXI_ARLEN,
    input   [2:0]                           S03_AXI_ARSIZE,
    input   [1:0]                           S03_AXI_ARBURST,
    input                                   S03_AXI_ARLOCK,
    input   [3:0]                           S03_AXI_ARCACHE,
    input   [2:0]                           S03_AXI_ARPROT,
    input   [3:0]                           S03_AXI_ARQOS,
    input                                   S03_AXI_ARVALID,
    output                                  S03_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S03_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S03_AXI_RDATA,
    output  [1:0]                           S03_AXI_RRESP,
    output                                  S03_AXI_RLAST,
    output                                  S03_AXI_RVALID,
    input                                   S03_AXI_RREADY,
   
   // Slave Interface S04
    output                                  S04_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 04)
    input                                   S04_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S04_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S04_AXI_AWADDR,
    input   [7:0]                           S04_AXI_AWLEN,
    input   [2:0]                           S04_AXI_AWSIZE,
    input   [1:0]                           S04_AXI_AWBURST,
    input                                   S04_AXI_AWLOCK,
    input   [3:0]                           S04_AXI_AWCACHE,
    input   [2:0]                           S04_AXI_AWPROT,
    input   [3:0]                           S04_AXI_AWQOS,
    input                                   S04_AXI_AWVALID,
    output                                  S04_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S04_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S04_AXI_WSTRB,
    input                                   S04_AXI_WLAST,
    input                                   S04_AXI_WVALID,
    output                                  S04_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S04_AXI_BID,
    output  [1:0]                           S04_AXI_BRESP,
    output                                  S04_AXI_BVALID,
    input                                   S04_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S04_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S04_AXI_ARADDR,
    input   [7:0]                           S04_AXI_ARLEN,
    input   [2:0]                           S04_AXI_ARSIZE,
    input   [1:0]                           S04_AXI_ARBURST,
    input                                   S04_AXI_ARLOCK,
    input   [3:0]                           S04_AXI_ARCACHE,
    input   [2:0]                           S04_AXI_ARPROT,
    input   [3:0]                           S04_AXI_ARQOS,
    input                                   S04_AXI_ARVALID,
    output                                  S04_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S04_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S04_AXI_RDATA,
    output  [1:0]                           S04_AXI_RRESP,
    output                                  S04_AXI_RLAST,
    output                                  S04_AXI_RVALID,
    input                                   S04_AXI_RREADY,
   
   // Slave Interface S05
    output                                  S05_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 05)
    input                                   S05_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S05_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S05_AXI_AWADDR,
    input   [7:0]                           S05_AXI_AWLEN,
    input   [2:0]                           S05_AXI_AWSIZE,
    input   [1:0]                           S05_AXI_AWBURST,
    input                                   S05_AXI_AWLOCK,
    input   [3:0]                           S05_AXI_AWCACHE,
    input   [2:0]                           S05_AXI_AWPROT,
    input   [3:0]                           S05_AXI_AWQOS,
    input                                   S05_AXI_AWVALID,
    output                                  S05_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S05_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S05_AXI_WSTRB,
    input                                   S05_AXI_WLAST,
    input                                   S05_AXI_WVALID,
    output                                  S05_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S05_AXI_BID,
    output  [1:0]                           S05_AXI_BRESP,
    output                                  S05_AXI_BVALID,
    input                                   S05_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S05_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S05_AXI_ARADDR,
    input   [7:0]                           S05_AXI_ARLEN,
    input   [2:0]                           S05_AXI_ARSIZE,
    input   [1:0]                           S05_AXI_ARBURST,
    input                                   S05_AXI_ARLOCK,
    input   [3:0]                           S05_AXI_ARCACHE,
    input   [2:0]                           S05_AXI_ARPROT,
    input   [3:0]                           S05_AXI_ARQOS,
    input                                   S05_AXI_ARVALID,
    output                                  S05_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S05_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S05_AXI_RDATA,
    output  [1:0]                           S05_AXI_RRESP,
    output                                  S05_AXI_RLAST,
    output                                  S05_AXI_RVALID,
    input                                   S05_AXI_RREADY,
   
   // Slave Interface S06
    output                                  S06_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 06)
    input                                   S06_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S06_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S06_AXI_AWADDR,
    input   [7:0]                           S06_AXI_AWLEN,
    input   [2:0]                           S06_AXI_AWSIZE,
    input   [1:0]                           S06_AXI_AWBURST,
    input                                   S06_AXI_AWLOCK,
    input   [3:0]                           S06_AXI_AWCACHE,
    input   [2:0]                           S06_AXI_AWPROT,
    input   [3:0]                           S06_AXI_AWQOS,
    input                                   S06_AXI_AWVALID,
    output                                  S06_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S06_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S06_AXI_WSTRB,
    input                                   S06_AXI_WLAST,
    input                                   S06_AXI_WVALID,
    output                                  S06_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S06_AXI_BID,
    output  [1:0]                           S06_AXI_BRESP,
    output                                  S06_AXI_BVALID,
    input                                   S06_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S06_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S06_AXI_ARADDR,
    input   [7:0]                           S06_AXI_ARLEN,
    input   [2:0]                           S06_AXI_ARSIZE,
    input   [1:0]                           S06_AXI_ARBURST,
    input                                   S06_AXI_ARLOCK,
    input   [3:0]                           S06_AXI_ARCACHE,
    input   [2:0]                           S06_AXI_ARPROT,
    input   [3:0]                           S06_AXI_ARQOS,
    input                                   S06_AXI_ARVALID,
    output                                  S06_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S06_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S06_AXI_RDATA,
    output  [1:0]                           S06_AXI_RRESP,
    output                                  S06_AXI_RLAST,
    output                                  S06_AXI_RVALID,
    input                                   S06_AXI_RREADY,
   
   // Slave Interface S07
    output                                  S07_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 07)
    input                                   S07_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S07_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S07_AXI_AWADDR,
    input   [7:0]                           S07_AXI_AWLEN,
    input   [2:0]                           S07_AXI_AWSIZE,
    input   [1:0]                           S07_AXI_AWBURST,
    input                                   S07_AXI_AWLOCK,
    input   [3:0]                           S07_AXI_AWCACHE,
    input   [2:0]                           S07_AXI_AWPROT,
    input   [3:0]                           S07_AXI_AWQOS,
    input                                   S07_AXI_AWVALID,
    output                                  S07_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S07_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S07_AXI_WSTRB,
    input                                   S07_AXI_WLAST,
    input                                   S07_AXI_WVALID,
    output                                  S07_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S07_AXI_BID,
    output  [1:0]                           S07_AXI_BRESP,
    output                                  S07_AXI_BVALID,
    input                                   S07_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S07_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S07_AXI_ARADDR,
    input   [7:0]                           S07_AXI_ARLEN,
    input   [2:0]                           S07_AXI_ARSIZE,
    input   [1:0]                           S07_AXI_ARBURST,
    input                                   S07_AXI_ARLOCK,
    input   [3:0]                           S07_AXI_ARCACHE,
    input   [2:0]                           S07_AXI_ARPROT,
    input   [3:0]                           S07_AXI_ARQOS,
    input                                   S07_AXI_ARVALID,
    output                                  S07_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S07_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S07_AXI_RDATA,
    output  [1:0]                           S07_AXI_RRESP,
    output                                  S07_AXI_RLAST,
    output                                  S07_AXI_RVALID,
    input                                   S07_AXI_RREADY,
   
   // Slave Interface S08
    output                                  S08_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 08)
    input                                   S08_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S08_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S08_AXI_AWADDR,
    input   [7:0]                           S08_AXI_AWLEN,
    input   [2:0]                           S08_AXI_AWSIZE,
    input   [1:0]                           S08_AXI_AWBURST,
    input                                   S08_AXI_AWLOCK,
    input   [3:0]                           S08_AXI_AWCACHE,
    input   [2:0]                           S08_AXI_AWPROT,
    input   [3:0]                           S08_AXI_AWQOS,
    input                                   S08_AXI_AWVALID,
    output                                  S08_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S08_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S08_AXI_WSTRB,
    input                                   S08_AXI_WLAST,
    input                                   S08_AXI_WVALID,
    output                                  S08_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S08_AXI_BID,
    output  [1:0]                           S08_AXI_BRESP,
    output                                  S08_AXI_BVALID,
    input                                   S08_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S08_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S08_AXI_ARADDR,
    input   [7:0]                           S08_AXI_ARLEN,
    input   [2:0]                           S08_AXI_ARSIZE,
    input   [1:0]                           S08_AXI_ARBURST,
    input                                   S08_AXI_ARLOCK,
    input   [3:0]                           S08_AXI_ARCACHE,
    input   [2:0]                           S08_AXI_ARPROT,
    input   [3:0]                           S08_AXI_ARQOS,
    input                                   S08_AXI_ARVALID,
    output                                  S08_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S08_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S08_AXI_RDATA,
    output  [1:0]                           S08_AXI_RRESP,
    output                                  S08_AXI_RLAST,
    output                                  S08_AXI_RVALID,
    input                                   S08_AXI_RREADY,
   
   // Slave Interface S09
    output                                  S09_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 09)
    input                                   S09_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S09_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S09_AXI_AWADDR,
    input   [7:0]                           S09_AXI_AWLEN,
    input   [2:0]                           S09_AXI_AWSIZE,
    input   [1:0]                           S09_AXI_AWBURST,
    input                                   S09_AXI_AWLOCK,
    input   [3:0]                           S09_AXI_AWCACHE,
    input   [2:0]                           S09_AXI_AWPROT,
    input   [3:0]                           S09_AXI_AWQOS,
    input                                   S09_AXI_AWVALID,
    output                                  S09_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S09_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S09_AXI_WSTRB,
    input                                   S09_AXI_WLAST,
    input                                   S09_AXI_WVALID,
    output                                  S09_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S09_AXI_BID,
    output  [1:0]                           S09_AXI_BRESP,
    output                                  S09_AXI_BVALID,
    input                                   S09_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S09_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S09_AXI_ARADDR,
    input   [7:0]                           S09_AXI_ARLEN,
    input   [2:0]                           S09_AXI_ARSIZE,
    input   [1:0]                           S09_AXI_ARBURST,
    input                                   S09_AXI_ARLOCK,
    input   [3:0]                           S09_AXI_ARCACHE,
    input   [2:0]                           S09_AXI_ARPROT,
    input   [3:0]                           S09_AXI_ARQOS,
    input                                   S09_AXI_ARVALID,
    output                                  S09_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S09_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S09_AXI_RDATA,
    output  [1:0]                           S09_AXI_RRESP,
    output                                  S09_AXI_RLAST,
    output                                  S09_AXI_RVALID,
    input                                   S09_AXI_RREADY,
   
   // Slave Interface S10
    output                                  S10_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 10)
    input                                   S10_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S10_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S10_AXI_AWADDR,
    input   [7:0]                           S10_AXI_AWLEN,
    input   [2:0]                           S10_AXI_AWSIZE,
    input   [1:0]                           S10_AXI_AWBURST,
    input                                   S10_AXI_AWLOCK,
    input   [3:0]                           S10_AXI_AWCACHE,
    input   [2:0]                           S10_AXI_AWPROT,
    input   [3:0]                           S10_AXI_AWQOS,
    input                                   S10_AXI_AWVALID,
    output                                  S10_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S10_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S10_AXI_WSTRB,
    input                                   S10_AXI_WLAST,
    input                                   S10_AXI_WVALID,
    output                                  S10_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S10_AXI_BID,
    output  [1:0]                           S10_AXI_BRESP,
    output                                  S10_AXI_BVALID,
    input                                   S10_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S10_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S10_AXI_ARADDR,
    input   [7:0]                           S10_AXI_ARLEN,
    input   [2:0]                           S10_AXI_ARSIZE,
    input   [1:0]                           S10_AXI_ARBURST,
    input                                   S10_AXI_ARLOCK,
    input   [3:0]                           S10_AXI_ARCACHE,
    input   [2:0]                           S10_AXI_ARPROT,
    input   [3:0]                           S10_AXI_ARQOS,
    input                                   S10_AXI_ARVALID,
    output                                  S10_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S10_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S10_AXI_RDATA,
    output  [1:0]                           S10_AXI_RRESP,
    output                                  S10_AXI_RLAST,
    output                                  S10_AXI_RVALID,
    input                                   S10_AXI_RREADY,
   
   // Slave Interface S11
    output                                  S11_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 11)
    input                                   S11_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S11_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S11_AXI_AWADDR,
    input   [7:0]                           S11_AXI_AWLEN,
    input   [2:0]                           S11_AXI_AWSIZE,
    input   [1:0]                           S11_AXI_AWBURST,
    input                                   S11_AXI_AWLOCK,
    input   [3:0]                           S11_AXI_AWCACHE,
    input   [2:0]                           S11_AXI_AWPROT,
    input   [3:0]                           S11_AXI_AWQOS,
    input                                   S11_AXI_AWVALID,
    output                                  S11_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S11_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S11_AXI_WSTRB,
    input                                   S11_AXI_WLAST,
    input                                   S11_AXI_WVALID,
    output                                  S11_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S11_AXI_BID,
    output  [1:0]                           S11_AXI_BRESP,
    output                                  S11_AXI_BVALID,
    input                                   S11_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S11_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S11_AXI_ARADDR,
    input   [7:0]                           S11_AXI_ARLEN,
    input   [2:0]                           S11_AXI_ARSIZE,
    input   [1:0]                           S11_AXI_ARBURST,
    input                                   S11_AXI_ARLOCK,
    input   [3:0]                           S11_AXI_ARCACHE,
    input   [2:0]                           S11_AXI_ARPROT,
    input   [3:0]                           S11_AXI_ARQOS,
    input                                   S11_AXI_ARVALID,
    output                                  S11_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S11_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S11_AXI_RDATA,
    output  [1:0]                           S11_AXI_RRESP,
    output                                  S11_AXI_RLAST,
    output                                  S11_AXI_RVALID,
    input                                   S11_AXI_RREADY,
   
   // Slave Interface S12
    output                                  S12_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 12)
    input                                   S12_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S12_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S12_AXI_AWADDR,
    input   [7:0]                           S12_AXI_AWLEN,
    input   [2:0]                           S12_AXI_AWSIZE,
    input   [1:0]                           S12_AXI_AWBURST,
    input                                   S12_AXI_AWLOCK,
    input   [3:0]                           S12_AXI_AWCACHE,
    input   [2:0]                           S12_AXI_AWPROT,
    input   [3:0]                           S12_AXI_AWQOS,
    input                                   S12_AXI_AWVALID,
    output                                  S12_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S12_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S12_AXI_WSTRB,
    input                                   S12_AXI_WLAST,
    input                                   S12_AXI_WVALID,
    output                                  S12_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S12_AXI_BID,
    output  [1:0]                           S12_AXI_BRESP,
    output                                  S12_AXI_BVALID,
    input                                   S12_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S12_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S12_AXI_ARADDR,
    input   [7:0]                           S12_AXI_ARLEN,
    input   [2:0]                           S12_AXI_ARSIZE,
    input   [1:0]                           S12_AXI_ARBURST,
    input                                   S12_AXI_ARLOCK,
    input   [3:0]                           S12_AXI_ARCACHE,
    input   [2:0]                           S12_AXI_ARPROT,
    input   [3:0]                           S12_AXI_ARQOS,
    input                                   S12_AXI_ARVALID,
    output                                  S12_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S12_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S12_AXI_RDATA,
    output  [1:0]                           S12_AXI_RRESP,
    output                                  S12_AXI_RLAST,
    output                                  S12_AXI_RVALID,
    input                                   S12_AXI_RREADY,
   
   // Slave Interface S13
    output                                  S13_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 13)
    input                                   S13_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S13_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S13_AXI_AWADDR,
    input   [7:0]                           S13_AXI_AWLEN,
    input   [2:0]                           S13_AXI_AWSIZE,
    input   [1:0]                           S13_AXI_AWBURST,
    input                                   S13_AXI_AWLOCK,
    input   [3:0]                           S13_AXI_AWCACHE,
    input   [2:0]                           S13_AXI_AWPROT,
    input   [3:0]                           S13_AXI_AWQOS,
    input                                   S13_AXI_AWVALID,
    output                                  S13_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S13_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S13_AXI_WSTRB,
    input                                   S13_AXI_WLAST,
    input                                   S13_AXI_WVALID,
    output                                  S13_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S13_AXI_BID,
    output  [1:0]                           S13_AXI_BRESP,
    output                                  S13_AXI_BVALID,
    input                                   S13_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S13_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S13_AXI_ARADDR,
    input   [7:0]                           S13_AXI_ARLEN,
    input   [2:0]                           S13_AXI_ARSIZE,
    input   [1:0]                           S13_AXI_ARBURST,
    input                                   S13_AXI_ARLOCK,
    input   [3:0]                           S13_AXI_ARCACHE,
    input   [2:0]                           S13_AXI_ARPROT,
    input   [3:0]                           S13_AXI_ARQOS,
    input                                   S13_AXI_ARVALID,
    output                                  S13_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S13_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S13_AXI_RDATA,
    output  [1:0]                           S13_AXI_RRESP,
    output                                  S13_AXI_RLAST,
    output                                  S13_AXI_RVALID,
    input                                   S13_AXI_RREADY,
   
   // Slave Interface S14
    output                                  S14_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 14)
    input                                   S14_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S14_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S14_AXI_AWADDR,
    input   [7:0]                           S14_AXI_AWLEN,
    input   [2:0]                           S14_AXI_AWSIZE,
    input   [1:0]                           S14_AXI_AWBURST,
    input                                   S14_AXI_AWLOCK,
    input   [3:0]                           S14_AXI_AWCACHE,
    input   [2:0]                           S14_AXI_AWPROT,
    input   [3:0]                           S14_AXI_AWQOS,
    input                                   S14_AXI_AWVALID,
    output                                  S14_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S14_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S14_AXI_WSTRB,
    input                                   S14_AXI_WLAST,
    input                                   S14_AXI_WVALID,
    output                                  S14_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S14_AXI_BID,
    output  [1:0]                           S14_AXI_BRESP,
    output                                  S14_AXI_BVALID,
    input                                   S14_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S14_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S14_AXI_ARADDR,
    input   [7:0]                           S14_AXI_ARLEN,
    input   [2:0]                           S14_AXI_ARSIZE,
    input   [1:0]                           S14_AXI_ARBURST,
    input                                   S14_AXI_ARLOCK,
    input   [3:0]                           S14_AXI_ARCACHE,
    input   [2:0]                           S14_AXI_ARPROT,
    input   [3:0]                           S14_AXI_ARQOS,
    input                                   S14_AXI_ARVALID,
    output                                  S14_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S14_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S14_AXI_RDATA,
    output  [1:0]                           S14_AXI_RRESP,
    output                                  S14_AXI_RLAST,
    output                                  S14_AXI_RVALID,
    input                                   S14_AXI_RREADY,
   
   // Slave Interface S15
    output                                  S15_AXI_ARESET_OUT_N,
   // ISVALID = (C_NUM_SLAVE_PORTS > 15)
    input                                   S15_AXI_ACLK,
    input   [C_AXI_ID_WIDTH-5:0]            S15_AXI_AWID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S15_AXI_AWADDR,
    input   [7:0]                           S15_AXI_AWLEN,
    input   [2:0]                           S15_AXI_AWSIZE,
    input   [1:0]                           S15_AXI_AWBURST,
    input                                   S15_AXI_AWLOCK,
    input   [3:0]                           S15_AXI_AWCACHE,
    input   [2:0]                           S15_AXI_AWPROT,
    input   [3:0]                           S15_AXI_AWQOS,
    input                                   S15_AXI_AWVALID,
    output                                  S15_AXI_AWREADY,
    input   [C_AXI_DATA_WIDTH-1:0]          S15_AXI_WDATA,
    input   [C_AXI_DATA_WIDTH/8-1:0]        S15_AXI_WSTRB,
    input                                   S15_AXI_WLAST,
    input                                   S15_AXI_WVALID,
    output                                  S15_AXI_WREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S15_AXI_BID,
    output  [1:0]                           S15_AXI_BRESP,
    output                                  S15_AXI_BVALID,
    input                                   S15_AXI_BREADY,
    input   [C_AXI_ID_WIDTH-5:0]            S15_AXI_ARID,
    input   [C_AXI_ADDR_WIDTH-1:0]          S15_AXI_ARADDR,
    input   [7:0]                           S15_AXI_ARLEN,
    input   [2:0]                           S15_AXI_ARSIZE,
    input   [1:0]                           S15_AXI_ARBURST,
    input                                   S15_AXI_ARLOCK,
    input   [3:0]                           S15_AXI_ARCACHE,
    input   [2:0]                           S15_AXI_ARPROT,
    input   [3:0]                           S15_AXI_ARQOS,
    input                                   S15_AXI_ARVALID,
    output                                  S15_AXI_ARREADY,
    output  [C_AXI_ID_WIDTH-5:0]            S15_AXI_RID,
    output  [C_AXI_DATA_WIDTH-1:0]          S15_AXI_RDATA,
    output  [1:0]                           S15_AXI_RRESP,
    output                                  S15_AXI_RLAST,
    output                                  S15_AXI_RVALID,
    input                                   S15_AXI_RREADY,
 
   // Master Interface
    output                                  M00_AXI_ARESET_OUT_N,
    input                                   M00_AXI_ACLK,
    output  [C_AXI_ID_WIDTH-1:0]            M00_AXI_AWID,
    output  [C_AXI_ADDR_WIDTH-1:0]          M00_AXI_AWADDR,
    output  [7:0]                           M00_AXI_AWLEN,
    output  [2:0]                           M00_AXI_AWSIZE,
    output  [1:0]                           M00_AXI_AWBURST,
    output                                  M00_AXI_AWLOCK,
    output  [3:0]                           M00_AXI_AWCACHE,
    output  [2:0]                           M00_AXI_AWPROT,
    output  [3:0]                           M00_AXI_AWQOS,
    output                                  M00_AXI_AWVALID,
    input                                   M00_AXI_AWREADY,
    output  [C_AXI_DATA_WIDTH-1:0]          M00_AXI_WDATA,
    output  [C_AXI_DATA_WIDTH/8-1:0]        M00_AXI_WSTRB,
    output                                  M00_AXI_WLAST,
    output                                  M00_AXI_WVALID,
    input                                   M00_AXI_WREADY,
    input   [C_AXI_ID_WIDTH-1:0]            M00_AXI_BID,
    input   [1:0]                           M00_AXI_BRESP,
    input                                   M00_AXI_BVALID,
    output                                  M00_AXI_BREADY,
    output  [C_AXI_ID_WIDTH-1:0]            M00_AXI_ARID,
    output  [C_AXI_ADDR_WIDTH-1:0]          M00_AXI_ARADDR,
    output  [7:0]                           M00_AXI_ARLEN,
    output  [2:0]                           M00_AXI_ARSIZE,
    output  [1:0]                           M00_AXI_ARBURST,
    output                                  M00_AXI_ARLOCK,
    output  [3:0]                           M00_AXI_ARCACHE,
    output  [2:0]                           M00_AXI_ARPROT,
    output  [3:0]                           M00_AXI_ARQOS,
    output                                  M00_AXI_ARVALID,
    input                                   M00_AXI_ARREADY,
    input   [C_AXI_ID_WIDTH-1:0]            M00_AXI_RID,
    input   [C_AXI_DATA_WIDTH-1:0]          M00_AXI_RDATA,
    input   [1:0]                           M00_AXI_RRESP,
    input                                   M00_AXI_RLAST,
    input                                   M00_AXI_RVALID,
    output                                  M00_AXI_RREADY
    );
    
    // Wires for interconnect connections to slave fifos and master fifo
    reg     [C_AXI_ID_WIDTH-1:0]        M_AXI_AWID;
    reg     [C_AXI_ADDR_WIDTH-1:0]      M_AXI_AWADDR;
    reg     [7:0]                       M_AXI_AWLEN;
    reg     [2:0]                       M_AXI_AWSIZE;
    reg     [1:0]                       M_AXI_AWBURST;
    reg                                 M_AXI_AWLOCK;
    reg     [3:0]                       M_AXI_AWCACHE;
    reg     [2:0]                       M_AXI_AWPROT;
    reg     [3:0]                       M_AXI_AWQOS ;
    wire                                M_AXI_AWVALID;
    wire                                M_AXI_AWREADY;
    reg     [C_AXI_DATA_WIDTH-1:0]      M_AXI_WDATA;
    reg     [C_AXI_DATA_WIDTH/8-1:0]    M_AXI_WSTRB;
    reg                                 M_AXI_WLAST;
    wire                                M_AXI_WVALID;
    wire                                M_AXI_WREADY;
    wire    [C_AXI_ID_WIDTH-1:0]        M_AXI_BID;
    wire    [1:0]                       M_AXI_BRESP;
    wire                                M_AXI_BVALID;
    wire                                M_AXI_BREADY;
    reg     [C_AXI_ID_WIDTH-1:0]        M_AXI_ARID;
    reg     [C_AXI_ADDR_WIDTH-1:0]      M_AXI_ARADDR;
    reg     [7:0]                       M_AXI_ARLEN;
    reg     [2:0]                       M_AXI_ARSIZE;
    reg     [1:0]                       M_AXI_ARBURST;
    reg                                 M_AXI_ARLOCK;
    reg     [3:0]                       M_AXI_ARCACHE;
    reg     [2:0]                       M_AXI_ARPROT;
    reg     [3:0]                       M_AXI_ARQOS;
    reg                                 M_AXI_ARVALID;
    wire                                M_AXI_ARREADY;
    wire    [C_AXI_ID_WIDTH-1:0]        M_AXI_RID;
    wire    [C_AXI_DATA_WIDTH-1:0]      M_AXI_RDATA;
    wire    [1:0]                       M_AXI_RRESP;
    wire                                M_AXI_RLAST;
    wire                                M_AXI_RVALID;
    wire                                M_AXI_RREADY;
    
    wire    [C_AXI_ID_WIDTH-5:0]        S_AXI_AWID      [C_NUM_SLAVE_PORTS-1:0];
    wire    [C_AXI_ADDR_WIDTH-1:0]      S_AXI_AWADDR    [C_NUM_SLAVE_PORTS-1:0];
    wire    [7:0]                       S_AXI_AWLEN     [C_NUM_SLAVE_PORTS-1:0];
    wire    [2:0]                       S_AXI_AWSIZE    [C_NUM_SLAVE_PORTS-1:0];
    wire    [1:0]                       S_AXI_AWBURST   [C_NUM_SLAVE_PORTS-1:0];
    wire                                S_AXI_AWLOCK    [C_NUM_SLAVE_PORTS-1:0];
    wire    [3:0]                       S_AXI_AWCACHE   [C_NUM_SLAVE_PORTS-1:0];
    wire    [2:0]                       S_AXI_AWPROT    [C_NUM_SLAVE_PORTS-1:0];
    wire    [3:0]                       S_AXI_AWQOS     [C_NUM_SLAVE_PORTS-1:0];
    wire    [C_NUM_SLAVE_PORTS-1:0]     S_AXI_AWVALID;
    reg     [C_NUM_SLAVE_PORTS-1:0]     S_AXI_AWREADY;
    wire    [C_AXI_DATA_WIDTH-1:0]      S_AXI_WDATA     [C_NUM_SLAVE_PORTS-1:0];
    wire    [C_AXI_DATA_WIDTH/8-1:0]    S_AXI_WSTRB     [C_NUM_SLAVE_PORTS-1:0];
    wire    [C_NUM_SLAVE_PORTS-1:0]     S_AXI_WLAST;
    wire    [C_NUM_SLAVE_PORTS-1:0]     S_AXI_WVALID;
    reg     [C_NUM_SLAVE_PORTS-1:0]     S_AXI_WREADY;
    wire    [C_AXI_ID_WIDTH-5:0]        S_AXI_BID;
    wire    [1:0]                       S_AXI_BRESP;
    wire    [C_NUM_SLAVE_PORTS-1:0]     S_AXI_BVALID;
    wire    [C_NUM_SLAVE_PORTS-1:0]     S_AXI_BREADY;
    wire    [C_AXI_ID_WIDTH-5:0]        S_AXI_ARID      [C_NUM_SLAVE_PORTS-1:0];
    wire    [C_AXI_ADDR_WIDTH-1:0]      S_AXI_ARADDR    [C_NUM_SLAVE_PORTS-1:0];
    wire    [7:0]                       S_AXI_ARLEN     [C_NUM_SLAVE_PORTS-1:0];
    wire    [2:0]                       S_AXI_ARSIZE    [C_NUM_SLAVE_PORTS-1:0];
    wire    [1:0]                       S_AXI_ARBURST   [C_NUM_SLAVE_PORTS-1:0];
    wire                                S_AXI_ARLOCK    [C_NUM_SLAVE_PORTS-1:0];
    wire    [3:0]                       S_AXI_ARCACHE   [C_NUM_SLAVE_PORTS-1:0];
    wire    [2:0]                       S_AXI_ARPROT    [C_NUM_SLAVE_PORTS-1:0];
    wire    [3:0]                       S_AXI_ARQOS     [C_NUM_SLAVE_PORTS-1:0];
    wire    [C_NUM_SLAVE_PORTS-1:0]     S_AXI_ARVALID;
    reg     [C_NUM_SLAVE_PORTS-1:0]     S_AXI_ARREADY;
    wire    [C_AXI_ID_WIDTH-5:0]        S_AXI_RID;
    wire    [C_AXI_DATA_WIDTH-1:0]      S_AXI_RDATA;
    wire    [1:0]                       S_AXI_RRESP;
    wire                                S_AXI_RLAST;
    wire    [C_NUM_SLAVE_PORTS-1:0]     S_AXI_RVALID;
    wire    [C_NUM_SLAVE_PORTS-1:0]     S_AXI_RREADY;

    integer                             i;
    
    // register the reset signal
    reg                                 INTERCONNECT_ARESETN_Q;
    always @ (posedge INTERCONNECT_ACLK) begin
        INTERCONNECT_ARESETN_Q <= INTERCONNECT_ARESETN;
    end

    //////////////////////
    // SLAVE INTERFACES //
    //////////////////////
    generate
    genvar ports;
    for(ports=C_NUM_SLAVE_PORTS; ports<=C_NUM_SLAVE_PORTS; ports=ports+1) begin:create_slave_interfaces

		if (ports > 15) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			slave_15 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S15_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S15_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S15_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S15_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S15_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S15_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S15_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S15_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S15_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S15_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S15_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S15_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S15_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S15_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S15_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S15_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S15_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S15_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S15_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S15_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S15_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S15_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S15_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S15_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S15_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S15_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S15_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S15_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S15_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S15_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S15_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S15_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S15_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S15_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S15_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S15_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S15_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S15_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID    [15]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR  [15]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN   [15]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE  [15]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST [15]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK  [15]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE [15]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT  [15]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS   [15]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID [15]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY [15]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA   [15]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB   [15]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST   [15]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID  [15]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY  [15]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID  [15]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY  [15]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID    [15]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR  [15]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN   [15]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE  [15]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST [15]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK  [15]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE [15]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT  [15]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS   [15]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID [15]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY [15]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID  [15]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY  [15])    // output m_axi_rready
			);
		end 
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S15_AXI_AWREADY = 0;
			assign S15_AXI_WREADY = 0;
			assign S15_AXI_BVALID = 0;
			assign S15_AXI_ARREADY = 0;
			assign S15_AXI_RVALID = 0;
		end

		if (ports > 14) begin        
			// fifos for the slave interfaces
			PicoAXIFifo  #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			slave_14 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S14_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S14_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S14_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S14_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S14_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S14_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S14_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S14_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S14_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S14_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S14_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S14_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S14_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S14_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S14_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S14_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S14_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S14_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S14_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S14_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S14_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S14_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S14_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S14_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S14_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S14_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S14_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S14_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S14_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S14_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S14_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S14_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S14_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S14_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S14_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S14_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S14_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S14_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID    [14]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR  [14]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN   [14]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE  [14]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST [14]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK  [14]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE [14]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT  [14]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS   [14]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID [14]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY [14]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA   [14]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB   [14]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST   [14]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID  [14]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY  [14]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID  [14]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY  [14]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID    [14]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR  [14]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN   [14]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE  [14]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST [14]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK  [14]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE [14]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT  [14]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS   [14]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID [14]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY [14]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID  [14]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY  [14])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S14_AXI_AWREADY = 0;
			assign S14_AXI_WREADY = 0;
			assign S14_AXI_BVALID = 0;
			assign S14_AXI_ARREADY = 0;
			assign S14_AXI_RVALID = 0;
		end

		if (ports > 13) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_13 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S13_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S13_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S13_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S13_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S13_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S13_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S13_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S13_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S13_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S13_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S13_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S13_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S13_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S13_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S13_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S13_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S13_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S13_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S13_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S13_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S13_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S13_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S13_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S13_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S13_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S13_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S13_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S13_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S13_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S13_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S13_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S13_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S13_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S13_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S13_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S13_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S13_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S13_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID    [13]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR  [13]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN   [13]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE  [13]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST [13]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK  [13]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE [13]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT  [13]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS   [13]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID [13]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY [13]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA   [13]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB   [13]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST   [13]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID  [13]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY  [13]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID  [13]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY  [13]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID    [13]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR  [13]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN   [13]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE  [13]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST [13]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK  [13]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE [13]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT  [13]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS   [13]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID [13]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY [13]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID  [13]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY  [13])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S13_AXI_AWREADY = 0;
			assign S13_AXI_WREADY = 0;
			assign S13_AXI_BVALID = 0;
			assign S13_AXI_ARREADY = 0;
			assign S13_AXI_RVALID = 0;
		end

		if (ports > 12) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_12 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S12_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S12_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S12_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S12_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S12_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S12_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S12_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S12_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S12_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S12_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S12_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S12_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S12_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S12_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S12_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S12_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S12_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S12_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S12_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S12_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S12_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S12_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S12_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S12_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S12_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S12_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S12_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S12_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S12_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S12_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S12_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S12_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S12_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S12_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S12_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S12_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S12_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S12_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID    [12]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR  [12]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN   [12]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE  [12]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST [12]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK  [12]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE [12]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT  [12]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS   [12]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID [12]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY [12]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA   [12]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB   [12]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST   [12]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID  [12]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY  [12]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID  [12]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY  [12]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID    [12]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR  [12]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN   [12]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE  [12]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST [12]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK  [12]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE [12]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT  [12]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS   [12]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID [12]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY [12]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID  [12]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY  [12])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S12_AXI_AWREADY = 0;
			assign S12_AXI_WREADY = 0;
			assign S12_AXI_BVALID = 0;
			assign S12_AXI_ARREADY = 0;
			assign S12_AXI_RVALID = 0;
		end

		if (ports > 11) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_11 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S11_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S11_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S11_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S11_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S11_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S11_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S11_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S11_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S11_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S11_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S11_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S11_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S11_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S11_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S11_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S11_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S11_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S11_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S11_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S11_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S11_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S11_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S11_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S11_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S11_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S11_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S11_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S11_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S11_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S11_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S11_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S11_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S11_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S11_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S11_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S11_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S11_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S11_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID    [11]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR  [11]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN   [11]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE  [11]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST [11]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK  [11]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE [11]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT  [11]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS   [11]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID [11]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY [11]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA   [11]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB   [11]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST   [11]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID  [11]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY  [11]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID  [11]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY  [11]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID    [11]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR  [11]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN   [11]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE  [11]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST [11]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK  [11]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE [11]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT  [11]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS   [11]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID [11]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY [11]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID  [11]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY  [11])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S11_AXI_AWREADY = 0;
			assign S11_AXI_WREADY = 0;
			assign S11_AXI_BVALID = 0;
			assign S11_AXI_ARREADY = 0;
			assign S11_AXI_RVALID = 0;
		end

		if (ports > 10) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_10 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S10_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S10_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S10_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S10_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S10_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S10_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S10_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S10_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S10_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S10_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S10_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S10_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S10_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S10_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S10_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S10_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S10_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S10_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S10_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S10_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S10_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S10_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S10_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S10_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S10_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S10_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S10_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S10_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S10_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S10_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S10_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S10_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S10_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S10_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S10_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S10_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S10_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S10_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID    [10]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR  [10]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN   [10]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE  [10]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST [10]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK  [10]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE [10]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT  [10]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS   [10]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID [10]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY [10]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA   [10]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB   [10]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST   [10]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID  [10]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY  [10]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID  [10]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY  [10]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID    [10]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR  [10]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN   [10]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE  [10]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST [10]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK  [10]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE [10]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT  [10]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS   [10]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID [10]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY [10]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID  [10]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY  [10])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S10_AXI_AWREADY = 0;
			assign S10_AXI_WREADY = 0;
			assign S10_AXI_BVALID = 0;
			assign S10_AXI_ARREADY = 0;
			assign S10_AXI_RVALID = 0;
		end

		if (ports > 9) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_9 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S09_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S09_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S09_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S09_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S09_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S09_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S09_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S09_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S09_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S09_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S09_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S09_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S09_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S09_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S09_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S09_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S09_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S09_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S09_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S09_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S09_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S09_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S09_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S09_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S09_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S09_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S09_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S09_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S09_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S09_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S09_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S09_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S09_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S09_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S09_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S09_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S09_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S09_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID     [9]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR   [9]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN    [9]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE   [9]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST  [9]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK   [9]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE  [9]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT   [9]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS    [9]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID  [9]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY  [9]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA    [9]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB    [9]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST    [9]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID   [9]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY   [9]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID   [9]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY   [9]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID     [9]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR   [9]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN    [9]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE   [9]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST  [9]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK   [9]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE  [9]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT   [9]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS    [9]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID  [9]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY  [9]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID   [9]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY   [9])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S09_AXI_AWREADY = 0;
			assign S09_AXI_WREADY = 0;
			assign S09_AXI_BVALID = 0;
			assign S09_AXI_ARREADY = 0;
			assign S09_AXI_RVALID = 0;
		end

		if (ports > 8) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_8 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S08_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S08_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S08_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S08_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S08_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S08_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S08_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S08_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S08_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S08_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S08_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S08_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S08_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S08_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S08_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S08_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S08_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S08_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S08_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S08_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S08_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S08_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S08_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S08_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S08_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S08_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S08_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S08_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S08_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S08_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S08_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S08_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S08_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S08_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S08_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S08_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S08_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S08_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID     [8]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR   [8]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN    [8]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE   [8]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST  [8]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK   [8]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE  [8]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT   [8]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS    [8]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID  [8]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY  [8]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA    [8]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB    [8]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST    [8]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID   [8]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY   [8]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID   [8]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY   [8]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID     [8]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR   [8]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN    [8]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE   [8]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST  [8]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK   [8]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE  [8]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT   [8]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS    [8]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID  [8]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY  [8]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID   [8]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY   [8])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S08_AXI_AWREADY = 0;
			assign S08_AXI_WREADY = 0;
			assign S08_AXI_BVALID = 0;
			assign S08_AXI_ARREADY = 0;
			assign S08_AXI_RVALID = 0;
		end

		if (ports > 7) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_7 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S07_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S07_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S07_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S07_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S07_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S07_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S07_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S07_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S07_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S07_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S07_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S07_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S07_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S07_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S07_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S07_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S07_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S07_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S07_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S07_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S07_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S07_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S07_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S07_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S07_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S07_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S07_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S07_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S07_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S07_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S07_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S07_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S07_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S07_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S07_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S07_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S07_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S07_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID     [7]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR   [7]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN    [7]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE   [7]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST  [7]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK   [7]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE  [7]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT   [7]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS    [7]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID  [7]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY  [7]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA    [7]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB    [7]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST    [7]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID   [7]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY   [7]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID   [7]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY   [7]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID     [7]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR   [7]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN    [7]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE   [7]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST  [7]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK   [7]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE  [7]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT   [7]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS    [7]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID  [7]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY  [7]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID   [7]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY   [7])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S07_AXI_AWREADY = 0;
			assign S07_AXI_WREADY = 0;
			assign S07_AXI_BVALID = 0;
			assign S07_AXI_ARREADY = 0;
			assign S07_AXI_RVALID = 0;
		end

		if (ports > 6) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_6 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S06_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S06_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S06_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S06_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S06_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S06_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S06_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S06_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S06_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S06_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S06_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S06_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S06_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S06_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S06_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S06_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S06_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S06_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S06_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S06_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S06_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S06_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S06_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S06_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S06_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S06_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S06_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S06_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S06_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S06_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S06_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S06_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S06_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S06_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S06_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S06_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S06_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S06_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID     [6]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR   [6]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN    [6]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE   [6]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST  [6]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK   [6]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE  [6]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT   [6]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS    [6]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID  [6]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY  [6]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA    [6]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB    [6]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST    [6]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID   [6]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY   [6]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID   [6]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY   [6]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID     [6]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR   [6]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN    [6]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE   [6]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST  [6]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK   [6]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE  [6]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT   [6]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS    [6]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID  [6]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY  [6]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID   [6]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY   [6])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S06_AXI_AWREADY = 0;
			assign S06_AXI_WREADY = 0;
			assign S06_AXI_BVALID = 0;
			assign S06_AXI_ARREADY = 0;
			assign S06_AXI_RVALID = 0;
		end

		if (ports > 5) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_5 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S05_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S05_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S05_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S05_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S05_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S05_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S05_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S05_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S05_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S05_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S05_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S05_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S05_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S05_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S05_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S05_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S05_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S05_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S05_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S05_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S05_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S05_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S05_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S05_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S05_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S05_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S05_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S05_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S05_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S05_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S05_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S05_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S05_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S05_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S05_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S05_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S05_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S05_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID     [5]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR   [5]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN    [5]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE   [5]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST  [5]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK   [5]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE  [5]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT   [5]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS    [5]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID  [5]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY  [5]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA    [5]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB    [5]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST    [5]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID   [5]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY   [5]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID   [5]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY   [5]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID     [5]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR   [5]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN    [5]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE   [5]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST  [5]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK   [5]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE  [5]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT   [5]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS    [5]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID  [5]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY  [5]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID   [5]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY   [5])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S05_AXI_AWREADY = 0;
			assign S05_AXI_WREADY = 0;
			assign S05_AXI_BVALID = 0;
			assign S05_AXI_ARREADY = 0;
			assign S05_AXI_RVALID = 0;
		end

		if (ports > 4) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_4 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S04_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S04_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S04_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S04_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S04_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S04_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S04_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S04_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S04_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S04_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S04_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S04_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S04_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S04_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S04_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S04_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S04_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S04_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S04_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S04_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S04_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S04_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S04_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S04_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S04_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S04_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S04_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S04_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S04_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S04_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S04_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S04_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S04_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S04_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S04_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S04_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S04_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S04_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID     [4]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR   [4]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN    [4]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE   [4]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST  [4]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK   [4]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE  [4]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT   [4]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS    [4]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID  [4]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY  [4]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA    [4]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB    [4]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST    [4]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID   [4]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY   [4]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID   [4]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY   [4]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID     [4]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR   [4]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN    [4]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE   [4]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST  [4]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK   [4]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE  [4]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT   [4]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS    [4]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID  [4]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY  [4]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID   [4]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY   [4])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S04_AXI_AWREADY = 0;
			assign S04_AXI_WREADY = 0;
			assign S04_AXI_BVALID = 0;
			assign S04_AXI_ARREADY = 0;
			assign S04_AXI_RVALID = 0;
		end

		if (ports > 3) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_3 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S03_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S03_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S03_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S03_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S03_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S03_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S03_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S03_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S03_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S03_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S03_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S03_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S03_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S03_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S03_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S03_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S03_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S03_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S03_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S03_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S03_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S03_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S03_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S03_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S03_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S03_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S03_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S03_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S03_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S03_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S03_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S03_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S03_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S03_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S03_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S03_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S03_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S03_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID     [3]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR   [3]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN    [3]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE   [3]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST  [3]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK   [3]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE  [3]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT   [3]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS    [3]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID  [3]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY  [3]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA    [3]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB    [3]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST    [3]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID   [3]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY   [3]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID   [3]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY   [3]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID     [3]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR   [3]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN    [3]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE   [3]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST  [3]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK   [3]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE  [3]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT   [3]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS    [3]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID  [3]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY  [3]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID   [3]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY   [3])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S03_AXI_AWREADY = 0;
			assign S03_AXI_WREADY = 0;
			assign S03_AXI_BVALID = 0;
			assign S03_AXI_ARREADY = 0;
			assign S03_AXI_RVALID = 0;
		end

		if (ports > 2) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_2 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S02_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S02_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S02_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S02_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S02_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S02_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S02_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S02_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S02_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S02_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S02_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S02_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S02_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S02_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S02_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S02_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S02_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S02_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S02_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S02_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S02_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S02_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S02_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S02_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S02_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S02_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S02_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S02_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S02_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S02_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S02_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S02_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S02_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S02_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S02_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S02_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S02_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S02_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID     [2]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR   [2]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN    [2]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE   [2]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST  [2]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK   [2]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE  [2]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT   [2]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS    [2]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID  [2]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY  [2]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA    [2]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB    [2]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST    [2]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID   [2]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY   [2]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID   [2]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY   [2]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID     [2]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR   [2]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN    [2]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE   [2]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST  [2]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK   [2]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE  [2]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT   [2]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS    [2]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID  [2]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY  [2]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID   [2]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY   [2])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S02_AXI_AWREADY = 0;
			assign S02_AXI_WREADY = 0;
			assign S02_AXI_BVALID = 0;
			assign S02_AXI_ARREADY = 0;
			assign S02_AXI_RVALID = 0;
		end

		if (ports > 1) begin        
			// fifos for the slave interfaces
			PicoAXIFifo #(
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
				.C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
				.C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
			)
			 slave_1 (
				.m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
				.s_aclk         (S01_AXI_ACLK),         // input s_aclk
				.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
				.s_axi_awid     (S01_AXI_AWID),         // input [7 : 0] s_axi_awid
				.s_axi_awaddr   (S01_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
				.s_axi_awlen    (S01_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
				.s_axi_awsize   (S01_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
				.s_axi_awburst  (S01_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
				.s_axi_awlock   (S01_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
				.s_axi_awcache  (S01_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
				.s_axi_awprot   (S01_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
				.s_axi_awqos    (S01_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
				.s_axi_awvalid  (S01_AXI_AWVALID),      // input s_axi_awvalid
				.s_axi_awready  (S01_AXI_AWREADY),      // output s_axi_awready
				.s_axi_wdata    (S01_AXI_WDATA),        // input [127 : 0] s_axi_wdata
				.s_axi_wstrb    (S01_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
				.s_axi_wlast    (S01_AXI_WLAST),        // input s_axi_wlast
				.s_axi_wvalid   (S01_AXI_WVALID),       // input s_axi_wvalid
				.s_axi_wready   (S01_AXI_WREADY),       // output s_axi_wready
				.s_axi_bid      (S01_AXI_BID),          // output [7 : 0] s_axi_bid
				.s_axi_bresp    (S01_AXI_BRESP),        // output [1 : 0] s_axi_bresp
				.s_axi_bvalid   (S01_AXI_BVALID),       // output s_axi_bvalid
				.s_axi_bready   (S01_AXI_BREADY),       // input s_axi_bready
				.s_axi_arid     (S01_AXI_ARID),         // input [7 : 0] s_axi_arid
				.s_axi_araddr   (S01_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
				.s_axi_arlen    (S01_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
				.s_axi_arsize   (S01_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
				.s_axi_arburst  (S01_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
				.s_axi_arlock   (S01_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
				.s_axi_arcache  (S01_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
				.s_axi_arprot   (S01_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
				.s_axi_arqos    (S01_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
				.s_axi_arvalid  (S01_AXI_ARVALID),      // input s_axi_arvalid
				.s_axi_arready  (S01_AXI_ARREADY),      // output s_axi_arready
				.s_axi_rid      (S01_AXI_RID),          // output [7 : 0] s_axi_rid
				.s_axi_rdata    (S01_AXI_RDATA),        // output [127 : 0] s_axi_rdata
				.s_axi_rresp    (S01_AXI_RRESP),        // output [1 : 0] s_axi_rresp
				.s_axi_rlast    (S01_AXI_RLAST),        // output s_axi_rlast
				.s_axi_rvalid   (S01_AXI_RVALID),       // output s_axi_rvalid
				.s_axi_rready   (S01_AXI_RREADY),       // input s_axi_rready
				.m_axi_awid     (S_AXI_AWID     [1]),   // output [7 : 0] m_axi_awid
				.m_axi_awaddr   (S_AXI_AWADDR   [1]),   // output [31 : 0] m_axi_awaddr
				.m_axi_awlen    (S_AXI_AWLEN    [1]),   // output [7 : 0] m_axi_awlen
				.m_axi_awsize   (S_AXI_AWSIZE   [1]),   // output [2 : 0] m_axi_awsize
				.m_axi_awburst  (S_AXI_AWBURST  [1]),   // output [1 : 0] m_axi_awburst
				.m_axi_awlock   (S_AXI_AWLOCK   [1]),   // output [1 : 0] m_axi_awlock
				.m_axi_awcache  (S_AXI_AWCACHE  [1]),   // output [3 : 0] m_axi_awcache
				.m_axi_awprot   (S_AXI_AWPROT   [1]),   // output [2 : 0] m_axi_awprot
				.m_axi_awqos    (S_AXI_AWQOS    [1]),   // output [3 : 0] m_axi_awqos
				.m_axi_awvalid  (S_AXI_AWVALID  [1]),   // output m_axi_awvalid
				.m_axi_awready  (S_AXI_AWREADY  [1]),   // input m_axi_awready
				.m_axi_wdata    (S_AXI_WDATA    [1]),   // output [127 : 0] m_axi_wdata
				.m_axi_wstrb    (S_AXI_WSTRB    [1]),   // output [15 : 0] m_axi_wstrb
				.m_axi_wlast    (S_AXI_WLAST    [1]),   // output m_axi_wlast
				.m_axi_wvalid   (S_AXI_WVALID   [1]),   // output m_axi_wvalid
				.m_axi_wready   (S_AXI_WREADY   [1]),   // input m_axi_wready
				.m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
				.m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
				.m_axi_bvalid   (S_AXI_BVALID   [1]),   // input m_axi_bvalid
				.m_axi_bready   (S_AXI_BREADY   [1]),   // output m_axi_bready
				.m_axi_arid     (S_AXI_ARID     [1]),   // output [7 : 0] m_axi_arid
				.m_axi_araddr   (S_AXI_ARADDR   [1]),   // output [31 : 0] m_axi_araddr
				.m_axi_arlen    (S_AXI_ARLEN    [1]),   // output [7 : 0] m_axi_arlen
				.m_axi_arsize   (S_AXI_ARSIZE   [1]),   // output [2 : 0] m_axi_arsize
				.m_axi_arburst  (S_AXI_ARBURST  [1]),   // output [1 : 0] m_axi_arburst
				.m_axi_arlock   (S_AXI_ARLOCK   [1]),   // output [1 : 0] m_axi_arlock
				.m_axi_arcache  (S_AXI_ARCACHE  [1]),   // output [3 : 0] m_axi_arcache
				.m_axi_arprot   (S_AXI_ARPROT   [1]),   // output [2 : 0] m_axi_arprot
				.m_axi_arqos    (S_AXI_ARQOS    [1]),   // output [3 : 0] m_axi_arqos
				.m_axi_arvalid  (S_AXI_ARVALID  [1]),   // output m_axi_arvalid
				.m_axi_arready  (S_AXI_ARREADY  [1]),   // input m_axi_arready
				.m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
				.m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
				.m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
				.m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
				.m_axi_rvalid   (S_AXI_RVALID   [1]),   // input m_axi_rvalid
				.m_axi_rready   (S_AXI_RREADY   [1])    // output m_axi_rready
			);
		end
		// if you don't need a port, just assign the valid and ready signals to 0
		else begin
			assign S01_AXI_AWREADY = 0;
			assign S01_AXI_WREADY = 0;
			assign S01_AXI_BVALID = 0;
			assign S01_AXI_ARREADY = 0;
			assign S01_AXI_RVALID = 0;
		end
        
        // must have at least 1 slave port for the AXI interconnect in order
        // to stream data from the host to the memory
        PicoAXIFifo #(
            .C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
            .C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
            .C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH-4)
        )
         slave_0 (
            .m_aclk         (INTERCONNECT_ACLK),    // input m_aclk
            .s_aclk         (S00_AXI_ACLK),         // input s_aclk
			.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
            .s_axi_awid     (S00_AXI_AWID),         // input [7 : 0] s_axi_awid
            .s_axi_awaddr   (S00_AXI_AWADDR),       // input [31 : 0] s_axi_awaddr
            .s_axi_awlen    (S00_AXI_AWLEN),        // input [7 : 0] s_axi_awlen
            .s_axi_awsize   (S00_AXI_AWSIZE),       // input [2 : 0] s_axi_awsize
            .s_axi_awburst  (S00_AXI_AWBURST),      // input [1 : 0] s_axi_awburst
            .s_axi_awlock   (S00_AXI_AWLOCK),       // input [1 : 0] s_axi_awlock
            .s_axi_awcache  (S00_AXI_AWCACHE),      // input [3 : 0] s_axi_awcache
            .s_axi_awprot   (S00_AXI_AWPROT),       // input [2 : 0] s_axi_awprot
            .s_axi_awqos    (S00_AXI_AWQOS),        // input [3 : 0] s_axi_awqos
            .s_axi_awvalid  (S00_AXI_AWVALID),      // input s_axi_awvalid
            .s_axi_awready  (S00_AXI_AWREADY),      // output s_axi_awready
            .s_axi_wdata    (S00_AXI_WDATA),        // input [127 : 0] s_axi_wdata
            .s_axi_wstrb    (S00_AXI_WSTRB),        // input [15 : 0] s_axi_wstrb
            .s_axi_wlast    (S00_AXI_WLAST),        // input s_axi_wlast
            .s_axi_wvalid   (S00_AXI_WVALID),       // input s_axi_wvalid
            .s_axi_wready   (S00_AXI_WREADY),       // output s_axi_wready
            .s_axi_bid      (S00_AXI_BID),          // output [7 : 0] s_axi_bid
            .s_axi_bresp    (S00_AXI_BRESP),        // output [1 : 0] s_axi_bresp
            .s_axi_bvalid   (S00_AXI_BVALID),       // output s_axi_bvalid
            .s_axi_bready   (S00_AXI_BREADY),       // input s_axi_bready
            .s_axi_arid     (S00_AXI_ARID),         // input [7 : 0] s_axi_arid
            .s_axi_araddr   (S00_AXI_ARADDR),       // input [31 : 0] s_axi_araddr
            .s_axi_arlen    (S00_AXI_ARLEN),        // input [7 : 0] s_axi_arlen
            .s_axi_arsize   (S00_AXI_ARSIZE),       // input [2 : 0] s_axi_arsize
            .s_axi_arburst  (S00_AXI_ARBURST),      // input [1 : 0] s_axi_arburst
            .s_axi_arlock   (S00_AXI_ARLOCK),       // input [1 : 0] s_axi_arlock
            .s_axi_arcache  (S00_AXI_ARCACHE),      // input [3 : 0] s_axi_arcache
            .s_axi_arprot   (S00_AXI_ARPROT),       // input [2 : 0] s_axi_arprot
            .s_axi_arqos    (S00_AXI_ARQOS),        // input [3 : 0] s_axi_arqos
            .s_axi_arvalid  (S00_AXI_ARVALID),      // input s_axi_arvalid
            .s_axi_arready  (S00_AXI_ARREADY),      // output s_axi_arready
            .s_axi_rid      (S00_AXI_RID),          // output [7 : 0] s_axi_rid
            .s_axi_rdata    (S00_AXI_RDATA),        // output [127 : 0] s_axi_rdata
            .s_axi_rresp    (S00_AXI_RRESP),        // output [1 : 0] s_axi_rresp
            .s_axi_rlast    (S00_AXI_RLAST),        // output s_axi_rlast
            .s_axi_rvalid   (S00_AXI_RVALID),       // output s_axi_rvalid
            .s_axi_rready   (S00_AXI_RREADY),       // input s_axi_rready
            .m_axi_awid     (S_AXI_AWID     [0]),   // output [7 : 0] m_axi_awid
            .m_axi_awaddr   (S_AXI_AWADDR   [0]),   // output [31 : 0] m_axi_awaddr
            .m_axi_awlen    (S_AXI_AWLEN    [0]),   // output [7 : 0] m_axi_awlen
            .m_axi_awsize   (S_AXI_AWSIZE   [0]),   // output [2 : 0] m_axi_awsize
            .m_axi_awburst  (S_AXI_AWBURST  [0]),   // output [1 : 0] m_axi_awburst
            .m_axi_awlock   (S_AXI_AWLOCK   [0]),   // output [1 : 0] m_axi_awlock
            .m_axi_awcache  (S_AXI_AWCACHE  [0]),   // output [3 : 0] m_axi_awcache
            .m_axi_awprot   (S_AXI_AWPROT   [0]),   // output [2 : 0] m_axi_awprot
            .m_axi_awqos    (S_AXI_AWQOS    [0]),   // output [3 : 0] m_axi_awqos
            .m_axi_awvalid  (S_AXI_AWVALID  [0]),   // output m_axi_awvalid
            .m_axi_awready  (S_AXI_AWREADY  [0]),   // input m_axi_awready
            .m_axi_wdata    (S_AXI_WDATA    [0]),   // output [127 : 0] m_axi_wdata
            .m_axi_wstrb    (S_AXI_WSTRB    [0]),   // output [15 : 0] m_axi_wstrb
            .m_axi_wlast    (S_AXI_WLAST    [0]),   // output m_axi_wlast
            .m_axi_wvalid   (S_AXI_WVALID   [0]),   // output m_axi_wvalid
            .m_axi_wready   (S_AXI_WREADY   [0]),   // input m_axi_wready
            .m_axi_bid      (S_AXI_BID),            // input [7 : 0] m_axi_bid
            .m_axi_bresp    (S_AXI_BRESP),          // input [1 : 0] m_axi_bresp
            .m_axi_bvalid   (S_AXI_BVALID   [0]),   // input m_axi_bvalid
            .m_axi_bready   (S_AXI_BREADY   [0]),   // output m_axi_bready
            .m_axi_arid     (S_AXI_ARID     [0]),   // output [7 : 0] m_axi_arid
            .m_axi_araddr   (S_AXI_ARADDR   [0]),   // output [31 : 0] m_axi_araddr
            .m_axi_arlen    (S_AXI_ARLEN    [0]),   // output [7 : 0] m_axi_arlen
            .m_axi_arsize   (S_AXI_ARSIZE   [0]),   // output [2 : 0] m_axi_arsize
            .m_axi_arburst  (S_AXI_ARBURST  [0]),   // output [1 : 0] m_axi_arburst
            .m_axi_arlock   (S_AXI_ARLOCK   [0]),   // output [1 : 0] m_axi_arlock
            .m_axi_arcache  (S_AXI_ARCACHE  [0]),   // output [3 : 0] m_axi_arcache
            .m_axi_arprot   (S_AXI_ARPROT   [0]),   // output [2 : 0] m_axi_arprot
            .m_axi_arqos    (S_AXI_ARQOS    [0]),   // output [3 : 0] m_axi_arqos
            .m_axi_arvalid  (S_AXI_ARVALID  [0]),   // output m_axi_arvalid
            .m_axi_arready  (S_AXI_ARREADY  [0]),   // input m_axi_arready
            .m_axi_rid      (S_AXI_RID),            // input [7 : 0] m_axi_rid
            .m_axi_rdata    (S_AXI_RDATA),          // input [127 : 0] m_axi_rdata
            .m_axi_rresp    (S_AXI_RRESP),          // input [1 : 0] m_axi_rresp
            .m_axi_rlast    (S_AXI_RLAST),          // input m_axi_rlast
            .m_axi_rvalid   (S_AXI_RVALID   [0]),   // input m_axi_rvalid
            .m_axi_rready   (S_AXI_RREADY   [0])    // output m_axi_rready
        );
		////////////////////////
		// END OF SLAVE FIFOS //
		////////////////////////
		
		// if there is only 1 slave port, we don't need an interconnect, we just 
		// need to connect the slave 0 FIFO to the master FIFO
		if (ports == 1) begin
			always @ (*) begin
				M_AXI_AWID       	= S_AXI_AWID	[0];
				M_AXI_AWADDR     	= S_AXI_AWADDR	[0];
				M_AXI_AWLEN     	= S_AXI_AWLEN	[0];
				M_AXI_AWSIZE     	= S_AXI_AWSIZE	[0];
				M_AXI_AWBURST    	= S_AXI_AWBURST	[0];
				M_AXI_AWLOCK     	= S_AXI_AWLOCK	[0];
				M_AXI_AWCACHE    	= S_AXI_AWCACHE	[0];
				M_AXI_AWPROT     	= S_AXI_AWPROT	[0];
				M_AXI_AWQOS      	= S_AXI_AWQOS	[0];
				S_AXI_AWREADY    	= M_AXI_AWREADY;
				
				M_AXI_WDATA      	= S_AXI_WDATA	[0];
				M_AXI_WSTRB      	= S_AXI_WSTRB	[0];
				M_AXI_WLAST      	= S_AXI_WLAST	[0];
				S_AXI_WREADY     	= M_AXI_WREADY;
				
				M_AXI_ARID       	= S_AXI_ARID	[0];
				M_AXI_ARADDR     	= S_AXI_ARADDR	[0];
				M_AXI_ARLEN      	= S_AXI_ARLEN	[0];
				M_AXI_ARSIZE     	= S_AXI_ARSIZE	[0];
				M_AXI_ARBURST    	= S_AXI_ARBURST	[0];
				M_AXI_ARLOCK     	= S_AXI_ARLOCK	[0];
				M_AXI_ARCACHE    	= S_AXI_ARCACHE	[0];
				M_AXI_ARPROT     	= S_AXI_ARPROT	[0];
				M_AXI_ARQOS      	= S_AXI_ARQOS	[0];
				M_AXI_ARVALID    	= S_AXI_ARVALID [0];
				S_AXI_ARREADY    	= M_AXI_ARREADY;
			end
            
			assign M_AXI_AWVALID   	= S_AXI_AWVALID [0];
			
			assign M_AXI_WVALID     = S_AXI_WVALID  [0];
            
            assign S_AXI_BID        = M_AXI_BID;
            assign S_AXI_BRESP      = M_AXI_BRESP;
            assign S_AXI_BVALID[0]  = M_AXI_BVALID;
            assign M_AXI_BREADY     = S_AXI_BREADY  [0];
			
            assign S_AXI_RID        = M_AXI_RID;
            assign S_AXI_RDATA      = M_AXI_RDATA;
            assign S_AXI_RRESP      = M_AXI_RRESP;
            assign S_AXI_RLAST      = M_AXI_RLAST;
            assign S_AXI_RVALID[0]  = M_AXI_RVALID;
            assign M_AXI_RREADY     = S_AXI_RREADY  [0];
		end
		// if there is more than 1 slave port, then we need the full interconnect
		else begin
			///////////////////////
			// read addr arbiter //
			///////////////////////
			wire                                loadRdAddrMux;
			wire    [LOG_C_NUM_SLAVE_PORTS-1:0] readAddrSlave;
			PicoAXIArbiter #(
				.C_NUM_SLAVE_PORTS      (C_NUM_SLAVE_PORTS),
				.LOG_C_NUM_SLAVE_PORTS  (LOG_C_NUM_SLAVE_PORTS)
			)
			readAddrArbiter
			(
				.clk                    (INTERCONNECT_ACLK),
				.rst                    (~INTERCONNECT_ARESETN_Q),
				
				.s_axi_valid            (S_AXI_ARVALID),
				.currentSlave           (readAddrSlave),
				.m_axi_ready            (loadRdAddrMux)
			);
			// read addr mux 
			// load the mux register when it is not holding valid data or when the
			// downstream device is taking the data currently stored in the register
			assign loadRdAddrMux = ~M_AXI_ARVALID | M_AXI_ARREADY;
			always @ (posedge INTERCONNECT_ACLK) begin
				if (!INTERCONNECT_ARESETN_Q) begin
					M_AXI_ARID      <= 0;
					M_AXI_ARVALID   <= 0;
					M_AXI_ARADDR    <= 0;
					M_AXI_ARLEN     <= 0;
					M_AXI_ARSIZE    <= 0;
					M_AXI_ARBURST   <= 0;
					M_AXI_ARLOCK    <= 0;
					M_AXI_ARCACHE   <= 0;
					M_AXI_ARPROT    <= 0;
					M_AXI_ARQOS     <= 0;
				end else if (loadRdAddrMux) begin
					M_AXI_ARID      <= {readAddrSlave,S_AXI_ARID[readAddrSlave]};
					M_AXI_ARVALID   <= S_AXI_ARVALID[readAddrSlave];
					M_AXI_ARADDR    <= S_AXI_ARADDR [readAddrSlave];
					M_AXI_ARLEN     <= S_AXI_ARLEN  [readAddrSlave];
					M_AXI_ARSIZE    <= S_AXI_ARSIZE [readAddrSlave];
					M_AXI_ARBURST   <= S_AXI_ARBURST[readAddrSlave];
					M_AXI_ARLOCK    <= S_AXI_ARLOCK [readAddrSlave];
					M_AXI_ARCACHE   <= S_AXI_ARCACHE[readAddrSlave];
					M_AXI_ARPROT    <= S_AXI_ARPROT [readAddrSlave];
					M_AXI_ARQOS     <= S_AXI_ARQOS  [readAddrSlave];
				end 
			end
			// ack the address from the proper slave port if loading the mux with new
			// data
			always @ (*) begin
				if (loadRdAddrMux) begin
					for(i=0; i<C_NUM_SLAVE_PORTS; i=i+1) begin
						if (i==readAddrSlave) begin
							S_AXI_ARREADY[i] = 1'b1;
						end else begin
							S_AXI_ARREADY[i] = 1'b0;
						end
					end 
				end else begin
					S_AXI_ARREADY = 0;
				end
			end
			///////////////////////////
			// end read addr arbiter //
			///////////////////////////

			/////////////////////////////
			// write addr/data arbiter //
			/////////////////////////////
			reg                                 WrAddrMuxValid;
			wire                                loadWrAddrMux;
			
			reg                                 WrDataMuxValid;
			wire                                loadWrDataMux;
			
			wire    [C_NUM_SLAVE_PORTS-1:0]     writeInfoValid;
			
			wire    [LOG_C_NUM_SLAVE_PORTS-1:0] writeAddrSlave;
			wire    [LOG_C_NUM_SLAVE_PORTS-1:0] writeDataSlave;
			reg     [LOG_C_NUM_SLAVE_PORTS-1:0] currentSlave;
			
			PicoAXIArbiter #(
				.C_NUM_SLAVE_PORTS      (C_NUM_SLAVE_PORTS),
				.LOG_C_NUM_SLAVE_PORTS  (LOG_C_NUM_SLAVE_PORTS)
			)
			writeAddrArbiter
			(
				.clk                    (INTERCONNECT_ACLK),
				.rst                    (~INTERCONNECT_ARESETN_Q),
				
				.s_axi_valid            (writeInfoValid),
				.currentSlave           (writeAddrSlave),
				.m_axi_ready            (loadWrAddrMux)
			);
			
			// both write address and data must be valid before starting a write
			// transaction from a slave
			assign writeInfoValid = S_AXI_AWVALID & S_AXI_WVALID;
			
			// load the address mux when:
			// 1) address mux does not hold valid data
			// or 
			// 2) address mux holds valid data, but it is being transmitted with the
			//    wlast signal of the valid data
			assign loadWrAddrMux = ~WrAddrMuxValid | (M_AXI_AWVALID & M_AXI_AWREADY);

			// load the data mux when:
			// 1) data mux does not hold valid data
			// or 
			// 2) data mux holds valid data but it is being transmitted to master port
			// 
			// from:
			// a) writeAddrSlave when wlast is asserted and valid in the mux
			// b) currentSlave when wlast is not asserted (valid) or not valid in the mux
			assign loadWrDataMux = ~WrDataMuxValid | (M_AXI_WVALID & M_AXI_WREADY);
			assign writeDataSlave = loadWrAddrMux ? writeAddrSlave : currentSlave;

			// don't assert valid unless both the address and data can be written if (WLAST)
			// note: this next line is a no-no for AXI protocol (valid should not depend
			// upon ready) but this should work because the ready signal is simply
			// the full signal from a fifo
			assign M_AXI_WVALID = WrDataMuxValid & (~M_AXI_WLAST | (M_AXI_AWREADY & M_AXI_WREADY));
			assign M_AXI_AWVALID = WrAddrMuxValid & M_AXI_WVALID & M_AXI_WLAST;
			
			// write addr mux 
			// -load the mux register when it is not holding valid data or when the
			// downstream device is taking the data currently stored in the register
			// -must hold the data in the mux if the address fifo is currently full
			always @ (posedge INTERCONNECT_ACLK) begin
				// waddr
				if (!INTERCONNECT_ARESETN_Q) begin
					WrAddrMuxValid  <= 0;
					M_AXI_AWID      <= 0;
					M_AXI_AWADDR    <= 0;
					M_AXI_AWLEN     <= 0;
					M_AXI_AWSIZE    <= 0;
					M_AXI_AWBURST   <= 0;
					M_AXI_AWLOCK    <= 0;
					M_AXI_AWCACHE   <= 0;
					M_AXI_AWPROT    <= 0;
					M_AXI_AWQOS     <= 0;
					currentSlave    <= 0;
				end else if (loadWrAddrMux) begin
					WrAddrMuxValid  <= writeInfoValid[writeAddrSlave];
					M_AXI_AWID      <= {writeAddrSlave, S_AXI_AWID[writeAddrSlave]};
					M_AXI_AWADDR    <= S_AXI_AWADDR [writeAddrSlave];
					M_AXI_AWLEN     <= S_AXI_AWLEN  [writeAddrSlave];
					M_AXI_AWSIZE    <= S_AXI_AWSIZE [writeAddrSlave];
					M_AXI_AWBURST   <= S_AXI_AWBURST[writeAddrSlave];
					M_AXI_AWLOCK    <= S_AXI_AWLOCK [writeAddrSlave];
					M_AXI_AWCACHE   <= S_AXI_AWCACHE[writeAddrSlave];
					M_AXI_AWPROT    <= S_AXI_AWPROT [writeAddrSlave];
					M_AXI_AWQOS     <= S_AXI_AWQOS  [writeAddrSlave];
					currentSlave    <= writeAddrSlave;
				end

				// wdata
				if (!INTERCONNECT_ARESETN_Q) begin
					WrDataMuxValid  <= 0;
					M_AXI_WDATA     <= 0;
					M_AXI_WSTRB     <= 0;
					M_AXI_WLAST     <= 0;
				end else if (loadWrDataMux) begin
					// first piece of data is valid only if both the address and data are valid
					if (loadWrAddrMux) begin
						WrDataMuxValid <= writeInfoValid[writeDataSlave];
					end 
					// subsequent data is valid if the data is valid
					else begin
						WrDataMuxValid <= S_AXI_WVALID[writeDataSlave];
					end
					M_AXI_WDATA     <= S_AXI_WDATA[writeDataSlave];
					M_AXI_WSTRB     <= S_AXI_WSTRB[writeDataSlave];
					M_AXI_WLAST     <= S_AXI_WLAST[writeDataSlave];
				end
			end

			// ack the address/data from the proper slave port if loading the mux with new data
			always @ (*) begin
				// only load the address if the address and data are valid
				S_AXI_AWREADY = 0;
				if (loadWrAddrMux && writeInfoValid[writeAddrSlave]) begin
					S_AXI_AWREADY[writeAddrSlave] = 1'b1;
				end
				
				// first load of data for a new transmission is only valid if both the
				// address and data are valid
				S_AXI_WREADY = 0;
				if (loadWrAddrMux) begin
					if (loadWrDataMux && writeInfoValid[writeDataSlave]) begin
						S_AXI_WREADY[writeDataSlave] = 1'b1;
					end
				end 
				// subsequent data loads only require the data to be valid
				else begin
					if (loadWrDataMux && S_AXI_WVALID[writeDataSlave]) begin
						S_AXI_WREADY[writeDataSlave] = 1'b1;
					end
				end
			end
			/////////////////////////////////
			// end write addr/data arbiter //
			/////////////////////////////////
		   
			/////////////////////
			// read data demux //
			/////////////////////
			PicoAXIDemux #(
				.C_NUM_SLAVE_PORTS      (C_NUM_SLAVE_PORTS),
				.C_AXI_SLAVE_ID_WIDTH   (C_AXI_ID_WIDTH-4),
				.C_AXI_MASTER_ID_WIDTH  (C_AXI_ID_WIDTH),
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH)
			)
			readDataDemux
			(
				.clk                    (INTERCONNECT_ACLK),
				.rst                    (~INTERCONNECT_ARESETN_Q),
				
				.s_axi_id               (S_AXI_RID),
				.s_axi_valid            (S_AXI_RVALID),
				.s_axi_ready            (S_AXI_RREADY),
				.s_axi_data             (S_AXI_RDATA),
				.s_axi_last             (S_AXI_RLAST),
				.s_axi_resp             (S_AXI_RRESP),

				.m_axi_id               (M_AXI_RID),
				.m_axi_valid            (M_AXI_RVALID),
				.m_axi_ready            (M_AXI_RREADY),
				.m_axi_data             (M_AXI_RDATA),
				.m_axi_last             (M_AXI_RLAST),
				.m_axi_resp             (M_AXI_RRESP)
			);
			/////////////////////////
			// end read data demux //
			/////////////////////////
		   
			//////////////////////////
			// write response demux //
			//////////////////////////
			PicoAXIDemux #(
				.C_NUM_SLAVE_PORTS      (C_NUM_SLAVE_PORTS),
				.C_AXI_SLAVE_ID_WIDTH   (C_AXI_ID_WIDTH-4),
				.C_AXI_MASTER_ID_WIDTH  (C_AXI_ID_WIDTH),
				.C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH)
			)
			writeReponseDemux
			(
				.clk                    (INTERCONNECT_ACLK),
				.rst                    (~INTERCONNECT_ARESETN_Q),
				
				.s_axi_id               (S_AXI_BID),
				.s_axi_valid            (S_AXI_BVALID),
				.s_axi_ready            (S_AXI_BREADY),
				.s_axi_resp             (S_AXI_BRESP),

				.m_axi_id               (M_AXI_BID),
				.m_axi_valid            (M_AXI_BVALID),
				.m_axi_ready            (M_AXI_BREADY),
				.m_axi_resp             (M_AXI_BRESP)
			);
			//////////////////////////////
			// end write response demux //
			//////////////////////////////
		end
		
    end // create_slave_interfaces
    endgenerate
    
    ///////////////////////////
    // master interface fifo //
    ///////////////////////////
    PicoAXIFifo #(
        .C_AXI_DATA_WIDTH       (C_AXI_DATA_WIDTH),
        .C_AXI_ADDR_WIDTH       (C_AXI_ADDR_WIDTH),
        .C_AXI_ID_WIDTH         (C_AXI_ID_WIDTH)
    )
    master 
    (
        .m_aclk         (M00_AXI_ACLK),         // input m_aclk
        .s_aclk         (INTERCONNECT_ACLK),    // input s_aclk
		.s_aresetn      (INTERCONNECT_ARESETN_Q), // input s_aresetn
        .s_axi_awid     (M_AXI_AWID),           // input [7 : 0] s_axi_awid
        .s_axi_awaddr   (M_AXI_AWADDR),         // input [31 : 0] s_axi_awaddr
        .s_axi_awlen    (M_AXI_AWLEN),          // input [7 : 0] s_axi_awlen
        .s_axi_awsize   (M_AXI_AWSIZE),         // input [2 : 0] s_axi_awsize
        .s_axi_awburst  (M_AXI_AWBURST),        // input [1 : 0] s_axi_awburst
        .s_axi_awlock   (M_AXI_AWLOCK),         // input [1 : 0] s_axi_awlock
        .s_axi_awcache  (M_AXI_AWCACHE),        // input [3 : 0] s_axi_awcache
        .s_axi_awprot   (M_AXI_AWPROT),         // input [2 : 0] s_axi_awprot
        .s_axi_awqos    (M_AXI_AWQOS),          // input [3 : 0] s_axi_awqos
        .s_axi_awvalid  (M_AXI_AWVALID),        // input s_axi_awvalid
        .s_axi_awready  (M_AXI_AWREADY),        // output s_axi_awready
        .s_axi_wdata    (M_AXI_WDATA),          // input [127 : 0] s_axi_wdata
        .s_axi_wstrb    (M_AXI_WSTRB),          // input [15 : 0] s_axi_wstrb
        .s_axi_wlast    (M_AXI_WLAST),          // input s_axi_wlast
        .s_axi_wvalid   (M_AXI_WVALID),         // input s_axi_wvalid
        .s_axi_wready   (M_AXI_WREADY),         // output s_axi_wready
        .s_axi_bid      (M_AXI_BID),            // output [7 : 0] s_axi_bid
        .s_axi_bresp    (M_AXI_BRESP),          // output [1 : 0] s_axi_bresp
        .s_axi_bvalid   (M_AXI_BVALID),         // output s_axi_bvalid
        .s_axi_bready   (M_AXI_BREADY),         // input s_axi_bready
        .s_axi_arid     (M_AXI_ARID),           // input [7 : 0] s_axi_arid
        .s_axi_araddr   (M_AXI_ARADDR),         // input [31 : 0] s_axi_araddr
        .s_axi_arlen    (M_AXI_ARLEN),          // input [7 : 0] s_axi_arlen
        .s_axi_arsize   (M_AXI_ARSIZE),         // input [2 : 0] s_axi_arsize
        .s_axi_arburst  (M_AXI_ARBURST),        // input [1 : 0] s_axi_arburst
        .s_axi_arlock   (M_AXI_ARLOCK),         // input [1 : 0] s_axi_arlock
        .s_axi_arcache  (M_AXI_ARCACHE),        // input [3 : 0] s_axi_arcache
        .s_axi_arprot   (M_AXI_ARPROT),         // input [2 : 0] s_axi_arprot
        .s_axi_arqos    (M_AXI_ARQOS),          // input [3 : 0] s_axi_arqos
        .s_axi_arvalid  (M_AXI_ARVALID),        // input s_axi_arvalid
        .s_axi_arready  (M_AXI_ARREADY),        // output s_axi_arready
        .s_axi_rid      (M_AXI_RID),            // output [7 : 0] s_axi_rid
        .s_axi_rdata    (M_AXI_RDATA),          // output [127 : 0] s_axi_rdata
        .s_axi_rresp    (M_AXI_RRESP),          // output [1 : 0] s_axi_rresp
        .s_axi_rlast    (M_AXI_RLAST),          // output s_axi_rlast
        .s_axi_rvalid   (M_AXI_RVALID),         // output s_axi_rvalid
        .s_axi_rready   (M_AXI_RREADY),         // input s_axi_rready
        .m_axi_awid     (M00_AXI_AWID),         // output [7 : 0] m_axi_awid
        .m_axi_awaddr   (M00_AXI_AWADDR),       // output [31 : 0] m_axi_awaddr
        .m_axi_awlen    (M00_AXI_AWLEN),        // output [7 : 0] m_axi_awlen
        .m_axi_awsize   (M00_AXI_AWSIZE),       // output [2 : 0] m_axi_awsize
        .m_axi_awburst  (M00_AXI_AWBURST),      // output [1 : 0] m_axi_awburst
        .m_axi_awlock   (M00_AXI_AWLOCK),       // output [1 : 0] m_axi_awlock
        .m_axi_awcache  (M00_AXI_AWCACHE),      // output [3 : 0] m_axi_awcache
        .m_axi_awprot   (M00_AXI_AWPROT),       // output [2 : 0] m_axi_awprot
        .m_axi_awqos    (M00_AXI_AWQOS),        // output [3 : 0] m_axi_awqos
        .m_axi_awvalid  (M00_AXI_AWVALID),      // output m_axi_awvalid
        .m_axi_awready  (M00_AXI_AWREADY),      // input m_axi_awready
        .m_axi_wdata    (M00_AXI_WDATA),        // output [127 : 0] m_axi_wdata
        .m_axi_wstrb    (M00_AXI_WSTRB),        // output [15 : 0] m_axi_wstrb
        .m_axi_wlast    (M00_AXI_WLAST),        // output m_axi_wlast
        .m_axi_wvalid   (M00_AXI_WVALID),       // output m_axi_wvalid
        .m_axi_wready   (M00_AXI_WREADY),       // input m_axi_wready
        .m_axi_bid      (M00_AXI_BID),          // input [7 : 0] m_axi_bid
        .m_axi_bresp    (M00_AXI_BRESP),        // input [1 : 0] m_axi_bresp
        .m_axi_bvalid   (M00_AXI_BVALID),       // input m_axi_bvalid
        .m_axi_bready   (M00_AXI_BREADY),       // output m_axi_bready
        .m_axi_arid     (M00_AXI_ARID),         // output [7 : 0] m_axi_arid
        .m_axi_araddr   (M00_AXI_ARADDR),       // output [31 : 0] m_axi_araddr
        .m_axi_arlen    (M00_AXI_ARLEN),        // output [7 : 0] m_axi_arlen
        .m_axi_arsize   (M00_AXI_ARSIZE),       // output [2 : 0] m_axi_arsize
        .m_axi_arburst  (M00_AXI_ARBURST),      // output [1 : 0] m_axi_arburst
        .m_axi_arlock   (M00_AXI_ARLOCK),       // output [1 : 0] m_axi_arlock
        .m_axi_arcache  (M00_AXI_ARCACHE),      // output [3 : 0] m_axi_arcache
        .m_axi_arprot   (M00_AXI_ARPROT),       // output [2 : 0] m_axi_arprot
        .m_axi_arqos    (M00_AXI_ARQOS),        // output [3 : 0] m_axi_arqos
        .m_axi_arvalid  (M00_AXI_ARVALID),      // output m_axi_arvalid
        .m_axi_arready  (M00_AXI_ARREADY),      // input m_axi_arready
        .m_axi_rid      (M00_AXI_RID),          // input [7 : 0] m_axi_rid
        .m_axi_rdata    (M00_AXI_RDATA),        // input [127 : 0] m_axi_rdata
        .m_axi_rresp    (M00_AXI_RRESP),        // input [1 : 0] m_axi_rresp
        .m_axi_rlast    (M00_AXI_RLAST),        // input m_axi_rlast
        .m_axi_rvalid   (M00_AXI_RVALID),       // input m_axi_rvalid
        .m_axi_rready   (M00_AXI_RREADY)        // output m_axi_rready
    );

    // assign all the reset out signals to their respective values
    assign S00_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S01_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S02_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S03_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S04_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S05_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S06_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S07_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S08_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S09_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S10_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S11_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S12_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S13_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S14_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign S15_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;
    assign M00_AXI_ARESET_OUT_N = INTERCONNECT_ARESETN_Q;

endmodule
