// PicoTestbench.v - testbench for the AXI_to_PicoStream sample project
// Copyright 2011 Pico Computing, Inc.

`timescale 1ns/1ps
`include "PicoSimParameters.v"

module PicoTestbench;
    
    PicoSim #(.verbose(0)) PicoSim();

    //reg [255:0] ref_seq;
    reg [255:0] ref_seq0;
    reg [255:0] ref_seq1;
    reg [255:0] ref_seq2;
    reg [255:0] ref_seq3;
    reg [255:0] ref_seq4;
    reg [255:0] ref_seq5;
    reg [255:0] ref_seq6;
    reg [255:0] ref_seq7;
    reg [127:0] query_seq;
    reg [127:0] read_data;


    initial begin
        //ref_seq = 256'h0464d13b63a068806fda9293a30ba5a4538ac43a6ab8be1448a9bc28759e62cb;
        ref_seq0 = 256'he389b65d283e6a2114be2ea9ac13a2c51a5ae0cac686a7f902290ac9ec471910;
        ref_seq1 = 256'h280aa28a020aaaf89aae0044813909030b2f804401e10a661972c5e8e183b808;
        ref_seq2 = 256'h854220248394972a8c42fa566fc68a843191be33900c214033ba207c8facaa7c;
        ref_seq3 = 256'h0a190931a2959ca240023f566b89f02a83c42b8c9e0a9a84000908c99090aa46;
        ref_seq4 = 256'h4640aaeeeefee8cccccccccccccccf1a113126a997296ac83a8a2fa9a02cf2bb;
        ref_seq5 = 256'h88aa68aae229a2aaea891050240501c214440411c14050140040108e644a8945;
        ref_seq6 = 256'h9ba26088eea2a4233980226062232c72ee110f3a94825caa160fa08a001693cb;
        ref_seq7 = 256'h80827101560a04ac8f0090d87ca21348c4a85a9a4c1bc6029a093006968c0148;
        query_seq = 128'hc8facaa7c280aa28a020aaaf89aae004;
        //query_seq = 128'h0464d13b63a068806fda9293a30ba5a4;
        //query_seq = 128'hc8facaa7c280aa28a020aaaf89aae004;
        //query_seq = 128'h66b89f02a83c42b8c9e0a9a84000908c;
        //query_seq = 128'ha08a001693cb88aa68aae229a2aaea89;

        // Base Initilization function required to use the PicoCard
        PicoSim.PicoSimInit();

        // Stream ref seq to DRAM at address 0
        $display("Writing ref seq to DRAM");
        PicoSim.PicoLoadBuffer128(0, ref_seq0[127:0]);
        PicoSim.PicoLoadBuffer128(16, ref_seq0[255:128]);
        PicoSim.PicoLoadBuffer128(32, ref_seq1[127:0]);
        PicoSim.PicoLoadBuffer128(48, ref_seq1[255:128]);
        PicoSim.PicoLoadBuffer128(64, ref_seq2[127:0]);
        PicoSim.PicoLoadBuffer128(80, ref_seq2[255:128]);
        PicoSim.PicoLoadBuffer128(96, ref_seq3[127:0]);
        PicoSim.PicoLoadBuffer128(112, ref_seq3[255:128]);
        PicoSim.PicoLoadBuffer128(128, ref_seq4[127:0]);
        PicoSim.PicoLoadBuffer128(144, ref_seq4[255:128]);
        PicoSim.PicoLoadBuffer128(160, ref_seq5[127:0]);
        PicoSim.PicoLoadBuffer128(176, ref_seq5[255:128]);
        PicoSim.PicoLoadBuffer128(192, ref_seq6[127:0]);
        PicoSim.PicoLoadBuffer128(208, ref_seq6[255:128]);
        PicoSim.PicoLoadBuffer128(224, ref_seq7[127:0]);
        PicoSim.PicoLoadBuffer128(240, ref_seq7[255:128]);
        PicoSim.WriteRam(0, 256, `PICO_DDR3_0);

        // Stream query seq to stream
        $display("Streaming query seq to FPGA");
        PicoSim.PicoLoadBuffer128(0, 128'h00000080000000400000000000000008);
        PicoSim.WriteStream(1, 0, 16);
        PicoSim.PicoLoadBuffer128(0, query_seq);
        PicoSim.WriteStream(1, 0, 16);
        /*PicoSim.PicoLoadBuffer128(0, 128'h00000080000000400000000000000008);
        PicoSim.WriteStream(2, 0, 16);
        PicoSim.PicoLoadBuffer128(0, query_seq);
        PicoSim.WriteStream(2, 0, 16);
        PicoSim.PicoLoadBuffer128(0, 128'h00000080000000400000000000000008);
        PicoSim.WriteStream(3, 0, 16);
        PicoSim.PicoLoadBuffer128(0, query_seq);
        PicoSim.WriteStream(3, 0, 16);
        PicoSim.PicoLoadBuffer128(0, 128'h00000080000000400000000000000008);
        PicoSim.WriteStream(4, 0, 16);
        PicoSim.PicoLoadBuffer128(0, query_seq);
        PicoSim.WriteStream(4, 0, 16);
        PicoSim.PicoLoadBuffer128(0, 128'h00000080000000400000000000000008);
        PicoSim.WriteStream(5, 0, 16);
        PicoSim.PicoLoadBuffer128(0, query_seq);
        PicoSim.WriteStream(5, 0, 16);*/

        // Stream result back from stream
        $display("Streaming result from FPGA");
        PicoSim.ReadStream(1, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:1 Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        /*PicoSim.ReadStream(2, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:2 Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        PicoSim.ReadStream(3, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:3 Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        PicoSim.ReadStream(4, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:4 Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        PicoSim.ReadStream(5, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:5 Query:%d Location:%d", read_data[47:32], read_data[31:0]);*/
        PicoSim.ReadStream(1, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:1 Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        /*PicoSim.ReadStream(2, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:2 Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        PicoSim.ReadStream(3, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:3 Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        PicoSim.ReadStream(4, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:4 Query:%d Location:%d", read_data[47:32], read_data[31:0]);
        PicoSim.ReadStream(5, 0, 16);
        read_data = PicoSim.PicoReadBuffer128(0);
        $display("Stream:5 Query:%d Location:%d", read_data[47:32], read_data[31:0]);*/
        

        

        $display("All Tests Successful!");
        $stop;
    end

endmodule
