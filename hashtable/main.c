#include "hashtable.h"
#include <string.h>
#include <stdio.h>

static char *chomp(char *buf)
{
    size_t length = strlen(buf);
    if (buf[length - 1] == '\n') {
        buf[length - 1] = '\0';
    }
    return buf;
}

int main() {
    hashtable_t *hashtable = create_hashtable();
    put_to_hashtable(hashtable, "C", "Cupcake");
    put_to_hashtable(hashtable, "D", "Donut");
    put_to_hashtable(hashtable, "E", "Eclair");
    put_to_hashtable(hashtable, "F", "Froyo");
    put_to_hashtable(hashtable, "G", "Gingerbread");

    char key[256];
    while (fgets(key, 256, stdin)) {
        chomp(key);
        const char *value = get_from_hashtable(hashtable, key);
        if (value) {
            printf("%s => %s\n", key, value);
        } else {
            printf("The key `%s` is not found.\n", key);
        }
    }

    destroy_hashtable(hashtable);
}
