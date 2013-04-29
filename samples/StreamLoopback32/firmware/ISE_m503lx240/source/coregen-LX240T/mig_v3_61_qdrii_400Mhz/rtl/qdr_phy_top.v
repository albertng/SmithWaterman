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
//  /   /         Filename           : qdr_phy_top.v
// /___/   /\     Date Last Modified : $date$
// \   \  /  \    Date Created       : Nov 18, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+
//
//Purpose:
//    This module
//  1. Instantiates all the modules used in the PHY
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps
(* X_CORE_INFO = "mig_v3_61_qdriip_V6, Coregen 12.4" , CORE_GENERATION_INFO = "qdriip_V6,mig_v3_61,{LANGUAGE=Verilog, SYNTHESIS_TOOL=ISE, AXI_ENABLE=0, LEVEL=PHY, NO_OF_CONTROLLERS=3, C0_INTERFACE_TYPE=QDR_II+_SRAM, CLK_f0_PERIOD=5716, C0_MEMORY_TYPE=components, C0_MEMORY_PART=cy7c1563v18-400bzxc, C0_DQ_WIDTH=18, C0_NUM_DEVICES=1, C0_FIXED_LATENCY_MODE=0, C0_PHY_LATENCY=0, REFCLK200_FREQ=200, MMCM_ADV_BANDWIDTH_f0=OPTIMIZED, CLK_f0FBOUT_MULT_F=8, CLK_f0OUT_DIVIDE=4, C0_DEBUG_PORT=OFF, C0_IODELAY_HP_MODE=ON, C0_INTERNAL_VREF=1, C0_DCI_INOUTS=1, INPUT_CLK_TYPE=SINGLE_ENDED,C1_INTERFACE_TYPE=QDR_II+_SRAM, CLK_f0_PERIOD=5716, C1_MEMORY_TYPE=components, C1_MEMORY_PART=cy7c1563v18-400bzxc, C1_DQ_WIDTH=18, C1_NUM_DEVICES=1, C1_FIXED_LATENCY_MODE=0, C1_PHY_LATENCY=0, REFCLK200_FREQ=200, MMCM_ADV_BANDWIDTH_f0=OPTIMIZED, CLK_f0FBOUT_MULT_F=8, CLK_f0OUT_DIVIDE=4, C1_DEBUG_PORT=OFF, C1_IODELAY_HP_MODE=ON, C1_INTERNAL_VREF=1, C1_DCI_INOUTS=1, INPUT_CLK_TYPE=SINGLE_ENDED,C2_INTERFACE_TYPE=QDR_II+_SRAM, CLK_f0_PERIOD=5716, C2_MEMORY_TYPE=components, C2_MEMORY_PART=cy7c1563v18-400bzxc, C2_DQ_WIDTH=18, C2_NUM_DEVICES=1, C2_FIXED_LATENCY_MODE=0, C2_PHY_LATENCY=0, REFCLK200_FREQ=200, MMCM_ADV_BANDWIDTH_f0=OPTIMIZED, CLK_f0FBOUT_MULT_F=8, CLK_f0OUT_DIVIDE=4, C2_DEBUG_PORT=OFF, C2_IODELAY_HP_MODE=ON, C2_INTERNAL_VREF=1, C2_DCI_INOUTS=1, INPUT_CLK_TYPE=SINGLE_ENDED}" *)
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

  // Width of each memory
  localparam integer MEMORY_WIDTH = DATA_WIDTH / NUM_DEVICES;
  
  //Wire Delcarations
  wire                            rst_wr_clk;
  wire                            cal_stage1_start;
  wire                            cal_stage2_start;
  wire                            init_done;
  wire [1:0]                      int_rd_cmd_n;
  wire [NUM_DEVICES-1:0]          clk_rd /* synthesis syn_keep = 1 */;
  wire [NUM_DEVICES-1:0]          rst_clk_rd;
  wire [1:0]                      int_wr_cmd_n;
  wire [ADDR_WIDTH-1:0]           iob_addr_rise0;
  wire [ADDR_WIDTH-1:0]           iob_addr_fall0; 
  wire [ADDR_WIDTH-1:0]           iob_addr_rise1; 
  wire [ADDR_WIDTH-1:0]           iob_addr_fall1; 
  wire [DATA_WIDTH-1:0]           iob_data_rise0;
  wire [DATA_WIDTH-1:0]           iob_data_fall0; 
  wire [DATA_WIDTH-1:0]           iob_data_rise1;
  wire [DATA_WIDTH-1:0]           iob_data_fall1; 
  wire [BW_WIDTH-1:0]             iob_bw_rise0;  
  wire [BW_WIDTH-1:0]             iob_bw_fall0; 
  wire [BW_WIDTH-1:0]             iob_bw_rise1;  
  wire [BW_WIDTH-1:0]             iob_bw_fall1; 
  wire [NUM_DEVICES-1:0]          cq_dly_ce;
  wire [NUM_DEVICES-1:0]          cq_dly_inc;
  wire [NUM_DEVICES-1:0]          cq_dly_rst;
  wire [TAP_BITS*NUM_DEVICES-1:0] cq_dly_load;
  wire [NUM_DEVICES-1:0]          cqn_dly_ce;
  wire [NUM_DEVICES-1:0]          cqn_dly_inc;
  wire [NUM_DEVICES-1:0]          cqn_dly_rst;
  wire [TAP_BITS*NUM_DEVICES-1:0] cqn_dly_load;
  wire [DATA_WIDTH-1:0]           q_dly_ce;
  wire [NUM_DEVICES-1:0]          q_dly_inc;
  wire [DATA_WIDTH-1:0]           q_dly_rst;
  wire [TAP_BITS*NUM_DEVICES-1:0] q_dly_load;
  wire [NUM_DEVICES-1:0]          q_dly_clkinv;
  wire [NUM_DEVICES-1:0]          iserdes_rst;
  wire [DATA_WIDTH-1:0]           iserdes_rd0;
  wire [DATA_WIDTH-1:0]           iserdes_fd0;
  wire [DATA_WIDTH-1:0]           iserdes_rd1;
  wire [DATA_WIDTH-1:0]           iserdes_fd1;
  wire [NUM_DEVICES-1:0]          clk_cq;
  wire [NUM_DEVICES-1:0]          clk_cqn;
  wire [NUM_DEVICES-1:0]          pd_source;

  //Instantiate the Top of the Write Path
  phy_write_top #(
    .BURST_LEN        (BURST_LEN),
    .REFCLK_FREQ      (REFCLK_FREQ),
    .CLK_PERIOD       (CLK_PERIOD),
    .NUM_DEVICES      (NUM_DEVICES),
    .DATA_WIDTH       (DATA_WIDTH),
    .BW_WIDTH         (BW_WIDTH),
    .ADDR_WIDTH       (ADDR_WIDTH),
    .IODELAY_GRP      (IODELAY_GRP),
    .TCQ              (TCQ)
  ) u_phy_write_top (
    .clk              (clk),            
    .rst_wr_clk       (rst_wr_clk), 
    .clk_mem          (clk_mem),  
    .cal_done         (cal_done),  
    .cal_stage1_start (cal_stage1_start),
    .cal_stage2_start (cal_stage2_start),
    .init_done        (init_done), 
    .int_rd_cmd_n     (int_rd_cmd_n),
    .int_wr_cmd_n     (int_wr_cmd_n),
    .wr_cmd0          (wr_cmd0),
    .wr_cmd1          (wr_cmd1),
    .wr_addr0         (wr_addr0),
    .wr_addr1         (wr_addr1), 
    .rd_cmd0          (rd_cmd0), 
    .rd_cmd1          (rd_cmd1), 
    .rd_addr0         (rd_addr0), 
    .rd_addr1         (rd_addr1),  
    .wr_data0         (wr_data0), 
    .wr_data1         (wr_data1),  
    .wr_bw_n0         (wr_bw_n0),  
    .wr_bw_n1         (wr_bw_n1),
    .iob_addr_rise0   (iob_addr_rise0), 
    .iob_addr_fall0   (iob_addr_fall0), 
    .iob_addr_rise1   (iob_addr_rise1), 
    .iob_addr_fall1   (iob_addr_fall1),
    .iob_data_rise0   (iob_data_rise0),
    .iob_data_fall0   (iob_data_fall0), 
    .iob_data_rise1   (iob_data_rise1),
    .iob_data_fall1   (iob_data_fall1),
    .iob_bw_rise0     (iob_bw_rise0), 
    .iob_bw_fall0     (iob_bw_fall0), 
    .iob_bw_rise1     (iob_bw_rise1),  
    .iob_bw_fall1     (iob_bw_fall1),
    .dbg_phy_wr_cmd_n (dbg_phy_wr_cmd_n),
    .dbg_phy_addr     (dbg_phy_addr),    
    .dbg_phy_rd_cmd_n (dbg_phy_rd_cmd_n),
    .dbg_phy_wr_data  (dbg_phy_wr_data)
  );

  //Instantiate the top of the read path
  phy_read_top #(
    .BURST_LEN          (BURST_LEN),
    .DATA_WIDTH         (DATA_WIDTH),
    .NUM_DEVICES        (NUM_DEVICES),
    .FIXED_LATENCY_MODE (FIXED_LATENCY_MODE),
    .PHY_LATENCY        (PHY_LATENCY),
    .CLK_PERIOD         (CLK_PERIOD),
    .REFCLK_FREQ        (REFCLK_FREQ),
    .PHASE_DETECT       (PHASE_DETECT),
    .DEVICE_TAPS        (DEVICE_TAPS),
    .TAP_BITS           (TAP_BITS),
    .MEMORY_WIDTH       (MEMORY_WIDTH),
    .IODELAY_GRP        (IODELAY_GRP),
    .SIM_CAL_OPTION     (SIM_CAL_OPTION),
    .SIM_INIT_OPTION    (SIM_INIT_OPTION),
    .MEM_TYPE           (MEM_TYPE),
    .CQ_BITS            (CQ_BITS),
    .Q_BITS             (Q_BITS),
    .DEBUG_PORT         (DEBUG_PORT),
    .TCQ                (TCQ)
  ) u_phy_read_top (
    .clk                    (clk),
    .clk_rd                 (clk_rd),
    .rst_clk                (rst_clk),
    .rst_clk_rd             (rst_clk_rd),
    .cq_dly_ce              (cq_dly_ce),
    .cq_dly_inc             (cq_dly_inc),
    .cq_dly_rst             (cq_dly_rst),
    .cq_dly_load            (cq_dly_load),
    .cqn_dly_ce             (cqn_dly_ce),
    .cqn_dly_inc            (cqn_dly_inc),
    .cqn_dly_rst            (cqn_dly_rst),
    .cqn_dly_load           (cqn_dly_load),
    .q_dly_ce               (q_dly_ce),
    .q_dly_inc              (q_dly_inc),
    .q_dly_rst              (q_dly_rst),
    .q_dly_load             (q_dly_load),
    .q_dly_clkinv           (q_dly_clkinv),
    .iserdes_rst            (iserdes_rst),
    .iserdes_rd0            (iserdes_rd0),
    .iserdes_fd0            (iserdes_fd0),
    .iserdes_rd1            (iserdes_rd1),
    .iserdes_fd1            (iserdes_fd1),
    .cal_done               (cal_done),
    .rd_data0               (rd_data0),
    .rd_data1               (rd_data1),
    .rd_valid0              (rd_valid0),
    .rd_valid1              (rd_valid1),
    .init_done              (init_done),
    .cal_stage1_start       (cal_stage1_start),
    .cal_stage2_start       (cal_stage2_start),
    .int_rd_cmd_n           (int_rd_cmd_n),
    .clk_cq                 (clk_cq),
    .clk_cqn                (clk_cqn),
    .pd_source              (pd_source),
    .clk_mem                (clk_mem),
    .clk_wr                 (clk_wr),
    .rst_wr_clk             (rst_wr_clk),
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
    .dbg_align_rd0          (dbg_align_rd0),
    .dbg_align_rd1          (dbg_align_rd1),
    .dbg_align_fd0          (dbg_align_fd0),
    .dbg_align_fd1          (dbg_align_fd1)
  );  

  //Instantiate the IOB module
  phy_iob #(
    .DATA_WIDTH       (DATA_WIDTH),
    .ADDR_WIDTH       (ADDR_WIDTH),
    .BW_WIDTH         (BW_WIDTH),
    .REFCLK_FREQ      (REFCLK_FREQ),
    .CLK_PERIOD       (CLK_PERIOD),
    .BURST_LEN        (BURST_LEN),
    .NUM_DEVICES      (NUM_DEVICES),
    .IODELAY_GRP      (IODELAY_GRP),
    .DEVICE_TAPS      (DEVICE_TAPS),
    .TAP_BITS         (TAP_BITS),
    .MEMORY_WIDTH     (MEMORY_WIDTH),
    .IBUF_LPWR_MODE   (IBUF_LPWR_MODE),
    .IODELAY_HP_MODE  (IODELAY_HP_MODE),
    .SIM_INIT_OPTION  (SIM_INIT_OPTION),
    .TCQ              (TCQ)
  ) u_phy_iob (
    .clk             (clk),         
    .rst_clk         (rst_clk),   
    .rst_wr_clk      (rst_wr_clk), 
    .clk_mem         (clk_mem),
    .clk_rd          (clk_rd),
    .rst_clk_rd      (rst_clk_rd),
    .int_rd_cmd_n    (int_rd_cmd_n),
    .int_wr_cmd_n    (int_wr_cmd_n),     
    .iob_addr_rise0  (iob_addr_rise0), 
    .iob_addr_fall0  (iob_addr_fall0), 
    .iob_addr_rise1  (iob_addr_rise1), 
    .iob_addr_fall1  (iob_addr_fall1),
    .iob_data_rise0  (iob_data_rise0),
    .iob_data_fall0  (iob_data_fall0), 
    .iob_data_rise1  (iob_data_rise1),
    .iob_data_fall1  (iob_data_fall1),
    .iob_bw_rise0    (iob_bw_rise0), 
    .iob_bw_fall0    (iob_bw_fall0), 
    .iob_bw_rise1    (iob_bw_rise1),  
    .iob_bw_fall1    (iob_bw_fall1),
    .clk_cq          (clk_cq),
    .clk_cqn         (clk_cqn),
    .pd_source       (pd_source),
    .cq_dly_ce       (cq_dly_ce),
    .cq_dly_inc      (cq_dly_inc),
    .cq_dly_rst      (cq_dly_rst),
    .cq_dly_load     (cq_dly_load),    
    .cqn_dly_ce      (cqn_dly_ce),
    .cqn_dly_inc     (cqn_dly_inc),
    .cqn_dly_rst     (cqn_dly_rst),
    .cqn_dly_load    (cqn_dly_load),  
    .q_dly_ce        (q_dly_ce),
    .q_dly_inc       (q_dly_inc),
    .q_dly_rst       (q_dly_rst),
    .q_dly_load      (q_dly_load),
    .dbg_cq_tapcnt   (dbg_cq_tapcnt), 
    .dbg_cqn_tapcnt  (dbg_cqn_tapcnt),
    .dbg_q_tapcnt    (dbg_q_tapcnt),
    .q_dly_clkinv    (q_dly_clkinv),
    .iserdes_rst     (iserdes_rst),
    .iserdes_rd0     (iserdes_rd0),
    .iserdes_fd0     (iserdes_fd0),
    .iserdes_rd1     (iserdes_rd1),
    .iserdes_fd1     (iserdes_fd1),
    .mem_k_p         (qdr_k_p),  
    .mem_k_n         (qdr_k_n),
    .mem_sa          (qdr_sa),          
    .mem_r_n         (qdr_r_n),          
    .mem_w_n         (qdr_w_n),          
    .mem_d           (qdr_d),         
    .mem_bw_n        (qdr_bw_n),
    .mem_cq_p        (qdr_cq_p),
    .mem_cq_n        (qdr_cq_n),
    .mem_q           (qdr_q),
    .dbg_clk_rd      (dbg_clk_rd)
  );

  //Instantiate the Top of the Reset
  phy_reset_sync #(
    .CLK_STABLE       (CLK_STABLE),
    .CLK_PERIOD       (CLK_PERIOD),
    .RST_ACT_LOW      (RST_ACT_LOW),
    .NUM_DEVICES      (NUM_DEVICES),
    .SIM_INIT_OPTION  (SIM_INIT_OPTION),
    .TCQ              (TCQ)
  ) u_phy_reset_sync (
    .sys_rst            (sys_rst),       
    .clk                (clk),            
    .rst_clk            (rst_clk),        
    .rst_wr_clk         (rst_wr_clk),    
    .clk_rd             (clk_rd),  
    .rst_clk_rd         (rst_clk_rd),  
    .mmcm_locked        (mmcm_locked),     
    .iodelay_ctrl_rdy   (iodelay_ctrl_rdy),
    .mem_dll_off_n      (qdr_dll_off_n)  
  );


  // Debug signals
  assign dbg_phy_status[0] = iodelay_ctrl_rdy; 
  assign dbg_phy_status[1] = mmcm_locked; 
  assign dbg_phy_status[2] = init_done; 
  assign dbg_phy_status[3] = cal_stage1_start;
  assign dbg_phy_status[4] = cal_stage2_start;
  assign dbg_phy_status[5] = |dbg_pd_calib_start;
  assign dbg_phy_status[6] = |dbg_pd_calib_done;
  assign dbg_phy_status[7] = cal_done;

endmodule
