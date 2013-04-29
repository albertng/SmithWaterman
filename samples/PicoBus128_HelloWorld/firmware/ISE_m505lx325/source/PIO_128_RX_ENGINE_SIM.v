//-----------------------------------------------------------------------------
//
// (c) Copyright 2009-2010 Xilinx, Inc. All rights reserved.
//
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
//
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
//
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
//
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
//
//-----------------------------------------------------------------------------
// Project    : Virtex-6 Integrated Block for PCI Express
// File       : PIO_128_RX_ENGINE.v
// Version    : 2.1
//--
//-- Description: 128 bit Local-Link Receive Unit.
//--
//--------------------------------------------------------------------------------

`timescale 1ns/1ns


module PIO_128_RX_ENGINE_SIM #(
  parameter C_DATA_WIDTH = 128,            // RX/TX interface data width
  parameter TCQ = 1,

  // Do not override parameters below this line
  parameter STRB_WIDTH = C_DATA_WIDTH / 8               // TSTRB width
) (
    input              clk,
    input              rst_n,
    
    //input [11:0]        read_log,
    //output reg [7:0]    read_log_inx,
    //output reg [7:0]    last_cpld_tag,
    
    output [127:0]      stream_data,
    output [9:0]        stream_inx,
    output              stream_valid,
    output              stream_desc,
    output reg [15:0]   stream_tag,
    
    input [127:0]       rx_hdr,
    input [127:0]       rx_data,
    //input               rx_valid,
    input               rx_sof,
    input [7:0]         rx_bar_hit,

  /*
                         * Memory Read data handshake with Completion
                         * transmit unit. Transmit unit reponds to
                         * req_compl assertion and responds with compl_done
                         * assertion when a Completion w/ data is transmitted.
                         */

    output             req_compl_o,
    output reg         req_compl_wd_o,

    input              compl_done_i,

    output reg [2:0]   req_tc_o,             // Memory Read TC
    output reg         req_td_o,             // Memory Read TD
    output reg         req_ep_o,             // Memory Read EP
    output reg [1:0]   req_attr_o,           // Memory Read Attribute
    output reg [9:0]   req_len_o,            // Memory Read Length (1DW)
    output reg [15:0]  req_rid_o,            // Memory Read Requestor ID
    output reg [7:0]   req_tag_o,            // Memory Read Tag
    output reg [7:0]   req_be_o,             // Memory Read Byte Enables
    output reg [63:0]  req_addr_o,           // Memory Read Address

/*
                         * Memory interface used to save 1 DW data received
                         * on Memory Write 32 TLP. Data extracted from
                         * inbound TLP is presented to the Endpoint memory
                         * unit.
                         */

    output reg [63:0]  wr_addr_o,           // Memory Write Address
    output reg [7:0]   wr_be_o,             // Memory Write Byte Enable
    output reg [31:0]  wr_data_o,           // Memory Write Data
    output reg         wr_en_o             // Memory Write Enable
);

`define DESC_FETCH_TAG  8'h1f

// these TYPEs are bits [30:24] in the PCIe header.
localparam PIO_128_RX_MEM_RD32_FMT_TYPE = 7'b00_00000;
localparam PIO_128_RX_MEM_WR32_FMT_TYPE = 7'b10_00000;
localparam PIO_128_RX_MEM_RD64_FMT_TYPE = 7'b01_00000;
localparam PIO_128_RX_MEM_WR64_FMT_TYPE = 7'b11_00000;
localparam PIO_128_RX_IO_RD32_FMT_TYPE  = 7'b00_00010;
localparam PIO_128_RX_IO_WR32_FMT_TYPE  = 7'b10_00010;
localparam PIO_128_RX_CPLD_FMT_TYPE     = 7'b10_01010;

localparam PIO_128_RX_RST_STATE         = 7'b0000000;
localparam PIO_128_RX_CPLD_STATE        = 7'b0000010;
//localparam PIO_128_RX_MEM_RD32_DW1DW2     =  7'b0000001;
//localparam PIO_128_RX_MEM_WR32_DW1DW2     =  7'b0000010;
//localparam PIO_128_RX_MEM_RD64_DW1DW2     =  7'b0000100;
//localparam PIO_128_RX_MEM_WR64_DW1DW2     =  7'b0001000;
//localparam PIO_128_RX_WAIT_STATE          =  7'b0010000;
localparam PIO_128_RX_MEM_WR64_DW5      = 7'b0100000;
//localparam PIO_128_RX_IO_WR32_DW1DW2      =  7'b1000000;

    // Local Registers
    
    reg             req_compl; // a pre-register for req_compl_o to ease timing.
    reg [3:0]       req_compl_q;
    assign req_compl_o = req_compl_q[2];
    
    reg [63:0]      wr_addr_p;
    reg             do_wr;

    reg [6:0]          state;
    reg [6:0]          tlp_type;

    wire               io_bar_hit_n;
    wire               mem32_bar_hit_n;
    wire               mem64_bar_hit_n;
    wire               erom_bar_hit_n;
    
    reg             start_cpld, start_cpld_q, start_cpld_qq;
    reg [9:0]       stream_inx;
    reg             stream_desc, stream_valid;
    reg [127:0]     rx_data_q, rx_data_qq, rx_data_q3, stream_data;
    reg [9:0]       cpld_dw_len, cpld_dw_rem, cpld_dw_len_q;
    // we're adding a pipeline stage to the bram read to improve timing. it'll be absorbed into the bram and won't add logic.
    //   (although the rx_data pipeline stage we have to add isn't free)
    reg [11:0]      read_log_q;
    
    wire [127:0]    rx_data_swizzled = {rx_data[103:96],
                                        rx_data[111:104],
                                        rx_data[119:112],
                                        rx_data[127:120],
                                        rx_data[71:64],
                                        rx_data[79:72],
                                        rx_data[87:80],
                                        rx_data[95:88],
                                        rx_data[39:32],
                                        rx_data[47:40],
                                        rx_data[55:48],
                                        rx_data[63:56],
                                        rx_data[07:00],
                                        rx_data[15:08],
                                        rx_data[23:16],
                                        rx_data[31:24]};


  always @ ( posedge clk ) begin
    if (!rst_n ) begin
      //m_axis_rx_tready <= #TCQ 1'b0;
      req_compl     <= #TCQ 0;
      req_compl_q   <= #TCQ 4'h0;
      req_compl_wd_o <= #TCQ 1'b1;
      req_tc_o       <= #TCQ 2'b0;
      req_td_o       <= #TCQ 1'b0;
      req_ep_o       <= #TCQ 1'b0;
      req_attr_o     <= #TCQ 2'b0;
      req_len_o      <= #TCQ 10'b0;
      req_rid_o      <= #TCQ 16'b0;
      req_tag_o      <= #TCQ 8'b0;
      req_be_o       <= #TCQ 8'b0;
      req_addr_o     <= #TCQ 64'b0;
      wr_be_o        <= #TCQ 8'b0;
      wr_addr_o      <= #TCQ 64'b0;
      wr_data_o      <= #TCQ 31'b0;
      wr_en_o        <= #TCQ 1'b0;
      start_cpld     <= #TCQ 0;
      stream_valid  <= #TCQ 0;
      cpld_dw_rem   <= #TCQ 0;
      do_wr         <= #TCQ 0;

      state          <= #TCQ PIO_128_RX_RST_STATE;
      tlp_type       <= #TCQ 7'b0;
    end else begin
        wr_en_o         <= #TCQ 1'b0;
        req_compl       <= #TCQ 0;
        req_compl_q     <= #TCQ {req_compl_q[2:0], req_compl};
        start_cpld      <= #TCQ 0;
        do_wr           <= #TCQ 0;
        
        // CPLD handling
        // the pipelining here is excessive, especially since we've 128b of data. might want to trim it back a stage.
        // this logic must exist outside any specific 'state' since we may receive another packet right behind a cpld, which
        //   would send us into any state.
        rx_data_q           <= #TCQ rx_data_swizzled;
        rx_data_qq          <= #TCQ rx_data_q;
        rx_data_q3          <= #TCQ rx_data_qq;
        start_cpld_q        <= #TCQ start_cpld;
        start_cpld_qq       <= #TCQ start_cpld_q;
        stream_valid        <= #TCQ |cpld_dw_rem;
        stream_data         <= #TCQ rx_data_q3;
        cpld_dw_len_q       <= #TCQ cpld_dw_len;
        if (start_cpld_qq) begin
            cpld_dw_rem     <= #TCQ cpld_dw_len_q;
        end else if (|cpld_dw_rem)
            if (cpld_dw_rem < 4)
               cpld_dw_rem <= 0;
            else
               cpld_dw_rem     <= #TCQ cpld_dw_rem - 4; // 4 dw per clock w/ 128b bus
        else
            stream_valid    <= #TCQ 0;
        
        if (do_wr) begin
            wr_addr_o   <= #TCQ wr_addr_p;
            wr_data_o   <= #TCQ rx_data_swizzled[31:0];
            wr_en_o     <= #TCQ 1'b1;
        end
        
      case (state)

        PIO_128_RX_RST_STATE : begin

            state               <= #TCQ PIO_128_RX_RST_STATE;
            req_compl_wd_o      <= #TCQ 1'b1;


          if (rx_sof) begin
              tlp_type        <= #TCQ rx_hdr[63:48];
              
              case (rx_hdr[30:24])
                
                PIO_128_RX_CPLD_FMT_TYPE : begin
                    //TODO we might want to make sure the byte count is something we expect (eg low 2 bits clear).
                    //$display("%0t: RX CPLD. 0x%xB, tag 0x%x", $time, rx_hdr[9:0]*4, rx_hdr[76:72]);
                    cpld_dw_len     <= #TCQ rx_hdr[9:0];
                    start_cpld      <= #TCQ 1;
                    stream_tag      <= #TCQ rx_hdr[95:80];
                    // use the returned tag to look up this data's final destination.
                    // we're just going to stay in the RST state while the data in this packet pours in.
                    // it'll get handled by the CPLD logic in this module, rather than complicating this state machine.
                end
                
                PIO_128_RX_MEM_RD64_FMT_TYPE : begin
					//$display("RX_MEM_RD64_FMT_TYPE hdr: %h_%h_%h_%h | data: %h_%h_%h_%h", rx_hdr[127:96], rx_hdr[95:64], rx_hdr[63:32], rx_hdr[31:0], rx_data[127:96], rx_data[95:64], rx_data[63:32], rx_data[31:0]);
                  if (rx_hdr[9:0] == 10'b1) begin
                    req_tc_o     <= #TCQ rx_hdr[22:20];
                    req_td_o     <= #TCQ rx_hdr[15];
                    req_ep_o     <= #TCQ rx_hdr[14];
                    req_attr_o   <= #TCQ rx_hdr[13:12];
                    req_len_o    <= #TCQ rx_hdr[9:0];
                    req_rid_o    <= #TCQ rx_hdr[63:48];
                    req_tag_o    <= #TCQ rx_hdr[47:40];
                    req_be_o     <= #TCQ rx_hdr[39:32];
                    
                    //lower qw
                    // Upper 32-bits of 64-bit address not used, but would be captured
                    // in this state if used.  Upper 32 address bits are on
                    //rx_hdr[127:96]
                    req_addr_o      <= #TCQ {32'h0, rx_hdr[95:66], 2'b00};
                    req_compl       <= #TCQ 1'b1;
                    req_compl_wd_o  <= #TCQ 1'b1;
                    state           <= #TCQ PIO_128_RX_RST_STATE;
                  end else begin
                    state           <= #TCQ PIO_128_RX_RST_STATE;
                  end
                end

                PIO_128_RX_MEM_WR64_FMT_TYPE : begin
                  if (rx_hdr[9:0] == 10'b1) begin
                    wr_be_o      <= #TCQ rx_hdr[39:32];
                    if (rx_hdr[47:40] == `DESC_FETCH_TAG) begin
                        
                    end else begin
                        
                    end
                    // lower qw
                    wr_addr_p   <= #TCQ {32'h0 /*TODO: huh? why not from rx_hdr?*/, rx_hdr[95:66], 2'b00};
                    do_wr       <= #TCQ 1;
                    state       <= #TCQ PIO_128_RX_RST_STATE;
                  end else begin
                    state       <= #TCQ PIO_128_RX_RST_STATE;
                  end
                end
              endcase
          end else // not a start of packet
            state <= #TCQ PIO_128_RX_RST_STATE;
        end //PIO_128_RX_RST_STATE
        
      endcase
    end // if
  end // always




  assign mem64_bar_hit_n = 1'b1;
  assign io_bar_hit_n = 1'b1;
  assign mem32_bar_hit_n = rx_bar_hit[0];
  assign erom_bar_hit_n  = rx_bar_hit[6];


  // synthesis translate_off
  reg  [8*20:1] state_ascii;
  always @(state)
  begin
    if      (state==PIO_128_RX_RST_STATE)         state_ascii <= #TCQ "RX_RST_STATE";
    //else if (state==PIO_128_RX_MEM_RD32_DW1DW2)   state_ascii <= #TCQ "RX_MEM_RD32_DW1DW2";
    //else if (state==PIO_128_RX_MEM_WR32_DW1DW2)   state_ascii <= #TCQ "RX_MEM_WR32_DW1DW2";
    //else if (state==PIO_128_RX_MEM_RD64_DW1DW2)   state_ascii <= #TCQ "RX_MEM_RD64_DW1DW2";
    //else if (state==PIO_128_RX_MEM_WR64_DW1DW2)   state_ascii <= #TCQ "RX_MEM_WR64_DW1DW2";
    else if (state==PIO_128_RX_MEM_WR64_DW5)      state_ascii <= #TCQ "RX_MEM_WR64_DW5";
    //else if (state==PIO_128_RX_WAIT_STATE)        state_ascii <= #TCQ "RX_WAIT_STATE";
    //else if (state==PIO_128_RX_IO_WR32_DW1DW2)    state_ascii <= #TCQ "PIO_128_RX_IO_WR32_DW1DW2";
    else                                          state_ascii <= #TCQ "PIO 128 STATE ERR";

  end
  // synthesis translate_on





endmodule // PIO_128_RX_ENGINE

