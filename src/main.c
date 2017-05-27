/**
 * @file main.c
 * @brief entry
 * @author ritchietam@qq.com
 * @version 0.0.1
 * @date 2017-05-27
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "iniparser.h"

// define some constants
#define START_GATEWAY_PORT 8888
#define START_API_PORT 8801

// functions declaration
int start_socket(int start_port);
void create_process(void);

/**
 * @brief entry 
 *
 * @param argc numbers of args
 * @param argv[] config file name of first one
 *
 * @return void
 */
void 
main(int argc, char * argv[])
{
    dictionary  *   ini;
    char *ini_name;

    // check the numbers of args
    if (argc!=2) {
        fprintf(stderr, "please provide a config file name\n");
    }else{
        ini_name = argv[1];
        ini = iniparser_load(ini_name);     
        iniparser_dump(ini, stderr);
    }
}


/**
 * @brief create new daemon process listen to specified port
 *
 * @param port listening port
 *
 * @return 
 */
int 
start_socket(int port)
{

}

/**
 * @brief create new process
 */
void
create_process(void)
{
    pid_t pid = fork();

    if (pid == 0) {
        // create child process success

    
    } else if(pid > 0) {
        // parent process
    
    } else {
        // fork child process error
        fprintf(stderr, "fork child error\n");
    }
}
