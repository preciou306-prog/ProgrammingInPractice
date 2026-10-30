#include <stdio.h>
#include "reports.h"
#include "employees.h"
#include "budget.h"

void employeeReport(void)
{
    int count = getEmployeeCount();
    double total = calculatePayrollTotal();

    printf("\n--- EMPLOYEE REPORT ---\n");
    printf("Number of employees: %d\n", count);
    printf("Total payroll      : %.2f\n", total);

    if (count > 0)
    {
        printf("Average salary     : %.2f\n", total / count);
    }
}

void budgetReport(void)
{
    double balance = calculateBudgetBalance();

    printf("\n--- BUDGET REPORT ---\n");
    printf("Revenue : %.2f\n", getRevenue());
    printf("Expenses: %.2f\n", getExpenses());
    printf("Balance : %.2f\n", balance);

    if (balance > 0)
    {
        printf("Status  : SURPLUS\n");
    }
    else if (balance < 0)
    {
        printf("Status  : DEFICIT\n");
    }
    else
    {
        printf("Status  : BALANCED\n");
    }
}