///Write a C program to check whether a  mathematical statement is solvable or not


#include <stdio.h>
#include <stdbool.h>

bool is_solvable(float num1, char op, float num2) {
    if (op == '/' && num2 == 0) {
        return false;
    }
    return true;
}

float solve(float num1, char op, float num2) {
    switch (op) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        default: return 0;
    }
}

int main() {
    float num1, num2;
    char op;

    printf("Enter a mathematical expression (like, 5 + 2): ");
    if (scanf("%f %c %f", &num1, &op, &num2) != 3) {
        printf("Invalid input format.\n");
        return 1;
    }

    if (op != '+' && op != '-' && op != '*' && op != '/') {
        printf("Unsupported operator.\n");
        return 1;
    }

    if (is_solvable(num1, op, num2)) {
        float result = solve(num1, op, num2);
        printf("Solvable. Result: %.2f\n", result);
    } else {
        printf("Unsolvable mathematical statement.\n");
    }

    return 0;
}
