/**
    This may look like nonsense, but really is -*- mode: C -*_
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * Compile:
 *   gcc-10 -g -std=c18 -Wall -lm -o 1.1 1.1.c
 *   c18 is the compiler program
 *   -Wall tells it to warn us about anthing that it finds unusual
 *   -o tells it to store the compiler output in a file named 1.1 or anthing you like
 *   -lm tells it to add some standard mathematical functions if necessary
 * Format Specifier:
 *   %zu
 *   %g

*/


/**
 *  The main thing that this program does.
*/
int main(void)
{
    // Declarations
    double A[5] = {
        [0] = 9.0,
        [1] = 2.9,
        [4] = 3.E+25,
        [3] = .00007};

    // Do some work
    for (size_t i = 0; i < 5; ++i)
    {
        printf("element %zu is %g, \tits square is %g\n", i, A[i], A[i] * A[i]);
    }

    return EXIT_SUCCESS;
}