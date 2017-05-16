#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include "list.h"

#define     TRUE    1
#define     FALSE   0

#define OPEN_COFNIG_FILE_ERROR      "open config file error"
#define CONF_FILE_NOT_EXISTS        "config file not exists,You should check conf.ini.example then make new \n one named conf.ini"

/**{{{
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
 *  split string with specific delimiter
 */
int split_line(const char *line, char *delimiter, char ***res)
{
    int count = 1;    
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;

    // traversal each char
    p = (char *)line;
    while (*p != '\0')
    {
        if (*p == *delimiter)
            count++;
        p++;
    }

    *res = (char**) malloc(sizeof(char*) * count);
    if (*res == NULL)
        exit(1);

    p = (char *)line;
    while (*p != '\0')
    {
        if (*p == *delimiter)
        {
            (*res)[i] = (char*) malloc( sizeof(char) * token_len );
            if ((*res)[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*res)[i] = (char*) malloc( sizeof(char) * token_len );
    if ((*res)[i] == NULL)
        exit(1);

    i = 0;
    p = (char *)line;
    t = ((*res)[i]);
    while (*p != '\0')
    {
        if (*p != *delimiter && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*res)[i]);
        }
        p++;
    }

    return count; 
}
/*}}}*/
/**
 *  fill data into linked list
 */
void fill_conf_list(List **head, char *stadium_id, char *app_id, char *app_key)
{
    if ( *head == NULL ){
        // need init linked list
        init_list(head); 
    }else{
        // append data to linked list node
        *head = append_list(*head, stadium_id, app_id, app_key);
    }
}    


/**
 *  parse config file line by line
 */
int parse_conf(FILE *fp)
{
    char *delimiter = "=";
    char *line = NULL;
    size_t len = 0;
    char *common = "[common]\n";         // getline read empty line return the \n char
    char *stadium = "[stadium]\n";       // getline read empty line return the \n char
    size_t read;
    short int read_common_conf = -1;           // -1 not ready 1 ready 2 done
    short int read_stadium_conf = -1;          // -1 not ready 1 ready 2 done
    char **res = NULL;                         // save result from split_line returned
    int res_len, i;
    List *head;

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
                     /*printf("%s\n", line); */
                    /*res_len = split_line(line, delimiter, &res);*/
                    /*for( i = 0; i < res_len; i++){*/
                        /*printf("key order %d value is %s\n", i, res[i]);*/
                    /*} */
                    char * stadium_id = "100001";
                    char * app_id = "1223123";
                    char * app_key = "234";
                    printf("%s\n", "-");
                    fill_conf_list(&head, stadium_id, app_id, app_key);
                    printf("%p\n", head);
                    append_list(head, stadium_id, app_id, app_key);
                    printf("%p\n", head);
                    printf("%s\n", "-");
                    /*printf("%s\n", *head->next);*/
                    /*printf("%s\n", "---");*/
                    /*printf("%s\n", *head->stadium_id);*/
                    /*printf("%s\n", "----");*/
                    /*printf("%s\n", *head->app_id);*/
                    /*printf("%s\n", "-----");*/
                }else if( read_common_conf == 2 && read_stadium_conf == 1 ){
                    // parse stadium section
                    /*printf("%s\n", line); */
                    /*printf("%s\n", line); */
                    /*res_len = split_line(line, delimiter, &res);*/
                    /*for( i = 0; i < res_len; i++){*/
                        /*printf("key order %d value is %s\n", i, res[i]);*/
                    /*} */
                    printf("%s\n", "++++");
                    char * stadium_id = "100001";
                    char * app_id = "1223123";
                    char * app_key = "23429834u29834ufsdfjskdfj";
                    fill_conf_list(&head, stadium_id, app_id, app_key);
                    printf("%s\n", head->stadium_id);
                    printf("%s\n", head->app_id);
                    printf("%s\n", head->app_key);
                }
            }
        }
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
