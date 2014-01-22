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
//      Albert Ng   Nov 19 2013     Send chromosome name
//      Albert Ng   Jan 16 2013     Added HOXD55, HOXD70
//      Albert Ng   Jan 21 2014     Added file positions

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
static const int CHR_NAME_FIELD = 2;
static const int REF_START_FIELD = 3;
static const int REF_END_FIELD = 4;
static const int THRESHOLD_FIELD = 5;

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
     << descrip[CHR_NAME_FIELD] << " ";
  if (descrip.size() == 5) {
    ss << descrip[THRESHOLD_FIELD - 2];
  } else {
    ss << descrip[REF_START_FIELD] << " " 
       << descrip[REF_END_FIELD] << " "
       << descrip[THRESHOLD_FIELD];
  }

  return TrySend(client_socket, ss.str());
}

bool SendEndOfQueryGroup(ClientSocket* client_socket) {
  return TrySend(client_socket, END_OF_QUERY_GROUP);
}
  
void PrintQuery(std::vector<std::string> descrip, char* seq, int length) {
  std::string seq_str(seq, length);
  std::cout << descrip[QUERY_NAME_FIELD] << " "
            << seq_str << " " 
            << descrip[REF_NAME_FIELD] << " "
            << descrip[REF_START_FIELD] << " "
            << descrip[REF_END_FIELD] << " "
            << descrip[THRESHOLD_FIELD]<<std::endl;
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

bool CheckQueryFileParse(std::string filename, std::vector<std::string> descrips, char* seq, int length) {
  int start;
  int end;
  int threshold;
  
  // Check number of description fields
  if (descrips.size() != 6 && (descrips.size() != 4 || descrips[CHR_NAME_FIELD] != ALL_CHROM)) {
    std::cerr << descrips[QUERY_NAME_FIELD] << ": Unexpected number of fields in sequence description" << std::endl;
    return false;
  }
  
  if (descrips.size() == 4) {
    if (descrips[CHR_NAME_FIELD] != ALL_CHROM) {
      std::cerr << descrips[QUERY_NAME_FIELD] << ": Expected " << ALL_CHROM << "in field " << CHR_NAME_FIELD+1 << " in sequence description" << std::endl;
      return false;
    } else {
      std::vector<std::string> coords;
      coords.push_back("1");
      coords.push_back("2");
      
      std::vector<std::string>::iterator it = descrips.begin();
      descrips.insert(it + REF_START_FIELD, coords.begin(), coords.end());
    }
  }
  
  // Check start coordinate
  if (descrips.size() == 6) {
    std::istringstream iss1(descrips[REF_START_FIELD]);
    iss1.exceptions(std::ios::failbit);
    try {
      iss1 >> start;
      //std::cout<<start<<std::endl;
      if (start < 1) {
        std::cerr << descrips[QUERY_NAME_FIELD] << ": Invalid ref seq start coordinate " << descrips[REF_START_FIELD] << std::endl;
        return false;
      }
    } catch (std::ios_base::failure &e) {
      std::cerr << descrips[QUERY_NAME_FIELD] << ": Invalid ref seq start coordinate " << descrips[REF_START_FIELD] << std::endl;
      return false;
    }
    
    // Check end coordinate
    std::istringstream iss2(descrips[REF_END_FIELD]);
    iss2.exceptions(std::ios::failbit);
    try {
      iss2 >> end;
      //std::cout<<end<<std::endl;
      if (end <= start) {
        std::cerr << descrips[QUERY_NAME_FIELD] << ": Ref seq end before ref seq start coordinate " << descrips[REF_END_FIELD] << std::endl;
        return false;
      }
    } catch (std::ios_base::failure &e) {
      std::cerr << descrips[QUERY_NAME_FIELD] << ": Invalid ref seq end coordinate " << descrips[REF_END_FIELD] << std::endl;
      return false;
    }
  }
  
  // Check threshold
  std::istringstream iss3(descrips[THRESHOLD_FIELD]);
  iss3.exceptions(std::ios::failbit);
  try {
    iss3 >> threshold;
    //std::cout<<threshold<<std::endl;
    if (threshold < 0) {
      std::cerr << descrips[QUERY_NAME_FIELD] << ": Invalid threshold " << descrips[THRESHOLD_FIELD] << std::endl;
      return false;
    }
  } catch (std::ios_base::failure &e) {
    std::cerr << descrips[QUERY_NAME_FIELD] << ": Invalid threshold " << descrips[THRESHOLD_FIELD] << std::endl;
    return false;
  }
  
  // Check query sequence characters
  for (int i = 0; i < length; i++) {
    if (seq[i] != 'n' && seq[i] != 'N' &&
        seq[i] != 'a' && seq[i] != 'A' &&
        seq[i] != 'g' && seq[i] != 'G' &&
        seq[i] != 'c' && seq[i] != 'C' &&
        seq[i] != 't' && seq[i] != 'T') {
      std::cerr << "Error in " << filename << ", " << descrips[QUERY_NAME_FIELD] << ": Invalid query seq char " << seq[i] << std::endl;
      return false;
    }
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
  std::vector<long long int> fileposs;
  
  // Parse the files
  bool parse_good = true;
  for (int i = 1; i < argc; i++) {
    std::string filename(argv[i]);
    ParseFastaFile(filename, &descrips, &seqs, &lengths, &fileposs);
    
    if (!CheckQueryFileParse(filename, descrips[i-1], seqs[i-1], lengths[i-1])) {
      parse_good = false;
    }
  }
  
  if (parse_good) {
    // Connect to server
    ClientSocket client_socket("localhost", 30000);
    
    // Send query group
    //SwAffineGapParams params("2 -2 -2 -2 2 -2 -2 2 -2 2 -2 -1"); // Simple scoring
    SwAffineGapParams params("91 -90 -25 -100 100 -100 -25 100 -90 91 -400 -30"); // HOXD55
    //SwAffineGapParams params("91 -114 -31 -123 100 -125 -31 100 -114 91 -400 -30"); // HOXD70
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
}
  
  
