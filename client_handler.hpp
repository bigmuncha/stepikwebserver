#ifndef __CLIENT_HANDLER_H_
#define __CLIENT_HANDLER_H_

#include "stringtreat.hpp"
//#include <boost/asio.hpp>
#include <cstdlib>
#include "parser.hpp"
//#include <boost/smart_ptr.hpp>
//#include <boost/thread/thread.hpp>
//#include <boost/bind/bind.hpp>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <thread>

//typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

void clients_handler(options );

void acceptor( options);
void session(int,options);

#endif // __CLIENT_HANDLER_H_
