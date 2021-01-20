#include "stringtreat.hpp"


std::string get_path(std::string data){

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
            return retstr;
            break;
        }if(flag ==1){
            retstr = retstr + a;
        }

    }
    return "";
}
