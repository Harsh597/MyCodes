#include <stdio.h>
#include <conio.h>
#include <math.h>
#define PI 3.14
#define AREA_SQUARE(x) (x*x)
#define AREA_CIRCLE(x) (x*x*PI)
#define AREA_TRIANGLE(b,h) ((b*h)/2)
#define ABS(x) (x>0?x:-1*x)
#define TO_LOWER(x) ((x+32))

void showbits(int n)
{
    int bits, temp;
    temp = n;
    int k, andmask;
    bits=log10(n)+1;
    // for (bits = 0; temp > 0; bits++)
    // {

    //     temp /= 2;
    // }

    for (int i = bits - 1; i >= 0; i--)
    {
        andmask = 1 << i;
        k = n & andmask;
        k == 0 ? printf("0") : printf("1");
    }
}
void print_array(int a[], int length)
{
    printf("\nArray after sorting\n");

    for (int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
}
void swap(int *a,int*b)
{
    *b=*a+*b-(*a=*b);
}
int partition(int a[], int beg, int end)
{
    int pivot = a[end];
    int p_index = beg - 1;
    for (int i = beg; i < end; i++)
    {
        if (a[i] < pivot)
        {
            p_index++;
            swap(&a[i], &a[p_index]);
        }
    }
    swap(&a[p_index + 1], &a[end]);
    return p_index + 1;
}
void quick_sort(int a[], int beg, int end)
{
    if (beg < end)
    {
        int p_index = partition(a, beg, end);
        quick_sort(a, beg, p_index - 1);
        quick_sort(a, p_index + 1, end);
    }
}
void myfunc()
{
    printf("\nThis function is defined in the myLibrary.c file");
}
int no_of_digits(long int num)
{
    int digits = 0;
    while (num > 0)
    {
        digits++;
        num /= 10;
    }
    return digits;
}
// int no_of_digit(long int num)
// {
//   int i = 0;
//   while (num / powf(10, i) > 1 || num / powf(10, i) < -1 )
//   {
//     i++;
//   }
// return i;
// }
int check_prime(int num)
{
    int prime = 0;
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            prime++;
            break;
        }
    }
    if (prime == 0)
        return 1; //prime
    else
        return 0; //not prime
}
long int fact(int num)
{

  long  int fact = 1;
    int i = 1;

    while (i <= num)
    {
        fact = fact * i;
        i++;
    }

    return fact;
}
// int sum_of_digit(long int n)
// {
//     int digits = no_of_digit(n);
//     int sum = 0;
//     for (int i = digits; i > 0; i--)
//     {
//         sum += n / powf(10, i - 1);
//         n %= (int)powf(10, i - 1);
//     }
//     return sum;
// }
int sum_of_digits(long int num)
{
    int rem, sum = 0;
    while (num > 0)
    {
        rem = num % 10;
        sum += rem;
        num /= 10;
    }
    return sum;
}
long int reverseno(long int num)
{
    int sum, temp = 0;

    for (int i = 1, j = no_of_digits(num) - 1; i <= no_of_digits(num); i++, j--)
    {
        sum = (num % (int)powf(10, i)) / pow(10, i - 1);
        temp += sum * powf(10, j);
    }

   // printf("\n %d ", temp);
   return temp;
}