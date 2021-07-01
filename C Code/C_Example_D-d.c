#include <stdio.h> // Implement the following procedure to generate prime
#include <conio.h> //    numbers from 1 to 100 into a program. This procedure is
void main()        //  called sieve of Eratosthenes.
{
    int a[100], k, step;
    printf("\nProgram of Sieve of Eratosthenes\n");
    for (int i = 0; i < 99; i++) //step 1 Fill an array num[100] with numbers from 1 to 100
        a[i] = i + 1;

    //  step 2 Starting with the second entry in the array, set all its
    //multiples to zero.
    //     step 3 Proceed to the next non-zero element and set all its
    // multiples to zero.
    for (int i = 1; i < 99; i++)
    {
        if (a[i] != 0) //step 4 Repeat step 3 till you have set up the multiples of
        {              //all the non-zero elements to zero
            k = 2 * a[i] - 1;
            step = a[i];
            for (int j = k; j < 99; j = j + step)
            {
                if (a[j] % a[i] == 0)
                    a[j] = 0;
            }
        }
    }
    // step 5 At the conclusion of step 4, all the non-zero entries
    // left in the array would be prime numbers, so print
    // out these numbers.

    for (int i = 0; i < 99; i++)
    {
        if (a[i] != 0)
            printf("\n %d", a[i]);
    }
}