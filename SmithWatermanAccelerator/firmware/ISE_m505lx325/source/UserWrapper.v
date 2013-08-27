// UserWrapper.v
// Copyright 2011 Pico Computing, Inc.

// This module instantiates the user module and all the stream and PicoBus connectors it needs.
         
`include "PicoDefines.v"

module UserWrapper 
`ifdef PICO_DDR3
    #(
`ifdef PICO_MODEL_M503
            parameter C1_C_S_AXI_ID_WIDTH       = 12,   // width of the ID out of this UserWrapper
                                                        // = width of the ID from the masters + 4
            parameter C1_C_S_AXI_ADDR_WIDTH     = 32,   // AXI address width in MIG 1 
            parameter C1_C_S_AXI_DATA_WIDTH     = 256,  // AXI data width in the MIG and interconnect
            parameter C1_C_S_AXI_MASTERS        = 3,    // number of master devices accessing MIG 1
`endif // PICO_MODEL_M503
            parameter C0_C_S_AXI_ID_WIDTH       = 12,   // width of the ID out of this UserWrapper
                                                        // = width of the ID from the masters + 4
            parameter C0_C_S_AXI_ADDR_WIDTH     = 32,   // AXI address width in MIG 0
            parameter C0_C_S_AXI_DATA_WIDTH     = 256,  // AXI data width in the MIG and interconnect
            parameter C0_C_S_AXI_MASTERS        = 3     // number of master devices accessing MIG 0
    )
`endif // PICO_DDR3
    
    (
`ifdef PICO_DDR3
	       
	//------------------------------------------------------
	// DDR3 Reset
	//------------------------------------------------------
`ifdef PICO_MODEL_M503
      output [1:0]                         ddr3_sys_rst,        // Resets the DDR3s
`else
      output [0:0]                         ddr3_sys_rst,        // Resets the DDR3
`endif

	//------------------------------------------------------
	// DDR3 0  - AXI ports
	//------------------------------------------------------
      input                                c0_tb_clk,           // AXI input clock

      // Input control signals
      input                                c0_phy_init_done,    // Initialization completed
      input                                c0_tb_rst,           // Active high reset signal

      // AXI write address channel signals
      input                                c0_s_axi_awready,    // Indicates slave is ready to accept a 
      output [C0_C_S_AXI_ID_WIDTH-1:0]     c0_s_axi_awid,       // Write ID
      output [C0_C_S_AXI_ADDR_WIDTH-1:0]   c0_s_axi_awaddr,     // Write address
      output [7:0]                         c0_s_axi_awlen,      // Write Burst Length
      output [2:0]                         c0_s_axi_awsize,     // Write Burst size
      output [1:0]                         c0_s_axi_awburst,    // Write Burst type
      output                               c0_s_axi_awlock,     // Write lock type
      output [3:0]                         c0_s_axi_awcache,    // Write Cache type
      output [2:0]                         c0_s_axi_awprot,     // Write Protection type
      output [3:0]                         c0_s_axi_awqos,      // Write Quality of Service Signaling
      output                               c0_s_axi_awvalid,    // Write address valid
     
      // AXI write data channel signals
      input                                c0_s_axi_wready,     // Write data ready
      output [C0_C_S_AXI_DATA_WIDTH-1:0]   c0_s_axi_wdata,      // Write data
      output [C0_C_S_AXI_DATA_WIDTH/8-1:0] c0_s_axi_wstrb,      // Write strobes
      output                               c0_s_axi_wlast,      // Last write transaction   
      output                               c0_s_axi_wvalid,     // Write valid
     
      // AXI write response channel signals
      input  [C0_C_S_AXI_ID_WIDTH-1:0]     c0_s_axi_bid,        // Response ID
      input  [1:0]                         c0_s_axi_bresp,      // Write response
      input                                c0_s_axi_bvalid,     // Write reponse valid
      output                               c0_s_axi_bready,     // Response ready
     
      // AXI read address channel signals
      input                                c0_s_axi_arready,    // Read address ready
      output [C0_C_S_AXI_ID_WIDTH-1:0]     c0_s_axi_arid,       // Read ID
      output [C0_C_S_AXI_ADDR_WIDTH-1:0]   c0_s_axi_araddr,     // Read address
      output [7:0]                         c0_s_axi_arlen,      // Read Burst Length
      output [2:0]                         c0_s_axi_arsize,     // Read Burst size
      output [1:0]                         c0_s_axi_arburst,    // Read Burst type
      output                               c0_s_axi_arlock,     // Read lock type
      output [3:0]                         c0_s_axi_arcache,    // Read Cache type
      output [2:0]                         c0_s_axi_arprot,     // Read Protection type
      output                               c0_s_axi_arvalid,    // Read address valid
      output [3:0]                         c0_s_axi_arqos,      // Read Quality of Service Signaling 
     
      // AXI read data channel signals   
      input  [C0_C_S_AXI_ID_WIDTH-1:0]     c0_s_axi_rid,        // Response ID
      input  [1:0]                         c0_s_axi_rresp,      // Read response
      input                                c0_s_axi_rvalid,     // Read reponse valid
      input  [C0_C_S_AXI_DATA_WIDTH-1:0]   c0_s_axi_rdata,      // Read data
      input                                c0_s_axi_rlast,      // Read last
      output                               c0_s_axi_rready,     // Read Response ready

`ifdef PICO_MODEL_M503
	//------------------------------------------------------
	// DDR3 1  - AXI ports
	//------------------------------------------------------
      input                                c1_tb_clk,           // AXI input clock

      // Input control signals
      input                                c1_phy_init_done,    // Initialization completed
      input                                c1_tb_rst,           // Active high reset signal

      // AXI write address channel signals
      input                                c1_s_axi_awready,    // Indicates slave is ready to accept a 
      output [C1_C_S_AXI_ID_WIDTH-1:0]     c1_s_axi_awid,       // Write ID
      output [C1_C_S_AXI_ADDR_WIDTH-1:0]   c1_s_axi_awaddr,     // Write address
      output [7:0]                         c1_s_axi_awlen,      // Write Burst Length
      output [2:0]                         c1_s_axi_awsize,     // Write Burst size
      output [1:0]                         c1_s_axi_awburst,    // Write Burst type
      output                               c1_s_axi_awlock,     // Write lock type
      output [3:0]                         c1_s_axi_awcache,    // Write Cache type
      output [2:0]                         c1_s_axi_awprot,     // Write Protection type
      output [3:0]                         c1_s_axi_awqos,      // Write Quality of Service Signaling
      output                               c1_s_axi_awvalid,    // Write address valid
     
      // AXI write data channel signals
      input                                c1_s_axi_wready,     // Write data ready
      output [C1_C_S_AXI_DATA_WIDTH-1:0]   c1_s_axi_wdata,      // Write data
      output [C1_C_S_AXI_DATA_WIDTH/8-1:0] c1_s_axi_wstrb,      // Write strobes
      output                               c1_s_axi_wlast,      // Last write transaction   
      output                               c1_s_axi_wvalid,     // Write valid
     
      // AXI write response channel signals
      input  [C1_C_S_AXI_ID_WIDTH-1:0]     c1_s_axi_bid,        // Response ID
      input  [1:0]                         c1_s_axi_bresp,      // Write response
      input                                c1_s_axi_bvalid,     // Write reponse valid
      output                               c1_s_axi_bready,     // Response ready
     
      // AXI read address channel signals
      input                                c1_s_axi_arready,    // Read address ready
      output [C1_C_S_AXI_ID_WIDTH-1:0]     c1_s_axi_arid,       // Read ID
      output [C1_C_S_AXI_ADDR_WIDTH-1:0]   c1_s_axi_araddr,     // Read address
      output [7:0]                         c1_s_axi_arlen,      // Read Burst Length
      output [2:0]                         c1_s_axi_arsize,     // Read Burst size
      output [1:0]                         c1_s_axi_arburst,    // Read Burst type
      output                               c1_s_axi_arlock,     // Read lock type
      output [3:0]                         c1_s_axi_arcache,    // Read Cache type
      output [2:0]                         c1_s_axi_arprot,     // Read Protection type
      output                               c1_s_axi_arvalid,    // Read address valid
      output [3:0]                         c1_s_axi_arqos,      // Read Quality of Service Signaling 
     
      // AXI read data channel signals   
      input  [C1_C_S_AXI_ID_WIDTH-1:0]     c1_s_axi_rid,        // Response ID
      input  [1:0]                         c1_s_axi_rresp,      // Read response
      input                                c1_s_axi_rvalid,     // Read reponse valid
      input  [C1_C_S_AXI_DATA_WIDTH-1:0]   c1_s_axi_rdata,      // Read data
      input                                c1_s_axi_rlast,      // Read last
      output                               c1_s_axi_rready,     // Read Response ready
`endif // PICO_MODEL_M503
`endif // PICO_DDR3

`ifdef PICO_QDRII 
   `ifdef PICO_MODEL_M503 	
       //------------------------------------------------------
       // QDRII Reset
       //------------------------------------------------------     
         
         output                               qdrii_sys_rst,
   
        //------------------------------------------------------
       // QDRII 0 Ports
       //------------------------------------------------------
       
         output                               c0_user_wr_cmd0,
         output                               c0_user_wr_cmd1,
         output [19:0]                        c0_user_wr_addr0,
         output [19:0]                        c0_user_wr_addr1,
         output                               c0_user_rd_cmd0,
         output                               c0_user_rd_cmd1,
         output [19:0]                        c0_user_rd_addr0,
         output [19:0]                        c0_user_rd_addr1,
         output [71:0]                        c0_user_wr_data0,
         output [35:0]                        c0_user_wr_data1,
         output [7:0]                         c0_user_wr_bw_n0,
         output [3:0]                         c0_user_wr_bw_n1,
         input                                c0_clk_tb,
         input                                c0_rst_clk_tb,
         input                                c0_user_rd_valid0,
         input                                c0_user_rd_valid1,
         input  [71:0]                        c0_user_rd_data0,
         input  [35:0]                        c0_user_rd_data1,
         input                                c0_cal_done,
        
        //------------------------------------------------------
       // QDRII 1 Ports
       //------------------------------------------------------
     
         output                               c1_user_wr_cmd0,
         output                               c1_user_wr_cmd1,
         output [19:0]                        c1_user_wr_addr0,
         output [19:0]                        c1_user_wr_addr1,
         output                               c1_user_rd_cmd0,
         output                               c1_user_rd_cmd1,
         output [19:0]                        c1_user_rd_addr0,
         output [19:0]                        c1_user_rd_addr1,
         output [71:0]                        c1_user_wr_data0,
         output [35:0]                        c1_user_wr_data1,
         output [7:0]                         c1_user_wr_bw_n0,
         output [3:0]                         c1_user_wr_bw_n1,
         input                                c1_clk_tb,
         input                                c1_rst_clk_tb,
         input                                c1_user_rd_valid0,
         input                                c1_user_rd_valid1,
         input  [71:0]                        c1_user_rd_data0,
         input  [35:0]                        c1_user_rd_data1,
         input                                c1_cal_done,
   
        //------------------------------------------------------
       // QDRII 2 Ports
       //------------------------------------------------------
   
         output                               c2_user_wr_cmd0,
         output                               c2_user_wr_cmd1,
         output [19:0]                        c2_user_wr_addr0,
         output [19:0]                        c2_user_wr_addr1,
         output                               c2_user_rd_cmd0,
         output                               c2_user_rd_cmd1,
         output [19:0]                        c2_user_rd_addr0,
         output [19:0]                        c2_user_rd_addr1,
         output [71:0]                        c2_user_wr_data0,
         output [35:0]                        c2_user_wr_data1,
         output [7:0]                         c2_user_wr_bw_n0,
         output [3:0]                         c2_user_wr_bw_n1,
         input                                c2_clk_tb,
         input                                c2_rst_clk_tb,
         input                                c2_user_rd_valid0,
         input                                c2_user_rd_valid1,
         input  [71:0]                        c2_user_rd_data0,
         input  [35:0]                        c2_user_rd_data1,
         input                                c2_cal_done,
         //PICO_MODEL_M503
    `elsif PICO_MODEL_EX600
       //------------------------------------------------------
       // QDRII Reset
       //------------------------------------------------------     
         
         output                               qdrii_sys_rst,
   
        //------------------------------------------------------
       // QDRII 0 Ports
       //------------------------------------------------------
       
         output                               c0_user_wr_cmd0,
         output                               c0_user_wr_cmd1,
         output [20:0]                        c0_user_wr_addr0,
         output [20:0]                        c0_user_wr_addr1,
         output                               c0_user_rd_cmd0,
         output                               c0_user_rd_cmd1,
         output [20:0]                        c0_user_rd_addr0,
         output [20:0]                        c0_user_rd_addr1,
         output [143:0]                       c0_user_wr_data0,
         output [71:0]                        c0_user_wr_data1,
         output [15:0]                        c0_user_wr_bw_n0,
         output [7:0]                         c0_user_wr_bw_n1,
         input                                c0_clk_tb,
         input                                c0_rst_clk_tb,
         input                                c0_user_rd_valid0,
         input                                c0_user_rd_valid1,
         input  [143:0]                       c0_user_rd_data0,
         input  [71:0]                        c0_user_rd_data1,
         input                                c0_cal_done,
        
        //------------------------------------------------------
       // QDRII 1 Ports
       //------------------------------------------------------
     
         output                               c1_user_wr_cmd0,
         output                               c1_user_wr_cmd1,
         output [20:0]                        c1_user_wr_addr0,
         output [20:0]                        c1_user_wr_addr1,
         output                               c1_user_rd_cmd0,
         output                               c1_user_rd_cmd1,
         output [20:0]                        c1_user_rd_addr0,
         output [20:0]                        c1_user_rd_addr1,
         output [143:0]                       c1_user_wr_data0,
         output [71:0]                        c1_user_wr_data1,
         output [15:0]                        c1_user_wr_bw_n0,
         output [7:0]                         c1_user_wr_bw_n1,
         input                                c1_clk_tb,
         input                                c1_rst_clk_tb,
         input                                c1_user_rd_valid0,
         input                                c1_user_rd_valid1,
         input  [143:0]                       c1_user_rd_data0,
         input  [71:0]                        c1_user_rd_data1,
         input                                c1_cal_done,
    `endif //PICO_MODEL_EX600
`endif // PICO_QDRII

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
      
    input               extra_clk,
    input               clk,
    input               rst,
    
    input               s_out_en,
    input      [8:0]    s_out_id,
    output     [127:0]  s_out_data,
    
    input               s_in_valid,
    input [8:0]         s_in_id,
    input [127:0]       s_in_data,
    
    input       [8:0]   s_poll_id,
    output      [31:0]  s_poll_seq,
    output      [127:0] s_poll_next_desc,
    output              s_poll_next_desc_valid,
    
    input       [8:0]   s_next_desc_rd_id,
    input               s_next_desc_rd_en,
    
    // user-direct writes
    output [127:0]      user_pci_wr_q_data,
    output              user_pci_wr_q_valid,
    input               user_pci_wr_q_en,

    output [127:0]      user_pci_wr_data_q_data,
    output              user_pci_wr_data_q_valid,
    input               user_pci_wr_data_q_en,
    
    input               direct_rx_valid
    );
    
    // function to compute ceil( log( x ) ) 
    // Note: log is computed in base 2
    function integer clogb2;
        input [31:0] value;
        begin
            value = value - 1;
            for (clogb2 = 0; value > 0; clogb2 = clogb2 + 1) begin
                value = value >> 1;
            end
        end
    endfunction
    
    `ifdef USER_MODULE_NAME                 // Only enable these streams if there is a usermodule
    
    /////////////////////////////////
    // UserModule PicoBus
    /////////////////////////////////
`ifdef PICOBUS_WIDTH
        wire [127:0]    s_out_data_userpb, s_poll_next_desc_userpb;
        wire [31:0]     s_poll_seq_userpb;
        wire            s_poll_next_desc_valid_userpb;
        
        wire [`PICOBUS_WIDTH-1:0]   UserModulePicoDataIn, UserModulePicoDataOut;
        wire [31:0]                 UserModulePicoAddr;
        wire                        UserModulePicoClk, UserModulePicoRst, UserModulePicoRd, UserModulePicoWr;
`endif // PICOBUS_WIDTH


`ifdef PICO_DDR3

    ////////////////
    // DDR3 MIG 0 //
    ////////////////
    // Slave Interface Wires 
    wire    [C0_C_S_AXI_MASTERS:0]          c0_axi_clk;

    // Slave Interface Write Address Ports
    wire    [C0_C_S_AXI_ID_WIDTH-5:0]       c0_axi_awid    [0:C0_C_S_AXI_MASTERS];
    wire    [C0_C_S_AXI_ADDR_WIDTH-1:0]     c0_axi_awaddr  [0:C0_C_S_AXI_MASTERS]; 
    wire    [7:0]                           c0_axi_awlen   [0:C0_C_S_AXI_MASTERS];
    wire    [2:0]                           c0_axi_awsize  [0:C0_C_S_AXI_MASTERS]; 
    wire    [1:0]                           c0_axi_awburst [0:C0_C_S_AXI_MASTERS]; 
    wire    [0:0]                           c0_axi_awlock  [0:C0_C_S_AXI_MASTERS];
    wire    [3:0]                           c0_axi_awcache [0:C0_C_S_AXI_MASTERS]; 
    wire    [2:0]                           c0_axi_awprot  [0:C0_C_S_AXI_MASTERS]; 
    wire    [3:0]                           c0_axi_awqos   [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_awvalid [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_awready [0:C0_C_S_AXI_MASTERS]; 
    // Slave Interface Write Data Ports
    wire    [C0_C_S_AXI_DATA_WIDTH-1:0]     c0_axi_wdata   [0:C0_C_S_AXI_MASTERS];
    wire    [C0_C_S_AXI_DATA_WIDTH/8-1:0]   c0_axi_wstrb   [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_wlast   [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_wvalid  [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_wready  [0:C0_C_S_AXI_MASTERS]; 
    // Slave Interface Write Response Ports
    wire    [C0_C_S_AXI_ID_WIDTH-5:0]       c0_axi_bid     [0:C0_C_S_AXI_MASTERS];
    wire    [1:0]                           c0_axi_bresp   [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_bvalid  [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_bready  [0:C0_C_S_AXI_MASTERS]; 
    // Slave Interface Read Address Ports
    wire    [C0_C_S_AXI_ID_WIDTH-5:0]       c0_axi_arid    [0:C0_C_S_AXI_MASTERS]; 
    wire    [C0_C_S_AXI_ADDR_WIDTH-1:0]     c0_axi_araddr  [0:C0_C_S_AXI_MASTERS]; 
    wire    [7:0]                           c0_axi_arlen   [0:C0_C_S_AXI_MASTERS];
    wire    [2:0]                           c0_axi_arsize  [0:C0_C_S_AXI_MASTERS]; 
    wire    [1:0]                           c0_axi_arburst [0:C0_C_S_AXI_MASTERS]; 
    wire    [0:0]                           c0_axi_arlock  [0:C0_C_S_AXI_MASTERS];
    wire    [3:0]                           c0_axi_arcache [0:C0_C_S_AXI_MASTERS]; 
    wire    [2:0]                           c0_axi_arprot  [0:C0_C_S_AXI_MASTERS];
    wire    [3:0]                           c0_axi_arqos   [0:C0_C_S_AXI_MASTERS];
    wire                                    c0_axi_arvalid [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_arready [0:C0_C_S_AXI_MASTERS]; 
    // Slave Interface Read Data Ports
    wire    [C0_C_S_AXI_ID_WIDTH-5:0]       c0_axi_rid     [0:C0_C_S_AXI_MASTERS];
    wire    [C0_C_S_AXI_DATA_WIDTH-1:0]     c0_axi_rdata   [0:C0_C_S_AXI_MASTERS]; 
    wire    [1:0]                           c0_axi_rresp   [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_rlast   [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_rvalid  [0:C0_C_S_AXI_MASTERS]; 
    wire                                    c0_axi_rready  [0:C0_C_S_AXI_MASTERS]; 
    
    /////////////////////////
    // Stream Controller 0 //
    /////////////////////////
    // host streaming interface sits on port 0 of the axi interconnect
    PicoStreamToAXI #(
        .C_AXI_ID_WIDTH     (C0_C_S_AXI_ID_WIDTH-4), 
        .C_AXI_ADDR_WIDTH   (C0_C_S_AXI_ADDR_WIDTH),
        .STREAM_DATA_WIDTH  (128),
        .UPSIZE_RATIO       (C0_C_S_AXI_DATA_WIDTH/128),
        .LOG_UPSIZE_RATIO   (clogb2(C0_C_S_AXI_DATA_WIDTH/128))
    ) 
    stream_to_mem_0
    (
        // streaming interface
        .clk                (clk),
        .rst                (rst),
    `ifdef PICO_MODEL_M503
        .si_ready           (stream_in_rdy[`DDR3_STREAM_ID_0]),
        .si_valid           (stream_in_valid[`DDR3_STREAM_ID_0]),
        .si_data            (stream_in_data[`DDR3_STREAM_ID_0]),
        .so_ready           (stream_out_rdy[`DDR3_STREAM_ID_0]),
        .so_valid           (stream_out_valid[`DDR3_STREAM_ID_0]),
        .so_data            (stream_out_data[`DDR3_STREAM_ID_0]),
    `else
        .si_ready           (stream_in_rdy[`DDR3_STREAM_ID]),
        .si_valid           (stream_in_valid[`DDR3_STREAM_ID]),
        .si_data            (stream_in_data[`DDR3_STREAM_ID]),
        .so_ready           (stream_out_rdy[`DDR3_STREAM_ID]),
        .so_valid           (stream_out_valid[`DDR3_STREAM_ID]),
        .so_data            (stream_out_data[`DDR3_STREAM_ID]),
    `endif // PICO_MODEL_M503

        // ddr3 signals
        .ddr3_reset         (ddr3_sys_rst[0]),
        .init_cmptd         (c0_phy_init_done),

        // axi interface
        .s_axi_awid         (c0_axi_awid[0]),
        .s_axi_awaddr       (c0_axi_awaddr[0]), 
        .s_axi_awlen        (c0_axi_awlen[0]),  
        .s_axi_awsize       (c0_axi_awsize[0]), 
        .s_axi_awburst      (c0_axi_awburst[0]),
        .s_axi_awlock       (c0_axi_awlock[0]), 
        .s_axi_awcache      (c0_axi_awcache[0]),
        .s_axi_awprot       (c0_axi_awprot[0]), 
        .s_axi_awqos        (c0_axi_awqos[0]),  
        .s_axi_awvalid      (c0_axi_awvalid[0]),
        .s_axi_awready      (c0_axi_awready[0]),
        .s_axi_wdata        (c0_axi_wdata[0]),  
        .s_axi_wstrb        (c0_axi_wstrb[0]),  
        .s_axi_wlast        (c0_axi_wlast[0]),  
        .s_axi_wvalid       (c0_axi_wvalid[0]), 
        .s_axi_wready       (c0_axi_wready[0]), 
        .s_axi_bid          (c0_axi_bid[0]),    
        .s_axi_bresp        (c0_axi_bresp[0]),  
        .s_axi_bvalid       (c0_axi_bvalid[0]), 
        .s_axi_bready       (c0_axi_bready[0]), 
        .s_axi_arid         (c0_axi_arid[0]),   
        .s_axi_araddr       (c0_axi_araddr[0]), 
        .s_axi_arlen        (c0_axi_arlen[0]),  
        .s_axi_arsize       (c0_axi_arsize[0]), 
        .s_axi_arburst      (c0_axi_arburst[0]),
        .s_axi_arlock       (c0_axi_arlock[0]), 
        .s_axi_arcache      (c0_axi_arcache[0]),
        .s_axi_arprot       (c0_axi_arprot[0]), 
        .s_axi_arqos        (c0_axi_arqos[0]),  
        .s_axi_arvalid      (c0_axi_arvalid[0]),
        .s_axi_arready      (c0_axi_arready[0]),
        .s_axi_rid          (c0_axi_rid[0]),    
        .s_axi_rdata        (c0_axi_rdata[0]),  
        .s_axi_rresp        (c0_axi_rresp[0]),  
        .s_axi_rlast        (c0_axi_rlast[0]),  
        .s_axi_rvalid       (c0_axi_rvalid[0]), 
        .s_axi_rready       (c0_axi_rready[0])    
    );

    ////////////////////////
    // AXI Interconnect 0 //
    ////////////////////////
    // port 0 used for the host streaming but other ports are available 
    // to the user logic
    PicoAXIInterconnect #(
        .C_NUM_SLAVE_PORTS      (C0_C_S_AXI_MASTERS+1),
        .LOG_C_NUM_SLAVE_PORTS  (clogb2(C0_C_S_AXI_MASTERS+1)),
        .C_AXI_ID_WIDTH         (C0_C_S_AXI_ID_WIDTH),
        .C_AXI_ADDR_WIDTH       (C0_C_S_AXI_ADDR_WIDTH),
        .C_AXI_DATA_WIDTH       (C0_C_S_AXI_DATA_WIDTH)
    )
    interconnect_inst_0
    (
        .INTERCONNECT_ACLK      (c0_tb_clk),        // input INTERCONNECT_ACLK
        .INTERCONNECT_ARESETN   (~c0_tb_rst),       // input INTERCONNECT_ARESETN
        
        .S00_AXI_ACLK           (clk),              // input S00_AXI_ACLK
        .S00_AXI_AWID           (c0_axi_awid[0]),   // input [3 : 0] S00_AXI_AWID
        .S00_AXI_AWADDR         (c0_axi_awaddr[0]), // input [31 : 0] S00_AXI_AWADDR
        .S00_AXI_AWLEN          (c0_axi_awlen[0]),  // input [7 : 0] S00_AXI_AWLEN
        .S00_AXI_AWSIZE         (c0_axi_awsize[0]), // input [2 : 0] S00_AXI_AWSIZE
        .S00_AXI_AWBURST        (c0_axi_awburst[0]),// input [1 : 0] S00_AXI_AWBURST
        .S00_AXI_AWLOCK         (c0_axi_awlock[0]), // input S00_AXI_AWLOCK
        .S00_AXI_AWCACHE        (c0_axi_awcache[0]),// input [3 : 0] S00_AXI_AWCACHE
        .S00_AXI_AWPROT         (c0_axi_awprot[0]), // input [2 : 0] S00_AXI_AWPROT
        .S00_AXI_AWQOS          (c0_axi_awqos[0]),  // input [3 : 0] S00_AXI_AWQOS
        .S00_AXI_AWVALID        (c0_axi_awvalid[0]),// input S00_AXI_AWVALID
        .S00_AXI_AWREADY        (c0_axi_awready[0]),// output S00_AXI_AWREADY
        .S00_AXI_WDATA          (c0_axi_wdata[0]),  // input [127 : 0] S00_AXI_WDATA
        .S00_AXI_WSTRB          (c0_axi_wstrb[0]),  // input [15 : 0] S00_AXI_WSTRB
        .S00_AXI_WLAST          (c0_axi_wlast[0]),  // input S00_AXI_WLAST
        .S00_AXI_WVALID         (c0_axi_wvalid[0]), // input S00_AXI_WVALID
        .S00_AXI_WREADY         (c0_axi_wready[0]), // output S00_AXI_WREADY
        .S00_AXI_BID            (c0_axi_bid[0]),    // output [3 : 0] S00_AXI_BID
        .S00_AXI_BRESP          (c0_axi_bresp[0]),  // output [1 : 0] S00_AXI_BRESP
        .S00_AXI_BVALID         (c0_axi_bvalid[0]), // output S00_AXI_BVALID
        .S00_AXI_BREADY         (c0_axi_bready[0]), // input S00_AXI_BREADY
        .S00_AXI_ARID           (c0_axi_arid[0]),   // input [3 : 0] S00_AXI_ARID
        .S00_AXI_ARADDR         (c0_axi_araddr[0]), // input [31 : 0] S00_AXI_ARADDR
        .S00_AXI_ARLEN          (c0_axi_arlen[0]),  // input [7 : 0] S00_AXI_ARLEN
        .S00_AXI_ARSIZE         (c0_axi_arsize[0]), // input [2 : 0] S00_AXI_ARSIZE
        .S00_AXI_ARBURST        (c0_axi_arburst[0]),// input [1 : 0] S00_AXI_ARBURST
        .S00_AXI_ARLOCK         (c0_axi_arlock[0]), // input S00_AXI_ARLOCK
        .S00_AXI_ARCACHE        (c0_axi_arcache[0]),// input [3 : 0] S00_AXI_ARCACHE
        .S00_AXI_ARPROT         (c0_axi_arprot[0]), // input [2 : 0] S00_AXI_ARPROT
        .S00_AXI_ARQOS          (c0_axi_arqos[0]),  // input [3 : 0] S00_AXI_ARQOS
        .S00_AXI_ARVALID        (c0_axi_arvalid[0]),// input S00_AXI_ARVALID
        .S00_AXI_ARREADY        (c0_axi_arready[0]),// output S00_AXI_ARREADY
        .S00_AXI_RID            (c0_axi_rid[0]),    // output [3 : 0] S00_AXI_RID
        .S00_AXI_RDATA          (c0_axi_rdata[0]),  // output [127 : 0] S00_AXI_RDATA
        .S00_AXI_RRESP          (c0_axi_rresp[0]),  // output [1 : 0] S00_AXI_RRESP
        .S00_AXI_RLAST          (c0_axi_rlast[0]),  // output S00_AXI_RLAST
        .S00_AXI_RVALID         (c0_axi_rvalid[0]), // output S00_AXI_RVALID
        .S00_AXI_RREADY         (c0_axi_rready[0]), // input S00_AXI_RREADY
   `ifdef PICO_AXI_PORT_1  
        .S01_AXI_ACLK           (c0_axi_clk[1]),    // input S01_AXI_ACLK
        .S01_AXI_AWID           (c0_axi_awid[1]),   // input [3 : 0] S01_AXI_AWID
        .S01_AXI_AWADDR         (c0_axi_awaddr[1]), // input [31 : 0] S01_AXI_AWADDR
        .S01_AXI_AWLEN          (c0_axi_awlen[1]),  // input [7 : 0] S01_AXI_AWLEN
        .S01_AXI_AWSIZE         (c0_axi_awsize[1]), // input [2 : 0] S01_AXI_AWSIZE
        .S01_AXI_AWBURST        (c0_axi_awburst[1]),// input [1 : 0] S01_AXI_AWBURST
        .S01_AXI_AWLOCK         (c0_axi_awlock[1]), // input S01_AXI_AWLOCK
        .S01_AXI_AWCACHE        (c0_axi_awcache[1]),// input [3 : 0] S01_AXI_AWCACHE
        .S01_AXI_AWPROT         (c0_axi_awprot[1]), // input [2 : 0] S01_AXI_AWPROT
        .S01_AXI_AWQOS          (c0_axi_awqos[1]),  // input [3 : 0] S01_AXI_AWQOS
        .S01_AXI_AWVALID        (c0_axi_awvalid[1]),// input S01_AXI_AWVALID
        .S01_AXI_AWREADY        (c0_axi_awready[1]),// output S01_AXI_AWREADY
        .S01_AXI_WDATA          (c0_axi_wdata[1]),  // input [127 : 0] S01_AXI_WDATA
        .S01_AXI_WSTRB          (c0_axi_wstrb[1]),  // input [15 : 0] S01_AXI_WSTRB
        .S01_AXI_WLAST          (c0_axi_wlast[1]),  // input S01_AXI_WLAST
        .S01_AXI_WVALID         (c0_axi_wvalid[1]), // input S01_AXI_WVALID
        .S01_AXI_WREADY         (c0_axi_wready[1]), // output S01_AXI_WREADY
        .S01_AXI_BID            (c0_axi_bid[1]),    // output [3 : 0] S01_AXI_BID
        .S01_AXI_BRESP          (c0_axi_bresp[1]),  // output [1 : 0] S01_AXI_BRESP
        .S01_AXI_BVALID         (c0_axi_bvalid[1]), // output S01_AXI_BVALID
        .S01_AXI_BREADY         (c0_axi_bready[1]), // input S01_AXI_BREADY
        .S01_AXI_ARID           (c0_axi_arid[1]),   // input [3 : 0] S01_axi_ARID
        .S01_AXI_ARADDR         (c0_axi_araddr[1]), // input [31 : 0] S01_AXI_ARADDR
        .S01_AXI_ARLEN          (c0_axi_arlen[1]),  // input [7 : 0] S01_AXI_ARLEN
        .S01_AXI_ARSIZE         (c0_axi_arsize[1]), // input [2 : 0] S01_AXI_ARSIZE
        .S01_AXI_ARBURST        (c0_axi_arburst[1]),// input [1 : 0] S01_AXI_ARBURST
        .S01_AXI_ARLOCK         (c0_axi_arlock[1]), // input S01_AXI_ARLOCK
        .S01_AXI_ARCACHE        (c0_axi_arcache[1]),// input [3 : 0] S01_AXI_ARCACHE
        .S01_AXI_ARPROT         (c0_axi_arprot[1]), // input [2 : 0] S01_AXI_ARPROT
        .S01_AXI_ARQOS          (c0_axi_arqos[1]),  // input [3 : 0] S01_AXI_ARQOS
        .S01_AXI_ARVALID        (c0_axi_arvalid[1]),// input S01_AXI_ARVALID
        .S01_AXI_ARREADY        (c0_axi_arready[1]),// output S01_AXI_ARREADY
        .S01_AXI_RID            (c0_axi_rid[1]),    // output [3 : 0] S01_AXI_RID
        .S01_AXI_RDATA          (c0_axi_rdata[1]),  // output [127 : 0] S01_AXI_RDATA
        .S01_AXI_RRESP          (c0_axi_rresp[1]),  // output [1 : 0] S01_AXI_RRESP
        .S01_AXI_RLAST          (c0_axi_rlast[1]),  // output S01_AXI_RLAST
        .S01_AXI_RVALID         (c0_axi_rvalid[1]), // output S01_AXI_RVALID
        .S01_AXI_RREADY         (c0_axi_rready[1]), // input S01_AXI_RREADY
    `endif // PICO_AXI_PORT_1
    `ifdef PICO_AXI_PORT_2
        .S02_AXI_ACLK           (c0_axi_clk[2]),    // input S02_AXI_ACLK
        .S02_AXI_AWID           (c0_axi_awid[2]),   // input [3 : 0] S02_AXI_AWID
        .S02_AXI_AWADDR         (c0_axi_awaddr[2]), // input [31 : 0] S02_AXI_AWADDR
        .S02_AXI_AWLEN          (c0_axi_awlen[2]),  // input [7 : 0] S02_AXI_AWLEN
        .S02_AXI_AWSIZE         (c0_axi_awsize[2]), // input [2 : 0] S02_AXI_AWSIZE
        .S02_AXI_AWBURST        (c0_axi_awburst[2]),// input [1 : 0] S02_AXI_AWBURST
        .S02_AXI_AWLOCK         (c0_axi_awlock[2]), // input S02_AXI_AWLOCK
        .S02_AXI_AWCACHE        (c0_axi_awcache[2]),// input [3 : 0] S02_AXI_AWCACHE
        .S02_AXI_AWPROT         (c0_axi_awprot[2]), // input [2 : 0] S02_AXI_AWPROT
        .S02_AXI_AWQOS          (c0_axi_awqos[2]),  // input [3 : 0] S02_AXI_AWQOS
        .S02_AXI_AWVALID        (c0_axi_awvalid[2]),// input S02_AXI_AWVALID
        .S02_AXI_AWREADY        (c0_axi_awready[2]),// output S02_AXI_AWREADY
        .S02_AXI_WDATA          (c0_axi_wdata[2]),  // input [127 : 0] S02_AXI_WDATA
        .S02_AXI_WSTRB          (c0_axi_wstrb[2]),  // input [15 : 0] S02_AXI_WSTRB
        .S02_AXI_WLAST          (c0_axi_wlast[2]),  // input S02_AXI_WLAST
        .S02_AXI_WVALID         (c0_axi_wvalid[2]), // input S02_AXI_WVALID
        .S02_AXI_WREADY         (c0_axi_wready[2]), // output S02_AXI_WREADY
        .S02_AXI_BID            (c0_axi_bid[2]),    // output [3 : 0] S02_AXI_BID
        .S02_AXI_BRESP          (c0_axi_bresp[2]),  // output [1 : 0] S02_AXI_BRESP
        .S02_AXI_BVALID         (c0_axi_bvalid[2]), // output S02_AXI_BVALID
        .S02_AXI_BREADY         (c0_axi_bready[2]), // input S02_AXI_BREADY
        .S02_AXI_ARID           (c0_axi_arid[2]),   // input [3 : 0] S02_axi_ARID
        .S02_AXI_ARADDR         (c0_axi_araddr[2]), // input [31 : 0] S02_AXI_ARADDR
        .S02_AXI_ARLEN          (c0_axi_arlen[2]),  // input [7 : 0] S02_AXI_ARLEN
        .S02_AXI_ARSIZE         (c0_axi_arsize[2]), // input [2 : 0] S02_AXI_ARSIZE
        .S02_AXI_ARBURST        (c0_axi_arburst[2]),// input [1 : 0] S02_AXI_ARBURST
        .S02_AXI_ARLOCK         (c0_axi_arlock[2]), // input S02_AXI_ARLOCK
        .S02_AXI_ARCACHE        (c0_axi_arcache[2]),// input [3 : 0] S02_AXI_ARCACHE
        .S02_AXI_ARPROT         (c0_axi_arprot[2]), // input [2 : 0] S02_AXI_ARPROT
        .S02_AXI_ARQOS          (c0_axi_arqos[2]),  // input [3 : 0] S02_AXI_ARQOS
        .S02_AXI_ARVALID        (c0_axi_arvalid[2]),// input S02_AXI_ARVALID
        .S02_AXI_ARREADY        (c0_axi_arready[2]),// output S02_AXI_ARREADY
        .S02_AXI_RID            (c0_axi_rid[2]),    // output [3 : 0] S02_AXI_RID
        .S02_AXI_RDATA          (c0_axi_rdata[2]),  // output [127 : 0] S02_AXI_RDATA
        .S02_AXI_RRESP          (c0_axi_rresp[2]),  // output [1 : 0] S02_AXI_RRESP
        .S02_AXI_RLAST          (c0_axi_rlast[2]),  // output S02_AXI_RLAST
        .S02_AXI_RVALID         (c0_axi_rvalid[2]), // output S02_AXI_RVALID
        .S02_AXI_RREADY         (c0_axi_rready[2]), // input S02_AXI_RREADY
    `endif // PICO_AXI_PORT_2    
    `ifdef PICO_AXI_PORT_3
        .S03_AXI_ACLK           (c0_axi_clk[3]),    // input S03_AXI_ACLK
        .S03_AXI_AWID           (c0_axi_awid[3]),   // input [3 : 0] S03_AXI_AWID
        .S03_AXI_AWADDR         (c0_axi_awaddr[3]), // input [31 : 0] S03_AXI_AWADDR
        .S03_AXI_AWLEN          (c0_axi_awlen[3]),  // input [7 : 0] S03_AXI_AWLEN
        .S03_AXI_AWSIZE         (c0_axi_awsize[3]), // input [2 : 0] S03_AXI_AWSIZE
        .S03_AXI_AWBURST        (c0_axi_awburst[3]),// input [1 : 0] S03_AXI_AWBURST
        .S03_AXI_AWLOCK         (c0_axi_awlock[3]), // input S03_AXI_AWLOCK
        .S03_AXI_AWCACHE        (c0_axi_awcache[3]),// input [3 : 0] S03_AXI_AWCACHE
        .S03_AXI_AWPROT         (c0_axi_awprot[3]), // input [2 : 0] S03_AXI_AWPROT
        .S03_AXI_AWQOS          (c0_axi_awqos[3]),  // input [3 : 0] S03_AXI_AWQOS
        .S03_AXI_AWVALID        (c0_axi_awvalid[3]),// input S03_AXI_AWVALID
        .S03_AXI_AWREADY        (c0_axi_awready[3]),// output S03_AXI_AWREADY
        .S03_AXI_WDATA          (c0_axi_wdata[3]),  // input [127 : 0] S03_AXI_WDATA
        .S03_AXI_WSTRB          (c0_axi_wstrb[3]),  // input [15 : 0] S03_AXI_WSTRB
        .S03_AXI_WLAST          (c0_axi_wlast[3]),  // input S03_AXI_WLAST
        .S03_AXI_WVALID         (c0_axi_wvalid[3]), // input S03_AXI_WVALID
        .S03_AXI_WREADY         (c0_axi_wready[3]), // output S03_AXI_WREADY
        .S03_AXI_BID            (c0_axi_bid[3]),    // output [3 : 0] S03_AXI_BID
        .S03_AXI_BRESP          (c0_axi_bresp[3]),  // output [1 : 0] S03_AXI_BRESP
        .S03_AXI_BVALID         (c0_axi_bvalid[3]), // output S03_AXI_BVALID
        .S03_AXI_BREADY         (c0_axi_bready[3]), // input S03_AXI_BREADY
        .S03_AXI_ARID           (c0_axi_arid[3]),   // input [3 : 0] S03_axi_ARID
        .S03_AXI_ARADDR         (c0_axi_araddr[3]), // input [31 : 0] S03_AXI_ARADDR
        .S03_AXI_ARLEN          (c0_axi_arlen[3]),  // input [7 : 0] S03_AXI_ARLEN
        .S03_AXI_ARSIZE         (c0_axi_arsize[3]), // input [2 : 0] S03_AXI_ARSIZE
        .S03_AXI_ARBURST        (c0_axi_arburst[3]),// input [1 : 0] S03_AXI_ARBURST
        .S03_AXI_ARLOCK         (c0_axi_arlock[3]), // input S03_AXI_ARLOCK
        .S03_AXI_ARCACHE        (c0_axi_arcache[3]),// input [3 : 0] S03_AXI_ARCACHE
        .S03_AXI_ARPROT         (c0_axi_arprot[3]), // input [2 : 0] S03_AXI_ARPROT
        .S03_AXI_ARQOS          (c0_axi_arqos[3]),  // input [3 : 0] S03_AXI_ARQOS
        .S03_AXI_ARVALID        (c0_axi_arvalid[3]),// input S03_AXI_ARVALID
        .S03_AXI_ARREADY        (c0_axi_arready[3]),// output S03_AXI_ARREADY
        .S03_AXI_RID            (c0_axi_rid[3]),    // output [3 : 0] S03_AXI_RID
        .S03_AXI_RDATA          (c0_axi_rdata[3]),  // output [127 : 0] S03_AXI_RDATA
        .S03_AXI_RRESP          (c0_axi_rresp[3]),  // output [1 : 0] S03_AXI_RRESP
        .S03_AXI_RLAST          (c0_axi_rlast[3]),  // output S03_AXI_RLAST
        .S03_AXI_RVALID         (c0_axi_rvalid[3]), // output S03_AXI_RVALID
        .S03_AXI_RREADY         (c0_axi_rready[3]), // input S03_AXI_RREADY
    `endif // PICO_AXI_PORT_3
    `ifdef PICO_AXI_PORT_4
        .S04_AXI_ACLK           (c0_axi_clk[4]),    // input S04_AXI_ACLK
        .S04_AXI_AWID           (c0_axi_awid[4]),   // input [3 : 0] S04_AXI_AWID
        .S04_AXI_AWADDR         (c0_axi_awaddr[4]), // input [31 : 0] S04_AXI_AWADDR
        .S04_AXI_AWLEN          (c0_axi_awlen[4]),  // input [7 : 0] S04_AXI_AWLEN
        .S04_AXI_AWSIZE         (c0_axi_awsize[4]), // input [2 : 0] S04_AXI_AWSIZE
        .S04_AXI_AWBURST        (c0_axi_awburst[4]),// input [1 : 0] S04_AXI_AWBURST
        .S04_AXI_AWLOCK         (c0_axi_awlock[4]), // input S04_AXI_AWLOCK
        .S04_AXI_AWCACHE        (c0_axi_awcache[4]),// input [3 : 0] S04_AXI_AWCACHE
        .S04_AXI_AWPROT         (c0_axi_awprot[4]), // input [2 : 0] S04_AXI_AWPROT
        .S04_AXI_AWQOS          (c0_axi_awqos[4]),  // input [3 : 0] S04_AXI_AWQOS
        .S04_AXI_AWVALID        (c0_axi_awvalid[4]),// input S04_AXI_AWVALID
        .S04_AXI_AWREADY        (c0_axi_awready[4]),// output S04_AXI_AWREADY
        .S04_AXI_WDATA          (c0_axi_wdata[4]),  // input [127 : 0] S04_AXI_WDATA
        .S04_AXI_WSTRB          (c0_axi_wstrb[4]),  // input [15 : 0] S04_AXI_WSTRB
        .S04_AXI_WLAST          (c0_axi_wlast[4]),  // input S04_AXI_WLAST
        .S04_AXI_WVALID         (c0_axi_wvalid[4]), // input S04_AXI_WVALID
        .S04_AXI_WREADY         (c0_axi_wready[4]), // output S04_AXI_WREADY
        .S04_AXI_BID            (c0_axi_bid[4]),    // output [3 : 0] S04_AXI_BID
        .S04_AXI_BRESP          (c0_axi_bresp[4]),  // output [1 : 0] S04_AXI_BRESP
        .S04_AXI_BVALID         (c0_axi_bvalid[4]), // output S04_AXI_BVALID
        .S04_AXI_BREADY         (c0_axi_bready[4]), // input S04_AXI_BREADY
        .S04_AXI_ARID           (c0_axi_arid[4]),   // input [3 : 0] S04_axi_ARID
        .S04_AXI_ARADDR         (c0_axi_araddr[4]), // input [31 : 0] S04_AXI_ARADDR
        .S04_AXI_ARLEN          (c0_axi_arlen[4]),  // input [7 : 0] S04_AXI_ARLEN
        .S04_AXI_ARSIZE         (c0_axi_arsize[4]), // input [2 : 0] S04_AXI_ARSIZE
        .S04_AXI_ARBURST        (c0_axi_arburst[4]),// input [1 : 0] S04_AXI_ARBURST
        .S04_AXI_ARLOCK         (c0_axi_arlock[4]), // input S04_AXI_ARLOCK
        .S04_AXI_ARCACHE        (c0_axi_arcache[4]),// input [3 : 0] S04_AXI_ARCACHE
        .S04_AXI_ARPROT         (c0_axi_arprot[4]), // input [2 : 0] S04_AXI_ARPROT
        .S04_AXI_ARQOS          (c0_axi_arqos[4]),  // input [3 : 0] S04_AXI_ARQOS
        .S04_AXI_ARVALID        (c0_axi_arvalid[4]),// input S04_AXI_ARVALID
        .S04_AXI_ARREADY        (c0_axi_arready[4]),// output S04_AXI_ARREADY
        .S04_AXI_RID            (c0_axi_rid[4]),    // output [3 : 0] S04_AXI_RID
        .S04_AXI_RDATA          (c0_axi_rdata[4]),  // output [127 : 0] S04_AXI_RDATA
        .S04_AXI_RRESP          (c0_axi_rresp[4]),  // output [1 : 0] S04_AXI_RRESP
        .S04_AXI_RLAST          (c0_axi_rlast[4]),  // output S04_AXI_RLAST
        .S04_AXI_RVALID         (c0_axi_rvalid[4]), // output S04_AXI_RVALID
        .S04_AXI_RREADY         (c0_axi_rready[4]), // input S04_AXI_RREADY
    `endif // PICO_AXI_PORT_4
    `ifdef PICO_AXI_PORT_5  
        .S05_AXI_ACLK           (c0_axi_clk[5]),    // input S05_AXI_ACLK
        .S05_AXI_AWID           (c0_axi_awid[5]),   // input [3 : 0] S05_AXI_AWID
        .S05_AXI_AWADDR         (c0_axi_awaddr[5]), // input [31 : 0] S05_AXI_AWADDR
        .S05_AXI_AWLEN          (c0_axi_awlen[5]),  // input [7 : 0] S05_AXI_AWLEN
        .S05_AXI_AWSIZE         (c0_axi_awsize[5]), // input [2 : 0] S05_AXI_AWSIZE
        .S05_AXI_AWBURST        (c0_axi_awburst[5]),// input [1 : 0] S05_AXI_AWBURST
        .S05_AXI_AWLOCK         (c0_axi_awlock[5]), // input S05_AXI_AWLOCK
        .S05_AXI_AWCACHE        (c0_axi_awcache[5]),// input [3 : 0] S05_AXI_AWCACHE
        .S05_AXI_AWPROT         (c0_axi_awprot[5]), // input [2 : 0] S05_AXI_AWPROT
        .S05_AXI_AWQOS          (c0_axi_awqos[5]),  // input [3 : 0] S05_AXI_AWQOS
        .S05_AXI_AWVALID        (c0_axi_awvalid[5]),// input S05_AXI_AWVALID
        .S05_AXI_AWREADY        (c0_axi_awready[5]),// output S05_AXI_AWREADY
        .S05_AXI_WDATA          (c0_axi_wdata[5]),  // input [127 : 0] S05_AXI_WDATA
        .S05_AXI_WSTRB          (c0_axi_wstrb[5]),  // input [15 : 0] S05_AXI_WSTRB
        .S05_AXI_WLAST          (c0_axi_wlast[5]),  // input S05_AXI_WLAST
        .S05_AXI_WVALID         (c0_axi_wvalid[5]), // input S05_AXI_WVALID
        .S05_AXI_WREADY         (c0_axi_wready[5]), // output S05_AXI_WREADY
        .S05_AXI_BID            (c0_axi_bid[5]),    // output [3 : 0] S05_AXI_BID
        .S05_AXI_BRESP          (c0_axi_bresp[5]),  // output [1 : 0] S05_AXI_BRESP
        .S05_AXI_BVALID         (c0_axi_bvalid[5]), // output S05_AXI_BVALID
        .S05_AXI_BREADY         (c0_axi_bready[5]), // input S05_AXI_BREADY
        .S05_AXI_ARID           (c0_axi_arid[5]),   // input [3 : 0] S05_axi_ARID
        .S05_AXI_ARADDR         (c0_axi_araddr[5]), // input [31 : 0] S05_AXI_ARADDR
        .S05_AXI_ARLEN          (c0_axi_arlen[5]),  // input [7 : 0] S05_AXI_ARLEN
        .S05_AXI_ARSIZE         (c0_axi_arsize[5]), // input [2 : 0] S05_AXI_ARSIZE
        .S05_AXI_ARBURST        (c0_axi_arburst[5]),// input [1 : 0] S05_AXI_ARBURST
        .S05_AXI_ARLOCK         (c0_axi_arlock[5]), // input S05_AXI_ARLOCK
        .S05_AXI_ARCACHE        (c0_axi_arcache[5]),// input [3 : 0] S05_AXI_ARCACHE
        .S05_AXI_ARPROT         (c0_axi_arprot[5]), // input [2 : 0] S05_AXI_ARPROT
        .S05_AXI_ARQOS          (c0_axi_arqos[5]),  // input [3 : 0] S05_AXI_ARQOS
        .S05_AXI_ARVALID        (c0_axi_arvalid[5]),// input S05_AXI_ARVALID
        .S05_AXI_ARREADY        (c0_axi_arready[5]),// output S05_AXI_ARREADY
        .S05_AXI_RID            (c0_axi_rid[5]),    // output [3 : 0] S05_AXI_RID
        .S05_AXI_RDATA          (c0_axi_rdata[5]),  // output [127 : 0] S05_AXI_RDATA
        .S05_AXI_RRESP          (c0_axi_rresp[5]),  // output [1 : 0] S05_AXI_RRESP
        .S05_AXI_RLAST          (c0_axi_rlast[5]),  // output S05_AXI_RLAST
        .S05_AXI_RVALID         (c0_axi_rvalid[5]), // output S05_AXI_RVALID
        .S05_AXI_RREADY         (c0_axi_rready[5]), // input S05_AXI_RREADY
    `endif // PICO_AXI_PORT_5
    `ifdef PICO_AXI_PORT_6
        .S06_AXI_ACLK           (c0_axi_clk[6]),    // input S06_AXI_ACLK
        .S06_AXI_AWID           (c0_axi_awid[6]),   // input [3 : 0] S06_AXI_AWID
        .S06_AXI_AWADDR         (c0_axi_awaddr[6]), // input [31 : 0] S06_AXI_AWADDR
        .S06_AXI_AWLEN          (c0_axi_awlen[6]),  // input [7 : 0] S06_AXI_AWLEN
        .S06_AXI_AWSIZE         (c0_axi_awsize[6]), // input [2 : 0] S06_AXI_AWSIZE
        .S06_AXI_AWBURST        (c0_axi_awburst[6]),// input [1 : 0] S06_AXI_AWBURST
        .S06_AXI_AWLOCK         (c0_axi_awlock[6]), // input S06_AXI_AWLOCK
        .S06_AXI_AWCACHE        (c0_axi_awcache[6]),// input [3 : 0] S06_AXI_AWCACHE
        .S06_AXI_AWPROT         (c0_axi_awprot[6]), // input [2 : 0] S06_AXI_AWPROT
        .S06_AXI_AWQOS          (c0_axi_awqos[6]),  // input [3 : 0] S06_AXI_AWQOS
        .S06_AXI_AWVALID        (c0_axi_awvalid[6]),// input S06_AXI_AWVALID
        .S06_AXI_AWREADY        (c0_axi_awready[6]),// output S06_AXI_AWREADY
        .S06_AXI_WDATA          (c0_axi_wdata[6]),  // input [127 : 0] S06_AXI_WDATA
        .S06_AXI_WSTRB          (c0_axi_wstrb[6]),  // input [15 : 0] S06_AXI_WSTRB
        .S06_AXI_WLAST          (c0_axi_wlast[6]),  // input S06_AXI_WLAST
        .S06_AXI_WVALID         (c0_axi_wvalid[6]), // input S06_AXI_WVALID
        .S06_AXI_WREADY         (c0_axi_wready[6]), // output S06_AXI_WREADY
        .S06_AXI_BID            (c0_axi_bid[6]),    // output [3 : 0] S06_AXI_BID
        .S06_AXI_BRESP          (c0_axi_bresp[6]),  // output [1 : 0] S06_AXI_BRESP
        .S06_AXI_BVALID         (c0_axi_bvalid[6]), // output S06_AXI_BVALID
        .S06_AXI_BREADY         (c0_axi_bready[6]), // input S06_AXI_BREADY
        .S06_AXI_ARID           (c0_axi_arid[6]),   // input [3 : 0] S06_axi_ARID
        .S06_AXI_ARADDR         (c0_axi_araddr[6]), // input [31 : 0] S06_AXI_ARADDR
        .S06_AXI_ARLEN          (c0_axi_arlen[6]),  // input [7 : 0] S06_AXI_ARLEN
        .S06_AXI_ARSIZE         (c0_axi_arsize[6]), // input [2 : 0] S06_AXI_ARSIZE
        .S06_AXI_ARBURST        (c0_axi_arburst[6]),// input [1 : 0] S06_AXI_ARBURST
        .S06_AXI_ARLOCK         (c0_axi_arlock[6]), // input S06_AXI_ARLOCK
        .S06_AXI_ARCACHE        (c0_axi_arcache[6]),// input [3 : 0] S06_AXI_ARCACHE
        .S06_AXI_ARPROT         (c0_axi_arprot[6]), // input [2 : 0] S06_AXI_ARPROT
        .S06_AXI_ARQOS          (c0_axi_arqos[6]),  // input [3 : 0] S06_AXI_ARQOS
        .S06_AXI_ARVALID        (c0_axi_arvalid[6]),// input S06_AXI_ARVALID
        .S06_AXI_ARREADY        (c0_axi_arready[6]),// output S06_AXI_ARREADY
        .S06_AXI_RID            (c0_axi_rid[6]),    // output [3 : 0] S06_AXI_RID
        .S06_AXI_RDATA          (c0_axi_rdata[6]),  // output [127 : 0] S06_AXI_RDATA
        .S06_AXI_RRESP          (c0_axi_rresp[6]),  // output [1 : 0] S06_AXI_RRESP
        .S06_AXI_RLAST          (c0_axi_rlast[6]),  // output S06_AXI_RLAST
        .S06_AXI_RVALID         (c0_axi_rvalid[6]), // output S06_AXI_RVALID
        .S06_AXI_RREADY         (c0_axi_rready[6]), // input S06_AXI_RREADY
    `endif // PICO_AXI_PORT_6
    `ifdef PICO_AXI_PORT_7
        .S07_AXI_ACLK           (c0_axi_clk[7]),    // input S07_AXI_ACLK
        .S07_AXI_AWID           (c0_axi_awid[7]),   // input [3 : 0] S07_AXI_AWID
        .S07_AXI_AWADDR         (c0_axi_awaddr[7]), // input [31 : 0] S07_AXI_AWADDR
        .S07_AXI_AWLEN          (c0_axi_awlen[7]),  // input [7 : 0] S07_AXI_AWLEN
        .S07_AXI_AWSIZE         (c0_axi_awsize[7]), // input [2 : 0] S07_AXI_AWSIZE
        .S07_AXI_AWBURST        (c0_axi_awburst[7]),// input [1 : 0] S07_AXI_AWBURST
        .S07_AXI_AWLOCK         (c0_axi_awlock[7]), // input S07_AXI_AWLOCK
        .S07_AXI_AWCACHE        (c0_axi_awcache[7]),// input [3 : 0] S07_AXI_AWCACHE
        .S07_AXI_AWPROT         (c0_axi_awprot[7]), // input [2 : 0] S07_AXI_AWPROT
        .S07_AXI_AWQOS          (c0_axi_awqos[7]),  // input [3 : 0] S07_AXI_AWQOS
        .S07_AXI_AWVALID        (c0_axi_awvalid[7]),// input S07_AXI_AWVALID
        .S07_AXI_AWREADY        (c0_axi_awready[7]),// output S07_AXI_AWREADY
        .S07_AXI_WDATA          (c0_axi_wdata[7]),  // input [127 : 0] S07_AXI_WDATA
        .S07_AXI_WSTRB          (c0_axi_wstrb[7]),  // input [15 : 0] S07_AXI_WSTRB
        .S07_AXI_WLAST          (c0_axi_wlast[7]),  // input S07_AXI_WLAST
        .S07_AXI_WVALID         (c0_axi_wvalid[7]), // input S07_AXI_WVALID
        .S07_AXI_WREADY         (c0_axi_wready[7]), // output S07_AXI_WREADY
        .S07_AXI_BID            (c0_axi_bid[7]),    // output [3 : 0] S07_AXI_BID
        .S07_AXI_BRESP          (c0_axi_bresp[7]),  // output [1 : 0] S07_AXI_BRESP
        .S07_AXI_BVALID         (c0_axi_bvalid[7]), // output S07_AXI_BVALID
        .S07_AXI_BREADY         (c0_axi_bready[7]), // input S07_AXI_BREADY
        .S07_AXI_ARID           (c0_axi_arid[7]),   // input [3 : 0] S07_axi_ARID
        .S07_AXI_ARADDR         (c0_axi_araddr[7]), // input [31 : 0] S07_AXI_ARADDR
        .S07_AXI_ARLEN          (c0_axi_arlen[7]),  // input [7 : 0] S07_AXI_ARLEN
        .S07_AXI_ARSIZE         (c0_axi_arsize[7]), // input [2 : 0] S07_AXI_ARSIZE
        .S07_AXI_ARBURST        (c0_axi_arburst[7]),// input [1 : 0] S07_AXI_ARBURST
        .S07_AXI_ARLOCK         (c0_axi_arlock[7]), // input S07_AXI_ARLOCK
        .S07_AXI_ARCACHE        (c0_axi_arcache[7]),// input [3 : 0] S07_AXI_ARCACHE
        .S07_AXI_ARPROT         (c0_axi_arprot[7]), // input [2 : 0] S07_AXI_ARPROT
        .S07_AXI_ARQOS          (c0_axi_arqos[7]),  // input [3 : 0] S07_AXI_ARQOS
        .S07_AXI_ARVALID        (c0_axi_arvalid[7]),// input S07_AXI_ARVALID
        .S07_AXI_ARREADY        (c0_axi_arready[7]),// output S07_AXI_ARREADY
        .S07_AXI_RID            (c0_axi_rid[7]),    // output [3 : 0] S07_AXI_RID
        .S07_AXI_RDATA          (c0_axi_rdata[7]),  // output [127 : 0] S07_AXI_RDATA
        .S07_AXI_RRESP          (c0_axi_rresp[7]),  // output [1 : 0] S07_AXI_RRESP
        .S07_AXI_RLAST          (c0_axi_rlast[7]),  // output S07_AXI_RLAST
        .S07_AXI_RVALID         (c0_axi_rvalid[7]), // output S07_AXI_RVALID
        .S07_AXI_RREADY         (c0_axi_rready[7]), // input S07_AXI_RREADY
    `endif // PICO_AXI_PORT_7
        .M00_AXI_ACLK           (c0_tb_clk),        // input M00_AXI_ACLK
        .M00_AXI_AWID           (c0_s_axi_awid),    // output [7 : 0] M00_AXI_AWID
        .M00_AXI_AWADDR         (c0_s_axi_awaddr),  // output [31 : 0] M00_AXI_AWADDR
        .M00_AXI_AWLEN          (c0_s_axi_awlen),   // output [7 : 0] M00_AXI_AWLEN
        .M00_AXI_AWSIZE         (c0_s_axi_awsize),  // output [2 : 0] M00_AXI_AWSIZE
        .M00_AXI_AWBURST        (c0_s_axi_awburst), // output [1 : 0] M00_AXI_AWBURST
        .M00_AXI_AWLOCK         (c0_s_axi_awlock),  // output M00_AXI_AWLOCK
        .M00_AXI_AWCACHE        (c0_s_axi_awcache), // output [3 : 0] M00_AXI_AWCACHE
        .M00_AXI_AWPROT         (c0_s_axi_awprot),  // output [2 : 0] M00_AXI_AWPROT
        .M00_AXI_AWQOS          (c0_s_axi_awqos),   // output [3 : 0] M00_AXI_AWQOS
        .M00_AXI_AWVALID        (c0_s_axi_awvalid), // output M00_AXI_AWVALID
        .M00_AXI_AWREADY        (c0_s_axi_awready), // input M00_AXI_AWREADY
        .M00_AXI_WDATA          (c0_s_axi_wdata),   // output [127 : 0] M00_AXI_WDATA
        .M00_AXI_WSTRB          (c0_s_axi_wstrb),   // output [15 : 0] M00_AXI_WSTRB
        .M00_AXI_WLAST          (c0_s_axi_wlast),   // output M00_AXI_WLAST
        .M00_AXI_WVALID         (c0_s_axi_wvalid),  // output M00_AXI_WVALID
        .M00_AXI_WREADY         (c0_s_axi_wready),  // input M00_AXI_WREADY
        .M00_AXI_BID            (c0_s_axi_bid),     // input [7 : 0] M00_AXI_BID
        .M00_AXI_BRESP          (c0_s_axi_bresp),   // input [1 : 0] M00_AXI_BRESP
        .M00_AXI_BVALID         (c0_s_axi_bvalid),  // input M00_AXI_BVALID
        .M00_AXI_BREADY         (c0_s_axi_bready),  // output M00_AXI_BREADY
        .M00_AXI_ARID           (c0_s_axi_arid),    // output [7 : 0] M00_AXI_ARID
        .M00_AXI_ARADDR         (c0_s_axi_araddr),  // output [31 : 0] M00_AXI_ARADDR
        .M00_AXI_ARLEN          (c0_s_axi_arlen),   // output [7 : 0] M00_AXI_ARLEN
        .M00_AXI_ARSIZE         (c0_s_axi_arsize),  // output [2 : 0] M00_AXI_ARSIZE
        .M00_AXI_ARBURST        (c0_s_axi_arburst), // output [1 : 0] M00_AXI_ARBURST
        .M00_AXI_ARLOCK         (c0_s_axi_arlock),  // output M00_AXI_ARLOCK
        .M00_AXI_ARCACHE        (c0_s_axi_arcache), // output [3 : 0] M00_AXI_ARCACHE
        .M00_AXI_ARPROT         (c0_s_axi_arprot),  // output [2 : 0] M00_AXI_ARPROT
        .M00_AXI_ARQOS          (c0_s_axi_arqos),   // output [3 : 0] M00_AXI_ARQOS
        .M00_AXI_ARVALID        (c0_s_axi_arvalid), // output M00_AXI_ARVALID
        .M00_AXI_ARREADY        (c0_s_axi_arready), // input M00_AXI_ARREADY
        .M00_AXI_RID            (c0_s_axi_rid),     // input [7 : 0] M00_AXI_RID
        .M00_AXI_RDATA          (c0_s_axi_rdata),   // input [127 : 0] M00_AXI_RDATA
        .M00_AXI_RRESP          (c0_s_axi_rresp),   // input [1 : 0] M00_AXI_RRESP
        .M00_AXI_RLAST          (c0_s_axi_rlast),   // input M00_AXI_RLAST
        .M00_AXI_RVALID         (c0_s_axi_rvalid),  // input M00_AXI_RVALID
        .M00_AXI_RREADY         (c0_s_axi_rready)   // output M00_AXI_RREADY
    ); // AXI interconnect instance

`ifdef PICO_MODEL_M503
    ////////////////
    // DDR3 MIG 1 //
    ////////////////

    // Slave Interface Wires 
    wire    [C1_C_S_AXI_MASTERS:0]          c1_axi_clk;

    // Slave Interface Write Address Ports
    wire    [C1_C_S_AXI_ID_WIDTH-5:0]       c1_axi_awid    [0:C1_C_S_AXI_MASTERS];
    wire    [C1_C_S_AXI_ADDR_WIDTH-1:0]     c1_axi_awaddr  [0:C1_C_S_AXI_MASTERS]; 
    wire    [7:0]                           c1_axi_awlen   [0:C1_C_S_AXI_MASTERS];
    wire    [2:0]                           c1_axi_awsize  [0:C1_C_S_AXI_MASTERS]; 
    wire    [1:0]                           c1_axi_awburst [0:C1_C_S_AXI_MASTERS]; 
    wire    [0:0]                           c1_axi_awlock  [0:C1_C_S_AXI_MASTERS];
    wire    [3:0]                           c1_axi_awcache [0:C1_C_S_AXI_MASTERS]; 
    wire    [2:0]                           c1_axi_awprot  [0:C1_C_S_AXI_MASTERS]; 
    wire    [3:0]                           c1_axi_awqos   [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_awvalid [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_awready [0:C1_C_S_AXI_MASTERS]; 
    // Slave Interface Write Data Ports
    wire    [C1_C_S_AXI_DATA_WIDTH-1:0]     c1_axi_wdata   [0:C1_C_S_AXI_MASTERS];
    wire    [C1_C_S_AXI_DATA_WIDTH/8-1:0]   c1_axi_wstrb   [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_wlast   [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_wvalid  [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_wready  [0:C1_C_S_AXI_MASTERS]; 
    // Slave Interface Write Response Ports
    wire    [C1_C_S_AXI_ID_WIDTH-5:0]       c1_axi_bid     [0:C1_C_S_AXI_MASTERS];
    wire    [1:0]                           c1_axi_bresp   [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_bvalid  [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_bready  [0:C1_C_S_AXI_MASTERS]; 
    // Slave Interface Read Address Ports
    wire    [C1_C_S_AXI_ID_WIDTH-5:0]       c1_axi_arid    [0:C1_C_S_AXI_MASTERS]; 
    wire    [C1_C_S_AXI_ADDR_WIDTH-1:0]     c1_axi_araddr  [0:C1_C_S_AXI_MASTERS]; 
    wire    [7:0]                           c1_axi_arlen   [0:C1_C_S_AXI_MASTERS];
    wire    [2:0]                           c1_axi_arsize  [0:C1_C_S_AXI_MASTERS]; 
    wire    [1:0]                           c1_axi_arburst [0:C1_C_S_AXI_MASTERS]; 
    wire    [0:0]                           c1_axi_arlock  [0:C1_C_S_AXI_MASTERS];
    wire    [3:0]                           c1_axi_arcache [0:C1_C_S_AXI_MASTERS]; 
    wire    [2:0]                           c1_axi_arprot  [0:C1_C_S_AXI_MASTERS];
    wire    [3:0]                           c1_axi_arqos   [0:C1_C_S_AXI_MASTERS];
    wire                                    c1_axi_arvalid [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_arready [0:C1_C_S_AXI_MASTERS]; 
    // Slave Interface Read Data Ports
    wire    [C1_C_S_AXI_ID_WIDTH-5:0]       c1_axi_rid     [0:C1_C_S_AXI_MASTERS];
    wire    [C1_C_S_AXI_DATA_WIDTH-1:0]     c1_axi_rdata   [0:C1_C_S_AXI_MASTERS]; 
    wire    [1:0]                           c1_axi_rresp   [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_rlast   [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_rvalid  [0:C1_C_S_AXI_MASTERS]; 
    wire                                    c1_axi_rready  [0:C1_C_S_AXI_MASTERS]; 

    /////////////////////////
    // Stream Controller 1 //
    /////////////////////////
    // host streaming interface sits on port 0 of the axi interconnect
    PicoStreamToAXI #(
        .C_AXI_ID_WIDTH     (C1_C_S_AXI_ID_WIDTH-4), 
        .C_AXI_ADDR_WIDTH   (C1_C_S_AXI_ADDR_WIDTH),
        .STREAM_DATA_WIDTH  (128),
        .UPSIZE_RATIO       (C1_C_S_AXI_DATA_WIDTH/128),
        .LOG_UPSIZE_RATIO   (clogb2(C1_C_S_AXI_DATA_WIDTH/128))
    ) 
    stream_to_mem_1
    (
        // streaming interface
        .clk                (clk),
        .rst                (rst),
        .si_ready           (stream_in_rdy[`DDR3_STREAM_ID_1]),
        .si_valid           (stream_in_valid[`DDR3_STREAM_ID_1]),
        .si_data            (stream_in_data[`DDR3_STREAM_ID_1]),
        .so_ready           (stream_out_rdy[`DDR3_STREAM_ID_1]),
        .so_valid           (stream_out_valid[`DDR3_STREAM_ID_1]),
        .so_data            (stream_out_data[`DDR3_STREAM_ID_1]),

        // ddr3 signals
        .ddr3_reset         (ddr3_sys_rst[1]),
        .init_cmptd         (c1_phy_init_done),

        // axi interface
        .s_axi_awid         (c1_axi_awid[0]),
        .s_axi_awaddr       (c1_axi_awaddr[0]),    
        .s_axi_awlen        (c1_axi_awlen[0]),     
        .s_axi_awsize       (c1_axi_awsize[0]),    
        .s_axi_awburst      (c1_axi_awburst[0]),   
        .s_axi_awlock       (c1_axi_awlock[0]),    
        .s_axi_awcache      (c1_axi_awcache[0]),   
        .s_axi_awprot       (c1_axi_awprot[0]),    
        .s_axi_awqos        (c1_axi_awqos[0]),     
        .s_axi_awvalid      (c1_axi_awvalid[0]),   
        .s_axi_awready      (c1_axi_awready[0]),   
        .s_axi_wdata        (c1_axi_wdata[0]),     
        .s_axi_wstrb        (c1_axi_wstrb[0]),     
        .s_axi_wlast        (c1_axi_wlast[0]),     
        .s_axi_wvalid       (c1_axi_wvalid[0]),    
        .s_axi_wready       (c1_axi_wready[0]),    
        .s_axi_bid          (c1_axi_bid[0]),       
        .s_axi_bresp        (c1_axi_bresp[0]),     
        .s_axi_bvalid       (c1_axi_bvalid[0]),    
        .s_axi_bready       (c1_axi_bready[0]),    
        .s_axi_arid         (c1_axi_arid[0]),      
        .s_axi_araddr       (c1_axi_araddr[0]),    
        .s_axi_arlen        (c1_axi_arlen[0]),     
        .s_axi_arsize       (c1_axi_arsize[0]),    
        .s_axi_arburst      (c1_axi_arburst[0]),   
        .s_axi_arlock       (c1_axi_arlock[0]),    
        .s_axi_arcache      (c1_axi_arcache[0]),   
        .s_axi_arprot       (c1_axi_arprot[0]),    
        .s_axi_arqos        (c1_axi_arqos[0]),     
        .s_axi_arvalid      (c1_axi_arvalid[0]),   
        .s_axi_arready      (c1_axi_arready[0]),   
        .s_axi_rid          (c1_axi_rid[0]),       
        .s_axi_rdata        (c1_axi_rdata[0]),     
        .s_axi_rresp        (c1_axi_rresp[0]),     
        .s_axi_rlast        (c1_axi_rlast[0]),     
        .s_axi_rvalid       (c1_axi_rvalid[0]),    
        .s_axi_rready       (c1_axi_rready[0])    
    );

    // port 0 used for the host streaming but other ports are available 
    // to the user logic
    PicoAXIInterconnect #(
        .C_NUM_SLAVE_PORTS      (C1_C_S_AXI_MASTERS+1),
        .LOG_C_NUM_SLAVE_PORTS  (clogb2(C1_C_S_AXI_MASTERS+1)),
        .C_AXI_ID_WIDTH         (C1_C_S_AXI_ID_WIDTH),
        .C_AXI_ADDR_WIDTH       (C1_C_S_AXI_ADDR_WIDTH),
        .C_AXI_DATA_WIDTH       (C1_C_S_AXI_DATA_WIDTH)
    )
    interconnect_inst_1 
    (
        .INTERCONNECT_ACLK      (c1_tb_clk),        // input INTERCONNECT_ACLK
        .INTERCONNECT_ARESETN   (~c1_tb_rst),       // input INTERCONNECT_ARESETN
        
        .S00_AXI_ACLK           (clk),              // input S00_AXI_ACLK
        .S00_AXI_AWID           (c1_axi_awid[0]),   // input [3 : 0] S00_AXI_AWID
        .S00_AXI_AWADDR         (c1_axi_awaddr[0]), // input [31 : 0] S00_AXI_AWADDR
        .S00_AXI_AWLEN          (c1_axi_awlen[0]),  // input [7 : 0] S00_AXI_AWLEN
        .S00_AXI_AWSIZE         (c1_axi_awsize[0]), // input [2 : 0] S00_AXI_AWSIZE
        .S00_AXI_AWBURST        (c1_axi_awburst[0]),// input [1 : 0] S00_AXI_AWBURST
        .S00_AXI_AWLOCK         (c1_axi_awlock[0]), // input S00_AXI_AWLOCK
        .S00_AXI_AWCACHE        (c1_axi_awcache[0]),// input [3 : 0] S00_AXI_AWCACHE
        .S00_AXI_AWPROT         (c1_axi_awprot[0]), // input [2 : 0] S00_AXI_AWPROT
        .S00_AXI_AWQOS          (c1_axi_awqos[0]),  // input [3 : 0] S00_AXI_AWQOS
        .S00_AXI_AWVALID        (c1_axi_awvalid[0]),// input S00_AXI_AWVALID
        .S00_AXI_AWREADY        (c1_axi_awready[0]),// output S00_AXI_AWREADY
        .S00_AXI_WDATA          (c1_axi_wdata[0]),  // input [127 : 0] S00_AXI_WDATA
        .S00_AXI_WSTRB          (c1_axi_wstrb[0]),  // input [15 : 0] S00_AXI_WSTRB
        .S00_AXI_WLAST          (c1_axi_wlast[0]),  // input S00_AXI_WLAST
        .S00_AXI_WVALID         (c1_axi_wvalid[0]), // input S00_AXI_WVALID
        .S00_AXI_WREADY         (c1_axi_wready[0]), // output S00_AXI_WREADY
        .S00_AXI_BID            (c1_axi_bid[0]),    // output [3 : 0] S00_AXI_BID
        .S00_AXI_BRESP          (c1_axi_bresp[0]),  // output [1 : 0] S00_AXI_BRESP
        .S00_AXI_BVALID         (c1_axi_bvalid[0]), // output S00_AXI_BVALID
        .S00_AXI_BREADY         (c1_axi_bready[0]), // input S00_AXI_BREADY
        .S00_AXI_ARID           (c1_axi_arid[0]),   // input [3 : 0] S00_AXI_ARID
        .S00_AXI_ARADDR         (c1_axi_araddr[0]), // input [31 : 0] S00_AXI_ARADDR
        .S00_AXI_ARLEN          (c1_axi_arlen[0]),  // input [7 : 0] S00_AXI_ARLEN
        .S00_AXI_ARSIZE         (c1_axi_arsize[0]), // input [2 : 0] S00_AXI_ARSIZE
        .S00_AXI_ARBURST        (c1_axi_arburst[0]),// input [1 : 0] S00_AXI_ARBURST
        .S00_AXI_ARLOCK         (c1_axi_arlock[0]), // input S00_AXI_ARLOCK
        .S00_AXI_ARCACHE        (c1_axi_arcache[0]),// input [3 : 0] S00_AXI_ARCACHE
        .S00_AXI_ARPROT         (c1_axi_arprot[0]), // input [2 : 0] S00_AXI_ARPROT
        .S00_AXI_ARQOS          (c1_axi_arqos[0]),  // input [3 : 0] S00_AXI_ARQOS
        .S00_AXI_ARVALID        (c1_axi_arvalid[0]),// input S00_AXI_ARVALID
        .S00_AXI_ARREADY        (c1_axi_arready[0]),// output S00_AXI_ARREADY
        .S00_AXI_RID            (c1_axi_rid[0]),    // output [3 : 0] S00_AXI_RID
        .S00_AXI_RDATA          (c1_axi_rdata[0]),  // output [127 : 0] S00_AXI_RDATA
        .S00_AXI_RRESP          (c1_axi_rresp[0]),  // output [1 : 0] S00_AXI_RRESP
        .S00_AXI_RLAST          (c1_axi_rlast[0]),  // output S00_AXI_RLAST
        .S00_AXI_RVALID         (c1_axi_rvalid[0]), // output S00_AXI_RVALID
        .S00_AXI_RREADY         (c1_axi_rready[0]), // input S00_AXI_RREADY
    `ifdef PICO_AXI_PORT_1
        .S01_AXI_ACLK           (c1_axi_clk[1]),    // input S01_AXI_ACLK
        .S01_AXI_AWID           (c1_axi_awid[1]),   // input [3 : 0] S01_AXI_AWID
        .S01_AXI_AWADDR         (c1_axi_awaddr[1]), // input [31 : 0] S01_AXI_AWADDR
        .S01_AXI_AWLEN          (c1_axi_awlen[1]),  // input [7 : 0] S01_AXI_AWLEN
        .S01_AXI_AWSIZE         (c1_axi_awsize[1]), // input [2 : 0] S01_AXI_AWSIZE
        .S01_AXI_AWBURST        (c1_axi_awburst[1]),// input [1 : 0] S01_AXI_AWBURST
        .S01_AXI_AWLOCK         (c1_axi_awlock[1]), // input S01_AXI_AWLOCK
        .S01_AXI_AWCACHE        (c1_axi_awcache[1]),// input [3 : 0] S01_AXI_AWCACHE
        .S01_AXI_AWPROT         (c1_axi_awprot[1]), // input [2 : 0] S01_AXI_AWPROT
        .S01_AXI_AWQOS          (c1_axi_awqos[1]),  // input [3 : 0] S01_AXI_AWQOS
        .S01_AXI_AWVALID        (c1_axi_awvalid[1]),// input S01_AXI_AWVALID
        .S01_AXI_AWREADY        (c1_axi_awready[1]),// output S01_AXI_AWREADY
        .S01_AXI_WDATA          (c1_axi_wdata[1]),  // input [127 : 0] S01_AXI_WDATA
        .S01_AXI_WSTRB          (c1_axi_wstrb[1]),  // input [15 : 0] S01_AXI_WSTRB
        .S01_AXI_WLAST          (c1_axi_wlast[1]),  // input S01_AXI_WLAST
        .S01_AXI_WVALID         (c1_axi_wvalid[1]), // input S01_AXI_WVALID
        .S01_AXI_WREADY         (c1_axi_wready[1]), // output S01_AXI_WREADY
        .S01_AXI_BID            (c1_axi_bid[1]),    // output [3 : 0] S01_AXI_BID
        .S01_AXI_BRESP          (c1_axi_bresp[1]),  // output [1 : 0] S01_AXI_BRESP
        .S01_AXI_BVALID         (c1_axi_bvalid[1]), // output S01_AXI_BVALID
        .S01_AXI_BREADY         (c1_axi_bready[1]), // input S01_AXI_BREADY
        .S01_AXI_ARID           (c1_axi_arid[1]),   // input [3 : 0] S01_axi_ARID
        .S01_AXI_ARADDR         (c1_axi_araddr[1]), // input [31 : 0] S01_AXI_ARADDR
        .S01_AXI_ARLEN          (c1_axi_arlen[1]),  // input [7 : 0] S01_AXI_ARLEN
        .S01_AXI_ARSIZE         (c1_axi_arsize[1]), // input [2 : 0] S01_AXI_ARSIZE
        .S01_AXI_ARBURST        (c1_axi_arburst[1]),// input [1 : 0] S01_AXI_ARBURST
        .S01_AXI_ARLOCK         (c1_axi_arlock[1]), // input S01_AXI_ARLOCK
        .S01_AXI_ARCACHE        (c1_axi_arcache[1]),// input [3 : 0] S01_AXI_ARCACHE
        .S01_AXI_ARPROT         (c1_axi_arprot[1]), // input [2 : 0] S01_AXI_ARPROT
        .S01_AXI_ARQOS          (c1_axi_arqos[1]),  // input [3 : 0] S01_AXI_ARQOS
        .S01_AXI_ARVALID        (c1_axi_arvalid[1]),// input S01_AXI_ARVALID
        .S01_AXI_ARREADY        (c1_axi_arready[1]),// output S01_AXI_ARREADY
        .S01_AXI_RID            (c1_axi_rid[1]),    // output [3 : 0] S01_AXI_RID
        .S01_AXI_RDATA          (c1_axi_rdata[1]),  // output [127 : 0] S01_AXI_RDATA
        .S01_AXI_RRESP          (c1_axi_rresp[1]),  // output [1 : 0] S01_AXI_RRESP
        .S01_AXI_RLAST          (c1_axi_rlast[1]),  // output S01_AXI_RLAST
        .S01_AXI_RVALID         (c1_axi_rvalid[1]), // output S01_AXI_RVALID
        .S01_AXI_RREADY         (c1_axi_rready[1]), // input S01_AXI_RREADY
    `endif // PICO_AXI_PORT_1
    `ifdef PICO_AXI_PORT_2
        .S02_AXI_ACLK           (c1_axi_clk[2]),    // input S02_AXI_ACLK
        .S02_AXI_AWID           (c1_axi_awid[2]),   // input [3 : 0] S02_AXI_AWID
        .S02_AXI_AWADDR         (c1_axi_awaddr[2]), // input [31 : 0] S02_AXI_AWADDR
        .S02_AXI_AWLEN          (c1_axi_awlen[2]),  // input [7 : 0] S02_AXI_AWLEN
        .S02_AXI_AWSIZE         (c1_axi_awsize[2]), // input [2 : 0] S02_AXI_AWSIZE
        .S02_AXI_AWBURST        (c1_axi_awburst[2]),// input [1 : 0] S02_AXI_AWBURST
        .S02_AXI_AWLOCK         (c1_axi_awlock[2]), // input S02_AXI_AWLOCK
        .S02_AXI_AWCACHE        (c1_axi_awcache[2]),// input [3 : 0] S02_AXI_AWCACHE
        .S02_AXI_AWPROT         (c1_axi_awprot[2]), // input [2 : 0] S02_AXI_AWPROT
        .S02_AXI_AWQOS          (c1_axi_awqos[2]),  // input [3 : 0] S02_AXI_AWQOS
        .S02_AXI_AWVALID        (c1_axi_awvalid[2]),// input S02_AXI_AWVALID
        .S02_AXI_AWREADY        (c1_axi_awready[2]),// output S02_AXI_AWREADY
        .S02_AXI_WDATA          (c1_axi_wdata[2]),  // input [127 : 0] S02_AXI_WDATA
        .S02_AXI_WSTRB          (c1_axi_wstrb[2]),  // input [15 : 0] S02_AXI_WSTRB
        .S02_AXI_WLAST          (c1_axi_wlast[2]),  // input S02_AXI_WLAST
        .S02_AXI_WVALID         (c1_axi_wvalid[2]), // input S02_AXI_WVALID
        .S02_AXI_WREADY         (c1_axi_wready[2]), // output S02_AXI_WREADY
        .S02_AXI_BID            (c1_axi_bid[2]),    // output [3 : 0] S02_AXI_BID
        .S02_AXI_BRESP          (c1_axi_bresp[2]),  // output [1 : 0] S02_AXI_BRESP
        .S02_AXI_BVALID         (c1_axi_bvalid[2]), // output S02_AXI_BVALID
        .S02_AXI_BREADY         (c1_axi_bready[2]), // input S02_AXI_BREADY
        .S02_AXI_ARID           (c1_axi_arid[2]),   // input [3 : 0] S02_axi_ARID
        .S02_AXI_ARADDR         (c1_axi_araddr[2]), // input [31 : 0] S02_AXI_ARADDR
        .S02_AXI_ARLEN          (c1_axi_arlen[2]),  // input [7 : 0] S02_AXI_ARLEN
        .S02_AXI_ARSIZE         (c1_axi_arsize[2]), // input [2 : 0] S02_AXI_ARSIZE
        .S02_AXI_ARBURST        (c1_axi_arburst[2]),// input [1 : 0] S02_AXI_ARBURST
        .S02_AXI_ARLOCK         (c1_axi_arlock[2]), // input S02_AXI_ARLOCK
        .S02_AXI_ARCACHE        (c1_axi_arcache[2]),// input [3 : 0] S02_AXI_ARCACHE
        .S02_AXI_ARPROT         (c1_axi_arprot[2]), // input [2 : 0] S02_AXI_ARPROT
        .S02_AXI_ARQOS          (c1_axi_arqos[2]),  // input [3 : 0] S02_AXI_ARQOS
        .S02_AXI_ARVALID        (c1_axi_arvalid[2]),// input S02_AXI_ARVALID
        .S02_AXI_ARREADY        (c1_axi_arready[2]),// output S02_AXI_ARREADY
        .S02_AXI_RID            (c1_axi_rid[2]),    // output [3 : 0] S02_AXI_RID
        .S02_AXI_RDATA          (c1_axi_rdata[2]),  // output [127 : 0] S02_AXI_RDATA
        .S02_AXI_RRESP          (c1_axi_rresp[2]),  // output [1 : 0] S02_AXI_RRESP
        .S02_AXI_RLAST          (c1_axi_rlast[2]),  // output S02_AXI_RLAST
        .S02_AXI_RVALID         (c1_axi_rvalid[2]), // output S02_AXI_RVALID
        .S02_AXI_RREADY         (c1_axi_rready[2]), // input S02_AXI_RREADY
    `endif // PICO_AXI_PORT_2
    `ifdef PICO_AXI_PORT_3
        .S03_AXI_ACLK           (c1_axi_clk[3]),    // input S03_AXI_ACLK
        .S03_AXI_AWID           (c1_axi_awid[3]),   // input [3 : 0] S03_AXI_AWID
        .S03_AXI_AWADDR         (c1_axi_awaddr[3]), // input [31 : 0] S03_AXI_AWADDR
        .S03_AXI_AWLEN          (c1_axi_awlen[3]),  // input [7 : 0] S03_AXI_AWLEN
        .S03_AXI_AWSIZE         (c1_axi_awsize[3]), // input [2 : 0] S03_AXI_AWSIZE
        .S03_AXI_AWBURST        (c1_axi_awburst[3]),// input [1 : 0] S03_AXI_AWBURST
        .S03_AXI_AWLOCK         (c1_axi_awlock[3]), // input S03_AXI_AWLOCK
        .S03_AXI_AWCACHE        (c1_axi_awcache[3]),// input [3 : 0] S03_AXI_AWCACHE
        .S03_AXI_AWPROT         (c1_axi_awprot[3]), // input [2 : 0] S03_AXI_AWPROT
        .S03_AXI_AWQOS          (c1_axi_awqos[3]),  // input [3 : 0] S03_AXI_AWQOS
        .S03_AXI_AWVALID        (c1_axi_awvalid[3]),// input S03_AXI_AWVALID
        .S03_AXI_AWREADY        (c1_axi_awready[3]),// output S03_AXI_AWREADY
        .S03_AXI_WDATA          (c1_axi_wdata[3]),  // input [127 : 0] S03_AXI_WDATA
        .S03_AXI_WSTRB          (c1_axi_wstrb[3]),  // input [15 : 0] S03_AXI_WSTRB
        .S03_AXI_WLAST          (c1_axi_wlast[3]),  // input S03_AXI_WLAST
        .S03_AXI_WVALID         (c1_axi_wvalid[3]), // input S03_AXI_WVALID
        .S03_AXI_WREADY         (c1_axi_wready[3]), // output S03_AXI_WREADY
        .S03_AXI_BID            (c1_axi_bid[3]),    // output [3 : 0] S03_AXI_BID
        .S03_AXI_BRESP          (c1_axi_bresp[3]),  // output [1 : 0] S03_AXI_BRESP
        .S03_AXI_BVALID         (c1_axi_bvalid[3]), // output S03_AXI_BVALID
        .S03_AXI_BREADY         (c1_axi_bready[3]), // input S03_AXI_BREADY
        .S03_AXI_ARID           (c1_axi_arid[3]),   // input [3 : 0] S03_axi_ARID
        .S03_AXI_ARADDR         (c1_axi_araddr[3]), // input [31 : 0] S03_AXI_ARADDR
        .S03_AXI_ARLEN          (c1_axi_arlen[3]),  // input [7 : 0] S03_AXI_ARLEN
        .S03_AXI_ARSIZE         (c1_axi_arsize[3]), // input [2 : 0] S03_AXI_ARSIZE
        .S03_AXI_ARBURST        (c1_axi_arburst[3]),// input [1 : 0] S03_AXI_ARBURST
        .S03_AXI_ARLOCK         (c1_axi_arlock[3]), // input S03_AXI_ARLOCK
        .S03_AXI_ARCACHE        (c1_axi_arcache[3]),// input [3 : 0] S03_AXI_ARCACHE
        .S03_AXI_ARPROT         (c1_axi_arprot[3]), // input [2 : 0] S03_AXI_ARPROT
        .S03_AXI_ARQOS          (c1_axi_arqos[3]),  // input [3 : 0] S03_AXI_ARQOS
        .S03_AXI_ARVALID        (c1_axi_arvalid[3]),// input S03_AXI_ARVALID
        .S03_AXI_ARREADY        (c1_axi_arready[3]),// output S03_AXI_ARREADY
        .S03_AXI_RID            (c1_axi_rid[3]),    // output [3 : 0] S03_AXI_RID
        .S03_AXI_RDATA          (c1_axi_rdata[3]),  // output [127 : 0] S03_AXI_RDATA
        .S03_AXI_RRESP          (c1_axi_rresp[3]),  // output [1 : 0] S03_AXI_RRESP
        .S03_AXI_RLAST          (c1_axi_rlast[3]),  // output S03_AXI_RLAST
        .S03_AXI_RVALID         (c1_axi_rvalid[3]), // output S03_AXI_RVALID
        .S03_AXI_RREADY         (c1_axi_rready[3]), // input S03_AXI_RREADY
    `endif // PICO_AXI_PORT_3 
    `ifdef PICO_AXI_PORT_4
        .S04_AXI_ACLK           (c1_axi_clk[4]),    // input S04_AXI_ACLK
        .S04_AXI_AWID           (c1_axi_awid[4]),   // input [3 : 0] S04_AXI_AWID
        .S04_AXI_AWADDR         (c1_axi_awaddr[4]), // input [31 : 0] S04_AXI_AWADDR
        .S04_AXI_AWLEN          (c1_axi_awlen[4]),  // input [7 : 0] S04_AXI_AWLEN
        .S04_AXI_AWSIZE         (c1_axi_awsize[4]), // input [2 : 0] S04_AXI_AWSIZE
        .S04_AXI_AWBURST        (c1_axi_awburst[4]),// input [1 : 0] S04_AXI_AWBURST
        .S04_AXI_AWLOCK         (c1_axi_awlock[4]), // input S04_AXI_AWLOCK
        .S04_AXI_AWCACHE        (c1_axi_awcache[4]),// input [3 : 0] S04_AXI_AWCACHE
        .S04_AXI_AWPROT         (c1_axi_awprot[4]), // input [2 : 0] S04_AXI_AWPROT
        .S04_AXI_AWQOS          (c1_axi_awqos[4]),  // input [3 : 0] S04_AXI_AWQOS
        .S04_AXI_AWVALID        (c1_axi_awvalid[4]),// input S04_AXI_AWVALID
        .S04_AXI_AWREADY        (c1_axi_awready[4]),// output S04_AXI_AWREADY
        .S04_AXI_WDATA          (c1_axi_wdata[4]),  // input [127 : 0] S04_AXI_WDATA
        .S04_AXI_WSTRB          (c1_axi_wstrb[4]),  // input [15 : 0] S04_AXI_WSTRB
        .S04_AXI_WLAST          (c1_axi_wlast[4]),  // input S04_AXI_WLAST
        .S04_AXI_WVALID         (c1_axi_wvalid[4]), // input S04_AXI_WVALID
        .S04_AXI_WREADY         (c1_axi_wready[4]), // output S04_AXI_WREADY
        .S04_AXI_BID            (c1_axi_bid[4]),    // output [3 : 0] S04_AXI_BID
        .S04_AXI_BRESP          (c1_axi_bresp[4]),  // output [1 : 0] S04_AXI_BRESP
        .S04_AXI_BVALID         (c1_axi_bvalid[4]), // output S04_AXI_BVALID
        .S04_AXI_BREADY         (c1_axi_bready[4]), // input S04_AXI_BREADY
        .S04_AXI_ARID           (c1_axi_arid[4]),   // input [3 : 0] S04_axi_ARID
        .S04_AXI_ARADDR         (c1_axi_araddr[4]), // input [31 : 0] S04_AXI_ARADDR
        .S04_AXI_ARLEN          (c1_axi_arlen[4]),  // input [7 : 0] S04_AXI_ARLEN
        .S04_AXI_ARSIZE         (c1_axi_arsize[4]), // input [2 : 0] S04_AXI_ARSIZE
        .S04_AXI_ARBURST        (c1_axi_arburst[4]),// input [1 : 0] S04_AXI_ARBURST
        .S04_AXI_ARLOCK         (c1_axi_arlock[4]), // input S04_AXI_ARLOCK
        .S04_AXI_ARCACHE        (c1_axi_arcache[4]),// input [3 : 0] S04_AXI_ARCACHE
        .S04_AXI_ARPROT         (c1_axi_arprot[4]), // input [2 : 0] S04_AXI_ARPROT
        .S04_AXI_ARQOS          (c1_axi_arqos[4]),  // input [3 : 0] S04_AXI_ARQOS
        .S04_AXI_ARVALID        (c1_axi_arvalid[4]),// input S04_AXI_ARVALID
        .S04_AXI_ARREADY        (c1_axi_arready[4]),// output S04_AXI_ARREADY
        .S04_AXI_RID            (c1_axi_rid[4]),    // output [3 : 0] S04_AXI_RID
        .S04_AXI_RDATA          (c1_axi_rdata[4]),  // output [127 : 0] S04_AXI_RDATA
        .S04_AXI_RRESP          (c1_axi_rresp[4]),  // output [1 : 0] S04_AXI_RRESP
        .S04_AXI_RLAST          (c1_axi_rlast[4]),  // output S04_AXI_RLAST
        .S04_AXI_RVALID         (c1_axi_rvalid[4]), // output S04_AXI_RVALID
        .S04_AXI_RREADY         (c1_axi_rready[4]), // input S04_AXI_RREADY
    `endif // PICO_AXI_PORT_4
    `ifdef PICO_AXI_PORT_5  
        .S05_AXI_ACLK           (c1_axi_clk[5]),    // input S05_AXI_ACLK
        .S05_AXI_AWID           (c1_axi_awid[5]),   // input [3 : 0] S05_AXI_AWID
        .S05_AXI_AWADDR         (c1_axi_awaddr[5]), // input [31 : 0] S05_AXI_AWADDR
        .S05_AXI_AWLEN          (c1_axi_awlen[5]),  // input [7 : 0] S05_AXI_AWLEN
        .S05_AXI_AWSIZE         (c1_axi_awsize[5]), // input [2 : 0] S05_AXI_AWSIZE
        .S05_AXI_AWBURST        (c1_axi_awburst[5]),// input [1 : 0] S05_AXI_AWBURST
        .S05_AXI_AWLOCK         (c1_axi_awlock[5]), // input S05_AXI_AWLOCK
        .S05_AXI_AWCACHE        (c1_axi_awcache[5]),// input [3 : 0] S05_AXI_AWCACHE
        .S05_AXI_AWPROT         (c1_axi_awprot[5]), // input [2 : 0] S05_AXI_AWPROT
        .S05_AXI_AWQOS          (c1_axi_awqos[5]),  // input [3 : 0] S05_AXI_AWQOS
        .S05_AXI_AWVALID        (c1_axi_awvalid[5]),// input S05_AXI_AWVALID
        .S05_AXI_AWREADY        (c1_axi_awready[5]),// output S05_AXI_AWREADY
        .S05_AXI_WDATA          (c1_axi_wdata[5]),  // input [127 : 0] S05_AXI_WDATA
        .S05_AXI_WSTRB          (c1_axi_wstrb[5]),  // input [15 : 0] S05_AXI_WSTRB
        .S05_AXI_WLAST          (c1_axi_wlast[5]),  // input S05_AXI_WLAST
        .S05_AXI_WVALID         (c1_axi_wvalid[5]), // input S05_AXI_WVALID
        .S05_AXI_WREADY         (c1_axi_wready[5]), // output S05_AXI_WREADY
        .S05_AXI_BID            (c1_axi_bid[5]),    // output [3 : 0] S05_AXI_BID
        .S05_AXI_BRESP          (c1_axi_bresp[5]),  // output [1 : 0] S05_AXI_BRESP
        .S05_AXI_BVALID         (c1_axi_bvalid[5]), // output S05_AXI_BVALID
        .S05_AXI_BREADY         (c1_axi_bready[5]), // input S05_AXI_BREADY
        .S05_AXI_ARID           (c1_axi_arid[5]),   // input [3 : 0] S05_axi_ARID
        .S05_AXI_ARADDR         (c1_axi_araddr[5]), // input [31 : 0] S05_AXI_ARADDR
        .S05_AXI_ARLEN          (c1_axi_arlen[5]),  // input [7 : 0] S05_AXI_ARLEN
        .S05_AXI_ARSIZE         (c1_axi_arsize[5]), // input [2 : 0] S05_AXI_ARSIZE
        .S05_AXI_ARBURST        (c1_axi_arburst[5]),// input [1 : 0] S05_AXI_ARBURST
        .S05_AXI_ARLOCK         (c1_axi_arlock[5]), // input S05_AXI_ARLOCK
        .S05_AXI_ARCACHE        (c1_axi_arcache[5]),// input [3 : 0] S05_AXI_ARCACHE
        .S05_AXI_ARPROT         (c1_axi_arprot[5]), // input [2 : 0] S05_AXI_ARPROT
        .S05_AXI_ARQOS          (c1_axi_arqos[5]),  // input [3 : 0] S05_AXI_ARQOS
        .S05_AXI_ARVALID        (c1_axi_arvalid[5]),// input S05_AXI_ARVALID
        .S05_AXI_ARREADY        (c1_axi_arready[5]),// output S05_AXI_ARREADY
        .S05_AXI_RID            (c1_axi_rid[5]),    // output [3 : 0] S05_AXI_RID
        .S05_AXI_RDATA          (c1_axi_rdata[5]),  // output [127 : 0] S05_AXI_RDATA
        .S05_AXI_RRESP          (c1_axi_rresp[5]),  // output [1 : 0] S05_AXI_RRESP
        .S05_AXI_RLAST          (c1_axi_rlast[5]),  // output S05_AXI_RLAST
        .S05_AXI_RVALID         (c1_axi_rvalid[5]), // output S05_AXI_RVALID
        .S05_AXI_RREADY         (c1_axi_rready[5]), // input S05_AXI_RREADY
    `endif // PICO_AXI_PORT_5
    `ifdef PICO_AXI_PORT_6
        .S06_AXI_ACLK           (c1_axi_clk[6]),    // input S06_AXI_ACLK
        .S06_AXI_AWID           (c1_axi_awid[6]),   // input [3 : 0] S06_AXI_AWID
        .S06_AXI_AWADDR         (c1_axi_awaddr[6]), // input [31 : 0] S06_AXI_AWADDR
        .S06_AXI_AWLEN          (c1_axi_awlen[6]),  // input [7 : 0] S06_AXI_AWLEN
        .S06_AXI_AWSIZE         (c1_axi_awsize[6]), // input [2 : 0] S06_AXI_AWSIZE
        .S06_AXI_AWBURST        (c1_axi_awburst[6]),// input [1 : 0] S06_AXI_AWBURST
        .S06_AXI_AWLOCK         (c1_axi_awlock[6]), // input S06_AXI_AWLOCK
        .S06_AXI_AWCACHE        (c1_axi_awcache[6]),// input [3 : 0] S06_AXI_AWCACHE
        .S06_AXI_AWPROT         (c1_axi_awprot[6]), // input [2 : 0] S06_AXI_AWPROT
        .S06_AXI_AWQOS          (c1_axi_awqos[6]),  // input [3 : 0] S06_AXI_AWQOS
        .S06_AXI_AWVALID        (c1_axi_awvalid[6]),// input S06_AXI_AWVALID
        .S06_AXI_AWREADY        (c1_axi_awready[6]),// output S06_AXI_AWREADY
        .S06_AXI_WDATA          (c1_axi_wdata[6]),  // input [127 : 0] S06_AXI_WDATA
        .S06_AXI_WSTRB          (c1_axi_wstrb[6]),  // input [15 : 0] S06_AXI_WSTRB
        .S06_AXI_WLAST          (c1_axi_wlast[6]),  // input S06_AXI_WLAST
        .S06_AXI_WVALID         (c1_axi_wvalid[6]), // input S06_AXI_WVALID
        .S06_AXI_WREADY         (c1_axi_wready[6]), // output S06_AXI_WREADY
        .S06_AXI_BID            (c1_axi_bid[6]),    // output [3 : 0] S06_AXI_BID
        .S06_AXI_BRESP          (c1_axi_bresp[6]),  // output [1 : 0] S06_AXI_BRESP
        .S06_AXI_BVALID         (c1_axi_bvalid[6]), // output S06_AXI_BVALID
        .S06_AXI_BREADY         (c1_axi_bready[6]), // input S06_AXI_BREADY
        .S06_AXI_ARID           (c1_axi_arid[6]),   // input [3 : 0] S06_axi_ARID
        .S06_AXI_ARADDR         (c1_axi_araddr[6]), // input [31 : 0] S06_AXI_ARADDR
        .S06_AXI_ARLEN          (c1_axi_arlen[6]),  // input [7 : 0] S06_AXI_ARLEN
        .S06_AXI_ARSIZE         (c1_axi_arsize[6]), // input [2 : 0] S06_AXI_ARSIZE
        .S06_AXI_ARBURST        (c1_axi_arburst[6]),// input [1 : 0] S06_AXI_ARBURST
        .S06_AXI_ARLOCK         (c1_axi_arlock[6]), // input S06_AXI_ARLOCK
        .S06_AXI_ARCACHE        (c1_axi_arcache[6]),// input [3 : 0] S06_AXI_ARCACHE
        .S06_AXI_ARPROT         (c1_axi_arprot[6]), // input [2 : 0] S06_AXI_ARPROT
        .S06_AXI_ARQOS          (c1_axi_arqos[6]),  // input [3 : 0] S06_AXI_ARQOS
        .S06_AXI_ARVALID        (c1_axi_arvalid[6]),// input S06_AXI_ARVALID
        .S06_AXI_ARREADY        (c1_axi_arready[6]),// output S06_AXI_ARREADY
        .S06_AXI_RID            (c1_axi_rid[6]),    // output [3 : 0] S06_AXI_RID
        .S06_AXI_RDATA          (c1_axi_rdata[6]),  // output [127 : 0] S06_AXI_RDATA
        .S06_AXI_RRESP          (c1_axi_rresp[6]),  // output [1 : 0] S06_AXI_RRESP
        .S06_AXI_RLAST          (c1_axi_rlast[6]),  // output S06_AXI_RLAST
        .S06_AXI_RVALID         (c1_axi_rvalid[6]), // output S06_AXI_RVALID
        .S06_AXI_RREADY         (c1_axi_rready[6]), // input S06_AXI_RREADY
    `endif // PICO_AXI_PORT_6
    `ifdef PICO_AXI_PORT_7
        .S07_AXI_ACLK           (c1_axi_clk[7]),    // input S07_AXI_ACLK
        .S07_AXI_AWID           (c1_axi_awid[7]),   // input [3 : 0] S07_AXI_AWID
        .S07_AXI_AWADDR         (c1_axi_awaddr[7]), // input [31 : 0] S07_AXI_AWADDR
        .S07_AXI_AWLEN          (c1_axi_awlen[7]),  // input [7 : 0] S07_AXI_AWLEN
        .S07_AXI_AWSIZE         (c1_axi_awsize[7]), // input [2 : 0] S07_AXI_AWSIZE
        .S07_AXI_AWBURST        (c1_axi_awburst[7]),// input [1 : 0] S07_AXI_AWBURST
        .S07_AXI_AWLOCK         (c1_axi_awlock[7]), // input S07_AXI_AWLOCK
        .S07_AXI_AWCACHE        (c1_axi_awcache[7]),// input [3 : 0] S07_AXI_AWCACHE
        .S07_AXI_AWPROT         (c1_axi_awprot[7]), // input [2 : 0] S07_AXI_AWPROT
        .S07_AXI_AWQOS          (c1_axi_awqos[7]),  // input [3 : 0] S07_AXI_AWQOS
        .S07_AXI_AWVALID        (c1_axi_awvalid[7]),// input S07_AXI_AWVALID
        .S07_AXI_AWREADY        (c1_axi_awready[7]),// output S07_AXI_AWREADY
        .S07_AXI_WDATA          (c1_axi_wdata[7]),  // input [127 : 0] S07_AXI_WDATA
        .S07_AXI_WSTRB          (c1_axi_wstrb[7]),  // input [15 : 0] S07_AXI_WSTRB
        .S07_AXI_WLAST          (c1_axi_wlast[7]),  // input S07_AXI_WLAST
        .S07_AXI_WVALID         (c1_axi_wvalid[7]), // input S07_AXI_WVALID
        .S07_AXI_WREADY         (c1_axi_wready[7]), // output S07_AXI_WREADY
        .S07_AXI_BID            (c1_axi_bid[7]),    // output [3 : 0] S07_AXI_BID
        .S07_AXI_BRESP          (c1_axi_bresp[7]),  // output [1 : 0] S07_AXI_BRESP
        .S07_AXI_BVALID         (c1_axi_bvalid[7]), // output S07_AXI_BVALID
        .S07_AXI_BREADY         (c1_axi_bready[7]), // input S07_AXI_BREADY
        .S07_AXI_ARID           (c1_axi_arid[7]),   // input [3 : 0] S07_axi_ARID
        .S07_AXI_ARADDR         (c1_axi_araddr[7]), // input [31 : 0] S07_AXI_ARADDR
        .S07_AXI_ARLEN          (c1_axi_arlen[7]),  // input [7 : 0] S07_AXI_ARLEN
        .S07_AXI_ARSIZE         (c1_axi_arsize[7]), // input [2 : 0] S07_AXI_ARSIZE
        .S07_AXI_ARBURST        (c1_axi_arburst[7]),// input [1 : 0] S07_AXI_ARBURST
        .S07_AXI_ARLOCK         (c1_axi_arlock[7]), // input S07_AXI_ARLOCK
        .S07_AXI_ARCACHE        (c1_axi_arcache[7]),// input [3 : 0] S07_AXI_ARCACHE
        .S07_AXI_ARPROT         (c1_axi_arprot[7]), // input [2 : 0] S07_AXI_ARPROT
        .S07_AXI_ARQOS          (c1_axi_arqos[7]),  // input [3 : 0] S07_AXI_ARQOS
        .S07_AXI_ARVALID        (c1_axi_arvalid[7]),// input S07_AXI_ARVALID
        .S07_AXI_ARREADY        (c1_axi_arready[7]),// output S07_AXI_ARREADY
        .S07_AXI_RID            (c1_axi_rid[7]),    // output [3 : 0] S07_AXI_RID
        .S07_AXI_RDATA          (c1_axi_rdata[7]),  // output [127 : 0] S07_AXI_RDATA
        .S07_AXI_RRESP          (c1_axi_rresp[7]),  // output [1 : 0] S07_AXI_RRESP
        .S07_AXI_RLAST          (c1_axi_rlast[7]),  // output S07_AXI_RLAST
        .S07_AXI_RVALID         (c1_axi_rvalid[7]), // output S07_AXI_RVALID
        .S07_AXI_RREADY         (c1_axi_rready[7]), // input S07_AXI_RREADY
    `endif // PICO_AXI_PORT_7
        .M00_AXI_ACLK           (c1_tb_clk),        // input M00_AXI_ACLK
        .M00_AXI_AWID           (c1_s_axi_awid),    // output [7 : 0] M00_AXI_AWID
        .M00_AXI_AWADDR         (c1_s_axi_awaddr),  // output [31 : 0] M00_AXI_AWADDR
        .M00_AXI_AWLEN          (c1_s_axi_awlen),   // output [7 : 0] M00_AXI_AWLEN
        .M00_AXI_AWSIZE         (c1_s_axi_awsize),  // output [2 : 0] M00_AXI_AWSIZE
        .M00_AXI_AWBURST        (c1_s_axi_awburst), // output [1 : 0] M00_AXI_AWBURST
        .M00_AXI_AWLOCK         (c1_s_axi_awlock),  // output M00_AXI_AWLOCK
        .M00_AXI_AWCACHE        (c1_s_axi_awcache), // output [3 : 0] M00_AXI_AWCACHE
        .M00_AXI_AWPROT         (c1_s_axi_awprot),  // output [2 : 0] M00_AXI_AWPROT
        .M00_AXI_AWQOS          (c1_s_axi_awqos),   // output [3 : 0] M00_AXI_AWQOS
        .M00_AXI_AWVALID        (c1_s_axi_awvalid), // output M00_AXI_AWVALID
        .M00_AXI_AWREADY        (c1_s_axi_awready), // input M00_AXI_AWREADY
        .M00_AXI_WDATA          (c1_s_axi_wdata),   // output [127 : 0] M00_AXI_WDATA
        .M00_AXI_WSTRB          (c1_s_axi_wstrb),   // output [15 : 0] M00_AXI_WSTRB
        .M00_AXI_WLAST          (c1_s_axi_wlast),   // output M00_AXI_WLAST
        .M00_AXI_WVALID         (c1_s_axi_wvalid),  // output M00_AXI_WVALID
        .M00_AXI_WREADY         (c1_s_axi_wready),  // input M00_AXI_WREADY
        .M00_AXI_BID            (c1_s_axi_bid),     // input [7 : 0] M00_AXI_BID
        .M00_AXI_BRESP          (c1_s_axi_bresp),   // input [1 : 0] M00_AXI_BRESP
        .M00_AXI_BVALID         (c1_s_axi_bvalid),  // input M00_AXI_BVALID
        .M00_AXI_BREADY         (c1_s_axi_bready),  // output M00_AXI_BREADY
        .M00_AXI_ARID           (c1_s_axi_arid),    // output [7 : 0] M00_AXI_ARID
        .M00_AXI_ARADDR         (c1_s_axi_araddr),  // output [31 : 0] M00_AXI_ARADDR
        .M00_AXI_ARLEN          (c1_s_axi_arlen),   // output [7 : 0] M00_AXI_ARLEN
        .M00_AXI_ARSIZE         (c1_s_axi_arsize),  // output [2 : 0] M00_AXI_ARSIZE
        .M00_AXI_ARBURST        (c1_s_axi_arburst), // output [1 : 0] M00_AXI_ARBURST
        .M00_AXI_ARLOCK         (c1_s_axi_arlock),  // output M00_AXI_ARLOCK
        .M00_AXI_ARCACHE        (c1_s_axi_arcache), // output [3 : 0] M00_AXI_ARCACHE
        .M00_AXI_ARPROT         (c1_s_axi_arprot),  // output [2 : 0] M00_AXI_ARPROT
        .M00_AXI_ARQOS          (c1_s_axi_arqos),   // output [3 : 0] M00_AXI_ARQOS
        .M00_AXI_ARVALID        (c1_s_axi_arvalid), // output M00_AXI_ARVALID
        .M00_AXI_ARREADY        (c1_s_axi_arready), // input M00_AXI_ARREADY
        .M00_AXI_RID            (c1_s_axi_rid),     // input [7 : 0] M00_AXI_RID
        .M00_AXI_RDATA          (c1_s_axi_rdata),   // input [127 : 0] M00_AXI_RDATA
        .M00_AXI_RRESP          (c1_s_axi_rresp),   // input [1 : 0] M00_AXI_RRESP
        .M00_AXI_RLAST          (c1_s_axi_rlast),   // input M00_AXI_RLAST
        .M00_AXI_RVALID         (c1_s_axi_rvalid),  // input M00_AXI_RVALID
        .M00_AXI_RREADY         (c1_s_axi_rready)   // output M00_AXI_RREADY
        ); // AXI interconnect instance
`endif // PICO_MODEL_M503
`endif// PICO_DDR3

    `ifdef PICOBUS_WIDTH                 // Only enable these streams if there is a User module using the picobus
        
        Stream2PicoBus #(.STREAM_ID(125), .W(`PICOBUS_WIDTH)) UserModule_s2pb (
            .s_clk(clk),
            .s_rst(rst),
            
            .s_out_en(s_out_en),
            .s_out_id(s_out_id),
            .s_out_data(s_out_data_userpb),

            .s_in_valid(s_in_valid),
            .s_in_id(s_in_id[8:0]),
            .s_in_data(s_in_data[127:0]),

            .s_poll_id(s_poll_id[8:0]),
            .s_poll_seq(s_poll_seq_userpb[31:0]),
            .s_poll_next_desc(s_poll_next_desc_userpb[127:0]),
            .s_poll_next_desc_valid(s_poll_next_desc_valid_userpb),

            .s_next_desc_rd_en(s_next_desc_rd_en),
            .s_next_desc_rd_id(s_next_desc_rd_id[8:0]),
            
            .PicoClk(UserModulePicoClk),
            .PicoRst(UserModulePicoRst),
            .PicoWr(UserModulePicoWr),
            .PicoDataIn(UserModulePicoDataIn),
            .PicoRd(UserModulePicoRd),
            .PicoAddr(UserModulePicoAddr),
            .PicoDataOut(UserModulePicoDataOut)
        );
    `endif

    // begin usermodule Stream Interface

    parameter INSTREAM = {40'h0
                `ifdef STREAM1_IN_WIDTH , `STREAM1_IN_WIDTH , 8'h01 `endif
                `ifdef STREAM2_IN_WIDTH , `STREAM2_IN_WIDTH , 8'h02 `endif
                `ifdef STREAM3_IN_WIDTH , `STREAM3_IN_WIDTH , 8'h03 `endif
                `ifdef STREAM4_IN_WIDTH , `STREAM4_IN_WIDTH , 8'h04 `endif
                `ifdef STREAM5_IN_WIDTH , `STREAM5_IN_WIDTH , 8'h05 `endif
                `ifdef STREAM6_IN_WIDTH , `STREAM6_IN_WIDTH , 8'h06 `endif
                `ifdef STREAM7_IN_WIDTH , `STREAM7_IN_WIDTH , 8'h07 `endif
                `ifdef STREAM8_IN_WIDTH , `STREAM8_IN_WIDTH , 8'h08 `endif
                `ifdef STREAM9_IN_WIDTH , `STREAM9_IN_WIDTH , 8'h09 `endif
                `ifdef STREAM10_IN_WIDTH , `STREAM10_IN_WIDTH , 8'h0A `endif
                `ifdef STREAM11_IN_WIDTH , `STREAM11_IN_WIDTH , 8'h0B `endif
                `ifdef STREAM12_IN_WIDTH , `STREAM12_IN_WIDTH , 8'h0C `endif
                `ifdef STREAM13_IN_WIDTH , `STREAM13_IN_WIDTH , 8'h0D `endif
                `ifdef STREAM14_IN_WIDTH , `STREAM14_IN_WIDTH , 8'h0E `endif
                `ifdef STREAM15_IN_WIDTH , `STREAM15_IN_WIDTH , 8'h0F `endif
                `ifdef STREAM16_IN_WIDTH , `STREAM16_IN_WIDTH , 8'h10 `endif
                `ifdef STREAM17_IN_WIDTH , `STREAM17_IN_WIDTH , 8'h11 `endif
                `ifdef STREAM18_IN_WIDTH , `STREAM18_IN_WIDTH , 8'h12 `endif
                `ifdef STREAM19_IN_WIDTH , `STREAM19_IN_WIDTH , 8'h13 `endif
                `ifdef STREAM20_IN_WIDTH , `STREAM20_IN_WIDTH , 8'h14 `endif
                `ifdef STREAM21_IN_WIDTH , `STREAM21_IN_WIDTH , 8'h15 `endif
                `ifdef STREAM22_IN_WIDTH , `STREAM22_IN_WIDTH , 8'h16 `endif
                `ifdef STREAM23_IN_WIDTH , `STREAM23_IN_WIDTH , 8'h17 `endif
                `ifdef STREAM24_IN_WIDTH , `STREAM24_IN_WIDTH , 8'h18 `endif
                `ifdef STREAM25_IN_WIDTH , `STREAM25_IN_WIDTH , 8'h19 `endif
                `ifdef STREAM26_IN_WIDTH , `STREAM26_IN_WIDTH , 8'h1A `endif
                `ifdef STREAM27_IN_WIDTH , `STREAM27_IN_WIDTH , 8'h1B `endif
                `ifdef STREAM28_IN_WIDTH , `STREAM28_IN_WIDTH , 8'h1C `endif
                `ifdef STREAM29_IN_WIDTH , `STREAM29_IN_WIDTH , 8'h1D `endif
                `ifdef STREAM30_IN_WIDTH , `STREAM30_IN_WIDTH , 8'h1E `endif
                `ifdef STREAM31_IN_WIDTH , `STREAM31_IN_WIDTH , 8'h1F `endif
                `ifdef STREAM32_IN_WIDTH , `STREAM32_IN_WIDTH , 8'h20 `endif
                `ifdef STREAM33_IN_WIDTH , `STREAM33_IN_WIDTH , 8'h21 `endif
                `ifdef STREAM34_IN_WIDTH , `STREAM34_IN_WIDTH , 8'h22 `endif
                `ifdef STREAM35_IN_WIDTH , `STREAM35_IN_WIDTH , 8'h23 `endif
                `ifdef STREAM36_IN_WIDTH , `STREAM36_IN_WIDTH , 8'h24 `endif
                `ifdef STREAM37_IN_WIDTH , `STREAM37_IN_WIDTH , 8'h25 `endif
                `ifdef STREAM38_IN_WIDTH , `STREAM38_IN_WIDTH , 8'h26 `endif
                `ifdef STREAM39_IN_WIDTH , `STREAM39_IN_WIDTH , 8'h27 `endif
                `ifdef STREAM40_IN_WIDTH , `STREAM40_IN_WIDTH , 8'h28 `endif
                `ifdef STREAM41_IN_WIDTH , `STREAM41_IN_WIDTH , 8'h29 `endif
                `ifdef STREAM42_IN_WIDTH , `STREAM42_IN_WIDTH , 8'h2A `endif
                `ifdef STREAM43_IN_WIDTH , `STREAM43_IN_WIDTH , 8'h2B `endif
                `ifdef STREAM44_IN_WIDTH , `STREAM44_IN_WIDTH , 8'h2C `endif
                `ifdef STREAM45_IN_WIDTH , `STREAM45_IN_WIDTH , 8'h2D `endif
                `ifdef STREAM46_IN_WIDTH , `STREAM46_IN_WIDTH , 8'h2E `endif
                `ifdef STREAM47_IN_WIDTH , `STREAM47_IN_WIDTH , 8'h2F `endif
                `ifdef STREAM48_IN_WIDTH , `STREAM48_IN_WIDTH , 8'h30 `endif
                `ifdef STREAM49_IN_WIDTH , `STREAM49_IN_WIDTH , 8'h31 `endif
                `ifdef STREAM50_IN_WIDTH , `STREAM50_IN_WIDTH , 8'h32 `endif
                `ifdef STREAM51_IN_WIDTH , `STREAM51_IN_WIDTH , 8'h33 `endif
                `ifdef STREAM52_IN_WIDTH , `STREAM52_IN_WIDTH , 8'h34 `endif
                `ifdef STREAM53_IN_WIDTH , `STREAM53_IN_WIDTH , 8'h35 `endif
                `ifdef STREAM54_IN_WIDTH , `STREAM54_IN_WIDTH , 8'h36 `endif
                `ifdef STREAM55_IN_WIDTH , `STREAM55_IN_WIDTH , 8'h37 `endif
                `ifdef STREAM56_IN_WIDTH , `STREAM56_IN_WIDTH , 8'h38 `endif
                `ifdef STREAM57_IN_WIDTH , `STREAM57_IN_WIDTH , 8'h39 `endif
                `ifdef STREAM58_IN_WIDTH , `STREAM58_IN_WIDTH , 8'h3A `endif
                `ifdef STREAM59_IN_WIDTH , `STREAM59_IN_WIDTH , 8'h3B `endif
                `ifdef STREAM60_IN_WIDTH , `STREAM60_IN_WIDTH , 8'h3C `endif
                `ifdef STREAM61_IN_WIDTH , `STREAM61_IN_WIDTH , 8'h3D `endif
                `ifdef STREAM62_IN_WIDTH , `STREAM62_IN_WIDTH , 8'h3E `endif
                `ifdef STREAM63_IN_WIDTH , `STREAM63_IN_WIDTH , 8'h3F `endif
                `ifdef STREAM64_IN_WIDTH , `STREAM64_IN_WIDTH , 8'h40 `endif
                `ifdef STREAM65_IN_WIDTH , `STREAM65_IN_WIDTH , 8'h41 `endif
                `ifdef STREAM66_IN_WIDTH , `STREAM66_IN_WIDTH , 8'h42 `endif
                `ifdef STREAM67_IN_WIDTH , `STREAM67_IN_WIDTH , 8'h43 `endif
                `ifdef STREAM68_IN_WIDTH , `STREAM68_IN_WIDTH , 8'h44 `endif
                `ifdef STREAM69_IN_WIDTH , `STREAM69_IN_WIDTH , 8'h45 `endif
                `ifdef STREAM70_IN_WIDTH , `STREAM70_IN_WIDTH , 8'h46 `endif
                `ifdef STREAM71_IN_WIDTH , `STREAM71_IN_WIDTH , 8'h47 `endif
                `ifdef STREAM72_IN_WIDTH , `STREAM72_IN_WIDTH , 8'h48 `endif
                `ifdef STREAM73_IN_WIDTH , `STREAM73_IN_WIDTH , 8'h49 `endif
                `ifdef STREAM74_IN_WIDTH , `STREAM74_IN_WIDTH , 8'h4A `endif
                `ifdef STREAM75_IN_WIDTH , `STREAM75_IN_WIDTH , 8'h4B `endif
                `ifdef STREAM76_IN_WIDTH , `STREAM76_IN_WIDTH , 8'h4C `endif
                `ifdef STREAM77_IN_WIDTH , `STREAM77_IN_WIDTH , 8'h4D `endif
                `ifdef STREAM78_IN_WIDTH , `STREAM78_IN_WIDTH , 8'h4E `endif
                `ifdef STREAM79_IN_WIDTH , `STREAM79_IN_WIDTH , 8'h4F `endif
                `ifdef STREAM80_IN_WIDTH , `STREAM80_IN_WIDTH , 8'h50 `endif
                `ifdef STREAM81_IN_WIDTH , `STREAM81_IN_WIDTH , 8'h51 `endif
                `ifdef STREAM82_IN_WIDTH , `STREAM82_IN_WIDTH , 8'h52 `endif
                `ifdef STREAM83_IN_WIDTH , `STREAM83_IN_WIDTH , 8'h53 `endif
                `ifdef STREAM84_IN_WIDTH , `STREAM84_IN_WIDTH , 8'h54 `endif
                `ifdef STREAM85_IN_WIDTH , `STREAM85_IN_WIDTH , 8'h55 `endif
                `ifdef STREAM86_IN_WIDTH , `STREAM86_IN_WIDTH , 8'h56 `endif
                `ifdef STREAM87_IN_WIDTH , `STREAM87_IN_WIDTH , 8'h57 `endif
                `ifdef STREAM88_IN_WIDTH , `STREAM88_IN_WIDTH , 8'h58 `endif
                `ifdef STREAM89_IN_WIDTH , `STREAM89_IN_WIDTH , 8'h59 `endif
                `ifdef STREAM90_IN_WIDTH , `STREAM90_IN_WIDTH , 8'h5A `endif
                `ifdef STREAM91_IN_WIDTH , `STREAM91_IN_WIDTH , 8'h5B `endif
                `ifdef STREAM92_IN_WIDTH , `STREAM92_IN_WIDTH , 8'h5C `endif
                `ifdef STREAM93_IN_WIDTH , `STREAM93_IN_WIDTH , 8'h5D `endif
                `ifdef STREAM94_IN_WIDTH , `STREAM94_IN_WIDTH , 8'h5E `endif
                `ifdef STREAM95_IN_WIDTH , `STREAM95_IN_WIDTH , 8'h5F `endif
                `ifdef STREAM96_IN_WIDTH , `STREAM96_IN_WIDTH , 8'h60 `endif
                `ifdef STREAM97_IN_WIDTH , `STREAM97_IN_WIDTH , 8'h61 `endif
                `ifdef STREAM98_IN_WIDTH , `STREAM98_IN_WIDTH , 8'h62 `endif
                `ifdef STREAM99_IN_WIDTH , `STREAM99_IN_WIDTH , 8'h63 `endif
                `ifdef STREAM100_IN_WIDTH , `STREAM100_IN_WIDTH , 8'h64 `endif
                `ifdef STREAM101_IN_WIDTH , `STREAM101_IN_WIDTH , 8'h65 `endif
                `ifdef STREAM102_IN_WIDTH , `STREAM102_IN_WIDTH , 8'h66 `endif
                `ifdef STREAM103_IN_WIDTH , `STREAM103_IN_WIDTH , 8'h67 `endif
                `ifdef STREAM104_IN_WIDTH , `STREAM104_IN_WIDTH , 8'h68 `endif
                `ifdef STREAM105_IN_WIDTH , `STREAM105_IN_WIDTH , 8'h69 `endif
                `ifdef STREAM106_IN_WIDTH , `STREAM106_IN_WIDTH , 8'h6A `endif
                `ifdef STREAM107_IN_WIDTH , `STREAM107_IN_WIDTH , 8'h6B `endif
                `ifdef STREAM108_IN_WIDTH , `STREAM108_IN_WIDTH , 8'h6C `endif
                `ifdef STREAM109_IN_WIDTH , `STREAM109_IN_WIDTH , 8'h6D `endif
                `ifdef STREAM110_IN_WIDTH , `STREAM110_IN_WIDTH , 8'h6E `endif
                `ifdef STREAM111_IN_WIDTH , `STREAM111_IN_WIDTH , 8'h6F `endif
                `ifdef STREAM112_IN_WIDTH , `STREAM112_IN_WIDTH , 8'h70 `endif
                `ifdef STREAM113_IN_WIDTH , `STREAM113_IN_WIDTH , 8'h71 `endif
                `ifdef STREAM114_IN_WIDTH , `STREAM114_IN_WIDTH , 8'h72 `endif
                `ifdef STREAM115_IN_WIDTH , `STREAM115_IN_WIDTH , 8'h73 `endif
                `ifdef STREAM116_IN_WIDTH , `STREAM116_IN_WIDTH , 8'h74 `endif
                `ifdef STREAM117_IN_WIDTH , `STREAM117_IN_WIDTH , 8'h75 `endif
                `ifdef STREAM118_IN_WIDTH , `STREAM118_IN_WIDTH , 8'h76 `endif
                `ifdef STREAM119_IN_WIDTH , `STREAM119_IN_WIDTH , 8'h77 `endif
                `ifdef STREAM120_IN_WIDTH , `STREAM120_IN_WIDTH , 8'h78 `endif
                `ifdef STREAM121_IN_WIDTH , `STREAM121_IN_WIDTH , 8'h79 `endif
                `ifdef STREAM122_IN_WIDTH , `STREAM122_IN_WIDTH , 8'h7A `endif
                `ifdef STREAM123_IN_WIDTH , `STREAM123_IN_WIDTH , 8'h7B `endif
                `ifdef STREAM124_IN_WIDTH , `STREAM124_IN_WIDTH , 8'h7C `endif
                `ifdef STREAM125_IN_WIDTH , `STREAM125_IN_WIDTH , 8'h7D `endif
                `ifdef STREAM126_IN_WIDTH , `STREAM126_IN_WIDTH , 8'h7E `endif
                    };


    parameter OUTSTREAM = {40'h0
                `ifdef STREAM1_OUT_WIDTH , `STREAM1_OUT_WIDTH , 8'h01 `endif
                `ifdef STREAM2_OUT_WIDTH , `STREAM2_OUT_WIDTH , 8'h02 `endif
                `ifdef STREAM3_OUT_WIDTH , `STREAM3_OUT_WIDTH , 8'h03 `endif
                `ifdef STREAM4_OUT_WIDTH , `STREAM4_OUT_WIDTH , 8'h04 `endif
                `ifdef STREAM5_OUT_WIDTH , `STREAM5_OUT_WIDTH , 8'h05 `endif
                `ifdef STREAM6_OUT_WIDTH , `STREAM6_OUT_WIDTH , 8'h06 `endif
                `ifdef STREAM7_OUT_WIDTH , `STREAM7_OUT_WIDTH , 8'h07 `endif
                `ifdef STREAM8_OUT_WIDTH , `STREAM8_OUT_WIDTH , 8'h08 `endif
                `ifdef STREAM9_OUT_WIDTH , `STREAM9_OUT_WIDTH , 8'h09 `endif
                `ifdef STREAM10_OUT_WIDTH , `STREAM10_OUT_WIDTH , 8'h0A `endif
                `ifdef STREAM11_OUT_WIDTH , `STREAM11_OUT_WIDTH , 8'h0B `endif
                `ifdef STREAM12_OUT_WIDTH , `STREAM12_OUT_WIDTH , 8'h0C `endif
                `ifdef STREAM13_OUT_WIDTH , `STREAM13_OUT_WIDTH , 8'h0D `endif
                `ifdef STREAM14_OUT_WIDTH , `STREAM14_OUT_WIDTH , 8'h0E `endif
                `ifdef STREAM15_OUT_WIDTH , `STREAM15_OUT_WIDTH , 8'h0F `endif
                `ifdef STREAM16_OUT_WIDTH , `STREAM16_OUT_WIDTH , 8'h10 `endif
                `ifdef STREAM17_OUT_WIDTH , `STREAM17_OUT_WIDTH , 8'h11 `endif
                `ifdef STREAM18_OUT_WIDTH , `STREAM18_OUT_WIDTH , 8'h12 `endif
                `ifdef STREAM19_OUT_WIDTH , `STREAM19_OUT_WIDTH , 8'h13 `endif
                `ifdef STREAM20_OUT_WIDTH , `STREAM20_OUT_WIDTH , 8'h14 `endif
                `ifdef STREAM21_OUT_WIDTH , `STREAM21_OUT_WIDTH , 8'h15 `endif
                `ifdef STREAM22_OUT_WIDTH , `STREAM22_OUT_WIDTH , 8'h16 `endif
                `ifdef STREAM23_OUT_WIDTH , `STREAM23_OUT_WIDTH , 8'h17 `endif
                `ifdef STREAM24_OUT_WIDTH , `STREAM24_OUT_WIDTH , 8'h18 `endif
                `ifdef STREAM25_OUT_WIDTH , `STREAM25_OUT_WIDTH , 8'h19 `endif
                `ifdef STREAM26_OUT_WIDTH , `STREAM26_OUT_WIDTH , 8'h1A `endif
                `ifdef STREAM27_OUT_WIDTH , `STREAM27_OUT_WIDTH , 8'h1B `endif
                `ifdef STREAM28_OUT_WIDTH , `STREAM28_OUT_WIDTH , 8'h1C `endif
                `ifdef STREAM29_OUT_WIDTH , `STREAM29_OUT_WIDTH , 8'h1D `endif
                `ifdef STREAM30_OUT_WIDTH , `STREAM30_OUT_WIDTH , 8'h1E `endif
                `ifdef STREAM31_OUT_WIDTH , `STREAM31_OUT_WIDTH , 8'h1F `endif
                `ifdef STREAM32_OUT_WIDTH , `STREAM32_OUT_WIDTH , 8'h20 `endif
                `ifdef STREAM33_OUT_WIDTH , `STREAM33_OUT_WIDTH , 8'h21 `endif
                `ifdef STREAM34_OUT_WIDTH , `STREAM34_OUT_WIDTH , 8'h22 `endif
                `ifdef STREAM35_OUT_WIDTH , `STREAM35_OUT_WIDTH , 8'h23 `endif
                `ifdef STREAM36_OUT_WIDTH , `STREAM36_OUT_WIDTH , 8'h24 `endif
                `ifdef STREAM37_OUT_WIDTH , `STREAM37_OUT_WIDTH , 8'h25 `endif
                `ifdef STREAM38_OUT_WIDTH , `STREAM38_OUT_WIDTH , 8'h26 `endif
                `ifdef STREAM39_OUT_WIDTH , `STREAM39_OUT_WIDTH , 8'h27 `endif
                `ifdef STREAM40_OUT_WIDTH , `STREAM40_OUT_WIDTH , 8'h28 `endif
                `ifdef STREAM41_OUT_WIDTH , `STREAM41_OUT_WIDTH , 8'h29 `endif
                `ifdef STREAM42_OUT_WIDTH , `STREAM42_OUT_WIDTH , 8'h2A `endif
                `ifdef STREAM43_OUT_WIDTH , `STREAM43_OUT_WIDTH , 8'h2B `endif
                `ifdef STREAM44_OUT_WIDTH , `STREAM44_OUT_WIDTH , 8'h2C `endif
                `ifdef STREAM45_OUT_WIDTH , `STREAM45_OUT_WIDTH , 8'h2D `endif
                `ifdef STREAM46_OUT_WIDTH , `STREAM46_OUT_WIDTH , 8'h2E `endif
                `ifdef STREAM47_OUT_WIDTH , `STREAM47_OUT_WIDTH , 8'h2F `endif
                `ifdef STREAM48_OUT_WIDTH , `STREAM48_OUT_WIDTH , 8'h30 `endif
                `ifdef STREAM49_OUT_WIDTH , `STREAM49_OUT_WIDTH , 8'h31 `endif
                `ifdef STREAM50_OUT_WIDTH , `STREAM50_OUT_WIDTH , 8'h32 `endif
                `ifdef STREAM51_OUT_WIDTH , `STREAM51_OUT_WIDTH , 8'h33 `endif
                `ifdef STREAM52_OUT_WIDTH , `STREAM52_OUT_WIDTH , 8'h34 `endif
                `ifdef STREAM53_OUT_WIDTH , `STREAM53_OUT_WIDTH , 8'h35 `endif
                `ifdef STREAM54_OUT_WIDTH , `STREAM54_OUT_WIDTH , 8'h36 `endif
                `ifdef STREAM55_OUT_WIDTH , `STREAM55_OUT_WIDTH , 8'h37 `endif
                `ifdef STREAM56_OUT_WIDTH , `STREAM56_OUT_WIDTH , 8'h38 `endif
                `ifdef STREAM57_OUT_WIDTH , `STREAM57_OUT_WIDTH , 8'h39 `endif
                `ifdef STREAM58_OUT_WIDTH , `STREAM58_OUT_WIDTH , 8'h3A `endif
                `ifdef STREAM59_OUT_WIDTH , `STREAM59_OUT_WIDTH , 8'h3B `endif
                `ifdef STREAM60_OUT_WIDTH , `STREAM60_OUT_WIDTH , 8'h3C `endif
                `ifdef STREAM61_OUT_WIDTH , `STREAM61_OUT_WIDTH , 8'h3D `endif
                `ifdef STREAM62_OUT_WIDTH , `STREAM62_OUT_WIDTH , 8'h3E `endif
                `ifdef STREAM63_OUT_WIDTH , `STREAM63_OUT_WIDTH , 8'h3F `endif
                `ifdef STREAM64_OUT_WIDTH , `STREAM64_OUT_WIDTH , 8'h40 `endif
                `ifdef STREAM65_OUT_WIDTH , `STREAM65_OUT_WIDTH , 8'h41 `endif
                `ifdef STREAM66_OUT_WIDTH , `STREAM66_OUT_WIDTH , 8'h42 `endif
                `ifdef STREAM67_OUT_WIDTH , `STREAM67_OUT_WIDTH , 8'h43 `endif
                `ifdef STREAM68_OUT_WIDTH , `STREAM68_OUT_WIDTH , 8'h44 `endif
                `ifdef STREAM69_OUT_WIDTH , `STREAM69_OUT_WIDTH , 8'h45 `endif
                `ifdef STREAM70_OUT_WIDTH , `STREAM70_OUT_WIDTH , 8'h46 `endif
                `ifdef STREAM71_OUT_WIDTH , `STREAM71_OUT_WIDTH , 8'h47 `endif
                `ifdef STREAM72_OUT_WIDTH , `STREAM72_OUT_WIDTH , 8'h48 `endif
                `ifdef STREAM73_OUT_WIDTH , `STREAM73_OUT_WIDTH , 8'h49 `endif
                `ifdef STREAM74_OUT_WIDTH , `STREAM74_OUT_WIDTH , 8'h4A `endif
                `ifdef STREAM75_OUT_WIDTH , `STREAM75_OUT_WIDTH , 8'h4B `endif
                `ifdef STREAM76_OUT_WIDTH , `STREAM76_OUT_WIDTH , 8'h4C `endif
                `ifdef STREAM77_OUT_WIDTH , `STREAM77_OUT_WIDTH , 8'h4D `endif
                `ifdef STREAM78_OUT_WIDTH , `STREAM78_OUT_WIDTH , 8'h4E `endif
                `ifdef STREAM79_OUT_WIDTH , `STREAM79_OUT_WIDTH , 8'h4F `endif
                `ifdef STREAM80_OUT_WIDTH , `STREAM80_OUT_WIDTH , 8'h50 `endif
                `ifdef STREAM81_OUT_WIDTH , `STREAM81_OUT_WIDTH , 8'h51 `endif
                `ifdef STREAM82_OUT_WIDTH , `STREAM82_OUT_WIDTH , 8'h52 `endif
                `ifdef STREAM83_OUT_WIDTH , `STREAM83_OUT_WIDTH , 8'h53 `endif
                `ifdef STREAM84_OUT_WIDTH , `STREAM84_OUT_WIDTH , 8'h54 `endif
                `ifdef STREAM85_OUT_WIDTH , `STREAM85_OUT_WIDTH , 8'h55 `endif
                `ifdef STREAM86_OUT_WIDTH , `STREAM86_OUT_WIDTH , 8'h56 `endif
                `ifdef STREAM87_OUT_WIDTH , `STREAM87_OUT_WIDTH , 8'h57 `endif
                `ifdef STREAM88_OUT_WIDTH , `STREAM88_OUT_WIDTH , 8'h58 `endif
                `ifdef STREAM89_OUT_WIDTH , `STREAM89_OUT_WIDTH , 8'h59 `endif
                `ifdef STREAM90_OUT_WIDTH , `STREAM90_OUT_WIDTH , 8'h5A `endif
                `ifdef STREAM91_OUT_WIDTH , `STREAM91_OUT_WIDTH , 8'h5B `endif
                `ifdef STREAM92_OUT_WIDTH , `STREAM92_OUT_WIDTH , 8'h5C `endif
                `ifdef STREAM93_OUT_WIDTH , `STREAM93_OUT_WIDTH , 8'h5D `endif
                `ifdef STREAM94_OUT_WIDTH , `STREAM94_OUT_WIDTH , 8'h5E `endif
                `ifdef STREAM95_OUT_WIDTH , `STREAM95_OUT_WIDTH , 8'h5F `endif
                `ifdef STREAM96_OUT_WIDTH , `STREAM96_OUT_WIDTH , 8'h60 `endif
                `ifdef STREAM97_OUT_WIDTH , `STREAM97_OUT_WIDTH , 8'h61 `endif
                `ifdef STREAM98_OUT_WIDTH , `STREAM98_OUT_WIDTH , 8'h62 `endif
                `ifdef STREAM99_OUT_WIDTH , `STREAM99_OUT_WIDTH , 8'h63 `endif
                `ifdef STREAM100_OUT_WIDTH , `STREAM100_OUT_WIDTH , 8'h64 `endif
                `ifdef STREAM101_OUT_WIDTH , `STREAM101_OUT_WIDTH , 8'h65 `endif
                `ifdef STREAM102_OUT_WIDTH , `STREAM102_OUT_WIDTH , 8'h66 `endif
                `ifdef STREAM103_OUT_WIDTH , `STREAM103_OUT_WIDTH , 8'h67 `endif
                `ifdef STREAM104_OUT_WIDTH , `STREAM104_OUT_WIDTH , 8'h68 `endif
                `ifdef STREAM105_OUT_WIDTH , `STREAM105_OUT_WIDTH , 8'h69 `endif
                `ifdef STREAM106_OUT_WIDTH , `STREAM106_OUT_WIDTH , 8'h6A `endif
                `ifdef STREAM107_OUT_WIDTH , `STREAM107_OUT_WIDTH , 8'h6B `endif
                `ifdef STREAM108_OUT_WIDTH , `STREAM108_OUT_WIDTH , 8'h6C `endif
                `ifdef STREAM109_OUT_WIDTH , `STREAM109_OUT_WIDTH , 8'h6D `endif
                `ifdef STREAM110_OUT_WIDTH , `STREAM110_OUT_WIDTH , 8'h6E `endif
                `ifdef STREAM111_OUT_WIDTH , `STREAM111_OUT_WIDTH , 8'h6F `endif
                `ifdef STREAM112_OUT_WIDTH , `STREAM112_OUT_WIDTH , 8'h70 `endif
                `ifdef STREAM113_OUT_WIDTH , `STREAM113_OUT_WIDTH , 8'h71 `endif
                `ifdef STREAM114_OUT_WIDTH , `STREAM114_OUT_WIDTH , 8'h72 `endif
                `ifdef STREAM115_OUT_WIDTH , `STREAM115_OUT_WIDTH , 8'h73 `endif
                `ifdef STREAM116_OUT_WIDTH , `STREAM116_OUT_WIDTH , 8'h74 `endif
                `ifdef STREAM117_OUT_WIDTH , `STREAM117_OUT_WIDTH , 8'h75 `endif
                `ifdef STREAM118_OUT_WIDTH , `STREAM118_OUT_WIDTH , 8'h76 `endif
                `ifdef STREAM119_OUT_WIDTH , `STREAM119_OUT_WIDTH , 8'h77 `endif
                `ifdef STREAM120_OUT_WIDTH , `STREAM120_OUT_WIDTH , 8'h78 `endif
                `ifdef STREAM121_OUT_WIDTH , `STREAM121_OUT_WIDTH , 8'h79 `endif
                `ifdef STREAM122_OUT_WIDTH , `STREAM122_OUT_WIDTH , 8'h7A `endif
                `ifdef STREAM123_OUT_WIDTH , `STREAM123_OUT_WIDTH , 8'h7B `endif
                `ifdef STREAM124_OUT_WIDTH , `STREAM124_OUT_WIDTH , 8'h7C `endif
                `ifdef STREAM125_OUT_WIDTH , `STREAM125_OUT_WIDTH , 8'h7D `endif
                `ifdef STREAM126_OUT_WIDTH , `STREAM126_OUT_WIDTH , 8'h7E `endif
                    };
                    
                    
    wire [31:0]     stream_in_desc_poll_seq[127:0];
    wire            stream_in_desc_poll_next_desc_valid[127:0];
    wire [127:0]    stream_in_desc_poll_next_desc[127:0];
    
    wire            stream_in_rdy[127:0];
    wire            stream_in_valid[127:0];
    wire [127:0]    stream_in_data[127:0];
    
    genvar k;
    generate
        for( k = 0; |INSTREAM[39+(k*40):0+(k*40)]; k=k+1)
            begin: stream_in
					if(INSTREAM[39+(k*40):8+(k*40)] == 128) begin
						 PicoStreamIn #(
							  .ID(INSTREAM[7+(k*40):0+(k*40)])
						 ) gen_stream_in (
							  .clk(clk),
							  .rst(rst),
							  

							  .s_rdy(stream_in_valid[INSTREAM[7+(k*40):0+(k*40)]]),
							  .s_en(stream_in_rdy[INSTREAM[7+(k*40):0+(k*40)]]),
							  .s_data(stream_in_data[INSTREAM[7+(k*40):0+(k*40)]][127:0]),
							  
							  .s_in_valid(s_in_valid),
							  .s_in_id(s_in_id[8:0]),
							  .s_in_data(s_in_data[127:0]),
							  
							  .s_poll_id(s_poll_id[8:0]),
							  .s_poll_seq(stream_in_desc_poll_seq[INSTREAM[7+(k*40):0+(k*40)]][31:0]),
							  .s_poll_next_desc(stream_in_desc_poll_next_desc[INSTREAM[7+(k*40):0+(k*40)]][127:0]),
							  .s_poll_next_desc_valid(stream_in_desc_poll_next_desc_valid[INSTREAM[7+(k*40):0+(k*40)]]),
							  
							  .s_next_desc_rd_en(s_next_desc_rd_en),
							  .s_next_desc_rd_id(s_next_desc_rd_id[8:0])
						 );
					end else 
					  if (INSTREAM[39+(k*40):8+(k*40)] == 32) begin
							wire s128_in_valid, s128_in_rdy;
							wire [127:0] s128_in_data;
							InStreamWidthConversion #(
									.W(32)
							) gen_width_in (
								.clk(clk),
								.rst(rst),
								
								.s128_valid(s128_in_valid),
								.s128_data(s128_in_data[127:0]),
								.s128_rdy(s128_in_rdy),
								
								.s_valid(stream_in_valid[INSTREAM[7+(k*40):0+(k*40)]]),
								.s_rdy(stream_in_rdy[INSTREAM[7+(k*40):0+(k*40)]]),
								.s_data(stream_in_data[INSTREAM[7+(k*40):0+(k*40)]][31:0])
							);
							PicoStreamIn #(
								  .ID(INSTREAM[7+(k*40):0+(k*40)])
							 ) gen_stream_in (
								  .clk(clk),
								  .rst(rst),
								  
								  .s_rdy(s128_in_valid),  //valid
								  .s_en(s128_in_rdy), // rdy
								  .s_data(s128_in_data[127:0]),
								  
								  .s_in_valid(s_in_valid),
								  .s_in_id(s_in_id[8:0]),
								  .s_in_data(s_in_data[127:0]),
								  
								  .s_poll_id(s_poll_id[8:0]),
								  .s_poll_seq(stream_in_desc_poll_seq[INSTREAM[7+(k*40):0+(k*40)]][31:0]),
								  .s_poll_next_desc(stream_in_desc_poll_next_desc[INSTREAM[7+(k*40):0+(k*40)]][127:0]),
								  .s_poll_next_desc_valid(stream_in_desc_poll_next_desc_valid[INSTREAM[7+(k*40):0+(k*40)]]),
								  
								  .s_next_desc_rd_en(s_next_desc_rd_en),
								  .s_next_desc_rd_id(s_next_desc_rd_id[8:0])
							 );
					end
            end
    endgenerate
    
    wire [31:0]     stream_out_desc_poll_seq[127:0];
    wire            stream_out_desc_poll_next_desc_valid[127:0];
    wire [127:0]    stream_out_desc_poll_next_desc[127:0];
    wire [127:0]    stream_out_data_card[127:0];        // This has to be ored together
    `endif //_NAME
    
    wire            stream_out_rdy[127:0];
    wire            stream_out_valid[127:0];
    wire [127:0]    stream_out_data[127:0];
    
    genvar m;
    generate
        for( m = 0; |OUTSTREAM[39+(m*40):0+(m*40)]; m=m+1) 
            begin: stream_out
					 if (OUTSTREAM[39+(m*40):8+(m*40)] == 128) begin
						 PicoStreamOut #(
							  .ID(OUTSTREAM[7+(m*40):0+(m*40)])
						 ) gen_stream_out (
							  .clk(clk),
							  .rst(rst),
							  
							  .s_rdy(stream_out_rdy[OUTSTREAM[7+(m*40):0+(m*40)]]),
							  .s_valid(stream_out_valid[OUTSTREAM[7+(m*40):0+(m*40)]]),
							  .s_data(stream_out_data[OUTSTREAM[7+(m*40):0+(m*40)]]),
							  
							  .s_out_en(s_out_en),
							  .s_out_id(s_out_id[8:0]),
							  .s_out_data(stream_out_data_card[OUTSTREAM[7+(m*40):0+(m*40)]][127:0]),
							  
							  .s_in_valid(s_in_valid),
							  .s_in_id(s_in_id[8:0]),
							  .s_in_data(s_in_data[127:0]),
							  
							  .s_poll_id(s_poll_id[8:0]),
							  .s_poll_seq(stream_out_desc_poll_seq[OUTSTREAM[7+(m*40):0+(m*40)]][31:0]),
							  .s_poll_next_desc(stream_out_desc_poll_next_desc[OUTSTREAM[7+(m*40):0+(m*40)]][127:0]),
							  .s_poll_next_desc_valid(stream_out_desc_poll_next_desc_valid[OUTSTREAM[7+(m*40):0+(m*40)]]),
							  
							  .s_next_desc_rd_en(s_next_desc_rd_en),
							  .s_next_desc_rd_id(s_next_desc_rd_id[8:0])
						 );
					end else
						if (OUTSTREAM[39+(m*40):8+(m*40)] == 32) begin
							wire s128_out_valid, s128_out_rdy;
							wire [127:0] s128_out_data;
							OutStreamWidthConversion #(
									.W(32)
							) gen_width_out (
								.clk(clk),
								.rst(rst),
								
								.s128_valid(s128_out_valid),
								.s128_data(s128_out_data[127:0]),
								.s128_rdy(s128_out_rdy),
								
								.s_valid(stream_out_valid[OUTSTREAM[7+(m*40):0+(m*40)]]),
								.s_rdy(stream_out_rdy[OUTSTREAM[7+(m*40):0+(m*40)]]),
								.s_data(stream_out_data[OUTSTREAM[7+(m*40):0+(m*40)]][31:0])
							);
							
							PicoStreamOut #(
							  .ID(OUTSTREAM[7+(m*40):0+(m*40)])
							) gen_stream_out (
							  .clk(clk),
							  .rst(rst),
							  
							  .s_rdy(s128_out_rdy),
							  .s_valid(s128_out_valid),
							  .s_data(s128_out_data),
							  
							  .s_out_en(s_out_en),
							  .s_out_id(s_out_id[8:0]),
							  .s_out_data(stream_out_data_card[OUTSTREAM[7+(m*40):0+(m*40)]][127:0]),
							  
							  .s_in_valid(s_in_valid),
							  .s_in_id(s_in_id[8:0]),
							  .s_in_data(s_in_data[127:0]),
							  
							  .s_poll_id(s_poll_id[8:0]),
							  .s_poll_seq(stream_out_desc_poll_seq[OUTSTREAM[7+(m*40):0+(m*40)]][31:0]),
							  .s_poll_next_desc(stream_out_desc_poll_next_desc[OUTSTREAM[7+(m*40):0+(m*40)]][127:0]),
							  .s_poll_next_desc_valid(stream_out_desc_poll_next_desc_valid[OUTSTREAM[7+(m*40):0+(m*40)]]),
							  
							  .s_next_desc_rd_en(s_next_desc_rd_en),
							  .s_next_desc_rd_id(s_next_desc_rd_id[8:0])
						 );
					end
            end
    endgenerate

    // end usermodule stream interface
            
`ifdef USER_MODULE_NAME
    `USER_MODULE_NAME 
      `ifdef PICO_DDR3
         #(
        `ifdef PICO_MODEL_M503
            .C1_C_S_AXI_ID_WIDTH       ( C1_C_S_AXI_ID_WIDTH-4 ),
            .C1_C_S_AXI_ADDR_WIDTH     ( C1_C_S_AXI_ADDR_WIDTH ),
            .C1_C_S_AXI_DATA_WIDTH     ( C1_C_S_AXI_DATA_WIDTH ),
        `endif // PICO_MODEL_M503
            .C0_C_S_AXI_ID_WIDTH       ( C0_C_S_AXI_ID_WIDTH-4 ),
            .C0_C_S_AXI_ADDR_WIDTH     ( C0_C_S_AXI_ADDR_WIDTH ),
            .C0_C_S_AXI_DATA_WIDTH     ( C0_C_S_AXI_DATA_WIDTH )
         )
      `endif
     UserModule (
    `undef UM_PREPEND_COMMA      // In case this gets used before
    `undef INCLUDE_STREAM_COMMON // ditto
    
    `ifdef EXTRA_CLK
         `ifdef  UM_PREPEND_COMMA , `endif
         `define UM_PREPEND_COMMA
         .extra_clk(extra_clk)
    `endif
    
    `ifdef USER_DIRECT_PCI
         `ifdef  UM_PREPEND_COMMA , `endif
         `define UM_PREPEND_COMMA
        .user_pci_wr_q_data(user_pci_wr_q_data),
        .user_pci_wr_q_valid(user_pci_wr_q_valid),
        .user_pci_wr_q_en(user_pci_wr_q_en),

        .user_pci_wr_data_q_data(user_pci_wr_data_q_data),
        .user_pci_wr_data_q_valid(user_pci_wr_data_q_valid),
        .user_pci_wr_data_q_en(user_pci_wr_data_q_en),
        
        .direct_rx_valid(direct_rx_valid),
        .direct_rx_data(s_in_data[127:0])
    `endif
    
    `ifdef PICOBUS_WIDTH
         `ifdef  UM_PREPEND_COMMA , `endif
         `define UM_PREPEND_COMMA
        .PicoClk(UserModulePicoClk),
        .PicoRst(UserModulePicoRst),
        .PicoAddr(UserModulePicoAddr[31:0]),
        .PicoDataIn(UserModulePicoDataIn),
        .PicoRd(UserModulePicoRd),
        .PicoWr(UserModulePicoWr),
        .PicoDataOut(UserModulePicoDataOut)
    `endif


      `ifdef PICO_QDRII
        `ifdef PICO_MODEL_M503   
         // user multi-port interface
            `ifdef  UM_PREPEND_COMMA , `endif
            `define UM_PREPEND_COMMA
            
         .qdrii_sys_rst                 ( qdrii_sys_rst     ), 
      
         //---------------------------------------------
         // QDRII 0
         
         .c0_user_wr_cmd0               ( c0_user_wr_cmd0   ),
         .c0_user_wr_cmd1               ( c0_user_wr_cmd1   ),
         .c0_user_wr_addr0              ( c0_user_wr_addr0  ),
         .c0_user_wr_addr1              ( c0_user_wr_addr1  ),
         .c0_user_rd_cmd0               ( c0_user_rd_cmd0   ),
         .c0_user_rd_cmd1               ( c0_user_rd_cmd1   ),
         .c0_user_rd_addr0              ( c0_user_rd_addr0  ),
         .c0_user_rd_addr1              ( c0_user_rd_addr1  ),
         .c0_user_wr_data0              ( c0_user_wr_data0  ),
         .c0_user_wr_data1              ( c0_user_wr_data1  ),
         .c0_user_wr_bw_n0              ( c0_user_wr_bw_n0  ),
         .c0_user_wr_bw_n1              ( c0_user_wr_bw_n1  ),
         .c0_clk_tb                     ( c0_clk_tb         ),
         .c0_rst_clk_tb                 ( c0_rst_clk_tb     ),
         .c0_user_rd_valid0             ( c0_user_rd_valid0 ),
         .c0_user_rd_valid1             ( c0_user_rd_valid1 ),
         .c0_user_rd_data0              ( c0_user_rd_data0  ),
         .c0_user_rd_data1              ( c0_user_rd_data1  ),
         .c0_cal_done                   ( c0_cal_done       ),

         //---------------------------------------------
         // QDRII 1
         
         .c1_user_wr_cmd0               ( c1_user_wr_cmd0   ),
         .c1_user_wr_cmd1               ( c1_user_wr_cmd1   ),
         .c1_user_wr_addr0              ( c1_user_wr_addr0  ),
         .c1_user_wr_addr1              ( c1_user_wr_addr1  ),
         .c1_user_rd_cmd0               ( c1_user_rd_cmd0   ),
         .c1_user_rd_cmd1               ( c1_user_rd_cmd1   ),
         .c1_user_rd_addr0              ( c1_user_rd_addr0  ),
         .c1_user_rd_addr1              ( c1_user_rd_addr1  ),
         .c1_user_wr_data0              ( c1_user_wr_data0  ),
         .c1_user_wr_data1              ( c1_user_wr_data1  ),
         .c1_user_wr_bw_n0              ( c1_user_wr_bw_n0  ),
         .c1_user_wr_bw_n1              ( c1_user_wr_bw_n1  ),
         .c1_clk_tb                     ( c1_clk_tb         ),
         .c1_rst_clk_tb                 ( c1_rst_clk_tb     ),
         .c1_user_rd_valid0             ( c1_user_rd_valid0 ),
         .c1_user_rd_valid1             ( c1_user_rd_valid1 ),
         .c1_user_rd_data0              ( c1_user_rd_data0  ),
         .c1_user_rd_data1              ( c1_user_rd_data1  ),
         .c1_cal_done                   ( c1_cal_done       ),

         //---------------------------------------------
         // QDRII 2
         
         .c2_user_wr_cmd0               ( c2_user_wr_cmd0   ),
         .c2_user_wr_cmd1               ( c2_user_wr_cmd1   ),
         .c2_user_wr_addr0              ( c2_user_wr_addr0  ),
         .c2_user_wr_addr1              ( c2_user_wr_addr1  ),
         .c2_user_rd_cmd0               ( c2_user_rd_cmd0   ),
         .c2_user_rd_cmd1               ( c2_user_rd_cmd1   ),
         .c2_user_rd_addr0              ( c2_user_rd_addr0  ),
         .c2_user_rd_addr1              ( c2_user_rd_addr1  ),
         .c2_user_wr_data0              ( c2_user_wr_data0  ),
         .c2_user_wr_data1              ( c2_user_wr_data1  ),
         .c2_user_wr_bw_n0              ( c2_user_wr_bw_n0  ),
         .c2_user_wr_bw_n1              ( c2_user_wr_bw_n1  ),
         .c2_clk_tb                     ( c2_clk_tb         ),
         .c2_rst_clk_tb                 ( c2_rst_clk_tb     ),
         .c2_user_rd_valid0             ( c2_user_rd_valid0 ),
         .c2_user_rd_valid1             ( c2_user_rd_valid1 ),
         .c2_user_rd_data0              ( c2_user_rd_data0  ),
         .c2_user_rd_data1              ( c2_user_rd_data1  ),
         .c2_cal_done                   ( c2_cal_done       )
         //PICO_MODEL_M503
      `elsif PICO_MODEL_EX600
         // user multi-port interface
            `ifdef  UM_PREPEND_COMMA , `endif
            `define UM_PREPEND_COMMA
            
         .qdrii_sys_rst                 ( qdrii_sys_rst     ), 
      
         //---------------------------------------------
         // QDRII 0
         
         .c0_user_wr_cmd0               ( c0_user_wr_cmd0   ),
         .c0_user_wr_cmd1               ( c0_user_wr_cmd1   ),
         .c0_user_wr_addr0              ( c0_user_wr_addr0  ),
         .c0_user_wr_addr1              ( c0_user_wr_addr1  ),
         .c0_user_rd_cmd0               ( c0_user_rd_cmd0   ),
         .c0_user_rd_cmd1               ( c0_user_rd_cmd1   ),
         .c0_user_rd_addr0              ( c0_user_rd_addr0  ),
         .c0_user_rd_addr1              ( c0_user_rd_addr1  ),
         .c0_user_wr_data0              ( c0_user_wr_data0  ),
         .c0_user_wr_data1              ( c0_user_wr_data1  ),
         .c0_user_wr_bw_n0              ( c0_user_wr_bw_n0  ),
         .c0_user_wr_bw_n1              ( c0_user_wr_bw_n1  ),
         .c0_clk_tb                     ( c0_clk_tb         ),
         .c0_rst_clk_tb                 ( c0_rst_clk_tb     ),
         .c0_user_rd_valid0             ( c0_user_rd_valid0 ),
         .c0_user_rd_valid1             ( c0_user_rd_valid1 ),
         .c0_user_rd_data0              ( c0_user_rd_data0  ),
         .c0_user_rd_data1              ( c0_user_rd_data1  ),
         .c0_cal_done                   ( c0_cal_done       ),

         //---------------------------------------------
         // QDRII 1
         
         .c1_user_wr_cmd0               ( c1_user_wr_cmd0   ),
         .c1_user_wr_cmd1               ( c1_user_wr_cmd1   ),
         .c1_user_wr_addr0              ( c1_user_wr_addr0  ),
         .c1_user_wr_addr1              ( c1_user_wr_addr1  ),
         .c1_user_rd_cmd0               ( c1_user_rd_cmd0   ),
         .c1_user_rd_cmd1               ( c1_user_rd_cmd1   ),
         .c1_user_rd_addr0              ( c1_user_rd_addr0  ),
         .c1_user_rd_addr1              ( c1_user_rd_addr1  ),
         .c1_user_wr_data0              ( c1_user_wr_data0  ),
         .c1_user_wr_data1              ( c1_user_wr_data1  ),
         .c1_user_wr_bw_n0              ( c1_user_wr_bw_n0  ),
         .c1_user_wr_bw_n1              ( c1_user_wr_bw_n1  ),
         .c1_clk_tb                     ( c1_clk_tb         ),
         .c1_rst_clk_tb                 ( c1_rst_clk_tb     ),
         .c1_user_rd_valid0             ( c1_user_rd_valid0 ),
         .c1_user_rd_valid1             ( c1_user_rd_valid1 ),
         .c1_user_rd_data0              ( c1_user_rd_data0  ),
         .c1_user_rd_data1              ( c1_user_rd_data1  ),
         .c1_cal_done                   ( c1_cal_done       )
          
         `endif //PICO_MODEL_EX600
      `endif //PICO_QDRII
      
      
      `ifdef PICO_DDR3 //TODO better name
        // user multi-port interface
            `ifdef  UM_PREPEND_COMMA , `endif
            `define UM_PREPEND_COMMA

        `ifdef PICO_MODEL_M503
         //---------------------------------------------
         // DDR3 1 AXI
         
    `ifdef PICO_AXI_PORT_1 
         // Slave 1 Interface
         .c1_s1_axi_clk             ( c1_axi_clk    [1] ),

         // Slave Interface Write Address Ports
         .c1_s1_axi_awid            ( c1_axi_awid   [1] ), 
         .c1_s1_axi_awaddr          ( c1_axi_awaddr [1] ), 
         .c1_s1_axi_awlen           ( c1_axi_awlen  [1] ), 
         .c1_s1_axi_awsize          ( c1_axi_awsize [1] ), 
         .c1_s1_axi_awburst         ( c1_axi_awburst[1] ),
         .c1_s1_axi_awlock          ( c1_axi_awlock [1] ), 
         .c1_s1_axi_awcache         ( c1_axi_awcache[1] ),
         .c1_s1_axi_awprot          ( c1_axi_awprot [1] ), 
         .c1_s1_axi_awqos           ( c1_axi_awqos  [1] ), 
         .c1_s1_axi_awvalid         ( c1_axi_awvalid[1] ),
         .c1_s1_axi_awready         ( c1_axi_awready[1] ),
         
         // Slave Interface Write Data Ports
         .c1_s1_axi_wdata           ( c1_axi_wdata  [1] ),
         .c1_s1_axi_wstrb           ( c1_axi_wstrb  [1] ),
         .c1_s1_axi_wlast           ( c1_axi_wlast  [1] ),
         .c1_s1_axi_wvalid          ( c1_axi_wvalid [1] ),
         .c1_s1_axi_wready          ( c1_axi_wready [1] ),
         
         // Slave Interface Write Response Ports
         .c1_s1_axi_bid             ( c1_axi_bid    [1] ), 
         .c1_s1_axi_bresp           ( c1_axi_bresp  [1] ),
         .c1_s1_axi_bvalid          ( c1_axi_bvalid [1] ),
         .c1_s1_axi_bready          ( c1_axi_bready [1] ),
        
         // Slave Interface Read Address Ports
         .c1_s1_axi_arid            ( c1_axi_arid   [1] ), 
         .c1_s1_axi_araddr          ( c1_axi_araddr [1] ),
         .c1_s1_axi_arlen           ( c1_axi_arlen  [1] ),
         .c1_s1_axi_arsize          ( c1_axi_arsize [1] ),
         .c1_s1_axi_arburst         ( c1_axi_arburst[1] ),
         .c1_s1_axi_arlock          ( c1_axi_arlock [1] ),
         .c1_s1_axi_arcache         ( c1_axi_arcache[1] ),
         .c1_s1_axi_arprot          ( c1_axi_arprot [1] ),
         .c1_s1_axi_arqos           ( c1_axi_arqos  [1] ),
         .c1_s1_axi_arvalid         ( c1_axi_arvalid[1] ),
         .c1_s1_axi_arready         ( c1_axi_arready[1] ),
         
         // Slave Interface Read Data Ports   
         .c1_s1_axi_rid             ( c1_axi_rid    [1] ),
         .c1_s1_axi_rdata           ( c1_axi_rdata  [1] ),
         .c1_s1_axi_rresp           ( c1_axi_rresp  [1] ),
         .c1_s1_axi_rlast           ( c1_axi_rlast  [1] ),
         .c1_s1_axi_rvalid          ( c1_axi_rvalid [1] ),
         .c1_s1_axi_rready          ( c1_axi_rready [1] ),
    `endif // PICO_AXI_PORT_1

    `ifdef PICO_AXI_PORT_2
         // Slave 2 Interface
         .c1_s2_axi_clk             ( c1_axi_clk    [2] ),

         // Slave Interface Write Address Ports
         .c1_s2_axi_awid            ( c1_axi_awid   [2] ), 
         .c1_s2_axi_awaddr          ( c1_axi_awaddr [2] ), 
         .c1_s2_axi_awlen           ( c1_axi_awlen  [2] ), 
         .c1_s2_axi_awsize          ( c1_axi_awsize [2] ), 
         .c1_s2_axi_awburst         ( c1_axi_awburst[2] ),
         .c1_s2_axi_awlock          ( c1_axi_awlock [2] ), 
         .c1_s2_axi_awcache         ( c1_axi_awcache[2] ),
         .c1_s2_axi_awprot          ( c1_axi_awprot [2] ), 
         .c1_s2_axi_awqos           ( c1_axi_awqos  [2] ), 
         .c1_s2_axi_awvalid         ( c1_axi_awvalid[2] ),
         .c1_s2_axi_awready         ( c1_axi_awready[2] ),
         
         // Slave Interface Write Data Ports
         .c1_s2_axi_wdata           ( c1_axi_wdata  [2] ),
         .c1_s2_axi_wstrb           ( c1_axi_wstrb  [2] ),
         .c1_s2_axi_wlast           ( c1_axi_wlast  [2] ),
         .c1_s2_axi_wvalid          ( c1_axi_wvalid [2] ),
         .c1_s2_axi_wready          ( c1_axi_wready [2] ),
         
         // Slave Interface Write Response Ports
         .c1_s2_axi_bid             ( c1_axi_bid    [2] ), 
         .c1_s2_axi_bresp           ( c1_axi_bresp  [2] ),
         .c1_s2_axi_bvalid          ( c1_axi_bvalid [2] ),
         .c1_s2_axi_bready          ( c1_axi_bready [2] ),
        
         // Slave Interface Read Address Ports
         .c1_s2_axi_arid            ( c1_axi_arid   [2] ), 
         .c1_s2_axi_araddr          ( c1_axi_araddr [2] ),
         .c1_s2_axi_arlen           ( c1_axi_arlen  [2] ),
         .c1_s2_axi_arsize          ( c1_axi_arsize [2] ),
         .c1_s2_axi_arburst         ( c1_axi_arburst[2] ),
         .c1_s2_axi_arlock          ( c1_axi_arlock [2] ),
         .c1_s2_axi_arcache         ( c1_axi_arcache[2] ),
         .c1_s2_axi_arprot          ( c1_axi_arprot [2] ),
         .c1_s2_axi_arqos           ( c1_axi_arqos  [2] ),
         .c1_s2_axi_arvalid         ( c1_axi_arvalid[2] ),
         .c1_s2_axi_arready         ( c1_axi_arready[2] ),
         
         // Slave Interface Read Data Ports   
         .c1_s2_axi_rid             ( c1_axi_rid    [2] ),
         .c1_s2_axi_rdata           ( c1_axi_rdata  [2] ),
         .c1_s2_axi_rresp           ( c1_axi_rresp  [2] ),
         .c1_s2_axi_rlast           ( c1_axi_rlast  [2] ),
         .c1_s2_axi_rvalid          ( c1_axi_rvalid [2] ),
         .c1_s2_axi_rready          ( c1_axi_rready [2] ),
    `endif // PICO_AXI_PORT_2

    `ifdef PICO_AXI_PORT_3
         // Slave 3 Interface
         .c1_s3_axi_clk             ( c1_axi_clk    [3] ),

         // Slave Interface Write Address Ports
         .c1_s3_axi_awid            ( c1_axi_awid   [3] ), 
         .c1_s3_axi_awaddr          ( c1_axi_awaddr [3] ), 
         .c1_s3_axi_awlen           ( c1_axi_awlen  [3] ), 
         .c1_s3_axi_awsize          ( c1_axi_awsize [3] ), 
         .c1_s3_axi_awburst         ( c1_axi_awburst[3] ),
         .c1_s3_axi_awlock          ( c1_axi_awlock [3] ), 
         .c1_s3_axi_awcache         ( c1_axi_awcache[3] ),
         .c1_s3_axi_awprot          ( c1_axi_awprot [3] ), 
         .c1_s3_axi_awqos           ( c1_axi_awqos  [3] ), 
         .c1_s3_axi_awvalid         ( c1_axi_awvalid[3] ),
         .c1_s3_axi_awready         ( c1_axi_awready[3] ),
         
         // Slave Interface Write Data Ports
         .c1_s3_axi_wdata           ( c1_axi_wdata  [3] ),
         .c1_s3_axi_wstrb           ( c1_axi_wstrb  [3] ),
         .c1_s3_axi_wlast           ( c1_axi_wlast  [3] ),
         .c1_s3_axi_wvalid          ( c1_axi_wvalid [3] ),
         .c1_s3_axi_wready          ( c1_axi_wready [3] ),
         
         // Slave Interface Write Response Ports
         .c1_s3_axi_bid             ( c1_axi_bid    [3] ), 
         .c1_s3_axi_bresp           ( c1_axi_bresp  [3] ),
         .c1_s3_axi_bvalid          ( c1_axi_bvalid [3] ),
         .c1_s3_axi_bready          ( c1_axi_bready [3] ),
        
         // Slave Interface Read Address Ports
         .c1_s3_axi_arid            ( c1_axi_arid   [3] ), 
         .c1_s3_axi_araddr          ( c1_axi_araddr [3] ),
         .c1_s3_axi_arlen           ( c1_axi_arlen  [3] ),
         .c1_s3_axi_arsize          ( c1_axi_arsize [3] ),
         .c1_s3_axi_arburst         ( c1_axi_arburst[3] ),
         .c1_s3_axi_arlock          ( c1_axi_arlock [3] ),
         .c1_s3_axi_arcache         ( c1_axi_arcache[3] ),
         .c1_s3_axi_arprot          ( c1_axi_arprot [3] ),
         .c1_s3_axi_arqos           ( c1_axi_arqos  [3] ),
         .c1_s3_axi_arvalid         ( c1_axi_arvalid[3] ),
         .c1_s3_axi_arready         ( c1_axi_arready[3] ),
         
         // Slave Interface Read Data Ports   
         .c1_s3_axi_rid             ( c1_axi_rid    [3] ),
         .c1_s3_axi_rdata           ( c1_axi_rdata  [3] ),
         .c1_s3_axi_rresp           ( c1_axi_rresp  [3] ),
         .c1_s3_axi_rlast           ( c1_axi_rlast  [3] ),
         .c1_s3_axi_rvalid          ( c1_axi_rvalid [3] ),
         .c1_s3_axi_rready          ( c1_axi_rready [3] ),
    `endif // PICO_AXI_PORT_3
   
    `ifdef PICO_AXI_PORT_4
         // Slave 4 Interface
         .c1_s4_axi_clk             ( c1_axi_clk    [4] ),

         // Slave Interface Write Address Ports
         .c1_s4_axi_awid            ( c1_axi_awid   [4] ), 
         .c1_s4_axi_awaddr          ( c1_axi_awaddr [4] ), 
         .c1_s4_axi_awlen           ( c1_axi_awlen  [4] ), 
         .c1_s4_axi_awsize          ( c1_axi_awsize [4] ), 
         .c1_s4_axi_awburst         ( c1_axi_awburst[4] ),
         .c1_s4_axi_awlock          ( c1_axi_awlock [4] ), 
         .c1_s4_axi_awcache         ( c1_axi_awcache[4] ),
         .c1_s4_axi_awprot          ( c1_axi_awprot [4] ), 
         .c1_s4_axi_awqos           ( c1_axi_awqos  [4] ), 
         .c1_s4_axi_awvalid         ( c1_axi_awvalid[4] ),
         .c1_s4_axi_awready         ( c1_axi_awready[4] ),
         
         // Slave Interface Write Data Ports
         .c1_s4_axi_wdata           ( c1_axi_wdata  [4] ),
         .c1_s4_axi_wstrb           ( c1_axi_wstrb  [4] ),
         .c1_s4_axi_wlast           ( c1_axi_wlast  [4] ),
         .c1_s4_axi_wvalid          ( c1_axi_wvalid [4] ),
         .c1_s4_axi_wready          ( c1_axi_wready [4] ),
         
         // Slave Interface Write Response Ports
         .c1_s4_axi_bid             ( c1_axi_bid    [4] ), 
         .c1_s4_axi_bresp           ( c1_axi_bresp  [4] ),
         .c1_s4_axi_bvalid          ( c1_axi_bvalid [4] ),
         .c1_s4_axi_bready          ( c1_axi_bready [4] ),
        
         // Slave Interface Read Address Ports
         .c1_s4_axi_arid            ( c1_axi_arid   [4] ), 
         .c1_s4_axi_araddr          ( c1_axi_araddr [4] ),
         .c1_s4_axi_arlen           ( c1_axi_arlen  [4] ),
         .c1_s4_axi_arsize          ( c1_axi_arsize [4] ),
         .c1_s4_axi_arburst         ( c1_axi_arburst[4] ),
         .c1_s4_axi_arlock          ( c1_axi_arlock [4] ),
         .c1_s4_axi_arcache         ( c1_axi_arcache[4] ),
         .c1_s4_axi_arprot          ( c1_axi_arprot [4] ),
         .c1_s4_axi_arqos           ( c1_axi_arqos  [4] ),
         .c1_s4_axi_arvalid         ( c1_axi_arvalid[4] ),
         .c1_s4_axi_arready         ( c1_axi_arready[4] ),
         
         // Slave Interface Read Data Ports   
         .c1_s4_axi_rid             ( c1_axi_rid    [4] ),
         .c1_s4_axi_rdata           ( c1_axi_rdata  [4] ),
         .c1_s4_axi_rresp           ( c1_axi_rresp  [4] ),
         .c1_s4_axi_rlast           ( c1_axi_rlast  [4] ),
         .c1_s4_axi_rvalid          ( c1_axi_rvalid [4] ),
         .c1_s4_axi_rready          ( c1_axi_rready [4] ),
    `endif // PICO_AXI_PORT_4

    `ifdef PICO_AXI_PORT_5
         // Slave 5 Interface
         .c1_s5_axi_clk             ( c1_axi_clk    [5] ),

         // Slave Interface Write Address Ports
         .c1_s5_axi_awid            ( c1_axi_awid   [5] ), 
         .c1_s5_axi_awaddr          ( c1_axi_awaddr [5] ), 
         .c1_s5_axi_awlen           ( c1_axi_awlen  [5] ), 
         .c1_s5_axi_awsize          ( c1_axi_awsize [5] ), 
         .c1_s5_axi_awburst         ( c1_axi_awburst[5] ),
         .c1_s5_axi_awlock          ( c1_axi_awlock [5] ), 
         .c1_s5_axi_awcache         ( c1_axi_awcache[5] ),
         .c1_s5_axi_awprot          ( c1_axi_awprot [5] ), 
         .c1_s5_axi_awqos           ( c1_axi_awqos  [5] ), 
         .c1_s5_axi_awvalid         ( c1_axi_awvalid[5] ),
         .c1_s5_axi_awready         ( c1_axi_awready[5] ),
         
         // Slave Interface Write Data Ports
         .c1_s5_axi_wdata           ( c1_axi_wdata  [5] ),
         .c1_s5_axi_wstrb           ( c1_axi_wstrb  [5] ),
         .c1_s5_axi_wlast           ( c1_axi_wlast  [5] ),
         .c1_s5_axi_wvalid          ( c1_axi_wvalid [5] ),
         .c1_s5_axi_wready          ( c1_axi_wready [5] ),
         
         // Slave Interface Write Response Ports
         .c1_s5_axi_bid             ( c1_axi_bid    [5] ), 
         .c1_s5_axi_bresp           ( c1_axi_bresp  [5] ),
         .c1_s5_axi_bvalid          ( c1_axi_bvalid [5] ),
         .c1_s5_axi_bready          ( c1_axi_bready [5] ),
        
         // Slave Interface Read Address Ports
         .c1_s5_axi_arid            ( c1_axi_arid   [5] ), 
         .c1_s5_axi_araddr          ( c1_axi_araddr [5] ),
         .c1_s5_axi_arlen           ( c1_axi_arlen  [5] ),
         .c1_s5_axi_arsize          ( c1_axi_arsize [5] ),
         .c1_s5_axi_arburst         ( c1_axi_arburst[5] ),
         .c1_s5_axi_arlock          ( c1_axi_arlock [5] ),
         .c1_s5_axi_arcache         ( c1_axi_arcache[5] ),
         .c1_s5_axi_arprot          ( c1_axi_arprot [5] ),
         .c1_s5_axi_arqos           ( c1_axi_arqos  [5] ),
         .c1_s5_axi_arvalid         ( c1_axi_arvalid[5] ),
         .c1_s5_axi_arready         ( c1_axi_arready[5] ),
         
         // Slave Interface Read Data Ports   
         .c1_s5_axi_rid             ( c1_axi_rid    [5] ),
         .c1_s5_axi_rdata           ( c1_axi_rdata  [5] ),
         .c1_s5_axi_rresp           ( c1_axi_rresp  [5] ),
         .c1_s5_axi_rlast           ( c1_axi_rlast  [5] ),
         .c1_s5_axi_rvalid          ( c1_axi_rvalid [5] ),
         .c1_s5_axi_rready          ( c1_axi_rready [5] ),
    `endif // PICO_AXI_PORT_5

    `ifdef PICO_AXI_PORT_6
         // Slave 6 Interface
         .c1_s6_axi_clk             ( c1_axi_clk    [6] ),

         // Slave Interface Write Address Ports
         .c1_s6_axi_awid            ( c1_axi_awid   [6] ), 
         .c1_s6_axi_awaddr          ( c1_axi_awaddr [6] ), 
         .c1_s6_axi_awlen           ( c1_axi_awlen  [6] ), 
         .c1_s6_axi_awsize          ( c1_axi_awsize [6] ), 
         .c1_s6_axi_awburst         ( c1_axi_awburst[6] ),
         .c1_s6_axi_awlock          ( c1_axi_awlock [6] ), 
         .c1_s6_axi_awcache         ( c1_axi_awcache[6] ),
         .c1_s6_axi_awprot          ( c1_axi_awprot [6] ), 
         .c1_s6_axi_awqos           ( c1_axi_awqos  [6] ), 
         .c1_s6_axi_awvalid         ( c1_axi_awvalid[6] ),
         .c1_s6_axi_awready         ( c1_axi_awready[6] ),
         
         // Slave Interface Write Data Ports
         .c1_s6_axi_wdata           ( c1_axi_wdata  [6] ),
         .c1_s6_axi_wstrb           ( c1_axi_wstrb  [6] ),
         .c1_s6_axi_wlast           ( c1_axi_wlast  [6] ),
         .c1_s6_axi_wvalid          ( c1_axi_wvalid [6] ),
         .c1_s6_axi_wready          ( c1_axi_wready [6] ),
         
         // Slave Interface Write Response Ports
         .c1_s6_axi_bid             ( c1_axi_bid    [6] ), 
         .c1_s6_axi_bresp           ( c1_axi_bresp  [6] ),
         .c1_s6_axi_bvalid          ( c1_axi_bvalid [6] ),
         .c1_s6_axi_bready          ( c1_axi_bready [6] ),
        
         // Slave Interface Read Address Ports
         .c1_s6_axi_arid            ( c1_axi_arid   [6] ), 
         .c1_s6_axi_araddr          ( c1_axi_araddr [6] ),
         .c1_s6_axi_arlen           ( c1_axi_arlen  [6] ),
         .c1_s6_axi_arsize          ( c1_axi_arsize [6] ),
         .c1_s6_axi_arburst         ( c1_axi_arburst[6] ),
         .c1_s6_axi_arlock          ( c1_axi_arlock [6] ),
         .c1_s6_axi_arcache         ( c1_axi_arcache[6] ),
         .c1_s6_axi_arprot          ( c1_axi_arprot [6] ),
         .c1_s6_axi_arqos           ( c1_axi_arqos  [6] ),
         .c1_s6_axi_arvalid         ( c1_axi_arvalid[6] ),
         .c1_s6_axi_arready         ( c1_axi_arready[6] ),
         
         // Slave Interface Read Data Ports   
         .c1_s6_axi_rid             ( c1_axi_rid    [6] ),
         .c1_s6_axi_rdata           ( c1_axi_rdata  [6] ),
         .c1_s6_axi_rresp           ( c1_axi_rresp  [6] ),
         .c1_s6_axi_rlast           ( c1_axi_rlast  [6] ),
         .c1_s6_axi_rvalid          ( c1_axi_rvalid [6] ),
         .c1_s6_axi_rready          ( c1_axi_rready [6] ),
    `endif // PICO_AXI_PORT_6
    
    `ifdef PICO_AXI_PORT_7
         // Slave 7 Interface
         .c1_s7_axi_clk             ( c1_axi_clk    [7] ),

         // Slave Interface Write Address Ports
         .c1_s7_axi_awid            ( c1_axi_awid   [7] ), 
         .c1_s7_axi_awaddr          ( c1_axi_awaddr [7] ), 
         .c1_s7_axi_awlen           ( c1_axi_awlen  [7] ), 
         .c1_s7_axi_awsize          ( c1_axi_awsize [7] ), 
         .c1_s7_axi_awburst         ( c1_axi_awburst[7] ),
         .c1_s7_axi_awlock          ( c1_axi_awlock [7] ), 
         .c1_s7_axi_awcache         ( c1_axi_awcache[7] ),
         .c1_s7_axi_awprot          ( c1_axi_awprot [7] ), 
         .c1_s7_axi_awqos           ( c1_axi_awqos  [7] ), 
         .c1_s7_axi_awvalid         ( c1_axi_awvalid[7] ),
         .c1_s7_axi_awready         ( c1_axi_awready[7] ),
         
         // Slave Interface Write Data Ports
         .c1_s7_axi_wdata           ( c1_axi_wdata  [7] ),
         .c1_s7_axi_wstrb           ( c1_axi_wstrb  [7] ),
         .c1_s7_axi_wlast           ( c1_axi_wlast  [7] ),
         .c1_s7_axi_wvalid          ( c1_axi_wvalid [7] ),
         .c1_s7_axi_wready          ( c1_axi_wready [7] ),
         
         // Slave Interface Write Response Ports
         .c1_s7_axi_bid             ( c1_axi_bid    [7] ), 
         .c1_s7_axi_bresp           ( c1_axi_bresp  [7] ),
         .c1_s7_axi_bvalid          ( c1_axi_bvalid [7] ),
         .c1_s7_axi_bready          ( c1_axi_bready [7] ),
        
         // Slave Interface Read Address Ports
         .c1_s7_axi_arid            ( c1_axi_arid   [7] ), 
         .c1_s7_axi_araddr          ( c1_axi_araddr [7] ),
         .c1_s7_axi_arlen           ( c1_axi_arlen  [7] ),
         .c1_s7_axi_arsize          ( c1_axi_arsize [7] ),
         .c1_s7_axi_arburst         ( c1_axi_arburst[7] ),
         .c1_s7_axi_arlock          ( c1_axi_arlock [7] ),
         .c1_s7_axi_arcache         ( c1_axi_arcache[7] ),
         .c1_s7_axi_arprot          ( c1_axi_arprot [7] ),
         .c1_s7_axi_arqos           ( c1_axi_arqos  [7] ),
         .c1_s7_axi_arvalid         ( c1_axi_arvalid[7] ),
         .c1_s7_axi_arready         ( c1_axi_arready[7] ),
         
         // Slave Interface Read Data Ports   
         .c1_s7_axi_rid             ( c1_axi_rid    [7] ),
         .c1_s7_axi_rdata           ( c1_axi_rdata  [7] ),
         .c1_s7_axi_rresp           ( c1_axi_rresp  [7] ),
         .c1_s7_axi_rlast           ( c1_axi_rlast  [7] ),
         .c1_s7_axi_rvalid          ( c1_axi_rvalid [7] ),
         .c1_s7_axi_rready          ( c1_axi_rready [7] ),
    `endif // PICO_AXI_PORT_7

         // AXI clock and reset
         .c1_axi_clk                ( c1_tb_clk         ),
         .c1_phy_init_done          ( c1_phy_init_done  ),
         .c1_axi_rst                ( c1_tb_rst         ),
        `endif // PICO_MODEL_M503	
            
         //---------------------------------------------
         // DDR3 0 AXI
         
    `ifdef PICO_AXI_PORT_1 
         // Slave 1 Interface
         .c0_s1_axi_clk             ( c0_axi_clk    [1] ),

         // Slave Interface Write Address Ports
         .c0_s1_axi_awid            ( c0_axi_awid   [1] ), 
         .c0_s1_axi_awaddr          ( c0_axi_awaddr [1] ), 
         .c0_s1_axi_awlen           ( c0_axi_awlen  [1] ), 
         .c0_s1_axi_awsize          ( c0_axi_awsize [1] ), 
         .c0_s1_axi_awburst         ( c0_axi_awburst[1] ),
         .c0_s1_axi_awlock          ( c0_axi_awlock [1] ), 
         .c0_s1_axi_awcache         ( c0_axi_awcache[1] ),
         .c0_s1_axi_awprot          ( c0_axi_awprot [1] ), 
         .c0_s1_axi_awqos           ( c0_axi_awqos  [1] ), 
         .c0_s1_axi_awvalid         ( c0_axi_awvalid[1] ),
         .c0_s1_axi_awready         ( c0_axi_awready[1] ),
         
         // Slave Interface Write Data Ports
         .c0_s1_axi_wdata           ( c0_axi_wdata  [1] ),
         .c0_s1_axi_wstrb           ( c0_axi_wstrb  [1] ),
         .c0_s1_axi_wlast           ( c0_axi_wlast  [1] ),
         .c0_s1_axi_wvalid          ( c0_axi_wvalid [1] ),
         .c0_s1_axi_wready          ( c0_axi_wready [1] ),
         
         // Slave Interface Write Response Ports
         .c0_s1_axi_bid             ( c0_axi_bid    [1] ), 
         .c0_s1_axi_bresp           ( c0_axi_bresp  [1] ),
         .c0_s1_axi_bvalid          ( c0_axi_bvalid [1] ),
         .c0_s1_axi_bready          ( c0_axi_bready [1] ),
        
         // Slave Interface Read Address Ports
         .c0_s1_axi_arid            ( c0_axi_arid   [1] ), 
         .c0_s1_axi_araddr          ( c0_axi_araddr [1] ),
         .c0_s1_axi_arlen           ( c0_axi_arlen  [1] ),
         .c0_s1_axi_arsize          ( c0_axi_arsize [1] ),
         .c0_s1_axi_arburst         ( c0_axi_arburst[1] ),
         .c0_s1_axi_arlock          ( c0_axi_arlock [1] ),
         .c0_s1_axi_arcache         ( c0_axi_arcache[1] ),
         .c0_s1_axi_arprot          ( c0_axi_arprot [1] ),
         .c0_s1_axi_arqos           ( c0_axi_arqos  [1] ),
         .c0_s1_axi_arvalid         ( c0_axi_arvalid[1] ),
         .c0_s1_axi_arready         ( c0_axi_arready[1] ),
         
         // Slave Interface Read Data Ports   
         .c0_s1_axi_rid             ( c0_axi_rid    [1] ),
         .c0_s1_axi_rdata           ( c0_axi_rdata  [1] ),
         .c0_s1_axi_rresp           ( c0_axi_rresp  [1] ),
         .c0_s1_axi_rlast           ( c0_axi_rlast  [1] ),
         .c0_s1_axi_rvalid          ( c0_axi_rvalid [1] ),
         .c0_s1_axi_rready          ( c0_axi_rready [1] ),
    `endif // PICO_AXI_PORT_1

    `ifdef PICO_AXI_PORT_2
         // Slave 2 Interface
         .c0_s2_axi_clk             ( c0_axi_clk    [2] ),

         // Slave Interface Write Address Ports
         .c0_s2_axi_awid            ( c0_axi_awid   [2] ), 
         .c0_s2_axi_awaddr          ( c0_axi_awaddr [2] ), 
         .c0_s2_axi_awlen           ( c0_axi_awlen  [2] ), 
         .c0_s2_axi_awsize          ( c0_axi_awsize [2] ), 
         .c0_s2_axi_awburst         ( c0_axi_awburst[2] ),
         .c0_s2_axi_awlock          ( c0_axi_awlock [2] ), 
         .c0_s2_axi_awcache         ( c0_axi_awcache[2] ),
         .c0_s2_axi_awprot          ( c0_axi_awprot [2] ), 
         .c0_s2_axi_awqos           ( c0_axi_awqos  [2] ), 
         .c0_s2_axi_awvalid         ( c0_axi_awvalid[2] ),
         .c0_s2_axi_awready         ( c0_axi_awready[2] ),
         
         // Slave Interface Write Data Ports
         .c0_s2_axi_wdata           ( c0_axi_wdata  [2] ),
         .c0_s2_axi_wstrb           ( c0_axi_wstrb  [2] ),
         .c0_s2_axi_wlast           ( c0_axi_wlast  [2] ),
         .c0_s2_axi_wvalid          ( c0_axi_wvalid [2] ),
         .c0_s2_axi_wready          ( c0_axi_wready [2] ),
         
         // Slave Interface Write Response Ports
         .c0_s2_axi_bid             ( c0_axi_bid    [2] ), 
         .c0_s2_axi_bresp           ( c0_axi_bresp  [2] ),
         .c0_s2_axi_bvalid          ( c0_axi_bvalid [2] ),
         .c0_s2_axi_bready          ( c0_axi_bready [2] ),
        
         // Slave Interface Read Address Ports
         .c0_s2_axi_arid            ( c0_axi_arid   [2] ), 
         .c0_s2_axi_araddr          ( c0_axi_araddr [2] ),
         .c0_s2_axi_arlen           ( c0_axi_arlen  [2] ),
         .c0_s2_axi_arsize          ( c0_axi_arsize [2] ),
         .c0_s2_axi_arburst         ( c0_axi_arburst[2] ),
         .c0_s2_axi_arlock          ( c0_axi_arlock [2] ),
         .c0_s2_axi_arcache         ( c0_axi_arcache[2] ),
         .c0_s2_axi_arprot          ( c0_axi_arprot [2] ),
         .c0_s2_axi_arqos           ( c0_axi_arqos  [2] ),
         .c0_s2_axi_arvalid         ( c0_axi_arvalid[2] ),
         .c0_s2_axi_arready         ( c0_axi_arready[2] ),
         
         // Slave Interface Read Data Ports   
         .c0_s2_axi_rid             ( c0_axi_rid    [2] ),
         .c0_s2_axi_rdata           ( c0_axi_rdata  [2] ),
         .c0_s2_axi_rresp           ( c0_axi_rresp  [2] ),
         .c0_s2_axi_rlast           ( c0_axi_rlast  [2] ),
         .c0_s2_axi_rvalid          ( c0_axi_rvalid [2] ),
         .c0_s2_axi_rready          ( c0_axi_rready [2] ),
    `endif // PICO_AXI_PORT_2

    `ifdef PICO_AXI_PORT_3
         // Slave 3 Interface
         .c0_s3_axi_clk             ( c0_axi_clk    [3] ),

         // Slave Interface Write Address Ports
         .c0_s3_axi_awid            ( c0_axi_awid   [3] ), 
         .c0_s3_axi_awaddr          ( c0_axi_awaddr [3] ), 
         .c0_s3_axi_awlen           ( c0_axi_awlen  [3] ), 
         .c0_s3_axi_awsize          ( c0_axi_awsize [3] ), 
         .c0_s3_axi_awburst         ( c0_axi_awburst[3] ),
         .c0_s3_axi_awlock          ( c0_axi_awlock [3] ), 
         .c0_s3_axi_awcache         ( c0_axi_awcache[3] ),
         .c0_s3_axi_awprot          ( c0_axi_awprot [3] ), 
         .c0_s3_axi_awqos           ( c0_axi_awqos  [3] ), 
         .c0_s3_axi_awvalid         ( c0_axi_awvalid[3] ),
         .c0_s3_axi_awready         ( c0_axi_awready[3] ),
         
         // Slave Interface Write Data Ports
         .c0_s3_axi_wdata           ( c0_axi_wdata  [3] ),
         .c0_s3_axi_wstrb           ( c0_axi_wstrb  [3] ),
         .c0_s3_axi_wlast           ( c0_axi_wlast  [3] ),
         .c0_s3_axi_wvalid          ( c0_axi_wvalid [3] ),
         .c0_s3_axi_wready          ( c0_axi_wready [3] ),
         
         // Slave Interface Write Response Ports
         .c0_s3_axi_bid             ( c0_axi_bid    [3] ), 
         .c0_s3_axi_bresp           ( c0_axi_bresp  [3] ),
         .c0_s3_axi_bvalid          ( c0_axi_bvalid [3] ),
         .c0_s3_axi_bready          ( c0_axi_bready [3] ),
        
         // Slave Interface Read Address Ports
         .c0_s3_axi_arid            ( c0_axi_arid   [3] ), 
         .c0_s3_axi_araddr          ( c0_axi_araddr [3] ),
         .c0_s3_axi_arlen           ( c0_axi_arlen  [3] ),
         .c0_s3_axi_arsize          ( c0_axi_arsize [3] ),
         .c0_s3_axi_arburst         ( c0_axi_arburst[3] ),
         .c0_s3_axi_arlock          ( c0_axi_arlock [3] ),
         .c0_s3_axi_arcache         ( c0_axi_arcache[3] ),
         .c0_s3_axi_arprot          ( c0_axi_arprot [3] ),
         .c0_s3_axi_arqos           ( c0_axi_arqos  [3] ),
         .c0_s3_axi_arvalid         ( c0_axi_arvalid[3] ),
         .c0_s3_axi_arready         ( c0_axi_arready[3] ),
         
         // Slave Interface Read Data Ports   
         .c0_s3_axi_rid             ( c0_axi_rid    [3] ),
         .c0_s3_axi_rdata           ( c0_axi_rdata  [3] ),
         .c0_s3_axi_rresp           ( c0_axi_rresp  [3] ),
         .c0_s3_axi_rlast           ( c0_axi_rlast  [3] ),
         .c0_s3_axi_rvalid          ( c0_axi_rvalid [3] ),
         .c0_s3_axi_rready          ( c0_axi_rready [3] ),
    `endif // PICO_AXI_PORT_3
   
    `ifdef PICO_AXI_PORT_4
         // Slave 4 Interface
         .c0_s4_axi_clk             ( c0_axi_clk    [4] ),

         // Slave Interface Write Address Ports
         .c0_s4_axi_awid            ( c0_axi_awid   [4] ), 
         .c0_s4_axi_awaddr          ( c0_axi_awaddr [4] ), 
         .c0_s4_axi_awlen           ( c0_axi_awlen  [4] ), 
         .c0_s4_axi_awsize          ( c0_axi_awsize [4] ), 
         .c0_s4_axi_awburst         ( c0_axi_awburst[4] ),
         .c0_s4_axi_awlock          ( c0_axi_awlock [4] ), 
         .c0_s4_axi_awcache         ( c0_axi_awcache[4] ),
         .c0_s4_axi_awprot          ( c0_axi_awprot [4] ), 
         .c0_s4_axi_awqos           ( c0_axi_awqos  [4] ), 
         .c0_s4_axi_awvalid         ( c0_axi_awvalid[4] ),
         .c0_s4_axi_awready         ( c0_axi_awready[4] ),
         
         // Slave Interface Write Data Ports
         .c0_s4_axi_wdata           ( c0_axi_wdata  [4] ),
         .c0_s4_axi_wstrb           ( c0_axi_wstrb  [4] ),
         .c0_s4_axi_wlast           ( c0_axi_wlast  [4] ),
         .c0_s4_axi_wvalid          ( c0_axi_wvalid [4] ),
         .c0_s4_axi_wready          ( c0_axi_wready [4] ),
         
         // Slave Interface Write Response Ports
         .c0_s4_axi_bid             ( c0_axi_bid    [4] ), 
         .c0_s4_axi_bresp           ( c0_axi_bresp  [4] ),
         .c0_s4_axi_bvalid          ( c0_axi_bvalid [4] ),
         .c0_s4_axi_bready          ( c0_axi_bready [4] ),
        
         // Slave Interface Read Address Ports
         .c0_s4_axi_arid            ( c0_axi_arid   [4] ), 
         .c0_s4_axi_araddr          ( c0_axi_araddr [4] ),
         .c0_s4_axi_arlen           ( c0_axi_arlen  [4] ),
         .c0_s4_axi_arsize          ( c0_axi_arsize [4] ),
         .c0_s4_axi_arburst         ( c0_axi_arburst[4] ),
         .c0_s4_axi_arlock          ( c0_axi_arlock [4] ),
         .c0_s4_axi_arcache         ( c0_axi_arcache[4] ),
         .c0_s4_axi_arprot          ( c0_axi_arprot [4] ),
         .c0_s4_axi_arqos           ( c0_axi_arqos  [4] ),
         .c0_s4_axi_arvalid         ( c0_axi_arvalid[4] ),
         .c0_s4_axi_arready         ( c0_axi_arready[4] ),
         
         // Slave Interface Read Data Ports   
         .c0_s4_axi_rid             ( c0_axi_rid    [4] ),
         .c0_s4_axi_rdata           ( c0_axi_rdata  [4] ),
         .c0_s4_axi_rresp           ( c0_axi_rresp  [4] ),
         .c0_s4_axi_rlast           ( c0_axi_rlast  [4] ),
         .c0_s4_axi_rvalid          ( c0_axi_rvalid [4] ),
         .c0_s4_axi_rready          ( c0_axi_rready [4] ),
    `endif // PICO_AXI_PORT_4

    `ifdef PICO_AXI_PORT_5
         // Slave 5 Interface
         .c0_s5_axi_clk             ( c0_axi_clk    [5] ),

         // Slave Interface Write Address Ports
         .c0_s5_axi_awid            ( c0_axi_awid   [5] ), 
         .c0_s5_axi_awaddr          ( c0_axi_awaddr [5] ), 
         .c0_s5_axi_awlen           ( c0_axi_awlen  [5] ), 
         .c0_s5_axi_awsize          ( c0_axi_awsize [5] ), 
         .c0_s5_axi_awburst         ( c0_axi_awburst[5] ),
         .c0_s5_axi_awlock          ( c0_axi_awlock [5] ), 
         .c0_s5_axi_awcache         ( c0_axi_awcache[5] ),
         .c0_s5_axi_awprot          ( c0_axi_awprot [5] ), 
         .c0_s5_axi_awqos           ( c0_axi_awqos  [5] ), 
         .c0_s5_axi_awvalid         ( c0_axi_awvalid[5] ),
         .c0_s5_axi_awready         ( c0_axi_awready[5] ),
         
         // Slave Interface Write Data Ports
         .c0_s5_axi_wdata           ( c0_axi_wdata  [5] ),
         .c0_s5_axi_wstrb           ( c0_axi_wstrb  [5] ),
         .c0_s5_axi_wlast           ( c0_axi_wlast  [5] ),
         .c0_s5_axi_wvalid          ( c0_axi_wvalid [5] ),
         .c0_s5_axi_wready          ( c0_axi_wready [5] ),
         
         // Slave Interface Write Response Ports
         .c0_s5_axi_bid             ( c0_axi_bid    [5] ), 
         .c0_s5_axi_bresp           ( c0_axi_bresp  [5] ),
         .c0_s5_axi_bvalid          ( c0_axi_bvalid [5] ),
         .c0_s5_axi_bready          ( c0_axi_bready [5] ),
        
         // Slave Interface Read Address Ports
         .c0_s5_axi_arid            ( c0_axi_arid   [5] ), 
         .c0_s5_axi_araddr          ( c0_axi_araddr [5] ),
         .c0_s5_axi_arlen           ( c0_axi_arlen  [5] ),
         .c0_s5_axi_arsize          ( c0_axi_arsize [5] ),
         .c0_s5_axi_arburst         ( c0_axi_arburst[5] ),
         .c0_s5_axi_arlock          ( c0_axi_arlock [5] ),
         .c0_s5_axi_arcache         ( c0_axi_arcache[5] ),
         .c0_s5_axi_arprot          ( c0_axi_arprot [5] ),
         .c0_s5_axi_arqos           ( c0_axi_arqos  [5] ),
         .c0_s5_axi_arvalid         ( c0_axi_arvalid[5] ),
         .c0_s5_axi_arready         ( c0_axi_arready[5] ),
         
         // Slave Interface Read Data Ports   
         .c0_s5_axi_rid             ( c0_axi_rid    [5] ),
         .c0_s5_axi_rdata           ( c0_axi_rdata  [5] ),
         .c0_s5_axi_rresp           ( c0_axi_rresp  [5] ),
         .c0_s5_axi_rlast           ( c0_axi_rlast  [5] ),
         .c0_s5_axi_rvalid          ( c0_axi_rvalid [5] ),
         .c0_s5_axi_rready          ( c0_axi_rready [5] ),
    `endif // PICO_AXI_PORT_5

    `ifdef PICO_AXI_PORT_6
         // Slave 6 Interface
         .c0_s6_axi_clk             ( c0_axi_clk    [6] ),

         // Slave Interface Write Address Ports
         .c0_s6_axi_awid            ( c0_axi_awid   [6] ), 
         .c0_s6_axi_awaddr          ( c0_axi_awaddr [6] ), 
         .c0_s6_axi_awlen           ( c0_axi_awlen  [6] ), 
         .c0_s6_axi_awsize          ( c0_axi_awsize [6] ), 
         .c0_s6_axi_awburst         ( c0_axi_awburst[6] ),
         .c0_s6_axi_awlock          ( c0_axi_awlock [6] ), 
         .c0_s6_axi_awcache         ( c0_axi_awcache[6] ),
         .c0_s6_axi_awprot          ( c0_axi_awprot [6] ), 
         .c0_s6_axi_awqos           ( c0_axi_awqos  [6] ), 
         .c0_s6_axi_awvalid         ( c0_axi_awvalid[6] ),
         .c0_s6_axi_awready         ( c0_axi_awready[6] ),
         
         // Slave Interface Write Data Ports
         .c0_s6_axi_wdata           ( c0_axi_wdata  [6] ),
         .c0_s6_axi_wstrb           ( c0_axi_wstrb  [6] ),
         .c0_s6_axi_wlast           ( c0_axi_wlast  [6] ),
         .c0_s6_axi_wvalid          ( c0_axi_wvalid [6] ),
         .c0_s6_axi_wready          ( c0_axi_wready [6] ),
         
         // Slave Interface Write Response Ports
         .c0_s6_axi_bid             ( c0_axi_bid    [6] ), 
         .c0_s6_axi_bresp           ( c0_axi_bresp  [6] ),
         .c0_s6_axi_bvalid          ( c0_axi_bvalid [6] ),
         .c0_s6_axi_bready          ( c0_axi_bready [6] ),
        
         // Slave Interface Read Address Ports
         .c0_s6_axi_arid            ( c0_axi_arid   [6] ), 
         .c0_s6_axi_araddr          ( c0_axi_araddr [6] ),
         .c0_s6_axi_arlen           ( c0_axi_arlen  [6] ),
         .c0_s6_axi_arsize          ( c0_axi_arsize [6] ),
         .c0_s6_axi_arburst         ( c0_axi_arburst[6] ),
         .c0_s6_axi_arlock          ( c0_axi_arlock [6] ),
         .c0_s6_axi_arcache         ( c0_axi_arcache[6] ),
         .c0_s6_axi_arprot          ( c0_axi_arprot [6] ),
         .c0_s6_axi_arqos           ( c0_axi_arqos  [6] ),
         .c0_s6_axi_arvalid         ( c0_axi_arvalid[6] ),
         .c0_s6_axi_arready         ( c0_axi_arready[6] ),
         
         // Slave Interface Read Data Ports   
         .c0_s6_axi_rid             ( c0_axi_rid    [6] ),
         .c0_s6_axi_rdata           ( c0_axi_rdata  [6] ),
         .c0_s6_axi_rresp           ( c0_axi_rresp  [6] ),
         .c0_s6_axi_rlast           ( c0_axi_rlast  [6] ),
         .c0_s6_axi_rvalid          ( c0_axi_rvalid [6] ),
         .c0_s6_axi_rready          ( c0_axi_rready [6] ),
    `endif // PICO_AXI_PORT_6
    
    `ifdef PICO_AXI_PORT_7
         // Slave 7 Interface
         .c0_s7_axi_clk             ( c0_axi_clk    [7] ),

         // Slave Interface Write Address Ports
         .c0_s7_axi_awid            ( c0_axi_awid   [7] ), 
         .c0_s7_axi_awaddr          ( c0_axi_awaddr [7] ), 
         .c0_s7_axi_awlen           ( c0_axi_awlen  [7] ), 
         .c0_s7_axi_awsize          ( c0_axi_awsize [7] ), 
         .c0_s7_axi_awburst         ( c0_axi_awburst[7] ),
         .c0_s7_axi_awlock          ( c0_axi_awlock [7] ), 
         .c0_s7_axi_awcache         ( c0_axi_awcache[7] ),
         .c0_s7_axi_awprot          ( c0_axi_awprot [7] ), 
         .c0_s7_axi_awqos           ( c0_axi_awqos  [7] ), 
         .c0_s7_axi_awvalid         ( c0_axi_awvalid[7] ),
         .c0_s7_axi_awready         ( c0_axi_awready[7] ),
         
         // Slave Interface Write Data Ports
         .c0_s7_axi_wdata           ( c0_axi_wdata  [7] ),
         .c0_s7_axi_wstrb           ( c0_axi_wstrb  [7] ),
         .c0_s7_axi_wlast           ( c0_axi_wlast  [7] ),
         .c0_s7_axi_wvalid          ( c0_axi_wvalid [7] ),
         .c0_s7_axi_wready          ( c0_axi_wready [7] ),
         
         // Slave Interface Write Response Ports
         .c0_s7_axi_bid             ( c0_axi_bid    [7] ), 
         .c0_s7_axi_bresp           ( c0_axi_bresp  [7] ),
         .c0_s7_axi_bvalid          ( c0_axi_bvalid [7] ),
         .c0_s7_axi_bready          ( c0_axi_bready [7] ),
        
         // Slave Interface Read Address Ports
         .c0_s7_axi_arid            ( c0_axi_arid   [7] ), 
         .c0_s7_axi_araddr          ( c0_axi_araddr [7] ),
         .c0_s7_axi_arlen           ( c0_axi_arlen  [7] ),
         .c0_s7_axi_arsize          ( c0_axi_arsize [7] ),
         .c0_s7_axi_arburst         ( c0_axi_arburst[7] ),
         .c0_s7_axi_arlock          ( c0_axi_arlock [7] ),
         .c0_s7_axi_arcache         ( c0_axi_arcache[7] ),
         .c0_s7_axi_arprot          ( c0_axi_arprot [7] ),
         .c0_s7_axi_arqos           ( c0_axi_arqos  [7] ),
         .c0_s7_axi_arvalid         ( c0_axi_arvalid[7] ),
         .c0_s7_axi_arready         ( c0_axi_arready[7] ),
         
         // Slave Interface Read Data Ports   
         .c0_s7_axi_rid             ( c0_axi_rid    [7] ),
         .c0_s7_axi_rdata           ( c0_axi_rdata  [7] ),
         .c0_s7_axi_rresp           ( c0_axi_rresp  [7] ),
         .c0_s7_axi_rlast           ( c0_axi_rlast  [7] ),
         .c0_s7_axi_rvalid          ( c0_axi_rvalid [7] ),
         .c0_s7_axi_rready          ( c0_axi_rready [7] ),
    `endif // PICO_AXI_PORT_7
    
         // AXI clock and reset
         .c0_axi_clk                ( c0_tb_clk         ),
         .c0_phy_init_done          ( c0_phy_init_done  ),
         .c0_axi_rst                ( c0_tb_rst         )
      `endif //PICO_DDR3
 
    //------------------------------------------------------//
    // EX-600 Interconnect Pins
    //------------------------------------------------------//
    `ifdef PICO_MODEL_EX600
        `ifdef EX600_INTERCONNECT
            `ifdef EX600_FPGA_0
                `ifdef  UM_PREPEND_COMMA , `endif
                `define UM_PREPEND_COMMA
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
                .DATA_C3                        (DATA_C3 )  
            `elsif EX600_FPGA_1
                `ifdef  UM_PREPEND_COMMA , `endif
                `define UM_PREPEND_COMMA
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
                .DATA_C3                        (DATA_C3 )  
            `elsif EX600_FPGA_2
                `ifdef  UM_PREPEND_COMMA , `endif
                `define UM_PREPEND_COMMA
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
                .DATA_L3                        (DATA_L3 )
            `elsif EX600_FPGA_3
                `ifdef  UM_PREPEND_COMMA , `endif
                `define UM_PREPEND_COMMA
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
                .DATA_L3                        (DATA_L3 )
            `elsif EX600_FPGA_4
                `ifdef  UM_PREPEND_COMMA , `endif
                `define UM_PREPEND_COMMA
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
                .DATA_L3                        (DATA_L3 )
            `elsif EX600_FPGA_5
                `ifdef  UM_PREPEND_COMMA , `endif
                `define UM_PREPEND_COMMA
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
                .DATA_L3                        (DATA_L3 )
            `else
                ERROR: FPGA number must be sepecified
            `endif
        `endif //EX600_INTERCONNECT            
    `endif //PICO_MODEL_EX600      
      
    // Below are ifdefs with the stream signals being brought in.  
    // Copy the names from the stream1 and change the 1 to what you are bringing in, format is the same throughout
    `ifdef STREAM1_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s1i_rdy(stream_in_rdy[1]),
        .s1i_valid(stream_in_valid[1]),
        .s1i_data(stream_in_data[1][`STREAM1_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM1_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s1o_rdy(stream_out_rdy[1]),
        .s1o_valid(stream_out_valid[1]),
        .s1o_data(stream_out_data[1][`STREAM1_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM2_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s2i_rdy(stream_in_rdy[2]),
        .s2i_valid(stream_in_valid[2]),
        .s2i_data(stream_in_data[2][`STREAM2_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM2_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s2o_rdy(stream_out_rdy[2]),
        .s2o_valid(stream_out_valid[2]),
        .s2o_data(stream_out_data[2][`STREAM2_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM3_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s3i_rdy(stream_in_rdy[3]),
        .s3i_valid(stream_in_valid[3]),
        .s3i_data(stream_in_data[3][`STREAM3_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM3_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s3o_rdy(stream_out_rdy[3]),
        .s3o_valid(stream_out_valid[3]),
        .s3o_data(stream_out_data[3][`STREAM3_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM4_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s4i_rdy(stream_in_rdy[4]),
        .s4i_valid(stream_in_valid[4]),
        .s4i_data(stream_in_data[4][`STREAM4_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM4_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s4o_rdy(stream_out_rdy[4]),
        .s4o_valid(stream_out_valid[4]),
        .s4o_data(stream_out_data[4][`STREAM4_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM5_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s5i_rdy(stream_in_rdy[5]),
        .s5i_valid(stream_in_valid[5]),
        .s5i_data(stream_in_data[5][`STREAM5_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM5_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s5o_rdy(stream_out_rdy[5]),
        .s5o_valid(stream_out_valid[5]),
        .s5o_data(stream_out_data[5][`STREAM5_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM6_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s6i_rdy(stream_in_rdy[6]),
        .s6i_valid(stream_in_valid[6]),
        .s6i_data(stream_in_data[6][`STREAM6_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM6_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s6o_rdy(stream_out_rdy[6]),
        .s6o_valid(stream_out_valid[6]),
        .s6o_data(stream_out_data[6][`STREAM6_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM7_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s7i_rdy(stream_in_rdy[7]),
        .s7i_valid(stream_in_valid[7]),
        .s7i_data(stream_in_data[7][`STREAM7_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM7_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s7o_rdy(stream_out_rdy[7]),
        .s7o_valid(stream_out_valid[7]),
        .s7o_data(stream_out_data[7][`STREAM7_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM8_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s8i_rdy(stream_in_rdy[8]),
        .s8i_valid(stream_in_valid[8]),
        .s8i_data(stream_in_data[8][`STREAM8_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM8_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s8o_rdy(stream_out_rdy[8]),
        .s8o_valid(stream_out_valid[8]),
        .s8o_data(stream_out_data[8][`STREAM8_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM9_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s9i_rdy(stream_in_rdy[9]),
        .s9i_valid(stream_in_valid[9]),
        .s9i_data(stream_in_data[9][`STREAM9_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM9_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s9o_rdy(stream_out_rdy[9]),
        .s9o_valid(stream_out_valid[9]),
        .s9o_data(stream_out_data[9][`STREAM9_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM10_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s10i_rdy(stream_in_rdy[10]),
        .s10i_valid(stream_in_valid[10]),
        .s10i_data(stream_in_data[10][`STREAM10_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM10_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s10o_rdy(stream_out_rdy[10]),
        .s10o_valid(stream_out_valid[10]),
        .s10o_data(stream_out_data[10][`STREAM10_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM11_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s11i_rdy(stream_in_rdy[11]),
        .s11i_valid(stream_in_valid[11]),
        .s11i_data(stream_in_data[11][`STREAM11_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM11_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s11o_rdy(stream_out_rdy[11]),
        .s11o_valid(stream_out_valid[11]),
        .s11o_data(stream_out_data[11][`STREAM11_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM12_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s12i_rdy(stream_in_rdy[12]),
        .s12i_valid(stream_in_valid[12]),
        .s12i_data(stream_in_data[12][`STREAM12_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM12_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s12o_rdy(stream_out_rdy[12]),
        .s12o_valid(stream_out_valid[12]),
        .s12o_data(stream_out_data[12][`STREAM12_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM13_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s13i_rdy(stream_in_rdy[13]),
        .s13i_valid(stream_in_valid[13]),
        .s13i_data(stream_in_data[13][`STREAM13_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM13_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s13o_rdy(stream_out_rdy[13]),
        .s13o_valid(stream_out_valid[13]),
        .s13o_data(stream_out_data[13][`STREAM13_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM14_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s14i_rdy(stream_in_rdy[14]),
        .s14i_valid(stream_in_valid[14]),
        .s14i_data(stream_in_data[14][`STREAM14_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM14_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s14o_rdy(stream_out_rdy[14]),
        .s14o_valid(stream_out_valid[14]),
        .s14o_data(stream_out_data[14][`STREAM14_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM15_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s15i_rdy(stream_in_rdy[15]),
        .s15i_valid(stream_in_valid[15]),
        .s15i_data(stream_in_data[15][`STREAM15_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM15_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s15o_rdy(stream_out_rdy[15]),
        .s15o_valid(stream_out_valid[15]),
        .s15o_data(stream_out_data[15][`STREAM15_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM16_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s16i_rdy(stream_in_rdy[16]),
        .s16i_valid(stream_in_valid[16]),
        .s16i_data(stream_in_data[16][`STREAM16_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM16_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s16o_rdy(stream_out_rdy[16]),
        .s16o_valid(stream_out_valid[16]),
        .s16o_data(stream_out_data[16][`STREAM16_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM17_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s17i_rdy(stream_in_rdy[17]),
        .s17i_valid(stream_in_valid[17]),
        .s17i_data(stream_in_data[17][`STREAM17_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM17_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s17o_rdy(stream_out_rdy[17]),
        .s17o_valid(stream_out_valid[17]),
        .s17o_data(stream_out_data[17][`STREAM17_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM18_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s18i_rdy(stream_in_rdy[18]),
        .s18i_valid(stream_in_valid[18]),
        .s18i_data(stream_in_data[18][`STREAM18_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM18_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s18o_rdy(stream_out_rdy[18]),
        .s18o_valid(stream_out_valid[18]),
        .s18o_data(stream_out_data[18][`STREAM18_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM19_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s19i_rdy(stream_in_rdy[19]),
        .s19i_valid(stream_in_valid[19]),
        .s19i_data(stream_in_data[19][`STREAM19_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM19_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s19o_rdy(stream_out_rdy[19]),
        .s19o_valid(stream_out_valid[19]),
        .s19o_data(stream_out_data[19][`STREAM19_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM20_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s20i_rdy(stream_in_rdy[20]),
        .s20i_valid(stream_in_valid[20]),
        .s20i_data(stream_in_data[20][`STREAM20_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM20_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s20o_rdy(stream_out_rdy[20]),
        .s20o_valid(stream_out_valid[20]),
        .s20o_data(stream_out_data[20][`STREAM20_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM21_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s21i_rdy(stream_in_rdy[21]),
        .s21i_valid(stream_in_valid[21]),
        .s21i_data(stream_in_data[21][`STREAM21_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM21_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s21o_rdy(stream_out_rdy[21]),
        .s21o_valid(stream_out_valid[21]),
        .s21o_data(stream_out_data[21][`STREAM21_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM22_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s22i_rdy(stream_in_rdy[22]),
        .s22i_valid(stream_in_valid[22]),
        .s22i_data(stream_in_data[22][`STREAM22_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM22_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s22o_rdy(stream_out_rdy[22]),
        .s22o_valid(stream_out_valid[22]),
        .s22o_data(stream_out_data[22][`STREAM22_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM23_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s23i_rdy(stream_in_rdy[23]),
        .s23i_valid(stream_in_valid[23]),
        .s23i_data(stream_in_data[23][`STREAM23_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM23_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s23o_rdy(stream_out_rdy[23]),
        .s23o_valid(stream_out_valid[23]),
        .s23o_data(stream_out_data[23][`STREAM23_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM24_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s24i_rdy(stream_in_rdy[24]),
        .s24i_valid(stream_in_valid[24]),
        .s24i_data(stream_in_data[24][`STREAM24_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM24_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s24o_rdy(stream_out_rdy[24]),
        .s24o_valid(stream_out_valid[24]),
        .s24o_data(stream_out_data[24][`STREAM24_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM25_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s25i_rdy(stream_in_rdy[25]),
        .s25i_valid(stream_in_valid[25]),
        .s25i_data(stream_in_data[25][`STREAM25_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM25_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s25o_rdy(stream_out_rdy[25]),
        .s25o_valid(stream_out_valid[25]),
        .s25o_data(stream_out_data[25][`STREAM25_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM26_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s26i_rdy(stream_in_rdy[26]),
        .s26i_valid(stream_in_valid[26]),
        .s26i_data(stream_in_data[26][`STREAM26_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM26_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s26o_rdy(stream_out_rdy[26]),
        .s26o_valid(stream_out_valid[26]),
        .s26o_data(stream_out_data[26][`STREAM26_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM27_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s27i_rdy(stream_in_rdy[27]),
        .s27i_valid(stream_in_valid[27]),
        .s27i_data(stream_in_data[27][`STREAM27_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM27_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s27o_rdy(stream_out_rdy[27]),
        .s27o_valid(stream_out_valid[27]),
        .s27o_data(stream_out_data[27][`STREAM27_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM28_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s28i_rdy(stream_in_rdy[28]),
        .s28i_valid(stream_in_valid[28]),
        .s28i_data(stream_in_data[28][`STREAM28_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM28_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s28o_rdy(stream_out_rdy[28]),
        .s28o_valid(stream_out_valid[28]),
        .s28o_data(stream_out_data[28][`STREAM28_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM29_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s29i_rdy(stream_in_rdy[29]),
        .s29i_valid(stream_in_valid[29]),
        .s29i_data(stream_in_data[29][`STREAM29_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM29_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s29o_rdy(stream_out_rdy[29]),
        .s29o_valid(stream_out_valid[29]),
        .s29o_data(stream_out_data[29][`STREAM29_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM30_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s30i_rdy(stream_in_rdy[30]),
        .s30i_valid(stream_in_valid[30]),
        .s30i_data(stream_in_data[30][`STREAM30_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM30_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s30o_rdy(stream_out_rdy[30]),
        .s30o_valid(stream_out_valid[30]),
        .s30o_data(stream_out_data[30][`STREAM30_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM31_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s31i_rdy(stream_in_rdy[31]),
        .s31i_valid(stream_in_valid[31]),
        .s31i_data(stream_in_data[31][`STREAM31_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM31_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s31o_rdy(stream_out_rdy[31]),
        .s31o_valid(stream_out_valid[31]),
        .s31o_data(stream_out_data[31][`STREAM31_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM32_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s32i_rdy(stream_in_rdy[32]),
        .s32i_valid(stream_in_valid[32]),
        .s32i_data(stream_in_data[32][`STREAM32_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM32_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s32o_rdy(stream_out_rdy[32]),
        .s32o_valid(stream_out_valid[32]),
        .s32o_data(stream_out_data[32][`STREAM32_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM33_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s33i_rdy(stream_in_rdy[33]),
        .s33i_valid(stream_in_valid[33]),
        .s33i_data(stream_in_data[33][`STREAM33_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM33_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s33o_rdy(stream_out_rdy[33]),
        .s33o_valid(stream_out_valid[33]),
        .s33o_data(stream_out_data[33][`STREAM33_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM34_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s34i_rdy(stream_in_rdy[34]),
        .s34i_valid(stream_in_valid[34]),
        .s34i_data(stream_in_data[34][`STREAM34_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM34_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s34o_rdy(stream_out_rdy[34]),
        .s34o_valid(stream_out_valid[34]),
        .s34o_data(stream_out_data[34][`STREAM34_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM35_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s35i_rdy(stream_in_rdy[35]),
        .s35i_valid(stream_in_valid[35]),
        .s35i_data(stream_in_data[35][`STREAM35_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM35_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s35o_rdy(stream_out_rdy[35]),
        .s35o_valid(stream_out_valid[35]),
        .s35o_data(stream_out_data[35][`STREAM35_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM36_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s36i_rdy(stream_in_rdy[36]),
        .s36i_valid(stream_in_valid[36]),
        .s36i_data(stream_in_data[36][`STREAM36_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM36_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s36o_rdy(stream_out_rdy[36]),
        .s36o_valid(stream_out_valid[36]),
        .s36o_data(stream_out_data[36][`STREAM36_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM37_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s37i_rdy(stream_in_rdy[37]),
        .s37i_valid(stream_in_valid[37]),
        .s37i_data(stream_in_data[37][`STREAM37_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM37_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s37o_rdy(stream_out_rdy[37]),
        .s37o_valid(stream_out_valid[37]),
        .s37o_data(stream_out_data[37][`STREAM37_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM38_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s38i_rdy(stream_in_rdy[38]),
        .s38i_valid(stream_in_valid[38]),
        .s38i_data(stream_in_data[38][`STREAM38_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM38_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s38o_rdy(stream_out_rdy[38]),
        .s38o_valid(stream_out_valid[38]),
        .s38o_data(stream_out_data[38][`STREAM38_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM39_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s39i_rdy(stream_in_rdy[39]),
        .s39i_valid(stream_in_valid[39]),
        .s39i_data(stream_in_data[39][`STREAM39_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM39_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s39o_rdy(stream_out_rdy[39]),
        .s39o_valid(stream_out_valid[39]),
        .s39o_data(stream_out_data[39][`STREAM39_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM40_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s40i_rdy(stream_in_rdy[40]),
        .s40i_valid(stream_in_valid[40]),
        .s40i_data(stream_in_data[40][`STREAM40_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM40_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s40o_rdy(stream_out_rdy[40]),
        .s40o_valid(stream_out_valid[40]),
        .s40o_data(stream_out_data[40][`STREAM40_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM41_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s41i_rdy(stream_in_rdy[41]),
        .s41i_valid(stream_in_valid[41]),
        .s41i_data(stream_in_data[41][`STREAM41_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM41_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s41o_rdy(stream_out_rdy[41]),
        .s41o_valid(stream_out_valid[41]),
        .s41o_data(stream_out_data[41][`STREAM41_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM42_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s42i_rdy(stream_in_rdy[42]),
        .s42i_valid(stream_in_valid[42]),
        .s42i_data(stream_in_data[42][`STREAM42_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM42_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s42o_rdy(stream_out_rdy[42]),
        .s42o_valid(stream_out_valid[42]),
        .s42o_data(stream_out_data[42][`STREAM42_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM43_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s43i_rdy(stream_in_rdy[43]),
        .s43i_valid(stream_in_valid[43]),
        .s43i_data(stream_in_data[43][`STREAM43_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM43_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s43o_rdy(stream_out_rdy[43]),
        .s43o_valid(stream_out_valid[43]),
        .s43o_data(stream_out_data[43][`STREAM43_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM44_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s44i_rdy(stream_in_rdy[44]),
        .s44i_valid(stream_in_valid[44]),
        .s44i_data(stream_in_data[44][`STREAM44_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM44_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s44o_rdy(stream_out_rdy[44]),
        .s44o_valid(stream_out_valid[44]),
        .s44o_data(stream_out_data[44][`STREAM44_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM45_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s45i_rdy(stream_in_rdy[45]),
        .s45i_valid(stream_in_valid[45]),
        .s45i_data(stream_in_data[45][`STREAM45_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM45_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s45o_rdy(stream_out_rdy[45]),
        .s45o_valid(stream_out_valid[45]),
        .s45o_data(stream_out_data[45][`STREAM45_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM46_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s46i_rdy(stream_in_rdy[46]),
        .s46i_valid(stream_in_valid[46]),
        .s46i_data(stream_in_data[46][`STREAM46_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM46_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s46o_rdy(stream_out_rdy[46]),
        .s46o_valid(stream_out_valid[46]),
        .s46o_data(stream_out_data[46][`STREAM46_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM47_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s47i_rdy(stream_in_rdy[47]),
        .s47i_valid(stream_in_valid[47]),
        .s47i_data(stream_in_data[47][`STREAM47_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM47_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s47o_rdy(stream_out_rdy[47]),
        .s47o_valid(stream_out_valid[47]),
        .s47o_data(stream_out_data[47][`STREAM47_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM48_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s48i_rdy(stream_in_rdy[48]),
        .s48i_valid(stream_in_valid[48]),
        .s48i_data(stream_in_data[48][`STREAM48_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM48_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s48o_rdy(stream_out_rdy[48]),
        .s48o_valid(stream_out_valid[48]),
        .s48o_data(stream_out_data[48][`STREAM48_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM49_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s49i_rdy(stream_in_rdy[49]),
        .s49i_valid(stream_in_valid[49]),
        .s49i_data(stream_in_data[49][`STREAM49_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM49_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s49o_rdy(stream_out_rdy[49]),
        .s49o_valid(stream_out_valid[49]),
        .s49o_data(stream_out_data[49][`STREAM49_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM50_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s50i_rdy(stream_in_rdy[50]),
        .s50i_valid(stream_in_valid[50]),
        .s50i_data(stream_in_data[50][`STREAM50_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM50_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s50o_rdy(stream_out_rdy[50]),
        .s50o_valid(stream_out_valid[50]),
        .s50o_data(stream_out_data[50][`STREAM50_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM51_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s51i_rdy(stream_in_rdy[51]),
        .s51i_valid(stream_in_valid[51]),
        .s51i_data(stream_in_data[51][`STREAM51_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM51_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s51o_rdy(stream_out_rdy[51]),
        .s51o_valid(stream_out_valid[51]),
        .s51o_data(stream_out_data[51][`STREAM51_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM52_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s52i_rdy(stream_in_rdy[52]),
        .s52i_valid(stream_in_valid[52]),
        .s52i_data(stream_in_data[52][`STREAM52_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM52_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s52o_rdy(stream_out_rdy[52]),
        .s52o_valid(stream_out_valid[52]),
        .s52o_data(stream_out_data[52][`STREAM52_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM53_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s53i_rdy(stream_in_rdy[53]),
        .s53i_valid(stream_in_valid[53]),
        .s53i_data(stream_in_data[53][`STREAM53_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM53_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s53o_rdy(stream_out_rdy[53]),
        .s53o_valid(stream_out_valid[53]),
        .s53o_data(stream_out_data[53][`STREAM53_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM54_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s54i_rdy(stream_in_rdy[54]),
        .s54i_valid(stream_in_valid[54]),
        .s54i_data(stream_in_data[54][`STREAM54_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM54_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s54o_rdy(stream_out_rdy[54]),
        .s54o_valid(stream_out_valid[54]),
        .s54o_data(stream_out_data[54][`STREAM54_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM55_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s55i_rdy(stream_in_rdy[55]),
        .s55i_valid(stream_in_valid[55]),
        .s55i_data(stream_in_data[55][`STREAM55_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM55_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s55o_rdy(stream_out_rdy[55]),
        .s55o_valid(stream_out_valid[55]),
        .s55o_data(stream_out_data[55][`STREAM55_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM56_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s56i_rdy(stream_in_rdy[56]),
        .s56i_valid(stream_in_valid[56]),
        .s56i_data(stream_in_data[56][`STREAM56_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM56_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s56o_rdy(stream_out_rdy[56]),
        .s56o_valid(stream_out_valid[56]),
        .s56o_data(stream_out_data[56][`STREAM56_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM57_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s57i_rdy(stream_in_rdy[57]),
        .s57i_valid(stream_in_valid[57]),
        .s57i_data(stream_in_data[57][`STREAM57_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM57_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s57o_rdy(stream_out_rdy[57]),
        .s57o_valid(stream_out_valid[57]),
        .s57o_data(stream_out_data[57][`STREAM57_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM58_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s58i_rdy(stream_in_rdy[58]),
        .s58i_valid(stream_in_valid[58]),
        .s58i_data(stream_in_data[58][`STREAM58_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM58_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s58o_rdy(stream_out_rdy[58]),
        .s58o_valid(stream_out_valid[58]),
        .s58o_data(stream_out_data[58][`STREAM58_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM59_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s59i_rdy(stream_in_rdy[59]),
        .s59i_valid(stream_in_valid[59]),
        .s59i_data(stream_in_data[59][`STREAM59_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM59_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s59o_rdy(stream_out_rdy[59]),
        .s59o_valid(stream_out_valid[59]),
        .s59o_data(stream_out_data[59][`STREAM59_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM60_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s60i_rdy(stream_in_rdy[60]),
        .s60i_valid(stream_in_valid[60]),
        .s60i_data(stream_in_data[60][`STREAM60_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM60_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s60o_rdy(stream_out_rdy[60]),
        .s60o_valid(stream_out_valid[60]),
        .s60o_data(stream_out_data[60][`STREAM60_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM61_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s61i_rdy(stream_in_rdy[61]),
        .s61i_valid(stream_in_valid[61]),
        .s61i_data(stream_in_data[61][`STREAM61_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM61_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s61o_rdy(stream_out_rdy[61]),
        .s61o_valid(stream_out_valid[61]),
        .s61o_data(stream_out_data[61][`STREAM61_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM62_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s62i_rdy(stream_in_rdy[62]),
        .s62i_valid(stream_in_valid[62]),
        .s62i_data(stream_in_data[62][`STREAM62_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM62_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s62o_rdy(stream_out_rdy[62]),
        .s62o_valid(stream_out_valid[62]),
        .s62o_data(stream_out_data[62][`STREAM62_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM63_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s63i_rdy(stream_in_rdy[63]),
        .s63i_valid(stream_in_valid[63]),
        .s63i_data(stream_in_data[63][`STREAM63_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM63_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s63o_rdy(stream_out_rdy[63]),
        .s63o_valid(stream_out_valid[63]),
        .s63o_data(stream_out_data[63][`STREAM63_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM64_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s64i_rdy(stream_in_rdy[64]),
        .s64i_valid(stream_in_valid[64]),
        .s64i_data(stream_in_data[64][`STREAM64_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM64_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s64o_rdy(stream_out_rdy[64]),
        .s64o_valid(stream_out_valid[64]),
        .s64o_data(stream_out_data[64][`STREAM64_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM65_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s65i_rdy(stream_in_rdy[65]),
        .s65i_valid(stream_in_valid[65]),
        .s65i_data(stream_in_data[65][`STREAM65_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM65_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s65o_rdy(stream_out_rdy[65]),
        .s65o_valid(stream_out_valid[65]),
        .s65o_data(stream_out_data[65][`STREAM65_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM66_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s66i_rdy(stream_in_rdy[66]),
        .s66i_valid(stream_in_valid[66]),
        .s66i_data(stream_in_data[66][`STREAM66_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM66_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s66o_rdy(stream_out_rdy[66]),
        .s66o_valid(stream_out_valid[66]),
        .s66o_data(stream_out_data[66][`STREAM66_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM67_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s67i_rdy(stream_in_rdy[67]),
        .s67i_valid(stream_in_valid[67]),
        .s67i_data(stream_in_data[67][`STREAM67_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM67_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s67o_rdy(stream_out_rdy[67]),
        .s67o_valid(stream_out_valid[67]),
        .s67o_data(stream_out_data[67][`STREAM67_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM68_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s68i_rdy(stream_in_rdy[68]),
        .s68i_valid(stream_in_valid[68]),
        .s68i_data(stream_in_data[68][`STREAM68_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM68_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s68o_rdy(stream_out_rdy[68]),
        .s68o_valid(stream_out_valid[68]),
        .s68o_data(stream_out_data[68][`STREAM68_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM69_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s69i_rdy(stream_in_rdy[69]),
        .s69i_valid(stream_in_valid[69]),
        .s69i_data(stream_in_data[69][`STREAM69_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM69_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s69o_rdy(stream_out_rdy[69]),
        .s69o_valid(stream_out_valid[69]),
        .s69o_data(stream_out_data[69][`STREAM69_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM70_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s70i_rdy(stream_in_rdy[70]),
        .s70i_valid(stream_in_valid[70]),
        .s70i_data(stream_in_data[70][`STREAM70_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM70_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s70o_rdy(stream_out_rdy[70]),
        .s70o_valid(stream_out_valid[70]),
        .s70o_data(stream_out_data[70][`STREAM70_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM71_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s71i_rdy(stream_in_rdy[71]),
        .s71i_valid(stream_in_valid[71]),
        .s71i_data(stream_in_data[71][`STREAM71_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM71_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s71o_rdy(stream_out_rdy[71]),
        .s71o_valid(stream_out_valid[71]),
        .s71o_data(stream_out_data[71][`STREAM71_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM72_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s72i_rdy(stream_in_rdy[72]),
        .s72i_valid(stream_in_valid[72]),
        .s72i_data(stream_in_data[72][`STREAM72_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM72_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s72o_rdy(stream_out_rdy[72]),
        .s72o_valid(stream_out_valid[72]),
        .s72o_data(stream_out_data[72][`STREAM72_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM73_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s73i_rdy(stream_in_rdy[73]),
        .s73i_valid(stream_in_valid[73]),
        .s73i_data(stream_in_data[73][`STREAM73_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM73_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s73o_rdy(stream_out_rdy[73]),
        .s73o_valid(stream_out_valid[73]),
        .s73o_data(stream_out_data[73][`STREAM73_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM74_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s74i_rdy(stream_in_rdy[74]),
        .s74i_valid(stream_in_valid[74]),
        .s74i_data(stream_in_data[74][`STREAM74_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM74_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s74o_rdy(stream_out_rdy[74]),
        .s74o_valid(stream_out_valid[74]),
        .s74o_data(stream_out_data[74][`STREAM74_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM75_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s75i_rdy(stream_in_rdy[75]),
        .s75i_valid(stream_in_valid[75]),
        .s75i_data(stream_in_data[75][`STREAM75_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM75_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s75o_rdy(stream_out_rdy[75]),
        .s75o_valid(stream_out_valid[75]),
        .s75o_data(stream_out_data[75][`STREAM75_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM76_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s76i_rdy(stream_in_rdy[76]),
        .s76i_valid(stream_in_valid[76]),
        .s76i_data(stream_in_data[76][`STREAM76_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM76_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s76o_rdy(stream_out_rdy[76]),
        .s76o_valid(stream_out_valid[76]),
        .s76o_data(stream_out_data[76][`STREAM76_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM77_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s77i_rdy(stream_in_rdy[77]),
        .s77i_valid(stream_in_valid[77]),
        .s77i_data(stream_in_data[77][`STREAM77_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM77_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s77o_rdy(stream_out_rdy[77]),
        .s77o_valid(stream_out_valid[77]),
        .s77o_data(stream_out_data[77][`STREAM77_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM78_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s78i_rdy(stream_in_rdy[78]),
        .s78i_valid(stream_in_valid[78]),
        .s78i_data(stream_in_data[78][`STREAM78_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM78_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s78o_rdy(stream_out_rdy[78]),
        .s78o_valid(stream_out_valid[78]),
        .s78o_data(stream_out_data[78][`STREAM78_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM79_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s79i_rdy(stream_in_rdy[79]),
        .s79i_valid(stream_in_valid[79]),
        .s79i_data(stream_in_data[79][`STREAM79_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM79_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s79o_rdy(stream_out_rdy[79]),
        .s79o_valid(stream_out_valid[79]),
        .s79o_data(stream_out_data[79][`STREAM79_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM80_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s80i_rdy(stream_in_rdy[80]),
        .s80i_valid(stream_in_valid[80]),
        .s80i_data(stream_in_data[80][`STREAM80_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM80_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s80o_rdy(stream_out_rdy[80]),
        .s80o_valid(stream_out_valid[80]),
        .s80o_data(stream_out_data[80][`STREAM80_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM81_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s81i_rdy(stream_in_rdy[81]),
        .s81i_valid(stream_in_valid[81]),
        .s81i_data(stream_in_data[81][`STREAM81_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM81_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s81o_rdy(stream_out_rdy[81]),
        .s81o_valid(stream_out_valid[81]),
        .s81o_data(stream_out_data[81][`STREAM81_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM82_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s82i_rdy(stream_in_rdy[82]),
        .s82i_valid(stream_in_valid[82]),
        .s82i_data(stream_in_data[82][`STREAM82_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM82_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s82o_rdy(stream_out_rdy[82]),
        .s82o_valid(stream_out_valid[82]),
        .s82o_data(stream_out_data[82][`STREAM82_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM83_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s83i_rdy(stream_in_rdy[83]),
        .s83i_valid(stream_in_valid[83]),
        .s83i_data(stream_in_data[83][`STREAM83_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM83_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s83o_rdy(stream_out_rdy[83]),
        .s83o_valid(stream_out_valid[83]),
        .s83o_data(stream_out_data[83][`STREAM83_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM84_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s84i_rdy(stream_in_rdy[84]),
        .s84i_valid(stream_in_valid[84]),
        .s84i_data(stream_in_data[84][`STREAM84_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM84_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s84o_rdy(stream_out_rdy[84]),
        .s84o_valid(stream_out_valid[84]),
        .s84o_data(stream_out_data[84][`STREAM84_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM85_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s85i_rdy(stream_in_rdy[85]),
        .s85i_valid(stream_in_valid[85]),
        .s85i_data(stream_in_data[85][`STREAM85_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM85_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s85o_rdy(stream_out_rdy[85]),
        .s85o_valid(stream_out_valid[85]),
        .s85o_data(stream_out_data[85][`STREAM85_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM86_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s86i_rdy(stream_in_rdy[86]),
        .s86i_valid(stream_in_valid[86]),
        .s86i_data(stream_in_data[86][`STREAM86_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM86_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s86o_rdy(stream_out_rdy[86]),
        .s86o_valid(stream_out_valid[86]),
        .s86o_data(stream_out_data[86][`STREAM86_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM87_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s87i_rdy(stream_in_rdy[87]),
        .s87i_valid(stream_in_valid[87]),
        .s87i_data(stream_in_data[87][`STREAM87_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM87_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s87o_rdy(stream_out_rdy[87]),
        .s87o_valid(stream_out_valid[87]),
        .s87o_data(stream_out_data[87][`STREAM87_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM88_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s88i_rdy(stream_in_rdy[88]),
        .s88i_valid(stream_in_valid[88]),
        .s88i_data(stream_in_data[88][`STREAM88_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM88_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s88o_rdy(stream_out_rdy[88]),
        .s88o_valid(stream_out_valid[88]),
        .s88o_data(stream_out_data[88][`STREAM88_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM89_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s89i_rdy(stream_in_rdy[89]),
        .s89i_valid(stream_in_valid[89]),
        .s89i_data(stream_in_data[89][`STREAM89_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM89_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s89o_rdy(stream_out_rdy[89]),
        .s89o_valid(stream_out_valid[89]),
        .s89o_data(stream_out_data[89][`STREAM89_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM90_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s90i_rdy(stream_in_rdy[90]),
        .s90i_valid(stream_in_valid[90]),
        .s90i_data(stream_in_data[90][`STREAM90_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM90_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s90o_rdy(stream_out_rdy[90]),
        .s90o_valid(stream_out_valid[90]),
        .s90o_data(stream_out_data[90][`STREAM90_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM91_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s91i_rdy(stream_in_rdy[91]),
        .s91i_valid(stream_in_valid[91]),
        .s91i_data(stream_in_data[91][`STREAM91_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM91_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s91o_rdy(stream_out_rdy[91]),
        .s91o_valid(stream_out_valid[91]),
        .s91o_data(stream_out_data[91][`STREAM91_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM92_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s92i_rdy(stream_in_rdy[92]),
        .s92i_valid(stream_in_valid[92]),
        .s92i_data(stream_in_data[92][`STREAM92_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM92_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s92o_rdy(stream_out_rdy[92]),
        .s92o_valid(stream_out_valid[92]),
        .s92o_data(stream_out_data[92][`STREAM92_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM93_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s93i_rdy(stream_in_rdy[93]),
        .s93i_valid(stream_in_valid[93]),
        .s93i_data(stream_in_data[93][`STREAM93_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM93_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s93o_rdy(stream_out_rdy[93]),
        .s93o_valid(stream_out_valid[93]),
        .s93o_data(stream_out_data[93][`STREAM93_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM94_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s94i_rdy(stream_in_rdy[94]),
        .s94i_valid(stream_in_valid[94]),
        .s94i_data(stream_in_data[94][`STREAM94_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM94_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s94o_rdy(stream_out_rdy[94]),
        .s94o_valid(stream_out_valid[94]),
        .s94o_data(stream_out_data[94][`STREAM94_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM95_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s95i_rdy(stream_in_rdy[95]),
        .s95i_valid(stream_in_valid[95]),
        .s95i_data(stream_in_data[95][`STREAM95_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM95_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s95o_rdy(stream_out_rdy[95]),
        .s95o_valid(stream_out_valid[95]),
        .s95o_data(stream_out_data[95][`STREAM95_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM96_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s96i_rdy(stream_in_rdy[96]),
        .s96i_valid(stream_in_valid[96]),
        .s96i_data(stream_in_data[96][`STREAM96_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM96_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s96o_rdy(stream_out_rdy[96]),
        .s96o_valid(stream_out_valid[96]),
        .s96o_data(stream_out_data[96][`STREAM96_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM97_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s97i_rdy(stream_in_rdy[97]),
        .s97i_valid(stream_in_valid[97]),
        .s97i_data(stream_in_data[97][`STREAM97_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM97_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s97o_rdy(stream_out_rdy[97]),
        .s97o_valid(stream_out_valid[97]),
        .s97o_data(stream_out_data[97][`STREAM97_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM98_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s98i_rdy(stream_in_rdy[98]),
        .s98i_valid(stream_in_valid[98]),
        .s98i_data(stream_in_data[98][`STREAM98_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM98_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s98o_rdy(stream_out_rdy[98]),
        .s98o_valid(stream_out_valid[98]),
        .s98o_data(stream_out_data[98][`STREAM98_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM99_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s99i_rdy(stream_in_rdy[99]),
        .s99i_valid(stream_in_valid[99]),
        .s99i_data(stream_in_data[99][`STREAM99_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM99_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s99o_rdy(stream_out_rdy[99]),
        .s99o_valid(stream_out_valid[99]),
        .s99o_data(stream_out_data[99][`STREAM99_OUT_WIDTH-1:0])
    `endif
    `ifdef STREAM100_IN_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s100i_rdy(stream_in_rdy[100]),
        .s100i_valid(stream_in_valid[100]),
        .s100i_data(stream_in_data[100][`STREAM100_IN_WIDTH-1:0])
    `endif
    `ifdef STREAM100_OUT_WIDTH
        `ifdef  UM_PREPEND_COMMA , `endif
        `define UM_PREPEND_COMMA
        `define INCLUDE_STREAM_COMMON
        .s100o_rdy(stream_out_rdy[100]),
        .s100o_valid(stream_out_valid[100]),
        .s100o_data(stream_out_data[100][`STREAM100_OUT_WIDTH-1:0])
    `endif

    `ifdef INCLUDE_STREAM_COMMON
        ,.clk(clk),
        .rst(rst)
    `endif
    
    );
`endif
    
// This is the stream compression for the in and out streams into the single signal which is transmited back across to the host.
    
    assign s_poll_seq[31:0]         = (32'h0
                                        `ifdef PICOBUS_WIDTH  | s_poll_seq_userpb     `endif
                                        `ifdef STREAM1_IN_WIDTH  | stream_in_desc_poll_seq[1]  `endif
                                        `ifdef STREAM1_OUT_WIDTH | stream_out_desc_poll_seq[1] `endif
                                        `ifdef STREAM2_IN_WIDTH  | stream_in_desc_poll_seq[2]  `endif
                                        `ifdef STREAM2_OUT_WIDTH | stream_out_desc_poll_seq[2] `endif
                                        `ifdef STREAM3_IN_WIDTH  | stream_in_desc_poll_seq[3]  `endif
                                        `ifdef STREAM3_OUT_WIDTH | stream_out_desc_poll_seq[3] `endif
                                        `ifdef STREAM4_IN_WIDTH  | stream_in_desc_poll_seq[4]  `endif
                                        `ifdef STREAM4_OUT_WIDTH | stream_out_desc_poll_seq[4] `endif
                                        `ifdef STREAM5_IN_WIDTH  | stream_in_desc_poll_seq[5]  `endif
                                        `ifdef STREAM5_OUT_WIDTH | stream_out_desc_poll_seq[5] `endif
                                        `ifdef STREAM6_IN_WIDTH  | stream_in_desc_poll_seq[6]  `endif
                                        `ifdef STREAM6_OUT_WIDTH | stream_out_desc_poll_seq[6] `endif
                                        `ifdef STREAM7_IN_WIDTH  | stream_in_desc_poll_seq[7]  `endif
                                        `ifdef STREAM7_OUT_WIDTH | stream_out_desc_poll_seq[7] `endif
                                        `ifdef STREAM8_IN_WIDTH  | stream_in_desc_poll_seq[8]  `endif
                                        `ifdef STREAM8_OUT_WIDTH | stream_out_desc_poll_seq[8] `endif
                                        `ifdef STREAM9_IN_WIDTH  | stream_in_desc_poll_seq[9]  `endif
                                        `ifdef STREAM9_OUT_WIDTH | stream_out_desc_poll_seq[9] `endif
                                        `ifdef STREAM10_IN_WIDTH  | stream_in_desc_poll_seq[10]  `endif
                                        `ifdef STREAM10_OUT_WIDTH | stream_out_desc_poll_seq[10] `endif
                                        `ifdef STREAM11_IN_WIDTH  | stream_in_desc_poll_seq[11]  `endif
                                        `ifdef STREAM11_OUT_WIDTH | stream_out_desc_poll_seq[11] `endif
                                        `ifdef STREAM12_IN_WIDTH  | stream_in_desc_poll_seq[12]  `endif
                                        `ifdef STREAM12_OUT_WIDTH | stream_out_desc_poll_seq[12] `endif
                                        `ifdef STREAM13_IN_WIDTH  | stream_in_desc_poll_seq[13]  `endif
                                        `ifdef STREAM13_OUT_WIDTH | stream_out_desc_poll_seq[13] `endif
                                        `ifdef STREAM14_IN_WIDTH  | stream_in_desc_poll_seq[14]  `endif
                                        `ifdef STREAM14_OUT_WIDTH | stream_out_desc_poll_seq[14] `endif
                                        `ifdef STREAM15_IN_WIDTH  | stream_in_desc_poll_seq[15]  `endif
                                        `ifdef STREAM15_OUT_WIDTH | stream_out_desc_poll_seq[15] `endif
                                        `ifdef STREAM16_IN_WIDTH  | stream_in_desc_poll_seq[16]  `endif
                                        `ifdef STREAM16_OUT_WIDTH | stream_out_desc_poll_seq[16] `endif
                                        `ifdef STREAM17_IN_WIDTH  | stream_in_desc_poll_seq[17]  `endif
                                        `ifdef STREAM17_OUT_WIDTH | stream_out_desc_poll_seq[17] `endif
                                        `ifdef STREAM18_IN_WIDTH  | stream_in_desc_poll_seq[18]  `endif
                                        `ifdef STREAM18_OUT_WIDTH | stream_out_desc_poll_seq[18] `endif
                                        `ifdef STREAM19_IN_WIDTH  | stream_in_desc_poll_seq[19]  `endif
                                        `ifdef STREAM19_OUT_WIDTH | stream_out_desc_poll_seq[19] `endif
                                        `ifdef STREAM20_IN_WIDTH  | stream_in_desc_poll_seq[20]  `endif
                                        `ifdef STREAM20_OUT_WIDTH | stream_out_desc_poll_seq[20] `endif
                                        `ifdef STREAM21_IN_WIDTH  | stream_in_desc_poll_seq[21]  `endif
                                        `ifdef STREAM21_OUT_WIDTH | stream_out_desc_poll_seq[21] `endif
                                        `ifdef STREAM22_IN_WIDTH  | stream_in_desc_poll_seq[22]  `endif
                                        `ifdef STREAM22_OUT_WIDTH | stream_out_desc_poll_seq[22] `endif
                                        `ifdef STREAM23_IN_WIDTH  | stream_in_desc_poll_seq[23]  `endif
                                        `ifdef STREAM23_OUT_WIDTH | stream_out_desc_poll_seq[23] `endif
                                        `ifdef STREAM24_IN_WIDTH  | stream_in_desc_poll_seq[24]  `endif
                                        `ifdef STREAM24_OUT_WIDTH | stream_out_desc_poll_seq[24] `endif
                                        `ifdef STREAM25_IN_WIDTH  | stream_in_desc_poll_seq[25]  `endif
                                        `ifdef STREAM25_OUT_WIDTH | stream_out_desc_poll_seq[25] `endif
                                        `ifdef STREAM26_IN_WIDTH  | stream_in_desc_poll_seq[26]  `endif
                                        `ifdef STREAM26_OUT_WIDTH | stream_out_desc_poll_seq[26] `endif
                                        `ifdef STREAM27_IN_WIDTH  | stream_in_desc_poll_seq[27]  `endif
                                        `ifdef STREAM27_OUT_WIDTH | stream_out_desc_poll_seq[27] `endif
                                        `ifdef STREAM28_IN_WIDTH  | stream_in_desc_poll_seq[28]  `endif
                                        `ifdef STREAM28_OUT_WIDTH | stream_out_desc_poll_seq[28] `endif
                                        `ifdef STREAM29_IN_WIDTH  | stream_in_desc_poll_seq[29]  `endif
                                        `ifdef STREAM29_OUT_WIDTH | stream_out_desc_poll_seq[29] `endif
                                        `ifdef STREAM30_IN_WIDTH  | stream_in_desc_poll_seq[30]  `endif
                                        `ifdef STREAM30_OUT_WIDTH | stream_out_desc_poll_seq[30] `endif
                                        `ifdef STREAM31_IN_WIDTH  | stream_in_desc_poll_seq[31]  `endif
                                        `ifdef STREAM31_OUT_WIDTH | stream_out_desc_poll_seq[31] `endif
                                        `ifdef STREAM32_IN_WIDTH  | stream_in_desc_poll_seq[32]  `endif
                                        `ifdef STREAM32_OUT_WIDTH | stream_out_desc_poll_seq[32] `endif
                                        `ifdef STREAM33_IN_WIDTH  | stream_in_desc_poll_seq[33]  `endif
                                        `ifdef STREAM33_OUT_WIDTH | stream_out_desc_poll_seq[33] `endif
                                        `ifdef STREAM34_IN_WIDTH  | stream_in_desc_poll_seq[34]  `endif
                                        `ifdef STREAM34_OUT_WIDTH | stream_out_desc_poll_seq[34] `endif
                                        `ifdef STREAM35_IN_WIDTH  | stream_in_desc_poll_seq[35]  `endif
                                        `ifdef STREAM35_OUT_WIDTH | stream_out_desc_poll_seq[35] `endif
                                        `ifdef STREAM36_IN_WIDTH  | stream_in_desc_poll_seq[36]  `endif
                                        `ifdef STREAM36_OUT_WIDTH | stream_out_desc_poll_seq[36] `endif
                                        `ifdef STREAM37_IN_WIDTH  | stream_in_desc_poll_seq[37]  `endif
                                        `ifdef STREAM37_OUT_WIDTH | stream_out_desc_poll_seq[37] `endif
                                        `ifdef STREAM38_IN_WIDTH  | stream_in_desc_poll_seq[38]  `endif
                                        `ifdef STREAM38_OUT_WIDTH | stream_out_desc_poll_seq[38] `endif
                                        `ifdef STREAM39_IN_WIDTH  | stream_in_desc_poll_seq[39]  `endif
                                        `ifdef STREAM39_OUT_WIDTH | stream_out_desc_poll_seq[39] `endif
                                        `ifdef STREAM40_IN_WIDTH  | stream_in_desc_poll_seq[40]  `endif
                                        `ifdef STREAM40_OUT_WIDTH | stream_out_desc_poll_seq[40] `endif
                                        `ifdef STREAM41_IN_WIDTH  | stream_in_desc_poll_seq[41]  `endif
                                        `ifdef STREAM41_OUT_WIDTH | stream_out_desc_poll_seq[41] `endif
                                        `ifdef STREAM42_IN_WIDTH  | stream_in_desc_poll_seq[42]  `endif
                                        `ifdef STREAM42_OUT_WIDTH | stream_out_desc_poll_seq[42] `endif
                                        `ifdef STREAM43_IN_WIDTH  | stream_in_desc_poll_seq[43]  `endif
                                        `ifdef STREAM43_OUT_WIDTH | stream_out_desc_poll_seq[43] `endif
                                        `ifdef STREAM44_IN_WIDTH  | stream_in_desc_poll_seq[44]  `endif
                                        `ifdef STREAM44_OUT_WIDTH | stream_out_desc_poll_seq[44] `endif
                                        `ifdef STREAM45_IN_WIDTH  | stream_in_desc_poll_seq[45]  `endif
                                        `ifdef STREAM45_OUT_WIDTH | stream_out_desc_poll_seq[45] `endif
                                        `ifdef STREAM46_IN_WIDTH  | stream_in_desc_poll_seq[46]  `endif
                                        `ifdef STREAM46_OUT_WIDTH | stream_out_desc_poll_seq[46] `endif
                                        `ifdef STREAM47_IN_WIDTH  | stream_in_desc_poll_seq[47]  `endif
                                        `ifdef STREAM47_OUT_WIDTH | stream_out_desc_poll_seq[47] `endif
                                        `ifdef STREAM48_IN_WIDTH  | stream_in_desc_poll_seq[48]  `endif
                                        `ifdef STREAM48_OUT_WIDTH | stream_out_desc_poll_seq[48] `endif
                                        `ifdef STREAM49_IN_WIDTH  | stream_in_desc_poll_seq[49]  `endif
                                        `ifdef STREAM49_OUT_WIDTH | stream_out_desc_poll_seq[49] `endif
                                        `ifdef STREAM50_IN_WIDTH  | stream_in_desc_poll_seq[50]  `endif
                                        `ifdef STREAM50_OUT_WIDTH | stream_out_desc_poll_seq[50] `endif
                                        `ifdef STREAM51_IN_WIDTH  | stream_in_desc_poll_seq[51]  `endif
                                        `ifdef STREAM51_OUT_WIDTH | stream_out_desc_poll_seq[51] `endif
                                        `ifdef STREAM52_IN_WIDTH  | stream_in_desc_poll_seq[52]  `endif
                                        `ifdef STREAM52_OUT_WIDTH | stream_out_desc_poll_seq[52] `endif
                                        `ifdef STREAM53_IN_WIDTH  | stream_in_desc_poll_seq[53]  `endif
                                        `ifdef STREAM53_OUT_WIDTH | stream_out_desc_poll_seq[53] `endif
                                        `ifdef STREAM54_IN_WIDTH  | stream_in_desc_poll_seq[54]  `endif
                                        `ifdef STREAM54_OUT_WIDTH | stream_out_desc_poll_seq[54] `endif
                                        `ifdef STREAM55_IN_WIDTH  | stream_in_desc_poll_seq[55]  `endif
                                        `ifdef STREAM55_OUT_WIDTH | stream_out_desc_poll_seq[55] `endif
                                        `ifdef STREAM56_IN_WIDTH  | stream_in_desc_poll_seq[56]  `endif
                                        `ifdef STREAM56_OUT_WIDTH | stream_out_desc_poll_seq[56] `endif
                                        `ifdef STREAM57_IN_WIDTH  | stream_in_desc_poll_seq[57]  `endif
                                        `ifdef STREAM57_OUT_WIDTH | stream_out_desc_poll_seq[57] `endif
                                        `ifdef STREAM58_IN_WIDTH  | stream_in_desc_poll_seq[58]  `endif
                                        `ifdef STREAM58_OUT_WIDTH | stream_out_desc_poll_seq[58] `endif
                                        `ifdef STREAM59_IN_WIDTH  | stream_in_desc_poll_seq[59]  `endif
                                        `ifdef STREAM59_OUT_WIDTH | stream_out_desc_poll_seq[59] `endif
                                        `ifdef STREAM60_IN_WIDTH  | stream_in_desc_poll_seq[60]  `endif
                                        `ifdef STREAM60_OUT_WIDTH | stream_out_desc_poll_seq[60] `endif
                                        `ifdef STREAM61_IN_WIDTH  | stream_in_desc_poll_seq[61]  `endif
                                        `ifdef STREAM61_OUT_WIDTH | stream_out_desc_poll_seq[61] `endif
                                        `ifdef STREAM62_IN_WIDTH  | stream_in_desc_poll_seq[62]  `endif
                                        `ifdef STREAM62_OUT_WIDTH | stream_out_desc_poll_seq[62] `endif
                                        `ifdef STREAM63_IN_WIDTH  | stream_in_desc_poll_seq[63]  `endif
                                        `ifdef STREAM63_OUT_WIDTH | stream_out_desc_poll_seq[63] `endif
                                        `ifdef STREAM64_IN_WIDTH  | stream_in_desc_poll_seq[64]  `endif
                                        `ifdef STREAM64_OUT_WIDTH | stream_out_desc_poll_seq[64] `endif
                                        `ifdef STREAM65_IN_WIDTH  | stream_in_desc_poll_seq[65]  `endif
                                        `ifdef STREAM65_OUT_WIDTH | stream_out_desc_poll_seq[65] `endif
                                        `ifdef STREAM66_IN_WIDTH  | stream_in_desc_poll_seq[66]  `endif
                                        `ifdef STREAM66_OUT_WIDTH | stream_out_desc_poll_seq[66] `endif
                                        `ifdef STREAM67_IN_WIDTH  | stream_in_desc_poll_seq[67]  `endif
                                        `ifdef STREAM67_OUT_WIDTH | stream_out_desc_poll_seq[67] `endif
                                        `ifdef STREAM68_IN_WIDTH  | stream_in_desc_poll_seq[68]  `endif
                                        `ifdef STREAM68_OUT_WIDTH | stream_out_desc_poll_seq[68] `endif
                                        `ifdef STREAM69_IN_WIDTH  | stream_in_desc_poll_seq[69]  `endif
                                        `ifdef STREAM69_OUT_WIDTH | stream_out_desc_poll_seq[69] `endif
                                        `ifdef STREAM70_IN_WIDTH  | stream_in_desc_poll_seq[70]  `endif
                                        `ifdef STREAM70_OUT_WIDTH | stream_out_desc_poll_seq[70] `endif
                                        `ifdef STREAM71_IN_WIDTH  | stream_in_desc_poll_seq[71]  `endif
                                        `ifdef STREAM71_OUT_WIDTH | stream_out_desc_poll_seq[71] `endif
                                        `ifdef STREAM72_IN_WIDTH  | stream_in_desc_poll_seq[72]  `endif
                                        `ifdef STREAM72_OUT_WIDTH | stream_out_desc_poll_seq[72] `endif
                                        `ifdef STREAM73_IN_WIDTH  | stream_in_desc_poll_seq[73]  `endif
                                        `ifdef STREAM73_OUT_WIDTH | stream_out_desc_poll_seq[73] `endif
                                        `ifdef STREAM74_IN_WIDTH  | stream_in_desc_poll_seq[74]  `endif
                                        `ifdef STREAM74_OUT_WIDTH | stream_out_desc_poll_seq[74] `endif
                                        `ifdef STREAM75_IN_WIDTH  | stream_in_desc_poll_seq[75]  `endif
                                        `ifdef STREAM75_OUT_WIDTH | stream_out_desc_poll_seq[75] `endif
                                        `ifdef STREAM76_IN_WIDTH  | stream_in_desc_poll_seq[76]  `endif
                                        `ifdef STREAM76_OUT_WIDTH | stream_out_desc_poll_seq[76] `endif
                                        `ifdef STREAM77_IN_WIDTH  | stream_in_desc_poll_seq[77]  `endif
                                        `ifdef STREAM77_OUT_WIDTH | stream_out_desc_poll_seq[77] `endif
                                        `ifdef STREAM78_IN_WIDTH  | stream_in_desc_poll_seq[78]  `endif
                                        `ifdef STREAM78_OUT_WIDTH | stream_out_desc_poll_seq[78] `endif
                                        `ifdef STREAM79_IN_WIDTH  | stream_in_desc_poll_seq[79]  `endif
                                        `ifdef STREAM79_OUT_WIDTH | stream_out_desc_poll_seq[79] `endif
                                        `ifdef STREAM80_IN_WIDTH  | stream_in_desc_poll_seq[80]  `endif
                                        `ifdef STREAM80_OUT_WIDTH | stream_out_desc_poll_seq[80] `endif
                                        `ifdef STREAM81_IN_WIDTH  | stream_in_desc_poll_seq[81]  `endif
                                        `ifdef STREAM81_OUT_WIDTH | stream_out_desc_poll_seq[81] `endif
                                        `ifdef STREAM82_IN_WIDTH  | stream_in_desc_poll_seq[82]  `endif
                                        `ifdef STREAM82_OUT_WIDTH | stream_out_desc_poll_seq[82] `endif
                                        `ifdef STREAM83_IN_WIDTH  | stream_in_desc_poll_seq[83]  `endif
                                        `ifdef STREAM83_OUT_WIDTH | stream_out_desc_poll_seq[83] `endif
                                        `ifdef STREAM84_IN_WIDTH  | stream_in_desc_poll_seq[84]  `endif
                                        `ifdef STREAM84_OUT_WIDTH | stream_out_desc_poll_seq[84] `endif
                                        `ifdef STREAM85_IN_WIDTH  | stream_in_desc_poll_seq[85]  `endif
                                        `ifdef STREAM85_OUT_WIDTH | stream_out_desc_poll_seq[85] `endif
                                        `ifdef STREAM86_IN_WIDTH  | stream_in_desc_poll_seq[86]  `endif
                                        `ifdef STREAM86_OUT_WIDTH | stream_out_desc_poll_seq[86] `endif
                                        `ifdef STREAM87_IN_WIDTH  | stream_in_desc_poll_seq[87]  `endif
                                        `ifdef STREAM87_OUT_WIDTH | stream_out_desc_poll_seq[87] `endif
                                        `ifdef STREAM88_IN_WIDTH  | stream_in_desc_poll_seq[88]  `endif
                                        `ifdef STREAM88_OUT_WIDTH | stream_out_desc_poll_seq[88] `endif
                                        `ifdef STREAM89_IN_WIDTH  | stream_in_desc_poll_seq[89]  `endif
                                        `ifdef STREAM89_OUT_WIDTH | stream_out_desc_poll_seq[89] `endif
                                        `ifdef STREAM90_IN_WIDTH  | stream_in_desc_poll_seq[90]  `endif
                                        `ifdef STREAM90_OUT_WIDTH | stream_out_desc_poll_seq[90] `endif
                                        `ifdef STREAM91_IN_WIDTH  | stream_in_desc_poll_seq[91]  `endif
                                        `ifdef STREAM91_OUT_WIDTH | stream_out_desc_poll_seq[91] `endif
                                        `ifdef STREAM92_IN_WIDTH  | stream_in_desc_poll_seq[92]  `endif
                                        `ifdef STREAM92_OUT_WIDTH | stream_out_desc_poll_seq[92] `endif
                                        `ifdef STREAM93_IN_WIDTH  | stream_in_desc_poll_seq[93]  `endif
                                        `ifdef STREAM93_OUT_WIDTH | stream_out_desc_poll_seq[93] `endif
                                        `ifdef STREAM94_IN_WIDTH  | stream_in_desc_poll_seq[94]  `endif
                                        `ifdef STREAM94_OUT_WIDTH | stream_out_desc_poll_seq[94] `endif
                                        `ifdef STREAM95_IN_WIDTH  | stream_in_desc_poll_seq[95]  `endif
                                        `ifdef STREAM95_OUT_WIDTH | stream_out_desc_poll_seq[95] `endif
                                        `ifdef STREAM96_IN_WIDTH  | stream_in_desc_poll_seq[96]  `endif
                                        `ifdef STREAM96_OUT_WIDTH | stream_out_desc_poll_seq[96] `endif
                                        `ifdef STREAM97_IN_WIDTH  | stream_in_desc_poll_seq[97]  `endif
                                        `ifdef STREAM97_OUT_WIDTH | stream_out_desc_poll_seq[97] `endif
                                        `ifdef STREAM98_IN_WIDTH  | stream_in_desc_poll_seq[98]  `endif
                                        `ifdef STREAM98_OUT_WIDTH | stream_out_desc_poll_seq[98] `endif
                                        `ifdef STREAM99_IN_WIDTH  | stream_in_desc_poll_seq[99]  `endif
                                        `ifdef STREAM99_OUT_WIDTH | stream_out_desc_poll_seq[99] `endif
                                        `ifdef STREAM100_IN_WIDTH  | stream_in_desc_poll_seq[100]  `endif
                                        `ifdef STREAM100_OUT_WIDTH | stream_out_desc_poll_seq[100] `endif
                                        `ifdef STREAM101_IN_WIDTH  | stream_in_desc_poll_seq[101]  `endif
                                        `ifdef STREAM101_OUT_WIDTH | stream_out_desc_poll_seq[101] `endif
                                        `ifdef STREAM102_IN_WIDTH  | stream_in_desc_poll_seq[102]  `endif
                                        `ifdef STREAM102_OUT_WIDTH | stream_out_desc_poll_seq[102] `endif
                                        `ifdef STREAM103_IN_WIDTH  | stream_in_desc_poll_seq[103]  `endif
                                        `ifdef STREAM103_OUT_WIDTH | stream_out_desc_poll_seq[103] `endif
                                        `ifdef STREAM104_IN_WIDTH  | stream_in_desc_poll_seq[104]  `endif
                                        `ifdef STREAM104_OUT_WIDTH | stream_out_desc_poll_seq[104] `endif
                                        `ifdef STREAM105_IN_WIDTH  | stream_in_desc_poll_seq[105]  `endif
                                        `ifdef STREAM105_OUT_WIDTH | stream_out_desc_poll_seq[105] `endif
                                        `ifdef STREAM106_IN_WIDTH  | stream_in_desc_poll_seq[106]  `endif
                                        `ifdef STREAM106_OUT_WIDTH | stream_out_desc_poll_seq[106] `endif
                                        `ifdef STREAM107_IN_WIDTH  | stream_in_desc_poll_seq[107]  `endif
                                        `ifdef STREAM107_OUT_WIDTH | stream_out_desc_poll_seq[107] `endif
                                        `ifdef STREAM108_IN_WIDTH  | stream_in_desc_poll_seq[108]  `endif
                                        `ifdef STREAM108_OUT_WIDTH | stream_out_desc_poll_seq[108] `endif
                                        `ifdef STREAM109_IN_WIDTH  | stream_in_desc_poll_seq[109]  `endif
                                        `ifdef STREAM109_OUT_WIDTH | stream_out_desc_poll_seq[109] `endif
                                        `ifdef STREAM110_IN_WIDTH  | stream_in_desc_poll_seq[110]  `endif
                                        `ifdef STREAM110_OUT_WIDTH | stream_out_desc_poll_seq[110] `endif
                                        `ifdef STREAM111_IN_WIDTH  | stream_in_desc_poll_seq[111]  `endif
                                        `ifdef STREAM111_OUT_WIDTH | stream_out_desc_poll_seq[111] `endif
                                        `ifdef STREAM112_IN_WIDTH  | stream_in_desc_poll_seq[112]  `endif
                                        `ifdef STREAM112_OUT_WIDTH | stream_out_desc_poll_seq[112] `endif
                                        `ifdef STREAM113_IN_WIDTH  | stream_in_desc_poll_seq[113]  `endif
                                        `ifdef STREAM113_OUT_WIDTH | stream_out_desc_poll_seq[113] `endif
                                        `ifdef STREAM114_IN_WIDTH  | stream_in_desc_poll_seq[114]  `endif
                                        `ifdef STREAM114_OUT_WIDTH | stream_out_desc_poll_seq[114] `endif
                                        `ifdef STREAM115_IN_WIDTH  | stream_in_desc_poll_seq[115]  `endif
                                        `ifdef STREAM115_OUT_WIDTH | stream_out_desc_poll_seq[115] `endif
                                        `ifdef STREAM116_IN_WIDTH  | stream_in_desc_poll_seq[116]  `endif
                                        `ifdef STREAM116_OUT_WIDTH | stream_out_desc_poll_seq[116] `endif
                                        `ifdef STREAM117_IN_WIDTH  | stream_in_desc_poll_seq[117]  `endif
                                        `ifdef STREAM117_OUT_WIDTH | stream_out_desc_poll_seq[117] `endif
                                        `ifdef STREAM118_IN_WIDTH  | stream_in_desc_poll_seq[118]  `endif
                                        `ifdef STREAM118_OUT_WIDTH | stream_out_desc_poll_seq[118] `endif
                                        `ifdef STREAM119_IN_WIDTH  | stream_in_desc_poll_seq[119]  `endif
                                        `ifdef STREAM119_OUT_WIDTH | stream_out_desc_poll_seq[119] `endif
                                        `ifdef STREAM120_IN_WIDTH  | stream_in_desc_poll_seq[120]  `endif
                                        `ifdef STREAM120_OUT_WIDTH | stream_out_desc_poll_seq[120] `endif
                                        `ifdef STREAM121_IN_WIDTH  | stream_in_desc_poll_seq[121]  `endif
                                        `ifdef STREAM121_OUT_WIDTH | stream_out_desc_poll_seq[121] `endif
                                        `ifdef STREAM122_IN_WIDTH  | stream_in_desc_poll_seq[122]  `endif
                                        `ifdef STREAM122_OUT_WIDTH | stream_out_desc_poll_seq[122] `endif
                                        `ifdef STREAM123_IN_WIDTH  | stream_in_desc_poll_seq[123]  `endif
                                        `ifdef STREAM123_OUT_WIDTH | stream_out_desc_poll_seq[123] `endif
                                        `ifdef STREAM124_IN_WIDTH  | stream_in_desc_poll_seq[124]  `endif
                                        `ifdef STREAM124_OUT_WIDTH | stream_out_desc_poll_seq[124] `endif
                                        `ifdef STREAM125_IN_WIDTH  | stream_in_desc_poll_seq[125]  `endif
                                        `ifdef STREAM125_OUT_WIDTH | stream_out_desc_poll_seq[125] `endif
                                        `ifdef STREAM126_IN_WIDTH  | stream_in_desc_poll_seq[126]  `endif
                                        `ifdef STREAM126_OUT_WIDTH | stream_out_desc_poll_seq[126] `endif
                                        );
    assign s_poll_next_desc_valid   = (1'b0
                                        `ifdef PICOBUS_WIDTH  | s_poll_next_desc_valid_userpb `endif
                                        `ifdef STREAM1_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[1]  `endif
                                        `ifdef STREAM1_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[1] `endif
                                        `ifdef STREAM2_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[2]  `endif
                                        `ifdef STREAM2_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[2] `endif
                                        `ifdef STREAM3_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[3]  `endif
                                        `ifdef STREAM3_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[3] `endif
                                        `ifdef STREAM4_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[4]  `endif
                                        `ifdef STREAM4_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[4] `endif
                                        `ifdef STREAM5_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[5]  `endif
                                        `ifdef STREAM5_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[5] `endif
                                        `ifdef STREAM6_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[6]  `endif
                                        `ifdef STREAM6_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[6] `endif
                                        `ifdef STREAM7_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[7]  `endif
                                        `ifdef STREAM7_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[7] `endif
                                        `ifdef STREAM8_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[8]  `endif
                                        `ifdef STREAM8_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[8] `endif
                                        `ifdef STREAM9_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[9]  `endif
                                        `ifdef STREAM9_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[9] `endif
                                        `ifdef STREAM10_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[10]  `endif
                                        `ifdef STREAM10_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[10] `endif
                                        `ifdef STREAM11_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[11]  `endif
                                        `ifdef STREAM11_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[11] `endif
                                        `ifdef STREAM12_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[12]  `endif
                                        `ifdef STREAM12_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[12] `endif
                                        `ifdef STREAM13_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[13]  `endif
                                        `ifdef STREAM13_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[13] `endif
                                        `ifdef STREAM14_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[14]  `endif
                                        `ifdef STREAM14_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[14] `endif
                                        `ifdef STREAM15_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[15]  `endif
                                        `ifdef STREAM15_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[15] `endif
                                        `ifdef STREAM16_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[16]  `endif
                                        `ifdef STREAM16_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[16] `endif
                                        `ifdef STREAM17_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[17]  `endif
                                        `ifdef STREAM17_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[17] `endif
                                        `ifdef STREAM18_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[18]  `endif
                                        `ifdef STREAM18_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[18] `endif
                                        `ifdef STREAM19_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[19]  `endif
                                        `ifdef STREAM19_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[19] `endif
                                        `ifdef STREAM20_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[20]  `endif
                                        `ifdef STREAM20_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[20] `endif
                                        `ifdef STREAM21_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[21]  `endif
                                        `ifdef STREAM21_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[21] `endif
                                        `ifdef STREAM22_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[22]  `endif
                                        `ifdef STREAM22_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[22] `endif
                                        `ifdef STREAM23_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[23]  `endif
                                        `ifdef STREAM23_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[23] `endif
                                        `ifdef STREAM24_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[24]  `endif
                                        `ifdef STREAM24_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[24] `endif
                                        `ifdef STREAM25_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[25]  `endif
                                        `ifdef STREAM25_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[25] `endif
                                        `ifdef STREAM26_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[26]  `endif
                                        `ifdef STREAM26_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[26] `endif
                                        `ifdef STREAM27_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[27]  `endif
                                        `ifdef STREAM27_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[27] `endif
                                        `ifdef STREAM28_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[28]  `endif
                                        `ifdef STREAM28_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[28] `endif
                                        `ifdef STREAM29_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[29]  `endif
                                        `ifdef STREAM29_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[29] `endif
                                        `ifdef STREAM30_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[30]  `endif
                                        `ifdef STREAM30_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[30] `endif
                                        `ifdef STREAM31_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[31]  `endif
                                        `ifdef STREAM31_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[31] `endif
                                        `ifdef STREAM32_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[32]  `endif
                                        `ifdef STREAM32_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[32] `endif
                                        `ifdef STREAM33_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[33]  `endif
                                        `ifdef STREAM33_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[33] `endif
                                        `ifdef STREAM34_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[34]  `endif
                                        `ifdef STREAM34_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[34] `endif
                                        `ifdef STREAM35_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[35]  `endif
                                        `ifdef STREAM35_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[35] `endif
                                        `ifdef STREAM36_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[36]  `endif
                                        `ifdef STREAM36_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[36] `endif
                                        `ifdef STREAM37_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[37]  `endif
                                        `ifdef STREAM37_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[37] `endif
                                        `ifdef STREAM38_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[38]  `endif
                                        `ifdef STREAM38_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[38] `endif
                                        `ifdef STREAM39_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[39]  `endif
                                        `ifdef STREAM39_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[39] `endif
                                        `ifdef STREAM40_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[40]  `endif
                                        `ifdef STREAM40_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[40] `endif
                                        `ifdef STREAM41_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[41]  `endif
                                        `ifdef STREAM41_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[41] `endif
                                        `ifdef STREAM42_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[42]  `endif
                                        `ifdef STREAM42_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[42] `endif
                                        `ifdef STREAM43_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[43]  `endif
                                        `ifdef STREAM43_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[43] `endif
                                        `ifdef STREAM44_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[44]  `endif
                                        `ifdef STREAM44_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[44] `endif
                                        `ifdef STREAM45_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[45]  `endif
                                        `ifdef STREAM45_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[45] `endif
                                        `ifdef STREAM46_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[46]  `endif
                                        `ifdef STREAM46_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[46] `endif
                                        `ifdef STREAM47_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[47]  `endif
                                        `ifdef STREAM47_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[47] `endif
                                        `ifdef STREAM48_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[48]  `endif
                                        `ifdef STREAM48_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[48] `endif
                                        `ifdef STREAM49_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[49]  `endif
                                        `ifdef STREAM49_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[49] `endif
                                        `ifdef STREAM50_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[50]  `endif
                                        `ifdef STREAM50_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[50] `endif
                                        `ifdef STREAM51_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[51]  `endif
                                        `ifdef STREAM51_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[51] `endif
                                        `ifdef STREAM52_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[52]  `endif
                                        `ifdef STREAM52_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[52] `endif
                                        `ifdef STREAM53_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[53]  `endif
                                        `ifdef STREAM53_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[53] `endif
                                        `ifdef STREAM54_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[54]  `endif
                                        `ifdef STREAM54_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[54] `endif
                                        `ifdef STREAM55_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[55]  `endif
                                        `ifdef STREAM55_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[55] `endif
                                        `ifdef STREAM56_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[56]  `endif
                                        `ifdef STREAM56_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[56] `endif
                                        `ifdef STREAM57_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[57]  `endif
                                        `ifdef STREAM57_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[57] `endif
                                        `ifdef STREAM58_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[58]  `endif
                                        `ifdef STREAM58_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[58] `endif
                                        `ifdef STREAM59_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[59]  `endif
                                        `ifdef STREAM59_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[59] `endif
                                        `ifdef STREAM60_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[60]  `endif
                                        `ifdef STREAM60_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[60] `endif
                                        `ifdef STREAM61_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[61]  `endif
                                        `ifdef STREAM61_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[61] `endif
                                        `ifdef STREAM62_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[62]  `endif
                                        `ifdef STREAM62_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[62] `endif
                                        `ifdef STREAM63_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[63]  `endif
                                        `ifdef STREAM63_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[63] `endif
                                        `ifdef STREAM64_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[64]  `endif
                                        `ifdef STREAM64_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[64] `endif
                                        `ifdef STREAM65_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[65]  `endif
                                        `ifdef STREAM65_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[65] `endif
                                        `ifdef STREAM66_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[66]  `endif
                                        `ifdef STREAM66_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[66] `endif
                                        `ifdef STREAM67_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[67]  `endif
                                        `ifdef STREAM67_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[67] `endif
                                        `ifdef STREAM68_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[68]  `endif
                                        `ifdef STREAM68_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[68] `endif
                                        `ifdef STREAM69_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[69]  `endif
                                        `ifdef STREAM69_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[69] `endif
                                        `ifdef STREAM70_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[70]  `endif
                                        `ifdef STREAM70_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[70] `endif
                                        `ifdef STREAM71_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[71]  `endif
                                        `ifdef STREAM71_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[71] `endif
                                        `ifdef STREAM72_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[72]  `endif
                                        `ifdef STREAM72_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[72] `endif
                                        `ifdef STREAM73_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[73]  `endif
                                        `ifdef STREAM73_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[73] `endif
                                        `ifdef STREAM74_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[74]  `endif
                                        `ifdef STREAM74_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[74] `endif
                                        `ifdef STREAM75_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[75]  `endif
                                        `ifdef STREAM75_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[75] `endif
                                        `ifdef STREAM76_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[76]  `endif
                                        `ifdef STREAM76_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[76] `endif
                                        `ifdef STREAM77_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[77]  `endif
                                        `ifdef STREAM77_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[77] `endif
                                        `ifdef STREAM78_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[78]  `endif
                                        `ifdef STREAM78_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[78] `endif
                                        `ifdef STREAM79_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[79]  `endif
                                        `ifdef STREAM79_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[79] `endif
                                        `ifdef STREAM80_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[80]  `endif
                                        `ifdef STREAM80_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[80] `endif
                                        `ifdef STREAM81_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[81]  `endif
                                        `ifdef STREAM81_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[81] `endif
                                        `ifdef STREAM82_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[82]  `endif
                                        `ifdef STREAM82_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[82] `endif
                                        `ifdef STREAM83_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[83]  `endif
                                        `ifdef STREAM83_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[83] `endif
                                        `ifdef STREAM84_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[84]  `endif
                                        `ifdef STREAM84_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[84] `endif
                                        `ifdef STREAM85_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[85]  `endif
                                        `ifdef STREAM85_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[85] `endif
                                        `ifdef STREAM86_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[86]  `endif
                                        `ifdef STREAM86_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[86] `endif
                                        `ifdef STREAM87_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[87]  `endif
                                        `ifdef STREAM87_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[87] `endif
                                        `ifdef STREAM88_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[88]  `endif
                                        `ifdef STREAM88_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[88] `endif
                                        `ifdef STREAM89_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[89]  `endif
                                        `ifdef STREAM89_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[89] `endif
                                        `ifdef STREAM90_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[90]  `endif
                                        `ifdef STREAM90_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[90] `endif
                                        `ifdef STREAM91_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[91]  `endif
                                        `ifdef STREAM91_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[91] `endif
                                        `ifdef STREAM92_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[92]  `endif
                                        `ifdef STREAM92_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[92] `endif
                                        `ifdef STREAM93_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[93]  `endif
                                        `ifdef STREAM93_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[93] `endif
                                        `ifdef STREAM94_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[94]  `endif
                                        `ifdef STREAM94_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[94] `endif
                                        `ifdef STREAM95_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[95]  `endif
                                        `ifdef STREAM95_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[95] `endif
                                        `ifdef STREAM96_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[96]  `endif
                                        `ifdef STREAM96_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[96] `endif
                                        `ifdef STREAM97_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[97]  `endif
                                        `ifdef STREAM97_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[97] `endif
                                        `ifdef STREAM98_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[98]  `endif
                                        `ifdef STREAM98_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[98] `endif
                                        `ifdef STREAM99_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[99]  `endif
                                        `ifdef STREAM99_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[99] `endif
                                        `ifdef STREAM100_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[100]  `endif
                                        `ifdef STREAM100_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[100] `endif
                                        `ifdef STREAM101_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[101]  `endif
                                        `ifdef STREAM101_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[101] `endif
                                        `ifdef STREAM102_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[102]  `endif
                                        `ifdef STREAM102_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[102] `endif
                                        `ifdef STREAM103_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[103]  `endif
                                        `ifdef STREAM103_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[103] `endif
                                        `ifdef STREAM104_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[104]  `endif
                                        `ifdef STREAM104_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[104] `endif
                                        `ifdef STREAM105_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[105]  `endif
                                        `ifdef STREAM105_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[105] `endif
                                        `ifdef STREAM106_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[106]  `endif
                                        `ifdef STREAM106_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[106] `endif
                                        `ifdef STREAM107_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[107]  `endif
                                        `ifdef STREAM107_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[107] `endif
                                        `ifdef STREAM108_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[108]  `endif
                                        `ifdef STREAM108_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[108] `endif
                                        `ifdef STREAM109_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[109]  `endif
                                        `ifdef STREAM109_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[109] `endif
                                        `ifdef STREAM110_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[110]  `endif
                                        `ifdef STREAM110_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[110] `endif
                                        `ifdef STREAM111_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[111]  `endif
                                        `ifdef STREAM111_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[111] `endif
                                        `ifdef STREAM112_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[112]  `endif
                                        `ifdef STREAM112_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[112] `endif
                                        `ifdef STREAM113_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[113]  `endif
                                        `ifdef STREAM113_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[113] `endif
                                        `ifdef STREAM114_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[114]  `endif
                                        `ifdef STREAM114_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[114] `endif
                                        `ifdef STREAM115_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[115]  `endif
                                        `ifdef STREAM115_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[115] `endif
                                        `ifdef STREAM116_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[116]  `endif
                                        `ifdef STREAM116_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[116] `endif
                                        `ifdef STREAM117_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[117]  `endif
                                        `ifdef STREAM117_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[117] `endif
                                        `ifdef STREAM118_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[118]  `endif
                                        `ifdef STREAM118_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[118] `endif
                                        `ifdef STREAM119_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[119]  `endif
                                        `ifdef STREAM119_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[119] `endif
                                        `ifdef STREAM120_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[120]  `endif
                                        `ifdef STREAM120_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[120] `endif
                                        `ifdef STREAM121_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[121]  `endif
                                        `ifdef STREAM121_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[121] `endif
                                        `ifdef STREAM122_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[122]  `endif
                                        `ifdef STREAM122_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[122] `endif
                                        `ifdef STREAM123_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[123]  `endif
                                        `ifdef STREAM123_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[123] `endif
                                        `ifdef STREAM124_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[124]  `endif
                                        `ifdef STREAM124_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[124] `endif
                                        `ifdef STREAM125_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[125]  `endif
                                        `ifdef STREAM125_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[125] `endif
                                        `ifdef STREAM126_IN_WIDTH  | stream_in_desc_poll_next_desc_valid[126]  `endif
                                        `ifdef STREAM126_OUT_WIDTH | stream_out_desc_poll_next_desc_valid[126] `endif
                                        );
    assign s_poll_next_desc[127:0]  = (128'h0
                                        `ifdef PICOBUS_WIDTH | s_poll_next_desc_userpb    `endif
                                        `ifdef STREAM1_IN_WIDTH  | stream_in_desc_poll_next_desc[1]  `endif
                                        `ifdef STREAM1_OUT_WIDTH | stream_out_desc_poll_next_desc[1] `endif
                                        `ifdef STREAM2_IN_WIDTH  | stream_in_desc_poll_next_desc[2]  `endif
                                        `ifdef STREAM2_OUT_WIDTH | stream_out_desc_poll_next_desc[2] `endif
                                        `ifdef STREAM3_IN_WIDTH  | stream_in_desc_poll_next_desc[3]  `endif
                                        `ifdef STREAM3_OUT_WIDTH | stream_out_desc_poll_next_desc[3] `endif
                                        `ifdef STREAM4_IN_WIDTH  | stream_in_desc_poll_next_desc[4]  `endif
                                        `ifdef STREAM4_OUT_WIDTH | stream_out_desc_poll_next_desc[4] `endif
                                        `ifdef STREAM5_IN_WIDTH  | stream_in_desc_poll_next_desc[5]  `endif
                                        `ifdef STREAM5_OUT_WIDTH | stream_out_desc_poll_next_desc[5] `endif
                                        `ifdef STREAM6_IN_WIDTH  | stream_in_desc_poll_next_desc[6]  `endif
                                        `ifdef STREAM6_OUT_WIDTH | stream_out_desc_poll_next_desc[6] `endif
                                        `ifdef STREAM7_IN_WIDTH  | stream_in_desc_poll_next_desc[7]  `endif
                                        `ifdef STREAM7_OUT_WIDTH | stream_out_desc_poll_next_desc[7] `endif
                                        `ifdef STREAM8_IN_WIDTH  | stream_in_desc_poll_next_desc[8]  `endif
                                        `ifdef STREAM8_OUT_WIDTH | stream_out_desc_poll_next_desc[8] `endif
                                        `ifdef STREAM9_IN_WIDTH  | stream_in_desc_poll_next_desc[9]  `endif
                                        `ifdef STREAM9_OUT_WIDTH | stream_out_desc_poll_next_desc[9] `endif
                                        `ifdef STREAM10_IN_WIDTH  | stream_in_desc_poll_next_desc[10]  `endif
                                        `ifdef STREAM10_OUT_WIDTH | stream_out_desc_poll_next_desc[10] `endif
                                        `ifdef STREAM11_IN_WIDTH  | stream_in_desc_poll_next_desc[11]  `endif
                                        `ifdef STREAM11_OUT_WIDTH | stream_out_desc_poll_next_desc[11] `endif
                                        `ifdef STREAM12_IN_WIDTH  | stream_in_desc_poll_next_desc[12]  `endif
                                        `ifdef STREAM12_OUT_WIDTH | stream_out_desc_poll_next_desc[12] `endif
                                        `ifdef STREAM13_IN_WIDTH  | stream_in_desc_poll_next_desc[13]  `endif
                                        `ifdef STREAM13_OUT_WIDTH | stream_out_desc_poll_next_desc[13] `endif
                                        `ifdef STREAM14_IN_WIDTH  | stream_in_desc_poll_next_desc[14]  `endif
                                        `ifdef STREAM14_OUT_WIDTH | stream_out_desc_poll_next_desc[14] `endif
                                        `ifdef STREAM15_IN_WIDTH  | stream_in_desc_poll_next_desc[15]  `endif
                                        `ifdef STREAM15_OUT_WIDTH | stream_out_desc_poll_next_desc[15] `endif
                                        `ifdef STREAM16_IN_WIDTH  | stream_in_desc_poll_next_desc[16]  `endif
                                        `ifdef STREAM16_OUT_WIDTH | stream_out_desc_poll_next_desc[16] `endif
                                        `ifdef STREAM17_IN_WIDTH  | stream_in_desc_poll_next_desc[17]  `endif
                                        `ifdef STREAM17_OUT_WIDTH | stream_out_desc_poll_next_desc[17] `endif
                                        `ifdef STREAM18_IN_WIDTH  | stream_in_desc_poll_next_desc[18]  `endif
                                        `ifdef STREAM18_OUT_WIDTH | stream_out_desc_poll_next_desc[18] `endif
                                        `ifdef STREAM19_IN_WIDTH  | stream_in_desc_poll_next_desc[19]  `endif
                                        `ifdef STREAM19_OUT_WIDTH | stream_out_desc_poll_next_desc[19] `endif
                                        `ifdef STREAM20_IN_WIDTH  | stream_in_desc_poll_next_desc[20]  `endif
                                        `ifdef STREAM20_OUT_WIDTH | stream_out_desc_poll_next_desc[20] `endif
                                        `ifdef STREAM21_IN_WIDTH  | stream_in_desc_poll_next_desc[21]  `endif
                                        `ifdef STREAM21_OUT_WIDTH | stream_out_desc_poll_next_desc[21] `endif
                                        `ifdef STREAM22_IN_WIDTH  | stream_in_desc_poll_next_desc[22]  `endif
                                        `ifdef STREAM22_OUT_WIDTH | stream_out_desc_poll_next_desc[22] `endif
                                        `ifdef STREAM23_IN_WIDTH  | stream_in_desc_poll_next_desc[23]  `endif
                                        `ifdef STREAM23_OUT_WIDTH | stream_out_desc_poll_next_desc[23] `endif
                                        `ifdef STREAM24_IN_WIDTH  | stream_in_desc_poll_next_desc[24]  `endif
                                        `ifdef STREAM24_OUT_WIDTH | stream_out_desc_poll_next_desc[24] `endif
                                        `ifdef STREAM25_IN_WIDTH  | stream_in_desc_poll_next_desc[25]  `endif
                                        `ifdef STREAM25_OUT_WIDTH | stream_out_desc_poll_next_desc[25] `endif
                                        `ifdef STREAM26_IN_WIDTH  | stream_in_desc_poll_next_desc[26]  `endif
                                        `ifdef STREAM26_OUT_WIDTH | stream_out_desc_poll_next_desc[26] `endif
                                        `ifdef STREAM27_IN_WIDTH  | stream_in_desc_poll_next_desc[27]  `endif
                                        `ifdef STREAM27_OUT_WIDTH | stream_out_desc_poll_next_desc[27] `endif
                                        `ifdef STREAM28_IN_WIDTH  | stream_in_desc_poll_next_desc[28]  `endif
                                        `ifdef STREAM28_OUT_WIDTH | stream_out_desc_poll_next_desc[28] `endif
                                        `ifdef STREAM29_IN_WIDTH  | stream_in_desc_poll_next_desc[29]  `endif
                                        `ifdef STREAM29_OUT_WIDTH | stream_out_desc_poll_next_desc[29] `endif
                                        `ifdef STREAM30_IN_WIDTH  | stream_in_desc_poll_next_desc[30]  `endif
                                        `ifdef STREAM30_OUT_WIDTH | stream_out_desc_poll_next_desc[30] `endif
                                        `ifdef STREAM31_IN_WIDTH  | stream_in_desc_poll_next_desc[31]  `endif
                                        `ifdef STREAM31_OUT_WIDTH | stream_out_desc_poll_next_desc[31] `endif
                                        `ifdef STREAM32_IN_WIDTH  | stream_in_desc_poll_next_desc[32]  `endif
                                        `ifdef STREAM32_OUT_WIDTH | stream_out_desc_poll_next_desc[32] `endif
                                        `ifdef STREAM33_IN_WIDTH  | stream_in_desc_poll_next_desc[33]  `endif
                                        `ifdef STREAM33_OUT_WIDTH | stream_out_desc_poll_next_desc[33] `endif
                                        `ifdef STREAM34_IN_WIDTH  | stream_in_desc_poll_next_desc[34]  `endif
                                        `ifdef STREAM34_OUT_WIDTH | stream_out_desc_poll_next_desc[34] `endif
                                        `ifdef STREAM35_IN_WIDTH  | stream_in_desc_poll_next_desc[35]  `endif
                                        `ifdef STREAM35_OUT_WIDTH | stream_out_desc_poll_next_desc[35] `endif
                                        `ifdef STREAM36_IN_WIDTH  | stream_in_desc_poll_next_desc[36]  `endif
                                        `ifdef STREAM36_OUT_WIDTH | stream_out_desc_poll_next_desc[36] `endif
                                        `ifdef STREAM37_IN_WIDTH  | stream_in_desc_poll_next_desc[37]  `endif
                                        `ifdef STREAM37_OUT_WIDTH | stream_out_desc_poll_next_desc[37] `endif
                                        `ifdef STREAM38_IN_WIDTH  | stream_in_desc_poll_next_desc[38]  `endif
                                        `ifdef STREAM38_OUT_WIDTH | stream_out_desc_poll_next_desc[38] `endif
                                        `ifdef STREAM39_IN_WIDTH  | stream_in_desc_poll_next_desc[39]  `endif
                                        `ifdef STREAM39_OUT_WIDTH | stream_out_desc_poll_next_desc[39] `endif
                                        `ifdef STREAM40_IN_WIDTH  | stream_in_desc_poll_next_desc[40]  `endif
                                        `ifdef STREAM40_OUT_WIDTH | stream_out_desc_poll_next_desc[40] `endif
                                        `ifdef STREAM41_IN_WIDTH  | stream_in_desc_poll_next_desc[41]  `endif
                                        `ifdef STREAM41_OUT_WIDTH | stream_out_desc_poll_next_desc[41] `endif
                                        `ifdef STREAM42_IN_WIDTH  | stream_in_desc_poll_next_desc[42]  `endif
                                        `ifdef STREAM42_OUT_WIDTH | stream_out_desc_poll_next_desc[42] `endif
                                        `ifdef STREAM43_IN_WIDTH  | stream_in_desc_poll_next_desc[43]  `endif
                                        `ifdef STREAM43_OUT_WIDTH | stream_out_desc_poll_next_desc[43] `endif
                                        `ifdef STREAM44_IN_WIDTH  | stream_in_desc_poll_next_desc[44]  `endif
                                        `ifdef STREAM44_OUT_WIDTH | stream_out_desc_poll_next_desc[44] `endif
                                        `ifdef STREAM45_IN_WIDTH  | stream_in_desc_poll_next_desc[45]  `endif
                                        `ifdef STREAM45_OUT_WIDTH | stream_out_desc_poll_next_desc[45] `endif
                                        `ifdef STREAM46_IN_WIDTH  | stream_in_desc_poll_next_desc[46]  `endif
                                        `ifdef STREAM46_OUT_WIDTH | stream_out_desc_poll_next_desc[46] `endif
                                        `ifdef STREAM47_IN_WIDTH  | stream_in_desc_poll_next_desc[47]  `endif
                                        `ifdef STREAM47_OUT_WIDTH | stream_out_desc_poll_next_desc[47] `endif
                                        `ifdef STREAM48_IN_WIDTH  | stream_in_desc_poll_next_desc[48]  `endif
                                        `ifdef STREAM48_OUT_WIDTH | stream_out_desc_poll_next_desc[48] `endif
                                        `ifdef STREAM49_IN_WIDTH  | stream_in_desc_poll_next_desc[49]  `endif
                                        `ifdef STREAM49_OUT_WIDTH | stream_out_desc_poll_next_desc[49] `endif
                                        `ifdef STREAM50_IN_WIDTH  | stream_in_desc_poll_next_desc[50]  `endif
                                        `ifdef STREAM50_OUT_WIDTH | stream_out_desc_poll_next_desc[50] `endif
                                        `ifdef STREAM51_IN_WIDTH  | stream_in_desc_poll_next_desc[51]  `endif
                                        `ifdef STREAM51_OUT_WIDTH | stream_out_desc_poll_next_desc[51] `endif
                                        `ifdef STREAM52_IN_WIDTH  | stream_in_desc_poll_next_desc[52]  `endif
                                        `ifdef STREAM52_OUT_WIDTH | stream_out_desc_poll_next_desc[52] `endif
                                        `ifdef STREAM53_IN_WIDTH  | stream_in_desc_poll_next_desc[53]  `endif
                                        `ifdef STREAM53_OUT_WIDTH | stream_out_desc_poll_next_desc[53] `endif
                                        `ifdef STREAM54_IN_WIDTH  | stream_in_desc_poll_next_desc[54]  `endif
                                        `ifdef STREAM54_OUT_WIDTH | stream_out_desc_poll_next_desc[54] `endif
                                        `ifdef STREAM55_IN_WIDTH  | stream_in_desc_poll_next_desc[55]  `endif
                                        `ifdef STREAM55_OUT_WIDTH | stream_out_desc_poll_next_desc[55] `endif
                                        `ifdef STREAM56_IN_WIDTH  | stream_in_desc_poll_next_desc[56]  `endif
                                        `ifdef STREAM56_OUT_WIDTH | stream_out_desc_poll_next_desc[56] `endif
                                        `ifdef STREAM57_IN_WIDTH  | stream_in_desc_poll_next_desc[57]  `endif
                                        `ifdef STREAM57_OUT_WIDTH | stream_out_desc_poll_next_desc[57] `endif
                                        `ifdef STREAM58_IN_WIDTH  | stream_in_desc_poll_next_desc[58]  `endif
                                        `ifdef STREAM58_OUT_WIDTH | stream_out_desc_poll_next_desc[58] `endif
                                        `ifdef STREAM59_IN_WIDTH  | stream_in_desc_poll_next_desc[59]  `endif
                                        `ifdef STREAM59_OUT_WIDTH | stream_out_desc_poll_next_desc[59] `endif
                                        `ifdef STREAM60_IN_WIDTH  | stream_in_desc_poll_next_desc[60]  `endif
                                        `ifdef STREAM60_OUT_WIDTH | stream_out_desc_poll_next_desc[60] `endif
                                        `ifdef STREAM61_IN_WIDTH  | stream_in_desc_poll_next_desc[61]  `endif
                                        `ifdef STREAM61_OUT_WIDTH | stream_out_desc_poll_next_desc[61] `endif
                                        `ifdef STREAM62_IN_WIDTH  | stream_in_desc_poll_next_desc[62]  `endif
                                        `ifdef STREAM62_OUT_WIDTH | stream_out_desc_poll_next_desc[62] `endif
                                        `ifdef STREAM63_IN_WIDTH  | stream_in_desc_poll_next_desc[63]  `endif
                                        `ifdef STREAM63_OUT_WIDTH | stream_out_desc_poll_next_desc[63] `endif
                                        `ifdef STREAM64_IN_WIDTH  | stream_in_desc_poll_next_desc[64]  `endif
                                        `ifdef STREAM64_OUT_WIDTH | stream_out_desc_poll_next_desc[64] `endif
                                        `ifdef STREAM65_IN_WIDTH  | stream_in_desc_poll_next_desc[65]  `endif
                                        `ifdef STREAM65_OUT_WIDTH | stream_out_desc_poll_next_desc[65] `endif
                                        `ifdef STREAM66_IN_WIDTH  | stream_in_desc_poll_next_desc[66]  `endif
                                        `ifdef STREAM66_OUT_WIDTH | stream_out_desc_poll_next_desc[66] `endif
                                        `ifdef STREAM67_IN_WIDTH  | stream_in_desc_poll_next_desc[67]  `endif
                                        `ifdef STREAM67_OUT_WIDTH | stream_out_desc_poll_next_desc[67] `endif
                                        `ifdef STREAM68_IN_WIDTH  | stream_in_desc_poll_next_desc[68]  `endif
                                        `ifdef STREAM68_OUT_WIDTH | stream_out_desc_poll_next_desc[68] `endif
                                        `ifdef STREAM69_IN_WIDTH  | stream_in_desc_poll_next_desc[69]  `endif
                                        `ifdef STREAM69_OUT_WIDTH | stream_out_desc_poll_next_desc[69] `endif
                                        `ifdef STREAM70_IN_WIDTH  | stream_in_desc_poll_next_desc[70]  `endif
                                        `ifdef STREAM70_OUT_WIDTH | stream_out_desc_poll_next_desc[70] `endif
                                        `ifdef STREAM71_IN_WIDTH  | stream_in_desc_poll_next_desc[71]  `endif
                                        `ifdef STREAM71_OUT_WIDTH | stream_out_desc_poll_next_desc[71] `endif
                                        `ifdef STREAM72_IN_WIDTH  | stream_in_desc_poll_next_desc[72]  `endif
                                        `ifdef STREAM72_OUT_WIDTH | stream_out_desc_poll_next_desc[72] `endif
                                        `ifdef STREAM73_IN_WIDTH  | stream_in_desc_poll_next_desc[73]  `endif
                                        `ifdef STREAM73_OUT_WIDTH | stream_out_desc_poll_next_desc[73] `endif
                                        `ifdef STREAM74_IN_WIDTH  | stream_in_desc_poll_next_desc[74]  `endif
                                        `ifdef STREAM74_OUT_WIDTH | stream_out_desc_poll_next_desc[74] `endif
                                        `ifdef STREAM75_IN_WIDTH  | stream_in_desc_poll_next_desc[75]  `endif
                                        `ifdef STREAM75_OUT_WIDTH | stream_out_desc_poll_next_desc[75] `endif
                                        `ifdef STREAM76_IN_WIDTH  | stream_in_desc_poll_next_desc[76]  `endif
                                        `ifdef STREAM76_OUT_WIDTH | stream_out_desc_poll_next_desc[76] `endif
                                        `ifdef STREAM77_IN_WIDTH  | stream_in_desc_poll_next_desc[77]  `endif
                                        `ifdef STREAM77_OUT_WIDTH | stream_out_desc_poll_next_desc[77] `endif
                                        `ifdef STREAM78_IN_WIDTH  | stream_in_desc_poll_next_desc[78]  `endif
                                        `ifdef STREAM78_OUT_WIDTH | stream_out_desc_poll_next_desc[78] `endif
                                        `ifdef STREAM79_IN_WIDTH  | stream_in_desc_poll_next_desc[79]  `endif
                                        `ifdef STREAM79_OUT_WIDTH | stream_out_desc_poll_next_desc[79] `endif
                                        `ifdef STREAM80_IN_WIDTH  | stream_in_desc_poll_next_desc[80]  `endif
                                        `ifdef STREAM80_OUT_WIDTH | stream_out_desc_poll_next_desc[80] `endif
                                        `ifdef STREAM81_IN_WIDTH  | stream_in_desc_poll_next_desc[81]  `endif
                                        `ifdef STREAM81_OUT_WIDTH | stream_out_desc_poll_next_desc[81] `endif
                                        `ifdef STREAM82_IN_WIDTH  | stream_in_desc_poll_next_desc[82]  `endif
                                        `ifdef STREAM82_OUT_WIDTH | stream_out_desc_poll_next_desc[82] `endif
                                        `ifdef STREAM83_IN_WIDTH  | stream_in_desc_poll_next_desc[83]  `endif
                                        `ifdef STREAM83_OUT_WIDTH | stream_out_desc_poll_next_desc[83] `endif
                                        `ifdef STREAM84_IN_WIDTH  | stream_in_desc_poll_next_desc[84]  `endif
                                        `ifdef STREAM84_OUT_WIDTH | stream_out_desc_poll_next_desc[84] `endif
                                        `ifdef STREAM85_IN_WIDTH  | stream_in_desc_poll_next_desc[85]  `endif
                                        `ifdef STREAM85_OUT_WIDTH | stream_out_desc_poll_next_desc[85] `endif
                                        `ifdef STREAM86_IN_WIDTH  | stream_in_desc_poll_next_desc[86]  `endif
                                        `ifdef STREAM86_OUT_WIDTH | stream_out_desc_poll_next_desc[86] `endif
                                        `ifdef STREAM87_IN_WIDTH  | stream_in_desc_poll_next_desc[87]  `endif
                                        `ifdef STREAM87_OUT_WIDTH | stream_out_desc_poll_next_desc[87] `endif
                                        `ifdef STREAM88_IN_WIDTH  | stream_in_desc_poll_next_desc[88]  `endif
                                        `ifdef STREAM88_OUT_WIDTH | stream_out_desc_poll_next_desc[88] `endif
                                        `ifdef STREAM89_IN_WIDTH  | stream_in_desc_poll_next_desc[89]  `endif
                                        `ifdef STREAM89_OUT_WIDTH | stream_out_desc_poll_next_desc[89] `endif
                                        `ifdef STREAM90_IN_WIDTH  | stream_in_desc_poll_next_desc[90]  `endif
                                        `ifdef STREAM90_OUT_WIDTH | stream_out_desc_poll_next_desc[90] `endif
                                        `ifdef STREAM91_IN_WIDTH  | stream_in_desc_poll_next_desc[91]  `endif
                                        `ifdef STREAM91_OUT_WIDTH | stream_out_desc_poll_next_desc[91] `endif
                                        `ifdef STREAM92_IN_WIDTH  | stream_in_desc_poll_next_desc[92]  `endif
                                        `ifdef STREAM92_OUT_WIDTH | stream_out_desc_poll_next_desc[92] `endif
                                        `ifdef STREAM93_IN_WIDTH  | stream_in_desc_poll_next_desc[93]  `endif
                                        `ifdef STREAM93_OUT_WIDTH | stream_out_desc_poll_next_desc[93] `endif
                                        `ifdef STREAM94_IN_WIDTH  | stream_in_desc_poll_next_desc[94]  `endif
                                        `ifdef STREAM94_OUT_WIDTH | stream_out_desc_poll_next_desc[94] `endif
                                        `ifdef STREAM95_IN_WIDTH  | stream_in_desc_poll_next_desc[95]  `endif
                                        `ifdef STREAM95_OUT_WIDTH | stream_out_desc_poll_next_desc[95] `endif
                                        `ifdef STREAM96_IN_WIDTH  | stream_in_desc_poll_next_desc[96]  `endif
                                        `ifdef STREAM96_OUT_WIDTH | stream_out_desc_poll_next_desc[96] `endif
                                        `ifdef STREAM97_IN_WIDTH  | stream_in_desc_poll_next_desc[97]  `endif
                                        `ifdef STREAM97_OUT_WIDTH | stream_out_desc_poll_next_desc[97] `endif
                                        `ifdef STREAM98_IN_WIDTH  | stream_in_desc_poll_next_desc[98]  `endif
                                        `ifdef STREAM98_OUT_WIDTH | stream_out_desc_poll_next_desc[98] `endif
                                        `ifdef STREAM99_IN_WIDTH  | stream_in_desc_poll_next_desc[99]  `endif
                                        `ifdef STREAM99_OUT_WIDTH | stream_out_desc_poll_next_desc[99] `endif
                                        `ifdef STREAM100_IN_WIDTH  | stream_in_desc_poll_next_desc[100]  `endif
                                        `ifdef STREAM100_OUT_WIDTH | stream_out_desc_poll_next_desc[100] `endif
                                        `ifdef STREAM101_IN_WIDTH  | stream_in_desc_poll_next_desc[101]  `endif
                                        `ifdef STREAM101_OUT_WIDTH | stream_out_desc_poll_next_desc[101] `endif
                                        `ifdef STREAM102_IN_WIDTH  | stream_in_desc_poll_next_desc[102]  `endif
                                        `ifdef STREAM102_OUT_WIDTH | stream_out_desc_poll_next_desc[102] `endif
                                        `ifdef STREAM103_IN_WIDTH  | stream_in_desc_poll_next_desc[103]  `endif
                                        `ifdef STREAM103_OUT_WIDTH | stream_out_desc_poll_next_desc[103] `endif
                                        `ifdef STREAM104_IN_WIDTH  | stream_in_desc_poll_next_desc[104]  `endif
                                        `ifdef STREAM104_OUT_WIDTH | stream_out_desc_poll_next_desc[104] `endif
                                        `ifdef STREAM105_IN_WIDTH  | stream_in_desc_poll_next_desc[105]  `endif
                                        `ifdef STREAM105_OUT_WIDTH | stream_out_desc_poll_next_desc[105] `endif
                                        `ifdef STREAM106_IN_WIDTH  | stream_in_desc_poll_next_desc[106]  `endif
                                        `ifdef STREAM106_OUT_WIDTH | stream_out_desc_poll_next_desc[106] `endif
                                        `ifdef STREAM107_IN_WIDTH  | stream_in_desc_poll_next_desc[107]  `endif
                                        `ifdef STREAM107_OUT_WIDTH | stream_out_desc_poll_next_desc[107] `endif
                                        `ifdef STREAM108_IN_WIDTH  | stream_in_desc_poll_next_desc[108]  `endif
                                        `ifdef STREAM108_OUT_WIDTH | stream_out_desc_poll_next_desc[108] `endif
                                        `ifdef STREAM109_IN_WIDTH  | stream_in_desc_poll_next_desc[109]  `endif
                                        `ifdef STREAM109_OUT_WIDTH | stream_out_desc_poll_next_desc[109] `endif
                                        `ifdef STREAM110_IN_WIDTH  | stream_in_desc_poll_next_desc[110]  `endif
                                        `ifdef STREAM110_OUT_WIDTH | stream_out_desc_poll_next_desc[110] `endif
                                        `ifdef STREAM111_IN_WIDTH  | stream_in_desc_poll_next_desc[111]  `endif
                                        `ifdef STREAM111_OUT_WIDTH | stream_out_desc_poll_next_desc[111] `endif
                                        `ifdef STREAM112_IN_WIDTH  | stream_in_desc_poll_next_desc[112]  `endif
                                        `ifdef STREAM112_OUT_WIDTH | stream_out_desc_poll_next_desc[112] `endif
                                        `ifdef STREAM113_IN_WIDTH  | stream_in_desc_poll_next_desc[113]  `endif
                                        `ifdef STREAM113_OUT_WIDTH | stream_out_desc_poll_next_desc[113] `endif
                                        `ifdef STREAM114_IN_WIDTH  | stream_in_desc_poll_next_desc[114]  `endif
                                        `ifdef STREAM114_OUT_WIDTH | stream_out_desc_poll_next_desc[114] `endif
                                        `ifdef STREAM115_IN_WIDTH  | stream_in_desc_poll_next_desc[115]  `endif
                                        `ifdef STREAM115_OUT_WIDTH | stream_out_desc_poll_next_desc[115] `endif
                                        `ifdef STREAM116_IN_WIDTH  | stream_in_desc_poll_next_desc[116]  `endif
                                        `ifdef STREAM116_OUT_WIDTH | stream_out_desc_poll_next_desc[116] `endif
                                        `ifdef STREAM117_IN_WIDTH  | stream_in_desc_poll_next_desc[117]  `endif
                                        `ifdef STREAM117_OUT_WIDTH | stream_out_desc_poll_next_desc[117] `endif
                                        `ifdef STREAM118_IN_WIDTH  | stream_in_desc_poll_next_desc[118]  `endif
                                        `ifdef STREAM118_OUT_WIDTH | stream_out_desc_poll_next_desc[118] `endif
                                        `ifdef STREAM119_IN_WIDTH  | stream_in_desc_poll_next_desc[119]  `endif
                                        `ifdef STREAM119_OUT_WIDTH | stream_out_desc_poll_next_desc[119] `endif
                                        `ifdef STREAM120_IN_WIDTH  | stream_in_desc_poll_next_desc[120]  `endif
                                        `ifdef STREAM120_OUT_WIDTH | stream_out_desc_poll_next_desc[120] `endif
                                        `ifdef STREAM121_IN_WIDTH  | stream_in_desc_poll_next_desc[121]  `endif
                                        `ifdef STREAM121_OUT_WIDTH | stream_out_desc_poll_next_desc[121] `endif
                                        `ifdef STREAM122_IN_WIDTH  | stream_in_desc_poll_next_desc[122]  `endif
                                        `ifdef STREAM122_OUT_WIDTH | stream_out_desc_poll_next_desc[122] `endif
                                        `ifdef STREAM123_IN_WIDTH  | stream_in_desc_poll_next_desc[123]  `endif
                                        `ifdef STREAM123_OUT_WIDTH | stream_out_desc_poll_next_desc[123] `endif
                                        `ifdef STREAM124_IN_WIDTH  | stream_in_desc_poll_next_desc[124]  `endif
                                        `ifdef STREAM124_OUT_WIDTH | stream_out_desc_poll_next_desc[124] `endif
                                        `ifdef STREAM125_IN_WIDTH  | stream_in_desc_poll_next_desc[125]  `endif
                                        `ifdef STREAM125_OUT_WIDTH | stream_out_desc_poll_next_desc[125] `endif
                                        `ifdef STREAM126_IN_WIDTH  | stream_in_desc_poll_next_desc[126]  `endif
                                        `ifdef STREAM126_OUT_WIDTH | stream_out_desc_poll_next_desc[126] `endif
                                        );
    assign s_out_data[127:0]        = (128'h0
                                        `ifdef PICOBUS_WIDTH | s_out_data_userpb `endif
                                        `ifdef STREAM1_OUT_WIDTH | stream_out_data_card[1][127:0] `endif
                                        `ifdef STREAM2_OUT_WIDTH | stream_out_data_card[2][127:0] `endif
                                        `ifdef STREAM3_OUT_WIDTH | stream_out_data_card[3][127:0] `endif
                                        `ifdef STREAM4_OUT_WIDTH | stream_out_data_card[4][127:0] `endif
                                        `ifdef STREAM5_OUT_WIDTH | stream_out_data_card[5][127:0] `endif
                                        `ifdef STREAM6_OUT_WIDTH | stream_out_data_card[6][127:0] `endif
                                        `ifdef STREAM7_OUT_WIDTH | stream_out_data_card[7][127:0] `endif
                                        `ifdef STREAM8_OUT_WIDTH | stream_out_data_card[8][127:0] `endif
                                        `ifdef STREAM9_OUT_WIDTH | stream_out_data_card[9][127:0] `endif
                                        `ifdef STREAM10_OUT_WIDTH | stream_out_data_card[10][127:0] `endif
                                        `ifdef STREAM11_OUT_WIDTH | stream_out_data_card[11][127:0] `endif
                                        `ifdef STREAM12_OUT_WIDTH | stream_out_data_card[12][127:0] `endif
                                        `ifdef STREAM13_OUT_WIDTH | stream_out_data_card[13][127:0] `endif
                                        `ifdef STREAM14_OUT_WIDTH | stream_out_data_card[14][127:0] `endif
                                        `ifdef STREAM15_OUT_WIDTH | stream_out_data_card[15][127:0] `endif
                                        `ifdef STREAM16_OUT_WIDTH | stream_out_data_card[16][127:0] `endif
                                        `ifdef STREAM17_OUT_WIDTH | stream_out_data_card[17][127:0] `endif
                                        `ifdef STREAM18_OUT_WIDTH | stream_out_data_card[18][127:0] `endif
                                        `ifdef STREAM19_OUT_WIDTH | stream_out_data_card[19][127:0] `endif
                                        `ifdef STREAM20_OUT_WIDTH | stream_out_data_card[20][127:0] `endif
                                        `ifdef STREAM21_OUT_WIDTH | stream_out_data_card[21][127:0] `endif
                                        `ifdef STREAM22_OUT_WIDTH | stream_out_data_card[22][127:0] `endif
                                        `ifdef STREAM23_OUT_WIDTH | stream_out_data_card[23][127:0] `endif
                                        `ifdef STREAM24_OUT_WIDTH | stream_out_data_card[24][127:0] `endif
                                        `ifdef STREAM25_OUT_WIDTH | stream_out_data_card[25][127:0] `endif
                                        `ifdef STREAM26_OUT_WIDTH | stream_out_data_card[26][127:0] `endif
                                        `ifdef STREAM27_OUT_WIDTH | stream_out_data_card[27][127:0] `endif
                                        `ifdef STREAM28_OUT_WIDTH | stream_out_data_card[28][127:0] `endif
                                        `ifdef STREAM29_OUT_WIDTH | stream_out_data_card[29][127:0] `endif
                                        `ifdef STREAM30_OUT_WIDTH | stream_out_data_card[30][127:0] `endif
                                        `ifdef STREAM31_OUT_WIDTH | stream_out_data_card[31][127:0] `endif
                                        `ifdef STREAM32_OUT_WIDTH | stream_out_data_card[32][127:0] `endif
                                        `ifdef STREAM33_OUT_WIDTH | stream_out_data_card[33][127:0] `endif
                                        `ifdef STREAM34_OUT_WIDTH | stream_out_data_card[34][127:0] `endif
                                        `ifdef STREAM35_OUT_WIDTH | stream_out_data_card[35][127:0] `endif
                                        `ifdef STREAM36_OUT_WIDTH | stream_out_data_card[36][127:0] `endif
                                        `ifdef STREAM37_OUT_WIDTH | stream_out_data_card[37][127:0] `endif
                                        `ifdef STREAM38_OUT_WIDTH | stream_out_data_card[38][127:0] `endif
                                        `ifdef STREAM39_OUT_WIDTH | stream_out_data_card[39][127:0] `endif
                                        `ifdef STREAM40_OUT_WIDTH | stream_out_data_card[40][127:0] `endif
                                        `ifdef STREAM41_OUT_WIDTH | stream_out_data_card[41][127:0] `endif
                                        `ifdef STREAM42_OUT_WIDTH | stream_out_data_card[42][127:0] `endif
                                        `ifdef STREAM43_OUT_WIDTH | stream_out_data_card[43][127:0] `endif
                                        `ifdef STREAM44_OUT_WIDTH | stream_out_data_card[44][127:0] `endif
                                        `ifdef STREAM45_OUT_WIDTH | stream_out_data_card[45][127:0] `endif
                                        `ifdef STREAM46_OUT_WIDTH | stream_out_data_card[46][127:0] `endif
                                        `ifdef STREAM47_OUT_WIDTH | stream_out_data_card[47][127:0] `endif
                                        `ifdef STREAM48_OUT_WIDTH | stream_out_data_card[48][127:0] `endif
                                        `ifdef STREAM49_OUT_WIDTH | stream_out_data_card[49][127:0] `endif
                                        `ifdef STREAM50_OUT_WIDTH | stream_out_data_card[50][127:0] `endif
                                        `ifdef STREAM51_OUT_WIDTH | stream_out_data_card[51][127:0] `endif
                                        `ifdef STREAM52_OUT_WIDTH | stream_out_data_card[52][127:0] `endif
                                        `ifdef STREAM53_OUT_WIDTH | stream_out_data_card[53][127:0] `endif
                                        `ifdef STREAM54_OUT_WIDTH | stream_out_data_card[54][127:0] `endif
                                        `ifdef STREAM55_OUT_WIDTH | stream_out_data_card[55][127:0] `endif
                                        `ifdef STREAM56_OUT_WIDTH | stream_out_data_card[56][127:0] `endif
                                        `ifdef STREAM57_OUT_WIDTH | stream_out_data_card[57][127:0] `endif
                                        `ifdef STREAM58_OUT_WIDTH | stream_out_data_card[58][127:0] `endif
                                        `ifdef STREAM59_OUT_WIDTH | stream_out_data_card[59][127:0] `endif
                                        `ifdef STREAM60_OUT_WIDTH | stream_out_data_card[60][127:0] `endif
                                        `ifdef STREAM61_OUT_WIDTH | stream_out_data_card[61][127:0] `endif
                                        `ifdef STREAM62_OUT_WIDTH | stream_out_data_card[62][127:0] `endif
                                        `ifdef STREAM63_OUT_WIDTH | stream_out_data_card[63][127:0] `endif
                                        `ifdef STREAM64_OUT_WIDTH | stream_out_data_card[64][127:0] `endif
                                        `ifdef STREAM65_OUT_WIDTH | stream_out_data_card[65][127:0] `endif
                                        `ifdef STREAM66_OUT_WIDTH | stream_out_data_card[66][127:0] `endif
                                        `ifdef STREAM67_OUT_WIDTH | stream_out_data_card[67][127:0] `endif
                                        `ifdef STREAM68_OUT_WIDTH | stream_out_data_card[68][127:0] `endif
                                        `ifdef STREAM69_OUT_WIDTH | stream_out_data_card[69][127:0] `endif
                                        `ifdef STREAM70_OUT_WIDTH | stream_out_data_card[70][127:0] `endif
                                        `ifdef STREAM71_OUT_WIDTH | stream_out_data_card[71][127:0] `endif
                                        `ifdef STREAM72_OUT_WIDTH | stream_out_data_card[72][127:0] `endif
                                        `ifdef STREAM73_OUT_WIDTH | stream_out_data_card[73][127:0] `endif
                                        `ifdef STREAM74_OUT_WIDTH | stream_out_data_card[74][127:0] `endif
                                        `ifdef STREAM75_OUT_WIDTH | stream_out_data_card[75][127:0] `endif
                                        `ifdef STREAM76_OUT_WIDTH | stream_out_data_card[76][127:0] `endif
                                        `ifdef STREAM77_OUT_WIDTH | stream_out_data_card[77][127:0] `endif
                                        `ifdef STREAM78_OUT_WIDTH | stream_out_data_card[78][127:0] `endif
                                        `ifdef STREAM79_OUT_WIDTH | stream_out_data_card[79][127:0] `endif
                                        `ifdef STREAM80_OUT_WIDTH | stream_out_data_card[80][127:0] `endif
                                        `ifdef STREAM81_OUT_WIDTH | stream_out_data_card[81][127:0] `endif
                                        `ifdef STREAM82_OUT_WIDTH | stream_out_data_card[82][127:0] `endif
                                        `ifdef STREAM83_OUT_WIDTH | stream_out_data_card[83][127:0] `endif
                                        `ifdef STREAM84_OUT_WIDTH | stream_out_data_card[84][127:0] `endif
                                        `ifdef STREAM85_OUT_WIDTH | stream_out_data_card[85][127:0] `endif
                                        `ifdef STREAM86_OUT_WIDTH | stream_out_data_card[86][127:0] `endif
                                        `ifdef STREAM87_OUT_WIDTH | stream_out_data_card[87][127:0] `endif
                                        `ifdef STREAM88_OUT_WIDTH | stream_out_data_card[88][127:0] `endif
                                        `ifdef STREAM89_OUT_WIDTH | stream_out_data_card[89][127:0] `endif
                                        `ifdef STREAM90_OUT_WIDTH | stream_out_data_card[90][127:0] `endif
                                        `ifdef STREAM91_OUT_WIDTH | stream_out_data_card[91][127:0] `endif
                                        `ifdef STREAM92_OUT_WIDTH | stream_out_data_card[92][127:0] `endif
                                        `ifdef STREAM93_OUT_WIDTH | stream_out_data_card[93][127:0] `endif
                                        `ifdef STREAM94_OUT_WIDTH | stream_out_data_card[94][127:0] `endif
                                        `ifdef STREAM95_OUT_WIDTH | stream_out_data_card[95][127:0] `endif
                                        `ifdef STREAM96_OUT_WIDTH | stream_out_data_card[96][127:0] `endif
                                        `ifdef STREAM97_OUT_WIDTH | stream_out_data_card[97][127:0] `endif
                                        `ifdef STREAM98_OUT_WIDTH | stream_out_data_card[98][127:0] `endif
                                        `ifdef STREAM99_OUT_WIDTH | stream_out_data_card[99][127:0] `endif
                                        `ifdef STREAM100_OUT_WIDTH | stream_out_data_card[100][127:0] `endif
                                        `ifdef STREAM101_OUT_WIDTH | stream_out_data_card[101][127:0] `endif
                                        `ifdef STREAM102_OUT_WIDTH | stream_out_data_card[102][127:0] `endif
                                        `ifdef STREAM103_OUT_WIDTH | stream_out_data_card[103][127:0] `endif
                                        `ifdef STREAM104_OUT_WIDTH | stream_out_data_card[104][127:0] `endif
                                        `ifdef STREAM105_OUT_WIDTH | stream_out_data_card[105][127:0] `endif
                                        `ifdef STREAM106_OUT_WIDTH | stream_out_data_card[106][127:0] `endif
                                        `ifdef STREAM107_OUT_WIDTH | stream_out_data_card[107][127:0] `endif
                                        `ifdef STREAM108_OUT_WIDTH | stream_out_data_card[108][127:0] `endif
                                        `ifdef STREAM109_OUT_WIDTH | stream_out_data_card[109][127:0] `endif
                                        `ifdef STREAM110_OUT_WIDTH | stream_out_data_card[110][127:0] `endif
                                        `ifdef STREAM111_OUT_WIDTH | stream_out_data_card[111][127:0] `endif
                                        `ifdef STREAM112_OUT_WIDTH | stream_out_data_card[112][127:0] `endif
                                        `ifdef STREAM113_OUT_WIDTH | stream_out_data_card[113][127:0] `endif
                                        `ifdef STREAM114_OUT_WIDTH | stream_out_data_card[114][127:0] `endif
                                        `ifdef STREAM115_OUT_WIDTH | stream_out_data_card[115][127:0] `endif
                                        `ifdef STREAM116_OUT_WIDTH | stream_out_data_card[116][127:0] `endif
                                        `ifdef STREAM117_OUT_WIDTH | stream_out_data_card[117][127:0] `endif
                                        `ifdef STREAM118_OUT_WIDTH | stream_out_data_card[118][127:0] `endif
                                        `ifdef STREAM119_OUT_WIDTH | stream_out_data_card[119][127:0] `endif
                                        `ifdef STREAM120_OUT_WIDTH | stream_out_data_card[120][127:0] `endif
                                        `ifdef STREAM121_OUT_WIDTH | stream_out_data_card[121][127:0] `endif
                                        `ifdef STREAM122_OUT_WIDTH | stream_out_data_card[122][127:0] `endif
                                        `ifdef STREAM123_OUT_WIDTH | stream_out_data_card[123][127:0] `endif
                                        `ifdef STREAM124_OUT_WIDTH | stream_out_data_card[124][127:0] `endif
                                        `ifdef STREAM125_OUT_WIDTH | stream_out_data_card[125][127:0] `endif
                                        `ifdef STREAM126_OUT_WIDTH | stream_out_data_card[126][127:0] `endif
                                        );
    
    
endmodule

