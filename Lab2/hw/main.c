#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;


int DayOfYear(int day, int month, int year)
{
    int result;
    int j;
    int monthsOfTheYear[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    result = 0;
    j = 0;

    while (month > j + 1)
    {
        result += monthsOfTheYear[j];
        j++ ;
    }

    if (month == j + 1)
    {
        result += day;
    }

    if (year % 4 == 0 && month > 2)
    {
        result ++;
    }

    return result;
}

int main()
{
    char string[100];
    int i = 0;
    Date date;
    int result = 0;

    printf("Enter a list of dates: ");
    scanf("%s", string);

    scanf("%d-%d-%d", &date.day, &date.month, &date.year);

    while(string[i] != '\0')
    {
        result = DayOfYear(date.day, date.month, date.year);
        printf("%d ", result);

        scanf("%d-%d-%d", &date.day, &date.month, &date.year);

        i++;
    }

    return 0;
}