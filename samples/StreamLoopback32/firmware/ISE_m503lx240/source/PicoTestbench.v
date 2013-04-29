// PicoTestbench.v - testbench for the StreamLoopback32 sample project
// Copyright 2011 Pico Computing, Inc.

`timescale 1ns/1ps
`include "PicoSimParameters.v"

module PicoTestbench;
    PicoSim PicoSim();
    
    reg     [31:0]              data;
    reg     [31:0]              sum;
    reg     [31:0]              stream_data;
    
    initial begin   
        PicoSim.PicoSimInit();       // Base Initialization function required to use the PicoCard

        // load up the buffer with 4kB of data
        for(data=0; data<`data_buf_size; data=data+4) begin
            PicoSim.PicoLoadBuffer32(data, data/4);
        end
        PicoSim.WriteStream(1, 0, `data_buf_size);
        
        // send 4kB more, 8kB total 
        for(data=`data_buf_size; data<2*`data_buf_size; data=data+4) begin
            PicoSim.PicoLoadBuffer32(data-`data_buf_size, data/4);
        end
        PicoSim.WriteStream(1, 0, `data_buf_size);
        
        // send 4kB more, 12kB total 
        for(data=2*`data_buf_size; data<3*`data_buf_size; data=data+4) begin
            PicoSim.PicoLoadBuffer32(data-(2*`data_buf_size), data/4);
        end
        PicoSim.WriteStream(1, 0, `data_buf_size);

        // clear the buffer
        for(data=0; data<`data_buf_size; data=data+4) begin
            PicoSim.PicoLoadBuffer32(data, 0);
        end

        // check the received data
        sum = 0;
        // 1st 4kB
        PicoSim.ReadStream(1, 0, `data_buf_size);
        for(data=0; data<`data_buf_size; data=data+4) begin
            stream_data = PicoSim.PicoReadBuffer32(data);
            if (stream_data != sum + data/4) begin
                $display("ERROR: stream_data[%d] = %X != %X + %X\n",
                    data/4,
                    stream_data,
                    sum,
                    data/4);
                $stop;
            end
            sum = stream_data;
        end
        // 2nd 4kB
        PicoSim.ReadStream(1, 0, `data_buf_size);
        for(data=`data_buf_size; data<2*`data_buf_size; data=data+4) begin
            stream_data = PicoSim.PicoReadBuffer32(data-`data_buf_size);
            if (stream_data != sum + data/4) begin
                $display("ERROR: stream_data[%d] = %X != %X + %X\n",
                    data/4,
                    stream_data,
                    sum,
                    data/4);
                $stop;
            end
            sum = stream_data;
        end
        // 3rd 4kB
        PicoSim.ReadStream(1, 0, `data_buf_size);
        for(data=2*`data_buf_size; data<3*`data_buf_size; data=data+4) begin
            stream_data = PicoSim.PicoReadBuffer32(data-(2*`data_buf_size));
            if (stream_data != sum + data/4) begin
                $display("ERROR: stream_data[%d] = %X != %X + %X\n",
                    data/4,
                    stream_data,
                    sum,
                    data/4);
                $stop;
            end
            sum = stream_data;
        end
        
        $display("All Tests Successful!");
        $finish;
    end
endmodule 

