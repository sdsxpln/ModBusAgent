#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <memory.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <stdarg.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>


// define some error message constants
#define CREATE_SOCKET_ERROR              "create socket fail"
#define CREATE_SOCKET_BIND_ERROR         "create socket bind error"
#define SOCKET_LISTEN_ERROR              "socket listen error"
#define SOCKET_ACCEPT_ERROR              "socket accept error"

#define MAXLINE 4096

int
main(int argc, char **argv){
   int sockfd, connfd;
   struct sockaddr_in server_addr;
   char buff[10];
   int n;

   if (sockfd = socket(AF_INET, SOCK_STREAM, 0) == -1 ) {
       printf("%s\n", CREATE_SOCKET_ERROR);
       exit(0);
   }

   // memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   server_addr.sin_port = htons( 8888 );

   if ( bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1){
       printf("%s\n", CREATE_SOCKET_BIND_ERROR);
       exit(0);
   }

   if( listen(sockfd, 10) == -1){
       printf("%s\n", SOCKET_LISTEN_ERROR);
       exit(0);
    }

    printf("%s\n", "server is running, waiting accept...");
    // waiting accept
    while(1){
        if( (connfd = accept(sockfd, (struct sockaddr*)NULL, NULL)) == -1){
            printf("%s\n", SOCKET_ACCEPT_ERROR);
            continue;
    }
    n = recv(connfd, buff, MAXLINE, 0);
    buff[n] = '\0';
    printf("recv msg from client: %s\n", buff);
        close(connfd);
    }
    close(sockfd);
    return 0;
}
