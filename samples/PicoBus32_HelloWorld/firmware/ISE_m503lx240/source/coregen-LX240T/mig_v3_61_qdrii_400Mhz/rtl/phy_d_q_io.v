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

///////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor             : Xilinx
// \   \   \/     Version            : 3.6.1 
//  \   \         Application        : MIG
//  /   /         Filename           : phy_d_q_io.v
// /___/   /\     Date Last Modified : $date$
// \   \  /  \    Date Created       : Nov 19, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ /RLDRAM-II
//
//Purpose:
//  This module
//  1. Is the I/O module for the entire D & Q bus for a single memory.
//  2. Instantiates the phy_read_v6_d_q_io module for each bit in the memory.
//
//Revision History:
//
///////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_d_q_io #
(
  parameter BYTE_WIDTH           = 18,           // clk:data ratio
  parameter REFCLK_FREQ          = 300.0,        // Reference Clock Freq(Mhz)
  parameter MEM_TYPE             = "QDR2PLUS",   // Memory Type
  parameter ODELAY_VAL           = 0,            // value to delay data
  parameter IODELAY_GRP          = "IODELAY_MIG",// May be assigned unique name 
  parameter HIGH_PERFORMANCE_MODE= "TRUE",       // IODELAY High Perf Mode
  parameter IBUF_LOW_PWR         = "FALSE",      // Input buffer low power mode
  parameter SIM_INIT_OPTION      = "NONE",        //Simulation only. "NONE", "SIM_MODE"
  parameter TCQ                  = 100           // Register delay
)
(
  // System signals
  input                          clk,         // system clock
  input                          rst_wr_clk,  // reset syncronized to clk
  input                          clk_mem,     // high frequency system clock
  input       [3:0]              wr_en,       // tri-state control
  input                          clk_cq,      // CQ from BUFIO
  input                          clk_cqn,     // CQ# from BUFIO
  input                          clk_rd,      // half freq CQ clock from BUFR
  input                          rst_clk_rd,  // reset syncrhonized to clk_rd

  // Memory Interface
  input       [BYTE_WIDTH-1:0]   mem_q,       // Q from memory
  output      [BYTE_WIDTH-1:0]   mem_d,       // D to memory
  inout       [BYTE_WIDTH-1:0]   mem_dq,      // DQ to/from memory
  
  // PHY Write Interface
  input       [BYTE_WIDTH-1:0]   data_rise0,
  input       [BYTE_WIDTH-1:0]   data_fall0,
  input       [BYTE_WIDTH-1:0]   data_rise1,
  input       [BYTE_WIDTH-1:0]   data_fall1,
  
  // IDELAY control
  input       [BYTE_WIDTH-1:0]   q_dly_ce,    // Q IDELAY clock enable
  input                          q_dly_inc,   // Q IDELAY increment
  input       [BYTE_WIDTH-1:0]   q_dly_rst,   // Q IDELAY reset
  input       [4:0]              q_dly_load,  // Q IDELAY cntvaluein load value
  output wire [BYTE_WIDTH*5-1:0] q_dly_tap,   // Q IDELAY tap settings 
                                              // concatenated together

  // ISERDES control
  input                          q_dly_clkinv,// Q IDELAY CLK inversion
  input                          iserdes_rst, // ISERDES reset
  
  // PHY Read Interface
  output wire [BYTE_WIDTH-1:0]   iserdes_rd0, // ISERDES Q4 -rise data 0
  output wire [BYTE_WIDTH-1:0]   iserdes_fd0, // ISERDES Q3 -fall data 0
  output wire [BYTE_WIDTH-1:0]   iserdes_rd1, // ISERDES Q2 -rise data 1
  output wire [BYTE_WIDTH-1:0]   iserdes_fd1 // ISERDES Q1 -fall data 1
  
);

  // Register ISERDES reset to help with timing
  (* KEEP = "TRUE" *)
  (* max_fanout = "1" *)
  reg iserdes_rst_int;

  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      iserdes_rst_int <= #TCQ 0;
    end else begin
      iserdes_rst_int <= #TCQ iserdes_rst;
    end
  end

  // Need to register the Q "inc" signals to make sure they align with the "ce"
  (* KEEP = "TRUE" *)
  (* max_fanout = "1" *)
  reg q_dly_inc_int;

  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      q_dly_inc_int  <= #TCQ 0;
    end else begin
      q_dly_inc_int  <= #TCQ q_dly_inc;
    end
  end

  genvar mw_i;
  generate
    for (mw_i=0; mw_i < BYTE_WIDTH; mw_i=mw_i+1)
    begin : d_q_mem_inst
      phy_v6_d_q_io #(
        .REFCLK_FREQ          (REFCLK_FREQ),
        .MEM_TYPE             (MEM_TYPE),
        .ODELAY_VAL           (ODELAY_VAL),
        .IODELAY_GRP          (IODELAY_GRP),
        .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE),
        .IBUF_LOW_PWR         (IBUF_LOW_PWR),
        .SIM_INIT_OPTION      (SIM_INIT_OPTION),
        .TCQ                  (TCQ)
      ) d_q_inst (
        //System Signals
        .clk              (clk),
        .rst_wr_clk       (rst_wr_clk),
        //Write Interface
        .clk_mem          (clk_mem),  
        .data_rise0       (data_rise0[mw_i]),
        .data_fall0       (data_fall0[mw_i]),
        .data_rise1       (data_rise1[mw_i]),
        .data_fall1       (data_fall1[mw_i]),
        .mem_d            (mem_d[mw_i]),
        //Bidirectional Interface
        .wr_en            (wr_en),
        .mem_dq           (mem_dq[mw_i]),
        //Read Interface
        .clk_cq           (clk_cq),
        .clk_cqn          (clk_cqn),
        .clk_rd           (clk_rd),
        .rst_clk_rd       (rst_clk_rd),
        .mem_q            (mem_q[mw_i]),
        .q_dly_ce         (q_dly_ce[mw_i]),
        .q_dly_inc        (q_dly_inc),
        .q_dly_inc_int    (q_dly_inc_int),
        .q_dly_rst        (q_dly_rst[mw_i]),
        .q_dly_load       (q_dly_load),
        .q_dly_tap        (q_dly_tap[(mw_i+1)*5-1:mw_i*5]),
        .q_dly_clkinv     (q_dly_clkinv),
        .iserdes_rst_int  (iserdes_rst_int),
        .iserdes_rd0      (iserdes_rd0[mw_i]),
        .iserdes_fd0      (iserdes_fd0[mw_i]),
        .iserdes_rd1      (iserdes_rd1[mw_i]),
        .iserdes_fd1      (iserdes_fd1[mw_i])
      );
    end
  endgenerate

endmodule
