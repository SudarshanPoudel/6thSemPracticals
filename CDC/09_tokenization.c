#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 5
#define MAX_OPERATORS 6

// Some C keywords for demonstration
char *keywords[] = {"int", "float", "if", "else", "while"};

// Some C operators for demonstration
char *operators[] = {"+", "-", "*", "/", "=", "=="};

// Function to check if a token is a keyword
int isKeyword(char *str) {
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) return 1;
    }
    return 0;
}

// Function to check if a token is an identifier
int isIdentifier(char *str) {
    if (isalpha(str[0]) || str[0] == '_') {
        for (int i = 1; str[i] != '\0'; i++) {
            if (!isalnum(str[i]) && str[i] != '_') return 0;
        }
        return 1;
    }
    return 0;
}

// Function to check if a token is a literal (number)
int isLiteral(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) return 0;
    }
    return 1;
}

// Function to check if a token is an operator
int isOperator(char *str) {
    for (int i = 0; i < MAX_OPERATORS; i++) {
        if (strcmp(str, operators[i]) == 0) return 1;
    }
    return 0;
}

// Tokenize the input string and classify tokens
void tokenizeAndClassify(char *input) {
    char *token = strtok(input, " ");  // Tokenize by spaces
    while (token != NULL) {
        if (isKeyword(token)) printf("Keyword: %s\n", token);
        else if (isIdentifier(token)) printf("Identifier: %s\n", token);
        else if (isLiteral(token)) printf("Literal: %s\n", token);
        else if (isOperator(token)) printf("Operator: %s\n", token);
        token = strtok(NULL, " ");  // Get the next token
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character from input

    tokenizeAndClassify(input);  // Tokenize and classify the input

    return 0;
}
