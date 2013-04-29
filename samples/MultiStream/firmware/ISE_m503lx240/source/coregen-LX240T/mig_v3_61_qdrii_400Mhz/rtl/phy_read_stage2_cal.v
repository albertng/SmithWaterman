//*****************************************************************************
//(c) Copyright 2009 - 2010 Xilinx, Inc. All rights reserved.
//
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
//
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
//
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
//
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.

////////////////////////////////////////////////////////////////////////////////
//   ____  ____
//  /   /\/   /
// /___/  \  /    Vendor             : Xilinx
// \   \   \/     Version            : 3.6.1 
//  \   \         Application        : MIG
//  /   /         Filename           : phy_read_stage2_cal.v
// /___/   /\     Date Last Modified    : $date$          
// \   \  /  \    Date Created          : Nov 10 2008 
//  \___\/\___\
//
//Device: Virtex-6
//Design: QDRII+ / RLDRAM-II
//
//Purpose:
//  This module
//  1. Sets the latency for fixed latency mode.
//  2. Matches latency across multiple memories.
//  3. Determines the amount of latency delay required to generate the valids.
//
//Revision History:
//
////////////////////////////////////////////////////////////////////////////////

`timescale 1ps/1ps

module phy_read_stage2_cal #
(
  parameter BURST_LEN           = 4,  // Burst Length
  parameter DATA_WIDTH          = 72, // Total data width across all memories
  parameter NUM_DEVICES         = 2,  // Number of memory devices
  parameter MEMORY_WIDTH        = 36, // Width of each memory
  parameter FIXED_LATENCY_MODE  = 0,  // 0 = minimum latency mode, 1 = fixed latency mode
  parameter PHY_LATENCY         = 16, // Indicates the desired latency for fixed latency mode
  parameter TCQ                 = 100 // Register delay
)
(
  // System Signals
  input                         clk,                // main system half freq clk
  input                         rst_clk,            // reset syncrhonized to clk

  // Stage 1 Calibration Interface
  input                         cal_stage2_start,   // indicates latency calibration can begin

  // Write Interface
  input       [1:0]             int_rd_cmd_n,       // read command(s) - only bit 0 is used for BL4

  // DCB Interface
  input       [DATA_WIDTH*4-1:0]  read_data,        // read data from DCB
  output reg  [NUM_DEVICES-1:0] inc_latency = 0,    // indicates latency through a DCB to be increased
  
  // Valid Generator Interface
  output reg  [4:0]             valid_latency,      // amount to delay read command

  // User Interface
  output reg                    cal_done,           // indicates overall calibration is complete
  
  // Phase Detector
  input       [NUM_DEVICES-1:0] pd_calib_done,      // indicates phase detector calibration is complete
  output reg                    cal_stage2_done,    // indicates stage 2 calibration is complete
  
  // Chipscope/Debug and Error
  output reg  [NUM_DEVICES-1:0] error_max_latency,  // mem_latency counter has maxed out
  output reg                    error_adj_latency,  // target PHY_LATENCY is invalid
  output      [127:0]           dbg_stage2_cal      // general debug port
);

  // Localparams
  localparam [DATA_WIDTH*4-1:0] LAT_CAL_DATA = {DATA_WIDTH{4'hA}}; // Data read back for latency calibration

  // Wires and Regs
  wire                  bl8_rd_cmd_int;                 // inidicates any BL8 rd_cmd
  wire                  bl4_rd_cmd_int;                 // inidicates any BL4 rd_cmd
  wire                  bl2_rd_cmd_int;                 // indicates any BL2 rd_cmd
  reg                   bl8_rd_cmd_int_r;               // delayed version of bl8_rd_cmd_int
  reg                   bl8_rd_cmd_int_r2;              // delayed version of bl8_rd_cmd_r
  reg                   bl4_rd_cmd_int_r;               // delayed version of bl4_rd_cmd_int
  reg                   bl2_rd_cmd_int_r;               // delayed version of bl2_rd_cmd_int
  wire                  rd_cmd;                         // indicates rd_cmd for latency calibration
  wire                  lat_measure_done;               // indicates latency measurement is complete
  wire                  en_mem_cntr;                    // memory counter enable
  wire                  start_lat_adj;                  // indicates that latency adjustment can begin
  reg                   en_mem_latency;                 // memory latency counter enable
  reg [4:0]             latency_cntr [NUM_DEVICES-1:0]; // counter indicating the latency for each memory in the inteface
  wire [DATA_WIDTH-1:0] rd0;                            // rising data 0 for all memories
  wire [DATA_WIDTH-1:0] fd0;                            // falling data 0 for all memories
  wire [DATA_WIDTH-1:0] rd1;                            // rising data 1 for all memories
  wire [DATA_WIDTH-1:0] fd1;                            // falling data 1 for all memories
  wire [DATA_WIDTH-1:0] rd0_lat;                        // rising data 0 latency cal training pattern
  wire [DATA_WIDTH-1:0] fd0_lat;                        // falling data 0 latency cal training pattern
  wire [DATA_WIDTH-1:0] rd1_lat;                        // rising data 1 latency cal training pattern
  wire [DATA_WIDTH-1:0] fd1_lat;                        // falling data 1 latency cal training pattern
  wire [NUM_DEVICES-1:0] rd0_vld;                       // indicates rd0 matches respective training pattern
  wire [NUM_DEVICES-1:0] fd0_vld;                       // indicates fd0 matches respective training pattern
  wire [NUM_DEVICES-1:0] rd1_vld;                       // indicates rd1 matches respective training pattern
  wire [NUM_DEVICES-1:0] fd1_vld;                       // indicates fd1 matches respective training pattern
  reg [4:0]             mem_latency  [NUM_DEVICES-1:0]; // register indicating the measured latency for each memory
  reg [NUM_DEVICES-1:0] latency_measured;               // indicates that the latency has been measured for each memory
  reg [4:0]             mem_cntr;                       // indicates which memory is being operated on
  reg                   mem_cntr_done;                  // indicates mem_cntr has cycled through all memories
  reg [4:0]             max_latency;                    // maximum measured latency  
  reg                   max_lat_done;                   // indicates maximum latency measurement is done
  reg                   max_lat_done_r;                 // delayed version of max_lat_done
  reg [4:0]             mem_lat_adj [NUM_DEVICES-1:0];  // amount latency needs incremented
  reg [NUM_DEVICES-1:0] lat_adj_done;                   // indicates latency adjustment is done

  // Create rd_cmd for BL8, BL4 and BL2. BL8/BL4 only uses one bit for incoming
  // rd_cmd's. Since this stage of calibration can't start until stage 1 is
  // complete, mask off all incoming rd_cmd's until stage 2 begins. There can
  // be rd_cmd's from the stage 1 calibration just after stage 2 starts. These
  // will be masked off by looking for the rising edge of rd_cmd.
  
  assign bl8_rd_cmd_int = (BURST_LEN == 8) && (int_rd_cmd_n == 2'b10); 
  assign bl4_rd_cmd_int = (BURST_LEN == 4) && (int_rd_cmd_n == 2'b10); 
  assign bl2_rd_cmd_int = (BURST_LEN == 2) && (int_rd_cmd_n == 2'b00);

  always @(posedge clk) begin
    if (rst_clk) begin
      bl8_rd_cmd_int_r  <= #TCQ 0;
      bl8_rd_cmd_int_r2 <= #TCQ 0;
    end else begin
      bl8_rd_cmd_int_r  <= #TCQ bl8_rd_cmd_int;
      bl8_rd_cmd_int_r2 <= #TCQ bl8_rd_cmd_int_r;
    end
  end

  always @(posedge clk) begin
    if (rst_clk)
      bl4_rd_cmd_int_r <= #TCQ 0;
    else
      bl4_rd_cmd_int_r <= #TCQ bl4_rd_cmd_int;
  end

  always @(posedge clk) begin
      if (rst_clk)
        bl2_rd_cmd_int_r <= #TCQ 0;
      else
        bl2_rd_cmd_int_r <= #TCQ bl2_rd_cmd_int;
  end
  
  //generate the rd_cmd flag
  generate
    if (BURST_LEN == 8) begin: BL8_RD_CMD
      assign rd_cmd = bl8_rd_cmd_int && !bl8_rd_cmd_int_r &&
                     !bl8_rd_cmd_int_r2 && cal_stage2_start && !cal_done;
    end else if (BURST_LEN == 4) begin : BL4_RD_CMD
      assign rd_cmd = bl4_rd_cmd_int && !bl4_rd_cmd_int_r && 
                      cal_stage2_start && !cal_done;
    end else if (BURST_LEN == 2) begin : BL2_RD_CMD
      assign rd_cmd = bl2_rd_cmd_int && !bl2_rd_cmd_int_r && 
                      cal_stage2_start && !cal_done;
    end
  endgenerate

  // Create an enable for the latency counter. Enable it whenver the
  // appropriate rd_cmd is seen from the initialization logic in the write
  // interface. Since only one rd_cmd is issued during this phase, it can
  // remain enabled after asserted for the first time.
  always @(posedge clk) begin
    if (rst_clk)
      en_mem_latency <= #TCQ 0;
    else if (cal_stage2_done)    
      en_mem_latency <= #TCQ 0;
    else if (rd_cmd)
      en_mem_latency <= #TCQ 1;
  end

  // For each memory in the interface, determine the latency from the time the
  // rd_cmd is issued until the expected read back data is received. This
  // determines the latency of the system.
  genvar nd_i;
  generate
    for (nd_i=0; nd_i < NUM_DEVICES; nd_i=nd_i+1) begin : mem_lat_inst

      // Count the number of cycles from the time that the rd_cmd is seen. This
      // will be used to determine how long for the read data to be returned and
      // hence the read latency. If latency_cntr counter maxes out, issue an 
      // error. This is either because the latency of the read is higher than 
      // the design can handle or because the latency calibration readback data 
      // of AA's was never correctly received. The latency counter begins 
      // counting from 1 since there is an additional cycle of latency in the 
      // read path not accounted for by this read command from the 
      // initialization logic.
      always @(posedge clk) begin
        if (rst_clk) begin
          latency_cntr[nd_i]      <= #TCQ 1;
          error_max_latency[nd_i] <= #TCQ 0;
        end else if (latency_cntr[nd_i] == 5'h1F) begin
          latency_cntr[nd_i]      <= #TCQ 5'h1F;
          if (!latency_measured[nd_i])
            error_max_latency[nd_i] <= #TCQ 1;
          else
            error_max_latency[nd_i] <= #TCQ 0;
        end else if (en_mem_latency || rd_cmd) begin
          latency_cntr[nd_i]      <= #TCQ latency_cntr[nd_i] + 1'b1;  
          error_max_latency[nd_i] <= #TCQ 0;
        end
      end

      // Break apart the read_data bus into the various rising and falling data
      // groups for each memory. The read_data bus is constructed as follows:
      // read_data = {rd0, fd0, rd1, fd1}
      // rd0 = {rd0[n], ..., rd0[1], rd0[0]}
      // fd0 = {fd0[n], ..., fd0[1], fd0[0]}
      // rd1 = {rd1[n], ..., rd1[1], rd1[0]}
      // fd1 = {fd1[n], ..., fd1[1], fd1[0]}
      assign rd0[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] =
             read_data[(nd_i*MEMORY_WIDTH+MEMORY_WIDTH*NUM_DEVICES*3)+:MEMORY_WIDTH];
      assign fd0[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] =
             read_data[(nd_i*MEMORY_WIDTH+MEMORY_WIDTH*NUM_DEVICES*2)+:MEMORY_WIDTH];
      assign rd1[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] =
             read_data[(nd_i*MEMORY_WIDTH+MEMORY_WIDTH*NUM_DEVICES*1)+:MEMORY_WIDTH];
      assign fd1[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] =
             read_data[(nd_i*MEMORY_WIDTH+MEMORY_WIDTH*NUM_DEVICES*0)+:MEMORY_WIDTH];

      // Pull off the respective LAT_CAL_DATA for each group of data.
      assign rd0_lat[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] = 
             LAT_CAL_DATA[(nd_i*MEMORY_WIDTH+MEMORY_WIDTH*NUM_DEVICES*3)+:MEMORY_WIDTH];
      assign fd0_lat[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] = 
             LAT_CAL_DATA[(nd_i*MEMORY_WIDTH+MEMORY_WIDTH*NUM_DEVICES*2)+:MEMORY_WIDTH];
      assign rd1_lat[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] =
             LAT_CAL_DATA[(nd_i*MEMORY_WIDTH+MEMORY_WIDTH*NUM_DEVICES*1)+:MEMORY_WIDTH];
      assign fd1_lat[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] =
             LAT_CAL_DATA[(nd_i*MEMORY_WIDTH+MEMORY_WIDTH*NUM_DEVICES*0)+:MEMORY_WIDTH];

      // Indicate if the data for each memory matches the respective
      // LAT_CAL_DATA.
      assign rd0_vld[nd_i] = (rd0[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] ==
                              rd0_lat[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH]);
      assign fd0_vld[nd_i] = (fd0[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] ==
                              fd0_lat[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH]);
      assign rd1_vld[nd_i] = (rd1[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] ==
                              rd1_lat[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH]);
      assign fd1_vld[nd_i] = (fd1[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH] ==
                              fd1_lat[nd_i*MEMORY_WIDTH+:MEMORY_WIDTH]);

      // Capture the current latency count when the received data
      // (LAT_CAL_DATA) is seen. Also indicate that the latency has been
      // measured for this memory.
      always @(posedge clk) begin
        if (rst_clk) begin
          mem_latency[nd_i]       <= #TCQ 0;
          latency_measured[nd_i]  <= #TCQ 0;
        end else if (en_mem_latency && rd0_vld[nd_i] && fd0_vld[nd_i] &&
                     rd1_vld[nd_i] && fd1_vld[nd_i]) begin
          mem_latency[nd_i]       <= #TCQ latency_cntr[nd_i];
          latency_measured[nd_i]  <= #TCQ 1;
        end
      end

    end
  endgenerate

  // Determine the maximum latency
  generate
    if (NUM_DEVICES == 1) begin : max_lat_inst_dev1

      // With only one device, the maximum latency of the system is simply the
      // the latency determined previously.
      always @(posedge clk) begin
        if (rst_clk)
          max_latency <= #TCQ 0;
        else if (latency_measured[0])
          max_latency <= #TCQ mem_latency[0];
      end

      always @(posedge clk) begin
        if (rst_clk)
          max_lat_done <= #TCQ 0;
        else if (latency_measured[0])
          max_lat_done <= #TCQ 1;
      end
      
    end else begin : max_lat_inst

      assign lat_measure_done = &latency_measured;
      assign en_mem_cntr  = (lat_measure_done && !mem_cntr_done);

      // Counter that cycles through each memory which will be used to determine
      // the largest latency in the system. It only starts counting after the 
      // latency has been measured for each device. Also indicates when all
      //  devices have been cycled through.
      always @(posedge clk) begin
        if (rst_clk) begin
          mem_cntr      <= #TCQ 0;
          mem_cntr_done <= #TCQ 0;
        end else if ((mem_cntr == (NUM_DEVICES - 1)) && lat_measure_done 
                      && !mem_cntr_done) begin
          mem_cntr      <= #TCQ mem_cntr;
          mem_cntr_done <= #TCQ 1;
        end else if (en_mem_cntr) begin
          mem_cntr      <= #TCQ mem_cntr + 1'b1;  
          mem_cntr_done <= #TCQ mem_cntr_done;
        end
      end

      // As the counter for each memory device increments, the latency of that
      // device is compared against the value in the max_latency register. If it
      // is larger than the stored value, it replaces the max_latency value.
      //  This repeats for each device until the maximum latency is found.
      always @(posedge clk) begin
        if (rst_clk) begin
          max_latency <= #TCQ 0;
        end else if ((mem_latency[mem_cntr] > max_latency) 
                      && !mem_cntr_done) begin
          max_latency <= #TCQ mem_latency[mem_cntr];
        end
      end

      // Indicate when maximum latency measurement is complete.
      always @(posedge clk) begin
        if (rst_clk)
          max_lat_done <= #TCQ 0;
        else
          max_lat_done <= #TCQ mem_cntr_done;
      end

    end
  endgenerate

  // Adjust the latency. For FIXED_LATENCY_MODE=1, the latency of each memory
  // must be increased to the target PHY_LATENCY value. For
  // FIXED_LATENCY_MODE=0, the latency of each memory is increased to the max
  // latency of any of the memories.
  genvar nd_j;
  generate
    if ((NUM_DEVICES > 1) || (FIXED_LATENCY_MODE == 1)) begin : adj_lat_inst

      // Determine when max_lat_done is first asserted. This will be used to
      // initiate the latency adjustment sequence.
      always @(posedge clk) begin
        if (rst_clk)
          max_lat_done_r <= #TCQ 0;
        else
          max_lat_done_r <= #TCQ max_lat_done;
      end

      assign start_lat_adj = max_lat_done && !max_lat_done_r;


      for (nd_j=0; nd_j < NUM_DEVICES; nd_j=nd_j+1) begin : inc_lat_inst

        // Adjust the latency as required for each memory. For
        // FIXED_LATENCY_MODE=0, the latency for each memory must be adjusted
        // to the maximum latency previously found within the system. For
        // FIXED_LATENCY_MODE=1, the latency for every memory will be adjusted
        // to the latency determined by the PHY_LATENCY parameter. Latency
        // adjustments are made by asserting the inc_latency signal
        // independently for each memory. For every cycle inc_latency is
        // asserted, the latency will be increased by one.
        always @(posedge clk) begin
          if (rst_clk) begin
            inc_latency[nd_j]   <= #TCQ 0;
            mem_lat_adj[nd_j]   <= #TCQ 0;
            lat_adj_done[nd_j]  <= #TCQ 0;
          end else if (start_lat_adj) begin
            if (FIXED_LATENCY_MODE == 0) begin
              inc_latency[nd_j]   <= #TCQ 0;
              mem_lat_adj[nd_j]   <= #TCQ max_latency - mem_latency[nd_j];
              lat_adj_done[nd_j]  <= #TCQ 0;
            end else begin
              inc_latency[nd_j]   <= #TCQ 0;
              mem_lat_adj[nd_j]   <= #TCQ PHY_LATENCY - mem_latency[nd_j];
              lat_adj_done[nd_j]  <= #TCQ 0;
            end
          end else if (max_lat_done_r) begin
            if (mem_lat_adj[nd_j] == 0) begin
              inc_latency[nd_j]   <= #TCQ 0;
              mem_lat_adj[nd_j]   <= #TCQ 0;
              lat_adj_done[nd_j]  <= #TCQ 1;
            end else begin
              inc_latency[nd_j]   <= #TCQ |mem_lat_adj[nd_j];
              mem_lat_adj[nd_j]   <= #TCQ mem_lat_adj[nd_j] - 1'b1;
              lat_adj_done[nd_j]  <= #TCQ 0;
            end
          end
        end

      end

      // Issue an error if in FIXED_LATENCY_MODE=1 and the target PHY_LATENCY
      // is less than what the system can safely provide.
      always @(posedge clk) begin
        if (rst_clk)
          error_adj_latency <= #TCQ 0;
        else if ((FIXED_LATENCY_MODE == 1) && start_lat_adj) begin
          if (PHY_LATENCY < max_latency)
            error_adj_latency <= #TCQ 1;
        end
      end

      // Signal that stage 2 calibration is complete once the latencies have
      // been adjusted.
      always @(posedge clk) begin
        if (rst_clk)
          cal_stage2_done <= #TCQ 0;
        else
          cal_stage2_done <= #TCQ |lat_adj_done;
      end
      
    end else begin : adj_lat_inst_dev1

      // Since no latency adjustments are required for single memory interface
      // with FIXED_LATENCY_MODE=0, calibration can be signaled as soon as
      // max_lat_done is asserted
      always @(posedge clk) begin
        if (rst_clk)
          cal_stage2_done <= #TCQ 0;
        else
          cal_stage2_done <= #TCQ max_lat_done;
      end
    
      // Tie off error_adj_latency signal
      always @(posedge clk) begin
        error_adj_latency <= #TCQ 0;
      end
      
    end
  endgenerate

  // The final step is to indicate to the vld_gen logic how much to delay
  // incoming rd_cmd's by in order to align them with the read data. This
  // latency to the vld_gen logic is set to either the max_latency - 3
  // FIXED_LATENCY_MODE=0) or PHY_LATENCY - 3 (FIXED_LATENCY_MODE=1). The
  // minus 3 is to account for the extra cycles out of the vld_gen logic.
  always @(posedge clk) begin
    if (rst_clk)
      valid_latency <= #TCQ 0;
    else if (cal_stage2_done) 
      valid_latency <= #TCQ valid_latency;     
    else if (FIXED_LATENCY_MODE == 0)
      valid_latency <= #TCQ max_latency - 2'h3;
    else
      valid_latency <= #TCQ PHY_LATENCY - 2'h3;
  end

  // Indicate overall calibration is complete once stage 2 calibration is done
  // and each phase detector has completed calibration.
  always @(posedge clk) begin
    if (rst_clk)
      cal_done <= #TCQ 0;
    else
      cal_done <= #TCQ &pd_calib_done && cal_stage2_done;
  end

  // Assign debug signals
  assign dbg_stage2_cal[0]       = en_mem_latency;
  assign dbg_stage2_cal[5:1]     = latency_cntr[0];
  assign dbg_stage2_cal[6]       = rd_cmd;
  assign dbg_stage2_cal[7]       = latency_measured[0];
  assign dbg_stage2_cal[8]       = bl4_rd_cmd_int;
  assign dbg_stage2_cal[9]       = bl4_rd_cmd_int_r;
  assign dbg_stage2_cal[127:10]  = 'b0;

endmodule
