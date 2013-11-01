//  File Name        : smithwatermanclient.cpp
//  Description      : Client Process main thread
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 28 2913     Completed initial revision

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>
#include "def.h"
#include "clientsocket.h"
#include "fasta.h"
#include "scoring.h"

static const int QUERY_NAME_FIELD = 0;
static const int REF_NAME_FIELD = 1;
static const int REF_START_FIELD = 2;
static const int REF_END_FIELD = 3;
static const int THRESHOLD_FIELD = 4;

void SendQuery(ClientSocket* client_socket, std::vector<std::string> descrip, char* seq, int length) {
  std::string seq_str(seq, length);

  client_socket->Send(descrip[QUERY_NAME_FIELD]);
  client_socket->Send(" ");
  client_socket->Send(seq_str);
  client_socket->Send(" ");
  client_socket->Send(descrip[REF_NAME_FIELD]);
  client_socket->Send(" ");
  client_socket->Send(descrip[REF_START_FIELD]);
  client_socket->Send(" ");
  client_socket->Send(descrip[REF_END_FIELD]);
  client_socket->Send(" ");
  client_socket->Send(descrip[THRESHOLD_FIELD]);
  client_socket->Send("\n");
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
  client_socket.Send(params.ToString());
  client_socket.Send("\n");
  
  // Send the queries
  for (int i = 0; i < seqs.size(); i++) {
    SendQuery(&client_socket, descrips[i], seqs[i], lengths[i]);
  }

  // Send end of query group packet
  client_socket.Send(END_OF_QUERY_GROUP);
  client_socket.Send("\n");
  
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
  
  
