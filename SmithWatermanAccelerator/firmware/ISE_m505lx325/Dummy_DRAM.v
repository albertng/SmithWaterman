
module Dummy_DRAM(
    input clk,
    input rst,

    // AXI Bus Interface
    input          axi0_clk_in,           // AXI bus clock
    output         axi0_arready_out,      // AXI bus address ready
    input [7:0]    axi0_arid_in,          // AXI bus address request ID
    input [32:0]   axi0_araddr_in,        // AXI bus address
    input [7:0]    axi0_arlen_in,         // AXI bus address read length    
    input          axi0_arvalid_in,       // AXI bus address valid
    output [7:0]   axi0_rid_out,          // AXI bus read data request ID
    output         axi0_rvalid_out,       // AXI bus read data valid
    output [255:0] axi0_rdata_out,        // AXI bus read data
    input          axi0_rready_in,        // AXI bus read data ready
    
    input          axi1_clk_in,           // AXI bus clock
    output         axi1_arready_out,      // AXI bus address ready
    input [7:0]    axi1_arid_in,          // AXI bus address request ID
    input [32:0]   axi1_araddr_in,        // AXI bus address
    input [7:0]    axi1_arlen_in,         // AXI bus address read length    
    input          axi1_arvalid_in,       // AXI bus address valid
    output [7:0]   axi1_rid_out,          // AXI bus read data request ID
    output         axi1_rvalid_out,       // AXI bus read data valid
    output [255:0] axi1_rdata_out,        // AXI bus read data
    input          axi1_rready_in,        // AXI bus read data ready
    
    input          axi2_clk_in,           // AXI bus clock
    output         axi2_arready_out,      // AXI bus address ready
    input [7:0]    axi2_arid_in,          // AXI bus address request ID
    input [32:0]   axi2_araddr_in,        // AXI bus address
    input [7:0]    axi2_arlen_in,         // AXI bus address read length    
    input          axi2_arvalid_in,       // AXI bus address valid
    output [7:0]   axi2_rid_out,          // AXI bus read data request ID
    output         axi2_rvalid_out,       // AXI bus read data valid
    output [255:0] axi2_rdata_out,        // AXI bus read data
    input          axi2_rready_in         // AXI bus read data ready
    );

    localparam WAIT = 0;
    localparam SEND = 1;
    reg state;
    reg next_state;

    reg [255:0] axi0_rdata;
    reg axi0_arready;
    reg axi0_rvalid;
    reg [255:0] axi1_rdata;
    reg axi1_arready;
    reg axi1_rvalid;
    reg [255:0] axi2_rdata;
    reg axi2_arready;
    reg axi2_rvalid;

    //assign axi0_arready_out = axi_arready;
    assign axi0_arready_out = 1;
    assign axi0_rid_out = axi0_arid_in;
    assign axi0_rvalid_out = axi0_arvalid_in;
    assign axi0_rdata_out = axi0_rdata;
    
    assign axi1_arready_out = 1;
    assign axi1_rid_out = axi1_arid_in;
    assign axi1_rvalid_out = axi1_arvalid_in;
    assign axi1_rdata_out = axi1_rdata;
    
    assign axi2_arready_out = 1;
    assign axi2_rid_out = axi2_arid_in;
    assign axi2_rvalid_out = axi2_arvalid_in;
    assign axi2_rdata_out = axi2_rdata;
    
    /*always @(posedge clk) begin
        if (rst) begin
            state = WAIT;
        end else begin
            state = next_state;
        end
    end
    always @(*) begin
        case(state)
            WAIT : begin
                if (axi_arvalid_in) begin
                    next_state = SEND;
                end else begin
                    next_state = WAIT;
                end
            end
            
            SEND : begin
                next_state = WAIT;
            end
        endcase
    end
    always @(*) begin
        case(state)
            WAIT : begin
                axi_arready = 0;
                axi_rvalid = 0;
            end
            
            SEND : begin
                axi_arready = 1;
                axi_rvalid = 1;
            end
        endcase
    end*/
    
    always @(*) begin
        if (axi0_araddr_in == 33'b0) begin
            axi0_rdata = 256'he389b65d283e6a2114be2ea9ac13a2c51a5ae0cac686a7f902290ac9ec471910;
        end else if (axi0_araddr_in == 33'b00100000) begin
            axi0_rdata = 256'h280aa28a020aaaf89aae0044813909030b2f804401e10a661972c5e8e183b808;
        end else if (axi0_araddr_in == 33'b01000000) begin
            axi0_rdata = 256'h854220248394972a8c42fa566fc68a843191be33900c214033ba207c8facaa7c;
        end else if (axi0_araddr_in == 33'b01100000) begin
            axi0_rdata = 256'h0a190931a2959ca240023f566b89f02a83c42b8c9e0a9a84000908c99090aa46;
        end else if (axi0_araddr_in == 33'b10000000) begin
            axi0_rdata = 256'h4640aaeeeefee8cccccccccccccccf1a113126a997296ac83a8a2fa9a02cf2bb;
        end else if (axi0_araddr_in == 33'b10100000) begin
            axi0_rdata = 256'h88aa68aae229a2aaea891050240501c214440411c14050140040108e644a8945;
        end else if (axi0_araddr_in == 33'b11000000) begin
            axi0_rdata = 256'h9ba26088eea2a4233980226062232c72ee110f3a94825caa160fa08a001693cb;
        end else if (axi0_araddr_in == 33'b11100000) begin
            axi0_rdata = 256'h80827101560a04ac8f0090d87ca21348c4a85a9a4c1bc6029a093006968c0148;
        end else begin
            axi0_rdata = 256'h0;
        end
    end
    
    always @(*) begin
        if (axi1_araddr_in == 33'b0) begin
            axi1_rdata = 256'he389b65d283e6a2114be2ea9ac13a2c51a5ae0cac686a7f902290ac9ec471910;
        end else if (axi1_araddr_in == 33'b00100000) begin
            axi1_rdata = 256'h280aa28a020aaaf89aae0044813909030b2f804401e10a661972c5e8e183b808;
        end else if (axi1_araddr_in == 33'b01000000) begin
            axi1_rdata = 256'h854220248394972a8c42fa566fc68a843191be33900c214033ba207c8facaa7c;
        end else if (axi1_araddr_in == 33'b01100000) begin
            axi1_rdata = 256'h0a190931a2959ca240023f566b89f02a83c42b8c9e0a9a84000908c99090aa46;
        end else if (axi1_araddr_in == 33'b10000000) begin
            axi1_rdata = 256'h4640aaeeeefee8cccccccccccccccf1a113126a997296ac83a8a2fa9a02cf2bb;
        end else if (axi1_araddr_in == 33'b10100000) begin
            axi1_rdata = 256'h88aa68aae229a2aaea891050240501c214440411c14050140040108e644a8945;
        end else if (axi1_araddr_in == 33'b11000000) begin
            axi1_rdata = 256'h9ba26088eea2a4233980226062232c72ee110f3a94825caa160fa08a001693cb;
        end else if (axi1_araddr_in == 33'b11100000) begin
            axi1_rdata = 256'h80827101560a04ac8f0090d87ca21348c4a85a9a4c1bc6029a093006968c0148;
        end else begin
            axi1_rdata = 256'h0;
        end
    end
    
    always @(*) begin
        if (axi2_araddr_in == 33'b0) begin
            axi2_rdata = 256'he389b65d283e6a2114be2ea9ac13a2c51a5ae0cac686a7f902290ac9ec471910;
        end else if (axi2_araddr_in == 33'b00100000) begin
            axi2_rdata = 256'h280aa28a020aaaf89aae0044813909030b2f804401e10a661972c5e8e183b808;
        end else if (axi2_araddr_in == 33'b01000000) begin
            axi2_rdata = 256'h854220248394972a8c42fa566fc68a843191be33900c214033ba207c8facaa7c;
        end else if (axi2_araddr_in == 33'b01100000) begin
            axi2_rdata = 256'h0a190931a2959ca240023f566b89f02a83c42b8c9e0a9a84000908c99090aa46;
        end else if (axi2_araddr_in == 33'b10000000) begin
            axi2_rdata = 256'h4640aaeeeefee8cccccccccccccccf1a113126a997296ac83a8a2fa9a02cf2bb;
        end else if (axi2_araddr_in == 33'b10100000) begin
            axi2_rdata = 256'h88aa68aae229a2aaea891050240501c214440411c14050140040108e644a8945;
        end else if (axi2_araddr_in == 33'b11000000) begin
            axi2_rdata = 256'h9ba26088eea2a4233980226062232c72ee110f3a94825caa160fa08a001693cb;
        end else if (axi2_araddr_in == 33'b11100000) begin
            axi2_rdata = 256'h80827101560a04ac8f0090d87ca21348c4a85a9a4c1bc6029a093006968c0148;
        end else begin
            axi2_rdata = 256'h0;
        end
    end
    /*assign axi_rdata_out = axi_araddr_in == 33'b0 ? 
                            256'h0464d13b63a068806fda9293a30ba5a4538ac43a6ab8be1448a9bc28759e62cb : 256'h0;*/

endmodule
