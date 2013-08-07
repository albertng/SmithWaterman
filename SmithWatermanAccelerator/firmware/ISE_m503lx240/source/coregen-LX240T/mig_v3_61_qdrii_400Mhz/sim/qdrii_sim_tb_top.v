//*****************************************************************************
// (c) Copyright 2009 - 2010 Xilinx, Inc. All rights reserved.
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
//
//*****************************************************************************
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor             : Xilinx
// \   \   \/     Version            : 3.6.1
//  \   \         Application        : MIG
//  /   /         Filename           : sim_tb_top.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:48 $
// \   \  /  \    Date Created       : Thu Apr 02 2009
//  \___\/\___\
//
// Device           : Virtex-6
// Design Name      : QDRII+ SRAM
// Purpose          :
//                   Top-level testbench for testing QDRII+.
//                   Instantiates:
//                     1. IP_TOP (top-level representing FPGA, contains core,
//                        clocking, built-in testbench/memory checker and other
//                        support structures)
//                     2. QDRII+ Memory Instantiations (Samsung only)
//                     3. Miscellaneous clock generation and reset logic
// Reference        :
// Revision History :
//*****************************************************************************

`timescale  1 ps / 100 fs

module qdrii_sim_tb_top (

           output   [0:0]               c0_qdriip_cq_p,     //Memory Interface
           output   [0:0]               c0_qdriip_cq_n,
           output   [0:0]               c0_qdriip_qvld,
           output   [17:0]              c0_qdriip_q,
           
           input    [0:0]               c0_qdriip_k_p,
           input    [0:0]               c0_qdriip_k_n,
           input    [17:0]              c0_qdriip_d,
           input    [19:0]              c0_qdriip_sa,
           input                        c0_qdriip_w_n,
           input                        c0_qdriip_r_n,
           input    [1:0]               c0_qdriip_bw_n,
           input                        c0_qdriip_dll_off_n,
           
           output   [0:0]               c1_qdriip_cq_p,     //Memory Interface
           output   [0:0]               c1_qdriip_cq_n,
           output   [0:0]               c1_qdriip_qvld,
           output   [17:0]              c1_qdriip_q,
           
           input    [0:0]               c1_qdriip_k_p,
           input    [0:0]               c1_qdriip_k_n,
           input    [17:0]              c1_qdriip_d,
           input    [19:0]              c1_qdriip_sa,
           input                        c1_qdriip_w_n,
           input                        c1_qdriip_r_n,
           input    [1:0]               c1_qdriip_bw_n,
           input                        c1_qdriip_dll_off_n,
           
           output   [0:0]               c2_qdriip_cq_p,     //Memory Interface
           output   [0:0]               c2_qdriip_cq_n,
           output   [0:0]               c2_qdriip_qvld,
           output   [17:0]              c2_qdriip_q,
           
           input    [0:0]               c2_qdriip_k_p,
           input    [0:0]               c2_qdriip_k_n,
           input    [17:0]              c2_qdriip_d,
           input    [19:0]              c2_qdriip_sa,
           input                        c2_qdriip_w_n,
           input                        c2_qdriip_r_n,
           input    [1:0]               c2_qdriip_bw_n,
           input                        c2_qdriip_dll_off_n
   
);

  parameter REFCLK200_FREQ        = 200;        //Iodelay Clock Frequency
  parameter IODELAY200_GRP             = "IODELAY200_MIG";
                                       // It is associated to a set of IODELAYs with
                                       // an IDELAYCTRL that have same IODELAY CONTROLLER
                                       // clock frequency.
  parameter CLK_f0FBOUT_MULT_F    = 6;           // write PLL VCO multiplier
  parameter CLK_f0OUT_DIVIDE      = 3;           // VCO output divisor for fast (memory) clocks
  parameter DIVCLK_f0_DIVIDE      = 1;           // write PLL VCO divisor

  parameter CLK_f0_PERIOD         = 2*2858;      //Double the Memory Clk Period (in ps)

  parameter C0_DEBUG_PORT         = "OFF";       // Enable debug port
  parameter C0_CLK_STABLE         = 2048;        //Cycles till CQ/CQ# is stable
  parameter C0_ADDR_WIDTH         = 20;          //Address Width
  parameter C0_DATA_WIDTH         = 18;          //Data Width
  parameter C0_BW_WIDTH           = 2;//Byte Write Width
  parameter C0_BURST_LEN          = 4;           //Burst Length
  parameter C0_NUM_DEVICES        = 1;           //No. of Connected Memories
  parameter C0_FIXED_LATENCY_MODE = 0;           //Enable Fixed Latency
  parameter C0_PHY_LATENCY        = 0;            //Expected Latency
  parameter C0_SIM_CAL_OPTION     = "FAST_CAL";      // Skip various calibration steps
  parameter C0_SIM_INIT_OPTION    = "SIM_MODE";      //Simulation only. "NONE", "SIM_MODE"
  parameter C0_PHASE_DETECT       = "ON";       // Disable Phase detector
  parameter C0_IBUF_LPWR_MODE     = "OFF";       // Input buffer low power mode
  parameter C0_IODELAY_HP_MODE    = "ON";        // IODELAY High Performance Mode
  parameter C0_TCQ                = 100;          //Simulation Register Delay,

  parameter C1_DEBUG_PORT         = "OFF";       // Enable debug port
  parameter C1_CLK_STABLE         = 2048;        //Cycles till CQ/CQ# is stable
  parameter C1_ADDR_WIDTH         = 20;          //Address Width
  parameter C1_DATA_WIDTH         = 18;          //Data Width
  parameter C1_BW_WIDTH           = 2;//Byte Write Width
  parameter C1_BURST_LEN          = 4;           //Burst Length
  parameter C1_NUM_DEVICES        = 1;           //No. of Connected Memories
  parameter C1_FIXED_LATENCY_MODE = 0;           //Enable Fixed Latency
  parameter C1_PHY_LATENCY        = 0;            //Expected Latency
  parameter C1_SIM_CAL_OPTION     = "FAST_CAL";      // Skip various calibration steps
  parameter C1_SIM_INIT_OPTION    = "SIM_MODE";      //Simulation only. "NONE", "SIM_MODE"
  parameter C1_PHASE_DETECT       = "ON";       // Disable Phase detector
  parameter C1_IBUF_LPWR_MODE     = "OFF";       // Input buffer low power mode
  parameter C1_IODELAY_HP_MODE    = "ON";        // IODELAY High Performance Mode
  parameter C1_TCQ                = 100;          //Simulation Register Delay,

  parameter C2_DEBUG_PORT         = "OFF";       // Enable debug port
  parameter C2_CLK_STABLE         = 2048;        //Cycles till CQ/CQ# is stable
  parameter C2_ADDR_WIDTH         = 20;          //Address Width
  parameter C2_DATA_WIDTH         = 18;          //Data Width
  parameter C2_BW_WIDTH           = 2;//Byte Write Width
  parameter C2_BURST_LEN          = 4;           //Burst Length
  parameter C2_NUM_DEVICES        = 1;           //No. of Connected Memories
  parameter C2_FIXED_LATENCY_MODE = 0;           //Enable Fixed Latency
  parameter C2_PHY_LATENCY        = 0;            //Expected Latency
  parameter C2_SIM_CAL_OPTION     = "FAST_CAL";      // Skip various calibration steps
  parameter C2_SIM_INIT_OPTION    = "SIM_MODE";      //Simulation only. "NONE", "SIM_MODE"
  parameter C2_PHASE_DETECT       = "ON";       // Disable Phase detector
  parameter C2_IBUF_LPWR_MODE     = "OFF";       // Input buffer low power mode
  parameter C2_IODELAY_HP_MODE    = "ON";        // IODELAY High Performance Mode
  parameter C2_TCQ                = 100;          //Simulation Register Delay,
  parameter INPUT_CLK_TYPE     = "SINGLE_ENDED";// # of clock type
  parameter MEM_TYPE           = "QDR2PLUS";  //Memory Type (QDR2PLUS, QDR2)
  parameter DEVICE_ARCH        = "virtex6";   //Target Device family
  parameter RST_ACT_LOW        = 0;
                               // =1 for active low reset,
                               // =0 for active high.

  //**************************************************************************//
  // Local parameters Declarations
  //**************************************************************************//

  localparam C0_TPROP_PCB_CTRL     = 0.00;             //Board delay value
  localparam C0_TPROP_PCB_CQ       = (C0_SIM_CAL_OPTION == "SKIP_CAL") ?
                                  CLK_f0_PERIOD / 4 : 0.00; //CQ delay to center of Q
  localparam C0_TPROP_PCB_DATA     = 0.00;             //DQ delay value
  localparam C0_TPROP_PCB_DATA_RD  = 0.00;             //READ DQ delay value

  localparam C0_MEMORY_WIDTH          = (C0_DATA_WIDTH/C0_NUM_DEVICES); //# of memory
                                                               //component's
                                                               //data width
  localparam C0_BW_COMP = C0_MEMORY_WIDTH/9;


  localparam REFCLK200_PERIOD      = 1000000.0/REFCLK200_FREQ;//Idelay Reference clock period (ps)

  localparam SYSCLK_f0_PERIOD      = 2858; //System Clock period (ps) for clock generation



  localparam C1_TPROP_PCB_CTRL     = 0.00;             //Board delay value
  localparam C1_TPROP_PCB_CQ       = (C1_SIM_CAL_OPTION == "SKIP_CAL") ?
                                  CLK_f0_PERIOD / 4 : 0.00; //CQ delay to center of Q
  localparam C1_TPROP_PCB_DATA     = 0.00;             //DQ delay value
  localparam C1_TPROP_PCB_DATA_RD  = 0.00;             //READ DQ delay value

  localparam C1_MEMORY_WIDTH          = (C1_DATA_WIDTH/C1_NUM_DEVICES); //# of memory
                                                               //component's
                                                               //data width
  localparam C1_BW_COMP = C1_MEMORY_WIDTH/9;




  localparam C2_TPROP_PCB_CTRL     = 0.00;             //Board delay value
  localparam C2_TPROP_PCB_CQ       = (C2_SIM_CAL_OPTION == "SKIP_CAL") ?
                                  CLK_f0_PERIOD / 4 : 0.00; //CQ delay to center of Q
  localparam C2_TPROP_PCB_DATA     = 0.00;             //DQ delay value
  localparam C2_TPROP_PCB_DATA_RD  = 0.00;             //READ DQ delay value

  localparam C2_MEMORY_WIDTH          = (C2_DATA_WIDTH/C2_NUM_DEVICES); //# of memory
                                                               //component's
                                                               //data width
  localparam C2_BW_COMP = C2_MEMORY_WIDTH/9;



  // Number of QDRIIP SDRAM controllers
  localparam QDRIIP_COUNT = 3;

  //**************************************************************************//
  // Wire Declarations
  //**************************************************************************//
  reg  sys_rst_n;
  wire sys_rst;
  wire compare_error;
  wire cal_done;
  wire [QDRIIP_COUNT-1:0] compare_error_i;
  wire [QDRIIP_COUNT-1:0] cal_done_i;



   reg                      sys_clk_f0;



   reg                      clk200_ref;






   reg                     c0_qdriip_w_n_delay;
   reg                     c0_qdriip_r_n_delay;
   reg                     c0_qdriip_dll_off_n_delay;
   reg [C0_NUM_DEVICES-1:0]   c0_qdriip_k_p_delay;
   reg [C0_NUM_DEVICES-1:0]   c0_qdriip_k_n_delay;
   reg [C0_ADDR_WIDTH-1:0]    c0_qdriip_sa_delay;
   reg [C0_BW_WIDTH-1:0]      c0_qdriip_bw_n_delay;
   reg [C0_DATA_WIDTH-1:0]    c0_qdriip_d_delay;
   reg [C0_DATA_WIDTH-1:0]    c0_qdriip_q_delay;
   reg [C0_NUM_DEVICES-1:0]   c0_qdriip_qvld_delay;
   reg [C0_NUM_DEVICES-1:0]   c0_qdriip_cq_p_delay;
   reg [C0_NUM_DEVICES-1:0]   c0_qdriip_cq_n_delay;










   reg                     c1_qdriip_w_n_delay;
   reg                     c1_qdriip_r_n_delay;
   reg                     c1_qdriip_dll_off_n_delay;
   reg [C1_NUM_DEVICES-1:0]   c1_qdriip_k_p_delay;
   reg [C1_NUM_DEVICES-1:0]   c1_qdriip_k_n_delay;
   reg [C1_ADDR_WIDTH-1:0]    c1_qdriip_sa_delay;
   reg [C1_BW_WIDTH-1:0]      c1_qdriip_bw_n_delay;
   reg [C1_DATA_WIDTH-1:0]    c1_qdriip_d_delay;
   reg [C1_DATA_WIDTH-1:0]    c1_qdriip_q_delay;
   reg [C1_NUM_DEVICES-1:0]   c1_qdriip_qvld_delay;
   reg [C1_NUM_DEVICES-1:0]   c1_qdriip_cq_p_delay;
   reg [C1_NUM_DEVICES-1:0]   c1_qdriip_cq_n_delay;














   reg                     c2_qdriip_w_n_delay;
   reg                     c2_qdriip_r_n_delay;
   reg                     c2_qdriip_dll_off_n_delay;
   reg [C2_NUM_DEVICES-1:0]   c2_qdriip_k_p_delay;
   reg [C2_NUM_DEVICES-1:0]   c2_qdriip_k_n_delay;
   reg [C2_ADDR_WIDTH-1:0]    c2_qdriip_sa_delay;
   reg [C2_BW_WIDTH-1:0]      c2_qdriip_bw_n_delay;
   reg [C2_DATA_WIDTH-1:0]    c2_qdriip_d_delay;
   reg [C2_DATA_WIDTH-1:0]    c2_qdriip_q_delay;
   reg [C2_NUM_DEVICES-1:0]   c2_qdriip_qvld_delay;
   reg [C2_NUM_DEVICES-1:0]   c2_qdriip_cq_p_delay;
   reg [C2_NUM_DEVICES-1:0]   c2_qdriip_cq_n_delay;






  //**************************************************************************//
  // Reset Generation
  //**************************************************************************//
  initial begin
    sys_rst_n = 1'b0;
    #200000
      sys_rst_n = 1'b1;
   end

   assign sys_rst = RST_ACT_LOW ? sys_rst_n : ~sys_rst_n;

  //**************************************************************************//
  // Clock Generation
  //**************************************************************************//

  // Generate system clock = twice rate of CLK

   initial
     sys_clk_f0    = 1'b0;
   // Generate design clock
   always #(SYSCLK_f0_PERIOD/2) sys_clk_f0 = ~sys_clk_f0;



   initial
     clk200_ref     = 1'b0;
   // Generate 200MHz reference clock
   always #(REFCLK200_PERIOD/2) clk200_ref = ~clk200_ref;




  // Generate system clock = twice rate of CLK






  // Generate system clock = twice rate of CLK






  //**************************************************************************//
  //                            BOARD Parameters
  //**************************************************************************//
  //These parameter values can be changed to model varying board delays
  //between the Virtex-6 device and the QDR II memory model


   always @*
   begin
     c0_qdriip_k_p_delay       <= #C0_TPROP_PCB_CTRL    c0_qdriip_k_p;
     c0_qdriip_k_n_delay       <= #C0_TPROP_PCB_CTRL    c0_qdriip_k_n;
     c0_qdriip_sa_delay        <= #C0_TPROP_PCB_CTRL    c0_qdriip_sa;
     c0_qdriip_bw_n_delay      <= #C0_TPROP_PCB_CTRL    c0_qdriip_bw_n;
     c0_qdriip_w_n_delay       <= #C0_TPROP_PCB_CTRL    c0_qdriip_w_n;
     c0_qdriip_d_delay         <= #C0_TPROP_PCB_DATA    c0_qdriip_d;
     c0_qdriip_r_n_delay       <= #C0_TPROP_PCB_CTRL    c0_qdriip_r_n;
     c0_qdriip_q_delay         <= #C0_TPROP_PCB_DATA_RD c0_qdriip_q;
     c0_qdriip_qvld_delay      <= #C0_TPROP_PCB_DATA_RD c0_qdriip_qvld;
     c0_qdriip_cq_p_delay      <= #C0_TPROP_PCB_CQ      c0_qdriip_cq_p;
     c0_qdriip_cq_n_delay      <= #C0_TPROP_PCB_CQ      c0_qdriip_cq_n;
     c0_qdriip_dll_off_n_delay <= #C0_TPROP_PCB_CTRL    c0_qdriip_dll_off_n;
   end





   always @*
   begin
     c1_qdriip_k_p_delay       <= #C1_TPROP_PCB_CTRL    c1_qdriip_k_p;
     c1_qdriip_k_n_delay       <= #C1_TPROP_PCB_CTRL    c1_qdriip_k_n;
     c1_qdriip_sa_delay        <= #C1_TPROP_PCB_CTRL    c1_qdriip_sa;
     c1_qdriip_bw_n_delay      <= #C1_TPROP_PCB_CTRL    c1_qdriip_bw_n;
     c1_qdriip_w_n_delay       <= #C1_TPROP_PCB_CTRL    c1_qdriip_w_n;
     c1_qdriip_d_delay         <= #C1_TPROP_PCB_DATA    c1_qdriip_d;
     c1_qdriip_r_n_delay       <= #C1_TPROP_PCB_CTRL    c1_qdriip_r_n;
     c1_qdriip_q_delay         <= #C1_TPROP_PCB_DATA_RD c1_qdriip_q;
     c1_qdriip_qvld_delay      <= #C1_TPROP_PCB_DATA_RD c1_qdriip_qvld;
     c1_qdriip_cq_p_delay      <= #C1_TPROP_PCB_CQ      c1_qdriip_cq_p;
     c1_qdriip_cq_n_delay      <= #C1_TPROP_PCB_CQ      c1_qdriip_cq_n;
     c1_qdriip_dll_off_n_delay <= #C1_TPROP_PCB_CTRL    c1_qdriip_dll_off_n;
   end





   always @*
   begin
     c2_qdriip_k_p_delay       <= #C2_TPROP_PCB_CTRL    c2_qdriip_k_p;
     c2_qdriip_k_n_delay       <= #C2_TPROP_PCB_CTRL    c2_qdriip_k_n;
     c2_qdriip_sa_delay        <= #C2_TPROP_PCB_CTRL    c2_qdriip_sa;
     c2_qdriip_bw_n_delay      <= #C2_TPROP_PCB_CTRL    c2_qdriip_bw_n;
     c2_qdriip_w_n_delay       <= #C2_TPROP_PCB_CTRL    c2_qdriip_w_n;
     c2_qdriip_d_delay         <= #C2_TPROP_PCB_DATA    c2_qdriip_d;
     c2_qdriip_r_n_delay       <= #C2_TPROP_PCB_CTRL    c2_qdriip_r_n;
     c2_qdriip_q_delay         <= #C2_TPROP_PCB_DATA_RD c2_qdriip_q;
     c2_qdriip_qvld_delay      <= #C2_TPROP_PCB_DATA_RD c2_qdriip_qvld;
     c2_qdriip_cq_p_delay      <= #C2_TPROP_PCB_CQ      c2_qdriip_cq_p;
     c2_qdriip_cq_n_delay      <= #C2_TPROP_PCB_CQ      c2_qdriip_cq_n;
     c2_qdriip_dll_off_n_delay <= #C2_TPROP_PCB_CTRL    c2_qdriip_dll_off_n;
   end


  //**************************************************************************//
  // Memory Models instantiations
  //**************************************************************************//

  // MIG does not output Cypress memory models. You have to instantiate the
  // appropriate Cypress memory model for the cypress controller designs
  // generated from MIG. Memory model instance name must be modified as per 
  // the model downloaded from the memory vendor website
  genvar c0_i;
  generate
    for(c0_i=0; c0_i<C0_NUM_DEVICES; c0_i=c0_i+1)begin : C0_COMP_INST
      cyqdr2_b4_18 QDR2PLUS_MEM
        (
         .TCK   ( 1'b0 ),
         .TMS   ( 1'b1 ),
         .TDI   ( 1'b1 ),
         .TDO   (),
         .D     ( c0_qdriip_d_delay[(C0_MEMORY_WIDTH*c0_i)+:C0_MEMORY_WIDTH] ),
         .Q     ( c0_qdriip_q [(C0_MEMORY_WIDTH*c0_i)+:C0_MEMORY_WIDTH]),
         .A     ( c0_qdriip_sa_delay ),
         .K     ( c0_qdriip_k_p_delay[c0_i] ),
         .Kb    ( c0_qdriip_k_n_delay[c0_i] ),
         .RPSb  ( c0_qdriip_r_n_delay ),
         .WPSb  ( c0_qdriip_w_n_delay ),
         .BWS0b ( c0_qdriip_bw_n_delay[(c0_i*C0_BW_COMP)] ),
         .BWS1b ( c0_qdriip_bw_n_delay[(c0_i*C0_BW_COMP)+1] ),
         .CQ    ( c0_qdriip_cq_p[c0_i] ),
         .CQb   ( c0_qdriip_cq_n[c0_i] ),
		 .ZQ    ( 1'b1 ),
         .DOFF  ( c0_qdriip_dll_off_n_delay ),
         .QVLD  ( c0_qdriip_qvld[c0_i] )
         );
    end
  endgenerate

  // MIG does not output Cypress memory models. You have to instantiate the
  // appropriate Cypress memory model for the cypress controller designs
  // generated from MIG. Memory model instance name must be modified as per 
  // the model downloaded from the memory vendor website
  genvar c1_i;
  generate
    for(c1_i=0; c1_i<C1_NUM_DEVICES; c1_i=c1_i+1)begin : C1_COMP_INST
      cyqdr2_b4_18 QDR2PLUS_MEM
        (
         .TCK   ( 1'b0 ),
         .TMS   ( 1'b1 ),
         .TDI   ( 1'b1 ),
         .TDO   (),
         .D     ( c1_qdriip_d_delay[(C1_MEMORY_WIDTH*c1_i)+:C1_MEMORY_WIDTH] ),
         .Q     ( c1_qdriip_q [(C1_MEMORY_WIDTH*c1_i)+:C1_MEMORY_WIDTH]),
         .A     ( c1_qdriip_sa_delay ),
         .K     ( c1_qdriip_k_p_delay[c1_i] ),
         .Kb    ( c1_qdriip_k_n_delay[c1_i] ),
         .RPSb  ( c1_qdriip_r_n_delay ),
         .WPSb  ( c1_qdriip_w_n_delay ),
         .BWS0b ( c1_qdriip_bw_n_delay[(c1_i*C1_BW_COMP)] ),
         .BWS1b ( c1_qdriip_bw_n_delay[(c1_i*C1_BW_COMP)+1] ),
         .CQ    ( c1_qdriip_cq_p[c1_i] ),
         .CQb   ( c1_qdriip_cq_n[c1_i] ),
		 .ZQ    ( 1'b1 ),
         .DOFF  ( c1_qdriip_dll_off_n_delay ),
         .QVLD  ( c1_qdriip_qvld[c1_i] )
         );
    end
  endgenerate

  // MIG does not output Cypress memory models. You have to instantiate the
  // appropriate Cypress memory model for the cypress controller designs
  // generated from MIG. Memory model instance name must be modified as per 
  // the model downloaded from the memory vendor website
  genvar c2_i;
  generate
    for(c2_i=0; c2_i<C2_NUM_DEVICES; c2_i=c2_i+1)begin : C2_COMP_INST
      cyqdr2_b4_18 QDR2PLUS_MEM
        (
         .TCK   ( 1'b0 ),
         .TMS   ( 1'b1 ),
         .TDI   ( 1'b1 ),
         .TDO   (),
         .D     ( c2_qdriip_d_delay[(C2_MEMORY_WIDTH*c2_i)+:C2_MEMORY_WIDTH] ),
         .Q     ( c2_qdriip_q [(C2_MEMORY_WIDTH*c2_i)+:C2_MEMORY_WIDTH]),
         .A     ( c2_qdriip_sa_delay ),
         .K     ( c2_qdriip_k_p_delay[c2_i] ),
         .Kb    ( c2_qdriip_k_n_delay[c2_i] ),
         .RPSb  ( c2_qdriip_r_n_delay ),
         .WPSb  ( c2_qdriip_w_n_delay ),
         .BWS0b ( c2_qdriip_bw_n_delay[(c2_i*C2_BW_COMP)] ),
         .BWS1b ( c2_qdriip_bw_n_delay[(c2_i*C2_BW_COMP)+1] ),
         .CQ    ( c2_qdriip_cq_p[c2_i] ),
         .CQb   ( c2_qdriip_cq_n[c2_i] ),
		 .ZQ    ( 1'b1 ),
         .DOFF  ( c2_qdriip_dll_off_n_delay ),
         .QVLD  ( c2_qdriip_qvld[c2_i] )
         );
    end
  endgenerate

  
endmodule
