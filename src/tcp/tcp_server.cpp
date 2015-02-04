//==============================================================================================
//= CLASS       : TCP_Server                                                                   =
//= Description: TCP Server module that creates and manages an instance of a tcp server        =
//==============================================================================================

#include "tcp_server.hpp"

// Create new tcp server instance
TCP_Server :: TCP_Server ()
{
  port = 12345;

  // initialize the server address struc with zero byte stream
  bzero(&server_address, sizeof(server_address));

  server_address.sin_family      = AF_INET;           // IP version not specified. Can be both.
  server_address.sin_addr.s_addr = htonl(INADDR_ANY); // make server accept all addresses
  server_address.sin_port        = htons(32000);       // Set port number in type [network byte order]

  // initalize socket with [internet addresses, socket stream sequences with default protocol]
  listenfd = socket( AF_INET, SOCK_STREAM, 0);

  // bind the address name and port number to the scoket address struct
  bind(listenfd,(struct sockaddr *)&server_address,sizeof(server_address));

}

// start listening at specified port with limited number of connections at the same time
void TCP_Server :: Listen (int acceptedNumOfConnection){

  // start listening
  cout << "Star listening at port " << port << std::endl;
  listen(listenfd, acceptedNumOfConnection);

  // forever loop for accepting connections
  while(1)
  {
    // initialize client address struct and accept new connection
    clilen = sizeof( clilen);

    connfd = accept( listenfd, (struct sockaddr *)&client_address, &clilen);

    // skip iteration if no incoming connections
    if(connfd == -1)
      continue;

    cout << "connection accepted - " << connfd << std::endl;

    // spawn a new proceess to recieve messages
    if ((childpid = fork()) == 0)
    {

      close(listenfd);
      // forever loop for accepting messages
      while(1)
      {
        // recieve a message from client to msg buffer
        msg_len      = recvfrom(connfd,msg,1000,0,(struct sockaddr *)&client_address,&clilen);

        // check if there is no more messages
        if(msg_len <= 0)
        {
          close(connfd);
          close(listenfd);
          cout << "Connection lost - " << listenfd << std::endl;
          break;
        }

        // put trailing characters
        msg[msg_len] = 0;

        cout << "Message received ... " << std::endl;

        // send back the received message
        sendto(connfd,msg,msg_len,0,(struct sockaddr *)&client_address,sizeof(client_address));

        // print the received message
        cout << "Message: " << msg << std::endl;
      }
    }
  }
}
