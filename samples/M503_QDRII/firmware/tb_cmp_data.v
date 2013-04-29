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
//  /   /         Filename           : tb_cmp_data.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:57 $ 
// \   \  /  \    Date Created       : Dec 01, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//    This module
//       1. generates the compare data and compares the write data against the
//          captured read data.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1 ps/1 ps

module tb_cmp_data #(
  parameter DATA_WIDTH = 72,  //Data Width
  parameter TCQ        = 100  //Register Delay
)
(
  input                     clk,
  input                     rst_clk,
  input                     rd_valid0,
  input                     rd_valid1,
  input [DATA_WIDTH*2-1:0]  rd_data0,
  input [DATA_WIDTH*2-1:0]  rd_data1,
  input [DATA_WIDTH*2-1:0]  rd_data0_comp,
  input [DATA_WIDTH*2-1:0]  rd_data1_comp,
  output reg                compare_error,
  output reg                cmp_err,
  input                     clear_error
);

  reg                     compare_en0;
  reg                     compare_en1;
  reg                     compare_lsb;
  reg                     compare_msb;
  reg                     compare_error_i;
  reg                     compare_error_2i;
  wire [DATA_WIDTH*2-1:0] comp_lsb;
  wire [DATA_WIDTH*2-1:0] comp_msb;

  reg                     compare_en0_r;
  reg                     compare_en1_r;
  reg  [DATA_WIDTH*2-1:0] rd_data0_r;
  reg  [DATA_WIDTH*2-1:0] rd_data1_r;
  reg  [DATA_WIDTH*2-1:0] rd_data0_comp_r;
  reg  [DATA_WIDTH*2-1:0] rd_data1_comp_r;

  reg                     compare_en0_2r;
  reg                     compare_en1_2r;
  reg  [DATA_WIDTH*2-1:0] rd_data0_2r;
  reg  [DATA_WIDTH*2-1:0] rd_data1_2r;
  reg  [DATA_WIDTH*2-1:0] rd_data1_comp_2r;
  reg  [DATA_WIDTH*2-1:0] rd_data0_comp_2r;

  //Enable a compare based on which data is valid DW0/DW1
  always @(posedge clk)
    begin
      if (rst_clk) begin
        compare_en0 <=#TCQ 1'b0;
        compare_en1 <=#TCQ 1'b0;
      end else begin
        compare_en0 <=#TCQ rd_valid0;
        compare_en1 <=#TCQ rd_valid1;
      end
    end

  always @ (posedge clk)
    begin
       if(rst_clk) begin
          rd_data0_r        <=#TCQ 'b0;
          rd_data0_2r       <=#TCQ 'b0;
          rd_data1_r        <=#TCQ 'b0;
          rd_data1_2r       <=#TCQ 'b0;
          rd_data1_comp_r   <=#TCQ 'b0;
          rd_data1_comp_2r  <=#TCQ 'b0;
          rd_data0_comp_r   <=#TCQ 'b0;
          rd_data0_comp_2r  <=#TCQ 'b0;
          compare_en0_r     <=#TCQ 1'b0;
          compare_en0_2r    <=#TCQ 1'b0;
          compare_en1_r     <=#TCQ 1'b0;
          compare_en1_2r    <=#TCQ 1'b0;
       end else begin
          rd_data0_r        <=#TCQ rd_data0;
          rd_data0_2r       <=#TCQ rd_data0_r;
          rd_data1_r        <=#TCQ rd_data1;
          rd_data1_2r       <=#TCQ rd_data1_r;
          rd_data1_comp_r   <=#TCQ rd_data1_comp;
          rd_data1_comp_2r  <=#TCQ rd_data1_comp_r;
          rd_data0_comp_r   <=#TCQ rd_data0_comp;
          rd_data0_comp_2r  <=#TCQ rd_data0_comp_r;
          compare_en0_r     <=#TCQ rd_valid0;
          compare_en0_2r    <=#TCQ compare_en0_r;
          compare_en1_r     <=#TCQ rd_valid1;
          compare_en1_2r    <=#TCQ compare_en1_r;
       end
    end

  //Compare each bit of data
  genvar comp_i;
  generate
    for(comp_i=0; comp_i < (DATA_WIDTH*2); comp_i=comp_i+1)
      begin:COMPARE_DATA
        tb_cmp_data_bits U_QDRII_TEST_CMP_DATA
          (
            .clk          ( clk ),
            .rst_clk      ( rst_clk ),
            .cmp_en0      ( compare_en0_2r ),
            .cmp_en1      ( compare_en1_2r ),
            .rd_data1     ( rd_data1_2r[comp_i] ),
            .rd_data0     ( rd_data0_2r[comp_i] ),
            .rd_data1_comp( rd_data1_comp_2r[comp_i] ),
            .rd_data0_comp( rd_data0_comp_2r[comp_i] ),
            .cmp_lsb      ( comp_lsb[comp_i] ),
            .cmp_msb      ( comp_msb[comp_i] )
          );
      end
  endgenerate

  //Whenever enable is triggered for the either Data Words 0 or 1, check if
  //there is an error between any bits and update the cummulative error
  //status.
  always@(posedge clk)
    begin
      if (rst_clk) begin
        compare_lsb <=#TCQ 1'b0;
        compare_msb <=#TCQ 1'b0;
        cmp_err     <=#TCQ 1'b0;
      end else begin
        if (compare_en0) begin
          compare_lsb <=#TCQ |comp_lsb;
          cmp_err     <=#TCQ (compare_lsb | compare_msb);
        end 
        if (compare_en1) begin
          compare_msb <=#TCQ |comp_msb;
          cmp_err     <=#TCQ (compare_lsb | compare_msb);
        end
      end 
    end

  //An error occurs if the compared bits are incorrect or if there is already
  //an existing error flagged.
  always @(posedge clk)
    begin
       if (rst_clk)
         compare_error_i <=#TCQ 1'b0;
       else if (clear_error)
         compare_error_i <=#TCQ 1'b0;
       else if (~cmp_err && ~compare_error_i)
         compare_error_i <=#TCQ 1'b0;
       else
         compare_error_i <=#TCQ 1'b1;
    end

  always @(posedge clk) begin
    if (rst_clk) begin
      compare_error_2i <=#TCQ 0;
      compare_error    <=#TCQ 0;
    end else begin
      compare_error_2i <=#TCQ compare_error_i;
      compare_error    <=#TCQ compare_error_2i;
    end
  end

  // synthesis translate_off
  always @(negedge clk)
    begin
      if (compare_error_i) begin
        $display (" DATA ERROR at time %t" , $time);
        $stop;
      end
    end
  // synthesis translate_on


endmodule
