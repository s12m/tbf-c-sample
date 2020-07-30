#include "hashtable.h"
#include <string.h>
#include <stdio.h>

int main() {
    hashtable_t *hashtable = create_hashtable();
    put_to_hashtable(hashtable, "LGTM", "Looks Good To Me");
    put_to_hashtable(hashtable, "IMO", "In My Opinion");
    put_to_hashtable(hashtable, "WIP", "Work In Progress");
    put_to_hashtable(hashtable, "AFAIK", "As Far As I Know");
    put_to_hashtable(hashtable, "FYI", "For Your Information");
    put_to_hashtable(hashtable, "TBD", "To Be Determined");
    put_to_hashtable(hashtable, "ASAP", "As Soon As Possible");
    put_to_hashtable(hashtable, "TLDR", "Too Long, Didn't Read");
    put_to_hashtable(hashtable, "AKA", "Also Known As");

    char key[256];
    while (1) {
        printf("Search key (Ctrl-d to exit): ");
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
