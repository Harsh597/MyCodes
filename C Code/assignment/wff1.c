#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50
int wff_brackets(char[], int);
void push(char);
char pop(void);
int closing_brackets(char[], int);
void symbol_conversion(char[], int);
void replaceSubstring(char[], char[], char[]);
int wff_check(char[], int);
int match(char, char);
int balance_brackets(char[]);
int check_brackets(char[]);
void to_upper(char *, int);
int top = -1;
int stack[MAX];
void main()
{
    char formula[50];
    int formula_length;
    printf("\t\tProgram to check for the well formed formula\n");
    printf("***********Instructions**************\n");
    printf("1)OR operator = ||\n");
    printf("2)AND operator = &&\n");
    printf("3)All other operators are same \n");
    printf("\tEnter the formula\n\t");
    fflush(stdin);
    //get_formula(formula);
    gets(formula);
    fflush(stdin);

    formula_length = strlen(formula);
    to_upper(formula, formula_length); //convert it to uppercase
    symbol_conversion(formula, formula_length);
    //puts(formula);

    if (formula_length == 0)
        printf("\n\tNO INPUT ");
    else if (formula_length == 1)
    {
        if (isalpha(formula))
            printf("\n\tVALID ");
        else
        {
            //puts("INVALID");
            printf("\n\tInvalid because no alphabet ");
            exit(1);
        }
    }
    else
    {
        if (check_brackets(formula) == 1) //if brackets exists
        {
            if (wff_brackets(formula, formula_length) != 1)
                puts("\n\tINVALID inside check brackets  ");
            else
                puts("\n\tVALID   ");
        }
        else //if brackets not exist
        {
            if (wff_check(formula, formula_length) != 1)
                puts("\n\tINVALID ");
            else
                puts("\n\tVALID ");

            //printf("\nINvalid");
        }
    }
    getch();
}
void get_formula(char formula[])
{
    int i = 0;
    char ch;
    do
    {
        ch = getch();
        if (ch >= 97 && ch <= 122)
        {
            ch -= 32;
        }

        formula[i++] = ch;

        printf("%c", ch);
    } while ((int)ch != 10 || (int)ch != 32);

    formula[i] = '\0';
    puts(formula);
}
int wff_brackets(char formula[], int length)
{
    int i, j, k;
    int cls_bkt_index;
    char within_brackets[50] = "";
    char without_brackets[50] = "";
    printf("\nInside wff_brackets %s", formula);
    if (check_brackets(formula) == 1)
    {
        if (balance_brackets(formula)) //if brackets are balanced
        {

            printf("\n brackets are balanced\n %s", formula);
            if (strstr(formula, "()") != NULL)
            {
                puts("INVALID");
                printf("\ninvalid due to empty brakets");
                return 0;

                // exit(1);
            }

            for (i = 0; i < length; i++)
            {
                if (formula[i] == '(')
                {
                    cls_bkt_index = closing_brackets(formula, i);
                    printf("\nopening bracket index is %d and closing bracket index is %d\n", i, cls_bkt_index);
                    for (k = 0, j = i + 1; j < cls_bkt_index; j++)
                    {
                        within_brackets[k++] = formula[j];
                    }
                    within_brackets[k] = '\0';
                    printf("within_brackets %s \n", within_brackets);
                    wff_brackets(within_brackets, strlen(within_brackets));
                    j += 2;

                    for (i = 0; i < strlen(formula); i++)
                    {

                        without_brackets[i] = formula[j++];
                    }
                    without_brackets[i] = '\0';

                    printf("\nwithoutbrackets %s \n", without_brackets);
                    printf("\nlength of withoutbrackets is %d", strlen(without_brackets));
                    if (strlen(without_brackets) >= 1)
                        wff_brackets(without_brackets, strlen(without_brackets));
                }
            }
        }
        else
        {
            printf("\n\t invalid due to unbalanced brackets\n");

            return 0;
            //puts("\nINVALID");
            //exit(1);
        }
    }
    else if (wff_check(formula, length) == 0)
    {
        //return 0;
        //puts("\n\tINVALID  ");
        //return 0;
        printf("\nInvalid due to 0 length in wff_check\n");
        getch();
        exit(1);
    }

    return 1;
    // puts("\nVALID");
}
void push(char item)
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
} /*End of push()*/
char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return (stack[top--]);
} /*End of pop()*/
int closing_brackets(char formula[], int open_index) //returning closing index of corresponding open bracket
{
    int cls_bkt_index, i, j;
    top = -1;
    // int stack[MAX];
    for (i = open_index; i < strlen(formula); i++)
    {
        if (formula[i] == '(')
            push(formula[i]);
        else if (formula[i] == ')')
        {
            pop();
            if (top == -1)
                return i;
        }
    }
    //  return -1;
}
void symbol_conversion(char formula[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if (formula[i] == '|' && formula[i + 1] == '|')
        {
            replaceSubstring(formula, "||", "+");
        }
        else if (formula[i] == '&' && formula[i + 1] == '&')
        {
            replaceSubstring(formula, "&&", "*");
        }
        else if (formula[i] == '-' && formula[i + 1] == '>')
        {
            replaceSubstring(formula, "->", "-");
        }
        else if (formula[i] == '<' && formula[i + 1] == '=' && formula[i + 2] == '>')
        {
            replaceSubstring(formula, "<=>", "=");
        }
    }
}
void replaceSubstring(char string[], char sub[], char new_str[])
{
    int stringLen, subLen, newLen;
    int i = 0, j, k;
    int flag = 0, start, end;
    stringLen = strlen(string);
    subLen = strlen(sub);
    newLen = strlen(new_str);

    for (i = 0; i < stringLen; i++)
    {
        flag = 0;
        start = i;
        for (j = 0; string[i] == sub[j]; j++, i++)
            if (j == subLen - 1)
                flag = 1;
        end = i;
        if (flag == 0)
            i -= j;
        else
        {
            for (j = start; j < end; j++)
            {
                for (k = start; k < stringLen; k++)
                    string[k] = string[k + 1];
                stringLen--;
                i--;
            }

            for (j = start; j < start + newLen; j++)
            {
                for (k = stringLen; k >= j; k--)
                    string[k + 1] = string[k];
                string[j] = new_str[j - start];
                stringLen++;
                i++;
            }
        }
    }
}
int wff_check(char formula[], int length)
{
    int i;
    char *p;
    // printf("\ninside wff_check %s\n", formula);
    if (length == 0)
    {
        // puts("INVALID");
        //     printf("\ninvalid becuase 0 length formula in wff check\n");
        return 0;
        //exit(1);
    }
    for (i = 0; i < length; i++)
    {
        if (formula[i] == '+' || formula[i] == '*' || formula[i] == '-' || formula[i] == '=') //if or,and,implis and double implies operator
        {

            if (!(isalpha(formula[i - 1]) && isalpha(formula[i + 1]) || formula[i + 1] == '~'))
            {
                // puts("INVALID");
                //    puts("Invalid because no alphabet before and after symbols\n");
                // exit(1);
                return 0;
            }
        }
        else if (formula[i] == '~') //not operator
        {
            if ((!isalpha(formula[i + 1]) && !formula[i + 1] == '~') || i >= length)
            {
                //puts("INVALID");
                puts("invalid because no alphabet after not operator");
                return 0;
                //exit(1);
            }
        }
        else if (isalpha(formula[i + 1]) || formula[i + 1] == '~')
        {
            // printf("\nInvalid due to two consecutive alphabets");
            return 0;
        }
    }

    return 1;
}
int match(char a, char b)
{

    if (a == '(' && b == ')')
        return 1;
    return 0;
} /*End of match()*/
int balance_brackets(char exp[])
{
    int i;
    char temp;
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        if (exp[i] == ')')
            if (top == -1) /*stack empty*/
            {
                // printf("Right parentheses are more than left parentheses\n");
                return 0;
            }
            else
            {
                temp = pop();
                if (!match(temp, exp[i]))
                {
                    //  printf("Mismatched parentheses are : ");
                    //printf("%c and %c\n", temp, exp[i]);
                    return 0;
                }
            }
    }
    if (top == -1) /*stack empty*/
    {
        //printf("Balanced Parentheses\n");
        return 1;
    }
    else
    {
        //printf("Left parentheses more than right parentheses\n");
        return 0;
    }
}
int check_brackets(char str[])
{
    //printf("\n inside check brackets string is %s\n", str);
    if ((strstr(str, "(") != NULL || strstr(str, ")") != NULL))
        return 1;
    else
        return 0;
}
void to_upper(char *str, int len)
{

    int j = 0;
    while (j < len)
    {

        *str = toupper(*str);
        j++;
        str++;
    }
}