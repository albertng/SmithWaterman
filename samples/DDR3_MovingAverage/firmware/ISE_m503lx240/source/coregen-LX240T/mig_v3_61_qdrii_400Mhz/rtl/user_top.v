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
//  /   /         Filename           : user_top.v
// /___/   /\     Date Last Modified : $date$
// \   \  /  \    Date Created       : Nov 18, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+
//
//Purpose:
//    This module
//  1. This is a wrapper which instantiates the PHY top Level which simplifies 
//     user interaction.  This wrapper supports both BL4 and BL2 designs.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module user_top #(
  parameter ADDR_WIDTH         = 19,          //Address Width
  parameter DATA_WIDTH         = 72,          //Data Width
  parameter BW_WIDTH           = 8,           //Byte Write Width
  parameter BURST_LEN          = 2,           //Burst Length
  parameter CLK_PERIOD         = 3752,        //Internal Fabric Clk Period (in ps)
  parameter REFCLK_FREQ        = 300.0,       //Ref. Clk Freq. for IODELAYs
  parameter NUM_DEVICES        = 2,           //Memory Devices
  parameter FIXED_LATENCY_MODE = 0,           //Use Fixed Latency Mode for read
  parameter PHY_LATENCY        = 0,           //Desired Latency
  parameter CLK_STABLE         = 2048,        //Cycles till CQ/CQ# is stable
  parameter IODELAY_GRP        = "IODELAY_MIG", //May be assigned unique name 
                                                // when mult IP cores in design
  parameter MEM_TYPE           = "QDR2PLUS",  //QDR Memory Type
  parameter DEVICE_ARCH        = "virtex6",   //Device Architecture
  parameter RST_ACT_LOW        = 1,           //System Reset is Active Low
  parameter PHASE_DETECT       = "OFF",       //Enable Phase detector
  parameter SIM_CAL_OPTION     = "NONE",      // Skip various calibration steps
  parameter SIM_INIT_OPTION    = "NONE",        //Simulation only. "NONE", "SIM_MODE"
  parameter IBUF_LPWR_MODE     = "OFF",       // Input buffer low power mode
  parameter IODELAY_HP_MODE    = "ON",        // IODELAY High Performance Mode
  parameter CQ_BITS            = 1,           //clog2(NUM_DEVICES - 1)   
  parameter Q_BITS             = 7,           //clog2(DATA_WIDTH - 1)
  parameter DEVICE_TAPS        = 32,          // Number of taps in the IDELAY chain
  parameter TAP_BITS           = 5,           // clog2(DEVICE_TAPS - 1)   
  parameter DEBUG_PORT         = "ON",        // Debug using Chipscope controls 
  parameter TCQ                = 100          //Register Delay
)
(
  //System Signals
  input                                     clk,              //main system half freq clk
  output wire                               rst_clk,          //reset sync to clk  
  input                                     sys_rst,          //unsync system clk reset
  input                                     clk_mem,          //full frequency clock
 input                                      clk_wr,
  input                                     mmcm_locked,      //MMCM is locked
  input                                     iodelay_ctrl_rdy, //IODELAY CTRL is ready

  //User Interface
  input                                     user_wr_cmd0,     //wr command 0
  input                                     user_wr_cmd1,     //wr command 1
  input       [ADDR_WIDTH-1:0]              user_wr_addr0,    //wr address 0
  input       [ADDR_WIDTH-1:0]              user_wr_addr1,    //wr address 1
  input                                     user_rd_cmd0,     //rd command 0
  input                                     user_rd_cmd1,     //rd command 1
  input       [ADDR_WIDTH-1:0]              user_rd_addr0,    //rd address 0
  input       [ADDR_WIDTH-1:0]              user_rd_addr1,    //rd address 1
  input       [(BURST_LEN*DATA_WIDTH)-1:0]  user_wr_data0,    //user write data 0
  input       [(DATA_WIDTH*2)-1:0]          user_wr_data1,    //user write data 1
  input       [(BURST_LEN*BW_WIDTH)-1:0]    user_wr_bw_n0,    //user byte writes 0
  input       [(BW_WIDTH*2)-1:0]            user_wr_bw_n1,    //user byte writes 1

  output wire                               user_cal_done,    //Calibration complete
  output wire                               user_rd_valid0,   //Read valid for rd_data0
  output wire                               user_rd_valid1,   //Read valid for rd_data1
  output wire [(BURST_LEN*DATA_WIDTH)-1:0]  user_rd_data0,    //Read data 0
  output wire [(DATA_WIDTH*2)-1:0]          user_rd_data1,    //Read data 1

  //Memory Interface
  output wire                               qdr_dll_off_n,    //QDR - turn off dll in mem
  output wire [NUM_DEVICES-1:0]             qdr_k_p,          //QDR clock K
  output wire [NUM_DEVICES-1:0]             qdr_k_n,          //QDR clock K#
  output wire [ADDR_WIDTH-1:0]              qdr_sa,           //QDR Memory Address
  output wire                               qdr_w_n,          //QDR Write 
  output wire                               qdr_r_n,          //QDR Read
  output wire [BW_WIDTH-1:0]                qdr_bw_n,         //QDR Byte Writes to Mem
  output wire [DATA_WIDTH-1:0]              qdr_d,            //QDR Data to Memory
  input       [DATA_WIDTH-1:0]              qdr_q,            //QDR Data from Memory
  input       [NUM_DEVICES-1:0]             qdr_qvld,         //QDR Data Valid from Mem
  input       [NUM_DEVICES-1:0]             qdr_cq_p,         //QDR echo clock CQ 
  input       [NUM_DEVICES-1:0]             qdr_cq_n,         //QDR echo clock CQ# 

  //ChipScope Readpath Debug Signals
  output wire [1:0]                       dbg_phy_wr_cmd_n,       //cs debug - wr command
  output wire [ADDR_WIDTH*4-1:0]          dbg_phy_addr,           //cs debug - address
  output wire [1:0]                       dbg_phy_rd_cmd_n,       //cs debug - rd command
  output wire [DATA_WIDTH*4-1:0]          dbg_phy_wr_data,        //cs debug - wr data
  input                                   dbg_inc_cq_all,         // increment all CQs
  input                                   dbg_inc_cqn_all,        // increment all CQ#s
  input                                   dbg_inc_q_all,          // increment all Qs
  input                                   dbg_dec_cq_all,         // decrement all CQs   
  input                                   dbg_dec_cqn_all,        // decrement all CQ#s 
  input                                   dbg_dec_q_all,          // decrement all Qs   
  input                                   dbg_inc_cq,             // increment selected CQ  
  input                                   dbg_inc_cqn,            // increment selected CQ#
  input                                   dbg_inc_q,              // increment selected Q  
  input                                   dbg_dec_cq,             // decrement selected CQ  
  input                                   dbg_dec_cqn,            // decrement selected CQ# 
  input                                   dbg_dec_q,              // decrement selected Q   
  input [CQ_BITS-1:0]                     dbg_sel_cq,             // selected CQ bit
  input [CQ_BITS-1:0]                     dbg_sel_cqn,            // selected CQ# bit
  input [Q_BITS-1:0]                      dbg_sel_q,              // selected Q bit
  input                                   dbg_pd_off,
  output wire [TAP_BITS*NUM_DEVICES-1:0]  dbg_cq_tapcnt,          // tap count for each cq
  output wire [TAP_BITS*NUM_DEVICES-1:0]  dbg_cqn_tapcnt,         // tap count for each cq#
  output wire [TAP_BITS*DATA_WIDTH-1:0]   dbg_q_tapcnt,           // tap count for each q
  output wire [NUM_DEVICES-1:0]           dbg_clk_rd,             // clk_rd in each domain
  output wire [255:0]                     dbg_rd_stage1_cal,      // stage 1 cal debug
  output wire [127:0]                     dbg_stage2_cal,         // stage 2 cal debug
  output wire [CQ_BITS-1:0]               dbg_cq_num,             // current cq/cq# being calibrated
  output wire [Q_BITS-1:0]                dbg_q_bit,              // current q being calibrated 
  output wire [4:0]                       dbg_valid_lat,          // latency of the system
  output wire [NUM_DEVICES-1:0]           dbg_phase,              // data align phase indication
  output wire [NUM_DEVICES-1:0]           dbg_inc_latency,        // increase latency for dcb
  output wire [5*NUM_DEVICES-1:0]         dbg_dcb_wr_ptr,         // dcb write pointers
  output wire [5*NUM_DEVICES-1:0]         dbg_dcb_rd_ptr,         // dcb read pointers
  output wire [4*DATA_WIDTH-1:0]          dbg_dcb_din,            // dcb data in
  output wire [4*DATA_WIDTH-1:0]          dbg_dcb_dout,           // dcb data out
  output wire [NUM_DEVICES-1:0]           dbg_error_max_latency,  // stage 2 cal max latency error
  output wire                             dbg_error_adj_latency,  // stage 2 cal latency adjustment error   
  output wire [NUM_DEVICES-1:0]           dbg_pd_calib_start,     // indicates phase detector to start
  output wire [NUM_DEVICES-1:0]           dbg_pd_calib_done,      // indicates phase detector is complete
  output wire [7:0]                       dbg_phy_status,          // phy status
  output wire [DATA_WIDTH-1:0]            dbg_align_rd0,
  output wire [DATA_WIDTH-1:0]            dbg_align_rd1,
  output wire [DATA_WIDTH-1:0]            dbg_align_fd0,
  output wire [DATA_WIDTH-1:0]            dbg_align_fd1
);

  //Internal Wires
  wire                              mux_wr_cmd0;
  wire [ADDR_WIDTH-1:0]             mux_wr_addr0;
  wire [(DATA_WIDTH*2)-1:0]         mux_wr_data0;
  wire [(DATA_WIDTH*2)-1:0]         mux_wr_data1;
  wire [(BW_WIDTH*2)-1:0]           mux_wr_bw_n0;
  wire [(BW_WIDTH*2)-1:0]           mux_wr_bw_n1;
  wire                              mux_rd_cmd1;
  wire [ADDR_WIDTH-1:0]             mux_rd_addr1;
  wire [(DATA_WIDTH*2)-1:0]         rd_data0;
  wire [(DATA_WIDTH*2)-1:0]         rd_data1;

  generate 
    if (BURST_LEN == 4) begin: mux_data_bl4
      assign mux_wr_data0 = user_wr_data0[DATA_WIDTH*4-1:DATA_WIDTH*2];
      assign mux_wr_bw_n0 = user_wr_bw_n0[BW_WIDTH*4-1:BW_WIDTH*2];
    end else begin: mux_data_bl2
      assign mux_wr_data0 = user_wr_data0;
      assign mux_wr_bw_n0 = user_wr_bw_n0;
    end
  endgenerate
  
  assign mux_wr_data1  = (BURST_LEN == 4) ? user_wr_data0[DATA_WIDTH*2-1:0] : user_wr_data1;
  assign mux_wr_bw_n1  = (BURST_LEN == 4) ? user_wr_bw_n0[BW_WIDTH*2-1:0] : user_wr_bw_n1;
  assign user_rd_data0 = (BURST_LEN == 4) ? {rd_data0, rd_data1} : rd_data0;
  assign user_rd_data1 = rd_data1;
  
  //Instantiate the Top of the PHY
  qdr_phy_top #(
    .ADDR_WIDTH         (ADDR_WIDTH),
    .DATA_WIDTH         (DATA_WIDTH),
    .BW_WIDTH           (BW_WIDTH),
    .BURST_LEN          (BURST_LEN),
    .CLK_PERIOD         (CLK_PERIOD),
    .REFCLK_FREQ        (REFCLK_FREQ),
    .NUM_DEVICES        (NUM_DEVICES),
    .FIXED_LATENCY_MODE (FIXED_LATENCY_MODE),
    .PHY_LATENCY        (PHY_LATENCY),
    .CLK_STABLE         (CLK_STABLE),
    .IODELAY_GRP        (IODELAY_GRP),
    .MEM_TYPE           (MEM_TYPE),
    .DEVICE_ARCH        (DEVICE_ARCH),
    .SIM_CAL_OPTION     (SIM_CAL_OPTION),
    .SIM_INIT_OPTION    (SIM_INIT_OPTION),
    .PHASE_DETECT       (PHASE_DETECT),
    .RST_ACT_LOW        (RST_ACT_LOW),
    .IBUF_LPWR_MODE     (IBUF_LPWR_MODE),
    .IODELAY_HP_MODE    (IODELAY_HP_MODE),
    .CQ_BITS            (CQ_BITS),
    .Q_BITS             (Q_BITS),
    .TAP_BITS           (TAP_BITS),
    .DEVICE_TAPS        (DEVICE_TAPS),
    .DEBUG_PORT         (DEBUG_PORT),
    .TCQ                (TCQ)
  ) u_qdr_phy_top (
    .clk                    (clk), 
    .rst_clk                (rst_clk),
    .sys_rst                (sys_rst),          
    .clk_mem                (clk_mem),
    .clk_wr                 (clk_wr),
    .mmcm_locked            (mmcm_locked),
    .iodelay_ctrl_rdy       (iodelay_ctrl_rdy),
    .wr_cmd0                (user_wr_cmd0), 
    .wr_cmd1                (user_wr_cmd1),          
    .wr_addr0               (user_wr_addr0), 
    .wr_addr1               (user_wr_addr1),    
    .rd_cmd0                (user_rd_cmd0),          
    .rd_cmd1                (user_rd_cmd1),         
    .rd_addr0               (user_rd_addr0),        
    .rd_addr1               (user_rd_addr1),  
    .wr_data0               (mux_wr_data0),        
    .wr_data1               (mux_wr_data1),        
    .wr_bw_n0               (mux_wr_bw_n0),        
    .wr_bw_n1               (mux_wr_bw_n1),        
    .cal_done               (user_cal_done),        
    .rd_valid0              (user_rd_valid0),       
    .rd_valid1              (user_rd_valid1),        
    .rd_data0               (rd_data0),       
    .rd_data1               (rd_data1),       
    .qdr_k_p                (qdr_k_p),        
    .qdr_k_n                (qdr_k_n),        
    .qdr_sa                 (qdr_sa),         
    .qdr_w_n                (qdr_w_n),         
    .qdr_r_n                (qdr_r_n),        
    .qdr_bw_n               (qdr_bw_n),       
    .qdr_d                  (qdr_d),          
    .qdr_q                  (qdr_q),          
    .qdr_qvld               (qdr_qvld),       
    .qdr_cq_p               (qdr_cq_p),        
    .qdr_cq_n               (qdr_cq_n),   
    .qdr_dll_off_n          (qdr_dll_off_n),
    .dbg_phy_wr_cmd_n       (dbg_phy_wr_cmd_n), 
    .dbg_phy_addr           (dbg_phy_addr),    
    .dbg_phy_rd_cmd_n       (dbg_phy_rd_cmd_n), 
    .dbg_phy_wr_data        (dbg_phy_wr_data),
    .dbg_inc_cq_all         (dbg_inc_cq_all),    
    .dbg_inc_cqn_all        (dbg_inc_cqn_all),   
    .dbg_inc_q_all          (dbg_inc_q_all),     
    .dbg_dec_cq_all         (dbg_dec_cq_all),    
    .dbg_dec_cqn_all        (dbg_dec_cqn_all),   
    .dbg_dec_q_all          (dbg_dec_q_all),     
    .dbg_inc_cq             (dbg_inc_cq),        
    .dbg_inc_cqn            (dbg_inc_cqn),       
    .dbg_inc_q              (dbg_inc_q),         
    .dbg_dec_cq             (dbg_dec_cq),        
    .dbg_dec_cqn            (dbg_dec_cqn),       
    .dbg_dec_q              (dbg_dec_q),         
    .dbg_sel_cq             (dbg_sel_cq),        
    .dbg_sel_cqn            (dbg_sel_cqn),       
    .dbg_sel_q              (dbg_sel_q),
    .dbg_pd_off             (dbg_pd_off),
    .dbg_cq_tapcnt          (dbg_cq_tapcnt), 
    .dbg_cqn_tapcnt         (dbg_cqn_tapcnt),
    .dbg_q_tapcnt           (dbg_q_tapcnt),  
    .dbg_clk_rd             (dbg_clk_rd),
    .dbg_rd_stage1_cal      (dbg_rd_stage1_cal),
    .dbg_stage2_cal         (dbg_stage2_cal),
    .dbg_cq_num             (dbg_cq_num),
    .dbg_q_bit              (dbg_q_bit),
    .dbg_valid_lat          (dbg_valid_lat),
    .dbg_phase              (dbg_phase),
    .dbg_inc_latency        (dbg_inc_latency),
    .dbg_dcb_wr_ptr         (dbg_dcb_wr_ptr),
    .dbg_dcb_rd_ptr         (dbg_dcb_rd_ptr),
    .dbg_dcb_din            (dbg_dcb_din),
    .dbg_dcb_dout           (dbg_dcb_dout),
    .dbg_error_max_latency  (dbg_error_max_latency),
    .dbg_error_adj_latency  (dbg_error_adj_latency),
    .dbg_pd_calib_start     (dbg_pd_calib_start),
    .dbg_pd_calib_done      (dbg_pd_calib_done),
    .dbg_phy_status         (dbg_phy_status),
    .dbg_align_rd0          (dbg_align_rd0),
    .dbg_align_rd1          (dbg_align_rd1),
    .dbg_align_fd0          (dbg_align_fd0),
    .dbg_align_fd1          (dbg_align_fd1)
  );

endmodule

/* COMMENTED OUT JBC
	`ifndef SIMULATION
            module qdr_phy_top #
            (
              parameter ADDR_WIDTH         = 20,            // JBC modifed from MIG Adress Width
              parameter DATA_WIDTH         = 18,            // JBC modifed from MIG Data Width
              parameter BW_WIDTH           = 2,             // JBC modifed from MIG Byte Write Width
              parameter BURST_LEN          = 4,             //Burst Length
              parameter CLK_PERIOD         = 5000,          // JBC modifed from MIG Internal Fabric Clk Period (ps)
              parameter REFCLK_FREQ        = 200.0,         // JBC modifed from MIG Reference Clk Feq for IODELAYs
              parameter NUM_DEVICES        = 1,             // JBC modifed from MIG  Memory Devices
              parameter FIXED_LATENCY_MODE = 0,             //Fixed Latency for data reads
              parameter PHY_LATENCY        = 0,             //Value for Fixed Latency Mode
              parameter CLK_STABLE         = 2048,          //Cycles till CQ/CQ# is stable
              parameter IODELAY_GRP        = "IODELAY200_QDRII_MIG", // JBC modifed from MIG  May be assigned unique name 
                                                            // when mult IP cores in design
              parameter MEM_TYPE           = "QDR2PLUS",    //Memory Type (QDR2PLUS, QDR2)
              parameter DEVICE_ARCH        = "virtex6",     //Device Architecture
              parameter RST_ACT_LOW        = 0,             // JBC modifed from MIG  System Reset is active low
              parameter PHASE_DETECT       = "ON",          //Enable Phase detector
              `ifdef SIMULATION
                 parameter SIM_CAL_OPTION     = "FAST_CAL",      // Skip various calibration steps
                 parameter SIM_INIT_OPTION    = "SIM_MODE",      //Simulation only. "NONE", "SIM_MODE"
              `else
                 parameter SIM_CAL_OPTION     = "NONE",      // Skip various calibration steps
                 parameter SIM_INIT_OPTION    = "NONE",      //Simulation only. "NONE", "SIM_MODE"
              `endif
              parameter IBUF_LPWR_MODE     = "OFF",         //Input buffer low power mode
              parameter IODELAY_HP_MODE    = "ON",          //IODELAY High Performance Mode
              parameter CQ_BITS            = 1,             //clog2(NUM_DEVICES - 1)   
              parameter Q_BITS             = 5,             // JBC modifed from MIG   clog2(DATA_WIDTH - 1)
              parameter DEVICE_TAPS        = 32,            // Number of taps in the IDELAY chain
              parameter TAP_BITS           = 5,             // clog2(DEVICE_TAPS - 1)
              parameter DEBUG_PORT         = "OFF",         // JBC modifed from MIG Debug using Chipscope controls 
              parameter TCQ                = 100            //Register Delay

            )
            (
              //System Signals
              input                           clk,              //main system half freq clk
              output wire                     rst_clk,          //reset sync to clk  
              input                           sys_rst,         //main write path reset 
              input                           clk_mem,          //full frequency clock
             input                            clk_wr,
              input                           mmcm_locked,      //MMCM is locked
              input                           iodelay_ctrl_rdy, //ready from IODELAY CTLR

               
              //PHY Write Path Interface
              input                           wr_cmd0,          //wr command 0
              input                           wr_cmd1,          //wr command 1
              input       [ADDR_WIDTH-1:0]    wr_addr0,         //wr address 0
              input       [ADDR_WIDTH-1:0]    wr_addr1,         //wr address 1
              input                           rd_cmd0,          //rd command 0
              input                           rd_cmd1,          //rd command 1
              input       [ADDR_WIDTH-1:0]    rd_addr0,         //rd address 0
              input       [ADDR_WIDTH-1:0]    rd_addr1,         //rd address 1
              input       [DATA_WIDTH*2-1:0]  wr_data0,         //user write data 0
              input       [DATA_WIDTH*2-1:0]  wr_data1,         //user write data 1
              input       [BW_WIDTH*2-1:0]    wr_bw_n0,         //user byte writes 0
              input       [BW_WIDTH*2-1:0]    wr_bw_n1,         //user byte writes 1

              //PHY Read Path Interface 
              output wire                     cal_done,         //Calibration complete
              output wire                     rd_valid0,        //Read valid for rd_data0
              output wire                     rd_valid1,        //Read valid for rd_data1
              output wire [DATA_WIDTH*2-1:0]  rd_data0,         //Read data 0
              output wire [DATA_WIDTH*2-1:0]  rd_data1,         //Read data 1


              //Memory Interface
              output wire                     qdr_dll_off_n,    //QDR - turn off dll in mem
              output wire [NUM_DEVICES-1:0]   qdr_k_p,          //QDR clock K
              output wire [NUM_DEVICES-1:0]   qdr_k_n,          //QDR clock K#
              output wire [ADDR_WIDTH-1:0]    qdr_sa,           //QDR Memory Address
              output wire                     qdr_w_n,          //QDR Write 
              output wire                     qdr_r_n,          //QDR Read
              output wire [BW_WIDTH-1:0]      qdr_bw_n,         //QDR Byte Writes to Mem
              output wire [DATA_WIDTH-1:0]    qdr_d,            //QDR Data to Memory
              input       [DATA_WIDTH-1:0]    qdr_q,            //QDR Data from Memory
              input       [NUM_DEVICES-1:0]   qdr_qvld,         //QDR Data Valid from Mem
              input       [NUM_DEVICES-1:0]   qdr_cq_p,         //QDR echo clock CQ 
              input       [NUM_DEVICES-1:0]   qdr_cq_n,         //QDR echo clock CQ# 

              //ChipScope Debug Signals
              output wire [1:0]                       dbg_phy_wr_cmd_n,       //cs debug - wr command
              output wire [ADDR_WIDTH*4-1:0]          dbg_phy_addr,           //cs debug - address
              output wire [1:0]                       dbg_phy_rd_cmd_n,       //cs debug - rd command
              output wire [DATA_WIDTH*4-1:0]          dbg_phy_wr_data,        //cs debug - wr data
              input                                   dbg_inc_cq_all,         // increment all CQs
              input                                   dbg_inc_cqn_all,        // increment all CQ#s
              input                                   dbg_inc_q_all,          // increment all Qs
              input                                   dbg_dec_cq_all,         // decrement all CQs   
              input                                   dbg_dec_cqn_all,        // decrement all CQ#s 
              input                                   dbg_dec_q_all,          // decrement all Qs   
              input                                   dbg_inc_cq,             // increment selected CQ  
              input                                   dbg_inc_cqn,            // increment selected CQ#
              input                                   dbg_inc_q,              // increment selected Q  
              input                                   dbg_dec_cq,             // decrement selected CQ  
              input                                   dbg_dec_cqn,            // decrement selected CQ# 
              input                                   dbg_dec_q,              // decrement selected Q   
              input [CQ_BITS-1:0]                     dbg_sel_cq,             // selected CQ bit
              input [CQ_BITS-1:0]                     dbg_sel_cqn,            // selected CQ# bit
              input [Q_BITS-1:0]                      dbg_sel_q,              // selected Q bit
              input                                   dbg_pd_off,
              output wire [TAP_BITS*NUM_DEVICES-1:0]  dbg_cq_tapcnt,          // tap count for each cq
              output wire [TAP_BITS*NUM_DEVICES-1:0]  dbg_cqn_tapcnt,         // tap count for each cq#
              output wire [TAP_BITS*DATA_WIDTH-1:0]   dbg_q_tapcnt,           // tap count for each q
              output wire [NUM_DEVICES-1:0]           dbg_clk_rd,             // clk_rd in each domain
              output wire [255:0]                     dbg_rd_stage1_cal,      // stage 1 cal debug
              output wire [127:0]                     dbg_stage2_cal,         // stage 2 cal debug
              output wire [CQ_BITS-1:0]               dbg_cq_num,             // current cq/cq# being calibrated
              output wire [Q_BITS-1:0]                dbg_q_bit,              // current q being calibrated 
              output wire [4:0]                       dbg_valid_lat,          // latency of the system
              output wire [NUM_DEVICES-1:0]           dbg_phase,              // data align phase indication
              output wire [NUM_DEVICES-1:0]           dbg_inc_latency,        // increase latency for dcb
              output wire [5*NUM_DEVICES-1:0]         dbg_dcb_wr_ptr,         // dcb write pointers
              output wire [5*NUM_DEVICES-1:0]         dbg_dcb_rd_ptr,         // dcb read pointers
              output wire [4*DATA_WIDTH-1:0]          dbg_dcb_din,            // dcb data in
              output wire [4*DATA_WIDTH-1:0]          dbg_dcb_dout,           // dcb data out
              output wire [NUM_DEVICES-1:0]           dbg_error_max_latency,  // stage 2 cal max latency error
              output wire                             dbg_error_adj_latency,  // stage 2 cal latency adjustment error   
              output wire [NUM_DEVICES-1:0]           dbg_pd_calib_start,     // indicates phase detector to start
              output wire [NUM_DEVICES-1:0]           dbg_pd_calib_done,      // indicates phase detector is complete
              output wire [7:0]                       dbg_phy_status,          // phy status
              output wire [DATA_WIDTH-1:0]            dbg_align_rd0,
              output wire [DATA_WIDTH-1:0]            dbg_align_rd1,
              output wire [DATA_WIDTH-1:0]            dbg_align_fd0,
              output wire [DATA_WIDTH-1:0]            dbg_align_fd1
            );
            endmodule
   `endif
   
   COMMENTED OUT JBC */
