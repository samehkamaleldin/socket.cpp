#include <iostream>
#include <tcp/tcp_server.hpp>
#include <sstream>

int main(int argc, char** argv)
{
  //initalize default port number and max connection cout
  int port = 12001, max_connection_count= 1000;

  // check if there are any passed arguments
  if(argc > 1)
  {
    // initialize string stream from argument
    std::istringstream arg_stream(argv[1]);

    // bind arguments stream to port int variable if valid
    if ( !(arg_stream >> port) )
      std::cerr << "Invalid number " << argv[1] << '\n';
  }

  // create server instance with specified port number
  TcpServer server(port);

  //start listening to connections
  server.Listen(max_connection_count);

  return 0;
}
