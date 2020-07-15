#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stddef.h>

typedef struct hashtable hashtable_t;

hashtable_t *create_hashtable();
void destroy_hashtable(hashtable_t *hashtable);
void put_to_hashtable(hashtable_t *hashtable, const char *key, const char *value);
const char *get_from_hashtable(const hashtable_t *hashtable, const char *key);

#endif
