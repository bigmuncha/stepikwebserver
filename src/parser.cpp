#include "parser.hpp"



options parser(int argc, char **argv) {

    options returnv;

    int c;

    while((c = getopt(argc,argv,"h:p:d:")) != -1){
        switch(c){
            case 'h':
                returnv.ip = optarg;
                break;
            case 'p':
                returnv.port = optarg;
                break;
            case 'd':
                returnv.path = optarg;
                break;
            default:
                abort();
        }
    }



    return returnv;
}
