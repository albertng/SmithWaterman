//  File Name        : serversocket.h
//  Description      : Server socket class definitions
//
//  Revision History :
//      Albert Ng   Oct 21 2013     Initial Revision
//

#ifndef SERVERSOCKET_H_
#define SERVERSOCKET_H_

#include "socket.h"

#define MAX_NUM_CONNECTIONS 5

class ServerSocket: public Socket {
  public:
    ServerSocket();
    ServerSocket(int port);
    virtual ~ServerSocket();
    bool Accept(Socket* new_sock);

  private:
    bool Bind(int port);
    bool Listen();
};

#endif // SERVERSOCKET_H_
