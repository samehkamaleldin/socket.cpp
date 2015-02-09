//==============================================================================================
// PROJECT   : SOCKET-CPP
// MODULE    : SOCKET-MANAGER CLASS
// AUTHOR    : samehkamaleldin
// SUMMARY   : Definition and of socket manager class that manages socket utilitles
//==============================================================================================

#include <string>
#include <sys/socket.h>

using std :: string;

class SocketManager{

static bool IsPortOpen(int);
static bool IsPortOpen(int,string);

static int    _socket_fd, _node_address_lenght;
static struct sockaddr_in _node_address;

};
