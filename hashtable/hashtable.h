#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stddef.h>

typedef struct hashtable hashtable_t;

hashtable_t *hashtable_create();
void hashtable_destroy(hashtable_t *);

size_t hashtable_count(const hashtable_t *);

void hashtable_append(hashtable_t *, const char *);

int hashtable_contain(const hashtable_t *, const char *);

#endif
