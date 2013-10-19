//  File Name        : queryseqmanager.cpp
//  Description      : Query Sequence Manager
//
//  Revision History :
//      Albert Ng   Oct 09 2013     Initial Revision 
//      Albert Ng   Oct 14 2013     Added SetQueryNumEngines()
//      Albert Ng   Oct 17 2013     Renamed SetQueryNumEngines to SetQueryNumJobs

#include <pthread.h>
#include <map>
#include "queryseqmanager.h"
#include <iostream> 
#include <string>

QuerySeqManager::QuerySeqManager() {
  pthread_mutex_init(&query_jobcount_map_mutex_, NULL);
  pthread_mutex_init(&query_seq_map_mutex_, NULL);
  cur_query_id_ = 0;
}

// Initialize a new dummy job count for the query
int QuerySeqManager::AddQuery(char* query_seq, int query_len) {
  int query_id = cur_query_id_;
  QuerySeq qs;
  qs.seq = query_seq;
  qs.len = query_len;  

  pthread_mutex_lock(&query_seq_map_mutex_);
  query_seq_map_[query_id] = qs;
  pthread_mutex_unlock(&query_seq_map_mutex_);
  
  pthread_mutex_lock(&query_jobcount_map_mutex_);
  query_jobcount_map_[query_id] = 1;
  pthread_mutex_unlock(&query_jobcount_map_mutex_);

  // NOTE: no mutex guards. Be careful.
  cur_query_id_++;
  return query_id;
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::SetQueryNumJobs(int query_id, int num_jobs) {
  pthread_mutex_lock(&query_jobcount_map_mutex_);
  query_jobcount_map_[query_id] = num_jobs;
  pthread_mutex_unlock(&query_jobcount_map_mutex_);
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::RemoveQuery(int query_id) {
  pthread_mutex_lock(&query_jobcount_map_mutex_);
  query_jobcount_map_.erase(query_id);
  pthread_mutex_unlock(&query_jobcount_map_mutex_);
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::IncHighScoreRegionCount(int query_id) {
  std::cout<<"HighScoreRegion"<<std::endl;
  pthread_mutex_lock(&query_jobcount_map_mutex_);
  query_jobcount_map_[query_id]++;
  pthread_mutex_unlock(&query_jobcount_map_mutex_);
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::DecHighScoreRegionCount(int query_id) {
  pthread_mutex_lock(&query_jobcount_map_mutex_);
  if (query_jobcount_map_.count(query_id) > 0) {
    query_jobcount_map_[query_id]--;
  }
  pthread_mutex_unlock(&query_jobcount_map_mutex_);
}

// A query is done when the job count value for that query is 0,
//   meaning all high scoring regions are aligned by the software
//   aligner threads, and all terminating packets are received from
//   the engines.
// Note: No error handling for invalid query_ids
bool QuerySeqManager::QueryDone(int query_id) {
  int val;

  pthread_mutex_lock(&query_jobcount_map_mutex_);
  val = query_jobcount_map_[query_id];
  pthread_mutex_unlock(&query_jobcount_map_mutex_);

  return val == 0;
}

// Note: No error handling for invalid query_ids
char* QuerySeqManager::GetQuerySeq(int query_id, int* query_len) {
  QuerySeq query_seq;

  pthread_mutex_lock(&query_seq_map_mutex_);
  query_seq = query_seq_map_[query_id];
  pthread_mutex_unlock(&query_seq_map_mutex_);
  
  *query_len = query_seq.len;
  return query_seq.seq;
}
