//==============================================================================================
//= CLASS       : TcpServer                                                                   =
//= Description : TCP Server module that creates and manages an instance of a tcp server       =
//==============================================================================================

#ifndef _TCP_SERVER_
#define _TCP_SERVER_

#include <iostream>
#include <string>
#include <cstring>      // Needed for memset
#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <netinet/in.h> // Needed for internet addresses

#define _MSG_BUFFER_SIZE_ 1000

using std::string;
using std::cout;

class TcpServer{

public:

  // initialize an new tcp server instance
  TcpServer(int);

  // start listening at specified port
  int Listen(int);

  // stop tcp server
  void Stop();

private:

  // address structure for both server and client
  struct sockaddr_in _server_address,_client_address;

  // sockets file discriptors and message length variable
  int    _listenfd , _connfd, _message_length, _port;

  // socket address length variable
  socklen_t _client_address_length;

  // child proceess id
  pid_t  _childpid;

  // array of characters that represents a message
  char _message[ _MSG_BUFFER_SIZE_ ];

  // ingeter represents a flag of stop server required
  int _stop_server_flag;
};

#endif
