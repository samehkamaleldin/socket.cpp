//==============================================================================================
//= Module      : Utils                                                                        =
//= Description : Network enum types and flags                                                 =
//==============================================================================================

#ifndef _UTILS_H_
#define _UTILS_H_

#include <sys/socket.h> // Needed for the socket functions
#include <netdb.h>      // Needed for the socket functions
#include <netinet/in.h> // Needed for internet addresses

// ---------------------------------------------------------------------------------------------
// define sockets transmited data types macros
// ---------------------------------------------------------------------------------------------
#ifndef __type_datagram_socket__
#define __type_datagram_socket__         SOCK_DGRAM
#endif

#ifndef __type_byte_stream_socket__
#define __type_byte_stream_socket__      SOCK_STREAM
#endif

#ifndef __type_sequenced_packet_socket__
#define __type_sequenced_packet_socket__ SOCK_SEQPACKET
#endif

// ---------------------------------------------------------------------------------------------
// define sockets types macros
// ---------------------------------------------------------------------------------------------
#ifndef __type_unix_domain_sockets__
#define __type_unix_domain_sockets__        AF_UNIX
#endif

#ifndef __type_unspecified_domain_sockets__
#define __type_unspecified_domain_sockets__ AF_UNSPEC
#endif

#ifndef __type_internet_domain_sockets__
#define __type_internet_domain_sockets__    AF_INET
#endif


// ---------------------------------------------------------------------------------------------
// define nodes types macros
// ---------------------------------------------------------------------------------------------
#ifndef __type_tcp_node__
#define __type_tcp_node__ 10
#endif

#ifndef __type_udp_node__
#define __type_udp_node__ 11
#endif

#endif
