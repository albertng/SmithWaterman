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
//  /   /         Filename           : phy_oserdes_io.v
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:57 $
// \   \  /  \    Date Created       : Nov 11, 2008 
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//    This module
//  1. Is an OSERDES wrapper files to simply code output I/O
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_oserdes_io#(
  parameter ODELAY_VAL      = 0,            //value to delay clk_wr
  parameter REFCLK_FREQ     = 300.0,        //Ref Clk Freq. for IODELAYs
  parameter IODELAY_GRP     = "IODELAY_MIG",// May be assigned unique name 
                                            // when mult IP cores in design
  parameter HIGH_PERFORMANCE_MODE = "TRUE", // IODELAY High Performance Mode
  parameter INIT_OQ_VAL     = 0,
  parameter DIFF_OUT        = 0             //Use Differential Ouputs Buffer
)
(
  input       clk,
  input       rst_wr_clk,
  input       clk_mem,
  input       data_rise0, 
  input       data_fall0,  
  input       data_rise1,   
  input       data_fall1,    
  output wire data_out_p,
  output wire data_out_n
);         

  wire oserdes_d_out;
  wire iodelay_d_out;

  OSERDESE1 #(
	  .DATA_RATE_OQ   ("DDR"),        //Output 'OQ' as DDR Format
	  .DATA_RATE_TQ   ("BUF"),        //Output 'TQ'  Unused
	  .DATA_WIDTH     (4),            //D inputs width of four
	  .DDR3_DATA      (0),            //Data is not for DDR3
	  .INIT_OQ        (INIT_OQ_VAL),  //Initial value of OQ output
	  .INIT_TQ        (1'b1),         //Initial value of TQ output
	  .INTERFACE_TYPE ("DEFAULT"),//To bypass DDR3 circuitry
	  .ODELAY_USED    (0),            //Internal ODELAY unused
	  .SERDES_MODE    ("MASTER"),     //This is the master OSERDES 
	  .SRVAL_OQ       (1'b1),         //'OQ' value on reset
	  .SRVAL_TQ       (1'b1),         //'TQ' value on reset - Unused
	  .TRISTATE_WIDTH (1)             //T inputs width of four - Unused
	) u_oserdes_d (
	  .OQ           (oserdes_d_out),             //Data Output
	  .SHIFTOUT1    (),             //Carry out for Data - Unused
	  .SHIFTOUT2    (),     
	  .TQ           (),             //Tristate outputs - Unused
	  .CLK          (clk_mem),      //Full Freq. Clock Input clocks D in OCB
	  .CLKDIV       (clk),          //Half Freq. Clock Input for clking Data
	  .CLKPERF      (),             //Full Freq. Performance Path - Clocks out
	  .CLKPERFDELAY (),             //Output from IODELAY
          .OFB          (),             //Feedback path - Unused
	  .D1           (data_rise0), 
	  .D2           (data_fall0),
	  .D3           (data_rise1),
	  .D4           (data_fall1),
	  .D5           (),             //Data inputs 5/6 - Unused
	  .D6           (),
	  .OCBEXTEND    (),
	  .OCE          (1'b1),         //Enable Data input bits
	  .ODV          (1'b0),         //Set to '0' because delay doesn't 
                                        //exceed 180 degrees
	  .SHIFTIN1     (1'b0),             //Carry in for Data - Unused
	  .SHIFTIN2     (1'b0),
	  .RST          (rst_wr_clk),   //Reset for OSERDES
	  .T1           (1'b0),         //Tie off Tristate inputs - Unused
	  .T2           (1'b0),
	  .T3           (1'b0),
	  .T4           (1'b0),
	  .TFB          (),             
	  .TCE          (1'b0),         //Disable Tristate inputs
	  .WC           (1'b0)          //Write Command to reset internal cntrs
	);

  (* IODELAY_GROUP = IODELAY_GRP *) IODELAYE1 #(
    .DELAY_SRC             ("O"),                   //Place dealy on the Output    
    .HIGH_PERFORMANCE_MODE (HIGH_PERFORMANCE_MODE), //EN for higher res. > power
    .IDELAY_TYPE           ("FIXED"),               //Fixed "I" Delay Value
    .ODELAY_TYPE           ("FIXED"),               //Fixed "O" Delay Value
    .IDELAY_VALUE          (0),                     //"I" delay of 0
    .ODELAY_VALUE          (ODELAY_VAL),            //"O" delay of ODELAY_VAL
    .REFCLK_FREQUENCY      (REFCLK_FREQ),
    .CINVCTRL_SEL          ("FALSE")     
  ) u_iodelay_addr (
    .DATAOUT     (iodelay_d_out),       //Delayed signal
    .C           (clk),
    .CE          (),
    .DATAIN      (),                    //Data in from fabric only
    .IDATAIN     (),                    //Data in from ilogic/fabric
    .INC         (),                    //only used in variable mode
    .ODATAIN     (oserdes_d_out),       //Data in from ologic/fabic
    .RST         (rst_wr_clk),
    .T           (1'b0),                //Tristate select - "Output"
    .CNTVALUEIN  (),                    //Loadable counter unused in fixed mode
    .CNTVALUEOUT (),                    //Current internal counter value
    .CLKIN       (),
    .CINVCTRL    (1'b0)
  );

  generate 
    if (DIFF_OUT==0) begin
      OBUFT IO_FF
        (
          .I (iodelay_d_out),
          .O (data_out_p),
          .T (1'b0)
        );

      assign data_out_n = 1'b0;
    end else begin
      OBUFDS u_iobuf_ck (
        .O  (data_out_p),
        .OB (data_out_n),
        .I  (iodelay_d_out) 
      );
    end
  endgenerate 

endmodule
