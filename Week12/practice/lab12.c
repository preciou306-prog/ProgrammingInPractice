#include <stdio.h>

#define COUNT 4

void swapWrong(double a, double b)
{
    double temp = a;
    a = b;
    b = temp;
}

void swapSalaries(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

void displaySalaries(const double salaries[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("  Employee %d: N$%.2f\n", i + 1, salaries[i]);
    }
}

double findHighest(const double salaries[], int n)
{
    double highest = salaries[0];
    for (int i = 1; i < n; i++)
    {
        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
    }
    return highest;
}

double calculateAverage(const double salaries[], int n)
{
    double total = 0.0;
    for (int i = 0; i < n; i++)
    {
        total += salaries[i];
    }
    return total / n;
}

void giveRaise(double salaries[], int n, double percent)
{
    for (int i = 0; i < n; i++)
    {
        salaries[i] = salaries[i] * (1 + percent / 100);
    }
}

int main(void)
{
    int age = 25;
    int *p = &age;
    double salaryA = 18500.50;
    double salaryB = 21000.75;
    double salaries[COUNT] = {15000.00, 18500.50, 21000.75, 17200.00};

    printf("--- Part A: pointer warm-up ---\n");
    printf("age = %d, address = %p, *p = %d\n", age, (void *)&age, *p);
    *p = 30;
    printf("After *p = 30, age = %d\n", age);

    printf("\n--- Part B: swapping ---\n");
    swapWrong(salaryA, salaryB);
    printf("After swapWrong: A = %.2f, B = %.2f (unchanged)\n", salaryA, salaryB);
    swapSalaries(&salaryA, &salaryB);
    printf("After swapSalaries: A = %.2f, B = %.2f (swapped)\n", salaryA, salaryB);

    printf("\n--- Part C: arrays and functions ---\n");
    printf("Before raise:\n");
    displaySalaries(salaries, COUNT);
    printf("Highest: N$%.2f\n", findHighest(salaries, COUNT));
    printf("Average: N$%.2f\n", calculateAverage(salaries, COUNT));

    giveRaise(salaries, COUNT, 10.0);
    printf("After a 10%% raise (the original array changed):\n");
    displaySalaries(salaries, COUNT);
    printf("Average: N$%.2f\n", calculateAverage(salaries, COUNT));

    return 0;
}