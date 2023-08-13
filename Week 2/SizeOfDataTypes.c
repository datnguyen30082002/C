#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <string.h>

int main()
{
    char dataType[10];
    printf("Enter the data type name (or 'all' to display all): ");
    scanf("%[^\n]s", dataType);

    if (strcmp(dataType, "int") == 0)
    {
        // Size of int
        printf("\nSize of int: %lu bytes\n", sizeof(int));
        printf("Range of int: %d to %d\n", INT_MIN, INT_MAX);
    }
    else if (strcmp(dataType, "float") == 0)
    {
        // Size of float
        printf("Size of float: %lu bytes\n", sizeof(float));
        printf("Range of float: %E to %E\n", FLT_MIN, FLT_MAX);
    }
    else if (strcmp(dataType, "double") == 0)
    {
        // Size of double
        printf("Size of double: %lu bytes\n", sizeof(double));
        printf("Range of double: %E to %E\n", DBL_MIN, DBL_MAX);
    }
    else if (strcmp(dataType, "char") == 0)
    {
        // Size of char
        printf("Size of char: %lu byte\n", sizeof(char));
        printf("Range of char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    }
    else
    {
        // Size of int
        printf("\nSize of int: %lu bytes\n", sizeof(int));
        printf("Range of int: %d to %d\n", INT_MIN, INT_MAX);

        // Size of float
        printf("Size of float: %lu bytes\n", sizeof(float));
        printf("Range of float: %e to %e\n", FLT_MIN, FLT_MAX);

        // Size of double
        printf("Size of double: %lu bytes\n", sizeof(double));
        printf("Range of double: %e to %e\n", DBL_MIN, DBL_MAX);

        // Size of char
        printf("Size of char: %lu byte\n", sizeof(char));
        printf("Range of char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    }

    return 0;
}