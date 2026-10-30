#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utilities.h"

static Supplier suppliers[MAX_RECORDS];
static int supplierCount = 0;

void addSupplier(void)
{
    Supplier *s;

    if (supplierCount >= MAX_RECORDS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    s = &suppliers[supplierCount];
    printf("Enter supplier ID: ");
    s->id = readInt();
    printf("Enter supplier name: ");
    readLine(s->name, sizeof s->name);
    printf("Enter email: ");
    readLine(s->email, sizeof s->email);
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

    printf("\n%-6s %-20s %-22s %-12s %-12s\n",
           "ID", "Name", "Email", "Phone", "Town");
    for (int i = 0; i < supplierCount; i++)
    {
        printf("%-6d %-20s %-22s %-12s %-12s\n",
               suppliers[i].id, suppliers[i].name, suppliers[i].email,
               suppliers[i].phone, suppliers[i].town);
    }
}

/* Text format: id|name|email|phone|town */
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
        fprintf(fp, "%d|%s|%s|%s|%s\n",
                suppliers[i].id, suppliers[i].name, suppliers[i].email,
                suppliers[i].phone, suppliers[i].town);
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

    while (fgets(line, sizeof line, fp) != NULL && count < MAX_RECORDS)
    {
        if (sscanf(line, "%d|%39[^|]|%39[^|]|%14[^|]|%19[^\n]",
                   &s.id, s.name, s.email, s.phone, s.town) == 5)
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