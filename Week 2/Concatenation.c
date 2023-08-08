#include <stdio.h>

#define CONCAT(a, b) a ## b

int main() {
    int xy= 42;
    printf("The concatenated variable is: %d\n", CONCAT(x, y));
    return 0;
}