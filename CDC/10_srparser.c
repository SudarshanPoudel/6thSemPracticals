#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack structure to simulate the shift-reduce process
char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

// Function to check if the top of the stack can be reduced
int reduce() {
    // E -> id
    if (top >= 0 && stack[top] == 'i') {
        printf(" Reduced: id -> E\n");
        stack[top] = 'E';  // Reduce 'id' to 'E'
        return 1;
    }
    // E -> E + E
    if (top >= 2 && stack[top] == 'E' && stack[top-1] == '+' && stack[top-2] == 'E') {
        printf(" Reduced: E + E -> E\n");
        stack[top-2] = 'E';  // Reduce 'E + E' to 'E'
        top -= 2;
        return 1;
    }
    // E -> E * E
    if (top >= 2 && stack[top] == 'E' && stack[top-1] == '*' && stack[top-2] == 'E') {
        printf(" Reduced: E * E -> E\n");
        stack[top-2] = 'E';  // Reduce 'E * E' to 'E'
        top -= 2;
        return 1;
    }
    // E -> ( E )
    if (top >= 2 && stack[top] == ')' && stack[top-1] == 'E' && stack[top-2] == '(') {
        printf(" Reduced: ( E ) -> E\n");
        stack[top-2] = 'E';  // Reduce '( E )' to 'E'
        top -= 2;
        return 1;
    }
    return 0;
}

// Function to perform the shift-reduce parsing
void shiftReduceParser(char input[]) {
    int i = 0;
    while (input[i] != '\0') {
        printf("\nStack: ");
        for (int j = 0; j <= top; j++) {
            printf("%c", stack[j]);
        }
        printf("  Input: ");
        for (int j = i; input[j] != '\0'; j++) {
            printf("%c", input[j]);
        }
        
        // Check for reduction first
        if (reduce()) {
            continue;  // After reduction, continue with the next step
        }
        
        // Shift the next symbol from input to the stack
        push(input[i]);
        i++;
    }

    // Final reduction if possible
    while (reduce()) {
        printf("\nStack: ");
        for (int j = 0; j <= top; j++) {
            printf("%c", stack[j]);
        }
        printf("\n");
    }

    if (top == 0 && stack[top] == 'E') {
        printf("\nParsing Successful! The input string is valid.\n");
    } else {
        printf("\nParsing Failed! The input string is invalid.\n");
    }
}

int main() {
    char input[MAX];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character from input

    shiftReduceParser(input);  // Perform the shift-reduce parsing on the input string

    return 0;
}