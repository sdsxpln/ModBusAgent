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
int  parse_ini_file(char * ini_name);

int main(int argc, char * argv[])
{
    int     status ;

    status = parse_ini_file(argv[1]);

    return status ;
}

int parse_ini_file(char * ini_name)
{
    dictionary  *   ini ;

    /* Some temporary variables to hold query results */
    int             b ;
    int             i ;
    double          d ;
    const char  *   s ;

    ini = iniparser_load(ini_name);
    if (ini==NULL) {
        fprintf(stderr, "cannot parse file: %s\n", ini_name);
        return -1 ;
    }
    iniparser_dump(ini, stderr);
    return 0;
}
