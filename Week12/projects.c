#include <stdio.h>
#include "projects.h"
#include "utilities.h"

static Project projects[MAX_RECORDS];
static int projectCount = 0;

static void readDate(Date *d)
{
    printf("  Day: ");
    d->day = readInt();
    printf("  Month: ");
    d->month = readInt();
    printf("  Year: ");
    d->year = readInt();
}

void addProject(void)
{
    Project *p;

    if (projectCount >= MAX_RECORDS)
    {
        printf("Project list is full.\n");
        return;
    }

    p = &projects[projectCount];
    printf("Enter project ID: ");
    p->id = readInt();
    printf("Enter project title: ");
    readLine(p->title, sizeof p->title);
    printf("Enter project budget: ");
    p->budget = readDouble();
    printf("Enter start date:\n");
    readDate(&p->startDate);
    printf("Enter end date:\n");
    readDate(&p->endDate);

    projectCount++;
    printf("Project added.\n");
}

void listProjects(void)
{
    if (projectCount == 0)
    {
        printf("No projects captured yet.\n");
        return;
    }

    printf("\n%-6s %-22s %14s %-12s %-12s\n",
           "ID", "Title", "Budget", "Start", "End");
    for (int i = 0; i < projectCount; i++)
    {
        printf("%-6d %-22s %14.2f %02d/%02d/%d %02d/%02d/%d\n",
               projects[i].id, projects[i].title, projects[i].budget,
               projects[i].startDate.day, projects[i].startDate.month,
               projects[i].startDate.year,
               projects[i].endDate.day, projects[i].endDate.month,
               projects[i].endDate.year);
    }
}