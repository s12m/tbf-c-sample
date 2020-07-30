#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

typedef struct Array array_t;

array_t *create_array(const size_t capacity);
void put_to_array(array_t *array, const size_t i, int value);
int get_from_array(const array_t *array, const size_t i);
void destroy_array(array_t *array);

#endif
