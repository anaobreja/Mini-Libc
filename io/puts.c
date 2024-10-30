#include <unistd.h>
#include <internal/io.h>
#include <errno.h>
#include "string.h"

int puts(const char *str) {
    size_t len = strlen(str);
    ssize_t bytes = write(1, str, len);

    if (bytes == -1)
        return -1;

    char newline = '\n';

    ssize_t new = write(1, &newline, 1);

    if (new == -1)
        return -1;

    return bytes + new;
}

