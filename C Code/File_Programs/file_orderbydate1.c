#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <windows.h>
void header(int c, int r);

void gotoxy(short col, short row)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {col, row};
    SetConsoleCursorPosition(h, position);
}
struct date
{
    int d, m, y;
};
struct employee
{
    int empcode[6];
    char empname[20];
    struct date join_date;
    float salary;
};
typedef struct employee EMP;
EMP emp;
void swapemp(EMP *emp1, EMP *emp2)
{
    EMP temp;
    temp = *emp1;
    *emp1 = *emp2;
    *emp2 = temp;
}

void addRecords(FILE *fp, char empcode[])
{
    fseek(fp, 0, SEEK_END);
    printf("\nEnter the employee code\n");
    gets(empcode);
    for (int i = 0; i < 5; i++)
        emp.empcode[i] = empcode[i] - '0';
    printf("Enter name\n");
    gets(emp.empname);
    printf("\nEnter the year of joining\n");
    scanf("%d", &emp.join_date.y);
    printf("\nEnter the month of joining\n");
    scanf("%d", &emp.join_date.m);
    printf("\nEnter the date of joining\n");
    scanf("%d", &emp.join_date.d);
    printf("\nEnter salary\n");
    scanf("%f", &emp.salary);
    fwrite(&emp, sizeof(emp), 1, fp);
}

void sortByDate(EMP *em, int rec)
{
    int i, j;
    for (i = 0; i < rec - 1; i++)
    {
        for (j = i + 1; j < rec; j++)
        {
            if (((em + j)->join_date.y) < ((em + i)->join_date.y))
                swapemp(em + j, em + i);
            if (((em + j)->join_date.y) == ((em + i)->join_date.y))
            {
                if (((em + j)->join_date.m) < ((em + i)->join_date.m))
                    swapemp(em + j, em + i);
            }
            if (((em + j)->join_date.y) == ((em + i)->join_date.y))
            {
                if (((em + j)->join_date.m) == ((em + i)->join_date.m))
                {
                    if (((em + j)->join_date.d) < ((em + i)->join_date.d))
                        swapemp(em + j, em + i);
                }
            }
        }
    }
}

void header(int c, int r)
{
    system("cls");
    gotoxy(c, r);
    printf("Emp code");
    gotoxy(c += 10, r);
    printf("Name");
    gotoxy(c += 16, r);
    printf("D.O.J");
    gotoxy(c += 18, r);
    printf("Salary");
}

void displayRecord(EMP emp, int c, int r)
{
    for (int i = 0; i < 5; i++)
        printf("%d", emp.empcode[i]);
    gotoxy(c + 10, r);
    printf("%s", emp.empname);
    gotoxy(c + 26, r);
    printf("%d/%d/%d", emp.join_date.d, emp.join_date.m, emp.join_date.y);
    gotoxy(c + 44, r);
    printf("%.2f", emp.salary);
}

void displayByDate(FILE *fp)
{
    int rec = 0, i;
    rewind(fp);
    fseek(fp, 0, SEEK_END);
    rec = ftell(fp) / sizeof(emp);

    EMP *em;
    em = (EMP *)malloc(rec * sizeof(emp));

    rewind(fp);
    i = 0;
    while (fread(&emp, sizeof(emp), 1, fp) == 1)
    {
        (em + i)->join_date = emp.join_date;
        i++;
    }

    sortByDate(em, rec);

    rewind(fp);
    int r = 5, c = 1;
    header(c, r);

    for (int k = 0; k < rec; k++)
    {
        r++;
        rewind(fp);
        while (fread(&emp, sizeof(emp), 1, fp) == 1)
        {
            c = 1;
            gotoxy(c, r);
            if (((emp.join_date.y) == ((em + k)->join_date.y)) && ((emp.join_date.m) == ((em + k)->join_date.m)) && ((emp.join_date.y) == ((em + k)->join_date.y)))
                displayRecord(emp, c, r);
        }
    }
    free(em);
}

void displayNormal(FILE *fp)
{
    rewind(fp);
    int r = 5, c = 1;
    header(c, r);
    while (fread(&emp, sizeof(emp), 1, fp) == 1)
    {
        r++;
        c = 1;
        gotoxy(c, r);
        displayRecord(emp, c, r);
    }
}
void main()
{
    FILE *fp;
    int ch;
    int rec;
    char empcode[6];
    int i, j;
    fp = fopen("EmpRecord.txt", "rb+");
    if (fp == NULL)
    {
        printf("\nError in opening file\n");
        exit(1);
    }

    do
    {

        printf("\n\n1) Add Records\n2) Display Records in order of joining date \n3) Display\n4) Exit\n");
        scanf("%d", &ch);
        fflush(stdin);
        switch (ch)
        {
        case 1:
            addRecords(fp, empcode);
            break;
        case 2:
            displayByDate(fp);
            break;
        case 3:
            displayNormal(fp);
            break;
        case 4:
            fclose(fp);
            free(em);
        }
    } while (ch != 4);
    fclose(fp);
}
