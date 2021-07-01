#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <alloca.h>
void sort_names(int);
struct student
{
    char name[50];
    int age;
};
struct student stu;

void main()
{
    FILE *fp1, *fp2;
    char ch;
    int record = 0;

    fp1 = fopen("C:\\Users\\harsh\\OneDrive\\Documents\\C Code\\MCA PROGRAMS\\student_record.txt", "rb");
    // fp2 = fopen("C:\\Users\\harsh\\OneDrive\\Documents\\C Code\\MCA PROGRAMS\\temp_student_record.txt", "wb");

    if (fp1 == NULL)
    {
        printf("\nError in opening student record file\n");
        exit(1);
    }
    while (fread(&stu, sizeof(stu), 1, fp1) == 1)
        record++;

    sort_names(record);
    fclose(fp1);
}
void sort_names(int record)
{
    char *name[record];
    char *temp, *p;

    int i, j, len;
    FILE *fp1;
    fp1 = fopen("C:\\Users\\harsh\\OneDrive\\Documents\\C Code\\MCA PROGRAMS\\student_record.txt", "rb");

    if (fp1 == NULL)
    {
        printf("\nError in opening student record file\n");
        exit(1);
    }
    i = 0;
    while (fread(&stu, sizeof(stu), 1, fp1) == 1)
    {
        len = strlen(stu.name);
        p = (char *)malloc(len + 1);
        strcpy(p, stu.name);
        name[i] = p;
        i++;
    }

    for (i = 0; i < record - 1; i++)
    {
        for (j = 0; j < record - i - 1; j++)
        {
            if (strcmp(name[j], name[j + 1]) > 0)
            {
                temp = name[j];
                name[j] = name[j + 1];
                name[j + 1] = temp;
            }
        }
    }
   
    for (i = 0; i < record; i++)
    {
        puts(name[i]);
    }

    fclose(fp1);
}