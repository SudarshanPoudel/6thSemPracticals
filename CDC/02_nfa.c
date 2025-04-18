// NFA Ending with ab

#include <stdio.h>
#include <string.h>

int accepted = 0;

void A(char[], int);
void B(char[], int);
void C(char[], int);

int main() {
    char input[100];
    printf("Enter Input string: ");
    scanf("%s", input);
    
    A(input, 0);

    if (accepted)
        printf("\nString accepted.\n");
    else
        printf("\nString rejected.\n");

    return 0;
}

void A(char input[], int i) {
    printf("\nState A");
    if (input[i] == '\0') return;

    A(input, i + 1);

    if (input[i] == 'a') {
        B(input, i + 1);  
    }
}

void B(char input[], int i) {
    printf("\nState B");
    if (input[i] == '\0') return;

    if (input[i] == 'b') {
        C(input, i + 1);
    }
}

void C(char input[], int i) {
    printf("\nState C");
    if (input[i] == '\0') {
        accepted = 1;
    }
}
