// StreamLoopback128.v
// Copyright 2010 Pico Computing, Inc.
/* This module illustrates the use of the streams interface between a PC host and
   the Pico Card. The kernel of this module echoes back the input data.
*/

`include "PicoDefines.v"

module StreamLoopback128 (
    // The clk and rst signals are shared between all the streams in this module,
    //   which are: stream #1 in, and stream #1 out.
    input               clk,
    input               rst,
    
    // These are the signals for stream #1 INto the firmware.
    input               s1i_valid,
    output              s1i_rdy,
    input [127:0]       s1i_data,
    
    // These are the signals for stream #1 OUT of the firmware.
    output              s1o_valid,
    input               s1o_rdy,
    output [127:0]      s1o_data
    );
    
    // this register tracks whether our current sum register value has been output yet,
    //   in which case we consider it "empty."
    reg         empty;
    // this is a running sum of the input stream.
    reg [31:0]  sum;
    // this is a copy of the low 32 bits of the last input value, because we want to echo it.
    reg [31:0]  last_input;
    
    // we're ready for more input whenever either:
    //   the current sum value has already been sent out, and is "empty"
    //   or, the output is ready, in which case we'll output the current sum on the same clock
    //     cycle that we compute the new sum.
    assign s1i_rdy = empty || s1o_rdy;
    // our output is valid whenever the current sum register is not "empty."
    assign s1o_valid = ~empty;
    // the output data is a concatenation of the current sum, the last input value, and a signature.
    assign s1o_data = {32'h42424242, 32'hdeadbeef, sum[31:0], last_input[31:0]};
    
    always @(posedge clk) begin
        if (rst) begin
            // we start the summing at 0 upon reset.
            empty   <= 1;
            sum     <= 32'h0;
        end else begin
            // Here we figure out whether our sum register will be empty on the next cycle.
            // If we're getting new input, we're definitely not going to be empty.
            // If we're outputting a value and _not_ getting new input, we will be empty.
            if (s1i_valid)
                empty   <= 0;
            else if (s1o_rdy)
                empty   <= 1;
            // If there's more input data for us (s1i_valid) and we've decided we're ready for it (s1i_rdy),
            //   then add the new value to the sum.
            if (s1i_rdy && s1i_valid) begin
                sum <= sum + s1i_data[31:0];
                last_input <= s1i_data[31:0];
            end
        end
    end
    
endmodule

