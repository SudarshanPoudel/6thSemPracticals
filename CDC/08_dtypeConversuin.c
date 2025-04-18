#include <stdio.h>

int main() {
    int intVar = 10;
    float floatVar = 5.75;

    // Convert int to float
    float convertedToFloat = (float)intVar;
    printf("Integer %d converted to float: %.2f\n", intVar, convertedToFloat);

    // Convert float to int
    int convertedToInt = (int)floatVar;
    printf("Float %.2f converted to int: %d\n", floatVar, convertedToInt);

    return 0;
}
