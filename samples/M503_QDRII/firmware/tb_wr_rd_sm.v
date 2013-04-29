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
//  /   /         Filename           : tb_wr_rd_sm.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:57 $
// \   \  /  \    Date Created       : 15 May 2006 
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+
//
//Purpose:
//    This module
//       1. generates writes and read commands emulating the user backend.
//
//Revision History:
//
///////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module tb_wr_rd_sm #(
  parameter BURST_LEN = 4,    //Burst Length
  parameter TCQ       = 100   //Register Delay
)
(
  input             clk,
  input             rst_clk,
  input             cal_done,
  input             user_wr_full,
  input             user_rd_full,
  output reg [1:0]  wr_cmd,
  output reg [1:0]  rd_cmd 
);

  //6 states - one-hot encoded
  localparam [5:0] TEST_INIT       = 6'b00_0001,
                   TEST_IDLE       = 6'b00_0010,
                   TEST_WR         = 6'b00_0100,
                   TEST_RD         = 6'b00_1000,
                   TEST_WR_RD      = 6'b10_0000;

  reg [5:0] ctrl_sm_cs;
  reg [5:0] ctrl_sm_ns;

  always @(posedge clk)
    begin
      if (rst_clk)
        ctrl_sm_cs <=#TCQ TEST_INIT;
      else
        ctrl_sm_cs <=#TCQ ctrl_sm_ns;
    end

  always @*
    begin
      case (ctrl_sm_cs)
        //Wait until calibration is done to issue commands
        TEST_INIT: begin
          wr_cmd   = 2'b00;
          rd_cmd   = 2'b00;

          if (cal_done)
            ctrl_sm_ns = TEST_IDLE;
          else
            ctrl_sm_ns = TEST_INIT;
        end

        TEST_IDLE: begin
          rd_cmd    = 2'b00;
          wr_cmd    = 2'b00;

          //If the rd/wr fifos are both empty send one of each transaction
          //if one of the fifos is full, send the other transaction type
          case ({user_wr_full, user_rd_full})
            2'b00: ctrl_sm_ns = TEST_WR; //to initiate a write before any reads
            2'b01: ctrl_sm_ns = TEST_WR;
            2'b10: ctrl_sm_ns = TEST_RD;
            2'b11: ctrl_sm_ns = TEST_IDLE;
          endcase
        end

        TEST_WR: begin
          rd_cmd   = 2'b00;
          wr_cmd   = 2'b01;  // Initiate a write cycle

          case ({user_wr_full, user_rd_full})
            2'b00: ctrl_sm_ns = TEST_WR_RD;
            2'b01: ctrl_sm_ns = TEST_WR;
            2'b10: ctrl_sm_ns = TEST_RD;
            2'b11: ctrl_sm_ns = TEST_IDLE;
          endcase
        end

        TEST_RD: begin
          rd_cmd    = 2'b01;  // Initiate a read cycle
          wr_cmd    = 2'b00;

          case ({user_wr_full, user_rd_full})
            2'b00: ctrl_sm_ns = TEST_WR_RD;
            2'b01: ctrl_sm_ns = TEST_WR;
            2'b10: ctrl_sm_ns = TEST_RD;
            2'b11: ctrl_sm_ns = TEST_IDLE;
          endcase
        end

        TEST_WR_RD : begin
          rd_cmd    = 2'b01;
          wr_cmd    = 2'b01;

          case ({user_wr_full, user_rd_full})
            2'b00: ctrl_sm_ns = TEST_WR_RD;
            2'b01: ctrl_sm_ns = TEST_WR;
            2'b10: ctrl_sm_ns = TEST_RD;
            2'b11: ctrl_sm_ns = TEST_IDLE;
          endcase
        end

        default: begin
          rd_cmd      = 2'bXX;
          wr_cmd      = 2'bXX;
          ctrl_sm_ns  = TEST_INIT;
        end
      endcase
    end

endmodule
