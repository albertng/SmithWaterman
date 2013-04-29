// MultiStream.v
// Copyright 2010 Pico Computing, Inc.
/* This module illustrates the use of the streams interface between a PC host and
   the Pico Card. The kernel of this module echoes back the "non-divisible" input data
    on stream 2 and the "divisible" input data on stream 1.
*/

`include "PicoDefines.v"
// can only do 4 bit division
parameter NUM_BITS = 4;

module MultiStream (
    
     // Signals for communicating with PicoBus
    input               PicoClk,
    input               PicoRst,
    input      [31:0]   PicoAddr,
    input      [31:0]   PicoDataIn, 
    input               PicoRd, 
    input               PicoWr,
    output reg [31:0]   PicoDataOut,

    // The clk and rst signals are shared between all the streams in this module,
    //   which are: stream #1 in, and stream #1 out.
    input               clk,
    input               rst,
    
    // These are the signals for stream #1 into the firmware.
    input               s1i_valid,
    output              s1i_rdy,
    input [127:0]       s1i_data,
    
    // These are the signals for the 2 streams out of the firmware.
    output              s1o_valid,
    input               s1o_rdy,
    output reg [127:0]  s1o_data,
     
    output              s2o_valid,
    input               s2o_rdy,
    output reg [127:0]  s2o_data
);

    // divisor we use to calculate division
    reg [NUM_BITS-1:0]  divisor;
    // register which stores the remainder from the last division
    reg [NUM_BITS-1:0]  remainder;
    // the divisor value on our pico bus
    reg [NUM_BITS-1:0]  div_pico;
    // temporary divisor value
    reg [NUM_BITS-1:0]  div1;
    // store the current value of the remainder
    wire [NUM_BITS-1:0] remainder_wire;
    
    // this register tracks whether our current sum register value has been output yet,
    //   in which case we consider it "empty.
    reg empty;
    
    // Stream 1 valid if value is not divisible and not empty
    assign s1o_valid = ~empty & ~(remainder == 0);

    // Stream 2 valid if value is divisible and not empty 
    assign s2o_valid = ~empty & (remainder == 0);

    // Input stream is ready when we are empty or either of output streams is valid and ready
    assign s1i_rdy = empty | (s1o_valid & s1o_rdy) | (s2o_valid & s2o_rdy);

    // calculate the remainder
    assign remainder_wire = s1i_data[NUM_BITS-1:0] - ((s1i_data[NUM_BITS-1:0]/divisor)*divisor);    

    // read the divisor into PicoAddr
    always @(posedge PicoClk) begin
        if (PicoRst) begin
            div_pico <= 0;
        end else begin
            if ( PicoWr && PicoAddr[31:0] == 32'h00 )
                div_pico <= PicoDataIn;
        end
    end
    
    // synchronize divisor from pico bus with clk
    always @(posedge clk) begin
        if (rst) begin
            div1 <= 0;
            divisor <= 0;
        end else begin
            div1 <= div_pico;
            divisor <= div1;
        end
    end
    
    // block which handles empty and remainder signals
    always @ (posedge clk) begin
        if (rst) begin
            empty <= 1;
            remainder <= 0;
        end else begin
            // If we're getting new input, we're definitely not going to be empty.
            // If we're outputting a value and not getting new input, we will be empty
            if (s1i_valid)
                empty <= 0;
            else if ((s1o_rdy & s1o_valid) | (s2o_valid & s2o_rdy))
                empty <= 1;
            // If there's more input data for us (s1i_valid) and we've decided we're ready for it (s1i_rdy),
            //   then calculate the remainder from the division
            if (s1i_rdy && s1i_valid) begin
                remainder <= remainder_wire;
            end
        end
    end
    
    // output data will always be the input data if input is ready
    always @ (posedge clk) begin
        if (rst) begin
            s1o_data <= 0;
            s2o_data <= 0;
        end else if (s1i_rdy) begin
            s1o_data <= s1i_data;
            s2o_data <= s1i_data;
        end
    end
    
endmodule
