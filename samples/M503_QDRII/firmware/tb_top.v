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
//  /   /         Filename           : tb_top.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:57 $
// \   \  /  \    Date Created       : Nov 19, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+
//
//Purpose:
//    This module
//       1. serves as the top level synthesizable user backend module.
//       2. Instantiates the write data generation, address generation modules
//          as well the compare modules to check for error.
//
//Revision History:
//
///////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module tb_top #(
  parameter BURST_LEN  = 4,           //Burst Length
  parameter ADDR_WIDTH = 19,          //Address Width
  parameter DATA_WIDTH = 72,          //Data Width
  parameter BW_WIDTH   = DATA_WIDTH/9,//Byte Write Width
  parameter TCQ        = 100          //Register Delay
)
(
  input                                     clk,
  input                                     rst_clk,
  output wire                               wr_cmd0, 
  output wire                               wr_cmd1, 
  output wire [ADDR_WIDTH-1:0]              wr_addr0,
  output wire [ADDR_WIDTH-1:0]              wr_addr1,
  output wire                               rd_cmd0, 
  output wire                               rd_cmd1, 
  output wire [ADDR_WIDTH-1:0]              rd_addr0, 
  output wire [ADDR_WIDTH-1:0]              rd_addr1,
  output wire [(BURST_LEN*DATA_WIDTH)-1:0]  wr_data0,
  output wire [DATA_WIDTH*2-1:0]            wr_data1,
  output wire [(BURST_LEN*BW_WIDTH)-1:0]    wr_bw_n0,
  output wire [BW_WIDTH*2-1:0]              wr_bw_n1,
  input                                     rd_valid0,
  input                                     rd_valid1,
  input       [(BURST_LEN*DATA_WIDTH)-1:0]  rd_data0, 
  input       [DATA_WIDTH*2-1:0]            rd_data1,
  input                                     cal_done,
  output wire                               compare_error,
  output wire                               cmp_err,
  input                                     clear_error
);

  //Wire Declarations
  wire [1:0]                        wr_cmd;
  wire [1:0]                        rd_cmd;
  wire [(BURST_LEN*DATA_WIDTH)-1:0] rd_data0_comp;
  wire [(DATA_WIDTH*2)-1:0]         rd_data1_comp;

  wire [(DATA_WIDTH*2)-1:0]         split_rd_data0_comp;
  wire [(DATA_WIDTH*2)-1:0]         split_rd_data0;
  wire [(DATA_WIDTH*2)-1:0]         split_rd_data1_comp;
  wire [(DATA_WIDTH*2)-1:0]         split_rd_data1;

  assign wr_cmd0 = wr_cmd[0];
  assign wr_cmd1 = wr_cmd[1];
  assign rd_cmd0 = rd_cmd[0];
  assign rd_cmd1 = rd_cmd[1];

  // Byte Write enables all enabled in this testbench
  assign wr_bw_n0 = {BURST_LEN*BW_WIDTH{1'b0}}; 
  assign wr_bw_n1 = {BW_WIDTH*2{1'b0}}; 

  // Write/Read State Machine, responsible for generating the read and write
  // commands to memory.  This supports burst lengths of 2 and 4.
  tb_wr_rd_sm #(
    .BURST_LEN (BURST_LEN),
    .TCQ       (TCQ)
  ) u_tb_wr_rd_sm (
    .clk          (clk),
    .rst_clk      (rst_clk),
    .cal_done     (cal_done),
    .user_wr_full (1'b0),     //No FIFOs used
    .user_rd_full (1'b0),
    .wr_cmd       (wr_cmd),
    .rd_cmd       (rd_cmd) 
  );

  // Address generation module responsible for generating address' to be used
  // for both read and write transactions to memory.
  tb_addr_gen #(
    .ADDR_WIDTH (ADDR_WIDTH),
    .TCQ        (TCQ)
  ) u_tb_addr_gen (
    .clk        (clk),
    .rst_clk    (rst_clk),
    .wr_cmd     (wr_cmd),
    .rd_cmd     (rd_cmd),
    .wr_addr0   (wr_addr0),
    .wr_addr1   (wr_addr1),
    .rd_addr0   (rd_addr0),
    .rd_addr1   (rd_addr1)
  );

  // Data Generation Module responsible for creating data used for write
  // transactions to the QDRII device. 
  tb_data_gen #(
    .DATA_WIDTH   (DATA_WIDTH),
    .BURST_LEN    (BURST_LEN),
    .TCQ          (TCQ)
  ) u_tb_data_gen (
    .clk            (clk),
    .rst_clk        (rst_clk),
    .rd_valid0      (rd_valid0),
    .rd_valid1      (rd_valid1),
    .wr_data0       (wr_data0),
    .wr_data1       (wr_data1),
    .wr_cmd         (wr_cmd),
    .rd_cmd         (rd_cmd),       
    .rd_data0_comp  (rd_data0_comp),
    .rd_data1_comp  (rd_data1_comp)
  );
  

  // State machine for reading back values from Read data FIFOs and comparing
  // to values stored in the testbench BRAMs.  This module is the hardware
  // testbench error detection module that makes sure the data returning from
  // the QDRII device is the same as the data written to it.
  generate 
    if (BURST_LEN == 4) begin: split_data_bl4
      assign split_rd_data0_comp = rd_data0_comp[DATA_WIDTH*4-1:DATA_WIDTH*2];
      assign split_rd_data0      = rd_data0[DATA_WIDTH*4-1:DATA_WIDTH*2];
      assign  split_rd_data1_comp = rd_data0_comp[DATA_WIDTH*2-1:0];
      assign split_rd_data1      = rd_data0[DATA_WIDTH*2-1:0];
    end else begin: split_data_bl2
      assign split_rd_data0_comp = rd_data0_comp;
      assign split_rd_data0      = rd_data0;
      assign split_rd_data1_comp = rd_data1_comp;
      assign split_rd_data1      = rd_data1;
    end 
  endgenerate

  tb_cmp_data #(
    .DATA_WIDTH (DATA_WIDTH),
    .TCQ        (TCQ)
  ) u_tb_cmp_data (
    .clk            (clk),
    .rst_clk        (rst_clk),
    .rd_valid0      (rd_valid0),
    .rd_valid1      (rd_valid1),
    .rd_data0       (split_rd_data0),
    .rd_data1       (split_rd_data1),
    .rd_data0_comp  (split_rd_data0_comp),
    .rd_data1_comp  (split_rd_data1_comp),
    .compare_error  (compare_error),
    .cmp_err        (cmp_err),
    .clear_error    (clear_error)
  );

endmodule
