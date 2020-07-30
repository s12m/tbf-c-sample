#include "array.h"
#include <stdlib.h>
#include <stdio.h>

struct Array {
    int *data;
    size_t capacity;
};

array_t *create_array(const size_t capacity) {
    array_t *array = (array_t *)malloc(sizeof(array_t));
    array->data = (int *)calloc(capacity, sizeof(int));
    array->capacity = capacity;
    return array;
}

void put_to_array(array_t *array, const size_t i, int value) {
    if (array->capacity <= i) {
        fprintf(stderr, "Invalid index: %zu\n", i);
        return;
    }
    array->data[i] = value;
}

int get_from_array(const array_t *array, const size_t i) {
    if (array->capacity <= i) {
        fprintf(stderr, "Invalid index: %zu\n", i);
        return 0;
    }
    return array->data[i];
}

void destroy_array(array_t *array) {
    free(array->data);
    free(array);
}
