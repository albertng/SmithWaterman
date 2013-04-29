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
//  /   /         Filename           : phy_read_sync.v
// /___/   /\     Date Last Modified : $date$   
// \   \  /  \    Date Created       : Nov 18, 2008 
//  \___\/\___\   
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//  This module
//  1. Resynchronizes IODELAY controls from stage 1 calibration in the clk domain
//     to the IODELAYs in the clk_rd domains.
//  2. Resynchronizes control for phase detectors between stage 2 calibration in
//     clk domain and the remaining logic in the clk_rd domains.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_read_sync #
(
  parameter TAP_BITS    = 5,  // Number of bits needed to represent DEVICE_TAPS
  parameter CQ_BITS     = 1,  // Number of bits needed to represent number of cq/cq#'s
  parameter Q_BITS      = 7,  // Number of bits needed to represent number of q's
  parameter DEVICE_ID   = 0,  // Indicates memory device instance
  parameter DEBUG_PORT  = "ON", // Debug using Chipscope controls
  parameter TCQ         = 100 // Register delay
)
(
  // clk Interface
  input                     clk,                  // main system half freq clk
  input                     rst_clk,              // reset syncrhonized to clk
  input [CQ_BITS-1:0]       cq_num_active_clk,    // indicates which CQ/CQ# the control is for
  input [Q_BITS-1:0]        q_bit_active_clk,     // indictes which Q the control is for
  input [TAP_BITS-1:0]      cq_num_load_clk,      // iodelay load value for CQ
  input [TAP_BITS-1:0]      cqn_num_load_clk,     // iodelay load value for CQ#
  input [TAP_BITS-1:0]      q_bit_load_clk,       // iodelay load value for Q
  input                     cq_num_rst_clk,       // iodelay rst control for CQ
  input                     cq_num_ce_clk,        // iodelay ce control for CQ
  input                     cq_num_inc_clk,       // iodelay inc control for CQ
  input                     cqn_num_rst_clk,      // iodelay rst control for CQ#
  input                     cqn_num_ce_clk,       // iodelay ce control for CQ#
  input                     cqn_num_inc_clk,      // iodelay inc control for CQ#
  input                     q_bit_rst_clk,        // iodelay rst for Q
  input                     q_bit_ce_clk,         // iodelay ce for Q
  input                     q_bit_inc_clk,        // iodelay inc for Q
  input                     q_bit_clkinv_clk,     // invert clk/clkb inputs of iserdes
  input                     phase_clk,            // phase indicator
  input                     cal_stage1_done_clk,  // stage 2 calibration complete
  input                     cal_stage2_done_clk,  // stage 2 calibration complete
  output reg                pd_calib_done_clk_r,  // phase detector calibration done
  
  // clk_rd Interface
  input                     clk_rd,             // half freq CQ clock
  input                     rst_clk_rd,         // reset syncrhonized to clk_rd
  output reg [CQ_BITS-1:0]  cq_num_active,      // indicates which CQ/CQ# the control is for
  (* max_fanout = "8" *)
  output reg [Q_BITS-1:0]   q_bit_active,       // indictes which Q the control is for
  output reg [TAP_BITS-1:0] cq_num_load,        // iodelay load value for CQ
  output reg [TAP_BITS-1:0] cqn_num_load,       // iodelay load value for CQ#
  output reg [TAP_BITS-1:0] q_bit_load,         // iodelay load value for Q
  output reg                cq_num_rst,         // iodelay rst control for CQ
  output reg                cq_num_ce,          // iodelay ce control for CQ
  output reg                cq_num_inc,         // iodelay inc control for CQ
  output reg                cqn_num_rst,        // iodelay rst control for CQ#
  output reg                cqn_num_ce,         // iodelay ce control for CQ#
  output reg                cqn_num_inc,        // iodelay inc control for CQ#
  output reg                q_bit_rst,          // iodelay rst for Q
  output reg                q_bit_ce,           // iodelay ce for Q
  output reg                q_bit_inc,          // iodelay inc for Q
  output reg                q_bit_clkinv,       // invert clk/clkb inputs of iserdes
  output reg                phase,              // phase indicator
  output reg                cal_stage1_done,    // stage 2 calibration complete
  output reg                cal_stage2_done,    // stage 2 calibration complete
  input                     pd_calib_done,       // phase detector calibration complete
  
  // debug signals  
  input                     dbg_inc_cq_all,    // increment all CQs
  input                     dbg_inc_cqn_all,   // increment all CQ#s
  input                     dbg_inc_q_all,     // increment all Qs
  input                     dbg_dec_cq_all,    // decrement all CQs   
  input                     dbg_dec_cqn_all,   // decrement all CQ#s 
  input                     dbg_dec_q_all,     // decrement all Qs   
  input                     dbg_inc_cq,        // increment selected CQ  
  input                     dbg_inc_cqn,       // increment selected CQ#
  input                     dbg_inc_q,         // increment selected Q  
  input                     dbg_dec_cq,        // decrement selected CQ  
  input                     dbg_dec_cqn,       // decrement selected CQ# 
  input                     dbg_dec_q,         // decrement selected Q   
  input [CQ_BITS-1:0]       dbg_sel_cq,        // selected CQ bit
  input [CQ_BITS-1:0]       dbg_sel_cqn,       // selected CQ# bit
  input [Q_BITS-1:0]        dbg_sel_q,         // selected Q bit
  output reg  [Q_BITS-1:0]  dbg_sel_q_clkrd,
  output reg  [CQ_BITS-1:0] dbg_sel_cq_clkrd,
  output reg  [CQ_BITS-1:0] dbg_sel_cqn_clkrd,
  output reg                dbg_inc_q_clkrd,
  output reg                dbg_dec_q_clkrd,
  output reg                dbg_inc_cq_clkrd,    
  output reg                dbg_dec_cq_clkrd,
  output reg                dbg_inc_cqn_clkrd,
  output reg                dbg_dec_cqn_clkrd,
  output reg                dbg_inc_q_all_clkrd,
  output reg                dbg_dec_q_all_clkrd,
  output reg                dbg_inc_cq_all_clkrd,
  output reg                dbg_dec_cq_all_clkrd,
  output reg                dbg_inc_cqn_all_clkrd,
  output reg                dbg_dec_cqn_all_clkrd
);

  reg   [Q_BITS-1:0]  q_bit_active_clk_r;
  reg   [CQ_BITS-1:0] cq_num_active_clk_r;
  reg                 q_bit_changed;
  reg                 cq_num_changed;
  wire                wr_en;
  reg                 rd_en;
  wire                fifo_empty;
  wire  [35:0]        fifo_wr_data;
  wire  [35:0]        fifo_rd_data;
  wire  [4:0]         q_bit_load_int;
  wire  [4:0]         cqn_num_load_int;
  wire  [4:0]         cq_num_load_int;
  wire                q_bit_inc_int;
  wire                q_bit_ce_int;
  wire                q_bit_rst_int;
  wire                cqn_num_inc_int;
  wire                cqn_num_ce_int;
  wire                cqn_num_rst_int;
  wire                cq_num_inc_int;
  wire                cq_num_ce_int;
  wire                cq_num_rst_int;
  wire  [Q_BITS-1:0]  q_bit_active_int;
  wire  [CQ_BITS-1:0] cq_num_active_int;
  reg                 q_bit_clkinv_clk_r;
                      (* ASYNC_REG = "TRUE" *)
  reg                 q_bit_clkinv_clkrd_r;
  reg                 q_bit_clkinv_int;  
  reg                 phase_clk_r;
                      (* ASYNC_REG = "TRUE" *)
  reg                 phase_clkrd_r;
  reg                 cal_stage1_done_clk_r;
                      (* ASYNC_REG = "TRUE" *)
  reg                 cal_stage1_done_clkrd_r;
  reg                 cal_stage2_done_clk_r;
                      (* ASYNC_REG = "TRUE" *)
  reg                 cal_stage2_done_clkrd_r;
  reg                 q_bit_clkinv_int_r;
  reg                 q_bit_clkinv_int_2r;
  reg                 pd_calib_done_clkrd_r;
                      (* ASYNC_REG = "TRUE" *)
  reg                 pd_calib_done_clk; 
  reg                 dbg_inc_cq_all_r;  
  reg                 dbg_inc_cqn_all_r; 
  reg                 dbg_inc_q_all_r;   
  reg                 dbg_dec_cq_all_r;  
  reg                 dbg_dec_cqn_all_r; 
  reg                 dbg_dec_q_all_r;   
  reg                 dbg_inc_cq_r;      
  reg                 dbg_inc_cqn_r;     
  reg                 dbg_inc_q_r;       
  reg                 dbg_dec_cq_r;      
  reg                 dbg_dec_cqn_r;     
  reg                 dbg_dec_q_r;       
  reg   [CQ_BITS-1:0] dbg_sel_cq_r;
  reg   [CQ_BITS-1:0] dbg_sel_cqn_r;  
  reg   [Q_BITS-1:0]  dbg_sel_q_r;
  reg                 dbg_inc_cq_all_2r; 
  reg                 dbg_inc_cqn_all_2r;
  reg                 dbg_inc_q_all_2r;  
  reg                 dbg_dec_cq_all_2r; 
  reg                 dbg_dec_cqn_all_2r;
  reg                 dbg_dec_q_all_2r;
  reg                 dbg_inc_cq_2r;
  reg                 dbg_inc_cqn_2r;
  reg                 dbg_inc_q_2r;
  reg                 dbg_dec_cq_2r;     
  reg                 dbg_dec_cqn_2r;
  reg                 dbg_dec_q_2r;
  reg  [CQ_BITS-1:0]  dbg_sel_cq_2r;     
  reg  [CQ_BITS-1:0]  dbg_sel_cqn_2r;
  reg  [Q_BITS-1:0]   dbg_sel_q_2r; 
  wire [Q_BITS-1:0]   dbg_sel_q_clk_r;
  wire [CQ_BITS-1:0]  dbg_sel_cq_clk_r;
  wire [CQ_BITS-1:0]  dbg_sel_cqn_clk_r;
  wire                dbg_inc_q_clk_r;
  wire                dbg_dec_q_clk_r;
  wire                dbg_inc_cq_clk_r;
  wire                dbg_dec_cq_clk_r;
  wire                dbg_inc_cqn_clk_r;
  wire                dbg_dec_cqn_clk_r;
  wire                dbg_inc_q_all_clk_r;
  wire                dbg_dec_q_all_clk_r;
  wire                dbg_inc_cq_all_clk_r;
  wire                dbg_dec_cqn_all_clk_r;  
  reg [Q_BITS-1:0]    dbg_sel_q_clkrd_r;
  reg [CQ_BITS-1:0]   dbg_sel_cq_clkrd_r;
  reg [CQ_BITS-1:0]   dbg_sel_cqn_clkrd_r;   
  reg                 dbg_inc_q_clkrd_r;    
  reg                 dbg_dec_q_clkrd_r;
  reg                 dbg_inc_cq_clkrd_r;    
  reg                 dbg_dec_cq_clkrd_r;
  reg                 dbg_inc_cqn_clkrd_r;    
  reg                 dbg_dec_cqn_clkrd_r;      
  reg                 dbg_inc_q_all_clkrd_r;
  reg                 dbg_dec_q_all_clkrd_r;
  reg                 dbg_inc_cq_all_clkrd_r;
  reg                 dbg_dec_cq_all_clkrd_r;
  reg                 dbg_inc_cqn_all_clkrd_r;
  reg                 dbg_dec_cqn_all_clkrd_r;

  // Indicate when q_bit and cq_num have changed so that it can be
  // used to trigger a write enable to the FIFO.
  always @(posedge clk) begin
    if (rst_clk) begin
      q_bit_active_clk_r  <= #TCQ 0;
      cq_num_active_clk_r <= #TCQ 0;
    end else begin
      q_bit_active_clk_r  <= #TCQ q_bit_active_clk;
      cq_num_active_clk_r <= #TCQ cq_num_active_clk;
    end
  end

  always @(posedge clk) begin
    if (rst_clk) begin
      q_bit_changed   <= #TCQ 0;
      cq_num_changed  <= #TCQ 0;
    end else begin
      q_bit_changed   <= #TCQ (q_bit_active_clk != q_bit_active_clk_r);    
      cq_num_changed  <= #TCQ (cq_num_active_clk != cq_num_active_clk_r);
    end
  end

  // Only write to the FIFO when active control is present
  assign wr_en = (cq_num_rst_clk || cq_num_ce_clk ||
                 cqn_num_rst_clk || cqn_num_ce_clk ||
                 q_bit_rst_clk || q_bit_ce_clk ||
                 q_bit_changed || cq_num_changed) && !rst_clk;

  assign fifo_wr_data = {cq_num_active_clk, //[24+Q_BITS+:CQ_BITS]
                         q_bit_active_clk,  //[24+:Q_BITS]
                         cq_num_rst_clk,    //[23]
                         cq_num_ce_clk,     //[22]
                         cq_num_inc_clk,    //[21]
                         cqn_num_rst_clk,   //[20]
                         cqn_num_ce_clk,    //[19]
                         cqn_num_inc_clk,   //[18]
                         q_bit_rst_clk,     //[17]
                         q_bit_ce_clk,      //[16]
                         q_bit_inc_clk,     //[15]
                         cq_num_load_clk,   //[14:10]
                         cqn_num_load_clk,  //[9:5]
                         q_bit_load_clk};   //[4:0]

  // Cross clock domains through async FIFO to avoid losing pulses
  FIFO18E1 #(
    .DATA_WIDTH(36),
    .DO_REG(1),
    .EN_SYN("FALSE"),
    .FIFO_MODE("FIFO18_36"),
    .FIRST_WORD_FALL_THROUGH("FALSE")
  ) u_read_sync_afifo (
    .DI           (fifo_wr_data[31:0]),
    .DIP          (fifo_wr_data[35:32]),
    .RDCLK        (clk_rd),
    .RDEN         (!fifo_empty),
    .REGCE        (1'b1),
    .RST          (rst_clk),
    .RSTREG       (1'b0),
    .WRCLK        (clk),
    .WREN         (wr_en),
    .ALMOSTEMPTY  (),
    .ALMOSTFULL   (),
    .DO           (fifo_rd_data[31:0]),
    .DOP          (fifo_rd_data[35:32]),
    .EMPTY        (fifo_empty),
    .FULL         (),
    .RDCOUNT      (),
    .RDERR        (),
    .WRCOUNT      (),
    .WRERR        ()
  );

  // Only read from FIFO when there is something to read (not empty)
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      rd_en   <= #TCQ 0;
    end else begin
      rd_en   <= #TCQ !fifo_empty;
    end
  end

  assign q_bit_load_int     = fifo_rd_data[4:0];
  assign cqn_num_load_int   = fifo_rd_data[9:5];
  assign cq_num_load_int    = fifo_rd_data[14:10];
  assign q_bit_inc_int      = fifo_rd_data[15];
  assign q_bit_ce_int       = fifo_rd_data[16];
  assign q_bit_rst_int      = fifo_rd_data[17];
  assign cqn_num_inc_int    = fifo_rd_data[18];
  assign cqn_num_ce_int     = fifo_rd_data[19];
  assign cqn_num_rst_int    = fifo_rd_data[20];
  assign cq_num_inc_int     = fifo_rd_data[21];
  assign cq_num_ce_int      = fifo_rd_data[22];
  assign cq_num_rst_int     = fifo_rd_data[23];
  assign q_bit_active_int   = fifo_rd_data[24+:Q_BITS];
  assign cq_num_active_int  = fifo_rd_data[(24+Q_BITS)+:CQ_BITS];
    
  // Only assign control from the fifo outputs when there is valid data
  // present in the fifo. Otherwise, tie off to zero to prevent invalid
  // active control from being assigned.
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      q_bit_load    <= #TCQ 0;
      cqn_num_load  <= #TCQ 0;
      cq_num_load   <= #TCQ 0;
      q_bit_inc     <= #TCQ 0;
      q_bit_ce      <= #TCQ 0;
      q_bit_rst     <= #TCQ 0;
      cqn_num_inc   <= #TCQ 0;
      cqn_num_ce    <= #TCQ 0;
      cqn_num_rst   <= #TCQ 0;
      cq_num_inc    <= #TCQ 0;
      cq_num_ce     <= #TCQ 0;
      cq_num_rst    <= #TCQ 0;
      q_bit_active  <= #TCQ 0;
      cq_num_active <= #TCQ 0;
    end else begin
      q_bit_load    <= #TCQ q_bit_load_int;
      cqn_num_load  <= #TCQ cqn_num_load_int;
      cq_num_load   <= #TCQ cq_num_load_int;
      q_bit_inc     <= #TCQ q_bit_inc_int;
      q_bit_ce      <= #TCQ rd_en ? q_bit_ce_int : 0;
      q_bit_rst     <= #TCQ rd_en ? q_bit_rst_int : 0;
      cqn_num_inc   <= #TCQ cqn_num_inc_int;
      cqn_num_ce    <= #TCQ rd_en ? cqn_num_ce_int : 0;
      cqn_num_rst   <= #TCQ rd_en ? cqn_num_rst_int : 0;
      cq_num_inc    <= #TCQ cq_num_inc_int;
      cq_num_ce     <= #TCQ rd_en ? cq_num_ce_int : 0;
      cq_num_rst    <= #TCQ rd_en ? cq_num_rst_int : 0;
      q_bit_active  <= #TCQ q_bit_active_int;
      cq_num_active <= #TCQ cq_num_active_int;
    end
  end

  // register vio signals into clk domain
  always @ (posedge clk) begin
    if (rst_clk) begin
      dbg_inc_cq_all_r  <= #TCQ 0;    
      dbg_inc_cqn_all_r <= #TCQ 0;  
      dbg_inc_q_all_r   <= #TCQ 0;
      dbg_dec_cq_all_r  <= #TCQ 0;  
      dbg_dec_cqn_all_r <= #TCQ 0;  
      dbg_dec_q_all_r   <= #TCQ 0;  
      dbg_inc_cq_r      <= #TCQ 0;  
      dbg_inc_cqn_r     <= #TCQ 0;  
      dbg_inc_q_r       <= #TCQ 0;  
      dbg_dec_cq_r      <= #TCQ 0;  
      dbg_dec_cqn_r     <= #TCQ 0;  
      dbg_dec_q_r       <= #TCQ 0;  
      dbg_sel_cq_r      <= #TCQ 0;  
      dbg_sel_cqn_r     <= #TCQ 0;  
      dbg_sel_q_r       <= #TCQ 0;   
      dbg_inc_cq_all_2r  <= #TCQ 0;    
      dbg_inc_cqn_all_2r <= #TCQ 0;  
      dbg_inc_q_all_2r   <= #TCQ 0;
      dbg_dec_cq_all_2r  <= #TCQ 0;  
      dbg_dec_cqn_all_2r <= #TCQ 0;  
      dbg_dec_q_all_2r   <= #TCQ 0;  
      dbg_inc_cq_2r      <= #TCQ 0;  
      dbg_inc_cqn_2r     <= #TCQ 0;  
      dbg_inc_q_2r       <= #TCQ 0;  
      dbg_dec_cq_2r      <= #TCQ 0;  
      dbg_dec_cqn_2r     <= #TCQ 0;  
      dbg_dec_q_2r       <= #TCQ 0;  
      dbg_sel_cq_2r      <= #TCQ 0;  
      dbg_sel_cqn_2r     <= #TCQ 0;  
      dbg_sel_q_2r       <= #TCQ 0; 
    end else begin
      dbg_inc_cq_all_r   <= #TCQ dbg_inc_cq_all;    
      dbg_inc_cqn_all_r  <= #TCQ dbg_inc_cqn_all;  
      dbg_inc_q_all_r    <= #TCQ dbg_inc_q_all;
      dbg_dec_cq_all_r   <= #TCQ dbg_dec_cq_all;  
      dbg_dec_cqn_all_r  <= #TCQ dbg_dec_cqn_all;  
      dbg_dec_q_all_r    <= #TCQ dbg_dec_q_all;  
      dbg_inc_cq_r       <= #TCQ dbg_inc_cq;  
      dbg_inc_cqn_r      <= #TCQ dbg_inc_cqn;  
      dbg_inc_q_r        <= #TCQ dbg_inc_q;  
      dbg_dec_cq_r       <= #TCQ dbg_dec_cq;  
      dbg_dec_cqn_r      <= #TCQ dbg_dec_cqn;  
      dbg_dec_q_r        <= #TCQ dbg_dec_q;  
      dbg_sel_cq_r       <= #TCQ dbg_sel_cq;  
      dbg_sel_cqn_r      <= #TCQ dbg_sel_cqn;  
      dbg_sel_q_r        <= #TCQ dbg_sel_q;   
      dbg_inc_cq_all_2r  <= #TCQ dbg_inc_cq_all_r;    
      dbg_inc_cqn_all_2r <= #TCQ dbg_inc_cqn_all_r;  
      dbg_inc_q_all_2r   <= #TCQ dbg_inc_q_all_r;
      dbg_dec_cq_all_2r  <= #TCQ dbg_dec_cq_all_r;  
      dbg_dec_cqn_all_2r <= #TCQ dbg_dec_cqn_all_r;  
      dbg_dec_q_all_2r   <= #TCQ dbg_dec_q_all_r;  
      dbg_inc_cq_2r      <= #TCQ dbg_inc_cq_r;  
      dbg_inc_cqn_2r     <= #TCQ dbg_inc_cqn_r;  
      dbg_inc_q_2r       <= #TCQ dbg_inc_q_r;  
      dbg_dec_cq_2r      <= #TCQ dbg_dec_cq_r;  
      dbg_dec_cqn_2r     <= #TCQ dbg_dec_cqn_r;  
      dbg_dec_q_2r       <= #TCQ dbg_dec_q_r;  
      dbg_sel_cq_2r      <= #TCQ dbg_sel_cq_r;  
      dbg_sel_cqn_2r     <= #TCQ dbg_sel_cqn_r;  
      dbg_sel_q_2r       <= #TCQ dbg_sel_q_r; 
    end   
  end

  // Synchronize signals going from clk domain to clk_rd domain

  // First register all signals in the clk domain
  always @(posedge clk) begin
    if (rst_clk) begin
      q_bit_clkinv_clk_r    <= #TCQ 0;
      phase_clk_r           <= #TCQ 0;
      cal_stage1_done_clk_r <= #TCQ 0;
      cal_stage2_done_clk_r <= #TCQ 0;
    end else begin
      q_bit_clkinv_clk_r    <= #TCQ q_bit_clkinv_clk;
      phase_clk_r           <= #TCQ phase_clk;
      cal_stage1_done_clk_r <= #TCQ cal_stage1_done_clk;
      cal_stage2_done_clk_r <= #TCQ cal_stage2_done_clk;
    end
  end

  assign dbg_sel_q_clk_r       = (DEBUG_PORT == "ON") ? dbg_sel_q_2r : 'b0;
  assign dbg_sel_cq_clk_r      = (DEBUG_PORT == "ON") ? dbg_sel_cq_2r : 'b0;
  assign dbg_sel_cqn_clk_r     = (DEBUG_PORT == "ON") ? dbg_sel_cqn_2r : 'b0;
  assign dbg_inc_q_clk_r       = (DEBUG_PORT == "ON") ? dbg_inc_q_2r : 'b0;
  assign dbg_dec_q_clk_r       = (DEBUG_PORT == "ON") ? dbg_dec_q_2r : 'b0;
  assign dbg_inc_cq_clk_r      = (DEBUG_PORT == "ON") ? dbg_inc_cq_2r : 'b0;
  assign dbg_dec_cq_clk_r      = (DEBUG_PORT == "ON") ? dbg_dec_cq_2r : 'b0;
  assign dbg_inc_cqn_clk_r     = (DEBUG_PORT == "ON") ? dbg_inc_cqn_2r : 'b0;
  assign dbg_dec_cqn_clk_r     = (DEBUG_PORT == "ON") ? dbg_dec_cqn_2r : 'b0;
  assign dbg_inc_q_all_clk_r   = (DEBUG_PORT == "ON") ? dbg_inc_q_all_2r : 'b0;
  assign dbg_dec_q_all_clk_r   = (DEBUG_PORT == "ON") ? dbg_dec_q_all_2r : 'b0;
  assign dbg_inc_cq_all_clk_r  = (DEBUG_PORT == "ON") ? dbg_inc_cq_all_2r : 'b0;
  assign dbg_dec_cq_all_clk_r  = (DEBUG_PORT == "ON") ? dbg_dec_cq_all_2r : 'b0;
  assign dbg_inc_cqn_all_clk_r = (DEBUG_PORT == "ON") ? dbg_inc_cqn_all_2r : 'b0;
  assign dbg_dec_cqn_all_clk_r = (DEBUG_PORT == "ON") ? dbg_dec_cqn_all_2r : 'b0;
  
  // Now double register each signal into the clk_rd domain
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      q_bit_clkinv_clkrd_r    <= #TCQ 0;
      q_bit_clkinv_int        <= #TCQ 0;
      phase_clkrd_r           <= #TCQ 0;
      phase                   <= #TCQ 0;
      cal_stage1_done_clkrd_r <= #TCQ 0;
      cal_stage1_done         <= #TCQ 0;
      cal_stage2_done_clkrd_r <= #TCQ 0;
      cal_stage2_done         <= #TCQ 0;
    end else begin
      q_bit_clkinv_clkrd_r    <= #TCQ q_bit_clkinv_clk_r;
      q_bit_clkinv_int        <= #TCQ q_bit_clkinv_clkrd_r;
      phase_clkrd_r           <= #TCQ phase_clk_r;
      phase                   <= #TCQ phase_clkrd_r;
      cal_stage1_done_clkrd_r <= #TCQ cal_stage1_done_clk_r;
      cal_stage1_done         <= #TCQ cal_stage1_done_clkrd_r;
      cal_stage2_done_clkrd_r <= #TCQ cal_stage2_done_clk_r;
      cal_stage2_done         <= #TCQ cal_stage2_done_clkrd_r; 
      
      //chipscope debug controls for CQ & Q
      dbg_sel_q_clkrd_r       <= #TCQ dbg_sel_q_clk_r;   
      dbg_sel_cq_clkrd_r      <= #TCQ dbg_sel_cq_clk_r;   
      dbg_sel_cqn_clkrd_r     <= #TCQ dbg_sel_cqn_clk_r;    
      dbg_inc_q_clkrd_r       <= #TCQ dbg_inc_q_clk_r;    
      dbg_dec_q_clkrd_r       <= #TCQ dbg_dec_q_clk_r;
      dbg_inc_cq_clkrd_r      <= #TCQ dbg_inc_cq_clk_r;    
      dbg_dec_cq_clkrd_r      <= #TCQ dbg_dec_cq_clk_r; 
      dbg_inc_cqn_clkrd_r     <= #TCQ dbg_inc_cqn_clk_r;    
      dbg_dec_cqn_clkrd_r     <= #TCQ dbg_dec_cqn_clk_r;  
      dbg_inc_q_all_clkrd_r   <= #TCQ dbg_inc_q_all_clk_r;
      dbg_dec_q_all_clkrd_r   <= #TCQ dbg_dec_q_all_clk_r;
      dbg_inc_cq_all_clkrd_r  <= #TCQ dbg_inc_cq_all_clk_r;
      dbg_dec_cq_all_clkrd_r  <= #TCQ dbg_dec_cq_all_clk_r;
      dbg_inc_cqn_all_clkrd_r <= #TCQ dbg_inc_cqn_all_clk_r;
      dbg_dec_cqn_all_clkrd_r <= #TCQ dbg_dec_cqn_all_clk_r; 
      
      dbg_sel_q_clkrd         <= #TCQ dbg_sel_q_clkrd_r;
      dbg_sel_cq_clkrd        <= #TCQ dbg_sel_cq_clkrd_r;  
      dbg_sel_cqn_clkrd       <= #TCQ dbg_sel_cqn_clkrd_r;  
      dbg_inc_q_clkrd         <= #TCQ dbg_inc_q_clkrd_r;    
      dbg_dec_q_clkrd         <= #TCQ dbg_dec_q_clkrd_r;
      dbg_inc_cq_clkrd        <= #TCQ dbg_inc_cq_clkrd_r;    
      dbg_dec_cq_clkrd        <= #TCQ dbg_dec_cq_clkrd_r;
      dbg_inc_cqn_clkrd       <= #TCQ dbg_inc_cqn_clkrd_r;    
      dbg_dec_cqn_clkrd       <= #TCQ dbg_dec_cqn_clkrd_r;   
      dbg_inc_q_all_clkrd     <= #TCQ dbg_inc_q_all_clkrd_r;
      dbg_dec_q_all_clkrd     <= #TCQ dbg_dec_q_all_clkrd_r;
      dbg_inc_cq_all_clkrd    <= #TCQ dbg_inc_cq_all_clkrd_r;
      dbg_dec_cq_all_clkrd    <= #TCQ dbg_dec_cq_all_clkrd_r;
      dbg_inc_cqn_all_clkrd   <= #TCQ dbg_inc_cqn_all_clkrd_r;
      dbg_dec_cqn_all_clkrd   <= #TCQ dbg_dec_cqn_all_clkrd_r;
      
    end             
  end               
                    
  // Further delay the clock invert signal to stay aligned with
  // cq_num_active
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      q_bit_clkinv_int_r  <= #TCQ 0;
      q_bit_clkinv_int_2r <= #TCQ 0;
      q_bit_clkinv        <= #TCQ 0;
    end else begin
      q_bit_clkinv_int_r  <= #TCQ q_bit_clkinv_int;
      q_bit_clkinv_int_2r <= #TCQ q_bit_clkinv_int_r;
      q_bit_clkinv        <= #TCQ q_bit_clkinv_int_2r;
    end
  end

  // Synchronize signals going from clk_rd domain to clk domain

  // First register all signals in the clk_rd domain
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      pd_calib_done_clkrd_r <= #TCQ 0;
    end else begin
      pd_calib_done_clkrd_r <= #TCQ pd_calib_done;
    end
  end

  // Now double register each signal into the clk domain
  always @(posedge clk) begin
    if (rst_clk) begin
      pd_calib_done_clk   <= #TCQ 0;
      pd_calib_done_clk_r <= #TCQ 0;
    end else begin
      pd_calib_done_clk   <= #TCQ pd_calib_done_clkrd_r;
      pd_calib_done_clk_r <= #TCQ pd_calib_done_clk;
    end
  end

endmodule
