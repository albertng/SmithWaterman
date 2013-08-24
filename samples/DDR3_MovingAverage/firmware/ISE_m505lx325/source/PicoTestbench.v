// PicoTestbench.v - testbench for the AXI_to_PicoStream sample project
// Copyright 2011 Pico Computing, Inc.

`timescale 1ns/1ps
`include "PicoSimParameters.v"

module PicoTestbench;
    
    //PicoSim #(.verbose(0)) PicoSim();
    PicoSim PicoSim();

    reg [127:0] inputData       [0:255];    // input data to compute the moving average
    reg [127:0] expectedAverage [0:255];    // computed expected moving average
    reg [127:0] actualAverage   [0:255];    // moving average from the FPGA

    integer     i;
    reg [33:0]  sum;

    initial begin
        
        // Base Initilization function required to use the PicoCard
        PicoSim.PicoSimInit();
       
        // stream 4kB of data to the memory at address 0
        for(i=0; i<4096; i=i+16) begin
            inputData[i/16] = $random & 32'hFFFFFFFF;
            PicoSim.PicoLoadBuffer128(i, inputData[i/16]);
        end
		PicoSim.WriteRam(0, 4096, `PICO_DDR3_0);
       
        // send command to compute moving average of 4kB of data from address 0 to address 4kB
        PicoSim.PicoLoadBuffer128(0, {32'h0, 32'd4096, 32'd4096, 32'h0});
        PicoSim.WriteStream(1, 0, 16);

        // compute the expected moving average 
        sum = 0;
        for(i=0; i<4096/16; i=i+1) begin
`ifdef PICO_MODEL_M501
            if (i > 3) begin
                sum = sum - inputData[i-4];
            end
            sum = sum + inputData[i];
            expectedAverage[i] = sum >> 2;
`else
            if (i % 2 == 0) begin
                if (i > 7) begin
                    sum = sum - inputData[i-8];
                end
                sum = sum + inputData[i];
                expectedAverage[i] = sum >> 2;
            end else begin
                expectedAverage[i] = 0;
            end
`endif
        end
        
        // allow the operation to complete: data to be read from DDR and result written to DDR
        #5000;

        // read moving average data from DDR
        PicoSim.ReadRam(4096, 4096, `PICO_DDR3_0);
        for(i=0; i<4096; i=i+16) begin
            actualAverage[i/16] = PicoSim.PicoReadBuffer128(i);
        end
        
        // compare the actual moving average data against the expected data
        for(i=0; i<4096/16; i=i+1) begin
            if (actualAverage[i] !== expectedAverage[i]) begin
                $display("data[%d]: actual (%h) != expected (%h)\n",
                    i, actualAverage[i], expectedAverage[i]);
                $stop;
            end
        end

        $display("All Tests Successful!");
        $stop;
    end

endmodule
