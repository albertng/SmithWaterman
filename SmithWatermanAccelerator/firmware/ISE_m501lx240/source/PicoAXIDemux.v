/*
* File Name : PiocAXIDemux.v
*
* Description :  This module demultiplexes read or write response data from
*                the master interface FIFO back to the proper slave interface
*                FIFO, which is specified by the MS bits of the transaction
*                ID.  
*
* Creation Date : Thu 18 Aug 2011 06:26:24 PM PDT
*
* Author : Corey Olson
*
* Last Modified : Mon 29 Aug 2011 03:03:41 PM PDT
*
* Copyright 2011 Pico Computing, Inc.
*/
module PicoAXIDemux #(
    parameter C_NUM_SLAVE_PORTS     = 4,
    parameter C_AXI_SLAVE_ID_WIDTH  = 8,
    parameter C_AXI_MASTER_ID_WIDTH = 8,
    parameter C_AXI_DATA_WIDTH      = 128
    )
    (

    // interconnect clock and reset
    input                                   clk,
    input                                   rst,

    // master port to the MIG
    input       [C_AXI_MASTER_ID_WIDTH-1:0] m_axi_id,
    input                                   m_axi_valid,
    output                                  m_axi_ready,
    input       [C_AXI_DATA_WIDTH-1:0]      m_axi_data,
    input                                   m_axi_last,
    input       [1:0]                       m_axi_resp,

    // slave ports back to the masters
    // pass most of these signals through, but use the valid and ready signals
    // to tell which slave should listen to the data
    output reg  [C_AXI_SLAVE_ID_WIDTH-1:0]  s_axi_id,
    output reg  [C_NUM_SLAVE_PORTS-1:0]     s_axi_valid,
    input       [C_NUM_SLAVE_PORTS-1:0]     s_axi_ready,
    output reg  [C_AXI_DATA_WIDTH-1:0]      s_axi_data,
    output reg                              s_axi_last,
    output reg  [1:0]                       s_axi_resp
    );
    
    /////////////////////
    // LOCAL VARIABLES //
    /////////////////////
    reg         rst_q;
    integer     i;
    wire        slaveTakingData;

    // register the reset signal
    always @ (posedge clk) begin
        rst_q <= rst;
    end

    // register the return data
    always @ (posedge clk) begin
        if (rst_q) begin
            s_axi_id    <= 0;
            s_axi_data  <= 0;
            s_axi_last  <= 0;
            s_axi_resp  <= 0;
            s_axi_valid <= 0;
        end 
        // grab new data from the master port if it's valid data and we are
        // ready to accept new data
        else if (m_axi_valid && m_axi_ready) begin
            s_axi_id    <= m_axi_id[C_AXI_SLAVE_ID_WIDTH-1:0];
            s_axi_data  <= m_axi_data;
            s_axi_last  <= m_axi_last;
            s_axi_resp  <= m_axi_resp;
            // set the valid signal based upon the MS bits of the master
            // transaction ID
            s_axi_valid <= 0;
            for(i=0; i<C_NUM_SLAVE_PORTS; i=i+1) begin
                if(m_axi_id[C_AXI_MASTER_ID_WIDTH-1:C_AXI_SLAVE_ID_WIDTH] == i) begin
                    s_axi_valid[i] <= 1'b1;
                end
            end
        end 
        // the target slave port is taking the valid data, so the data stored
        // is no longer valid
        else if (slaveTakingData) begin
            s_axi_valid <= 0;
        end
    end

    // set m_axi_ready only when we either do not currently hold valid data or
    // it's about to get transmitted
    assign m_axi_ready = slaveTakingData | (s_axi_valid==0);

    // asserted when one of the slave ports is accepting valid data
    assign slaveTakingData = |(s_axi_valid & s_axi_ready);

endmodule
