/*
* File Name : PicoMIG.v
*
* Creation Date : Fri 03 Aug 2012 12:45:47 PM PDT
*
* Author : Corey Olson
*
* Last Modified : Fri 02 Nov 2012 10:23:22 AM CDT
*
* Description : This model is meant to replace the MIG and the DDR3 simulation models in order to
*               speed up simulations.  
*               
*               This memory is implemented as a hash table of size 'NUM_BYTES' bytes.  NUM_BYTES
*               can be set by the user, but it must be a power of 2.  NUM_BYTES has been tested at
*               1kB and 1MB.
*
*               A second table (called the address table) holds the address and a valid bit for
*               each bucket of the data hash table.  A bucket of the data hash table contains
*               'DATA_ENTRIES_PER_ADDR' entries of data, where each entry is equal to the AXI data
*               width.  
*                
*               TODO:
*               1) enable more memory by backing the memories with files (mmap)
*
* Copyright 2011 Pico Computing, Inc.
*/
`include "PicoDefines.v"
module PicoMIG #(

    //***************************************************************************
    // The following parameter refers to the total number of bytes this memory should hold
    //***************************************************************************
    parameter NUM_BYTES             = (1<<20),  // total number of bytes this memory should hold
    parameter DATA_ENTRIES_PER_ADDR = 8,        // number of data table entries per entry of the
                                                //  address table (range = {1,2,4}) 


    //***************************************************************************
    // The following parameters refer to width of various ports
    //***************************************************************************
    parameter RANKS                 = 1,
                                      // # of Ranks.
    parameter BANK_WIDTH            = 3,
                                      // # of memory Bank Address bits.
    parameter ROW_WIDTH             = 15,
                                      // # of memory Row Address bits.
    parameter COL_WIDTH             = 10,
                                      // # of memory Column Address bits.
    parameter DQ_WIDTH              = 64,
                                     // # of DQ (data)

    //***************************************************************************
    // Simulation parameters
    //***************************************************************************
`ifdef SIMULATION
    parameter SIMULATION            = "TRUE",
                                      // Should be TRUE during design simulations and
                                      // FALSE during implementations
`else
    parameter SIMULATION            = "FALSE",
                                      // Should be TRUE during design simulations and
                                      // FALSE during implementations
`endif
    
    //***************************************************************************
    // AXI4 Shim parameters
    //***************************************************************************
    parameter C_S_AXI_ID_WIDTH              = 4,
                                              // Width of all master and slave ID signals.
                                              // # = >= 1.
    parameter C_S_AXI_ADDR_WIDTH            = 32,
                                              // Width of S_AXI_AWADDR, S_AXI_ARADDR, M_AXI_AWADDR and
                                              // M_AXI_ARADDR for all SI/MI slots.
                                              // # = 32.
    parameter C_S_AXI_DATA_WIDTH            = 256,
                                              // Width of WDATA and RDATA on SI slot.
                                              // Must be <= APP_DATA_WIDTH.
                                              // # = 32, 64, 128, 256.
    parameter RST_ACT_LOW                   = 0,
                                              // =1 for active low reset,
                                              // =0 for active high.
   
    //***************************************************************************
    // these are not used for anything
    //***************************************************************************
    parameter DQS_WIDTH             = 8,
    parameter CK_WIDTH              = 1,
                                     // # of CK/CK# outputs to memory.
    parameter CKE_WIDTH             = 1,
                                     // # of CKE outputs to memory.
    parameter CS_WIDTH              = 1,
                                     // # of unique CS outputs to memory.
    parameter DM_WIDTH              = 8,
                                     // # of DM (data mask)
    parameter ODT_WIDTH             = 1,
                                     // # of ODT outputs to memory.
    parameter nCS_PER_RANK          = 1,
                                     // # of unique CS outputs per rank for phy
    
    //***************************************************************************
    // DO NOT MODIFY BELOW THIS LINE
    //***************************************************************************
    parameter DATA_ENTRIES                  = NUM_BYTES / (C_S_AXI_DATA_WIDTH/8),
    parameter ADDR_ENTRIES                  = DATA_ENTRIES / DATA_ENTRIES_PER_ADDR
    )
  (

    // clock
`ifdef PICO_MODEL_M505
    input                                        extra_clk,  // 200 MHz clock that we will use as
                                                             //  the global clock for this MIG
`else
    input                                        sys_clk,
`endif
    
    // output a clock and a reset
    output                                       ui_clk,
    output reg                                   ui_clk_sync_rst=1,
    
    // DO NOT USE THESE 
    inout [DQ_WIDTH-1:0]                         ddr3_dq,
    inout [DQS_WIDTH-1:0]                        ddr3_dqs_n,
    inout [DQS_WIDTH-1:0]                        ddr3_dqs_p,
    output [ROW_WIDTH-1:0]                       ddr3_addr,
    output [BANK_WIDTH-1:0]                      ddr3_ba,
    output                                       ddr3_ras_n,
    output                                       ddr3_cas_n,
    output                                       ddr3_we_n,
    output                                       ddr3_reset_n,
    output [CK_WIDTH-1:0]                        ddr3_ck_p,
    output [CK_WIDTH-1:0]                        ddr3_ck_n,
    output [CKE_WIDTH-1:0]                       ddr3_cke,
    output [CS_WIDTH*nCS_PER_RANK-1:0]           ddr3_cs_n,
    output [DM_WIDTH-1:0]                        ddr3_dm,
    output [ODT_WIDTH-1:0]                       ddr3_odt,
    input                                        sys_clk_p,
    input                                        sys_clk_n,
    input                                        aresetn,
    input                                        app_sr_req,
    output                                       app_sr_active,
    input                                        app_ref_req,
    output                                       app_ref_ack,
    input                                        app_zq_req,
    output                                       app_zq_ack,
    input                                        scl,
    inout                                        sda,
    input                                        clk_ref,
    // END OF DO NOT USE THESE 

    // Slave Interface Write Address Ports
    input  [C_S_AXI_ID_WIDTH-1:0]                s_axi_awid,
    input  [C_S_AXI_ADDR_WIDTH-1:0]              s_axi_awaddr,
    input  [7:0]                                 s_axi_awlen,
    input  [2:0]                                 s_axi_awsize,
    input  [1:0]                                 s_axi_awburst,
    input  [0:0]                                 s_axi_awlock,
    input  [3:0]                                 s_axi_awcache,
    input  [2:0]                                 s_axi_awprot,
    input  [3:0]                                 s_axi_awqos,
    input                                        s_axi_awvalid,
    output reg                                   s_axi_awready,
    // Slave Interface Write Data Ports
    input  [C_S_AXI_DATA_WIDTH-1:0]              s_axi_wdata,
    input  [C_S_AXI_DATA_WIDTH/8-1:0]            s_axi_wstrb,
    input                                        s_axi_wlast,
    input                                        s_axi_wvalid,
    output reg                                   s_axi_wready,
    // Slave Interface Write Response Ports
    input                                        s_axi_bready,
    output [C_S_AXI_ID_WIDTH-1:0]                s_axi_bid,
    output [1:0]                                 s_axi_bresp,
    output reg                                   s_axi_bvalid,
    // Slave Interface Read Address Ports
    input  [C_S_AXI_ID_WIDTH-1:0]                s_axi_arid,
    input  [C_S_AXI_ADDR_WIDTH-1:0]              s_axi_araddr,
    input  [7:0]                                 s_axi_arlen,
    input  [2:0]                                 s_axi_arsize,
    input  [1:0]                                 s_axi_arburst,
    input  [0:0]                                 s_axi_arlock,
    input  [3:0]                                 s_axi_arcache,
    input  [2:0]                                 s_axi_arprot,
    input  [3:0]                                 s_axi_arqos,
    input                                        s_axi_arvalid,
    output reg                                   s_axi_arready,
    // Slave Interface Read Data Ports
    input                                        s_axi_rready,
    output [C_S_AXI_ID_WIDTH-1:0]                s_axi_rid,
    output reg [C_S_AXI_DATA_WIDTH-1:0]          s_axi_rdata,
    output [1:0]                                 s_axi_rresp,
    output reg                                   s_axi_rlast,
    output reg                                   s_axi_rvalid,

    // calibration complete signal
`ifdef PICO_MODEL_M505
    output                                       init_calib_complete,
`else
    output                                       phy_init_done,
`endif // PICO_MODEL_M505

    // System reset
    input                                        sys_rst
    );
    
    //////////////////////
    // internal signals //
    //////////////////////
    wire sys_rst_act_hi;
    reg sys_rst_q=1;
    wire ui_rst;   // active high reset synchronous to the ui_clk
    reg calib_complete=0;

    ///////////
    // logic //
    ///////////
    assign  sys_rst_act_hi = RST_ACT_LOW ? ~sys_rst: sys_rst;
`ifdef PICO_MODEL_M505
    assign ui_clk = extra_clk;
    assign init_calib_complete = calib_complete;
`else
    assign ui_clk = sys_clk;
    assign phy_init_done = calib_complete;
`endif
    always @ (posedge ui_clk) begin
        sys_rst_q <= sys_rst;
        ui_clk_sync_rst <= sys_rst_q;
        if (ui_clk_sync_rst) begin
            calib_complete <= 0;
        end else begin
            calib_complete <= 1;
        end
    end
    assign ui_rst = ui_clk_sync_rst;

    // simply loopback some of the read burst stuff
    assign s_axi_rid = s_axi_arid;
    assign s_axi_rresp = 0;
    // simply loopback some of the write burst stuff
    assign s_axi_bid = s_axi_awid;
    assign s_axi_bresp = 0;
 
    ///////////////
    // FUNCTIONS //
    ///////////////
    // computes ceil( log( x ) ) 
    function integer clogb2;
        input [31:0] value;
        begin
            value = value - 1;
            // want log2(0) = 1
            if (value == 0) begin
                value = 1;
            end
            for (clogb2 = 0; value > 0; clogb2 = clogb2 + 1) begin
                value = value >> 1;
            end
        end
    endfunction

    // hashes the address and returns an index into the address table
    // note: it is important that sequential addresses fall into the same mem data bucket
    function [clogb2(ADDR_ENTRIES)-1:0] hashAddress;
        input [C_S_AXI_ADDR_WIDTH-1:0] address;
        begin
            hashAddress = address >> clogb2(DATA_ENTRIES_PER_ADDR * (C_S_AXI_DATA_WIDTH/8));
        end
    endfunction
    
    // returns the address that is the first address in the same hash table bucket as the specified
    //  address
    function [C_S_AXI_ADDR_WIDTH-1:0] firstAddrInBucket;
        input [C_S_AXI_ADDR_WIDTH-1:0] address;
        begin
            firstAddrInBucket = address & ~(DATA_ENTRIES_PER_ADDR * (C_S_AXI_DATA_WIDTH/8) - 1);
        end
    endfunction
   
    // returns 1 if the current address is within the range of the address table entry
    // addr table format = {start address (inclusive), end address (exclusive), valid}
    function addrInRange;
        input [2*C_S_AXI_ADDR_WIDTH:0] addrTableEntry;
        begin
            if ((currentAddress >= addrTableEntry[2*C_S_AXI_ADDR_WIDTH:C_S_AXI_ADDR_WIDTH+1]) &&
                (currentAddress <  addrTableEntry[C_S_AXI_ADDR_WIDTH:1])) begin
                addrInRange = 1;
            end else begin
                addrInRange = 0;
            end
        end
    endfunction

    // returns true if the input address is within the valid range for the specified device
    function addrIsValid;
        input [C_S_AXI_ADDR_WIDTH-1:0] address;
        reg [C_S_AXI_ADDR_WIDTH:0] addrCeiling;
        begin
            addrIsValid = 1;
            addrCeiling = RANKS * (1<<BANK_WIDTH) * (1<<ROW_WIDTH) * (1<<COL_WIDTH) * (DQ_WIDTH/8);
            if (address >= addrCeiling) begin
                addrIsValid = 0;
            end 
        end
    endfunction

    ////////////////
    // data array //
    ////////////////
    reg [C_S_AXI_DATA_WIDTH-1:0]            memData         [0:DATA_ENTRIES-1];
    reg [clogb2(DATA_ENTRIES_PER_ADDR)-1:0] memBucketOffset;    
                                                            // offset in the mem data table from
                                                            //  the start of the bucket
    ///////////////////
    // address table //
    ///////////////////
    reg [2*C_S_AXI_ADDR_WIDTH:0]            addrTableData   [0:ADDR_ENTRIES-1];
                                                            // format = {start address (inclusive),
                                                            //  end address (exclusive), valid}
    
    reg [clogb2(ADDR_ENTRIES)-1:0]          addrTableIndex; // current index into the address table
    reg [clogb2(ADDR_ENTRIES)-1:0]          endAddrTableIndex;
                                                            // index where we should finish
                                                            //  searching in the addr table for a
                                                            //  valid entry

    ///////////
    // TASKS //
    ///////////
    
    // checks if the input address is valid for the current setup
    localparam UNUSED_ADDR_BITS = (C_S_AXI_DATA_WIDTH / 8) - 1;
    task checkAddressValid;
        input [C_S_AXI_ADDR_WIDTH-1:0] address;
        begin
            if ((address & UNUSED_ADDR_BITS) != 0) begin
                $display("ERROR: Invalid address = 0x%X", address);
                $display("INFO: Data is byte-addressable and must be aligned to the data bus width (0x%X B)", C_S_AXI_DATA_WIDTH/8);
                $stop;
            end
        end
    endtask

    // initializes the number of transactions for the current burst based upon the s_axi_arlen or
    //  s_axi_awlen
    task initNumTransactions;
        input doRead;
        begin
            if(doRead) begin
                txRemaining = s_axi_arlen + 1;
            end else begin
                txRemaining = s_axi_awlen + 1;
            end
        end
    endtask

    // initializes the current AXI address based upon the s_axi_araddr or s_axi_awaddr; sets the
    //  ending address table index
    task initAddress;
        input doRead;
        begin
            // set the current address
            if(doRead) begin
                currentAddress = s_axi_araddr;
            end else begin
                currentAddress = s_axi_awaddr;
            end

            // check that the address is not outside the range of valid addresses for this memory
            // note: this relies upon the parameters: RANKS, BANK_WIDTH, ROW_WIDTH, COL_WIDTH,
            //       and DQ_WIDTH
            if (!addrIsValid(currentAddress)) begin
                $display("PicoError! Address (0x%X) is out of the valid range", currentAddress);
                $stop;
            end

            // initialize the entry to search in the address table (and the last entry to check)
            addrTableIndex = hashAddress(currentAddress);
            if (addrTableIndex == 0) begin
                endAddrTableIndex = ADDR_ENTRIES - 1;
            end else begin
                endAddrTableIndex = addrTableIndex - 1;
            end
        end
    endtask

    // scans the address table to set the address table index and mem bucket offset to the proper
    //  values for the current address; does not modify the current address; if when checking the
    //  endAddrTableIndex, we cannot use that entry, then we have run out of memory and we should
    //  end the simulation
    task setupTransaction;
        reg run;
        begin
            run = 1;
            // addr table format = {start address (inclusive), end address (exclusive), valid}
            while(run) begin: SETUP_TX_LOOP
                // check if the current entry is valid
                if (addrTableData[addrTableIndex][0] !== 1'b1) begin
                    // if invalid, then allocate the current address to this entry
                    allocAddrTableEntry();
                    setMemBucketOffset(addrTableData[addrTableIndex]);
                    run = 0;
                end 
                // if valid, check if the current address falls within the range of the entry
                else if (addrInRange(addrTableData[addrTableIndex])) begin
                    // if so, set the mem bucket offset
                    setMemBucketOffset(addrTableData[addrTableIndex]);
                    run = 0;
                end
                // if it doesn't fall within range of the entry, check if we just examined the last
                //  address in the address table
                // TODO: modify this to check for a maximum number of reprobes
                else if (addrTableIndex == endAddrTableIndex) begin
                    $display("PicoError! Wrapped around address table; not enough memory");
                    $display("Either reduce the memory requirements or increase the NUM_BYTES parameter");
                    $stop;
                end 
                // if not, move onto the next addr table index
                // TODO: change this to a reprobe function
                else begin
                    addrTableIndex = (addrTableIndex + 1) % ADDR_ENTRIES;
                end
            end
        end
    endtask

    // allocates an entry of the address table for the current address
    /* BUG FIXED HERE!
    * If I allocate an entry for the current address and the next DATA_ENTRIES_PER_ADDR entries,
    * then I must ensure that the address for all DATA_ENTRIES_PER_ADDR entries hash to the same
    * starting bucket
    */ 
    task allocAddrTableEntry;
        reg [C_S_AXI_ADDR_WIDTH-1:0] entryStartAddr;
        reg [C_S_AXI_ADDR_WIDTH-1:0] entryEndAddr;
        begin
            entryStartAddr = firstAddrInBucket(currentAddress);
            entryEndAddr = entryStartAddr + (DATA_ENTRIES_PER_ADDR * (C_S_AXI_DATA_WIDTH/8));
            addrTableData[addrTableIndex] = {entryStartAddr, entryEndAddr,1'b1};
        end
    endtask

    // sets the memory bucket offset for the current address based upon the address in the address
    //  table at the addrTableIndex
    // addr table format = {start address (inclusive), end address (exclusive), valid}
    task setMemBucketOffset;
        input [2*C_S_AXI_ADDR_WIDTH:0] addrTableEntry;
        reg   [C_S_AXI_ADDR_WIDTH-1:0] startAddr;
        begin
            memBucketOffset = 0;
            startAddr = addrTableEntry >> (C_S_AXI_ADDR_WIDTH+1);
            while ((startAddr + (memBucketOffset * (C_S_AXI_DATA_WIDTH/8))) < currentAddress) begin
                memBucketOffset = memBucketOffset + 1;
            end
        end
    endtask

    // reads data from the memory buffer into the s_axi_rdata; increments the currentAddress;
    //  decrements the number of transactions remaining
    task doRead;
        begin
            `ifdef PICO_MIG_ZERO_INIT
            s_axi_rdata <= #1 (memData[DATA_ENTRIES_PER_ADDR * addrTableIndex + memBucketOffset] === {256{1'bx}}) ? 256'h0 : memData[DATA_ENTRIES_PER_ADDR * addrTableIndex + memBucketOffset];
            `else
            s_axi_rdata <= #1 memData[DATA_ENTRIES_PER_ADDR * addrTableIndex + memBucketOffset];
            `endif
            $display("%t: PicoInfo: Read from address 0x%X, data = 0x%X", $time,
                        currentAddress, memData[DATA_ENTRIES_PER_ADDR * addrTableIndex + memBucketOffset]);
        end
    endtask

    // writes data from the s_axi_wdata into the memory buffer; increments the currentAddress;
    //  decrements the number of transactions remaining
    task doWrite;
        begin
            $display("%t: PicoInfo: Write to  address 0x%X, data = 0x%X", $time,
                        currentAddress, s_axi_wdata);
            memData[DATA_ENTRIES_PER_ADDR * addrTableIndex + memBucketOffset] = s_axi_wdata;
        end
    endtask
    
    // increments the current address and decrements the number of transactions remaining
    task incrAddress;
        begin
            currentAddress = currentAddress + (C_S_AXI_DATA_WIDTH/8);
            txRemaining = txRemaining - 1;
        end
    endtask

    ////////////////////
    // initialization //
    ////////////////////
    /* 
    * format of initialization file - except for first line, each line only contains 1 entry, which
    * is the next 64 bits of data
    * 
    * Note: all data should be in hex format
    * 
    * line  |   entry       | description
    * --------------------------------------------------
    * 0     |   addr nBytes | byte address - number of bytes to write
    * 1     |   data[0]     | LS 8 bytes of data
    * ...
    * n     |   data[n-1]   | MS 8 bytes of data
    *
    * Example: writes 16B of data to address 0 = 0xDECAFBAD_CAFEBABE
    * 
    * 0 10
    * CAFEBABE
    * DECAFBAD
    *
    */
    task initMem;
        input [8*50-1:0]                filename;

        // for actually interfacing to the memory
        reg [C_S_AXI_ADDR_WIDTH-1:0]    currentAddress; 
        reg [C_S_AXI_DATA_WIDTH-1:0]    writeData;

        // file handling stuff
        integer                         ddr;
        reg                             eof;
        reg [1023:0]                       str;
        integer                         status;
        reg [C_S_AXI_ADDR_WIDTH-1:0]    writeAddr;
        reg [C_S_AXI_ADDR_WIDTH-1:0]    writeBytes;
        reg [C_S_AXI_DATA_WIDTH-1:0]    fileData;
        reg [9:0]                       bitPos;

        begin
            $display("PicoInfo: Initializing memory with %s", filename);   

            // open the file
            ddr = $fopen(filename, "r");
            status = $ferror(ddr, str);
            if (status != 0) begin
                $display("Error openening %s", filename);
                $stop;
            end

            // while there are more lines in the file
            while(!$feof(ddr)) begin

                // grab the address and size
                status = $fscanf(ddr, "%X %X\n", writeAddr, writeBytes);

                // force s_axi_awlen and s_axi_awaddr to the correct values
                force s_axi_awlen = (((8 * writeBytes) + C_S_AXI_DATA_WIDTH - 1) / 
                                     C_S_AXI_DATA_WIDTH) - 1;
                force s_axi_awaddr = writeAddr;

                // initialize the number of transactions for the write
                initNumTransactions(0); 

                // initialize the address for the write
                initAddress(0); 

                // do until we have written all this data
                while (txRemaining > 0) begin

                    // grab the next C_S_AXI_DATA_WIDTH bits of write data
                    writeData = 0;
                    for(bitPos=0; bitPos<C_S_AXI_DATA_WIDTH; bitPos=bitPos+64) begin
                        status = $fscanf(ddr, "%X\n", fileData);
                        writeData = writeData + (fileData << bitPos);
                    end

                    // finds an entry in the address table for this write data
                    setupTransaction();
                
                    // control the input
                    force s_axi_wdata = writeData;

                    // does the write
                    doWrite();

                    // move on to the next piece of data
                    incrAddress();

                end // while (txRemaining > 0) begin
            end // while(!$feof(ddr)) begin

            // releases the inputs so they can be controlled externally
            release s_axi_awlen;
            release s_axi_awaddr;
            release s_axi_wdata;
            
            // closes the input data file
            $fclose(ddr);
        end
    endtask

    ////////////////
    // controller //
    ////////////////
/*               On a write
*               1) hash the address to get the target entry of the address table (addrTableIndex)
*               2) record the last index of the address table that we will check before giving up
*                  (endAddrTableIndex)
*               3) read the address table at addrTableIndex
*               4) if the entry does not contain valid data, jump to step 9
*               5) if the entry contains valid data and address matches the current address, jump
*                  to step 10
*               6) if addrTableIndex==endAddrTableIndex, the memory has been used up and the
*                  simulation should end
*               7) addrTableIndex = (addrTableIndex + 1) % ADDR_ENTRIES
*               8) return to step 3
*               9) write the address (with valid bit) into the address table
*               10) write the data (in multiple cycles if required) into the data memory at index
*                   DATA_ENTRIES_PER_ADDR * i
*               11) send write response back on the B port
*               
*               On a read
*               1) hash the address to get the target entry of the address table (addrTableIndex)
*               2) record the last index of the address table that we will check before giving up
*                  (endAddrTableIndex)
*               3) read the address table at addrTableIndex
*               4) if the entry does not contain valid data, jump to step 9
*               5) if the entry contains valid data and address matches the current address, jump
*                  to step 10
*               6) if addrTableIndex==endAddrTableIndex, the memory has been used up and the
*                  simulation should end
*               7) addrTableIndex = (addrTableIndex + 1) % ADDR_ENTRIES
*               8) return to step 3
*               9) write the address (with valid bit) into the address table
*               9) write the address (with valid bit) into the address table
*               10) read the data (in multiple cycles if required) from the data memory at index
*                   DATA_ENTRIES_PER_ADDR * i (send on R port)
*/
    reg [2:0]                       state;

    reg                             checkRead;      // tells if we should ack a write or read command

    reg [C_S_AXI_ADDR_WIDTH-1:0]    currentAddress; // the current address for the transaction;
                                                    //  this should update as a burst proceeds

    reg [7:0]                       txRemaining;    // the number of remaining transactions for
                                                    //  this burst

    // states
    localparam  WAIT                = 0,    // wait for a write or read command
                CMD_INIT            = 1,    // set up the initial address and lengths
                DO_READ             = 2,    // perform a single read transaction
                DO_WRITE            = 3,    // perform a single write transaction
                COMPLETE_WRITE      = 4;    // send out a write response
    
    // FSM
    always @ (posedge ui_clk) begin
        if (ui_rst) begin
            state                       <= WAIT;
            checkRead                   <= 0;
            s_axi_rvalid                <= 0;
            s_axi_rlast                 <= 0;
        end else begin
            case (state)
                // wait until we have a valid write or read command on the input
                // note: this is steps 1 and 2 from the description above
                WAIT: begin
                    if ((checkRead && s_axi_arvalid) || 
                       (!checkRead && s_axi_awvalid && s_axi_wvalid)) begin
                        state           <= CMD_INIT;
                    end else begin
                        checkRead       <= ~checkRead;
                    end
                end

                // set the total number of transactions; set the current address for the burst; set
                //  the starting entry in the address table
                CMD_INIT: begin
                    initNumTransactions(checkRead); 
                    initAddress(checkRead); 
                    if(checkRead) begin
                        checkAddressValid(s_axi_araddr);
                        state           <= DO_READ;
                    end else begin
                        checkAddressValid(s_axi_awaddr);
                        state           <= DO_WRITE;
                    end
                end

                // attempts to find a location in the address table for the current address; sets
                //  the addrTableIndex and memBucketOffset to the correct values
                // reads from the currentAddress, increments currentAddress, decrements the number
                //  of remaining transactions
                DO_READ: begin
                    if (s_axi_rvalid && s_axi_rlast && s_axi_rready) begin
                        checkRead       <= ~checkRead;
                        state           <= WAIT;
                        s_axi_rvalid    <= 0;
                        s_axi_rlast     <= 0;
                    end else if (s_axi_rready) begin
                        setupTransaction();
                        doRead();
                        s_axi_rvalid    <= 1;
                        // must check the number of remaining transactions before incrementing the
                        //  address and decrementing the transaction count
                        if(txRemaining == 1) begin
                            s_axi_rlast <= 1;
                        end
                        incrAddress();
                    end
                end
                
                // attempts to find a location in the address table for the current address; sets
                //  the addrTableIndex and memBucketOffset to the correct values
                // writes the current data to the memory
                DO_WRITE: begin
                    if (s_axi_wvalid) begin
                        setupTransaction();
                        doWrite();
                        incrAddress();
                        if(s_axi_wlast) begin
                            state       <= COMPLETE_WRITE;
                        end
                    end
                end

                // send out a write response
                COMPLETE_WRITE: begin
                    if (s_axi_bready) begin
                        checkRead       <= ~checkRead;
                        state           <= WAIT;
                    end
                end

            endcase
        end
    end
   
    // asynchronous logic
    always @ (*) begin

        s_axi_awready   = 0;
        s_axi_wready    = 0;
        s_axi_bvalid    = 0;
        s_axi_arready   = 0;

        case (state)
           
            // only ack the read address upon the completion of the read 
            DO_READ: begin
                if(s_axi_rvalid && s_axi_rready && s_axi_rlast) begin
                    s_axi_arready = 1;
                end
            end
            
            // ack the write data at all times, only ack the write address upon the completion of
            //  the write
            DO_WRITE: begin
                s_axi_wready = 1;
            end

            // send out a write response
            COMPLETE_WRITE: begin
                s_axi_bvalid = 1;
                if(s_axi_bready) begin
                    s_axi_awready = 1;
                end
            end

        endcase
    end

    // check that this is not the top-level simulation module
    always @ (*) begin
        if(ui_clk === 1'bx) begin
            $display("Error detected, ui_clk = x.");
            $display("Pico_MIG_model is not meant to be run as a top level simulation module.");
            $display("Please refer to the Pico DDR documentation for more details.");
            $stop;
        end
    end

    /* debug signals
    reg [(1<<C_S_AXI_ID_WIDTH)-1:0] addrAsserted;
    always @ (*) begin
        addrAsserted = 0;
        addrAsserted[s_axi_arid] = 1'b1;
    end
    // */
    always @ (posedge ui_clk) begin
        if(s_axi_rvalid && s_axi_rdata === 'hx) begin
            $display("[%t] Read data = 0x%X", $time, s_axi_rdata);
        end
    end

endmodule
