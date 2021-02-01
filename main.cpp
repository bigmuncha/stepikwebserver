#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utility>
#include "client_handler.hpp"




int main(int argc, char **argv) {
    try{

        signal(SIGHUP,SIG_IGN);

        pid_t pid;

        pid = fork();

        if(!pid){
            umask(0);
            setsid();
            options opt;
        opt = parser(argc,argv);

        clients_handler(opt);

    return 0;

        }else {
            return 0;
        }

    }
    catch(std::exception&e ){
        std::cerr <<"Exception " << e.what() << '\n';
    }


    return 0;
}
