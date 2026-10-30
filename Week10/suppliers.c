#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

void addSupplier(void)
{
    Supplier *s;

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    s = &suppliers[supplierCount];
    printf("Enter supplier name: ");
    readLine(s->name, sizeof s->name);
    printf("Enter phone: ");
    readLine(s->phone, sizeof s->phone);
    printf("Enter town: ");
    readLine(s->town, sizeof s->town);

    supplierCount++;
    printf("Supplier added.\n");
}

void listSuppliers(void)
{
    if (supplierCount == 0)
    {
        printf("No suppliers captured yet.\n");
        return;
    }

    printf("\n%-25s %-15s %-15s\n", "Name", "Phone", "Town");
    for (int i = 0; i < supplierCount; i++)
    {
        printf("%-25s %-15s %-15s\n",
               suppliers[i].name, suppliers[i].phone, suppliers[i].town);
    }
}

/* Text format: name|phone|town */
int saveSuppliers(void)
{
    FILE *fp = fopen("data/suppliers.txt", "w");

    if (fp == NULL)
    {
        perror("data/suppliers.txt");
        return 0;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        fprintf(fp, "%s|%s|%s\n",
                suppliers[i].name, suppliers[i].phone, suppliers[i].town);
    }

    fclose(fp);
    printf("Saved %d supplier(s) to data/suppliers.txt\n", supplierCount);
    return 1;
}

int loadSuppliers(void)
{
    FILE *fp = fopen("data/suppliers.txt", "r");
    char line[300];
    Supplier s;
    int count = 0;

    if (fp == NULL)
    {
        printf("No saved suppliers found (data/suppliers.txt).\n");
        return 0;
    }

    while (fgets(line, sizeof line, fp) != NULL && count < MAX_SUPPLIERS)
    {
        if (sscanf(line, "%99[^|]|%29[^|]|%49[^\n]", s.name, s.phone, s.town) == 3)
        {
            suppliers[count] = s;
            count++;
        }
        else
        {
            printf("Skipped a malformed line in suppliers.txt\n");
        }
    }

    fclose(fp);
    supplierCount = count;
    printf("Loaded %d supplier(s) from data/suppliers.txt\n", supplierCount);
    return 1;
}

int getSupplierCount(void)
{
    return supplierCount;
}