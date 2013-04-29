// PicoBus32_HelloWorld.v
// Copyright 2011 Pico Computing Inc.

module PicoBus32_HelloWorld(
    // These are the standard PicoBus signals that we'll use to communicate with the rest of the system.
    input               PicoClk, 
    input               PicoRst,
    input  [31:0]       PicoAddr,
    input  [31:0]       PicoDataIn, 
    input               PicoRd, 
    input               PicoWr,
    output reg [31:0]   PicoDataOut
);

    // We will use the following Address table for the PicoAddress
    // TheReg0 @ PicoAddr == 32'h0
    // TheReg1 @ PicoAddr == 32'h4
    // TheReg2 @ PicoAddr == 32'h8
    // TheReg3 @ PicoAddr == 32'hc

    reg [31:0] TheReg0;     // This is a simple flip of the bits
    reg [31:0] TheReg1;     // This is an XOR with the value currently in it
    reg [31:0] TheReg2;     // This is adder starting at 0, and incrementing by each write
    
    reg [31:0] TheReg3;     // This is a counter which increments by 1 on each write 
                            // to the above registers, ignoring input data

    always @(posedge PicoClk) begin
        if (PicoRst) begin
            // we'll start off with known reset values when the system asserts PicoRst at startup.
            TheReg0 <= 32'h0;
            TheReg1 <= 32'hdeadbeef;
            TheReg2 <= 32'h0;
            TheReg3 <= 32'h0;
        end else begin
            // Here we process writes to the FPGA.
            // The PicoBus will assert PicoWr on the same cycle that PicoAddr is valid and the data in on PicoDataIn.
            if ( PicoWr && PicoAddr[31:0] == 32'h0 )
                // simply invert the bits of the input data, and store it.
                TheReg0 <= ~PicoDataIn;
            if ( PicoWr && PicoAddr[31:0] == 32'h4 )
                // XOR the input data with our previous value.
                TheReg1 <= TheReg1 ^ PicoDataIn;    
            if ( PicoWr && PicoAddr[31:0] == 32'h8 )
                // add the value written to our current value.
                TheReg2 <= TheReg2 + PicoDataIn;    
            if ( PicoWr && ( PicoAddr[31:0] == 32'h0 || PicoAddr[31:0] == 32'h4 || PicoAddr[31:0] == 32'h8 || PicoAddr[31:0] == 32'hc) )
                // increment the value of TheReg3 by 1 each time a write is done to any of the registers we have.
                // note that this statement is processed in parallel with the statements that handle writes to each
                // of the specific registers.
                TheReg3 <= TheReg3 + 1;    
        end
        
        // Here we answer read requests on the PicoBus.
        // We place the requested data on PicoDataOut on the next cycle after PicoRd and PicoAddr are valid.
        if (PicoRd && PicoAddr[31:0] == 32'h0)
            PicoDataOut <= TheReg0;     
        else if (PicoRd && PicoAddr[31:0] == 32'h4)
            PicoDataOut <= TheReg1;     
        else if (PicoRd && PicoAddr[31:0] == 32'h8)
            PicoDataOut <= TheReg2;     
        else if (PicoRd && PicoAddr[31:0] == 32'hc)
            PicoDataOut <= TheReg3;     
        else
            // since the PicoBus is shared, we need to drive our output to 0 when we're not being read from.
            PicoDataOut <= 32'h0;
    end
endmodule
