#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * struct itself is not a type.
 * struct + indentifier is a new type like `struct Today` is a new type.
 * a typedef only creates an alias for a type, but never a new type: typedef T T-Alias
 * typedef provides new name for an existing type.
 * 
*/

typedef struct TodayStruct
{
    int year;
    int mon;
    int day;
    int hour;
    int min;
    int sec;
} Today;

typedef Today Today1;

typedef struct Timespec
{
    time_t tv_sec;
    long tv_nsec;
} Timespec;

typedef struct Stardate
{
    Today date;
    Timespec precision;
} Stardate;

typedef struct Person
{
    char *name;
    Stardate bdate;
} Person;

int main(void)
{
    Today1 td1 =
        {
            .year = 2020,
            .mon = 10,
            .day = 9,
            .hour = 15,
            .min = 23,
            .sec = 59,
        };

    printf("today1.year = %d\n", td1.year);

    Person p =
        {
            .name = "God King",
            .bdate =
                {
                    .date =
                        {
                            .year = 2020,
                            .mon = 10,
                            .day = 9,
                            .hour = 15,
                            .min = 23,
                            .sec = 59,
                        },
                    .precision =
                        {
                            .tv_nsec = 1000000,
                            .tv_sec = 10000000,
                        },
                },
        };
    printf("p.name = %s \n", p.name);
}