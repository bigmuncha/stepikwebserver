#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char *argv[]) {

    try {

        if(argc != 2){
            std::cerr << "use host(ip addr)" << std::endl;
        }

        char *port = "80";
        boost::asio::io_context io_contex;

        tcp::socket serv_socket(io_contex);

        tcp::resolver resolver(io_contex);

        boost::asio::connect(serv_socket, resolver.resolve(argv[1], port));



    } catch (std::exception & e) {
        std::cerr <<"Exception "<< e.what() << '\n';
    }



    return 0;
}
