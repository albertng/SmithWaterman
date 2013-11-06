//  File Name        : smithwatermanclient.cpp
//  Description      : Client Process main thread
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 28 2913     Completed initial revision
//      Albert Ng   Nov 05 2013     Added handshaking

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <assert.h>
#include <sstream>
#include "def.h"
#include "clientsocket.h"
#include "fasta.h"
#include "scoring.h"

static const int QUERY_NAME_FIELD = 0;
static const int REF_NAME_FIELD = 1;
static const int REF_START_FIELD = 2;
static const int REF_END_FIELD = 3;
static const int THRESHOLD_FIELD = 4;

bool TrySend(ClientSocket* client_socket, std::string msg) {
  std::string rcv_buf;
  
  // Send the message
  client_socket->Send(msg);
  client_socket->Send("\n");
  
  // Receive success acknowledgement
  client_socket->Recv(&rcv_buf);
  assert(rcv_buf.length() == 1);
  
  return (rcv_buf[0] == '0');
}

bool SendParams(ClientSocket* client_socket, SwAffineGapParams params) {
  bool success = TrySend(client_socket, params.ToString());
  if (!success) {
    success = TrySend(client_socket, params.ToString());
  }
  return success;
}

bool SendQuery(ClientSocket* client_socket, std::vector<std::string> descrip, char* seq, int length) {
  std::string seq_str(seq, length);
  std::stringstream ss;
  ss << descrip[QUERY_NAME_FIELD] << " " 
     << seq_str << " " 
     << descrip[REF_NAME_FIELD] << " " 
     << descrip[REF_START_FIELD] << " " 
     << descrip[REF_END_FIELD] << " "
     << descrip[THRESHOLD_FIELD];

  bool success = TrySend(client_socket, ss.str());
  if (!success) {
    success = TrySend(client_socket, ss.str());
  }
  return success;
}

bool SendEndOfQueryGroup(ClientSocket* client_socket) {
  bool success = TrySend(client_socket, END_OF_QUERY_GROUP);
  if (!success) {
    success = TrySend(client_socket, END_OF_QUERY_GROUP);
  }
  return success;
}
  
void PrintQuery(std::vector<std::string> descrip, char* seq, int length) {
  std::string seq_str(seq, length);
  std::cout<<descrip[QUERY_NAME_FIELD]<<" "<<seq_str<<" "<<descrip[REF_NAME_FIELD]<<" "
          <<descrip[REF_START_FIELD]<<" "<<descrip[REF_END_FIELD]<<" "<<descrip[THRESHOLD_FIELD]<<std::endl;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: ./smithwatermanclient <QUERY SEQ FASTA FILE1> [<QUERY SEQ FASTA FILE2> ...]\n");
    exit(1);
  }
  
  std::vector<std::vector<std::string> > descrips;
  std::vector<char*> seqs;
  std::vector<int> lengths;
  
  // Parse the files
  for (int i = 1; i < argc; i++) {
    std::string filename(argv[i]);
    ParseFastaFile(filename, &descrips, &seqs, &lengths);
  }
  
  // Connect to server
  ClientSocket client_socket("localhost", 30000);
  
  // Send the parameters
  SwAffineGapParams params("2 -2 -2 -2 2 -2 -2 2 -2 2 -2 -1");
  if (!SendParams(&client_socket, params)) {
    std::cerr << "Error: Invalid parameter set " << params.ToString() << std::endl;
    exit(1);
  }
  
  // Send the queries
  for (int i = 0; i < seqs.size(); i++) {
    if (!SendQuery(&client_socket, descrips[i], seqs[i], lengths[i])) {
      std::cerr << "Error: Invalid query " << std::endl;
      std::cerr << ">";
      for (int j = 0; j < descrips[i].size(); j++) {
        std::cerr << descrips[i][j] << " ";
      }
      std::cerr << "\n";
      std::string query_str(seqs[i], lengths[i]);
      std:: cerr << query_str << std::endl;
      exit(1);
    }
    //PrintQuery(descrips[i], seqs[i], lengths[i]);
  }

  // Send end of query group packet
  if (!SendEndOfQueryGroup(&client_socket)) {
    std::cerr << "Error: Invalid End Of Query Group msg " << END_OF_QUERY_GROUP << std::endl;
    exit(1);
  }
  
  // Print what was sent
  std::cout<<params.ToString()<<std::endl;
  for (int i = 0; i < seqs.size(); i++) {
    PrintQuery(descrips[i], seqs[i], lengths[i]);
  }
  std::cout<<END_OF_QUERY_GROUP<<std::endl;
  
  // Receive and print alignments
  bool done = false;
  std::string rcv_buf;
  while (done == false) {
    client_socket.Recv(&rcv_buf);
    std::cout << rcv_buf;
    if (rcv_buf.find(END_OF_QUERY_GROUP) != std::string::npos) {
      done = true;
    }
  }
  std::cout << std::flush;
}
  
  
