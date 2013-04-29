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

///////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor             : Xilinx
// \   \   \/     Version            : 3.6.1 
//  \   \         Application        : MIG
//  /   /         Filename           : phy_v6_d_q_io.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:57 $
// \   \  /  \    Date Created       : Nov 19, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//  This module
//  1. Is the I/O module for a single Q bit coming from the memory.
//  2. Instantiates the IBUF followed by the IDELAY to delay the Q and
//     then passes the data to the ISERDES for deserialization.
//
//Revision History:
//
///////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_v6_d_q_io #
(
  parameter REFCLK_FREQ          = 300.0,        // Reference Clock Freq(Mhz)
  parameter MEM_TYPE             = "QDR2PLUS",   // Memory Type
  parameter ODELAY_VAL           = 0,            // Value to delay data
  parameter IODELAY_GRP          = "IODELAY_MIG",// May be assigned unique name 
  parameter HIGH_PERFORMANCE_MODE= "TRUE",       // IODELAY High Perf Mode
  parameter IBUF_LOW_PWR         = "FALSE",      // Input buffer low power mode
  parameter SIM_INIT_OPTION      = "NONE",       //Simulation only. "NONE", "SIM_MODE",
                                                 //  "SKIP_PU_DLY"
  parameter TCQ                  = 100           // Register delay
)
(
  // System signals
  input             clk,          // system clock
  input             rst_wr_clk,   // reset syncronized to clk
  input             clk_mem,      // high frequency system clock
  input       [3:0] wr_en,        // tri-state control
  input             clk_cq,       // CQ from BUFIO
  input             clk_cqn,      // CQ# from BUFIO
  input             clk_rd,       // half freq CQ clock from BUFR
  input             rst_clk_rd,   // reset syncrhonized to clk_rd

  // Memory Interface
  input             mem_q,        // Q from memory
  output wire       mem_d,        // D to memory
  inout             mem_dq,       // DQ to/from memory
  
  // PHY Write Interface
  input             data_rise0, 
  input             data_fall0,  
  input             data_rise1,   
  input             data_fall1,

  // IDELAY control
  input             q_dly_ce,     // Q IDELAY clock enable
  input             q_dly_inc,    // Q IDELAY increment
  input             q_dly_inc_int,// Q IDELAY increment delayed
  input             q_dly_rst,    // Q IDELAY reset
  input       [4:0] q_dly_load,   // Q IDELAY cntvaluein load value
  output wire [4:0] q_dly_tap,    // Q IDELAY tap setting
  
  // ISERDES control
  input             q_dly_clkinv, // Q IDELAY CLK inversion
  input             iserdes_rst_int,  // ISERDES reset
  
  // PHY Read Interface
  output reg        iserdes_rd0,  // ISERDES Q4 output - rise data 0
  output reg        iserdes_fd0,  // ISERDES Q3 output - fall data 0
  output reg        iserdes_rd1,  // ISERDES Q2 output - rise data 1
  output reg        iserdes_fd1  // ISERDES Q1 output - fall data 1
);
                               
  reg  q_dly_ce_int;
  wire q_ibuf;
  wire q_idelay;
  wire oserdes_d_out;
  wire iodelay_d_out;
  wire ocb_tfb;    // Must be connected to T input of IODELAY
  wire dq_oe_n_r;  // Connect OSERDES to IOBUF
  wire oserdes_oq;
  wire iserdes_rd0_int;
  wire iserdes_fd0_int;
  wire iserdes_rd1_int;
  wire iserdes_fd1_int;
  
  reg iserdes_fd1_int2;

  // Prevent the taps from overflowing or underflowing by capping them at their
  // minimum or maximum value
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      q_dly_ce_int <= #TCQ 0;
    end else if (q_dly_ce) begin
      if (q_dly_inc) begin
        q_dly_ce_int <= #TCQ !(&q_dly_tap);
      end else begin
        q_dly_ce_int <= #TCQ |q_dly_tap;
      end
    end else begin
      q_dly_ce_int <= #TCQ 0;
    end
  end
  
  // Register ISERDES output to do a bitslip
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      iserdes_fd1_int2 <= #TCQ 0;
    end else begin
      iserdes_fd1_int2 <= #TCQ iserdes_fd1_int;
    end   
  end
  
  // Register ISERDES outputs for better timing
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      iserdes_rd0 <= #TCQ 0;
      iserdes_fd0 <= #TCQ 0;
      iserdes_rd1 <= #TCQ 0;
      iserdes_fd1 <= #TCQ 0;
    end else if (q_dly_clkinv) begin
      iserdes_rd0 <= #TCQ iserdes_fd1_int2;
      iserdes_fd0 <= #TCQ iserdes_rd0_int;
      iserdes_rd1 <= #TCQ iserdes_fd0_int;
      iserdes_fd1 <= #TCQ iserdes_rd1_int;
    end else begin
      iserdes_rd0 <= #TCQ iserdes_rd0_int;
      iserdes_fd0 <= #TCQ iserdes_fd0_int;
      iserdes_rd1 <= #TCQ iserdes_rd1_int;
      iserdes_fd1 <= #TCQ iserdes_fd1_int;
    end
  end

  generate
    if (MEM_TYPE == "QDR2PLUS" || MEM_TYPE == "QDR2" ||
        MEM_TYPE == "RLD2_SIO" ) begin : IO_Q_D
        
      // Q first passes through an IBUF
      IBUF    
      #(
        .IBUF_LOW_PWR (IBUF_LOW_PWR)
      ) u_ibuf_q (
        .I (mem_q),
        .O (q_ibuf)
      );
      
      // Q then passes through an IDELAY
     (* IODELAY_GROUP = IODELAY_GRP *) 
     IODELAYE1 #(
        .DELAY_SRC              ("I"),
        .HIGH_PERFORMANCE_MODE  (HIGH_PERFORMANCE_MODE),
        .IDELAY_TYPE            ("VAR_LOADABLE"),
        .REFCLK_FREQUENCY       (REFCLK_FREQ),
        .SIGNAL_PATTERN         ("DATA")
     ) u_iodelay_d (
        .CNTVALUEOUT  (q_dly_tap),
        .DATAOUT      (q_idelay),
        .C            (clk_rd),
        .CE           (q_dly_ce_int),
        .CINVCTRL     (),
        .CNTVALUEIN   (q_dly_load),
        .DATAIN       (),
        .IDATAIN      (q_ibuf),
        .INC          (q_dly_inc_int),
        .ODATAIN      (),
        .RST          (q_dly_rst),
        .CLKIN        (),
        .T            (1'b1)
     );
     
     // Finally Q is deserialized in the ISERDES
     ISERDESE1 #(
        .DATA_RATE          ("DDR"),
        .DATA_WIDTH         (4),
        .DYN_CLK_INV_EN     ("FALSE"),
        .DYN_CLKDIV_INV_EN  ("FALSE"),
        .IOBDELAY           ("IFD"),     
        .INTERFACE_TYPE     ("NETWORKING"),
        .NUM_CE             (2),
        .SERDES_MODE        ("MASTER")
     ) u_iserdes_q (
        .BITSLIP        (1'b0),
        .CE1            (1'b1),
        .CE2            (1'b1),
        .DYNCLKDIVSEL   (1'b0),
        .CLK            (clk_cq),
        .CLKB           (clk_cqn),
        .CLKDIV         (clk_rd),
        .D              (),
        .DDLY           (q_idelay),
        .DYNCLKSEL      (1'b0),
        .OCLK           (),
        .RST            (iserdes_rst_int),
        .SHIFTIN1       (1'b0),
        .SHIFTIN2       (1'b0),
        .O              (),
        .Q1             (iserdes_fd1_int),
        .Q2             (iserdes_rd1_int),
        .Q3             (iserdes_fd0_int),
        .Q4             (iserdes_rd0_int),
        .Q5             (),
        .Q6             (),
        .SHIFTOUT1      (),
        .SHIFTOUT2      (),
        .OFB            ()
     );
     
     //Output D data
     phy_oserdes_io #(
        .ODELAY_VAL           (ODELAY_VAL),
        .REFCLK_FREQ          (REFCLK_FREQ),
        .IODELAY_GRP          (IODELAY_GRP),
        .HIGH_PERFORMANCE_MODE(HIGH_PERFORMANCE_MODE),
        .INIT_OQ_VAL          (1'b0),
        .DIFF_OUT             (0)
      ) u_phy_oserdes_data (
        .clk          (clk),
        .rst_wr_clk   (rst_wr_clk),
        .clk_mem      (clk_mem),
        .data_rise0   (data_rise0), 
        .data_fall0   (data_fall0),  
        .data_rise1   (data_rise1),   
        .data_fall1   (data_fall1),    
        .data_out_p   (mem_d),
        .data_out_n   ()
      );
      
      
    end else if (MEM_TYPE == "RLD2_CIO") begin : IO_DQ
    
      //tie the D outputs low since not used
      assign mem_d = 1'b0;

      IOBUF    
      #(
        .IBUF_LOW_PWR (IBUF_LOW_PWR)
      ) u_iobuf_dq (
        .I  (q_idelay),    // Input from IODELAY output  
        .T  (dq_oe_n_r),
        .IO (mem_dq),   
        .O  (q_ibuf)       //connect to IDATA_IN  of IODELAY 
      );
      
      // DQ then passes through an IODELAY (input and output)
     (* IODELAY_GROUP = IODELAY_GRP *) 
     IODELAYE1 #(
        .CINVCTRL_SEL           ("FALSE"),
        .DELAY_SRC              ("IO"),
        .HIGH_PERFORMANCE_MODE  (HIGH_PERFORMANCE_MODE),
        .IDELAY_TYPE            ("VARIABLE"),
        .IDELAY_VALUE           (0),
        .ODELAY_TYPE            ("FIXED"),
        .ODELAY_VALUE           (ODELAY_VAL),
        .REFCLK_FREQUENCY       (REFCLK_FREQ),
        .SIGNAL_PATTERN         ("DATA")
     ) u_iodelay_dq (
        .CNTVALUEOUT  (q_dly_tap),
        .DATAOUT      (q_idelay),
        .C            (clk_rd),
        .CE           (q_dly_ce_int),
        .CINVCTRL     (1'b0),           //Not used
        .CNTVALUEIN   (q_dly_load),
        .DATAIN       (),               //Not used
        .IDATAIN      (q_ibuf),
        .INC          (q_dly_inc_int),
        .ODATAIN      (oserdes_oq),
        .RST          (q_dly_rst),
        .CLKIN        (),
        .T            (ocb_tfb)
     );
     
     // Finally DQ is deserialized in the ISERDES
     ISERDESE1 #(
        .DATA_RATE          ("DDR"),
        .DATA_WIDTH         (4),
        .DYN_CLK_INV_EN     ("FALSE"),
        .DYN_CLKDIV_INV_EN  ("FALSE"),
        .IOBDELAY           ("IFD"),     
        .INTERFACE_TYPE     ("NETWORKING"),
        .NUM_CE             (2),
        .SERDES_MODE        ("MASTER")
     ) u_iserdes_dq (
        .BITSLIP        (1'b0),
        .CE1            (1'b1),
        .CE2            (1'b1),
        .DYNCLKDIVSEL   (1'b0),
        .CLK            (clk_cq),
        .CLKB           (clk_cqn),
        .CLKDIV         (clk_rd),
        .D              (),
        .DDLY           (q_idelay),
        .DYNCLKSEL      (1'b0),
        .OCLK           (clk_mem),
        .RST            (iserdes_rst_int),
        .SHIFTIN1       (1'b0),
        .SHIFTIN2       (1'b0),
        .O              (),
        .Q1             (iserdes_fd1_int),
        .Q2             (iserdes_rd1_int),
        .Q3             (iserdes_fd0_int),
        .Q4             (iserdes_rd0_int),
        .Q5             (),
        .Q6             (),
        .SHIFTOUT1      (),
        .SHIFTOUT2      (),
        .OFB            ()
     );
     
     OSERDESE1 #(
	     .DATA_RATE_OQ   ("DDR"),        //Output 'OQ' as DDR Format
	     .DATA_RATE_TQ   ("DDR"),        //Output 'TQ' as DDR Format - Unused
	     .DATA_WIDTH     (4),            //D inputs width of four
	     .DDR3_DATA      (0),            //Data is not for DDR3
	     .INIT_OQ        (1'b0),         //Initial value of OQ output
	     .INIT_TQ        (1'b1),         //Initial value of TQ output
	     .INTERFACE_TYPE ("DEFAULT"),//To bypass DDR3 circuitry
	     .ODELAY_USED    (0),            //Internal ODELAY unused
	     .SERDES_MODE    ("MASTER"),     //This is the master OSERDES 
	     .SRVAL_OQ       (1'b0),         //'OQ' value on reset
	     .SRVAL_TQ       (1'b1),         //'TQ' value on reset - Unused
	     .TRISTATE_WIDTH (4)             //T inputs width of four - Unused
	   ) u_oserdes_dq (
	      .OQ           (oserdes_oq),   //Data Output
	      .SHIFTOUT1    (),             //Carry out for Data - Unused
	      .SHIFTOUT2    (),
	      .TQ           (dq_oe_n_r),    //Tristate outputs
	      .CLK          (clk_mem),      //Full Freq. Clock Input clocks D in OCB
	      .CLKDIV       (clk),          //Half Freq. Clock Input for clking Data
	      .CLKPERF      (),       //Full Freq. Performance Path - Clock out
	      .CLKPERFDELAY (),             //Output from IODELAY
              .OFB          (),             //Feedback path - Unused
	      .D1           (data_rise0),
	      .D2           (data_fall0),
	      .D3           (data_rise1),
	      .D4           (data_fall1),
	      .D5           (1'b0),         //Data inputs 5/6 - Unused
	      .D6           (1'b0),
	      .OCBEXTEND    (),
	      .OCE          (1'b1),         //Enable Data input bits
	      .ODV          (1'b0),         //Set to '0' because delay doesn't 
                                            //exceed 180 degrees
	      .SHIFTIN1     (1'b0),         //Carry in for Data - Unused
	      .SHIFTIN2     (1'b0),
	      .RST          (rst_wr_clk),   //Reset for OSERDES
              .T1           (wr_en[0]),     //Tristate inputs
	      .T2           (wr_en[1]),
              .T3           (wr_en[2]),
	      .T4           (wr_en[3]),
	      .TFB          (ocb_tfb),
	      .TCE          (1'b1),         //Enable Tristate inputs
	      .WC           (1'b0)            //Write Command to reset internal cntrs
	   );
    
    end
  endgenerate

endmodule
