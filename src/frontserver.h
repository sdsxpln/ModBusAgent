/**
 * @file frontserver.h
 * @brief gateway socket receive from IOT gateway
 * @author ritchietam
 * @version 0.0.1
 * @date 2017-06-02
 */

#include <event.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h>


//内部函数，只能被本文件中的函数调用
static short ListenPort = 8080;
static long ListenAddr = INADDR_ANY;//任意地址，值就是0
static int   MaxConnections = 1024;

static int ServerSocket;
//创建event
static struct event ServerEvent;

