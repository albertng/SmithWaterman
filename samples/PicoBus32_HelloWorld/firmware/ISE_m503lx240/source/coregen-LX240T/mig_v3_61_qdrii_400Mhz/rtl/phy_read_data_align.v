//*****************************************************************************
// (c) Copyright 2009 - 2010 Xilinx, Inc. All rights reserved.
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
//  /   /         Filename           : phy_read_data_align.v
// /___/   /\     Date Last Modified : $date$
// \   \  /  \    Date Created       : Nov 17, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM_II
//
//Purpose:
//  This module
//  1. Realigns the incoming data based on the phase signal from the delay /
//     alignment calibration. If phase = 0, no realignment occurs and data
//     exits in the same manner that it is delivered from the ISERDES. If
//     phase = 1, the data is realigned to correct for the CLK/CLKB
//     relationship relative to CLKDIV in the ISERDES. Specifically it delays
//     iserdes data 1 and swaps position with iserdes data 0.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_read_data_align #
(
  parameter MEMORY_WIDTH  = 36, // Width of each memory
  parameter TCQ           = 100 // Register delay
)
(
  // System Signals
  input                           clk_rd,       // half freq CQ clock
  input                           rst_clk_rd,   // reset syncrhonized to clk_rd

  // ISERDES Interface
  input       [MEMORY_WIDTH-1:0]  iserdes_rd0,  // rising data 0 from ISERDES
  input       [MEMORY_WIDTH-1:0]  iserdes_fd0,  // falling data 0 from ISERDES
  input       [MEMORY_WIDTH-1:0]  iserdes_rd1,  // rising data 1 from ISERDES
  input       [MEMORY_WIDTH-1:0]  iserdes_fd1,  // falling data 1 from ISERDES

  // DCB Interface
  output reg  [MEMORY_WIDTH-1:0]  rise_data0,   // rising data 0 to DCB
  output reg  [MEMORY_WIDTH-1:0]  fall_data0,   // falling data 0 to DCB
  output reg  [MEMORY_WIDTH-1:0]  rise_data1,   // rising data 1 to DCB
  output reg  [MEMORY_WIDTH-1:0]  fall_data1,   // falling data 1 to DCB

  // Delay/Alignment Calibration Interface
  input                           phase,        // realigns when asserted
  
  // ChipScope Debug Signals
  output                          dbg_phase     // phase indicator
);

  reg [MEMORY_WIDTH-1:0]  iserdes_rd1_r;
  reg [MEMORY_WIDTH-1:0]  iserdes_fd1_r;

  // Delay rising and falling data 1 from ISERDES in case the data needs
  // to be realigned
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      iserdes_rd1_r <= #TCQ 0;
      iserdes_fd1_r <= #TCQ 0;
    end else begin
      iserdes_rd1_r <= #TCQ iserdes_rd1;
      iserdes_fd1_r <= #TCQ iserdes_fd1;
    end
  end

  // Realign when phase is asserted. Rise and fall data 0 output is derived from
  // the registered rise and fall data 1 (from above) from the ISERDES. Rise and
  // fall data 1 output comes from the ISERDES rise and fall data 0.
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      rise_data0 <= #TCQ 0;
      fall_data0 <= #TCQ 0;
      rise_data1 <= #TCQ 0;
      fall_data1 <= #TCQ 0;
    end else begin
      rise_data0 <= #TCQ phase ? iserdes_rd1_r : iserdes_rd0;
      fall_data0 <= #TCQ phase ? iserdes_fd1_r : iserdes_fd0;
      rise_data1 <= #TCQ phase ? iserdes_rd0 : iserdes_rd1;
      fall_data1 <= #TCQ phase ? iserdes_fd0 : iserdes_fd1;
    end
  end

  // Assign debug signals
  assign dbg_phase = phase;

endmodule
