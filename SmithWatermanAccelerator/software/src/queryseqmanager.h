//  File Name        : queryseqmanager.h
//  Description      : Query Sequence Manager definitions
//
//  Revision History :
//      Albert Ng   Oct 09 2013     Initial Revision 
//      Albert Ng   Oct 14 2013     Added SetQueryNumEngines()
//      Albert Ng   Oct 17 2013     Renamed SetQueryNumEngines to SetQueryNumJobs
//      Albert Ng   Oct 22 2013     Changed AddQuery to take a string
//                                  Added query name
//      Albert Ng   May 21 2014     Query hit count


#ifndef QUERYSEQMANAGER_H_
#define QUERYSEQMANAGER_H_

#include <pthread.h>
#include <map>
#include <string>

#define QUERY_ERROR_MEM 0x1

// Query Sequence Manager class
//   Handles bookkeeping of query sequences and their alignment jobs
//   Each query sequence has an associated semaphore that keeps track
//   of the number of software alignment jobs to be done for the query.
//   This semaphore is initialized with the number of FPGA engines
//   the query is scheduled across. It is incremented when a new high
//   scoring region is found by the FPGA engines, and is decremented
//   when a software aligner finishes aligning a high scoring region.
//   It is also decremented when a FPGA engine finishes its alignment.
//   Thus, the semaphore only reaches zero when all high scoring regions
//   are found and aligned by the software threads.
// Note: SetQueryNumJobs() must be called after a query is added via
//   AddQuery(), before Inc/DecHighScoreRegionCount() are called.
class QuerySeqManager {
  public:
    QuerySeqManager();

    // Adds a new query sequence under management and returns its ID
    int AddQuery(std::string query_name, std::string query_string);

    // Set the number of engines the query is scheduled across
    void SetQueryNumJobs(int query_id, int num_jobs);

    // Removes a query sequence under management
    void RemoveQuery(int query_id);

    // Increment semaphore for the given query ID
    void IncHighScoreRegionCount(int query_id);

    // Decrement semaphore for the given query ID
    void DecHighScoreRegionCount(int query_id);

    // Check if all alignments for given query is complete
    bool QueryDone(int query_id);

    // Look up query sequence from the query ID and store the query
    //   length in the passed pointer
    char* GetQuerySeq(int query_id, int* query_len);

    // Get the query name from the query ID
    std::string GetQueryName(int query_id);

    // Increment the number of hits for a query
    void IncHitCount(int query_id);
    
    // Get the number of hits for a query
    int GetHitCount(int query_id);

    // Record an error code for a query
    void RecordError(int query_id, int error);
    
    // Get the error code for a query
    int GetErrors(int query_id);

  private:
    // Useful struct to simplify some code
    // Don't want to use std::string because ref seq manager uses char* and
    //   we don't want to mix up the usage
    struct QuerySeq {
      std::string name;
      char* seq;
      int len;
    };

    // One job count per query, query done when job count is zero
    std::map<int, int> query_jobcount_map_;

    // Mutex guarding query job count map, since the map will be accessed
    //   by several threads
    pthread_mutex_t query_jobcount_map_mutex_;

    // Bookkeeping between query ID and query sequence 
    std::map<int, QuerySeq>  query_seq_map_;

    // Mutex guarding query sequence map, since the map will be accessed
    //   by several threads
    pthread_mutex_t query_seq_map_mutex_;

    // Number of hits per query
    std::map<int, int> query_hitcount_map_;
    
    // Mutex guarding query hitcount map
    pthread_mutex_t query_hitcount_map_mutex_;

    // Query error codes
    std::map<int, int> query_errors_map_;
    
    // Mutex guarding query error codes map
    pthread_mutex_t query_errors_map_mutex_;

    // Next query ID to assign
    int cur_query_id_;
};


#endif // QUERYSEQMANAGER_H_
