//  File Name        : smithwatermanclient.cpp
//  Description      : Client Process main thread
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//      Albert Ng   Oct 28 2913     Completed initial revision

#include "clientsocket.h"
#include "def.h"
#include "fasta.h"
#include "scoring.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <string>

#define QUERY_NAME_FIELD 0
#define REF_NAME_FIELD 1
#define REF_START_FIELD 2
#define REF_END_FIELD 3
#define THRESHOLD_FIELD 4

void SendQuery(ClientSocket* client_socket, std::string descrip, char* seq, int length) {
  std::string seq_str(seq, length);

  std::vector<std::string> fields;
  std::string cur_str = "";
  for (int i = 1; i < descrip.length(); i++) {
    if (!isalpha(descrip[i]) && !isdigit(descrip[i])) {
      fields.push_back(cur_str);
      cur_str = "";
    } else {
      cur_str.push_back(descrip[i]);
    }
  }
  fields.push_back(cur_str);

  client_socket->Send(fields[QUERY_NAME_FIELD]);
  client_socket->Send(" ");
  client_socket->Send(seq_str);
  client_socket->Send(" ");
  client_socket->Send(fields[REF_NAME_FIELD]);
  client_socket->Send(" ");
  client_socket->Send(fields[REF_START_FIELD]);
  client_socket->Send(" ");
  client_socket->Send(fields[REF_END_FIELD]);
  client_socket->Send(" ");
  client_socket->Send(fields[THRESHOLD_FIELD]);
  client_socket->Send("\n");
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: ./smithwatermanclient <QUERY SEQ FASTA FILE1> [<QUERY SEQ FASTA FILE2> ...]\n");
    exit(1);
  }
  
  std::vector<std::string> descrips;
  std::vector<char*> seqs;
  std::vector<int> lengths;
  
  // Parse the files
  for (int i = 1; i < argc; i++) {
    std::string filename(argv[i]);
    ParseFastaFile(filename, &descrips, &seqs, &lengths);
  }
  
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
  
  // RECEIVE AND PRINT ALIGNMENTS
  bool done = false;
  std::string rcv_buf;
  while (done == false) {
    client_socket.Recv(&rcv_buf);
    std::cout << rcv_buf;
    if (rcv_buf.find(END_OF_QUERY_GROUP) != std::string::npos) {
      done = true;
    }
  }
}
  
  
