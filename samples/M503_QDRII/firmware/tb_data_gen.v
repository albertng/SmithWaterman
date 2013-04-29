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
//  /   /         Filename           : tb_data_gen.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:57 $
// \   \  /  \    Date Created       : Nov 24, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ /RLDRAM-II
//
//Purpose:
//    This module
//       1. generates test write data for the memory interface.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////


`timescale 1ps/1ps

module tb_data_gen #(
  parameter DATA_WIDTH = 72,            //Data Width
  parameter BW_WIDTH   = DATA_WIDTH/9,  //Byte Write Width
  parameter BURST_LEN  = 4,             //Burst Length
  parameter TCQ        = 100            //Register Delay
)
(
  //System Signals
  input                                 clk,
  input                                 rst_clk,

  //Read Path Interface
  input                                 rd_valid0,
  input                                 rd_valid1,

  //Write Path Interface
  output [(BURST_LEN*DATA_WIDTH)-1:0]   wr_data0,
  output [(DATA_WIDTH*2)-1:0]           wr_data1,

  //Example Test Bench Interface
  input  [1:0]                          wr_cmd,
  input  [1:0]                          rd_cmd,           
  output [(BURST_LEN*DATA_WIDTH)-1:0]   rd_data0_comp,
  output [(DATA_WIDTH*2)-1:0]           rd_data1_comp
);
   
  reg [7:0] cmp_data_counter0 = 0;
  reg [7:0] cmp_data_counter1 = 0;
  reg [7:0] wr_data_counter   = 0;

  reg  [DATA_WIDTH-1 :0] wr_data0_r;
  reg  [DATA_WIDTH-1 :0] wr_data1_r;
  reg  [DATA_WIDTH-1 :0] wr_data0_2r;
  reg  [DATA_WIDTH-1 :0] wr_data1_2r;

  wire [(DATA_WIDTH*2)-1 :0]  tmp_wr_data0;
  wire [(DATA_WIDTH*2)-1 :0]  tmp_rd_data0_comp;


  always @ (posedge clk)
    begin
      if (rst_clk) begin
        cmp_data_counter0 <=#TCQ 0;
        cmp_data_counter1 <=#TCQ 0;
      end else begin
        if (rd_valid0) 
          cmp_data_counter0 <=#TCQ cmp_data_counter0 + 1;
        if (rd_valid1)
          cmp_data_counter1 <=#TCQ cmp_data_counter1 + 1;
      end
    end

  assign rd_data0_comp = (BURST_LEN == 4) ? {tmp_rd_data0_comp, rd_data1_comp} : tmp_rd_data0_comp;
  assign tmp_rd_data0_comp = {{BW_WIDTH{cmp_data_counter0, 1'b1}}, {BW_WIDTH{cmp_data_counter0, 1'b0}}};
  assign rd_data1_comp = {{BW_WIDTH{cmp_data_counter1, 1'b0}}, {BW_WIDTH{cmp_data_counter1, 1'b1}}};
   
  always @ (posedge clk)
    begin
       if (rst_clk)
         wr_data_counter <=#TCQ 0;
       else if (|wr_cmd)
         wr_data_counter <=#TCQ wr_data_counter + 1;
    end

  assign wr_data0 = (BURST_LEN == 4) ? {tmp_wr_data0, wr_data1} : tmp_wr_data0;
  assign tmp_wr_data0 = {{BW_WIDTH{wr_data_counter, 1'b1}}, {BW_WIDTH{wr_data_counter, 1'b0}}};
  assign wr_data1 = {{BW_WIDTH{wr_data_counter, 1'b0}}, {BW_WIDTH{wr_data_counter, 1'b1}}};

endmodule
