//  File Name        : serversocket.cpp
//  Description      : Server socket class
//
//  Revision History :
//      Albert Ng   Oct 21 2013     Initial Revision
//      Albert Ng   Oct 29 2013     Added ShutdownRecv()

#include <arpa/inet.h>
#include "serversocket.h"

ServerSocket::ServerSocket() {
}

ServerSocket::ServerSocket(int port) {
  Init(port);
}

void ServerSocket::Init(int port) {
  Create();
  Bind(port);
  Listen();
}

ServerSocket::~ServerSocket() {
}

bool ServerSocket::Bind(int port) {
  if (sock_fd_ == INVALID) {
    return false;
  }

  sock_addr_.sin_family = AF_INET;
  sock_addr_.sin_addr.s_addr = INADDR_ANY;
  sock_addr_.sin_port = htons(port);

  return (bind(sock_fd_, (struct sockaddr *) &sock_addr_, sizeof(sock_addr_)) != -1);
}

bool ServerSocket::Listen() {
  if (sock_fd_ == INVALID) {
    return false;
  }

  return (listen(sock_fd_, MAX_NUM_CONNECTIONS) != -1);
}

bool ServerSocket::Accept(Socket* new_sock) {
  socklen_t addr_len = sizeof(sock_addr_);
  int new_sock_fd = accept(sock_fd_, (struct sockaddr *) &sock_addr_, &addr_len);
  new_sock->SetSockFD(new_sock_fd);

  return (new_sock_fd > 0);
}

bool ServerSocket::ShutdownRecv() {
  if (sock_fd_ == INVALID) {
    return false;
  }
  
  return shutdown(sock_fd_, SHUT_RD);
}
