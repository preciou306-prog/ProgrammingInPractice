#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 50

typedef struct
{
    char name[100];
    char phone[30];
    char town[50];
} Supplier;

void addSupplier(void);
void listSuppliers(void);
int saveSuppliers(void);
int loadSuppliers(void);
int getSupplierCount(void);

#endif