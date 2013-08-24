// PicoTestbench.v - testbench for the AXI_to_PicoStream sample project
// Copyright 2011 Pico Computing, Inc.

`timescale 1ns/1ps
`include "PicoSimParameters.v"

module PicoTestbench;
    
    PicoSim #(.verbose(0)) PicoSim();

    reg [255:0] ref_seq;
    reg [127:0] query_seq;
    reg [127:0] read_data;


    initial begin
        //ref_seq = 256'h0464d13b63a068806fda9293a30ba5a4538ac43a6ab8be1448a9bc28759e62cb;
        query_seq = 128'hc8facaa7c280aa28a020aaaf89aae004;
        //query_seq = 128'h66b89f02a83c42b8c9e0a9a84000908c;
        //query_seq = 128'ha08a001693cb88aa68aae229a2aaea89;

        // Base Initilization function required to use the PicoCard
        PicoSim.PicoSimInit();

        /*// Stream ref seq to DRAM at address 0
        $display("Writing ref seq to DRAM");
        PicoSim.PicoLoadBuffer128(0, ref_seq[127:0]);
        PicoSim.PicoLoadBuffer128(16, ref_seq[255:128]);
        PicoSim.WriteRam(0, 32, `PICO_DDR3_0);*/

        // Stream query seq to stream
        $display("Streaming query seq to FPGA");
        PicoSim.PicoLoadBuffer128(0, 128'h00000080000000010000000000000008);
        PicoSim.WriteStream(1, 0, 16);
        PicoSim.PicoLoadBuffer128(0, query_seq);
        PicoSim.WriteStream(1, 0, 16);

        // Stream result back from stream
        $display("Streaming result from FPGA");
        PicoSim.ReadStream(1, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        PicoSim.ReadStream(1, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        

        

        $display("All Tests Successful!");
        $stop;
    end

endmodule
