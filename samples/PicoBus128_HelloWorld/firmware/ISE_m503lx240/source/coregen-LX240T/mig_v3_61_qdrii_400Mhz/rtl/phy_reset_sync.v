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
 
//*****************************************************************************
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor              : Xilinx
// \   \   \/     Version             : 3.6.1 
//  \   \         Application         : MIG
//  /   /         Filename            : phy_reset_sync.v
// /___/   /\     Date Last Modified  : $date$
// \   \  /  \    Date Created        : Nov 18, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design Name: QDRII+ / RLDRAM-II
//Purpose:
//   reset synchronization and memory initialization
//Reference:
//Revision History:
//*****************************************************************************

`timescale 1ps/1ps

module phy_reset_sync#(
  parameter CLK_STABLE      = 2048,   //Cycles till CQ/CQ# are stable
  parameter CLK_PERIOD      = 3752,   //Internal Fabric Clk Period (in ps)
  parameter RST_ACT_LOW     = 1,      //sys reset is active low
  parameter NUM_DEVICES     = 2,      //No. of Memory Devices
  parameter SIM_INIT_OPTION = "NONE", //Simulation Only mode
  parameter TCQ             = 100     //Register Delay
)
(
  input                         sys_rst,          //System Reset from MMCM
  input                         clk,              //Half Freq. System Clock
  (* shreg_extract = "no" *)
  output wire                   rst_clk,          //Reset Sync to CLK
  (* shreg_extract = "no" *)
  output wire                   rst_wr_clk,       //Reset Sync to CLK for write path only
  input       [NUM_DEVICES-1:0] clk_rd,           //Read Path clock generated from CQ/CQ#
  (* shreg_extract = "no" *)
  (* max_fanout = "50" *)
  output wire [NUM_DEVICES-1:0] rst_clk_rd,       //Read Path reset 
  input                         mmcm_locked,      //MMCM clocks are locked
  input                         iodelay_ctrl_rdy, //IODELAY controller ready signal
  output wire                   mem_dll_off_n     //DLL off signal to Memory Device
);

  // # of clock cycles to delay deassertion of reset. Needs to be a fairly
  // high number not so much for metastability protection, but to give time
  // for reset (i.e. stable clock cycles) to propagate through all state
  // machines and to all control signals (i.e. not all control signals have
  // resets, instead they rely on base state logic being reset, and the effect
  // of that reset propagating through the logic). Need this because we may not
  // be getting stable clock cycles while reset asserted (i.e. since reset
  // depends on DCM lock status)
  localparam RST_SYNC_NUM = 5;  //*FIXME*

  //Calculate the number of cycles needed for 200 us.  This is used to
  //initialize the memory device and turn off the dll signal to it.
  localparam INIT_DONE = (SIM_INIT_OPTION != "NONE") 
                          ? 10 : (200*1000*1000/CLK_PERIOD);

  //Wire Delcarations
  wire                    sys_rst_act_hi;
  wire                    rst_wr_clk_tmp;
  wire                    rst_clk_tmp;
  wire [NUM_DEVICES-1:0]  rst_clk_rd_tmp;

  reg             init_cnt_done;
  reg             init_cnt_done_r;
  reg             cq_stable;
  reg     [11:0]  cq_cnt;
  reg     [16:0]  init_cnt;

  //Initialize all bits to 1
  (* shreg_extract = "no" *)
  (* max_fanout = "50" *)
  reg [RST_SYNC_NUM-1:0]  rst_wr_clk_sync_r  = -1;
  (* shreg_extract = "no" *)
  (* max_fanout = "50" *)
  reg [RST_SYNC_NUM-1:0]  rst_clk_sync_r     = -1;
  reg [RST_SYNC_NUM-1:0]  rst_clk_rd_sync_r [NUM_DEVICES-1:0] ;

  //---------------------------------------------------------------------------
  //Reset Synchronization Logic
  // 1. RST_WR_CLK - Synchronized to CLK however should also be 
  // held as long as the clocks are not locked indicated by the mmcm or 
  // if the IODELAY controller is not ready yet
  //
  // 2. RST_CLK - This reset is sync. to CLK and should be held as long as
  // clocks CQ/CQ# coming back from the memory device is not yet stable.  
  // It is assumed stable based on the parameter CLK_STABLE taken from the
  // memory spec.
  //
  // 3. RST_CLK_RD - Synchonronized to clk_rd, this reset should be held until
  // clocks CQ/CQ# are stable.
  //---------------------------------------------------------------------------
  assign sys_rst_act_hi   = RST_ACT_LOW ? ~sys_rst: sys_rst;
  assign rst_wr_clk_tmp   = ~mmcm_locked | sys_rst_act_hi | ~iodelay_ctrl_rdy;
  assign rst_clk_tmp      = ~cq_stable   | sys_rst_act_hi;
  
  genvar i;
  generate
    for(i = 0; i < NUM_DEVICES; i = i +1)
      begin : RST_CLK_RD_TMP
        assign rst_clk_rd_tmp[i]  = ~cq_stable   | sys_rst_act_hi;
      end 
  endgenerate

  always @(posedge clk or posedge rst_wr_clk_tmp)
    if (rst_wr_clk_tmp)
      rst_wr_clk_sync_r <= #TCQ {(RST_SYNC_NUM){1'b1}};
    else
      // logical left shift by one (pads with 0)
      rst_wr_clk_sync_r <= #TCQ rst_wr_clk_sync_r << 1;
 
  assign rst_wr_clk = rst_wr_clk_sync_r[RST_SYNC_NUM-1];

  always @(posedge clk or posedge rst_clk_tmp)
    if (rst_clk_tmp)
      rst_clk_sync_r <= #TCQ {RST_SYNC_NUM{1'b1}};
    else
      rst_clk_sync_r <= #TCQ rst_clk_sync_r << 1;
  
  assign rst_clk = rst_clk_sync_r[RST_SYNC_NUM-1];

  genvar j;
  generate
    for(j = 0; j < NUM_DEVICES; j = j +1)
      begin : RST_CLK_RD_SYNC_R
        always @(posedge clk_rd[j] or posedge rst_clk_rd_tmp[j])
          begin 
            if (rst_clk_rd_tmp[j])
              rst_clk_rd_sync_r[j] <= #TCQ {RST_SYNC_NUM{1'b1}};
            else
              rst_clk_rd_sync_r[j] <= #TCQ rst_clk_rd_sync_r[j] << 1;
          end
      end 
  endgenerate

  genvar k;
  generate 
    for (k = 0; k < NUM_DEVICES; k = k+1)
      begin: RST_CLK_RD
        assign rst_clk_rd[k] = rst_clk_rd_sync_r[k][RST_SYNC_NUM-1];
      end
  endgenerate


  //---------------------------------------------------------------------------
  //Initialization Logic for Memory
  //The counters below are used to determine when the CQ/CQ# clocks are stable
  //and memory initialization is complete.
  //This logic operates on the same clock and reset as the write path logic to
  //ensure the counters are in sync to that of driving the K/K# clocks.  They
  //should remain in sync as CQ/CQ# are echos of K/K#
  //---------------------------------------------------------------------------

  //init_cnt generates a 200 us counter based on CLK_PERIOD.
  //This counter is needed to determine when to turn of the dll signal to
  //memory and initialization of the memory is considered complete.
  always @ (posedge clk)
    begin
      if (rst_wr_clk)
        init_cnt <=#TCQ 0;
      else if (init_cnt_done_r == 1'b0 && (init_cnt != INIT_DONE))
        init_cnt <=#TCQ init_cnt + 1;
     end

  //Signal init_cnt_done once 200 us is up
  always @ (posedge clk)
    begin
      if (rst_wr_clk) begin
        init_cnt_done   <=#TCQ 1'b0;
        init_cnt_done_r <=#TCQ 1'b0;
      end else if (init_cnt == INIT_DONE) begin
        init_cnt_done   <=#TCQ 1'b1;
        init_cnt_done_r <=#TCQ init_cnt_done;
      end
    end

  assign mem_dll_off_n = init_cnt_done_r;

  // Count CLK_STABLE cycles to determine that CQ/CQ# clocks are stable.  When
  // ready, both RST_CLK and RST_CLK_RD can come out of reset.  Only start
  // counting once the the initial count for memory is complete (ie
  // init_cnt_done_r)
  always @(posedge clk)
    begin
      if (rst_wr_clk)
        cq_cnt <= 0;
      else if ((init_cnt_done_r) && (cq_cnt != CLK_STABLE))
        cq_cnt <= cq_cnt + 1;
    end

  always @(posedge clk)
    begin
      if (rst_wr_clk) begin
        cq_stable   <=#TCQ 1'b0;
      end else if (cq_cnt == CLK_STABLE) begin
        cq_stable   <=#TCQ 1'b1;
      end
    end

endmodule
