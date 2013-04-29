//*****************************************************************************
//(c) Copyright 2009 - 2010 Xilinx, Inc. All rights reserved.
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

////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor             : Xilinx
// \   \   \/     Version            : 3.6.1 
//  \   \         Application        : MIG
//  /   /         Filename           : phy_read_clk_io.v
// /___/   /\     Date Last Modified  :  $date$
// \   \  /  \    Date Created        :  Nov 18, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//  This module
//  1. Is the I/O module for the incoming CQ echo clock from the memory.
//  2. Instantiates the IBUF followed by the IDELAY to delay the CQ clock
//     and routes it through a BUFIO.
//  3. Routes the CQ clock from the IDELAY through a BUFR which divides
//     the clock by 2.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps
module phy_read_clk_io #
(
  parameter REFCLK_FREQ           = 300.0,        // Indicates the IDELAYCTRL 
                                                  // reference clock frequency
  parameter MEM_TYPE              = "QDR2PLUS",   // Memory Type (QDR2PLUS, 
                                                  // RLD2_CIO, RLD2_SIO)
  parameter IODELAY_GRP           = "IODELAY_MIG",// May be assigned unique name 
  parameter HIGH_PERFORMANCE_MODE = "TRUE",       // IODELAY High PerfMode
  parameter IBUF_LOW_PWR          = "FALSE",      // Input buffer low power mode
  parameter TCQ                   = 100           // Register delay
)
(
  // Memory Interface
  input             mem_cq,       // CQ clock from the memory
  input             mem_cq_n,     // CQ# clock from the memory

  // IDELAY control
  input             cal_clk,      // IDELAY clock used for dynamic inc/dec
  input             cq_dly_ce,    // CQ IDELAY clock enable
  input             cq_dly_inc,   // CQ IDELAY increment
  input             cq_dly_rst,   // CQ IDELAY reset
  input       [4:0] cq_dly_load,  // CQ IDELAY cntvaluein load value
  output wire [4:0] cq_dly_tap,   // CQ IDELAY tap settings concatenated
  
  input             cqn_dly_ce,   // CQ# IDELAY clock enable
  input             cqn_dly_inc,  // CQ# IDELAY increment
  input             cqn_dly_rst,  // CQ# IDELAY reset
  input       [4:0] cqn_dly_load, // CQ# IDELAY cntvaluein load value
  output wire [4:0] cqn_dly_tap,  // CQ# IDELAY tap settings concatenated

  // PHY Read Interface
  output wire       clk_cq,       // BUFIO CQ output
  output wire       clk_cqn,      // BUFIO CQ# output
  output wire       clk_rd,       // BUFR half frequency CQ output
  output wire       pd_source,    // PD Source for RLDRAM II
  input             rst_clk_rd    // Reset syncrhonized to clk_rd
);

  reg   cq_dly_ce_int;
  reg   cqn_dly_ce_int;
  reg   cq_dly_inc_int;
  reg   cqn_dly_inc_int;
  wire  cq_ibuf;
  wire  cq_idelay;
  wire  cq_bufio;
  wire  cq_bufr;
  wire  cqn_ibuf;
  wire  cqn_idelay;
  wire  cqn_bufio;

  // Prevent the taps from overflowing or underflowing by capping them at their
  // minimum or maximum value
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      cq_dly_ce_int <= #TCQ 0;
    end else if (cq_dly_ce) begin
      if (cq_dly_inc) begin
        cq_dly_ce_int <= #TCQ !(&cq_dly_tap);
      end else begin
        cq_dly_ce_int <= #TCQ |cq_dly_tap;
      end
    end else begin
      cq_dly_ce_int <= #TCQ 0;
    end
  end

  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      cqn_dly_ce_int <= #TCQ 0;
    end else if (cqn_dly_ce) begin
      if (cqn_dly_inc) begin
        cqn_dly_ce_int <= #TCQ !(&cqn_dly_tap);
      end else begin
        cqn_dly_ce_int <= #TCQ |cqn_dly_tap;
      end
    end else begin
      cqn_dly_ce_int <= #TCQ 0;
    end
  end
  
  // need to register the "inc" signals to make sure they align with the "ce"
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      cq_dly_inc_int  <= #TCQ 0;
      cqn_dly_inc_int <= #TCQ 0;
    end else begin
      cq_dly_inc_int  <= #TCQ cq_dly_inc;
      cqn_dly_inc_int <= #TCQ cqn_dly_inc;
    end
  end

  generate
    if (MEM_TYPE == "QDR2PLUS" || MEM_TYPE == "QDR2") begin : IBUF_CQ_CQ_B
      // CQ first passes through an IBUF
      IBUF   
      #(
        .IBUF_LOW_PWR (IBUF_LOW_PWR)
      )cq_ibuf_inst (
        .I (mem_cq),
        .O (cq_ibuf)
      );  
  
      // CQ# first passes through an IBUF
      IBUF   
      #(
        .IBUF_LOW_PWR (IBUF_LOW_PWR)
      )cqn_ibuf_inst (
        .I (mem_cq_n),
        .O (cqn_ibuf)
      );
      
      //assign pd_source = 'b0;
      assign pd_source = cqn_ibuf;
      
    end else begin: IOBUF_QK
      //Differential Input Buffer
      //N-side used for the Phase Detector
      IOBUFDS_DIFF_OUT  #(
        .IBUF_LOW_PWR (IBUF_LOW_PWR)
      ) qk_ibufgds_diff_out
      (
        .O   (cq_ibuf),
        .OB  (cqn_ibuf),
        .IO  (mem_cq),
        .IOB (mem_cq_n),
        .I   (1'b0),
        .TM  (1'b1),
        .TS  (1'b1)
      );
      
      assign pd_source = cqn_ibuf;

    end //end - IBUF_CQ_CQ_B
  endgenerate

  // CQ then passes through an IDELAY
  IODELAYE1 #(
    .CINVCTRL_SEL          ("FALSE"),
    .DELAY_SRC              ("I"),
    .HIGH_PERFORMANCE_MODE  (HIGH_PERFORMANCE_MODE),
    .IDELAY_TYPE            ("VAR_LOADABLE"),
    .REFCLK_FREQUENCY       (REFCLK_FREQ),
    .SIGNAL_PATTERN         ("CLOCK")
  ) cq_idelay_inst (
    .CNTVALUEOUT  (cq_dly_tap),
    .DATAOUT      (cq_idelay),
    .C            (cal_clk),
    .CE           (cq_dly_ce_int),
    .CINVCTRL     (),
    .CNTVALUEIN   (cq_dly_load),
    .DATAIN       (),
    .IDATAIN      (cq_ibuf),
    .INC          (cq_dly_inc_int),
    .ODATAIN      (),
    .RST          (cq_dly_rst),
    .CLKIN        (),
    .T            (1'b1)
  );
  
  assign cqn_bufio   = ~cq_bufio;
  assign cqn_dly_tap = 'b0;
  
//  generate
//    if (MEM_TYPE == "QDR2PLUS" || MEM_TYPE == "QDR2") begin : CQ_B_IOB
//    
//      // CQ# then passes through an IDELAY
//      IODELAYE1 #( 
//         .CINVCTRL_SEL          ("FALSE"),
//        .DELAY_SRC              ("I"),
//        .HIGH_PERFORMANCE_MODE  (HIGH_PERFORMANCE_MODE),
//        .IDELAY_TYPE            ("VAR_LOADABLE"),
//        .REFCLK_FREQUENCY       (REFCLK_FREQ),
//        .SIGNAL_PATTERN         ("CLOCK")
//      ) cqn_idelay_inst (
//        .CNTVALUEOUT  (cqn_dly_tap),
//        .DATAOUT      (cqn_idelay),
//        .C            (cal_clk),
//        .CE           (cqn_dly_ce_int),
//        .CINVCTRL     (),
//        .CNTVALUEIN   (cqn_dly_load),
//        .DATAIN       (),
//        .IDATAIN      (cqn_ibuf),
//        .INC          (cqn_dly_inc_int),
//        .ODATAIN      (),
//        .RST          (cqn_dly_rst),
//        .CLKIN        (),
//        .T            (1'b1)
//      );
//  
//      // Out of the IDELAY, CQ# is distributed through a BUFIO
//      BUFIO cqn_bufio_inst
//      (
//        .I (cqn_idelay),
//        .O (cqn_bufio)
//      );
//  
//    end else begin//end - CQ_B_IOB
//      assign cqn_bufio   = ~cq_bufio;
//      assign cqn_dly_tap = 'b0;
//    end
//  endgenerate

  // Out of the IDELAY, CQ is distributed through a BUFIO
  BUFIO cq_bufio_inst
  (
    .I (cq_idelay),
    .O (cq_bufio)
  );
  
  // The output of the IDELAY also passes through a BUFR that divides
  // the clock by 2
  BUFR #(
    .BUFR_DIVIDE("2"),
    .SIM_DEVICE ("VIRTEX6")
  ) cq_bufr_inst (
    .O    (cq_bufr), 
    .CE   (1'b1), 
    .CLR  (1'b0), 
    .I    (cq_idelay)
  );
      
  assign clk_cq = cq_bufio;
  assign clk_rd = cq_bufr;
  
  //  assign #1100 clk_cqn = cqn_bufio;
  assign clk_cqn = cqn_bufio;
    
endmodule
