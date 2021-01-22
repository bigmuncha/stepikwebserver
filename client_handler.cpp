#include "client_handler.hpp"
#include <thread>
using boost::asio::ip::tcp;


void clients_handler(boost::asio::io_service & io_service, options opt){

    acceptor(io_service, opt);
}


void acceptor(boost::asio::io_service& io_service, options opt){
    tcp::acceptor acceptor_(io_service);
    tcp::resolver resolver(io_service);
    tcp::endpoint end(boost::asio::ip::address::from_string(opt.ip),
                      atoi(opt.port));
    acceptor_.open(end.protocol());
    acceptor_.set_option(
        boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor_.bind(end);
    acceptor_.listen();

    for(;;){
        std::thread(session, acceptor_.accept(),opt).detach();
    }

}

void session(tcp::socket socket,options opt){
    std::cout << "Connect YES\n";

    char data[8192];
    size_t length = socket.read_some(boost::asio::buffer(data));

    std::cout << data << "\n";

    return_string hand(data);
    hand.fill_the_body(opt.path);

    std::cout <<hand.get_path();

    socket.write_some(boost::asio::buffer(hand.get_result()));

}
