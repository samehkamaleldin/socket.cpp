//==============================================================================================
//= CLASS       : Node                                                                         =
//= Description : Node module that manages an instance of node network                         =
//==============================================================================================

#ifndef _NODE_HPP_
#define _NODE_HPP_

#include <iostream>
#include <string>
#include <cstring>      // Needed for memset
#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <netinet/in.h> // Needed for internet addresses
#include <unistd.h>
#include <arpa/inet.h>

#include <net/utils.hpp>

using std::string;

// define global macros
#define _MSG_BUFFER_SIZE_       2048
#define _MAX_ADDRESS_NAME_      1024
#define _MAX_OTHER_CONNECTIONS_ 2048

class Node{

private:
  int _self_socket;

public:
  // initialize an new tcp server instance
  Node();
  Node(int);
  Node(string,string,string);

  std::string ip;
  std::string name;
  std::string type;

  void SetIPFromSocketAddress(struct sockaddr *socketAddress);

protected:

  // address structure for both server and client
  struct sockaddr_in  self_address, host_address;
  struct sockaddr_in *other_addresses;

  // sockets file discriptors, message length variable and other integer variables
  int socket_fd, incoming_message_length, outgoing_message_length, port, terminate_connection_flag;

  // socket address length variable
  socklen_t client_address_length, server_address_lenght;

  // array of characters that represents a message
  char incoming_message[ _MSG_BUFFER_SIZE_ ];
  char outgoing_message[ _MSG_BUFFER_SIZE_ ];

  // the address name string
  char address_name[_MAX_ADDRESS_NAME_];
};

#endif
