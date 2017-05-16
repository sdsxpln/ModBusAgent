#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// define some error messages
#define LINKED_LIST_NODE_CREATE_ERROR       "linked list node malloc error"
#define LINKED_LIST_NOT_INIT                "linked list yet init"

/**
 *  just init linked list 
 */
void init_list(List **head)
{
    List *new;

    if ( *head = NULL ){
        new = (List *)malloc(sizeof(List));
        *head = new;     
    }
}

/**
 *  append node to linked list 
 *  order by stadium_id
 */ 

List* append_list(List *head, char* stadium_id, char* app_id, char* app_key)
{
    List *new;

    if ( head != NULL ){
        printf("%s\n", LINKED_LIST_NOT_INIT);
    }    

    new = (List *)malloc(sizeof(List));
    if ( new == NULL ){
        printf("%s\n", LINKED_LIST_NODE_CREATE_ERROR);
    }

    // fill data 
    new->stadium_id = stadium_id;
    new->app_id = app_id;
    new->app_key = app_key;

    // ptr 
    head->next = new;
    
    return head;
}
