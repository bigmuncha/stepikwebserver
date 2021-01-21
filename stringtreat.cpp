#include "stringtreat.hpp"


void return_string::fill_the_body(){
    std::ofstream file;

    file.open(path_to_file);
    if(!file.is_open()){
        std::cerr << "file";

    }
}

std::string return_string::not_found404(){
    return "HTTP/1.0 404 Not Found\r\nContent-Type: text/html\r\n\r\n";
}

return_string::return_string(){

}

return_string::return_string(std::string data){
    search_path(data);


}

void return_string::search_path(std::string data){

    std::string str;
    for(int i =0;data[i] !='\r'; i++){
        str = str + data[i];
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
            return ;
        }if(flag ==1){
            retstr = retstr + a;
        }

    }
    path_to_file =  "/";
}

std::string return_string::get_path(){
    return path_to_file;
}
