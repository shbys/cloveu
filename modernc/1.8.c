#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BirdStruct
{
    char const *jay;
    char const *magpie;
    char const *raven;
    char const *chough;
};

/**
 * struct BirdStruct is a new type we have declared.
 * 
 *  a_bird ----------------------------------------------------
 *          struct BirdStruct
 *          .jay                    .magpie                 .raven                  .chough
 *          ↓                       ↓                       ↓                       ↓
 *          "jay"                   "magpie"                "raven"                 "chough"
*/

struct BirdStruct const a_bird = {
    .jay = "jay",
    .magpie = "magpie",
    .raven = "raven",
    .chough = "chough",
};

typedef struct CatStruct
{
    char const *jay;
    char const *magpie;
    char const *raven;
} Cat;

Cat const a_cat = {
    .jay = "jay",
    .magpie = "magpie",
    .raven = "raven",
};

/*-----------------------------------------------------------------------------------------------*/

/**
 * Type MyDateTime to represent a calendar time:
 * year, month, day, hour, minute, second
*/
typedef int MyDateTime[6];
MyDateTime const mdt = {
    2020,
    10,
    9,
    15,
    23,
    56,
};

#define DAYS_BEFORE                                  \
    (int const[12])                                  \
    {                                                \
        [0] = 0, [1] = 31, [2] = 59, [3] = 90,       \
        [4] = 120, [5] = 151, [6] = 181, [7] = 212,  \
        [8] = 243, [9] = 273, [10] = 303, [11] = 334 \
    }

/**
 * Type MyDateTimeStruct to represent a calendar time:
 * year, month, day, hour, minute, second
*/
typedef struct MyDateTimeStruct
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} MyDateTimeStruct;

/**
 *                                      .year       .month      .day    .hour       .minute     .second
 * mdts:    struct MyDateTimeStruct     int 2020    int 10      int 9   int 15      int 23      int 56
*/

MyDateTimeStruct const mdts = {
    .year = 2020,
    .month = 10,
    .day = 9,
    .hour = 15,
    .minute = 23,
    .second = 56,
};

/*-----------------------------------------------------------------------------------------------*/

int main(void)
{
    printf("Cat is [jay] = %s\t[magpie] = %s\t[raven] = %s\n",
           a_cat.jay, a_cat.magpie, a_cat.raven);
    printf("struct BirdStruct is [jay] = %s\t[magpie] = %s\t[raven] = %s\t[chough] = %s\n",
           a_bird.jay, a_bird.magpie, a_bird.raven, a_bird.chough);

    printf("MyDateTime value =\t\t\t%d-%d-%d %d:%d:%d\n",
           mdt[0], mdt[1], mdt[2], mdt[3], mdt[4], mdt[5]);
    printf("MyDateTimeStruct value =\t\t%d-%d-%d %d:%d:%d\ndays_before =\t\t\t\t%d\n",
           mdts.year, mdts.month, mdts.day,
           mdts.hour, mdts.minute, mdts.second,
           DAYS_BEFORE[mdts.month]);

    return EXIT_SUCCESS;
}