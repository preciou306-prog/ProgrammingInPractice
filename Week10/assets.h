#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 50

typedef struct
{
    char name[100];
    double value;
} Asset;

void addAsset(void);
void listAssets(void);
int saveAssets(void);
int loadAssets(void);
int getAssetCount(void);

#endif