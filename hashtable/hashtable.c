#include "hashtable.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

static const size_t FIRST_BUCKET = 11;
static const size_t increase_bucket(size_t bucket)
{
    return bucket * 2 + 1;
}
static const double MAX_LOAD_FACTOR = 0.75;

static size_t get_hash(size_t bucket, const char *);
static void rehash(hashtable_t *);

struct hashtable {
    list_t **lists;
    size_t bucket;
    size_t count;
};

hashtable_t *hashtable_create()
{
    size_t i;
    hashtable_t *hashtable = (hashtable_t *)malloc(sizeof(hashtable_t));
    hashtable->bucket = FIRST_BUCKET;
    hashtable->lists = (list_t **)malloc(sizeof(list_t *) * hashtable->bucket);
    for (i = 0; i < hashtable->bucket; ++i) {
        hashtable->lists[i] = list_create();
    }
    hashtable->count = 0;
    return hashtable;
}

void hashtable_destroy(hashtable_t *hashtable)
{
    size_t i;
    for (i = 0; i < hashtable->bucket; ++i) {
        list_destroy(hashtable->lists[i]);
    }
    free(hashtable->lists);
    free(hashtable);
}

size_t hashtable_count(const hashtable_t *hashtable)
{
    return hashtable->count;
}

void hashtable_append(hashtable_t *hashtable, const char *string)
{
    rehash(hashtable);
    list_append(hashtable->lists[get_hash(hashtable->bucket, string)], string);
    ++hashtable->count;
}

int hashtable_contain(const hashtable_t *hashtable, const char *string)
{
    size_t hash = get_hash(hashtable->bucket, string);
    return list_index(hashtable->lists[hash], string) >= 0 ? 1 : 0;
}

size_t get_hash(size_t bucket, const char *string)
{
    size_t i, j;
    size_t length = strlen(string);
    size_t raw = 0;
    for (i = 0; i < length; ++i) {
        raw += pow(31, length - (i + 1)) * (unsigned char)string[i];
    }
    return raw % bucket;
}

void rehash(hashtable_t *hashtable)
{
    double load_factor = hashtable->count / (double)hashtable->bucket;
    size_t new_bucket;
    list_t **new_lists;
    size_t i, j, hash;
    char *string;
    if (load_factor >= MAX_LOAD_FACTOR) {
        new_bucket = increase_bucket(hashtable->bucket);
        new_lists = (list_t **)malloc(sizeof(list_t *) * new_bucket);
        for (i = 0; i < new_bucket; ++i) {
            new_lists[i] = list_create();
        }
        for (i = 0; i < hashtable->bucket; ++i) {
            for (j = 0; j < list_count(hashtable->lists[i]); ++j) {
                string = (char *)list_get(hashtable->lists[i], j);
                hash = get_hash(new_bucket, string);
                list_move_node(hashtable->lists[i], new_lists[hash], string);
            }
        }
        for (i = 0; i < hashtable->bucket; ++i) {
            list_destroy(hashtable->lists[i]);
        }
        free(hashtable->lists);
        hashtable->bucket = new_bucket;
        hashtable->lists = new_lists;
    }
}
