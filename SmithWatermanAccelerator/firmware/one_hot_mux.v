/*  File Name        : one_hot_mux.v
 *  Description      : Mux with variable data width and bus count, with a one-hot encoded
 *                     select.
 *
 *  Revision History :
 *      Albert Ng   Jun 06 2013     Initial Revision
 *
 */
module one_hot_mux(
    input  [bus_count*bus_width-1:0] data_in,
    input  [bus_count-1:0] select,
    output [bus_width-1:0] data_out
    );

    parameter bus_count = 4;
    parameter bus_width = 4;
    
    reg [bus_width-1:0] data_out_r;

    assign data_out = data_out_r;
    integer i, j;
    always @(*) begin
            data_out_r = 'b0;
            for (i = 0; i < bus_count; i = i + 1)
                for (j = 0; j < bus_width; j = j + 1)
                    data_out_r[j] = data_out_r[j] | (data_in[bus_width*i + j] & select[i]);
    end
endmodule
