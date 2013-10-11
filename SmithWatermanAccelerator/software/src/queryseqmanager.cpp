//  File Name        : queryseqmanager.cpp
//  Description      : Query Sequence Manager
//
//  Revision History :
//      Albert Ng   Oct 09 2013     Initial Revision 

#include <pthread.h>
#include <map>
#include <semaphore.h>
#include "queryseqmanager.h"

QuerySeqManager::QuerySeqManager() {
  pthread_mutex_init(&query_semaphore_map_mutex_, NULL);
  pthread_mutex_init(&query_seq_map_mutex_, NULL);
  cur_query_id_ = 0;
}

// Initialize a new semaphore for the query, starting at
//   the number of FPGA engines to schedule this query
//   alignment across.
int QuerySeqManager::AddQuery(char* query_seq, int query_len, int num_engines) {
  sem_t* new_sem = new sem_t;
  sem_init(new_sem, 0, num_engines);
  
  int query_id = cur_query_id_;
  QuerySeq qs;
  qs.seq = query_seq;
  qs.len = query_len;  

  pthread_mutex_lock(&query_seq_map_mutex_);
  query_seq_map_[query_id] = qs;
  pthread_mutex_unlock(&query_seq_map_mutex_);
  
  pthread_mutex_lock(&query_semaphore_map_mutex_);
  query_semaphore_map_[query_id] = new_sem;
  pthread_mutex_unlock(&query_semaphore_map_mutex_);

  cur_query_id_++;
  return query_id;
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::RemoveQuery(int query_id) {
  pthread_mutex_lock(&query_semaphore_map_mutex_);
  if (query_semaphore_map_.count(query_id) > 0) {
    delete query_semaphore_map_[query_id];
  }
  query_semaphore_map_.erase(query_id);
  pthread_mutex_unlock(&query_semaphore_map_mutex_);
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::IncHighScoreRegionCount(int query_id) {
  pthread_mutex_lock(&query_semaphore_map_mutex_);
  if (query_semaphore_map_.count(query_id) > 0) {
    sem_post(query_semaphore_map_[query_id]);
  }
  pthread_mutex_unlock(&query_semaphore_map_mutex_);
}

// Note: No error handling for invalid query_ids
void QuerySeqManager::DecHighScoreRegionCount(int query_id) {
  pthread_mutex_lock(&query_semaphore_map_mutex_);
  if (query_semaphore_map_.count(query_id) > 0) {
    sem_wait(query_semaphore_map_[query_id]);
  }
  pthread_mutex_unlock(&query_semaphore_map_mutex_);
}

// A query is done when the semaphore value for that query is 0,
//   meaning all high scoring regions are aligned by the software
//   aligner threads, and all terminating packets are received from
//   the engines.
// Note: No error handling for invalid query_ids
bool QuerySeqManager::QueryDone(int query_id) {
  int sem_val = 1;

  pthread_mutex_lock(&query_semaphore_map_mutex_);
  if (query_semaphore_map_.count(query_id) > 0) {
    sem_getvalue(query_semaphore_map_[query_id], &sem_val);
  }
  pthread_mutex_unlock(&query_semaphore_map_mutex_);

  return sem_val == 0;
}

// Note: No error handling for invalid query_ids
char* QuerySeqManager::GetQuerySeq(int query_id, int* query_len) {
  QuerySeq query_seq;
  query_seq.seq = NULL;

  pthread_mutex_lock(&query_seq_map_mutex_);
  if (query_seq_map_.count(query_id) > 0) {
    query_seq = query_seq_map_[query_id];
  }
  pthread_mutex_unlock(&query_seq_map_mutex_);
  *query_len = query_seq.len;

  return query_seq.seq;
}
