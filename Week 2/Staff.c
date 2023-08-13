#include <stdio.h>
#include <string.h>

// Define staff struct
struct Staff
{
    char name[50];
    int age;
    float salary;
};

// Define a staff's position enum
enum Position
{
    STAFF,
    MANAGER,
    DIRECTOR
};

// Print out staff's position function
void printPostion(enum Position pos)
{
    switch (pos)
    {
    case 0:
        printf(" Staff ");
        break;
    case 1:
        printf(" Manager ");
        break;
    case 2:
        printf(" Director ");
        break;
    }
}

// Define staff's information union
union Info
{
    int age;
    float salary;
};

int main()
{
    struct Staff staff;
    union Info info;
    enum Position position;

    // Enter staff's information
    printf("Enter staff's information:\n");
    printf("Name: ");
    scanf("%[^\n]s", staff.name);
    printf("Age: ");
    scanf("%d", &staff.age);
    printf("Salary: ");
    scanf("%f", &staff.salary);

    // Enter staff's position
    int choice;
    printf("Choose a position (0: Staff, 1: Manager, 2: Director): ");
    scanf("%d", &choice);
    position = choice;

    // Print out all of the staff's information
    printf("\nStaff's information:\n");
    printf("Name: %s\n", staff.name);
    printf("Age: %d\n", staff.age);
    printf("Salary: %.2f\n", staff.salary);
    printf("Position: ");
    printPostion(position);

    return 0;
}