//  File Name        : clientcomm.cpp
//  Description      : Client Communicator class
//
//  TODO: Add Receive Alignments capability
//
//  Revision History :
//      Albert Ng   Oct 30 2013     Initial Revision
//

#include "clientcomm.h"
#include <string>
#include <assert.h>

ClientComm::ClientComm(std::string host, int port) {
  client_socket_ = new ClientSocket(host, port);
  started_ = false;
  ended_ = false;
}

ClientComm::~ClientComm() {
  delete client_socket_;
}

void ClientComm::StartQueryGroup(SWAffineGapParams params) {
  assert(started_ == false);
  assert(ended_ == false);
  
  started_ = true;
  client_socket_->Send(params.ToString());
  client_socket_->Send("\n");
}

void ClientComm::SendQuery(std::vector<std::string> descrip, char* seq, int length) {
  assert(started_ == true);
  assert(ended_ == false);
  
  std::string seq_str(seq, length);

  client_socket_->Send(descrip[QUERY_NAME_FIELD]);
  client_socket_->Send(" ");
  client_socket_->Send(seq_str);
  client_socket_->Send(" ");
  client_socket_->Send(descrip[REF_NAME_FIELD]);
  client_socket_->Send(" ");
  client_socket_->Send(descrip[REF_START_FIELD]);
  client_socket_->Send(" ");
  client_socket->_Send(descrip[REF_END_FIELD]);
  client_socket->_Send(" ");
  client_socket->_Send(descrip[THRESHOLD_FIELD]);
  client_socket->_Send("\n");
}

void ClientComm::EndQueryGroup() {
  assert(started_ == true);
  assert(ended_ == false);
  
  client_socket_->Send(END_OF_QUERY_GROUP);
  client_socket_->Send("\n");
  
  ended_ == true;
}

