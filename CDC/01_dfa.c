#include <stdio.h>

void A(char[], int);
void B(char[], int);
void C(char[], int);
void D(char[], int);

int main() {
    char input[100];
    printf("Enter Input string: ");
    scanf("%s", input);
    A(input, 0);
    return 0;
}

void A(char input[], int i) {
    printf("\nState A");
    if(input[i] == 'a') {
        B(input, i + 1);
    } else {
        D(input, i);
    }
}

void B(char input[], int i) {
    printf("\nState B");
    if(input[i] == 'b') {
        C(input, i + 1);
    } else {
        D(input, i);
    }
}

void C(char input[], int i) {
    printf("\nState C");
    if(input[i] == '\0') {
        printf("\nString accepted.\n");
        return;
    } else {
        C(input, i + 1); 
    }
}

void D(char input[], int i) {
    printf("\nState D");
    printf("\nString rejected.\n");
}
