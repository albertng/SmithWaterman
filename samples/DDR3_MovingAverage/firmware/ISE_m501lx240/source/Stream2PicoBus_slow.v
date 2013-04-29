// Stream2PicoBus.v
// Copyright 2011 Pico Computing, Inc.

// This module implements a PicoBus on two streams:
//   an input stream that carries commands and write data, and
//   an output stream that carries read data.
// Command format:
//   [64]       read flag. 1=read, 0=write.
//   [63:32]    addr in bytes. for 128b PicoBus, bottom four bits are forced to zero.
//   [31:0]     size in bytes

// The read feature is only using 1/3 potential bus throughput, for want of a fifo. That's probably fine.

//TODO it would be really easy to add variable-latency reads. just add a PicoRdAck or PicoDataOutValid signal, and watch it
//  rather than PicoRd_q.

module Stream2PicoBus #(
    parameter           STREAM_ID=1,
    parameter           W=128
    ) (
    input               s_clk,
    input               s_rst,
    
    input               s_out_en,
    input       [8:0]   s_out_id,
    output      [127:0] s_out_data,
    
    input               s_in_valid,
    input [8:0]         s_in_id,
    input [127:0]       s_in_data,
    
    input       [8:0]   s_poll_id,
    output      [31:0]  s_poll_seq,
    output      [127:0] s_poll_next_desc,
    output              s_poll_next_desc_valid,
    
    input       [8:0]   s_next_desc_rd_id,
    input               s_next_desc_rd_en,
    
    output              PicoClk,
    output reg          PicoRst,
    output reg  [W-1:0] PicoDataIn,
    output reg          PicoWr,
    input       [W-1:0] PicoDataOut,
    output reg  [31:0]  PicoAddr,
    output reg          PicoRd
    );
    
    wire               i_valid;
    wire              i_rdy;
    wire [127:0]       i_data;
    wire              o_valid;
    wire               o_rdy;
    wire [127:0]      o_data;
    
    wire [31:0]     s126o_desc_poll_seq;
    wire            s126o_desc_poll_next_desc_valid;
    wire [127:0]    s126o_desc_poll_next_desc;
    wire [127:0]    s126o_data_fetch;
    
    PicoStreamOut #(
        .ID(STREAM_ID)
    ) s126o_stream (
        .clk(s_clk),
        .rst(s_rst),
        
        .s_rdy(o_rdy),
        .s_valid(o_valid),
        .s_data(o_data),
        
        .s_out_en(s_out_en),
        .s_out_id(s_out_id[8:0]),
        .s_out_data(s126o_data_fetch[127:0]),
        
        .s_in_valid(s_in_valid),
        .s_in_id(s_in_id[8:0]),
        .s_in_data(s_in_data[127:0]),
        
        .s_poll_id(s_poll_id[8:0]),
        .s_poll_seq(s126o_desc_poll_seq[31:0]),
        .s_poll_next_desc(s126o_desc_poll_next_desc[127:0]),
        .s_poll_next_desc_valid(s126o_desc_poll_next_desc_valid),
        
        .s_next_desc_rd_en(s_next_desc_rd_en),
        .s_next_desc_rd_id(s_next_desc_rd_id[8:0])
    );
    
    wire [31:0]     s126i_desc_poll_seq;
    wire            s126i_desc_poll_next_desc_valid;
    wire [127:0]    s126i_desc_poll_next_desc;
    
    PicoStreamIn #(
        .ID(STREAM_ID)
    ) s126i_stream (
        .clk(s_clk),
        .rst(s_rst),
        
        .s_rdy(i_valid),
        .s_en(i_rdy),
        .s_data(i_data[127:0]),
        
        .s_in_valid(s_in_valid),
        .s_in_id(s_in_id[8:0]),
        .s_in_data(s_in_data[127:0]),
        
        .s_poll_id(s_poll_id[8:0]),
        .s_poll_seq(s126i_desc_poll_seq[31:0]),
        .s_poll_next_desc(s126i_desc_poll_next_desc[127:0]),
        .s_poll_next_desc_valid(s126i_desc_poll_next_desc_valid),
        
        .s_next_desc_rd_en(s_next_desc_rd_en),
        .s_next_desc_rd_id(s_next_desc_rd_id[8:0])
    );
    
    assign s_out_data               = s126o_data_fetch;
    assign s_poll_seq               = s126i_desc_poll_seq | s126o_desc_poll_seq;
    assign s_poll_next_desc         = s126i_desc_poll_next_desc | s126o_desc_poll_next_desc;
    assign s_poll_next_desc_valid   = s126i_desc_poll_next_desc_valid | s126o_desc_poll_next_desc_valid;
    
    reg         start_wr, rd_active, wr_active;
    reg [31:0]  rd_len, wr_len;
    reg         PicoRd_q;
    reg         rst_q;
    
    reg [127:0] cmd;
    reg         cmd_valid;
    
    always @(posedge s_clk) begin
        rst_q   <= s_rst;
        
        if (rst_q) begin
            cmd_valid   <= 0;
        end else begin
            cmd_valid       <= 0;
            if (i_valid && ~rd_active && ~wr_active && ~cmd_valid) begin
                cmd_valid   <= 1;
                cmd         <= i_data;
            end
        end
    end
    
    generate if (W == 128) begin:W128
        
        assign PicoClk = s_clk;
        assign i_rdy = ~rd_active && ~cmd_valid;
        assign o_valid = PicoRd_q;
        assign o_data = PicoDataOut[127:0];
        
        always @(posedge s_clk) begin
            if (rst_q) begin
                rd_active   <= 0;
                wr_active   <= 0;
            end
            
            PicoRst <= rst_q;
            PicoRd  <= 0;
            PicoWr  <= 0;
            PicoRd_q<= PicoRd;
            
            if (cmd_valid /*&& ~rd_active && ~wr_active*/) begin
                if (cmd[64]) begin
                    rd_len      <= cmd[31:0];
                    PicoAddr  <= {cmd[63:32+4], 4'h0};
                    rd_active   <= 1;
                end else begin
                    wr_len      <= cmd[31:0];
                    PicoAddr  <= {cmd[63:32+4], 4'h0};
                    start_wr    <= 1;
                    wr_active   <= 1;
                end
            end
            
            if (i_valid) begin
                
                if (wr_active) begin
                    wr_len      <= wr_len - 16;
                    PicoDataIn  <= i_data[127:0];
                    PicoWr      <= 1;
                    if (~start_wr)
                        PicoAddr  <= PicoAddr + 16;
                    start_wr    <= 0;
                    if (wr_len == 32'h10)
                        wr_active   <= 0;
                end
            end
            
            // we'll fire a read every 3 clock cycles when the output is ready.
            // we could fire one every cycle if we had our own fifo with an almost-full flag, but this is good enough.
            if (o_rdy && |rd_active) begin
                if (~PicoRd && ~PicoRd_q)
                    PicoRd      <= 1;
                if (PicoRd_q) begin
                    rd_len      <= rd_len - 16;
                    PicoAddr  <= PicoAddr + 16;
                    if (rd_len == 32'h10)
                        rd_active   <= 0;
                end
            end
        end
        
    end else if (W == 32) begin:W32
    
        reg [1:0]   wr_byte, rd_byte;
        reg         o_valid_reg;
        reg [127:0] o_data_reg;
        
        assign PicoClk = s_clk;
        assign i_rdy = (~rd_active && ~wr_active && ~cmd_valid) || (wr_active && ((wr_byte == 2'h3) || (wr_len == 32'h4)));
        assign o_valid = o_valid_reg;
        assign o_data = o_data_reg;
        
        always @(posedge s_clk) begin
            if (rst_q) begin
                rd_active   <= 0;
                wr_active   <= 0;
            end
            
            //if (PicoRd)     $display("%0t: PicoRd @ 0x%x", $time, PicoAddr);
            //if (PicoRd_q)   $display("%0t: PicoRd data 0x%x", $time, PicoDataOut[31:0]);
            //if (PicoWr)     $display("%0t: PicoWr @ 0x%x. data: 0x%x", $time, PicoAddr, PicoDataIn[31:0]);
            
            PicoRst <= rst_q;
            PicoRd  <= 0;
            PicoWr  <= 0;
            PicoRd_q<= PicoRd;
            
            if (cmd_valid /*&& ~rd_active && ~wr_active*/) begin
                if (cmd[64]) begin
                    rd_len      <= cmd[31:0];
                    PicoAddr  <= {cmd[63:32+2], 2'h0};
                    rd_byte     <= 2'h0;
                    rd_active   <= 1;
                end else begin
                    wr_len      <= cmd[31:0];
                    PicoAddr  <= {cmd[63:32+2], 2'h0};
                    wr_byte     <= 2'h0;
                    start_wr    <= 1;
                    wr_active   <= 1;
                end
            end
            
            if (wr_active && (~i_rdy || i_valid  || (wr_len == 32'h4))) begin
                wr_len      <= wr_len - 4;
                if      (wr_byte == 2'h0)   PicoDataIn <= i_data[31:0];
                else if (wr_byte == 2'h1)   PicoDataIn <= i_data[63:32];
                else if (wr_byte == 2'h2)   PicoDataIn <= i_data[95:64];
                else if (wr_byte == 2'h3)   PicoDataIn <= i_data[127:96];
                wr_byte     <= wr_byte + 1;
                PicoWr      <= 1;
                if (~start_wr)
                    PicoAddr  <= PicoAddr + 4;
                start_wr    <= 0;
                if (wr_len == 32'h4)
                    wr_active   <= 0;
            end
            
            // we'll fire a read every 3 clock cycles when the output is ready.
            // we could fire one every cycle if we had our own fifo with an almost-full flag, but this is good enough.
            if (o_rdy && |rd_active) begin
                if (~PicoRd && ~PicoRd_q)
                    PicoRd      <= 1;
                if (PicoRd_q) begin
                    rd_len      <= rd_len - 4;
                    PicoAddr  <= PicoAddr + 4;
                    if (rd_len == 32'h4)
                        rd_active   <= 0;
                end
            end
            
            // assemble the PicoDataOut into the 128b register for stream output.
            // (this should be able to handle any number of 32b words, not just multiples of 4. so we may send out partial 128b words.)
            o_valid_reg <= PicoRd_q && ((rd_byte == 2'h3) || (rd_len == 32'h4));
            if (PicoRd_q) begin
                rd_byte <= rd_byte + 1;
                if      (rd_byte == 2'h0)   o_data_reg[31:0]    <= PicoDataOut;
                else if (rd_byte == 2'h1)   o_data_reg[63:32]   <= PicoDataOut;
                else if (rd_byte == 2'h2)   o_data_reg[95:64]   <= PicoDataOut;
                else if (rd_byte == 2'h3)   o_data_reg[127:96]  <= PicoDataOut;
            end
        end
    
    end endgenerate
    
endmodule

