// User_Ram_M503.v
// Copyright 2011 Pico Computing, Inc.
// This module tests the QDRII system and communicates with the host via the PicoBus

`timescale 1ns / 1ps
`include "PicoDefines.v"

module Pico_QDRII_test #(

    parameter QDRIIP_ADDR_WIDTH = 20,           // address width
    parameter QDRIIP_DATA_WIDTH = 18,           // data width
    parameter QDRIIP_BURST_LEN  = 4,            // burst length
    parameter QDRIIP_TCQ        = 100,          // tcq delay
    
    parameter QDRII_CTRL_ADDR   = 32'h12350000, // PicoBus Address for controlling the QDRII system
    parameter QDRII_ERR_ADDR    = 32'h12350020, // PicoBus Address for accessing error flags
    parameter QDRII_DATA_ADDR   = 32'h12350040, // base PicoBus Address for accessing read data
    parameter QDRII_DATA_INCR   = 32'h00000020, // increment amount for reading different read data
    parameter QDRII_SIG         = 32'h55AA55AA  // QDRII PicoData signature
    ) 
    (

    //------------------------------------------------------
    // QDRII Reset
    //------------------------------------------------------     
      
    output reg                          qdrii_sys_rst,

    //------------------------------------------------------
    // QDRII 0 Ports
    //------------------------------------------------------
     
    output                              c0_user_wr_cmd0,
    output                              c0_user_wr_cmd1,
    output [19:0]                       c0_user_wr_addr0,
    output [19:0]                       c0_user_wr_addr1,
    output                              c0_user_rd_cmd0,
    output                              c0_user_rd_cmd1,
    output [19:0]                       c0_user_rd_addr0,
    output [19:0]                       c0_user_rd_addr1,
    output [71:0]                       c0_user_wr_data0,
    output [35:0]                       c0_user_wr_data1,
    output [7:0]                        c0_user_wr_bw_n0,
    output [3:0]                        c0_user_wr_bw_n1,
    input                               c0_clk_tb,
    input                               c0_rst_clk_tb,
    input                               c0_user_rd_valid0,
    input                               c0_user_rd_valid1,
    input  [71:0]                       c0_user_rd_data0,
    input  [35:0]                       c0_user_rd_data1,
    input                               c0_cal_done,
     
    //------------------------------------------------------
    // QDRII 1 Ports
    //------------------------------------------------------
  
    output                              c1_user_wr_cmd0,
    output                              c1_user_wr_cmd1,
    output [19:0]                       c1_user_wr_addr0,
    output [19:0]                       c1_user_wr_addr1,
    output                              c1_user_rd_cmd0,
    output                              c1_user_rd_cmd1,
    output [19:0]                       c1_user_rd_addr0,
    output [19:0]                       c1_user_rd_addr1,
    output [71:0]                       c1_user_wr_data0,
    output [35:0]                       c1_user_wr_data1,
    output [7:0]                        c1_user_wr_bw_n0,
    output [3:0]                        c1_user_wr_bw_n1,
    input                               c1_clk_tb,
    input                               c1_rst_clk_tb,
    input                               c1_user_rd_valid0,
    input                               c1_user_rd_valid1,
    input  [71:0]                       c1_user_rd_data0,
    input  [35:0]                       c1_user_rd_data1,
    input                               c1_cal_done,

    //------------------------------------------------------
    // QDRII 2 Ports
    //------------------------------------------------------

    output                              c2_user_wr_cmd0,
    output                              c2_user_wr_cmd1,
    output [19:0]                       c2_user_wr_addr0,
    output [19:0]                       c2_user_wr_addr1,
    output                              c2_user_rd_cmd0,
    output                              c2_user_rd_cmd1,
    output [19:0]                       c2_user_rd_addr0,
    output [19:0]                       c2_user_rd_addr1,
    output [71:0]                       c2_user_wr_data0,
    output [35:0]                       c2_user_wr_data1,
    output [7:0]                        c2_user_wr_bw_n0,
    output [3:0]                        c2_user_wr_bw_n1,
    input                               c2_clk_tb,
    input                               c2_rst_clk_tb,
    input                               c2_user_rd_valid0,
    input                               c2_user_rd_valid1,
    input  [71:0]                       c2_user_rd_data0,
    input  [35:0]                       c2_user_rd_data1,
    input                               c2_cal_done,

    //------------------------------------------------------
    // PicoBus Ports
    //------------------------------------------------------

    input                               PicoClk,             // Pico Clock
    input                               PicoRst,             // Pico Reset
    input  [31:0]                       PicoAddr,            // Pico Address
    input  [127:0]                      PicoDataIn,          // Pico Data In
    output reg [127:0]                  PicoDataOut,         // Pico Data Out
    input                               PicoRd,              // Pico Read Valid
    input                               PicoWr               // Pico Write Valid
);
    
//------------------------------------------------------
// Wire Declarations
//------------------------------------------------------
    
    wire                                c0_qdriip_error;
    wire                                c0_qdriip_cmp_err; 
    wire                                c1_qdriip_error;
    wire                                c1_qdriip_cmp_err;
    wire                                c2_qdriip_error;
    wire                                c2_qdriip_cmp_err;    

//------------------------------------------------------
// Register Declarations
//------------------------------------------------------
    
    reg                                 c0_cal_done_1;
    reg                                 c1_cal_done_1;
    reg                                 c2_cal_done_1;
    
    reg                                 c0_cal_done_q;
    reg                                 c1_cal_done_q;
    reg                                 c2_cal_done_q;
    
    reg                                 qdrii_sys_rst_1 = 1'b0;
    reg                                 qdrii_sys_rst_q = 1'b0;
    
    reg                                 c0_qdriip_error_1;
    reg                                 c0_qdriip_cmp_err_1;
    reg                                 c1_qdriip_error_1;
    reg                                 c1_qdriip_cmp_err_1;
    reg                                 c2_qdriip_error_1;
    reg                                 c2_qdriip_cmp_err_1;
    
    reg                                 c0_qdriip_error_q;
    reg                                 c0_qdriip_cmp_err_q; 
    reg                                 c1_qdriip_error_q;
    reg                                 c1_qdriip_cmp_err_q;
    reg                                 c2_qdriip_error_q;
    reg                                 c2_qdriip_cmp_err_q;
    
    reg     [71:0]                      c0_user_rd_data0_1;
    reg     [71:0]                      c1_user_rd_data0_1;
    reg     [71:0]                      c2_user_rd_data0_1;
    
    reg     [71:0]                      c0_user_rd_data0_q;
    reg     [71:0]                      c1_user_rd_data0_q;
    reg     [71:0]                      c2_user_rd_data0_q;
    
//------------------------------------------------------
// PicoBus Interface
//  From the PCIE we can:
//     - reset QDRII 
//     - verify the QDRII is configured by checking cal_done
//------------------------------------------------------

  
    always @ (posedge PicoClk) begin
        // Write interface        
        if ( PicoRst ) begin
            qdrii_sys_rst_q     <= 1'b0;
        end else if ( PicoWr && (PicoAddr == QDRII_CTRL_ADDR) ) begin
            qdrii_sys_rst_q     <= PicoDataIn[64];
        end

        // Read interface       
        if ( PicoRst ) begin
            PicoDataOut         <= 128'h0;
        end else if ( PicoRd && (PicoAddr == QDRII_CTRL_ADDR) ) begin
            PicoDataOut[0]      <= c0_cal_done_q;
            PicoDataOut[16]     <= c1_cal_done_q;
            PicoDataOut[32]     <= c2_cal_done_q;
            PicoDataOut[64]     <= qdrii_sys_rst_q; 
            PicoDataOut[127:96] <= QDRII_SIG;
        end else if ( PicoRd && (PicoAddr == QDRII_ERR_ADDR) ) begin
            PicoDataOut[0]      <= c0_qdriip_error_q;         
            PicoDataOut[16]     <= c0_qdriip_cmp_err_q;
            PicoDataOut[32]     <= c1_qdriip_error_q;       
            PicoDataOut[48]     <= c1_qdriip_cmp_err_q;        
            PicoDataOut[64]     <= c2_qdriip_error_q;      
            PicoDataOut[80]     <= c2_qdriip_cmp_err_q;
        end else if ( PicoRd && (PicoAddr == QDRII_DATA_ADDR) ) begin
            PicoDataOut[71:0]   <= c0_user_rd_data0_q;
        end else if ( PicoRd && (PicoAddr == QDRII_DATA_ADDR + 1*QDRII_DATA_INCR) ) begin
            PicoDataOut[71:0]   <= c1_user_rd_data0_q;
        end else if ( PicoRd && (PicoAddr == QDRII_DATA_ADDR + 2*QDRII_DATA_INCR) ) begin
            PicoDataOut[71:0]   <= c2_user_rd_data0_q; 
        end else begin
            PicoDataOut         <= 128'h0;
        end
    end
    
//-------------------------------------------------------------//
// Buffer Signals 
//-------------------------------------------------------------//
// Note: We only need to buffer these signals because the PCIe
//       interface (i.e. PicoBus) is on the right side of the 
//       FPGA and the QDRII pins are on the left side of the
//       FPGA.  If we drive the QDRII pins from fabric alone
//       and do not interface with the QDRII from the PCIe, we
//       may not need these buffers.  However, if we interface
//       with the QDRII system via the PCIe, as we do here, we 
//       will need to buffer the data moving back and forth 
//       between the two systems.
//-------------------------------------------------------------//
    always @ (posedge PicoClk) begin
        
        // QDRII reset signal
        qdrii_sys_rst_1         <= qdrii_sys_rst_q;
        qdrii_sys_rst           <= qdrii_sys_rst_1;

        // error signals
        c0_qdriip_error_1       <= c0_qdriip_error;
        c0_qdriip_cmp_err_1     <= c0_qdriip_cmp_err; 
        c1_qdriip_error_1       <= c1_qdriip_error;
        c1_qdriip_cmp_err_1     <= c1_qdriip_cmp_err;
        c2_qdriip_error_1       <= c2_qdriip_error;
        c2_qdriip_cmp_err_1     <= c2_qdriip_cmp_err;
        
        c0_qdriip_error_q       <= c0_qdriip_error_1;
        c0_qdriip_cmp_err_q     <= c0_qdriip_cmp_err_1; 
        c1_qdriip_error_q       <= c1_qdriip_error_1;
        c1_qdriip_cmp_err_q     <= c1_qdriip_cmp_err_1;
        c2_qdriip_error_q       <= c2_qdriip_error_1;
        c2_qdriip_cmp_err_q     <= c2_qdriip_cmp_err_1;
        
        // read data
        c0_user_rd_data0_1      <= c0_user_rd_data0;
        c1_user_rd_data0_1      <= c1_user_rd_data0;
        c2_user_rd_data0_1      <= c2_user_rd_data0;
        
        c0_user_rd_data0_q      <= c0_user_rd_data0_1;
        c1_user_rd_data0_q      <= c1_user_rd_data0_1;
        c2_user_rd_data0_q      <= c2_user_rd_data0_1;

        // calibration done signals
        c0_cal_done_1           <= c0_cal_done;
        c1_cal_done_1           <= c1_cal_done;
        c2_cal_done_1           <= c2_cal_done;
        
        c0_cal_done_q           <= c0_cal_done_1;
        c1_cal_done_q           <= c1_cal_done_1;
        c2_cal_done_q           <= c2_cal_done_1;
    end
    
//-------------------------------------------------------------//
// Xilinx QDRII Traffic Generation Module
//-------------------------------------------------------------//

    tb_top #(
        .BURST_LEN      (QDRIIP_BURST_LEN),
        .ADDR_WIDTH     (QDRIIP_ADDR_WIDTH),
        .DATA_WIDTH     (QDRIIP_DATA_WIDTH),
        .TCQ            (QDRIIP_TCQ)
    ) 
    c0_qdriip_u_tb_top  (
        .clk            (c0_clk_tb),
        .rst_clk        (c0_rst_clk_tb),
        .wr_cmd0        (c0_user_wr_cmd0),
        .wr_cmd1        (c0_user_wr_cmd1),
        .wr_addr0       (c0_user_wr_addr0),
        .wr_addr1       (c0_user_wr_addr1),
        .rd_cmd0        (c0_user_rd_cmd0),
        .rd_cmd1        (c0_user_rd_cmd1),
        .rd_addr0       (c0_user_rd_addr0),
        .rd_addr1       (c0_user_rd_addr1),
        .wr_data0       (c0_user_wr_data0),
        .wr_data1       (c0_user_wr_data1),
        .wr_bw_n0       (c0_user_wr_bw_n0),
        .wr_bw_n1       (c0_user_wr_bw_n1),
        .rd_valid0      (c0_user_rd_valid0),
        .rd_valid1      (c0_user_rd_valid1),
        .rd_data0       (c0_user_rd_data0),
        .rd_data1       (c0_user_rd_data1),
        .cal_done       (c0_cal_done),
        .compare_error  (c0_qdriip_error),
        .cmp_err        (c0_qdriip_cmp_err),
        .clear_error    (1'b0)
    );

    tb_top #(
        .BURST_LEN      (QDRIIP_BURST_LEN),
        .ADDR_WIDTH     (QDRIIP_ADDR_WIDTH),
        .DATA_WIDTH     (QDRIIP_DATA_WIDTH),
        .TCQ            (QDRIIP_TCQ)
    ) 
    c1_qdriip_u_tb_top  (
        .clk            (c1_clk_tb),
        .rst_clk        (c1_rst_clk_tb),
        .wr_cmd0        (c1_user_wr_cmd0),
        .wr_cmd1        (c1_user_wr_cmd1),
        .wr_addr0       (c1_user_wr_addr0),
        .wr_addr1       (c1_user_wr_addr1),
        .rd_cmd0        (c1_user_rd_cmd0),
        .rd_cmd1        (c1_user_rd_cmd1),
        .rd_addr0       (c1_user_rd_addr0),
        .rd_addr1       (c1_user_rd_addr1),
        .wr_data0       (c1_user_wr_data0),
        .wr_data1       (c1_user_wr_data1),
        .wr_bw_n0       (c1_user_wr_bw_n0),
        .wr_bw_n1       (c1_user_wr_bw_n1),
        .rd_valid0      (c1_user_rd_valid0),
        .rd_valid1      (c1_user_rd_valid1),
        .rd_data0       (c1_user_rd_data0),
        .rd_data1       (c1_user_rd_data1),
        .cal_done       (c1_cal_done),
        .compare_error  (c1_qdriip_error),
        .cmp_err        (c1_qdriip_cmp_err),
        .clear_error    (1'b0)
    );

    tb_top #(
        .BURST_LEN      (QDRIIP_BURST_LEN),
        .ADDR_WIDTH     (QDRIIP_ADDR_WIDTH),
        .DATA_WIDTH     (QDRIIP_DATA_WIDTH),
        .TCQ            (QDRIIP_TCQ)
    )
    c2_qdriip_u_tb_top  (
        .clk            (c2_clk_tb),
        .rst_clk        (c2_rst_clk_tb),
        .wr_cmd0        (c2_user_wr_cmd0),
        .wr_cmd1        (c2_user_wr_cmd1),
        .wr_addr0       (c2_user_wr_addr0),
        .wr_addr1       (c2_user_wr_addr1),
        .rd_cmd0        (c2_user_rd_cmd0),
        .rd_cmd1        (c2_user_rd_cmd1),
        .rd_addr0       (c2_user_rd_addr0),
        .rd_addr1       (c2_user_rd_addr1),
        .wr_data0       (c2_user_wr_data0),
        .wr_data1       (c2_user_wr_data1),
        .wr_bw_n0       (c2_user_wr_bw_n0),
        .wr_bw_n1       (c2_user_wr_bw_n1),
        .rd_valid0      (c2_user_rd_valid0),
        .rd_valid1      (c2_user_rd_valid1),
        .rd_data0       (c2_user_rd_data0),
        .rd_data1       (c2_user_rd_data1),
        .cal_done       (c2_cal_done),
        .compare_error  (c2_qdriip_error),
        .cmp_err        (c2_qdriip_cmp_err),
        .clear_error    (1'b0)
    );

endmodule

