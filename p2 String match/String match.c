///Write a C program to recognize strings under ''a'' , 'a*b+' , ' aab'

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool match_a(const char *str) {
    return strcmp(str, "a") == 0;
}

bool match_a_star_b_plus(const char *str) {

    return strcmp(str, "a*b+") == 0;
}

bool match_abb(const char *str) {
    return strcmp(str, "abb") == 0;
}

int main() {


    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    if (match_a(str))
        printf("Recognize string : 'a'\n");
    else if (match_a_star_b_plus(str))
        printf("Recognize string : 'a*b+'\n");
    else if (match_abb(str))
        printf("Recognize string : 'abb'\n");
    else
        printf("Not recognize string \n");

    return 0;
}
