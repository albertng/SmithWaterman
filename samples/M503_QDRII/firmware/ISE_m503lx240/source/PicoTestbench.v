// PicoTestbench.v - empty testbench
// Copyright 2011 Pico Computing, Inc.

`timescale 1ns/1ps
`include "PicoSimParameters.v"


module PicoTestbench;
    PicoSim #(.verbose(1)) PicoSim();
    
    parameter QDRII_CTRL_ADDR   = 32'h12350000; // PicoBus Address for controlling the QDRII system
    parameter QDRII_ERR_ADDR    = 32'h12350020; // PicoBus Address for accessing error flags
    parameter QDRII_DATA_ADDR   = 32'h12350040; // base PicoBus Address for accessing read data
    parameter QDRII_DATA_INCR   = 32'h00000020; // increment amount for reading different read data
    parameter QDRII_SIG         = 32'h55AA55AA; // QDRII PicoData signature

    parameter NUM_QDRII         = 3;            // number of QDRII chips on the M503 board
    parameter TEST_RUNTIME_NS   = 20000;        // runtime to allow the traffic generator to stress
                                                //  the QDRII system (in ns)
    
    integer                     i;
    integer                     j;
    reg [15:0]                  cal_done [0:NUM_QDRII];
    wire                        all_cal_complete;
    reg [128-16*NUM_QDRII-1:0]  junk;

    // test for all QDRII systems to be calibrated
    assign all_cal_complete = cal_done[2][0] & cal_done[1][0] & cal_done[0][0];

    initial begin
        PicoSim.PicoSimInit();       // Base Initialization function required to use the PicoCard

        // reset all QDRII systems
		$display("Resetting the QDRII systems\n");
        PicoSim.WritePicoBus(QDRII_CTRL_ADDR, {64'h1, 64'h0});
        PicoSim.WritePicoBus(QDRII_CTRL_ADDR, 128'h0);

        for (i=0; i<NUM_QDRII; i=i+1) begin
            cal_done[i] = 0;
        end

        // wait for calibration to complete on all QDRII systems
        for (i=0; all_cal_complete!==1; i=i+1) begin
			$display("Waiting for QDRII calibration to complete: %d\n", i);
            PicoSim.ReadPicoBus(QDRII_CTRL_ADDR, 16);
            {junk, cal_done[2], cal_done[1], cal_done[0]} = PicoSim.PicoReadBuffer128(0);
        end
		$display("QDRII calibration completed: %d, %d, %d\n", cal_done[2], cal_done[1], cal_done[0]);

        // let the test run for a while
        if (NUM_QDRII > 0) begin
            $display("Allowing QDRII test to run for %d ns\n", TEST_RUNTIME_NS);
            #TEST_RUNTIME_NS;
        end

        // read some data from each QDRII system
        for (i=0; i<NUM_QDRII; i=i+1) begin
			$display("Fetching read data from QDRII %d\n", i);
            PicoSim.ReadPicoBus(QDRII_DATA_ADDR + i*QDRII_DATA_INCR, 16);
        end

        // read the error flags
		$display("Reading the error flags\n");
        PicoSim.ReadPicoBus(QDRII_ERR_ADDR, 16);
        if (PicoSim.PicoReadBuffer128(0) != 128'h0) begin
            $display("Error in traffic generation module! Error flags: %h\n",
                        PicoSim.PicoReadBuffer128(0));
            $stop;
        end

        $display("All Tests Successful!");
        $stop;
    end
    
endmodule 
