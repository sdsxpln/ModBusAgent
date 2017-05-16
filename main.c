#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "conf.h"

#define     MAX_LINE        2
#define     PORT            8888
#define     BACKLOG         1024
#define     MAX_CONNECT     20


int main(int argc , char **argv)
{
    const char *file_path = "conf.ini";

    // check conf file exists
    if ( check_conf_exists(file_path) == 1 ){
        // file exist
        load_conf(file_path); 
    }
    return 0;
}

