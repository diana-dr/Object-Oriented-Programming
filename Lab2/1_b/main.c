// Given a vector of numbers, find the longest increasing contiguous sub sequence, such the sum
//of that any 2 consecutive elements is a prime number.

#include <stdio.h>

int getLen(const int vector[50])
{
    int i;

    i = 0;

    while (vector[i])
    {
        i++;
    }

    return i;
}

int longestSubsequence(const int vector[50])
{
    int k, j = 0, max = 0, p = 0;
    int sub[20];
    int sub1[20];
    int result[20];

    for (int i = 0; i < getLen(vector); i++)
    {

        if (vector[i] < vector[i + 1])
        {
            k = i;
            p++;

            while (vector[i + 1] < vector[i + 2])
            {
                i++;
                p++;
            }
            sub[j] = p;
            sub1[j] = k;
        }
    }

    for (int i = 0; i < getLen(sub); i++)
    {
        if (sub[i] > max)
        {
            max = sub[i];
        }
    }

    return 0;

}

int main()
{
    int vector[50];
    int i = 0;
    int nbr;


    printf("Enter a string of integers, the last one 0: ");
    scanf("%d", &nbr);

    while (nbr != 0)
    {
        vector[i] = nbr;
    }

    return 0;
}