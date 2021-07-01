#include <stdio.h>
struct Date_Of_Join
{
    unsigned d : 5;
    unsigned m : 4;
    unsigned y : 12;
};
typedef struct Date_Of_Join DOJ;
typedef struct Employee
{
    int empcode;
    DOJ date;
} EMP;

void getdata(EMP e[])
{
    int year, month, dt;

    printf("\nEnter the details of 3 employees\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\n%d Employee\n", i + 1);

        printf("Enter empcode\t");
        scanf("%d", &e[i].empcode);
        printf("Enter the year of joining\t");
        scanf("%d", &year);
        e[i].date.y = year;
        printf("Enter the month of joining\t");
        scanf("%d", &month);
        e[i].date.m = month;
        printf("Enter the date of joining\t");
        scanf("%d", &dt);
        e[i].date.d = dt;
    }
}

void displaydata(EMP e[])
{
    printf("\n the details of 3 employees\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\n%d Employee\n", i + 1);
        printf("\nempcode\t");
        printf("%d", e[i].empcode);
        printf("\nyear of joining\t");
        printf("%d", e[i].date.y);
        printf("\nmonth of joining\t");
        printf("%d", e[i].date.m);
        printf("\ndate of joining\t");
        printf("%d", e[i].date.d);
        printf("\n\nBytes occupied by e = %d\n", sizeof(e[i]));
    }
}
void swap(EMP *e1, EMP *e2)
{
    EMP temp;
    temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}
void sortByDate(EMP e[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (e[j].date.y > e[j + 1].date.y)
            {
                swap(&e[j], &e[j + 1]);
            }
            if ((e[j].date.y == e[j + 1].date.y) && (e[j].date.m > e[j + 1].date.m))
            {
                swap(&e[j], &e[j + 1]);
            }
            if ((e[j].date.y == e[j + 1].date.y) && (e[j].date.m == e[j + 1].date.m) && (e[j].date.d > e[j + 1].date.d))
            {
                swap(&e[j], &e[j + 1]);
            }
        }
    }
}
int main()
{
    EMP e[3];
    getdata(e);
    sortByDate(e, 3);
    displaydata(e);
    return 0;
}