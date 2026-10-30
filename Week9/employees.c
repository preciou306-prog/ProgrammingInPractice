#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static Employee employees[MAX_EMPLOYEES];
static int employeeCount = 0;

void addEmployee(void)
{
    Employee *e;
    int id;

    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("Employee list is full.\n");
        return;
    }

    printf("Enter employee ID: ");
    id = readInt();

    if (searchEmployee(id) != -1)
    {
        printf("An employee with that ID already exists.\n");
        return;
    }

    e = &employees[employeeCount];
    e->id = id;
    printf("Enter employee name: ");
    readLine(e->name, sizeof e->name);
    printf("Enter salary: ");
    e->salary = readDouble();

    employeeCount++;
    printf("Employee added.\n");
}

void listEmployees(void)
{
    if (employeeCount == 0)
    {
        printf("No employees captured yet.\n");
        return;
    }

    printf("\n%-8s %-25s %12s\n", "ID", "Name", "Salary");
    for (int i = 0; i < employeeCount; i++)
    {
        printf("%-8d %-25s %12.2f\n",
               employees[i].id, employees[i].name, employees[i].salary);
    }
}

int searchEmployee(int id)
{
    for (int i = 0; i < employeeCount; i++)
    {
        if (employees[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void displayEmployee(int index)
{
    printf("ID    : %d\n", employees[index].id);
    printf("Name  : %s\n", employees[index].name);
    printf("Salary: %.2f\n", employees[index].salary);
}

double calculatePayrollTotal(void)
{
    double total = 0.0;
    for (int i = 0; i < employeeCount; i++)
    {
        total += employees[i].salary;
    }
    return total;
}

int getEmployeeCount(void)
{
    return employeeCount;
}