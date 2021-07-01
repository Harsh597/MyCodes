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
int valid_not(char[]);
int top = -1;
int stack[MAX];
void main()
{
    char formula[MAX];
    int formula_length;
    printf("\t\tProgram to check for the well formed formula\n");
    printf("\t\t***********Instructions**************\n");
    printf("\t\t1)OR operator = ||\n");
    printf("\t\t2)AND operator = &&\n");
    printf("\t\t3)All other operators are same \n");
    printf("\t\tEnter the formula\n\t\t");
    fflush(stdin);
    gets(formula);
    fflush(stdin);
    formula_length = strlen(formula);
    to_upper(formula, formula_length);          //convert formula into uppercase
    symbol_conversion(formula, formula_length); // converting symbols to do operations on them easily('||'->'+' , '&&'->'*' , '->' ->'-' '<=>'=>'=' )
    if (formula_length == 0)
        printf("\n\t\tINVALID ");
    else if (formula_length == 1)
    {
        if (isalpha(formula))
            printf("\n\t\tVALID ");
        else //if only single char and it is not alphabet then it is invalid
        {
            puts("\n\t\tINVALID");
            exit(1);
        }
    }
    else if (valid_not(formula) == 1) // checking if there is valid  use of not operator or not if it is then go inside
    {
        {
            if (check_brackets(formula) == 1) //if brackets exists
            {
                if (wff_brackets(formula, formula_length) != 1) // if brackets are not used properly
                {
                    puts("\n\t\tINVALID");
                }
                else // if no probelm in brackets
                    puts("\n\t\tVALID   ");
            }
            else //if brackets not exist
            {
                if (wff_check(formula, formula_length) != 1)
                    puts("\n\t\tINVALID ");
                else
                    puts("\n\t\tVALID ");

                //printf("\nINvalid");
            }
        }
    }
    else //if not operator or brackets is not used properly
    {
        printf("\n\t\tINVALID");
    }
    getch();
}

int valid_not(char formula[]) // function to check if not operator is used properly or not
{
    for (int i = 1; i < strlen(formula) - 1; i++)
    {
        if (formula[i] == '~' && ((isalpha(formula[i - 1]) || formula[i - 1] == '(' || formula[i - 1] == ')' && (isalpha(formula[i + 1]) || formula[i - 1] == '(' || formula[i - 1] == ')'))))
            return 0;
    }
    return 1;
}
int wff_brackets(char formula[], int length)
{
    int i, j, k;
    int cls_bkt_index;
    char within_brackets[MAX] = "";
    char without_brackets[MAX] = "";
    if (check_brackets(formula) == 1)
    {
        if (balance_brackets(formula)) //if brackets are balanced
        {
            if (strstr(formula, "()") != NULL) // if empty brackets exits
            {
                // puts("\n\t\tINVALID");
                return 0;
            }

            for (i = 0; i < length; i++)
            {
                if (formula[i] == '(')
                {
                    cls_bkt_index = closing_brackets(formula, i);
                    for (k = 0, j = i + 1; j < cls_bkt_index; j++)
                    {
                        within_brackets[k++] = formula[j];
                    }
                    within_brackets[k] = '\0';
                    wff_brackets(within_brackets, strlen(within_brackets)); // recursively calling and passing within brackets content
                    if (formula[j + 1] == '+' || formula[j + 1] == '-' || formula[j + 1] == '*' || formula[j + 1] == '=')
                        j += 2;
                    else
                        j++;

                    for (i = 0; i < strlen(formula); i++)
                    {

                        without_brackets[i] = formula[j++];
                    }
                    without_brackets[i] = '\0';

                    if (strlen(without_brackets) >= 1)
                        wff_brackets(without_brackets, strlen(without_brackets)); // passing without brackets content
                }
            }
        }
        else //if unbalanced brackets
        {
            //  printf("\n\t\tINVALID");
            return 0;
        }
    }
    else if (wff_check(formula, length) == 0) // if formula is not well formed
    {
        printf("\n\t\tINVALID");
        getch();
        exit(1);
    }

    return 1; // if not probelm exists
}
void push(char item) // function to perform push in stack
{
    if (top == (MAX - 1))
    {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack[top] = item;
} /*End of push()*/
char pop() // function to perform pop in stack
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
}
void symbol_conversion(char formula[], int len) // function to convert logical operators into convenient operators
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
void replaceSubstring(char string[], char sub[], char new_str[]) // function to replace substring inside the string
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
    if (length == 0) // if formula contains nothing
    {
        // puts("\t\tINVALID");
        return 0;
    }
    for (i = 0; i < length; i++)
    {
        if (formula[i] == '+' || formula[i] == '*' || formula[i] == '-' || formula[i] == '=') //checking if or,and,implies and double implies operator are used properly or not
        {

            if (!(isalpha(formula[i - 1]) && isalpha(formula[i + 1]) || formula[i + 1] == '~'))
            {
                // puts("\t\tINVALID");
                return 0;
            }
        }
        else if (formula[i] == '~') //checking if not operator is used properly or not
        {
            if ((!isalpha(formula[i + 1]) && !formula[i + 1] == '~' && !isalpha(formula[i - 1])) || i >= length)
            {
                // puts("\t\tINVALID");
                return 0;
            }
        }
        else if (isalpha(formula[i + 1]) || formula[i + 1] == '~') // if two consecutive atoms are used
        {
            //  puts("\t\tINVALID");
            return 0;
        }
    }

    return 1;
}
int match(char a, char b) //function to check if brackets are matched or not
{

    if (a == '(' && b == ')')
        return 1;
    return 0;
} /*End of match()*/
int balance_brackets(char exp[]) // function to check if brackets are balanced or not
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
                return 0;
            }
            else
            {
                temp = pop();
                if (!match(temp, exp[i]))
                {
                    return 0;
                }
            }
    }
    if (top == -1) /*stack empty*/
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int check_brackets(char str[]) //function to check if brackets exits or not
{
    if ((strstr(str, "(") != NULL || strstr(str, ")") != NULL))
        return 1;
    else
        return 0;
}
void to_upper(char *str, int len) // function to convert formula into uppercase
{
    int j = 0;
    while (j < len)
    {

        *str = toupper(*str);
        j++;
        str++;
    }
}