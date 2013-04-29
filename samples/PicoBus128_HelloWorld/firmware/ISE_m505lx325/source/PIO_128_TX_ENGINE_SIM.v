//-----------------------------------------------------------------------------
//
// (c) Copyright 2009-2010 Xilinx, Inc. All rights reserved.
//

// Modifications Copyright 2011 Pico Computing, Inc.

//TODO make the max size packet size configurable, rather than fixed at 128.
//  since maxreadrequest is often 512, that would allow us to send just 1/4 the number of packets for the same read.
//TODO we should be able to assert the 'streaming' line, reducing latency a little bit. test it sometime.

`timescale 1ns/1ns




module PIO_128_TX_ENGINE_SIM    #(
  // RX/TX interface data width
  parameter C_DATA_WIDTH = 128,
  parameter TCQ = 1,

  // TSTRB width
  parameter STRB_WIDTH = C_DATA_WIDTH / 8
)(

  input               clk,
  input               rst_n,

  // AXIS
  input                           s_axis_tx_tready,
  output  reg [C_DATA_WIDTH-1:0]  s_axis_tx_tdata,
  output  reg [STRB_WIDTH-1:0]    s_axis_tx_tstrb,
  output  reg                     s_axis_tx_tlast,
  output  reg                     s_axis_tx_tvalid,
  output  reg [21:0]			  s_axis_tx_tuser,
  output                          tx_src_dsc,
  
  input [127:0]     wr_data,  // ????
  input             wr_valid,
  input	[3:0]		wr_type,  // Bit signature for the command type.  [0] = read | [1] = write | [2] = memory data
  output reg        wr_en,
  
  //input [127:0]     iwr_q_data,  // command read
  //input             iwr_q_valid,
  //output reg        iwr_q_en,
  
  //input [127:0]     iwr_wr_q_data,	// command write
  //input             iwr_wr_q_valid,
  //output reg        iwr_wr_q_en,
  
  //input [127:0]     wr_data_q_data,  // memory write data
  //input             wr_data_q_valid,
  //output            wr_data_q_en,
  
  input             tx_rd_req_ok,
  
  output reg [7:0]  last_cpld_tag,

  input               req_compl_i,
  input               req_compl_wd_i,
  output  reg         compl_done_o,

  input [2:0]         req_tc_i,
  input               req_td_i,
  input               req_ep_i,
  input [1:0]         req_attr_i,
  input [9:0]         req_len_i,
  input [15:0]        req_rid_i,
  input [7:0]         req_tag_i,
  input [7:0]         req_be_i,
  input [63:0]        req_addr_i,

  output [63:0]       rd_addr_o,
  output [3:0]        rd_be_o,
  input  [31:0]       rd_data_i,

  input [15:0]        completer_id_i,
  input               cfg_bus_mstr_enable_i,
  
  // command tuser inputs
  input [7:0] 	cmd_bar_hit,	// user bits [9:2]
  input			cmd_sof,		// user bit 14
  input			cmd_eof, 		// user bit 21
  input			cmd_align_sof	// user bit 13
);

`define DESC_FETCH_TAG  8'h1f

localparam TX_CMD_RD    = 2'b00;


localparam MEM_RD32_FMT_TYPE    = 7'b00_00000;
localparam MEM_RD64_FMT_TYPE    = 7'b01_00000;
localparam MEM_WR32_FMT_TYPE    = 7'b10_00000;
localparam MEM_WR64_FMT_TYPE    = 7'b11_00000;
localparam CPLD_FMT_TYPE        = 7'b10_01010;
localparam CPL_FMT_TYPE         = 7'b00_01010;

localparam STATE_RST        = 8'b00000001;
localparam STATE_BS         = 8'b00000010;
localparam STATE_CMD        = 8'b00000100;
localparam STATE_MEM_WR64   = 8'b00001000;
localparam STATE_MEM_W_DATA = 8'b00010000;



// This is a simulation only module and should not be used for anything but that.
function [127:0] swap128;
   input [127:0] in;
  begin
  swap128 = {
     in[39:32],
     in[47:40],
     in[55:48],
     in[63:56],
     in[7:0],
     in[15:8],
     in[23:16],
     in[31:24],
     in[103:96],
     in[111:104],
     in[119:112],
     in[127:120],
     in[71:64],
     in[79:72],
     in[87:80],
     in[95:88]}; 
  end
endfunction

    // Local registers
    reg [7:0]           state;

    reg [11:0]          byte_count;
    reg [06:0]          lower_addr;

    reg                 req_compl_q;
    reg                 req_compl_q2;
    reg                 req_compl_wd_q;
    reg                 req_compl_wd_q2;

    reg                 hold_cpl;
    reg [7:0]           next_rd_tag; // the next header tag we'll use for a read request.
    
    // cmd pipeline's constituents
    reg [127:0]         cmd;
    reg [47:0]          cmd_addr;
    reg [1:0]           cmd_type;
    reg [19:0]          cmd_size;
    reg                 cmd_read;
    reg                 cmd_read_desc;
    reg [9:0]           cmd_stream_num;
    
    reg                 iwr_q_en_q;
    
    reg                 writing;
    reg [127:0]         wr_data_q;
    
    wire [11:0]         read_burst_size = (|cmd_size[9:0]) ? {5'h0, cmd_size[6:0]} : 12'h80;

    // Local wires
    wire [31:0]     rd_data_sw = {rd_data_i[7:0], rd_data_i[15:8], rd_data_i[23:16], rd_data_i[31:24]};
    
    // Unused discontinue
    assign tx_src_dsc = 1'b0;

    /*
     * Present address and byte enable to memory module
     */

    assign rd_addr_o = req_addr_i;
    assign rd_be_o =   req_be_i[3:0];

    /*
     * Calculate byte count based on byte enable
     */

    always @ (rd_be_o) begin

      casex (rd_be_o[3:0])

        4'b1xx1 : byte_count = 12'h004;
        4'b01x1 : byte_count = 12'h003;
        4'b1x10 : byte_count = 12'h003;
        4'b0011 : byte_count = 12'h002;
        4'b0110 : byte_count = 12'h002;
        4'b1100 : byte_count = 12'h002;
        4'b0001 : byte_count = 12'h001;
        4'b0010 : byte_count = 12'h001;
        4'b0100 : byte_count = 12'h001;
        4'b1000 : byte_count = 12'h001;
        4'b0000 : byte_count = 12'h001;

      endcase

    end

    /*
     * Calculate lower address based on  byte enable
     */

    always @ (rd_be_o or req_addr_i) begin

      casex ({req_compl_wd_q2, rd_be_o[3:0]})

        5'b0_xxxx : lower_addr = 8'h0;
        5'bx_0000 : lower_addr = {req_addr_i[6:2], 2'b00};
        5'bx_xxx1 : lower_addr = {req_addr_i[6:2], 2'b00};
        5'bx_xx10 : lower_addr = {req_addr_i[6:2], 2'b01};
        5'bx_x100 : lower_addr = {req_addr_i[6:2], 2'b10};
        5'bx_1000 : lower_addr = {req_addr_i[6:2], 2'b11};

      endcase

    end

    always @ ( posedge clk ) begin

        if (!rst_n ) begin
		  s_axis_tx_tuser <= #TCQ 0;
          req_compl_q     <= #TCQ 1'b0;
          req_compl_q2    <= #TCQ 1'b0;
          req_compl_wd_q  <= #TCQ 1'b0;
          req_compl_wd_q2 <= #TCQ 1'b0;

        end else begin
          s_axis_tx_tuser <= #TCQ {cmd_eof,6'b0,cmd_sof,cmd_align_sof,3'b0,cmd_bar_hit[7:0],2'b0};
          req_compl_q     <= #TCQ req_compl_i;
          req_compl_q2    <= #TCQ req_compl_q;
          req_compl_wd_q  <= #TCQ req_compl_wd_i;
          req_compl_wd_q2 <= #TCQ req_compl_wd_q;


        end

    end

    /*
     *  Generate Completion with 1 DW Payload
     */
reg [(8*16)-1:0] state_ascii;

always @(posedge clk)
	case(state)
		STATE_RST: 			state_ascii <= "STATE_RST";
		STATE_BS:  			state_ascii <= "STATE_BS";      
		STATE_CMD: 			state_ascii <= "STATE_CMD";      
		STATE_MEM_WR64:  	state_ascii <= "STATE_MEM_WR64";
		STATE_MEM_W_DATA:	state_ascii <= "STATE_MEM_W_DATA";
	endcase

   reg [3:0] CPLD_state;
   reg [9:0] CPLD_size;

   
    always @ ( posedge clk ) begin
		
		if (wr_type[1])
			wr_en <= s_axis_tx_tready && writing && ~((state == STATE_MEM_W_DATA) && (cmd_size[6:0] == 7'h10));
        if (!rst_n ) begin
            state           <= STATE_RST;

            s_axis_tx_tlast   <= #TCQ 1'b0;
            s_axis_tx_tvalid  <= #TCQ 1'b0;
            s_axis_tx_tdata   <= #TCQ {C_DATA_WIDTH{1'b0}};
            s_axis_tx_tstrb   <= #TCQ {STRB_WIDTH{1'b1}};

            compl_done_o      <= #TCQ 1'b0;
            hold_cpl        <= #TCQ 1'b0;
            
            wr_en            <= #TCQ 0;
            next_rd_tag         <= #TCQ 8'h1;
            last_cpld_tag       <= #TCQ 8'h0;
            CPLD_state          <= #TCQ 4'b1;
            CPLD_size           <= #TCQ 20'hX;
            writing             <= #TCQ 0;

        end else begin
            if (req_compl_q2)
                hold_cpl <= 1;
            
            wr_en     <= #TCQ 0;
            //wr_data_q_en    <= #TCQ 0;
            
            //iwr_q_en_q      <= #TCQ iwr_q_en;
            
            compl_done_o    <= #TCQ 0;
            
            if (wr_en & wr_type[2])
                wr_data_q    <= #TCQ wr_data;
            
            case (state)
                STATE_RST : begin
                    // completion request pending
                    // TODO we should put these into the pipeline we use for all other writes
                    if ( CPLD_state[1] == 1 && CPLD_size == 0 ) begin
                          // $display("%0t: CPLD clear", $time);
                          `ifdef FULL_DEBUG $display("Host CPLD : %h", s_axis_tx_tdata); `endif
                           CPLD_state <= 4'h1;
                           s_axis_tx_tvalid <= 1'b0;
                           s_axis_tx_tlast <= 1'b0;
                    end
                    if ( wr_type == 2'b11 && wr_valid) begin // Driven CPLD state off RX capture
                        if ( CPLD_state[0] == 1 ) begin  // Initial CPLD response
                          `ifdef FULL_DEBUG $display("Host CPLD : %h", s_axis_tx_tdata); `endif
                          // $display("%0t: CPLD state 0", $time);
                           s_axis_tx_tvalid  <= #TCQ  1'b1;
                           s_axis_tx_tdata   <= #TCQ  {                   // Bits
                                            wr_data[71:64],
                                            wr_data[79:72],
                                            wr_data[87:80],
                                            wr_data[95:88],
                                            //wr_data[95:64],               // 32
                                            // [95:64]
                                            wr_data[63:48],                // 16 request id
                                            wr_data[17:10],                //  8 Tag
                                            {1'b0},                   //  1
                                            7'hX,               //  7 lower Addres
                                            // [63:32]
                                            completer_id_i,           // 16
                                            {3'b0},                   //  3 compl status (0 == success)
                                            {1'b0},                   //  1 byte count modified? (BCM)
                                            wr_data[9:0],2'b0,        // 12 BYTE COUNT
                                            // [31:0]
                                            {1'b0},                   //  1
                                            (req_compl_wd_q2 ?
                                            CPLD_FMT_TYPE :
                                            CPL_FMT_TYPE),            //  7 FMT & Type
                                            {1'b0},                   //  1
                                            3'b0,                 //  3 TC
                                            {4'b0},                   //  4
                                            1'b0,                 //  1 TD
                                            1'b0,                 //  1 EP
                                            2'b0,               //  2 Attr
                                            {2'b0},                   //  2
                                            wr_data[9:0]              // 10 Length
                                            };
                           CPLD_size <= {wr_data[11:2],2'b0}; // trim bottom which should be 0 anyways.  Throw error in sim bench
                           CPLD_state <= 4'b0010;
                        end else
                        if ( CPLD_state[1] == 1 && CPLD_size != 0 ) begin // DWs back to the card
                        //$display("CPLD tx_tdata : 0x%h_0x%h_0x%h_0x%h",s_axis_tx_tdata[127:96],s_axis_tx_tdata[95:64],s_axis_tx_tdata[63:32],s_axis_tx_tdata[31:0]);
                        //$display("%0t: CPLD state 1", $time);
                           `ifdef FULL_DEBUG $display("Host CPLD : %h", s_axis_tx_tdata); `endif
                              s_axis_tx_tdata   <= #TCQ {
                                            wr_data[103:96],
                                            wr_data[111:104],
                                            wr_data[119:112],
                                            wr_data[127:120],
                                            wr_data[71:64],
                                            wr_data[79:72],
                                            wr_data[87:80],
                                            wr_data[95:88],
                                            wr_data[39:32],
                                            wr_data[47:40],
                                            wr_data[55:48],
                                            wr_data[63:56],
                                            wr_data[07:00],
                                            wr_data[15:08],
                                            wr_data[23:16],
                                            wr_data[31:24]};
                           if(CPLD_size == 4) s_axis_tx_tlast <= 1'b1;
                           CPLD_size <= CPLD_size - 4;
                        end  
                    end else 
                    if ((req_compl_q2 | hold_cpl) && (s_axis_tx_tready || ~s_axis_tx_tvalid)) begin
                        s_axis_tx_tlast   <= #TCQ 1'b1;
                        s_axis_tx_tvalid  <= #TCQ 1'b1;
                        s_axis_tx_tdata   <= #TCQ {                   // Bits
                                            rd_data_sw,               // 32
                                            // [95:64]
                                            req_rid_i,                // 16
                                            req_tag_i,                //  8
                                            {1'b0},                   //  1
                                            lower_addr,               //  7
                                            // [63:32]
                                            completer_id_i,           // 16
                                            {3'b0},                   //  3 compl status (0 == success)
                                            {1'b0},                   //  1 byte count modified? (BCM)
                                            byte_count,               // 12
                                            // [31:0]
                                            {1'b0},                   //  1
                                            (req_compl_wd_q2 ?
                                            CPLD_FMT_TYPE :
                                            CPL_FMT_TYPE),            //  7
                                            {1'b0},                   //  1
                                            req_tc_i,                 //  3
                                            {4'b0},                   //  4
                                            req_td_i,                 //  1
                                            req_ep_i,                 //  1
                                            req_attr_i,               //  2
                                            {2'b0},                   //  2
                                            req_len_i                 // 10
                                            };
                           s_axis_tx_tuser[21] <= 1'b1;
                           s_axis_tx_tuser[14:13] <= 2'b11;

                        // Here we select if the packet has data or
                        // not.  The strobe signal will mask data
                        // when it is not needed.  No reason to change
                        // the data bus.
                        if (req_compl_wd_q2)
                          s_axis_tx_tstrb   <= #TCQ 16'hFFFF;
                        else
                          s_axis_tx_tstrb   <= #TCQ 16'h0FFF;

                        compl_done_o        <= #TCQ 1'b1;
                        hold_cpl            <= #TCQ 0;
                    
                    //TODO we wouldn't have to check ready/valid on moving to the CMD state if we were more selective with
                    //  clearing valid/ready and postponed the check till the CMD state.
                    end else 
                    if (wr_valid && (wr_type[1] || wr_type[2]) && (s_axis_tx_tready || ~s_axis_tx_tvalid)) begin
                        wr_en     		<= #TCQ 1;
						cmd             <= #TCQ wr_data;
                        cmd_addr        <= #TCQ wr_data[79:32];
                        cmd_type        <= #TCQ wr_data[107:106]; //wr_q_data[21:20];
                        cmd_size        <= #TCQ wr_data[19:0];
                        cmd_read        <= #TCQ wr_data[107];
                        cmd_read_desc   <= #TCQ wr_data[106];
                        cmd_stream_num  <= #TCQ wr_data[105:96];
                        s_axis_tx_tlast <= #TCQ 1'b0;
                        s_axis_tx_tvalid<= #TCQ 1'b0;
                        writing         <= #TCQ 1;
                        state           <= STATE_CMD;
                    // the iwr_q fifo seems to be taking an extra cycle to assert empty. pos. replace it with literal fifo block.
                    end else if (wr_valid && wr_type[0] && (s_axis_tx_tready || ~s_axis_tx_tvalid)) begin
                        wr_en        	<= #TCQ 1;
                        cmd             <= #TCQ wr_data;
                        cmd_addr        <= #TCQ wr_data[79:32];
                        cmd_type        <= #TCQ wr_data[107:106]; //wr_q_data[21:20];
                        cmd_size        <= #TCQ wr_data[19:0];
                        cmd_read        <= #TCQ wr_data[107];
                        cmd_read_desc   <= #TCQ wr_data[106];
                        cmd_stream_num  <= #TCQ wr_data[105:96];
                        s_axis_tx_tlast <= #TCQ 1'b0;
                        s_axis_tx_tvalid<= #TCQ 1'b0;
                        state           <= STATE_CMD;
                    end else if (s_axis_tx_tready || ~s_axis_tx_tvalid) begin
                        // this is excessive. we really only need to clear tvalid, right?
                        s_axis_tx_tlast   <= #TCQ 1'b0;
                        s_axis_tx_tvalid  <= #TCQ 1'b0;
                        s_axis_tx_tdata   <= #TCQ {C_DATA_WIDTH{1'b0}};
                        s_axis_tx_tstrb   <= #TCQ {STRB_WIDTH{1'b1}};
                    end
                end //STATE_RST
                
                STATE_CMD : begin
                    wr_en    <= #TCQ 0;
                    if (cmd_type == 2'b10 && s_axis_tx_tready && tx_rd_req_ok) begin   // Read
                        last_cpld_tag       <= #TCQ next_rd_tag;
                        next_rd_tag[7:0]    <= #TCQ next_rd_tag[7:0] + 1; // the top 3 tag bits aren't used unless we enable the Extended Tag feature.
                        s_axis_tx_tlast     <= #TCQ 1'b1;
                        s_axis_tx_tvalid    <= #TCQ 1'b1;
                        cmd_addr            <= #TCQ cmd_addr + read_burst_size;
                        cmd_size            <= #TCQ cmd_size - read_burst_size;
                        //$display("read_burst_size: 0x%x", read_burst_size);
                        if (|cmd_addr[47:32]) begin
                            //$display("%0t: TX MEM_RD64. addr:0x%x, len:0x%xB, tag:0x%x", $time, cmd_addr[47:0], read_burst_size, next_rd_tag);
                            s_axis_tx_tstrb     <= #TCQ 16'hFFFF;        // tdata byte enables. 0xFFFF for a 4DWORD packet
                            s_axis_tx_tdata     <= #TCQ {
                                                                                // <bit width> <description>
                                                // [127:64]
                                                cmd_addr[31:2],                 // 30 addr[31:2]
                                                2'b0,                           //  2 reserved (addr[1:0])
                                                16'h0, cmd_addr[47:32],         // 32 upper addr or first DWORD of data.
                                                // [63:32]
                                                completer_id_i,                 // 16 our id (actually called requester id in this context)
                                                next_rd_tag,                    //  8 tag XXX:increment this for multi-packet mrds
                                                4'hF,                           //  4 last DWORD byte enables XXX:must be zero if count==1
                                                4'hF,                           //  4 first DWORD byte enables
                                                // [31:0]
                                                1'b0,                           //  1 reserved
                                                MEM_RD64_FMT_TYPE,              //  7 type and 32/64b flag
                                                1'b0,                           //  1 reserved
                                                3'b0, /*XXX*/                   //  3 traffic class (TC)
                                                4'b0,                           //  4 reserved
                                                1'b0,                           //  1 TLP digest present (TD)
                                                1'b0,                           //  1 poisoned (EP)
                                                2'b0, /*XXX*/                   //  2 relaxed order, no snoop bits
                                                2'b0,                           //  2 reserved
                                                (|cmd_size[9:0]) ? cmd_size[9:0] : 10'h20//cmd_size[11:2]                  // 10 length in DWORDs
                                                };
                        end else begin
                            //$display("%0t: TX MEM_RD32. addr:0x%x, len:0x%xB, tag:0x%x", $time, cmd_addr[47:0], cmd_size[11:2]*4, next_rd_tag);
                            s_axis_tx_tstrb     <= #TCQ {4'h0, 12'hFFF};        // tdata byte enables. 0x0FFF for a 3DWORD packet
                            s_axis_tx_tdata     <= #TCQ {
                                                                                // <bit width> <description>
                                                // [127:64]
                                                32'h0,                          // 32 upper addr or first DWORD of data.
                                                cmd_addr[31:2],                 // 30 addr[31:2]
                                                2'b0,                           //  2 reserved (addr[1:0])
                                                // [63:32]
                                                completer_id_i,                 // 16 our id (actually called requester id in this context)
                                                next_rd_tag,                    //  8 tag XXX:increment this for multi-packet mrds
                                                4'hF,                           //  4 last DWORD byte enables XXX:must be zero if count==1
                                                4'hF,                           //  4 first DWORD byte enables
                                                // [31:0]
                                                1'b0,                           //  1 reserved
                                                MEM_RD32_FMT_TYPE,              //  7 type and 32/64b flag
                                                1'b0,                           //  1 reserved
                                                3'b0, /*XXX*/                   //  3 traffic class (TC)
                                                4'b0,                           //  4 reserved
                                                1'b0,                           //  1 TLP digest present (TD)
                                                1'b0,                           //  1 poisoned (EP)
                                                2'b0, /*XXX*/                   //  2 relaxed order, no snoop bits
                                                2'b0,                           //  2 reserved
                                                (|cmd_size[9:0]) ? cmd_size[9:0] : 10'h20//cmd_size[11:2]  
                                                };
                        end
                        // note that we aren't waiting for the tready ack. we're counting on STATE_RST to handle that.
                        if (cmd_addr[31:16] == 16'hcafe) //XXX see note for STATE_BS
                            state   <= STATE_BS;
                        else if (cmd_size[19:0] == {8'h0, read_burst_size})
                            state   <= STATE_RST;
                        // otherwise, stay in this state, we need to send more packets to finish this request.
                    end else 
                    if (cmd_type == 2'b00 /*&& s_axis_tx_tready*/) begin               // Write
                        s_axis_tx_tvalid    <= #TCQ 1'b1;
                        if (|cmd_addr[47:32]) begin
                            ////$display("%0t: TX MEM_WR64 for seq_rpt. addr:0x%x, data:0x%x", $time, cmd_addr[47:0], cmd[31:0]);
                            s_axis_tx_tlast     <= #TCQ 1'b0;
                            s_axis_tx_tstrb     <= #TCQ 16'hFFFF;        // tdata byte enables. 0xFFFF for a 4DWORD packet
                            s_axis_tx_tdata     <= #TCQ {
                                                                                // <bit width> <description>
                                                // [127:96]
                                                cmd_addr[31:2],                 // 30 addr[31:2]
                                                2'b0,                           //  2 reserved (addr[1:0])
                                                16'h0, cmd_addr[47:32],         // 32 upper addr or first DWORD of data. XXX
                                                // [63:32]
                                                completer_id_i,                 // 16 our id (actually called requester id in this context)
                                                8'h1,                           //  8 tag
                                                4'h0,                           //  4 last DWORD byte enables. must be zero if count==1
                                                4'hF,                           //  4 first DWORD byte enables
                                                // [31:0]
                                                1'b0,                           //  1 reserved
                                                MEM_WR64_FMT_TYPE,              //  7 type and 32/64b flag
                                                1'b0,                           //  1 reserved
                                                3'b0, /*XXX*/                   //  3 traffic class (TC)
                                                4'b0,                           //  4 reserved
                                                1'b0,                           //  1 TLP digest present (TD)
                                                1'b0,                           //  1 poisoned (EP)
                                                2'b0, /*XXX*/                   //  2 relaxed order, no snoop bits
                                                2'b0,                           //  2 reserved
                                                10'h1                           // 10 length in DWORDs
                                                };
                            state   <=  STATE_MEM_WR64;
                        end else begin
                            ////$display("%0t: TX MEM_WR32 for seq_rpt. addr:0x%x, data:0x%x", $time, cmd_addr[47:0], cmd[31:0]);
                            s_axis_tx_tlast     <= #TCQ 1'b1;
                            s_axis_tx_tstrb     <= #TCQ 16'hFFFF;                // tdata byte enables
                            s_axis_tx_tdata     <= #TCQ {
                                                                                // <bit width> <description>
                                                // [127:96]
                                                cmd[7:0], cmd[15:8], cmd[23:16], cmd[31:24],    // 32 first DWORD of data.
                                                cmd_addr[31:2],                 // 30 addr[31:2]
                                                2'b0,                           //  2 reserved (addr[1:0])
                                                // [63:32]
                                                completer_id_i,                 // 16 our id (actually called requester id in this context)
                                                8'h1,                           //  8 tag
                                                4'h0,                           //  4 last DWORD byte enables. must be zero if count==1
                                                4'hF,                           //  4 first DWORD byte enables
                                                // [31:0]
                                                1'b0,                           //  1 reserved
                                                MEM_WR32_FMT_TYPE,              //  7 type and 32/64b flag
                                                1'b0,                           //  1 reserved
                                                3'b0, /*XXX*/                   //  3 traffic class (TC)
                                                4'b0,                           //  4 reserved
                                                1'b0,                           //  1 TLP digest present (TD)
                                                1'b0,                           //  1 poisoned (EP)
                                                2'b0, /*XXX*/                   //  2 relaxed order, no snoop bits
                                                2'b0,                           //  2 reserved
                                                10'h1                           // 10 length in DWORDs
                                                };
                            state   <= STATE_RST;
                        end
                    end else 
                    if (cmd_type == 2'b01 && s_axis_tx_tready) begin
                        s_axis_tx_tvalid    <= #TCQ 1'b1;
                        if (|cmd_addr[47:32]) begin
                            //$display("%0t: TX MEM_WR64. addr:0x%x, size(DW):0x%x", $time, cmd_addr[47:0],
//                                    (|cmd_size[9:0]) ? cmd_size[9:0] : 10'h20);
                            s_axis_tx_tlast     <= #TCQ 1'b0;
                            s_axis_tx_tstrb     <= #TCQ 16'hFFFF;        // tdata byte enables. 0xFFFF for a 4DWORD packet
                            s_axis_tx_tdata     <= #TCQ {
                                                                                // <bit width> <description>
                                                // [127:96]
                                                cmd_addr[31:2],                 // 30 addr[31:2]
                                                2'b0,                           //  2 reserved (addr[1:0])
                                                16'h0, cmd_addr[47:32],         // 32 upper addr or first DWORD of data. XXX
                                                // [63:32]
                                                completer_id_i,                 // 16 our id (actually called requester id in this context)
                                                8'h1,                           //  8 tag
                                                4'hF,                           //  4 last DWORD byte enables. must be zero if count==1
                                                4'hF,                           //  4 first DWORD byte enables
                                                // [31:0]
                                                1'b0,                           //  1 reserved
                                                MEM_WR64_FMT_TYPE,              //  7 type and 32/64b flag
                                                1'b0,                           //  1 reserved
                                                3'b0, /*XXX*/                   //  3 traffic class (TC)
                                                4'b0,                           //  4 reserved
                                                1'b0,                           //  1 TLP digest present (TD)
                                                1'b0,                           //  1 poisoned (EP)
                                                2'b0, /*XXX*/                   //  2 relaxed order, no snoop bits
                                                2'b0,                           //  2 reserved
                                                (|cmd_size[9:0]) ? {5'h0, cmd_size[6:0]} : 10'h20/*10'h4*/                           // 10 length in DWORDs
                                                };
                            state   <=  STATE_MEM_W_DATA;
                        end else begin
                            //$display("%0t: TX MEM_WR32. addr:0x%x, data:0x%x",
//                                    $time, cmd_addr[47:0], wr_data[31:0]);
                            s_axis_tx_tlast     <= #TCQ 1'b0;
                            s_axis_tx_tstrb     <= #TCQ 16'hFFFF;                // tdata byte enables
                            s_axis_tx_tdata     <= #TCQ {
                                                                                // <bit width> <description>
                                                // [127:96]
                                                wr_data[7:0],
                                                wr_data[15:8],
                                                wr_data[23:16],
                                                wr_data[31:24],          // 32 first DWORD of data.
                                                cmd_addr[31:2],                 // 30 addr[31:2]
                                                2'b0,                           //  2 reserved (addr[1:0])
                                                // [63:32]
                                                completer_id_i,                 // 16 our id (actually called requester id in this context)
                                                8'h1,                           //  8 tag
                                                4'hF,                           //  4 last DWORD byte enables. must be zero if count==1
                                                4'hF,                           //  4 first DWORD byte enables
                                                // [31:0]
                                                1'b0,                           //  1 reserved
                                                MEM_WR32_FMT_TYPE,              //  7 type and 32/64b flag
                                                1'b0,                           //  1 reserved
                                                3'b0, /*XXX*/                   //  3 traffic class (TC)
                                                4'b0,                           //  4 reserved
                                                1'b0,                           //  1 TLP digest present (TD)
                                                1'b0,                           //  1 poisoned (EP)
                                                2'b0, /*XXX*/                   //  2 relaxed order, no snoop bits
                                                2'b0,                           //  2 reserved
                                                (|cmd_size[9:0]) ? cmd_size[9:0] : 10'h20/*10'h4*/                           // 10 length in DWORDs
                                                };
                            state   <= STATE_MEM_W_DATA;
                        end
                    end else 
                    if (s_axis_tx_tready && s_axis_tx_tvalid) begin
                        // this is state is used when, for example, we're in the middle of sending a string of read requests
                        //   and our "max outstanding requests" machinery tells us to stop. we're essentially freezing here
                        //   until we're allowed to go again. but we can't assert valid while we're waiting.
                        //TODO this could stall us for as much as 1us!!! rewrite the state machine to be able to
                        //  carry on with other traffic while we're waiting for permission to send more read requests.
                        s_axis_tx_tvalid    <= #TCQ 0; //TODO this is pretty clumsy
                    end
                end
                
                STATE_MEM_WR64 : begin
                    //TODO do we really need to check tx_ready? I don't think axi will deassert it in the middle of this packet
                    //  update 20110404: it won't deassert in the middle, if we just sent out the first cycle, tready may not
                    //    have been asserted yet. wait on tready till we're really in the middle of the packet.
                    if (s_axis_tx_tready) begin
                        s_axis_tx_tvalid    <= #TCQ 1'b1;
                        s_axis_tx_tlast     <= #TCQ 1'b1;
                        s_axis_tx_tstrb     <= #TCQ {12'h0, 4'hF};
                        s_axis_tx_tdata     <= #TCQ {96'h0, cmd[7:0], cmd[15:8], cmd[23:16], cmd[31:24]};
                        state               <= STATE_RST;
                    end
                end
                
                STATE_MEM_W_DATA : begin
                    if (s_axis_tx_tready) begin
                        //s_axis_tx_tvalid    <= #TCQ 1'b1;
                        cmd_size    <= #TCQ cmd_size - 20'h10;
                        cmd_addr    <= #TCQ cmd_addr + 48'h10; //TODO do we really need to wrap over more than 12 bits?
                        // if we're on the border of a 128B packet, we're either done or starting a new packet.
                        if (cmd_size[6:0] == 7'h10) begin
                            s_axis_tx_tlast     <= #TCQ 1'b1;
                            //wr_data_q_en        <= #TCQ 0;
                            if (|cmd_size[19:7]) begin
                                state               <= STATE_CMD;
                            end else begin
                                writing             <= #TCQ 0;
                                state               <= STATE_RST;
                            end
                        end
                        if (|cmd_addr[47:32]) begin
                            //$display("%0t: TX MEM_WR64 data. size:0x%x, addr:0x%x, 0x%x_0x%x_0x%x_0x%x",
//                                    $time, cmd_size[19:0], cmd_addr[47:0],
//                                    wr_data_q[127:96], wr_data_q[95:64],
//                                    wr_data_q[63:32], wr_data_q[31:0]);
                            s_axis_tx_tstrb <= #TCQ 16'hFFFF;
                            s_axis_tx_tdata <= #TCQ {
                                            wr_data_q[7:0],
                                            wr_data_q[15:8],
                                            wr_data_q[23:16],
                                            wr_data_q[31:24],
                                            wr_data_q[39:32],
                                            wr_data_q[47:40],
                                            wr_data_q[55:48],
                                            wr_data_q[63:56],
                                            wr_data_q[71:64],
                                            wr_data_q[79:72],
                                            wr_data_q[87:80],
                                            wr_data_q[95:88],
                                            wr_data_q[103:96],
                                            wr_data_q[111:104],
                                            wr_data_q[119:112],
                                            wr_data_q[127:120]};
                        end else begin
                            //$display("%0t: TX MEM_WR32 data. size:0x%x, addr:0x%x, 0x%x_0x%x_0x%x_0x%x",
//                                    $time, cmd_size[19:0], cmd_addr[47:0],
//                                    wr_data_q[127:96], wr_data_q[95:64],
//                                    wr_data_q[63:32], wr_data[31:0]);
                            if (cmd_size[6:0] == 7'h10)
                                s_axis_tx_tstrb <= #TCQ {4'h0, 12'hFFF};
                            else
                                s_axis_tx_tstrb <= #TCQ 16'hFFFF;
                            s_axis_tx_tdata <= #TCQ {
                                            wr_data[7:0],
                                            wr_data[15:8],
                                            wr_data[23:16],
                                            wr_data[31:24],
                                            wr_data_q[39:32],
                                            wr_data_q[47:40],
                                            wr_data_q[55:48],
                                            wr_data_q[63:56],
                                            wr_data_q[71:64],
                                            wr_data_q[79:72],
                                            wr_data_q[87:80],
                                            wr_data_q[95:88],
                                            wr_data_q[103:96],
                                            wr_data_q[111:104],
                                            wr_data_q[119:112],
                                            wr_data_q[127:120]};
                        end
                    end // tready
                end
                
                // this state just sets stuff that might otherwise be optimized out, so we can chipscope it.
                STATE_BS : begin
                    s_axis_tx_tlast <= 0;
                    if (s_axis_tx_tlast)
                        s_axis_tx_tdata <= {128{1'b1}};
                    else begin
                        s_axis_tx_tdata <= {128{1'b0}};
                        state           <= STATE_RST;
                    end
                end
            endcase
        end
    end

endmodule // PIO_128_TX_ENGINE

