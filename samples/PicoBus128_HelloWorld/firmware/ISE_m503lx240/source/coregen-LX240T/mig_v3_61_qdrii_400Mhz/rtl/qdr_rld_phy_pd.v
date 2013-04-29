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
//*****************************************************************************
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor                : Xilinx
// \   \   \/     Version               : 3.6.1
//  \   \         Application           : MIG
//  /   /         Filename              : qdr_rld_phy_pd.v
// /___/   /\     Date Last Modified    : $date$
// \   \  /  \    Date Created          : Jan 30 2009
//  \___\/\___\
//
//Device            : Virtex-6
//Design            : QDRII+ SRAM/RLDRAM II SDRAM
//Purpose           : top level module for QDRII+/RLDRAM II Phase Detection. 
//Reference         :
//Revision History  :
//*****************************************************************************

`timescale 1ps/1ps

module qdr_rld_phy_pd #(
   parameter CLK_PERIOD  = 1876,          // Indicates the number of picoseconds 
                                          // for one CLK period
   parameter REFCLK_FREQ = 300.0,         // Ref Clk Freq. for IODELAYs
   parameter IODELAY_GRP = "IODELAY_MIG", // May be assigned unique name
                                          // when mult IP cores in design
   parameter MEM_TYPE   = "QDR2PLUS",     // Memory Type
   parameter MIN_TAPS   = 5,
   parameter TCQ         = 100,           // Register Delay
   parameter SIM_CAL_OPTION = "NONE",      // "NONE", "FAST_CAL", or "SKIP_CAL"
   parameter SIM_INIT_OPTION     = "NONE"  //Simulation only. "NONE", "SIM_MODE"
)
(
  output     pd_en_maintain,
  output     pd_calib_done,
  output     pd_incdec_maintain,
  output reg pd_calib_error,
  input      pd_calib_start,
  input      clk_cq,
  input      clk_cqn,
  input      clk_rd,
  input      clk,
  input      clk_mem,
  input      clk_wr,
  input      wc,
  input      rst_clk_rd,
  input      rst_wr_clk,
  input      pd_source,
  input      dbg_pd_off
);

  //offset the IODELAY for decrement
  localparam IODELAY_PD_VAL = MIN_TAPS;
   
  localparam REFCLK200_LOW_LIMIT = 8000; //clk_rd lower limit in ps
  localparam REFCLK300_LOW_LIMIT = 5334; //clk_rd lower limit in ps
  
// **************** internal signals ****************

  wire       oserdes_pd_out;
  wire       iobuf_out;
  reg       pd_data_source;
  wire       pd_iodly;
  wire       pd_en_calib;
  wire       trip_point;
  wire       trip_point_1;
  wire       pd_psen;
  reg        first_calib_n;
  reg        inv_trip_point;
  wire       pd_incdec_calib;
  reg  [4:0] tap_count;
  wire [4:0] cnt_value_out;
  wire       tq;
  wire       pd_incdec;
  reg        pd_en_calib_int;
  reg        pd_incdec_int;
  
// **************** Debug **********************************
  //synthesis translate_off
  always @(posedge pd_calib_start) begin
    if (!rst_wr_clk) begin
      $display ("QDR_RLD_PHY_PD: Phase Detector Initial Cal started at   %t", 
                $time);
      if ( (REFCLK_FREQ == 300.0 && CLK_PERIOD > REFCLK300_LOW_LIMIT ) || 
           (REFCLK_FREQ == 200.0 && CLK_PERIOD > REFCLK200_LOW_LIMIT))
        $display ("QDR_RLD_PHY_PD: WARNING: Lower Frequency limit exceeded");
    end
  end
  
  always @(posedge pd_calib_done) begin
    if (!rst_wr_clk)
      $display ("QDR_RLD_PHY_PD: Phase Detector Initial Cal completed at %t", 
                $time);
  end
   //synthesis translate_on
// **************** instantiate PD OSERDESE1 ****************

//generate
//  if (MEM_TYPE == "QDR2PLUS" || MEM_TYPE == "QDR2") begin : QDR2_PD_TRIP
//    OSERDESE1 #(
//      .DATA_RATE_OQ   ("DDR"),
//      .DATA_RATE_TQ   ("DDR"),
//      .DATA_WIDTH     (4),
//      .DDR3_DATA      (1),
//      .INIT_OQ        (1'b0),
//      .INIT_TQ        (1'b1),
//      .INTERFACE_TYPE ("MEMORY_DDR3"),
//      .ODELAY_USED    (0),
//      .SERDES_MODE    ("MASTER"),
//      .SRVAL_OQ       (1'b0),
//      .SRVAL_TQ       (1'b0),
//      .TRISTATE_WIDTH (4)
//    ) u_pd_oserdes  (
//      .OQ           (oserdes_pd_out),  //Data Output
//      .SHIFTOUT1    (),             //Carry out for Data - Unused
//      .SHIFTOUT2    (),
//      .TQ           (tq),           //Tristate outputs
//      .CLK          (clk_mem),      //Full Freq Clk Input clocks D in OCB
//      .CLKDIV       (clk),          //Half Freq Clk Input for clking Data
//      .CLKPERF      (clk_wr),       
//      .CLKPERFDELAY (),             
//      .OFB          (),             
//      .D1           (1'b1),
//      .D2           (1'b0),
//      .D3           (1'b1),
//      .D4           (1'b0),
//      .D5           (),             //Data inputs 5/6 - Unused
//      .D6           (),
//      .OCBEXTEND    (),
//      .OCE          (1'b1),         //Enable Data input bits
//      .ODV          (1'b0),         //Set to '0' because delay doesn't
//                                    //exceed 180 degrees
//      .SHIFTIN1     (),             //Carry in for Data - Unused
//      .SHIFTIN2     (),
//      .RST          (rst_wr_clk),   //Reset for OSERDES
//      .T1           (1'b0),         //Tie off Tristate inputs - Unused
//      .T2           (1'b0),
//      .T3           (1'b0),
//      .T4           (1'b0),
//      .TFB          (),
//      .TCE          (1'b0),         //Disable Tristate inputs
//      .WC           (wc)            //Write Command to reset internal cntrs
//    );
//  
//  // **************** instantiate PD IOBUF ****************
//  
//    IOBUF #
//    (
//     .IOSTANDARD("HSTL_II")
//     ) u_iobuf_pd (
//        .O   (iobuf_out),
//        .IO  (),
//        .I   (oserdes_pd_out),
//        .T   (tq)
//      );
//      
//  end else begin : RLD2_PD_TRIP
//    assign iobuf_out = pd_source;
//  end
//endgenerate   

assign iobuf_out = pd_source; 

// **************** optionally delay pd_source ****************

  // set delay to 900 to test inv_trip_point

  always @ (iobuf_out) pd_data_source <= #900 iobuf_out;

// **************** instantiate PD IODELAYE1 ****************

  IODELAYE1 #(
    .DELAY_SRC              ("I"),
    .HIGH_PERFORMANCE_MODE  ("TRUE"),
    .IDELAY_TYPE            ("VARIABLE"),
    .IDELAY_VALUE           (IODELAY_PD_VAL),
    .REFCLK_FREQUENCY       (REFCLK_FREQ),
    .SIGNAL_PATTERN         ("CLOCK")
  ) qdr_pd_idelay (
    .CNTVALUEOUT  (cnt_value_out),
    .DATAOUT      (pd_iodly),
    .C            (clk_rd),
    .CE           (pd_en_calib_int),
    .CINVCTRL     (1'b0),
    .CNTVALUEIN   (5'b0),
    .DATAIN       (1'b0),
    .IDATAIN      (pd_data_source),
    .INC          (pd_incdec_int),
    .ODATAIN      (1'b0),
    .RST          (rst_clk_rd),
    .CLKIN        (1'b0),
    .T            (1'b1)
  );

// **************** instantiate PD ISERDESE1 ****************

  ISERDESE1 #(
    .DATA_RATE          ("DDR"),
    .DATA_WIDTH         (4),
    .DYN_CLKDIV_INV_EN  ("TRUE"),
    .IOBDELAY           ("IFD"),
    .INTERFACE_TYPE     ("NETWORKING"),
    .NUM_CE             (2),
    .SERDES_MODE        ("MASTER")
  ) qdr_pd_iserdes (
    .BITSLIP        (1'b0),
    .CE1            (1'b1),
    .CE2            (1'b1),
    .DYNCLKDIVSEL   (1'b0),
    .CLK            (clk_cq),
    .CLKB           (~clk_cq), //clk_cqn),
    .CLKDIV         (clk_rd),
    .D              (),
    .DDLY           (pd_iodly),
    .DYNCLKSEL      (),
    .OCLK           (),
    .RST            (rst_clk_rd),
    .SHIFTIN1       (),
    .SHIFTIN2       (),
    .O              (),
    .Q1             (trip_point),
    .Q2             (),
    .Q3             (),
    .Q4             (),
    .Q5             (),
    .Q6             (),
    .SHIFTOUT1      (),
    .SHIFTOUT2      (),
    .OFB            ()
  );

// **************** conditionally invert trip_point ****************

  always @(posedge clk_rd)
  if(rst_clk_rd)
  begin
    first_calib_n  <= #TCQ 1'b0;
    inv_trip_point <= #TCQ 1'b0;
  end
  else
  begin
    if(pd_psen) first_calib_n <= #TCQ 1'b1;
    if(~first_calib_n & pd_psen & ~pd_incdec) inv_trip_point <= #TCQ 1'b1;
  end

  //assign trip_point_1 = inv_trip_point ^ trip_point; 
  assign trip_point_1 = (cnt_value_out < 5 && inv_trip_point) ? inv_trip_point : (inv_trip_point ^ trip_point);                                                                                                                 

// **************** instantiate phy_ocb_mon ****************

  qdr_rld_phy_ocb_mon #
    (
     .SIM_CAL_OPTION(SIM_CAL_OPTION),//,
     .SIM_INIT_OPTION(SIM_INIT_OPTION),
     .TCQ           (TCQ)
     )
    u_qdr_rld_phy_ocb_mon
      (
       .dbg_ocb_mon        (),
       .ocb_mon_PSEN       (pd_psen),
       .ocb_mon_PSINCDEC   (pd_incdec),
       .ocb_mon_calib_done (pd_calib_done),
       .ocb_wc             (),
       .ocb_extend         (trip_point_1),
       .ocb_mon_PSDONE     (1'b1),
       .ocb_mon_go         (pd_calib_start),
       .clk                (clk_rd),
       .rst                (rst_clk_rd),
       .ocb_enabled_n      (1'b0) //always enabled
       );

  assign pd_en_maintain = pd_psen &  pd_calib_done & ~dbg_pd_off;
  assign pd_en_calib    = pd_psen & ~pd_calib_done & first_calib_n;

  assign pd_incdec_calib    = pd_incdec;
  assign pd_incdec_maintain = ~pd_incdec & ~dbg_pd_off;   
  
  // Prevent the taps from overflowing or underflowing by capping them at their
  // minimum or maximum value
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      pd_en_calib_int <= #TCQ 0;
    end else if (pd_en_calib) begin
      if (pd_incdec) begin
        pd_en_calib_int <= #TCQ !(&cnt_value_out);
      end else begin
        pd_en_calib_int <= #TCQ |cnt_value_out;
      end
    end else begin
      pd_en_calib_int <= #TCQ 0;
    end
  end
  
  // need to register the "inc" signals to make sure they align with the "ce"
  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      pd_incdec_int  <= #TCQ 0;
    else
      pd_incdec_int  <= #TCQ pd_incdec;
  end
  
  always @ (posedge clk_rd)
  begin
    if (rst_clk_rd)
      tap_count <=#TCQ 'b0;
    else if (pd_en_calib && pd_incdec)
      tap_count <=#TCQ tap_count + 1;
    else if (pd_en_calib && !pd_incdec)
      tap_count <=#TCQ tap_count - 1;
    else
      tap_count <=#TCQ tap_count;
  end
  
  //generate en error signal
  always @ (posedge clk_rd) begin
    if (rst_clk_rd)
      pd_calib_error  <=#TCQ 'b0;
    else if (pd_en_calib && pd_incdec && (&cnt_value_out))
      pd_calib_error  <=#TCQ ~pd_calib_done;
    else
      pd_calib_error  <=#TCQ pd_calib_error;
  end

endmodule
