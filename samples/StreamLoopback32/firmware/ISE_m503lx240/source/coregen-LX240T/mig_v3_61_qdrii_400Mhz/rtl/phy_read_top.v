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
//  /   /         Filename           : phy_read_top.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:57 $
// \   \  /  \    Date Created       : Nov 17, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//  This module
//  1. Instantiates all the read path submodules
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_read_top #
(
  parameter BURST_LEN           = 4,              // 4 = Burst Length 4, 2 = Burst Length 2
  parameter DATA_WIDTH          = 72,             // Total data width across all memories
  parameter NUM_DEVICES         = 2,              // Number of memory devices
  parameter FIXED_LATENCY_MODE  = 0,              // 0 = minimum latency mode, 1 = fixed latency mode
  parameter PHY_LATENCY         = 16,             // Indicates the desired latency for fixed latency mode
  parameter CLK_PERIOD          = 1876,           // Indicates the number of picoseconds for one CLK period
  parameter REFCLK_FREQ         = 300.0,          // Indicates the IDELAYCTRL reference clock frequency
  parameter DEVICE_TAPS         = 32,             // Number of taps in target IODELAY
  parameter TAP_BITS            = 5,              // Number of bits needed to represent DEVICE_TAPS
  parameter MEMORY_WIDTH        = 36,             // Width of each memory
  parameter PHASE_DETECT        = "OFF",          // Enable Phase detector
  parameter IODELAY_GRP         = "IODELAY_MIG",  // May be assigned unique name when mult IP cores in design
  parameter SIM_CAL_OPTION      = "NONE",         // Skip various calibration steps - "NONE, "FAST_CAL", "SKIP_CAL"
  parameter SIM_INIT_OPTION     = "NONE",        //Simulation only. "NONE", "SIM_MODE"
  parameter MEM_TYPE            = "QDR2PLUS",     // Memory Type (QDR2PLUS, QDR2)
  parameter CQ_BITS             = 1,              //clog2(NUM_DEVICES - 1)   
  parameter Q_BITS              = 7,              //clog2(DATA_WIDTH - 1)  
  parameter DEBUG_PORT          = "ON",           // Debug using Chipscope controls 
  parameter TCQ                 = 100             // Register delay
)
(
  // System Signals
  input                           clk,              // main system half freq clk
  input       [NUM_DEVICES-1:0]   clk_rd,           // half freq CQ clock
  input                           rst_clk,          // main read path reset sync to clk
  input       [NUM_DEVICES-1:0]   rst_clk_rd,       // reset syncrhonized to clk_rd
  input                           clk_wr,

  // I/O Interface
  output wire [NUM_DEVICES-1:0]          cq_dly_ce,     // CQ IDELAY clock enable
  output wire [NUM_DEVICES-1:0]          cq_dly_inc,    // CQ IDELAY increment
  output wire [NUM_DEVICES-1:0]          cq_dly_rst,    // CQ IDELAY reset
  output wire [TAP_BITS*NUM_DEVICES-1:0] cq_dly_load,   // CQ IDELAY cntvaluein load value
  output wire [NUM_DEVICES-1:0]          cqn_dly_ce,    // CQ# IDELAY clock enable
  output wire [NUM_DEVICES-1:0]          cqn_dly_inc,   // CQ# IDELAY increment
  output wire [NUM_DEVICES-1:0]          cqn_dly_rst,   // CQ# IDELAY reset
  output wire [TAP_BITS*NUM_DEVICES-1:0] cqn_dly_load,  // CQ# IDELAY cntvaluein load value
  output wire [DATA_WIDTH-1:0]           q_dly_ce,      // Q IDELAY clock enable
  output wire [NUM_DEVICES-1:0]          q_dly_inc,     // Q IDELAY increment
  output wire [DATA_WIDTH-1:0]           q_dly_rst,     // Q IDELAY reset
  output wire [TAP_BITS*NUM_DEVICES-1:0] q_dly_load,    // Q IDELAY cntvaluein load value
  output wire [NUM_DEVICES-1:0]          q_dly_clkinv,  // Q IDELAY CLK inversion
  output wire [NUM_DEVICES-1:0]          iserdes_rst,   // ISERDES reset
  input       [DATA_WIDTH-1:0]           iserdes_rd0,   // ISERDES Q4 output - rise data 0
  input       [DATA_WIDTH-1:0]           iserdes_fd0,   // ISERDES Q3 output - fall data 0
  input       [DATA_WIDTH-1:0]           iserdes_rd1,   // ISERDES Q2 output - rise data 1
  input       [DATA_WIDTH-1:0]           iserdes_fd1,   // ISERDES Q1 output - fall data 1

  // User Interface
  output wire                     cal_done,         // calibration done
  output wire [DATA_WIDTH*2-1:0]  rd_data0,         // user read data 0
  output wire [DATA_WIDTH*2-1:0]  rd_data1,         // user read data 1
  output wire                     rd_valid0,        // user read data 0 valid
  output wire                     rd_valid1,        // user read data 1 valid

  // Write Path Interface
  input                           init_done,        // initialization complete
  output wire                     cal_stage1_start, // stage 1 calibration start
  output wire                     cal_stage2_start, // stage 2 calibration start
  input  wire  [1:0]              int_rd_cmd_n,     // internal rd cmd

  // Phase Detector Interface
  input [NUM_DEVICES-1:0]         clk_cq,           // CQ BUFIO clock
  input [NUM_DEVICES-1:0]         clk_cqn,          // CQ# BUFIO clock
  input [NUM_DEVICES-1:0]         pd_source,        // RLDRAM II PD Source 
  input                           clk_mem,          // Full frequency clock
  input                           rst_wr_clk,       // Reset write path reset

  //ChipScope Debug Signals
  input                           dbg_inc_cq_all,         // increment all CQs
  input                           dbg_inc_cqn_all,        // increment all CQ#s
  input                           dbg_inc_q_all,          // increment all Qs
  input                           dbg_dec_cq_all,         // decrement all CQs   
  input                           dbg_dec_cqn_all,        // decrement all CQ#s 
  input                           dbg_dec_q_all,          // decrement all Qs   
  input                           dbg_inc_cq,             // increment selected CQ  
  input                           dbg_inc_cqn,            // increment selected CQ#
  input                           dbg_inc_q,              // increment selected Q  
  input                           dbg_dec_cq,             // decrement selected CQ  
  input                           dbg_dec_cqn,            // decrement selected CQ# 
  input                           dbg_dec_q,              // decrement selected Q   
  input [CQ_BITS-1:0]             dbg_sel_cq,             // selected CQ bit
  input [CQ_BITS-1:0]             dbg_sel_cqn,            // selected CQ# bit
  input [Q_BITS-1:0]              dbg_sel_q,              // selected Q bit
  input                           dbg_pd_off,
  output wire [255:0]             dbg_rd_stage1_cal,      // stage 1 cal debug
  output wire [127:0]             dbg_stage2_cal,         // stage 2 cal debug
  output wire [CQ_BITS-1:0]       dbg_cq_num,             // current cq/cq# being calibrated
  output wire [Q_BITS-1:0]        dbg_q_bit,              // current q being calibrated 
  output wire [4:0]               dbg_valid_lat,          // latency of the system
  output wire [NUM_DEVICES-1:0]   dbg_phase,              // data align phase indication
  output wire [NUM_DEVICES-1:0]   dbg_inc_latency,        // increase latency for dcb
  output wire [5*NUM_DEVICES-1:0] dbg_dcb_wr_ptr,         // dcb write pointers
  output wire [5*NUM_DEVICES-1:0] dbg_dcb_rd_ptr,         // dcb read pointers
  output wire [4*DATA_WIDTH-1:0]  dbg_dcb_din,            // dcb data in
  output wire [4*DATA_WIDTH-1:0]  dbg_dcb_dout,           // dcb data out
  output wire [NUM_DEVICES-1:0]   dbg_error_max_latency,  // stage 2 cal max latency error
  output wire                     dbg_error_adj_latency,  // stage 2 cal latency adjustment error  
  output wire [NUM_DEVICES-1:0]   dbg_pd_calib_start,     // indicates phase detector to start
  output wire [NUM_DEVICES-1:0]   dbg_pd_calib_done,      // indicates phase detector is complete
  output wire [DATA_WIDTH-1:0]    dbg_align_rd0,
  output wire [DATA_WIDTH-1:0]    dbg_align_fd0,
  output wire [DATA_WIDTH-1:0]    dbg_align_rd1,
  output wire [DATA_WIDTH-1:0]    dbg_align_fd1
);

  // Local parameters
  localparam integer TAPS_RESERVED    = (PHASE_DETECT == "ON") ? 3 : 1;  // Number of taps to reserve for RTC
  localparam integer IODELAY_TAP_RES  = 1000000 / (REFCLK_FREQ * 64); // IDELAY tap resolution in ps
  localparam integer MEM_PERIOD       = CLK_PERIOD/2;                 // External memory frequence is 2x internal
  localparam integer CENTER_TAP       = (((MEM_PERIOD / 4) / IODELAY_TAP_RES) > 31) ? 31 :
                                         ((MEM_PERIOD / 4) / IODELAY_TAP_RES);  // Number of taps to "ideal" center, limit to 31
  localparam integer MIN_TAPS         = TAPS_RESERVED;                          // minimum usuable clock tap setting
  localparam integer MAX_TAPS         = DEVICE_TAPS - TAPS_RESERVED ;        // maximum usable clock tap setting

  // Wires and Regs
  wire [DATA_WIDTH-1:0]           dcb_rd0;
  wire [DATA_WIDTH-1:0]           dcb_fd0;
  wire [DATA_WIDTH-1:0]           dcb_rd1;
  wire [DATA_WIDTH-1:0]           dcb_fd1;
  wire [NUM_DEVICES-1:0]          phase_clk; 
  wire [CQ_BITS-1:0]              cq_num_active_clk;
  wire [Q_BITS-1:0]               q_bit_active_clk;
  wire [TAP_BITS-1:0]             cq_num_load_clk;
  wire [TAP_BITS-1:0]             cqn_num_load_clk;
  wire [TAP_BITS-1:0]             q_bit_load_clk;
  wire                            cq_num_rst_clk;
  wire                            cq_num_ce_clk;
  wire                            cq_num_inc_clk;
  wire                            cqn_num_rst_clk;
  wire                            cqn_num_ce_clk;
  wire                            cqn_num_inc_clk;
  wire                            q_bit_rst_clk;
  wire                            q_bit_ce_clk;
  wire                            q_bit_inc_clk;
  wire                            q_bit_clkinv_clk;
  wire [NUM_DEVICES-1:0]          error_align;
  wire [4*DATA_WIDTH-1:0]         read_data;
  wire [NUM_DEVICES-1:0]          inc_latency;
  wire [4:0]                      valid_latency;
  wire [NUM_DEVICES-1:0]          error_max_latency;
  wire                            error_adj_latency;
  wire [DATA_WIDTH-1:0]           align_rd0;
  wire [DATA_WIDTH-1:0]           align_fd0;
  wire [DATA_WIDTH-1:0]           align_rd1;
  wire [DATA_WIDTH-1:0]           align_fd1;
  wire [NUM_DEVICES-1:0]          phase;
  wire [CQ_BITS*NUM_DEVICES-1:0]  cq_num_active;
  wire [Q_BITS*NUM_DEVICES-1:0]   q_bit_active;
  wire [TAP_BITS*NUM_DEVICES-1:0] cq_num_load;
  wire [TAP_BITS*NUM_DEVICES-1:0] cqn_num_load;
  wire [TAP_BITS*NUM_DEVICES-1:0] q_bit_load;
  wire [NUM_DEVICES-1:0]          cq_num_rst;
  wire [NUM_DEVICES-1:0]          cq_num_ce;
  wire [NUM_DEVICES-1:0]          cq_num_inc;
  wire [NUM_DEVICES-1:0]          cqn_num_rst;
  wire [NUM_DEVICES-1:0]          cqn_num_ce;
  wire [NUM_DEVICES-1:0]          cqn_num_inc;
  wire [NUM_DEVICES-1:0]          q_bit_rst;
  wire [NUM_DEVICES-1:0]          q_bit_ce;
  wire [NUM_DEVICES-1:0]          q_bit_inc;
  wire [NUM_DEVICES-1:0]          q_bit_clkinv;
  wire [NUM_DEVICES-1:0]          pd_calib_done_clk;
  wire                            cal_stage2_done_clk;
  wire [NUM_DEVICES-1:0]          cal_stage1_done;
  wire [NUM_DEVICES-1:0]          cal_stage2_done;
  wire [NUM_DEVICES-1:0]          pd_en_maintain;
  wire [NUM_DEVICES-1:0]          pd_calib_done;
  wire [NUM_DEVICES-1:0]          pd_incdec_maintain;
  wire [NUM_DEVICES-1:0]          pd_calib_error;
  wire [Q_BITS*NUM_DEVICES-1:0]   dbg_sel_q_clkrd;
  wire [CQ_BITS*NUM_DEVICES-1:0]  dbg_sel_cq_clkrd;
  wire [CQ_BITS*NUM_DEVICES-1:0]  dbg_sel_cqn_clkrd;  
  wire [NUM_DEVICES-1:0]          dbg_inc_q_clkrd;    
  wire [NUM_DEVICES-1:0]          dbg_dec_q_clkrd;
  wire [NUM_DEVICES-1:0]          dbg_inc_cq_clkrd;    
  wire [NUM_DEVICES-1:0]          dbg_dec_cq_clkrd;
  wire [NUM_DEVICES-1:0]          dbg_inc_cqn_clkrd;    
  wire [NUM_DEVICES-1:0]          dbg_dec_cqn_clkrd;    
  wire [NUM_DEVICES-1:0]          dbg_inc_q_all_clkrd;
  wire [NUM_DEVICES-1:0]          dbg_dec_q_all_clkrd;
  wire [NUM_DEVICES-1:0]          dbg_inc_cq_all_clkrd;
  wire [NUM_DEVICES-1:0]          dbg_dec_cq_all_clkrd;
  wire [NUM_DEVICES-1:0]          dbg_inc_cqn_all_clkrd;
  wire [NUM_DEVICES-1:0]          dbg_dec_cqn_all_clkrd;
   reg [3:0]    rst_delayed = 0;
   reg          wc;
   
  
  always @ (posedge clk) 
    begin
      rst_delayed[0] <=#TCQ rst_wr_clk;
      rst_delayed[1] <=#TCQ rst_delayed[0];
      rst_delayed[2] <=#TCQ rst_delayed[1];
      rst_delayed[3] <=#TCQ rst_delayed[2];
    end
  
  //set the wc bit as input to the OSERDES 3 cycles after reset is released
  //pulse again after OCB monitor is complete
  always @ (posedge clk)
    begin
      wc <=#TCQ (rst_delayed[3] & ~rst_delayed[2]);
    end  

   

  assign rd_data0   = {dcb_rd0, dcb_fd0};
  assign rd_data1   = {dcb_rd1, dcb_fd1};
  assign read_data  = {rd_data0, rd_data1};
  
  //debug signals
  assign dbg_align_rd0 = align_rd0;
  assign dbg_align_fd0 = align_fd0;
  assign dbg_align_rd1 = align_rd1;
  assign dbg_align_fd1 = align_fd1;

  // Instantiate valid generator logic that retimes the valids for the out
  // going data.
  phy_read_vld_gen #(   
    .BURST_LEN    (BURST_LEN),
    .TCQ          (TCQ)    
  ) u_phy_read_vld_gen (
    .clk            (clk),
    .rst_clk        (rst_clk),
    .int_rd_cmd_n   (int_rd_cmd_n),
    .valid_latency  (valid_latency),
    .cal_done       (cal_done),
    .data_valid0    (rd_valid0),
    .data_valid1    (rd_valid1),
    .dbg_valid_lat  (dbg_valid_lat)
  );
  
  // Instantiate the stage 1 calibration which performs delay calibration in
  // order to center align the clock and data. It also performs realignment
  // calibration.
  phy_read_stage1_cal #(
    .DATA_WIDTH       (DATA_WIDTH),
    .NUM_DEVICES      (NUM_DEVICES),
    .MEMORY_WIDTH     (MEMORY_WIDTH),
    .DEVICE_TAPS      (DEVICE_TAPS),
    .TAP_BITS         (TAP_BITS),
    .IODELAY_TAP_RES  (IODELAY_TAP_RES),
    .CENTER_TAP       (CENTER_TAP),
    .MIN_TAPS         (MIN_TAPS),
    .MAX_TAPS         (MAX_TAPS),
    .CQ_BITS          (CQ_BITS),
    .Q_BITS           (Q_BITS),
    .MEM_TYPE         (MEM_TYPE),
    .SIM_CAL_OPTION   (SIM_CAL_OPTION),
    .TCQ              (TCQ)    
  ) u_phy_read_stage1_cal (
    .clk              (clk),
    .rst_clk          (rst_clk),
    .init_done        (init_done),
    .cal_stage1_start (cal_stage1_start),
    .cal_stage2_start (cal_stage2_start),
    .rise_data0       (dcb_rd0),
    .fall_data0       (dcb_fd0),
    .rise_data1       (dcb_rd1),
    .fall_data1       (dcb_fd1),
    .phase            (phase_clk),
    .cq_num           (cq_num_active_clk),
    .q_bit            (q_bit_active_clk),
    .cq_num_load      (cq_num_load_clk),
    .cqn_num_load     (cqn_num_load_clk),
    .q_bit_load       (q_bit_load_clk),
    .cq_num_rst       (cq_num_rst_clk),
    .cq_num_ce        (cq_num_ce_clk),
    .cq_num_inc       (cq_num_inc_clk),
    .cqn_num_rst      (cqn_num_rst_clk),
    .cqn_num_ce       (cqn_num_ce_clk),
    .cqn_num_inc      (cqn_num_inc_clk),
    .q_bit_rst        (q_bit_rst_clk),
    .q_bit_ce         (q_bit_ce_clk),
    .q_bit_inc        (q_bit_inc_clk),
    .q_bit_clkinv     (q_bit_clkinv_clk),
    .error_align      (error_align),
    .dbg_rd_stage1_cal(dbg_rd_stage1_cal)
  );
  
  // Instantiate the stage 2 calibration logic which resolves latencies in the
  // system and calibrates the valids.
  phy_read_stage2_cal #(
    .BURST_LEN          (BURST_LEN),
    .DATA_WIDTH         (DATA_WIDTH),
    .NUM_DEVICES        (NUM_DEVICES),
    .MEMORY_WIDTH       (MEMORY_WIDTH),
    .FIXED_LATENCY_MODE (FIXED_LATENCY_MODE),
    .PHY_LATENCY        (PHY_LATENCY),
    .TCQ                (TCQ)    
  ) u_phy_read_stage2_cal (
    .clk                (clk),
    .rst_clk            (rst_clk),
    .cal_stage2_start   (cal_stage2_start),
    .int_rd_cmd_n       (int_rd_cmd_n),
    .read_data          (read_data),
    .inc_latency        (inc_latency),
    .valid_latency      (valid_latency),
    .cal_done           (cal_done),
    .pd_calib_done      (pd_calib_done_clk),
    .cal_stage2_done    (cal_stage2_done_clk),
    .error_max_latency  (error_max_latency),
    .error_adj_latency  (error_adj_latency),
    .dbg_stage2_cal     (dbg_stage2_cal)
  );
  
  genvar nd_i;
  generate
    for (nd_i=0; nd_i < NUM_DEVICES; nd_i=nd_i+1) begin : nd_io_inst

      // Instantiate the data align logic which realigns the data from the
      // ISERDES as needed.
      phy_read_data_align #(
        .MEMORY_WIDTH (MEMORY_WIDTH),
        .TCQ          (TCQ)    
      ) u_phy_read_data_align (
        .clk_rd       (clk_rd[nd_i]),
        .rst_clk_rd   (rst_clk_rd[nd_i]),
        .iserdes_rd0  (iserdes_rd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .iserdes_fd0  (iserdes_fd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .iserdes_rd1  (iserdes_rd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .iserdes_fd1  (iserdes_fd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .rise_data0   (align_rd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .fall_data0   (align_fd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .rise_data1   (align_rd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .fall_data1   (align_fd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .phase        (phase[nd_i]),
        .dbg_phase    (dbg_phase[nd_i])
      );

      // Instantiate the data circular buffer which is used to cross incoming
      // read data from the clk_rd domains into the main clk domain. It is also
      // used to adjust latencies.
      phy_read_dcb #(
        .MEMORY_WIDTH (MEMORY_WIDTH),
        .TCQ          (TCQ)    
      ) u_phy_read_dcb (
        .clk_rd         (clk_rd[nd_i]),
        .rst_clk_rd     (rst_clk_rd[nd_i]),
        .clk            (clk),
        .rst_clk        (rst_clk),
        .cq_dly_rst     (cq_dly_rst[nd_i]),
        .din_rd0        (align_rd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .din_fd0        (align_fd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .din_rd1        (align_rd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .din_fd1        (align_fd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .dout_rd0       (dcb_rd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .dout_fd0       (dcb_fd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .dout_rd1       (dcb_rd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .dout_fd1       (dcb_fd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .inc_latency    (inc_latency[nd_i]),
        .dbg_dcb_wr_ptr (dbg_dcb_wr_ptr[(nd_i*5)+:5]),
        .dbg_dcb_rd_ptr (dbg_dcb_rd_ptr[(nd_i*5)+:5]),
        .dbg_dcb_din    (dbg_dcb_din[(nd_i*4*MEMORY_WIDTH)+:4*MEMORY_WIDTH]),
        .dbg_dcb_dout   (dbg_dcb_dout[(nd_i*4*MEMORY_WIDTH)+:4*MEMORY_WIDTH])
      );
      
      // Instantiate the synchronization logic which syncs IODELAY/ISERDES
      // control from the clk domain into the rd_clk domain.
      phy_read_sync #(
        .TAP_BITS (TAP_BITS),
        .CQ_BITS  (CQ_BITS),
        .Q_BITS   (Q_BITS),
        .DEVICE_ID (nd_i),
        .DEBUG_PORT (DEBUG_PORT),
        .TCQ      (TCQ)
      ) u_phy_read_sync (
        .clk                  (clk),
        .rst_clk              (rst_clk),
        .cq_num_active_clk    (cq_num_active_clk),
        .q_bit_active_clk     (q_bit_active_clk),
        .cq_num_load_clk      (cq_num_load_clk),
        .cqn_num_load_clk     (cqn_num_load_clk),
        .q_bit_load_clk       (q_bit_load_clk),
        .cq_num_rst_clk       (cq_num_rst_clk),
        .cq_num_ce_clk        (cq_num_ce_clk),
        .cq_num_inc_clk       (cq_num_inc_clk),
        .cqn_num_rst_clk      (cqn_num_rst_clk),
        .cqn_num_ce_clk       (cqn_num_ce_clk),
        .cqn_num_inc_clk      (cqn_num_inc_clk),
        .q_bit_rst_clk        (q_bit_rst_clk),
        .q_bit_ce_clk         (q_bit_ce_clk),
        .q_bit_inc_clk        (q_bit_inc_clk),
        .q_bit_clkinv_clk     (q_bit_clkinv_clk),
        .phase_clk            (phase_clk[nd_i]),
        .cal_stage1_done_clk  (cal_stage2_start),
        .cal_stage2_done_clk  (cal_stage2_done_clk),
        .pd_calib_done_clk_r  (pd_calib_done_clk[nd_i]),
        .clk_rd               (clk_rd[nd_i]),
        .rst_clk_rd           (rst_clk_rd[nd_i]),
        .cq_num_active        (cq_num_active[CQ_BITS*(nd_i+1)-1:CQ_BITS*nd_i]),
        .q_bit_active         (q_bit_active[Q_BITS*(nd_i+1)-1:Q_BITS*nd_i]),
        .cq_num_load          (cq_num_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .cqn_num_load         (cqn_num_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .q_bit_load           (q_bit_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .cq_num_rst           (cq_num_rst[nd_i]),
        .cq_num_ce            (cq_num_ce[nd_i]),
        .cq_num_inc           (cq_num_inc[nd_i]),
        .cqn_num_rst          (cqn_num_rst[nd_i]),
        .cqn_num_ce           (cqn_num_ce[nd_i]),
        .cqn_num_inc          (cqn_num_inc[nd_i]),
        .q_bit_rst            (q_bit_rst[nd_i]),
        .q_bit_ce             (q_bit_ce[nd_i]),
        .q_bit_inc            (q_bit_inc[nd_i]),
        .q_bit_clkinv         (q_bit_clkinv[nd_i]),
        .phase                (phase[nd_i]),
        .cal_stage1_done      (cal_stage1_done[nd_i]),
        .cal_stage2_done      (cal_stage2_done[nd_i]),
        .pd_calib_done        (pd_calib_done[nd_i]),
        //Debug signals in clk domain      
        .dbg_inc_cq_all       (dbg_inc_cq_all),    
        .dbg_inc_cqn_all      (dbg_inc_cqn_all),   
        .dbg_inc_q_all        (dbg_inc_q_all),     
        .dbg_dec_cq_all       (dbg_dec_cq_all),    
        .dbg_dec_cqn_all      (dbg_dec_cqn_all),   
        .dbg_dec_q_all        (dbg_dec_q_all),     
        .dbg_inc_cq           (dbg_inc_cq),        
        .dbg_inc_cqn          (dbg_inc_cqn),       
        .dbg_inc_q            (dbg_inc_q),         
        .dbg_dec_cq           (dbg_dec_cq),        
        .dbg_dec_cqn          (dbg_dec_cqn),       
        .dbg_dec_q            (dbg_dec_q),         
        .dbg_sel_cq           (dbg_sel_cq),        
        .dbg_sel_cqn          (dbg_sel_cqn),       
        .dbg_sel_q            (dbg_sel_q),
        //Debug signals in clk_rd domain
        .dbg_sel_q_clkrd      (dbg_sel_q_clkrd[Q_BITS*(nd_i+1)-1:Q_BITS*nd_i]),
        .dbg_sel_cq_clkrd     (dbg_sel_cq_clkrd[CQ_BITS*(nd_i+1)-1:CQ_BITS*nd_i]),
        .dbg_sel_cqn_clkrd    (dbg_sel_cqn_clkrd[CQ_BITS*(nd_i+1)-1:CQ_BITS*nd_i]),
        .dbg_inc_q_clkrd      (dbg_inc_q_clkrd[nd_i]),   
        .dbg_dec_q_clkrd      (dbg_dec_q_clkrd[nd_i]),
        .dbg_inc_cq_clkrd     (dbg_inc_cq_clkrd[nd_i]),   
        .dbg_dec_cq_clkrd     (dbg_dec_cq_clkrd[nd_i]),
        .dbg_inc_cqn_clkrd    (dbg_inc_cqn_clkrd[nd_i]),   
        .dbg_dec_cqn_clkrd    (dbg_dec_cqn_clkrd[nd_i]),   
        .dbg_inc_q_all_clkrd  (dbg_inc_q_all_clkrd[nd_i]),
        .dbg_dec_q_all_clkrd  (dbg_dec_q_all_clkrd[nd_i]),
        .dbg_inc_cq_all_clkrd (dbg_inc_cq_all_clkrd[nd_i]),  
        .dbg_dec_cq_all_clkrd (dbg_dec_cq_all_clkrd[nd_i]),
        .dbg_inc_cqn_all_clkrd(dbg_inc_cqn_all_clkrd[nd_i]),  
        .dbg_dec_cqn_all_clkrd(dbg_dec_cqn_all_clkrd[nd_i])
        
      );
        
      // Instantiate the IODELAY control logic which replicates the control 
      // for the target I/O.
      phy_read_dly_ctrl #(
        .MEMORY_WIDTH         (MEMORY_WIDTH),
        .NUM_DEVICES          (NUM_DEVICES),
        .DEVICE_ID            (nd_i),
        .MIN_TAPS             (MIN_TAPS),
        .MAX_TAPS             (MAX_TAPS),
        .TAP_BITS             (TAP_BITS),
        .CQ_BITS              (CQ_BITS),
        .Q_BITS               (Q_BITS),
        .DEBUG_PORT           (DEBUG_PORT),
        .SIM_CAL_OPTION       (SIM_CAL_OPTION),
        .MEM_TYPE             (MEM_TYPE),
        .TCQ                  (TCQ)
      ) u_phy_read_dly_ctrl (
        .clk_rd               (clk_rd[nd_i]),
        .rst_clk_rd           (rst_clk_rd[nd_i]),
        .cq_num_active        (cq_num_active[CQ_BITS*(nd_i+1)-1:CQ_BITS*nd_i]),
        .q_bit_active         (q_bit_active[Q_BITS*(nd_i+1)-1:Q_BITS*nd_i]),
        .cq_num_load          (cq_num_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .cqn_num_load         (cqn_num_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .q_bit_load           (q_bit_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .cq_num_rst           (cq_num_rst[nd_i]),
        .cq_num_ce            (cq_num_ce[nd_i]),
        .cq_num_inc           (cq_num_inc[nd_i]),
        .cqn_num_rst          (cqn_num_rst[nd_i]),
        .cqn_num_ce           (cqn_num_ce[nd_i]),
        .cqn_num_inc          (cqn_num_inc[nd_i]),
        .q_bit_rst            (q_bit_rst[nd_i]),
        .q_bit_ce             (q_bit_ce[nd_i]),
        .q_bit_inc            (q_bit_inc[nd_i]),
        .q_bit_clkinv         (q_bit_clkinv[nd_i]),
        .cal_stage1_done      (cal_stage1_done[nd_i]),
        .cal_stage2_done      (cal_stage2_done[nd_i]),
        .pd_en_maintain       (pd_en_maintain[nd_i]),
        .pd_incdec_maintain   (pd_incdec_maintain[nd_i]),
        .dbg_sel_q_clkrd      (dbg_sel_q_clkrd[Q_BITS*(nd_i+1)-1:Q_BITS*nd_i]),
        .dbg_sel_cq_clkrd     (dbg_sel_cq_clkrd[CQ_BITS*(nd_i+1)-1:CQ_BITS*nd_i]),
        .dbg_sel_cqn_clkrd    (dbg_sel_cqn_clkrd[CQ_BITS*(nd_i+1)-1:CQ_BITS*nd_i]),    
        .dbg_inc_q_clkrd      (dbg_inc_q_clkrd[nd_i]),
        .dbg_dec_q_clkrd      (dbg_dec_q_clkrd[nd_i]),
        .dbg_inc_cq_clkrd     (dbg_inc_cq_clkrd[nd_i]),
        .dbg_dec_cq_clkrd     (dbg_dec_cq_clkrd[nd_i]),
        .dbg_inc_cqn_clkrd    (dbg_inc_cqn_clkrd[nd_i]),
        .dbg_dec_cqn_clkrd    (dbg_dec_cqn_clkrd[nd_i]),
        .dbg_inc_q_all_clkrd  (dbg_inc_q_all_clkrd[nd_i]),
        .dbg_dec_q_all_clkrd  (dbg_dec_q_all_clkrd[nd_i]),
        .dbg_inc_cq_all_clkrd (dbg_inc_cq_all_clkrd[nd_i]),  
        .dbg_dec_cq_all_clkrd (dbg_dec_cq_all_clkrd[nd_i]),
        .dbg_inc_cqn_all_clkrd(dbg_inc_cqn_all_clkrd[nd_i]),  
        .dbg_dec_cqn_all_clkrd(dbg_dec_cqn_all_clkrd[nd_i]),
        .cq_dly_ce            (cq_dly_ce[nd_i]),
        .cq_dly_inc           (cq_dly_inc[nd_i]),
        .cq_dly_rst           (cq_dly_rst[nd_i]),
        .cq_dly_load          (cq_dly_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .cqn_dly_ce           (cqn_dly_ce[nd_i]),
        .cqn_dly_inc          (cqn_dly_inc[nd_i]),
        .cqn_dly_rst          (cqn_dly_rst[nd_i]),
        .cqn_dly_load         (cqn_dly_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .q_dly_ce             (q_dly_ce[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .q_dly_inc            (q_dly_inc[nd_i]),
        .q_dly_rst            (q_dly_rst[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .q_dly_load           (q_dly_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .q_dly_clkinv         (q_dly_clkinv[nd_i]),
        .iserdes_rst          (iserdes_rst[nd_i])
      );

      // Instantiate the Phase Detector which corrects changes in BUFIO/BUFR delays
      // as a result of V/T. Do not generate when SIM_CAL_OPTION == "SKIP_CAL".
      if (PHASE_DETECT == "ON" && SIM_CAL_OPTION != "SKIP_CAL") begin : gen_enable_pd
        qdr_rld_phy_pd #(
          .CLK_PERIOD      (CLK_PERIOD),
          .REFCLK_FREQ     (REFCLK_FREQ),
          .IODELAY_GRP     (IODELAY_GRP),
          .MEM_TYPE        (MEM_TYPE),
          .MIN_TAPS        (MIN_TAPS),
          .TCQ             (TCQ),
          .SIM_CAL_OPTION  (SIM_CAL_OPTION),
          .SIM_INIT_OPTION (SIM_INIT_OPTION) 
          ) u_qdr_rld_phy_pd (
          .pd_en_maintain     (pd_en_maintain[nd_i]),
          .pd_calib_done      (pd_calib_done[nd_i]),
          .pd_incdec_maintain (pd_incdec_maintain[nd_i]),
          .pd_calib_error     (pd_calib_error[nd_i]),
          .pd_calib_start     (cal_stage2_done[nd_i]),
          .clk_cq             (clk_cq[nd_i]),
          .clk_cqn            (clk_cqn[nd_i]),
          .clk_rd             (clk_rd[nd_i]),
          .clk                (clk),
          .clk_mem            (clk_mem),
	  .clk_wr             (clk_wr),
	  .wc                 (wc),
          .dbg_pd_off         (dbg_pd_off),
          .rst_clk_rd         (rst_clk_rd[nd_i]),
          .rst_wr_clk         (rst_wr_clk),
          .pd_source          (pd_source[nd_i])
        );
      end else begin : gen_disable_pd_tie_off
        assign pd_en_maintain[nd_i]     = 1'b0;
        assign pd_calib_done[nd_i]      = 1'b1;
        assign pd_incdec_maintain[nd_i] = 1'b0;
      end
    end

  endgenerate
 
  // Debug signals
  assign dbg_inc_latency       = inc_latency;
  assign dbg_error_max_latency = error_max_latency;
  assign dbg_error_adj_latency = error_adj_latency;
  assign dbg_cq_num            = cq_num_active_clk;
  assign dbg_q_bit             = q_bit_active_clk;
  assign dbg_pd_calib_start    = cal_stage2_done_clk;
  assign dbg_pd_calib_done     = pd_calib_done_clk;
  assign dbg_pd_calib_error    = pd_calib_error;

endmodule
