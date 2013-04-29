// PicoTestbench.v - testbench for the PicoBus128_HelloWorld sample project
// Copyright 2011 Pico Computing, Inc.

`timescale 1ns/1ps
`include "PicoSimParameters.v"


module PicoTestbench;
    PicoSim PicoSim();

    initial begin
        PicoSim.PicoSimInit();       // Base Initialization function required to use the PicoCard

        // The following Transactions are single writes and reads of the different registers in PicoBus128_HelloWorld.v
        PicoSim.WritePicoBus(32'h0, 32'hdeadbeef);      // Card Address, Data
        PicoSim.ReadPicoBus (32'h0, 32'h10);     // Card Address, Length, Host buffer address

        // Here we do two writes then read back from each of the PicoBus Addresses we wrote to
        $display("Writing 0x60 to registers at 0x10 and 0x20");
        PicoSim.WritePicoBus(32'h10, 32'h00000060);     
        PicoSim.WritePicoBus(32'h20, 32'h00000060);   
        $display("Reading registers at 0x10 and 0x20");
        PicoSim.ReadPicoBus (32'h10, 32'h10);   
        PicoSim.ReadPicoBus (32'h20, 32'h10);     

        // We read our write counter, then write to it and read it again
        $display("Getting the of writes to any of the four registers");
        PicoSim.ReadPicoBus (32'h30, 32'h10);   
        $display("Writing 0x60 to register 0x30");
        PicoSim.WritePicoBus(32'h30, 32'h00000060);   
        $display("Getting the of writes to any of the four registers");
        PicoSim.ReadPicoBus (32'h30, 32'h10);

        // Finally we do a read of all the reg in a single read.
        // This works due to their address being consecutive 
        $display("Reading all four registers in one shot");
        PicoSim.ReadPicoBus (32'h0, 32'h40);

        // verifying the final PicoBus read produced the expected data
        // expected data:
        // reg 0 = ~(0xdeadbeef)
        // reg 1 = {32'hdecafbad, 32'h12345678, 32'h87654321, 32'hdeadbeef} ^ 0x60
        // reg 2 = 0x60
        // reg 3 = 4
        if ((~(128'hdeadbeef)) != PicoSim.PicoReadBuffer128(0)) begin
            $display("Read incorrect value for reg 0: %X", PicoSim.PicoReadBuffer128(0));
            $stop;
        end else if (({32'hdecafbad, 32'h12345678, 32'h87654321, 32'hdeadbeef} ^ 128'h60) != 
                        PicoSim.PicoReadBuffer128(16)) begin
            $display("Read incorrect value for reg 1: %X", PicoSim.PicoReadBuffer128(16));
            $stop;
        end else if (128'h60 != PicoSim.PicoReadBuffer128(32)) begin
            $display("Read incorrect value for reg 2: %X", PicoSim.PicoReadBuffer128(32));
            $stop;
        end else if (128'h4 != PicoSim.PicoReadBuffer128(48)) begin
            $display("Read incorrect value for reg 3: %X", PicoSim.PicoReadBuffer128(48));
            $stop;
        end

        $display("All Tests Successful!");
        $finish;
    end
endmodule 

