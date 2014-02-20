//  File Name        : servercomm.cpp
//  Description      : Server Communicator class
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 29 2013     Requires a new client connection per query group
//      Albert Ng   Nov 01 2013     Report ref name with each alignment
//      Albert Ng   Nov 06 2013     Added error handling to GetQueryGroup()
//      Albert Ng   Nov 19 2013     Added chromosomes
//      Albert Ng   Jan 27 2014     Changed to return requests, not changing server state

#include <sstream>
#include <iostream>
#include <queue>
#include <assert.h>
#include <vector>
#include "servercomm.h"
#include "threadqueue.h"
#include "def.h"
#include "alignment.h"

ServerComm::ServerComm(int port) {
  server_.Init(port);
  state_ = PARAMS;
}

ServerComm::~ServerComm() {
}

std::vector<ServerComm::JobRequest> ServerComm::GetQueryGroup(unsigned int* errors) {
  std::vector<ServerComm::JobRequest> new_jobs;

  bool query_group_done = false;
  std::string cur_line = "";
  std::string rcv_buf = "";
  *errors = 0;
  
  server_.Accept(&client_sock_);
  
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
      query_group_done = Action(cur_line, &new_jobs, &line_errors);
      *errors |= line_errors;
      
      // Invalid line check
      if (line_errors != 0) {
        query_group_done = true;
      }

      cur_line = "";
    }
  }
  client_sock_.ShutdownRecv();
  
  return new_jobs;
}

bool ServerComm::Action(std::string line, 
                        std::vector<ServerComm::JobRequest>* new_jobs, 
                        unsigned int* errors) {
  bool query_group_done = false;
  ServerComm::JobRequest job;
  
  std::cout<<line<<std::endl;
  
  switch (state_) {
    case PARAMS : {                           // Store the scoring params
      try {
        SwAffineGapParams params(line);
        
        job.params_job = true;
        job.params = params;
        new_jobs->push_back(job);
        
        params_ = params;
        state_ = QUERIES;
      } catch (std::ios_base::failure &e) {
        *errors |= SYNTAX_ERROR_PARAMS;
        state_ = PARAMS;
      }
      break;
    }
      
    case QUERIES : {
      if (line != END_OF_QUERY_GROUP) {  // Store a query sequence
        std::string query_name;
        std::string query_seq;
        std::string ref_name;
        std::string chr_name;
        long long int ref_start;
        long long int ref_end;
        int threshold;

        
        std::istringstream iss(line);
        iss.exceptions(std::ios::failbit);
        try {
          iss >> query_name;
          iss >> query_seq; 
          iss >> ref_name;
          iss >> chr_name;
          if (chr_name != ALL_CHROM) {
            iss >> ref_start;
            iss >> ref_end;
          }
          iss >> threshold;
          
          job.params_job = false;
          job.query_name = query_name;
          job.query_seq = query_seq;
          job.ref_name = ref_name;
          job.chr_name = chr_name;
          job.ref_start = ref_start;
          job.ref_end = ref_end;
          job.threshold = threshold;
          job.params = params_;
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

void ServerComm::SendAlignment(AlignmentResult res, std::string query_name, std::string ref_name, std::string chr_name) {
  std::stringstream ss;
  
  ss << "Ref: " << ref_name << "\n"
     << "Chr: " << chr_name << "\n"
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
  if (errors & SYNTAX_ERROR_CHRNAME) {
    client_sock_.Send(SYNTAX_ERROR_CHRNAME_STR);
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
  if (errors & SYNTAX_ERROR_QUERYLEN) {
    client_sock_.Send(SYNTAX_ERROR_QUERYLEN_STR);
  }
  if (errors & SYNTAX_ERROR_THRESHOLDMAX) {
    client_sock_.Send(SYNTAX_ERROR_THRESHOLDMAX_STR);
  }
  if (errors == 0) {
    client_sock_.Send(QUERY_GROUP_SUCCESS);
  } else {
    client_sock_.Send(QUERY_GROUP_FAIL);
  }
  client_sock_.Send("\n");
  client_sock_.Close();
}

