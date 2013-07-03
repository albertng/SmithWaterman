
module bram_tb;

    // Inputs
    reg clk;
    reg wea;
    reg [9:0] addra;
    reg [127:0] dina;
    reg [9:0] addrb;
    
    // Outputs
    wire [127:0] doutb;

    query_seq_bram qsbram1 (
        .clka(clk),
        .wea(wea),
        .addra(addra),
        .dina(dina),
        .clkb(clk),
        .addrb(addrb),
        .doutb(doutb)
    );

    initial begin
        clk = 0;
        wea = 0;
        addra = 0;
        dina = 0;
        addrb = 0;
        #100;
        wea = 1;
        addra = 0;
        dina = 10;
        #10;
        wea = 0;
        addrb = 0;
        #100;
        $finish;
    
    end
    
    always begin
        #5 clk = !clk;
    end
    
endmodule