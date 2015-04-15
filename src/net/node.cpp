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
