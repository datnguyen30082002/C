/*
Reference: Split string until delimiter
https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
*/
#include <stdio.h>
#include <string.h>

#define SIZE 50
#define NAME 50
#define PHONE_NUMBER 50
#define ADDRESS 100

// Define a struct of contact
typedef struct
{
    char name[NAME];
    char phoneNumber[PHONE_NUMBER];
    char address[ADDRESS];
} Info;

// Define a function to print out the contact's information
void printContactInfo(Info contact)
{
    printf("Name: %s\n", contact.name);
    printf("Phone: %s\n", contact.phoneNumber);
    printf("Address: %s\n", contact.address);
}

// Define a function to print out all of the contacts
void printContacts(Info contacts[SIZE], int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("\n");
        printContactInfo(contacts[i]);
    }
}

// Define a function that converts upper case character into lower case character to make sure that users can enter the name in both upper and lower character
void toLowerCase(char characterArray[])
{
    for (int i = 0; i < strlen(characterArray); i++)
    {
        if (characterArray[i] > 'A' && characterArray[i] < 'Z')
            characterArray[i] += 32;
    }
}

// Define a function to print out the contact that is matched with the entered name
void searchContacts(Info contacts[SIZE], int number, char name[NAME])
{
    for (int i = 0; i < number; i++)
    {
        char name1[NAME], name2[NAME];
        strcpy(name1, contacts[i].name);
        strcpy(name2, name);

        toLowerCase(name1);
        toLowerCase(name2);

        if (strstr(name1, name2) != NULL)
        {
            printf("\nContact found:\n");
            printContactInfo(contacts[i]);
        }
    }
}

// Write contact's data to file function
void writeContactToFile(FILE *file)
{
    Info contact;

    printf("Enter name: ");
    getchar(); // Consume the newline character left in the input buffer
    scanf("%[^\n]s", contact.name);
    printf("Enter phone number: ");
    getchar();
    scanf("%[^\n]s", contact.phoneNumber);
    printf("Enter address: ");
    getchar(); // Consume the newline character left in the input buffer
    scanf("%[^\n]s", contact.address);

    fprintf(file, "%s | %s | %s\n", contact.name, contact.phoneNumber, contact.address);

    printf("\nContact added successfully!\n");
}

// Define a function to load contact's data from file
void loadContactsFromFile(char fileName[50], Info contacts[], int *number)
{
    FILE *file = fopen("contact.txt", "r");

    if (file == NULL)
    {
        printf("File cannot be opened");
        return;
    }

    *number = 0; // Size of the contacts array

    char line[500];

    /*
    This block of code is used for extracting the data from the file and store back to the contact object.
    After extracting and storing successfully then it will push back the contact object to the contact array.
    */

    while (fgets(line, sizeof(line), file))
    {
        Info contact;

        // Split line to each contact object's parameter
        int index = 0;
        char *token = strtok(line, "|");

        // Keep printing tokens while one of the delimiters present in str[].
        while (token != NULL)
        {
            if (index == 0) // To extract the name
            {
                strcpy(contact.name, token);
                index++;
            }
            else if (index == 1) // To extract the phone number
            {
                strcpy(contact.phoneNumber, token);
                index++;
            }
            else if (index == 2) // To extract the address
            {
                strcpy(contact.address, token);
                index++;
            }
            token = strtok(NULL, "|");
        }

        // Store the above information back to the array of contact object
        contacts[*number] = contact; // Push back the contact object to the contact array
        *number = *number + 1;       // Increase the array size by 1
    }

    fclose(file);
}

int main()
{
    char fileName[50] = "contact.txt";
    FILE *file = fopen(fileName, "a+");

    if (file == NULL)
    {
        printf("File cannot be open!\n");
        return 1;
    }

    Info contacts[SIZE];
    int number = 0;

    int choice;
    char searchName[NAME];

    do
    {
        printf("\nWelcome to the Contact Manager!\n");
        printf("1. Add new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search for a contact\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            writeContactToFile(file);
            fclose(file);
            break;
        case 2:
            loadContactsFromFile(fileName, contacts, &number);
            printContacts(contacts, number);
            break;
        case 3:
            printf("Enter contact name: ");
            getchar();
            scanf("%[^\n]s", searchName);

            searchContacts(contacts, number, searchName);
            break;
        case 4:
            printf("Goodbye!\n");
            break;
        default:
            printf("\nThere is no matching option. Please enter again.\n");
            break;
        }
    } while (choice != 4);

    fclose(file);

    return 0;
}