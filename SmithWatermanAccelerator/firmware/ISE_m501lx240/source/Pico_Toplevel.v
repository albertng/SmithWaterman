
//-----------------------------------------------------------------------------
//
// (c) Copyright 2009 Xilinx, Inc. All rights reserved.
//
// Copyright 2009 Pico Computing, Inc.

`timescale 1ns / 1ps

`include "PicoDefines.v"

module Pico_Toplevel # (
    
    parameter PL_FAST_TRAIN	            = "FALSE",
    parameter C_DATA_WIDTH              = 128,            
                                        // RX/TX interface data width
`ifdef PICO_DDR3    
    ////////////////////////////
    // Shared DDR3 Parameters //
    ////////////////////////////
    parameter nCS_PER_RANK              = 1,
                                        // # of unique CS outputs per Rank for
                                        // phy.
    parameter BANK_WIDTH                = 3,
                                        // # of memory Bank Address bits.
    parameter C0_C_S_AXI_ID_WIDTH       = 12, 
                                        // Width of all master and slave ID signals.
                                        // # = >= 1.
    parameter C0_C_S_AXI_ADDR_WIDTH     = 33, 
                                        // Width of S_AXI_AWADDR, S_AXI_ARADDR, M_AXI_AWADDR and 
                                        // M_AXI_ARADDR for all SI/MI slots.
                                        // # = 32.
    parameter RST_ACT_LOW               = 0,
                                        // =1 for active low reset,
                                        // =0 for active high.
    parameter COL_WIDTH                 = 10,
                                        // bits of the address used to select a column
    //////////////////////////
    // M501 DDR3 Parameters //
    //////////////////////////
	`ifdef PICO_MODEL_M501
    parameter ROW_WIDTH                 = 14,
                                        // # of memory Row Address bits.
    parameter CK_WIDTH                  = 1,
                                        // # of CK/CK# outputs to memory.
    parameter CKE_WIDTH                 = 1,
                                        // # of CKE outputs to memory.
    parameter CS_WIDTH                  = 1,
                                        // # of unique CS outputs to memory.
    parameter DM_WIDTH                  = 4,
                                        // # of Data Mask bits.
    parameter DQ_WIDTH                  = 32,
                                        // # of Data (DQ) bits.
    parameter DQS_WIDTH                 = 4,
                                        // # of DQS/DQS# bits.
    parameter C0_C_S_AXI_DATA_WIDTH     = 128,
                                        // Width of WDATA and RDATA on SI slot.
                                        // Must be less or equal to APP_DATA_WIDTH.
                                        // # = 32, 64, 128, 256.
    parameter RANKS                     = 1,
                                        // number of ranks
    //////////////////////////
    // M503 DDR3 Parameters //
    //////////////////////////
	`elsif PICO_MODEL_M503  // shared M503 DDR3 parameters
    parameter ROW_WIDTH                 = 15,
                                        // # of memory Row Address bits.
    parameter CK_WIDTH                  = 2,
                                        // # of CK/CK# outputs to memory.
    parameter CKE_WIDTH                 = 2,
                                        // # of CKE outputs to memory.
    parameter CS_WIDTH                  = 2,
                                        // # of unique CS outputs to memory.
    parameter DM_WIDTH                  = 8,
                                        // # of Data Mask bits.
    parameter DQ_WIDTH                  = 64,
                                        // # of Data (DQ) bits.
    parameter DQS_WIDTH                 = 8,
                                        // # of DQS/DQS# bits.
                                        // Number of DQS groups in I/O column #2.
    parameter C0_C_S_AXI_DATA_WIDTH     = 256,
                                        // Width of WDATA and RDATA on SI slot.
                                        // Must be less or equal to APP_DATA_WIDTH.
                                        // # = 32, 64, 128, 256.
    parameter C1_C_S_AXI_ID_WIDTH       = 12, 
                                        // Width of all master and slave ID signals.
                                        // # = >= 1.
    parameter C1_C_S_AXI_ADDR_WIDTH     = 32, 
                                        // Width of S_AXI_AWADDR, S_AXI_ARADDR, M_AXI_AWADDR and 
                                        // M_AXI_ARADDR for all SI/MI slots.
                                        // # = 32.
    
    parameter C1_C_S_AXI_DATA_WIDTH     = 256,
                                        // Width of WDATA and RDATA on SI slot.
                                        // Must be less or equal to APP_DATA_WIDTH.
                                        // # = 32, 64, 128, 256.
    parameter RANKS                     = 2,
                                        // number of ranks
    //////////////////////////
    // M505 DDR3 Parameters //
    //////////////////////////
	`elsif PICO_MODEL_M505
    parameter ROW_WIDTH                 = 16,
                                        // # of memory Row Address bits.
    parameter CK_WIDTH                  = 2,    // -> 2 CBO
                                        // # of CK/CK# outputs to memory.
    parameter CS_WIDTH                  = 2,    // -> 2 CBO
                                        // # of unique CS outputs to memory.
    parameter CKE_WIDTH                 = 2,    // -> 2 CBO
                                        // # of CKE outputs to memory.
    parameter DQ_WIDTH                  = 64,
                                        // # of DQ (data)
    parameter DM_WIDTH                  = 8,
                                        // # of DM (data mask)
    parameter DQS_WIDTH                 = 8,
                                        // # of DQS/DQS# bits.
                                        // Number of DQS groups in I/O column #2.
    parameter RANKS                     = 2,
                                        // number of ranks
    parameter ODT_WIDTH                 = 2,
                                        // # of ODT outputs to memory.

    //***************************************************************************
    // AXI4 Shim parameters
    //***************************************************************************
    parameter C0_C_S_AXI_DATA_WIDTH     = 256,
                                        // Width of WDATA and RDATA on SI slot.
                                        // Must be <= APP_DATA_WIDTH.
                                        // # = 32, 64, 128, 256.
    parameter C_RD_WR_ARB_ALGORITHM     = "RD_PRI_REG",
                                        // Indicates the Arbitration
                                        // Allowed values - "TDM", "ROUND_ROBIN",
                                        // "RD_PRI_REG", "RD_PRI_REG_STARVE_LIMIT"

	`endif // PICO_MODEL_M501
`endif // PICO_DDR3 
    
    // Do not override parameters below this line
    parameter STRB_WIDTH                = C_DATA_WIDTH / 8               
                                        // TSTRB width
)
(

`ifdef SIMULATION
    input                               user_clk,
    input                               user_reset,
    input                               user_lnk_up,

    // Tx
    input  [5:0]                        tx_buf_av,
    input                               tx_cfg_req,
    input                               tx_err_drop,
    output                              tx_cfg_gnt,

    input                               s_axis_tx_tready,
    output  [C_DATA_WIDTH-1:0]          s_axis_tx_tdata,
    output  [STRB_WIDTH-1:0]            s_axis_tx_tstrb,
    output  [3:0]                       s_axis_tx_tuser,
    output                              s_axis_tx_tlast,
    output                              s_axis_tx_tvalid,

    // Rx
    output                              rx_np_ok,
    input  [C_DATA_WIDTH-1:0]           m_axis_rx_tdata,
    input  [STRB_WIDTH-1:0]             m_axis_rx_tstrb,
    input                               m_axis_rx_tlast,
    input                               m_axis_rx_tvalid,
    output                              m_axis_rx_tready,
    input  [21:0]                       m_axis_rx_tuser,

    // Flow Control
    input  [11:0]                       fc_cpld,
    input  [7:0]                        fc_cplh,
    input  [11:0]                       fc_npd,
    input  [7:0]                        fc_nph,
    input  [11:0]                       fc_pd,
    input  [7:0]                        fc_ph,
    output [2:0]                        fc_sel,
`else
    output  [7:0]                       pci_exp_txp,
    output  [7:0]                       pci_exp_txn,
    input   [7:0]                       pci_exp_rxp,
    input   [7:0]                       pci_exp_rxn,
`endif // SIMULATION

`ifdef PICO_MODEL_M501
    // flash
    input                               flash_busy,
    output                              flash_byte,
    output                              flash_ce,
    output                              flash_oe,
    output                              flash_reset,
    output                              flash_we,
    output [25:0]                       flash_a,
    inout  [15:0]                       flash_d,
`endif // PICO_MODEL_M501

`ifdef PICO_MODEL_M505
    // flash
    input                               flash_busy,
    output                              flash_byte,
    output                              flash_ce,
    output                              flash_oe,
    output                              flash_reset,
    output                              flash_we,
    output [25:0]                       flash_a,
    inout  [15:0]                       flash_d,
`endif // PICO_MODEL_M501
  
`ifdef PICO_DDR3

    inout  [DQ_WIDTH-1:0]               c0_ddr3_dq,
    output [ROW_WIDTH-1:0]              c0_ddr3_addr,
    output [BANK_WIDTH-1:0]             c0_ddr3_ba,
    output                              c0_ddr3_ras_n,
    output                              c0_ddr3_cas_n,
    output                              c0_ddr3_we_n,
    output                              c0_ddr3_reset_n,
    output [DM_WIDTH-1:0]               c0_ddr3_dm,
    inout  [DQS_WIDTH-1:0]              c0_ddr3_dqs_p,
    inout  [DQS_WIDTH-1:0]              c0_ddr3_dqs_n,
    output [CK_WIDTH-1:0]               c0_ddr3_ck_p,
    output [CK_WIDTH-1:0]               c0_ddr3_ck_n,
    output [CS_WIDTH*nCS_PER_RANK-1:0]  c0_ddr3_cs_n,
	`ifdef PICO_MODEL_M505
    output [ODT_WIDTH-1:0]              c0_ddr3_odt,
    `else
    output [CS_WIDTH*nCS_PER_RANK-1:0]  c0_ddr3_odt,
    `endif
    output [CKE_WIDTH-1:0]              c0_ddr3_cke,
    inout                               c0_ddr3_sda,
    output                              c0_ddr3_scl,
	`ifdef SIMULATION
    output                              c0_phy_init_done,
	`endif // SIMULATION
    
	`ifdef PICO_MODEL_M503
    inout  [DQ_WIDTH-1:0]               c1_ddr3_dq,
    output [14:0]                       c1_ddr3_addr,
    output [BANK_WIDTH-1:0]             c1_ddr3_ba,
    output                              c1_ddr3_ras_n,
    output                              c1_ddr3_cas_n,
    output                              c1_ddr3_we_n,
    output                              c1_ddr3_reset_n,
    output [DM_WIDTH-1:0]               c1_ddr3_dm,
    inout  [DQS_WIDTH-1:0]              c1_ddr3_dqs_p,
    inout  [DQS_WIDTH-1:0]              c1_ddr3_dqs_n,
    output [CK_WIDTH-1:0]               c1_ddr3_ck_p,
    output [CK_WIDTH-1:0]               c1_ddr3_ck_n,
    output [CS_WIDTH*nCS_PER_RANK-1:0]  c1_ddr3_cs_n,
    output [CS_WIDTH*nCS_PER_RANK-1:0]  c1_ddr3_odt,
    output [CKE_WIDTH-1:0]              c1_ddr3_cke,
    inout                               c1_ddr3_sda,
    output                              c1_ddr3_scl,

		`ifdef SIMULATION
    output                              c1_phy_init_done, 
		`endif // SIMULATION
	`endif // PICO_MODEL_M503
`endif // PICO_DDR3

`ifdef PICO_QDRII
	`ifdef PICO_MODEL_M503  // QDRII is only on the M503 right now (not the M501 or M505)
    // Memory Interface 0
    input   [0:0]                       c0_qdriip_cq_p,     
    input   [0:0]                       c0_qdriip_cq_n,
    input   [0:0]                       c0_qdriip_qvld,
    input   [17:0]                      c0_qdriip_q,
    output  [0:0]                       c0_qdriip_k_p,
    output  [0:0]                       c0_qdriip_k_n,
    output  [17:0]                      c0_qdriip_d,
    output  [19:0]                      c0_qdriip_sa,
    output                              c0_qdriip_w_n,
    output                              c0_qdriip_r_n,
    output  [1:0]                       c0_qdriip_bw_n,
    output                              c0_qdriip_dll_off_n,
    
    // Memory Interface 1
    input   [0:0]                       c1_qdriip_cq_p,     
    input   [0:0]                       c1_qdriip_cq_n,
    input   [0:0]                       c1_qdriip_qvld,
    input   [17:0]                      c1_qdriip_q,
    output  [0:0]                       c1_qdriip_k_p,
    output  [0:0]                       c1_qdriip_k_n,
    output  [17:0]                      c1_qdriip_d,
    output  [19:0]                      c1_qdriip_sa,
    output                              c1_qdriip_w_n,
    output                              c1_qdriip_r_n,
    output  [1:0]                       c1_qdriip_bw_n,
    output                              c1_qdriip_dll_off_n,
    
    // Memory Interface 2
    input   [0:0]                       c2_qdriip_cq_p,     
    input   [0:0]                       c2_qdriip_cq_n,
    input   [0:0]                       c2_qdriip_qvld,
    input   [17:0]                      c2_qdriip_q,
    output  [0:0]                       c2_qdriip_k_p,
    output  [0:0]                       c2_qdriip_k_n,
    output  [17:0]                      c2_qdriip_d,
    output  [19:0]                      c2_qdriip_sa,
    output                              c2_qdriip_w_n,
    output                              c2_qdriip_r_n,
    output  [1:0]                       c2_qdriip_bw_n,
    output                              c2_qdriip_dll_off_n,
       
      `ifdef SIMULATION
    output                              c0_cal_done,
    output                              c1_cal_done,
    output                              c2_cal_done, 
      `endif // SIMULATION
      // PICO_MODEL_M503
    //--------------------------------------------------------//
    // EX-600
    `elsif PICO_MODEL_EX600
    // Memory Interface 0
    input   [0:0]                       c0_qdriip_cq_p,     
    input   [0:0]                       c0_qdriip_cq_n,
    input   [0:0]                       c0_qdriip_qvld,
    input   [35:0]                      c0_qdriip_q,
    output  [0:0]                       c0_qdriip_k_p,
    output  [0:0]                       c0_qdriip_k_n,
    output  [35:0]                      c0_qdriip_d,
    output  [20:0]                      c0_qdriip_sa,
    output                              c0_qdriip_w_n,
    output                              c0_qdriip_r_n,
    output  [3:0]                       c0_qdriip_bw_n,
    output                              c0_qdriip_dll_off_n,
    
    // Memory Interface 1
    input   [0:0]                       c1_qdriip_cq_p,     
    input   [0:0]                       c1_qdriip_cq_n,
    input   [0:0]                       c1_qdriip_qvld,
    input   [35:0]                      c1_qdriip_q,
    output  [0:0]                       c1_qdriip_k_p,
    output  [0:0]                       c1_qdriip_k_n,
    output  [35:0]                      c1_qdriip_d,
    output  [20:0]                      c1_qdriip_sa,
    output                              c1_qdriip_w_n,
    output                              c1_qdriip_r_n,
    output  [3:0]                       c1_qdriip_bw_n,
    output                              c1_qdriip_dll_off_n,
           
      `ifdef SIMULATION
    output                              c0_cal_done,
    output                              c1_cal_done,
      `endif // SIMULATION
    `endif //PICO_MODEL_EX600
`endif // QDRII
    
    input                               extra_clk_p,
    input                               extra_clk_n,
`ifdef PICO_MODEL_M505
    input                               clk_400_p,  
    input                               clk_400_n,  // 400 MHz differential clock inputs used to
                                                    //  generate the DDR3 interface clocks in the
                                                    //  MIG
`endif

//------------------------------------------------------//
// EX-600 Interconnect Pins
//------------------------------------------------------//
`ifdef PICO_MODEL_EX600
    `ifdef EX600_INTERCONNECT
        `ifdef EX600_FPGA_0
            output                          CLK_P_R0,
            output                          CLK_N_R0,
            output  [11:0]                  DATA_R0,
            output                          CLK_P_R1,
            output                          CLK_N_R1,
            output  [11:0]                  DATA_R1,
            output                          CLK_P_R2,
            output                          CLK_N_R2,
            output  [11:0]                  DATA_R2,
            input                           CLK_P_R3,
            input                           CLK_N_R3,
            input   [11:0]                  DATA_R3,
            output                          CLK_P_C0,
            output                          CLK_N_C0,
            output  [11:0]                  DATA_C0,
            output                          CLK_P_C1,
            output                          CLK_N_C1,
            output  [11:0]                  DATA_C1,
            input                           CLK_P_C2,
            input                           CLK_N_C2,
            input   [11:0]                  DATA_C2,
            input                           CLK_P_C3,
            input                           CLK_N_C3,
            input   [11:0]                  DATA_C3,   
        `elsif EX600_FPGA_1
            output                          CLK_P_R0,
            output                          CLK_N_R0,
            output  [11:0]                  DATA_R0,
            output                          CLK_P_R1,
            output                          CLK_N_R1,
            output  [11:0]                  DATA_R1,
            output                          CLK_P_R2,
            output                          CLK_N_R2,
            output  [11:0]                  DATA_R2,
            input                           CLK_P_R3,
            input                           CLK_N_R3,
            input   [11:0]                  DATA_R3,
            input                           CLK_P_C0,
            input                           CLK_N_C0,
            input   [11:0]                  DATA_C0,
            input                           CLK_P_C1,
            input                           CLK_N_C1,
            input   [11:0]                  DATA_C1,
            output                          CLK_P_C2,
            output                          CLK_N_C2,
            output  [11:0]                  DATA_C2,
            output                          CLK_P_C3,
            output                          CLK_N_C3,
            output  [11:0]                  DATA_C3, 
        `elsif EX600_FPGA_2
            output                          CLK_P_R0,
            output                          CLK_N_R0,
            output  [11:0]                  DATA_R0,
            output                          CLK_P_R1,
            output                          CLK_N_R1,
            output  [11:0]                  DATA_R1,
            output                          CLK_P_R2,
            output                          CLK_N_R2,
            output  [11:0]                  DATA_R2,
            input                           CLK_P_R3,
            input                           CLK_N_R3,
            input   [11:0]                  DATA_R3,
            output                          CLK_P_C0,
            output                          CLK_N_C0,
            output  [11:0]                  DATA_C0,
            output                          CLK_P_C1,
            output                          CLK_N_C1,
            output  [11:0]                  DATA_C1,
            input                           CLK_P_C2,
            input                           CLK_N_C2,
            input   [11:0]                  DATA_C2,
            input                           CLK_P_C3,
            input                           CLK_N_C3,
            input   [11:0]                  DATA_C3,
            input                           CLK_P_L0,
            input                           CLK_N_L0,
            input   [11:0]                  DATA_L0,
            input                           CLK_P_L1,
            input                           CLK_N_L1,
            input   [11:0]                  DATA_L1,
            input                           CLK_P_L2,
            input                           CLK_N_L2,
            input   [11:0]                  DATA_L2,
            output                          CLK_P_L3,
            output                          CLK_N_L3,
            output  [11:0]                  DATA_L3,
        `elsif EX600_FPGA_3
            output                          CLK_P_R0,
            output                          CLK_N_R0,
            output  [11:0]                  DATA_R0,
            output                          CLK_P_R1,
            output                          CLK_N_R1,
            output  [11:0]                  DATA_R1,
            output                          CLK_P_R2,
            output                          CLK_N_R2,
            output  [11:0]                  DATA_R2,
            input                           CLK_P_R3,
            input                           CLK_N_R3,
            input   [11:0]                  DATA_R3,
            input                           CLK_P_C0,
            input                           CLK_N_C0,
            input   [11:0]                  DATA_C0,
            input                           CLK_P_C1,
            input                           CLK_N_C1,
            input   [11:0]                  DATA_C1,
            output                          CLK_P_C2,
            output                          CLK_N_C2,
            output  [11:0]                  DATA_C2,
            output                          CLK_P_C3,
            output                          CLK_N_C3,
            output  [11:0]                  DATA_C3,
            input                           CLK_P_L0,
            input                           CLK_N_L0,
            input   [11:0]                  DATA_L0,
            input                           CLK_P_L1,
            input                           CLK_N_L1,
            input   [11:0]                  DATA_L1,
            input                           CLK_P_L2,
            input                           CLK_N_L2,
            input   [11:0]                  DATA_L2,
            output                          CLK_P_L3,
            output                          CLK_N_L3,
            output  [11:0]                  DATA_L3,
        `elsif EX600_FPGA_4
            output                          CLK_P_C0,
            output                          CLK_N_C0,
            output  [11:0]                  DATA_C0,
            output                          CLK_P_C1,
            output                          CLK_N_C1,
            output  [11:0]                  DATA_C1,
            input                           CLK_P_C2,
            input                           CLK_N_C2,
            input   [11:0]                  DATA_C2,
            input                           CLK_P_C3,
            input                           CLK_N_C3,
            input   [11:0]                  DATA_C3,
            input                           CLK_P_L0,
            input                           CLK_N_L0,
            input   [11:0]                  DATA_L0,
            input                           CLK_P_L1,
            input                           CLK_N_L1,
            input   [11:0]                  DATA_L1,
            input                           CLK_P_L2,
            input                           CLK_N_L2,
            input   [11:0]                  DATA_L2,
            output                          CLK_P_L3,
            output                          CLK_N_L3,
            output  [11:0]                  DATA_L3,
        `elsif EX600_FPGA_5
            input                           CLK_P_C0,
            input                           CLK_N_C0,
            input   [11:0]                  DATA_C0,
            input                           CLK_P_C1,
            input                           CLK_N_C1,
            input   [11:0]                  DATA_C1,
            output                          CLK_P_C2,
            output                          CLK_N_C2,
            output  [11:0]                  DATA_C2,
            output                          CLK_P_C3,
            output                          CLK_N_C3,
            output  [11:0]                  DATA_C3,
            input                           CLK_P_L0,
            input                           CLK_N_L0,
            input   [11:0]                  DATA_L0,
            input                           CLK_P_L1,
            input                           CLK_N_L1,
            input   [11:0]                  DATA_L1,
            input                           CLK_P_L2,
            input                           CLK_N_L2,
            input   [11:0]                  DATA_L2,
            output                          CLK_P_L3,
            output                          CLK_N_L3,
            output  [11:0]                  DATA_L3,
        `else
            ERROR: FPGA number must be sepecified
        `endif
    `endif //EX600_INTERCONNECT            
`endif //PICO_MODEL_EX600

    input                               sys_clk_p,
    input                               sys_clk_n,
    input                               sys_reset_n
);
    
    wire                                s_clk;
    wire                                s_rst;

    wire [127:0]                        s_in_data;
    wire [8:0]                          s_in_id;
    wire                                s_in_valid;

    wire                                s_out_en;
    wire [8:0]                          s_out_id;
    wire [127:0]                        s_out_data;

    wire [8:0]                          s_poll_id;
    wire [31:0]                         s_poll_seq;
    wire                                s_poll_next_desc_valid;
    wire [127:0]                        s_poll_next_desc;

    wire                                s_next_desc_rd_en;
    wire [8:0]                          s_next_desc_rd_id;
    
    wire [9:0]                          temp;

`ifdef PICOBUS_WIDTH
    wire [7:0]                          UserPBWidth = `PICOBUS_WIDTH;
`else
    wire [7:0]                          UserPBWidth = 0;
`endif // PICOBUS_WIDTH

    // user-direct writes
    wire [127:0]                        user_pci_wr_q_data;
    wire                                user_pci_wr_q_valid, user_pci_wr_q_en;
    wire [127:0]                        user_pci_wr_data_q_data;
    wire                                user_pci_wr_data_q_valid, user_pci_wr_data_q_en;
    wire                                direct_rx_valid;

    wire                                extra_clk;

`ifdef PICO_QDRII
	`ifdef PICO_MODEL_M503  // QDRII is only on the M503 right now (not the M501 or M505)
    wire                                qdrii_sys_rst;

    // User Interface 0
    wire                                c0_user_wr_cmd0;
    wire                                c0_user_wr_cmd1;
    wire [19:0]                         c0_user_wr_addr0;
    wire [19:0]                         c0_user_wr_addr1;
    wire                                c0_user_rd_cmd0;
    wire                                c0_user_rd_cmd1;
    wire [19:0]                         c0_user_rd_addr0;
    wire [19:0]                         c0_user_rd_addr1;
    wire [71:0]                         c0_user_wr_data0;
    wire [35:0]                         c0_user_wr_data1;
    wire [7:0]                          c0_user_wr_bw_n0;
    wire [3:0]                          c0_user_wr_bw_n1;
    wire                                c0_clk_tb;
    wire                                c0_rst_clk_tb;
    wire                                c0_user_rd_valid0;
    wire                                c0_user_rd_valid1;
    wire [71:0]                         c0_user_rd_data0;
    wire [35:0]                         c0_user_rd_data1;
  
    // User interface 1
    wire                                c1_user_wr_cmd0;
    wire                                c1_user_wr_cmd1;
    wire [19:0]                         c1_user_wr_addr0;
    wire [19:0]                         c1_user_wr_addr1;
    wire                                c1_user_rd_cmd0;
    wire                                c1_user_rd_cmd1;
    wire [19:0]                         c1_user_rd_addr0;
    wire [19:0]                         c1_user_rd_addr1;
    wire [71:0]                         c1_user_wr_data0;
    wire [35:0]                         c1_user_wr_data1;
    wire [7:0]                          c1_user_wr_bw_n0;
    wire [3:0]                          c1_user_wr_bw_n1;
    wire                                c1_clk_tb;
    wire                                c1_rst_clk_tb;
    wire                                c1_user_rd_valid0;
    wire                                c1_user_rd_valid1;
    wire [71:0]                         c1_user_rd_data0;
    wire [35:0]                         c1_user_rd_data1;
     
    // User interface 2
    wire                                c2_user_wr_cmd0;
    wire                                c2_user_wr_cmd1;
    wire [19:0]                         c2_user_wr_addr0;
    wire [19:0]                         c2_user_wr_addr1;
    wire                                c2_user_rd_cmd0;
    wire                                c2_user_rd_cmd1;
    wire [19:0]                         c2_user_rd_addr0;
    wire [19:0]                         c2_user_rd_addr1;
    wire [71:0]                         c2_user_wr_data0;
    wire [35:0]                         c2_user_wr_data1;
    wire [7:0]                          c2_user_wr_bw_n0;
    wire [3:0]                          c2_user_wr_bw_n1;
    wire                                c2_clk_tb;
    wire                                c2_rst_clk_tb;
    wire                                c2_user_rd_valid0;
    wire                                c2_user_rd_valid1;
    wire [71:0]                         c2_user_rd_data0;
    wire [35:0]                         c2_user_rd_data1;
     
        `ifndef SIMULATION
    wire                                c0_cal_done;
    wire                                c1_cal_done;
    wire                                c2_cal_done; 
        `endif // SIMULATION
    `elsif PICO_MODEL_EX600
        wire                                qdrii_sys_rst;

    // User Interface 0
    wire                                c0_user_wr_cmd0;
    wire                                c0_user_wr_cmd1;
    wire [20:0]                         c0_user_wr_addr0;
    wire [20:0]                         c0_user_wr_addr1;
    wire                                c0_user_rd_cmd0;
    wire                                c0_user_rd_cmd1;
    wire [20:0]                         c0_user_rd_addr0;
    wire [20:0]                         c0_user_rd_addr1;
    wire [143:0]                        c0_user_wr_data0;
    wire [71:0]                         c0_user_wr_data1;
    wire [15:0]                          c0_user_wr_bw_n0;
    wire [7:0]                          c0_user_wr_bw_n1;
    wire                                c0_clk_tb;
    wire                                c0_rst_clk_tb;
    wire                                c0_user_rd_valid0;
    wire                                c0_user_rd_valid1;
    wire [143:0]                        c0_user_rd_data0;
    wire [71:0]                         c0_user_rd_data1;
  
    // User interface 1
    wire                                c1_user_wr_cmd0;
    wire                                c1_user_wr_cmd1;
    wire [20:0]                         c1_user_wr_addr0;
    wire [20:0]                         c1_user_wr_addr1;
    wire                                c1_user_rd_cmd0;
    wire                                c1_user_rd_cmd1;
    wire [20:0]                         c1_user_rd_addr0;
    wire [20:0]                         c1_user_rd_addr1;
    wire [143:0]                        c1_user_wr_data0;
    wire [71:0]                         c1_user_wr_data1;
    wire [15:0]                         c1_user_wr_bw_n0;
    wire [7:0]                          c1_user_wr_bw_n1;
    wire                                c1_clk_tb;
    wire                                c1_rst_clk_tb;
    wire                                c1_user_rd_valid0;
    wire                                c1_user_rd_valid1;
    wire [143:0]                        c1_user_rd_data0;
    wire [71:0]                         c1_user_rd_data1;
     
        `ifndef SIMULATION
    wire                                c0_cal_done;
    wire                                c1_cal_done;
        `endif //SIMULATION
    `endif // PICO_MODEL_EX600
`endif // PICO_QDRII

`ifdef PICO_DDR3
	`ifdef PICO_MODEL_M503
    wire    [1:0]                       ddr3_sys_rst;
	`else // PICO_MODEL_M501 & PICO_MODEL_M505
    wire                                ddr3_sys_rst;
	`endif // PICO_MODEL_M503
    
    // Master Interface to MIG 0
    wire                                c0_rst;
    wire                                c0_clk;
    // Master Interface Write Address Ports
    wire    [C0_C_S_AXI_ID_WIDTH-1:0]   c0_s_axi_awid;
    wire    [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s_axi_awaddr; 
    wire    [7:0]                       c0_s_axi_awlen;
    wire    [2:0]                       c0_s_axi_awsize; 
    wire    [1:0]                       c0_s_axi_awburst; 
    wire    [0:0]                       c0_s_axi_awlock;
    wire    [3:0]                       c0_s_axi_awcache; 
    wire    [2:0]                       c0_s_axi_awprot; 
    wire    [3:0]                       c0_s_axi_awqos; 
    wire                                c0_s_axi_awvalid; 
    wire                                c0_s_axi_awready; 
    // Master Interface Write Data Ports
    wire    [C0_C_S_AXI_DATA_WIDTH-1:0] c0_s_axi_wdata;
    wire    [C0_C_S_AXI_DATA_WIDTH/8-1:0] c0_s_axi_wstrb; 
    wire                                c0_s_axi_wlast; 
    wire                                c0_s_axi_wvalid; 
    wire                                c0_s_axi_wready; 
    // Master Interface Write Response Ports
    wire    [C0_C_S_AXI_ID_WIDTH-1:0]   c0_s_axi_bid;
    wire    [1:0]                       c0_s_axi_bresp; 
    wire                                c0_s_axi_bvalid; 
    wire                                c0_s_axi_bready; 
    // Master Interface Read Address Ports
    wire    [C0_C_S_AXI_ID_WIDTH-1:0]   c0_s_axi_arid; 
    wire    [C0_C_S_AXI_ADDR_WIDTH-1:0] c0_s_axi_araddr; 
    wire    [7:0]                       c0_s_axi_arlen;
    wire    [2:0]                       c0_s_axi_arsize; 
    wire    [1:0]                       c0_s_axi_arburst; 
    wire    [0:0]                       c0_s_axi_arlock;
    wire    [3:0]                       c0_s_axi_arcache; 
    wire    [2:0]                       c0_s_axi_arprot;
    wire    [3:0]                       c0_s_axi_arqos;
    wire                                c0_s_axi_arvalid; 
    wire                                c0_s_axi_arready; 
    // Master Interface Read Data Ports
    wire    [C0_C_S_AXI_ID_WIDTH-1:0]   c0_s_axi_rid;
    wire    [C0_C_S_AXI_DATA_WIDTH-1:0] c0_s_axi_rdata; 
    wire    [1:0]                       c0_s_axi_rresp; 
    wire                                c0_s_axi_rlast; 
    wire                                c0_s_axi_rvalid; 
    wire                                c0_s_axi_rready; 
	`ifndef SIMULATION  
    wire                                c0_phy_init_done;
	`endif // SIMULATION

	`ifdef PICO_MODEL_M503
    // Master Interface to MIG 1
    wire                                c1_rst;
    wire                                c1_clk;
    // Master Interface Write Address Ports
    wire  [C1_C_S_AXI_ID_WIDTH-1:0]     c1_s_axi_awid; 
    wire  [C1_C_S_AXI_ADDR_WIDTH-1:0]   c1_s_axi_awaddr; 
    wire  [7:0]                         c1_s_axi_awlen; 
    wire  [2:0]                         c1_s_axi_awsize; 
    wire  [1:0]                         c1_s_axi_awburst; 
    wire  [0:0]                         c1_s_axi_awlock; 
    wire  [3:0]                         c1_s_axi_awcache; 
    wire  [2:0]                         c1_s_axi_awprot; 
    wire  [3:0]                         c1_s_axi_awqos; 
    wire                                c1_s_axi_awvalid; 
    wire                                c1_s_axi_awready; 
    // Master Interface Write Data Ports
    wire  [C1_C_S_AXI_DATA_WIDTH-1:0]   c1_s_axi_wdata; 
    wire  [C1_C_S_AXI_DATA_WIDTH/8-1:0] c1_s_axi_wstrb; 
    wire                                c1_s_axi_wlast; 
    wire                                c1_s_axi_wvalid; 
    wire                                c1_s_axi_wready; 
    // Master Interface Write Response Ports
    wire  [C1_C_S_AXI_ID_WIDTH-1:0]     c1_s_axi_bid;
    wire  [1:0]                         c1_s_axi_bresp; 
    wire                                c1_s_axi_bvalid; 
    wire                                c1_s_axi_bready; 
    // Master Interface Read Address Ports
    wire  [C1_C_S_AXI_ID_WIDTH-1:0]     c1_s_axi_arid;
    wire  [C1_C_S_AXI_ADDR_WIDTH-1:0]   c1_s_axi_araddr; 
    wire  [7:0]                         c1_s_axi_arlen; 
    wire  [2:0]                         c1_s_axi_arsize; 
    wire  [1:0]                         c1_s_axi_arburst; 
    wire  [0:0]                         c1_s_axi_arlock; 
    wire  [3:0]                         c1_s_axi_arcache; 
    wire  [2:0]                         c1_s_axi_arprot; 
    wire  [3:0]                         c1_s_axi_arqos; 
    wire                                c1_s_axi_arvalid; 
    wire                                c1_s_axi_arready; 
    // Master Interface Read Data Ports
    wire  [C1_C_S_AXI_ID_WIDTH-1:0]     c1_s_axi_rid; 
    wire  [C1_C_S_AXI_DATA_WIDTH-1:0]   c1_s_axi_rdata; 
    wire  [1:0]                         c1_s_axi_rresp; 
    wire                                c1_s_axi_rlast; 
    wire                                c1_s_axi_rvalid; 
    wire                                c1_s_axi_rready;
		`ifndef SIMULATION  
    wire                                c1_phy_init_done;
		`endif // SIMULATION
	`endif // PICO_MODEL_M503
`endif // PICO_DDR3


`ifdef PICO_MODEL_M501	// M501
	`ifdef PICO_FPGA_LX240T
    PicoFrameworkM501_LX240T2
	`else
    PicoFrameworkM501_LX195T1
	`endif // PICO_FPGA_LX240T
	
    PicoFramework (

        .flash_busy                     ( flash_busy ),
        .flash_byte                     ( flash_byte ),
        .flash_ce                       ( flash_ce ),
        .flash_oe                       ( flash_oe ),
        .flash_reset                    ( flash_reset ),
        .flash_we                       ( flash_we ),
        .flash_a                        ( flash_a ),
        .flash_d                        ( flash_d ),

`elsif PICO_MODEL_M503	// M503
	`ifdef PICO_FPGA_LX240T
    PicoFrameworkM503_LX240T2
	`elsif PICO_FPGA_SX315T
    PicoFrameworkM503_SX315T2
	`elsif PICO_FPGA_LX550T
    PicoFrameworkM503_LX550T2
	`elsif PICO_FPGA_LX550T_1
    PicoFrameworkM503_LX550T1
	`endif // PICO_FPGA_LX240T
    
    PicoFramework (
    
`elsif PICO_MODEL_EX600	// EX600
	`ifdef PICO_FPGA_SX315T
    PicoFrameworkEX600_SX315T2
	`endif // PICO_FPGA_SX315T
    
    PicoFramework (

`elsif PICO_MODEL_M505 // PICO_MODEL_M505
    `ifdef PICO_FPGA_LX325T
    PicoFrameworkM505_LX325T1
    `endif
    
    PicoFramework (

        .flash_busy                     ( flash_busy ),
        .flash_byte                     ( flash_byte ),
        .flash_ce                       ( flash_ce ),
        .flash_oe                       ( flash_oe ),
        .flash_reset                    ( flash_reset ),
        .flash_we                       ( flash_we ),
        .flash_a                        ( flash_a ),
        .flash_d                        ( flash_d ),

`else
    UNKNOWN_PICO_MODEL_DEFINE!!
`endif
        
        // stream signals we're taking to the toplevel for the user
        .s_clk                          ( s_clk ),
        .s_rst                          ( s_rst ),

        .s_out_en                       ( s_out_en ),
        .s_out_id                       ( s_out_id ),
        .s_out_data                     ( s_out_data ),

        .s_in_valid                     ( s_in_valid ),
        .s_in_id                        ( s_in_id[8:0] ),
        .s_in_data                      ( s_in_data[127:0] ),

        .s_poll_id                      ( s_poll_id[8:0] ),
        .s_poll_seq                     ( s_poll_seq[31:0] ),
        .s_poll_next_desc               ( s_poll_next_desc[127:0] ),
        .s_poll_next_desc_valid         ( s_poll_next_desc_valid ),

        .s_next_desc_rd_en              ( s_next_desc_rd_en ),
        .s_next_desc_rd_id              ( s_next_desc_rd_id[8:0] ),

        .UserPBWidth                    ( UserPBWidth ),
  
        // user-direct writes
        .user_pci_wr_q_data             ( user_pci_wr_q_data ),
        .user_pci_wr_q_valid            ( user_pci_wr_q_valid ),
        .user_pci_wr_q_en               ( user_pci_wr_q_en ),

        .user_pci_wr_data_q_data        ( user_pci_wr_data_q_data ),
        .user_pci_wr_data_q_valid       ( user_pci_wr_data_q_valid ),
        .user_pci_wr_data_q_en          ( user_pci_wr_data_q_en ),
        .direct_rx_valid                ( direct_rx_valid ),
        
`ifdef SIMULATION
        // Common
        .user_clk                       ( user_clk ),
        .user_reset                     ( user_reset ),
        .user_lnk_up                    ( user_lnk_up ),

        // Tx
        .tx_buf_av                      ( tx_buf_av ),
        //.tx_cfg_req                     ( tx_cfg_req ),
        .tx_err_drop                    ( tx_err_drop ),
        .s_axis_tx_tready               ( s_axis_tx_tready ),
        .s_axis_tx_tdata                ( s_axis_tx_tdata ),
        .s_axis_tx_tstrb                ( s_axis_tx_tstrb ),
        .s_axis_tx_tuser                ( s_axis_tx_tuser ),
        .s_axis_tx_tlast                ( s_axis_tx_tlast ),
        .s_axis_tx_tvalid               ( s_axis_tx_tvalid ),
        //.tx_cfg_gnt                     ( tx_cfg_gnt ),

        // Rx
        .m_axis_rx_tdata                ( m_axis_rx_tdata ),
        .m_axis_rx_tstrb                ( m_axis_rx_tstrb ),
        .m_axis_rx_tlast                ( m_axis_rx_tlast ),
        .m_axis_rx_tvalid               ( m_axis_rx_tvalid ),
        .m_axis_rx_tready               ( m_axis_rx_tready ),
        .m_axis_rx_tuser                ( m_axis_rx_tuser ),
        .rx_np_ok                       ( rx_np_ok ),

        // Flow Control
        .fc_cpld                        ( fc_cpld ),
        .fc_cplh                        ( fc_cplh ),
        .fc_npd                         ( fc_npd ),
        .fc_nph                         ( fc_nph ),
        .fc_pd                          ( fc_pd ),
        .fc_ph                          ( fc_ph ),
        .fc_sel                         ( fc_sel ),
`else
        .pci_exp_txp                    ( pci_exp_txp ),
        .pci_exp_txn                    ( pci_exp_txn ),
        .pci_exp_rxp                    ( pci_exp_rxp ),
        .pci_exp_rxn                    ( pci_exp_rxn ),
`endif // SIMULATION

        .temp                           ( temp ),

        .extra_clk_p                    ( extra_clk_p ),
        .extra_clk_n                    ( extra_clk_n ),
        .extra_clk                      ( extra_clk ),

        .sys_clk_p                      ( sys_clk_p ),
        .sys_clk_n                      ( sys_clk_n ),
        .sys_reset_n                    ( sys_reset_n )
    );
    
    
    
    UserWrapper
`ifdef PICO_DDR3
    #(

	`ifdef PICO_MODEL_M503
		`ifdef PICO_AXI_MASTERS
        .C1_C_S_AXI_MASTERS             ( `PICO_AXI_MASTERS),
		`endif // PICO_AXI_MASTERS
        .C1_C_S_AXI_ID_WIDTH            ( C1_C_S_AXI_ID_WIDTH ), 
        .C1_C_S_AXI_ADDR_WIDTH          ( C1_C_S_AXI_ADDR_WIDTH ), 
        .C1_C_S_AXI_DATA_WIDTH          ( C1_C_S_AXI_DATA_WIDTH ),
	`endif // PICO_MODEL_M503

	`ifdef PICO_AXI_MASTERS
        .C0_C_S_AXI_MASTERS             ( `PICO_AXI_MASTERS ),
	`endif // PICO_AXI_MASTERS
        .C0_C_S_AXI_ID_WIDTH            ( C0_C_S_AXI_ID_WIDTH ), 
        .C0_C_S_AXI_ADDR_WIDTH          ( C0_C_S_AXI_ADDR_WIDTH ), 
        .C0_C_S_AXI_DATA_WIDTH          ( C0_C_S_AXI_DATA_WIDTH )
    )
`endif
    UserWrapper 
    (

`ifdef PICO_QDRII
	`ifdef PICO_MODEL_M503  // QDRII is only on the M503 right now (not the M501 or M505)

        .qdrii_sys_rst                  ( qdrii_sys_rst     ), 
      
         // QDRII 0
        .c0_user_wr_cmd0                ( c0_user_wr_cmd0   ),
        .c0_user_wr_cmd1                ( c0_user_wr_cmd1   ),
        .c0_user_wr_addr0               ( c0_user_wr_addr0  ),
        .c0_user_wr_addr1               ( c0_user_wr_addr1  ),
        .c0_user_rd_cmd0                ( c0_user_rd_cmd0   ),
        .c0_user_rd_cmd1                ( c0_user_rd_cmd1   ),
        .c0_user_rd_addr0               ( c0_user_rd_addr0  ),
        .c0_user_rd_addr1               ( c0_user_rd_addr1  ),
        .c0_user_wr_data0               ( c0_user_wr_data0  ),
        .c0_user_wr_data1               ( c0_user_wr_data1  ),
        .c0_user_wr_bw_n0               ( c0_user_wr_bw_n0  ),
        .c0_user_wr_bw_n1               ( c0_user_wr_bw_n1  ),
        .c0_clk_tb                      ( c0_clk_tb         ),
        .c0_rst_clk_tb                  ( c0_rst_clk_tb     ),
        .c0_user_rd_valid0              ( c0_user_rd_valid0 ),
        .c0_user_rd_valid1              ( c0_user_rd_valid1 ),
        .c0_user_rd_data0               ( c0_user_rd_data0  ),
        .c0_user_rd_data1               ( c0_user_rd_data1  ),
        .c0_cal_done                    ( c0_cal_done       ),

         // QDRII 1
        .c1_user_wr_cmd0                ( c1_user_wr_cmd0   ),
        .c1_user_wr_cmd1                ( c1_user_wr_cmd1   ),
        .c1_user_wr_addr0               ( c1_user_wr_addr0  ),
        .c1_user_wr_addr1               ( c1_user_wr_addr1  ),
        .c1_user_rd_cmd0                ( c1_user_rd_cmd0   ),
        .c1_user_rd_cmd1                ( c1_user_rd_cmd1   ),
        .c1_user_rd_addr0               ( c1_user_rd_addr0  ),
        .c1_user_rd_addr1               ( c1_user_rd_addr1  ),
        .c1_user_wr_data0               ( c1_user_wr_data0  ),
        .c1_user_wr_data1               ( c1_user_wr_data1  ),
        .c1_user_wr_bw_n0               ( c1_user_wr_bw_n0  ),
        .c1_user_wr_bw_n1               ( c1_user_wr_bw_n1  ),
        .c1_clk_tb                      ( c1_clk_tb         ),
        .c1_rst_clk_tb                  ( c1_rst_clk_tb     ),
        .c1_user_rd_valid0              ( c1_user_rd_valid0 ),
        .c1_user_rd_valid1              ( c1_user_rd_valid1 ),
        .c1_user_rd_data0               ( c1_user_rd_data0  ),
        .c1_user_rd_data1               ( c1_user_rd_data1  ),
        .c1_cal_done                    ( c1_cal_done       ),

         // QDRII 2
        .c2_user_wr_cmd0                ( c2_user_wr_cmd0   ),
        .c2_user_wr_cmd1                ( c2_user_wr_cmd1   ),
        .c2_user_wr_addr0               ( c2_user_wr_addr0  ),
        .c2_user_wr_addr1               ( c2_user_wr_addr1  ),
        .c2_user_rd_cmd0                ( c2_user_rd_cmd0   ),
        .c2_user_rd_cmd1                ( c2_user_rd_cmd1   ),
        .c2_user_rd_addr0               ( c2_user_rd_addr0  ),
        .c2_user_rd_addr1               ( c2_user_rd_addr1  ),
        .c2_user_wr_data0               ( c2_user_wr_data0  ),
        .c2_user_wr_data1               ( c2_user_wr_data1  ),
        .c2_user_wr_bw_n0               ( c2_user_wr_bw_n0  ),
        .c2_user_wr_bw_n1               ( c2_user_wr_bw_n1  ),
        .c2_clk_tb                      ( c2_clk_tb         ),
        .c2_rst_clk_tb                  ( c2_rst_clk_tb     ),
        .c2_user_rd_valid0              ( c2_user_rd_valid0 ),
        .c2_user_rd_valid1              ( c2_user_rd_valid1 ),
        .c2_user_rd_data0               ( c2_user_rd_data0  ),
        .c2_user_rd_data1               ( c2_user_rd_data1  ),
        .c2_cal_done                    ( c2_cal_done       ),
    // PICO_MODEL_M503
    `elsif PICO_MODEL_EX600
        .qdrii_sys_rst                  ( qdrii_sys_rst     ), 
      
         // QDRII 0
        .c0_user_wr_cmd0                ( c0_user_wr_cmd0   ),
        .c0_user_wr_cmd1                ( c0_user_wr_cmd1   ),
        .c0_user_wr_addr0               ( c0_user_wr_addr0  ),
        .c0_user_wr_addr1               ( c0_user_wr_addr1  ),
        .c0_user_rd_cmd0                ( c0_user_rd_cmd0   ),
        .c0_user_rd_cmd1                ( c0_user_rd_cmd1   ),
        .c0_user_rd_addr0               ( c0_user_rd_addr0  ),
        .c0_user_rd_addr1               ( c0_user_rd_addr1  ),
        .c0_user_wr_data0               ( c0_user_wr_data0  ),
        .c0_user_wr_data1               ( c0_user_wr_data1  ),
        .c0_user_wr_bw_n0               ( c0_user_wr_bw_n0  ),
        .c0_user_wr_bw_n1               ( c0_user_wr_bw_n1  ),
        .c0_clk_tb                      ( c0_clk_tb         ),
        .c0_rst_clk_tb                  ( c0_rst_clk_tb     ),
        .c0_user_rd_valid0              ( c0_user_rd_valid0 ),
        .c0_user_rd_valid1              ( c0_user_rd_valid1 ),
        .c0_user_rd_data0               ( c0_user_rd_data0  ),
        .c0_user_rd_data1               ( c0_user_rd_data1  ),
        .c0_cal_done                    ( c0_cal_done       ),

         // QDRII 1
        .c1_user_wr_cmd0                ( c1_user_wr_cmd0   ),
        .c1_user_wr_cmd1                ( c1_user_wr_cmd1   ),
        .c1_user_wr_addr0               ( c1_user_wr_addr0  ),
        .c1_user_wr_addr1               ( c1_user_wr_addr1  ),
        .c1_user_rd_cmd0                ( c1_user_rd_cmd0   ),
        .c1_user_rd_cmd1                ( c1_user_rd_cmd1   ),
        .c1_user_rd_addr0               ( c1_user_rd_addr0  ),
        .c1_user_rd_addr1               ( c1_user_rd_addr1  ),
        .c1_user_wr_data0               ( c1_user_wr_data0  ),
        .c1_user_wr_data1               ( c1_user_wr_data1  ),
        .c1_user_wr_bw_n0               ( c1_user_wr_bw_n0  ),
        .c1_user_wr_bw_n1               ( c1_user_wr_bw_n1  ),
        .c1_clk_tb                      ( c1_clk_tb         ),
        .c1_rst_clk_tb                  ( c1_rst_clk_tb     ),
        .c1_user_rd_valid0              ( c1_user_rd_valid0 ),
        .c1_user_rd_valid1              ( c1_user_rd_valid1 ),
        .c1_user_rd_data0               ( c1_user_rd_data0  ),
        .c1_user_rd_data1               ( c1_user_rd_data1  ),
        .c1_cal_done                    ( c1_cal_done       ),
    `endif // PICO_MODEL_EX600
`endif // PICO_QDRII

`ifdef PICO_DDR3 
        
        .ddr3_sys_rst                   ( ddr3_sys_rst ),// System reset
        
        // Slave Interface Write Address Ports
        .c0_s_axi_awid                  ( c0_s_axi_awid ), 
        .c0_s_axi_awaddr                ( c0_s_axi_awaddr ), 
        .c0_s_axi_awlen                 ( c0_s_axi_awlen ), 
        .c0_s_axi_awsize                ( c0_s_axi_awsize ), 
        .c0_s_axi_awburst               ( c0_s_axi_awburst ), 
        .c0_s_axi_awlock                ( c0_s_axi_awlock ), 
        .c0_s_axi_awcache               ( c0_s_axi_awcache ), 
        .c0_s_axi_awprot                ( c0_s_axi_awprot ), 
        .c0_s_axi_awqos                 ( c0_s_axi_awqos ), 
        .c0_s_axi_awvalid               ( c0_s_axi_awvalid ), 
        .c0_s_axi_awready               ( c0_s_axi_awready ), 
        // Slave Interface Write Data Ports
        .c0_s_axi_wdata                 ( c0_s_axi_wdata ), 
        .c0_s_axi_wstrb                 ( c0_s_axi_wstrb ), 
        .c0_s_axi_wlast                 ( c0_s_axi_wlast ), 
        .c0_s_axi_wvalid                ( c0_s_axi_wvalid ), 
        .c0_s_axi_wready                ( c0_s_axi_wready ), 
        // Slave Interface Write Response Ports
        .c0_s_axi_bid                   ( c0_s_axi_bid ), 
        .c0_s_axi_bresp                 ( c0_s_axi_bresp ), 
        .c0_s_axi_bvalid                ( c0_s_axi_bvalid ), 
        .c0_s_axi_bready                ( c0_s_axi_bready ), 
        // Slave Interface Read Address Ports
        .c0_s_axi_arid                  ( c0_s_axi_arid ), 
        .c0_s_axi_araddr                ( c0_s_axi_araddr ), 
        .c0_s_axi_arlen                 ( c0_s_axi_arlen ),
        .c0_s_axi_arsize                ( c0_s_axi_arsize ), 
        .c0_s_axi_arburst               ( c0_s_axi_arburst ), 
        .c0_s_axi_arlock                ( c0_s_axi_arlock ), 
        .c0_s_axi_arcache               ( c0_s_axi_arcache ), 
        .c0_s_axi_arprot                ( c0_s_axi_arprot ), 
        .c0_s_axi_arqos                 ( c0_s_axi_arqos ), 
        .c0_s_axi_arvalid               ( c0_s_axi_arvalid ), 
        .c0_s_axi_arready               ( c0_s_axi_arready ), 
        // Slave Interface Read Data Ports
        .c0_s_axi_rid                   ( c0_s_axi_rid ), 
        .c0_s_axi_rdata                 ( c0_s_axi_rdata ), 
        .c0_s_axi_rresp                 ( c0_s_axi_rresp ), 
        .c0_s_axi_rlast                 ( c0_s_axi_rlast ), 
        .c0_s_axi_rvalid                ( c0_s_axi_rvalid ), 
        .c0_s_axi_rready                ( c0_s_axi_rready ),
        // Common ports
        .c0_tb_rst                      ( c0_rst ),
        .c0_tb_clk                      ( c0_clk ),
        .c0_phy_init_done               ( c0_phy_init_done ),

		`ifdef PICO_MODEL_M503
        // Slave Interface Write Address Ports
        .c1_s_axi_awid                  ( c1_s_axi_awid ), 
        .c1_s_axi_awaddr                ( c1_s_axi_awaddr ), 
        .c1_s_axi_awlen                 ( c1_s_axi_awlen ), 
        .c1_s_axi_awsize                ( c1_s_axi_awsize ), 
        .c1_s_axi_awburst               ( c1_s_axi_awburst ), 
        .c1_s_axi_awlock                ( c1_s_axi_awlock ), 
        .c1_s_axi_awcache               ( c1_s_axi_awcache ), 
        .c1_s_axi_awprot                ( c1_s_axi_awprot ), 
        .c1_s_axi_awqos                 ( c1_s_axi_awqos ), 
        .c1_s_axi_awvalid               ( c1_s_axi_awvalid ), 
        .c1_s_axi_awready               ( c1_s_axi_awready ), 
        // Slave Interface Write Data Ports
        .c1_s_axi_wdata                 ( c1_s_axi_wdata ), 
        .c1_s_axi_wstrb                 ( c1_s_axi_wstrb ), 
        .c1_s_axi_wlast                 ( c1_s_axi_wlast ), 
        .c1_s_axi_wvalid                ( c1_s_axi_wvalid ), 
        .c1_s_axi_wready                ( c1_s_axi_wready ), 
        // Slave Interface Write Response Ports
        .c1_s_axi_bid                   ( c1_s_axi_bid ), 
        .c1_s_axi_bresp                 ( c1_s_axi_bresp ), 
        .c1_s_axi_bvalid                ( c1_s_axi_bvalid ), 
        .c1_s_axi_bready                ( c1_s_axi_bready ), 
        // Slave Interface Read Address Ports
        .c1_s_axi_arid                  ( c1_s_axi_arid ), 
        .c1_s_axi_araddr                ( c1_s_axi_araddr ), 
        .c1_s_axi_arlen                 ( c1_s_axi_arlen ),
        .c1_s_axi_arsize                ( c1_s_axi_arsize ), 
        .c1_s_axi_arburst               ( c1_s_axi_arburst ), 
        .c1_s_axi_arlock                ( c1_s_axi_arlock ), 
        .c1_s_axi_arcache               ( c1_s_axi_arcache ), 
        .c1_s_axi_arprot                ( c1_s_axi_arprot ), 
        .c1_s_axi_arqos                 ( c1_s_axi_arqos ), 
        .c1_s_axi_arvalid               ( c1_s_axi_arvalid ), 
        .c1_s_axi_arready               ( c1_s_axi_arready ), 
        // Slave Interface Read Data Ports
        .c1_s_axi_rid                   ( c1_s_axi_rid ), 
        .c1_s_axi_rdata                 ( c1_s_axi_rdata ), 
        .c1_s_axi_rresp                 ( c1_s_axi_rresp ), 
        .c1_s_axi_rlast                 ( c1_s_axi_rlast ), 
        .c1_s_axi_rvalid                ( c1_s_axi_rvalid ), 
        .c1_s_axi_rready                ( c1_s_axi_rready ),
        // Common ports
        .c1_tb_rst                      ( c1_rst ),
        .c1_tb_clk                      ( c1_clk ),
        .c1_phy_init_done               ( c1_phy_init_done ),
	`endif // PICO_MODEL_M503
`endif //PICO_DDR3

//------------------------------------------------------//
// EX-600 Interconnect Pins
//------------------------------------------------------//
`ifdef PICO_MODEL_EX600
    `ifdef EX600_INTERCONNECT
        `ifdef EX600_FPGA_0
            .CLK_P_R0                       (CLK_P_R0),
            .CLK_N_R0                       (CLK_N_R0),
            .DATA_R0                        (DATA_R0 ),
            .CLK_P_R1                       (CLK_P_R1),
            .CLK_N_R1                       (CLK_N_R1),
            .DATA_R1                        (DATA_R1 ),
            .CLK_P_R2                       (CLK_P_R2),
            .CLK_N_R2                       (CLK_N_R2),
            .DATA_R2                        (DATA_R2 ),
            .CLK_P_R3                       (CLK_P_R3),
            .CLK_N_R3                       (CLK_N_R3),
            .DATA_R3                        (DATA_R3 ),
            .CLK_P_C0                       (CLK_P_C0),
            .CLK_N_C0                       (CLK_N_C0),
            .DATA_C0                        (DATA_C0 ),
            .CLK_P_C1                       (CLK_P_C1),
            .CLK_N_C1                       (CLK_N_C1),
            .DATA_C1                        (DATA_C1 ),
            .CLK_P_C2                       (CLK_P_C2),
            .CLK_N_C2                       (CLK_N_C2),
            .DATA_C2                        (DATA_C2 ),
            .CLK_P_C3                       (CLK_P_C3),
            .CLK_N_C3                       (CLK_N_C3),
            .DATA_C3                        (DATA_C3 ),   
        `elsif EX600_FPGA_1
            .CLK_P_R0                       (CLK_P_R0),
            .CLK_N_R0                       (CLK_N_R0),
            .DATA_R0                        (DATA_R0 ),
            .CLK_P_R1                       (CLK_P_R1),
            .CLK_N_R1                       (CLK_N_R1),
            .DATA_R1                        (DATA_R1 ),
            .CLK_P_R2                       (CLK_P_R2),
            .CLK_N_R2                       (CLK_N_R2),
            .DATA_R2                        (DATA_R2 ),
            .CLK_P_R3                       (CLK_P_R3),
            .CLK_N_R3                       (CLK_N_R3),
            .DATA_R3                        (DATA_R3 ),
            .CLK_P_C0                       (CLK_P_C0),
            .CLK_N_C0                       (CLK_N_C0),
            .DATA_C0                        (DATA_C0 ),
            .CLK_P_C1                       (CLK_P_C1),
            .CLK_N_C1                       (CLK_N_C1),
            .DATA_C1                        (DATA_C1 ),
            .CLK_P_C2                       (CLK_P_C2),
            .CLK_N_C2                       (CLK_N_C2),
            .DATA_C2                        (DATA_C2 ),
            .CLK_P_C3                       (CLK_P_C3),
            .CLK_N_C3                       (CLK_N_C3),
            .DATA_C3                        (DATA_C3 ),  
        `elsif EX600_FPGA_2
            .CLK_P_R0                       (CLK_P_R0),
            .CLK_N_R0                       (CLK_N_R0),
            .DATA_R0                        (DATA_R0 ),
            .CLK_P_R1                       (CLK_P_R1),
            .CLK_N_R1                       (CLK_N_R1),
            .DATA_R1                        (DATA_R1 ),
            .CLK_P_R2                       (CLK_P_R2),
            .CLK_N_R2                       (CLK_N_R2),
            .DATA_R2                        (DATA_R2 ),
            .CLK_P_R3                       (CLK_P_R3),
            .CLK_N_R3                       (CLK_N_R3),
            .DATA_R3                        (DATA_R3 ),
            .CLK_P_C0                       (CLK_P_C0),
            .CLK_N_C0                       (CLK_N_C0),
            .DATA_C0                        (DATA_C0 ),
            .CLK_P_C1                       (CLK_P_C1),
            .CLK_N_C1                       (CLK_N_C1),
            .DATA_C1                        (DATA_C1 ),
            .CLK_P_C2                       (CLK_P_C2),
            .CLK_N_C2                       (CLK_N_C2),
            .DATA_C2                        (DATA_C2 ),
            .CLK_P_C3                       (CLK_P_C3),
            .CLK_N_C3                       (CLK_N_C3),
            .DATA_C3                        (DATA_C3 ), 
            .CLK_P_L0                       (CLK_P_L0),
            .CLK_N_L0                       (CLK_N_L0),
            .DATA_L0                        (DATA_L0 ),
            .CLK_P_L1                       (CLK_P_L1),
            .CLK_N_L1                       (CLK_N_L1),
            .DATA_L1                        (DATA_L1 ),
            .CLK_P_L2                       (CLK_P_L2),
            .CLK_N_L2                       (CLK_N_L2),
            .DATA_L2                        (DATA_L2 ),
            .CLK_P_L3                       (CLK_P_L3),
            .CLK_N_L3                       (CLK_N_L3),
            .DATA_L3                        (DATA_L3 ),
        `elsif EX600_FPGA_3
            .CLK_P_R0                       (CLK_P_R0),
            .CLK_N_R0                       (CLK_N_R0),
            .DATA_R0                        (DATA_R0 ),
            .CLK_P_R1                       (CLK_P_R1),
            .CLK_N_R1                       (CLK_N_R1),
            .DATA_R1                        (DATA_R1 ),
            .CLK_P_R2                       (CLK_P_R2),
            .CLK_N_R2                       (CLK_N_R2),
            .DATA_R2                        (DATA_R2 ),
            .CLK_P_R3                       (CLK_P_R3),
            .CLK_N_R3                       (CLK_N_R3),
            .DATA_R3                        (DATA_R3 ),
            .CLK_P_C0                       (CLK_P_C0),
            .CLK_N_C0                       (CLK_N_C0),
            .DATA_C0                        (DATA_C0 ),
            .CLK_P_C1                       (CLK_P_C1),
            .CLK_N_C1                       (CLK_N_C1),
            .DATA_C1                        (DATA_C1 ),
            .CLK_P_C2                       (CLK_P_C2),
            .CLK_N_C2                       (CLK_N_C2),
            .DATA_C2                        (DATA_C2 ),
            .CLK_P_C3                       (CLK_P_C3),
            .CLK_N_C3                       (CLK_N_C3),
            .DATA_C3                        (DATA_C3 ), 
            .CLK_P_L0                       (CLK_P_L0),
            .CLK_N_L0                       (CLK_N_L0),
            .DATA_L0                        (DATA_L0 ),
            .CLK_P_L1                       (CLK_P_L1),
            .CLK_N_L1                       (CLK_N_L1),
            .DATA_L1                        (DATA_L1 ),
            .CLK_P_L2                       (CLK_P_L2),
            .CLK_N_L2                       (CLK_N_L2),
            .DATA_L2                        (DATA_L2 ),
            .CLK_P_L3                       (CLK_P_L3),
            .CLK_N_L3                       (CLK_N_L3),
            .DATA_L3                        (DATA_L3 ),
        `elsif EX600_FPGA_4
            .CLK_P_C0                       (CLK_P_C0),
            .CLK_N_C0                       (CLK_N_C0),
            .DATA_C0                        (DATA_C0 ),
            .CLK_P_C1                       (CLK_P_C1),
            .CLK_N_C1                       (CLK_N_C1),
            .DATA_C1                        (DATA_C1 ),
            .CLK_P_C2                       (CLK_P_C2),
            .CLK_N_C2                       (CLK_N_C2),
            .DATA_C2                        (DATA_C2 ),
            .CLK_P_C3                       (CLK_P_C3),
            .CLK_N_C3                       (CLK_N_C3),
            .DATA_C3                        (DATA_C3 ), 
            .CLK_P_L0                       (CLK_P_L0),
            .CLK_N_L0                       (CLK_N_L0),
            .DATA_L0                        (DATA_L0 ),
            .CLK_P_L1                       (CLK_P_L1),
            .CLK_N_L1                       (CLK_N_L1),
            .DATA_L1                        (DATA_L1 ),
            .CLK_P_L2                       (CLK_P_L2),
            .CLK_N_L2                       (CLK_N_L2),
            .DATA_L2                        (DATA_L2 ),
            .CLK_P_L3                       (CLK_P_L3),
            .CLK_N_L3                       (CLK_N_L3),
            .DATA_L3                        (DATA_L3 ),
        `elsif EX600_FPGA_5
            .CLK_P_C0                       (CLK_P_C0),
            .CLK_N_C0                       (CLK_N_C0),
            .DATA_C0                        (DATA_C0 ),
            .CLK_P_C1                       (CLK_P_C1),
            .CLK_N_C1                       (CLK_N_C1),
            .DATA_C1                        (DATA_C1 ),
            .CLK_P_C2                       (CLK_P_C2),
            .CLK_N_C2                       (CLK_N_C2),
            .DATA_C2                        (DATA_C2 ),
            .CLK_P_C3                       (CLK_P_C3),
            .CLK_N_C3                       (CLK_N_C3),
            .DATA_C3                        (DATA_C3 ), 
            .CLK_P_L0                       (CLK_P_L0),
            .CLK_N_L0                       (CLK_N_L0),
            .DATA_L0                        (DATA_L0 ),
            .CLK_P_L1                       (CLK_P_L1),
            .CLK_N_L1                       (CLK_N_L1),
            .DATA_L1                        (DATA_L1 ),
            .CLK_P_L2                       (CLK_P_L2),
            .CLK_N_L2                       (CLK_N_L2),
            .DATA_L2                        (DATA_L2 ),
            .CLK_P_L3                       (CLK_P_L3),
            .CLK_N_L3                       (CLK_N_L3),
            .DATA_L3                        (DATA_L3 ),
        `else
            ERROR: FPGA number must be sepecified
        `endif
    `endif //EX600_INTERCONNECT            
`endif //PICO_MODEL_EX600


        .extra_clk                      ( extra_clk ),
        .clk                            ( s_clk ),
        .rst                            ( s_rst ),
        
        .s_out_en                       ( s_out_en ),
        .s_out_id                       ( s_out_id ),
        .s_out_data                     ( s_out_data ),
        
        .s_in_valid                     ( s_in_valid ),
        .s_in_id                        ( s_in_id[8:0] ),
        .s_in_data                      ( s_in_data[127:0] ),
        
        .s_poll_id                      ( s_poll_id[8:0] ),
        .s_poll_seq                     ( s_poll_seq[31:0] ),
        .s_poll_next_desc               ( s_poll_next_desc[127:0] ),
        .s_poll_next_desc_valid         ( s_poll_next_desc_valid ),
        
        .s_next_desc_rd_en              ( s_next_desc_rd_en ),
        .s_next_desc_rd_id              ( s_next_desc_rd_id[8:0] ),
        
        // user-direct writes
        .direct_rx_valid                ( direct_rx_valid ),
        .user_pci_wr_q_data             ( user_pci_wr_q_data ),
        .user_pci_wr_q_valid            ( user_pci_wr_q_valid ),
        .user_pci_wr_q_en               ( user_pci_wr_q_en ),
        
        .user_pci_wr_data_q_data        ( user_pci_wr_data_q_data ),
        .user_pci_wr_data_q_valid       ( user_pci_wr_data_q_valid ),
        .user_pci_wr_data_q_en          ( user_pci_wr_data_q_en )
    );


	//------------------------------------------------------
	// QDRII M503 MIG instantiation
	//   - instantiates all three QDRII cores
	//------------------------------------------------------
`ifdef PICO_QDRII
	`ifdef PICO_MODEL_M503  // QDRII is only on the M503 right now (not the M501 or M505)
   
	mig_v3_61_qdrii_400Mhz mig_v3_61_qdrii_400Mhz(
         
        // reset and clocking
        .sys_clk_f0                     ( extra_clk           ),
        .clk200_ref                     ( extra_clk           ),
        .sys_rst                        ( qdrii_sys_rst       ),

        // QDRII 0
        .c0_qdriip_cq_p                 ( c0_qdriip_cq_p      ),
        .c0_qdriip_cq_n                 ( c0_qdriip_cq_n      ),
        .c0_qdriip_qvld                 ( c0_qdriip_qvld      ),
        .c0_qdriip_q                    ( c0_qdriip_q         ),
        .c0_qdriip_k_p                  ( c0_qdriip_k_p       ),
        .c0_qdriip_k_n                  ( c0_qdriip_k_n       ),
        .c0_qdriip_d                    ( c0_qdriip_d         ),
        .c0_qdriip_sa                   ( c0_qdriip_sa        ),
        .c0_qdriip_w_n                  ( c0_qdriip_w_n       ),
        .c0_qdriip_r_n                  ( c0_qdriip_r_n       ),
        .c0_qdriip_bw_n                 ( c0_qdriip_bw_n      ),
        
        .c0_user_wr_cmd0                ( c0_user_wr_cmd0     ),
        .c0_user_wr_cmd1                ( c0_user_wr_cmd1     ),
        .c0_user_wr_addr0               ( c0_user_wr_addr0    ),
        .c0_user_wr_addr1               ( c0_user_wr_addr1    ),
        .c0_user_rd_cmd0                ( c0_user_rd_cmd0     ),
        .c0_user_rd_cmd1                ( c0_user_rd_cmd1     ),
        .c0_user_rd_addr0               ( c0_user_rd_addr0    ),
        .c0_user_rd_addr1               ( c0_user_rd_addr1    ),
        .c0_user_wr_data0               ( c0_user_wr_data0    ),
        .c0_user_wr_data1               ( c0_user_wr_data1    ),
        .c0_user_wr_bw_n0               ( c0_user_wr_bw_n0    ),
        .c0_user_wr_bw_n1               ( c0_user_wr_bw_n1    ),
        .c0_clk_tb                      ( c0_clk_tb           ),
        .c0_rst_clk_tb                  ( c0_rst_clk_tb       ),
        .c0_user_rd_valid0              ( c0_user_rd_valid0   ),
        .c0_user_rd_valid1              ( c0_user_rd_valid1   ),
        .c0_user_rd_data0               ( c0_user_rd_data0    ),
        .c0_user_rd_data1               ( c0_user_rd_data1    ),
        .c0_qdriip_dll_off_n            ( c0_qdriip_dll_off_n ),
        .c0_cal_done                    ( c0_cal_done         ),

        // QDRII 1
        .c1_qdriip_cq_p                 ( c1_qdriip_cq_p      ),
        .c1_qdriip_cq_n                 ( c1_qdriip_cq_n      ),
        .c1_qdriip_qvld                 ( c1_qdriip_qvld      ),
        .c1_qdriip_q                    ( c1_qdriip_q         ),
        .c1_qdriip_k_p                  ( c1_qdriip_k_p       ),
        .c1_qdriip_k_n                  ( c1_qdriip_k_n       ),
        .c1_qdriip_d                    ( c1_qdriip_d         ),
        .c1_qdriip_sa                   ( c1_qdriip_sa        ),
        .c1_qdriip_w_n                  ( c1_qdriip_w_n       ),
        .c1_qdriip_r_n                  ( c1_qdriip_r_n       ),
        .c1_qdriip_bw_n                 ( c1_qdriip_bw_n      ),
        
        .c1_user_wr_cmd0                ( c1_user_wr_cmd0     ),
        .c1_user_wr_cmd1                ( c1_user_wr_cmd1     ),
        .c1_user_wr_addr0               ( c1_user_wr_addr0    ),
        .c1_user_wr_addr1               ( c1_user_wr_addr1    ),
        .c1_user_rd_cmd0                ( c1_user_rd_cmd0     ),
        .c1_user_rd_cmd1                ( c1_user_rd_cmd1     ),
        .c1_user_rd_addr0               ( c1_user_rd_addr0    ),
        .c1_user_rd_addr1               ( c1_user_rd_addr1    ),
        .c1_user_wr_data0               ( c1_user_wr_data0    ),
        .c1_user_wr_data1               ( c1_user_wr_data1    ),
        .c1_user_wr_bw_n0               ( c1_user_wr_bw_n0    ),
        .c1_user_wr_bw_n1               ( c1_user_wr_bw_n1    ),
        .c1_clk_tb                      ( c1_clk_tb           ),
        .c1_rst_clk_tb                  ( c1_rst_clk_tb       ),
        .c1_user_rd_valid0              ( c1_user_rd_valid0   ),
        .c1_user_rd_valid1              ( c1_user_rd_valid1   ),
        .c1_user_rd_data0               ( c1_user_rd_data0    ),
        .c1_user_rd_data1               ( c1_user_rd_data1    ),
        .c1_qdriip_dll_off_n            ( c1_qdriip_dll_off_n ),
        .c1_cal_done                    ( c1_cal_done         ),

        // QDRII 2
        .c2_qdriip_cq_p                 ( c2_qdriip_cq_p      ),
        .c2_qdriip_cq_n                 ( c2_qdriip_cq_n      ),
        .c2_qdriip_qvld                 ( c2_qdriip_qvld      ),
        .c2_qdriip_q                    ( c2_qdriip_q         ),
        .c2_qdriip_k_p                  ( c2_qdriip_k_p       ),
        .c2_qdriip_k_n                  ( c2_qdriip_k_n       ),
        .c2_qdriip_d                    ( c2_qdriip_d         ),
        .c2_qdriip_sa                   ( c2_qdriip_sa        ),
        .c2_qdriip_w_n                  ( c2_qdriip_w_n       ),
        .c2_qdriip_r_n                  ( c2_qdriip_r_n       ),
        .c2_qdriip_bw_n                 ( c2_qdriip_bw_n      ),

        .c2_user_wr_cmd0                ( c2_user_wr_cmd0     ),
        .c2_user_wr_cmd1                ( c2_user_wr_cmd1     ),
        .c2_user_wr_addr0               ( c2_user_wr_addr0    ),
        .c2_user_wr_addr1               ( c2_user_wr_addr1    ),
        .c2_user_rd_cmd0                ( c2_user_rd_cmd0     ),
        .c2_user_rd_cmd1                ( c2_user_rd_cmd1     ),
        .c2_user_rd_addr0               ( c2_user_rd_addr0    ),
        .c2_user_rd_addr1               ( c2_user_rd_addr1    ),
        .c2_user_wr_data0               ( c2_user_wr_data0    ),
        .c2_user_wr_data1               ( c2_user_wr_data1    ),
        .c2_user_wr_bw_n0               ( c2_user_wr_bw_n0    ),
        .c2_user_wr_bw_n1               ( c2_user_wr_bw_n1    ),
        .c2_clk_tb                      ( c2_clk_tb           ),
        .c2_rst_clk_tb                  ( c2_rst_clk_tb       ),
        .c2_user_rd_valid0              ( c2_user_rd_valid0   ),
        .c2_user_rd_valid1              ( c2_user_rd_valid1   ),
        .c2_user_rd_data0               ( c2_user_rd_data0    ),
        .c2_user_rd_data1               ( c2_user_rd_data1    ),
        .c2_qdriip_dll_off_n            ( c2_qdriip_dll_off_n ),
        .c2_cal_done                    ( c2_cal_done         )
	); // PICO_MODEL_M503
	
   `elsif  PICO_MODEL_EX600
   	mig_v3_61_qdrii_400Mhz mig_v3_61_qdrii_400Mhz(
         
        // reset and clocking
        .sys_clk_f0                     ( extra_clk           ),
        .clk200_ref                     ( extra_clk           ),
        .sys_rst                        ( qdrii_sys_rst       ),

        // QDRII 0
        .c0_qdriip_cq_p                 ( c0_qdriip_cq_p      ),
        .c0_qdriip_cq_n                 ( c0_qdriip_cq_n      ),
        .c0_qdriip_qvld                 ( c0_qdriip_qvld      ),
        .c0_qdriip_q                    ( c0_qdriip_q         ),
        .c0_qdriip_k_p                  ( c0_qdriip_k_p       ),
        .c0_qdriip_k_n                  ( c0_qdriip_k_n       ),
        .c0_qdriip_d                    ( c0_qdriip_d         ),
        .c0_qdriip_sa                   ( c0_qdriip_sa        ),
        .c0_qdriip_w_n                  ( c0_qdriip_w_n       ),
        .c0_qdriip_r_n                  ( c0_qdriip_r_n       ),
        .c0_qdriip_bw_n                 ( c0_qdriip_bw_n      ),
        
        .c0_user_wr_cmd0                ( c0_user_wr_cmd0     ),
        .c0_user_wr_cmd1                ( c0_user_wr_cmd1     ),
        .c0_user_wr_addr0               ( c0_user_wr_addr0    ),
        .c0_user_wr_addr1               ( c0_user_wr_addr1    ),
        .c0_user_rd_cmd0                ( c0_user_rd_cmd0     ),
        .c0_user_rd_cmd1                ( c0_user_rd_cmd1     ),
        .c0_user_rd_addr0               ( c0_user_rd_addr0    ),
        .c0_user_rd_addr1               ( c0_user_rd_addr1    ),
        .c0_user_wr_data0               ( c0_user_wr_data0    ),
        .c0_user_wr_data1               ( c0_user_wr_data1    ),
        .c0_user_wr_bw_n0               ( c0_user_wr_bw_n0    ),
        .c0_user_wr_bw_n1               ( c0_user_wr_bw_n1    ),
        .c0_clk_tb                      ( c0_clk_tb           ),
        .c0_rst_clk_tb                  ( c0_rst_clk_tb       ),
        .c0_user_rd_valid0              ( c0_user_rd_valid0   ),
        .c0_user_rd_valid1              ( c0_user_rd_valid1   ),
        .c0_user_rd_data0               ( c0_user_rd_data0    ),
        .c0_user_rd_data1               ( c0_user_rd_data1    ),
        .c0_qdriip_dll_off_n            ( c0_qdriip_dll_off_n ),
        .c0_cal_done                    ( c0_cal_done         ),

        // QDRII 1
        .c1_qdriip_cq_p                 ( c1_qdriip_cq_p      ),
        .c1_qdriip_cq_n                 ( c1_qdriip_cq_n      ),
        .c1_qdriip_qvld                 ( c1_qdriip_qvld      ),
        .c1_qdriip_q                    ( c1_qdriip_q         ),
        .c1_qdriip_k_p                  ( c1_qdriip_k_p       ),
        .c1_qdriip_k_n                  ( c1_qdriip_k_n       ),
        .c1_qdriip_d                    ( c1_qdriip_d         ),
        .c1_qdriip_sa                   ( c1_qdriip_sa        ),
        .c1_qdriip_w_n                  ( c1_qdriip_w_n       ),
        .c1_qdriip_r_n                  ( c1_qdriip_r_n       ),
        .c1_qdriip_bw_n                 ( c1_qdriip_bw_n      ),
        
        .c1_user_wr_cmd0                ( c1_user_wr_cmd0     ),
        .c1_user_wr_cmd1                ( c1_user_wr_cmd1     ),
        .c1_user_wr_addr0               ( c1_user_wr_addr0    ),
        .c1_user_wr_addr1               ( c1_user_wr_addr1    ),
        .c1_user_rd_cmd0                ( c1_user_rd_cmd0     ),
        .c1_user_rd_cmd1                ( c1_user_rd_cmd1     ),
        .c1_user_rd_addr0               ( c1_user_rd_addr0    ),
        .c1_user_rd_addr1               ( c1_user_rd_addr1    ),
        .c1_user_wr_data0               ( c1_user_wr_data0    ),
        .c1_user_wr_data1               ( c1_user_wr_data1    ),
        .c1_user_wr_bw_n0               ( c1_user_wr_bw_n0    ),
        .c1_user_wr_bw_n1               ( c1_user_wr_bw_n1    ),
        .c1_clk_tb                      ( c1_clk_tb           ),
        .c1_rst_clk_tb                  ( c1_rst_clk_tb       ),
        .c1_user_rd_valid0              ( c1_user_rd_valid0   ),
        .c1_user_rd_valid1              ( c1_user_rd_valid1   ),
        .c1_user_rd_data0               ( c1_user_rd_data0    ),
        .c1_user_rd_data1               ( c1_user_rd_data1    ),
        .c1_qdriip_dll_off_n            ( c1_qdriip_dll_off_n ),
        .c1_cal_done                    ( c1_cal_done         )
	); 
	`endif // PICO_MODEL_EX600
`endif // PICO_QDRII

    //------------------------------------------------------
    // DDR3 MIG
    //------------------------------------------------------
`ifdef PICO_DDR3
    
    // axi reset
    reg c0_aresetn;
    always @ (posedge c0_clk ) c0_aresetn <= ~c0_rst;
	
    `ifdef PICO_MODEL_M503
    reg c1_aresetn;
    always @ (posedge c1_clk ) c1_aresetn <= ~c1_rst;
    `endif

    // Memory Interface Generator 0
    `ifdef PICO_SIM_MIG
    PicoMIG #(
        .RANKS                          ( RANKS                 ),
        .ROW_WIDTH                      ( ROW_WIDTH             ),
        .COL_WIDTH                      ( COL_WIDTH             ),
    `else 
	mig_DDR3 #(
	`endif // PICO_SIM_MIG
        
    `ifdef PICO_MODEL_M505
        .ODT_WIDTH                      ( ODT_WIDTH             ),
    `endif
        
        .RANKS                          ( RANKS                 ),
        .IODELAY_GRP                    ( "IODELAY_MIG_DDR3_0"  ),
        
        .nCS_PER_RANK                   (nCS_PER_RANK           ),
        .BANK_WIDTH                     ( BANK_WIDTH            ),
        
        .DQ_WIDTH                       ( DQ_WIDTH              ),
        .DQS_WIDTH                      ( DQS_WIDTH             ),
        .DM_WIDTH                       ( DM_WIDTH              ),
        
        .CK_WIDTH                       ( CK_WIDTH              ),
        .CKE_WIDTH                      ( CKE_WIDTH             ),
        .CS_WIDTH                       ( CS_WIDTH              ),
        
        .C_S_AXI_ID_WIDTH               ( C0_C_S_AXI_ID_WIDTH   ), 
        .C_S_AXI_ADDR_WIDTH             ( C0_C_S_AXI_ADDR_WIDTH ), 
        .C_S_AXI_DATA_WIDTH             ( C0_C_S_AXI_DATA_WIDTH ),
        
        .RST_ACT_LOW                    ( RST_ACT_LOW           )
    ) mig_DDR3_0 (
   
    // Signals Unique to an M-Series Module 
    `ifdef PICO_MODEL_M501
        .phy_init_done                  ( c0_phy_init_done ),
        .sys_clk                        ( extra_clk ),              
        .sys_rst                        ( ddr3_sys_rst ),
    `elsif PICO_MODEL_M503
        .phy_init_done                  ( c0_phy_init_done ),
        .sys_clk                        ( extra_clk ),              
        .sda                            ( c0_ddr3_sda ),
        .scl                            ( c0_ddr3_scl ),
        .sys_rst                        ( ddr3_sys_rst[0] ),
        .clk_ref                        ( extra_clk ),
    `elsif PICO_MODEL_M505
        .sys_rst                        ( ddr3_sys_rst ),
        .init_calib_complete            ( c0_phy_init_done ),
        
        // Application interface ports
        .app_sr_req                     ( 1'b0 ),                   // reserved input
        .app_sr_active                  ( app_sr_active ),          // output reserved
        .app_ref_req                    ( 1'b0 ),                   // active-high input to request
                                                                    //  refresh command be sent to
                                                                    //  DRAM
        .app_ref_ack                    ( app_ref_ack ),            // output reserved
        .app_zq_req                     ( 1'b0 ),                   // active-high input to request
                                                                    //  that a ZA calibration
                                                                    //  command be sent to DRAM
        .app_zq_ack                     ( app_zq_ack ),             // active-high output indicates
                                                                    //  the memory controller has
                                                                    //  sent the requested ZQ
                                                                    //  calibration command to the
                                                                    //  PHY interface
        // System Clock Ports
        .sys_clk_p                      ( clk_400_p ),
        .sys_clk_n                      ( clk_400_n ),

        // Reference clock for the iodelay_ctrl
        .extra_clk                      ( extra_clk ),

        // temperature from the System Monitor is used by the MIG to compensate
        // for temperature changes (requires 12 bits)
        .device_temp_i                  ( {temp, 2'b0} ),
    `endif // ifdef PICO_MODEL_M501
    
    // Signals Common to all M-Series Modules
        // DDR3 Physical Pins
        .ddr3_ck_p                      ( c0_ddr3_ck_p ),
        .ddr3_ck_n                      ( c0_ddr3_ck_n ),
        .ddr3_addr                      ( c0_ddr3_addr ),
        .ddr3_ba                        ( c0_ddr3_ba ),
        .ddr3_ras_n                     ( c0_ddr3_ras_n ),
        .ddr3_cas_n                     ( c0_ddr3_cas_n ),
        .ddr3_we_n                      ( c0_ddr3_we_n ),
        .ddr3_cs_n                      ( c0_ddr3_cs_n ),
        .ddr3_cke                       ( c0_ddr3_cke ),
        .ddr3_odt                       ( c0_ddr3_odt ),
        .ddr3_reset_n                   ( c0_ddr3_reset_n ),
        .ddr3_dm                        ( c0_ddr3_dm ),
        .ddr3_dq                        ( c0_ddr3_dq ),
        .ddr3_dqs_p                     ( c0_ddr3_dqs_p ),
        .ddr3_dqs_n                     ( c0_ddr3_dqs_n ),
        
        // Slave Interface Write Address Ports
        .s_axi_awid                     ( c0_s_axi_awid ), 
        .s_axi_awaddr                   ( c0_s_axi_awaddr ), 
        .s_axi_awlen                    ( c0_s_axi_awlen ), 
        .s_axi_awsize                   ( c0_s_axi_awsize ), 
        .s_axi_awburst                  ( c0_s_axi_awburst ), 
        .s_axi_awlock                   ( c0_s_axi_awlock ), 
        .s_axi_awcache                  ( c0_s_axi_awcache ), 
        .s_axi_awprot                   ( c0_s_axi_awprot ), 
        .s_axi_awqos                    ( c0_s_axi_awqos ), 
        .s_axi_awvalid                  ( c0_s_axi_awvalid ), 
        .s_axi_awready                  ( c0_s_axi_awready ), 
        // Slave Interface Write Data Ports
        .s_axi_wdata                    ( c0_s_axi_wdata ), 
        .s_axi_wstrb                    ( c0_s_axi_wstrb ), 
        .s_axi_wlast                    ( c0_s_axi_wlast ), 
        .s_axi_wvalid                   ( c0_s_axi_wvalid ), 
        .s_axi_wready                   ( c0_s_axi_wready ), 
        // Slave Interface Write Response Ports
        .s_axi_bid                      ( c0_s_axi_bid ), 
        .s_axi_bresp                    ( c0_s_axi_bresp ), 
        .s_axi_bvalid                   ( c0_s_axi_bvalid ), 
        .s_axi_bready                   ( c0_s_axi_bready ), 
        // Slave Interface Read Address Ports
        .s_axi_arid                     ( c0_s_axi_arid ), 
        .s_axi_araddr                   ( c0_s_axi_araddr ), 
        .s_axi_arlen                    ( c0_s_axi_arlen ), 
        .s_axi_arburst                  ( c0_s_axi_arburst ),
        .s_axi_arsize                   ( c0_s_axi_arsize ), 
        .s_axi_arlock                   ( c0_s_axi_arlock ), 
        .s_axi_arcache                  ( c0_s_axi_arcache ), 
        .s_axi_arprot                   ( c0_s_axi_arprot ), 
        .s_axi_arqos                    ( c0_s_axi_arqos ), 
        .s_axi_arvalid                  ( c0_s_axi_arvalid ), 
        .s_axi_arready                  ( c0_s_axi_arready ), 
        // Slave Interface Read Data Ports
        .s_axi_rid                      ( c0_s_axi_rid ), 
        .s_axi_rdata                    ( c0_s_axi_rdata ), 
        .s_axi_rresp                    ( c0_s_axi_rresp ), 
        .s_axi_rlast                    ( c0_s_axi_rlast ), 
        .s_axi_rvalid                   ( c0_s_axi_rvalid ), 
        .s_axi_rready                   ( c0_s_axi_rready ), 
        .ui_clk_sync_rst                ( c0_rst ),
        .ui_clk                         ( c0_clk ),
        .aresetn                        ( c0_aresetn )
    );   

    `ifdef PICO_MODEL_M503
    
    // Memory Interface Generator 1
    `ifdef PICO_SIM_MIG
    PicoMIG #(
        .RANKS                          ( RANKS                 ),
        .ROW_WIDTH                      ( ROW_WIDTH             ),
        .COL_WIDTH                      ( COL_WIDTH             ),
    `else
    mig_DDR3 #(
    `endif

        .RANKS                          ( RANKS                 ),
        .IODELAY_GRP                    ( "IODELAY_MIG_DDR3_1"  ),
        
        .nCS_PER_RANK                   ( nCS_PER_RANK          ),
        .BANK_WIDTH                     ( BANK_WIDTH            ),
        
        .DQ_WIDTH                       ( DQ_WIDTH              ),
        .DQS_WIDTH                      ( DQS_WIDTH             ),
        .DM_WIDTH                       ( DM_WIDTH              ),
        
        .CK_WIDTH                       ( CK_WIDTH              ),
        .CKE_WIDTH                      ( CKE_WIDTH             ),
        .CS_WIDTH                       ( CS_WIDTH              ),
        
        .nDQS_COL0                      ( 6                     ),
        .nDQS_COL1                      ( 2                     ),
        .DQS_LOC_COL0                   ( 48'h050403020100      ),
        .DQS_LOC_COL1                   ( 16'h0706              ),
        
        .C_S_AXI_ID_WIDTH               ( C1_C_S_AXI_ID_WIDTH   ), 
        .C_S_AXI_ADDR_WIDTH             ( C1_C_S_AXI_ADDR_WIDTH ), 
        .C_S_AXI_DATA_WIDTH             ( C1_C_S_AXI_DATA_WIDTH ),
        
        .RST_ACT_LOW                    ( RST_ACT_LOW           )
    )
    mig_DDR3_1
    (
        // DDR3 Physical Pins
        .ddr3_ck_p                      ( c1_ddr3_ck_p ),
        .ddr3_ck_n                      ( c1_ddr3_ck_n ),
        .ddr3_addr                      ( c1_ddr3_addr ),
        .ddr3_ba                        ( c1_ddr3_ba ),
        .ddr3_ras_n                     ( c1_ddr3_ras_n ),
        .ddr3_cas_n                     ( c1_ddr3_cas_n ),
        .ddr3_we_n                      ( c1_ddr3_we_n ),
        .ddr3_cs_n                      ( c1_ddr3_cs_n ),
        .ddr3_cke                       ( c1_ddr3_cke ),
        .ddr3_odt                       ( c1_ddr3_odt ),
        .ddr3_reset_n                   ( c1_ddr3_reset_n ),
        .ddr3_dm                        ( c1_ddr3_dm ),
        .ddr3_dq                        ( c1_ddr3_dq ),
        .ddr3_dqs_p                     ( c1_ddr3_dqs_p ),
        .ddr3_dqs_n                     ( c1_ddr3_dqs_n ),
        .sda                            ( c1_ddr3_sda ),
        .scl                            ( c1_ddr3_scl ),
        
        //source Clock and Reset
        .sys_clk                        ( extra_clk ),
        .sys_rst                        ( ddr3_sys_rst[1] ),
        .clk_ref                        ( extra_clk ),
        
        // Slave Interface Write Address Ports
        .s_axi_awid                     ( c1_s_axi_awid ), 
        .s_axi_awaddr                   ( c1_s_axi_awaddr ), 
        .s_axi_awlen                    ( c1_s_axi_awlen ), 
        .s_axi_awsize                   ( c1_s_axi_awsize ), 
        .s_axi_awburst                  ( c1_s_axi_awburst ), 
        .s_axi_awlock                   ( c1_s_axi_awlock ), 
        .s_axi_awcache                  ( c1_s_axi_awcache ), 
        .s_axi_awprot                   ( c1_s_axi_awprot ), 
        .s_axi_awqos                    ( c1_s_axi_awqos ), 
        .s_axi_awvalid                  ( c1_s_axi_awvalid ), 
        .s_axi_awready                  ( c1_s_axi_awready ), 
        // Slave Interface Write Data Ports
        .s_axi_wdata                    ( c1_s_axi_wdata ), 
        .s_axi_wstrb                    ( c1_s_axi_wstrb ), 
        .s_axi_wlast                    ( c1_s_axi_wlast ), 
        .s_axi_wvalid                   ( c1_s_axi_wvalid ), 
        .s_axi_wready                   ( c1_s_axi_wready ), 
        // Slave Interface Write Response Ports
        .s_axi_bid                      ( c1_s_axi_bid ), 
        .s_axi_bresp                    ( c1_s_axi_bresp ), 
        .s_axi_bvalid                   ( c1_s_axi_bvalid ), 
        .s_axi_bready                   ( c1_s_axi_bready ), 
        // Slave Interface Read Address Ports
        .s_axi_arid                     ( c1_s_axi_arid ), 
        .s_axi_araddr                   ( c1_s_axi_araddr ), 
        .s_axi_arlen                    ( c1_s_axi_arlen ), 
        .s_axi_arburst                  ( c1_s_axi_arburst ),
        .s_axi_arsize                   ( c1_s_axi_arsize ), 
        .s_axi_arlock                   ( c1_s_axi_arlock ), 
        .s_axi_arcache                  ( c1_s_axi_arcache ), 
        .s_axi_arprot                   ( c1_s_axi_arprot ), 
        .s_axi_arqos                    ( c1_s_axi_arqos ), 
        .s_axi_arvalid                  ( c1_s_axi_arvalid ), 
        .s_axi_arready                  ( c1_s_axi_arready ), 
        // Slave Interface Read Data Ports
        .s_axi_rid                      ( c1_s_axi_rid ), 
        .s_axi_rdata                    ( c1_s_axi_rdata ), 
        .s_axi_rresp                    ( c1_s_axi_rresp ), 
        .s_axi_rlast                    ( c1_s_axi_rlast ), 
        .s_axi_rvalid                   ( c1_s_axi_rvalid ), 
        .s_axi_rready                   ( c1_s_axi_rready ), 
        .ui_clk_sync_rst                ( c1_rst ),
        .ui_clk                         ( c1_clk ),
        .phy_init_done                  ( c1_phy_init_done ),
        .aresetn                        ( c1_aresetn )
    );   
	`endif // PICO_MODEL_M503
`endif //PICO_DDR3

endmodule

