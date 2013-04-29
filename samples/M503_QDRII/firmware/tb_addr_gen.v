//*****************************************************************************
//(c) Copyright 2006 - 2009 Xilinx, Inc. All rights reserved.
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
//  /   /         Filename           : tb_addr_gen.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:57 $
// \   \  /  \    Date Created       : Nov 24, 2008 
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+
//
//Purpose:
//    This module
//       1. generates the write and read test memory addresses.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module tb_addr_gen #(
  parameter ADDR_WIDTH = 19,  //Address Width
  parameter TCQ        = 100  //Register Delay
)
(
  input                         clk,
  input                         rst_clk,
  input       [1:0]             wr_cmd,
  input       [1:0]             rd_cmd,
  output wire [ADDR_WIDTH-1:0]  wr_addr0,
  output wire [ADDR_WIDTH-1:0]  wr_addr1,
  output wire [ADDR_WIDTH-1:0]  rd_addr0, 
  output wire [ADDR_WIDTH-1:0]  rd_addr1 
);
     
  reg [ADDR_WIDTH-1:0] rd_addr_cntr  = 0;
  reg [ADDR_WIDTH-1:0] wr_addr_cntr  = 0;

  assign wr_addr0 = (wr_cmd[0]) ? wr_addr_cntr : 'bX;
  assign wr_addr1 = (wr_cmd[1]) ? wr_addr_cntr : 'bX;

  assign rd_addr0 = (rd_cmd[0]) ? rd_addr_cntr : 'bX;
  assign rd_addr1 = (rd_cmd[1]) ? rd_addr_cntr : 'bX;

  always @ (posedge clk)
    begin
      if (rst_clk) begin
        rd_addr_cntr   <=#TCQ 0;

      //Increment the address while calibration is done
      end else if (|rd_cmd) begin
        rd_addr_cntr <=#TCQ rd_addr_cntr + 1;
      end
    end
    
  always @ (posedge clk)
    begin
      if (rst_clk) begin
        wr_addr_cntr   <=#TCQ 0;

      //Increment the address while calibration is done
      end else if (|wr_cmd) begin
        wr_addr_cntr <=#TCQ wr_addr_cntr + 1;
      end
    end

endmodule
