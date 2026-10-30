#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

static void displayMainMenu(void)
{
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Add Employee\n");
    printf("2. List Employees\n");
    printf("3. Search Employee\n");
    printf("4. Enter Budget\n");
    printf("5. Reports\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

int main(void)
{
    int choice = 0;
    int id = 0;
    int index = 0;

    do
    {
        displayMainMenu();
        choice = readInt();

        switch (choice)
        {
            case 1:
                addEmployee();
                break;
            case 2:
                listEmployees();
                break;
            case 3:
                printf("Enter employee ID: ");
                id = readInt();
                index = searchEmployee(id);
                if (index == -1)
                {
                    printf("Employee not found.\n");
                }
                else
                {
                    displayEmployee(index);
                }
                break;
            case 4:
                addBudget();
                break;
            case 5:
                employeeReport();
                budgetReport();
                break;
            case 6:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (choice != 6)
        {
            pauseScreen();
        }
    } while (choice != 6);

    return 0;
}