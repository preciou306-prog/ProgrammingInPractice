#include <stdio.h>
#include <string.h>

void readLine(char *buf, int size)
{
    if (fgets(buf, size, stdin) == NULL)
    {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

int main()
{
    char supplierName[100];
    char email[100];
    char phone[30];
    char town[50];
    char searchName[100];
    char backup[100];
    char description[300];

    /* Task 1: basic details */
    printf("Enter supplier name: ");
    readLine(supplierName, sizeof(supplierName));
    printf("Enter email: ");
    readLine(email, sizeof(email));
    printf("Enter phone: ");
    readLine(phone, sizeof(phone));
    printf("Enter town: ");
    readLine(town, sizeof(town));

    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s\n", supplierName);
    printf("Email: %s\n", email);
    printf("Phone: %s\n", phone);
    printf("Town : %s\n", town);

    /* Task 2: string length */
    printf("\nSupplier name length: %zu\n", strlen(supplierName));
    printf("Email length: %zu\n", strlen(email));
    printf("Town length: %zu\n", strlen(town));

    /* Task 3: supplier search with strcmp */
    printf("\nEnter supplier name to search: ");
    readLine(searchName, sizeof(searchName));

    if (strcmp(searchName, "ABC Office Supplies") == 0 ||
        strcmp(searchName, "Namibia Stationery") == 0)
    {
        printf("Supplier found.\n");
    }
    else
    {
        printf("Supplier not found.\n");
    }

    /* Task 4: copy with strcpy */
    strcpy(backup, supplierName);
    printf("\nOriginal: %s\n", supplierName);
    printf("Backup  : %s\n", backup);

    /* Task 5: build a sentence with strcpy and strcat */
    strcpy(description, supplierName);
    strcat(description, " operates in ");
    strcat(description, town);
    strcat(description, ".");
    printf("\n%s\n", description);

    return 0;
}