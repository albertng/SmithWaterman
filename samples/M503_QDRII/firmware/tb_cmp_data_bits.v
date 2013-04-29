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
//  /   /         Filename           : tb_cmp_data_bits.v
// /___/   /\     Date Last Modified  : $Date: 2010/10/27 17:40:57 $
// \   \  /  \    Date Created        : 15 May 2006
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII /RLDRAM-II
//
//Purpose:
//    This module
//       1. Incorporates a one bit comparision scheme.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module tb_cmp_data_bits #(
  parameter TCQ = 100   //Register Delay
)
(
  input      clk,
  input      rst_clk,
  input      cmp_en0,
  input      cmp_en1,
  input      rd_data1,
  input      rd_data0,
  input      rd_data0_comp,
  input      rd_data1_comp,
  output reg cmp_lsb,
  output reg cmp_msb
);

  always @ (posedge clk)
    begin
      if (rst_clk) begin
         cmp_lsb <=#TCQ 1'b0;
         cmp_msb <=#TCQ 1'b0;
      end else begin
        //Compare the LSB bit
        if (cmp_en0)
          cmp_lsb <=#TCQ ~(rd_data0 == rd_data0_comp);

        //Compare the MSB bit
        if (cmp_en1)
          cmp_msb <=#TCQ ~(rd_data1 == rd_data1_comp);
      end
    end

endmodule
