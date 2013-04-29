/*
* File Name : Pico_Moving_Average.v
*
* Description : This module is designed to compute the moving average of a linear array of data.
*               The data is written into the DDR3 system by the host software, and the software
*               then streams an address and length to the firmware via the stream.  The firmware
*               then reads the data from the DDR3, computes the 4 sample moving average, and writes
*               the data back to the DDR3 (at an address sent from the host with the read address).
*               
*               Note: The read address, read data, write address, and write data ports to the DDR
*               system all operate on separate state machines for this sample.  This allows heavy
*               pipelining of read and write requests in the DDR system, which yields better
*               performance for random accesses into the DDR.
*
* Creation Date : Mon 20 Feb 2012 03:03:44 PM PST
*
* Author : Corey Olson
*
* Last Modified : Fri 02 Nov 2012 10:31:42 AM CDT
*
* Copyright 2011 Pico Computing, Inc.
*/

`include "axi_defines.v"
`include "PicoDefines.v"

module Pico_Moving_Average #(
    parameter C0_C_S_AXI_ID_WIDTH   = 8,                    // AXI ID width for this module
    parameter C0_C_S_AXI_ADDR_WIDTH = 32,                   // AXI address width
    parameter C0_C_S_AXI_DATA_WIDTH = 256,                  // AXI data width
    
    parameter C1_C_S_AXI_ID_WIDTH   = 8,                    // AXI ID width for this module
    parameter C1_C_S_AXI_ADDR_WIDTH = 32,                   // AXI address width
    parameter C1_C_S_AXI_DATA_WIDTH = 256                   // AXI data width
    
    )
    (
    
    //////////////////////
    // STREAM INTERFACE //
    //////////////////////

    input                               clk,                // stream clock
    input                               rst,                // synchronous reset for the stream clock

    input                               s1i_valid,          // data is valid in stream when asserted
    input   [`STREAM1_IN_WIDTH-1:0]     s1i_data,           // data from the stream
    output                              s1i_rdy,            // data transfers when valid & rdy are asserted


    /////////////////////
    // DDR 1 INTERFACE //
    /////////////////////
    `ifdef PICO_MODEL_M503
    // Note: the second DDR3 interface is unused on the M-503 in this sample, but it can 
    //       operate in parallel with DDR 0 to double the memory bandwidth on the M-503
    // Input control signals
    input                               c1_axi_clk,         // AXI input clock
    input                               c1_phy_init_done,   // Initialization completed
    input                               c1_axi_rst,         // Active high AXI reset signal
    
    // AXI port 1
    output                              c1_s1_axi_clk,      // clock for master 1

    // AXI write address channel signals
    input                               c1_s1_axi_awready,  // Indicates slave is ready to accept a 
    output [C1_C_S_AXI_ID_WIDTH-1:0]    c1_s1_axi_awid,     // Write address ID
    output [C1_C_S_AXI_ADDR_WIDTH-1:0]  c1_s1_axi_awaddr,   // Write address, byte-addressable
    output [7:0]                        c1_s1_axi_awlen,    // Write Burst Length
    output [2:0]                        c1_s1_axi_awsize,   // Write Burst size
    output [1:0]                        c1_s1_axi_awburst,  // Write Burst type
    output                              c1_s1_axi_awlock,   // Write lock type
    output [3:0]                        c1_s1_axi_awcache,  // Write Cache type
    output [2:0]                        c1_s1_axi_awprot,   // Write Protection type
    output [3:0]                        c1_s1_axi_awqos,    // Write Quality of Service Signaling
    output                              c1_s1_axi_awvalid,  // Write address valid
     
    // AXI write data channel signals
    input                               c1_s1_axi_wready,   // Write data ready
    output [C1_C_S_AXI_DATA_WIDTH-1:0]  c1_s1_axi_wdata,    // Write data
    output [C1_C_S_AXI_DATA_WIDTH/8-1:0]c1_s1_axi_wstrb,    // Write strobes
    output                              c1_s1_axi_wlast,    // Last write transaction   
    output                              c1_s1_axi_wvalid,   // Write valid
     
    // AXI write response channel signals
    input  [C1_C_S_AXI_ID_WIDTH-1:0]    c1_s1_axi_bid,      // Response ID
    input  [1:0]                        c1_s1_axi_bresp,    // Write response
    input                               c1_s1_axi_bvalid,   // Write reponse valid
    output                              c1_s1_axi_bready,   // Response ready
     
    // AXI read address channel signals
    input                               c1_s1_axi_arready,  // Read address ready
    output [C1_C_S_AXI_ID_WIDTH-1:0]    c1_s1_axi_arid,     // Read ID
    output [C1_C_S_AXI_ADDR_WIDTH-1:0]  c1_s1_axi_araddr,   // Read address, byte-addressable
    output [7:0]                        c1_s1_axi_arlen,    // Read Burst Length
    output [2:0]                        c1_s1_axi_arsize,   // Read Burst size
    output [1:0]                        c1_s1_axi_arburst,  // Read Burst type
    output                              c1_s1_axi_arlock,   // Read lock type
    output [3:0]                        c1_s1_axi_arcache,  // Read Cache type
    output [2:0]                        c1_s1_axi_arprot,   // Read Protection type
    output                              c1_s1_axi_arvalid,  // Read address valid
    output [3:0]                        c1_s1_axi_arqos,    // Read Quality of Service Signaling 
     
    // AXI read data channel signals   
    input  [C1_C_S_AXI_ID_WIDTH-1:0]    c1_s1_axi_rid,      // Response ID
    input  [1:0]                        c1_s1_axi_rresp,    // Read response
    input                               c1_s1_axi_rvalid,   // Read reponse valid
    input  [C1_C_S_AXI_DATA_WIDTH-1:0]  c1_s1_axi_rdata,    // Read data
    input                               c1_s1_axi_rlast,    // Read last
    output                              c1_s1_axi_rready,   // Read Response ready
    `endif // PICO_MODEL_M503    

    /////////////////////
    // DDR 0 INTERFACE //
    /////////////////////
    
    // Input control signals
    input                               c0_axi_clk,         // AXI input clock
    input                               c0_phy_init_done,   // Initialization completed
    input                               c0_axi_rst,         // Active high AXI reset signal
    
    // AXI port 1
    output                              c0_s1_axi_clk,      // clock for master 1

    // AXI write address channel signals
    input                               c0_s1_axi_awready,  // Indicates slave is ready to accept a 
    output [C0_C_S_AXI_ID_WIDTH-1:0]    c0_s1_axi_awid,     // Write address ID
    output reg [C0_C_S_AXI_ADDR_WIDTH-1:0]  c0_s1_axi_awaddr,   // Write address, byte-addressable
    output reg [7:0]                    c0_s1_axi_awlen,    // Write Burst Length
    output [2:0]                        c0_s1_axi_awsize,   // Write Burst size
    output [1:0]                        c0_s1_axi_awburst,  // Write Burst type
    output                              c0_s1_axi_awlock,   // Write lock type
    output [3:0]                        c0_s1_axi_awcache,  // Write Cache type
    output [2:0]                        c0_s1_axi_awprot,   // Write Protection type
    output [3:0]                        c0_s1_axi_awqos,    // Write Quality of Service Signaling
    output reg                          c0_s1_axi_awvalid,  // Write address valid
     
    // AXI write data channel signals
    input                               c0_s1_axi_wready,   // Write data ready
    output [C0_C_S_AXI_DATA_WIDTH-1:0]  c0_s1_axi_wdata,    // Write data
    output [C0_C_S_AXI_DATA_WIDTH/8-1:0]c0_s1_axi_wstrb,    // Write strobes
    output                              c0_s1_axi_wlast,    // Last write transaction   
    output                              c0_s1_axi_wvalid,   // Write valid
     
    // AXI write response channel signals
    input  [C0_C_S_AXI_ID_WIDTH-1:0]    c0_s1_axi_bid,      // Response ID
    input  [1:0]                        c0_s1_axi_bresp,    // Write response
    input                               c0_s1_axi_bvalid,   // Write reponse valid
    output                              c0_s1_axi_bready,   // Response ready
     
    // AXI read address channel signals
    input                               c0_s1_axi_arready,  // Read address ready
    output [C0_C_S_AXI_ID_WIDTH-1:0]    c0_s1_axi_arid,     // Read ID
    output reg [C0_C_S_AXI_ADDR_WIDTH-1:0]  c0_s1_axi_araddr,   // Read address, byte-addressable
    output reg [7:0]                    c0_s1_axi_arlen,    // Read Burst Length
    output [2:0]                        c0_s1_axi_arsize,   // Read Burst size
    output [1:0]                        c0_s1_axi_arburst,  // Read Burst type
    output                              c0_s1_axi_arlock,   // Read lock type
    output [3:0]                        c0_s1_axi_arcache,  // Read Cache type
    output [2:0]                        c0_s1_axi_arprot,   // Read Protection type
    output reg                          c0_s1_axi_arvalid,  // Read address valid
    output [3:0]                        c0_s1_axi_arqos,    // Read Quality of Service Signaling 
     
    // AXI read data channel signals   
    input  [C0_C_S_AXI_ID_WIDTH-1:0]    c0_s1_axi_rid,      // Response ID
    input  [1:0]                        c0_s1_axi_rresp,    // Read response
    input                               c0_s1_axi_rvalid,   // Read reponse valid
    input  [C0_C_S_AXI_DATA_WIDTH-1:0]  c0_s1_axi_rdata,    // Read data
    input                               c0_s1_axi_rlast,    // Read last
    output                              c0_s1_axi_rready    // Read Response ready
    
    );

    /////////////////////
    // LOCAL VARIABLES //
    /////////////////////
    
    localparam LENGTH                   = 4;                // number of elements to including in
                                                            //  the moving average
                                                            // NOTE: this must be a power of 2
                                                            //       because we later compute the
                                                            //       average by shifting to the
                                                            //       right by LOG_LENGTH
    localparam LOG_LENGTH               = 2;                // ceiling [log base 2(LENGTH)]
    
    reg                                 rst_q;              // registered version of the reset
    integer                             i;                  // integer for loops

    ////////////////////////
    // REGISTER THE RESET //
    ////////////////////////
    always @ (posedge clk) 
        rst_q <= rst;

    /**********************************************************************************************
    * if not using a memory interface, set the output valid and ready signals to 0
    **********************************************************************************************/
    `ifdef PICO_MODEL_M503
    assign c1_s1_axi_clk        = clk;
    assign c1_s1_axi_awvalid    = 0;
    assign c1_s1_axi_wvalid     = 0;
    assign c1_s1_axi_bready     = 0;
    assign c1_s1_axi_arvalid    = 0;
    assign c1_s1_axi_rready     = 0;
    `endif
    
    /**********************************************************************************************
    * THESE SIGNALS BELOW ARE CONSTANTS AND DO NOT NEED TO BE CHANGED BY THE USER FOR MOST
    * APPLICATIONS
    * NOTES: 1) A full description of these AXI signals can be found in the AMBA AXI Protocol Spec
    *           http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.ihi0022d/index.html
    *        2) The definitions used here to set these contants may be found in axi_defines.v,
    *           which is located in ISE_M50xlx240/source/axi_defines.v.
    **********************************************************************************************/
    
    //---------------------------------------------------------------------------------------------
    // AW = write address port signals
    //---------------------------------------------------------------------------------------------
    assign c0_s1_axi_awlock     = `NORMAL_ACCESS;           // Write lock type
    assign c0_s1_axi_awcache    = `NON_CACHE_NON_BUFFER;    // Write Cache type
    assign c0_s1_axi_awprot     = `DATA_SECURE_NORMAL;      // Write Protection type
    assign c0_s1_axi_awburst    = `INCREMENTING;            // address should increment
    assign c0_s1_axi_awqos      = `NOT_QOS_PARTICIPANT;     // not participating in the quality 
                                                            //  of service function
    `ifdef PICO_MODEL_M501
    assign c0_s1_axi_awsize     = `SIXTEEN_BYTES;           // number of bytes per transfer when
                                                            //  using the M-501
    `else
    assign c0_s1_axi_awsize     = `THIRTY_TWO_BYTES;        // number of bytes per transfer when
                                                            //  using the M-503 or M-505
    `endif
    
    //---------------------------------------------------------------------------------------------
    // W = write data port signals
    //---------------------------------------------------------------------------------------------
    assign c0_s1_axi_wstrb      = ~0;                       // byte write enable signals
    
    //---------------------------------------------------------------------------------------------
    // AR = read address port signals
    //---------------------------------------------------------------------------------------------
    assign c0_s1_axi_arlock     = `NORMAL_ACCESS;           // Read lock type
    assign c0_s1_axi_arcache    = `NON_CACHE_NON_BUFFER;    // Read Cache type
    assign c0_s1_axi_arprot     = `DATA_SECURE_NORMAL;      // Read Protection type
    assign c0_s1_axi_arburst    = `INCREMENTING;            // address should increment
    assign c0_s1_axi_arqos      = `NOT_QOS_PARTICIPANT;     // not participating in the quality 
                                                            //  of service function
    `ifdef PICO_MODEL_M501
    assign c0_s1_axi_arsize     = `SIXTEEN_BYTES;           // number of bytes per transfer when
                                                            //  using the M-501
    `else
    assign c0_s1_axi_arsize     = `THIRTY_TWO_BYTES;        // number of bytes per transfer when
                                                            //  using the M-503 or M-505
    `endif
    /**********************************************************************************************
    * END OF STANDARD CONSTANTS 
    **********************************************************************************************/

   


    /**********************************************************************************************
    * THESE SIGNALS BELOW ARE CONSTANT FOR THIS SAMPLE, BUT THEY CAN BE DYNAMIC FOR OTHER STANDARD
    * USER APPLICATIONS
    **********************************************************************************************/
    //---------------------------------------------------------------------------------------------
    // global signals
    //---------------------------------------------------------------------------------------------
    assign c0_s1_axi_clk        = clk;                      // clock for the DDR interface; this
                                                            //  sample runs the interface to the
                                                            //  AXI interconnect on the stream
                                                            //  clock, but this can also be run on
                                                            //  the DDR clock by:
                                                            //  assign c0_s1_axi_clk = c0_axi_clk

    //---------------------------------------------------------------------------------------------
    // AW = write address port signals
    //---------------------------------------------------------------------------------------------
    assign c0_s1_axi_awid       = 0;                        // Write burst ID; note that
                                                            //  only one burst can be
                                                            //  outstanding with a given
                                                            //  burst ID; in this example, we
                                                            //  assume that only 1 burst will
                                                            //  be outstanding at any time, so we
                                                            //  can keep a constant burst ID

    //---------------------------------------------------------------------------------------------
    // B = write response port signals 
    //---------------------------------------------------------------------------------------------
    assign c0_s1_axi_bready     = 1;                        // ready signal for the write response
                                                            //  port; in this example we assume
                                                            //  that all writes are successful and
                                                            //  therefore do not need to check the
                                                            //  write response

    //---------------------------------------------------------------------------------------------
    // AR = read address port signals
    //---------------------------------------------------------------------------------------------
    assign c0_s1_axi_arid       = 0;                        // Read burst ID; note that
                                                            //  only one burst can be
                                                            //  outstanding with a given
                                                            //  burst ID; in this example, we
                                                            //  assume that only 1 burst will
                                                            //  be outstanding at any time, so we
                                                            //  can keep a constant burst ID
    /**********************************************************************************************
    * END OF CONSTANT DDR SIGNALS THAT SHOULD BE SET BY THE USER
    **********************************************************************************************/




    /**********************************************************************************************
    * THESE SIGNALS BELOW ARE DYNAMIC FOR THIS SAMPLE AND WILL BE DYNAMIC FOR MOST USER
    * APPLICATIONS:
    * 
    * ---------------------------------------------------------------------------------------------
    * AW = write address
    * ---------------------------------------------------------------------------------------------
    * c0_s1_axi_awaddr      - byte address for the write port; note that the AXI bus is byte-addressable
    * c0_s1_axi_awlen       - length (in terms of 128-bit or 256-bit transfers) for this write
    *                         burst - 1; e.g. to write 128-bits of data on the M-501, set this
    *                         value to 0. to write 256-bits of data on the M-501, set this value to
    *                         1. similarly, to write 256-bits of data on the M-503 or M-505, set this value
    *                         to 0 (since we transfer 256 bits with each transaction on the M-503
    *                         and M-505)
    * c0_s1_axi_awvalid     - assert this valid signal whenever the write address signals are all
    *                         set; write address and other signals are accepted whenever
    *                         c0_s1_axi_awvalid and c0_s1_axi_awready are asserted in the same
    *                         clock cycle
    * 
    * ---------------------------------------------------------------------------------------------
    * W = write data
    * ---------------------------------------------------------------------------------------------
    * c0_s1_axi_wlast       - this signal should be 0 for all transactions (transfer of 128 bits on 
    *                         the M-501 and 256 bits on the M-503 or M-505) in a write burst (series of
    *                         transactions), except for the last transaction.  e.g. if writing 256
    *                         bits on the M-501, c0_s1_axi_awlast should be 0 for the first
    *                         transaction (of 128 bits) and 1 for the second transaction;
    *                         similarly if writing 1024 bits on the M-503 or M-505, this should be 0 for the
    *                         first three transactions (of 256 bits) and 1 for the fourth
    *                         transaction
    * c0_s1_axi_wdata       - the actual data to be written (128 bits wide on the M-501 and 256
    *                         bits wide on the M-503 or M-505)
    * c0_s1_axi_wvalid      - this valid signal should be asserted by the user logic when the write
    *                         data and last signals have been set to the correct values.  it should
    *                         then remain asserted until c0_s1_axi_wready is asserted.  the actual
    *                         data transaction occurs when wvalid and wready are asserted in the
    *                         same clock cycle
    *
    * ---------------------------------------------------------------------------------------------
    * AR = read address
    * ---------------------------------------------------------------------------------------------
    * c0_s1_axi_araddr      - address for the read port; note that the AXI bus is byte-addressable
    * c0_s1_axi_arlen       - length (in terms of 128-bit or 256-bit transfers) for this read
    *                         burst - 1; e.g. to read 128-bits of data on the M-501, set this
    *                         value to 0. to read 256-bits of data on the M-501, set this value to
    *                         1. similarly, to read 256-bits of data on the M-503 or M-505, set this value
    *                         to 0 (since we transfer 256 bits with each transaction on the M-503
    *                         or M-505)
    * c0_s1_axi_arvalid     - assert this valid signal whenever the read address signals are all
    *                         set; read address and other signals are accepted whenever
    *                         c0_s1_axi_arvalid and c0_s1_axi_arready are asserted in the same
    *                         clock cycle
    *
    * ---------------------------------------------------------------------------------------------
    * R = read data
    * ---------------------------------------------------------------------------------------------
    * c0_s1_axi_rready      - the user logic should monitor the state of the c0_s1_axi_rvalid
    *                         signal.  when the rvalid signal is asserted, the DDR system have
    *                         valid read data to return to the user.  the user can then accept that
    *                         data by asserting this rready signal.  the data transfer occurs when
    *                         rvalid and rready are asserted in the same clock cycle.  the user
    *                         logic may assert rready whenever they are ready to accept read data
    *                         (even if the rvalid signal is not asserted) or they may choose to
    *                         wait until the rvalid signal is asserted before asserting rready
    *                          
    * END OF DYNAMIC DDR SIGNALS THAT SHOULD BE SET BY THE USER
    **********************************************************************************************/






    /////////////////////////////
    // BEGIN SAMPLE USER LOGIC //
    /////////////////////////////

    /**********************************************************************************************
    * Stream 1 In = command stream
    * 
    * stream 1 in data format:
    * data[127:0] = {32'h0, 
    *               32-bit data size (in bytes), 
    *               32-bit address for the averages (byte address), 
    *               32-bit input data address (byte address)}
    *
    * NOTE: data size must be: 0 < size <= 4kB (M-501), 8kB (M-503), 8kB (M-505)
    **********************************************************************************************/

    /////////////////////////
    // STATES FOR ALL FSMs //
    /////////////////////////
    localparam  WAIT    = 0,    // wait for valid data
                VALID   = 1;    // have valid data, so do something with it


    ///////////////////////
    // READ ADDRESS PORT //
    /////////////////////// 
    reg                                 arState;
    reg                                 nextArState;
    reg                                 loadArAddr;
    reg                                 loadAwAddr;

    // address and length for the read from the command stream
    always @ (posedge clk) begin
        if (rst_q) begin
            c0_s1_axi_araddr    <= 0;
            c0_s1_axi_arlen     <= 0;
        end else if (loadArAddr) begin
            c0_s1_axi_araddr    <= s1i_data[31:0];
            c0_s1_axi_arlen     <= (s1i_data[95:64] >> c0_s1_axi_arsize) - 1;
        end
    end

    // FSM
    always @ (posedge clk) begin
        if (rst_q) begin
            arState <= WAIT;
        end else begin
            arState <= nextArState;
        end
    end

    // next state logic
    always @ (*) begin
        c0_s1_axi_arvalid   = 0;
        nextArState         = arState;
        case (arState)
            // wait for valid data from the input command stream
            WAIT: begin
                loadArAddr = 1;
                // data is accepted from the input stream once s1i_valid, loadArAddr, and
                //  loadAwAddr are all asserted in the same clock cycle
                if (s1i_valid && loadAwAddr) begin
                    nextArState = VALID;
                end
            end
            // received valid address and length data from the command stream, so send the read
            //  address
            VALID: begin
				loadArAddr = 0;
                c0_s1_axi_arvalid = 1;
                // read address is sent to the DDR system when arvalid and arready are asserted in
                //  the same clock cycle
                if (c0_s1_axi_arready) begin
                    nextArState = WAIT;
                end
            end
        endcase
    end
   

    ////////////////////////
    // WRITE ADDRESS PORT //
    //////////////////////// 
    reg                                 awState;
    reg                                 nextAwState;

    // address and length for the write from the command stream
    always @ (posedge clk) begin
        if (rst_q) begin
            c0_s1_axi_awaddr    <= 0;
            c0_s1_axi_awlen     <= 0;
        end else if (loadAwAddr) begin
            c0_s1_axi_awaddr    <= s1i_data[63:32];
            c0_s1_axi_awlen     <= (s1i_data[95:64] >> c0_s1_axi_awsize) - 1;
        end
    end

    // FSM
    always @ (posedge clk) begin
        if (rst_q) begin
            awState <= WAIT;
        end else begin
            awState <= nextAwState;
        end
    end

    // next state logic
    always @ (*) begin
        c0_s1_axi_awvalid   = 0;
        nextAwState         = awState;
        case (awState)
            // wait for valid data from the input command stream
            WAIT: begin
                loadAwAddr = 1;
                // data is accepted from the input stream once s1i_valid, loadArAddr, and
                //  loadAwAddr are all asserted in the same clock cycle
                if (s1i_valid && loadArAddr) begin
                    nextAwState = VALID;
                end
            end
            // received valid address and length data from the command stream, so send the write
            //  address
            VALID: begin
			    loadAwAddr = 0;
                c0_s1_axi_awvalid = 1;
                // write address is sent to the DDR system when awvalid and awready are asserted in
                //  the same clock cycle
                if (c0_s1_axi_awready) begin
                    nextAwState = WAIT;
                end
            end
        endcase
    end


    //////////////////////
    // SMOOTHING FILTER //
    //////////////////////
    reg     [31:0]                      data [0:LENGTH-1];  // data in the current moving average
    reg                                 dataValid;          // valid flag for the first piece of
                                                            //  data in the averaging window
    wire                                dataReady;          // data in the averaging window has
                                                            //  been accepted by the adder when
                                                            //  this is asserted
    reg                                 lastData;           // flag to mark the last piece of data
                                                            //  read from the DDR for this burst
    wire                                shiftData;          // shifts new data into the window when
                                                            //  the shifter does not contain valid
                                                            //  data yet to be averaged
    wire                                clearData;          // clear the data in the shifter after
                                                            //  the current data has finished
                                                            //  getting averaged; this should be
                                                            //  asserted with the last transaction
                                                            //  of a burst

    reg     [31+LOG_LENGTH:0]           sum;                // sum of the LENGTH elements
    reg     [31:0]                      average;            // registered current moving average
    reg                                 lastAverage;        // asserted with the last average to be
                                                            //  written to the DDR
    reg                                 averageValid;       // average data to be written to the
                                                            //  DDR is valid when asserted
    wire                                averageReady;       // write data port is ready to accept
                                                            //  more averaged data
    
    // clear data from the shifter when the last piece of valid data has been grabbed by the adder
    assign clearData = dataValid & dataReady & lastData;

    // shift new data into the shifter when data in the shifter has already been grabbed by the
    //  adder to compute the average
    assign shiftData = ~dataValid & c0_s1_axi_rvalid & c0_s1_axi_rready;

    // grab new data from the shifter into the adder when the adder currently does not contain any
    //  valid average data
    assign dataReady = ~averageValid;

    // shifter to hold the temporary values being averaged
    always @ (posedge clk) begin
        if (rst_q || clearData) begin
            // clear the moving window
            for(i=0; i<LENGTH; i=i+1) begin
                data[i]     <= 0;
            end
            dataValid       <= 0;
            lastData        <= 0;
        end else if (shiftData) begin
            // shift oldest data out of the window and new data from the memory into the moving
            //  window
            data[0]         <= c0_s1_axi_rdata;
            for(i=1; i<LENGTH; i=i+1) begin
                data[i]     <= data[i-1];
            end
            dataValid       <= c0_s1_axi_rvalid;
            lastData        <= c0_s1_axi_rlast;
        end else if (dataReady) begin
            // clear dataValid signal when the current data in the shifter is grabbed by the adder
            dataValid       <= 0;
        end
    end

    // compute the sum of the elements in the window
    always @ (*) begin
        sum                 = 0;
        for(i=0; i<LENGTH; i=i+1) begin
            sum             = sum + data[i];
        end
    end

    // divide the sum to get the average
    always @ (posedge clk) begin
        if (rst_q) begin
            average         <= 0;
            lastAverage     <= 0;
        end else if (averageReady) begin
            average         <= sum >> LOG_LENGTH;
            lastAverage     <= lastData;
        end
    end
    
    // average is valid when shifting new data into the shifter, and it is stale when it has been
    //  written into the DDR
    always @ (posedge clk) begin
        if (rst_q) begin
            averageValid    <= 0;
        end else if (~averageValid) begin
            averageValid    <= dataValid;
        end else if (averageReady) begin
            averageValid    <= 0;
        end
    end


    ////////////////////
    // READ DATA PORT //
    //////////////////// 
    // the read port is ready to hand off new data to the shifter when:
    // 1) the shifter currently does not hold valid data
    assign c0_s1_axi_rready = ~dataValid;


    /////////////////////
    // WRITE DATA PORT //
    ///////////////////// 
    // we assert the valid signal straight from the filter's valid signal and we pass the ready
    //  signal from the DDR system back to the filter
    assign c0_s1_axi_wvalid = averageValid;
    assign c0_s1_axi_wlast  = lastAverage;
    assign averageReady     = c0_s1_axi_wready;

    // data to be written to the DDR; in this example, we write the computed average to the DDR
    assign c0_s1_axi_wdata  = average;                  


    /////////////////
    // STREAM 1 IN //
    /////////////////
    assign s1i_rdy          = loadArAddr & loadAwAddr;
    
endmodule
