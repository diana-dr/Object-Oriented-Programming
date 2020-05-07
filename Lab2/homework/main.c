#include <stdio.h>
#include <string.h>


int findDayFromString(int position, char string[100])
{
    int day = 0;

    day = string[position] - '0';
    day = day * 10;
    day += string[position + 1] - '0';

    return day;
}

int findMonthFromString(int position, char string[100])
{
    int month = 0;

    month = string[position] - '0';
    month = month * 10;
    month += string[position + 1] - '0';

    return month;
}

int findYearFromString(int position, char string[100])
{
    int year = 0;

    year = string[position] - '0';
    year = year * 10;
    year += string[position + 1] - '0';
    year = year * 100;
    year += string[position + 2] - '0';
    year = year * 1000;
    year += string[position + 3] - '0';

    return year;
}

int DayOfYearByDate(int day, int month, int year)
{
    int result;
    int j;
    int monthsOfTheYear[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    result = 0;
    j = 0;

    while (month > j + 1)
    {
        result += monthsOfTheYear[j];
        j++;
    }

    if (month == j + 1)
    {
        result += day;
    }

    if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2)
    {
        result++;
    }

    return result;
}

int main()
{
    int result;
    int lenghtOfString;
    int position = 0;
    int day = 0;
    int month = 0;
    int year = 0;
    char inputString[100];

    printf("Enter a list of dates: ");

    scanf("%[^'\n']s", &inputString);

    lenghtOfString = strlen(inputString);

    while (position < lenghtOfString)
    {
        day = findDayFromString(position, inputString);
        month = findMonthFromString(position + 3, inputString);
        year = findYearFromString(position + 6, inputString);

        result = DayOfYearByDate(day, month, year);

        printf("%d ", result);

        position += 11;
    }

    return 0;
}
