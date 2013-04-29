`timescale 1ns/1ps
`include "PicoSimParameters.v"
`include "PicoDefines.v"

// This define is used for card to card testing, and will cause miss printed statements from the sim bench.
//`define CARD2CARD

// Copyright 2011 Pico Computing Inc.
// Revision 0.00 - File Creation - 4/20/2011

/* There is no module here since this file is an auto include into PICO_128_SIM_USER_TOP inside that module.
 * The code in this file represents the link between the host (the two _SIM modules) and the card
 *  it will allow the user to simulate the bus transactions between the card and the host allowing for full simulation
 *  and pre-testing of code inside of simulation.
 */
module PicoSim #(
    parameter verbose=0,
    parameter buf_size = `data_buf_size/16,
    parameter module_name = 0
    );
// Modules named from host Side
// Outputs from card / Inputs to host
    // System Signals
    reg [15:0] checktest;      
    reg [127:0] header_lock;
    reg [127:0] host_data_q;
    reg [47:0]  full_addr;
    reg [127:0] state_ascii;
    reg sys_clk, extra_clk=0;
    `ifdef PICO_MODEL_M505
    reg clk_400=0;
    `endif // PICO_MODEL_M505
    reg sys_rst_n;
   
    //RX module signals
    wire           host_compl_done;

    wire  [127:0]  s_axis_tx_tdata;
    wire           s_axis_tx_tlast;
    wire           s_axis_tx_tvalid;
// Inputs to card / Outputs from host
    // System Signals

    // RX module signals
    wire  [127:0]  host_stream_data;
    wire  [9:0]    host_stream_inx;
    wire           host_stream_valid;
    wire  [15:0]   host_stream_tag;
    wire           host_stream_desc;
    wire           host_req_compl;
    wire           host_req_compl_wd;
    wire  [2:0]    host_req_tc;
    wire           host_req_td;
    wire           host_req_ep;
    wire  [1:0]    host_req_attr;
    wire  [9:0]    host_req_len;
    wire  [15:0]   host_req_rid;
    wire  [7:0]    host_req_tag;
    wire  [7:0]    host_req_be;
    wire  [63:0]   host_req_addr;

    wire  [63:0]   host_wr_addr;
    wire  [7:0]    host_wr_be;
    wire  [31:0]   host_wr_data;
    wire           host_wr_en;     
    wire                wr_en;
    wire           s_axis_tx_tready;
    wire  [127:0]  m_axis_rx_tdata, host_hdr,host_data;
    wire  [15:0]   m_axis_rx_tstrb,s_axis_tx_tstrb;
    wire  [21:0]   m_axis_rx_tuser;
    wire  [7:0]    host_bar_hit;
    reg   [7:0]     cmd_bar_hit;
    reg             cmd_sof, cmd_eof, cmd_align_sof;
// SIM reg / wires

    reg [127:0] memory_buf[buf_size-1:0];    // shared data buffer between directions and streams
    reg [127:0] desc_buf[255:0];
    reg [143:0] cmd_buf[255:0];
    //reg [10:0]  rd_desc_buf[31:0][31:0];
    reg [48:0]  tag_table[255:0];       // holds the request tag and address they go to.  Size based off max sim size
    reg [7:0]   cmd_cnt;        // counts the number of 128bit words
    reg [7:0]   wr_data_cnt;  // XXX might be the wrong size for larger data bufs
    reg [7:0]   desc_cnt;
    
    reg [127:0] wr_data;
    reg         wr_valid;
    reg [3:0]   wr_type;
    reg [15:0]  comp_id, tag_id;
   
    reg [31:0]  read32lock = 0;

    // RX data statemachine
    reg [127:0] stream_data_hold;
    reg         stream_valid_q;
    reg [47:0]  stream_addr;

    reg         CPLD_process = 0;
    reg [9:0]   CPLD_length = 'hX;
    reg [7:0]   CPLD_tag='hX;
    reg [8:0]   tag=9'h100;
    reg [127:0] CPLD_data=128'hX;
    reg [9:0]   CPLD_addr;
    reg [6:0]   cpld_hit, cpld_hit_q;
    reg [7:0]   tag_cnt=0, tag_store=0;
    reg [31:0]  last_seq=32'h0;
    reg         TX_lock =0;
    
    wire [9:0]  cpl_addr;
    wire [6:0]  user_cmd_type;

    reg [1:0]   buf_sel = 0;
    reg [11:0]  data_addr;
    reg [7:0]   data_cnt = 0;
    
    reg [255:0] stream_create = 256'h0;
    reg [31:0]  seq_cnt[511:0];
    reg [8:0]   stream_count=0, timeout_cnt;
    reg [7:0]   bar = 8'h01;
    reg [9:0]   bufinit;
 
    reg [127:0] mem_data_hold [1:0];
    
    reg [11:0]  readcompare, writecount;
    reg         readdone, writedone;    
    reg [127:0] membuf_checksum = 128'h0;
    reg [7:0]   addr_cnt;
    
    // Software driven Simulation
    reg         software_drive=0, software_rdy=0, software_error=0;
    reg         software_go, software_go_q;
    reg [163:0] software_cmd; // {4b Cmd} {12 mem_addr} {32 stream / addr} {32 length}  
    reg [127:0] software_data_0, software_data_1, software_data_2, software_data_3, software_data_4;
    reg [127:0] software_data_5, software_data_6, software_data_7, software_data_8, software_data_9;

    
    // USER_DIRECT_PCI wires / registers
    reg [127:0] user_return_data;
    reg [21:0]  user_return_user;
    reg         user_direct=0, user_return_valid, user_return_last;
    reg [15:0]  user_return_strb;

   
   localparam MEM_RD32_FMT_TYPE    = 7'b000_0000;
   localparam MEM_RD64_FMT_TYPE    = 7'b010_0000;
   localparam MEM_WR32_FMT_TYPE    = 7'b100_0000;
   localparam MEM_WR64_FMT_TYPE    = 7'b110_0000;
   localparam CPLD_FMT_TYPE        = 7'b100_1010;
   localparam CPL_FMT_TYPE         = 7'b000_1010;
    
   always #2.5  extra_clk <= ~extra_clk;
   always #2    sys_clk <= ~sys_clk;
   
    // 400 MHz clock for the DDR3 system on the M-505
    `ifdef PICO_MODEL_M505
    always #1.25 clk_400 <= ~clk_400;
    `endif // PICO_MODEL_M505


    // wires for the interface to the DDR3 model
    `ifdef PICO_DDR3

    reg [9:0] memStreams [1:0];
    reg [1:0] memStreamSetup = 2'b00;
    
    `ifndef PICO_SIM_MIG
    `ifdef PICO_MODEL_M501
        wire [31:0]      c0_ddr3_dq;
        wire [13:0]      c0_ddr3_addr;
        wire [2:0]       c0_ddr3_ba;
        wire             c0_ddr3_ras_n;
        wire             c0_ddr3_cas_n;
        wire             c0_ddr3_we_n;
        wire             c0_ddr3_reset_n;
        wire [3:0]       c0_ddr3_dm;
        wire [3:0]       c0_ddr3_dqs_p;
        wire [3:0]       c0_ddr3_dqs_n;
        wire             c0_ddr3_ck_p;
        wire             c0_ddr3_ck_n;
        wire             c0_ddr3_cs_n;
        wire             c0_ddr3_odt;
        wire             c0_ddr3_cke;
        wire             c0_ddr3_sda;
        wire             c0_ddr3_scl;
        wire             c0_phy_init_done;
    `elsif PICO_MODEL_M505
        wire [63:0]      c0_ddr3_dq;
        wire [15:0]      c0_ddr3_addr;
        wire [2:0]       c0_ddr3_ba;
        wire             c0_ddr3_ras_n;
        wire             c0_ddr3_cas_n;
        wire             c0_ddr3_we_n;
        wire             c0_ddr3_reset_n;
        wire [7:0]       c0_ddr3_dm;
        wire [7:0]       c0_ddr3_dqs_p;
        wire [7:0]       c0_ddr3_dqs_n;
        wire [1:0]       c0_ddr3_ck_p;
        wire [1:0]       c0_ddr3_ck_n;
        wire [1:0]       c0_ddr3_cs_n;
        wire [1:0]       c0_ddr3_odt;
        wire [1:0]       c0_ddr3_cke;
        wire             c0_ddr3_sda;
        wire             c0_ddr3_scl;
        wire             c0_phy_init_done;
    `elsif PICO_MODEL_M503
        wire [63:0]      c0_ddr3_dq;
        wire [14:0]      c0_ddr3_addr;
        wire [2:0]       c0_ddr3_ba;
        wire             c0_ddr3_ras_n;
        wire             c0_ddr3_cas_n;
        wire             c0_ddr3_we_n;
        wire             c0_ddr3_reset_n;
        wire [7:0]       c0_ddr3_dm;
        wire [7:0]       c0_ddr3_dqs_p;
        wire [7:0]       c0_ddr3_dqs_n;
        wire [1:0]       c0_ddr3_ck_p;
        wire [1:0]       c0_ddr3_ck_n;
        wire [1:0]       c0_ddr3_cs_n;
        wire [1:0]       c0_ddr3_odt;
        wire [1:0]       c0_ddr3_cke;
        wire             c0_ddr3_sda;
        wire             c0_ddr3_scl;
        wire             c0_phy_init_done;
             
        wire [63:0]      c1_ddr3_dq;
        wire [14:0]      c1_ddr3_addr;
        wire [2:0]       c1_ddr3_ba;
        wire             c1_ddr3_ras_n;
        wire             c1_ddr3_cas_n;
        wire             c1_ddr3_we_n;
        wire             c1_ddr3_reset_n;
        wire [7:0]       c1_ddr3_dm;
        wire [7:0]       c1_ddr3_dqs_p;
        wire [7:0]       c1_ddr3_dqs_n;
        wire [1:0]       c1_ddr3_ck_p;
        wire [1:0]       c1_ddr3_ck_n;
        wire [1:0]       c1_ddr3_cs_n;
        wire [1:0]       c1_ddr3_odt;
        wire [1:0]       c1_ddr3_cke;
        wire             c1_ddr3_sda;
        wire             c1_ddr3_scl;
        wire             c1_phy_init_done;
    `endif // PICO_MODEL_M503
    `endif // PICO_SIM_MIG
    `endif // PICO_DDR3
         
    `ifdef PICO_QDRII
      `ifdef PICO_MODEL_M503
        wire                   qdrii_sys_rst;

        wire [0:0]              c0_qdriip_cq_p; 
        wire [0:0]              c0_qdriip_cq_n;
        wire [0:0]              c0_qdriip_qvld;
        wire [17:0]             c0_qdriip_q;
        wire [0:0]              c0_qdriip_k_p;
        wire [0:0]              c0_qdriip_k_n;
        wire [17:0]             c0_qdriip_d;
        wire [19:0]             c0_qdriip_sa;
        wire                    c0_qdriip_w_n;
        wire                    c0_qdriip_r_n;
        wire [1:0]              c0_qdriip_bw_n;
        wire                    c0_qdriip_dll_off_n;
        wire                    c0_cal_done;
           
        wire [0:0]              c1_qdriip_cq_p;
        wire [0:0]              c1_qdriip_cq_n;
        wire [0:0]              c1_qdriip_qvld;
        wire [17:0]             c1_qdriip_q;
        wire [0:0]              c1_qdriip_k_p;
        wire [0:0]              c1_qdriip_k_n;
        wire [17:0]             c1_qdriip_d;
        wire [19:0]             c1_qdriip_sa;
        wire                    c1_qdriip_w_n;
        wire                    c1_qdriip_r_n;
        wire [1:0]              c1_qdriip_bw_n;
        wire                    c1_qdriip_dll_off_n;
        wire                    c1_cal_done;
              
        wire [0:0]              c2_qdriip_cq_p;
        wire [0:0]              c2_qdriip_cq_n;
        wire [0:0]              c2_qdriip_qvld;
        wire [17:0]             c2_qdriip_q;
        wire [0:0]              c2_qdriip_k_p;
        wire [0:0]              c2_qdriip_k_n;
        wire [17:0]             c2_qdriip_d;
        wire [19:0]             c2_qdriip_sa;
        wire                    c2_qdriip_w_n;
        wire                    c2_qdriip_r_n;
        wire [1:0]              c2_qdriip_bw_n;
        wire                    c2_qdriip_dll_off_n;
        wire                    c2_cal_done;
      // PICO_MODEL_M503
      `elsif PICO_MODEL_EX600
        wire                   qdrii_sys_rst;

        wire [0:0]              c0_qdriip_cq_p; 
        wire [0:0]              c0_qdriip_cq_n;
        wire [0:0]              c0_qdriip_qvld;
        wire [35:0]             c0_qdriip_q;
        wire [0:0]              c0_qdriip_k_p;
        wire [0:0]              c0_qdriip_k_n;
        wire [35:0]             c0_qdriip_d;
        wire [20:0]             c0_qdriip_sa;
        wire                    c0_qdriip_w_n;
        wire                    c0_qdriip_r_n;
        wire [3:0]              c0_qdriip_bw_n;
        wire                    c0_qdriip_dll_off_n;
        wire                    c0_cal_done;
           
        wire [0:0]              c1_qdriip_cq_p;
        wire [0:0]              c1_qdriip_cq_n;
        wire [0:0]              c1_qdriip_qvld;
        wire [35:0]             c1_qdriip_q;
        wire [0:0]              c1_qdriip_k_p;
        wire [0:0]              c1_qdriip_k_n;
        wire [35:0]             c1_qdriip_d;
        wire [20:0]             c1_qdriip_sa;
        wire                    c1_qdriip_w_n;
        wire                    c1_qdriip_r_n;
        wire [3:0]              c1_qdriip_bw_n;
        wire                    c1_qdriip_dll_off_n;
        wire                    c1_cal_done;
      `endif //PICO_MODEL_EX600
    `endif // PICO_QDRII
   
// Host Modules Instantiation
    PIO_128_RX_ENGINE_SIM #(
        .C_DATA_WIDTH(128),
        .TCQ(1)
    ) PIO_128_RX_ENGINE_SIM (
        .clk(sys_clk),
        .rst_n(sys_rst_n),
        
    
        .stream_data(host_stream_data),
        .stream_inx(host_stream_inx),
        .stream_valid(host_stream_valid),
        .stream_tag(host_stream_tag),
        .stream_desc(host_stream_desc),
        
        // AXI bus signals into Card TX
        .rx_hdr(host_hdr),
        .rx_data(host_data),
        .rx_sof(host_sof),
        .rx_bar_hit(host_bar_hit),
        
        .req_compl_o(host_req_compl),
        .req_compl_wd_o(host_req_compl_wd),
        .compl_done_i(host_compl_done),
        .req_tc_o(host_req_tc),
        .req_td_o(host_req_td),
        .req_ep_o(host_req_ep),
        .req_attr_o(host_req_attr),
        .req_len_o(host_req_len),
        .req_rid_o(host_req_rid),
        .req_tag_o(host_req_tag),
        .req_be_o(host_req_be),
        .req_addr_o(host_req_addr),
        
        .wr_addr_o(host_wr_addr),
        .wr_be_o(host_wr_be),
        .wr_data_o(host_wr_data),
        .wr_en_o(host_wr_en)
    );
   
    PIO_128_TX_ENGINE_SIM #(
        .C_DATA_WIDTH( 128 ),
        .TCQ(1)
    ) PIO_128_TX_ENGINE_SIM (
        .clk(sys_clk),                                  // I
        .rst_n(sys_rst_n),                              // I
        
        .wr_data (wr_data),      // I [127:0]
        .wr_valid(wr_valid),     // I
        .wr_type (wr_type),    // I [3:0]
        .wr_en   (wr_en),        // O
        
        .tx_rd_req_ok( user_direct ? 1'b0 : m_axis_rx_tready ),
        
    
        // AXIS Tx into card RX
        .s_axis_tx_tready( 1'b1 ),      // I
        .s_axis_tx_tdata( m_axis_rx_tdata[127:0] ),        // O
        .s_axis_tx_tstrb( m_axis_rx_tstrb[15:0] ),        // O
        .s_axis_tx_tlast( m_axis_rx_tlast ),        // O
        .s_axis_tx_tvalid( m_axis_rx_tvalid ),      // O
        .s_axis_tx_tuser( m_axis_rx_tuser[21:0] ),          // O
        .tx_src_dsc( ),            // O
    
        // Handshake with Rx engine
        .req_compl_i(host_req_compl),                    // I
        .req_compl_wd_i(host_req_compl_wd),              // I
        .compl_done_o(host_compl_done),                  // 0
    
        .req_tc_i(host_req_tc),                          // I [2:0]
        .req_td_i(host_req_td),                          // I
        .req_ep_i(host_req_ep),                          // I
        .req_attr_i(host_req_attr),                      // I [1:0]
        .req_len_i(host_req_len),                        // I [9:0]
        .req_rid_i(host_req_rid),                        // I [15:0]
        .req_tag_i(host_req_tag),                        // I [7:0]
        .req_be_i(host_req_be),                          // I [7:0]
        .req_addr_i(host_req_addr),                      // I [63:0]
    
        // Read Port
    
        .rd_addr_o(),                        // O [63:0]
        .rd_be_o(),                            // O [3:0]
        .rd_data_i(),                        // I [31:0]
    
        .completer_id_i(comp_id),          // I [15:0]
        .cfg_bus_mstr_enable_i(), // I
        
        .cmd_bar_hit(cmd_bar_hit),
        .cmd_sof(cmd_sof),    
        .cmd_eof(cmd_eof),     
        .cmd_align_sof(cmd_align_sof)
    );
    
    sof_catch sof_catch (
        .clk(sys_clk),
        .m_axis_rx_tdata(  s_axis_tx_tdata  ),    // I
        .m_axis_rx_tlast(  s_axis_tx_tlast  ),    // I
        .m_axis_rx_tvalid( s_axis_tx_tvalid ),    // I
        .m_axis_rx_sof ( s_axis_tx_sof )         // O
    );
    
    PCIeHdrAlignSplit HdrAligner_SIM (
        .clk(sys_clk),                              // I
        .rst_n(sys_rst_n),                          // I

        // AXIS RX host - TX card
        .m_axis_rx_tdata(  s_axis_tx_tdata  ),    // I
        .m_axis_rx_tlast(  s_axis_tx_tlast  ),    // I
        .m_axis_rx_tvalid( s_axis_tx_tvalid ),  // I
        .m_axis_rx_tready( s_axis_tx_tready ),  // O
        .m_axis_rx_tuser ( {s_axis_tx_tvalid,6'b0,s_axis_tx_sof,1'b0,3'b0,8'h1,2'b0}  ),   // I
        .m_axis_rx_tstrb ( s_axis_tx_tstrb  ),    // I

        // outputs
        .hdr(host_hdr),
        .data(host_data),
        //.valid(host_valid),
        .sof(host_sof),
        .bar_hit(host_bar_hit)
    );
    
//////////////////////////////////////////////////
///////         User Direct             //////////
//////////////////////////////////////////////////

    assign user_cmd_type =  (s_axis_tx_sof && s_axis_tx_tvalid && s_axis_tx_tdata[29]) ? {s_axis_tx_tdata[30],(s_axis_tx_tdata[30:24] == 7'b01001010)?1'b0:1'b1,s_axis_tx_tdata[28:24]} :
                            (s_axis_tx_sof && s_axis_tx_tvalid && !s_axis_tx_tdata[29])? s_axis_tx_tdata[30:24] : 7'h0;
    always @(posedge sys_clk) begin
        if ( (user_cmd_type == MEM_WR32_FMT_TYPE || user_cmd_type == MEM_WR64_FMT_TYPE) && s_axis_tx_tdata[95:76] != 20'hff34_5) begin   // This is an undelayed host_sof
            if (s_axis_tx_sof && s_axis_tx_tdata[95:88] != 8'h20)
                user_direct <= 1;
            else
                user_direct <= 0;
        end
        user_return_data    <= s_axis_tx_tdata;
        user_return_valid   <= s_axis_tx_tvalid;
        user_return_strb    <= s_axis_tx_tstrb;
        user_return_last    <= s_axis_tx_tlast;
        user_return_user    <= {s_axis_tx_tvalid,6'b0,s_axis_tx_sof,1'b0,3'b0,8'h04,2'b0};
    end    
    
//////////////////////////////////////////////////    
//////////////// Card module /////////////////////
//////////////////////////////////////////////////    
`ifdef PICO_IO
    wire [`PICO_IO-1:0] connector_io;
    assign connector_io[11:0] = connector_io[23:12];
`endif

    Pico_Toplevel #(
        .C_DATA_WIDTH( 128 )
    ) FPGA (
    `ifdef PICO_DDR3
    `ifndef PICO_SIM_MIG
        // DDR3 0
        .c0_ddr3_dq        (c0_ddr3_dq),
        .c0_ddr3_addr      (c0_ddr3_addr),
        .c0_ddr3_ba        (c0_ddr3_ba),
        .c0_ddr3_ras_n     (c0_ddr3_ras_n),
        .c0_ddr3_cas_n     (c0_ddr3_cas_n),
        .c0_ddr3_we_n      (c0_ddr3_we_n),
        .c0_ddr3_reset_n   (c0_ddr3_reset_n),
        .c0_ddr3_cs_n      (c0_ddr3_cs_n),
        .c0_ddr3_odt       (c0_ddr3_odt),
        .c0_ddr3_cke       (c0_ddr3_cke),
        .c0_ddr3_dm        (c0_ddr3_dm),
        .c0_ddr3_dqs_p     (c0_ddr3_dqs_p),
        .c0_ddr3_dqs_n     (c0_ddr3_dqs_n),
        .c0_ddr3_ck_p      (c0_ddr3_ck_p),
        .c0_ddr3_ck_n      (c0_ddr3_ck_n),
        .c0_ddr3_sda       (c0_ddr3_sda),
        .c0_ddr3_scl       (c0_ddr3_scl),
        .c0_phy_init_done  (c0_phy_init_done),
    `ifdef PICO_MODEL_M503
        // DDR3 1
        .c1_ddr3_dq        (c1_ddr3_dq),
        .c1_ddr3_addr      (c1_ddr3_addr),
        .c1_ddr3_ba        (c1_ddr3_ba),
        .c1_ddr3_ras_n     (c1_ddr3_ras_n),
        .c1_ddr3_cas_n     (c1_ddr3_cas_n),
        .c1_ddr3_we_n      (c1_ddr3_we_n),
        .c1_ddr3_reset_n   (c1_ddr3_reset_n),
        .c1_ddr3_cs_n      (c1_ddr3_cs_n),
        .c1_ddr3_odt       (c1_ddr3_odt),
        .c1_ddr3_cke       (c1_ddr3_cke),
        .c1_ddr3_dm        (c1_ddr3_dm),
        .c1_ddr3_dqs_p     (c1_ddr3_dqs_p),
        .c1_ddr3_dqs_n     (c1_ddr3_dqs_n),
        .c1_ddr3_ck_p      (c1_ddr3_ck_p),
        .c1_ddr3_ck_n      (c1_ddr3_ck_n),
        .c1_ddr3_sda       (c1_ddr3_sda),
        .c1_ddr3_scl       (c1_ddr3_scl),
        .c1_phy_init_done  (c1_phy_init_done),
    `endif // PICO_MODEL_M503
    `endif // PICO_SIM_MIG
    `endif // PICO_DDR3 
		
    `ifdef PICO_QDRII
      `ifdef PICO_MODEL_M503
        // QDRII 0
        .c0_qdriip_cq_p     ( c0_qdriip_cq_p      ),
        .c0_qdriip_cq_n     ( c0_qdriip_cq_n      ),
        .c0_qdriip_qvld     ( c0_qdriip_qvld      ),
        .c0_qdriip_q        ( c0_qdriip_q         ),
        .c0_qdriip_k_p      ( c0_qdriip_k_p       ),
        .c0_qdriip_k_n      ( c0_qdriip_k_n       ),
        .c0_qdriip_d        ( c0_qdriip_d         ),
        .c0_qdriip_sa       ( c0_qdriip_sa        ),
        .c0_qdriip_w_n      ( c0_qdriip_w_n       ),
        .c0_qdriip_r_n      ( c0_qdriip_r_n       ),
        .c0_qdriip_bw_n     ( c0_qdriip_bw_n      ),
        .c0_cal_done        ( c0_cal_done         ),
        .c0_qdriip_dll_off_n( c0_qdriip_dll_off_n ),
        // QDRII 1
        .c1_qdriip_cq_p     ( c1_qdriip_cq_p      ),
        .c1_qdriip_cq_n     ( c1_qdriip_cq_n      ),
        .c1_qdriip_qvld     ( c1_qdriip_qvld      ),
        .c1_qdriip_q        ( c1_qdriip_q         ),
        .c1_qdriip_k_p      ( c1_qdriip_k_p       ),
        .c1_qdriip_k_n      ( c1_qdriip_k_n       ),
        .c1_qdriip_d        ( c1_qdriip_d         ),
        .c1_qdriip_sa       ( c1_qdriip_sa        ),
        .c1_qdriip_w_n      ( c1_qdriip_w_n       ),
        .c1_qdriip_r_n      ( c1_qdriip_r_n       ),
        .c1_qdriip_bw_n     ( c1_qdriip_bw_n      ),
        .c1_cal_done        ( c1_cal_done         ),
        .c1_qdriip_dll_off_n( c1_qdriip_dll_off_n ),
        // QDRII 2
        .c2_qdriip_cq_p     ( c2_qdriip_cq_p      ),
        .c2_qdriip_cq_n     ( c2_qdriip_cq_n      ),
        .c2_qdriip_qvld     ( c2_qdriip_qvld      ),
        .c2_qdriip_q        ( c2_qdriip_q         ),
        .c2_qdriip_k_p      ( c2_qdriip_k_p       ),
        .c2_qdriip_k_n      ( c2_qdriip_k_n       ),
        .c2_qdriip_d        ( c2_qdriip_d         ),
        .c2_qdriip_sa       ( c2_qdriip_sa        ),
        .c2_qdriip_w_n      ( c2_qdriip_w_n       ),
        .c2_qdriip_r_n      ( c2_qdriip_r_n       ),
        .c2_qdriip_bw_n     ( c2_qdriip_bw_n      ),
        .c2_cal_done        ( c2_cal_done         ),
        .c2_qdriip_dll_off_n( c2_qdriip_dll_off_n ),
      `elsif PICO_MODEL_EX600
        // QDRII 0
        .c0_qdriip_cq_p     ( c0_qdriip_cq_p      ),
        .c0_qdriip_cq_n     ( c0_qdriip_cq_n      ),
        .c0_qdriip_qvld     ( c0_qdriip_qvld      ),
        .c0_qdriip_q        ( c0_qdriip_q         ),
        .c0_qdriip_k_p      ( c0_qdriip_k_p       ),
        .c0_qdriip_k_n      ( c0_qdriip_k_n       ),
        .c0_qdriip_d        ( c0_qdriip_d         ),
        .c0_qdriip_sa       ( c0_qdriip_sa        ),
        .c0_qdriip_w_n      ( c0_qdriip_w_n       ),
        .c0_qdriip_r_n      ( c0_qdriip_r_n       ),
        .c0_qdriip_bw_n     ( c0_qdriip_bw_n      ),
        .c0_cal_done        ( c0_cal_done         ),
        .c0_qdriip_dll_off_n( c0_qdriip_dll_off_n ),
        // QDRII 1
        .c1_qdriip_cq_p     ( c1_qdriip_cq_p      ),
        .c1_qdriip_cq_n     ( c1_qdriip_cq_n      ),
        .c1_qdriip_qvld     ( c1_qdriip_qvld      ),
        .c1_qdriip_q        ( c1_qdriip_q         ),
        .c1_qdriip_k_p      ( c1_qdriip_k_p       ),
        .c1_qdriip_k_n      ( c1_qdriip_k_n       ),
        .c1_qdriip_d        ( c1_qdriip_d         ),
        .c1_qdriip_sa       ( c1_qdriip_sa        ),
        .c1_qdriip_w_n      ( c1_qdriip_w_n       ),
        .c1_qdriip_r_n      ( c1_qdriip_r_n       ),
        .c1_qdriip_bw_n     ( c1_qdriip_bw_n      ),
        .c1_cal_done        ( c1_cal_done         ),
        .c1_qdriip_dll_off_n( c1_qdriip_dll_off_n ),
      `endif //PICO_MODEL_EX600
    `endif // PICO_QDRII
  
    .user_clk ( sys_clk ),                               // I
    .user_reset ( ~sys_rst_n ),                           // I
    .user_lnk_up (1'b1),
  
    `ifdef PICO_IO
        .connector_io(connector_io),
    `endif
    .extra_clk_p(extra_clk),
    .extra_clk_n(~extra_clk),

    `ifdef PICO_MODEL_M505
        .clk_400_p          (  clk_400 ),
        .clk_400_n          ( ~clk_400 ),
    `endif // PICO_MODEL_M505

    .s_axis_tx_tready ( s_axis_tx_tready ),         // I
    .s_axis_tx_tdata  ( s_axis_tx_tdata  ),         // O
    .s_axis_tx_tstrb  ( s_axis_tx_tstrb  ),         // O
    .s_axis_tx_tlast  ( s_axis_tx_tlast  ),         // O
    .s_axis_tx_tvalid ( s_axis_tx_tvalid ),         // O

    .m_axis_rx_tdata ( user_direct ? user_return_data  : m_axis_rx_tdata  ),          // I
    .m_axis_rx_tstrb ( user_direct ? user_return_strb  : m_axis_rx_tstrb  ),          // I
    .m_axis_rx_tlast ( user_direct ? user_return_last  : m_axis_rx_tlast  ),          // I
    .m_axis_rx_tvalid( user_direct ? user_return_valid : m_axis_rx_tvalid ),          // I
    .m_axis_rx_tready( m_axis_rx_tready ),          // O
    .m_axis_rx_tuser ( user_direct ? user_return_user  : m_axis_rx_tuser  )           // I

    //.cfg_completer_id (16'hCAFE),         // I [15:0]
    //.cfg_bus_mstr_enable ()     // I
    );
 
 
 // DDR3 Simulation Model
`ifdef PICO_DDR3
`ifndef PICO_SIM_MIG
    sim_tb_top DDR3_sim_model_0 (
        .ddr3_dq_fpga           (c0_ddr3_dq),
        .ddr3_addr_fpga         (c0_ddr3_addr),
        .ddr3_ba_fpga           (c0_ddr3_ba),
        .ddr3_ras_n_fpga        (c0_ddr3_ras_n),
        .ddr3_cas_n_fpga        (c0_ddr3_cas_n),
        .ddr3_we_n_fpga         (c0_ddr3_we_n),
        .ddr3_cs_n_fpga         (c0_ddr3_cs_n),
        .ddr3_odt_fpga          (c0_ddr3_odt),
        .ddr3_cke_fpga          (c0_ddr3_cke),
        .ddr3_reset_n           (c0_ddr3_reset_n),
        .ddr3_dm_fpga           (c0_ddr3_dm),
        .ddr3_dqs_p_fpga        (c0_ddr3_dqs_p),
        .ddr3_dqs_n_fpga        (c0_ddr3_dqs_n),
        .ddr3_ck_p_fpga         (c0_ddr3_ck_p),
        .ddr3_ck_n_fpga         (c0_ddr3_ck_n),
        .ddr3_sda               (c0_ddr3_sda),
        .ddr3_scl               (c0_ddr3_scl)
    );
`ifdef PICO_MODEL_M503
    sim_tb_top DDR3_sim_model_1 (
        .ddr3_ck_p_fpga         (c1_ddr3_ck_p),
        .ddr3_ck_n_fpga         (c1_ddr3_ck_n),
        .ddr3_addr_fpga         (c1_ddr3_addr),
        .ddr3_ba_fpga           (c1_ddr3_ba),
        .ddr3_ras_n_fpga        (c1_ddr3_ras_n),
        .ddr3_cas_n_fpga        (c1_ddr3_cas_n),
        .ddr3_we_n_fpga         (c1_ddr3_we_n),
        .ddr3_cs_n_fpga         (c1_ddr3_cs_n),
        .ddr3_cke_fpga          (c1_ddr3_cke),
        .ddr3_odt_fpga          (c1_ddr3_odt),
        .ddr3_reset_n           (c1_ddr3_reset_n),
        .ddr3_dm_fpga           (c1_ddr3_dm),
        .ddr3_dq_fpga           (c1_ddr3_dq),
        .ddr3_dqs_p_fpga        (c1_ddr3_dqs_p),
        .ddr3_dqs_n_fpga        (c1_ddr3_dqs_n),
        .ddr3_sda               (c1_ddr3_sda),
        .ddr3_scl               (c1_ddr3_scl)
    );
`endif // PICO_MODEL_M503
`endif // PICO_SIM_MIG
`endif // PICO_DDR3
 
// QDRII Simulation Models
`ifdef PICO_QDRII
   `ifdef PICO_MODEL_M503
       qdrii_sim_tb_top qdrii_sim_tb_top (
           // QDRII 0
           .c0_qdriip_cq_p         ( c0_qdriip_cq_p      ),
           .c0_qdriip_cq_n         ( c0_qdriip_cq_n      ),
           .c0_qdriip_qvld         ( c0_qdriip_qvld      ),
           .c0_qdriip_q            ( c0_qdriip_q         ),
           .c0_qdriip_k_p          ( c0_qdriip_k_p       ),
           .c0_qdriip_k_n          ( c0_qdriip_k_n       ),
           .c0_qdriip_d            ( c0_qdriip_d         ),
           .c0_qdriip_sa           ( c0_qdriip_sa        ),
           .c0_qdriip_w_n          ( c0_qdriip_w_n       ),
           .c0_qdriip_r_n          ( c0_qdriip_r_n       ),
           .c0_qdriip_bw_n         ( c0_qdriip_bw_n      ),
           .c0_qdriip_dll_off_n    ( c0_qdriip_dll_off_n ),
           // QDRII 1
           .c1_qdriip_cq_p         ( c1_qdriip_cq_p      ),
           .c1_qdriip_cq_n         ( c1_qdriip_cq_n      ),
           .c1_qdriip_qvld         ( c1_qdriip_qvld      ),
           .c1_qdriip_q            ( c1_qdriip_q         ),
           .c1_qdriip_k_p          ( c1_qdriip_k_p       ),
           .c1_qdriip_k_n          ( c1_qdriip_k_n       ),
           .c1_qdriip_d            ( c1_qdriip_d         ),
           .c1_qdriip_sa           ( c1_qdriip_sa        ),
           .c1_qdriip_w_n          ( c1_qdriip_w_n       ),
           .c1_qdriip_r_n          ( c1_qdriip_r_n       ),
           .c1_qdriip_bw_n         ( c1_qdriip_bw_n      ),
           .c1_qdriip_dll_off_n    ( c1_qdriip_dll_off_n ),
           // QDRII 2
           .c2_qdriip_cq_p         ( c2_qdriip_cq_p      ),
           .c2_qdriip_cq_n         ( c2_qdriip_cq_n      ),
           .c2_qdriip_qvld         ( c2_qdriip_qvld      ),
           .c2_qdriip_q            ( c2_qdriip_q         ),
           .c2_qdriip_k_p          ( c2_qdriip_k_p       ),
           .c2_qdriip_k_n          ( c2_qdriip_k_n       ),
           .c2_qdriip_d            ( c2_qdriip_d         ),
           .c2_qdriip_sa           ( c2_qdriip_sa        ),
           .c2_qdriip_w_n          ( c2_qdriip_w_n       ),
           .c2_qdriip_r_n          ( c2_qdriip_r_n       ),
           .c2_qdriip_bw_n         ( c2_qdriip_bw_n      ),
           .c2_qdriip_dll_off_n    ( c2_qdriip_dll_off_n )
           );
    `elsif PICO_MODEL_EX600
       qdrii_sim_tb_top qdrii_sim_tb_top (
           // QDRII 0
           .c0_qdriip_cq_p         ( c0_qdriip_cq_p      ),
           .c0_qdriip_cq_n         ( c0_qdriip_cq_n      ),
           .c0_qdriip_qvld         ( c0_qdriip_qvld      ),
           .c0_qdriip_q            ( c0_qdriip_q         ),
           .c0_qdriip_k_p          ( c0_qdriip_k_p       ),
           .c0_qdriip_k_n          ( c0_qdriip_k_n       ),
           .c0_qdriip_d            ( c0_qdriip_d         ),
           .c0_qdriip_sa           ( c0_qdriip_sa        ),
           .c0_qdriip_w_n          ( c0_qdriip_w_n       ),
           .c0_qdriip_r_n          ( c0_qdriip_r_n       ),
           .c0_qdriip_bw_n         ( c0_qdriip_bw_n      ),
           .c0_qdriip_dll_off_n    ( c0_qdriip_dll_off_n ),
           // QDRII 1
           .c1_qdriip_cq_p         ( c1_qdriip_cq_p      ),
           .c1_qdriip_cq_n         ( c1_qdriip_cq_n      ),
           .c1_qdriip_qvld         ( c1_qdriip_qvld      ),
           .c1_qdriip_q            ( c1_qdriip_q         ),
           .c1_qdriip_k_p          ( c1_qdriip_k_p       ),
           .c1_qdriip_k_n          ( c1_qdriip_k_n       ),
           .c1_qdriip_d            ( c1_qdriip_d         ),
           .c1_qdriip_sa           ( c1_qdriip_sa        ),
           .c1_qdriip_w_n          ( c1_qdriip_w_n       ),
           .c1_qdriip_r_n          ( c1_qdriip_r_n       ),
           .c1_qdriip_bw_n         ( c1_qdriip_bw_n      ),
           .c1_qdriip_dll_off_n    ( c1_qdriip_dll_off_n )
           ); 
    `endif
`endif // PICO_QDRII

        //////////////////////////
        //////// TASKS ///////////
        //////////////////////////

    function [31:0] swap32;
        input [31:0] in;
    begin
        swap32 = {in[07:00],
                  in[15:08],
                  in[23:16],
                  in[31:24]};
    end
    endfunction
 
    function [127:0] PicoReadBuffer128;
		input [11:0]     addr;
    begin
        if (addr[11:4] > buf_size) begin
		    $display("ERROR: PicoReadBuffer128 address outside memory range!");
            $stop;
        end
        if (|addr[3:0]) begin
            $display("ERROR: PicoReadBuffer128 address must be 128-bit aligned!");
            $stop;
        end
        PicoReadBuffer128 = memory_buf[addr[11:4]];
    end
    endfunction
  
    function [31:0] PicoReadBuffer32;
		input [11:0]     addr;
    begin
        if (addr[11:4] > buf_size) begin
            $display("ERROR: PicoReadBuffer32 address outside memory range!");
            $stop;
        end
        if (|addr[1:0]) begin
            $display("ERROR: PicoReadBuffer32 address must be 32-bit aligned!");
            $stop;
        end
        case ( addr[3:2] )
            0: PicoReadBuffer32 = memory_buf[addr[11:4]][31:0];
            1: PicoReadBuffer32 = memory_buf[addr[11:4]][63:32];
            2: PicoReadBuffer32 = memory_buf[addr[11:4]][95:64];
            3: PicoReadBuffer32 = memory_buf[addr[11:4]][127:96];
        endcase
    end
    endfunction

    function [127:0] PicoReadBuffer;
        input [9:0]     addr;
    begin
        $display("ERROR: using obsolete function PicoReadBuffer. Please use PicoReadBuffer32 or PicoReadBuffer128.");
        $stop;
    end
    endfunction

    function [127:0] PicoReadMem;
        input [9:0]     addr;
    begin
            $display("ERROR: using obsolete function PicoReadMem. Please use PicoReadBuffer32 or PicoReadBuffer128.");
            $stop;
    end
    endfunction

 
 // This is the base config task which prepares the bus for a data transaction.
    task PicoSimInit;  
    begin
        $display("%t: PicoSimInit", $time);
    `ifdef PICO_DDR3
        memStreams[0] = 124;
        memStreams[1] = 123;
    `endif
        sys_clk <= 0;
        sys_rst_n <= 0;
        #1000;
        sys_rst_n <= 1;
        cmd_cnt <= 0;
        wr_data_cnt <= 0;
        desc_cnt <= 0;
        wr_type[3:0] <= 0;
        comp_id    <= 16'h0;
        tag_id    <= 16'h0;
        @(posedge sys_clk);
        #1400;

          // initilize the seq_cnt register
        seq_cnt[0][31:0]=32'b0;       seq_cnt[1][31:0]=32'b0;     seq_cnt[2][31:0]=32'b0;       seq_cnt[3][31:0]=32'b0;       seq_cnt[4][31:0]=32'b0;       seq_cnt[5][31:0]=32'b0;       seq_cnt[6][31:0]=32'b0;       seq_cnt[7][31:0]=32'b0;    seq_cnt[8][31:0]=32'b0;       seq_cnt[9][31:0]=32'b0;        seq_cnt[10][31:0]=32'b0;    seq_cnt[11][31:0]=32'b0;    seq_cnt[12][31:0]=32'b0;    seq_cnt[13][31:0]=32'b0;    seq_cnt[14][31:0]=32'b0;    seq_cnt[15][31:0]=32'b0;    seq_cnt[16][31:0]=32'b0;    seq_cnt[17][31:0]=32'b0;    seq_cnt[18][31:0]=32'b0;    seq_cnt[19][31:0]=32'b0;    seq_cnt[20][31:0]=32'b0;    seq_cnt[21][31:0]=32'b0;    seq_cnt[22][31:0]=32'b0;    seq_cnt[23][31:0]=32'b0;    seq_cnt[24][31:0]=32'b0;    seq_cnt[25][31:0]=32'b0;    seq_cnt[26][31:0]=32'b0;    seq_cnt[27][31:0]=32'b0;    seq_cnt[28][31:0]=32'b0;    seq_cnt[29][31:0]=32'b0;    seq_cnt[30][31:0]=32'b0;    seq_cnt[31][31:0]=32'b0;    seq_cnt[32][31:0]=32'b0;    seq_cnt[33][31:0]=32'b0;    seq_cnt[34][31:0]=32'b0;    seq_cnt[35][31:0]=32'b0;    seq_cnt[36][31:0]=32'b0;    seq_cnt[37][31:0]=32'b0;    seq_cnt[38][31:0]=32'b0;    seq_cnt[39][31:0]=32'b0;    seq_cnt[40][31:0]=32'b0;    seq_cnt[41][31:0]=32'b0;    seq_cnt[42][31:0]=32'b0;    seq_cnt[43][31:0]=32'b0;    seq_cnt[44][31:0]=32'b0;    seq_cnt[45][31:0]=32'b0;    seq_cnt[46][31:0]=32'b0;    seq_cnt[47][31:0]=32'b0;    seq_cnt[48][31:0]=32'b0;    seq_cnt[49][31:0]=32'b0;    seq_cnt[50][31:0]=32'b0;    seq_cnt[51][31:0]=32'b0;    seq_cnt[52][31:0]=32'b0;    seq_cnt[53][31:0]=32'b0;    seq_cnt[54][31:0]=32'b0;    seq_cnt[55][31:0]=32'b0;    seq_cnt[56][31:0]=32'b0;    seq_cnt[57][31:0]=32'b0;    seq_cnt[58][31:0]=32'b0;    seq_cnt[59][31:0]=32'b0;    seq_cnt[60][31:0]=32'b0;    seq_cnt[61][31:0]=32'b0;    seq_cnt[62][31:0]=32'b0;    seq_cnt[63][31:0]=32'b0;    seq_cnt[64][31:0]=32'b0;    seq_cnt[65][31:0]=32'b0;    seq_cnt[66][31:0]=32'b0;    seq_cnt[67][31:0]=32'b0;    seq_cnt[68][31:0]=32'b0;    seq_cnt[69][31:0]=32'b0;    seq_cnt[70][31:0]=32'b0;    seq_cnt[71][31:0]=32'b0;    seq_cnt[72][31:0]=32'b0;    seq_cnt[73][31:0]=32'b0;    seq_cnt[74][31:0]=32'b0;    seq_cnt[75][31:0]=32'b0;    seq_cnt[76][31:0]=32'b0;    seq_cnt[77][31:0]=32'b0;    seq_cnt[78][31:0]=32'b0;    seq_cnt[79][31:0]=32'b0;    seq_cnt[80][31:0]=32'b0;    seq_cnt[81][31:0]=32'b0;    seq_cnt[82][31:0]=32'b0;    seq_cnt[83][31:0]=32'b0;    seq_cnt[84][31:0]=32'b0;    seq_cnt[85][31:0]=32'b0;    seq_cnt[86][31:0]=32'b0;    seq_cnt[87][31:0]=32'b0;    seq_cnt[88][31:0]=32'b0;    seq_cnt[89][31:0]=32'b0;    seq_cnt[90][31:0]=32'b0;    seq_cnt[91][31:0]=32'b0;    seq_cnt[92][31:0]=32'b0;    seq_cnt[93][31:0]=32'b0;    seq_cnt[94][31:0]=32'b0;    seq_cnt[95][31:0]=32'b0;    seq_cnt[96][31:0]=32'b0;    seq_cnt[97][31:0]=32'b0;    seq_cnt[98][31:0]=32'b0;    seq_cnt[99][31:0]=32'b0;   seq_cnt[100][31:0]=32'b0;    seq_cnt[101][31:0]=32'b0;    seq_cnt[102][31:0]=32'b0;    seq_cnt[103][31:0]=32'b0;    seq_cnt[104][31:0]=32'b0;    seq_cnt[105][31:0]=32'b0;    seq_cnt[106][31:0]=32'b0;    seq_cnt[107][31:0]=32'b0;    seq_cnt[108][31:0]=32'b0;    seq_cnt[109][31:0]=32'b0;    seq_cnt[110][31:0]=32'b0;    seq_cnt[111][31:0]=32'b0;    seq_cnt[112][31:0]=32'b0;    seq_cnt[113][31:0]=32'b0;    seq_cnt[114][31:0]=32'b0;    seq_cnt[115][31:0]=32'b0;    seq_cnt[116][31:0]=32'b0;    seq_cnt[117][31:0]=32'b0;    seq_cnt[118][31:0]=32'b0;    seq_cnt[119][31:0]=32'b0;    seq_cnt[120][31:0]=32'b0;    seq_cnt[121][31:0]=32'b0;    seq_cnt[122][31:0]=32'b0;    seq_cnt[123][31:0]=32'b0;    seq_cnt[124][31:0]=32'b0;    seq_cnt[125][31:0]=32'b0;    seq_cnt[126][31:0]=32'b0;    seq_cnt[127][31:0]=32'b0;    seq_cnt[128][31:0]=32'b0;    seq_cnt[129][31:0]=32'b0;    seq_cnt[130][31:0]=32'b0;    seq_cnt[131][31:0]=32'b0;    seq_cnt[132][31:0]=32'b0;    seq_cnt[133][31:0]=32'b0;    seq_cnt[134][31:0]=32'b0;    seq_cnt[135][31:0]=32'b0;    seq_cnt[136][31:0]=32'b0;    seq_cnt[137][31:0]=32'b0;    seq_cnt[138][31:0]=32'b0;    seq_cnt[139][31:0]=32'b0;    seq_cnt[140][31:0]=32'b0;    seq_cnt[141][31:0]=32'b0;    seq_cnt[142][31:0]=32'b0;    seq_cnt[143][31:0]=32'b0;    seq_cnt[144][31:0]=32'b0;    seq_cnt[145][31:0]=32'b0;    seq_cnt[146][31:0]=32'b0;    seq_cnt[147][31:0]=32'b0;    seq_cnt[148][31:0]=32'b0;    seq_cnt[149][31:0]=32'b0;    seq_cnt[150][31:0]=32'b0;    seq_cnt[151][31:0]=32'b0;    seq_cnt[152][31:0]=32'b0;    seq_cnt[153][31:0]=32'b0;    seq_cnt[154][31:0]=32'b0;    seq_cnt[155][31:0]=32'b0;    seq_cnt[156][31:0]=32'b0;    seq_cnt[157][31:0]=32'b0;    seq_cnt[158][31:0]=32'b0;    seq_cnt[159][31:0]=32'b0;    seq_cnt[160][31:0]=32'b0;    seq_cnt[161][31:0]=32'b0;    seq_cnt[162][31:0]=32'b0;    seq_cnt[163][31:0]=32'b0;    seq_cnt[164][31:0]=32'b0;    seq_cnt[165][31:0]=32'b0;    seq_cnt[166][31:0]=32'b0;    seq_cnt[167][31:0]=32'b0;    seq_cnt[168][31:0]=32'b0;    seq_cnt[169][31:0]=32'b0;    seq_cnt[170][31:0]=32'b0;    seq_cnt[171][31:0]=32'b0;    seq_cnt[172][31:0]=32'b0;    seq_cnt[173][31:0]=32'b0;    seq_cnt[174][31:0]=32'b0;    seq_cnt[175][31:0]=32'b0;    seq_cnt[176][31:0]=32'b0;    seq_cnt[177][31:0]=32'b0;    seq_cnt[178][31:0]=32'b0;    seq_cnt[179][31:0]=32'b0;    seq_cnt[180][31:0]=32'b0;    seq_cnt[181][31:0]=32'b0;    seq_cnt[182][31:0]=32'b0;    seq_cnt[183][31:0]=32'b0;    seq_cnt[184][31:0]=32'b0;    seq_cnt[185][31:0]=32'b0;    seq_cnt[186][31:0]=32'b0;    seq_cnt[187][31:0]=32'b0;    seq_cnt[188][31:0]=32'b0;    seq_cnt[189][31:0]=32'b0;    seq_cnt[190][31:0]=32'b0;    seq_cnt[191][31:0]=32'b0;    seq_cnt[192][31:0]=32'b0;    seq_cnt[193][31:0]=32'b0;    seq_cnt[194][31:0]=32'b0;    seq_cnt[195][31:0]=32'b0;    seq_cnt[196][31:0]=32'b0;    seq_cnt[197][31:0]=32'b0;    seq_cnt[198][31:0]=32'b0;    seq_cnt[199][31:0]=32'b0;    seq_cnt[200][31:0]=32'b0;    seq_cnt[201][31:0]=32'b0;    seq_cnt[202][31:0]=32'b0;    seq_cnt[203][31:0]=32'b0;    seq_cnt[204][31:0]=32'b0;    seq_cnt[205][31:0]=32'b0;    seq_cnt[206][31:0]=32'b0;    seq_cnt[207][31:0]=32'b0;    seq_cnt[208][31:0]=32'b0;    seq_cnt[209][31:0]=32'b0;    seq_cnt[210][31:0]=32'b0;    seq_cnt[211][31:0]=32'b0;    seq_cnt[212][31:0]=32'b0;    seq_cnt[213][31:0]=32'b0;    seq_cnt[214][31:0]=32'b0;    seq_cnt[215][31:0]=32'b0;    seq_cnt[216][31:0]=32'b0;    seq_cnt[217][31:0]=32'b0;    seq_cnt[218][31:0]=32'b0;    seq_cnt[219][31:0]=32'b0;    seq_cnt[220][31:0]=32'b0;    seq_cnt[221][31:0]=32'b0;    seq_cnt[222][31:0]=32'b0;    seq_cnt[223][31:0]=32'b0;    seq_cnt[224][31:0]=32'b0;    seq_cnt[225][31:0]=32'b0;    seq_cnt[226][31:0]=32'b0;    seq_cnt[227][31:0]=32'b0;    seq_cnt[228][31:0]=32'b0;    seq_cnt[229][31:0]=32'b0;    seq_cnt[230][31:0]=32'b0;    seq_cnt[231][31:0]=32'b0;    seq_cnt[232][31:0]=32'b0;    seq_cnt[233][31:0]=32'b0;    seq_cnt[234][31:0]=32'b0;    seq_cnt[235][31:0]=32'b0;    seq_cnt[236][31:0]=32'b0;    seq_cnt[237][31:0]=32'b0;    seq_cnt[238][31:0]=32'b0;    seq_cnt[239][31:0]=32'b0;    seq_cnt[240][31:0]=32'b0;    seq_cnt[241][31:0]=32'b0;    seq_cnt[242][31:0]=32'b0;    seq_cnt[243][31:0]=32'b0;    seq_cnt[244][31:0]=32'b0;    seq_cnt[245][31:0]=32'b0;    seq_cnt[246][31:0]=32'b0;    seq_cnt[247][31:0]=32'b0;    seq_cnt[248][31:0]=32'b0;    seq_cnt[249][31:0]=32'b0;    seq_cnt[250][31:0]=32'b0;    seq_cnt[251][31:0]=32'b0;    seq_cnt[252][31:0]=32'b0;    seq_cnt[253][31:0]=32'b0;    seq_cnt[254][31:0]=32'b0;    seq_cnt[255][31:0]=32'b0;    seq_cnt[256][31:0]=32'b0;    seq_cnt[257][31:0]=32'b0;    seq_cnt[258][31:0]=32'b0;    seq_cnt[259][31:0]=32'b0;    seq_cnt[260][31:0]=32'b0;    seq_cnt[261][31:0]=32'b0;    seq_cnt[262][31:0]=32'b0;    seq_cnt[263][31:0]=32'b0;    seq_cnt[264][31:0]=32'b0;    seq_cnt[265][31:0]=32'b0;    seq_cnt[266][31:0]=32'b0;    seq_cnt[267][31:0]=32'b0;    seq_cnt[268][31:0]=32'b0;    seq_cnt[269][31:0]=32'b0;    seq_cnt[270][31:0]=32'b0;    seq_cnt[271][31:0]=32'b0;    seq_cnt[272][31:0]=32'b0;    seq_cnt[273][31:0]=32'b0;    seq_cnt[274][31:0]=32'b0;    seq_cnt[275][31:0]=32'b0;    seq_cnt[276][31:0]=32'b0;    seq_cnt[277][31:0]=32'b0;    seq_cnt[278][31:0]=32'b0;    seq_cnt[279][31:0]=32'b0;    seq_cnt[280][31:0]=32'b0;    seq_cnt[281][31:0]=32'b0;    seq_cnt[282][31:0]=32'b0;    seq_cnt[283][31:0]=32'b0;    seq_cnt[284][31:0]=32'b0;    seq_cnt[285][31:0]=32'b0;    seq_cnt[286][31:0]=32'b0;    seq_cnt[287][31:0]=32'b0;    seq_cnt[288][31:0]=32'b0;    seq_cnt[289][31:0]=32'b0;    seq_cnt[290][31:0]=32'b0;    seq_cnt[291][31:0]=32'b0;    seq_cnt[292][31:0]=32'b0;    seq_cnt[293][31:0]=32'b0;    seq_cnt[294][31:0]=32'b0;    seq_cnt[295][31:0]=32'b0;    seq_cnt[296][31:0]=32'b0;    seq_cnt[297][31:0]=32'b0;    seq_cnt[298][31:0]=32'b0;    seq_cnt[299][31:0]=32'b0;    seq_cnt[300][31:0]=32'b0;    seq_cnt[301][31:0]=32'b0;    seq_cnt[302][31:0]=32'b0;    seq_cnt[303][31:0]=32'b0;    seq_cnt[304][31:0]=32'b0;    seq_cnt[305][31:0]=32'b0;    seq_cnt[306][31:0]=32'b0;    seq_cnt[307][31:0]=32'b0;    seq_cnt[308][31:0]=32'b0;    seq_cnt[309][31:0]=32'b0;    seq_cnt[310][31:0]=32'b0;    seq_cnt[311][31:0]=32'b0;    seq_cnt[312][31:0]=32'b0;    seq_cnt[313][31:0]=32'b0;    seq_cnt[314][31:0]=32'b0;    seq_cnt[315][31:0]=32'b0;    seq_cnt[316][31:0]=32'b0;    seq_cnt[317][31:0]=32'b0;    seq_cnt[318][31:0]=32'b0;    seq_cnt[319][31:0]=32'b0;    seq_cnt[320][31:0]=32'b0;    seq_cnt[321][31:0]=32'b0;    seq_cnt[322][31:0]=32'b0;    seq_cnt[323][31:0]=32'b0;    seq_cnt[324][31:0]=32'b0;    seq_cnt[325][31:0]=32'b0;    seq_cnt[326][31:0]=32'b0;    seq_cnt[327][31:0]=32'b0;    seq_cnt[328][31:0]=32'b0;    seq_cnt[329][31:0]=32'b0;    seq_cnt[330][31:0]=32'b0;    seq_cnt[331][31:0]=32'b0;    seq_cnt[332][31:0]=32'b0;    seq_cnt[333][31:0]=32'b0;    seq_cnt[334][31:0]=32'b0;    seq_cnt[335][31:0]=32'b0;    seq_cnt[336][31:0]=32'b0;    seq_cnt[337][31:0]=32'b0;    seq_cnt[338][31:0]=32'b0;    seq_cnt[339][31:0]=32'b0;    seq_cnt[340][31:0]=32'b0;    seq_cnt[341][31:0]=32'b0;    seq_cnt[342][31:0]=32'b0;    seq_cnt[343][31:0]=32'b0;    seq_cnt[344][31:0]=32'b0;    seq_cnt[345][31:0]=32'b0;    seq_cnt[346][31:0]=32'b0;    seq_cnt[347][31:0]=32'b0;    seq_cnt[348][31:0]=32'b0;    seq_cnt[349][31:0]=32'b0;    seq_cnt[350][31:0]=32'b0;    seq_cnt[351][31:0]=32'b0;    seq_cnt[352][31:0]=32'b0;    seq_cnt[353][31:0]=32'b0;    seq_cnt[354][31:0]=32'b0;    seq_cnt[355][31:0]=32'b0;    seq_cnt[356][31:0]=32'b0;    seq_cnt[357][31:0]=32'b0;    seq_cnt[358][31:0]=32'b0;    seq_cnt[359][31:0]=32'b0;    seq_cnt[360][31:0]=32'b0;    seq_cnt[361][31:0]=32'b0;    seq_cnt[362][31:0]=32'b0;    seq_cnt[363][31:0]=32'b0;    seq_cnt[364][31:0]=32'b0;    seq_cnt[365][31:0]=32'b0;    seq_cnt[366][31:0]=32'b0;    seq_cnt[367][31:0]=32'b0;    seq_cnt[368][31:0]=32'b0;    seq_cnt[369][31:0]=32'b0;    seq_cnt[370][31:0]=32'b0;    seq_cnt[371][31:0]=32'b0;    seq_cnt[372][31:0]=32'b0;    seq_cnt[373][31:0]=32'b0;    seq_cnt[374][31:0]=32'b0;    seq_cnt[375][31:0]=32'b0;    seq_cnt[376][31:0]=32'b0;    seq_cnt[377][31:0]=32'b0;    seq_cnt[378][31:0]=32'b0;    seq_cnt[379][31:0]=32'b0;    seq_cnt[380][31:0]=32'b0;    seq_cnt[381][31:0]=32'b0;    seq_cnt[382][31:0]=32'b0;    seq_cnt[383][31:0]=32'b0;    seq_cnt[384][31:0]=32'b0;    seq_cnt[385][31:0]=32'b0;    seq_cnt[386][31:0]=32'b0;    seq_cnt[387][31:0]=32'b0;    seq_cnt[388][31:0]=32'b0;    seq_cnt[389][31:0]=32'b0;    seq_cnt[390][31:0]=32'b0;    seq_cnt[391][31:0]=32'b0;    seq_cnt[392][31:0]=32'b0;    seq_cnt[393][31:0]=32'b0;    seq_cnt[394][31:0]=32'b0;    seq_cnt[395][31:0]=32'b0;    seq_cnt[396][31:0]=32'b0;    seq_cnt[397][31:0]=32'b0;    seq_cnt[398][31:0]=32'b0;    seq_cnt[399][31:0]=32'b0;    seq_cnt[400][31:0]=32'b0;    seq_cnt[401][31:0]=32'b0;    seq_cnt[402][31:0]=32'b0;    seq_cnt[403][31:0]=32'b0;    seq_cnt[404][31:0]=32'b0;    seq_cnt[405][31:0]=32'b0;    seq_cnt[406][31:0]=32'b0;    seq_cnt[407][31:0]=32'b0;    seq_cnt[408][31:0]=32'b0;    seq_cnt[409][31:0]=32'b0;    seq_cnt[410][31:0]=32'b0;    seq_cnt[411][31:0]=32'b0;    seq_cnt[412][31:0]=32'b0;    seq_cnt[413][31:0]=32'b0;    seq_cnt[414][31:0]=32'b0;    seq_cnt[415][31:0]=32'b0;    seq_cnt[416][31:0]=32'b0;    seq_cnt[417][31:0]=32'b0;    seq_cnt[418][31:0]=32'b0;    seq_cnt[419][31:0]=32'b0;    seq_cnt[420][31:0]=32'b0;    seq_cnt[421][31:0]=32'b0;    seq_cnt[422][31:0]=32'b0;    seq_cnt[423][31:0]=32'b0;    seq_cnt[424][31:0]=32'b0;    seq_cnt[425][31:0]=32'b0;    seq_cnt[426][31:0]=32'b0;    seq_cnt[427][31:0]=32'b0;    seq_cnt[428][31:0]=32'b0;    seq_cnt[429][31:0]=32'b0;    seq_cnt[430][31:0]=32'b0;    seq_cnt[431][31:0]=32'b0;    seq_cnt[432][31:0]=32'b0;    seq_cnt[433][31:0]=32'b0;    seq_cnt[434][31:0]=32'b0;    seq_cnt[435][31:0]=32'b0;    seq_cnt[436][31:0]=32'b0;    seq_cnt[437][31:0]=32'b0;    seq_cnt[438][31:0]=32'b0;    seq_cnt[439][31:0]=32'b0;    seq_cnt[440][31:0]=32'b0;    seq_cnt[441][31:0]=32'b0;    seq_cnt[442][31:0]=32'b0;    seq_cnt[443][31:0]=32'b0;    seq_cnt[444][31:0]=32'b0;    seq_cnt[445][31:0]=32'b0;    seq_cnt[446][31:0]=32'b0;    seq_cnt[447][31:0]=32'b0;    seq_cnt[448][31:0]=32'b0;    seq_cnt[449][31:0]=32'b0;    seq_cnt[450][31:0]=32'b0;    seq_cnt[451][31:0]=32'b0;    seq_cnt[452][31:0]=32'b0;    seq_cnt[453][31:0]=32'b0;    seq_cnt[454][31:0]=32'b0;    seq_cnt[455][31:0]=32'b0;    seq_cnt[456][31:0]=32'b0;    seq_cnt[457][31:0]=32'b0;    seq_cnt[458][31:0]=32'b0;    seq_cnt[459][31:0]=32'b0;    seq_cnt[460][31:0]=32'b0;    seq_cnt[461][31:0]=32'b0;    seq_cnt[462][31:0]=32'b0;    seq_cnt[463][31:0]=32'b0;    seq_cnt[464][31:0]=32'b0;    seq_cnt[465][31:0]=32'b0;    seq_cnt[466][31:0]=32'b0;    seq_cnt[467][31:0]=32'b0;    seq_cnt[468][31:0]=32'b0;    seq_cnt[469][31:0]=32'b0;    seq_cnt[470][31:0]=32'b0;    seq_cnt[471][31:0]=32'b0;    seq_cnt[472][31:0]=32'b0;    seq_cnt[473][31:0]=32'b0;    seq_cnt[474][31:0]=32'b0;    seq_cnt[475][31:0]=32'b0;    seq_cnt[476][31:0]=32'b0;    seq_cnt[477][31:0]=32'b0;    seq_cnt[478][31:0]=32'b0;    seq_cnt[479][31:0]=32'b0;    seq_cnt[480][31:0]=32'b0;    seq_cnt[481][31:0]=32'b0;    seq_cnt[482][31:0]=32'b0;    seq_cnt[483][31:0]=32'b0;    seq_cnt[484][31:0]=32'b0;    seq_cnt[485][31:0]=32'b0;    seq_cnt[486][31:0]=32'b0;    seq_cnt[487][31:0]=32'b0;    seq_cnt[488][31:0]=32'b0;    seq_cnt[489][31:0]=32'b0;    seq_cnt[490][31:0]=32'b0;    seq_cnt[491][31:0]=32'b0;    seq_cnt[492][31:0]=32'b0;    seq_cnt[493][31:0]=32'b0;    seq_cnt[494][31:0]=32'b0;    seq_cnt[495][31:0]=32'b0;    seq_cnt[496][31:0]=32'b0;    seq_cnt[497][31:0]=32'b0;    seq_cnt[498][31:0]=32'b0;    seq_cnt[499][31:0]=32'b0;    seq_cnt[500][31:0]=32'b0;    seq_cnt[501][31:0]=32'b0;    seq_cnt[502][31:0]=32'b0;    seq_cnt[503][31:0]=32'b0;    seq_cnt[504][31:0]=32'b0;    seq_cnt[505][31:0]=32'b0;    seq_cnt[506][31:0]=32'b0;    seq_cnt[507][31:0]=32'b0;    seq_cnt[508][31:0]=32'b0;    seq_cnt[509][31:0]=32'b0;    seq_cnt[510][31:0]=32'b0;    seq_cnt[511][31:0]=32'b0;

        #100; 
        // enable the stream machine
        // set the addr window to 0
        state_ascii <= "enable stream machine";
        w32(32'hfb900800, 32'h0);
        #100;
        w32(32'hfb900010, 32'h1);
        
        #1000; 
        PicoSim.CreateStream( 126,"in");    
        PicoSim.CreateStream( 126,"out");   
    //    PicoSim.CreateStream( 127,"out");   
    //    PicoSim.CreateStream( 127,"in");   
        stream_create[126]=1;
        stream_create[254]=1;
    //    stream_create[127]=1;
    //    stream_create[255]=1;
    
    
    `ifdef PICOBUS_WIDTH                // These are the user module Picobus streams
        PicoSim.CreateStream( 125,"in");    
        PicoSim.CreateStream( 125,"out");
        stream_create[125]=1;
        stream_create[253]=1;
    `endif
     
        `ifdef STREAM1_IN_WIDTH     PicoSim.CreateStream(1,"in");       stream_create[1]=1;  `endif
        `ifdef STREAM1_OUT_WIDTH    PicoSim.CreateStream(1,"out");      stream_create[129]=1;  `endif
        `ifdef STREAM2_IN_WIDTH     PicoSim.CreateStream(2,"in");       stream_create[2]=1;  `endif
        `ifdef STREAM2_OUT_WIDTH    PicoSim.CreateStream(2,"out");      stream_create[130]=1;  `endif
        `ifdef STREAM3_IN_WIDTH     PicoSim.CreateStream(3,"in");       stream_create[3]=1;  `endif
        `ifdef STREAM3_OUT_WIDTH    PicoSim.CreateStream(3,"out");      stream_create[131]=1;  `endif
        `ifdef STREAM4_IN_WIDTH     PicoSim.CreateStream(4,"in");       stream_create[4]=1;  `endif
        `ifdef STREAM4_OUT_WIDTH    PicoSim.CreateStream(4,"out");      stream_create[132]=1;  `endif
        `ifdef STREAM5_IN_WIDTH     PicoSim.CreateStream(5,"in");       stream_create[5]=1;  `endif
        `ifdef STREAM5_OUT_WIDTH    PicoSim.CreateStream(5,"out");      stream_create[133]=1;  `endif
        `ifdef STREAM6_IN_WIDTH     PicoSim.CreateStream(6,"in");       stream_create[6]=1;  `endif
        `ifdef STREAM6_OUT_WIDTH    PicoSim.CreateStream(6,"out");      stream_create[134]=1;  `endif
        `ifdef STREAM7_IN_WIDTH     PicoSim.CreateStream(7,"in");       stream_create[7]=1;  `endif
        `ifdef STREAM7_OUT_WIDTH    PicoSim.CreateStream(7,"out");      stream_create[135]=1;  `endif
        `ifdef STREAM8_IN_WIDTH     PicoSim.CreateStream(8,"in");       stream_create[8]=1;  `endif
        `ifdef STREAM8_OUT_WIDTH    PicoSim.CreateStream(8,"out");      stream_create[136]=1;  `endif
        `ifdef STREAM9_IN_WIDTH     PicoSim.CreateStream(9,"in");       stream_create[9]=1;  `endif
        `ifdef STREAM9_OUT_WIDTH    PicoSim.CreateStream(9,"out");      stream_create[137]=1;  `endif
        `ifdef STREAM10_IN_WIDTH    PicoSim.CreateStream(10,"in");      stream_create[10]=1;  `endif
        `ifdef STREAM10_OUT_WIDTH   PicoSim.CreateStream(10,"out");     stream_create[138]=1;  `endif
        `ifdef STREAM11_IN_WIDTH    PicoSim.CreateStream(11,"in");      stream_create[11]=1;  `endif
        `ifdef STREAM11_OUT_WIDTH   PicoSim.CreateStream(11,"out");     stream_create[139]=1;  `endif
        `ifdef STREAM12_IN_WIDTH    PicoSim.CreateStream(12,"in");      stream_create[12]=1;  `endif
        `ifdef STREAM12_OUT_WIDTH   PicoSim.CreateStream(12,"out");     stream_create[140]=1;  `endif
        `ifdef STREAM13_IN_WIDTH    PicoSim.CreateStream(13,"in");      stream_create[13]=1;  `endif
        `ifdef STREAM13_OUT_WIDTH   PicoSim.CreateStream(13,"out");     stream_create[141]=1;  `endif
        `ifdef STREAM14_IN_WIDTH    PicoSim.CreateStream(14,"in");      stream_create[14]=1;  `endif
        `ifdef STREAM14_OUT_WIDTH   PicoSim.CreateStream(14,"out");     stream_create[142]=1;  `endif
        `ifdef STREAM15_IN_WIDTH    PicoSim.CreateStream(15,"in");      stream_create[15]=1;  `endif
        `ifdef STREAM15_OUT_WIDTH   PicoSim.CreateStream(15,"out");     stream_create[143]=1;  `endif
        `ifdef STREAM16_IN_WIDTH    PicoSim.CreateStream(16,"in");      stream_create[16]=1;  `endif
        `ifdef STREAM16_OUT_WIDTH   PicoSim.CreateStream(16,"out");     stream_create[144]=1;  `endif
        `ifdef STREAM17_IN_WIDTH    PicoSim.CreateStream(17,"in");      stream_create[17]=1;  `endif
        `ifdef STREAM17_OUT_WIDTH   PicoSim.CreateStream(17,"out");     stream_create[145]=1;  `endif
        `ifdef STREAM18_IN_WIDTH    PicoSim.CreateStream(18,"in");      stream_create[18]=1;  `endif
        `ifdef STREAM18_OUT_WIDTH   PicoSim.CreateStream(18,"out");     stream_create[146]=1;  `endif
        `ifdef STREAM19_IN_WIDTH    PicoSim.CreateStream(19,"in");      stream_create[19]=1;  `endif
        `ifdef STREAM19_OUT_WIDTH   PicoSim.CreateStream(19,"out");     stream_create[147]=1;  `endif
        `ifdef STREAM20_IN_WIDTH    PicoSim.CreateStream(20,"in");      stream_create[20]=1;  `endif
        `ifdef STREAM20_OUT_WIDTH   PicoSim.CreateStream(20,"out");     stream_create[148]=1;  `endif
        `ifdef STREAM21_IN_WIDTH    PicoSim.CreateStream(21,"in");      stream_create[21]=1;  `endif
        `ifdef STREAM21_OUT_WIDTH   PicoSim.CreateStream(21,"out");     stream_create[149]=1;  `endif
        `ifdef STREAM22_IN_WIDTH    PicoSim.CreateStream(22,"in");      stream_create[22]=1;  `endif
        `ifdef STREAM22_OUT_WIDTH   PicoSim.CreateStream(22,"out");     stream_create[150]=1;  `endif
        `ifdef STREAM23_IN_WIDTH    PicoSim.CreateStream(23,"in");      stream_create[23]=1;  `endif
        `ifdef STREAM23_OUT_WIDTH   PicoSim.CreateStream(23,"out");     stream_create[151]=1;  `endif
        `ifdef STREAM24_IN_WIDTH    PicoSim.CreateStream(24,"in");      stream_create[24]=1;  `endif
        `ifdef STREAM24_OUT_WIDTH   PicoSim.CreateStream(24,"out");     stream_create[152]=1;  `endif
        `ifdef STREAM25_IN_WIDTH    PicoSim.CreateStream(25,"in");      stream_create[25]=1;  `endif
        `ifdef STREAM25_OUT_WIDTH   PicoSim.CreateStream(25,"out");     stream_create[153]=1;  `endif
        `ifdef STREAM26_IN_WIDTH    PicoSim.CreateStream(26,"in");      stream_create[26]=1;  `endif
        `ifdef STREAM26_OUT_WIDTH   PicoSim.CreateStream(26,"out");     stream_create[154]=1;  `endif
        `ifdef STREAM27_IN_WIDTH    PicoSim.CreateStream(27,"in");      stream_create[27]=1;  `endif
        `ifdef STREAM27_OUT_WIDTH   PicoSim.CreateStream(27,"out");     stream_create[155]=1;  `endif
        `ifdef STREAM28_IN_WIDTH    PicoSim.CreateStream(28,"in");      stream_create[28]=1;  `endif
        `ifdef STREAM28_OUT_WIDTH   PicoSim.CreateStream(28,"out");     stream_create[156]=1;  `endif
        `ifdef STREAM29_IN_WIDTH    PicoSim.CreateStream(29,"in");      stream_create[29]=1;  `endif
        `ifdef STREAM29_OUT_WIDTH   PicoSim.CreateStream(29,"out");     stream_create[157]=1;  `endif
        `ifdef STREAM30_IN_WIDTH    PicoSim.CreateStream(30,"in");      stream_create[30]=1;  `endif
        `ifdef STREAM30_OUT_WIDTH   PicoSim.CreateStream(30,"out");     stream_create[158]=1;  `endif
        `ifdef STREAM31_IN_WIDTH    PicoSim.CreateStream(31,"in");      stream_create[31]=1;  `endif
        `ifdef STREAM31_OUT_WIDTH   PicoSim.CreateStream(31,"out");     stream_create[159]=1;  `endif
        `ifdef STREAM32_IN_WIDTH    PicoSim.CreateStream(32,"in");      stream_create[32]=1;  `endif
        `ifdef STREAM32_OUT_WIDTH   PicoSim.CreateStream(32,"out");     stream_create[160]=1;  `endif
        `ifdef STREAM33_IN_WIDTH    PicoSim.CreateStream(33,"in");      stream_create[33]=1;  `endif
        `ifdef STREAM33_OUT_WIDTH   PicoSim.CreateStream(33,"out");     stream_create[161]=1;  `endif
        `ifdef STREAM34_IN_WIDTH    PicoSim.CreateStream(34,"in");      stream_create[34]=1;  `endif
        `ifdef STREAM34_OUT_WIDTH   PicoSim.CreateStream(34,"out");     stream_create[162]=1;  `endif
        `ifdef STREAM35_IN_WIDTH    PicoSim.CreateStream(35,"in");      stream_create[35]=1;  `endif
        `ifdef STREAM35_OUT_WIDTH   PicoSim.CreateStream(35,"out");     stream_create[163]=1;  `endif
        `ifdef STREAM36_IN_WIDTH    PicoSim.CreateStream(36,"in");      stream_create[36]=1;  `endif
        `ifdef STREAM36_OUT_WIDTH   PicoSim.CreateStream(36,"out");     stream_create[164]=1;  `endif
        `ifdef STREAM37_IN_WIDTH    PicoSim.CreateStream(37,"in");      stream_create[37]=1;  `endif
        `ifdef STREAM37_OUT_WIDTH   PicoSim.CreateStream(37,"out");     stream_create[165]=1;  `endif
        `ifdef STREAM38_IN_WIDTH    PicoSim.CreateStream(38,"in");      stream_create[38]=1;  `endif
        `ifdef STREAM38_OUT_WIDTH   PicoSim.CreateStream(38,"out");     stream_create[166]=1;  `endif
        `ifdef STREAM39_IN_WIDTH    PicoSim.CreateStream(39,"in");      stream_create[39]=1;  `endif
        `ifdef STREAM39_OUT_WIDTH   PicoSim.CreateStream(39,"out");     stream_create[167]=1;  `endif
        `ifdef STREAM40_IN_WIDTH    PicoSim.CreateStream(40,"in");      stream_create[40]=1;  `endif
        `ifdef STREAM40_OUT_WIDTH   PicoSim.CreateStream(40,"out");     stream_create[168]=1;  `endif
        `ifdef STREAM41_IN_WIDTH    PicoSim.CreateStream(41,"in");      stream_create[41]=1;  `endif
        `ifdef STREAM41_OUT_WIDTH   PicoSim.CreateStream(41,"out");     stream_create[169]=1;  `endif
        `ifdef STREAM42_IN_WIDTH    PicoSim.CreateStream(42,"in");      stream_create[42]=1;  `endif
        `ifdef STREAM42_OUT_WIDTH   PicoSim.CreateStream(42,"out");     stream_create[170]=1;  `endif
        `ifdef STREAM43_IN_WIDTH    PicoSim.CreateStream(43,"in");      stream_create[43]=1;  `endif
        `ifdef STREAM43_OUT_WIDTH   PicoSim.CreateStream(43,"out");     stream_create[171]=1;  `endif
        `ifdef STREAM44_IN_WIDTH    PicoSim.CreateStream(44,"in");      stream_create[44]=1;  `endif
        `ifdef STREAM44_OUT_WIDTH   PicoSim.CreateStream(44,"out");     stream_create[172]=1;  `endif
        `ifdef STREAM45_IN_WIDTH    PicoSim.CreateStream(45,"in");      stream_create[45]=1;  `endif
        `ifdef STREAM45_OUT_WIDTH   PicoSim.CreateStream(45,"out");     stream_create[173]=1;  `endif
        `ifdef STREAM46_IN_WIDTH    PicoSim.CreateStream(46,"in");      stream_create[46]=1;  `endif
        `ifdef STREAM46_OUT_WIDTH   PicoSim.CreateStream(46,"out");     stream_create[174]=1;  `endif
        `ifdef STREAM47_IN_WIDTH    PicoSim.CreateStream(47,"in");      stream_create[47]=1;  `endif
        `ifdef STREAM47_OUT_WIDTH   PicoSim.CreateStream(47,"out");     stream_create[175]=1;  `endif
        `ifdef STREAM48_IN_WIDTH    PicoSim.CreateStream(48,"in");      stream_create[48]=1;  `endif
        `ifdef STREAM48_OUT_WIDTH   PicoSim.CreateStream(48,"out");     stream_create[176]=1;  `endif
        `ifdef STREAM49_IN_WIDTH    PicoSim.CreateStream(49,"in");      stream_create[49]=1;  `endif
        `ifdef STREAM49_OUT_WIDTH   PicoSim.CreateStream(49,"out");     stream_create[177]=1;  `endif
        `ifdef STREAM50_IN_WIDTH    PicoSim.CreateStream(50,"in");      stream_create[50]=1;  `endif
        `ifdef STREAM50_OUT_WIDTH   PicoSim.CreateStream(50,"out");     stream_create[178]=1;  `endif
        `ifdef STREAM51_IN_WIDTH    PicoSim.CreateStream(51,"in");      stream_create[51]=1;  `endif
        `ifdef STREAM51_OUT_WIDTH   PicoSim.CreateStream(51,"out");     stream_create[179]=1;  `endif
        `ifdef STREAM52_IN_WIDTH    PicoSim.CreateStream(52,"in");      stream_create[52]=1;  `endif
        `ifdef STREAM52_OUT_WIDTH   PicoSim.CreateStream(52,"out");     stream_create[180]=1;  `endif
        `ifdef STREAM53_IN_WIDTH    PicoSim.CreateStream(53,"in");      stream_create[53]=1;  `endif
        `ifdef STREAM53_OUT_WIDTH   PicoSim.CreateStream(53,"out");     stream_create[181]=1;  `endif
        `ifdef STREAM54_IN_WIDTH    PicoSim.CreateStream(54,"in");      stream_create[54]=1;  `endif
        `ifdef STREAM54_OUT_WIDTH   PicoSim.CreateStream(54,"out");     stream_create[182]=1;  `endif
        `ifdef STREAM55_IN_WIDTH    PicoSim.CreateStream(55,"in");      stream_create[55]=1;  `endif
        `ifdef STREAM55_OUT_WIDTH   PicoSim.CreateStream(55,"out");     stream_create[183]=1;  `endif
        `ifdef STREAM56_IN_WIDTH    PicoSim.CreateStream(56,"in");      stream_create[56]=1;  `endif
        `ifdef STREAM56_OUT_WIDTH   PicoSim.CreateStream(56,"out");     stream_create[184]=1;  `endif
        `ifdef STREAM57_IN_WIDTH    PicoSim.CreateStream(57,"in");      stream_create[57]=1;  `endif
        `ifdef STREAM57_OUT_WIDTH   PicoSim.CreateStream(57,"out");     stream_create[185]=1;  `endif
        `ifdef STREAM58_IN_WIDTH    PicoSim.CreateStream(58,"in");      stream_create[58]=1;  `endif
        `ifdef STREAM58_OUT_WIDTH   PicoSim.CreateStream(58,"out");     stream_create[186]=1;  `endif
        `ifdef STREAM59_IN_WIDTH    PicoSim.CreateStream(59,"in");      stream_create[59]=1;  `endif
        `ifdef STREAM59_OUT_WIDTH   PicoSim.CreateStream(59,"out");     stream_create[187]=1;  `endif
        `ifdef STREAM60_IN_WIDTH    PicoSim.CreateStream(60,"in");      stream_create[60]=1;  `endif
        `ifdef STREAM60_OUT_WIDTH   PicoSim.CreateStream(60,"out");     stream_create[188]=1;  `endif
        `ifdef STREAM61_IN_WIDTH    PicoSim.CreateStream(61,"in");      stream_create[61]=1;  `endif
        `ifdef STREAM61_OUT_WIDTH   PicoSim.CreateStream(61,"out");     stream_create[189]=1;  `endif
        `ifdef STREAM62_IN_WIDTH    PicoSim.CreateStream(62,"in");      stream_create[62]=1;  `endif
        `ifdef STREAM62_OUT_WIDTH   PicoSim.CreateStream(62,"out");     stream_create[190]=1;  `endif
        `ifdef STREAM63_IN_WIDTH    PicoSim.CreateStream(63,"in");      stream_create[63]=1;  `endif
        `ifdef STREAM63_OUT_WIDTH   PicoSim.CreateStream(63,"out");     stream_create[191]=1;  `endif
        `ifdef STREAM64_IN_WIDTH    PicoSim.CreateStream(64,"in");      stream_create[64]=1;  `endif
        `ifdef STREAM64_OUT_WIDTH   PicoSim.CreateStream(64,"out");     stream_create[192]=1;  `endif
        `ifdef STREAM65_IN_WIDTH    PicoSim.CreateStream(65,"in");      stream_create[65]=1;  `endif
        `ifdef STREAM65_OUT_WIDTH   PicoSim.CreateStream(65,"out");     stream_create[193]=1;  `endif
        `ifdef STREAM66_IN_WIDTH    PicoSim.CreateStream(66,"in");      stream_create[66]=1;  `endif
        `ifdef STREAM66_OUT_WIDTH   PicoSim.CreateStream(66,"out");     stream_create[194]=1;  `endif
        `ifdef STREAM67_IN_WIDTH    PicoSim.CreateStream(67,"in");      stream_create[67]=1;  `endif
        `ifdef STREAM67_OUT_WIDTH   PicoSim.CreateStream(67,"out");     stream_create[195]=1;  `endif
        `ifdef STREAM68_IN_WIDTH    PicoSim.CreateStream(68,"in");      stream_create[68]=1;  `endif
        `ifdef STREAM68_OUT_WIDTH   PicoSim.CreateStream(68,"out");     stream_create[196]=1;  `endif
        `ifdef STREAM69_IN_WIDTH    PicoSim.CreateStream(69,"in");      stream_create[69]=1;  `endif
        `ifdef STREAM69_OUT_WIDTH   PicoSim.CreateStream(69,"out");     stream_create[197]=1;  `endif
        `ifdef STREAM70_IN_WIDTH    PicoSim.CreateStream(70,"in");      stream_create[70]=1;  `endif
        `ifdef STREAM70_OUT_WIDTH   PicoSim.CreateStream(70,"out");     stream_create[198]=1;  `endif
        `ifdef STREAM71_IN_WIDTH    PicoSim.CreateStream(71,"in");      stream_create[71]=1;  `endif
        `ifdef STREAM71_OUT_WIDTH   PicoSim.CreateStream(71,"out");     stream_create[199]=1;  `endif
        `ifdef STREAM72_IN_WIDTH    PicoSim.CreateStream(72,"in");      stream_create[72]=1;  `endif
        `ifdef STREAM72_OUT_WIDTH   PicoSim.CreateStream(72,"out");     stream_create[200]=1;  `endif
        `ifdef STREAM73_IN_WIDTH    PicoSim.CreateStream(73,"in");      stream_create[73]=1;  `endif
        `ifdef STREAM73_OUT_WIDTH   PicoSim.CreateStream(73,"out");     stream_create[201]=1;  `endif
        `ifdef STREAM74_IN_WIDTH    PicoSim.CreateStream(74,"in");      stream_create[74]=1;  `endif
        `ifdef STREAM74_OUT_WIDTH   PicoSim.CreateStream(74,"out");     stream_create[202]=1;  `endif
        `ifdef STREAM75_IN_WIDTH    PicoSim.CreateStream(75,"in");      stream_create[75]=1;  `endif
        `ifdef STREAM75_OUT_WIDTH   PicoSim.CreateStream(75,"out");     stream_create[203]=1;  `endif
        `ifdef STREAM76_IN_WIDTH    PicoSim.CreateStream(76,"in");      stream_create[76]=1;  `endif
        `ifdef STREAM76_OUT_WIDTH   PicoSim.CreateStream(76,"out");     stream_create[204]=1;  `endif
        `ifdef STREAM77_IN_WIDTH    PicoSim.CreateStream(77,"in");      stream_create[77]=1;  `endif
        `ifdef STREAM77_OUT_WIDTH   PicoSim.CreateStream(77,"out");     stream_create[205]=1;  `endif
        `ifdef STREAM78_IN_WIDTH    PicoSim.CreateStream(78,"in");      stream_create[78]=1;  `endif
        `ifdef STREAM78_OUT_WIDTH   PicoSim.CreateStream(78,"out");     stream_create[206]=1;  `endif
        `ifdef STREAM79_IN_WIDTH    PicoSim.CreateStream(79,"in");      stream_create[79]=1;  `endif
        `ifdef STREAM79_OUT_WIDTH   PicoSim.CreateStream(79,"out");     stream_create[207]=1;  `endif
        `ifdef STREAM80_IN_WIDTH    PicoSim.CreateStream(80,"in");      stream_create[80]=1;  `endif
        `ifdef STREAM80_OUT_WIDTH   PicoSim.CreateStream(80,"out");     stream_create[208]=1;  `endif
        `ifdef STREAM81_IN_WIDTH    PicoSim.CreateStream(81,"in");      stream_create[81]=1;  `endif
        `ifdef STREAM81_OUT_WIDTH   PicoSim.CreateStream(81,"out");     stream_create[209]=1;  `endif
        `ifdef STREAM82_IN_WIDTH    PicoSim.CreateStream(82,"in");      stream_create[82]=1;  `endif
        `ifdef STREAM82_OUT_WIDTH   PicoSim.CreateStream(82,"out");     stream_create[210]=1;  `endif
        `ifdef STREAM83_IN_WIDTH    PicoSim.CreateStream(83,"in");      stream_create[83]=1;  `endif
        `ifdef STREAM83_OUT_WIDTH   PicoSim.CreateStream(83,"out");     stream_create[211]=1;  `endif
        `ifdef STREAM84_IN_WIDTH    PicoSim.CreateStream(84,"in");      stream_create[84]=1;  `endif
        `ifdef STREAM84_OUT_WIDTH   PicoSim.CreateStream(84,"out");     stream_create[212]=1;  `endif
        `ifdef STREAM85_IN_WIDTH    PicoSim.CreateStream(85,"in");      stream_create[85]=1;  `endif
        `ifdef STREAM85_OUT_WIDTH   PicoSim.CreateStream(85,"out");     stream_create[213]=1;  `endif
        `ifdef STREAM86_IN_WIDTH    PicoSim.CreateStream(86,"in");      stream_create[86]=1;  `endif
        `ifdef STREAM86_OUT_WIDTH   PicoSim.CreateStream(86,"out");     stream_create[214]=1;  `endif
        `ifdef STREAM87_IN_WIDTH    PicoSim.CreateStream(87,"in");      stream_create[87]=1;  `endif
        `ifdef STREAM87_OUT_WIDTH   PicoSim.CreateStream(87,"out");     stream_create[215]=1;  `endif
        `ifdef STREAM88_IN_WIDTH    PicoSim.CreateStream(88,"in");      stream_create[88]=1;  `endif
        `ifdef STREAM88_OUT_WIDTH   PicoSim.CreateStream(88,"out");     stream_create[216]=1;  `endif
        `ifdef STREAM89_IN_WIDTH    PicoSim.CreateStream(89,"in");      stream_create[89]=1;  `endif
        `ifdef STREAM89_OUT_WIDTH   PicoSim.CreateStream(89,"out");     stream_create[217]=1;  `endif
        `ifdef STREAM90_IN_WIDTH    PicoSim.CreateStream(90,"in");      stream_create[90]=1;  `endif
        `ifdef STREAM90_OUT_WIDTH   PicoSim.CreateStream(90,"out");     stream_create[218]=1;  `endif
        `ifdef STREAM91_IN_WIDTH    PicoSim.CreateStream(91,"in");      stream_create[91]=1;  `endif
        `ifdef STREAM91_OUT_WIDTH   PicoSim.CreateStream(91,"out");     stream_create[219]=1;  `endif
        `ifdef STREAM92_IN_WIDTH    PicoSim.CreateStream(92,"in");      stream_create[92]=1;  `endif
        `ifdef STREAM92_OUT_WIDTH   PicoSim.CreateStream(92,"out");     stream_create[220]=1;  `endif
        `ifdef STREAM93_IN_WIDTH    PicoSim.CreateStream(93,"in");      stream_create[93]=1;  `endif
        `ifdef STREAM93_OUT_WIDTH   PicoSim.CreateStream(93,"out");     stream_create[221]=1;  `endif
        `ifdef STREAM94_IN_WIDTH    PicoSim.CreateStream(94,"in");      stream_create[94]=1;  `endif
        `ifdef STREAM94_OUT_WIDTH   PicoSim.CreateStream(94,"out");     stream_create[222]=1;  `endif
        `ifdef STREAM95_IN_WIDTH    PicoSim.CreateStream(95,"in");      stream_create[95]=1;  `endif
        `ifdef STREAM95_OUT_WIDTH   PicoSim.CreateStream(95,"out");     stream_create[223]=1;  `endif
        `ifdef STREAM96_IN_WIDTH    PicoSim.CreateStream(96,"in");      stream_create[96]=1;  `endif
        `ifdef STREAM96_OUT_WIDTH   PicoSim.CreateStream(96,"out");     stream_create[224]=1;  `endif
        `ifdef STREAM97_IN_WIDTH    PicoSim.CreateStream(97,"in");      stream_create[97]=1;  `endif
        `ifdef STREAM97_OUT_WIDTH   PicoSim.CreateStream(97,"out");     stream_create[225]=1;  `endif
        `ifdef STREAM98_IN_WIDTH    PicoSim.CreateStream(98,"in");      stream_create[98]=1;  `endif
        `ifdef STREAM98_OUT_WIDTH   PicoSim.CreateStream(98,"out");     stream_create[226]=1;  `endif
        `ifdef STREAM99_IN_WIDTH    PicoSim.CreateStream(99,"in");      stream_create[99]=1;  `endif
        `ifdef STREAM99_OUT_WIDTH   PicoSim.CreateStream(99,"out");     stream_create[227]=1;  `endif
        `ifdef STREAM100_IN_WIDTH   PicoSim.CreateStream(100,"in");     stream_create[100]=1;  `endif
        `ifdef STREAM100_OUT_WIDTH  PicoSim.CreateStream(100,"out");    stream_create[228]=1;  `endif
        `ifdef STREAM101_IN_WIDTH   PicoSim.CreateStream(101,"in");     stream_create[101]=1;  `endif
        `ifdef STREAM101_OUT_WIDTH  PicoSim.CreateStream(101,"out");    stream_create[229]=1;  `endif
        `ifdef STREAM102_IN_WIDTH   PicoSim.CreateStream(102,"in");     stream_create[102]=1;  `endif
        `ifdef STREAM102_OUT_WIDTH  PicoSim.CreateStream(102,"out");    stream_create[230]=1;  `endif
        `ifdef STREAM103_IN_WIDTH   PicoSim.CreateStream(103,"in");     stream_create[103]=1;  `endif
        `ifdef STREAM103_OUT_WIDTH  PicoSim.CreateStream(103,"out");    stream_create[231]=1;  `endif
        `ifdef STREAM104_IN_WIDTH   PicoSim.CreateStream(104,"in");     stream_create[104]=1;  `endif
        `ifdef STREAM104_OUT_WIDTH  PicoSim.CreateStream(104,"out");    stream_create[232]=1;  `endif
        `ifdef STREAM105_IN_WIDTH   PicoSim.CreateStream(105,"in");     stream_create[105]=1;  `endif
        `ifdef STREAM105_OUT_WIDTH  PicoSim.CreateStream(105,"out");    stream_create[233]=1;  `endif
        `ifdef STREAM106_IN_WIDTH   PicoSim.CreateStream(106,"in");     stream_create[106]=1;  `endif
        `ifdef STREAM106_OUT_WIDTH  PicoSim.CreateStream(106,"out");    stream_create[234]=1;  `endif
        `ifdef STREAM107_IN_WIDTH   PicoSim.CreateStream(107,"in");     stream_create[107]=1;  `endif
        `ifdef STREAM107_OUT_WIDTH  PicoSim.CreateStream(107,"out");    stream_create[235]=1;  `endif
        `ifdef STREAM108_IN_WIDTH   PicoSim.CreateStream(108,"in");     stream_create[108]=1;  `endif
        `ifdef STREAM108_OUT_WIDTH  PicoSim.CreateStream(108,"out");    stream_create[236]=1;  `endif
        `ifdef STREAM109_IN_WIDTH   PicoSim.CreateStream(109,"in");     stream_create[109]=1;  `endif
        `ifdef STREAM109_OUT_WIDTH  PicoSim.CreateStream(109,"out");    stream_create[237]=1;  `endif
        `ifdef STREAM110_IN_WIDTH   PicoSim.CreateStream(110,"in");     stream_create[110]=1;  `endif
        `ifdef STREAM110_OUT_WIDTH  PicoSim.CreateStream(110,"out");    stream_create[238]=1;  `endif
        `ifdef STREAM111_IN_WIDTH   PicoSim.CreateStream(111,"in");     stream_create[111]=1;  `endif
        `ifdef STREAM111_OUT_WIDTH  PicoSim.CreateStream(111,"out");    stream_create[239]=1;  `endif
        `ifdef STREAM112_IN_WIDTH   PicoSim.CreateStream(112,"in");     stream_create[112]=1;  `endif
        `ifdef STREAM112_OUT_WIDTH  PicoSim.CreateStream(112,"out");    stream_create[240]=1;  `endif
        `ifdef STREAM113_IN_WIDTH   PicoSim.CreateStream(113,"in");     stream_create[113]=1;  `endif
        `ifdef STREAM113_OUT_WIDTH  PicoSim.CreateStream(113,"out");    stream_create[241]=1;  `endif
        `ifdef STREAM114_IN_WIDTH   PicoSim.CreateStream(114,"in");     stream_create[114]=1;  `endif
        `ifdef STREAM114_OUT_WIDTH  PicoSim.CreateStream(114,"out");    stream_create[242]=1;  `endif
        `ifdef STREAM115_IN_WIDTH   PicoSim.CreateStream(115,"in");     stream_create[115]=1;  `endif
        `ifdef STREAM115_OUT_WIDTH  PicoSim.CreateStream(115,"out");    stream_create[243]=1;  `endif
        `ifdef STREAM116_IN_WIDTH   PicoSim.CreateStream(116,"in");     stream_create[116]=1;  `endif
        `ifdef STREAM116_OUT_WIDTH  PicoSim.CreateStream(116,"out");    stream_create[244]=1;  `endif
        `ifdef STREAM117_IN_WIDTH   PicoSim.CreateStream(117,"in");     stream_create[117]=1;  `endif
        `ifdef STREAM117_OUT_WIDTH  PicoSim.CreateStream(117,"out");    stream_create[245]=1;  `endif
        `ifdef STREAM118_IN_WIDTH   PicoSim.CreateStream(118,"in");     stream_create[118]=1;  `endif
        `ifdef STREAM118_OUT_WIDTH  PicoSim.CreateStream(118,"out");    stream_create[246]=1;  `endif
        `ifdef STREAM119_IN_WIDTH   PicoSim.CreateStream(119,"in");     stream_create[119]=1;  `endif
        `ifdef STREAM119_OUT_WIDTH  PicoSim.CreateStream(119,"out");    stream_create[247]=1;  `endif
        `ifdef STREAM120_IN_WIDTH   PicoSim.CreateStream(120,"in");     stream_create[120]=1;  `endif
        `ifdef STREAM120_OUT_WIDTH  PicoSim.CreateStream(120,"out");    stream_create[248]=1;  `endif
        `ifdef STREAM121_IN_WIDTH   PicoSim.CreateStream(121,"in");     stream_create[121]=1;  `endif
        `ifdef STREAM121_OUT_WIDTH  PicoSim.CreateStream(121,"out");    stream_create[249]=1;  `endif
        `ifdef STREAM122_IN_WIDTH   PicoSim.CreateStream(122,"in");     stream_create[122]=1;  `endif
        `ifdef STREAM122_OUT_WIDTH  PicoSim.CreateStream(122,"out");    stream_create[250]=1;  `endif
        `ifdef STREAM123_IN_WIDTH   PicoSim.CreateStream(123,"in");     stream_create[123]=1;  `endif
        `ifdef STREAM123_OUT_WIDTH  PicoSim.CreateStream(123,"out");    stream_create[251]=1;  `endif
        `ifdef STREAM124_IN_WIDTH   PicoSim.CreateStream(124,"in");     stream_create[124]=1;  `endif
        `ifdef STREAM124_OUT_WIDTH  PicoSim.CreateStream(124,"out");    stream_create[252]=1;  `endif
//        `ifdef STREAM125_IN_WIDTH   PicoSim.CreateStream(125,"in");     stream_create[125]=1;  `endif
//        `ifdef STREAM125_OUT_WIDTH  PicoSim.CreateStream(125,"out");    stream_create[253]=1;  `endif
       
        #1250;
    // initilize the mem buf to 0
        if (software_drive) begin
            software_rdy = 1;
            Software_Driven();
        end
    end
    endtask
  
    task load_desc;
        input [7:0]    addr;
        input [127:0]  desc;
    begin
        desc_buf[addr][127:0] = desc[127:0];
        //@(posedge sys_clk);
    end
    endtask
    
    task w32;  // Single 32 word write for now
        input [31:0]    addr;
        input [31:0]    data;
    begin
                                                // none, bar, command, type, 
        cmd_buf[cmd_cnt][143:0] = {16'h0,1'b1,5'b0,bar,3'b110,3'b010,2'b00,10'b0,32'h0,32'hfb900800,addr[31:0]};
        cmd_cnt = cmd_cnt + 1;  // shift the description counter up
        // no comp_id for this command type as it is a direct write
        if (verbose) $display("addr %h : data %h",addr,data);
        @(posedge sys_clk);
        cmd_buf[cmd_cnt][143:0] = {16'h0,1'b1,5'b0,bar,3'b110,3'b010,2'b00,10'b0,32'h0,(32'hfb900000 | addr[10:0]),data[31:0]};
        cmd_cnt = cmd_cnt + 1;  // shift the description counter up
        // no comp_id for this command type as it is a direct write
        @(posedge sys_clk);
    end
    endtask
  
    task w32_direct;  // Single 32 word write for now
        input [31:0]    addr;
        input [31:0]    data;
    begin
        cmd_buf[cmd_cnt][143:0] = {16'h0,1'b1,5'b0,bar,3'b110,3'b010,2'b00,10'b0,32'h0,(32'hfb900000 | addr[31:0]),data[31:0]};
        cmd_cnt = cmd_cnt + 1;  // shift the description counter up
        // no comp_id for this command type as it is a direct write
        @(posedge sys_clk);
    end
    endtask
   
    task r32;
        input [47:0]    card_addr;
        input [47:0]    data_addr;
    begin
        if( |data_addr[3:0]) begin
            $display("Data address will be trimmed to 128 bit interval");
            $stop;
        end
        cmd_buf[cmd_cnt][143:0] = {tag_id[15:0],1'b1,5'b0,bar,3'b110,3'b001,2'b10,10'b0,16'b0,card_addr[47:0],12'b0,20'b1};
        tag_table[tag_id] = {data_addr[47:4],4'b0};
        tag_id   = tag_id +1;
        cmd_cnt  = cmd_cnt + 1;  // shift the description counter up
        @(posedge sys_clk);
    end
    endtask
  
  // this is the obsolete version that shouldn't be called
    task PicoLoadBuffer;
        input [9:0]     addr;
        input [127:0]   data;
    begin
        $display("ERROR: using obsolete function PicoLoadBuffer. Please use PicoLoadBuffer32 or PicoLoadBuffer128.");
        $stop;
    end
    endtask
  
  // Simple function which allows you to load data into the memory buffer which can then be pulled into the card.
    task PicoLoadBuffer128;
        input [11:0]     addr;
        input [127:0]   data;
    begin
        if (|addr[3:0]) begin
          $display("ERROR: PicoLoadBuffer128 addresses must be 128-bit aligned!");
          $stop;
        end
        memory_buf[addr[11:4]][127:0] = data[127:0];
        if (verbose) $display("addr : 0x%h | data : 0x%h",addr,data);
    end
    endtask
  
  // Simple function which allows you to load data into the memory buffer which can then be pulled into the card.
    task PicoLoadBuffer32;
        input [11:0]     addr;
        input [31:0]   data;
    begin
        if (|addr[1:0]) begin
            $display("ERROR: PicoLoadBuffer32 addresses must be 32-bit aligned!");
            $stop;
        end
        case (addr[3:2])
            0: memory_buf[addr[11:4]][31:0]   = data[31:0];
            1: memory_buf[addr[11:4]][63:32]  = data[31:0];
            2: memory_buf[addr[11:4]][95:64]  = data[31:0];
            3: memory_buf[addr[11:4]][127:96] = data[31:0];
        endcase
        if (verbose) $display("addr : 0x%h | data : 0x%h",addr,data);
    end
    endtask

    task PicoLoadData;
        input [9:0]     addr;
        input [127:0]   data;
    begin
        $display("ERROR: using obsolete function PicoLoadData. Please use PicoLoadBuffer32 or PicoLoadBuffer128.");
        $stop;
    end
    endtask
  
  // This function allows for a data file to be read into the memory buffer.
  //It will always start at place 0 and work up through the buffer.
    task PicoLoadFile;
        input [8*32:0] datafile;
    begin
        if (verbose) $display("Loading data from file %s.", datafile);
        $readmemh(datafile, memory_buf);
        @(posedge sys_clk);
        #10;
    end
    endtask
    
    task ReadStream;
        input [6:0]     stream;
        input [11:0]    addr_h;
        input [31:0]    length;
    begin
		readdone=0;
        if (verbose) $display ("------------ DEBUG - STARTED READSTREAM CMD ------------ ");
		if (stream_create[stream+8'h80] == 0 ) begin
            $display("Stream %d is not created.",stream);
            $stop;
        end
        if ((length[3:0] != 0) || (length[31:0] > `data_buf_size)) begin
            $display("Read length Value is incorrect, halting simulation.");
            $stop;
        end
        load_desc(8'h80+stream,{64'h00000000_00600000,20'h20000,addr_h,length});
        StreamSetSeq( 32'h100 | stream, "out", 32'h10 + seq_cnt[stream+9'h100][31:0]);
        StreamSetSeq( stream, "out", length + seq_cnt[stream][31:0]);
        timeout_cnt = 0;
        // while (length[31:0] + seq_cnt[stream][31:0] != last_seq[31:0]) begin
            // timeout_cnt = timeout_cnt + 1;
            // if (verbose==2) $display ("------------ DEBUG - IN READSTREAM CMD ------------ ");
            // #20;
            // if(timeout_cnt  == 256) begin $display("STUCK IN READ STREAM"); $finish; end
        // end       
        
	   readcompare = addr_h + length-16;
/*	   while (!host_sof) begin
			if (length + seq_cnt[stream][31:0] == last_seq) last_seq <= 32'h0; // have to reset it due to only reporting to a single register.
	   #2;
	   end
*/	   #4;
        while ( (!readdone) || (length[31:0] + seq_cnt[stream][31:0] != last_seq[31:0]) ) begin
            if ( !(data_addr < readcompare) ) 
                readdone = 1;
            #2;
        end
	   	last_seq <= 32'h0; // have to reset it due to only reporting to a single register.
	    seq_cnt[stream][31:0] <= length[31:0] + seq_cnt[stream][31:0];
        seq_cnt[stream+9'h100][31:0] <= seq_cnt[stream+9'h100][31:0] + 32'h10;
        if (verbose) $display ("------------ DEBUG - LEFT READSTREAM CMD ------------ ");
		readcompare = 12'hXXX;
		readdone = 1'bX;
		#50;    
    end
    endtask

    task WriteStream;
        input [6:0]     stream;
        input [11:0]    addr_h;
        input [31:0]    length;
    begin
        if (verbose) $display ("------------ DEBUG - STARTED WRITESTREAM CMD ------------ ");
		writecount = length;
		writedone = 0;
		if (stream_create[stream] == 0 ) begin
            $display("Stream %d is not created.",stream);
            $stop;
        end
        if ( (length[3:0] != 0) || (length[31:0] > `data_buf_size) ) begin
            $display("Write length Value is incorrect, halting simulation.");
            $stop;
        end
        load_desc(8'h80+stream,{64'h00000000_00c00000,20'h20000,addr_h,length});
        StreamSetSeq( 32'h100 | stream, "in", 32'h10 + seq_cnt[stream+9'h180][31:0]);
        StreamSetSeq( stream, "in", length+ seq_cnt[8'h80+stream][31:0]);
        timeout_cnt = 0;
        // while () begin
            // timeout_cnt = timeout_cnt + 1;
            // if (verbose==2) $display ("------------ DEBUG - IN WRITESTREAM CMD ------------ ");
            // #20;
            // if(timeout_cnt == 256) begin $display("STUCK IN WRITE STREAM"); $finish; end
        // end
                
		while (!writedone  || (length[31:0] + seq_cnt[8'h80+stream][31:0] != last_seq[31:0])) begin
			#2;
		end
		#20;
		last_seq <= 32'h0; // have to reset it due to only reporting to a single register.
		seq_cnt[8'h80+stream][31:0] <= length[31:0] + seq_cnt[8'h80+stream][31:0];
        seq_cnt[stream+9'h180][31:0] <= seq_cnt[stream+9'h180][31:0] + 32'h10;
		if (verbose) $display ("------------ DEBUG - LEFT WRITESTREAM CMD ------------ ");
		writedone = 1'bX;
		#60;
		
    end
    endtask
  
    task CreateStream;
        input [6:0]     stream;
        input [8*3:0]   dir;  // valid values out, in, i/o
    begin
        if (verbose) $display("Enable Stream %d as %s",stream,dir);
        $display("Enable Stream %d as %s",stream,dir);
        
        //w32(32'hfb900800, 32'h12346000 + (stream_count << 2));
        if(dir == "in") begin     // stream host -> fpga
            w32(32'h12346000 + (stream_count << 2)  , 32'h80 | stream);
            w32(32'h12346000 + (stream_count+1 << 2), 32'h180 | stream);
            @(posedge sys_clk);
            StreamSetDesc( stream, "in", {2'b01,2'b0,1'b1,stream+8'h80,20'h0}, 32'hffff_ffff);
        end else
        if (dir == "out") begin   // stream fpgs -> host
            w32(32'h12346000 + (stream_count << 2)  , 32'h0 | stream);
            w32(32'h12346000 + (stream_count+1 << 2), 32'h100 | stream);
            @(posedge sys_clk);
            StreamSetDesc( stream, "out", {2'b01,2'b0,1'b1,stream+8'h80,20'h0}, 32'hffff_ffff);
        end else
        begin
            $display ( "Stream Enable Error, Please set direction correctly" );
            $stop;
        end
        // setting seq_push_addr
        w32(32'h12345000 | ((dir=="in" ? (8'h80 | stream) : stream) << 3), 32'hFF34_5000);
        stream_count <= stream_count +2;
        @(posedge sys_clk);
    end
    endtask
  
`ifdef PICO_DDR3  
    task ReadRam;
        input [32:0]    addr;
        input [31:0]    bytes;
        input [6:0]     memID;

        reg   [31:0]    cmdBytes;
        reg   [31:0]    remainingBytes;
        reg   [31:0]    currentBytes;
    begin
        $display("ReadRam(0x%x, 0x%x, %d)", addr, bytes, memID);
        if (memID > 1) begin
            $display("invalid memory ID.");
            $stop;
        end
        InitDDR3(memID);

        // send the command to the host memory controller to read from DRAM
        // streamAXICtrl control bits:
        // 127:125  = cmd =
        //              0: read from DDR3
        //              2: write DDR3 reset signal
        //              3: read DDR3 reset signal
        //              4: write to DDR3
        if (bytes > 16) begin
            cmdBytes = bytes - 16;
        end else begin
            cmdBytes = 0;
        end
        WriteStreamData(memStreams[memID],{3'h0,60'h0,addr,cmdBytes});
        
        // read the data in <= `data_buf_size chunks
        remainingBytes = bytes;
        while(remainingBytes > 0) begin
            if (remainingBytes > `data_buf_size) begin
                currentBytes = `data_buf_size;
            end else begin
                currentBytes = remainingBytes;
            end
            ReadStream(memStreams[memID],0,currentBytes);
            remainingBytes = remainingBytes - currentBytes;
        end
    end
    endtask
  
  // this task writes data from the buffer to the specified DDR3 stream 
  // along with a command to initiate the DDR3 write
    task WriteRam;
        input [32:0]    addr;
        input [31:0]    bytes;
        input [6:0]     memID;

        reg   [31:0]    cmdBytes;

    begin
        $display("WriteRam(0x%x, 0x%x, %d)", addr, bytes, memID);
        if (memID > 1) begin
            $display("invalid memory ID.");
            $stop;
        end
        InitDDR3(memID);
        
        // load the proper data into the buffer for the write command
        // streamAXICtrl control bits:
        // 127:125  = cmd =
        //              0: read from DDR3
        //              2: write DDR3 reset signal
        //              3: read DDR3 reset signal
        //              4: write to DDR3
        
        // write the command to the DDR3 stream
        if (bytes > 15) begin
            cmdBytes = bytes - 16;
        end else begin
            cmdBytes = 0;
        end
        WriteStreamData(memStreams[memID],{3'h4,60'h0,addr,cmdBytes});

        // write the data to the DDR3 input stream
        WriteStream(memStreams[memID],0,bytes);
    end
    endtask
    
    // task to initialize the DDR3 from a file
    // see PicoMIG.v for the format of the DDR file
    // Note: filename must be <= 50 characters
    task InitDDR3FromFile;
        input [6:0]     memID;
        input [50*8-1:0]fname;
    begin
        $display("InitDDR3FromFile(0x%x, %s)", memID, fname);
        
        // initialize the DDR so that subsequent calls to ReadRam/WriteRam will not force a reset
        //  and/or calibration
        if (memID > 1) begin
            $display("invalid memory ID.");
            $stop;
        end
        InitDDR3(memID);
        
        // call the initMem task in the sim MIG
        `ifndef PICO_SIM_MIG
        $display("InitDDR3FromFile() only valid when using the Pico simulation version of MIG");
        $display("Please contact support@picocomputing.com for more information on this task");
        $stop;
        `elsif PICO_MODEL_M503
        if (memID == `PICO_DDR3_0) begin
            FPGA.mig_DDR3_0.initMem(fname);
        end else begin
            FPGA.mig_DDR3_1.initMem(fname);
        end
        `else // PICO_MODEL_M501 || PICO_MODEL_M505
        FPGA.mig_DDR3_0.initMem(fname);
        `endif
    end
    endtask

  // checks if the DDR3 systems need to be reset
    task InitDDR3;
        input [6:0]     memID;
    begin
        
        // checks if the DDR has not yet been reset
        if (!memStreamSetup[memID]) begin
            PicoDDR3Reset(memID);
            `ifdef PICO_MODEL_M503
            // if on the M-503, reset both DDR systems in parallel
            PicoDDR3Reset(`PICO_DDR3_1 - memID);
            `endif
        
            // waits for calibration to complete on the DDR
            WaitDDR3Calibration(memID);
            `ifdef PICO_MODEL_M503
            WaitDDR3Calibration(`PICO_DDR3_1 - memID);
            `endif
        end        
    end
    endtask

  
  // reset the DDR3 system
    task PicoDDR3Reset;
        input [6:0]     memID;
    begin
        $display("PicoDDR3Reset(%d)", memID);
        if (memID > 1) begin
            $display("invalid memory ID.");
            $stop;
        end
        // streamAXICtrl control bits:
        // 127:125  = cmd =
        //              0: read from DDR3
        //              2: write DDR3 reset signal
        //              3: read DDR3 reset signal
        //              4: write to DDR3
        // 0        = ddr3_reset

        // write the DDR3 reset
        WriteStreamData(memStreams[memID], {3'h2,124'h0,1'h1});

        // release the DDR3 reset
        WriteStreamData(memStreams[memID], {3'h2,124'h0,1'h0});
    end
    endtask

  // this task reads the status of the DDR3 signals and waits for the
  // phy_init_done status bit to be a 1
    task WaitDDR3Calibration;
        input [8:0]     memID;

        reg [127:0]     status;
        reg [127:0]     mem0backup;
        integer timeout;
    begin
        if (memID > 1) begin
            $display("invalid memory ID.");
            $stop;
        end
        // save buffer location 0 for later restoration, since we'll read the status into this location.
        mem0backup = PicoReadBuffer128(0);
        // streamAXICtrl control bits:
        // 127:125  = cmd =
        //              3: read DDR3 reset signal
        for(timeout = 100; timeout>0; timeout=timeout-1) begin: wait_calibration
            // send the read DDR3 status command
            PicoLoadBuffer128(0,{3'h3,124'h0,1'h0});
            WriteStream(memStreams[memID],0,16);
        
            // read the DDR3 status bits from the memory stream
            ReadStream(memStreams[memID],0,16);
            status = PicoReadBuffer128(0);

            // check if the calibration has completed
            if (status[1:0] == 2'h2) begin
                $display("DDR3 calibration finished at timeout value: %d", timeout);
                memStreamSetup[memID] = 1;
                timeout = 1;
            end 
            // check to see if we have timed out, and if so, stop the
            // simulation
            else if (timeout == 1) begin
                $display("DDR3 Calibration loop timeout reached. Ending Simualtion\n");
                $stop;
            end 
            // sleep between status reads
            else begin
                #1000;
            end
        end
        // restore
        PicoLoadBuffer128(0, mem0backup);
        
        $display("WaitDDR3Calibration(%d) Completed", memID);
    end
    endtask
  
  // should now use WriteRam instead of this task
    task PicoWriteRam;
        input [31:0]    addr;
        input [31:0]    bytes;
        input [6:0]     memID;
    begin
        $display("WARNING: PicoWriteRam is a deprecated task.  Please update all testbenches to use WriteRam instead\n");
        WriteRam(addr,bytes,memID);
    end
    endtask

  // should now use ReadRam instead of this task
    task PicoReadRam;
        input [31:0]    addr;
        input [31:0]    bytes;
        input [6:0]     memID;
    begin
        $display("WARNING: PicoReadRam is a deprecated task.  Please update all testbenches to use ReadRam instead\n");
        ReadRam(addr,bytes,memID);
    end
    endtask
`endif //PICO_DDR3

  
    task StreamSetSeq;
        input [8:0]     stream;
        input [8*3:0]   dir;  // valid values out, in
        input [31:0]    sequence;
    begin
        if (verbose) $display("Setting Stream %d Sequence to %h",stream, sequence);
        w32_direct(32'h800 | ((dir=="in" ? (8'h80 | stream) : stream) << 2), sequence);
    end
    endtask
  
    task StreamSetDesc;
        input [7:0]     stream;
        input [8*3:0]   dir;  // valid values out, in
        input [31:0]    addr;
        input [31:0]    len;
    begin
        if (verbose) $display("Setting Descriptor");
        w32(32'h12301008 | (( dir=="in" ? (8'h80 | stream) : stream) << 4), 32'h0000_0000 | (1 << 24 ) | (1 << 23) | (4'hc << 16) );
        w32(32'h12301004 | (( dir=="in" ? (8'h80 | stream) : stream) << 4), addr);
        w32(32'h12301000 | (( dir=="in" ? (8'h80 | stream) : stream) << 4), len);
    end
    endtask
  
    task WriteStreamData;             // This writes a single word to the stream
        input [7:0] stream;
        input [127:0] data;
    begin
        mem_data_hold[8'h00][127:0] = memory_buf[8'h00][127:0];
        PicoLoadBuffer128(8'h00,data);
        #5;
        WriteStream(stream,12'h000,32'h10);
        #5;
        memory_buf[8'h00][127:0] = mem_data_hold[8'h00][127:0];
        #100;
    end
    endtask
  
    task PicoInternalBusWrite;        // These functions use the stream call, and have size passed to them from the other s fucntions
        input [7:0]     stream;
        input [7:0]     bus_size;
        input [31:0]    addr;
        input [127:0]   data;
    begin
        mem_data_hold[8'h00][127:0] = memory_buf[8'h00][127:0];
        mem_data_hold[8'h01][127:0] = memory_buf[8'h01][127:0];
    
        if (bus_size == 32) begin
            PicoLoadBuffer128(8'h00,{64'h0,addr,32'h04});
            PicoLoadBuffer128(8'h010,data);
            #2;
            WriteStream(stream,12'h000,32'h20);
        end
        if (bus_size == 128) begin
            PicoLoadBuffer128(8'h00,{64'h0,addr,32'h10});
            PicoLoadBuffer128(8'h010,data);
            #2;
            WriteStream(stream,12'h000,32'h20);
        end
        #5;
        memory_buf[8'h00][127:0] = mem_data_hold[8'h00][127:0];
        memory_buf[8'h01][127:0] = mem_data_hold[8'h01][127:0];
        #100;
    end
    endtask
  
    task PicoInternalBusRead;         // These functions use the stream call, and have size passed to them from the other picobus fucntions
        input [7:0]     stream;
        input [7:0]     bus_size;
        input [31:0]    addr;
        input [31:0]    length;
        input [11:0]    addr_h;
    begin
        mem_data_hold[8'h00][127:0] = memory_buf[8'h00][127:0];
		if (bus_size == 32) begin  // currently the same function as the 128 but should be fine as the fifo will give back 128bits of data
            if ( length[1:0] != 0 ) begin
                $display("Length Value is incorrect, halting simulation.");
                $stop;
            end
            PicoLoadBuffer128(8'h00,{64'h1,addr,length});
            WriteStream(stream, 8'h00, 32'h10);
            read32lock = length;
            if (length < 32'h10)
                ReadStream(stream, addr_h, 32'h10);
            else if (length[3:0])   // if the bottom bits in length are set, set them to 0 and add one ot the read
                ReadStream(stream, addr_h, {length[31:4]+1,4'h0} );
            else
                ReadStream(stream, addr_h, length);
        end
        if ( bus_size == 128 ) begin
            if ( length[3:0] != 0 ) begin
                $display("Length Value is incorrect, halting simulation.");
                $stop;
            end
            PicoLoadBuffer128(8'h00,{64'h1,addr,length});
            WriteStream(stream, 8'h00, 32'h10);
			memory_buf[8'h00][127:0] = mem_data_hold[8'h00][127:0];
            ReadStream(stream, addr_h, length);
        end
        #100;
    end
    endtask
  
    task WriteSystemPicoBus;
        input [31:0]    addr;
        input [127:0]   data;
    begin
        PicoInternalBusWrite(126, 32, addr, data);
    end
    endtask
  
    task ReadSystemPicoBus;
        input [31:0]    addr;
        input [31:0]    length;
        input [11:0]    addr_h;
    begin
        PicoInternalBusRead(126, 32, addr, length, addr_h);
    end
    endtask
  
    task WritePicoBus;
        input [31:0]    addr;
        input [127:0]   data; 
    begin
        PicoInternalBusWrite(125, `ifdef PICOBUS_WIDTH `PICOBUS_WIDTH `else 128 `endif, addr, data);
    end
    endtask
  
  // read from the picobus at an automatically chosen addr
    task ReadPicoBus;
        input [31:0]    addr;
        input [31:0]    length;
    begin
        PicoInternalBusRead(125, `ifdef PICOBUS_WIDTH `PICOBUS_WIDTH `else 128 `endif, addr, length, 12'h0);
    end
    endtask
  
  // read from the picobus into a specified address
    task ReadPicoBusAddr;
        input [31:0]    addr;
        input [31:0]    length;
        input [11:0]    addr_h;
    begin
        PicoInternalBusRead(125, `ifdef PICOBUS_WIDTH `PICOBUS_WIDTH `else 128 `endif, addr, length, addr_h);
    end
    endtask

    task MemChecksum;
        input [7:0]     addr_l;
        input [7:0]     addr_h;
    begin
        membuf_checksum = 128'h0;
        addr_cnt = addr_l;
        @(posedge sys_clk);
        while (addr_cnt < addr_h+1) begin
            membuf_checksum = membuf_checksum ^ memory_buf[addr_cnt][127:0];
            addr_cnt = addr_cnt + 1;
            @(posedge sys_clk);
        end
        #100;
    end
    endtask


    task Software_Driven;             // This task gives the software the ability to control the simulation.
    begin
        $display("Waiting for Software Input");
        while (software_drive) begin
            if (software_go && !software_go_q) begin            // This only pulls a single command even if go is left high
                // cmd bits ( PicoRead | PicoWrite | StreamRead | StreamWrite )
                if (software_cmd[79:76] == 4'b1000 || software_cmd[79:76] == 4'b0100 || software_cmd[79:76] == 4'b0010 || software_cmd[79:76] == 4'b0001 || software_cmd[79:76] == 4'b1001 || software_cmd[79:76] == 4'b0101) begin
                    software_error = 0;
                    if (software_cmd[79] && software_cmd[76]) begin      // PicoSysRead
                        $display("Software: ReadPicoSysBus");
                        software_rdy = 0;
                        ReadSystemPicoBus(software_cmd[63:32], software_cmd[31:0], software_cmd[75:64]);
                        $display("Software: ReadPicoSysBus Done");
                    end else
                    if (software_cmd[78] && software_cmd[76]) begin      // PicoSysWrite
                        $display("Software: WritePicoSysBus");
                        software_rdy = 0;
                        WriteSystemPicoBus(software_cmd[63:32],128'h0);     // data doesn't matter as we don't set it if software is driving
                        $display("Software: WritePicoSysBus Done");
                    end else
                    if (software_cmd[79]) begin                          // PicoUserRead
                        $display("Software: ReadPicoBus");
                        software_rdy = 0;
                        ReadPicoBusAddr(software_cmd[63:32], software_cmd[31:0], software_cmd[75:64]);
                        $display("Software: ReadPicoBus Done");
                    end else
                    if (software_cmd[78]) begin                          // PicoUserWrite
                        $display("Software: WritePicoBus");
                        software_rdy = 0; 
                        WritePicoBus(software_cmd[63:32],software_data_0);     // data doesn't matter as we don't set it if     software is driving
                        $display("Software: WritePicoBus Done");
                    end else
                    if (software_cmd[77]) begin                          // StreamRead
                        $display("Software: StreamRead");
                        software_rdy = 0;
                        ReadStream(software_cmd[38:32],software_cmd[75:64],software_cmd[31:0]);
                        $display("Software: StreamRead Done");
                    end else
                    if (software_cmd[76]) begin                          // StreamWrite
                        $display("Software: StreamWrite");
                        software_rdy = 0;
                        WriteStream(software_cmd[38:32],software_cmd[75:64],software_cmd[31:0]);
                        $display("Software: StreamWrite Done");
                    end
                end 
                else begin
                $display ("Software: ERROR");
                software_error = 1;
                end
            end
            if (!software_go) begin
                software_rdy = 1;
            end
            #1;
        end
    end
    endtask
  
    always @(posedge sys_clk) begin
        software_go_q <= software_go;
    end

    always @(posedge software_go) begin
        memory_buf[0][127:0] <= software_data_0;
        memory_buf[1][127:0] <= software_data_1;
        memory_buf[2][127:0] <= software_data_2;
        memory_buf[3][127:0] <= software_data_3;
        memory_buf[4][127:0] <= software_data_4;
        memory_buf[5][127:0] <= software_data_5;
        memory_buf[6][127:0] <= software_data_6;
        memory_buf[7][127:0] <= software_data_7;
        memory_buf[8][127:0] <= software_data_8;
        memory_buf[9][127:0] <= software_data_9;
    end
      
      
    // TX load command state machine.
    always @(posedge sys_clk) begin
        if( cmd_buf[desc_cnt][127] && !CPLD_process) begin // this means there is a valid command in the buffer
            TX_lock         <= 1;
            comp_id         <= cmd_buf[desc_cnt][143:128];
            cmd_sof         <= cmd_buf[desc_cnt][112];
            cmd_align_sof   <= cmd_buf[desc_cnt][111];
            cmd_eof         <= cmd_buf[desc_cnt][113];
            cmd_bar_hit     <= cmd_buf[desc_cnt][121:114];
            wr_data[127:0]  <= {20'b0,cmd_buf[desc_cnt][110:0]}; // upper 20 bits used for cmd stuff in buffer so not sent
            wr_type[2:0]    <= cmd_buf[desc_cnt][110:108];
            wr_valid        <= #1 1'b1;
            if (wr_en) begin
                #1;
                TX_lock         <= 0;
                cmd_sof         <= 1'bX;
                cmd_align_sof   <= 1'bX;
                cmd_eof         <= 1'bX;
                wr_valid        <= 0;
                wr_type[2:0]    <= 3'bXXX;
                wr_data[127:0]  <= 128'hX;
                cmd_buf[desc_cnt][143:0] <= 144'hX;
                desc_cnt        <= desc_cnt+1; // dealt with current command
            end
        end
    end

    always @(posedge host_sof) header_lock = host_hdr;
    always @(posedge s_axis_tx_tvalid) begin  // locking feature for data processing
        cpld_hit = s_axis_tx_tdata[30:24];
    end
    assign cpl_addr = (cpld_hit_q == MEM_RD32_FMT_TYPE && host_hdr[93:92] == 1 )? {host_hdr[94:84]/*,host_hdr[77:68]*/}   : // upper 2 bits used to select buffer
                      (cpld_hit_q == MEM_RD32_FMT_TYPE && host_hdr[93:92] == 2 )? {host_hdr[93:92],host_hdr[75:68]}       : // upper 2 bits used to select buffer
                      10'hX;                  

    always @(posedge sys_clk) begin
        buf_sel <= #1 tag_table[tag_cnt[7:0]][9:8];
        host_data_q <= host_data;  // needed for the data grab.
        if (data_cnt == 0) data_addr = 12'h0;
        if ( host_sof && ((cpld_hit_q == MEM_WR64_FMT_TYPE) || (cpld_hit_q == MEM_WR32_FMT_TYPE)) && ( {header_lock[95:66], 2'b00} != 32'hff34_5000 ) ) begin // Data coming back to the card
            if (data_cnt == 0) begin // First packet address
                data_addr <= host_hdr[75:64]; // Bottom two bits are zero so we shift down for vector addressing
                data_cnt  <= host_hdr[7:0];
                checktest <= header_lock[95:88];
                full_addr = {header_lock[87:64],header_lock[127:96]};
                /*if (header_lock[95:88] != 8'h20)   begin
                    full_addr = {header_lock[87:64],header_lock[127:96]};
                end else 
                    full_addr = 0;*/
            end
        end
        if (data_cnt != 0) begin// Full data packets
            memory_buf[data_addr[11:4]][127:0] = {
                                    swap32(host_data[127:96]),
                                    swap32(host_data[95:64]),
                                    swap32(host_data[63:32]),
                                    swap32(host_data[31:0])};
            if(read32lock == 4) begin
                $display ("%0t: Host received 32b \n\t[Addr : %h] \t0x%h", $time,data_addr,memory_buf[data_addr[11:4]][31:0]);
                read32lock = 0;
            end else 
            if(read32lock == 8) begin
                $display ("%0t: Host received 32b \n\t[Addr : %h] \t0x%h\n\t \t0x%h\n\t", $time,data_addr,memory_buf[data_addr[11:4]][31:0],memory_buf[data_addr[11:4]][63:32]);
                read32lock = 0;
            end else 
            if(read32lock == 12) begin
                $display ("%0t: Host received 32b \n\t[Addr : %h] \t0x%h\n\t \t0x%h\n\t \t0x%h\n\t", $time,data_addr,memory_buf[data_addr[11:4]][31:0],memory_buf[data_addr[11:4]][63:32],memory_buf[data_addr[11:4]][95:64]);
                read32lock = 0;
            end else 
            if(read32lock >= 16) begin
                $display ("%0t: Host received 32b \n\t[Addr : %h] \t0x%h\n\t \t0x%h\n\t \t0x%h\n\t \t0x%h\n\t", $time,data_addr,memory_buf[data_addr[11:4]][31:0],memory_buf[data_addr[11:4]][63:32],memory_buf[data_addr[11:4]][95:64],memory_buf[data_addr[11:4]][127:96]);
                read32lock = read32lock - 16;
            end else 
            begin
                $display ("%0t: Host received 128b \n\t[Addr : %h] 0x%h_%h_%h_%h", $time,data_addr,
                        memory_buf[data_addr[11:4]][127:96],
                        memory_buf[data_addr[11:4]][95:64],
                        memory_buf[data_addr[11:4]][63:32],
                        memory_buf[data_addr[11:4]][31:0]);
            end
            data_cnt <= data_cnt - 4;
            if (data_cnt < 4 ) data_cnt <= 0;  // this takes priority over the line above
            data_addr <= data_addr + 8'h10;
        end 
        // Store read data in memory buffer
        stream_valid_q <= host_stream_valid;
        if ( host_stream_valid ) begin
            stream_data_hold[127:0] <= host_stream_data[127:0];
            stream_addr[47:0] <= {4'b0,tag_table[host_stream_tag][47:4]};
        end
        if ( stream_valid_q ) begin
            memory_buf[stream_addr][127:0] <= stream_data_hold[127:0];
        end
    end 


    // CPLD machine - Drives host TX to send data to the card's RX
    always @(posedge sys_clk) begin     // in own loop to make sure stuff gets hit right.
        cpld_hit_q <= cpld_hit;
        if ( host_sof && ((cpld_hit_q == MEM_RD64_FMT_TYPE) || (cpld_hit_q == MEM_RD32_FMT_TYPE)) ) begin // Grab Tag address, and shove into tag table.  Need to add so only happens for CPLDs
            if ( host_hdr[47:40] != tag[7:0] || tag[8] ) begin
                tag <= {1'b0,host_hdr[47:40]};
                tag_table[tag_store][48:0] <= {host_hdr[47:40],5'h0,host_hdr[63:48],host_hdr[9:2],1'b1,cpl_addr[9:0]};
                tag_store <= #1 tag_store + 1;
            end
        end
    end
    reg [7:0] sent_tag;
    always @(posedge sys_clk) begin
        if ( tag_table[tag_cnt][10] && !CPLD_process && ( !TX_lock | (cmd_buf[desc_cnt][127] == 1'b1) )) begin
            #2;
            CPLD_process = 1;  // Locks the TX command structure in the CPLD response
            CPLD_tag <= tag_cnt;
            CPLD_length <= {tag_table[tag_cnt[7:0]][18:11],2'b0};
            wr_type = 2'b11;
            wr_valid = 1;
            // first packet
            sent_tag = tag_table[tag_cnt[7:0]][47:40];
            wr_data = {32'hX,
                    (buf_sel[0] ? desc_buf[tag_table[tag_cnt][7:0]][31:0] :     // First 32 bits of data in header
                    memory_buf[tag_table[tag_cnt][7:0]][31:0]),      
                    16'hcafe,//tag_table[tag_cnt[7:0]][34:19],        // Card Requester ID
                    16'h0,                  // Completer ID,unneeded?
                    14'b0,                  // Unused wr_data bits
                    tag_table[tag_cnt[7:0]][47:40],                // Tag
                    tag_table[tag_cnt[7:0]][18:11],2'b0};    // length of reqest
            CPLD_addr[9:0] <= tag_table[tag_cnt][9:0];
            cmd_sof <= 1;
            cmd_eof <= 0;
            cmd_align_sof <= 0;
            tag_table[tag_cnt][10] <= 0;
            tag_cnt <= #1 tag_cnt + 1;
        end else
        if ( CPLD_length == 0 && CPLD_process) begin
            if (verbose) $display ("CPLD data: %h" , wr_data);
            wr_type = 2'bXX;
            wr_valid = 0;
            CPLD_process = 0;
            cmd_eof <= 0;
            wr_data <= 128'hX;
        end
       
        if ( CPLD_process && CPLD_length != 0 ) begin
            if (verbose) $display ("CPLD addr: %h", CPLD_addr);
            if (verbose) $display ("CPLD data: %h" , wr_data);
            cmd_sof <= 0;
            if (CPLD_length == 4) cmd_eof <= 1;
            wr_data[95:0]   =   CPLD_addr[8] ? desc_buf[CPLD_addr[7:0]][127:32] :     
                                memory_buf[CPLD_addr[7:0]][127:32];
            wr_data[127:96] =   CPLD_addr[8] ? 32'h0 :     
                                memory_buf[CPLD_addr[7:0]+1][31:0];
            CPLD_addr   =   CPLD_addr + 1;
            CPLD_length =   CPLD_length - 4;
            writecount = writecount - 16;
            if (writecount == 0) begin 
                writedone = 1;
            end
        end
    end

    // RX seq reporting catch
    always @(posedge sys_clk) begin
        if (host_wr_en && host_wr_addr[63:0] == 64'h0000_0000_ff34_5000) begin
            // store the last seq response so we can test against it in the Read and Write stream commands.
            last_seq <= host_wr_data[31:0];
        end
    end

endmodule 

module sof_catch (
    input           clk,
    input  [127:0]  m_axis_rx_tdata,
    input           m_axis_rx_tlast,
    input           m_axis_rx_tvalid,
    output          m_axis_rx_sof       // can't have a cycle delay here
);
    reg tvalid_q, tlast_q;
    assign m_axis_rx_sof = ( (m_axis_rx_tvalid && !tvalid_q) || ( m_axis_rx_tvalid && tlast_q) ) ? 1'b1 : 1'b0;

    always @(posedge clk) begin
        tvalid_q <= #1 m_axis_rx_tvalid;
        tlast_q  <= #1 m_axis_rx_tlast;
    end
endmodule 
