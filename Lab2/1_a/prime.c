// Generate all the prime numbers smaller than a given natural number n.

#include <stdio.h>
#include <stdbool.h>


int checkIfPrime(int a)
{
    // given a positive integer a the function checks if it is prime or not
    // if a is prime it will return 1, otherwise it will return 0

    bool flag = 1;

    for (int i = 2; i <= a/2; ++i)
    {
        if(a % i == 0)
        {
            flag = 0;
            break;
        }
    }

    return flag;
}


int main()
{

    int n;
    int counter = 0;
    char string[20];

    printf("Give a number: ");
    scanf("%d", &n);

    for(int i = 2; i < n; i++)
    {
        if(checkIfPrime(i) == 1)
        {
             printf("%d ", i);
        }
    }

}