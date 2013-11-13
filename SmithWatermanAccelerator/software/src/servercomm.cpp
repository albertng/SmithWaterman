//  File Name        : servercomm.cpp
//  Description      : Server Communicator class
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 29 2013     Requires a new client connection per query group
//      Albert Ng   Nov 01 2013     Report ref name with each alignment
//      Albert Ng   Nov 06 2013     Added error handling to GetQueryGroup()

#include <sstream>
#include <iostream>
#include <queue>
#include <assert.h>
#include <vector>
#include "servercomm.h"
#include "threadqueue.h"
#include "scoring.h"
#include "def.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "alignment.h"

ServerComm::ServerComm(int port) {
  server_.Init(port);
  state_ = PARAMS;
}

ServerComm::~ServerComm() {
}

// Sends the client an acknowledge after each line transmitted. The acknowledge indicates
//   whether or not the line was successfully parsed. If the line was not successfully
//   parsed, the client is excepted to retransmit the line. If the retransmitted line was
//   invalid again, then the entire query group is terminated.
// This should allow intermittent transmission errors to be handled, but should skip
//   jobs that contain any actual line errors.
std::vector<int> ServerComm::GetQueryGroup(ThreadQueue<AlignmentJob>* alignment_job_queue, 
                                         QuerySeqManager* query_seq_manager,
                                         RefSeqManager* ref_seq_manager,
                                         unsigned int* errors) {
  std::vector<AlignmentJob> new_jobs;                                    
  std::vector<std::string> query_names;
  std::vector<std::string> query_seqs;
  std::vector<int> query_ids;
  
  bool query_group_done = false;
  std::string cur_line = "";
  std::string rcv_buf = "";
  *errors = 0;
  
  server_.Accept(&client_sock_);
  
  /*while (query_group_done == false) {
    client_sock_.Recv(&rcv_buf);
    
    // Find first newline in buffer
    int newline_pos = rcv_buf.find('\n');
    
    // No newline, append entire buffer to current line and keep going
    if (newline_pos == std::string::npos) {
      cur_line += rcv_buf;
    } else {
      // Newline found, append buffer (w/o the newline) to current line
      cur_line += rcv_buf.substr(0, newline_pos);
    
      // Parse the line
      bool line_good;
      query_group_done = Action(cur_line, &new_jobs, ref_seq_manager, &query_names, &query_seqs, &line_good);
      
      // Invalid line
      if (line_good == false) {
        query_group_done = true;
        query_group_good = false;
      }
      cur_line = "";
    }
  }*/

  while (query_group_done == false) {   
    // Nothing left in buffer, receive from client
    if (rcv_buf.length() == 0) {
      client_sock_.Recv(&rcv_buf);
    }
    
    // Find first newline in buffer
    int newline_pos = rcv_buf.find('\n');
    
    // No newline, append entire buffer to current line and keep going
    if (newline_pos == std::string::npos) {
      cur_line += rcv_buf;
      rcv_buf = "";
    } else { 
      // Newline found, append buffer up to the newline to current line
      cur_line += rcv_buf.substr(0, newline_pos);
      if (newline_pos != rcv_buf.length() - 1) {
        rcv_buf = rcv_buf.substr(newline_pos + 1);
      } else {
        rcv_buf = "";
      }
      
      // Parse the line
      unsigned int line_errors = 0;
      query_group_done = Action(cur_line, &new_jobs, ref_seq_manager, &query_names, &query_seqs, &line_errors);
      *errors |= line_errors;
      
      // Invalid line check
      if (line_errors != 0) {
        query_group_done = true;
      }
      
      cur_line = "";
    }
  }
  client_sock_.ShutdownRecv();
  
  if (*errors == 0) {
    for (int i = 0; i < new_jobs.size(); i++) {
      if (i != 0) {
        int query_id = query_seq_manager->AddQuery(query_names[i-1], query_seqs[i-1]);
        query_ids.push_back(query_id);
        new_jobs[i].query_id = query_id;
      }
      alignment_job_queue->Push(new_jobs[i]);
    }
  }
  
  return query_ids;
}

bool ServerComm::Action(std::string line, 
                        std::vector<AlignmentJob>* new_jobs, 
                        RefSeqManager* ref_seq_manager,
                        std::vector<std::string>* query_names,
                        std::vector<std::string>* query_seqs,
                        unsigned int* errors) {
  bool query_group_done = false;
  *errors = 0;
  //std::cout<<line<<std::endl;
  switch (state_) {
    case PARAMS : {                           // Store the scoring params
      try {
        SwAffineGapParams params(line);
        AlignmentJob params_job;
        params_job.query_id = PARAMS_JOB;
        params_job.params = params;
        //alignment_job_queue->Push(params_job);
        new_jobs->push_back(params_job);
        //std::cout<<"Alignment params job: "<<params_job.query_id<< " "<<params_job.ref_id<<" "<<params_job.ref_offset<<" "<<params_job.ref_len<<" "<<params_job.threshold<<" "<<params_job.params.ToString()<<std::endl;
        params_ = params;
        state_ = QUERIES;
        break;
      } catch (std::ios_base::failure &e) {
        *errors |= SYNTAX_ERROR_PARAMS;
        state_ = PARAMS;
        break;
      }
    }
      
    case QUERIES : {
      if (line != END_OF_QUERY_GROUP) {  // Store a query sequence
        std::string query_name;
        std::string ref_name;
        long long int ref_start;
        long long int ref_end;
        int threshold;
        std::string query_seq;
        
        std::istringstream iss(line);
        iss.exceptions(std::ios::failbit);
        try {
          iss >> query_name;
          iss >> query_seq; 
          iss >> ref_name;
          iss >> ref_start;
          iss >> ref_end;
          iss >> threshold;
          
          int ref_id = (ref_seq_manager->GetRefID(ref_name));
          
          // Some syntax checks
          unsigned int syntax_errors = 0;
          for (int i = 0; i < query_seq.length(); i++) {          // Check for invalid nucleotides
            if (query_seq[i] != 'n' && query_seq[i] != 'N' &&
                query_seq[i] != 'a' && query_seq[i] != 'A' &&
                query_seq[i] != 'g' && query_seq[i] != 'G' &&
                query_seq[i] != 'c' && query_seq[i] != 'C' &&
                query_seq[i] != 't' && query_seq[i] != 'T') {
              *errors |= SYNTAX_ERROR_QUERYSEQ;
              break;
            }
          }
          if (ref_id == -1) {                                     // Check for invalid ref seq
            *errors |= SYNTAX_ERROR_REFNAME;
          }
          if (ref_id != -1 && ref_start >= ref_end - 1) {                         // Check for invalid start/end coordinates
            *errors |= SYNTAX_ERROR_REFSTARTEND;
          }
          if (ref_id != -1 && ref_start >= ref_seq_manager->GetRefLength(ref_id)) {
            *errors |= SYNTAX_ERROR_REFSTART;
          }
          if (ref_id != -1 && ref_end - 1 > ref_seq_manager->GetRefLength(ref_id)) {
            *errors |= SYNTAX_ERROR_REFEND;
          }
          
          //int query_id = query_seq_manager->AddQuery(query_name, query_seq);
          //query_ids->push_back(query_id);
          query_names->push_back(query_name);
          query_seqs->push_back(query_seq);
          
          AlignmentJob job;
          job.ref_id = ref_seq_manager->GetRefID(ref_name);
          job.ref_offset = ref_start - 1;
          job.ref_len = ref_end - ref_start;
          job.threshold = threshold;
          job.params = params_;
          //std::cout<<"Alignment job: "<<job.query_id<< " "<<job.ref_id<<" "<<job.ref_offset<<" "<<job.ref_len<<" "<<job.threshold<<" "<<job.params.ToString()<<std::endl;
          //alignment_job_queue->Push(job);
          new_jobs->push_back(job);
          
          if (*errors == 0) {
            state_ = QUERIES;
          } else {
            query_group_done = true;
            state_ = PARAMS;
          }
        } catch (std::ios_base::failure &e) {
          *errors |= SYNTAX_ERROR_QUERYDESCRIP;
          query_group_done = true;
          state_ = PARAMS;
        }
      } else {                                // Done with the query group
        query_group_done = true;
        state_ = PARAMS;
      }
      break;
    }
      
    default : {                               // Should never get here
      assert(false);
      break;
    }
  }
  
  return query_group_done;
}

void ServerComm::SendAlignment(AlignmentResult res, std::string query_name, std::string ref_name) {
  std::stringstream ss;
  
  ss << "Ref: " << ref_name << "\n"
     << "Query: " << query_name << "\n"
     << "Score: " << res.score << "\n"
     << res.alignment.ToString() << "\n";

  client_sock_.Send(ss.str());
}

void ServerComm::EndQueryGroup(unsigned int errors) {
  if (errors & SYNTAX_ERROR_QUERYSEQ) {
    client_sock_.Send(SYNTAX_ERROR_QUERYSEQ_STR);
  }
  if (errors & SYNTAX_ERROR_REFNAME) {
    client_sock_.Send(SYNTAX_ERROR_REFNAME_STR);
  }
  if (errors & SYNTAX_ERROR_REFSTART) {
    client_sock_.Send(SYNTAX_ERROR_REFSTART_STR);
  }
  if (errors & SYNTAX_ERROR_REFEND) {
    client_sock_.Send(SYNTAX_ERROR_REFEND_STR);
  }
  if (errors & SYNTAX_ERROR_REFSTARTEND) {
    client_sock_.Send(SYNTAX_ERROR_REFSTARTEND_STR);
  }
  if (errors & SYNTAX_ERROR_QUERYDESCRIP) {
    client_sock_.Send(SYNTAX_ERROR_QUERYDESCRIP_STR);
  }
  if (errors & SYNTAX_ERROR_PARAMS) {
    client_sock_.Send(SYNTAX_ERROR_PARAMS_STR);
  }
  if (errors == 0) {
    client_sock_.Send(QUERY_GROUP_SUCCESS);
  } else {
    client_sock_.Send(QUERY_GROUP_FAIL);
  }
  client_sock_.Send("\n");
  client_sock_.Close();
}

