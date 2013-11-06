//  File Name        : smithwatermanclient.cpp
//  Description      : Client Process main thread
//
//  TODO: FASTA file syntax checker
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 28 2913     Completed initial revision
//      Albert Ng   Nov 05 2013     Added handshaking
//      Albert Ng   Nov 06 2013     Removed handshaking

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
  if (!client_socket->Send(msg)) {
    return false;
  }
  return client_socket->Send("\n");
}

bool SendParams(ClientSocket* client_socket, SwAffineGapParams params) {
  return TrySend(client_socket, params.ToString());
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

  return TrySend(client_socket, ss.str());
}

bool SendEndOfQueryGroup(ClientSocket* client_socket) {
  return TrySend(client_socket, END_OF_QUERY_GROUP);
}
  
void PrintQuery(std::vector<std::string> descrip, char* seq, int length) {
  std::string seq_str(seq, length);
  std::cout<<descrip[QUERY_NAME_FIELD]<<" "<<seq_str<<" "<<descrip[REF_NAME_FIELD]<<" "
          <<descrip[REF_START_FIELD]<<" "<<descrip[REF_END_FIELD]<<" "<<descrip[THRESHOLD_FIELD]<<std::endl;
}

bool SendQueryGroup(ClientSocket* client_socket,
                    SwAffineGapParams params,
                    std::vector<std::vector<std::string> > descrips, 
                    std::vector<char*> seqs, 
                    std::vector<int> lengths) {
  if (!SendParams(client_socket, params)) {
    return false;
  }
  
  for (int i = 0; i < seqs.size(); i++) {
    if (!SendQuery(client_socket, descrips[i], seqs[i], lengths[i])) {
      return false;
    }
  }
  
  if (!SendEndOfQueryGroup(client_socket)) {
    return false;
  }
  
  return true;
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
  
  // Send query group
  SwAffineGapParams params("2 -2 -2 -2 2 -2 -2 2 -2 2 -2 -1");
  SendQueryGroup(&client_socket, params, descrips, seqs, lengths);

  // Receive and print alignments
  bool done = false;
  std::string rcv_buf;
  std::string out_str = "";
  while (done == false) {
    client_socket.Recv(&rcv_buf);
    out_str += rcv_buf;
    if (rcv_buf.find(QUERY_GROUP_SUCCESS) != std::string::npos ||
        rcv_buf.find(QUERY_GROUP_FAIL) != std::string::npos) {
      done = true;
    }
  }

  std::cout << out_str << std::flush;
}
  
  
