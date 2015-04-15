//=============================================================================================
// CLASS       : client                                                                    =
// Description : TCP Client module that creates and manages an instance of a tcp client       =
//=============================================================================================

#ifndef _TCP_CLIENT_HPP_
#define _TCP_CLIENT_HPP_

#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <netinet/in.h> // Needed for internet addresses

// library specific headers
#include <net/node.hpp>
#include <net/utils.hpp>

using namespace std;

namespace tcp{
  class client : public Node
  {

  public:

    // initialize a new tcp client instance
    client(string, int);

    // connect to host node
    void Connect(void);

    // send message to currently connected host node
    void Send(string);

    // send typed message to currently connected host node
    void Send(string,string);

    // send message to specific connected socket address
    void Send(struct sockaddr*, string);

    // send typed message to specific connected socket address
    void Send(struct sockaddr*,string,string);

    // Stop connection with host
    void Stop();

  private:

    // child proceess id
    pid_t  _childpid;

  };
}
#endif
