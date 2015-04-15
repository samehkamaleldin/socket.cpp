#include <iostream>
#include <tcp/tcp_server.hpp>
#include <sstream>

using std::string;
using std::cout;

void print(Node *nd, string msg)
{
  cout<< nd->ip <<" : " << msg << std::endl;
}

int main(int argc, char** argv)
{
  //initialize default port number and max connection cout
  int port = 12002, max_connection_count= 1000;

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

  server.OnMessage(print);

  //start listening to connections
  int result = server.Listen(max_connection_count);
  if(result != 0)
    cout << "Faild to start server !" << std::endl;

  return 0;
}
