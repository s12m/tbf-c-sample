#include "hashtable.h"
#include <stdio.h>
#include <string.h>

static char *chomp(char *buf)
{
    size_t length = strlen(buf);

    if (buf[length - 1] == '\n') {
        buf[length - 1] = '\0';
    }

    return buf;
}

int main(int argc, char **argv)
{
    FILE *fp = fopen("words_ja", "r");
    if (fp == NULL) {
        printf("file not found.\n");
        return 1;
    }

    hashtable_t *hashtable = hashtable_create();
    char buf[1024];
    while (fgets(buf, 1024, fp)) {
        chomp(buf);
        hashtable_append(hashtable, buf);
    }

    fseek(fp, 0, SEEK_SET);
    while (fgets(buf, 1024, fp)) {
        chomp(buf);
        printf("%s: %s\n", buf, hashtable_contain(hashtable, buf) ? "yes" : "no");
    }
    fclose(fp);

    hashtable_destroy(hashtable);
}
