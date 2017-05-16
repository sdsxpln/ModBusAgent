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

    if ( *head == NULL ){
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
    List *new, *current;

    if ( head == NULL ){
        printf("%s\n", LINKED_LIST_NOT_INIT);
    }    

    current = head;
    // traversal linked list
    while ( current->next != NULL ){
        if ( atoi(current->stadium_id) < atoi(stadium_id) ){
            break; 
        } 

        current = current->next;
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
    current->next = new;
    
    return head;
}

/**
 *  get linked list length
 */
int link_len(List *head)
{
    int len=0;

    do {
        len += 1;
        head = head->next; 
    }while( head->next == NULL);

    return len;
}

/**
 *  search on linked list
 *  start from head until find node or reached tail
 */
List* search_list(List *head, char* stadium_id)
{
    // traversal linked list
    List *current;

    current = head;
    while( current->next == NULL ){
        if ( atoi(current->next) == atoi(stadium_id) ){
            break;
        }
        current = current->next;
    }
    
    return current;
}
