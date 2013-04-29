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
//  /   /         Filename           : phy_read_stage1_cal.v
// /___/   /\     Date Last Modified    : $date$          
// \   \  /  \    Date Created          : Nov 18, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//  This module
//  1. Center aligns the incoming Q data to the respective CQ and CQ# clocks on
//     a per bit basis.
//  2. Determines if the data from the ISERDES must be realigned.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_read_stage1_cal #
(
  parameter DATA_WIDTH       = 72,          // Total data width across all memories
  parameter NUM_DEVICES      = 2,           // Number of memory devices
  parameter MEMORY_WIDTH     = 36,          // Width of each memory
  parameter DEVICE_TAPS      = 32,          // Number of taps in target IDELAY
  parameter TAP_BITS         = 5,           // Number of bits needed to represent DEVICE_TAPS
  parameter IODELAY_TAP_RES  = 52,          // IODELAY tap resolution in ps
  parameter CENTER_TAP       = 9,           // Number of taps to "ideal" center
  parameter MIN_TAPS         = 5,           // minimum usuable clock tap setting
  parameter MAX_TAPS         = 5,           // maximum usuable clock tap setting
  parameter CQ_BITS          = 1,           // Number of bits needed to represent number of cq/cq#'s
  parameter Q_BITS           = 7,           // Number of bits needed to represent number of q's
  parameter MEM_TYPE         = "QDR2PLUS",  // Memory Type (QDR2PLUS, QDR2)
  parameter SIM_CAL_OPTION   = 0,           // Skip various calibration steps - "NONE, "FAST_CAL", "SKIP_CAL"
  parameter TCQ              = 100          // Register delay
)
(
  // System Signals
  input                     clk,              // main system half freq clk
  input                     rst_clk,          // reset syncrhonized to clk

  // Write Interface
  input                     init_done,        // indicates initialization is done
  output reg                cal_stage1_start, // indicates cal stage 1 to begin
  output reg                cal_stage2_start, // indicates cal stage 2 to begin

  // DCB Interface
  input [DATA_WIDTH-1:0]    rise_data0,       // rising data 0
  input [DATA_WIDTH-1:0]    fall_data0,       // falling data 0
  input [DATA_WIDTH-1:0]    rise_data1,       // rising data 1
  input [DATA_WIDTH-1:0]    fall_data1,       // falling data 1

  // Data Align Interface
  output reg [NUM_DEVICES-1:0]  phase,        // phase indicator for each memory
  
  // IODELAY Control Interface
  output reg [CQ_BITS-1:0]  cq_num,           // indicates which CQ/CQ# the control is for
  output reg [Q_BITS-1:0]   q_bit,            // indictes which Q the control is for
  output reg [TAP_BITS-1:0] cq_num_load,      // iodelay load value for CQ
  output reg [TAP_BITS-1:0] cqn_num_load,     // iodelay load value for CQ#
  output reg [TAP_BITS-1:0] q_bit_load,       // iodelay load value for Q
  output reg                cq_num_rst,       // iodelay rst control for CQ
  output reg                cq_num_ce,        // iodelay ce control for CQ
  output wire               cq_num_inc,       // iodelay inc control for CQ
  output reg                cqn_num_rst,      // iodelay rst control for CQ#
  output reg                cqn_num_ce,       // iodelay ce control for CQ#
  output wire               cqn_num_inc,      // iodelay inc control for CQ#
  output reg                q_bit_rst,        // iodelay rst for each Q
  output reg                q_bit_ce,         // iodelay ce for each Q
  output wire               q_bit_inc,        // iodelay inc for all Q

  // ISERDES Interface
  output reg                q_bit_clkinv,     // invert clk/clkb inputs of iserdes

  // Chipscope/Debug and Error
  output reg [NUM_DEVICES-1:0]  error_align,   // no valid data alignment found
  output wire [255:0]           dbg_rd_stage1_cal
);

  // {{{ Wire, Reg, param Declarations ----------

  // tap centering states
  localparam CTR_IDLE              = 9'b000000001;
  localparam CTR_SEEK_LEFT0        = 9'b000000010;
  localparam CTR_SEEK_LEFT0_CHK    = 9'b000000100;
  localparam CTR_SEEK_RIGHT        = 9'b000001000;
  localparam CTR_SEEK_RIGHT_CHK    = 9'b000010000;
  localparam CTR_SEEK_LEFT1        = 9'b000100000;
  localparam CTR_SEEK_LEFT1_CHK    = 9'b001000000;
  localparam CTR_SEEK_LEFT1_CHK_WT = 9'b010000000;
  localparam CTR_DONE              = 9'b100000000; 

  // main calibration states
  localparam CAL_IDLE       = 14'b00_0000_0000_0001;
  localparam CAL_Q_RISE     = 14'b00_0000_0000_0010;
  localparam CAL_Q_RISE_INV = 14'b00_0000_0000_0100;
  localparam CAL_DET_OPT    = 14'b00_0000_0000_1000;
  localparam CAL_Q_FALL     = 14'b00_0000_0001_0000;
  localparam CAL_DET_OVR    = 14'b00_0000_0010_0000;
  localparam CAL_SET_OVR    = 14'b00_0000_0100_0000;
  localparam CAL_QBIT_DET   = 14'b00_0000_1000_0000;
  localparam CAL_QBIT_SET   = 14'b00_0001_0000_0000;
  localparam CAL_ADJ_REQ    = 14'b00_0010_0000_0000;
  localparam CAL_ADJ        = 14'b00_0100_0000_0000;
  localparam CAL_SET_PHASE  = 14'b00_1000_0000_0000;
  localparam CAL_DONE       = 14'b01_0000_0000_0000;
  localparam CAL_RST_WAIT   = 14'b10_0000_0000_0000; 

  // configurable delays
  localparam TAP_ADJ_DLY    = 4;
  localparam CAL_START_DLY  = 60;
  localparam C_NUM_RDY_DLY  = 8;
  localparam Q_BIT_RDY_DLY  = 8;
  localparam TAP_DLY        = 36;
  localparam LOAD_DLY       = 12;
  localparam RST_DLY        = 36;
  localparam POL_DLY        = 36;


  // Number of cycles to make sure the data window is valid. This is an
  // averaging scheme used to make sure that the instable regions at the
  // edges of windows do not cause false positives. This can be adjusted
  // higher to sample over a larger window.
  localparam WINDOW_VLD_STABLE_CNT = (SIM_CAL_OPTION == "NONE") ? 48 : 16;

  // Parameter that is used to force subsequent data bits to look for the same
  // window that the first bit in the memory used.
  localparam LEFT0_SAME_WINDOW = 7;
  
  //localparam MEMORY_TYPE  = (MEM_TYPE == "RLD2_CIO" || MEM_TYPE == "RLD2_SIO")? "RLD2" : "QDR";    
  localparam MEMORY_TYPE  = "RLD2"; 
  
  localparam MEM_TYPE_RLD = (MEMORY_TYPE == "RLD2");  
  
  localparam MIN_WINDOW_SIZE = 3;
    
  // capture calibration data
  reg [DATA_WIDTH-1:0]      rise_data0_r; 
  reg [DATA_WIDTH-1:0]      fall_data0_r; 
  reg [DATA_WIDTH-1:0]      rise_data1_r; 
  reg [DATA_WIDTH-1:0]      fall_data1_r; 
  reg                       rd0;          
  reg                       fd0;          
  reg                       rd1;          
  reg                       fd1;          
  reg                       rd0_r;        
  reg                       fd0_r;        
  reg                       rd1_r;        
  reg                       fd1_r;        
  reg                       sample;       
  wire [3:0]                rd_window;    
  wire [7:0]                d_window;
  reg                       rd_valid_d;   
  reg                       rd_valid;
  wire [3:0]                fd_window;
  reg                       fd_valid_d;
  reg                       fd_valid;
  reg                       window_vld;
  reg                       opp_window_vld;
  
  // tap centering
  reg                       ctr_idle_rdy;
  wire                      data_rdy;
  reg                       data_rdy_r;
  wire                      start_stable_cnt;
  reg   [9:0]               stable_cnt;
  reg                       window_vld_stable;
  reg                       en_vld_check;
  reg                       stable_cnt_0;
  reg                       stable_cnt_0_r;
  reg                       data_stable;
  reg                       data_stable_r;
  reg                       init_done_r1;
  reg                       init_done_r2;
  reg                       en_data_cap;
  reg   [TAP_ADJ_DLY:0]     en_tap_adj_tmp = 0;
  reg                       en_tap_adj;
  reg                       en_rise_tap;
  reg                       en_fall_tap;
  reg   [TAP_BITS-1:0]      cq_dly_tap;
  reg   [TAP_BITS-1:0]      cqn_dly_tap;
  reg   [TAP_BITS-1:0]      q_dly_tap;
  reg                       c_tap_max;
  reg                       q_tap_max;
  reg   [8:0]               tap_ctr_ns;
  reg   [8:0]               tap_ctr_cs;
  reg                       save_left0_tap;
  reg                       save_right_tap;
  reg                       save_left1_tap;
  reg                       save_found_left0;
  reg                       save_found_right;
  reg                       save_found_left1;
  reg                       save_cdt_max;
  reg                       save_qdt_max;
  reg                       save_opp_first;
  reg                       save_done;
  reg                       issue_cdt_rst_d;
  reg                       issue_cdt_rst;
  reg                       save_start_left0_d;
  reg                       save_start_left0;
  reg                       ignore_first_right;
  reg                       right_valid;
  reg                       insuff_right;
  reg                       qmem0_start_left0;
  reg   [TAP_BITS-1:0]      qmem0_left0_tap;
  wire                      ctr_seek_st;
  wire                      ctr_c_dly_st;
  wire                      ctr_q_dly_st;
  reg   [TAP_BITS-1:0]      left0_tap;
  reg   [TAP_BITS-1:0]      right_tap;
  reg   [TAP_BITS-1:0]      left1_tap;
  reg                       found_left0;
  reg                       found_right;
  reg                       found_left1;
  reg                       cdt_max;
  reg                       qdt_max;
  reg                       opp_first;
  reg                       ctr_done_pre;
  reg                       ctr_done;
  reg   [4:0]               q0mem_left0_tap;
  reg   [4:0]               q0mem_right_tap;
  reg   [4:0]               q0mem_left1_tap;
  reg                       q0mem_found_left0;
  reg                       q0mem_found_right;
  reg                       q0mem_found_left1;
  reg                       q0mem_cdt_max;
  reg                       q0mem_qdt_max;
  reg                       q0mem_opp_first;
  reg                       q0mem_start_left0;
  reg                       start_left0;
  reg                       clpct_lte_dt;
  reg                       cr_gt_ql;
  reg                       ct_lte_dtpcr;
  reg                       left0_gr_ctr;
  reg   [TAP_BITS:0]        left0_plus_right;
  reg   [TAP_BITS:0]        left0_plus_center;
  reg   [TAP_BITS:0]        right_plus_maxt;
  reg   [TAP_BITS-1:0]      right_minus_left1;
  reg   [TAP_BITS-1:0]      left1_minus_right;
  reg   [TAP_BITS:0]        ct_minus_left1;
  reg                       cdt_selected_d;
  reg   [TAP_BITS-1:0]      optimal_tap_d;
  reg   [TAP_BITS-1:0]      tap_offset_d;
  reg                       true_center_d;
  reg                       try_clk_inv_d;
  reg   [TAP_BITS:0]        window_size_d;
  reg                       cdt_selected;
  reg   [TAP_BITS-1:0]      optimal_tap;
  reg   [TAP_BITS-1:0]      tap_offset;
  reg                       true_center;
  reg                       try_clk_inv;
  reg   [TAP_BITS:0]        window_size;
  
  // overall calibration control
  reg   [CAL_START_DLY:0]   cal_sm_start_tmp = 0;
  reg                       cal_sm_start;
  wire                      q_mem_0;
  wire                      q_bit_max;
  wire                      q_mem_max;
  reg   [13:0]              cal_cs;
  reg   [13:0]              cal_ns;
  reg                       start_ctr_cal_int;
  wire                      start_in_progress;
  reg                       cal_rise;
  reg                       save_rise_edge;
  reg                       save_rise_edge_inv;
  reg                       save_fall_edge;
  reg                       save_current;
  reg                       force_clk_invert;
  reg                       clear_clk_invert;  
  reg                       issue_dly_rst_d;
  reg                       issue_dly_rst;
  reg                       issue_load_c;
  reg                       issue_load_q;
  reg                       inc_q;
  reg                       inc_cq;
  reg                       next_q_grp;
  reg                       start_ctr_cal_d;
  reg                       cal_rise_d;
  reg                       save_rise_edge_d;
  reg                       save_rise_edge_inv_d;
  reg                       save_fall_edge_d;
  reg                       save_current_d;
  reg                       force_clk_invert_d;
  reg                       set_clk_polarity;
  reg                       issue_load_c_d;
  reg                       issue_load_q_d;
  reg                       inc_q_d;
  reg                       inc_cq_d;
  reg                       next_q_grp_d;
  reg                       save_target_q;
  reg                       clr_q;
  reg                       load_init;
  reg                       capture_adj;
  reg                       start_adj;
  reg                       start_ctr_cal_int_r;
  reg                       start_ctr_cal_int_2r;
  reg                       start_ctr_cal;
  reg                       start_ctr_cal_hold;
  reg                       start_ctr_cal_rdy;
  reg                       re_cdt_selected;
  reg   [TAP_BITS-1:0]      re_optimal_tap;
  reg   [TAP_BITS-1:0]      re_tap_offset;
  reg                       re_true_center;
  reg                       re_captured;
  reg                       re_start_left0;
  reg   [TAP_BITS-1:0]      re_left0_tap;
  reg                       re_window_size0;
  reg   [4:0]               re_qmem0_left0_tap;
  reg   [4:0]               re_qmem0_right_tap;
  reg   [4:0]               re_qmem0_left1_tap;
  reg                       re_qmem0_found_left0;
  reg                       re_qmem0_found_right;
  reg                       re_qmem0_found_left1;
  reg                       re_qmem0_cdt_max;
  reg                       re_qmem0_qdt_max;
  reg                       re_qmem0_opp_first;
  reg                       re_qmem0_start_left0;
  reg                       rei_cdt_selected;
  reg   [TAP_BITS-1:0]      rei_optimal_tap;
  reg                       rei_true_center;
  reg                       rei_captured;
  reg                       rei_start_left0;
  reg   [TAP_BITS-1:0]      rei_left0_tap;
  reg                       rei_window_size0;
  reg   [4:0]               rei_qmem0_left0_tap;
  reg   [4:0]               rei_qmem0_right_tap;
  reg   [4:0]               rei_qmem0_left1_tap;
  reg                       rei_qmem0_found_left0;
  reg                       rei_qmem0_found_right;
  reg                       rei_qmem0_found_left1;
  reg                       rei_qmem0_cdt_max;
  reg                       rei_qmem0_qdt_max;
  reg                       rei_qmem0_opp_first;
  reg                       rei_qmem0_start_left0;
  reg                       fe_cdt_selected;
  reg   [TAP_BITS-1:0]      fe_optimal_tap;
  reg                       fe_captured;
  reg                       curr_cdt_selected;
  reg   [TAP_BITS-1:0]      curr_optimal_tap;
  reg                       curr_captured;
  
  // determine optimal q0 tap setting
  wire                      tap_offset0;
  reg                       re_tap_off0;
  reg                       rei_tap_off0;
  reg                       re_better_tap_off;
  reg                       invert_clk_d;
  reg                       rise_cdt_delayed_d;
  reg                       det_opt_done_d;
  reg   [3:0]               det_opt_setting_d;
  reg                       invert_clk;
  reg                       rise_cdt_delayed;
  reg                       det_opt_done;
  reg   [3:0]               det_opt_setting;
  
  // set overall q0 tap setting
  wire  [TAP_BITS-1:0]      rise_optimal_tap;
  reg                       cq_qdly_larger;
  reg                       fe_captured_r;
  reg   [TAP_BITS-1:0]      cq_num_load_val_d;
  reg   [TAP_BITS-1:0]      cqn_num_load_val_d;
  reg   [TAP_BITS-1:0]      q_bit_load_val_d;
  reg   [TAP_BITS-1:0]      cq_num_load_val;
  reg   [TAP_BITS-1:0]      cqn_num_load_val;
  reg   [TAP_BITS-1:0]      q_bit_load_val;
  reg                       det_ovr_done;
  reg                       set_ovr_st;
  reg                       set_ovr_done;

  // determine q_bit tap settings
  wire                      new_cdt_larger;
  wire  [TAP_BITS-1:0]      curr_minus_cq;
  wire  [TAP_BITS:0]        cqn_plus_curr_minus_cq;
  wire                      cqn_tap_overflow;
  wire                      q_tap_overflow;
  wire  [TAP_BITS:0]        cq_plus_curr;
  reg   [TAP_BITS-1:0]      prev_q_adj_d;
  reg   [TAP_BITS-1:0]      q_tap_d;
  reg   [TAP_BITS-1:0]      cq_tap_d;
  reg   [TAP_BITS-1:0]      cqn_tap_d;
  reg                       prev_adj_req_d;
  reg   [TAP_BITS-1:0]      prev_q_adj;
  reg                       cap_prev_adj_req;
  reg                       prev_adj_req;
  reg   [TAP_BITS-1:0]      cq_tap;
  reg   [TAP_BITS-1:0]      cqn_tap;
  reg   [TAP_BITS-1:0]      q_tap;
  reg                       qbit_det_done;
  
  // set q_bit tap settings
  reg                       qbit_set_st;
  reg                       qbit_set_done;
  reg   [Q_BITS-1:0]        target_q;
  reg   [TAP_BITS-1:0]      q_adj_val;
  reg                       q_bit_adj_done;
  wire                      adjust_q;
  reg                       all_q_adj;
  
  // phase alignment
  wire  [MEMORY_WIDTH-1:0]  cnum_rise_data0 [NUM_DEVICES-1:0];
  wire  [MEMORY_WIDTH-1:0]  cnum_fall_data0 [NUM_DEVICES-1:0];
  wire  [MEMORY_WIDTH-1:0]  cnum_rise_data1 [NUM_DEVICES-1:0];
  wire  [MEMORY_WIDTH-1:0]  cnum_fall_data1 [NUM_DEVICES-1:0];
  reg   [MEMORY_WIDTH-1:0]  cnum_rd0;
  reg   [MEMORY_WIDTH-1:0]  cnum_fd0;
  reg   [MEMORY_WIDTH-1:0]  cnum_rd1;
  reg   [MEMORY_WIDTH-1:0]  cnum_fd1;
  wire  [MEMORY_WIDTH-1:0]  phase0_mw_vld;
  wire  [MEMORY_WIDTH-1:0]  phase1_mw_vld;
  wire                      phase0_data_vld0;
  wire                      phase1_data_vld0;
  reg                       phase0_data_vld1;
  reg                       phase1_data_vld1;
  wire                      phase0_data_vld;
  wire                      phase1_data_vld;
  reg                       phase1_vld;
  reg                       phase0_vld;
  reg                       phase_error;

  // idelay/iserdes control
  reg   [Q_BITS-1:0]        q_mem;
  reg   [C_NUM_RDY_DLY:0]   c_num_done_tmp = 0;
  reg                       c_num_done_int;
  reg                       c_num_done;
  reg                       c_num_rdy;
  wire                      q_bit_changed;
  reg   [Q_BIT_RDY_DLY:0]   q_bit_done_tmp = 0;
  reg                       q_bit_done_int;
  reg                       q_bit_done;
  reg                       q_bit_rdy;
  reg   [TAP_DLY:0]         cq_tap_done_tmp = 0;
  reg                       cq_tap_done_int;
  reg                       cq_tap_done;
  reg   [TAP_DLY:0]         cqn_tap_done_tmp = 0;
  reg                       cqn_tap_done_int;
  reg                       cqn_tap_done;
  reg   [TAP_DLY:0]         q_tap_done_tmp = 0;
  reg                       q_tap_done_int;
  reg                       q_tap_done;
  wire                      tap_done;
  wire                      load_c_changed;
  reg   [LOAD_DLY:0]        load_c_tmp = 0;
  reg                       load_c;
  reg                       load_c_fall;
  reg                       load_c_done;
  reg                       load_q_changed;
  reg   [LOAD_DLY:0]        load_q_tmp = 0;
  reg                       load_q;
  reg                       load_q_fall;
  reg                       load_q_done;
  wire                      load_done;
  wire                      cq_rst_changed;
  reg   [RST_DLY:0]         cq_rst_done_tmp = 0;
  reg                       cq_rst_done_int;
  reg   [3:0]               outstanding_cq_rst;
  reg                       cq_rst_done;
  wire                      q_rst_changed;
  reg   [RST_DLY:0]         q_rst_done_tmp = 0;
  reg                       q_rst_done_int;
  reg   [3:0]               outstanding_q_rst;
  reg                       q_rst_done;
  wire                      rst_done;
  reg                       clear_clk_invert_r;
  reg                       clear_clk_invert_2r;
  reg                       clear_clk_invert_3r;
  wire                      polarity_changed;
  reg   [POL_DLY:0]         polarity_done_tmp = 0;
  reg                       polarity_done_int;
  reg                       polarity_done;
  reg                      min_window_chk;
  reg [4:0]                min_window_cnt; 
  
  // Chipscope debug signals  
  assign dbg_rd_stage1_cal[255:245] = 'b0;
  assign dbg_rd_stage1_cal[244]     = en_vld_check;
  assign dbg_rd_stage1_cal[243:234] = stable_cnt;
  assign dbg_rd_stage1_cal[233]     = window_vld_stable;
  assign dbg_rd_stage1_cal[232]     = fd_valid;
  assign dbg_rd_stage1_cal[231]     = rd_valid;
  assign dbg_rd_stage1_cal[230:226] = fd_window;
  assign dbg_rd_stage1_cal[225:221] = rd_window;
  assign dbg_rd_stage1_cal[220]     = fd1;
  assign dbg_rd_stage1_cal[219]     = rd1;
  assign dbg_rd_stage1_cal[218]     = fd0;
  assign dbg_rd_stage1_cal[217]     = rd0;
  assign dbg_rd_stage1_cal[216]     = rst_done;
  assign dbg_rd_stage1_cal[215]     = init_done;
  assign dbg_rd_stage1_cal[214]     = cal_sm_start;
  assign dbg_rd_stage1_cal[213:209] = curr_optimal_tap;
  assign dbg_rd_stage1_cal[208]     = new_cdt_larger;
  assign dbg_rd_stage1_cal[207]     = curr_cdt_selected;
  assign dbg_rd_stage1_cal[206:202] = rei_qmem0_left0_tap;
  assign dbg_rd_stage1_cal[201:197] = rei_qmem0_right_tap;
  assign dbg_rd_stage1_cal[196:192] = rei_qmem0_left1_tap;
  assign dbg_rd_stage1_cal[191]     = rei_qmem0_found_left0;
  assign dbg_rd_stage1_cal[190]     = rei_qmem0_found_right;
  assign dbg_rd_stage1_cal[189]     = rei_qmem0_found_left1;
  assign dbg_rd_stage1_cal[188]     = rei_qmem0_cdt_max;
  assign dbg_rd_stage1_cal[187]     = rei_qmem0_qdt_max;
  assign dbg_rd_stage1_cal[186]     = rei_qmem0_opp_first;
  assign dbg_rd_stage1_cal[185]     = rei_qmem0_start_left0;
  assign dbg_rd_stage1_cal[184:180] = re_qmem0_left0_tap;
  assign dbg_rd_stage1_cal[179:175] = re_qmem0_right_tap;
  assign dbg_rd_stage1_cal[174:170] = re_qmem0_left1_tap;
  assign dbg_rd_stage1_cal[169]     = re_qmem0_found_left0;
  assign dbg_rd_stage1_cal[168]     = re_qmem0_found_right;
  assign dbg_rd_stage1_cal[167]     = re_qmem0_found_left1;
  assign dbg_rd_stage1_cal[166]     = re_qmem0_cdt_max;
  assign dbg_rd_stage1_cal[165]     = re_qmem0_qdt_max;
  assign dbg_rd_stage1_cal[164]     = re_qmem0_opp_first;
  assign dbg_rd_stage1_cal[163]     = re_qmem0_start_left0;
  assign dbg_rd_stage1_cal[162:158] = optimal_tap;
  assign dbg_rd_stage1_cal[157:154] = det_opt_setting;
  assign dbg_rd_stage1_cal[153:148] = window_size;
  assign dbg_rd_stage1_cal[147]     = q_bit_rst;
  assign dbg_rd_stage1_cal[146:142] = q_bit_load;
  assign dbg_rd_stage1_cal[141]     = cqn_num_rst;
  assign dbg_rd_stage1_cal[140:136] = cqn_num_load;
  assign dbg_rd_stage1_cal[135]     = cq_num_rst;
  assign dbg_rd_stage1_cal[134:130] = cq_num_load;
  assign dbg_rd_stage1_cal[129]     = load_done;
  assign dbg_rd_stage1_cal[128]     = tap_done;
  assign dbg_rd_stage1_cal[127]     = q_bit_ce;
  assign dbg_rd_stage1_cal[126]     = cqn_num_ce;
  assign dbg_rd_stage1_cal[125]     = cq_num_ce;
  assign dbg_rd_stage1_cal[124]     = q_bit_rdy;
  assign dbg_rd_stage1_cal[123]     = c_num_rdy;
  assign dbg_rd_stage1_cal[122]     = phase_error;
  assign dbg_rd_stage1_cal[121]     = phase1_data_vld;
  assign dbg_rd_stage1_cal[120]     = phase0_data_vld;
  assign dbg_rd_stage1_cal[119]     = q_bit_adj_done;
  assign dbg_rd_stage1_cal[118:114] = q_adj_val;
  assign dbg_rd_stage1_cal[113:109] = prev_q_adj;
  assign dbg_rd_stage1_cal[108]     = prev_adj_req;
  assign dbg_rd_stage1_cal[107]     = load_init;
  assign dbg_rd_stage1_cal[106]     = capture_adj;
  assign dbg_rd_stage1_cal[105:101] = q_tap;
  assign dbg_rd_stage1_cal[100:96]  = cqn_tap;
  assign dbg_rd_stage1_cal[95:91]   = cq_tap;
  assign dbg_rd_stage1_cal[90]      = rise_cdt_delayed;
  assign dbg_rd_stage1_cal[89]      = invert_clk;
  assign dbg_rd_stage1_cal[88]      = re_cdt_selected;
  assign dbg_rd_stage1_cal[87:83]   = re_optimal_tap;
  assign dbg_rd_stage1_cal[82:78]   = right_tap; 
  assign dbg_rd_stage1_cal[77:73]   = left1_tap; 
  assign dbg_rd_stage1_cal[72:68]   = left0_tap; 
  assign dbg_rd_stage1_cal[67]      = cal_rise; 
  assign dbg_rd_stage1_cal[66]      = polarity_done;
  assign dbg_rd_stage1_cal[65]      = q_bit_clkinv;
  assign dbg_rd_stage1_cal[64]      = fe_cdt_selected; 
  assign dbg_rd_stage1_cal[63]      = rei_cdt_selected;
  assign dbg_rd_stage1_cal[62:58]   = fe_optimal_tap;  
  assign dbg_rd_stage1_cal[57:53]   = rei_optimal_tap; 
  assign dbg_rd_stage1_cal[52]      = qbit_set_done;
  assign dbg_rd_stage1_cal[51]      = qbit_det_done;  
  assign dbg_rd_stage1_cal[50]      = det_ovr_done;                 
  assign dbg_rd_stage1_cal[49]      = det_opt_done;
  assign dbg_rd_stage1_cal[48]      = fe_captured;
  assign dbg_rd_stage1_cal[47]      = re_captured;
  assign dbg_rd_stage1_cal[46]      = q_mem_0;
  assign dbg_rd_stage1_cal[45]      = ctr_done;       
  assign dbg_rd_stage1_cal[44]      = cdt_selected;   
  assign dbg_rd_stage1_cal[43]      = rei_captured;    
  assign dbg_rd_stage1_cal[42]      = tap_offset;     
  assign dbg_rd_stage1_cal[41]      = try_clk_inv;    
  assign dbg_rd_stage1_cal[40]      = found_right;
  assign dbg_rd_stage1_cal[39]      = found_left1;
  assign dbg_rd_stage1_cal[38]      = found_left0;
  assign dbg_rd_stage1_cal[37]      = en_tap_adj;
  assign dbg_rd_stage1_cal[36]      = data_rdy;
  assign dbg_rd_stage1_cal[35]      = opp_window_vld;
  assign dbg_rd_stage1_cal[34]      = window_vld;
  assign dbg_rd_stage1_cal[33:29]   = q_dly_tap;
  assign dbg_rd_stage1_cal[28:24]   = cqn_dly_tap;
  assign dbg_rd_stage1_cal[23:19]   = cq_dly_tap;
  assign dbg_rd_stage1_cal[18:5]    = cal_cs;
  assign dbg_rd_stage1_cal[4:0]     = tap_ctr_cs;
  

  // {{{ Capture Calibration Data ---------------
  
  // Infer a mux that such that the calibration logic only operates on the data
  // from one bit at a time. Register the inputs since timing will be tight for
  // wider interfaces.
  always @(posedge clk) begin
    if (rst_clk) begin
      rise_data0_r <= #TCQ 0;
      fall_data0_r <= #TCQ 0;
      rise_data1_r <= #TCQ 0;
      fall_data1_r <= #TCQ 0;
    end else begin
      rise_data0_r <= #TCQ rise_data0;
      fall_data0_r <= #TCQ fall_data0;
      rise_data1_r <= #TCQ rise_data1;
      fall_data1_r <= #TCQ fall_data1;
    end
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      rd0 <= #TCQ 0;
      fd0 <= #TCQ 0;
      rd1 <= #TCQ 0;
      fd1 <= #TCQ 0;
    end else begin
      rd0 <= #TCQ rise_data0_r[q_bit];
      fd0 <= #TCQ fall_data0_r[q_bit];
      rd1 <= #TCQ rise_data1_r[q_bit];
      fd1 <= #TCQ fall_data1_r[q_bit];
    end
  end

  // Register data again to allow data to be looked at across two cycles which
  // is necessary since the training sequence is 8 words (4 rising and 4
  // falling).
  always @(posedge clk) begin
    if (rst_clk) begin
      rd0_r <= #TCQ 0;
      fd0_r <= #TCQ 0;
      rd1_r <= #TCQ 0;
      fd1_r <= #TCQ 0;
    end else begin
      rd0_r <= #TCQ rd0;
      fd0_r <= #TCQ fd0;
      rd1_r <= #TCQ rd1;
      fd1_r <= #TCQ fd1;
    end
  end

  // Create a signal that toggles which will be used as an indicator to sample
  // the data on every other cycle. This is necessary since the training
  // sequence must be evaluated over two cycles.
  always @(posedge clk) begin
    if (rst_clk)
      sample <= #TCQ 0;
    else
      sample <= #TCQ !sample;
  end

  // Rising edge valid data will ideally be 0100 over two cycles. However, 
  // depending on how the sample signal aligns with the incoming data in
  // addition to the phase alignment in the ISERDES, it coult be 1000, 0100,
  // 0010, or 0001.
  assign rd_window  = {rd0, rd1, rd0_r, rd1_r};
  
  assign d_window = {rd_window, fd_window};

  // Note this was done in an always to avoid X propagation from the IDELAY
  // data that occurs when the clock is moved outside of the data window.
  // For RLDRAM, the entire data window is looked at since there are no separate rise and fall clocks
  always @* begin
    if ( (MEMORY_TYPE == "RLD2" ) && ((d_window == 8'b10000111) || (d_window == 8'b01001011) ||
           (d_window == 8'b00101101) || (d_window == 8'b00011110)))
        rd_valid_d = 1;
    else if ((MEMORY_TYPE == "QDR" ) &&  ((rd_window == 4'b1000) || (rd_window == 4'b0100) ||
        (rd_window == 4'b0010) || (rd_window == 4'b0001)))
        rd_valid_d = 1;
    else
        rd_valid_d = 0;
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      rd_valid <= #TCQ 0;
    end else if (sample) begin
      rd_valid <= #TCQ rd_valid_d;
    end
  end

  // Falling edge valid data will ideally be 1011 over two cycles. However, 
  // depending on how the sample signal aligns with the incoming data in
  // addition to the phase alignment in the ISERDES, it coult be 0111, 1011,
  // 1101, or 1110.
  assign fd_window  = {fd0, fd1, fd0_r, fd1_r};

  // Note this was done in an always to avoid X propagation from the IDELAY
  // data that occurs when the clock is moved outside of the data window.
  // For RLDRAM, the entire data window is looked at since there are no separate rise and fall clocks
  always @* begin
    if ( (MEMORY_TYPE == "RLD2" ) && ((d_window == 8'b01111000) || (d_window == 8'b10110100) ||
           (d_window == 8'b11010010) || (d_window == 8'b11100001)))
        fd_valid_d = 1;
    else if ((MEMORY_TYPE == "QDR" ) && ((fd_window == 4'b0111) || (fd_window == 4'b1011) ||
        (fd_window == 4'b1101) || (fd_window == 4'b1110)))
      fd_valid_d = 1;
    else
      fd_valid_d = 0;
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      fd_valid <= #TCQ 0;
    end else if (sample) begin
      fd_valid <= #TCQ fd_valid_d;
    end
  end

  // Indicate if data being capture is valid for the target window and/or for
  // the other window. Note that when the ISERDES clock inversion is used, 
  // calibrating CQ actually causes it to clock the falling edge data and
  // CQ# to clock the rising edge data.
  always @(posedge clk) begin
    if (rst_clk) begin
      window_vld      <= #TCQ 0;
      opp_window_vld  <= #TCQ 0;
    end else if (MEMORY_TYPE == "RLD2") begin
      window_vld      <= #TCQ (cal_rise ? rd_valid : fd_valid);
      opp_window_vld  <= #TCQ (cal_rise ? fd_valid : rd_valid);
    end else if (cal_rise) begin
      window_vld      <= #TCQ (q_bit_clkinv ? fd_valid : rd_valid);
      opp_window_vld  <= #TCQ (q_bit_clkinv ? rd_valid : fd_valid);
    end else begin
      window_vld      <= #TCQ (q_bit_clkinv ? rd_valid : fd_valid);
      opp_window_vld  <= #TCQ (q_bit_clkinv ? fd_valid : rd_valid);
    end
  end

  // }}} end Capture Calibration Data -----------
  

  // {{{ Tap Centering --------------------------

  // Indicate when the tap center should begin.
  always @(posedge clk) begin
    if (rst_clk) begin
      ctr_idle_rdy <= #TCQ 0;
    end else if ((tap_ctr_cs == CTR_IDLE) && (start_ctr_cal_rdy)) begin
      ctr_idle_rdy <= #TCQ 1;
    end else if (tap_ctr_cs == CTR_DONE) begin
      ctr_idle_rdy <= #TCQ 0;
    end
  end

  // Data is captured following a tap adjustment, a reset, or a change in
  // iserdes clk polarity. It is enabled once all have been adjusted (i.e.
  // looks for rising edge). The rising edge is necessary since the done
  // signals will not immediately deassert following an adjustment at this
  // stage.
  assign data_rdy = cq_tap_done && cqn_tap_done && q_tap_done &&
                    rst_done && polarity_done && ctr_idle_rdy &&
                    !issue_cdt_rst_d && !issue_cdt_rst &&
                    !issue_dly_rst_d && !issue_dly_rst && data_stable;

  always @(posedge clk) begin
    if (rst_clk)
      data_rdy_r <= #TCQ 0;
    else
      data_rdy_r <= #TCQ data_rdy;
  end

  // Indicate that the window can begin being checked after changes have
  // stabilized.
  assign start_stable_cnt = data_rdy && !data_rdy_r;

  always @(posedge clk) begin
    if (rst_clk)
      en_vld_check <= #TCQ 0;  
    else if (start_stable_cnt)
      en_vld_check <= #TCQ 1;
    else if (stable_cnt == 1)
      en_vld_check <= #TCQ 0;
    else if  (data_stable == 0)
      en_vld_check <= #TCQ 0;
  end

  // To avoid regions of instability around window edges, look at window_vld
  // over multiple cycles. Only consider the window valid if it is stable
  // and valid over WINDOW_VLD_STABLE_CNT number of cycles.
  always @(posedge clk) begin
    if (rst_clk) begin
      stable_cnt        <= #TCQ WINDOW_VLD_STABLE_CNT;
      window_vld_stable <= #TCQ 0;
    end else if (start_stable_cnt) begin
      stable_cnt        <= #TCQ WINDOW_VLD_STABLE_CNT;
      window_vld_stable <= #TCQ window_vld;
    end else if (stable_cnt == 0) begin
      stable_cnt        <= #TCQ 0;
      window_vld_stable <= #TCQ window_vld_stable;
    end else if (!window_vld && en_vld_check) begin
      stable_cnt        <= #TCQ 0;
      window_vld_stable <= #TCQ 0;
    end else if (en_vld_check) begin
      stable_cnt        <= #TCQ stable_cnt - 1'b1;
      window_vld_stable <= #TCQ window_vld;
    end
  end

  // Enable data capture after a stable window has been found or determined
  // that the window is not valid.
  always @(posedge clk) begin
    if (rst_clk) begin
      stable_cnt_0   <= #TCQ 0;
      stable_cnt_0_r <= #TCQ 0;
    end else begin
      stable_cnt_0   <= #TCQ (stable_cnt == 0);
      stable_cnt_0_r <= #TCQ stable_cnt_0;
    end
  end

  always @(posedge clk) begin
    if (rst_clk)
      en_data_cap <= #TCQ 0;
    else
      en_data_cap <= #TCQ stable_cnt_0 && ! stable_cnt_0_r;
  end
  
  // Initialization state machine drops the init_done signal when a refresh
  // is going to occur. This assumes the init state machine keeps the init_done
  // low until read data is valid
  // Only used for RLDRAM II, for QDR2+ init_done should stay active high
  always @(posedge clk) begin
    if (rst_clk) begin
      init_done_r1 <= #TCQ 0;
      init_done_r2 <= #TCQ 0;
      data_stable  <= #TCQ 0;
      data_stable_r<= #TCQ 0;
    end else begin
      init_done_r1 <= #TCQ init_done;
      init_done_r2 <= #TCQ init_done_r1;
      data_stable  <= #TCQ init_done & init_done_r2;
      data_stable_r<= #TCQ data_stable;
    end
  end
  
  // CQ inc and ce generation for rising edge data. CQ taps are incremented
  // when looking for the right edge from within the rising edge window or when
  // looking for the left edge of the rising edge window from within the
  // falling edge data.
  // CQ# inc and ce generation for falling edge data. CQ# taps are incremented
  // when looking for the right edge from within the falling edge window or
  // when looking for the left edge of the falling edge window from within the
  // rising edge data.
  // Tap adjustments are made following TAP_ADJ_DLY cycles after the data has
  // been captured.
  always @(posedge clk) begin
    en_tap_adj_tmp <= #TCQ {en_tap_adj_tmp[TAP_ADJ_DLY-1:0], en_data_cap};
  end

  // Tap adjustments are only allowed if there are no updates to the IDELAY
  // or ISERDES in progress.
  always @(posedge clk) begin
    if (rst_clk)
      en_tap_adj <= #TCQ 0;
    else
      en_tap_adj <= #TCQ en_tap_adj_tmp[TAP_ADJ_DLY] && data_rdy;
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      en_rise_tap <= #TCQ 0;
      en_fall_tap <= #TCQ 0;
    end else begin
      en_rise_tap <= #TCQ cal_rise && en_tap_adj  ;
      en_fall_tap <= #TCQ !cal_rise && en_tap_adj;
    end
  end

  always @(posedge clk) begin
    if (rst_clk)
      cq_dly_tap  <= #TCQ MIN_TAPS;
    else if (ctr_c_dly_st)
      cq_dly_tap  <= #TCQ en_rise_tap ? cq_dly_tap + 1'b1 : cq_dly_tap;
    else
      cq_dly_tap  <= #TCQ MIN_TAPS;
  end
  
  always @(posedge clk) begin
    if (rst_clk)
      cqn_dly_tap  <= #TCQ MIN_TAPS;
    else if (ctr_c_dly_st && !issue_cdt_rst && !issue_dly_rst)
      cqn_dly_tap  <= #TCQ en_fall_tap ? cqn_dly_tap + 1'b1 : cqn_dly_tap;
    else
      cqn_dly_tap  <= #TCQ MIN_TAPS;
  end
  
  always @(posedge clk) begin
    if (rst_clk)
      q_dly_tap <= #TCQ 0;
    else if (ctr_q_dly_st && !issue_dly_rst)
      q_dly_tap <= #TCQ en_tap_adj ? q_dly_tap + 1'b1 : q_dly_tap;
    else
      q_dly_tap <= #TCQ 0;
  end
  
  // Monitor logic for tap settings that check if enough taps are reserved for
  // the phase detector. Clock must factor in the taps reserved for the phase
  // detector logic where as the data taps use the entire range.
  always @(posedge clk) begin
    if (rst_clk) begin
      c_tap_max <= #TCQ 0;
    end else begin
      c_tap_max <= #TCQ cal_rise ? (cq_dly_tap == DEVICE_TAPS - 1)
                                 : (cqn_dly_tap == DEVICE_TAPS - 1);
    end
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      q_tap_max <= #TCQ 0;
    end else begin
      q_tap_max  <= #TCQ q_dly_tap == DEVICE_TAPS - 1;
    end
  end

  //Tap Centering State Machine

  
  // Register Tap Centering state maching outputs
  always @(posedge clk) begin
    if (rst_clk) begin
      tap_ctr_cs    <= #TCQ CTR_IDLE;
      issue_cdt_rst <= #TCQ 0;
    end else begin
      tap_ctr_cs    <= #TCQ tap_ctr_ns;
      issue_cdt_rst <= #TCQ issue_cdt_rst_d || issue_dly_rst_d;
    end
  end

  always @* begin
    save_left0_tap      = 0;      
    save_right_tap      = 0;
    save_left1_tap      = 0;
    save_found_left0    = 0;
    save_found_right    = 0;
    save_found_left1    = 0;
    save_cdt_max        = 0;
    save_qdt_max        = 0;
    save_opp_first      = 0;
    save_done           = 0;
    issue_cdt_rst_d     = 0;
    save_start_left0_d  = 0;
    
    case (tap_ctr_cs)

      // When ready to sample the data, determine if valid data was captured
      // from the target window (rising edge data if calibrating against CQ or
      // falling edge data if calibrating against CQ#).
      CTR_IDLE : begin
        casex ({en_data_cap, window_vld_stable})
          // Initial data captured was target data so look for right edge by
          // delaying the clock from within target edge data.
          2'b11 : begin
            save_start_left0_d  = 0;
            tap_ctr_ns          = CTR_SEEK_RIGHT;
          end
          // Initial data captured was not target data so look for left edge
          // by shifting delaying the clock starting from the opp edge data.
          2'b10 : begin
            save_start_left0_d  = 1;
            tap_ctr_ns          = CTR_SEEK_LEFT0;
          end
          // Wait until data is to be captured
          default : begin
            save_start_left0_d  = 0;
            tap_ctr_ns          = CTR_IDLE;
          end
        endcase
      end

      // Initial window was not the target window. Search for the left edge of
      // the target window by delaying the clock.
      CTR_SEEK_LEFT0 : begin
        casex ({en_data_cap, window_vld_stable, c_tap_max})
          // Data transitioned to valid data indicating the left edge of
          // the target data was found within a valid tap range. Look for
          // right edge next, once data is valid after the min_window_chk is done
          3'b110 : begin
            save_left0_tap    = 1;
            save_found_left0  = 1;
            save_opp_first    = 1;
            tap_ctr_ns        = CTR_SEEK_LEFT0_CHK;
          end
          // Tap setting maxed out before the edge could be found. Since
          // there is no valid clock shift setting that would put it in the
          // target window, clock inversion is required.
          3'b1?1 : begin
            save_left0_tap  = 1;
            save_cdt_max    = 1;
            save_opp_first  = 1;
            tap_ctr_ns      = CTR_DONE;
          end
          default : begin
            tap_ctr_ns  = CTR_SEEK_LEFT0;
          end
        endcase
      end
      
      
      // Check to ensure stable transition to valid window
      CTR_SEEK_LEFT0_CHK : begin
           if (c_tap_max) begin
             
             save_cdt_max    = 1;
             save_opp_first  = 1;
             tap_ctr_ns      = CTR_DONE;
              
           // if start of window detection is right, data has to be stable for the minimum window size.
           // Then proceed to CTR_SEEK_RIGHT state.
           end else if (en_data_cap && window_vld_stable) begin
              if (min_window_cnt == MIN_WINDOW_SIZE) begin
                tap_ctr_ns = CTR_SEEK_RIGHT;
              end else begin
                tap_ctr_ns = CTR_SEEK_LEFT0_CHK;
              end   
           // if data is not stable, then the start of window detection happened at the edge of the window.
           // Move to CTR_SEEK_LEFT0 until data is stable to proceed further.
           // left0_tap needs to be modified.
           end else if (en_data_cap && ~window_vld_stable) begin
               save_left0_tap    = 0;
               save_found_left0  = 0;
               save_opp_first    = 0;
               tap_ctr_ns        = CTR_SEEK_LEFT0; 
           end else begin
              tap_ctr_ns = CTR_SEEK_LEFT0_CHK;
           end              
       end      
       
       
       // Search for the right edge of the target window by delaying the clock.
      CTR_SEEK_RIGHT : begin
        casex ({en_data_cap, found_left0, window_vld_stable, c_tap_max, ignore_first_right})
          // Data changed from valid to invalid indicating the right edge of
          // the target data was found within valid tap range. Left edge was
          // also found previously.
          //5'b110?? : begin
          //  save_right_tap    = 1;
          //  save_found_right  = 1;
          //  tap_ctr_ns        = CTR_DONE;
          //end
          //  // Found the right edge within valid tap range but left edge was
         //  // not previously found. Look for left edge next by shifting data.
         //  5'b100?0 : begin
         //    save_right_tap    = 1;
         //    save_found_right  = 1;
         //    //issue_cdt_rst_d   = 1;
         //    tap_ctr_ns        = CTR_SEEK_LEFT1;
         //  end
         
         // the above two conditions have been consolidated to check for only
         // window_vld_stable going low in the state machine here.
         // the check to see if the calibration is done or needs to increment data
         // delay is done in the CTR_SEEK_RIGHT_CHK state.
          
           5'b1?0?? : begin
            save_right_tap    = 1;
            save_found_right  = 1;
            tap_ctr_ns        = CTR_SEEK_RIGHT_CHK;
          end
          
          // This is a special case that forces later bits to follow the same
          // calibration scheme used for the first bit in the memory.
          // Specifically, if a large amount of clock delay was required before
          // the left0 edge was found, then the same scheme is forced to later
          // bits by ignoring any initial valid windows and looking for the
          // same first edge found by bit 0.
          5'b100?1 : begin
            save_right_tap    = 0;
            save_found_right  = 0;
            issue_cdt_rst_d   = 0;
            tap_ctr_ns        = CTR_SEEK_LEFT0;
          end
        
          // Tap setting maxed out before the edge could be found.
          5'b1111? : begin
            save_right_tap    = 1;
            save_cdt_max      = 1;
            tap_ctr_ns        = CTR_DONE;
          end
          // Right edge could not be found before clock taps ran out. Try delaying
          // data next to see if the left1 edge can be found.
          5'b1011? : begin
            save_right_tap    = 1;
            save_cdt_max      = 1;
            issue_cdt_rst_d   = 1;
            tap_ctr_ns        = CTR_SEEK_LEFT1_CHK_WT;
          end
          default: begin
            tap_ctr_ns        = CTR_SEEK_RIGHT;
          end
        endcase
      end
      
      // check to ensure end of valid window has reached.
       CTR_SEEK_RIGHT_CHK : begin
            // if end of taps condition is reached
            if (c_tap_max) begin
              // Tap setting maxed out before the edge could be found.
              if (found_left0) begin
                 save_cdt_max      = 1;
                 tap_ctr_ns        = CTR_DONE;              
              end else begin
              // Right edge could not be found before clock taps ran out. Try delaying
              // data next to see if the left1 edge can be found.
                 save_cdt_max      = 1;
                 issue_cdt_rst_d   = 1;
                 tap_ctr_ns        = CTR_SEEK_LEFT1_CHK_WT;
              end
              
           end else if (~window_vld_stable) begin
               // if window is not stable after checking for MIN_WINDOW_SIZE number of taps
               if (min_window_cnt == MIN_WINDOW_SIZE) begin
                  // if left0 edge was previously detected and now the right edge has been detected
                  // the calibration for the current clock is done.
                  if (found_left0) begin
                     tap_ctr_ns = CTR_DONE;
                  // if left0_edge was not previously detected, issue clock delay reset and 
                  // look for the left edge by shifting data.
                  end else begin
                     issue_cdt_rst_d   = 1; 
                     tap_ctr_ns = CTR_SEEK_LEFT1_CHK_WT;
                  end
               end else begin
                     tap_ctr_ns = CTR_SEEK_RIGHT_CHK;
               end  
          // if valid data becomes available which is possible when the original alignment
          // put the clock at the end of valid window, in which case the clock is actually
          // at the beginning and not the end of the window.
          end else if (window_vld_stable ) begin
             if (min_window_cnt == MIN_WINDOW_SIZE) begin 
                 if (~found_left0) begin
                    // if left edge was not previously detected and this instability                       
                    // happened during the initial CQ/CQ# and Q alignment, treat this as the left0 edge.  
                    if (right_tap <= MIN_WINDOW_SIZE + 2 + MIN_TAPS) begin
                      save_right_tap    = 0;
                      save_found_right  = 0;
                      save_left0_tap    = 1;
                      save_found_left0  = 1;
                      save_opp_first    = 1;
                      tap_ctr_ns        = CTR_SEEK_LEFT0_CHK; 
                    // if the right edge detected is indeed valid and the window_vld_stable is due
                    // to high jitter still persisting, proceed to look for left edge by
                    // shifting data.
                    end else begin
                      issue_cdt_rst_d   = 1;      
                      tap_ctr_ns        = CTR_SEEK_LEFT1_CHK_WT; 
                    end
                 // if valid left0 and right edges have been detected and yet window_vld_stable is high
                 //   MIN_WINDOW_SIZE taps after the first right edge was seen..   
                 end else begin
                     tap_ctr_ns = CTR_DONE; // possibly an invalid case..
                 end   
              end else begin
                 tap_ctr_ns = CTR_SEEK_RIGHT_CHK;
              end   
                
          end else begin
              tap_ctr_ns = CTR_SEEK_RIGHT_CHK;
          end          
       end
       
        // wait state to reset the min window counter.              
      CTR_SEEK_LEFT1_CHK_WT : begin        
                    tap_ctr_ns        = CTR_SEEK_LEFT1_CHK;
      end
                     
      
      // Search for the left edge of the target window by delaying the data.  
      // ensure data is stable for atleast MIN_WINDOW_SIZE of taps before proceeding to 
      // finding the left1 edge.
                                                                
      CTR_SEEK_LEFT1_CHK : begin     
      
         if (en_data_cap && ~window_vld_stable) begin
               if (~found_left1) begin
               save_left1_tap    = 1;  
               save_found_left1  = 1;
               end
               if (min_window_cnt == MIN_WINDOW_SIZE) begin
                    tap_ctr_ns = CTR_DONE;
               end else begin
                   tap_ctr_ns = CTR_SEEK_LEFT1_CHK;
               end
               
          end else if (en_data_cap && window_vld_stable) begin
               if (min_window_cnt == MIN_WINDOW_SIZE) begin
                    tap_ctr_ns = CTR_SEEK_LEFT1;
               end else begin
                   tap_ctr_ns = CTR_SEEK_LEFT1_CHK;
               end
          end else begin
                   tap_ctr_ns = CTR_SEEK_LEFT1_CHK;
          end
          
      end
                                                                                                                               
                                                                                                                                        
      // Search for the left edge of the target window by delaying the data.                                                            
      CTR_SEEK_LEFT1 : begin
        casex ({en_data_cap, window_vld_stable, q_tap_max})
          // Data changed from valid to invalid indicating the left edge of
          // the target data was found with a valid range by delaying the
          // the data.
          3'b10? : begin
            save_left1_tap    = 1;
            save_found_left1  = 1;
            tap_ctr_ns        = CTR_DONE;
          end
          // Tap setting maxed out before edge could be found.
          3'b111 : begin
            save_left1_tap  = 1;
            save_qdt_max    = 1;
            tap_ctr_ns      = CTR_DONE;
          end
          default : begin
            tap_ctr_ns      = CTR_SEEK_LEFT1;
          end
        endcase
      end

      // Edges have been found or taps have maxed out. Save the results and
      // for the tap centering to start again if necessary.
      CTR_DONE : begin
        save_done  = 1;
        tap_ctr_ns = start_ctr_cal ? CTR_IDLE : CTR_DONE;
      end

      default : begin
        save_left0_tap      = 1'hX;      
        save_right_tap      = 1'hX;
        save_left1_tap      = 1'hX;
        save_found_left0    = 1'hX;
        save_found_right    = 1'hX;
        save_found_left1    = 1'hX;
        save_cdt_max        = 1'hX;
        save_qdt_max        = 1'hX;
        save_opp_first      = 1'hX;
        save_done           = 1'hX;
        issue_cdt_rst_d     = 1'hX;
        save_start_left0_d  = 1'hX;
        tap_ctr_ns          = CTR_IDLE;
      end

    endcase
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      save_start_left0 <= #TCQ 0;
    end else begin
      save_start_left0 <= #TCQ save_start_left0_d;
    end
  end
  
  // Indicate to ignore the first right edge of a data valid window if the
  // first bit in the memory initially found the left0 edge and if the tap
  // setting of that edge was greater than LEFT0_SAME_WINDOW number of taps.
  always @(posedge clk) begin
    if (rst_clk) begin
      ignore_first_right <= #TCQ 0;
    end else if (q_mem_0) begin
      ignore_first_right <= #TCQ 0;
    end else if (qmem0_start_left0) begin
      ignore_first_right <= #TCQ (qmem0_left0_tap >= LEFT0_SAME_WINDOW);
    end
  end
  
  always @ (posedge clk) begin
    if (rst_clk) begin
       min_window_cnt <= #TCQ 0;
    end else if ((tap_ctr_cs == CTR_SEEK_LEFT0_CHK) || (tap_ctr_cs == CTR_SEEK_RIGHT_CHK) || (tap_ctr_cs == CTR_SEEK_LEFT1_CHK)) begin
        if ((ctr_c_dly_st && (en_rise_tap || en_fall_tap)) || (ctr_q_dly_st && en_tap_adj)) begin 
        //if (en_rise_tap || en_fall_tap) begin
             min_window_cnt <= #TCQ min_window_cnt + 1;
        end else begin
             min_window_cnt <= #TCQ min_window_cnt;
        end
    end else begin
       min_window_cnt <= #TCQ 0;
    end 
  end
  
  // States in which CQ, CQ#, or Q taps are moved
  assign ctr_seek_st  = ((tap_ctr_cs == CTR_SEEK_LEFT0) || 
                         (tap_ctr_cs == CTR_SEEK_RIGHT) || 
                        (tap_ctr_cs == CTR_SEEK_LEFT1));

  // States in which CQ or CQ# taps are moved
  assign ctr_c_dly_st = ((tap_ctr_cs == CTR_SEEK_LEFT0) || (tap_ctr_cs == CTR_SEEK_LEFT0_CHK) || (tap_ctr_cs == CTR_SEEK_RIGHT) ||(tap_ctr_cs == CTR_SEEK_RIGHT_CHK));
  
  // State in which Q taps are moved
  assign ctr_q_dly_st = (tap_ctr_cs == CTR_SEEK_LEFT1) || (tap_ctr_cs == CTR_SEEK_LEFT1_CHK);
  
  // Save status of SM including information on current tap values and whether
  // clock inversion is required. These are all cleared upon entering idle. The
  // right_tap is set to the current cq*_dly_tap - 1 since that was the last
  // valid tap setting. Likewise for left1_tap, it is set to cq_dly_tap + 1.
  always @(posedge clk) begin
    if (rst_clk) begin
      left0_tap     <= #TCQ 0;
      right_tap     <= #TCQ 0;
      left1_tap     <= #TCQ 0;
      found_left0   <= #TCQ 0;
      found_right   <= #TCQ 0;
      found_left1   <= #TCQ 0;
      cdt_max       <= #TCQ 0;
      qdt_max       <= #TCQ 0;
      opp_first     <= #TCQ 0;
      ctr_done_pre  <= #TCQ 0;
      start_left0   <= #TCQ 0;
    end else if (tap_ctr_cs == CTR_IDLE) begin
      left0_tap     <= #TCQ 0;
      right_tap     <= #TCQ 0;
      left1_tap     <= #TCQ 0;
      found_left0   <= #TCQ 0;
      found_right   <= #TCQ 0;
      found_left1   <= #TCQ 0;
      cdt_max       <= #TCQ 0;
      qdt_max       <= #TCQ 0;
      opp_first     <= #TCQ 0;
      ctr_done_pre  <= #TCQ 0;
      start_left0   <= #TCQ 0;
    end else begin
      if (save_left0_tap)
        left0_tap <= #TCQ cal_rise ? cq_dly_tap : cqn_dly_tap;
      if (save_right_tap)
        right_tap <= #TCQ cal_rise ? cq_dly_tap - 1'b1: cqn_dly_tap - 1'b1;
      if (save_left1_tap)
        left1_tap <= #TCQ (q_dly_tap == 0) ? 0 : q_dly_tap - 1'b1;
      if (save_found_left0)
        found_left0 <= #TCQ 1;
      if (save_found_right)
        found_right <= #TCQ 1;
      if (save_found_left1)
        found_left1 <= #TCQ 1;
      if (save_cdt_max)
        cdt_max <= #TCQ 1;
      if (save_qdt_max)
        qdt_max <= #TCQ 1;
      if (save_opp_first)
        opp_first <= #TCQ 1;
      if (save_done)
        ctr_done_pre <= #TCQ 1;
      if (save_start_left0)
        start_left0 <= #TCQ 1;
    end
  end

  // Delay tap centering done indication by a cycle to allow time for all
  // logic to complete updating
  always @(posedge clk) begin
    if (rst_clk)
      ctr_done <= #TCQ 0;
    else
      ctr_done <= #TCQ ctr_done_pre;
  end

  // Save information for the first bit in each device
  always @(posedge clk) begin
    if (rst_clk) begin
      q0mem_left0_tap   <= #TCQ 0;
      q0mem_right_tap   <= #TCQ 0;
      q0mem_left1_tap   <= #TCQ 0;
      q0mem_found_left0 <= #TCQ 0;
      q0mem_found_right <= #TCQ 0;
      q0mem_found_left1 <= #TCQ 0;
      q0mem_cdt_max     <= #TCQ 0;
      q0mem_qdt_max     <= #TCQ 0;
      q0mem_opp_first   <= #TCQ 0;
      q0mem_start_left0 <= #TCQ 0;
    end else if (q_mem_0) begin
      if (save_left0_tap)
        q0mem_left0_tap   <= #TCQ cal_rise ? cq_dly_tap : cqn_dly_tap;
      if (save_right_tap)
        q0mem_right_tap   <= #TCQ cal_rise ? cq_dly_tap - 1'b1: cqn_dly_tap - 1'b1;
      if (save_left1_tap)
        q0mem_left1_tap   <= #TCQ (q_dly_tap == 0) ? 0 : q_dly_tap - 1'b1;
      if (save_found_left0)
        q0mem_found_left0 <= #TCQ 1;
      if (save_found_right)
        q0mem_found_right <= #TCQ 1;
      if (save_found_left1)
        q0mem_found_left1 <= #TCQ 1;
      if (save_cdt_max)
        q0mem_cdt_max     <= #TCQ 1;
      if (save_qdt_max)
        q0mem_qdt_max     <= #TCQ 1;
      if (save_opp_first)
        q0mem_opp_first   <= #TCQ 1;
      if (save_start_left0)
        q0mem_start_left0 <= #TCQ 1;
    end
  end

  // CDT left0 edge setting + taps to center <= maximum usable clock taps
  always @(posedge clk) begin
    if (rst_clk)
      clpct_lte_dt <= #TCQ 0;
    else
      clpct_lte_dt <= #TCQ (left0_plus_center <= MAX_TAPS);
  end
  
  
  
  // CDT left0 edge setting >= center taps
  always @(posedge clk) begin
    if (rst_clk)
      left0_gr_ctr <= #TCQ 0;
    else
      left0_gr_ctr <= #TCQ (left0_tap >= CENTER_TAP);
  end
  
  // CDT right edge setting > QDT left1 edge setting
  always @(posedge clk) begin
    if (rst_clk)
      cr_gt_ql <= #TCQ 0;
    else
      cr_gt_ql <= #TCQ (right_tap - MIN_TAPS > left1_tap);
  end
  
   // taps to center <= maximum data taps + CDT right edge setting
  always @(posedge clk) begin
    if (rst_clk)
      ct_lte_dtpcr <= #TCQ 0;
    else
      ct_lte_dtpcr <= #TCQ CENTER_TAP <= right_plus_maxt;
  end
  
  // left0_tap + center_tap
  always @(posedge clk) begin
    if (rst_clk)
      left0_plus_center <= #TCQ 0;
    else
      left0_plus_center <= #TCQ left0_tap + CENTER_TAP;
  end
  
  // right tap + max-tap
  always @(posedge clk) begin
    if (rst_clk)
      right_plus_maxt <= #TCQ 0;
    else
      right_plus_maxt <= #TCQ right_tap + MAX_TAPS;
  end
  
  // left0_tap + right_tap
  always @(posedge clk) begin
    if (rst_clk)
      left0_plus_right <= #TCQ 0;
    else
      left0_plus_right <= #TCQ left0_tap + right_tap;
  end
  
  // right_tap - left1_tap
  always @(posedge clk) begin
    if (rst_clk)
      right_minus_left1 <= #TCQ 0;
    else
      right_minus_left1 <= #TCQ (right_tap - MIN_TAPS) - left1_tap;
  end
  
  // left1_tap - right_tap
  always @(posedge clk) begin
    if (rst_clk)
      left1_minus_right <= #TCQ 0;
    else
      left1_minus_right <= #TCQ left1_tap - (right_tap - MIN_TAPS);
  end

  // cetner tap - left1 tap
  always @(posedge clk) begin
    if (rst_clk)
      ct_minus_left1 <= #TCQ 0;
    else if (CENTER_TAP < left1_tap)
      ct_minus_left1 <= #TCQ 0;
    else
      ct_minus_left1 <= #TCQ CENTER_TAP - left1_tap;
  end 


  // Determine tap setting to find center of window (or closest to center).
  // cdt_selected_d indicates if delaying the clock was best. Otherwise, it
  // indicates that data delay was necessary. Depending on the cdt_selected_d
  // setting, either the clock or data tap setting is placed on optimal_tap_d.
  // The tap_offset_d value indicates the distance from the true middle for
  // the selected setting. A value of 0 for the offset indicates that the
  // could be achieved with the optimal_tap_d setting.
  always @* begin
    casex ({found_left0, found_right, found_left1, 
            cdt_max, qdt_max, opp_first,
            clpct_lte_dt, cr_gt_ql, ct_lte_dtpcr, left0_gr_ctr})
      // Initial alignment put the clock within the opposite edge data window.
      // Delaying the clock did not find the left of the target data window
      // before the taps ran out. Therefore, there is no valid setting and
      // clock inversion is required.
      10'b0??_1?1_???? : begin
        cdt_selected_d  = 0;
        optimal_tap_d   = MIN_TAPS;
        tap_offset_d    = -1; // Sets to maximum value (all 1's)
        true_center_d   = 0;
        try_clk_inv_d   = 1;
        window_size_d   = 0;
      end
      // Initial alignment put the clock within the correct data window.
      // Delaying the clock could not find the right edge before the
      // clock taps maxed out. Reseting the clock delay to zero and
      // delaying the data was not able to find the left edge before the
      // data taps maxed out. Optimal setting is no clock taps and no
      // data taps.
      10'b000_110_???? : begin
        cdt_selected_d  = 1;
        optimal_tap_d   = MIN_TAPS;
        tap_offset_d    = 0;
        true_center_d   = 0;
        try_clk_inv_d   = 0;
        window_size_d   = DEVICE_TAPS + MAX_TAPS - MIN_TAPS;
      end
      // Initial alignment put the clock within the correct data window.
      // Delaying the clock could not find the right edge before the
      // clock taps maxed out. Reseting the clock delay to zero and
      // delaying the data was able to find the left edge before the
      // data taps maxed out. Delaying the clock is able to hit the
      // ideal center.
      // Optimal setting is CENTER_TAPS - data taps.
      10'b001_100_???? : begin
        cdt_selected_d  = 1;
        optimal_tap_d   = ct_minus_left1[4:0] + MIN_TAPS;
        tap_offset_d    = 0;
        true_center_d   = 0;
        try_clk_inv_d   = 1;
        window_size_d   = MAX_TAPS + left1_tap;
      end
      // Initial alignment put the clock within the opposite edge data window.
      // Delaying the clock found the left edge but right edge could not be
      // found before the taps ran out.
      // Maximum clock delay taps gets closest to center but not all the way.
      10'b10?_1?1_0??? : begin
        cdt_selected_d  = 1;
        optimal_tap_d   = MAX_TAPS;
        tap_offset_d    = CENTER_TAP - (MAX_TAPS - left0_tap);
        true_center_d   = 0;
        try_clk_inv_d   = 1;
        window_size_d   = MAX_TAPS - left0_tap;
      end
      // Initial alignment put the clock within the opposite edge data window.
      // Delaying the clock found the left edge but right edge could not be
      // found before the taps ran out.
      // Maximum clock delay taps does hit ideal center.
      10'b10?_1?1_1??? : begin
        cdt_selected_d  = 1;
        optimal_tap_d   = CENTER_TAP + left0_tap;
        tap_offset_d    = 0;
        true_center_d   = 0;
        try_clk_inv_d   = 1;
        window_size_d   = MAX_TAPS - left0_tap;
      end
      // Initial alignment put the clock within the opposite edge data window.
      // Delaying the clock found both the left and right edges of the target
      // data window.
      // Optimal setting is the midway between the left and right edges.
      10'b11?_??1_???0 : begin
        cdt_selected_d  = 1;
        optimal_tap_d   = left0_plus_right[TAP_BITS:1];  // (left0_tap + right_tap) / 2
        tap_offset_d    = 0;
        true_center_d   = 1;
        try_clk_inv_d   = 0;
        window_size_d   = right_tap - left0_tap;
      end
      // Initial alignment put the clock within the opposite edge data window.
      // Delaying the clock found both the left and right edges of the target
      // data window. Optimal setting is close to the end of the delay chain
      // Inversion can provide a smaller delay on the clock.
      10'b11?_??1_???1 : begin
        cdt_selected_d  = 1;
        optimal_tap_d   = left0_plus_right[TAP_BITS:1];  // (left0_tap + right_tap) / 2
        tap_offset_d    = 0;
        true_center_d   = 0;
        try_clk_inv_d   = 1;
        window_size_d   = right_tap - left0_tap;
      end 
   //   // Initial alignment put the clock within the opposite edge data window.
   //   // Delaying the clock found both the left and right edges of the target
   //   // data window. Optimal setting is close to the end of the delay chain
   //   // Inversion can provide a smaller delay on the clock.
   //   10'b11?_??1_???? : begin
   //     cdt_selected_d  = 1;
   //     optimal_tap_d   = left0_plus_right[TAP_BITS:1];  // (left0_tap + right_tap) / 2
   //     tap_offset_d    = 0;
   //     true_center_d   = 1;
   //     try_clk_inv_d   = 0;
   //     window_size_d   = right_tap - left0_tap;
   //   end
      
      // Initial alignment put the clock within the correct data window.
      // Delaying the clock found the right edge. Reseting the clock delay to
      // zero and then delaying the data found the left edge. Clock delay was
      // larger than data delay.
      // Optimal setting is (clock taps - data taps) / 2
      10'b?11_??0_?1?? : begin
        cdt_selected_d  = 1;
        optimal_tap_d   = {1'b0, right_minus_left1[TAP_BITS-1:1]} + MIN_TAPS;  // (right_tap - left1_tap) / 2
        tap_offset_d    = 0;
        true_center_d   = 1;
        try_clk_inv_d   = 0;
        window_size_d   = right_tap + left1_tap;
      end
      // Initial alignment put the clock within the correct data window.
      // Delaying the clock found the right edge. Reseting the clock delay to
      // zero and then delaying the data found the left edge. Clock delay was
      // smaller than data delay.
      // Optimal setting is (data taps - clock taps) / 2
      10'b?11_??0_?0?? : begin
        cdt_selected_d  = 0;
        optimal_tap_d   = {1'b0, left1_minus_right[TAP_BITS-1:1]};  // (left1_tap - right_tap) / 2
        tap_offset_d    = 0;
        true_center_d   = 1;
        try_clk_inv_d   = 1;
        window_size_d   = left1_tap + right_tap - MIN_TAPS;
      end
      // Initial alignment put the clock with the correct data window.
      // Delaying the clock found the right edge. Reseting the clock delay to
      // zero and then delaying the data could not find the left edge before the
      // taps ran out. The ideal center tap cannot be reached by delaying data.
      // Maximum data delay taps gets closest to center but not all the way.
      10'b?10_?10_??0? : begin
        cdt_selected_d  = 0;
        optimal_tap_d   = DEVICE_TAPS - 1; //max taps on the data
        tap_offset_d    = CENTER_TAP -  DEVICE_TAPS - 1;
        true_center_d   = 0;
        try_clk_inv_d   = 1;
        window_size_d   = DEVICE_TAPS + right_tap - MIN_TAPS;
      end
      // Initial alignment put the clock with the correct data window.
      // Delaying the clock found the right edge. Reseting the clock delay to
      // zero and then delaying the data could not find the left edge before the
      // taps ran out. The ideal center tap can be reached by delaying data.
      // Optimal setting is the difference between center tap and right edge.
      10'b?10_?10_??1? : begin
        cdt_selected_d  = 0;
        optimal_tap_d   = CENTER_TAP; // center taps delay on the data
        tap_offset_d    = 0;
        true_center_d   = 0;
        try_clk_inv_d   = 1;
        window_size_d   = DEVICE_TAPS + right_tap - MIN_TAPS;
      end
      default : begin
        cdt_selected_d  = 1'h0;
        optimal_tap_d   = 5'h00;
        tap_offset_d    = 5'h00;
        true_center_d   = 0;
        try_clk_inv_d   = 1'h0;
        window_size_d   = 0;
      end
    endcase
  end


  always @(posedge clk) begin
    if (rst_clk) begin
      cdt_selected  <= #TCQ 0;
      optimal_tap   <= #TCQ 0;
      tap_offset    <= #TCQ 0;
      true_center   <= #TCQ 0;
      try_clk_inv   <= #TCQ 0;
      window_size   <= #TCQ 0;
    end else begin
      cdt_selected  <= #TCQ cdt_selected_d;
      optimal_tap   <= #TCQ optimal_tap_d;
      tap_offset    <= #TCQ tap_offset_d;
      true_center   <= #TCQ true_center_d;
      try_clk_inv   <= #TCQ try_clk_inv_d;
      window_size   <= #TCQ window_size_d;
    end
  end

  // }}} end Tap Centering ----------------------


  // {{{ Overall Calibration Control ------------

  // After the initialization logic has completed, signal to the initilization
  // logic to begin stage 1 calibration. Wait for the read back data to come
  // across before starting the calibration state machine.
  always @(posedge clk) begin
    if (rst_clk)
      cal_stage1_start <= #TCQ 0;
    else if (init_done)
      cal_stage1_start <= #TCQ 1;
  end

  always @(posedge clk) begin
    cal_sm_start_tmp <= #TCQ {cal_sm_start_tmp[CAL_START_DLY-1:0], cal_stage1_start};
  end

  always @(posedge clk) begin
    if (rst_clk)
      cal_sm_start <= #TCQ 0;
    else
      cal_sm_start <= #TCQ cal_sm_start_tmp[CAL_START_DLY];
  end
  
  assign q_mem_0 = (q_mem == 0);
  assign q_bit_max = (q_bit == DATA_WIDTH - 1);
  assign q_mem_max = (q_mem == MEMORY_WIDTH - 1);

  // Register State Machine Outputs
  always @(posedge clk) begin
    if (rst_clk) begin
      cal_cs              <= #TCQ CAL_IDLE;
      start_ctr_cal_int   <= #TCQ 0;
      cal_rise            <= #TCQ 1;
      save_rise_edge      <= #TCQ 0;
      save_rise_edge_inv  <= #TCQ 0;
      save_fall_edge      <= #TCQ 0;
      save_current        <= #TCQ 0;
      force_clk_invert    <= #TCQ 0;
      issue_dly_rst       <= #TCQ 0;
      issue_load_c        <= #TCQ 0;
      issue_load_q        <= #TCQ 0;
      inc_q               <= #TCQ 0;
      inc_cq              <= #TCQ 0;
      next_q_grp          <= #TCQ 0;
    end else begin
      cal_cs              <= #TCQ cal_ns;
      start_ctr_cal_int   <= #TCQ start_ctr_cal_d;
      cal_rise            <= #TCQ cal_rise_d;
      save_rise_edge      <= #TCQ save_rise_edge_d;
      save_rise_edge_inv  <= #TCQ save_rise_edge_inv_d;
      save_fall_edge      <= #TCQ save_fall_edge_d;
      save_current        <= #TCQ save_current_d;
      force_clk_invert    <= #TCQ force_clk_invert_d;
      issue_dly_rst       <= #TCQ issue_dly_rst_d;
      issue_load_c        <= #TCQ issue_load_c_d;
      issue_load_q        <= #TCQ issue_load_q_d;
      inc_q               <= #TCQ inc_q_d;
      inc_cq              <= #TCQ inc_cq_d;
      next_q_grp          <= #TCQ next_q_grp_d;
    end
  end

  // Per-bit delay calibration state machine
  always @* begin

      start_ctr_cal_d       = 0;
      cal_rise_d            = cal_rise;
      save_rise_edge_d      = 0;
      save_rise_edge_inv_d  = 0;
      save_fall_edge_d      = 0;
      save_current_d        = 0;
      force_clk_invert_d    = 0;
      clear_clk_invert      = 0;
      set_clk_polarity      = 0;
      issue_dly_rst_d       = 0;
      issue_load_c_d        = 0;
      issue_load_q_d        = 0;
      inc_q_d               = 0;
      inc_cq_d              = 0;
      save_target_q         = 0;
      clr_q                 = 0;
      load_init             = 0;
      capture_adj           = 0;
      start_adj             = 0;
      next_q_grp_d          = 0;
      cal_ns                = CAL_IDLE;
    case (cal_cs)

      // Wait until initialization logic is complete and then initiate tap
      // centering on rising edge data for Q0. Completely skip delay
      // calibration when SIM_CAL_OPTION="SKIP_CAL" and proceed to calibrate
      // a single phase.
      CAL_IDLE : begin
        if (cal_sm_start) begin
          if (SIM_CAL_OPTION == "NONE" || SIM_CAL_OPTION == "FAST_CAL") begin
            start_ctr_cal_d = 1;
            cal_rise_d      = 1;
            cal_ns          = CAL_Q_RISE;
          end else if (SIM_CAL_OPTION == "SKIP_CAL" && data_stable) begin
            start_ctr_cal_d = 0;
            cal_rise_d      = 1;
            cal_ns          = CAL_SET_PHASE;
          end
        end else begin
          start_ctr_cal_d = 0;
          cal_rise_d      = 1;
          cal_ns          = CAL_IDLE;
        end
      end

      // Wait for tap centering state machine to return the best tap settings
      // for the particual bit being calibrated. Clock inversion is only tried
      // for the first Q bit in each CQ group.
      CAL_Q_RISE : begin
        casex ({ctr_done, start_in_progress, q_mem_0, try_clk_inv})
          // Center was found for first Q in memory and clock inversion is not
          // necessary.
          4'b10_10 : begin
            start_ctr_cal_d     = 0;
            save_rise_edge_d    = 1;
            save_current_d      = 0;
            force_clk_invert_d  = 0;
            cal_ns              = CAL_DET_OPT;
          end
          // Center was found for first Q in memory and clock inversion
          // needs to be checked for better results.
          4'b10_11 : begin
            start_ctr_cal_d     = 1;
            save_rise_edge_d    = 1;
            save_current_d      = 0;
            force_clk_invert_d  = 1;
            issue_dly_rst_d = 1;
            cal_ns              = CAL_Q_RISE_INV;
          end
          // Center was found for a Q other than the first in the memory.
          4'b10_0? : begin
            start_ctr_cal_d     = 0;
            save_rise_edge_d    = 0;
            save_current_d      = 1;
            force_clk_invert_d  = 0;
            cal_ns              = CAL_QBIT_DET;
          end
          // Wait until the centering algorithm returns.
          default : begin
            start_ctr_cal_d     = 0;
            save_rise_edge_d    = 0;
            save_current_d      = 0;
            force_clk_invert_d  = 0;
            cal_ns              = CAL_Q_RISE;
          end
        endcase
      end

      // Wait for tap centering state machine to return the best tap settings
      // for first rising edge bit in the memory using the inverted clock.
      CAL_Q_RISE_INV : begin
        if (ctr_done && !start_in_progress) begin
          save_rise_edge_inv_d  = 1;
          cal_ns                = CAL_DET_OPT;
        end else begin
          save_rise_edge_inv_d  = 0;
          cal_ns                = CAL_Q_RISE_INV;
        end
      end

      // Determine the optimal tap setting for the first Q bit in the target CQ
      // group. This dictates if the ISERDES clock should be inverted and is
      // used for the remainder of the calibration. Set the calibrated clock
      // polarity and proceed to calibration the falling data for the first Q
      // in the memory.
      CAL_DET_OPT : begin
        if (det_opt_done && MEMORY_TYPE == "RLD2" ) begin
          set_clk_polarity  = 1;
          start_ctr_cal_d   = 0;
          issue_dly_rst_d   = 1;
          cal_rise_d        = 1;
          cal_ns            = CAL_DET_OVR;
        end else if (det_opt_done && MEMORY_TYPE == "QDR" ) begin
          set_clk_polarity  = 1;
          start_ctr_cal_d   = 1;
          issue_dly_rst_d   = 1;
          cal_rise_d        = 0;
          cal_ns            = CAL_Q_FALL;
        end else begin
          set_clk_polarity  = 0;
          start_ctr_cal_d   = 0;
          issue_dly_rst_d   = 0;
          cal_rise_d        = 1;
          cal_ns            = CAL_DET_OPT;
        end
      end

      // Wait for tap centering state machine to return the best tap settings
      // for first falling edge bit in the memory using the clock polarity
      // previously chosen by the rising edge data.
      CAL_Q_FALL : begin
        if (ctr_done && !start_in_progress) begin
          save_fall_edge_d  = 1;
          cal_ns            = CAL_DET_OVR;
        end else begin
          save_fall_edge_d  = 0;
          cal_ns            = CAL_Q_FALL;
        end
      end

      // Now that both rising and falling edge data have been calibrated for
      // the first Q in the memory, determine and the overall settings that
      // best suit the rise and fall data.
      CAL_DET_OVR : begin    
        if (MEMORY_TYPE == "RLD2"  && det_ovr_done) begin
           issue_load_c_d  = 0;
           issue_load_q_d  = 0;
           load_init       = 0;
           cal_ns = CAL_RST_WAIT;
        end else if (det_ovr_done) begin
          issue_load_c_d  = 1;
          issue_load_q_d  = 1;
          load_init       = 1;
          cal_ns          = CAL_SET_OVR;
        end else begin
          issue_load_c_d  = 0;
          issue_load_q_d  = 0;
          load_init       = 0;
          cal_ns          = CAL_DET_OVR;
        end
      end
       
      // The statemachine waits for cq_rst_done to go high before issuing load_c
      
      CAL_RST_WAIT : begin    
         if (cq_rst_done) begin
          issue_load_c_d  = 1;
          issue_load_q_d  = 1;
          load_init       = 1;
          cal_ns          = CAL_SET_OVR;
        end else begin
          issue_load_c_d  = 0;
          issue_load_q_d  = 0;
          load_init       = 0;
          cal_ns          = CAL_RST_WAIT;  
        end 
      end      
      
      // Set the overall settings for both the rise and fall data for the first
      // Q in the memory. Wait for the update to complete before advancing on
      // and calibrating the next Q bit in the memory.      
      CAL_SET_OVR : begin
        if (set_ovr_done && data_stable) begin
          if (SIM_CAL_OPTION == "FAST_CAL") begin
            start_ctr_cal_d = 0;
            inc_q_d         = 0;
            cal_rise_d      = 1;
            cal_ns          = CAL_SET_PHASE;
          end else begin
            start_ctr_cal_d = 1;
            inc_q_d         = 1;
            cal_rise_d      = 1;
            issue_dly_rst_d = 1;
            cal_ns          = CAL_Q_RISE;
          end
        end else begin
          start_ctr_cal_d = 0;
          inc_q_d         = 0;
          cal_rise_d      = cal_rise;
          cal_ns          = CAL_SET_OVR;
        end
      end

      // Determine the settings for the current Q being calibrated and if any
      // adjustments to the previous Q's in the memory must be made.
      CAL_QBIT_DET : begin
        casex ({qbit_det_done, prev_adj_req})
          // Settings for the current Q have been determined and adjustments
          // to previous Q's are required. Load the C and Q values for the
          // current Q before adjusting the previous Q's.
          2'b11 : begin
            issue_load_c_d  = 1;
            issue_load_q_d  = 1;
            save_target_q   = 1;
            capture_adj     = 1;
            cal_ns          = CAL_QBIT_SET;
          end
          // Settings for the current Q have been determined and no adjustments
          // to the previous Q's are required.
          2'b10 : begin
            issue_load_c_d  = q_mem_max;
            issue_load_q_d  = 1;
            save_target_q   = 0;
            capture_adj     = 1;
            cal_ns          = CAL_QBIT_SET;
          end
          // Wait until the current Q settings are determined and if any prior
          // Q adjustments are needed.
          default : begin
            issue_load_c_d  = 0;
            issue_load_q_d  = 0;
            save_target_q   = 0;
            capture_adj     = 0;
            cal_ns          = CAL_QBIT_DET;
          end
        endcase
      end

      // Set the data tap delay for the current Q being calibrated.
      CAL_QBIT_SET : begin
      casex ({data_stable, q_mem_max, qbit_set_done, q_bit_max, cap_prev_adj_req})
          // Data delay has been set and updates have completed. Continue on
          // calibrating the next Q in the memory.
          5'b1_0100 : begin
            clr_q           = 0;
            start_ctr_cal_d = 1;
            inc_q_d         = 1;
            inc_cq_d        = 0;
            issue_dly_rst_d = 1;
            cal_ns          = CAL_Q_RISE;
          end
          // Data delay has been set and updated have completed. There are no
          // more Q's to calibrated.
          5'b1_0110 : begin
            clr_q           = 0;
            start_ctr_cal_d = 0;
            inc_q_d         = 0;
            inc_cq_d        = 0;
            cal_ns          = CAL_DONE;
          end
          // The final Q in the memory has been set. Proceed on to set the
          // phase for the data alignment logic.
          5'b1_11?0 : begin
            clr_q           = 0;
            start_ctr_cal_d = 0;
            inc_q_d         = 0;
            inc_cq_d        = 0;
            cal_ns          = CAL_SET_PHASE;
          end
          // The C and Q values for the current Q be calibrated have been
          // loaded. Adjustments are required for previous Q's.
          5'b1_?1?1 : begin
            clr_q           = 1;
            start_ctr_cal_d = 0;
            inc_q_d         = 0;
            inc_cq_d        = 0;
            cal_ns          = CAL_ADJ_REQ;
          end
          // Wait for the data delay to be set and the updates to take effect.
          default : begin
            clr_q           = 0;
            start_ctr_cal_d = 0;
            inc_q_d         = 0;
            inc_cq_d        = 0;
            cal_ns          = CAL_QBIT_SET;
          end
        endcase
      end
      
      // Data delay adjustments are required for previous Q's in the memory.
      CAL_ADJ_REQ : begin
        casex ({data_stable, q_mem_max, all_q_adj, load_done, q_bit_rdy, tap_done})
          // The values for the current Q have been loaded and completed
          // updating and all previous Q's have been adjusted. It is not
          // necessary to wait for the settings of those previous Q's to
          // update since they do not affect other Q's. There are additional
          // Q's to calibrate within the memory.
          6'b101_11? : begin
            start_ctr_cal_d = 1;
            inc_q_d         = 1;
            inc_cq_d        = 0;
            start_adj       = 0;
            issue_dly_rst_d = 1;
            cal_ns          = CAL_Q_RISE;
          end
          // All Q's in the memory have been adjusted. Proceed on to set the
          // phase for the data alignment.
          6'b111_111 : begin
            start_ctr_cal_d = 0;
            inc_q_d         = 0;
            inc_cq_d        = 0;
            start_adj       = 0;
            cal_ns          = CAL_SET_PHASE;
          end
          // After the Q bit setting has stabilized, proceed to adjust the data
          // delay for that bit.
          6'b1?0_?1? : begin
            start_ctr_cal_d = 0;
            inc_q_d         = 0;
            inc_cq_d        = 0;
            start_adj       = 1;
            cal_ns          = CAL_ADJ;
          end
          // Wait until either all previous Q's have been adjusted or when the
          // target Q being adjusted for has had time to update.
          default : begin
            start_ctr_cal_d = 0;
            inc_q_d         = 0;
            inc_cq_d        = 0;
            start_adj       = 0;
            cal_ns          = CAL_ADJ_REQ;
          end
        endcase
      end

      // Adjust the data tap delay for the target Q. This handles adding data
      // delay for previous Q's when required. After the complete data delay
      // has been added for the target Q, continue to check if there are other
      // Q's that need adjusting.
      CAL_ADJ : begin
        if (q_bit_adj_done) begin
          inc_q_d = 1;
          cal_ns  = CAL_ADJ_REQ;
        end else begin
          inc_q_d = 0;
          cal_ns  = CAL_ADJ;
        end
      end

      // Set the proper phase for the data alignment logic. If there are
      // additional memories to calibrate, continue on to them otherwise
      // calibration is complete. Finish calibration when
      // SIM_CAL_OPTION="SKIP_CAL.
      CAL_SET_PHASE : begin
        if (SIM_CAL_OPTION == "NONE") begin
          start_ctr_cal_d   = !q_bit_max;
          inc_cq_d          = !q_bit_max;
          inc_q_d           = !q_bit_max;
          next_q_grp_d      = 0;
          clear_clk_invert  = !q_bit_max;
          cal_ns            = q_bit_max ? CAL_DONE : CAL_Q_RISE;
        end else if (SIM_CAL_OPTION == "FAST_CAL") begin
          start_ctr_cal_d   = (cq_num != NUM_DEVICES-1);
          inc_cq_d          = (cq_num != NUM_DEVICES-1);
          inc_q_d           = (cq_num != NUM_DEVICES-1);
          next_q_grp_d      = (cq_num != NUM_DEVICES-1);
          clear_clk_invert  = (cq_num != NUM_DEVICES-1);
          cal_ns            = (cq_num != NUM_DEVICES-1) ? CAL_Q_RISE : CAL_DONE;
        end else if (SIM_CAL_OPTION == "SKIP_CAL") begin
          start_ctr_cal_d   = 0;
          inc_cq_d          = 0;
          inc_q_d           = 0;
          next_q_grp_d      = 0;
          clear_clk_invert  = 0;
          cal_ns            = CAL_DONE;
        end
      end

      // Delay calibration is complete.
      CAL_DONE : begin
        cal_ns = CAL_DONE;
      end

      default : begin
        cal_ns = CAL_IDLE;
      end

    endcase
  end

  // Indicate that stage 2 calibration should begin after stage one calibration
  // is complete.
  always @(posedge clk) begin
    if (rst_clk)
      cal_stage2_start <= #TCQ 0;
    else if (cal_ns == CAL_DONE)
      cal_stage2_start <= #TCQ 1;
  end

  // Extend the tap centering start signal to three cycles. This is necessary
  // to both exit the DONE state and proceed through the IDLE state.
  always @(posedge clk) begin
    if (rst_clk) begin
      start_ctr_cal_int_r <= #TCQ 0;
      start_ctr_cal_int_2r <= #TCQ 0;
    end else begin
      start_ctr_cal_int_r <= #TCQ start_ctr_cal_int;
      start_ctr_cal_int_2r <= #TCQ start_ctr_cal_int_r;
    end
  end

  always @(posedge clk) begin
    if (rst_clk)
      start_ctr_cal <= #TCQ 0;
    else
      start_ctr_cal <= #TCQ start_ctr_cal_int || start_ctr_cal_int_r || 
                            start_ctr_cal_int_2r;
  end

  // Wait to begin centering state machine until q_bit_rdy and c_num_rdy are
  // asserted. This is necessary to allow time to mux in new data based on
  // q_bit.
  always @(posedge clk) begin
    if (rst_clk)
      start_ctr_cal_hold <= #TCQ 0;
    else if (start_ctr_cal)
      start_ctr_cal_hold <= #TCQ 1;
    else if (start_ctr_cal_rdy)
      start_ctr_cal_hold <= #TCQ 0;
  end

  always @(posedge clk) begin
    if (rst_clk)
      start_ctr_cal_rdy <= #TCQ 0;
    else if (start_ctr_cal_hold)
      start_ctr_cal_rdy <= #TCQ q_bit_rdy && c_num_rdy && rst_done && polarity_done;
    else if (!start_ctr_cal_hold)
      start_ctr_cal_rdy <= #TCQ 0;
  end

  // Indicate when the start is active which will be used to gate the checking
  // of ctr_done.
  assign start_in_progress = start_ctr_cal_int || start_ctr_cal;

  // Save the results from the tap centering state machine for the rising edge
  // data.
  always @(posedge clk) begin
    if (rst_clk) begin
      re_cdt_selected       <= #TCQ 0;
      re_optimal_tap        <= #TCQ 0;
      re_tap_offset         <= #TCQ 0;
      re_true_center        <= #TCQ 0;
      re_start_left0        <= #TCQ 0;
      re_left0_tap          <= #TCQ 0;
      re_window_size0       <= #TCQ 0;
      re_qmem0_left0_tap    <= #TCQ 0;
      re_qmem0_right_tap    <= #TCQ 0;
      re_qmem0_left1_tap    <= #TCQ 0;
      re_qmem0_found_left0  <= #TCQ 0;
      re_qmem0_found_right  <= #TCQ 0;
      re_qmem0_found_left1  <= #TCQ 0;
      re_qmem0_cdt_max      <= #TCQ 0;
      re_qmem0_qdt_max      <= #TCQ 0;
      re_qmem0_opp_first    <= #TCQ 0;
      re_qmem0_start_left0  <= #TCQ 0;
    end else if (cal_rise && save_rise_edge) begin
      re_cdt_selected       <= #TCQ cdt_selected;
      re_optimal_tap        <= #TCQ optimal_tap;
      re_tap_offset         <= #TCQ tap_offset;
      re_true_center        <= #TCQ true_center;
      re_start_left0        <= #TCQ start_left0;
      re_left0_tap          <= #TCQ left0_tap;
      re_window_size0       <= #TCQ (window_size == 0);
      re_qmem0_left0_tap    <= #TCQ q0mem_left0_tap;
      re_qmem0_right_tap    <= #TCQ q0mem_right_tap;
      re_qmem0_left1_tap    <= #TCQ q0mem_left1_tap;
      re_qmem0_found_left0  <= #TCQ q0mem_found_left0;
      re_qmem0_found_right  <= #TCQ q0mem_found_right;
      re_qmem0_found_left1  <= #TCQ q0mem_found_left1;
      re_qmem0_cdt_max      <= #TCQ q0mem_cdt_max;
      re_qmem0_qdt_max      <= #TCQ q0mem_qdt_max;
      re_qmem0_opp_first    <= #TCQ q0mem_opp_first;
      re_qmem0_start_left0  <= #TCQ q0mem_start_left0;
    end
  end

  // Indicate when rising edge has been captured.
  always @(posedge clk) begin
    if (rst_clk)
      re_captured <= #TCQ 0;
    else
      re_captured <= #TCQ cal_rise && save_rise_edge;
  end

  // Save the results from the tap centering state machine for the rising edge
  // data now with the clk/clkb inputs to the ISERDES inverted.
  always @(posedge clk) begin
    if (rst_clk) begin
      rei_cdt_selected      <= #TCQ 0;
      rei_optimal_tap       <= #TCQ 0;
      rei_true_center       <= #TCQ 0;
      rei_start_left0       <= #TCQ 0;
      rei_left0_tap         <= #TCQ 0;
      rei_window_size0      <= #TCQ 0;
      rei_qmem0_left0_tap   <= #TCQ 0;
      rei_qmem0_right_tap   <= #TCQ 0;
      rei_qmem0_left1_tap   <= #TCQ 0;
      rei_qmem0_found_left0 <= #TCQ 0;
      rei_qmem0_found_right <= #TCQ 0;
      rei_qmem0_found_left1 <= #TCQ 0;
      rei_qmem0_cdt_max     <= #TCQ 0;
      rei_qmem0_qdt_max     <= #TCQ 0;
      rei_qmem0_opp_first   <= #TCQ 0;
      rei_qmem0_start_left0 <= #TCQ 0;
    end else if (cal_rise && save_rise_edge_inv) begin
      rei_cdt_selected      <= #TCQ cdt_selected;
      rei_optimal_tap       <= #TCQ optimal_tap;
      rei_true_center       <= #TCQ true_center;
      rei_start_left0       <= #TCQ start_left0;
      rei_left0_tap         <= #TCQ left0_tap;
      rei_window_size0      <= #TCQ (window_size == 0);
      rei_qmem0_left0_tap   <= #TCQ q0mem_left0_tap;
      rei_qmem0_right_tap   <= #TCQ q0mem_right_tap;
      rei_qmem0_left1_tap   <= #TCQ q0mem_left1_tap;
      rei_qmem0_found_left0 <= #TCQ q0mem_found_left0;
      rei_qmem0_found_right <= #TCQ q0mem_found_right;
      rei_qmem0_found_left1 <= #TCQ q0mem_found_left1;
      rei_qmem0_cdt_max     <= #TCQ q0mem_cdt_max;
      rei_qmem0_qdt_max     <= #TCQ q0mem_qdt_max;
      rei_qmem0_opp_first   <= #TCQ q0mem_opp_first;
      rei_qmem0_start_left0 <= #TCQ q0mem_start_left0;
    end
  end

  // Indicate when rising edge using inverted ISERDES clock has been captured.
  always @(posedge clk) begin
    if (rst_clk)
      rei_captured <= #TCQ 0;
    else
      rei_captured <= #TCQ cal_rise && save_rise_edge_inv;
  end
  
  // Save the results from the tap centering state machine for the falling edge
  // data using the optimal clock polarity from the rising edge calibration.
  // For RLDRAM, there is no separate falling edge capture and hence the rising edge
  // signals are assigned.
  always @(posedge clk) begin
    if (rst_clk) begin
      fe_cdt_selected <= #TCQ 0;
      fe_optimal_tap  <= #TCQ 0;
    end else if  (cal_rise && save_rise_edge && MEMORY_TYPE == "RLD2" ) begin
      fe_cdt_selected <= #TCQ cdt_selected;
      fe_optimal_tap  <= #TCQ optimal_tap;
    end else if (cal_rise && save_rise_edge_inv && MEMORY_TYPE == "RLD2" ) begin 
      fe_cdt_selected <= #TCQ cdt_selected;
      fe_optimal_tap  <= #TCQ optimal_tap;
    end else if (!cal_rise && save_fall_edge) begin // QDRII case
      fe_cdt_selected <= #TCQ cdt_selected;
      fe_optimal_tap  <= #TCQ optimal_tap;
    end
  end

  // Indicate when falling edge has been captured.
  always @(posedge clk) begin
    if (rst_clk)
      fe_captured <= #TCQ 0;
    else if (MEMORY_TYPE == "RLD2" && cq_num_rst)
      fe_captured <= 1'b1;
    else
      fe_captured <= #TCQ !cal_rise && save_fall_edge;
  end
  
  // Save results from the tap centering state machine for the subsequent bits
  // following Q0 from each memory. This will be for the rising edge data using
  // the previously determined clock inversion.
  always @(posedge clk) begin
    if (rst_clk) begin
      curr_cdt_selected <= #TCQ 0;
      curr_optimal_tap  <= #TCQ 0;
    end else if (save_current) begin
      curr_cdt_selected <= #TCQ cdt_selected;
      curr_optimal_tap  <= #TCQ optimal_tap;
    end
  end

  // Indicate when current Q has been captured.
  always @(posedge clk) begin
    if (rst_clk)
      curr_captured <= #TCQ 0;
    else
      curr_captured <= #TCQ save_current;
  end

  // }}} end Overall Calibration Control --------
  

  // {{{ Determine Optimal Q0 Tap Setting -------

  // Determine optimal edge setting between using the non-inverted clk/clkb
  // inputs to the ISERDES versus the inverted clks (if applicable). The best
  // option is the one that can find the exact middle (or closest) with
  // priority given to clock delay over data (because of the better jitter
  // characteristics).

  // Determine if the settings were able to find the middle
  assign tap_offset0 = (tap_offset == 0);

  always @(posedge clk) begin
    if (rst_clk) begin
      re_tap_off0     <= #TCQ 0;
    end else if (cal_rise && save_rise_edge) begin
      re_tap_off0     <= #TCQ tap_offset0;
    end
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      rei_tap_off0      <= #TCQ 0;
    end else if (cal_rise && save_rise_edge_inv) begin
      rei_tap_off0      <= #TCQ tap_offset0;
    end
  end

  // Determine if the rising edge clock/data was closer to the middle of the
  // eye than the rising clock/data using clk/clkb ISERDES inversion.

  always @(posedge clk) begin
    if (rst_clk) begin
      re_better_tap_off <= #TCQ 1;
    end else if (cal_rise && save_rise_edge) begin
      re_better_tap_off <= #TCQ 1;
    end else if (cal_rise && save_rise_edge_inv) begin
      re_better_tap_off <= #TCQ (re_tap_offset <= tap_offset);
    end
  end
  
  // Select best setting
  always @* begin
    casex ({re_cdt_selected, rei_cdt_selected, 
            re_tap_off0, rei_tap_off0,
            re_true_center, rei_true_center,
            re_window_size0, rei_window_size0,
            re_better_tap_off})
      // Delaying the clock without any inversion found exact middle
      9'b1?_1?_1?_??_? : begin
        invert_clk_d        = 0;
        rise_cdt_delayed_d  = 1;
        det_opt_done_d      = re_captured;
        det_opt_setting_d   = 4'd0;     
      end
      // Delaying the clock with inversion found exact middle (rising edge clock
      // or data delay was not able to find exact middle)
      9'b?1_?1_?1_??_? : begin 
        invert_clk_d        = 1;
        rise_cdt_delayed_d  = 1;
        det_opt_done_d      = rei_captured;
        det_opt_setting_d   = 4'd1;
      end

      // Delaying the clock without any inversion found approximate middle
      // (rising edge with inversion was not able to find the exact middle)
      9'b1?_1?_0?_??_? : begin  
        invert_clk_d        = 0;
        rise_cdt_delayed_d  = 1;
        det_opt_done_d      = rei_captured;
        det_opt_setting_d   = 4'd3;
      end

      // Delaying the clock with inversion found approximate middle (rising
      // edge clock or data delay was not able to find approximate middle)
      9'b?1_?1_?0_??_? : begin 
        invert_clk_d        = 1;
        rise_cdt_delayed_d  = 1;
        det_opt_done_d      = rei_captured;
        det_opt_setting_d   = 4'd5;
      end

      // Delaying the clock without any inversion got closest to middle (rising
      // edge with inversion was not able to get closer to middle)
      9'b1?_0?_??_0?_? : begin
        invert_clk_d        = 0;
        rise_cdt_delayed_d  = 1;
        det_opt_done_d      = rei_captured;
        det_opt_setting_d   = 4'd7;
      end

      // Delaying the clock with inversion got closest to middle (rising edge
      // clock or data delay was not able to get closer to the middle)
      9'b?1_?0_??_?0_? : begin   
        invert_clk_d        = 1;
        rise_cdt_delayed_d  = 1;
        det_opt_done_d      = rei_captured;
        det_opt_setting_d     = 4'd9;
      end
      
      // Default to delaying data with better tap offset. This is a last resort.
      default : begin
        invert_clk_d        = !re_better_tap_off;
        rise_cdt_delayed_d  = 0;
        det_opt_done_d      = rei_captured;
        det_opt_setting_d   = 4'd11;
      end
    endcase
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      invert_clk        <= #TCQ 0;
      rise_cdt_delayed  <= #TCQ 1;
      det_opt_done      <= #TCQ 0;
      det_opt_setting   <= #TCQ 0;
    end else begin
      invert_clk        <= #TCQ invert_clk_d;  
      rise_cdt_delayed  <= #TCQ rise_cdt_delayed_d;
      det_opt_done      <= #TCQ det_opt_done_d;
      det_opt_setting   <= #TCQ det_opt_setting_d;
    end
  end

  // }}} end Determine Optimal Q0 Tap Setting ---


  // {{{ Set Overall Q0 Tap Setting -------------
  
  // Set overall Q0 tap setting. If both rise and fall edge data used clock
  // delays to center, then no adjustments are needed as both CQ and CQ# can
  // be independently controlled. However, if data delay is required for either
  // or both, then the clocks will need to be adjusted as well since delaying
  // the data for one edge affects the other edge.

  assign rise_optimal_tap = invert_clk ? rei_optimal_tap : re_optimal_tap;

  always @(posedge clk) begin
    if (rst_clk) begin
      cq_qdly_larger  <= #TCQ 0;
      fe_captured_r   <= #TCQ 0;
    end else begin
      cq_qdly_larger  <= #TCQ rise_optimal_tap > fe_optimal_tap;
      fe_captured_r   <= #TCQ fe_captured;
    end
  end

  always @* begin
    casex ({MEM_TYPE_RLD, rise_cdt_delayed, fe_cdt_selected, cq_qdly_larger})
       // RLD case where clocks are centered with clock delay only.
      4'b1_1?_? : begin
        cq_num_load_val_d   = rise_optimal_tap;
        cqn_num_load_val_d  = MIN_TAPS;
        q_bit_load_val_d    = 0;
      end
      // RLD case where clocks are centered with data delay only.
      4'b1_0?_? : begin
        cq_num_load_val_d   = MIN_TAPS;
        cqn_num_load_val_d  = MIN_TAPS;
        q_bit_load_val_d    = rise_optimal_tap;
      end
      // Both CQ and CQ# are centered with clock delay only. No adjustment is
      // required.
      4'b0_11_? : begin
        cq_num_load_val_d   = rise_optimal_tap;
        cqn_num_load_val_d  = fe_optimal_tap;
        q_bit_load_val_d    = 0;
      end
      // CQ can be centered with clock delay but CQ# requires data delay. Thus
      // the CQ clock delay must be adjusted further to account for the Q being
      // delayed.
      4'b0_10_? : begin
        cq_num_load_val_d   = rise_optimal_tap + fe_optimal_tap;
        cqn_num_load_val_d  = MIN_TAPS;
        q_bit_load_val_d    = fe_optimal_tap;
      end
      // CQ# can be centered with clock delay but CQ requires data delay. Thus
      // the CQ# clock delay must be adjusted further to account for the Q
      // being delayed.
      4'b0_01_? : begin
        cq_num_load_val_d   = MIN_TAPS;
        cqn_num_load_val_d  = fe_optimal_tap + rise_optimal_tap;
        q_bit_load_val_d    = rise_optimal_tap;
      end
      // Both CQ and CQ# required data delays and the CQ data delay is larger
      // than the data delay for CQ#. CQ# clock delay must be adjusted to
      // account for larger Q delay.
      4'b0_00_1 : begin
        cq_num_load_val_d   = MIN_TAPS;
        cqn_num_load_val_d  = rise_optimal_tap - fe_optimal_tap;
        q_bit_load_val_d    = rise_optimal_tap;
      end
      // Both CQ and CQ# required data delays and the CQ# data delay is larger
      // than the data delay for CQ. CQ clock delay must be adjusted to
      // account for larger Q delay.
      default : begin
        cq_num_load_val_d   = fe_optimal_tap - rise_optimal_tap;
        cqn_num_load_val_d  = MIN_TAPS;
        q_bit_load_val_d    = fe_optimal_tap;
      end
    endcase
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      cq_num_load_val   <= #TCQ MIN_TAPS;
      cqn_num_load_val  <= #TCQ MIN_TAPS;
      q_bit_load_val    <= #TCQ 0;
    end else begin
      cq_num_load_val   <= #TCQ cq_num_load_val_d;
      cqn_num_load_val  <= #TCQ cqn_num_load_val_d;
      q_bit_load_val    <= #TCQ q_bit_load_val_d;
    end
  end

  // Indicate when the overall Q0 settings have been determined.
  always @(posedge clk) begin
    if (rst_clk) begin
      det_ovr_done  <= #TCQ 0;
    end else begin
      det_ovr_done  <= #TCQ fe_captured_r;
    end
  end

  // Save the left0 info for the first bit in the memory that indicate if the
  // first bit initially found the left0 edge of the eye and what the tap
  // setting was of that left0 edge.
  always @(posedge clk) begin
    if (rst_clk) begin
      qmem0_start_left0 <= #TCQ 0;
      qmem0_left0_tap   <= #TCQ 0;
    end else if (q_mem_0) begin
      qmem0_start_left0 <= #TCQ invert_clk ? rei_start_left0 : re_start_left0;
      qmem0_left0_tap   <= #TCQ invert_clk ? rei_left0_tap : re_left0_tap;
    end
  end

  // Setting the overall Q0 tap settings is complete once the tap values have
  // been loaded and reset and the data has allowed to settle.
  always @(posedge clk) begin
    if (rst_clk) begin
      set_ovr_st   <= #TCQ 0;
      set_ovr_done <= #TCQ 0;
    end else begin
      set_ovr_st   <= #TCQ (cal_cs == CAL_SET_OVR);
      set_ovr_done <= #TCQ set_ovr_st && load_done && rst_done && polarity_done;
    end
  end

  // }}} end Set Overall Q0 Tap Setting ---------
  

  // {{{ Determine Q_bit Tap Settings -----------
  
  // As additional Q bits are calibrated against following the first bit of the
  // memory, adjustments may be required to all previous bits if more clock
  // delay is needed than had previously been set.
  assign new_cdt_larger = (curr_optimal_tap > cq_tap);

  // Current q bit setting - existing cq setting
  assign curr_minus_cq = curr_optimal_tap - cq_tap;

  // Existing cqn setting + current q bit setting - existing cq setting
  assign cqn_plus_curr_minus_cq = cqn_tap + curr_optimal_tap - cq_tap;

  // Determine if cqn_tap will overflow when existing cqn setting is added to
  // q setting for current bit minus existing cq setting
  assign cqn_tap_overflow = cqn_plus_curr_minus_cq > 6'h1F;

  // cq setting plus q setting for current bit
  //assign cq_plus_curr = cq_tap + curr_optimal_tap;
  assign cq_plus_curr = curr_optimal_tap;

  // Determine if q_tap will overflow when desired q setting plus the existing
  // cq setting are added
  assign q_tap_overflow = cq_plus_curr > 6'h1F;
      
  always @* begin
    casex ({curr_cdt_selected, new_cdt_larger})
      // Current Q calibration requires clock delay larger than what was needed
      // for previously calibrated bits. Data delay must be added to previous
      // bits to account for larger clock delay.
      2'b11 : begin
        prev_q_adj_d    = curr_optimal_tap - cq_tap;
        q_tap_d         = 0;
        cq_tap_d        = curr_optimal_tap;
        cqn_tap_d       = cqn_tap_overflow ? 5'b11111 
                                           : cqn_plus_curr_minus_cq[4:0];
        prev_adj_req_d  = 1;
      end
      // Current Q calibration requires less clock delay that what was needed
      // for previously calibrated bits. Data delay must be added to the
      // current bit to account for larger clock delay.
      2'b10 : begin
        prev_q_adj_d    = 0;
        q_tap_d         = cq_tap - curr_optimal_tap;
        cq_tap_d        = cq_tap;
        cqn_tap_d       = cqn_tap;
        prev_adj_req_d  = 0;
      end
      // Current Q calibration requires data delay only. No other adjustments
      // are required since data delay only affects this bit.
      2'b0?: begin
        prev_q_adj_d    = 0;
        q_tap_d         = q_tap_overflow ? 5'b11111 : cq_plus_curr[4:0];
        cq_tap_d        = cq_tap;
        cqn_tap_d       = cqn_tap;
        prev_adj_req_d  = 0;
      end
      default : begin
        prev_q_adj_d    = 5'hXX;
        q_tap_d         = 5'hXX;
        cq_tap_d        = 5'hXX;
        cqn_tap_d       = 5'hXX;
        prev_adj_req_d  = 1'hX;
      end
    endcase
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      prev_adj_req  <= #TCQ 0;
  end else begin
      prev_adj_req  <= #TCQ prev_adj_req_d;
    end
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      prev_q_adj        <= #TCQ 0;
      cap_prev_adj_req  <= #TCQ 0;
    end else if (capture_adj) begin
      prev_q_adj        <= #TCQ prev_q_adj_d;
      cap_prev_adj_req  <= #TCQ prev_adj_req;
    end
  end

  // For CQ/CQ#, initial values are loaded from values determined during the Q0
  // calibration. After that values from the adjustment logic are used.
  always @(posedge clk) begin
    if (rst_clk) begin
      cq_tap  <= #TCQ MIN_TAPS;
      cqn_tap <= #TCQ MIN_TAPS;
    end else if (load_init) begin
      cq_tap  <= #TCQ cq_num_load_val;
      cqn_tap <= #TCQ cqn_num_load_val;
    end else if (capture_adj) begin
      cq_tap  <= #TCQ cq_tap_d;
      cqn_tap <= #TCQ cqn_tap_d;
    end
  end

  // For Q, initial values are loaded from values determined during the Q0
  // calibration. After that values from the adjustment logic are used.
  always @(posedge clk) begin
    if (rst_clk)
      q_tap  <= #TCQ 0;
    else if (load_init)
      q_tap  <= #TCQ q_bit_load_val;
    else if (capture_adj)
      q_tap  <= #TCQ q_tap_d;
  end

  // Indicate when the current Q tap settings have been determined.
  always @(posedge clk) begin
    if (rst_clk)
      qbit_det_done <= #TCQ 0;
    else
      qbit_det_done <= #TCQ curr_captured;
  end

  // }}} end Determine Q_bit Tap Settings -------

  
  // {{{ Set Q_bit Tap Settings -----------------

  // In the case that only the current Q needs the tap set and no adjustment is
  // needed for previous bits, the step is complete once the tap values have
  // been loaded and reset and the data has allowed to settle.
  always @(posedge clk) begin
    if (rst_clk)
      qbit_set_st <= #TCQ 0;
    else
      qbit_set_st <= #TCQ (cal_cs == CAL_QBIT_SET);
  end
  
  always @(posedge clk) begin
    if (rst_clk)
      qbit_set_done <= #TCQ 0;
    else
      qbit_set_done <= #TCQ qbit_set_st && load_done && rst_done;
  end

  // Otherwise, the previous bits do require adjusting.
  
  // Save the current Q bit being worked on before reseting it to adjust
  // previous bits.
  always @(posedge clk) begin
    if (rst_clk)
      target_q <= #TCQ 0;
    else if (save_target_q)
      target_q <= #TCQ q_bit;
  end

  // Issue an enable to adjust the Q tap setting for previous bits by enabling
  // the increment (asserting clock enable) for the number of cycles needed to
  // adjust. Adjustments are complete once the target Q has been adjusted by
  // the desired number of taps.
  always @(posedge clk) begin
    if (rst_clk) begin
      q_adj_val       <= #TCQ 0;
      q_bit_adj_done  <= #TCQ 0;
    end else if (start_adj) begin
      q_adj_val       <= #TCQ prev_q_adj;
      q_bit_adj_done  <= #TCQ 0;
    end else if (q_adj_val == 0) begin
      q_adj_val       <= #TCQ 0;
      q_bit_adj_done  <= #TCQ 1;
    end else begin
      q_adj_val       <= #TCQ q_adj_val - 1'b1;
      q_bit_adj_done  <= #TCQ 0;
    end
  end

  assign adjust_q = |q_adj_val && (cal_cs == CAL_ADJ);

  // Indicate when all previous bits have been adjusted.
  always @(posedge clk) begin
    if (rst_clk) begin
      all_q_adj <= #TCQ 0;
    end else begin
      all_q_adj <= #TCQ (target_q == q_bit);
    end
  end

  // }}} end Set Q_bit Tap Settings -------------


  // {{{ Phase Alignment ------------------------
  
  // The data from the ISERDES can appear either in order and all in the same
  // cycle OR it can be spread across two cycles with the order out of sync.
  // The behavior depends on how the ISERDES input and output clock align with
  // each other. A phase setting of 0 indicates that no realigning is required
  // while a setting of 1 indicates that realignment is necessary.
  
  // Mux in the data for the current CQ/CQ# data being operated on. This data
  // will be used for checking and setting the data alignment.
  genvar nd_j;
  generate
    for (nd_j=0; nd_j < NUM_DEVICES; nd_j=nd_j+1) begin : nd_cnum_data
      assign cnum_rise_data0[nd_j] = rise_data0_r[(nd_j+1)*MEMORY_WIDTH-1:nd_j*MEMORY_WIDTH];
      assign cnum_fall_data0[nd_j] = fall_data0_r[(nd_j+1)*MEMORY_WIDTH-1:nd_j*MEMORY_WIDTH];
      assign cnum_rise_data1[nd_j] = rise_data1_r[(nd_j+1)*MEMORY_WIDTH-1:nd_j*MEMORY_WIDTH];
      assign cnum_fall_data1[nd_j] = fall_data1_r[(nd_j+1)*MEMORY_WIDTH-1:nd_j*MEMORY_WIDTH];
    end
  endgenerate

  always @(posedge clk) begin
    if (rst_clk) begin
      cnum_rd0 <= #TCQ 0;
      cnum_fd0 <= #TCQ 0;
      cnum_rd1 <= #TCQ 0;
      cnum_fd1 <= #TCQ 0;
    end else begin
      cnum_rd0 <= #TCQ cnum_rise_data0[cq_num];
      cnum_fd0 <= #TCQ cnum_fall_data0[cq_num];
      cnum_rd1 <= #TCQ cnum_rise_data1[cq_num];
      cnum_fd1 <= #TCQ cnum_fall_data1[cq_num];
    end
  end

  // The incoming data stream for any given bit is ideally 01100101 - (first
  // cycle - rd0, fd0, rd1, fd1 followed by second cycle - rd0, fd0, rd1, fd1).
  // If a phase setting of 0 is correct (the inital mode), then the pattern
  // will be 01100101 or 01010110. Either one is valid since the pattern is
  // spread over two cycles and it is unknown which cycle it is sampling on.
  // If a phase setting of 1 is correct, then the pattern will be 01011001 or
  // 10010101.
  genvar mw_i;
  generate
    for (mw_i=0; mw_i < MEMORY_WIDTH; mw_i=mw_i+1) begin : mw_phase_inst
      assign phase0_mw_vld[mw_i] = ((cnum_rd0[mw_i] == 0) && 
                                    (cnum_fd0[mw_i] == 1) && 
                                    (cnum_rd1[mw_i] ^ cnum_fd1[mw_i]));
      assign phase1_mw_vld[mw_i] = ((cnum_rd1[mw_i] == 0) && 
                                    (cnum_fd1[mw_i] == 1) &&
                                    (cnum_rd0[mw_i] ^ cnum_fd0[mw_i]));
    end
  endgenerate

  assign phase0_data_vld0 = &phase0_mw_vld;
  assign phase1_data_vld0 = &phase1_mw_vld;

  // Because of the pattern, one phase will toggle in and out of being valid
  // while the other is constantly valid. Checking that it is valid for two
  // consecutive cycles will ensure that the toggling phase is sample on one
  // of the valid cycles.
  always @(posedge clk) begin
    if (rst_clk) begin
      phase0_data_vld1 <= #TCQ 0;
      phase1_data_vld1 <= #TCQ 0;
    end else begin
      phase0_data_vld1 <= #TCQ phase0_data_vld0;
      phase1_data_vld1 <= #TCQ phase1_data_vld0;
    end
  end

  assign phase0_data_vld = phase0_data_vld0 && phase0_data_vld1;
  assign phase1_data_vld = phase1_data_vld0 && phase1_data_vld1;

  // Indicate which phase setting is correct. If neither are correct across all
  // bits or if both are indicating they are correct, issue an error.
  always @(posedge clk) begin
    if (rst_clk) begin
      phase1_vld  <= #TCQ 0;
      phase0_vld  <= #TCQ 0;
      phase_error <= #TCQ 0;
    end else begin
      phase1_vld  <= #TCQ phase1_data_vld;
      phase0_vld  <= #TCQ phase0_data_vld;
      phase_error <= #TCQ !(phase0_data_vld ^ phase1_data_vld);
    end
  end
  
  genvar nd_i;
  generate
    for (nd_i=0; nd_i < NUM_DEVICES; nd_i=nd_i+1) begin : nd_phase_inst

      // Set the correct phase for the current memory when in the CAL_SET_PHASE.
      // SIM_CAL_OPTION="SKIP_CAL" assumes the same phase setting across all
      // devices.
      always @(posedge clk) begin
        if (rst_clk)
          phase[nd_i] <= #TCQ 0;
        else if ((cal_cs == CAL_SET_PHASE) && ((SIM_CAL_OPTION == "NONE") || 
                 (SIM_CAL_OPTION == "FAST_CAL")) && (cq_num == nd_i) &&
                  data_stable_r)
          phase[nd_i] <= #TCQ phase1_vld;
        else if ((cal_cs == CAL_SET_PHASE) && (SIM_CAL_OPTION == "SKIP_CAL"))
          phase[nd_i] <= #TCQ phase1_vld;    
      end
  
      // Indicate an error when neither phase setting provided valid data.
      always @(posedge clk) begin
        if (rst_clk)
          error_align[nd_i] <= #TCQ 0;
            else if ((cal_cs == CAL_SET_PHASE) && 
                     (SIM_CAL_OPTION == "NONE") && (cq_num == nd_i))
          error_align[nd_i] <= #TCQ phase_error;
            else if ((cal_cs == CAL_SET_PHASE) && 
                     (SIM_CAL_OPTION == "SKIP_CAL"))
          error_align[nd_i] <= #TCQ phase_error;
      end

    end  
  endgenerate
  
  // }}} end Phase Alignment --------------------
  

  // {{{ IDELAY/ISERDES Control -----------------

  // {{{ Target Indicator -------------
  
  // Indicate which CQ/CQ# is currently being worked on.
  always @(posedge clk) begin
    if (rst_clk)
      cq_num <= #TCQ 0;
    else if (inc_cq)
      cq_num <= #TCQ cq_num + 1'b1;
  end

  // Indicate which Q for the entire memory (q_bit) and which Q for a given
  // memory (q_mem) is currently being worked on.
  always @(posedge clk) begin
    if (rst_clk) begin
      q_bit <= #TCQ 0;
      q_mem <= #TCQ 0;
    end else if (clr_q) begin
      q_bit <= #TCQ cq_num * MEMORY_WIDTH;
      q_mem <= #TCQ 0;
    end else if (inc_q && !next_q_grp) begin
      q_bit <= #TCQ q_bit + 1'b1;
      q_mem <= #TCQ (q_mem == MEMORY_WIDTH-1) ? 0 : q_mem + 1'b1;
    end else if (inc_q && next_q_grp) begin
      q_bit <= #TCQ q_bit + MEMORY_WIDTH;
      q_mem <= #TCQ 0;
    end
  end

  // Wait C_NUM_RDY_DLY cycle after cq_num is changed to allow time for it to
  // cross into clk_rd domain before issuing any control to target idelay. It
  // is considered ready when all consequetive c_num_changed bits have passed
  // (i.e. - looks for falling edge out of SRL).
  always @(posedge clk) begin
    c_num_done_tmp <= #TCQ {c_num_done_tmp[C_NUM_RDY_DLY-1:0], inc_cq};
  end

  always @(posedge clk) begin
    if (rst_clk)
      c_num_done_int <= #TCQ 0;
    else
      c_num_done_int <= #TCQ c_num_done_tmp[C_NUM_RDY_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      c_num_done <= #TCQ 0;
    else
      c_num_done <= #TCQ c_num_done_int && !c_num_done_tmp[C_NUM_RDY_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      c_num_rdy <= #TCQ 1;
    else if (inc_cq)
      c_num_rdy <= #TCQ 0;
    else if (c_num_done)
      c_num_rdy <= #TCQ 1;
  end
  
  // Wait Q_BIT_RDY_DLY cycle after q_bit is changed to allow time for it to
  // cross into clk_rd domain before issuing any control to target idelay. It
  // is considered ready when all consequetive q_bit_changed bits have passed
  // (i.e. - looks for falling edge out of SRL).
  assign q_bit_changed = clr_q || inc_q_d;

  always @(posedge clk) begin
    q_bit_done_tmp <= #TCQ {q_bit_done_tmp[Q_BIT_RDY_DLY-1:0], q_bit_changed};
  end

  always @(posedge clk) begin
    if (rst_clk)
      q_bit_done_int <= #TCQ 0;
    else
      q_bit_done_int <= #TCQ q_bit_done_tmp[Q_BIT_RDY_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      q_bit_done <= #TCQ 0;
    else
      q_bit_done <= #TCQ q_bit_done_int && !q_bit_done_tmp[Q_BIT_RDY_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      q_bit_rdy <= #TCQ 1;
    else if (q_bit_changed)
      q_bit_rdy <= #TCQ 0;
    else if (q_bit_done)
      q_bit_rdy <= #TCQ 1;
  end
  
  // }}} end Target Indicator ---------


  // {{{ IDELAY CE Control ------------

  // The calibration logic currently only increments taps.
  assign cq_num_inc   = 1;
  assign cqn_num_inc  = 1;
  assign q_bit_inc    = 1;
  
  // CQ/CQ# tap inc control. The taps are incremented each cycle that ce is
  // asserted for current cq_num (target CQ/CQ#). It is incremented during the
  // tap centering state machine in order to find the edges.
  always @(posedge clk) begin
    if (rst_clk)
      cq_num_ce   <= #TCQ 0;
    else if (ctr_c_dly_st)
      cq_num_ce   <= #TCQ en_rise_tap || en_fall_tap;
    else
      cq_num_ce   <= #TCQ 0;
  end

  always @(posedge clk) begin
    if (rst_clk)
      cqn_num_ce   <= #TCQ 0;
    else if (ctr_c_dly_st && MEMORY_TYPE == "RLD2" )
      cqn_num_ce   <= #TCQ en_rise_tap; 
    else if (ctr_c_dly_st)
      cqn_num_ce   <= #TCQ en_fall_tap || en_rise_tap;
    else
      cqn_num_ce   <= #TCQ 0;
  end

  // Q tap inc control. The taps are incremented each cycle that ce is asserted
  // for current q_bit (target Q). It is incremented during the tap centering
  // state machine in order to find the left edge from within the target window
  // and during the adjustment process in the overall calibration flow.
  always @(posedge clk) begin
    if (rst_clk)
      q_bit_ce  <= #TCQ 0;
    else if (ctr_q_dly_st)
      q_bit_ce  <= #TCQ en_tap_adj;
    else if (adjust_q)
      q_bit_ce  <= #TCQ 1;
    else
      q_bit_ce  <= #TCQ 0;
  end
  
  // Wait TAP_DLY cycles after a tap has been adjusted (ce asserted) to allow
  // time for the control to pass into the clk_rd domain and for the update to
  // take place. Done is deasserted as soon as the reset is issued and then
  // isn't released until the final delayed rst has propogated through the
  // shift chain.

  // cq ce done
  always @(posedge clk) begin
    cq_tap_done_tmp <= #TCQ {cq_tap_done_tmp[TAP_DLY-1:0], cq_num_ce};
  end

  always @(posedge clk) begin
    if (rst_clk)
      cq_tap_done_int <= #TCQ 0;
    else
      cq_tap_done_int <= #TCQ cq_tap_done_tmp[TAP_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      cq_tap_done <= #TCQ 1;
    else if (cq_num_ce)
      cq_tap_done <= #TCQ 0;
    else if (cq_tap_done_int)
      cq_tap_done <= #TCQ 1;
  end  

  // cq# ce done
  always @(posedge clk) begin
    cqn_tap_done_tmp <= #TCQ {cqn_tap_done_tmp[TAP_DLY-1:0], cqn_num_ce};
  end

  always @(posedge clk) begin
    if (rst_clk)
      cqn_tap_done_int <= #TCQ 0;
    else
      cqn_tap_done_int <= #TCQ cqn_tap_done_tmp[TAP_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      cqn_tap_done <= #TCQ 1;
    else if (cqn_num_ce)
      cqn_tap_done <= #TCQ 0;
    else if (cqn_tap_done_int)
      cqn_tap_done <= #TCQ 1;
  end  

  // q ce done
  always @(posedge clk) begin
    q_tap_done_tmp <= #TCQ {q_tap_done_tmp[TAP_DLY-1:0], q_bit_ce};
  end

  always @(posedge clk) begin
    if (rst_clk)
      q_tap_done_int <= #TCQ 0;
    else
      q_tap_done_int <= #TCQ q_tap_done_tmp[TAP_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      q_tap_done <= #TCQ 1;
    else if (q_bit_ce)
      q_tap_done <= #TCQ 0;
    else if (q_tap_done_int)
      q_tap_done <= #TCQ 1;
  end  
  
  assign tap_done = cq_tap_done && cqn_tap_done && q_tap_done;
  
  // }}} end IDLEAY CE Control --------
  

  // {{{ Load Control -----------------

  // Wait LOAD_DLYto allow time for the
  // load data to  cycles after load_c/q has been issued uing the rst to     
  // actually loadcross into the clk_rd domain before iss                    
  //                 the value into the IODELAY.                               
  // load_c
  always @(posedge clk) begin
    load_c_tmp <= #TCQ {load_c_tmp[LOAD_DLY-1:0], issue_load_c};
  end

  always @(posedge clk) begin
    if (rst_clk)
      load_c <= #TCQ 0;
    else
      load_c <= #TCQ load_c_tmp[LOAD_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      load_c_fall <= #TCQ 0;
    else
      load_c_fall <= #TCQ load_c && !load_c_tmp[LOAD_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      load_c_done <= #TCQ 1;
    else if (issue_load_c)
      load_c_done <= #TCQ 0;
    else if (load_c_fall)
      load_c_done <= #TCQ 1;
  end

  // load_q
  always @(posedge clk) begin
    if (rst_clk)
      load_q_changed <= #TCQ 0;
    else
      load_q_changed <= #TCQ issue_load_q;
  end

  always @(posedge clk) begin
    load_q_tmp <= #TCQ {load_q_tmp[LOAD_DLY-1:0], load_q_changed};
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      load_q <= #TCQ 0;
    end else begin
      load_q <= #TCQ load_q_tmp[LOAD_DLY];
    end
  end

  always @(posedge clk) begin
    if (rst_clk)
      load_q_fall <= #TCQ 0;
    else
      load_q_fall <= #TCQ load_q && !load_q_tmp[LOAD_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      load_q_done <= #TCQ 1;
    else if (issue_load_q)
      load_q_done <= #TCQ 0;
    else if (load_q_fall)
      load_q_done <= #TCQ 1;
  end

  assign load_done = load_c_done && load_q_done;

  // }}} end Load Control -------------


  // {{{ IDELAY RST Control -----------
  
  // Upon reset, the IDELAY tap is set to the load value. The taps can be reset
  // to a default value or loaded with a target value. When loaded with a
  // target value, the load value must be allowed time to cross into the clk_rd
  // domain before the reset is issued.

  // cq rst
  
   // cq rst
  always @(posedge clk) begin
    if (rst_clk) begin
      cq_num_rst  <= #TCQ 1;
      cq_num_load <= #TCQ MIN_TAPS;
    end else if (issue_cdt_rst || issue_dly_rst) begin
      cq_num_rst  <= #TCQ 1;
      cq_num_load <= #TCQ MIN_TAPS;
    end else if (load_c) begin
      cq_num_rst  <= #TCQ 1;
      cq_num_load <= #TCQ cq_tap;
    end else begin
      cq_num_rst  <= #TCQ 0;
      cq_num_load <= #TCQ cq_tap;
    end
  end
  
 //cq# rst
  always @(posedge clk) begin
    if (rst_clk) begin
      cqn_num_rst  <= #TCQ 1;
      cqn_num_load <= #TCQ MIN_TAPS;
    end else if (issue_cdt_rst || issue_dly_rst ) begin
      cqn_num_rst  <= #TCQ 1;
      cqn_num_load <= #TCQ MIN_TAPS;
    end else if (load_c && MEMORY_TYPE == "RLD2" ) begin
      cqn_num_rst  <= #TCQ 1;
      cqn_num_load <= #TCQ cq_tap;
    end else if (load_c && MEMORY_TYPE == "QDR" ) begin
      cqn_num_rst  <= #TCQ 1;
      cqn_num_load <= #TCQ cqn_tap;
    end else if (MEMORY_TYPE == "QDR" )begin
      cqn_num_rst  <= #TCQ 0;
      cqn_num_load <= #TCQ cqn_tap;
    end else if (MEMORY_TYPE == "RLD2" ) begin
      cqn_num_rst  <= #TCQ 0;
      cqn_num_load <= #TCQ cq_tap;
    end
  end
              
 
  // q rst
  always @(posedge clk) begin
    if (rst_clk) begin
      q_bit_rst  <= #TCQ 1;
      q_bit_load <= #TCQ 0;
    end else if (issue_dly_rst) begin
      q_bit_rst  <= #TCQ 1;
      q_bit_load <= #TCQ 0;
    end else if (load_q) begin
      q_bit_rst  <= #TCQ 1;
      q_bit_load <= #TCQ q_tap;
    end else begin
      q_bit_rst  <= #TCQ 0;
      q_bit_load <= #TCQ q_tap;
    end
  end
  
  // Wait RST_DLY cycles after the resets have been issued to allow time for
  // the control to pass into the clk_rd domain and for the update to take
  // place. Done is deasserted as soon as the reset is issued and then isn't
  // released until the final delayed rst has propogated through the shift
  // chain.
  
  // cq/cq# rst done
  assign cq_rst_changed = issue_cdt_rst || issue_dly_rst || load_c;
  
  always @(posedge clk) begin
    cq_rst_done_tmp <= #TCQ {cq_rst_done_tmp[RST_DLY-1:0], cq_rst_changed};
  end

  always @(posedge clk) begin
    if (rst_clk)
      cq_rst_done_int <= #TCQ 0;
    else
      cq_rst_done_int <= #TCQ cq_rst_done_tmp[RST_DLY];
  end

  // Keep track of the outstanding resets in the shift register
  always @(posedge clk) begin
    if (rst_clk)
      outstanding_cq_rst <= #TCQ 0;
    else if (cq_rst_changed && !cq_rst_done_int)
      outstanding_cq_rst <= #TCQ outstanding_cq_rst + 1'b1;
    else if (cq_rst_done_int && !cq_rst_changed)
      outstanding_cq_rst <= #TCQ outstanding_cq_rst - 1'b1;
  end

  // Wait to signal that the reset is done until all resets leave the shift
  // register
  always @(posedge clk) begin
    if (rst_clk)
      cq_rst_done <= #TCQ 1;
    else if (cq_rst_changed)
      cq_rst_done <= #TCQ 0;
    else if (outstanding_cq_rst == 0)
      cq_rst_done <= #TCQ 1;
  end  

  // q rst done
  assign q_rst_changed = issue_dly_rst || load_q;

  always @(posedge clk) begin
    q_rst_done_tmp <= #TCQ {q_rst_done_tmp[RST_DLY-1:0], q_rst_changed};
  end

  always @(posedge clk) begin
    if (rst_clk)
      q_rst_done_int <= #TCQ 0;
    else
      q_rst_done_int <= #TCQ q_rst_done_tmp[RST_DLY];
  end

  // Keep track of the outstanding resets in the shift register
  always @(posedge clk) begin
    if (rst_clk)
      outstanding_q_rst <= #TCQ 0;
    else if (q_rst_changed && !q_rst_done_int)
      outstanding_q_rst <= #TCQ outstanding_q_rst + 1'b1;
    else if (q_rst_done_int && !q_rst_changed)
      outstanding_q_rst <= #TCQ outstanding_q_rst - 1'b1;
  end

  // Wait to signal that the reset is done until all resets leave the shift
  // register
  always @(posedge clk) begin
    if (rst_clk)
      q_rst_done <= #TCQ 1;
    else if (q_rst_changed)
      q_rst_done <= #TCQ 0;
    else if (outstanding_q_rst == 0)
      q_rst_done <= #TCQ 1;
  end  

  assign rst_done = cq_rst_done && q_rst_done;

  // }}} end IDELAY RST Control --------------


  // {{{ ISERDES Clock Control --------

  // Delay clearing the clock invert signal by a few cycles to allow time for
  // changes / updates to take affect before reseting it.
  always @(posedge clk) begin
    if (rst_clk) begin
      clear_clk_invert_r  <= #TCQ 0;
      clear_clk_invert_2r <= #TCQ 0;
      clear_clk_invert_3r <= #TCQ 0;
    end else begin
      clear_clk_invert_r  <= #TCQ clear_clk_invert;
      clear_clk_invert_2r <= #TCQ clear_clk_invert_r;
      clear_clk_invert_3r <= #TCQ clear_clk_invert_2r;
    end
  end

  // Set ISERDES clk/clkb clock polarity. It can be forced to use the inverted
  // clock or can be selected to use the chosen clock inversion.
  always @(posedge clk) begin
    if (rst_clk)
      q_bit_clkinv <= #TCQ 0;
    else if (force_clk_invert)
      q_bit_clkinv <= #TCQ 1;
    else if (set_clk_polarity)
      q_bit_clkinv <= #TCQ invert_clk;
    else if (clear_clk_invert_3r)
      q_bit_clkinv <= #TCQ 0;
  end

  // Wait POL_DLY cycles after the ISERDES clk/clkb polarity has been changed
  // to allow time for the control to pass into the clk_rd domain and for the
  // update to take place.
  assign polarity_changed = force_clk_invert || set_clk_polarity || clear_clk_invert;
  
  always @(posedge clk) begin
    polarity_done_tmp <= #TCQ {polarity_done_tmp[POL_DLY-1:0], polarity_changed};
  end

  always @(posedge clk) begin
    if (rst_clk)
      polarity_done_int <= #TCQ 0;
    else
      polarity_done_int <= #TCQ polarity_done_tmp[POL_DLY];
  end

  always @(posedge clk) begin
    if (rst_clk)
      polarity_done <= #TCQ 1;
    else if (polarity_changed)
      polarity_done <= #TCQ 0;
    else if (polarity_done_int)
      polarity_done <= #TCQ 1;
  end  

  // }}} end ISERDES Clock Control ----
  
  // }}} end IDELAY/ISERDES Control -------------
  
endmodule
