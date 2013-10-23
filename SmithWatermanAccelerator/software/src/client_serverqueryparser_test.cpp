//  File Name        : client_serverqueryparser_test.cpp
//  Description      : Client process of Server Query Parser class test
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//

#include "clientsocket.h"
#include "def.h"
#include "scoring.h"
#include <iostream>

int main(void) {
  ClientSocket client_socket("localhost", 30000);
  client_socket.Send("2 -1 -2 -3 10 -5 -7 7 -102 74 -240 -400\n");
  //sleep(1);
  client_socket.Send("query1 ACGTNGTCANGTNA test1 10 15 100\n");
  //sleep(1);
  client_socket.Send("query2 NGTNA test2 1000 1015 22\n");
  //sleep(1);
  client_socket.Send("query7 ACNGTNA test1 76 95 46\n");
  //sleep(1);
  client_socket.Send("query3 ACGTNGTA test2 4 1015 701\n");
  //sleep(1);
  client_socket.Send(END_OF_QUERY_GROUP);
  client_socket.Send("\n");
  //sleep(1);
  
  ClientSocket client_socket2("localhost", 30000);
  client_socket2.Send("100 -37 22 -3 6 -10 -7 7 -2 47 -141 -230\n");
  //sleep(1);
  client_socket2.Send("query1 ACGTNGTCANGTNA test1 10 15 100\n");
  //sleep(1);
  client_socket2.Send("query2 NGTNA test2 1000 1015 22\n");
  //sleep(1);
  client_socket2.Send(END_OF_QUERY_GROUP);
  client_socket2.Send("\n");
  return 0;
}
