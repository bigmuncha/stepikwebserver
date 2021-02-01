#include "client_handler.hpp"
#include <thread>


int set_nonblock(int fd){
    int flags;
#if defined(O_NONBLOCK)
    if(-1 == (flags = fcntl(fd, F_GETFL, 0)))
        flags = 0;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    flags = 1;
    return ioctl(fd, FIOBIO, &flangs);
#endif
}


void clients_handler( options opt){
    acceptor(opt);
}


void acceptor( options opt){

    int MasterSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    SockAddr.sin_port = htons(std::atoi(opt.port));
    inet_pton(AF_INET, opt.ip, &SockAddr.sin_addr);


    bind(MasterSocket,(struct sockaddr*)& SockAddr, sizeof(SockAddr));


    listen(MasterSocket, SOMAXCONN);

    int clientfd;
    socklen_t len;
    struct sockaddr_in cliaddr;


    len = sizeof(cliaddr);

    for(;;){
    clientfd = accept(MasterSocket, (struct sockaddr *)&cliaddr, &len);

    std::thread t(session, clientfd,opt);
    t.join();
    }
    //session(clientfd,opt);


}



void session(int fd,options opt){
    std::cout << "Connect YES\n";

    char data[8192];
    int RecvSize = recv(fd,data,8192,MSG_NOSIGNAL);

    if((RecvSize == 0) && (errno != EAGAIN)){
        shutdown(fd, SHUT_RDWR);
        close(fd);
    }else if(RecvSize > 0){
        return_string hand(data);

        hand.fill_the_body(opt.path);

        std::cout <<hand.get_path() <<'\n';
        std::cout <<hand.get_result() <<'\n';
        std::string res = hand.get_result();
        send(fd,res.c_str(),res.length(),MSG_NOSIGNAL);

    }

}
