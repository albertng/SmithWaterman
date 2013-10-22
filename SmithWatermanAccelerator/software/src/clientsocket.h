//  File Name        : clientsocket.h
//  Description      : Client socket class definitions
//
//  Revision History :
//      Albert Ng   Oct 21 2013     Initial Revision
//

#ifndef CLIENTSOCKET_H_
#define CLIENTSOCKET_H_

#include "socket.h"
#include <string>

class ClientSocket: public Socket {
  public:
    ClientSocket();
    ClientSocket(std::string host, int port);
    virtual ~ClientSocket();

  private:
    bool Connect(std::string host, int port);
};

#endif // CLIENTSOCKET_H_
