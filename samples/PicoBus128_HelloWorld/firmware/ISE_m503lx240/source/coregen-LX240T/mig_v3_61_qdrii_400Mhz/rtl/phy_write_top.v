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
//  /   /         Filename           : phy_write_top.v
// /___/   /\     Date Last Modified : $date$
// \   \  /  \    Date Created       : Nov 12, 2008 
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ 
//
//Purpose:
//    This module
//  1. Instantiates all the write path submodules
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_write_top #
(
  parameter BURST_LEN   = 4,            //Burst Length
  parameter REFCLK_FREQ = 300.0,        //Ref. Clk Freq. for IODELAYs
  parameter CLK_PERIOD  = 3752,         //Internal Fabric Clk Period (in ps)
  parameter NUM_DEVICES = 2,            //Memory Devices
  parameter DATA_WIDTH  = 72,           //Data Width
  parameter ADDR_WIDTH  = 19,           //Address Width
  parameter BW_WIDTH    = 8,            //Byte Write Width
  parameter IODELAY_GRP = "IODELAY_MIG",// May be assigned unique name 
                                        // when mult IP cores in design
  parameter TCQ         = 100           //Register Delay
)
(
  //System Signals
  input                           clk,             //main system half freq clk
  input                           rst_wr_clk,      //main write path reset
  input                           clk_mem,         //full frequency clock

  //Read Path Interface
  input                           cal_done,        //calibration done
  input                           cal_stage1_start,//stage 1 calibration start
  input                           cal_stage2_start,//stage 2 calibration start
  output wire                     init_done,       //init done, cal can begin

  //User Interface
  input                           wr_cmd0,         //wr command 0
  input                           wr_cmd1,         //wr command 1
  input       [ADDR_WIDTH-1:0]    wr_addr0,        //wr address 0
  input       [ADDR_WIDTH-1:0]    wr_addr1,        //wr address 1
  input                           rd_cmd0,         //rd command 0
  input                           rd_cmd1,         //rd command 1
  input       [ADDR_WIDTH-1:0]    rd_addr0,        //rd address 0
  input       [ADDR_WIDTH-1:0]    rd_addr1,        //rd address 1
  input       [DATA_WIDTH*2-1:0]  wr_data0,        //user write data 0
  input       [DATA_WIDTH*2-1:0]  wr_data1,        //user write data 1
  input       [BW_WIDTH*2-1:0]    wr_bw_n0,        //user byte writes 0
  input       [BW_WIDTH*2-1:0]    wr_bw_n1,        //user byte writes 1
  
  //Outputs to IOBs
  output wire [1:0]               int_rd_cmd_n,    //internal rd cmd
  output wire [1:0]               int_wr_cmd_n,    //internal rd cmd
  output wire [ADDR_WIDTH-1:0]    iob_addr_rise0,  //OSERDES addr rise0
  output wire [ADDR_WIDTH-1:0]    iob_addr_fall0,  //OSERDES addr fall0
  output wire [ADDR_WIDTH-1:0]    iob_addr_rise1,  //OSERDES addr rise1
  output wire [ADDR_WIDTH-1:0]    iob_addr_fall1,  //OSERDES addr fall1

  output wire [DATA_WIDTH-1:0]    iob_data_rise0,  //OSERDES d rise0
  output wire [DATA_WIDTH-1:0]    iob_data_fall0,  //OSERDES d fall0
  output wire [DATA_WIDTH-1:0]    iob_data_rise1,  //OSERDES d rise1
  output wire [DATA_WIDTH-1:0]    iob_data_fall1,  //OSERDES d fall1
  output wire [BW_WIDTH-1:0]      iob_bw_rise0,    //OSERDES bw rise0
  output wire [BW_WIDTH-1:0]      iob_bw_fall0,    //OSERDES bw fall0
  output wire [BW_WIDTH-1:0]      iob_bw_rise1,    //OSERDES bw rise1
  output wire [BW_WIDTH-1:0]      iob_bw_fall1,    //OSERDES bw fall1

  //ChipScope Debug Signals
  output wire [1:0]               dbg_phy_wr_cmd_n,//cs debug - wr command
  output wire [ADDR_WIDTH*4-1:0]  dbg_phy_addr,    //cs debug - address
  output wire [1:0]               dbg_phy_rd_cmd_n,//cs debug - rd command
  output wire [DATA_WIDTH*4-1:0]  dbg_phy_wr_data  //cs debug - wr data
);

  wire [1:0]              init_rd_cmd;
  wire [1:0]              init_wr_cmd;
  wire [ADDR_WIDTH-1:0]   init_wr_addr0;
  wire [ADDR_WIDTH-1:0]   init_wr_addr1;
  wire [ADDR_WIDTH-1:0]   init_rd_addr0;
  wire [ADDR_WIDTH-1:0]   init_rd_addr1;
  wire [DATA_WIDTH*2-1:0] init_wr_data0;
  wire [DATA_WIDTH*2-1:0] init_wr_data1;

  phy_write_control_io  #(
    .BURST_LEN   (BURST_LEN),
    .CLK_PERIOD  (CLK_PERIOD),
    .ADDR_WIDTH  (ADDR_WIDTH),
    .TCQ         (TCQ)
  ) u_phy_write_control (
    .clk                (clk),
    .rst_wr_clk         (rst_wr_clk),
    .clk_mem            (clk_mem),
    .wr_cmd0            (wr_cmd0),
    .wr_cmd1            (wr_cmd1),
    .wr_addr0           (wr_addr0),
    .wr_addr1           (wr_addr1),
    .rd_cmd0            (rd_cmd0),
    .rd_cmd1            (rd_cmd1),
    .rd_addr0           (rd_addr0),
    .rd_addr1           (rd_addr1),
    .init_rd_cmd        (init_rd_cmd),
    .init_wr_cmd        (init_wr_cmd),
    .init_wr_addr0      (init_wr_addr0),
    .init_wr_addr1      (init_wr_addr1),
    .init_rd_addr0      (init_rd_addr0),
    .init_rd_addr1      (init_rd_addr1),
    .cal_done           (cal_done),
    .int_rd_cmd_n       (int_rd_cmd_n),
    .int_wr_cmd_n       (int_wr_cmd_n),     
    .iob_addr_rise0     (iob_addr_rise0), 
    .iob_addr_fall0     (iob_addr_fall0), 
    .iob_addr_rise1     (iob_addr_rise1), 
    .iob_addr_fall1     (iob_addr_fall1),  
    .dbg_phy_wr_cmd_n   (dbg_phy_wr_cmd_n),
    .dbg_phy_addr       (dbg_phy_addr),    
    .dbg_phy_rd_cmd_n   (dbg_phy_rd_cmd_n)
  );

  phy_write_data_io #(
    .BURST_LEN   (BURST_LEN),
    .CLK_PERIOD  (CLK_PERIOD),
    .DATA_WIDTH  (DATA_WIDTH),
    .BW_WIDTH    (BW_WIDTH),
    .TCQ         (TCQ)
  ) u_phy_write_data (
    .clk                (clk),
    .rst_wr_clk         (rst_wr_clk), 
    .clk_mem            (clk_mem),
    .cal_done           (cal_done),  
    .wr_cmd0            (wr_cmd0),
    .wr_cmd1            (wr_cmd1),    
    .init_wr_cmd        (init_wr_cmd), 
   // .int_wr_cmd_n       (int_wr_cmd_n),      
    .init_wr_data0      (init_wr_data0),
    .init_wr_data1      (init_wr_data1),
    .wr_data0           (wr_data0), 
    .wr_data1           (wr_data1),
    .wr_bw_n0           (wr_bw_n0), 
    .wr_bw_n1           (wr_bw_n1),
    .iob_data_rise0     (iob_data_rise0),
    .iob_data_fall0     (iob_data_fall0), 
    .iob_data_rise1     (iob_data_rise1),
    .iob_data_fall1     (iob_data_fall1),
    .iob_bw_rise0       (iob_bw_rise0), 
    .iob_bw_fall0       (iob_bw_fall0), 
    .iob_bw_rise1       (iob_bw_rise1),  
    .iob_bw_fall1       (iob_bw_fall1),
    .dbg_phy_wr_data    (dbg_phy_wr_data) 
  );

  phy_write_init_sm #(
    .BURST_LEN   (BURST_LEN),
    .ADDR_WIDTH  (ADDR_WIDTH),
    .DATA_WIDTH  (DATA_WIDTH),
    .REFCLK_FREQ (REFCLK_FREQ),
    .TCQ         (TCQ)
  ) u_phy_write_init_sm (
    .clk                (clk), 
    .rst_wr_clk         (rst_wr_clk),
    .cal_stage1_start   (cal_stage1_start),
    .cal_stage2_start   (cal_stage2_start),
    .init_done          (init_done), 
    .init_wr_data0      (init_wr_data0),
    .init_wr_data1      (init_wr_data1),
    .init_wr_addr0      (init_wr_addr0),
    .init_wr_addr1      (init_wr_addr1),
    .init_rd_addr0      (init_rd_addr0),
    .init_rd_addr1      (init_rd_addr1),
    .init_rd_cmd        (init_rd_cmd),
    .init_wr_cmd        (init_wr_cmd)
  );

endmodule
