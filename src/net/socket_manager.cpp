//==============================================================================================
// PROJECT   : SOCKET-CPP
// MODULE    : SOCKET-MANAGER CLASS
// AUTHOR    : samehkamaleldin
// SUMMARY   : Impelementation and of socket manager class that manages socket utilitles
//==============================================================================================

#include <net/socket_manager.hpp>  // for linkage with the class header file
#include <net/utils.hpp>           // for using our defined macros
#include <strings.h>               // for using bzero function
#include <sys/socket.h>            // Needed for the socket functions
#include <netdb.h>                 // Needed for the socket functions
#include <netinet/in.h>            // Needed for internet addresses
#include <errno.h>                 // for using error number macros
#include <arpa/inet.h>             // Needed for internet addresses

// ---------------------------------------------------------------------------------------------
// Definition of static members
// ---------------------------------------------------------------------------------------------
int    SocketManager :: _socket_fd;
int    SocketManager ::  _node_address_lenght;

struct sockaddr_in SocketManager :: _node_address;


// ---------------------------------------------------------------------------------------------
// Summary : Check if port is open in current machine
// Input  :-
//         > [int] port_number : the port number to be checked
// Output :-
//         > [bool] return: boolean true if port is open and false otherwise
// ---------------------------------------------------------------------------------------------
bool SocketManager :: IsPortOpen (int port_number){

  // initialize the node address struct with zero byte stream
  bzero(&_node_address, sizeof(_node_address));

  _node_address.sin_family      = __type_internet_domain_sockets__; // IP version not specified. Can be both.
  _node_address.sin_addr.s_addr = htonl(INADDR_ANY);                // make server accept all addresses
  _node_address.sin_port        = htons(port_number);               // Set port number in type [network byte order]

  // initialize socket with [internet addresses, socket stream sequences with default protocol]
  _socket_fd = socket( __type_internet_domain_sockets__ , __type_byte_stream_socket__ , 0 );

  // bind the address name and port number to the scoket address struct
  int bind_result   = bind(_socket_fd,(struct sockaddr *)&_node_address,sizeof(_node_address));

  // check the bind result
  if (bind_result != 0 && errno == EADDRINUSE)
    return true;
  else
    return false;
}

// ---------------------------------------------------------------------------------------------
// Summary : Check if port is open in a machine with specified address
// Input  :-
//         > [int] port_number : the port number to be checked
//         > [int] address     : address of machine to be checked
// Output :-
//         > [bool] return: boolean true if port is open and false otherwise
// ---------------------------------------------------------------------------------------------
bool SocketManager :: IsPortOpen (int port_number, string address){
  // initialize the node address struct with zero byte stream
  bzero(&_node_address, sizeof(_node_address));

  _node_address.sin_family      = __type_internet_domain_sockets__; // IP version not specified. Can be both.
  _node_address.sin_addr.s_addr = inet_addr( address.c_str() );     // Set node address name
  _node_address.sin_port        = htons(port_number);               // Set port number in type [network byte order]

  // initialize socket with [internet addresses, socket stream sequences with default protocol]
  _socket_fd = socket( __type_internet_domain_sockets__ , __type_byte_stream_socket__ , 0 );

  // bind the address name and port number to the scoket address struct
  int bind_result   = bind(_socket_fd,(struct sockaddr *)&_node_address,sizeof(_node_address));

  // check the bind result
  if (bind_result != 0 && errno == EADDRINUSE)
    return true;
    else
      return false;
}
