#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

/* Read a line and remove the newline that fgets keeps */
void readLine(char *buf, int size)
{
    if (fgets(buf, size, stdin) == NULL)
    {
        buf[0] = '\0';
        return;
    }
    buf[strcspn(buf, "\n")] = '\0';
}

int readInt(void)
{
    char line[50];
    readLine(line, sizeof line);
    return atoi(line);
}

double readDouble(void)
{
    char line[50];
    readLine(line, sizeof line);
    return atof(line);
}

void pauseScreen(void)
{
    char line[10];
    printf("\nPress Enter to continue...");
    readLine(line, sizeof line);
}