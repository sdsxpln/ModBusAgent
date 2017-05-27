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

// functions declaration


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
