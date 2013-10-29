//  File Name        : servercomm.h
//  Description      : Server Communicator class definitions
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//

#ifndef SERVERCOMM_H_
#define SERVERCOMM_H_

#include "serversocket.h"
#include "threadqueue.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "alignment.h"
#include "def.h"
#include <string>
#include <list>

class ServerComm {
  public:
    ServerComm(int port);
    ~ServerComm();
    
    // Receive the next query group from a client.
    // Add the queries to the query seq manager
    // Store the scoring params and queries onto the alignment job queue
    // Returns the list of query IDs in this group
    std::list<int> ParseQueryGroup(ThreadQueue<AlignmentJob>* alignment_job_queue, 
                                   QuerySeqManager* query_seq_manager,
                                   RefSeqManager* ref_seq_manager);
    
    // Send the alignment result to the client
    void SendAlignment(AlignmentResult res, std::string query_name);
    
    // Send end of query group signal
    void SendEndOfQueryGroup();
    
  private:
    enum ParserState {PARAMS, QUERIES};
    
    // FSM action function
    // Returns true when a query group is done
    bool Action(std::string line,
                ThreadQueue<AlignmentJob>* alignment_job_queue, 
                QuerySeqManager* query_seq_manager,
                RefSeqManager* ref_seq_manager,
                std::list<int>* query_ids);
    
    ServerSocket server_;
    ServerSocket client_sock_;
    std::string rcv_buf_;
    std::string cur_line_;
    bool client_active_;
    ParserState state_;
    SwAffineGapParams params_;
};
    
    
    
#endif // SERVERCOMM_H_
