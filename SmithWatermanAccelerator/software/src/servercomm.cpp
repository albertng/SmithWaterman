//  File Name        : servercomm.cpp
//  Description      : Server Communicator class
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 29 2013     Requires a new client connection per query group

#include "servercomm.h"
#include "threadqueue.h"
#include "scoring.h"
#include <sstream>
#include "def.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "alignment.h"
#include <iostream>

ServerComm::ServerComm(int port) {
  server_.Init(port);
  state_ = PARAMS;
}

ServerComm::~ServerComm() {
}

std::list<int> ServerComm::GetQueryGroup(ThreadQueue<AlignmentJob>* alignment_job_queue, 
                                           QuerySeqManager* query_seq_manager,
                                           RefSeqManager* ref_seq_manager) {
  std::list<int> query_ids;
  bool query_group_done = false;
  std::string cur_line = "";
  std::string rcv_buf = "";
  
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
      query_group_done = Action(cur_line, alignment_job_queue, query_seq_manager, ref_seq_manager, &query_ids);
      cur_line = "";
    }
  }
  client_sock_.ShutdownRecv();
  
  return query_ids;
}

bool ServerComm::Action(std::string line, 
                        ThreadQueue<AlignmentJob>* alignment_job_queue, 
                        QuerySeqManager* query_seq_manager,
                        RefSeqManager* ref_seq_manager,
                        std::list<int>* query_ids) {
  bool query_group_done = false;
  //std::cout<<"Action line: "<<line<<std::endl;
  switch (state_) {
    case PARAMS : {                           // Store the scoring params
      SwAffineGapParams params(line);
      AlignmentJob params_job;
      params_job.query_id = PARAMS_JOB;
      params_job.params = params;
      alignment_job_queue->Push(params_job);
      //std::cout<<"Alignment params job: "<<params_job.query_id<< " "<<params_job.ref_id<<" "<<params_job.ref_offset<<" "<<params_job.ref_len<<" "<<params_job.threshold<<" "<<params_job.params.ToString()<<std::endl;
      params_ = params;
      state_ = QUERIES;
      break;
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
        //std::cout<<"Alignment job: "<<job.query_id<< " "<<job.ref_id<<" "<<job.ref_offset<<" "<<job.ref_len<<" "<<job.threshold<<" "<<job.params.ToString()<<std::endl;
        alignment_job_queue->Push(job);
        
        state_ = QUERIES;
      } else {                                // Done with the query group
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

void ServerComm::SendAlignment(AlignmentResult res, std::string query_name) {
  std::stringstream ss;
  
  ss << "Query: " << query_name << "\tScore: " << res.score << "\n"
     << res.alignment.ToString() << "\n";

  client_sock_.Send(ss.str());
}

void ServerComm::EndQueryGroup() {
  client_sock_.Send(END_OF_QUERY_GROUP);
  client_sock_.Send("\n");
  client_sock_.Close();
}

