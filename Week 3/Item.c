#include <stdio.h>
#include <string.h>

#define ITEM_NAME 20
#define ITEM_ARRAY_ELEMENT 10

enum Type
{
    Clothing,
    Footwear,
    Electronics
};

union Info
{
    int size;
    float weight;
};

struct Item
{
    char name[ITEM_NAME];
    float price;
    enum Type type;
    union Info info;
};

// Define a function to enter item information
void enterItemInfo(struct Item *item)
{
    printf("Name: ");
    scanf("%s", item->name);
    printf("Price: ");
    scanf("%f", &item->price);
    printf("Type (0: Clothing, 1: Footwear, 2: Electronics): ");
    scanf("%d", &item->type);
    if (item->type == 0 || item->type == 1)
    {
        printf("Size: ");
        scanf("%d", &item->info.size);
    }
    else
    {
        printf("Weight: ");
        scanf("%f", &item->info.weight);
    }
    printf("\n");
}

// Define a function to print out the item's type
void printProductType(struct Item *item)
{
    switch (item->type)
    {
    case 0:
        printf("Clothing");
        break;
    case 1:
        printf("Footwear");
        break;
    case 2:
        printf("Electronics");
        break;
    default:
        break;
    }
}

// Define a function to print the product's information
void printProductInfo(struct Item *item)
{
    printf("Name: %s", item->name);
    printf("\nPrice: %.2f", item->price);
    printf("\nType: ");
    printProductType(item);
    if (item->type == 2)
        printf("\nWeight: %.2f", item->info.weight);
    else
        printf("\nSize: %d", item->info.size);
}

// Define a function to enter a list of items
void enterItemList(int number, struct Item items[ITEM_ARRAY_ELEMENT])
{
    for (int i = 0; i < number; i++)
    {
        printf("Enter information for product %d:\n", i + 1);
        enterItemInfo(&items[i]);
    }
}

// Define a function to print out the retrieved product
void printRetrievedProduct(int number, char productName[ITEM_NAME], struct Item items[ITEM_ARRAY_ELEMENT])
{
    // Declare a flag
    int found = 0;

    // If there is a matching item
    printf("Product Information:\n");
    for (int i = 0; i < number; i++)
    {
        if (strcmp(productName, items[i].name) == 0)
        {
            printProductInfo(&items[i]);
            found = 1;
            break;
        }
    }

    // If there is no matching item
    if (found != 1)
        printf("\nThere is no matching item. Please enter again.\n");
}

int main()
{
    struct Item items[ITEM_ARRAY_ELEMENT];
    int number;
    printf("Enter the amount of items: ");
    scanf("%d", &number);

    printf("\n");

    enterItemList(number, items);

    char productName[ITEM_NAME];
    printf("Enter the name of the product to retrieve information: ");
    scanf("%s", productName);

    printRetrievedProduct(number, productName, items);

    return 0;
}