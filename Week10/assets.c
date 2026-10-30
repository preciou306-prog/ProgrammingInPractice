#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "utilities.h"

static Asset assets[MAX_ASSETS];
static int assetCount = 0;

void addAsset(void)
{
    Asset *a;

    if (assetCount >= MAX_ASSETS)
    {
        printf("Asset list is full.\n");
        return;
    }

    a = &assets[assetCount];
    printf("Enter asset name: ");
    readLine(a->name, sizeof a->name);
    printf("Enter asset value: ");
    a->value = readDouble();

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

    printf("\n%-30s %15s\n", "Asset", "Value");
    for (int i = 0; i < assetCount; i++)
    {
        printf("%-30s %15.2f\n", assets[i].name, assets[i].value);
    }
}

/* Text format: name|value */
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
        fprintf(fp, "%s|%.2f\n", assets[i].name, assets[i].value);
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

    while (fgets(line, sizeof line, fp) != NULL && count < MAX_ASSETS)
    {
        if (sscanf(line, "%99[^|]|%lf", a.name, &a.value) == 2)
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