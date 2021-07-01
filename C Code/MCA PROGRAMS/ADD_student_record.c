#include<stdio.h>
#include<stdlib.h>
struct student
{
    char name[50];
    int age; 
};
void main()
{
    FILE *fp;
    char ch;
    struct student stu;
    fp=fopen("student_record.txt","a");
    if(fp==NULL)
    {
        printf("\nError in opening student record file\n");
        exit(1);
    }
    do
    {
        printf("\nEnter the name of the student\n");
        fflush(stdin);

        gets(stu.name);
        printf("\nEnter the age of the student\n");
        fflush(stdin);

        scanf("%d",&stu.age);

        fwrite(&stu,sizeof(stu),1,fp);
        printf("\nWant to add more record? y/n\n");
        fflush(stdin);
        ch=getche();
    } while (ch=='Y' ||ch=='y');
    fclose(fp);
    

}