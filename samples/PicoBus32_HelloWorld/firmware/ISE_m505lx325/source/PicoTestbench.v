// PicoTestbench.v - testbench for the PicoBus32_HelloWorld sample project
// Copyright 2011 Pico Computing, Inc.

`timescale 1ns/1ps
`include "PicoSimParameters.v"

module PicoTestbench;
    PicoSim PicoSim();

    initial begin
        PicoSim.PicoSimInit();       // Base Initialization function required to use the PicoCard

        // The following Transactions are single writes and reads of the different registers in PicoBus32_HelloWorld.v
        PicoSim.WritePicoBus(32'h0, 32'hdeadbeef);      // Card Address, Data
        PicoSim.ReadPicoBus (32'h0, 32'h04);     // Card Address, Length, Host buffer address

        

        // Here we do two writes then read back from each of the PicoBus Addresses we wrote to
        $display("Writing 0x60 to registers at 0x10 and 0x20");
        PicoSim.WritePicoBus(32'h04, 32'h00000060);     
        PicoSim.WritePicoBus(32'h08, 32'h00000060);   
        $display("Reading registers at 0x10 and 0x20");
        PicoSim.ReadPicoBus (32'h04, 32'h04);   
        PicoSim.ReadPicoBus (32'h08, 32'h04);     

        // We read our write counter, then write to it and read it again
        $display("Getting the of writes to any of the four registers");
        PicoSim.ReadPicoBus (32'h0c, 32'h04);   
        $display("Writing 0x60 to register 0x30");
        PicoSim.WritePicoBus(32'h0c, 32'h00000060);   
        $display("Getting the of writes to any of the four registers");
        PicoSim.ReadPicoBus (32'h0c, 32'h04);

        // Finally we do a read of all the reg in a single read.
        // This works due to their address being consecutive 
        $display("Reading all four registers in one shot");
        PicoSim.ReadPicoBus (32'h0, 32'h10);
        
        // verifying the final PicoBus read produced the expected data
        // expected data:
        // reg 0 = ~(0xdeadbeef)
        // reg 1 = 0xdeadbeef ^ 0x60
        // reg 2 = 0x60
        // reg 3 = 4
        if ((~(32'hdeadbeef)) != PicoSim.PicoReadBuffer32(0)) begin
            $display("Read incorrect value for reg 0: %X", PicoSim.PicoReadBuffer32(0));
            $stop;
        end else if ((32'hdeadbeef ^ 128'h60) != PicoSim.PicoReadBuffer32(4)) begin
            $display("Read incorrect value for reg 1: %X", PicoSim.PicoReadBuffer32(4));
            $stop;
        end else if (32'h60 != PicoSim.PicoReadBuffer32(8)) begin
            $display("Read incorrect value for reg 2: %X", PicoSim.PicoReadBuffer32(8));
            $stop;
        end else if (32'h4 != PicoSim.PicoReadBuffer32(12)) begin
            $display("Read incorrect value for reg 3: %X", PicoSim.PicoReadBuffer32(12));
            $stop;
        end
        
        $display("All Tests Successful!");
        $finish;
    end
endmodule 

