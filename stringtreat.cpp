#include "stringtreat.hpp"


void return_string::fill_the_body(char *pre_path){
    std::ifstream file;
    path_to_file =pre_path + path_to_file;
    //pthread_create(a, b ,NULL);
    if(path_to_file.empty()){
        result = not_found404();
        return;
    }
    std::cout <<"PATH\n" << path_to_file <<"\nPATH\n";
    //std::cerr <<"omar";
    std::cout <<path_to_file;

    file.open(path_to_file);
    if(!file.is_open()){
        std::cerr << "error open file\n";
        result = not_found404();
    }else{
        std::cout <<"file normal open good \n";
        std::string s;
        std::string temp;
    for (;!file.eof();) {
        std::getline(file, s);
        temp = temp +s;
        //std::cout <<s <<'\n';
    }
//    std::cout <<"TYT\n";
    result = ok200(temp);
  //  std::cout <<"TYT\n";
    }

    file.close();

}

std::string return_string::get_result(){
    return result;
}

std::string return_string::ok200(std::string str){
    std::string returner;

    returner = status_strings::ok +
        "Content-length:" +
        std::to_string(str.length()) +
        "\r\n" +
        "Connection: close\r\n"+
        content_type::text_html +
        "\r\n" + str;
    return returner;
}

std::string return_string::not_found404(){
    return
        "HTTP/1.0 404 NOT FOUND\r\n"
        "Content-length: 0\r\n"
        "Connection: close\r\n"
        "Content-Type: text/html\r\n"
        "\r\n"
        "";
}

return_string::return_string(){

}

return_string::return_string(std::string data){
    search_path(data);
    std::cout <<path_to_file <<"\n";
}

void return_string::search_path(std::string data){



    std::string str;
    for(int i =0;data[i] !='\r'; i++){

        str = str + data[i];
    }

    if(str == "/"){
        path_to_file = "index.html";
        return;
    }

    std::string retstr;
    int flag=0;
    char a;
    for(int i=0;i < str.length();i++){
        a=str[i];

        if(a == ' '){
            flag++;
            continue;
        }
        if(flag >= 2){
            path_to_file =  retstr;
            break;
        }if(flag ==1){
            if(a == '?'){
                break;
            }
            retstr = retstr + a;
        }

    }

    std::cout <<"файл\n"<<path_to_file <<"\nfile\n";
    if(path_to_file == "/"){
        path_to_file = "/index.html";
        return;
    }else{
        path_to_file = "OOOOOOOOOOO";
    }

}

std::string return_string::get_path(){
    return path_to_file;
}
