//  File Name        : clientcomm.h
//  Description      : Client Communicator class definitions
//
//  TODO: Add Receive Alignments capability
//
//  Revision History :
//      Albert Ng   Oct 30 2013     Initial Revision
//

#ifndef CLIENTCOMM_H_
#define CLIENTCOMM_H_

#include "clientsocket.h"
#include "scoring.h"
#include <string>

class ClientComm {
  public:
    ClientComm(std::string host, int port);
    ~ClientComm();
    
    void ClientComm::StartQueryGroup(SWAffineGapParams params);
    void ClientComm::SendQuery(std::vector<std::string> descrip, char* seq, int length);
    void ClientComm::EndQueryGroup();
    
  private:
    ClientSocket* client_socket_;
    bool started_;
    bool ended_;
    
    static const int QUERY_NAME_FIELD = 0;
    static const int REF_NAME_FIELD = 1;
    static const int REF_START_FIELD = 2;
    static const int REF_END_FIELD = 3;
    static const int THRESHOLD_FIELD = 4;
};

#endif // CLIENTCOMM_H_


