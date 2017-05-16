#ifndef _LIST_H
#define _LIST_H

// define constants
#define STADIUM_ID_LEN      6
#define APP_ID_LEN          32
#define APP_KEY_LEN         32



/**
 *  'list.h' use linked list storage the config file 
 */
struct LIST {
    // data area
    char stadium_id[STADIUM_ID_LEN]; 
    char app_id[APP_ID_LEN]; 
    char app_key[APP_KEY_LEN]; 

    // ptr area
    struct LIST *next;
};
typedef struct LIST List;

// linked list methods
extern void init_list(List **head, char *stadium_id, char *app_id, char *app_key)



#endif /* _CONF_H */
