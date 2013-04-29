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
//  /   /         Filename           : phy_write_init_sm.v
// /___/   /\     Date Last Modified : $date$
// \   \  /  \    Date Created       : Nov 12, 2008 
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ 
//
//Purpose:
//    This module
//  1. Is the initialization state machine for delay calibration before regular
//     memory transactions begin.
//  2. This sm generates control, address, and data.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////


`timescale 1ps/1ps

module phy_write_init_sm #
(
  parameter BURST_LEN   = 4,    //Burst Length
  parameter ADDR_WIDTH  = 19,   //Address Width
  parameter DATA_WIDTH  = 72,   //Data Width
  parameter REFCLK_FREQ = 300.0,//Ref Clk Freq. for IODELAYs
  parameter TCQ         = 100   //Register Delay
)
(
  input                          clk,              //main system half freq clk
  input                          rst_wr_clk,       //main write path reset
  input                          cal_stage1_start, //stage 1 calibration start
  input                          cal_stage2_start, //stage 2 calibration start
  output reg                     init_done,        //init done, cal can begin
  output reg  [DATA_WIDTH*2-1:0] init_wr_data0,    //init sm write data 0
  output reg  [DATA_WIDTH*2-1:0] init_wr_data1,    //init sm write data 1
  output reg  [ADDR_WIDTH-1:0]   init_wr_addr0,    //init sm write addr 0
  output reg  [ADDR_WIDTH-1:0]   init_wr_addr1,    //init sm write addr 1
  output reg  [ADDR_WIDTH-1:0]   init_rd_addr0,    //init sm read addr 0
  output reg  [ADDR_WIDTH-1:0]   init_rd_addr1,    //init sma read addr 1
  output reg  [1:0]              init_rd_cmd,      //init sm read command
  output reg  [1:0]              init_wr_cmd      //init sm write command
);

  //Local Parameter Declarations
  //Four states in the init sm, one-hot encoded
  localparam CAL_INIT         =  4'b0001;
  localparam CAL_WRITE        =  4'b0010;
  localparam CAL_READ         =  4'b0100;
  localparam CAL_DONE         =  4'b1000;

  //Stage 1 Calibration Pattern
  //00FF_FF00
  //00FF_00FF
  localparam [DATA_WIDTH*8-1:0] DATA_STAGE1 = 
                                {{DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b1}},
                                 {DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b1}},
                                 {DATA_WIDTH{1'b1}}, {DATA_WIDTH{1'b0}},
                                 {DATA_WIDTH{1'b0}}, {DATA_WIDTH{1'b1}}};

  //Stage 2 Calibration Pattern 
  //AAAA_AAAA
  localparam [DATA_WIDTH*4-1:0] DATA_STAGE2 = {DATA_WIDTH{4'hA}};

  //Wire Declarations
  reg [3:0]    phy_init_cs;
  reg [3:0]    phy_init_ns;
  reg [6:0]    rst_delayed = 0;
  reg          cal_stage2_start_r;
  reg [2:0]    addr_cntr; 
  reg [1:0]    init_wr_cmd_d;
  reg [1:0]    init_rd_cmd_d;
  reg          incr_addr;

  always @ (posedge clk) 
    begin
      rst_delayed[0] <=#TCQ rst_wr_clk;
      rst_delayed[1] <=#TCQ rst_delayed[0];
      rst_delayed[2] <=#TCQ rst_delayed[1];
      rst_delayed[3] <=#TCQ rst_delayed[2];
      rst_delayed[4] <=#TCQ rst_delayed[3];
      rst_delayed[5] <=#TCQ rst_delayed[4];
      rst_delayed[6] <=#TCQ rst_delayed[5];
    end  

  //Signals to the read path that initialization can begin 
  always @ (posedge clk)
    begin
      if (rst_wr_clk) begin
        init_done <=#TCQ 1'b0;
      end else if (rst_delayed[6] & ~rst_delayed[5]) begin 
        init_done <=#TCQ 1'b1;
      end
    end

  always @ (posedge clk) 
    begin
      if (rst_wr_clk) begin
        cal_stage2_start_r <=#TCQ 1'b0;
      end else begin
        cal_stage2_start_r <=#TCQ cal_stage2_start;
      end
    end

  //addr_cntr is used to select the data for initalization writes and
  //addressing.  The LSB is used to index data while [ADDR_WIDTH-1:1] is used
  //as the address therefore it is incremented by 2.
  always @ (posedge clk) 
    begin
      if (rst_wr_clk) begin
        addr_cntr <=#TCQ 3'b000;

      //always use an address of 0x0 in stage 2 calibration
      end else if (cal_stage2_start) begin
        if (~cal_stage2_start_r & cal_stage2_start)
          addr_cntr <=#TCQ (BURST_LEN == 4) ? 3'b100 : 3'b010;
        else if (|init_wr_cmd)
          addr_cntr <= #TCQ 3'b000;

      end else if (incr_addr) begin
        addr_cntr[1:0] <=#TCQ addr_cntr + 2;
        addr_cntr[2]   <=#TCQ 1'b0;

      end
    end

  //Register the State Machine Outputs
  always @(posedge clk)
    begin
      if (rst_wr_clk) begin
        init_wr_cmd   <=#TCQ 2'b00;
        init_rd_cmd   <=#TCQ 2'b00;
        init_wr_addr0 <=#TCQ 0;
        init_wr_addr1 <=#TCQ 0;
        init_rd_addr0 <=#TCQ 0;
        init_rd_addr1 <=#TCQ 0;
        init_wr_data0 <=#TCQ 0;
        init_wr_data1 <=#TCQ 0;
        phy_init_cs   <=#TCQ CAL_INIT;


      end else begin
        init_wr_cmd   <=#TCQ init_wr_cmd_d;
        init_rd_cmd   <=#TCQ init_rd_cmd_d;

        //init_wr_addr0/init_rd_addr1 are only used in BL2 mode.  Because of
        //this, we use all the address bits to maintain using even numbers for
        //the address' on the rising edge.  For BL2 the rising edge address 
        //should cycle through values 0,2,4, and 6.  On the falling edge where
        //'*addr1' is used the address should be rising edge +1 ('*addr0' +1).  
        //To save resources, instead of adding a +1, a 1 is concatinated
        //onto the rising edge address.
        //In BL4 mode, since reads only occur on the rising edge, and writes
       //on the falling edge, we uses everything but the LSB of addr_cntr 
        //since the LSB is only used to index the data register.  For BL4, 
        //the address should access 0x0 - 0x3 in stage one and 0x0 in stage 2.

        init_wr_addr0 <=#TCQ addr_cntr[1:0];          //Not used in BL4 - X
        init_wr_addr1 <=#TCQ (BURST_LEN == 4) ? addr_cntr[2:1] : 
                                                {addr_cntr[1:1], 1'b1};
        init_rd_addr0 <=#TCQ (BURST_LEN == 4) ? addr_cntr[2:1] : 
                                                addr_cntr[1:0];
        init_rd_addr1 <=#TCQ {addr_cntr[1:1], 1'b1};  //Not used in BL4 - X

        //based on the address a bit-select is used to select 2 Data Words for
        //the pre-defined arrary of data for read calibration.
        init_wr_data0 <=#TCQ (cal_stage2_start) ?
                     DATA_STAGE2[(DATA_WIDTH*2)-1:0] :
                     DATA_STAGE1[(addr_cntr*DATA_WIDTH*2)+:(DATA_WIDTH*2)];

        init_wr_data1 <=#TCQ (cal_stage2_start) ? 
                     DATA_STAGE2[(DATA_WIDTH*4)-1:(DATA_WIDTH*2)]:
                     DATA_STAGE1[((addr_cntr+1)*DATA_WIDTH*2)+:(DATA_WIDTH*2)];

        phy_init_cs   <=#TCQ phy_init_ns;
      end
    end

  //Initialization State Machine
  always @ *
    begin
      case (phy_init_cs)
        //In the init state, wait for cal_stage1_start to be asserted from the
        //read path to begin read/write transactions
        //Throughout this state machine, all outputs are registered except for 
        //incr_addr.  This is because that signal is used to set the address
        //which should be in line with the rest of the signals so it is used
        //immediately.
        CAL_INIT : begin
          init_wr_cmd_d   = 2'b00;
          init_rd_cmd_d   = 2'b00;
          incr_addr       = 0;

          if (cal_stage1_start)
            phy_init_ns = CAL_WRITE;
          else
            phy_init_ns = CAL_INIT;
        end

        //Send a write command.  For BL2 mode two writes are issued to write
        //4 Data Words, in BL4 mode, only write on the falling edge by using
        //bit [1] of init_wr_cmd.
        CAL_WRITE  :  begin
          init_wr_cmd_d   = (BURST_LEN == 4) ? 2'b10 : 2'b11;
          init_rd_cmd_d   = 2'b00;
          incr_addr       = 1;
          
          //On the last two data words we are done writing in stage1
          //For stage two only one write is necessary
          if ((cal_stage2_start_r & cal_stage2_start) || 
              (addr_cntr == 4'b0010))
            phy_init_ns = CAL_READ;
          else
            phy_init_ns = CAL_WRITE;
        end

        //Send a write command.  For BL2 mode two reads are issued to read
        //back 4 Data Words, in BL4 mode, only read on the rising edge by using
        //bit [0] of init_rd_cmd.
        CAL_READ   : begin
          init_wr_cmd_d   = 2'b00;
          init_rd_cmd_d   = (BURST_LEN == 4) ? 2'b01 : 2'b11;
          incr_addr       = 1;

          //In stage 1 calibration, continuously read back data until stage 2 is
          //ready to begin.  in stage 2 read once then calibration is complete.
          //Only exit the read state when an entire sequence is complete (ie
          //on the last address of a sequence)
          if (cal_stage2_start_r & addr_cntr == 3'b000) begin
            phy_init_ns = CAL_DONE;
          end else if (~cal_stage2_start_r & cal_stage2_start) begin
            phy_init_ns = CAL_WRITE;
          end else begin
            phy_init_ns = CAL_READ;
          end

        end
          
        //Calibration Complete
        CAL_DONE : begin
          init_wr_cmd_d   = 2'b00;
          init_rd_cmd_d   = 2'b00;
          incr_addr       = 0;
          phy_init_ns     = CAL_DONE;
        end
           
        default:   begin
          init_wr_cmd_d   = 2'bXX;
          init_rd_cmd_d   = 2'bXX;
          incr_addr       = 0;
          phy_init_ns     = CAL_INIT;
        end
      endcase

    end //end init sm

endmodule
