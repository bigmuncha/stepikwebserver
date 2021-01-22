#ifndef __CLIENT_HANDLER_H_
#define __CLIENT_HANDLER_H_

#include "stringtreat.hpp"
#include <boost/asio.hpp>
#include <cstdlib>
#include "parser.hpp"
//#include <boost/smart_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <boost/bind/bind.hpp>

//typedef boost::shared_ptr<boost::asio::ip::tcp::socket> socket_ptr;

void clients_handler(boost::asio::io_service&,options );

void acceptor(boost::asio::io_service&, options);
void session(boost::asio::ip::tcp::socket,options);

#endif // __CLIENT_HANDLER_H_
