#include <cstdlib>
#include <boost/asio.hpp>
#include "stringtreat.hpp"
#include <unistd.h>
#include <utility>
#include <stdlib.h>
#include <stdio.h>
#include "parser.hpp"
using boost::asio::ip::tcp;


int main(int argc, char **argv) {
    try{
        options opt;
        opt = parser(argc,argv);


        boost::asio::io_context io_context;
        tcp::socket socket(io_context);
        tcp::acceptor acceptor_(io_context);
        tcp::resolver resolver(io_context);
        tcp::endpoint endpoint =
            *resolver.resolve(opt.ip,opt.port).begin();
        acceptor_.open(endpoint.protocol());
        acceptor_.set_option(
            boost::asio::ip::tcp::acceptor::reuse_address(true));
        acceptor_.bind(endpoint);
        acceptor_.listen();
        acceptor_.accept(socket);


        std::cout << "Connect YES\n";

        char data[8192];


        /*static const char templ[] = "HTTP/1.0 200 OK\r\n"
          "Content-length: 50\r\n"
        "Connection: close\r\n"
        "Content-Type: text/html\r\n"
        "\r\n"
        "Omar idet gulat";*/


    size_t length = socket.read_some(boost::asio::buffer(data));

    std::cout << data << "\n";

    return_string hand(data);
    hand.fill_the_body(opt.path);

    std::cout <<hand.get_path();

    //std::cout << "DO WRITE ZDES\n";
    socket.write_some(boost::asio::buffer(hand.get_result()));
    //std::cout <<"AFTER WRITE\n";
    //socket.write_some(boost::asio::buffer(con_type));
  //  socket.write_some(boost::asio::buffer("\n"));





    }
    catch(std::exception&e ){
        std::cerr <<"Exception " << e.what() << '\n';
    }


    return 0;
}
