#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SUPPLIERS 5
#define EMPLOYEE_COUNT 5

/* Supplier data shared by the supplier functions */
char supplierNames[MAX_SUPPLIERS][100];
char supplierEmails[MAX_SUPPLIERS][100];
char supplierPhones[MAX_SUPPLIERS][30];
char supplierTowns[MAX_SUPPLIERS][50];
int supplierCount = 0;

/* Function prototypes */
void displayWelcome();
void displayMenu();
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);
void addSupplier();
void displaySupplier();
void searchSupplier();
void supplierManagement();
void readLine(char *buf, int size);
int readInt();
float readFloat();

int main()
{
    int employeeIDs[EMPLOYEE_COUNT] = {101, 102, 103, 104, 105};
    int choice = 0;
    int id = 0;
    int position = 0;
    float basic = 0, housing = 0, transport = 0;
    float amount = 0, revenue = 0, expenses = 0, balance = 0;

    displayWelcome();

    do
    {
        displayMenu();
        choice = readInt();

        switch (choice)
        {
            case 1:
                printf("Basic salary: ");
                basic = readFloat();
                printf("Housing allowance: ");
                housing = readFloat();
                printf("Transport allowance: ");
                transport = readFloat();
                printf("Gross salary: %.2f\n",
                       calculateSalary(basic, housing, transport));
                break;

            case 2:
                printf("Enter amount: ");
                amount = readFloat();
                printf("VAT: %.2f\n", calculateVAT(amount));
                break;

            case 3:
                printf("Enter revenue: ");
                revenue = readFloat();
                printf("Enter expenses: ");
                expenses = readFloat();
                balance = calculateBudget(revenue, expenses);
                printf("Balance: %.2f\n", balance);
                if (balance > 0)
                {
                    printf("SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("DEFICIT\n");
                }
                else
                {
                    printf("BALANCED\n");
                }
                break;

            case 4:
                printf("Enter employee ID: ");
                id = readInt();
                position = searchEmployee(id, employeeIDs, EMPLOYEE_COUNT);
                if (position == -1)
                {
                    printf("Employee not found.\n");
                }
                else
                {
                    printf("Employee found at position %d.\n", position);
                }
                break;

            case 5:
                supplierManagement();
                break;

            case 6:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayWelcome()
{
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu()
{
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}

void addSupplier()
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    printf("Enter supplier name: ");
    readLine(supplierNames[supplierCount], sizeof(supplierNames[supplierCount]));
    printf("Enter email: ");
    readLine(supplierEmails[supplierCount], sizeof(supplierEmails[supplierCount]));
    printf("Enter phone: ");
    readLine(supplierPhones[supplierCount], sizeof(supplierPhones[supplierCount]));
    printf("Enter town: ");
    readLine(supplierTowns[supplierCount], sizeof(supplierTowns[supplierCount]));
    supplierCount++;
    printf("Supplier added.\n");
}

void displaySupplier()
{
    if (supplierCount == 0)
    {
        printf("No suppliers captured yet.\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\n--- SUPPLIER %d ---\n", i + 1);
        printf("Name : %s\n", supplierNames[i]);
        printf("Email: %s\n", supplierEmails[i]);
        printf("Phone: %s\n", supplierPhones[i]);
        printf("Town : %s\n", supplierTowns[i]);
    }
}

void searchSupplier()
{
    char searchName[100];
    int found = 0;

    printf("Enter supplier name to search: ");
    readLine(searchName, sizeof(searchName));

    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierNames[i], searchName) == 0)
        {
            printf("Supplier found: %s, %s, %s\n",
                   supplierEmails[i], supplierPhones[i], supplierTowns[i]);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Supplier not found.\n");
    }
}

void supplierManagement()
{
    int sub = 0;

    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to main menu\n");
        printf("Enter choice: ");
        sub = readInt();

        switch (sub)
        {
            case 1: addSupplier(); break;
            case 2: displaySupplier(); break;
            case 3: searchSupplier(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (sub != 4);
}

/* Helper: read a line and remove the newline fgets keeps */
void readLine(char *buf, int size)
{
    if (fgets(buf, size, stdin) == NULL)
    {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

int readInt()
{
    char line[50];
    readLine(line, sizeof(line));
    return atoi(line);
}

float readFloat()
{
    char line[50];
    readLine(line, sizeof(line));
    return (float)atof(line);
}