#include <stdio.h>
#include <stdlib.h>

/*
    string literal

            [0]                 [1]                 [2]
    birds   char const *const   char const *const   char const *const
            ↓                   ↓                   ↓
            "raven"             "magpie"            "jay"
 */

char const *const birds[3] = {
    "raven",
    "magpie",
    "jay",
};

char const *const pronouns[3] = {
    "we",
    "you",
    "they",
};

char const *const ordinal[3] = {
    "first",
    "second",
    "third",
};

int main(void)
{
    for (unsigned i = 0; i < 3; ++i)
    {
        printf("Corvid %u is the %s at %p\n", i, birds[i], &birds[i]);
    }

    for (unsigned i = 0; i < 3; ++i)
    {
        printf("%s plural pronoun is \"%s\"\n", ordinal[i], pronouns[i]);
    }

    return EXIT_SUCCESS;
}