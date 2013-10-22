//  File Name        : clientsocket_test.cpp
//  Description      : Client Socket class test
//
//  Revision History :
//      Albert Ng   Oct 21 2013     Initial Revision
//

#include "clientsocket.h"
#include <iostream>

int main(void) {
  ClientSocket client_socket("localhost", 30000);
  
  std::string data = "Test from client!";
  client_socket.Send(data);
  std::string rcv_data;
  client_socket.Recv(&rcv_data);
  std::cout << rcv_data << std::endl;

  return 0;
}
