#include <string>
#include <fstream>
#include <iostream>

namespace content_type{
    const std::string text_html=
        "Content-Type: text/html\r\n";
}

namespace status_strings{
    const std::string ok =
        "HTTP/1.0 200 OK\r\n";
    const std::string bad_request =
        "HTTP/1.0 400 Bad Request\r\n";
    const std::string not_found =
        "HTTP/1.0 404 Not Found\r\n";
}

class return_string {
    public:

        void fill_the_body();
        return_string(std::string);
        return_string();

        std::string ok200(std::string);
        std::string not_found404();
        std::string get_path();

    private:
        void search_path(std::string);
        std::string path_to_file;

        std::string content_length;
        std::string body;
        std::string prebody = "\r\n";
        std::string lastseq = "\r\n";

        std::string result;
};
