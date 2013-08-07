/*  File Name        : AXIArbiter_tb.v
 *  Description      : AXI Bus Arbiter test bench 
 *
 *  Revision History :
 *      Albert Ng   Jul 12 2013     Initial Revision
 *      Albert Ng   Aug 07 2013     Changed DRAM data width to 33
 *
 */

module AXIArbiter_tb;

    // Inputs
    reg clk;
    reg rst;
    reg axi_arready_in;
    reg [7:0] axi_rid_in;
    reg axi_rvalid_in;
    reg [255:0] axi_rdata_in;
    reg [3:0] active_ports_in1;
    reg [3:0] active_ports_in2;
    reg [5:0] rd_id_0_in;
    reg [32:0] rd_addr_0_in;
    reg [7:0] rd_len_0_in;
    reg rd_info_valid_0_in;
    reg rd_data_rdy_0_in;
    reg [5:0] rd_id_1_in;
    reg [32:0] rd_addr_1_in;
    reg [7:0] rd_len_1_in;
    reg rd_info_valid_1_in;
    reg rd_data_rdy_1_in;
    reg [5:0] rd_id_2_in;
    reg [32:0] rd_addr_2_in;
    reg [7:0] rd_len_2_in;
    reg rd_info_valid_2_in;
    reg rd_data_rdy_2_in;
    reg [5:0] rd_id_3_in;
    reg [32:0] rd_addr_3_in;
    reg [7:0] rd_len_3_in;
    reg rd_info_valid_3_in;
    reg rd_data_rdy_3_in;

    // Outputs
    wire axi_clk_out1;
    wire [7:0] axi_arid_out1;
    wire [32:0] axi_araddr_out1;
    wire [7:0] axi_arlen_out1;
    wire axi_arvalid_out1;
    wire axi_rready_out1;
    wire rd_info_rdy_0_out1;
    wire [255:0] rd_data_0_out1;
    wire rd_data_valid_0_out1;
    wire rd_info_rdy_1_out1;
    wire [255:0] rd_data_1_out1;
    wire rd_data_valid_1_out1;
    wire rd_info_rdy_2_out1;
    wire [255:0] rd_data_2_out1;
    wire rd_data_valid_2_out1;
    wire rd_info_rdy_3_out1;
    wire [255:0] rd_data_3_out1;
    wire rd_data_valid_3_out1;

    wire [7:0] axi_arid_out2;
    wire [32:0] axi_araddr_out2;
    wire [7:0] axi_arlen_out2;
    wire axi_arvalid_out2;
    wire axi_rready_out2;
    wire rd_info_rdy_0_out2;
    wire [255:0] rd_data_0_out2;
    wire rd_data_valid_0_out2;
    wire rd_info_rdy_1_out2;
    wire [255:0] rd_data_1_out2;
    wire rd_data_valid_1_out2;
    wire rd_info_rdy_2_out2;
    wire [255:0] rd_data_2_out2;
    wire rd_data_valid_2_out2;
    wire rd_info_rdy_3_out2;
    wire [255:0] rd_data_3_out2;
    wire rd_data_valid_3_out2;

    // Instantiate the Units Under Test (UUT)
    AXIArbiter uut1 (
        .clk(clk), 
        .rst(rst), 
        .axi_clk_out(axi_clk_out1), 
        .axi_arready_in(axi_arready_in), 
        .axi_arid_out(axi_arid_out1), 
        .axi_araddr_out(axi_araddr_out1), 
        .axi_arlen_out(axi_arlen_out1), 
        .axi_arvalid_out(axi_arvalid_out1), 
        .axi_rid_in(axi_rid_in), 
        .axi_rvalid_in(axi_rvalid_in), 
        .axi_rdata_in(axi_rdata_in), 
        .axi_rready_out(axi_rready_out1), 
        .active_ports_in(active_ports_in1),
        .rd_id_0_in(rd_id_0_in), 
        .rd_addr_0_in(rd_addr_0_in), 
        .rd_len_0_in(rd_len_0_in), 
        .rd_info_valid_0_in(rd_info_valid_0_in), 
        .rd_info_rdy_0_out(rd_info_rdy_0_out1), 
        .rd_data_0_out(rd_data_0_out1), 
        .rd_data_valid_0_out(rd_data_valid_0_out1), 
        .rd_data_rdy_0_in(rd_data_rdy_0_in), 
        .rd_id_1_in(rd_id_1_in), 
        .rd_addr_1_in(rd_addr_1_in), 
        .rd_len_1_in(rd_len_1_in), 
        .rd_info_valid_1_in(rd_info_valid_1_in), 
        .rd_info_rdy_1_out(rd_info_rdy_1_out1), 
        .rd_data_1_out(rd_data_1_out1), 
        .rd_data_valid_1_out(rd_data_valid_1_out1), 
        .rd_data_rdy_1_in(rd_data_rdy_1_in), 
        .rd_id_2_in(rd_id_2_in), 
        .rd_addr_2_in(rd_addr_2_in), 
        .rd_len_2_in(rd_len_2_in), 
        .rd_info_valid_2_in(rd_info_valid_2_in), 
        .rd_info_rdy_2_out(rd_info_rdy_2_out1), 
        .rd_data_2_out(rd_data_2_out1), 
        .rd_data_valid_2_out(rd_data_valid_2_out1), 
        .rd_data_rdy_2_in(rd_data_rdy_2_in), 
        .rd_id_3_in(rd_id_3_in), 
        .rd_addr_3_in(rd_addr_3_in), 
        .rd_len_3_in(rd_len_3_in), 
        .rd_info_valid_3_in(rd_info_valid_3_in), 
        .rd_info_rdy_3_out(rd_info_rdy_3_out1), 
        .rd_data_3_out(rd_data_3_out1), 
        .rd_data_valid_3_out(rd_data_valid_3_out1), 
        .rd_data_rdy_3_in(rd_data_rdy_3_in)
    );

    AXIArbiter uut2 (
        .clk(clk), 
        .rst(rst), 
        .axi_clk_out(axi_clk_out), 
        .axi_arready_in(axi_arready_in), 
        .axi_arid_out(axi_arid_out2), 
        .axi_araddr_out(axi_araddr_out2), 
        .axi_arlen_out(axi_arlen_out2), 
        .axi_arvalid_out(axi_arvalid_out2), 
        .axi_rid_in(axi_rid_in), 
        .axi_rvalid_in(axi_rvalid_in), 
        .axi_rdata_in(axi_rdata_in), 
        .axi_rready_out(axi_rready_out2), 
        .active_ports_in(active_ports_in2),
        .rd_id_0_in(rd_id_0_in), 
        .rd_addr_0_in(rd_addr_0_in), 
        .rd_len_0_in(rd_len_0_in), 
        .rd_info_valid_0_in(rd_info_valid_0_in), 
        .rd_info_rdy_0_out(rd_info_rdy_0_out2), 
        .rd_data_0_out(rd_data_0_out2), 
        .rd_data_valid_0_out(rd_data_valid_0_out2), 
        .rd_data_rdy_0_in(rd_data_rdy_0_in), 
        .rd_id_1_in(rd_id_1_in), 
        .rd_addr_1_in(rd_addr_1_in), 
        .rd_len_1_in(rd_len_1_in), 
        .rd_info_valid_1_in(rd_info_valid_1_in), 
        .rd_info_rdy_1_out(rd_info_rdy_1_out2), 
        .rd_data_1_out(rd_data_1_out2), 
        .rd_data_valid_1_out(rd_data_valid_1_out2), 
        .rd_data_rdy_1_in(rd_data_rdy_1_in), 
        .rd_id_2_in(rd_id_2_in), 
        .rd_addr_2_in(rd_addr_2_in), 
        .rd_len_2_in(rd_len_2_in), 
        .rd_info_valid_2_in(rd_info_valid_2_in), 
        .rd_info_rdy_2_out(rd_info_rdy_2_out2), 
        .rd_data_2_out(rd_data_2_out2), 
        .rd_data_valid_2_out(rd_data_valid_2_out2), 
        .rd_data_rdy_2_in(rd_data_rdy_2_in), 
        .rd_id_3_in(rd_id_3_in), 
        .rd_addr_3_in(rd_addr_3_in), 
        .rd_len_3_in(rd_len_3_in), 
        .rd_info_valid_3_in(rd_info_valid_3_in), 
        .rd_info_rdy_3_out(rd_info_rdy_3_out2), 
        .rd_data_3_out(rd_data_3_out2), 
        .rd_data_valid_3_out(rd_data_valid_3_out2), 
        .rd_data_rdy_3_in(rd_data_rdy_3_in)
    );

    integer i;
    initial begin
        // Initialize Inputs
        clk <= 0;
        rst <= 1;
        axi_arready_in <= 0;
        axi_rid_in <= 0;
        axi_rvalid_in <= 0;
        axi_rdata_in <= 0;
        active_ports_in1 <= 4'b1111;
        rd_id_0_in <= 0;
        rd_addr_0_in <= 0;
        rd_len_0_in <= 0;
        rd_info_valid_0_in <= 0;
        rd_data_rdy_0_in <= 0;
        rd_id_1_in <= 0;
        rd_addr_1_in <= 0;
        rd_len_1_in <= 0;
        rd_info_valid_1_in <= 0;
        rd_data_rdy_1_in <= 0;
        rd_id_2_in <= 0;
        rd_addr_2_in <= 0;
        rd_len_2_in <= 0;
        rd_info_valid_2_in <= 0;
        rd_data_rdy_2_in <= 0;
        rd_id_3_in <= 0;
        rd_addr_3_in <= 0;
        rd_len_3_in <= 0;
        rd_info_valid_3_in <= 0;
        rd_data_rdy_3_in <= 0;
        #20;
        rst <= 0;
        
        for (i = 0; i < 5; i = i + 1) begin
            // Wait_port_valid / Reader 0 priority
            if (axi_arvalid_out1 != 0)
                $display("@%0dns axi_ar_valid_out1 error", $time);
            if (axi_rready_out1 != 0)
                $display("@%0dns axi_rready_out1 error", $time);
            if (rd_info_rdy_0_out1 != 0)
                $display("@%0dns rd_info_rdy_0_out1 error", $time);
            if (rd_info_rdy_1_out1 != 0)
                $display("@%0dns rd_info_rdy_1_out1 error", $time);
            if (rd_info_rdy_2_out1 != 0)
                $display("@%0dns rd_info_rdy_2_out1 error", $time);
            if (rd_info_rdy_3_out1 != 0)
                $display("@%0dns rd_info_rdy_3_out1 error", $time);
            if (rd_data_valid_0_out1 != 0)
                $display("@%0dns rd_data_valid_0_out1 error", $time);
            if (rd_data_valid_1_out1 != 0)
                $display("@%0dns rd_data_valid_1_out1 error", $time);
            if (rd_data_valid_2_out1 != 0)
                $display("@%0dns rd_data_valid_2_out1 error", $time);
            if (rd_data_valid_3_out1 != 0)
                $display("@%0dns rd_data_valid_3_out1 error", $time);
        end

        // Wait_port_valid / Reader 0 priority
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        rd_id_0_in <= 6'b000001;
        rd_addr_0_in <= 10;
        rd_len_0_in <= 0;
        rd_info_valid_0_in <= 1;
        #10;

        // Connect_port / Reader 0 serviced
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b00000001)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 10)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);        
        #10;

        // Wait_axi_rdy / Reader 0 serviced
        axi_arready_in <= 1;
        #1;
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b00000001)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 10)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 1)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time); 
        #9;
        
        // Wait_port_valid / Reader 1 priority
        axi_arready_in <= 0;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        rd_id_0_in <= 6'b000010;
        rd_addr_0_in <= 11;
        rd_len_0_in <= 0;
        rd_info_valid_0_in <= 1;
        rd_id_1_in <= 6'b000011;
        rd_addr_1_in <= 20;
        rd_len_1_in <= 0;
        rd_info_valid_1_in <= 1;
        #9;

        // Connect_port / Reader 1 serviced
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b01000011)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 20)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);        
        #10;

        for (i = 0; i < 2; i = i + 1) begin
            // Wait_axi_rdy / Reader 1 serviced
            if (axi_arvalid_out1 != 1)
                $display("@%0dns axi_ar_valid_out1 error", $time);
            if (axi_arid_out1 != 8'b01000011)
                $display("@%0dns axi_arid_out1 error", $time);
            if (axi_araddr_out1 != 20)
                $display("@%0dns axi_araddr_out1 error", $time);
            if (axi_arlen_out1 != 0)
                $display("@%0dns axi_arlen_out1 error", $time);
            if (axi_rready_out1 != 0)
                $display("@%0dns axi_rready_out1 error", $time);
            if (rd_info_rdy_0_out1 != 0)
                $display("@%0dns rd_info_rdy_0_out1 error", $time);
            if (rd_info_rdy_1_out1 != 0)
                $display("@%0dns rd_info_rdy_1_out1 error", $time);
            if (rd_info_rdy_2_out1 != 0)
                $display("@%0dns rd_info_rdy_2_out1 error", $time);
            if (rd_info_rdy_3_out1 != 0)
                $display("@%0dns rd_info_rdy_3_out1 error", $time);
            if (rd_data_valid_0_out1 != 0)
                $display("@%0dns rd_data_valid_0_out1 error", $time);
            if (rd_data_valid_1_out1 != 0)
                $display("@%0dns rd_data_valid_1_out1 error", $time);
            if (rd_data_valid_2_out1 != 0)
                $display("@%0dns rd_data_valid_2_out1 error", $time);
            if (rd_data_valid_3_out1 != 0)
                $display("@%0dns rd_data_valid_3_out1 error", $time);   
            #10;
        end

        // Wait_axi_rdy / Reader 1 serviced
        axi_arready_in <= 1;
        #1;
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b01000011)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 20)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 1)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Wait_port_valid / Reader 2 priority
        axi_arready_in <= 0;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        rd_info_valid_1_in <= 0;
        #9;

        // Connect_port / Reader 0 serviced
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b00000010)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 11)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);        
        #10;

        // Wait_axi_rdy / Reader 0 serviced
        axi_arready_in <= 1;
        #1;
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b00000010)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 11)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 1)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Wait_port_valid / Reader 3 priority
        axi_arready_in <= 0;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        rd_info_valid_0_in <= 0;
        #9;

        // Wait_port_valid / Reader 3 priority
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        rd_id_2_in <= 6'b100001;
        rd_addr_2_in <= 30;
        rd_len_2_in <= 0;
        rd_info_valid_2_in <= 1;
        rd_id_3_in <= 6'b111001;
        rd_addr_3_in <= 40;
        rd_len_3_in <= 0;
        rd_info_valid_3_in <= 1;
        #10;

        // Connect_port / Reader 3 serviced
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b11111001)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 40)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);        
        #10;

        // Wait_axi_rdy / Reader 3 serviced
        axi_arready_in <= 1;
        #1;
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b11111001)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 40)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 1)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Wait_port_valid / Reader 0 priority
        axi_arready_in <= 0;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        rd_info_valid_3_in <= 0;
        #9;

        // Connect_port / Reader 2 serviced
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b10100001)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 30)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #10;
        
        // Wait_axi_rdy / Reader 2 serviced
        axi_arready_in <= 1;
        #1;
        if (axi_arvalid_out1 != 1)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_arid_out1 != 8'b10100001)
            $display("@%0dns axi_arid_out1 error", $time);
        if (axi_araddr_out1 != 30)
            $display("@%0dns axi_araddr_out1 error", $time);
        if (axi_arlen_out1 != 0)
            $display("@%0dns axi_arlen_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 1)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Wait_port_valid / Reader 1 priority
        axi_arready_in <= 0;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        rd_info_valid_2_in <= 0;
        #9;

        for (i = 0; i < 5; i = i + 1) begin
            // Wait_port_valid
            if (axi_arvalid_out1 != 0)
                $display("@%0dns axi_ar_valid_out1 error", $time);
            if (axi_rready_out1 != 0)
                $display("@%0dns axi_rready_out1 error", $time);
            if (rd_info_rdy_0_out1 != 0)
                $display("@%0dns rd_info_rdy_0_out1 error", $time);
            if (rd_info_rdy_1_out1 != 0)
                $display("@%0dns rd_info_rdy_1_out1 error", $time);
            if (rd_info_rdy_2_out1 != 0)
                $display("@%0dns rd_info_rdy_2_out1 error", $time);
            if (rd_info_rdy_3_out1 != 0)
                $display("@%0dns rd_info_rdy_3_out1 error", $time);
            if (rd_data_valid_0_out1 != 0)
                $display("@%0dns rd_data_valid_0_out1 error", $time);
            if (rd_data_valid_1_out1 != 0)
                $display("@%0dns rd_data_valid_1_out1 error", $time);
            if (rd_data_valid_2_out1 != 0)
                $display("@%0dns rd_data_valid_2_out1 error", $time);
            if (rd_data_valid_3_out1 != 0)
                $display("@%0dns rd_data_valid_3_out1 error", $time);
            #10;
        end

        // Reader 0 data valid
        axi_rvalid_in <= 1;
        axi_rid_in <= 8'b00000001;
        axi_rdata_in <= 1234;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 1)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_0_out1 != 1234)
            $display("@%0dns rd_data_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Acknowledge reader 0 data
        rd_data_rdy_0_in <= 1;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 1)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 1)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_0_out1 != 1234)
            $display("@%0dns rd_data_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;
        
        // Wait read data valid
        axi_rvalid_in <= 0;
        rd_data_rdy_0_in <= 0;
        #1; 
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Reader 1 data valid
        axi_rvalid_in <= 1;
        axi_rid_in <= 8'b01000011;
        axi_rdata_in <= 5678;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 1)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_1_out1 != 5678)
            $display("@%0dns rd_data_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        for (i = 0; i < 2; i = i + 1) begin
            // Wait reader 1 data rdy
            if (axi_arvalid_out1 != 0)
                $display("@%0dns axi_ar_valid_out1 error", $time);
            if (axi_rready_out1 != 0)
                $display("@%0dns axi_rready_out1 error", $time);
            if (rd_info_rdy_0_out1 != 0)
                $display("@%0dns rd_info_rdy_0_out1 error", $time);
            if (rd_info_rdy_1_out1 != 0)
                $display("@%0dns rd_info_rdy_1_out1 error", $time);
            if (rd_info_rdy_2_out1 != 0)
                $display("@%0dns rd_info_rdy_2_out1 error", $time);
            if (rd_info_rdy_3_out1 != 0)
                $display("@%0dns rd_info_rdy_3_out1 error", $time);
            if (rd_data_valid_0_out1 != 0)
                $display("@%0dns rd_data_valid_0_out1 error", $time);
            if (rd_data_valid_1_out1 != 1)
                $display("@%0dns rd_data_valid_1_out1 error", $time);
            if (rd_data_1_out1 != 5678)
                $display("@%0dns rd_data_1_out1 error", $time);
            if (rd_data_valid_2_out1 != 0)
                $display("@%0dns rd_data_valid_2_out1 error", $time);
            if (rd_data_valid_3_out1 != 0)
                $display("@%0dns rd_data_valid_3_out1 error", $time);
            #10;
        end

        // Acknowledge reader 1 data
        rd_data_rdy_1_in <= 1;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 1)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 1)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_1_out1 != 5678)
            $display("@%0dns rd_data_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Reader 0 data valid
        axi_rvalid_in <= 1;
        axi_rid_in <= 8'b00000010;
        axi_rdata_in <= 9012;
        rd_data_rdy_1_in <= 0;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 1)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_0_out1 != 9012)
            $display("@%0dns rd_data_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Acknowledge reader 0 data
        rd_data_rdy_0_in <= 1;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 1)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 1)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_0_out1 != 9012)
            $display("@%0dns rd_data_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Wait read data valid
        axi_rvalid_in <= 0;
        rd_data_rdy_0_in <= 0;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;
 
        // Reader 3 data valid
        axi_rvalid_in <= 1;
        axi_rid_in <= 8'b11111001;
        axi_rdata_in <= 3456;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 1)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        if (rd_data_3_out1 != 3456)
            $display("@%0dns rd_data_3_out1 error", $time);
        #9;

        // Acknowledge reader 3 data
        rd_data_rdy_3_in <= 1;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 1)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 1)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        if (rd_data_3_out1 != 3456)
            $display("@%0dns rd_data_3_out1 error", $time);
        #9;

        // Wait read data valid
        axi_rvalid_in <= 0;
        rd_data_rdy_3_in <= 0;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Reader 2 data valid
        axi_rvalid_in <= 1;
        axi_rid_in <= 8'b10100001;
        axi_rdata_in <= 7890;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 1)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_2_out1 != 7890)
            $display("@%0dns rd_data_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Acknowledge reader 2 data
        rd_data_rdy_2_in <= 1;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 1)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 1)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_2_out1 != 7890)
            $display("@%0dns rd_data_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Wait read data valid
        axi_rvalid_in <= 0;
        rd_data_rdy_2_in <= 0;
        #1;
        if (axi_arvalid_out1 != 0)
            $display("@%0dns axi_ar_valid_out1 error", $time);
        if (axi_rready_out1 != 0)
            $display("@%0dns axi_rready_out1 error", $time);
        if (rd_info_rdy_0_out1 != 0)
            $display("@%0dns rd_info_rdy_0_out1 error", $time);
        if (rd_info_rdy_1_out1 != 0)
            $display("@%0dns rd_info_rdy_1_out1 error", $time);
        if (rd_info_rdy_2_out1 != 0)
            $display("@%0dns rd_info_rdy_2_out1 error", $time);
        if (rd_info_rdy_3_out1 != 0)
            $display("@%0dns rd_info_rdy_3_out1 error", $time);
        if (rd_data_valid_0_out1 != 0)
            $display("@%0dns rd_data_valid_0_out1 error", $time);
        if (rd_data_valid_1_out1 != 0)
            $display("@%0dns rd_data_valid_1_out1 error", $time);
        if (rd_data_valid_2_out1 != 0)
            $display("@%0dns rd_data_valid_2_out1 error", $time);
        if (rd_data_valid_3_out1 != 0)
            $display("@%0dns rd_data_valid_3_out1 error", $time);
        #9;

        // Re-initialize inputs for uut2
        rst <= 1;
        axi_arready_in <= 0;
        axi_rid_in <= 0;
        axi_rvalid_in <= 0;
        axi_rdata_in <= 0;
        active_ports_in2 <= 4'b0011;
        rd_id_0_in <= 0;
        rd_addr_0_in <= 0;
        rd_len_0_in <= 0;
        rd_info_valid_0_in <= 0;
        rd_data_rdy_0_in <= 0;
        rd_id_1_in <= 0;
        rd_addr_1_in <= 0;
        rd_len_1_in <= 0;
        rd_info_valid_1_in <= 0;
        rd_data_rdy_1_in <= 0;
        rd_id_2_in <= 0;
        rd_addr_2_in <= 0;
        rd_len_2_in <= 0;
        rd_info_valid_2_in <= 0;
        rd_data_rdy_2_in <= 0;
        rd_id_3_in <= 0;
        rd_addr_3_in <= 0;
        rd_len_3_in <= 0;
        rd_info_valid_3_in <= 0;
        rd_data_rdy_3_in <= 0;
        #20;
        rst <= 0;

        // Wait_port_valid / Reader 0 priority
        if (axi_arvalid_out2 != 0)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time);
        rd_id_0_in <= 6'b000001;
        rd_addr_0_in <= 10;
        rd_len_0_in <= 0;
        rd_info_valid_0_in <= 1;
        rd_id_1_in <= 6'b000011;
        rd_addr_1_in <= 20;
        rd_len_1_in <= 0;
        rd_info_valid_1_in <= 1;
        #10;

        // Connect_port / Reader 0 serviced
        if (axi_arvalid_out2 != 1)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_arid_out2 != 8'b00000001)
            $display("@%0dns axi_arid_out2 error", $time);
        if (axi_araddr_out2 != 10)
            $display("@%0dns axi_araddr_out2 error", $time);
        if (axi_arlen_out2 != 0)
            $display("@%0dns axi_arlen_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time);        
        #10;

        // Wait_axi_rdy / Reader 0 serviced
        axi_arready_in <= 1;
        #1;
        if (axi_arvalid_out2 != 1)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_arid_out2 != 8'b00000001)
            $display("@%0dns axi_arid_out2 error", $time);
        if (axi_araddr_out2 != 10)
            $display("@%0dns axi_araddr_out2 error", $time);
        if (axi_arlen_out2 != 0)
            $display("@%0dns axi_arlen_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 1)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time); 
        #9;

        // Wait_port_valid / Reader 1 priority
        axi_arready_in <= 0;
        #1; 
        if (axi_arvalid_out2 != 0)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time);
        #9;

        // Connect_port / Reader 1 serviced
        if (axi_arvalid_out2 != 1)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_arid_out2 != 8'b01000011)
            $display("@%0dns axi_arid_out2 error", $time);
        if (axi_araddr_out2 != 20)
            $display("@%0dns axi_araddr_out2 error", $time);
        if (axi_arlen_out2 != 0)
            $display("@%0dns axi_arlen_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time);        
        #10;

        // Wait_axi_rdy / Reader 1 serviced
        axi_arready_in <= 1;
        #1;
        if (axi_arvalid_out2 != 1)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_arid_out2 != 8'b01000011)
            $display("@%0dns axi_arid_out2 error", $time);
        if (axi_araddr_out2 != 20)
            $display("@%0dns axi_araddr_out2 error", $time);
        if (axi_arlen_out2 != 0)
            $display("@%0dns axi_arlen_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 1)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time); 
        #9;

        // Wait_port_valid / Reader 0 priority
        axi_arready_in <= 0;
        #1; 
        if (axi_arvalid_out2 != 0)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time);
        #9;


        // Connect_port / Reader 0 serviced
        if (axi_arvalid_out2 != 1)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_arid_out2 != 8'b00000001)
            $display("@%0dns axi_arid_out2 error", $time);
        if (axi_araddr_out2 != 10)
            $display("@%0dns axi_araddr_out2 error", $time);
        if (axi_arlen_out2 != 0)
            $display("@%0dns axi_arlen_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time);        
        #10;

        // Wait_axi_rdy / Reader 0 serviced
        axi_arready_in <= 1;
        #1;
        if (axi_arvalid_out2 != 1)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_arid_out2 != 8'b00000001)
            $display("@%0dns axi_arid_out2 error", $time);
        if (axi_araddr_out2 != 10)
            $display("@%0dns axi_araddr_out2 error", $time);
        if (axi_arlen_out2 != 0)
            $display("@%0dns axi_arlen_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 1)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time); 
        #9;

        // Wait_port_valid / Reader 1 priority
        axi_arready_in <= 0;
        rd_info_valid_0_in <= 0;
        #1; 
        if (axi_arvalid_out2 != 0)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time);
        #9;

        // Connect_port / Reader 1 serviced
        if (axi_arvalid_out2 != 1)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_arid_out2 != 8'b01000011)
            $display("@%0dns axi_arid_out2 error", $time);
        if (axi_araddr_out2 != 20)
            $display("@%0dns axi_araddr_out2 error", $time);
        if (axi_arlen_out2 != 0)
            $display("@%0dns axi_arlen_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time);        
        #10;

        // Wait_axi_rdy / Reader 1 serviced
        axi_arready_in <= 1;
        #1;
        if (axi_arvalid_out2 != 1)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_arid_out2 != 8'b01000011)
            $display("@%0dns axi_arid_out2 error", $time);
        if (axi_araddr_out2 != 20)
            $display("@%0dns axi_araddr_out2 error", $time);
        if (axi_arlen_out2 != 0)
            $display("@%0dns axi_arlen_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 1)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time); 
        #9;

        // Wait_port_valid / Reader 0 priority
        axi_arready_in <= 0;
        rd_info_valid_1_in <= 0;
        #1; 
        if (axi_arvalid_out2 != 0)
            $display("@%0dns axi_ar_valid_out2 error", $time);
        if (axi_rready_out2 != 0)
            $display("@%0dns axi_rready_out2 error", $time);
        if (rd_info_rdy_0_out2 != 0)
            $display("@%0dns rd_info_rdy_0_out2 error", $time);
        if (rd_info_rdy_1_out2 != 0)
            $display("@%0dns rd_info_rdy_1_out2 error", $time);
        if (rd_info_rdy_2_out2 != 0)
            $display("@%0dns rd_info_rdy_2_out2 error", $time);
        if (rd_info_rdy_3_out2 != 0)
            $display("@%0dns rd_info_rdy_3_out2 error", $time);
        if (rd_data_valid_0_out2 != 0)
            $display("@%0dns rd_data_valid_0_out2 error", $time);
        if (rd_data_valid_1_out2 != 0)
            $display("@%0dns rd_data_valid_1_out2 error", $time);
        if (rd_data_valid_2_out2 != 0)
            $display("@%0dns rd_data_valid_2_out2 error", $time);
        if (rd_data_valid_3_out2 != 0)
            $display("@%0dns rd_data_valid_3_out2 error", $time);
        #9;


        // Wait 100 ns
        #100;
        $display("Tests complete!");
        $finish;

    end
    
    always begin
        #5 clk = !clk;
    end
    
endmodule

