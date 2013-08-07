//*****************************************************************************
//(c) Copyright 2006 - 2009 Xilinx, Inc. All rights reserved.
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
// /___/  \  /    Vendor             : Xilinx
// \   \   \/     Version            : 3.6.1 
//  \   \         Application        : MIG
//  /   /         Filename           : qdr_rld_infrastructure.v
// /___/   /\     Date Last Modified : $Date: 2010/10/28 08:40:25 $
// \   \  /  \    Date Created       : November 19, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design Name: QDRII+ / RLDRAM-II
//
//Purpose:
//   Clock generation/distribution and reset synchronization
//Reference:
//Revision History:
//*****************************************************************************

`timescale 1 ps/1 ps

module qdr_rld_infrastructure #(
  parameter RST_ACT_LOW        = 1,             //Active Low Reset
  parameter CLK_PERIOD         = 3752,          //Internal fabric Clk Period (in ps)
  parameter MMCM_ADV_BANDWIDTH = "OPTIMIZED", // MMCM programming algorithm
  parameter CLKFBOUT_MULT_F    = 4,             // write PLL VCO multiplier
  parameter CLKOUT_DIVIDE      = 4,             // VCO output divisor for fast (memory) clocks
  parameter DIVCLK_DIVIDE      = 1,             // write PLL VCO divisor
  parameter NUM_DEVICES        = 2              //No. of Connected Memories
)
(
  input       mmcm_clk,        // MMCM clk input
  input       sys_rst,          //system reset
  output wire clk0,             //full frequency system clock
  output wire clkdiv0,          //half frequency system clock
  output wire clk_wr,
  output wire mmcm_locked       //mmcm is locked
);

  wire                       sys_rst_act_hi;
  wire                       clk0_bufg;
  wire                       clk0_mmcm;
  wire                       clkdiv0_bufg;
  wire                       clkdiv0_mmcm;
  wire                       clkfbout_mmcm;

  //Clk period in nanosecond used for mmcm clock generation
  //divide clk_period by 2 to get the external memory frequency
  localparam CLK_PERIOD_NS = (CLK_PERIOD/2) / (1000.0);

  localparam CLKOUT0_DIVIDE_F = CLKOUT_DIVIDE;
  localparam CLKOUT1_DIVIDE   = CLKOUT_DIVIDE * 2; // output div for fabric clk 
  localparam CLKOUT2_DIVIDE   = CLKOUT_DIVIDE;
  localparam CLKOUT3_DIVIDE   = CLKOUT_DIVIDE;

  localparam integer VCO_PERIOD = (DIVCLK_DIVIDE * CLK_PERIOD)/(CLKFBOUT_MULT_F * 2);
  localparam CLKOUT2_PERIOD     = VCO_PERIOD * CLKOUT2_DIVIDE  ;

  //***************************************************************************
  // Assign global clocks:
  //   1. CLK200  : IDELAYCTRL reference
  //   2. CLK0    : Full rate (used only for IOB) 
  //   3. CLKDIV0 : Half rate (used for majority of internal logic)
  //***************************************************************************
  
  assign clk0       = clk0_bufg;
  assign clkdiv0    = clkdiv0_bufg;

  assign  sys_rst_act_hi = RST_ACT_LOW ? ~sys_rst: sys_rst;


  //***************************************************************************
  // Global base clock generation and distribution  
  //***************************************************************************

  //*****************************************************************
  // VCCO freq = M * (input clock) = [400MHz, 1000MHz] ([400,1200] for -3)
  // Expect input frequency to be in range [300MHz, 550MHz], choose M = 2
  // such that VCCO frequency = [600MHz, 1.1MHz]
  //*****************************************************************

  MMCM_ADV #(
    .BANDWIDTH              (MMCM_ADV_BANDWIDTH),
    .CLOCK_HOLD             ("FALSE"),
    .STARTUP_WAIT           ("FALSE"),
    .COMPENSATION           ("INTERNAL"),
    .REF_JITTER1            (0.005),
    .REF_JITTER2            (0.005),
    .CLKOUT0_DIVIDE_F       (CLKOUT0_DIVIDE_F),
    .CLKOUT1_DIVIDE         (CLKOUT1_DIVIDE),
    .CLKOUT2_DIVIDE         (CLKOUT2_DIVIDE),
    .CLKOUT3_DIVIDE         (CLKOUT3_DIVIDE),
    .CLKOUT4_DIVIDE         (1),
    .CLKOUT5_DIVIDE         (1),
    .CLKOUT6_DIVIDE         (1),
    .DIVCLK_DIVIDE          (DIVCLK_DIVIDE),
    .CLKFBOUT_MULT_F        (CLKFBOUT_MULT_F),
    .CLKFBOUT_PHASE         (0.000),
    .CLKIN1_PERIOD          (5.000),  //JBC
    .CLKIN2_PERIOD          (10.000),
    .CLKOUT0_DUTY_CYCLE     (0.500),
    .CLKOUT0_PHASE          (0.000),
    .CLKOUT1_DUTY_CYCLE     (0.500),
    .CLKOUT1_PHASE          (0.000),
    .CLKOUT2_DUTY_CYCLE     (0.500),
    .CLKOUT2_PHASE          (0.000),
    .CLKOUT3_DUTY_CYCLE     (0.500),
    .CLKOUT3_PHASE          (0.000),
    .CLKOUT4_DUTY_CYCLE     (0.500),
    .CLKOUT4_PHASE          (0.000),
    .CLKOUT5_DUTY_CYCLE     (0.500),
    .CLKOUT5_PHASE          (0.000),
    .CLKOUT6_DUTY_CYCLE     (0.500),
    .CLKOUT6_PHASE          (0.000),
    .CLKOUT0_USE_FINE_PS    ("TRUE"),
    .CLKOUT1_USE_FINE_PS    ("TRUE"),
    .CLKOUT2_USE_FINE_PS    ("TRUE"),
    .CLKOUT3_USE_FINE_PS    ("FALSE"),
    .CLKOUT4_USE_FINE_PS    ("FALSE"),
    .CLKOUT5_USE_FINE_PS    ("FALSE"),
    .CLKOUT6_USE_FINE_PS    ("FALSE")
  ) u_mmcm_gen (
    .CLKFBOUT          (clkfbout_mmcm),
    .CLKFBOUTB         (),
    .CLKFBSTOPPED      (),
    .CLKINSTOPPED      (),
    .CLKOUT0           (clk0_mmcm),
    .CLKOUT0B          (),
    .CLKOUT1           (clkdiv0_mmcm),
    .CLKOUT1B          (),
    .CLKOUT2           (clk_wr),
    .CLKOUT2B          (),
    .CLKOUT3           (),
    .CLKOUT3B          (),
    .CLKOUT4           (),
    .CLKOUT5           (),
    .CLKOUT6           (),
    .DO                (),
    .DRDY              (),
    .LOCKED            (mmcm_locked),
    .PSDONE            (),
    .CLKFBIN           (clkfbout_mmcm),
    .CLKIN1            (mmcm_clk),
    .CLKIN2            (1'b0),
    .CLKINSEL          (1'b1),
    .DADDR             (7'b0000000),
    .DCLK              (1'b0),
    .DEN               (1'b0),
    .DI                (16'h0000),
    .DWE               (1'b0),
    .PSCLK             (1'b0),
    .PSEN              (1'b0),
    .PSINCDEC          (1'b0),
    .PWRDWN            (1'b0),
    .RST               (sys_rst_act_hi)
  );

  BUFG u_bufg_clk0
    (
     .O (clk0_bufg),
     .I (clk0_mmcm)
     );

  BUFG u_bufg_clkdiv0
    (
     .O (clkdiv0_bufg),
     .I (clkdiv0_mmcm)
     );

endmodule
