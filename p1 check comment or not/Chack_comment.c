///Write a C program to identify whether a given line is comment or not


#include <stdio.h>
#include <string.h>

int main() {
    char line[1000];

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    size_t len = strlen(line);
    if (line[len - 1] == '\n') {
        line[len - 1] = '\0';
    }

    if (strncmp(line, "//", 2) == 0) {
        printf("This is a single-line comment.\n");
    }
    else if (strncmp(line, "/*", 2) == 0 && strstr(line, "*/") != NULL) {
        printf("This is a multi-line comment.\n");
    }
    else {
        printf("This is not a comment.\n");
    }

    return 0;
}
