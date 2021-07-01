	#include<stdio.h>
	#include<conio.h>
	#include<stdlib.h>
	int main()
{
FILE *fp;
char file[100];
int i = 1;
char ch;
printf("Enter the file name\n");
gets(file);
fp = fopen(file, "r+");
if (fp == NULL)
{
	puts("\nFile can't be open");
	exit(1);
}
/*Line no. before first line*/
printf("%d. ", i);
i++;
do
{
	ch = fgetc(fp);
	if (ch == '.')
	{
		printf("%c", ch);
		if (fgetc(fp) == EOF)
			continue;

		/*Printing the line number*/
		printf("\n%d. ", i);

		i++;
		continue;
	}
	printf("%c", ch);
} while (ch != EOF);
fclose(fp);
_getch();
return 0;
	}