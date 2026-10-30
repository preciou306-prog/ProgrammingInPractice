#include <stdio.h>
#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"
#include "projects.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

static void displayMainMenu(void)
{
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf(" 1. Add Employee\n");
    printf(" 2. List Employees\n");
    printf(" 3. Search Employee\n");
    printf(" 4. Add Supplier\n");
    printf(" 5. List Suppliers\n");
    printf(" 6. Add Asset\n");
    printf(" 7. List Assets\n");
    printf(" 8. Add Department Budget\n");
    printf(" 9. List Department Budgets\n");
    printf("10. Add Project\n");
    printf("11. List Projects\n");
    printf("12. Enter Revenue and Expenses\n");
    printf("13. Reports\n");
    printf("14. Save Data (text files)\n");
    printf("15. Load Data (text files)\n");
    printf("16. Save Employees (binary)\n");
    printf("17. Load Employees (binary)\n");
    printf(" 0. Exit\n");
    printf("Enter choice: ");
}

int main(void)
{
    int choice = -1;
    int id = 0;
    int index = 0;

    do
    {
        displayMainMenu();
        choice = readInt();

        switch (choice)
        {
            case 1:  addEmployee(); break;
            case 2:  listEmployees(); break;
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
            case 4:  addSupplier(); break;
            case 5:  listSuppliers(); break;
            case 6:  addAsset(); break;
            case 7:  listAssets(); break;
            case 8:  addBudget(); break;
            case 9:  loadBudget(); break;
            case 10: addProject(); break;
            case 11: listProjects(); break;
            case 12: addBudget(); break;
            case 13:
                employeeReport();
                budgetReport();
                break;
            case 14:
                saveEmployees();
                saveSuppliers();
                saveAssets();
                saveBudget();
                break;
            case 15:
                loadEmployees();
                loadSuppliers();
                loadAssets();
                loadBudget();
                break;
            case 16: saveEmployeesBinary(); break;
            case 17: loadEmployeesBinary(); break;
            case 0:  printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }

        if (choice != 0)
        {
            pauseScreen();
        }
    } while (choice != 0);

    return 0;
}