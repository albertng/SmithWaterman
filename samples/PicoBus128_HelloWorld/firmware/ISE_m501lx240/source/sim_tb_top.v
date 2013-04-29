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
// \   \  /  \    Date Created       : Mon Jun 23 2008
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

module sim_tb_top (
    inout [31:0]   ddr3_dq_fpga,
    input [13:0]   ddr3_addr_fpga,
    input [2:0]    ddr3_ba_fpga,
    input          ddr3_ras_n_fpga,
    input          ddr3_cas_n_fpga,
    input          ddr3_we_n_fpga,
    input [0:0]    ddr3_cs_n_fpga,
    input [0:0]    ddr3_odt_fpga,
    input [1-1:0]  ddr3_cke_fpga,
    input          ddr3_reset_n,
    input [3:0]    ddr3_dm_fpga,
    inout [3:0]    ddr3_dqs_p_fpga,
    inout [3:0]    ddr3_dqs_n_fpga,
    input [1-1:0]  ddr3_ck_p_fpga,
    input [1-1:0]  ddr3_ck_n_fpga,
    inout          ddr3_sda,
    input          ddr3_scl
);

  parameter REFCLK_FREQ           = 300;
                                    // # = 200 when design frequency < 533 MHz,
                                    //   = 300 when design frequency >= 533 MHz.
  parameter SIM_BYPASS_INIT_CAL   = "FAST";
                                    // # = "OFF" -  Complete memory init &
                                    //              calibration sequence
                                    // # = "SKIP" - Skip memory init &
                                    //              calibration sequence
                                    // # = "FAST" - Skip memory init & use
                                    //              abbreviated calib sequence
  parameter RST_ACT_LOW           = 1;
                                    // =1 for active low reset,
                                    // =0 for active high.
  parameter IODELAY_GRP           = "IODELAY_MIG";
                                    //to phy_top
  parameter nCK_PER_CLK           = 2;
                                    // # of memory CKs per fabric clock.
                                    // # = 2, 1.
  parameter nCS_PER_RANK          = 1;
                                    // # of unique CS outputs per Rank for
                                    // phy.
  parameter DQS_CNT_WIDTH         = 2;
                                    // # = ceil(log2(DQS_WIDTH)).
  parameter RANK_WIDTH            = 1;
                                    // # = ceil(log2(RANKS)).
  parameter BANK_WIDTH            = 3;
                                    // # of memory Bank Address bits.
  parameter CK_WIDTH              = 1;
                                    // # of CK/CK# outputs to memory.
  parameter CKE_WIDTH             = 1;
                                    // # of CKE outputs to memory.
  parameter COL_WIDTH             = 10;
                                    // # of memory Column Address bits.
  parameter CS_WIDTH              = 1;
                                    // # of unique CS outputs to memory.
  parameter DM_WIDTH              = 4;
                                    // # of Data Mask bits.
  parameter DQ_WIDTH              = 32;
                                    // # of Data (DQ) bits.
  parameter DQS_WIDTH             = 4;
                                    // # of DQS/DQS# bits.
  parameter ROW_WIDTH             = 14;
                                    // # of memory Row Address bits.
  parameter BURST_MODE            = "8";
                                    // Burst Length (Mode Register 0).
                                    // # = "8", "4", "OTF".
  parameter INPUT_CLK_TYPE        = "SINGLE_ENDED";
                                    // input clock type DIFFERENTIAL or SINGLE_ENDED
  parameter BM_CNT_WIDTH          = 3;
                                    // # = ceil(log2(nBANK_MACHS)).
  parameter ADDR_CMD_MODE         = "1T" ;
                                    // # = "2T", "1T".
  parameter ORDERING              = "NORM";
                                    // # = "NORM", "STRICT", "RELAXED".
  parameter RTT_NOM               = "60";
                                    // RTT_NOM (ODT) (Mode Register 1).
                                    // # = "DISABLED" - RTT_NOM disabled,
                                    //   = "120" - RZQ/2,
                                    //   = "60" - RZQ/4,
                                    //   = "40" - RZQ/6.
   parameter RTT_WR               = "OFF";
                                       // RTT_WR (ODT) (Mode Register 2).
                                       // # = "OFF" - Dynamic ODT off,
                                       //   = "120" - RZQ/2,
                                       //   = "60" - RZQ/4,
  parameter OUTPUT_DRV            = "HIGH";
                                    // Output Driver Impedance Control (Mode Register 1).
                                    // # = "HIGH" - RZQ/7,
                                    //   = "LOW" - RZQ/6.
  parameter REG_CTRL              = "OFF";
                                    // # = "ON" - RDIMMs,
                                    //   = "OFF" - Components, SODIMMs, UDIMMs.
  parameter CLKFBOUT_MULT_F       = 16;
                                    // write PLL VCO multiplier.
  parameter DIVCLK_DIVIDE         = 8;
                                    // write PLL VCO divisor.
  parameter CLKOUT_DIVIDE         = 2;
                                    // VCO output divisor for fast (memory) clocks.
  parameter tCK                   = 1875;
                                    // memory tCK paramter.
                                    // # = Clock Period.
  parameter DEBUG_PORT            = "OFF";
                                    // # = "ON" Enable debug signals/controls.
                                    //   = "OFF" Disable debug signals/controls.
  parameter tPRDI                   = 1_000_000;
                                    // memory tPRDI paramter.
  parameter tREFI                   = 7800000;
                                    // memory tREFI paramter.
  parameter tZQI                    = 128_000_000;
                                    // memory tZQI paramter.
  parameter ADDR_WIDTH              = 28;
                                    // # = RANK_WIDTH + BANK_WIDTH
                                    //     + ROW_WIDTH + COL_WIDTH;
  parameter STARVE_LIMIT            = 2;
                                    // # = 2,3,4.
  parameter TCQ                     = 100;
  parameter ECC_TEST                = "OFF";
  parameter DATA_WIDTH              = 32;
  parameter PAYLOAD_WIDTH           = (ECC_TEST == "OFF") ? DATA_WIDTH : DQ_WIDTH;


	  
  parameter INTERFACE               = "AXI4";
                                      // Port Interface.
                                      // # = UI - User Interface,
                                      //   = AXI4 - AXI4 Interface.
  //***********************************************************************//
  // AXI related parameters
  //***********************************************************************//
  parameter C_S_AXI_ID_WIDTH        = 8; 
                                      // Width of all master and slave ID signals.
                                      // # = >= 1.
  parameter C_S_AXI_ADDR_WIDTH      = 32; 
                                      // Width of S_AXI_AWADDR, S_AXI_ARADDR, M_AXI_AWADDR and 
                                      // M_AXI_ARADDR for all SI/MI slots.
                                      // # = 32.
  parameter C_S_AXI_DATA_WIDTH      = 128;
                                      // Width of WDATA and RDATA on SI slot.
                                      // Must be less or equal to APP_DATA_WIDTH.
				      // # = 32, 64, 128, 256.
  //**************************************************************************//
  // Local parameters Declarations
  //**************************************************************************//
  localparam real TPROP_DQS          = 0.00;  // Delay for DQS signal during Write Operation
  localparam real TPROP_DQS_RD       = 0.00;  // Delay for DQS signal during Read Operation
  localparam real TPROP_PCB_CTRL     = 0.00;  // Delay for Address and Ctrl signals
  localparam real TPROP_PCB_DATA     = 0.00;  // Delay for data signal during Write operation
  localparam real TPROP_PCB_DATA_RD  = 0.00;  // Delay for data signal during Read operation

  localparam MEMORY_WIDTH = 16;
  localparam NUM_COMP = DQ_WIDTH/MEMORY_WIDTH;
  localparam real CLK_PERIOD = tCK;
  localparam real REFCLK_PERIOD = (1000000.0/(2*REFCLK_FREQ));
  localparam DRAM_DEVICE = "COMP";
                         // DRAM_TYPE: "UDIMM", "RDIMM", "COMPS"

   // VT delay change options/settings
  localparam VT_ENABLE                  = "OFF";
                                        // Enable VT delay var's
  localparam VT_RATE                    = CLK_PERIOD/500;
                                        // Size of each VT step
  localparam VT_UPDATE_INTERVAL         = CLK_PERIOD*50;
                                        // Update interval
  localparam VT_MAX                     = CLK_PERIOD/40;
                                        // Maximum VT shift


  //**************************************************************************//
  // Wire Declarations
  //**************************************************************************//
  reg sys_rst_n;


  reg [DM_WIDTH-1:0]                 ddr3_dm_sdram_tmp;


  // The test bench output signal 'error' is not valid for AXI
  // designs because the test bench is not available as of now
  wire                               error;          
  wire                               phy_init_done;
  wire                               ddr3_parity;
  wire                               sda;
  wire                               scl;

/* COMMENTED OUT
     wire [DQ_WIDTH-1:0]                ddr3_dq_fpga;
     wire [ROW_WIDTH-1:0]               ddr3_addr_fpga;
     wire [BANK_WIDTH-1:0]              ddr3_ba_fpga;
     wire                               ddr3_ras_n_fpga;
     wire                               ddr3_cas_n_fpga;
     wire                               ddr3_we_n_fpga;
     wire [(CS_WIDTH*nCS_PER_RANK)-1:0] ddr3_cs_n_fpga;
     wire [(CS_WIDTH*nCS_PER_RANK)-1:0] ddr3_odt_fpga;
     wire [CKE_WIDTH-1:0]               ddr3_cke_fpga;
     wire [DM_WIDTH-1:0]                ddr3_dm_fpga;
     wire [DQS_WIDTH-1:0]               ddr3_dqs_p_fpga;
     wire [DQS_WIDTH-1:0]               ddr3_dqs_n_fpga;
     wire [CK_WIDTH-1:0]                ddr3_ck_p_fpga;
     wire [CK_WIDTH-1:0]                ddr3_ck_n_fpga;
COMMENTED OUT*/

  wire [DQ_WIDTH-1:0]                ddr3_dq_sdram;
  reg [ROW_WIDTH-1:0]                ddr3_addr_sdram;
  reg [BANK_WIDTH-1:0]               ddr3_ba_sdram;
  reg                                ddr3_ras_n_sdram;
  reg                                ddr3_cas_n_sdram;
  reg                                ddr3_we_n_sdram;
  reg [(CS_WIDTH*nCS_PER_RANK)-1:0]  ddr3_cs_n_sdram;
  reg [(CS_WIDTH*nCS_PER_RANK)-1:0]  ddr3_odt_sdram;
  reg [CKE_WIDTH-1:0]                ddr3_cke_sdram;
  wire [DM_WIDTH-1:0]                ddr3_dm_sdram;
  wire [DQS_WIDTH-1:0]               ddr3_dqs_p_sdram;
  wire [DQS_WIDTH-1:0]               ddr3_dqs_n_sdram;
  reg [CK_WIDTH-1:0]                 ddr3_ck_p_sdram;
  reg [CK_WIDTH-1:0]                 ddr3_ck_n_sdram;

  reg [ROW_WIDTH-1:0]               ddr3_addr_r;
  reg [BANK_WIDTH-1:0]              ddr3_ba_r;
  reg                               ddr3_ras_n_r;
  reg                               ddr3_cas_n_r;
  reg                               ddr3_we_n_r;
  reg [(CS_WIDTH*nCS_PER_RANK)-1:0] ddr3_cs_n_r;
  reg [(CS_WIDTH*nCS_PER_RANK)-1:0] ddr3_odt_r;
  reg [CKE_WIDTH-1:0]               ddr3_cke_r;


  wire                               clk;
  wire                               rst;		  

  //**************************************************************************//
  // Clock generation and reset
  //**************************************************************************//

  initial begin
    sys_rst_n = 1'b0;

    #120000
      sys_rst_n = 1'b1;
  end

   assign sys_rst = RST_ACT_LOW ? sys_rst_n : ~sys_rst_n;

  //**************************************************************************//


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
    ddr3_dm_sdram_tmp <=  #(TPROP_PCB_DATA) ddr3_dm_fpga;//DM signal generation
  end

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

  assign sda = 1'b1;
  assign scl = 1'b1;


   // Extra one clock pipelining for RDIMM address and
   // control signals is implemented here (Implemented external to memory model)
   always @( posedge ddr3_ck_p_sdram[0] ) begin
     if ( ddr3_reset_n == 1'b0 ) begin
       ddr3_ras_n_r <= 1'b1;
       ddr3_cas_n_r <= 1'b1;
       ddr3_we_n_r  <= 1'b1;
       ddr3_cs_n_r  <= {(CS_WIDTH*nCS_PER_RANK){1'b1}};
       ddr3_odt_r   <= 1'b0;
     end
     else begin
       ddr3_addr_r  <= #(CLK_PERIOD/2) ddr3_addr_sdram;
       ddr3_ba_r    <= #(CLK_PERIOD/2) ddr3_ba_sdram;
       ddr3_ras_n_r <= #(CLK_PERIOD/2) ddr3_ras_n_sdram;
       ddr3_cas_n_r <= #(CLK_PERIOD/2) ddr3_cas_n_sdram;
       ddr3_we_n_r  <= #(CLK_PERIOD/2) ddr3_we_n_sdram;
       ddr3_cs_n_r  <= #(CLK_PERIOD/2) ddr3_cs_n_sdram;
       ddr3_odt_r   <= #(CLK_PERIOD/2) ddr3_odt_sdram;
     end
   end

   // to avoid tIS violations on CKE when reset is deasserted
   always @( posedge ddr3_ck_n_sdram[0] )
     if ( ddr3_reset_n == 1'b0 )
       ddr3_cke_r <= 1'b0;
     else
       ddr3_cke_r <= #(CLK_PERIOD) ddr3_cke_sdram;



  //***************************************************************************
  // Instantiate memories
  //***************************************************************************

  genvar r,i,dqs_x;
  generate
    if(DRAM_DEVICE == "COMP") begin : comp_inst
      for (r = 0; r < CS_WIDTH; r = r+1) begin: mem_rnk
        if(MEMORY_WIDTH == 16) begin: mem_16
          if(DQ_WIDTH/16) begin: gen_mem
            for (i = 0; i < NUM_COMP; i = i + 1) begin: gen_mem
              ddr3_model u_comp_ddr3
                (
                 .rst_n   (ddr3_reset_n),
                 .ck      (ddr3_ck_p_sdram),
                 .ck_n    (ddr3_ck_n_sdram),
                 .cke     (ddr3_cke_sdram[r]),
                 .cs_n    (ddr3_cs_n_sdram[r]),
                 .ras_n   (ddr3_ras_n_sdram),
                 .cas_n   (ddr3_cas_n_sdram),
                 .we_n    (ddr3_we_n_sdram),
                 .dm_tdqs (ddr3_dm_sdram[(2*(i+1)-1):(2*i)]),
                 .ba      (ddr3_ba_sdram),
                 .addr    (ddr3_addr_sdram),
                 .dq      (ddr3_dq_sdram[16*(i+1)-1:16*(i)]),
                 .dqs     (ddr3_dqs_p_sdram[(2*(i+1)-1):(2*i)]),
                 .dqs_n   (ddr3_dqs_n_sdram[(2*(i+1)-1):(2*i)]),
                 .tdqs_n  (),
                 .odt     (ddr3_odt_sdram[r])
                 );
            end
          end
          if (DQ_WIDTH%16) begin: gen_mem_extrabits
            ddr3_model u_comp_ddr3
              (
               .rst_n   (ddr3_reset_n),
               .ck      (ddr3_ck_p_sdram),
               .ck_n    (ddr3_ck_n_sdram),
               .cke     (ddr3_cke_sdram[r]),
               .cs_n    (ddr3_cs_n_sdram[r]),
               .ras_n   (ddr3_ras_n_sdram),
               .cas_n   (ddr3_cas_n_sdram),
               .we_n    (ddr3_we_n_sdram),
               .dm_tdqs ({ddr3_dm_sdram[DM_WIDTH-1],ddr3_dm_sdram[DM_WIDTH-1]}),
               .ba      (ddr3_ba_sdram),
               .addr    (ddr3_addr_sdram),
               .dq      ({ddr3_dq_sdram[DQ_WIDTH-1:(DQ_WIDTH-8)],
                          ddr3_dq_sdram[DQ_WIDTH-1:(DQ_WIDTH-8)]}),
               .dqs     ({ddr3_dqs_p_sdram[DQS_WIDTH-1],
                          ddr3_dqs_p_sdram[DQS_WIDTH-1]}),
               .dqs_n   ({ddr3_dqs_n_sdram[DQS_WIDTH-1],
                          ddr3_dqs_n_sdram[DQS_WIDTH-1]}),
               .tdqs_n  (),
               .odt     (ddr3_odt_sdram[r])
               );
          end
        end
        else if((MEMORY_WIDTH == 8) || (MEMORY_WIDTH == 4)) begin: mem_8_4
          for (i = 0; i < NUM_COMP; i = i + 1) begin: gen_mem
            ddr3_model u_comp_ddr3
              (
               .rst_n   (ddr3_reset_n),
               .ck      (ddr3_ck_p_sdram),
               .ck_n    (ddr3_ck_n_sdram),
               .cke     (ddr3_cke_sdram[r]),
               .cs_n    (ddr3_cs_n_sdram[r]),
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
               .odt     (ddr3_odt_sdram[r])
               );
          end
        end
      end
    end
    else if(DRAM_DEVICE == "RDIMM") begin: rdimm_inst
      for (r = 0; r < CS_WIDTH; r = r+1) begin: mem_rnk
        if((MEMORY_WIDTH == 8) || (MEMORY_WIDTH == 4)) begin: mem_8_4
          for (i = 0; i < NUM_COMP; i = i + 1) begin: gen_mem
            ddr3_model u_comp_ddr3
              (
               .rst_n   (ddr3_reset_n),
               .ck      (ddr3_ck_p_sdram[(i*MEMORY_WIDTH)/72]),
               .ck_n    (ddr3_ck_n_sdram[(i*MEMORY_WIDTH)/72]),
               .cke     (ddr3_cke_r[((i*MEMORY_WIDTH)/72)+(nCS_PER_RANK*r)]),
               .cs_n    (ddr3_cs_n_r[((i*MEMORY_WIDTH)/72)+(nCS_PER_RANK*r)]),
               .ras_n   (ddr3_ras_n_r),
               .cas_n   (ddr3_cas_n_r),
               .we_n    (ddr3_we_n_r),
               .dm_tdqs (ddr3_dm_sdram[i]),
               .ba      (ddr3_ba_r),
               .addr    (ddr3_addr_r),
               .dq      (ddr3_dq_sdram[MEMORY_WIDTH*(i+1)-1:MEMORY_WIDTH*(i)]),
               .dqs     (ddr3_dqs_p_sdram[i]),
               .dqs_n   (ddr3_dqs_n_sdram[i]),
               .tdqs_n  (),
               .odt     (ddr3_odt_r[((i*MEMORY_WIDTH)/72)+(nCS_PER_RANK*r)])
               );
          end
        end
      end
    end
    else if(DRAM_DEVICE == "UDIMM") begin: udimm_inst
      for (r = 0; r < CS_WIDTH; r = r+1) begin: mem_rnk
        if(MEMORY_WIDTH == 16) begin: mem_16
          if(DQ_WIDTH/16) begin: gen_mem
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
                 .dm_tdqs (ddr3_dm_sdram[(2*(i+1)-1):(2*i)]),
                 .ba      (ddr3_ba_sdram),
                 .addr    (ddr3_addr_sdram),
                 .dq      (ddr3_dq_sdram[MEMORY_WIDTH*(i+1)-1:MEMORY_WIDTH*(i)]),
                 .dqs     (ddr3_dqs_p_sdram[(2*(i+1)-1):(2*i)]),
                 .dqs_n   (ddr3_dqs_n_sdram[(2*(i+1)-1):(2*i)]),
                 .tdqs_n  (),
                 .odt     (ddr3_odt_sdram[((i*MEMORY_WIDTH)/72)+(nCS_PER_RANK*r)])
                 );
            end
          end
          if (DQ_WIDTH%16) begin: gen_mem_extrabits
            ddr3_model u_comp_ddr3
              (
               .rst_n   (ddr3_reset_n),
               .ck      (ddr3_ck_p_sdram[(DQ_WIDTH-1)/72]),
               .ck_n    (ddr3_ck_n_sdram[(DQ_WIDTH-1)/72]),
               .cke     (ddr3_cke_sdram[((DQ_WIDTH-1)/72)+(nCS_PER_RANK*r)]),
               .cs_n    (ddr3_cs_n_sdram[((DQ_WIDTH-1)/72)+(nCS_PER_RANK*r)]),
               .ras_n   (ddr3_ras_n_sdram),
               .cas_n   (ddr3_cas_n_sdram),
               .we_n    (ddr3_we_n_sdram),
               .dm_tdqs ({ddr3_dm_sdram[DM_WIDTH-1],ddr3_dm_sdram[DM_WIDTH-1]}),
               .ba      (ddr3_ba_sdram),
               .addr    (ddr3_addr_sdram),
               .dq      ({ddr3_dq_sdram[DQ_WIDTH-1:(DQ_WIDTH-8)],
                          ddr3_dq_sdram[DQ_WIDTH-1:(DQ_WIDTH-8)]}),
               .dqs     ({ddr3_dqs_p_sdram[DQS_WIDTH-1],
                          ddr3_dqs_p_sdram[DQS_WIDTH-1]}),
               .dqs_n   ({ddr3_dqs_n_sdram[DQS_WIDTH-1],
                          ddr3_dqs_n_sdram[DQS_WIDTH-1]}),
               .tdqs_n  (),
               .odt     (ddr3_odt_sdram[((DQ_WIDTH-1)/72)+(nCS_PER_RANK*r)])
               );
          end
        end
        else if((MEMORY_WIDTH == 8) || (MEMORY_WIDTH == 4)) begin: mem_8_4
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
      end
    end
    else if(DRAM_DEVICE == "SODIMM") begin: sodimm_inst
      for (r = 0; r < CS_WIDTH; r = r+1) begin: mem_rnk
        if(MEMORY_WIDTH == 16) begin: mem_16
          if(DQ_WIDTH/16) begin: gen_mem
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
                 .dm_tdqs (ddr3_dm_sdram[(2*(i+1)-1):(2*i)]),
                 .ba      (ddr3_ba_sdram),
                 .addr    (ddr3_addr_sdram),
                 .dq      (ddr3_dq_sdram[MEMORY_WIDTH*(i+1)-1:MEMORY_WIDTH*(i)]),
                 .dqs     (ddr3_dqs_p_sdram[(2*(i+1)-1):(2*i)]),
                 .dqs_n   (ddr3_dqs_n_sdram[(2*(i+1)-1):(2*i)]),
                 .tdqs_n  (),
                 .odt     (ddr3_odt_sdram[((i*MEMORY_WIDTH)/72)+(nCS_PER_RANK*r)])
                 );
            end
          end
          if (DQ_WIDTH%16) begin: gen_mem_extrabits
            ddr3_model u_comp_ddr3
              (
               .rst_n   (ddr3_reset_n),
               .ck      (ddr3_ck_p_sdram[(DQ_WIDTH-1)/72]),
               .ck_n    (ddr3_ck_n_sdram[(DQ_WIDTH-1)/72]),
               .cke     (ddr3_cke_sdram[((DQ_WIDTH-1)/72)+(nCS_PER_RANK*r)]),
               .cs_n    (ddr3_cs_n_sdram[((DQ_WIDTH-1)/72)+(nCS_PER_RANK*r)]),
               .ras_n   (ddr3_ras_n_sdram),
               .cas_n   (ddr3_cas_n_sdram),
               .we_n    (ddr3_we_n_sdram),
               .dm_tdqs ({ddr3_dm_sdram[DM_WIDTH-1],ddr3_dm_sdram[DM_WIDTH-1]}),
               .ba      (ddr3_ba_sdram),
               .addr    (ddr3_addr_sdram),
               .dq      ({ddr3_dq_sdram[DQ_WIDTH-1:(DQ_WIDTH-8)],
                          ddr3_dq_sdram[DQ_WIDTH-1:(DQ_WIDTH-8)]}),
               .dqs     ({ddr3_dqs_p_sdram[DQS_WIDTH-1],
                          ddr3_dqs_p_sdram[DQS_WIDTH-1]}),
               .dqs_n   ({ddr3_dqs_n_sdram[DQS_WIDTH-1],
                          ddr3_dqs_n_sdram[DQS_WIDTH-1]}),
               .tdqs_n  (),
               .odt     (ddr3_odt_sdram[((DQ_WIDTH-1)/72)+(nCS_PER_RANK*r)])
               );
          end
        end
        if((MEMORY_WIDTH == 8) || (MEMORY_WIDTH == 4)) begin: mem_8_4
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
      end
    end
  endgenerate

   
   

endmodule

