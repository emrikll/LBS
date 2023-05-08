#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define __STDC_WANT_LIB_EXT1__ 1

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s text", argv[0]);
        exit(0);
    }

    char buffer[1024];
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);
    safe_copy(buffer, argv[1], 1024);

    printf("You wrote: %s \n", buffer);
    exit(0);
}

void safe_copy(char* buffer[], char* string[], int size) {
    if (strlen(string) < size) {
        strcpy(buffer, string);
    }
}