// a. Read a sequence of natural numbers (sequence ended by 0) and determine the number of 0
// digits of the product of the read numbers.

#include <stdio.h>


int main()
{
    int seq[50];
    int vector[50];
    int p = 1;
    int i = 0;
    int k = 0;


    printf("Give a sequence of numbers, last one 0: ");
    scanf("%d", seq);


    while (seq[i] != 0)
    {
        p = p * seq[i];
        i++;
    }

    i = 0;


    while (p != 0)
    {
        vector[i] = p % 10;

        if (vector[i] == 0)
        {
            k++;
        }

        p = p / 10;
        i++;
    }

    printf("%d", k);

    return 0;
}