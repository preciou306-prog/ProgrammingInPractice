#include <stdio.h>

int main()
{
    char names[4][50];
    float prices[4];
    int registered[4];
    int documentsComplete[4];
    int qualified[4];
    float budget = 0;
    float lowestPrice = 0;
    int preferred = -1;

    printf("TENDER EVALUATION\n");
    printf("-----------------\n");

    printf("Enter available budget: ");
    scanf("%f", &budget);

    for (int i = 0; i < 4; i++)
    {
        printf("\nSupplier %d\n", i + 1);

        printf("Enter supplier name: ");
        scanf("%49s", names[i]);

        printf("Enter tender price: ");
        scanf("%f", &prices[i]);

        printf("Is supplier registered? (1=Yes, 0=No): ");
        scanf("%d", &registered[i]);

        printf("Are all documents complete? (1=Yes, 0=No): ");
        scanf("%d", &documentsComplete[i]);

        if (registered[i] == 1 && documentsComplete[i] == 1 && prices[i] <= budget)
        {
            qualified[i] = 1;

            if (preferred == -1 || prices[i] < lowestPrice)
            {
                preferred = i;
                lowestPrice = prices[i];
            }
        }
        else
        {
            qualified[i] = 0;
        }
    }

    printf("\n--- Evaluation Results ---\n");

    for (int i = 0; i < 4; i++)
    {
        printf("%-12s %10.2f  ", names[i], prices[i]);

        if (qualified[i] == 0)
        {
            printf("Disqualified\n");
        }
        else if (i == preferred)
        {
            printf("Preferred Supplier\n");
        }
        else
        {
            printf("Qualified\n");
        }
    }

    return 0;
}