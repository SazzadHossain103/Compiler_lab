///Write a C program to simulate a lexical analyzer for validating  operator


#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool is_operator(const char *op) {

    const char *operators[] = {
        "+", "-", "*", "/", "%",
        "==", "!=", "<", ">", "<=", ">=",
        "&&", "||", "!",
        "="
    };

    int n = sizeof(operators) / sizeof(operators[0]);

    for (int i = 0; i < n; i++) {
        if (strcmp(op, operators[i]) == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    char input[10];

    printf("Enter an operator: ");
    scanf("%s", input);

    if (is_operator(input)) {
        printf("'%s' is a valid operator.\n", input);
    } else {
        printf("'%s' is NOT a valid operator.\n", input);
    }

    return 0;
}
