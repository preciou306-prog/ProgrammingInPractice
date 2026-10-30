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