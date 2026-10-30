#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "utilities.h"

static Employee employees[MAX_RECORDS];
static int employeeCount = 0;

void addEmployee(void)
{
    Employee *e;
    int id;

    if (employeeCount >= MAX_RECORDS)
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
    printf("Enter department: ");
    readLine(e->department, sizeof e->department);
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

    printf("\n%-6s %-20s %-15s %12s\n", "ID", "Name", "Department", "Salary");
    for (int i = 0; i < employeeCount; i++)
    {
        printf("%-6d %-20s %-15s %12.2f\n",
               employees[i].id, employees[i].name,
               employees[i].department, employees[i].salary);
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
    printf("ID        : %d\n", employees[index].id);
    printf("Name      : %s\n", employees[index].name);
    printf("Department: %s\n", employees[index].department);
    printf("Salary    : %.2f\n", employees[index].salary);
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

/* ---------- file handling ---------- */

/* Text format: id|name|department|salary */
int saveEmployees(void)
{
    FILE *fp = fopen("data/employees.txt", "w");

    if (fp == NULL)
    {
        perror("data/employees.txt");
        return 0;
    }

    for (int i = 0; i < employeeCount; i++)
    {
        fprintf(fp, "%d|%s|%s|%.2f\n",
                employees[i].id, employees[i].name,
                employees[i].department, employees[i].salary);
    }

    fclose(fp);
    printf("Saved %d employee(s) to data/employees.txt\n", employeeCount);
    return 1;
}

int loadEmployees(void)
{
    FILE *fp = fopen("data/employees.txt", "r");
    char line[200];
    Employee e;
    int count = 0;

    if (fp == NULL)
    {
        printf("No saved employees found (data/employees.txt).\n");
        return 0;
    }

    while (fgets(line, sizeof line, fp) != NULL && count < MAX_RECORDS)
    {
        if (sscanf(line, "%d|%29[^|]|%19[^|]|%lf",
                   &e.id, e.name, e.department, &e.salary) == 4)
        {
            employees[count] = e;
            count++;
        }
        else
        {
            printf("Skipped a malformed line in employees.txt\n");
        }
    }

    fclose(fp);
    employeeCount = count;
    printf("Loaded %d employee(s) from data/employees.txt\n", employeeCount);
    return 1;
}

/* Binary format: raw Employee records */
int saveEmployeesBinary(void)
{
    FILE *fp = fopen("data/employees.dat", "wb");
    size_t written;

    if (fp == NULL)
    {
        perror("data/employees.dat");
        return 0;
    }

    written = fwrite(employees, sizeof employees[0], (size_t)employeeCount, fp);
    fclose(fp);

    if (written != (size_t)employeeCount)
    {
        printf("Error: not all employees were written.\n");
        return 0;
    }

    printf("Saved %d employee(s) to data/employees.dat\n", employeeCount);
    return 1;
}

int loadEmployeesBinary(void)
{
    FILE *fp = fopen("data/employees.dat", "rb");
    size_t count;

    if (fp == NULL)
    {
        printf("No binary employee file found (data/employees.dat).\n");
        return 0;
    }

    count = fread(employees, sizeof employees[0], MAX_RECORDS, fp);
    fclose(fp);

    employeeCount = (int)count;
    printf("Loaded %d employee(s) from data/employees.dat\n", employeeCount);
    return 1;
}