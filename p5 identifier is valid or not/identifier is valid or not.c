///Write a C program to test whether a given identifier is valid or not


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

bool is_keyword(const char *word) {
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool is_valid_identifier(const char *id) {
    int len = strlen(id);

    if (len == 0)
        return false;

    if (!(isalpha(id[0]) || id[0] == '_'))
        return false;

    for (int i = 1; i < len; i++) {
        if (!(isalnum(id[i]) || id[i] == '_'))
            return false;
    }

    if (is_keyword(id))
        return false;

    return true;
}

int main() {
    char input[100];

    printf("Enter an identifier: ");
    scanf("%s", input);

    if (is_valid_identifier(input)) {
        printf("'%s' is a valid identifier.\n", input);
    } else {
        printf("'%s' is NOT a valid identifier.\n", input);
    }

    return 0;
}
