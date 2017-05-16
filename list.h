/**
 *  'list.h' use linked list storage the config file 
 */
#ifndef _LIST_H
#define _LIST_H

struct LIST {
    // data area
    char *stadium_id; 
    char *app_id; 
    char *app_key; 

    // ptr area
    struct LIST *next;
};
typedef struct LIST List;

// linked list methods
extern List* search_list(List *head, char* stadium_id);
extern int link_len(List *head);
extern List* append_list(List *head, char* stadium_id, char* app_id, char* app_key);
extern void init_list(List **head);

#endif /* _CONF_H */
