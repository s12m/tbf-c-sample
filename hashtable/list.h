#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct list list_t;

list_t *list_create();
void list_destroy(list_t *);

size_t list_count(list_t *);

void list_append(list_t *, const char *);
const char *list_get(const list_t *, size_t);

size_t list_index(const list_t *, const char *);

void list_move_node(list_t *source, list_t *target, const char *);

#endif
