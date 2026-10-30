#include <stdio.h>
#include "budget.h"
#include "utilities.h"

static double revenue = 0.0;
static double expenses = 0.0;

void addBudget(void)
{
    printf("Enter total revenue: ");
    revenue = readDouble();
    printf("Enter total expenses: ");
    expenses = readDouble();
    printf("Budget captured.\n");
}

double calculateBudgetBalance(void)
{
    return revenue - expenses;
}

double getRevenue(void)
{
    return revenue;
}

double getExpenses(void)
{
    return expenses;
}

/* ---------- Week 10: file handling ---------- */

/* Text format: revenue|expenses */
int saveBudget(void)
{
    FILE *fp = fopen("data/budget.txt", "w");

    if (fp == NULL)
    {
        perror("data/budget.txt");
        return 0;
    }

    fprintf(fp, "%.2f|%.2f\n", revenue, expenses);
    fclose(fp);
    printf("Saved budget to data/budget.txt\n");
    return 1;
}

int loadBudget(void)
{
    FILE *fp = fopen("data/budget.txt", "r");
    char line[100];
    double r, e;

    if (fp == NULL)
    {
        printf("No saved budget found (data/budget.txt).\n");
        return 0;
    }

    if (fgets(line, sizeof line, fp) != NULL &&
        sscanf(line, "%lf|%lf", &r, &e) == 2)
    {
        revenue = r;
        expenses = e;
        printf("Loaded budget from data/budget.txt\n");
    }
    else
    {
        printf("Budget file is empty or malformed.\n");
    }

    fclose(fp);
    return 1;
}