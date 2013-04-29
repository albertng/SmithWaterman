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
//  /   /         Filename           : phy_read_dcb.v
// /___/   /\     Date Last Modified : $date$
// \   \  /  \    Date Created       : Nov 17, 2008
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//  This module
//  1. Data Circular Buffer (DCB) - This module is used to transfer the data
//     from the clk_rd domain into the clk domain. The DCB is a circular buffer
//     which continually writes data from the Data Align logic on each clk_rd
//     cycle to BRAM. On the read side of the BRAM, data is continually read
//     on every clk cycle.
//  2. In order to safely allow the transfer of data between the two clock
//     domains there must at least one space between the read and write
//     pointers. In order to compensate for phase variations between the two
//     clocks that will occur over V/T and deal with uncertainties in how both
//     sides come out of reset, the target spacing between the two pointers
//     will be 3. However, do to the uncertainties just mentioned, the actual
//     difference between the pointers could be between 1 and 5 (before forcing
//     additional latency into the system).
//  3. The DCB also allows latency through the path to be increased to account
//     for latency differences when multiple devices are used or if the latency
//     needs to be increased to meet a target latency for fixed latency mode.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_read_dcb #
(
  parameter MEMORY_WIDTH  = 36, // Width of each memory
  parameter TCQ           = 100 // Register delay
)
(
  // System Signals
  input                             clk_rd,     // half freq CQ clock - write side
  input                             rst_clk_rd, // reset syncrhonized to clk_rd - write side
  input                             clk,        // main system half freq clk - read side
  input                             rst_clk,    // main read path reset sync to clk - read side
  input                             cq_dly_rst, // CQ IODELAY reset indication

  // Data Align Interface
  input        [MEMORY_WIDTH-1:0]   din_rd0,    // rise data 0 from data align
  input        [MEMORY_WIDTH-1:0]   din_fd0,    // fall data 0 from data align
  input        [MEMORY_WIDTH-1:0]   din_rd1,    // rise data 1 from data align
  input        [MEMORY_WIDTH-1:0]   din_fd1,    // fall data 1 from data align
  
  // User Interface
  output reg   [MEMORY_WIDTH-1:0]   dout_rd0,   // rise data 0 from DCB
  output reg   [MEMORY_WIDTH-1:0]   dout_fd0,   // fall data 0 from DCB
  output reg   [MEMORY_WIDTH-1:0]   dout_rd1,   // rise data 1 from DCB
  output reg   [MEMORY_WIDTH-1:0]   dout_fd1,   // fall data 1 from DCB

  // Latency Calibration Interface
  input                             inc_latency, // increases latency when asserted
  
  // ChipScope Debug Signals
  output wire [4:0]                 dbg_dcb_wr_ptr,
  output wire [4:0]                 dbg_dcb_rd_ptr,
  output wire [MEMORY_WIDTH*4-1:0]  dbg_dcb_din,
  output wire [MEMORY_WIDTH*4-1:0]  dbg_dcb_dout
);

  wire [MEMORY_WIDTH*4-1:0] dcb_in;
  wire [MEMORY_WIDTH*4-1:0] dcb_out;
  reg                       cq_dly_rst_r;
  reg                       cq_dly_rst_2r;
  reg                       cq_dly_rst_3r;
  reg                       cq_dly_rst_4r;
  reg                       cq_dly_rst_ext;
  reg                       cdr_clkrd_r;
  reg                       rst_wr_ptr;
                            (* ASYNC_REG = "TRUE" *)
  reg                       cdr_clk_r;
  reg                       rst_rd_ptr;
  reg  [4:0]                wr_ptr;
  reg  [4:0]                rd_ptr;
    
  wire [MEMORY_WIDTH*4-1:0]  di_int0;
  wire [MEMORY_WIDTH*4-1:0]  do_int0;

  assign dcb_in   = {din_fd1, din_rd1, din_fd0, din_rd0};
  
  // Register outputs to help with timing
  always @(posedge clk) begin
    if (rst_clk) begin
      dout_rd0 <= #TCQ 0;
      dout_fd0 <= #TCQ 0;
      dout_rd1 <= #TCQ 0;
      dout_fd1 <= #TCQ 0;
    end else begin
      dout_rd0 <= #TCQ dcb_out[MEMORY_WIDTH-1:0];
      dout_fd0 <= #TCQ dcb_out[2*MEMORY_WIDTH-1:MEMORY_WIDTH];
      dout_rd1 <= #TCQ dcb_out[3*MEMORY_WIDTH-1:2*MEMORY_WIDTH];
      dout_fd1 <= #TCQ dcb_out[4*MEMORY_WIDTH-1:3*MEMORY_WIDTH];
    end
  end

  // As CQ is calibrated, the rd_ptr can pass the wr_ptr due to delayed or
  // missed clk_rd pulses. To avoid this, reset the points back to their
  // original values each time the CQ IODELAY reset is issued from
  // calibration.
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      cq_dly_rst_r  <= #TCQ 0;
      cq_dly_rst_2r <= #TCQ 0;
      cq_dly_rst_3r <= #TCQ 0;
      cq_dly_rst_4r <= #TCQ 0;
    end else begin
      cq_dly_rst_r  <= #TCQ cq_dly_rst;
      cq_dly_rst_2r <= #TCQ cq_dly_rst_r;
      cq_dly_rst_3r <= #TCQ cq_dly_rst_2r;
      cq_dly_rst_4r <= #TCQ cq_dly_rst_3r;
    end
  end

  // Extend the reset signal to ensure (1) that the pulse is not missed due to
  // the unknown phase of the two clocks and (2) that the change of phase
  // resulting from clk_rd being reset does not affect this logic.
  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      cq_dly_rst_ext <= #TCQ 0;
    else
      cq_dly_rst_ext <= #TCQ cq_dly_rst_r  || cq_dly_rst_2r ||
                             cq_dly_rst_3r || cq_dly_rst_4r;
  end

  // Match double registers used to cross from clk_rd to clk domain to ensure
  // that both pointers are reset within a cycle of each other.
  always @(posedge clk_rd) begin
    if (rst_clk_rd) begin
      cdr_clkrd_r   <= #TCQ 0;
      rst_wr_ptr    <= #TCQ 0;
    end else begin
      cdr_clkrd_r   <= #TCQ cq_dly_rst_ext;
      rst_wr_ptr    <= #TCQ cdr_clkrd_r;
    end
  end

  // Cross from clk_rd to clk domain
  always @(posedge clk) begin
    if (rst_clk) begin
      cdr_clk_r   <= #TCQ 0;
      rst_rd_ptr  <= #TCQ 0;
    end else begin
      cdr_clk_r   <= #TCQ cq_dly_rst_ext;
      rst_rd_ptr  <= #TCQ cdr_clk_r;
    end
  end

  // Read pointer must always trail write pointer. Therefore, reset write pointer
  // to 3 and read pointer to 0 to allow sufficient spacing between the pointers
  // under reset uncertainties and variations in clock phases over V/T. Otherwise,
  // the pointers continually increment and wrap around when the counter tops out.
  always @(posedge clk_rd) begin
    if (rst_clk_rd)
      wr_ptr <= #TCQ 3;
    else if (rst_wr_ptr)
      wr_ptr <= #TCQ 3;
    else
      wr_ptr <= #TCQ wr_ptr + 1'b1;
  end

  // The read pointer has one additional requirement in that if inc_latency is
  // asserted for the clk cycle, then the read pointer doesn't increment. This
  // has the affect of increasing the latency through the system.
  always @(posedge clk) begin
    if (rst_clk)
      rd_ptr <= #TCQ 0;
    else if (rst_rd_ptr)
      rd_ptr <= #TCQ 0;
    else if (inc_latency)
      rd_ptr <= #TCQ rd_ptr;
    else
      rd_ptr <= #TCQ rd_ptr + 1'b1;
  end

  // Assign debug signals
  assign dbg_dcb_din    = dcb_in;
  assign dbg_dcb_dout   = dcb_out;
  assign dbg_dcb_wr_ptr = wr_ptr;
  assign dbg_dcb_rd_ptr = rd_ptr;
  
  assign di_int0 = dcb_in;
  assign dcb_out = do_int0;
  
  
  //***************************************************************************
  // instantiate RAM64X1D for storage for x8, x9 and x18 memories
  //***************************************************************************

  genvar i;

    generate
    for(i = 0; i < 4*MEMORY_WIDTH; i = i+1) begin: gen_ram
      RAM64X1D #
      (
        .INIT (64'h0000000000000000)
      )
      u_RAM64X1D
      (.DPO         (do_int0[i]),
       .SPO         (),
       .A0          (wr_ptr[0]),
       .A1          (wr_ptr[1]),
       .A2          (wr_ptr[2]),
       .A3          (wr_ptr[3]),  
       .A4          (wr_ptr[4]),  
       .A5          (1'b0),
       .D           (di_int0[i]),
       .DPRA0       (rd_ptr[0]),
       .DPRA1       (rd_ptr[1]),
       .DPRA2       (rd_ptr[2]),
       .DPRA3       (rd_ptr[3]), 
       .DPRA4       (rd_ptr[4]), 
       .DPRA5       (1'b0),
       .WCLK        (clk_rd),
       .WE          (1'b1)
      );
    end
  endgenerate




endmodule
