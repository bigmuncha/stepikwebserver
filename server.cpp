#include <cstdlib>
#include <boost/asio.hpp>
#include <array>
#include "stringtreat.hpp"
#include <utility>

using boost::asio::ip::tcp;


int main(int argc, char *argv[]) {
    try{

    boost::asio::io_context io_context;
    tcp::socket socket(io_context);
    tcp::acceptor a(io_context, tcp::endpoint(tcp::v4(), 9000));

    a.accept(socket);
    std::cout << "Connect YES\n";

    char data[8192];


    static const char templ[] = "HTTP/1.0 200 OK\r\n"
        "Content-length: 50\r\n"
        "Connection: close\r\n"
        "Content-Type: text/html\r\n"
        "\r\n"
        "Omar idet gulat";

    for(;;){
    size_t length = socket.read_some(boost::asio::buffer(data));

    std::cout << data << "\n";

    return_string hand(data);
    std::cout <<hand.get_path() <<'\n';



    socket.write_some(boost::asio::buffer(templ));

    //socket.write_some(boost::asio::buffer(con_type));
  //  socket.write_some(boost::asio::buffer("\n"));

    socket.write_some(boost::asio::buffer("<p>HELLO</p>\n"));
    socket.write_some(boost::asio::buffer("<p>HELLO</p>\n"));
    socket.write_some(boost::asio::buffer("<p>HELLO</p>\n"));
    socket.write_some(boost::asio::buffer("<p>HELLO</p>\n"));
    socket.write_some(boost::asio::buffer("<p>HELLO</p>\n"));

    }


    }
    catch(std::exception&e ){
        std::cerr <<"Exception " << e.what() << '\n';
    }


    return 0;
}
