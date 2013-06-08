/*  File Name        : one_hot_mux_tb.v
 *  Description      : Testbench for mux with variable data width and bus count, with a one-hot 
 *                     encoded select.
 *
 *  Revision History :
 *      Albert Ng   Jun 06 2013     Initial Revision
 *
 */

module one_hot_mux_tb;

    // Inputs
    reg [11:0] data_in;
    reg [3:0] select;

    // Outputs
    wire [2:0] data_out;

    // Instantiate the Unit Under Test (UUT)
    one_hot_mux #(4, 3) uut (
        .data_in(data_in), 
        .select(select), 
        .data_out(data_out)
    );

    initial begin
        // Initialize Inputs
        data_in = 0;
        select = 0;

        // Wait 100 ns for global reset to finish
        #100;
        
        data_in = 12'b000001010011;
        select = 4'b0001;
        #5;
        if (data_out != 3'b011) begin
            $display("Error, Select %d: Got %d Expected %d", select, data_out, 3'b011);
        end
        #5;
        select = 4'b0010;
        #5;
        if (data_out != 3'b010) begin
            $display("Error, Select %d: Got %d Expected %d", select, data_out, 3'b010);
        end
        #5;
        select = 4'b0100;
        #5;
        if (data_out != 3'b001) begin
            $display("Error, Select %d: Got %d Expected %d", select, data_out, 3'b001);
        end
        #5;
        select = 4'b1000;
        #5;
        if (data_out != 3'b000) begin
            $display("Error, Select %d: Got %d Expected %d", select, data_out, 3'b000);
        end
        
        #5;
        $finish;

    end
      
endmodule

