//=============================================================================================
// CLASS       : client                                                                    =
// Description : TCP Client module that creates and manages an instance of a tcp client       =
//=============================================================================================

#include <tcp/tcp_client.hpp>

#include <cstring>
#include <iostream>

namespace tcp{
  // ---------------------------------------------------------------------------------------------
  // Summary        : Create new instance of tcp client class (Class constructor)
  //
  // Pre-Condition  : None
  // Post-Condition : None
  //
  // Input :-
  //        > [string] host_address_name : address name of the host i.e ["192.186.0.4"]
  //        > [int]    port_number       : port of host node i.e [8080]
  //
  // Output:-
  //        > None
  // ---------------------------------------------------------------------------------------------
  client :: client (string host_address_name, int port_number) : Node(port_number)
  {

    // initialize host address struct
    host_address.sin_family      = __type_internet_domain_sockets__;
    host_address.sin_addr.s_addr = inet_addr( host_address_name.c_str() );
    host_address.sin_port        = htons(port_number);

    // initialize connection socket
    socket_fd = socket( __type_internet_domain_sockets__ , __type_byte_stream_socket__ , 0 );

  }

  // ---------------------------------------------------------------------------------------------
  // Summary : Connect to host node
  // ---------------------------------------------------------------------------------------------
  void client :: Connect ()
  {
    // Connect to host node
    connect( socket_fd, (struct sockaddr *)&host_address, sizeof(host_address) );

    // spawn a new proceess to recieve messages
    if ((_childpid = fork()) == 0)
    {
      // wait for messages from host node
      while(!terminate_connection_flag){

        // recieve incoming message from host
        incoming_message_length = recvfrom(socket_fd,incoming_message,_MSG_BUFFER_SIZE_,0,NULL,NULL);

        // check if message is not empty
        if(incoming_message_length > 0){

          //put trailing character
          incoming_message[incoming_message_length] = 0;

          //print the message [for testing purposes]
          cout << "message: " << incoming_message << std::endl;
        }
      }

      // check if terminate connection flag is on
      if(terminate_connection_flag)
      {
        // close host connection socket
        close(socket_fd);

        // reset terminate connection flag
        terminate_connection_flag = 0;
      }
    }
  }

  // ---------------------------------------------------------------------------------------------
  // Summary      : Send message to currently connected host
  // Pre-Condition: client must has an open connection with host
  // ---------------------------------------------------------------------------------------------
  void client :: Send(string message)
  {
    try{
      // send the message to host's open socket
      sendto( socket_fd, message.c_str(), strlen(message.c_str()), 0, (struct sockaddr *)&host_address,sizeof(host_address));
    }
    catch(int exp){

    }
  }
}
