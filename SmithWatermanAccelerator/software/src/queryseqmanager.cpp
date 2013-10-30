//  File Name        : queryseqmanager.cpp
//  Description      : Query Sequence Manager
//
//  Revision History :
//      Albert Ng   Oct 09 2013     Initial Revision 
//      Albert Ng   Oct 14 2013     Added SetQueryNumEngines()
//      Albert Ng   Oct 17 2013     Renamed SetQueryNumEngines to SetQueryNumJobs
//      Albert Ng   Oct 22 2013     Changed AddQuery to take a string
//                                  Added query name
//      Albert Ng   Oct 28 2013     Deleted query seq char array in RemoveQuery()

#include <pthread.h>
#include <map>
#include "queryseqmanager.h"
#include <iostream> 
#include <string>
#include <cstring>

QuerySeqManager::QuerySeqManager() {
  pthread_mutex_init(&query_jobcount_map_mutex_, NULL);
  pthread_mutex_init(&query_seq_map_mutex_, NULL);
  cur_query_id_ = 0;
}

// Initialize a new dummy job count for the query
int QuerySeqManager::AddQuery(std::string query_name, std::string query_string) {
  char* query_seq = new char[query_string.length()];
  memcpy(query_seq, query_string.c_str(), query_string.length());

  int query_id = cur_query_id_;
  QuerySeq qs;
  qs.name = query_name;
  qs.seq = query_seq;
  qs.len = query_string.length();  

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
  //std::cout<<"Query "<<query_id<<" init num jobs "<< num_jobs<<std::endl;
  pthread_mutex_lock(&query_jobcount_map_mutex_);
  query_jobcount_map_[query_id] = num_jobs;
  pthread_mutex_unlock(&query_jobcount_map_mutex_);
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::RemoveQuery(int query_id) {
  pthread_mutex_lock(&query_seq_map_mutex_);
  delete[] query_seq_map_[query_id].seq;
  query_seq_map_.erase(query_id);
  pthread_mutex_unlock(&query_seq_map_mutex_);

  pthread_mutex_lock(&query_jobcount_map_mutex_);
  query_jobcount_map_.erase(query_id);
  pthread_mutex_unlock(&query_jobcount_map_mutex_);
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::IncHighScoreRegionCount(int query_id) {
  pthread_mutex_lock(&query_jobcount_map_mutex_);
  query_jobcount_map_[query_id]++;
  //std::cout<<"Query "<<query_id<<" Inc HSR count to "<<query_jobcount_map_[query_id]<<std::endl;
  pthread_mutex_unlock(&query_jobcount_map_mutex_);
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::DecHighScoreRegionCount(int query_id) {
  pthread_mutex_lock(&query_jobcount_map_mutex_);
  if (query_jobcount_map_.count(query_id) > 0) {
    query_jobcount_map_[query_id]--;
  }
  //std::cout<<"Query "<<query_id<<" Dec HSR count to "<<query_jobcount_map_[query_id]<<std::endl;
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

// Note: No error handling for invalid query_ids
std::string QuerySeqManager::GetQueryName(int query_id) {
  QuerySeq query_seq;

  pthread_mutex_lock(&query_seq_map_mutex_);
  query_seq = query_seq_map_[query_id];
  pthread_mutex_unlock(&query_seq_map_mutex_);

  return query_seq.name;
}
