#include <string>


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


std::string get_path(std::string);
