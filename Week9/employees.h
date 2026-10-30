#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100

typedef struct
{
    int id;
    char name[50];
    double salary;
} Employee;

void addEmployee(void);
void listEmployees(void);
int searchEmployee(int id);
void displayEmployee(int index);
double calculatePayrollTotal(void);
int getEmployeeCount(void);

#endif