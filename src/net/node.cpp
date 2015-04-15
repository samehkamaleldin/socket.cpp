//==============================================================================================
//= CLASS       : Node                                                                         =
//= Description : Node module that manages an instance of node network                         =
//==============================================================================================

#include <net/node.hpp>

// Create a new instance of class node
Node :: Node()
{

  name = "";
  ip   = "0.0.0.0";
  type = "";

  // initialize terminate connection flag
  terminate_connection_flag = 0;

  //initialize self and host address values
  bzero( &self_address , sizeof(self_address) );
  bzero( &host_address , sizeof(host_address) );
}

// Create a new instance of class node
Node :: Node(int port_number)
{
  terminate_connection_flag = 0;

  //initialize self and host address values
  bzero( &self_address , sizeof(self_address) );
  bzero( &host_address , sizeof(host_address) );

  port = port_number;
}

// Create a new instance of class node
Node :: Node(string _name, string _ip, string _type)
{
  this->name = _name;
  this->ip   = _ip;
  this->type = _type;
}

// ---------------------------------------------------------------------------------------------
// Summary : Get IP address v4 or v6 from sockaddr_in struct
// Input  :-
//         > [sockaddr_in] socketAddress : the port number to be checked
// ---------------------------------------------------------------------------------------------
void Node :: SetIPFromSocketAddress(struct sockaddr *socketAddress)
{

  if (socketAddress -> sa_family == __type_internet_domain_sockets__)
  {
    struct sockaddr_in* pV4Addr = (struct sockaddr_in*)&socketAddress;
    char str_ip4[INET_ADDRSTRLEN];
    int ip4Addr = pV4Addr -> sin_addr.s_addr;
    inet_ntop( __type_internet_domain_sockets__, &ip4Addr, str_ip4, INET_ADDRSTRLEN);
    std::string node_ip(str_ip4);
    this -> ip = node_ip;
  }
  else
  {
    struct sockaddr_in6* pV6Addr = (struct sockaddr_in6*)&socketAddress;
    in6_addr ip6Addr = pV6Addr -> sin6_addr;
    char str_ip6[INET6_ADDRSTRLEN];
    inet_ntop( AF_INET6, &ip6Addr, str_ip6, INET6_ADDRSTRLEN );
    std::string node_ip(str_ip6);
    this -> ip = node_ip;
  }
}
