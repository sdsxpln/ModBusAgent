#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>

#define     TRUE    1
#define     FALSE   0

#define OPEN_COFNIG_FILE_ERROR      "open config file error"
#define CONF_FILE_NOT_EXISTS        "config file not exists,You should check conf.ini.example then make new \n one named conf.ini"

/**
 *  check config file exists
 */
int check_conf_exists(const char *file_path)
{
    if ( access(file_path, F_OK) == 0 ){
        return TRUE; 
    }else{
        printf("%s\n", CONF_FILE_NOT_EXISTS);
        return FALSE; 
    } 
}

/**
 *  parse config file line by line
 */
int parse_conf(FILE *fp)
{
    char *line = NULL;
    size_t len = 0;

    while(getline(&line, &len, fp) != -1){
        printf("%s\n", line); 
    }

    free(line);
    fclose(fp);
    return 0;
}

/**
 *  load config file 
 */
void load_conf(const char *file_path)
{
    FILE *fp;

    fp = fopen(file_path, "r");
    if ( fp == NULL ){
        printf("%s\n", OPEN_COFNIG_FILE_ERROR);
    }else{
        parse_conf(fp);
    }
}
