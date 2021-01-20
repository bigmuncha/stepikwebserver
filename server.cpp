#include <iostream>
#include <cstdlib>
#include <boost/asio.hpp>
#include <array>
#include "reply.hpp"

using boost::asio::ip::tcp;




class return_string {
    public:

    private:
        std::string code;
        std::string lenght;
        std::string content_type;
        std::string body;
        std::string prebody = "\r\n";
        std::string lastseq = "\r\n";

};
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

    std::string get;
    for(int i =0;data[i] !='\r'; i++){
        get = get + data[i];
    }

    std::cout <<data <<"\n";


    std::cout << "TYT\n";
    std::cout <<get <<"\n";

    std::string neccessary = get_path(get);
    std::cout << neccessary <<"\n";
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
