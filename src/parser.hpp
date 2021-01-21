#ifndef __PARSER_H_
#define __PARSER_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct options {
    char *ip;
    char *port;
    char *path;
};



options parser(int , char **);


#endif // __PARSER_H_
