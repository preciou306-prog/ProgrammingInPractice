# MFMS Week 9 - Multi-file Municipal Financial Management System

## Modules
- main.c: menu and program flow
- employees.c/.h: add, list, search employees and payroll total
- budget.c/.h: revenue, expenses and budget balance
- utilities.c/.h: input helpers (readLine, readInt, readDouble, pauseScreen)
- reports.c/.h: employee and budget reports

## Build
gcc -std=c99 -Wall -Wextra -pedantic -c main.c
gcc -std=c99 -Wall -Wextra -pedantic -c employees.c
gcc -std=c99 -Wall -Wextra -pedantic -c budget.c
gcc -std=c99 -Wall -Wextra -pedantic -c utilities.c
gcc -std=c99 -Wall -Wextra -pedantic -c reports.c
gcc main.o employees.o budget.o utilities.o reports.o -o mfms

## Run
./mfms