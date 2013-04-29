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
//  /   /         Filename           : phy_read_dly_ctrl.v
// /___/   /\     Date Last Modified : $date$
// \   \  /  \    Date Created       : Dec 14, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//  This module
//  1. Drives the IODELAY control (rst, ce, inc, and load) for each clock and
//     data I/O based on the control from the calibration logic.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_read_dly_ctrl #
(
  parameter MEMORY_WIDTH    = 36,         // Width of each memory
  parameter NUM_DEVICES     = 2,          // Number of memory devices
  parameter DEVICE_ID       = 0,          // Indicates memory device instance
  parameter MIN_TAPS        = 5,          // minimum usuable clock tap setting
  parameter MAX_TAPS        = 5,          // maximum usuable clock tap setting
  parameter TAP_BITS        = 5,          // Number of bits to represent DEVICE_TAPS
  parameter CQ_BITS         = 1,          // Number of bits to represent number of cq/cq#'s
  parameter Q_BITS          = 7,          // Number of bits to represent number of q's
  parameter SIM_CAL_OPTION  = "NONE",     // Skip various calibration steps - 
                                          //"NONE, "FAST_CAL", "SKIP_CAL"
  parameter MEM_TYPE        = "QDR2PLUS", // Memory Type (QDR2PLUS, QDR2)
  parameter DEBUG_PORT      = "ON",       // Debug using Chipscope controls
  parameter TCQ             = 100         // Register delay
)
(
  // System Signals
  input                         clk_rd,             // half freq CQ clock
  input                         rst_clk_rd,         // reset syncrhonized to clk_rd

  // Stage 1 Calibration Signals Synchronized to clk_rd
  input [CQ_BITS-1:0]           cq_num_active,      // indicates which CQ/CQ# the control is for 
  input [Q_BITS-1:0]            q_bit_active,       // indictes which Q the control is for
  input [TAP_BITS-1:0]          cq_num_load,        // iodelay load value for CQ
  input [TAP_BITS-1:0]          cqn_num_load,       // iodelay load value for CQ#
  input [TAP_BITS-1:0]          q_bit_load,         // iodelay load value for Q
  input                         cq_num_rst,         // iodelay rst control for CQ
  input                         cq_num_ce,          // iodelay ce control for CQ
  input                         cq_num_inc,         // iodelay inc control for CQ
  input                         cqn_num_rst,        // iodelay rst control for CQ#
  input                         cqn_num_ce,         // iodelay ce control for CQ#
  input                         cqn_num_inc,        // iodelay inc control for CQ#
  input                         q_bit_rst,          // iodelay rst for Q
  input                         q_bit_ce,           // iodelay ce for Q
  input                         q_bit_inc,          // iodelay inc for Q
  input                         q_bit_clkinv,       // invert clk/clkb inputs of iserdes
  input                         cal_stage1_done,

  // Phase Detector Signals
  input                         cal_stage2_done,    // indicates stage 2 calibration is complete
  input                         pd_en_maintain,     // iodelay ce from phase detector
  input                         pd_incdec_maintain, // iodelay inc/dec from phase detector
  
  // chipscope debug signals
  input [Q_BITS-1:0]            dbg_sel_q_clkrd,
  input [CQ_BITS-1:0]           dbg_sel_cq_clkrd,
  input [CQ_BITS-1:0]           dbg_sel_cqn_clkrd,
  input                         dbg_inc_q_clkrd,
  input                         dbg_dec_q_clkrd,
  input                         dbg_inc_cq_clkrd,
  input                         dbg_dec_cq_clkrd,
  input                         dbg_inc_cqn_clkrd,
  input                         dbg_dec_cqn_clkrd,
  input                         dbg_inc_q_all_clkrd,
  input                         dbg_dec_q_all_clkrd,
  input                         dbg_inc_cq_all_clkrd,
  input                         dbg_dec_cq_all_clkrd,
  input                         dbg_inc_cqn_all_clkrd,
  input                         dbg_dec_cqn_all_clkrd,
  
  // IDELAY/ISERDES Signals
  output reg                    cq_dly_ce,          // CQ IDELAY clock enable
  output reg                    cq_dly_inc,         // CQ IDELAY increment
  output reg                    cq_dly_rst,         // CQ IDELAY clock reset
  output reg [TAP_BITS-1:0]     cq_dly_load,        // CQ IDELAY cntvaluein load value
  output reg                    cqn_dly_ce,         // CQ# IDELAY clock enable
  output reg                    cqn_dly_inc,        // CQ# IDELAY increment
  output reg                    cqn_dly_rst,        // CQ# IDELAY clock reset
  output reg [TAP_BITS-1:0]     cqn_dly_load,       // CQ# IDELAY cntvaluein load value
  output reg [MEMORY_WIDTH-1:0] q_dly_ce,           // Q IDELAY clock enable
  output reg                    q_dly_inc,          // Q IDELAY increment
  output reg [MEMORY_WIDTH-1:0] q_dly_rst,          // Q IDELAY clock reset
  output reg [TAP_BITS-1:0]     q_dly_load,         // Q IDELAY cntvaluein load value
  output reg                    q_dly_clkinv,       // ISERDES clk inversion
  output reg                    iserdes_rst         // ISERDES reset
);

  reg                    q_dly_clkinv_r;
  reg                    clkinv_changed;
  reg                    iserdes_rst_int;
  reg                    iserdes_rst_int_r;
  reg                    iserdes_rst_int_2r;
  reg                    iserdes_rst_int_3r;
  reg                    iserdes_rst_int_4r;
  reg [TAP_BITS-1:0]     q_bit_target;
  reg [TAP_BITS-1:0]     q_bit_current;
  reg [MEMORY_WIDTH-1:0] q_bit_load_ce;
  reg                    taps_match;

  // Drive IODELAY load values to all CQs, CQ#s, and Qs - loaded on reset
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      cq_dly_load   <= #TCQ MIN_TAPS;
      cqn_dly_load  <= #TCQ MIN_TAPS;
      q_dly_load    <= #TCQ 0;
    end else begin
      cq_dly_load   <= #TCQ cq_num_load;
      cqn_dly_load  <= #TCQ cqn_num_load;
      q_dly_load    <= #TCQ q_bit_load;
    end
  end
  
  // Drive IODLEAY inc values to all CQs, CQ#s, and Qs. Drive with signals from
  // stage 1 calibration until stage 2 is complete. Then drive with signals
  // from phase detector.
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      cq_dly_inc  <= #TCQ 1;
      cqn_dly_inc <= #TCQ 1;
      q_dly_inc   <= #TCQ 1;
    end else begin
      if (DEBUG_PORT == "OFF") begin
        cq_dly_inc  <= #TCQ cal_stage2_done ? pd_incdec_maintain : cq_num_inc;
        cqn_dly_inc <= #TCQ cal_stage2_done ? pd_incdec_maintain : cqn_num_inc;
        q_dly_inc   <= #TCQ cal_stage2_done ? 0 : q_bit_inc;
      end else begin 
        cq_dly_inc  <= #TCQ cal_stage1_done ? 
                       (pd_incdec_maintain || dbg_inc_cq_clkrd || 
                        dbg_inc_cq_all_clkrd)  : cq_num_inc; 
        cqn_dly_inc <= #TCQ cal_stage1_done ? 
                       (pd_incdec_maintain || dbg_inc_cqn_clkrd || 
                        dbg_inc_cqn_all_clkrd) : cqn_num_inc;
        q_dly_inc   <= #TCQ cal_stage1_done ? ( dbg_inc_q_clkrd || 
                        dbg_inc_q_all_clkrd)   : q_bit_inc;
      end 
    end
  end

  // IODELAY/ISERDES control is sent to the I/O's for this memory only if this
  // device is the target (cq_num_active == DEVICE_ID). For clock enables, send
  // the control to the I/O's from calibration logic during stage 1 and 2
  // calibration. After that they are driven from the phase detector.

  // ISERDES  clk/clkb input polarity control
  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      q_dly_clkinv <= #TCQ 0;
    else if (cq_num_active == DEVICE_ID)
      q_dly_clkinv <= #TCQ q_bit_clkinv;
  end

  // Issue ISERDES reset whenever clock inversion control changes
  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      q_dly_clkinv_r <= #TCQ 0;
    else
      q_dly_clkinv_r <= #TCQ q_dly_clkinv;
  end

  // Indicate if q_bit_clkinv changed states
  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      clkinv_changed <= #TCQ 0;
    else
      clkinv_changed <= #TCQ q_dly_clkinv ^ q_dly_clkinv_r;
  end

  // Shared ISERDES reset across all clock and data within clock group. 
  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      iserdes_rst_int <= #TCQ 1;
    else if (cq_num_active == DEVICE_ID)
      iserdes_rst_int <= #TCQ clkinv_changed || cq_num_rst || cqn_num_rst;
    else
      iserdes_rst_int <= #TCQ 0;
  end

  // Extend the reset to ensure that it is seen when the clocks move as a
  // result of the taps be inc/dec or reset
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      iserdes_rst_int_r   <= #TCQ 1;
      iserdes_rst_int_2r  <= #TCQ 1;
      iserdes_rst_int_3r  <= #TCQ 1;
      iserdes_rst_int_4r  <= #TCQ 1;
    end else begin
      iserdes_rst_int_r   <= #TCQ iserdes_rst_int;
      iserdes_rst_int_2r  <= #TCQ iserdes_rst_int_r;
      iserdes_rst_int_3r  <= #TCQ iserdes_rst_int_2r;
      iserdes_rst_int_4r  <= #TCQ iserdes_rst_int_3r;
    end
  end

  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      iserdes_rst <= #TCQ 1;
    else
      iserdes_rst <= #TCQ iserdes_rst_int || iserdes_rst_int_r ||
                          iserdes_rst_int_2r || iserdes_rst_int_3r || 
                          iserdes_rst_int_4r;
  end

// Individual CQ IODELAY enables
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      cq_dly_ce <= #TCQ 0;
    end else if ( DEBUG_PORT == "OFF") begin
      if (cq_num_active == DEVICE_ID)
        cq_dly_ce <= #TCQ cal_stage2_done ? pd_en_maintain : cq_num_ce;
      else
        cq_dly_ce <= #TCQ cal_stage2_done ? pd_en_maintain : 0;
    end else if (DEBUG_PORT == "ON" && cal_stage2_done) begin
       if (dbg_sel_cq_clkrd == DEVICE_ID)   
          cq_dly_ce <= #TCQ (pd_en_maintain || dbg_inc_cq_clkrd || 
                      dbg_dec_cq_clkrd || dbg_inc_cq_all_clkrd ||
                      dbg_dec_cq_all_clkrd );
       else 
          cq_dly_ce <= #TCQ pd_en_maintain || dbg_inc_cq_all_clkrd || dbg_dec_cq_all_clkrd ;
    end else if ((DEBUG_PORT == "ON") && !cal_stage2_done) begin
      if (cq_num_active == DEVICE_ID)
        cq_dly_ce <= #TCQ cq_num_ce;
      else
        cq_dly_ce <= #TCQ 0;    
    end else begin
      cq_dly_ce <= #TCQ 0; 
    end
  end

  // Individual CQ IODELAY resets with load values
  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      cq_dly_rst <= #TCQ 1;
    else if (cq_num_active == DEVICE_ID)
      cq_dly_rst <= #TCQ cq_num_rst;
    else
      cq_dly_rst <= #TCQ 0;
  end
  
  // Individual CQ IODELAY enables
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      cqn_dly_ce <= #TCQ 0;
    end else if ( DEBUG_PORT == "OFF") begin
      if (cq_num_active == DEVICE_ID)
        cqn_dly_ce <= #TCQ cal_stage2_done ? pd_en_maintain : cqn_num_ce;
      else
        cqn_dly_ce <= #TCQ cal_stage2_done ? pd_en_maintain : 0;
    end else if (DEBUG_PORT == "ON" && cal_stage2_done) begin
       if (dbg_sel_cqn_clkrd == DEVICE_ID)   
          cqn_dly_ce <= #TCQ (pd_en_maintain || dbg_inc_cqn_clkrd || 
                      dbg_dec_cqn_clkrd || dbg_inc_cqn_all_clkrd ||
                      dbg_dec_cqn_all_clkrd );
       else 
          cqn_dly_ce <= #TCQ pd_en_maintain || dbg_inc_cqn_all_clkrd || dbg_dec_cqn_all_clkrd ;
    end else if ((DEBUG_PORT == "ON") && !cal_stage2_done) begin
      if (cq_num_active == DEVICE_ID)
        cqn_dly_ce <= #TCQ cqn_num_ce;
      else
        cqn_dly_ce <= #TCQ 0;    
    end else begin
      cqn_dly_ce <= #TCQ 0; 
    end
  end

  // Individual CQ# IODELAY resets with load values
  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      cqn_dly_rst <= #TCQ 1;
    else if (cq_num_active == DEVICE_ID)
      cqn_dly_rst <= #TCQ cqn_num_rst;
    else
      cqn_dly_rst <= #TCQ 0;
  end

  // Save the value of q_bit load whenever a reset is issued
  always @ (posedge clk_rd) begin
    if (rst_clk_rd) begin
      q_bit_target   <= #TCQ 0;
    end else if (MEM_TYPE=="QDR2PLUS" ||
                 MEM_TYPE=="QDR2" ) begin
      q_bit_target   <= #TCQ 0;
    end else if (|q_dly_rst) begin //save for any reset since a shared signal
      q_bit_target   <= #TCQ q_dly_load;
    end
  end
  
  //generate a flag for when taps expected and current do not match
  always @ (posedge clk_rd) begin
    if (rst_clk_rd)
      taps_match   <= #TCQ 0;
    else if (q_bit_current == q_bit_target)
      taps_match   <= #TCQ 1;
    else
      taps_match   <= #TCQ 0;
  end
  
  // Update the value of q_bit_current
  // want to increment taps to match the q_bit_target value
  // set via parralel load
  always @ (posedge clk_rd) begin
    if (rst_clk_rd) begin
      q_bit_current   <= #TCQ 0;
    end else if (MEM_TYPE=="QDR2PLUS" ||
                 MEM_TYPE=="QDR2") begin
      q_bit_current   <= #TCQ 0;
    end else if (|q_dly_rst) begin
      q_bit_current   <= #TCQ 0;
    end else if (q_bit_current != q_bit_target) begin
      q_bit_current   <= #TCQ q_bit_current + 1;
    end else begin
      q_bit_current   <= #TCQ q_bit_current;
    end
  end
  
  // IODELAY control is sent to the I/O's for this memory only if this
  // device is the target.

  genvar mw_i;
  generate
    for (mw_i=0; mw_i < MEMORY_WIDTH; mw_i=mw_i+1) 
    begin : q_dlyctrl_inst
    
      // Increment the taps of a given bit to the target value
      // this assumes enough time is given after rst with the current bit 
      // to reach the target value
      always @ (posedge clk_rd) begin
        if (rst_clk_rd) begin
          q_bit_load_ce[mw_i]   <= #TCQ 0;
        end else if (MEM_TYPE=="QDR2PLUS" ||
                     MEM_TYPE=="QDR2" ) begin
          q_bit_load_ce[mw_i]   <= #TCQ 0;
        end else if (!taps_match) begin
          if (q_bit_active == mw_i+(MEMORY_WIDTH*DEVICE_ID)) 
            q_bit_load_ce[mw_i] <= #TCQ 1;
          else if (SIM_CAL_OPTION == "FAST_CAL" && cq_num_active == DEVICE_ID)
            q_bit_load_ce[mw_i] <= #TCQ 1;
          else
            q_bit_load_ce[mw_i] <= #TCQ 0;
        end else begin
          q_bit_load_ce[mw_i] <= #TCQ 0;
        end
      end

      // Individual Q IODELAY enables
      always @(posedge clk_rd) begin
        if (rst_clk_rd)
          q_dly_ce[mw_i] <= #TCQ 0;
        else if (SIM_CAL_OPTION == "FAST_CAL" && cq_num_active == DEVICE_ID)
          q_dly_ce[mw_i] <= #TCQ q_bit_ce | q_bit_load_ce[mw_i];
        else if (DEBUG_PORT == "OFF") 
          if (q_bit_active == mw_i+(MEMORY_WIDTH*DEVICE_ID)) 
            q_dly_ce[mw_i] <= #TCQ q_bit_ce | q_bit_load_ce[mw_i];
          else
            q_dly_ce[mw_i] <= #TCQ 0;
        else if ((DEBUG_PORT == "ON") && cal_stage1_done) 
          if (dbg_sel_q_clkrd == mw_i+(MEMORY_WIDTH*DEVICE_ID))
            q_dly_ce[mw_i] <= #TCQ (dbg_inc_q_clkrd || dbg_dec_q_clkrd || 
                                    dbg_inc_q_all_clkrd || dbg_dec_q_all_clkrd);
          else
            q_dly_ce[mw_i] <= #TCQ (dbg_inc_q_all_clkrd || dbg_dec_q_all_clkrd);
        else if ((DEBUG_PORT == "ON") && !cal_stage1_done)
          if (q_bit_active == mw_i+(MEMORY_WIDTH*DEVICE_ID)) 
            q_dly_ce[mw_i] <= #TCQ q_bit_ce | q_bit_load_ce[mw_i];
          else
            q_dly_ce[mw_i] <= #TCQ 0;
        else
          q_dly_ce[mw_i] <= #TCQ 0;
      end

      // Individual Q IODELAY resets with load values
      always @(posedge clk_rd) begin
        if (rst_clk_rd)
          q_dly_rst[mw_i] <= #TCQ 1;
        else if (SIM_CAL_OPTION == "FAST_CAL" && cq_num_active == DEVICE_ID)
          q_dly_rst[mw_i] <= #TCQ q_bit_rst;
        else if (q_bit_active == mw_i+(MEMORY_WIDTH*DEVICE_ID)) 
          q_dly_rst[mw_i] <= #TCQ q_bit_rst;
        else
          q_dly_rst[mw_i] <= #TCQ 0;
      end
    end
  endgenerate

endmodule
