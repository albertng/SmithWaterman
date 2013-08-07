// SystemMonitor32.v
// Exposes the raw system monitor values for internal voltage, auxiliary voltage, and temperature.
// Calculate the "real" values from the raw values as follows:
//     Voltage = (RAW_VALUE / 1024) * 3
//     Degrees Celsius = RAW_VALUE * 503.975 / 1024 - 273.15

// The system monitor is placed in auto-sequence mode so it continuously samples all the sensors we want.
// We just need to watch the end-of-channel (eoc) flag to know when to grab data. When that goes high, we send the
// channel number to the address port. A few cycles later, the data shows up and drdy goes high, at which point we latch it.

`include "PicoDefines.v"

module SystemMonitor32 (
    /* PicoBus ports */
    input              PicoRst,
    input              PicoClk,
    input      [31:0]  PicoAddr,
    input      [31:0] PicoDataIn,
    output reg [31:0] PicoDataOut,
    input              PicoRd,
    input              PicoWr,
    output reg [9:0]   temp
);

reg [9:0] Vccint, Vccaux, Vp;
wire [15:0] dobus;
wire [4:0] channel;
wire eoc, drdy;

// dclk can be 8-250MHz. the internal sysmon clk can be 1-5.2MHz.
// bits 8-15 of INIT_42 specify the divisor. we'll slow down dclk to ease timing
//   and then we'll adjust the divisor to give us a valid internal clk.
// the e17 PicoClk is 62.5MHz and the m501 is 250MHz.
reg [5:0] PicoClkCnt;
always @(posedge PicoClk) PicoClkCnt <= PicoClkCnt + 1;
wire dclk = PicoClkCnt[5];

always @(posedge PicoClk)
    if (PicoRd & (PicoAddr[31:0] == (`SYSTEM_MONITOR_ADDR+4)))
        PicoDataOut[31:0] <= {6'h0, Vp[9:0],
                              6'h0, Vccaux[9:0]};
    else if (PicoRd & (PicoAddr[31:0] == (`SYSTEM_MONITOR_ADDR)))
        PicoDataOut[31:0] <= {6'h0, Vccint[9:0],
                              6'h0, temp[9:0]};
    else
        PicoDataOut[31:0] <= 32'h0;

always @(posedge dclk) begin
    if (drdy) begin
        if (channel[4:0] == 5'h0) temp <= dobus[15:6];
        if (channel[4:0] == 5'h1) Vccint <= dobus[15:6];
        if (channel[4:0] == 5'h2) Vccaux <= dobus[15:6];
        if (channel[4:0] == 5'h3) Vp <= dobus[15:6];
    end
end

// instantiation based on example from the V5 user guide.
SYSMON #(
    .INIT_40(16'h3000), // Configuration register 0 (0x3000 means average 256 samples)
    .INIT_41(16'h20FE), // Configuration register 1 (low bit disable overtemp shutdown)
    .INIT_42(16'h0200), // Configuration register 2
    .INIT_43(16'h0), // Test register 0
    .INIT_44(16'h0), // Test register 1
    .INIT_45(16'h0), // Test register 2
    .INIT_46(16'h0), // Test register 3
    .INIT_47(16'h0), // Test register 4
    .INIT_48(16'h0F01), // Sequence register 0
    .INIT_49(16'h0), // Sequence register 1
    .INIT_4A(16'h0), // Sequence register 2
    .INIT_4B(16'h0), // Sequence register 3
    .INIT_4C(16'h0), // Sequence register 4
    .INIT_4D(16'h0), // Sequence register 5
    .INIT_4E(16'h0), // Sequence register 6
    .INIT_4F(16'h0), // Sequence register 7
    .INIT_50(16'h0), // Alarm limit register 0
    .INIT_51(16'h0), // Alarm limit register 1
    .INIT_52(16'h0), // Alarm limit register 2
    .INIT_53(16'hB883), // Alarm limit register 3 0xB88X = 90 Celcius
    .INIT_54(16'h0), // Alarm limit register 4
    .INIT_55(16'h0), // Alarm limit register 5
    .INIT_56(16'h0), // Alarm limit register 6
    .INIT_57(16'h0)  // Alarm limit register 7
) my_sysmon (
    .BUSY(busy), // 1-bit output ADC busy signal
    .CHANNEL(channel), // 5-bit output channel selection
    .DO(dobus[15:0]), // 16-bit output data bus for dynamic reconfig port
    .EOC(eoc),
    .DRDY(drdy),
    .DADDR({2'b0, channel}),// 7-bit input address bus for dynamic reconfig
    .DCLK(dclk), // 1-bit input clock for dynamic reconfig port
    .DEN(eoc), // 1-bit input enable for dynamic reconfig port
    .DWE(1'b0), // 1-bit input write enable for dynamic reconfig port
    .RESET(1'b0) // 1-bit input active high reset
);

endmodule
