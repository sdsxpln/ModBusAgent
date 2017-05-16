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
    char *common = "[common]\n";         // getline read empty line return the \n char
    char *stadium = "[stadium]\n";       // getline read empty line return the \n char
    size_t read;
    short int read_common_conf = -1;           // -1 not ready 1 ready 2 done
    short int read_stadium_conf = -1;          // -1 not ready 1 ready 2 done

    while( (read = getline(&line, &len, fp)) != -1){
        if ( read > 1 ){
            // except \n
            if ( strcmp(line, common) == 0 ){
                // parse common conf 
                read_common_conf = 1;
            }else if( strcmp(line, stadium) == 0 ){
                // parse stadium conf 
                read_common_conf = 2;
                read_stadium_conf = 1;
            }else{
                // according to the value of read_common_conf and read_stadium_conf check 
                // current line be longs to which section(common or stadium)
                if ( read_common_conf == 1 && read_stadium_conf == -1 ){
                    // parse stadium section
                    printf("%s\n", line); 
                }else if( read_common_conf == 2 && read_stadium_conf == 1 ){
                    // parse stadium section
                    printf("%s\n", line); 
                }
            }
        }
    }

    free(line);
    fclose(fp);
    return 0;
}

/**
 *  split string with specific delimiter
 */
char ** split_line(){
    
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
