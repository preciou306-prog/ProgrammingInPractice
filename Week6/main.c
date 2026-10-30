#include <stdio.h>
#include <string.h>

#define SALARY_COUNT 50
#define BUDGET_COUNT 10
#define REG_COUNT 20

int main()
{
    float salaries[SALARY_COUNT];
    float budgets[BUDGET_COUNT];
    char registrations[REG_COUNT][20];

    float total = 0;
    float average = 0;
    float highest = 0;
    float lowest = 0;
    float searchSalary = 0;
    char searchReg[20];
    int found = 0;
    float temp = 0;

    printf("MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
    printf("=======================================\n");

    /* ---------- PART A: EMPLOYEE SALARIES ---------- */
    printf("\nPART A: EMPLOYEE SALARIES\n");

    for (int i = 0; i < SALARY_COUNT; i++)
    {
        printf("Enter salary %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("\nEmployee Salaries\n");
    total = 0;
    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < SALARY_COUNT; i++)
    {
        printf("%d. %.2f\n", i + 1, salaries[i]);
        total = total + salaries[i];

        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
        if (salaries[i] < lowest)
        {
            lowest = salaries[i];
        }
    }

    average = total / SALARY_COUNT;
    printf("\nAverage salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary : %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchSalary);

    found = 0;
    for (int i = 0; i < SALARY_COUNT; i++)
    {
        if (salaries[i] == searchSalary)
        {
            printf("Salary found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Salary not found.\n");
    }

    /* ---------- PART B: DEPARTMENT BUDGETS ---------- */
    printf("\nPART B: DEPARTMENT BUDGETS\n");

    for (int i = 0; i < BUDGET_COUNT; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }

    printf("\nDepartment Budgets\n");
    total = 0;
    for (int i = 0; i < BUDGET_COUNT; i++)
    {
        printf("%d. %.2f\n", i + 1, budgets[i]);
        total = total + budgets[i];
    }

    average = total / BUDGET_COUNT;
    printf("\nTotal budget  : %.2f\n", total);
    printf("Average budget: %.2f\n", average);

    for (int i = 0; i < BUDGET_COUNT - 1; i++)
    {
        for (int j = 0; j < BUDGET_COUNT - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets sorted (lowest to highest)\n");
    for (int i = 0; i < BUDGET_COUNT; i++)
    {
        printf("%.2f\n", budgets[i]);
    }

    /* ---------- PART C: VEHICLE REGISTRATIONS ---------- */
    printf("\nPART C: VEHICLE REGISTRATION NUMBERS\n");

    for (int i = 0; i < REG_COUNT; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nVehicle Registrations\n");
    for (int i = 0; i < REG_COUNT; i++)
    {
        printf("%d. %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter a registration number to search for: ");
    scanf("%19s", searchReg);

    found = 0;
    for (int i = 0; i < REG_COUNT; i++)
    {
        if (strcmp(registrations[i], searchReg) == 0)
        {
            printf("Registration found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Registration not found.\n");
    }

    return 0;
}