//==============================================================================================
//= CLASS       : TcpServer                                                                    =
//= Description : TCP Server module that creates and manages an instance of a tcp server       =
//==============================================================================================

#include <tcp/tcp_server.hpp>

// Create new tcp server instance
TcpServer :: TcpServer (int portNumber)
{
  //initalize port number and stop server flag
  _port             = portNumber;
  _stop_server_flag = 0;

  // initialize the server address struct with zero byte stream
  bzero(&_server_address, sizeof(_server_address));

  _server_address.sin_family      = AF_INET;           // IP version not specified. Can be both.
  _server_address.sin_addr.s_addr = htonl(INADDR_ANY); // make server accept all addresses
  _server_address.sin_port        = htons(_port);       // Set port number in type [network byte order]

  // initalize socket with [internet addresses, socket stream sequences with default protocol]
  _listenfd = socket( AF_INET, SOCK_STREAM, 0);

  // bind the address name and port number to the scoket address struct
  bind(_listenfd,(struct sockaddr *)&_server_address,sizeof(_server_address));

}

// start listening at specified port with limited number of connections at the same time
void TcpServer :: Listen (int accepted_num_of_connections){

  // start listening to the port
  cout << "Start listening at port " << _port << std::endl;
  listen(_listenfd, accepted_num_of_connections);

  // forever loop for accepting connections
  while(1)
  {
    if(_stop_server_flag)
    {
      cout << "Server is stopped !";
      _stop_server_flag = 0;
      break;
    }
    // initialize client address struct and accept new connection
    _client_address_length = sizeof( _client_address_length);

    _connfd = accept( _listenfd, (struct sockaddr *)&_client_address, &_client_address_length);

    // skip iteration if no incoming connections
    if(_connfd == -1)
      continue;

    cout << "Connection accepted - " << _connfd << std::endl;

    // spawn a new proceess to recieve messages
    if ((_childpid = fork()) == 0)
    {

      close(_listenfd);
      // forever loop for accepting messages
      while(1)
      {
        // recieve a message from client to msg buffer
        _message_length = recvfrom( _connfd, _message, _MSG_BUFFER_SIZE_, 0, (struct sockaddr *)&_client_address,&_client_address_length);

        // check if there is no more messages
        if(_message_length <= 0)
        {
          close(_connfd);
          cout << "Connection lost - " << _connfd << std::endl;
          break;
        }

        // put trailing characters
        _message[_message_length] = 0;

        // send back the received message [ For testing purposes]
        sendto(_connfd,_message,_message_length,0,(struct sockaddr *)&_client_address,sizeof(_client_address));

        // print the received message
        cout << "Message: " << _message << std::endl;
      }
    }
  }
}
