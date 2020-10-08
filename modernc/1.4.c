#include <stdio.h>
#include <stdlib.h>

enum corvid
{
    magpie,
    raven,
    jay,
    corvid_num,
};

/*
    string literal

            [magpie]            [raven]             [jay]
    birds   char const *const   char const *const   char const *const
            ↓                   ↓                   ↓
            "magpie"            "raven"             "jay"
 */

char const *const birds[corvid_num] = {
    [magpie] = "magpie",
    [raven] = "raven",
    [jay] = "jay",
};

int main(void)
{
    for (unsigned i = 0; i < corvid_num; ++i)
    {
        printf("Corvid %u is the %s\n", i, birds[i]);
    }

    return EXIT_SUCCESS;
}