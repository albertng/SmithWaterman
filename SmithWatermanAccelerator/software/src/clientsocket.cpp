//  File Name        : clientsocket.cpp
//  Description      : Client socket class
//
//  Revision History :
//      Albert Ng   Oct 21 2013     Initial Revision
//

#include <string>
#include <arpa/inet.h>
#include "clientsocket.h"

ClientSocket::ClientSocket() {
}

ClientSocket::ClientSocket(std::string host, int port) {
  Create();
  Connect(host, port);
}

ClientSocket::~ClientSocket() {
}

bool ClientSocket::Connect(std::string host, int port) {
  if (sock_fd_ == INVALID) {
    return false;
  }

  sock_addr_.sin_family = AF_INET;
  sock_addr_.sin_port = htons(port);
  inet_pton(AF_INET, host.c_str(), &(sock_addr_.sin_addr));

  return (connect(sock_fd_, (struct sockaddr *) &sock_addr_, sizeof(sock_addr_)) == 0);
}
