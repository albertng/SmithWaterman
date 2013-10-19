//  File Name        : queryseqmanager.h
//  Description      : Query Sequence Manager definitions
//
//  Revision History :
//      Albert Ng   Oct 09 2013     Initial Revision 
//      Albert Ng   Oct 14 2013     Added SetQueryNumEngines()
//      Albert Ng   Oct 17 2013     Renamed SetQueryNumEngines to SetQueryNumJobs


#ifndef QUERYSEQMANAGER_H_
#define QUERYSEQMANAGER_H_

#include <pthread.h>
#include <map>
#include <semaphore.h>

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
    int AddQuery(char* query_seq, int query_len);

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

  private:
    // Useful struct to simplify some code
    // Don't want to use std::string because ref seq manager uses char* and
    //   we don't want to mix up the usage
    struct QuerySeq {
      char* seq;
      int len;
    };

    // One semaphore per query, query done when semaphore is zero
    std::map<int, sem_t*> query_semaphore_map_;

    // Mutex guarding query semaphore map, since the map will be accessed
    //   by several threads
    pthread_mutex_t query_semaphore_map_mutex_;

    // Bookkeeping between query ID and query sequence 
    std::map<int, QuerySeq>  query_seq_map_;

    // Mutex guarding query sequence map, since the map will be accessed
    //   by several threads
    pthread_mutex_t query_seq_map_mutex_;

    // Next query ID to assign
    int cur_query_id_;
};


#endif // QUERYSEQMANAGER_H_
