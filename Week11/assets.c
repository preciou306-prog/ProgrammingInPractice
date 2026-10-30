#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utilities.h"

static Asset assets[MAX_RECORDS];
static int assetCount = 0;

static void readDate(Date *d)
{
    printf("  Day: ");
    d->day = readInt();
    printf("  Month: ");
    d->month = readInt();
    printf("  Year: ");
    d->year = readInt();
}

void addAsset(void)
{
    Asset *a;

    if (assetCount >= MAX_RECORDS)
    {
        printf("Asset list is full.\n");
        return;
    }

    a = &assets[assetCount];
    printf("Enter asset ID: ");
    a->id = readInt();
    printf("Enter description: ");
    readLine(a->description, sizeof a->description);
    printf("Enter value: ");
    a->value = readDouble();
    printf("Enter acquired date:\n");
    readDate(&a->acquired);

    assetCount++;
    printf("Asset added.\n");
}

void listAssets(void)
{
    if (assetCount == 0)
    {
        printf("No assets captured yet.\n");
        return;
    }

    printf("\n%-6s %-25s %14s %-12s\n", "ID", "Description", "Value", "Acquired");
    for (int i = 0; i < assetCount; i++)
    {
        printf("%-6d %-25s %14.2f %02d/%02d/%d\n",
               assets[i].id, assets[i].description, assets[i].value,
               assets[i].acquired.day, assets[i].acquired.month,
               assets[i].acquired.year);
    }
}

/* Text format: id|description|value|day|month|year */
int saveAssets(void)
{
    FILE *fp = fopen("data/assets.txt", "w");

    if (fp == NULL)
    {
        perror("data/assets.txt");
        return 0;
    }

    for (int i = 0; i < assetCount; i++)
    {
        fprintf(fp, "%d|%s|%.2f|%d|%d|%d\n",
                assets[i].id, assets[i].description, assets[i].value,
                assets[i].acquired.day, assets[i].acquired.month,
                assets[i].acquired.year);
    }

    fclose(fp);
    printf("Saved %d asset(s) to data/assets.txt\n", assetCount);
    return 1;
}

int loadAssets(void)
{
    FILE *fp = fopen("data/assets.txt", "r");
    char line[200];
    Asset a;
    int count = 0;

    if (fp == NULL)
    {
        printf("No saved assets found (data/assets.txt).\n");
        return 0;
    }

    while (fgets(line, sizeof line, fp) != NULL && count < MAX_RECORDS)
    {
        if (sscanf(line, "%d|%39[^|]|%lf|%d|%d|%d",
                   &a.id, a.description, &a.value,
                   &a.acquired.day, &a.acquired.month, &a.acquired.year) == 6)
        {
            assets[count] = a;
            count++;
        }
        else
        {
            printf("Skipped a malformed line in assets.txt\n");
        }
    }

    fclose(fp);
    assetCount = count;
    printf("Loaded %d asset(s) from data/assets.txt\n", assetCount);
    return 1;
}

int getAssetCount(void)
{
    return assetCount;
}