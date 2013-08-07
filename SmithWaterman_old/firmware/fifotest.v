module fifotest(
    input clk,
    input rst,
    input [17:0] din,
    input wr_en,
    input rd_en,
    output [17:0] dout,
    output full,
    output empty
    );
    
    inter_ref_block_fifo irbf (
        .clk(clk),
        .rst(rst),
        .din(din),
        .wr_en(wr_en),
        .rd_en(rd_en),
        .dout(dout),
        .full(full),
        .empty(empty)
    );
endmodule
