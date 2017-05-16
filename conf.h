/**
 *  'parse_conf.h' contains parse config file function declare
 */
#ifndef _CONF_H
#define _CONF_H
#include <stdio.h>
#define CONF_VERSION "0.1.1"

extern int check_conf_exists(const char *file_path);
extern int parse_conf(FILE *fp);
extern void load_conf(const char *file_path);

#endif /* _CONF_H */
