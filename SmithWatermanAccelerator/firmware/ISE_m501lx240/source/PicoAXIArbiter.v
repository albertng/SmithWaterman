/*
* File Name : PicoAXIArbiter.v
*
* Description : This module is responsbile for arbitrating access to
*               the AXI master interface from the AXI slave interfaces.  It
*               reads request signals from the slave interfaces, and it
*               acknowledges those requests in a round-robin priority scheme.
*               When a request is acknowledged, its data (address info) is
*               written into the master interface FIFO, which will be emptied
*               by the master interface controller.  If this arbiter is
*               arbitrating write accesses, the write address and data must be
*               valid for a slave port before acknowledging access.  Also,
*               once the write address is parsed into the master interface
*               FIFO, the slave port is placed into a "to-be-handled" FIFO,
*               which specifies the order that the write data should be
*               arbitrated (done by the multiplexer module).
*               
*               Note: This round-robin priority scheme does not waste any
*               cycles checking empty slave ports.  i.e. if a slave port is 
*               not requesting access, it is skipped and no cycles are 
*               wasted checking that port.
*           
*               Note: this module simply drives a pipelined mux, so no data
*               must enter this module.
*
* Creation Date : Wed 13 Jul 2011 05:34:47 PM PDT
*
* Author : Corey Olson
*
* Last Modified : Thu 28 Jul 2011 04:52:23 PM PDT
*
* Copyright 2011 Pico Computing, Inc.
*/
module PicoAXIArbiter #(
    ////////////////
    // PARAMETERS //
    ////////////////
    parameter C_NUM_SLAVE_PORTS             = 4,        // number of slave interfaces that will be 
                                                        //  requesting access 
    parameter LOG_C_NUM_SLAVE_PORTS         = 2         // = ceil(log(C_NUM_SLAVE_PORTS))
    )
    (
    input                                   clk,
    input                                   rst,
    
    //////////////////////
    // slave interfaces //
    //////////////////////
    input       [C_NUM_SLAVE_PORTS-1:0]     s_axi_valid,

    ///////////////////////////
    // multiplexer interface //
    ///////////////////////////
    output reg  [LOG_C_NUM_SLAVE_PORTS-1:0] currentSlave,
    input                                   m_axi_ready
    );

    ////////////////////////
    // INTERNAL VARIABLES //
    ////////////////////////
    wire    [2*C_NUM_SLAVE_PORTS-1:0]   concatenatedValid;
    reg     [C_NUM_SLAVE_PORTS-1:0]     rotatedValid;
    reg     [LOG_C_NUM_SLAVE_PORTS-1:0] nextSlave;
    integer                             i;
    reg                                 rst_q;

    ///////////////////////
    // Arbitration Logic //
    ///////////////////////
    assign concatenatedValid = {s_axi_valid, s_axi_valid};

    // register the reset signal
    always @ (posedge clk) begin
        rst_q <= rst;
    end
    
    // rotate the incoming requests to the left by the previous ack'd slave + 1
    always @ (posedge clk) begin
        if (rst_q) begin
            rotatedValid <= 0;
        end else if (m_axi_ready) begin
            rotatedValid <= concatenatedValid >> (nextSlave + 1);
        end
    end
    
    // priority encoder to find which bank should be used for the next waddr AXI write
    always @ (*) begin
        nextSlave = 0;
        // priority given to LS rotatedValid bit
        // rotatedValid[0] has highest priority
        // rotatedValid[C_NUM_SLAVE_PORTS-1] has lowest priority
        for(i=C_NUM_SLAVE_PORTS-1; i>=0; i=i-1) begin
            if (rotatedValid[i]) begin
                nextSlave = (currentSlave + 1 + i);
                if (nextSlave >= C_NUM_SLAVE_PORTS) begin
                    nextSlave = nextSlave - C_NUM_SLAVE_PORTS;
                end
            end
        end
    end
    
    // store the slave that should be ack'd next
    always @ (posedge clk) begin
        if (rst_q) begin
            currentSlave <= 0;
        end else if (m_axi_ready) begin
            currentSlave <= nextSlave;
        end
    end

endmodule
