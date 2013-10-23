//  File Name        : serverqueryparser.cpp
//  Description      : Server Query Parser class
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//

#include "serverqueryparser.h"
#include "threadqueue.h"
#include "scoring.h"
#include <sstream>
#include "def.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include <iostream>

ServerQueryParser::ServerQueryParser(int port) {
  server_.Init(port);
  rcv_buf_ = "";
  cur_line_ = "";
  client_active_ = false;
  state_ = PARAMS;
}

ServerQueryParser::~ServerQueryParser() {
}

std::list<int> ServerQueryParser::ParseQueryGroup(ThreadQueue<AlignmentJob>* alignment_job_queue, 
                                                  QuerySeqManager* query_seq_manager,
                                                  RefSeqManager* ref_seq_manager) {
  std::list<int> query_ids;
  bool query_group_done = false;
  
  while (query_group_done == false) {
    // No active client, connect to one
    if (client_active_ == false) {
      server_.Accept(&client_sock_);
      client_active_ = true;
    }
    
    // Nothing left in buffer, receive from client
    if (rcv_buf_.length() == 0) {
      client_sock_.Recv(&rcv_buf_);
    }
    
    // Find first newline in buffer
    int newline_pos = rcv_buf_.find('\n');
    
    // No newline, append entire buffer to current line and keep going
    if (newline_pos == std::string::npos) {
      cur_line_ += rcv_buf_;
      rcv_buf_ = "";
    } else { 
      // Newline found, append buffer up to the newline to current line
      cur_line_ += rcv_buf_.substr(0, newline_pos);
      if (newline_pos != rcv_buf_.length() - 1) {
        rcv_buf_ = rcv_buf_.substr(newline_pos + 1);
      } else {
        rcv_buf_ = "";
      }
      
      // Parse the line
      query_group_done = Action(cur_line_, alignment_job_queue, query_seq_manager, ref_seq_manager, &query_ids);
      cur_line_ = "";
    }
  }
  
  return query_ids;
}

bool ServerQueryParser::Action(std::string line, 
                               ThreadQueue<AlignmentJob>* alignment_job_queue, 
                               QuerySeqManager* query_seq_manager,
                               RefSeqManager* ref_seq_manager,
                               std::list<int>* query_ids) {
  bool query_group_done = false;
  
  switch (state_) {
    case PARAMS : {                           // Store the scoring params
      SwAffineGapParams params(cur_line_);
      AlignmentJob params_job;
      params_job.query_id = PARAMS_JOB;
      params_job.params = params;
      alignment_job_queue->Push(params_job);
      params_ = params;
      state_ = QUERIES;
      break;
    }
      
    case QUERIES : {
      if (cur_line_ != END_OF_QUERY_GROUP) {  // Store a query sequence
        std::string query_name;
        std::string ref_name;
        long long int ref_start;
        long long int ref_end;
        int threshold;
        std::string query_seq;
        
        std::istringstream iss(cur_line_);
        iss >> query_name;
        iss >> query_seq; 
        iss >> ref_name;
        iss >> ref_start;
        iss >> ref_end;
        iss >> threshold;
        
        int query_id = query_seq_manager->AddQuery(query_name, query_seq);
        query_ids->push_back(query_id);
        
        AlignmentJob job;
        job.query_id = query_id;
        job.ref_id = ref_seq_manager->GetRefID(ref_name);
        job.ref_offset = ref_start - 1;
        job.ref_len = ref_end - ref_start;
        job.threshold = threshold;
        job.params = params_;
        alignment_job_queue->Push(job);
        
        state_ = QUERIES;
      } else {                                // Done with the query group
        if (rcv_buf_.length() == 0) {
          if (client_sock_.Recv(&rcv_buf_) == 0) {
            client_active_ = false;
          }
        }
        query_group_done = true;
        state_ = PARAMS;
      }
      break;
    }
      
    default : {                               // Should never get here
      std::cerr << "ParseQueryGroup FSM bad state!" << std::endl;
      break;
    }
  }
  
  return query_group_done;
}
