#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX][10];
int top = -1;
int tempVar = 1;
char finalResultVar[10] = "";

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void push(char *str) {
    strcpy(stack[++top], str);
}

char* pop() {
    return stack[top--];
}

void generate3AC(char expr[]) {
    char opStack[MAX];
    int opTop = -1;
    char token, op, temp[10], left[10], right[10];
    int i = 0;

    // Detect assignment (e.g., A=...)
    if (isalpha(expr[0]) && expr[1] == '=') {
        finalResultVar[0] = expr[0];
        finalResultVar[1] = '\0';
        i = 2; // Skip 'A='
    }

    for (; expr[i]; i++) {
        token = expr[i];
        if (isspace(token)) continue;

        if (isalnum(token)) {
            char operand[2] = {token, '\0'};
            push(operand);
        } else if (token == '(') {
            opStack[++opTop] = token;
        } else if (token == ')') {
            while (opStack[opTop] != '(') {
                op = opStack[opTop--];
                strcpy(right, pop());
                strcpy(left, pop());
                sprintf(temp, "t%d", tempVar++);
                printf("%s = %s %c %s\n", temp, left, op, right);
                push(temp);
            }
            opTop--; // Pop '('
        } else { // Operator
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(token)) {
                op = opStack[opTop--];
                strcpy(right, pop());
                strcpy(left, pop());
                sprintf(temp, "t%d", tempVar++);
                printf("%s = %s %c %s\n", temp, left, op, right);
                push(temp);
            }
            opStack[++opTop] = token;
        }
    }

    while (opTop != -1) {
        op = opStack[opTop--];
        strcpy(right, pop());
        strcpy(left, pop());
        sprintf(temp, "t%d", tempVar++);
        printf("%s = %s %c %s\n", temp, left, op, right);
        push(temp);
    }

    if (finalResultVar[0] != '\0') {
        printf("%s = %s\n", finalResultVar, pop());
    }
}

int main() {
    char expr[MAX];
    printf("Enter infix expression: ");
    scanf("%s", expr);

    printf("\nThree Address Code:\n");
    generate3AC(expr);

    return 0;
}
