//==============================================================================================
//= CLASS       : TCP_Server                                                                   =
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

using std::string;
using std::cout;

class TCP_Server{

public:

  // initialize an new tcp server instance
  TCP_Server();

  // start listening at specified port
  void Listen(int);

  // stop tcp server
  void Stop();

private:

  // address structure for both server and client
  struct sockaddr_in server_address,client_address;

  // sockets file discriptors and message length variable
  int    listenfd , connfd, msg_len, port;

  // socket address length variable
  socklen_t clilen;

  // child proceess id
  pid_t     childpid;

  // array of characters that represents a message
  char msg[1000];
};

#endif
