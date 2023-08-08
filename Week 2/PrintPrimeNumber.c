#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Using preprocessor
#define IS_PRIME(number) (isPrimeNumber(number)) 

// Check whether the number is a prime number or not function
bool isPrimeNumber(int number)
{
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}

// Print out all the prime numbers in the range of the lower bound to the upper bound fucntion
void printAllPrimeNumbers(int lowerBound, int upperBound)
{
    for (int i = lowerBound; i <= upperBound; i++)
    {
        if (IS_PRIME(i))
            printf("%d ", i);
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1) // If there is only the program name, print out the error message
        printf("There is only the program name. Please enter again.");
    else if (argc == 2) // If there is not enough bounds, print out the error message
        printf("There is only one bound of the range. Please enter enough 2 bounds.");
    else // Print out all the prime numbers within the range
    {
        int lowerBound = atoi(argv[1]);
        int upperBound = atoi(argv[2]);

        printf("Prime numbers in range of %d to %d: \n", lowerBound, upperBound);
        printAllPrimeNumbers(lowerBound, upperBound);
    }

    return 0;
}