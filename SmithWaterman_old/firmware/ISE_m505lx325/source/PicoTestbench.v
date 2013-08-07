// PicoTestbench.v - testbench for the StreamLoopback128 sample project
// Copyright 2011 Pico Computing, Inc.

`timescale 1ns/1ps
`include "PicoSimParameters.v"

module PicoTestbench;
    PicoSim PicoSim();

    initial begin
        PicoSim.PicoSimInit();       // Base Initialization function required to use the PicoCard

        PicoSim.PicoLoadBuffer128(8'h0,     128'h1);
        PicoSim.PicoLoadBuffer128(8'h10,   128'h10);
        PicoSim.PicoLoadBuffer128(8'h20, 128'h1000);

        PicoSim.WriteStream(7'h1, 8'h000, 32'h10);
        PicoSim.ReadStream (7'h1, 8'h050, 32'h10);
        #100;
        PicoSim.WriteStream(7'h1, 8'h010, 32'h20);
        PicoSim.ReadStream (7'h1, 8'h0a0, 32'h10);
        PicoSim.ReadStream (7'h1, 8'h0f0, 32'h10);
        #100;

        PicoSim.WriteStream(7'h1, 8'h000, 32'h30);
        PicoSim.ReadStream (7'h1, 8'h050, 32'h10);

        if (PicoSim.PicoReadBuffer128(8'h50) == 128'h42424242_deadbeef_00001012_00000001)
            $display("All Tests Successful!");
        else
            $display("Bad data!");

        #4000;

        $finish;
    end
endmodule 
