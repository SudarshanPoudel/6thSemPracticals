#include <stdio.h>
#include <ctype.h>
#include <string.h>

// common C keywords, can be extended
char *keywords[] = {"int", "float", "char", "if", "while"};

int isKeyword(char str[]) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isValidIdentifier(char str[]) {
    if (!isalpha(str[0]) && str[0] != '_')
        return 0;

    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_')
            return 0;
    }

    if (isKeyword(str))
        return 0;

    return 1;
}

int main() {
    char str[100];

    printf("Enter identifier: ");
    scanf("%s", str);

    if (isValidIdentifier(str))
        printf("Valid identifier.\n");
    else
        printf("Invalid identifier.\n");

    return 0;
}
