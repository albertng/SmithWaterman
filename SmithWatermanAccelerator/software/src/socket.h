//  File Name        : socket.h
//  Description      : Basic socket class definitions
//
//  Revision History :
//      Albert Ng   Oct 21 2013     Initial Revision
//

#ifndef SOCKET_H_
#define SOCKET_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>

#define RECV_BUF_SIZE 1024

class Socket {
  public:
    Socket();
    virtual ~Socket();

    bool Send(std::string s);
    int  Recv(std::string* s);

    void SetSockFD(int sock_fd);

  protected:
    bool Create();
    int sock_fd_;
    sockaddr_in sock_addr_;
    static const int INVALID = -1; // Invalid socket file descriptor value
};

#endif // SOCKET_H_
