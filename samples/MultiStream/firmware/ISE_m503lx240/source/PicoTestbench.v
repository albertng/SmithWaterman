// PicoTestbench.v - testbench for the AXI_to_PicoStream sample project
// Copyright 2011 Pico Computing, Inc.

`timescale 1ns/1ps
`include "PicoSimParameters.v"

module PicoTestbench;
    
     PicoSim #(.verbose(0)) PicoSim();
     parameter num_bits = 4;
     parameter div_mask =(~(~0 << num_bits)); 
     parameter buf_size = `data_buf_size;
     
     integer    i, div_count;
     
     // divisor register that we will write to PicoBus
     reg [31:0] divisor = 2;
     // register to keep track of next value to write or read
     reg [127:0] next_value;

     initial begin    
        // Base Initilization function required to use the PicoCard
        PicoSim.PicoSimInit();
        // Write the divisor to PicoBus address 0
        PicoSim.WritePicoBus(32'h00, divisor);
        div_count = 0;
        // stream 4kB of data to the memory at address 0
        for (i = 0; i < buf_size; i=i+16) begin
            // calculate next sequential value
            next_value = i/16;
            // count number of divisible values to check later
            if (next_value % divisor == 0)
                div_count = div_count+1;
            // write next_value to next space on the buffer
            PicoSim.PicoLoadBuffer128(i, next_value );
        end
        // Write entire block of 4kb to input stream
        PicoSim.WriteStream(1,0,buf_size);           
        
        // Check one value from each stream for every divisible value
        for (i = 0; i < div_count; i = i+1) begin
             PicoSim.ReadStream(1, 0, 16);
             next_value = PicoSim.PicoReadBuffer128(0);
             if ((div_mask & next_value)%divisor == 0)  begin
                 $display("Expected value not divisible by %d \
                             from stream 1, received %d",divisor, next_value);
                 $stop;
             end

            PicoSim.ReadStream(2,16,16);
            next_value = PicoSim.PicoReadBuffer128(16);
            if ((div_mask & next_value)%divisor != 0) begin
                $display("Expected value divisible by %d \
                             from stream 2, received %d",divisor, next_value);
                $stop;
            end
        end
         
        // check all remaining indivisible values on stream 1
        for (i = 0; i < (buf_size/32) - (2*div_count); i = i+1) begin
            PicoSim.ReadStream(1, 0, 16);
            next_value = PicoSim.PicoReadBuffer128(0);
            if ((div_mask & next_value)%divisor == 0) begin
                $display("Expected value not divisible by %d \
                            from stream 2, received %d",divisor, next_value);
                $stop;
            end
        end
        $display("All Tests Successful");        
        $stop;
    end   
endmodule
