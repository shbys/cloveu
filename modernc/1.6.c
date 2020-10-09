#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Array parameters behave as if the array is passed by reference.
 * Don't use the `sizeof` operator on array parameters to functions.
 * A special kind of array, even has literals: strings
 * A string is a 0-terminated array of `char`.
 * Array can't be assigned to.
 * 
 */

#define ARRAY_SWAP_LENGTH 2

void swap_double(double a[static ARRAY_SWAP_LENGTH])
{
    double temp = a[0];
    a[0] = a[1];
    a[1] = temp;
}

/*
 * Below are all equivalent declarations.
 * They are arrays of `char`.
 * They are strings.
 */

char const jay0[] = "jay";
char const jay1[] = {"jay"};
char const jay2[] = {
    'j',
    'a',
    'y',
    0,
};
char const jay3[4] = {
    'j',
    'a',
    'y',
};

/*
 * Below are not strings.
 * They are arrays of `char` but not 0-terminated.
 */

char const jay4[3] = {'j', 'a', 'y'};
char const jay5[3] = "jay";

/*
 *          [0]             [1]             [2]             [3]
 *  jay0    char 'j'        char 'a'        char 'y'        char '\0'
 *  jay1    char 'j'        char 'a'        char 'y'        char '\0'
 *  jay2    char 'j'        char 'a'        char 'y'        char '\0'
 *  jay3    char 'j'        char 'a'        char 'y'        char '\0'
 *  jay4    char 'j'        char 'a'        char 'y'        
 *  jay5    char 'j'        char 'a'        char 'y'        
 */

int main(void)
{
    double a[ARRAY_SWAP_LENGTH] = {
        1.0,
        2.0,
    };
    printf("Before swap a[0] = %g, a[1] = %g\n", a[0], a[1]);
    swap_double(a);
    printf("After swap a[0] = %g, a[1] = %g\n", a[0], a[1]);

    printf("jay0=%s\tlength=%zu\n", jay0, strlen(jay0));
    printf("jay1=%s\tlength=%zu\n", jay1, strlen(jay1));
    printf("jay2=%s\tlength=%zu\n", jay2, strlen(jay2));
    printf("jay3=%s\tlength=%zu\n", jay3, strlen(jay3));

    // below will give a waning:
    // %s directive argument is not a nul-terminated string
    // strlen argument missing terminating nul-[-Wstringop-overflow=]
    printf("jay4=%s\tlength=%zu\n", jay4, strlen(jay4));
    printf("jay5=%s\tlength=%zu\n", jay5, strlen(jay5));

    // below convert the array of `char` to string
    int len_of_jay4 = sizeof(jay4) / sizeof(jay4[0]);
    int len_of_jay5 = sizeof(jay5) / sizeof(jay5[0]);
    char jay4_string[len_of_jay4 + 1];
    char jay5_string[len_of_jay5 + 1];

    memcpy(jay4_string, jay4, len_of_jay4);
    jay4_string[len_of_jay4] = 0;

    memcpy(jay5_string, jay5, len_of_jay5);
    jay5_string[len_of_jay5] = 0;

    printf("jay4_string=%s\tlength=%zu\n", jay4_string, strlen(jay4_string));
    printf("jay5_string=%s\tlength=%zu\n", jay5_string, strlen(jay5_string));

    return EXIT_SUCCESS;
}