#include "list.h"
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *element;
    struct node *next;
} node_t;

static node_t *create_node(const char *);

struct list {
    node_t *first;
    node_t *last;
    size_t count;
};

list_t *list_create()
{
    list_t *list = (list_t *)malloc(sizeof(list_t));
    list->first = list->last = NULL;
    list->count = 0;
    return list;
}

void list_destroy(list_t *list)
{
    node_t *node = list->first;
    node_t *tmp;
    while (node) {
        tmp = node;
        node = tmp->next;
        free(tmp->element);
        free(tmp);
    }
    free(list);
}

size_t list_count(list_t *list)
{
    return list->count;
}

void list_append(list_t *list, const char *string)
{
    node_t *node = create_node(string);
    if (list->count == 0) {
        list->first = list->last = node;
        list->count = 1;
    } else {
        list->last->next = node;
        list->last = list->last->next;
        ++list->count;
    }
}

const char *list_get(const list_t *list, size_t index)
{
    size_t i;
    node_t *node = list->first;
    if (index > list->count - 1) {
        return NULL;
    }
    for (i = 0; i < list->count; ++i) {
        if (i == index) {
            return node->element;
        }
        node = node->next;
    }
    return NULL;
}

size_t list_index(const list_t *list, const char *string)
{
    size_t i = 0;
    node_t *node = list->first;
    while (node) {
        if (strcmp(node->element, string) == 0) {
            return i;
        }
        ++i;
        node = node->next;
    }
}

void list_move_node(list_t *source, list_t *target, const char *string)
{
    node_t *node = source->first;
    node_t *prev = NULL;

    while (node) {
        if (strcmp(string, node->element) == 0) {
            // remove from source
            if (prev) {
                prev->next = node->next;
                if (prev->next == NULL) {
                    source->last = prev;
                }
            } else {
                source->first = node->next;
                if (source->first == NULL) {
                    source->last = NULL;
                }
            }
            --source->count;

            // append to target
            node->next = NULL;
            if (target->count == 0) {
                target->first = target->last = node;
            } else {
                target->last->next = node;
                target->last = target->last->next;
            }
            ++target->count;
            break;
        }

        prev = node;
        node = node->next;
    }
}

node_t *create_node(const char *string)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->element = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(node->element, string);
    node->next = NULL;
    return node;
}
