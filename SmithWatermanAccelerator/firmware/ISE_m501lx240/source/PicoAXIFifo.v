/*
* File Name : PicoAXIFifo.v
*
* Description :  Set of asynchronous FIFOs for full AXI4 interface.  This uses
*                a set of fifos for each AXI4 port (aw, w, b, ar, r).  The
*                fifos are used to cross clock domains, from the s_aclk to the
*                m_aclk domain.  S_aclk is always associated with the slave
*                ports.  To be explicit, the slave side for all ports (aw, w,
*                b, ar, r) are on the same side, as shown in the diagram
*                below.
*
*                       s_aclk              |           m_aclk
*                   -------------------------------------------------
*                   |   slave_aw    ->->    |   ->->    master_aw   |
*                   |                       |                       |
*                   |                       |                       |
*                   |   slave_w     ->->    |   ->->    master_w    |
*                   |                       |                       |
*                   |                       |                       |
*                   |   slave_b     <-<-    |   <-<-    master_b    |
*                   |                       |                       |
*                   |                       |                       |
*                   |   slave_ar    ->->    |   ->->    master_ar   |
*                   |                       |                       |
*                   |                       |                       |
*                   |   slave_r     <-<-    |   <-<-    master_r    |
*                   -------------------------------------------------
*
*
* Creation Date : Tue 23 Aug 2011 02:38:01 PM PDT
*
* Author : Corey Olson
*
* Last Modified : Wed 06 Jul 2011 02:13:58 PM PDT
*
* Copyright 2011 Pico Computing, Inc.
*/
module PicoAXIFifo #(
    parameter C_AXI_DATA_WIDTH      = 128,  // width of the axi data
    parameter C_AXI_ADDR_WIDTH      = 32,   // address width
    parameter C_AXI_ID_WIDTH        = 8     // id width (same for master and slave)
    )
    (
    // slave ports
    input                               s_aclk,
    input                               s_aresetn,      // need to synchronize the resetn 
                                                        //  signal to the s_aclk domain because 
                                                        //  the input reset is synchronous to 
                                                        //  the m_aclk domain

    input   [C_AXI_ID_WIDTH-1:0]        s_axi_awid,
    input   [C_AXI_ADDR_WIDTH-1:0]      s_axi_awaddr,
    input   [7:0]                       s_axi_awlen,
    input   [2:0]                       s_axi_awsize,
    input   [1:0]                       s_axi_awburst,
    input                               s_axi_awlock,
    input   [3:0]                       s_axi_awcache,
    input   [2:0]                       s_axi_awprot,
    input   [3:0]                       s_axi_awqos,
    input                               s_axi_awvalid,
    output                              s_axi_awready,

    input   [C_AXI_DATA_WIDTH-1:0]      s_axi_wdata,
    input   [C_AXI_DATA_WIDTH/8-1:0]    s_axi_wstrb,
    input                               s_axi_wlast,
    input                               s_axi_wvalid,
    output                              s_axi_wready,
    
    output  [C_AXI_ID_WIDTH-1:0]        s_axi_bid,
    output  [1:0]                       s_axi_bresp,
    output                              s_axi_bvalid,
    input                               s_axi_bready,

    input   [C_AXI_ID_WIDTH-1:0]        s_axi_arid,
    input   [C_AXI_ADDR_WIDTH-1:0]      s_axi_araddr,
    input   [7:0]                       s_axi_arlen,
    input   [2:0]                       s_axi_arsize,
    input   [1:0]                       s_axi_arburst,
    input                               s_axi_arlock,
    input   [3:0]                       s_axi_arcache,
    input   [2:0]                       s_axi_arprot,
    input   [3:0]                       s_axi_arqos,
    input                               s_axi_arvalid,
    output                              s_axi_arready,

    output  [C_AXI_ID_WIDTH-1:0]        s_axi_rid,
    output  [C_AXI_DATA_WIDTH-1:0]      s_axi_rdata,
    output  [1:0]                       s_axi_rresp,
    output                              s_axi_rlast,
    output                              s_axi_rvalid,
    input                               s_axi_rready,
    
    // master ports
    input                               m_aclk,
    
    output  [C_AXI_ID_WIDTH-1:0]        m_axi_awid,
    output  [C_AXI_ADDR_WIDTH-1:0]      m_axi_awaddr,
    output  [7:0]                       m_axi_awlen,
    output  [2:0]                       m_axi_awsize,
    output  [1:0]                       m_axi_awburst,
    output                              m_axi_awlock,
    output  [3:0]                       m_axi_awcache,
    output  [2:0]                       m_axi_awprot,
    output  [3:0]                       m_axi_awqos,
    output                              m_axi_awvalid,
    input                               m_axi_awready,
    
    output  [C_AXI_DATA_WIDTH-1:0]      m_axi_wdata,
    output  [C_AXI_DATA_WIDTH/8-1:0]    m_axi_wstrb,
    output                              m_axi_wlast,
    output                              m_axi_wvalid,
    input                               m_axi_wready,
    
    input   [C_AXI_ID_WIDTH-1:0]        m_axi_bid,
    input   [1:0]                       m_axi_bresp,
    input                               m_axi_bvalid,
    output                              m_axi_bready,

    output  [C_AXI_ID_WIDTH-1:0]        m_axi_arid,
    output  [C_AXI_ADDR_WIDTH-1:0]      m_axi_araddr,
    output  [7:0]                       m_axi_arlen,
    output  [2:0]                       m_axi_arsize,
    output  [1:0]                       m_axi_arburst,
    output                              m_axi_arlock,
    output  [3:0]                       m_axi_arcache,
    output  [2:0]                       m_axi_arprot,
    output  [3:0]                       m_axi_arqos,
    output                              m_axi_arvalid,
    input                               m_axi_arready,
    
    input   [C_AXI_ID_WIDTH-1:0]        m_axi_rid,
    input   [C_AXI_DATA_WIDTH-1:0]      m_axi_rdata,
    input   [1:0]                       m_axi_rresp,
    input                               m_axi_rlast,
    input                               m_axi_rvalid,
    output                              m_axi_rready
    );

    ////////////////////////
    // register the reset //
    ////////////////////////
    // synchronize to the slave clock
    reg s_aresetn_0=1;
    reg s_aresetn_q=1;
    always @ (posedge s_aclk) begin
        s_aresetn_0 <= s_aresetn;
        s_aresetn_q <= s_aresetn_0;
    end

    // synchronize to the master clock
    reg m_aresetn_0=1;
    reg m_aresetn_q=1;
    always @ (posedge m_aclk) begin
        m_aresetn_0 <= s_aresetn;
        m_aresetn_q <= m_aresetn_0;
    end

    ////////////////
    // waddr fifo //
    ////////////////
    wire    waddrFull;
    wire    waddrEmpty;
    
    // data flows from slave to master
    assign  s_axi_awready = ~waddrFull;
    assign  m_axi_awvalid = ~waddrEmpty;
    
    (* RLOC = "X0Y0" *)
    asyncFifoBRAM #(
        .WIDTH  (C_AXI_ID_WIDTH+C_AXI_ADDR_WIDTH+8+3+2+1+4+3+4)
    )
    waddrFifo 
    (
        // write on the slave clock
        .wr_clk (s_aclk),
        .wr_rst (~s_aresetn_q),
        .din    ({s_axi_awid,
                  s_axi_awaddr,
                  s_axi_awlen,
                  s_axi_awsize,
                  s_axi_awburst,
                  s_axi_awlock,
                  s_axi_awcache,
                  s_axi_awprot,
                  s_axi_awqos}),
        .wr_en  (s_axi_awvalid),
        
        // read on the master clock
        .rd_clk (m_aclk),
        .rd_rst (~m_aresetn_q),
        .dout   ({m_axi_awid,
                  m_axi_awaddr,
                  m_axi_awlen,
                  m_axi_awsize,
                  m_axi_awburst,
                  m_axi_awlock,
                  m_axi_awcache,
                  m_axi_awprot,
                  m_axi_awqos}),
        .rd_en  (m_axi_awready),

        // status
        .full   (waddrFull),
        .empty  (waddrEmpty)
    );

    ////////////////
    // wdata fifo //
    ////////////////
    wire    wdataFull;
    wire    wdataEmpty;
    
    // data flows from slave to master
    assign  s_axi_wready = ~wdataFull;
    assign  m_axi_wvalid = ~wdataEmpty;
    
    (* RLOC = "X0Y1" *)
    asyncFifoBRAM #(
        .WIDTH  (C_AXI_DATA_WIDTH+(C_AXI_DATA_WIDTH/8)+1)
    )
    wdataFifo 
    (
        // write on the slave clock
        .wr_clk (s_aclk),
        .wr_rst (~s_aresetn_q),
        .din    ({s_axi_wstrb,
                  s_axi_wlast,
                  s_axi_wdata}),
        .wr_en  (s_axi_wvalid),
        
        // read on the master clock
        .rd_clk (m_aclk),
        .rd_rst (~m_aresetn_q),
        .dout   ({m_axi_wstrb,
                  m_axi_wlast,
                  m_axi_wdata}),
        .rd_en  (m_axi_wready),

        // status
        .full   (wdataFull),
        .empty  (wdataEmpty)
    );
    
    ////////////
    // b fifo //
    ////////////
    wire    bFull;
    wire    bEmpty;
    
    // data flows from master to slave
    assign  m_axi_bready = ~bFull;
    assign  s_axi_bvalid = ~bEmpty;
    
    asyncFifoBRAM #(
        .WIDTH  (C_AXI_ID_WIDTH+2)
    )
    bFifo 
    (
        // write on the master clock
        .wr_clk (m_aclk),
        .wr_rst (~m_aresetn_q),
        .din    ({m_axi_bid,
                  m_axi_bresp}),
        .wr_en  (m_axi_bvalid),
        
        // read on the slave clock
        .rd_clk (s_aclk),
        .rd_rst (~s_aresetn_q),
        .dout   ({s_axi_bid,
                  s_axi_bresp}),
        .rd_en  (s_axi_bready),

        // status
        .full   (bFull),
        .empty  (bEmpty)
    );
    
    ////////////////
    // raddr fifo //
    ////////////////
    wire    raddrFull;
    wire    raddrEmpty;
    
    // data flows from slave to master
    assign  s_axi_arready = ~raddrFull;
    assign  m_axi_arvalid = ~raddrEmpty;
    
    asyncFifoBRAM #(
        .WIDTH  (C_AXI_ID_WIDTH+C_AXI_ADDR_WIDTH+8+3+2+1+4+3+4)
    )
    raddrFifo 
    (
        // write on the slave clock
        .wr_clk (s_aclk),
        .wr_rst (~s_aresetn_q),
        .din    ({s_axi_arid,
                  s_axi_araddr,
                  s_axi_arlen,
                  s_axi_arsize,
                  s_axi_arburst,
                  s_axi_arlock,
                  s_axi_arcache,
                  s_axi_arprot,
                  s_axi_arqos}),
        .wr_en  (s_axi_arvalid),
        
        // read on the master clock
        .rd_clk (m_aclk),
        .rd_rst (~m_aresetn_q),
        .dout   ({m_axi_arid,
                  m_axi_araddr,
                  m_axi_arlen,
                  m_axi_arsize,
                  m_axi_arburst,
                  m_axi_arlock,
                  m_axi_arcache,
                  m_axi_arprot,
                  m_axi_arqos}),
        .rd_en  (m_axi_arready),

        // status
        .full   (raddrFull),
        .empty  (raddrEmpty)
    );
    
    ////////////////
    // rdata fifo //
    ////////////////
    wire    rdataFull;
    wire    rdataEmpty;
    
    // data flows from master to slave
    assign  m_axi_rready = ~rdataFull;
    assign  s_axi_rvalid = ~rdataEmpty;
    
    asyncFifoBRAM #(
        .WIDTH  (C_AXI_ID_WIDTH+C_AXI_DATA_WIDTH+2+1)
    )
    rdataFifo 
    (
        // write on the master clock
        .wr_clk (m_aclk),
        .wr_rst (~m_aresetn_q),
        .din    ({m_axi_rid,
                  m_axi_rresp,
                  m_axi_rlast,
                  m_axi_rdata}),
        .wr_en  (m_axi_rvalid),
        
        // read on the slave clock
        .rd_clk (s_aclk),
        .rd_rst (~s_aresetn_q),
        .dout   ({s_axi_rid,
                  s_axi_rresp,
                  s_axi_rlast,
                  s_axi_rdata}),
        .rd_en  (s_axi_rready),

        // status
        .full   (rdataFull),
        .empty  (rdataEmpty)
    );

endmodule
