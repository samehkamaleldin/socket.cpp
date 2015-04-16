# socket.cpp [![Build Status](https://travis-ci.org/samehkamaleldin/socket.cpp.svg?branch=master)](https://travis-ci.org/samehkamaleldin/socket.cpp)

Simple socket programming library in C++, that facilitates using sockets in c++ as it provides an easy interface for socket programming functions.


### How to use
**socket.cpp** library tends to provide an interface of sockets functions similar to JavaScript's `socket.io` framework.
Here is a few example of library usage:

*TCP Server*
```cpp
// create simple tcp server
int port = 4000;
tcp::server server(port);
server.OnMessage(PrintMessage);
server.Listen();
```

*TCP Client*
```cpp
// create simple tcp client and connect to server
int     port    = 4000;
string  address = "127.0.0.1";

tcp::client client( address, port);
client.Connect();
client.Send("Hi");
```

### Contribution
If you want to modify how library is implemented, click the `Fork` button in the top-right corner of this page, and then clone your fork from the command line by replacing [username] with your GitHub user name:
``` bash
git clone https://github.com/[username]/socket.cpp.git
```

## Building
Building process has been tested using `GNU Make 3.81` and `g++ 4.9.2`
And library can be build easily as follows:
``` bash
git clone https://github.com/samehkamaleldin/socket.cpp.git
cd ./socket.cpp/build
make
```
And the target library `socket-cpp.so` and binaries for examples can be found in `dist` directory under repositories home directory.

## Acknowledgement
The development of this library has been inspired by a set of code documentation pages, C++ examples and tutorials
about C/C++ socket programming such as:-

1. [Kevin C. Almeroth, University of California - CS 176B: Network Computing (Examples)](http://www.cs.ucsb.edu/~almeroth/classes/W01.176B/hw2/examples/)
