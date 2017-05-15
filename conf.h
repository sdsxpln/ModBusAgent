#ifndef _CONF_H
#define _CONF_H

/**
 *  'parse_conf.h' contains parse config file function declare
 */

#define CONF_VERSION "0.1.1"

extern char *get_ini(const char *section, const char *key);
extern char *free_ini(const char *section, const char *key);
extern void ini_load(const char *filename);

#endif /* _CONF_H */
