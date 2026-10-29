#include <stdio.h>

int main()
{
    float basicSalary = 0;
    float housing = 0;
    float transport = 0;
    float tax = 0;
    float grossSalary = 0;
    float netSalary = 0;

    printf("EMPLOYEE SALARY CALCULATOR\n");
    printf("--------------------------\n");

    printf("Enter basic salary: ");
    scanf("%f", &basicSalary);

    printf("Enter housing allowance: ");
    scanf("%f", &housing);

    printf("Enter transport allowance: ");
    scanf("%f", &transport);

    printf("Enter tax: ");
    scanf("%f", &tax);

    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    printf("\nGross Salary: %.2f\n", grossSalary);
    printf("Net Salary: %.2f\n", netSalary);

    if (netSalary >= 20000)
    {
        printf("High Income\n");
    }
    else
    {
        printf("Standard Income\n");
    }

    return 0;
}