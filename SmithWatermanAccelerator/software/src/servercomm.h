//  File Name        : servercomm.h
//  Description      : Server Communicator class definitions
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Nov 01 2013     Report ref name with each alignment

#ifndef SERVERCOMM_H_
#define SERVERCOMM_H_

#include <string>
#include <list>
#include "def.h"
#include "serversocket.h"
#include "threadqueue.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "alignment.h"

#define SYNTAX_ERROR_QUERYSEQ 0x1
#define SYNTAX_ERROR_REFNAME 0x2
#define SYNTAX_ERROR_REFSTART 0x4
#define SYNTAX_ERROR_REFEND 0x8
#define SYNTAX_ERROR_REFSTARTEND 0x10
#define SYNTAX_ERROR_QUERYDESCRIP 0x20
#define SYNTAX_ERROR_PARAMS 0x40
#define SYNTAX_ERROR_QUERYSEQ_STR "Error in query sequence.\n"
#define SYNTAX_ERROR_REFNAME_STR "Error in ref seq name.\n"
#define SYNTAX_ERROR_REFSTART_STR "Error in ref seq start index.\n"
#define SYNTAX_ERROR_REFEND_STR "Error in ref seq end index.\n"
#define SYNTAX_ERROR_REFSTARTEND_STR "Error in ref seq indices.\n"
#define SYNTAX_ERROR_QUERYDESCRIP_STR "Error in query description line.\n"
#define SYNTAX_ERROR_PARAMS_STR "Error in scoring parameters.\n"

class ServerComm {
  public:
    ServerComm(int port);
    ~ServerComm();
    
    // Get a query group from a client.
    // Add the queries to the query seq manager.
    // Store the scoring params and queries onto the alignment job queue.
    // Returns the list of query IDs in this group.
    std::vector<int> GetQueryGroup(ThreadQueue<AlignmentJob>* alignment_job_queue, 
                                   QuerySeqManager* query_seq_manager,
                                   RefSeqManager* ref_seq_manager,
                                   unsigned int* errors);
    
    // Send the alignment result to the client.
    void SendAlignment(AlignmentResult res, std::string query_name, std::string ref_name);
    
    // Finish off a query group and close the client.
    // Sends corresponding message depending on whether or not the query group alignment
    //   was successful (unsuccessful = bad parse).
    void EndQueryGroup(unsigned int errors);
    
  private:
    enum ParserState {PARAMS, QUERIES};
    
    // FSM action function, performed on each line
    // Returns true when a query group is done
    // Returns whether the line is valid in line_good
    bool Action(std::string line, 
                std::vector<AlignmentJob>* new_jobs, 
                RefSeqManager* ref_seq_manager,
                std::vector<std::string>* query_names,
                std::vector<std::string>* query_seqs,
                unsigned int* errors);
    
    ServerSocket server_;
    ServerSocket client_sock_;
    ParserState state_;
    SwAffineGapParams params_;
};
    
#endif // SERVERCOMM_H_
