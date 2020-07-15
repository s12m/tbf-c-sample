#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#define DEFAULT_CAPACITY 5

typedef struct node {
    char key[256];
    char value[256];
    struct node *next;
} node_t;

node_t *create_node(const char *key, const char *value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    memset(node->key, 0, sizeof(node->key));
    strncpy(node->key, key, sizeof(node->key) - 1);
    memset(node->value, 0, sizeof(node->value));
    strncpy(node->value, value, sizeof(node->value) - 1);
    node->next = NULL;
    return node;
}

struct hashtable {
    node_t **bucket;
    size_t capacity;
    size_t size;
};

size_t generate_hash_value(const char *key, const size_t capacity) {
    size_t val = 0;
    for (char *p = key; *p != '\0'; p++) {
        val += (unsigned char)(*p);
    }
    return val % capacity;
}

hashtable_t *create_hashtable() {
    hashtable_t *hashtable = (hashtable_t *)malloc(sizeof(hashtable_t));
    hashtable->bucket = (node_t **)calloc(DEFAULT_CAPACITY, sizeof(node_t *));
    hashtable->capacity = DEFAULT_CAPACITY;
    hashtable->size = 0;
    return hashtable;
}

void destroy_hashtable(hashtable_t *hashtable) {
    for (size_t i = 0; i < hashtable->capacity; i++) {
        node_t *node = hashtable->bucket[i];
        while (node) {
            node_t *tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(hashtable->bucket);
    free(hashtable);
}

void put_to_hashtable(hashtable_t *hashtable, const char *key, const char *value) {
    size_t i = generate_hash_value(key, hashtable->capacity);
    node_t *node = hashtable->bucket[i];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            memset(node->value, 0, sizeof(node->value));
            strncpy(node->value, value, sizeof(node->value) - 1);
            return;
        }
        node = node->next;
    }
    hashtable->bucket[i] = create_node(key, value);
}

const char *get_from_hashtable(const hashtable_t *hashtable, const char *key) {
    size_t i = generate_hash_value(key, hashtable->capacity);
    node_t *node = hashtable->bucket[i];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return NULL;
}
