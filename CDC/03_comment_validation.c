#include <stdio.h>
#include <string.h>

int isSingleLineComment(char str[]) {
    return (str[0] == '/' && str[1] == '/');
}

int isMultiLineComment(char str[]) {
    int len = strlen(str);
    return (len >= 4 && str[0] == '/' && str[1] == '*' &&
            str[len - 2] == '*' && str[len - 1] == '/');
}

int main() {
    char input[1000];

    printf("Enter a comment string: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline (if any)
    input[strcspn(input, "\n")] = 0;

    if (isSingleLineComment(input)) {
        printf("Valid single-line comment.\n\n");
    } else if (isMultiLineComment(input)) {
        printf("Valid multi-line comment.\n\n");
    } else {
        printf("Invalid comment.\n");
    }

    return 0;
}
