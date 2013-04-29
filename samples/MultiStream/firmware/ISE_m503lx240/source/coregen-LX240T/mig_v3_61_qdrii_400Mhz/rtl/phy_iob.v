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
//  /   /         Filename           : phy_iob.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:57 $
// \   \  /  \    Date Created       : Nov 18, 2008 
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+
//
//Purpose:
//    This module
//  1. Instantiates all the modules that use the IOBs
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_iob #(
  parameter DATA_WIDTH      = 72,           //Data Width
  parameter ADDR_WIDTH      = 19,           //Adress Width
  parameter BW_WIDTH        = DATA_WIDTH/9, //Byte Write Width
  parameter REFCLK_FREQ     = 300.0,        //Reference Clk Feq for IODELAYs
  parameter CLK_PERIOD      = 3752,         //Internal Fabric Clk Period (ps)
  parameter BURST_LEN       = 4,            //Burst Length
  parameter NUM_DEVICES     = 2,            //Memory Devices
  parameter IODELAY_GRP     = "IODELAY_MIG",//May be assigned unique name 
                                            //when mult IP cores in design
  parameter DEVICE_TAPS     = 32,           //Number of taps in target IODELAY
  parameter TAP_BITS        = 5,            //Number of bits needed to represent
                                            // DEVICE_TAPS
  parameter MEMORY_WIDTH    = 36,           //Width of each memory
  parameter IBUF_LPWR_MODE  = "OFF",        //Input buffer low power mode
  parameter IODELAY_HP_MODE = "ON",         //IODELAY High Performance Mode
  parameter SIM_INIT_OPTION    = "NONE",        //Simulation only. "NONE", "SIM_MODE"
  parameter TCQ             = 100           //Register Delay
)
(
  //System Signals
  input                           clk,            //main system half freq clk   
  input                           rst_clk,
  input                           rst_wr_clk,     //main write path reset 
  input                           clk_mem,        //full frequency clock
  output wire [NUM_DEVICES-1:0]   clk_rd,         //half freq CQ clock
  input       [NUM_DEVICES-1:0]   rst_clk_rd,     //reset syncrhonized to clk_rd

  //Write Path Inputs 
  input       [1:0]               int_rd_cmd_n,   //internal rd cmd
  input       [1:0]               int_wr_cmd_n,   //internal rd cmd
  input       [ADDR_WIDTH-1:0]    iob_addr_rise0, //OSERDES addr rise0
  input       [ADDR_WIDTH-1:0]    iob_addr_fall0, //OSERDES addr fall0
  input       [ADDR_WIDTH-1:0]    iob_addr_rise1, //OSERDES addr rise1
  input       [ADDR_WIDTH-1:0]    iob_addr_fall1, //OSERDES addr fall1
  input       [DATA_WIDTH-1:0]    iob_data_rise0, //OSERDES d rise0
  input       [DATA_WIDTH-1:0]    iob_data_fall0, //OSERDES d fall0
  input       [DATA_WIDTH-1:0]    iob_data_rise1, //OSERDES d rise1
  input       [DATA_WIDTH-1:0]    iob_data_fall1, //OSERDES d fall1
  input       [BW_WIDTH-1:0]      iob_bw_rise0,   //OSERDES bw rise0
  input       [BW_WIDTH-1:0]      iob_bw_fall0,   //OSERDES bw fall0
  input       [BW_WIDTH-1:0]      iob_bw_rise1,   //OSERDES bw rise1
  input       [BW_WIDTH-1:0]      iob_bw_fall1,   //OSERDES bw fall1
  
  //Read Path Signals
  output wire [NUM_DEVICES-1:0]          clk_cq,      // CQ BUFIO clock
  output wire [NUM_DEVICES-1:0]          clk_cqn,     // CQ# BUFIO clock
  output wire [NUM_DEVICES-1:0]          pd_source,   // RLDRAM II PD Source
  input       [NUM_DEVICES-1:0]          cq_dly_ce,   // CQ IDELAY clock enable
  input       [NUM_DEVICES-1:0]          cq_dly_inc,  // CQ IDELAY increment
  input       [NUM_DEVICES-1:0]          cq_dly_rst,  // CQ IDELAY reset
  input       [TAP_BITS*NUM_DEVICES-1:0] cq_dly_load, // CQ IDELAY cntvaluein
  output reg [TAP_BITS*NUM_DEVICES-1:0]  dbg_cq_tapcnt,  // CQ IDELAY tap settings
  input       [NUM_DEVICES-1:0]          cqn_dly_ce,  // CQ# IDELAY clock enable
  input       [NUM_DEVICES-1:0]          cqn_dly_inc, // CQ# IDELAY increment
  input       [NUM_DEVICES-1:0]          cqn_dly_rst, // CQ# IDELAY reset
  input       [TAP_BITS*NUM_DEVICES-1:0] cqn_dly_load,// CQ# IDELAY cntvaluein
  output reg  [TAP_BITS*NUM_DEVICES-1:0] dbg_cqn_tapcnt, // CQ# IDELAY tap settings
  input       [DATA_WIDTH-1:0]           q_dly_ce,    // Q IDELAY clock enable
  input       [NUM_DEVICES-1:0]          q_dly_inc,   // Q IDELAY increment
  input       [DATA_WIDTH-1:0]           q_dly_rst,   // Q IDELAY reset
  input       [TAP_BITS*NUM_DEVICES-1:0] q_dly_load,  // Q IDELAY cntvaluein
  output reg  [TAP_BITS*DATA_WIDTH-1:0]  dbg_q_tapcnt,   // Q IDELAY tap settings
  input       [NUM_DEVICES-1:0]          q_dly_clkinv,// Q IDELAY CLK inversion
  input       [NUM_DEVICES-1:0]          iserdes_rst, // ISERDES reset
  output      [DATA_WIDTH-1:0]           iserdes_rd0, // ISERDES Q4 -rise data 0
  output      [DATA_WIDTH-1:0]           iserdes_fd0, // ISERDES Q3 -fall data 0
  output      [DATA_WIDTH-1:0]           iserdes_rd1, // ISERDES Q2 -rise data 1
  output      [DATA_WIDTH-1:0]           iserdes_fd1, // ISERDES Q1 -fall data 1
  output wire [NUM_DEVICES-1:0]          dbg_clk_rd, 

  //Memory Interface Signals
  output wire [NUM_DEVICES-1:0]   mem_k_p,        //clock K
  output wire [NUM_DEVICES-1:0]   mem_k_n,        //clock K#
  output wire [ADDR_WIDTH-1:0]    mem_sa,         //Memory Address
  output wire                     mem_w_n,        //Write Cmd
  output wire                     mem_r_n,        //Read Cmd
  output wire [BW_WIDTH-1:0]      mem_bw_n,       //Byte Writes to Memory
  output wire [DATA_WIDTH-1:0]    mem_d,          //Data to Memory
  input       [NUM_DEVICES-1:0]   mem_cq_p,       //CQ echo clock
  input       [NUM_DEVICES-1:0]   mem_cq_n,       //CQ# echo clock
  input       [DATA_WIDTH-1:0]    mem_q           //Q data
);

  // Local Parameters
  //Calculate the tap resolution based on the Reference Clock
  localparam integer IODELAY_TAP_RES = 1000000 / (REFCLK_FREQ * 64);

  localparam SHIFT_BY4 = ((CLK_PERIOD/2) / (4 * IODELAY_TAP_RES));
  
  //Select the address delay value for IODELAY depending on BL
  localparam ODELAY_ADDR_VAL = (BURST_LEN == 4) ? SHIFT_BY4 : 0;

  // Enable low power mode for input buffer
  localparam IBUF_LOW_PWR 
             = (IBUF_LPWR_MODE == "OFF") ? "FALSE" : 
               ((IBUF_LPWR_MODE == "ON")  ? "TRUE" : "ILLEGAL");

  // Set performance mode for IODELAY (power vs. performance tradeoff)
  localparam HIGH_PERFORMANCE_MODE 
             = (IODELAY_HP_MODE == "OFF") ? "FALSE" : 
               ((IODELAY_HP_MODE == "ON")  ? "TRUE" : "ILLEGAL");

  wire [TAP_BITS*NUM_DEVICES-1:0] cq_dly_tap;
  wire [TAP_BITS*NUM_DEVICES-1:0] cqn_dly_tap;
  wire [TAP_BITS*DATA_WIDTH-1:0]  q_dly_tap;
  reg [TAP_BITS*NUM_DEVICES-1:0] cq_dly_tap_r;
  reg [TAP_BITS*NUM_DEVICES-1:0] cqn_dly_tap_r;
  reg [TAP_BITS*DATA_WIDTH-1:0]  q_dly_tap_r;
  reg [TAP_BITS*NUM_DEVICES-1:0] cq_dly_tap_2r;
  reg [TAP_BITS*NUM_DEVICES-1:0] cqn_dly_tap_2r;
  reg [TAP_BITS*DATA_WIDTH-1:0]  q_dly_tap_2r;
  
  assign dbg_clk_rd = clk_rd;
  
  genvar dbg_nd_i;
  generate
    for(dbg_nd_i = 0; dbg_nd_i < NUM_DEVICES; dbg_nd_i = dbg_nd_i +1)
      begin : DBG_DLY_INST
  
  always @ (posedge clk_rd[dbg_nd_i])
    begin
      if (rst_clk_rd[dbg_nd_i]) begin
         cq_dly_tap_r  [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]  <= #TCQ 0;         
         cqn_dly_tap_r [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]  <= #TCQ 0;
         q_dly_tap_r   [(TAP_BITS*(dbg_nd_i+1)*MEMORY_WIDTH)-1 : (dbg_nd_i*TAP_BITS*MEMORY_WIDTH)]  <= #TCQ 0;
         cq_dly_tap_2r [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]  <= #TCQ 0;         
         cqn_dly_tap_2r[TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]  <= #TCQ 0;
         q_dly_tap_2r  [(TAP_BITS*(dbg_nd_i+1)*MEMORY_WIDTH)-1 : (dbg_nd_i*TAP_BITS*MEMORY_WIDTH)]  <= #TCQ 0;
         dbg_cq_tapcnt [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]  <= #TCQ 0;         
         dbg_cqn_tapcnt[TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)] <= #TCQ 0;
         dbg_q_tapcnt  [(TAP_BITS*(dbg_nd_i+1)*MEMORY_WIDTH)-1 : (dbg_nd_i*TAP_BITS*MEMORY_WIDTH)]<= #TCQ 0;
      end else begin
         cq_dly_tap_r  [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]                           <= #TCQ cq_dly_tap    [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)];         
         cqn_dly_tap_r [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]                           <= #TCQ cqn_dly_tap   [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)];         
         cq_dly_tap_2r [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]                           <= #TCQ cq_dly_tap_r  [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)];         
         cqn_dly_tap_2r[TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]                           <= #TCQ cqn_dly_tap_r [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)];         
         dbg_cq_tapcnt [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]                           <= #TCQ cq_dly_tap_2r [TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)];         
         dbg_cqn_tapcnt[TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)]                           <= #TCQ cqn_dly_tap_2r[TAP_BITS*(dbg_nd_i+1)-1 : (dbg_nd_i*TAP_BITS)];
         q_dly_tap_r   [(TAP_BITS*(dbg_nd_i+1)*MEMORY_WIDTH)-1 : (dbg_nd_i*TAP_BITS*MEMORY_WIDTH)] <= #TCQ q_dly_tap     [(TAP_BITS*(dbg_nd_i+1)*MEMORY_WIDTH)-1 : (dbg_nd_i*TAP_BITS*MEMORY_WIDTH)];
         q_dly_tap_2r  [(TAP_BITS*(dbg_nd_i+1)*MEMORY_WIDTH)-1 : (dbg_nd_i*TAP_BITS*MEMORY_WIDTH)] <= #TCQ q_dly_tap_r   [(TAP_BITS*(dbg_nd_i+1)*MEMORY_WIDTH)-1 : (dbg_nd_i*TAP_BITS*MEMORY_WIDTH)];
         dbg_q_tapcnt  [(TAP_BITS*(dbg_nd_i+1)*MEMORY_WIDTH)-1 : (dbg_nd_i*TAP_BITS*MEMORY_WIDTH)] <= #TCQ q_dly_tap_2r  [(TAP_BITS*(dbg_nd_i+1)*MEMORY_WIDTH)-1 : (dbg_nd_i*TAP_BITS*MEMORY_WIDTH)];
      end
   end   
  end
  endgenerate  
      

  // Instantiations  
  //Instantiate the OSERDES to clock out single-ended K clocks 
  
  genvar clkp_i;
  generate
    for(clkp_i = 0; clkp_i < NUM_DEVICES; clkp_i = clkp_i +1)
      begin : CLKP_INST

        phy_oserdes_io #(
          .ODELAY_VAL           (SHIFT_BY4),
          .REFCLK_FREQ          (REFCLK_FREQ),
          .IODELAY_GRP          (IODELAY_GRP),
          .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE),
          .INIT_OQ_VAL          (1'b1),
          .DIFF_OUT             (0)
        ) u_phy_oserdes_clk (
          .clk          (clk),
          .rst_wr_clk   (rst_wr_clk),
          .clk_mem      (clk_mem),
          .data_rise0   (1'b0), 
          .data_fall0   (1'b1),  
          .data_rise1   (1'b0),   
          .data_fall1   (1'b1),    
          .data_out_p   (mem_k_p[clkp_i]), 
          .data_out_n   ()
        );
      end
  endgenerate   
  
   // Instantiations  
  //Instantiate the OSERDES to clock out single ended K# clocks 
  
  genvar clkn_i;
  generate
    for(clkn_i = 0; clkn_i < NUM_DEVICES; clkn_i = clkn_i +1)
      begin : CLKN_INST

        phy_oserdes_io #(
          .ODELAY_VAL           (SHIFT_BY4),
          .REFCLK_FREQ          (REFCLK_FREQ),
          .IODELAY_GRP          (IODELAY_GRP),
          .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE),
          .INIT_OQ_VAL          (1'b0), 
          .DIFF_OUT             (0)
        ) u_phy_oserdes_clk (
          .clk          (clk),
          .rst_wr_clk   (rst_wr_clk),
          .clk_mem      (clk_mem),
          .data_rise0   (1'b1), 
          .data_fall0   (1'b0),  
          .data_rise1   (1'b1),   
          .data_fall1   (1'b0),    
          .data_out_p   (mem_k_n[clkn_i]), 
          .data_out_n   ()
        );
      end
  endgenerate
  

  //Instantiate an OSERDES for the read and write command lines
  //delay the clock for read/write commands.  this does not need a delay
  //value but is inserted to maintain delay across commands and addressing
  //which encounter a minor delay through the IODELAYE1 primitive
  phy_oserdes_io #(
    .ODELAY_VAL           (SHIFT_BY4),
    .REFCLK_FREQ          (REFCLK_FREQ),
    .IODELAY_GRP          (IODELAY_GRP),
    .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE), 
    .INIT_OQ_VAL          (1'b0), 
    .DIFF_OUT             (0)
  ) u_phy_oserdes_rd (
    .clk          (clk),
    .rst_wr_clk   (rst_wr_clk),
    .clk_mem      (clk_mem),
    .data_rise0   (int_rd_cmd_n[0]), 
    .data_fall0   (int_rd_cmd_n[0]),  
    .data_rise1   (int_rd_cmd_n[1]),   
    .data_fall1   (int_rd_cmd_n[1]),    
    .data_out_p   (mem_r_n), 
    .data_out_n   ()
  );
  
  phy_oserdes_io #(
    .ODELAY_VAL           (SHIFT_BY4),
    .REFCLK_FREQ          (REFCLK_FREQ),
    .IODELAY_GRP          (IODELAY_GRP),
    .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE),
    .INIT_OQ_VAL          (1'b 0), 
    .DIFF_OUT             (0)
  )u_phy_oserdes_wr (
    .clk          (clk),
    .rst_wr_clk   (rst_wr_clk),
    .clk_mem      (clk_mem),
    .data_rise0   (int_wr_cmd_n[0]), 
    .data_fall0   (int_wr_cmd_n[0]),  
    .data_rise1   (int_wr_cmd_n[1]),   
    .data_fall1   (int_wr_cmd_n[1]),    
    .data_out_p   (mem_w_n),
    .data_out_n   ()
  );

  //Instantiate an OSERDES for each bit of the address
  //Delay clk_wr by .25 to center align the address.  This is only used with
  //BURST_LEN == 2.  Otherwise the delay value is 0
  genvar aw_i;
  generate
    for(aw_i = 0; aw_i < ADDR_WIDTH; aw_i = aw_i +1)
      begin : ADDR_INST
        phy_oserdes_io #(
          .ODELAY_VAL           (ODELAY_ADDR_VAL),
          .REFCLK_FREQ          (REFCLK_FREQ),
          .IODELAY_GRP          (IODELAY_GRP),
          .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE),
          .INIT_OQ_VAL          (1'b0), 
          .DIFF_OUT             (0)
        ) u_phy_oserdes_addr (
          .clk          (clk),
          .rst_wr_clk   (rst_wr_clk),
          .clk_mem      (clk_mem),
          .data_rise0   (iob_addr_rise0[aw_i]), 
          .data_fall0   (iob_addr_fall0[aw_i]),  
          .data_rise1   (iob_addr_rise1[aw_i]),   
          .data_fall1   (iob_addr_fall1[aw_i]),    
          .data_out_p   (mem_sa[aw_i]), 
          .data_out_n   ()
        );
      end
  endgenerate
  
  //Instantiate an OSERDES for each byte write bit to clock out the 
  //byte writes using the perfomance path (clk_wr)
  genvar bw_i;
  generate
    for(bw_i = 0; bw_i < BW_WIDTH; bw_i = bw_i +1)
      begin : BW_N_INST
        phy_oserdes_io #(
          .ODELAY_VAL           (0),
          .REFCLK_FREQ          (REFCLK_FREQ),
          .IODELAY_GRP          (IODELAY_GRP),
          .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE),
          .INIT_OQ_VAL          (1'b0), 
          .DIFF_OUT             (0)
        )u_phy_oserdes_bw (
          .clk          (clk),
          .rst_wr_clk   (rst_wr_clk),
          .clk_mem      (clk_mem),
          .data_rise0   (iob_bw_rise0[bw_i]), 
          .data_fall0   (iob_bw_fall0[bw_i]),  
          .data_rise1   (iob_bw_rise1[bw_i]),   
          .data_fall1   (iob_bw_fall1[bw_i]),    
          .data_out_p   (mem_bw_n[bw_i]),
          .data_out_n   ()
        );
      end
  endgenerate

  // Instantiate I/Os for read path
  genvar nd_i;
  generate
    for (nd_i=0; nd_i < NUM_DEVICES; nd_i=nd_i+1) begin : nd_io_inst

      // Instantiate the I/O logic for the CQ clock.
      phy_read_clk_io #(
        .REFCLK_FREQ          (REFCLK_FREQ),
        .IODELAY_GRP          (IODELAY_GRP),
        .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE),
        .IBUF_LOW_PWR         (IBUF_LOW_PWR),
        .TCQ                  (TCQ)
      ) u_phy_read_cq_io (
        .mem_cq       (mem_cq_p[nd_i]),
        .mem_cq_n     (mem_cq_n[nd_i]),
        .cal_clk      (clk_rd[nd_i]),
        .cq_dly_ce    (cq_dly_ce[nd_i]),
        .cq_dly_inc   (cq_dly_inc[nd_i]),
        .cq_dly_rst   (cq_dly_rst[nd_i]),
        .cq_dly_load  (cq_dly_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .cq_dly_tap   (cq_dly_tap[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .cqn_dly_ce   (cqn_dly_ce[nd_i]),
        .cqn_dly_inc  (cqn_dly_inc[nd_i]),
        .cqn_dly_rst  (cqn_dly_rst[nd_i]),
        .cqn_dly_load (cqn_dly_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .cqn_dly_tap  (cqn_dly_tap[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .clk_cq       (clk_cq[nd_i]),
        .clk_cqn      (clk_cqn[nd_i]),
        .clk_rd       (clk_rd[nd_i]),
        .pd_source    (pd_source[nd_i]),
        .rst_clk_rd   (rst_clk_rd[nd_i])
      );

      // Instantiate the I/O logic for the D & Q data.
      phy_d_q_io #(
        .BYTE_WIDTH           (MEMORY_WIDTH),
        .REFCLK_FREQ          (REFCLK_FREQ),
        .ODELAY_VAL           (0),
        .IODELAY_GRP          (IODELAY_GRP),
        .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE),
        .IBUF_LOW_PWR         (IBUF_LOW_PWR),
        .SIM_INIT_OPTION      (SIM_INIT_OPTION),
        .TCQ                  (TCQ)
      ) u_phy_d_q_io (
        //System Signals
        .clk          (clk),
        .rst_wr_clk   (rst_wr_clk),        
        //Write Interface
        .clk_mem      (clk_mem),
        .data_rise0   (iob_data_rise0[MEMORY_WIDTH*(nd_i+1)-1:
                                      MEMORY_WIDTH*nd_i]),
        .data_fall0   (iob_data_fall0[MEMORY_WIDTH*(nd_i+1)-1:
                                      MEMORY_WIDTH*nd_i]),
        .data_rise1   (iob_data_rise1[MEMORY_WIDTH*(nd_i+1)-1:
                                      MEMORY_WIDTH*nd_i]),
        .data_fall1   (iob_data_fall1[MEMORY_WIDTH*(nd_i+1)-1:
                                      MEMORY_WIDTH*nd_i]),
        .mem_d        (mem_d[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        //Bidirectional Interface
        .wr_en        (4'b0),
        .mem_dq       (),
        //Read Interface
        .clk_cq       (clk_cq[nd_i]),
        .clk_cqn      (clk_cqn[nd_i]),
        .clk_rd       (clk_rd[nd_i]),
        .rst_clk_rd   (rst_clk_rd[nd_i]),
        .mem_q        (mem_q[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .q_dly_ce     (q_dly_ce[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .q_dly_inc    (q_dly_inc[nd_i]),
        .q_dly_rst    (q_dly_rst[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .q_dly_load   (q_dly_load[TAP_BITS*(nd_i+1)-1:TAP_BITS*nd_i]),
        .q_dly_tap    (q_dly_tap[MEMORY_WIDTH*TAP_BITS*(nd_i+1)-1:
                                 MEMORY_WIDTH*TAP_BITS*nd_i]),
        .q_dly_clkinv (q_dly_clkinv[nd_i]),
        .iserdes_rst  (iserdes_rst[nd_i]),
        .iserdes_rd0  (iserdes_rd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .iserdes_fd0  (iserdes_fd0[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .iserdes_rd1  (iserdes_rd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i]),
        .iserdes_fd1  (iserdes_fd1[MEMORY_WIDTH*(nd_i+1)-1:MEMORY_WIDTH*nd_i])
      );
    end
  endgenerate
  
endmodule
