//  File Name        : servercomm.cpp
//  Description      : Server Communicator class
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 29 2013     Requires a new client connection per query group
//      Albert Ng   Nov 01 2013     Report ref name with each alignment
//      Albert Ng   Nov 05 2013     Added error handling to GetQueryGroup()

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
                                         RefSeqManager* ref_seq_manager) {
  std::vector<AlignmentJob> new_jobs;                                    
  std::vector<std::string> query_names;
  std::vector<std::string> query_seqs;
  std::vector<int> query_ids;
  
  bool query_group_done = false;
  bool query_group_good = true;
  std::string cur_line = "";
  std::string rcv_buf;
  
  server_.Accept(&client_sock_);
  
  while (query_group_done == false) {
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
        client_sock_.Send("1");           // Notify client of invalid line
        if (query_group_good == false) {  // Line already invalid once, so terminate query group
          query_group_done == true;
        } else {                          // First time line is invalid
          query_group_good = false;       //   Record that invalid line received
          query_group_done = false;       //   Need client to send again, so can't complete query group
        }
      } else {
        client_sock_.Send("0");           // Notify client of successful line parse
        query_group_good = true;          // Query group is good so far
      }
      cur_line = "";
    }
  }
  
  
  /*while (query_group_done == false) {   
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
      query_group_done = Action(cur_line, &new_jobs, ref_seq_manager, &query_ids, &query_names, &query_seqs, &line_good);
      cur_line = "";
    }
  }*/
  client_sock_.ShutdownRecv();
  
  if (query_group_good == true) {
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
                        bool* line_good) {
  bool query_group_done = false;
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
        *line_good = true;
        break;
      } catch (std::ios_base::failure &e) {
        *line_good = false;
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
          
          *line_good = true;
          state_ = QUERIES;
        } catch (std::ios_base::failure &e) {
          *line_good = false;
          state_ = QUERIES;
          break;
        }
      } else {                                // Done with the query group
        query_group_done = true;
        *line_good = true;
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

void ServerComm::EndQueryGroup() {
  client_sock_.Send(END_OF_QUERY_GROUP);
  client_sock_.Send("\n");
  client_sock_.Close();
}

