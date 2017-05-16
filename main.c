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

int create_socket();

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


int create_socket()
{
    struct sockaddr_in servaddr , cliaddr;

    int listenfd , connfd;
    pid_t childpid;

    char buf[MAX_LINE];

    socklen_t clilen;

    if((listenfd = socket(AF_INET , SOCK_STREAM , 0)) < 0)
    {
        perror("socket error");
        exit(1);
    }

    bzero(&servaddr , sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if(bind(listenfd , (struct sockaddr*)&servaddr , sizeof(servaddr)) < 0)
    {
        perror("bind error");
        exit(1);
    }

    if(listen(listenfd , BACKLOG) < 0)
    {
        perror("listen error");
        exit(1);
    }

    for( ; ; )
    {
        clilen = sizeof(cliaddr);
        if((connfd = accept(listenfd , (struct sockaddr *)&cliaddr , &clilen)) < 0 )
        {
            perror("accept error");
            exit(1);
        }

        if((childpid = fork()) == 0) 
        {
            close(listenfd);
            ssize_t n;
            char buff[MAX_LINE];
            int i;
            while((n = read(connfd , buff , MAX_LINE)) > 0)
            {
                write(connfd , buff , n);
            }


            // test all start or all close
            const char *all_start_hex = "\xfe\x55\x07\x00\x12\x80\x80\x0a\x4a";

            write(connfd, all_start_hex, sizeof(all_start_hex));
            printf("%s\n", all_start);

            exit(0);
        }
        close(connfd);
    }
    close(listenfd);
}
