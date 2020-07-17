#include "hashtable.h"
#include <stdlib.h>
#include <string.h>
#define DEFAULT_CAPACITY 5
#define MAX_LOAD_FACTOR 0.8

typedef struct node {
    char *key;
    char *value;
    struct node *next;
} node_t;

node_t *create_node(const char *key, const char *value) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->key = (char *)calloc(strlen(key) + 1, sizeof(char));
    strcpy(node->key, key);
    node->value = (char *)calloc(strlen(value) + 1, sizeof(char));
    strcpy(node->value, value);
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

void destroy_bucket(node_t *bucket[], const size_t capacity) {
    for (size_t i = 0; i < capacity; i++) {
        node_t *node = bucket[i];
        while (node) {
            node_t *tmp = node;
            node = node->next;
            free(tmp->value);
            free(tmp->key);
            free(tmp);
        }
    }
    free(bucket);
}

void destroy_hashtable(hashtable_t *hashtable) {
    destroy_bucket(hashtable->bucket, hashtable->capacity);
    free(hashtable);
}

void rehash(hashtable_t *hashtable, const size_t new_capacity) {
    node_t **old_bucket = hashtable->bucket;
    size_t old_capacity = hashtable->capacity;
    hashtable->bucket = (node_t **)calloc(new_capacity, sizeof(node_t *));
    hashtable->capacity = new_capacity;
    hashtable->size = 0;
    for (size_t i = 0; i < old_capacity; i++) {
        node_t *node = old_bucket[i];
        while (node) {
            put_to_hashtable(hashtable, node->key, node->value);
            node = node->next;
        }
    }
    destroy_bucket(old_bucket, old_capacity);
}

void put_to_hashtable(hashtable_t *hashtable, const char *key, const char *value) {
    size_t i = generate_hash_value(key, hashtable->capacity);
    node_t *node = hashtable->bucket[i];
    while (node) {
        if (strcmp(node->key, key) == 0) {
            strncpy(node->value, value, sizeof(node->value) - 1);
            return;
        }
        node = node->next;
    }
    hashtable->bucket[i] = create_node(key, value);
    hashtable->size++;

    double load_factor = (double)hashtable->size / hashtable->capacity;
    if (load_factor > MAX_LOAD_FACTOR) {
        size_t new_capacity = hashtable->capacity * 2;
        rehash(hashtable, new_capacity);
    }
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
