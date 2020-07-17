#include "hashtable.h"
#include <string.h>
#include <stdio.h>

int main() {
    hashtable_t *hashtable = create_hashtable();
    put_to_hashtable(hashtable, "C", "Cupcake");
    put_to_hashtable(hashtable, "D", "Donut");
    put_to_hashtable(hashtable, "E", "Eclair");
    put_to_hashtable(hashtable, "F", "Froyo");
    put_to_hashtable(hashtable, "G", "Gingerbread");

    char key[256];
    while (1) {
        printf("Search key (Ctrl+D to exit): ");
        if (fgets(key, 256, stdin) == NULL) {
            break;
        }
        key[strlen(key) - 1] = '\0'; // 改行コードを削除
        const char *value = get_from_hashtable(hashtable, key);
        if (value) {
            printf("%s => %s\n", key, value);
        } else {
            printf("The key `%s` is not found.\n", key);
        }
    }

    destroy_hashtable(hashtable);
}
