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
// /___/   /\     Date Last Modified : $Date: 2010/10/27 17:40:34 $
// \   \  /  \    Date Created       : Fri Jul 03 2009
//  \___\/\___\
//
// Device           : Virtex-6
// Design Name      : DDR3 SDRAM
// Purpose          :
//                   Top-level testbench for testing DDR3.
//                   Instantiates:
//                     1. IP_TOP (top-level representing FPGA, contains core,
//                        clocking, built-in testbench/memory checker and other
//                        support structures)
//                     2. DDR3 Memory
//                     3. Miscellaneous clock generation and reset logic
// Reference        :
// Revision History :
//*****************************************************************************

`timescale 1ps/100fs

module sim_tb_top #(

   parameter nCS_PER_RANK            = 1,
                                       // # of unique CS outputs per Rank for
                                       // phy.
   parameter DQS_CNT_WIDTH           = 3,
                                       // # = ceil(log2(DQS_WIDTH)).
   parameter RANK_WIDTH              = 1,
                                       // # = ceil(log2(RANKS)).
   parameter BANK_WIDTH              = 3,
                                       // # of memory Bank Address bits.
   parameter CK_WIDTH                = 2,
                                       // # of CK/CK# outputs to memory.
   parameter CKE_WIDTH               = 2,
                                       // # of CKE outputs to memory.
   parameter COL_WIDTH               = 10,
                                       // # of memory Column Address bits.
   parameter CS_WIDTH                = 2,
                                       // # of unique CS outputs to memory.
   parameter DM_WIDTH                = 8,
                                       // # of Data Mask bits.
   parameter DQ_WIDTH                = 64,
                                       // # of Data (DQ) bits.
   parameter DQS_WIDTH               = 8,
                                       // # of DQS/DQS# bits.
   parameter ROW_WIDTH               = 15,
                                       // # of memory Row Address bits.
                                       // DQS groups in column #4.
   // --------------------------------------- //
   // Don't Modify Parameters Below this Line //
   // --------------------------------------- //
   parameter ADDR_WIDTH              = RANK_WIDTH+BANK_WIDTH+ROW_WIDTH+COL_WIDTH
                                       // # = RANK_WIDTH + BANK_WIDTH
                                       //     + ROW_WIDTH + COL_WIDTH;
)
(
        inout [CK_WIDTH-1:0]                ddr3_ck_p_fpga,
        input [CK_WIDTH-1:0]                ddr3_ck_n_fpga,
        input [ROW_WIDTH-1:0]               ddr3_addr_fpga,
        input [BANK_WIDTH-1:0]              ddr3_ba_fpga,
        input                               ddr3_ras_n_fpga,
        input                               ddr3_cas_n_fpga,
        input                               ddr3_we_n_fpga,
        input [CS_WIDTH-1:0]                ddr3_cs_n_fpga,
        input [CKE_WIDTH-1:0]               ddr3_cke_fpga,
        input [(CS_WIDTH*nCS_PER_RANK)-1:0] ddr3_odt_fpga,
        input                               ddr3_reset_n,
        input [DM_WIDTH-1:0]                ddr3_dm_fpga,
        input [DQ_WIDTH-1:0]                ddr3_dq_fpga,
        inout [DQS_WIDTH-1:0]               ddr3_dqs_p_fpga,
        inout [DQS_WIDTH-1:0]               ddr3_dqs_n_fpga,
        inout                               ddr3_sda,
        input                               ddr3_scl
);



  function integer STR_TO_INT;
    input [7:0] in;
    begin
      if(in == "8")
        STR_TO_INT = 8;
      else if(in == "4")
        STR_TO_INT = 4;
      else
        STR_TO_INT = 0;
    end
  endfunction

  //**************************************************************************//
  // Local parameters Declarations
  //**************************************************************************//

  localparam real TPROP_DQS          = 0.00;  // Delay for DQS signal during Write Operation
  localparam real TPROP_DQS_RD       = 0.00;  // Delay for DQS signal during Read Operation
  localparam real TPROP_PCB_CTRL     = 0.00;  // Delay for Address and Ctrl signals
  localparam real TPROP_PCB_DATA     = 0.00;  // Delay for data signal during Write operation
  localparam real TPROP_PCB_DATA_RD  = 0.00;  // Delay for data signal during Read operation

  localparam MEMORY_WIDTH = 8;
  localparam NUM_COMP = DQ_WIDTH/MEMORY_WIDTH;
  localparam DRAM_DEVICE = "COMP";
                         // DRAM_TYPE: "UDIMM", "RDIMM", "COMPS"

  //**************************************************************************//
  // Wire Declarations
  //**************************************************************************//
  reg                                   sys_rst_n;

  reg   [DM_WIDTH-1:0]                  ddr3_dm_sdram_tmp;

  wire  [DQ_WIDTH-1:0]                  ddr3_dq_sdram;
  reg   [ROW_WIDTH-1:0]                 ddr3_addr_sdram;
  reg   [BANK_WIDTH-1:0]                ddr3_ba_sdram;
  reg                                   ddr3_ras_n_sdram;
  reg                                   ddr3_cas_n_sdram;
  reg                                   ddr3_we_n_sdram;
  reg   [(CS_WIDTH*nCS_PER_RANK)-1:0]   ddr3_cs_n_sdram;
  reg   [(CS_WIDTH*nCS_PER_RANK)-1:0]   ddr3_odt_sdram;
  reg   [CKE_WIDTH-1:0]                 ddr3_cke_sdram;
  wire  [DM_WIDTH-1:0]                  ddr3_dm_sdram;
  wire  [DQS_WIDTH-1:0]                 ddr3_dqs_p_sdram;
  wire  [DQS_WIDTH-1:0]                 ddr3_dqs_n_sdram;
  reg   [CK_WIDTH-1:0]                  ddr3_ck_p_sdram;
  reg   [CK_WIDTH-1:0]                  ddr3_ck_n_sdram;


  //**************************************************************************//
  // Reset Generation
  //**************************************************************************//
  initial begin
    sys_rst_n = 1'b0;
    #120000
      sys_rst_n = 1'b1;
   end


  //**************************************************************************//
  always @( * ) begin
    ddr3_ck_p_sdram   <=  #(TPROP_PCB_CTRL) ddr3_ck_p_fpga;
    ddr3_ck_n_sdram   <=  #(TPROP_PCB_CTRL) ddr3_ck_n_fpga;
    ddr3_addr_sdram   <=  #(TPROP_PCB_CTRL) ddr3_addr_fpga;
    ddr3_ba_sdram     <=  #(TPROP_PCB_CTRL) ddr3_ba_fpga;
    ddr3_ras_n_sdram  <=  #(TPROP_PCB_CTRL) ddr3_ras_n_fpga;
    ddr3_cas_n_sdram  <=  #(TPROP_PCB_CTRL) ddr3_cas_n_fpga;
    ddr3_we_n_sdram   <=  #(TPROP_PCB_CTRL) ddr3_we_n_fpga;
    ddr3_cs_n_sdram   <=  #(TPROP_PCB_CTRL) ddr3_cs_n_fpga;
    ddr3_cke_sdram    <=  #(TPROP_PCB_CTRL) ddr3_cke_fpga;
    ddr3_odt_sdram    <=  #(TPROP_PCB_CTRL) ddr3_odt_fpga;
  end

  always @( * )
    ddr3_dm_sdram_tmp <=  #(TPROP_PCB_DATA) ddr3_dm_fpga;//DM signal generation
  assign ddr3_dm_sdram = ddr3_dm_sdram_tmp;


  // Controlling the bi-directional BUS

  genvar dqwd;
  generate
    for (dqwd = 0;dqwd < DQ_WIDTH;dqwd = dqwd+1) begin : dq_delay
      WireDelay #
       (
        .Delay_g  (TPROP_PCB_DATA),
        .Delay_rd (TPROP_PCB_DATA_RD)
       )
      u_delay_dq
       (
        .A     (ddr3_dq_fpga[dqwd]),
        .B     (ddr3_dq_sdram[dqwd]),
        .reset (sys_rst_n)
       );
    end
  endgenerate

  genvar dqswd;
  generate
    for (dqswd = 0;dqswd < DQS_WIDTH;dqswd = dqswd+1) begin : dqs_delay
      WireDelay #
       (
        .Delay_g  (TPROP_DQS),
        .Delay_rd (TPROP_DQS_RD)
       )
      u_delay_dqs_p
       (
        .A     (ddr3_dqs_p_fpga[dqswd]),
        .B     (ddr3_dqs_p_sdram[dqswd]),
        .reset (sys_rst_n)
       );

      WireDelay #
       (
        .Delay_g  (TPROP_DQS),
        .Delay_rd (TPROP_DQS_RD)
       )
      u_delay_dqs_n
       (
        .A     (ddr3_dqs_n_fpga[dqswd]),
        .B     (ddr3_dqs_n_sdram[dqswd]),
        .reset (sys_rst_n)
       );
    end
  endgenerate
   
  //**************************************************************************//
  // Memory Models instantiations
  //**************************************************************************//

  genvar r,i;
  generate
    for (r = 0; r < CS_WIDTH; r = r + 1) begin: mem_rnk
      for (i = 0; i < NUM_COMP; i = i + 1) begin: gen_mem
        ddr3_model u_comp_ddr3
          (
           .rst_n   (ddr3_reset_n),
           .ck      (ddr3_ck_p_sdram[(i*MEMORY_WIDTH)/72]),
           .ck_n    (ddr3_ck_n_sdram[(i*MEMORY_WIDTH)/72]),
           .cke     (ddr3_cke_sdram[((i*MEMORY_WIDTH)/72)+(nCS_PER_RANK*r)]),
           .cs_n    (ddr3_cs_n_sdram[((i*MEMORY_WIDTH)/72)+(nCS_PER_RANK*r)]),
           .ras_n   (ddr3_ras_n_sdram),
           .cas_n   (ddr3_cas_n_sdram),
           .we_n    (ddr3_we_n_sdram),
           .dm_tdqs (ddr3_dm_sdram[i]),
           .ba      (ddr3_ba_sdram),
           .addr    (ddr3_addr_sdram),
           .dq      (ddr3_dq_sdram[MEMORY_WIDTH*(i+1)-1:MEMORY_WIDTH*(i)]),
           .dqs     (ddr3_dqs_p_sdram[i]),
           .dqs_n   (ddr3_dqs_n_sdram[i]),
           .tdqs_n  (),
           .odt     (ddr3_odt_sdram[((i*MEMORY_WIDTH)/72)+(nCS_PER_RANK*r)])
           );
      end
    end
  endgenerate

endmodule
