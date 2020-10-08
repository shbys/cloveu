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
 *   Compound literals: (T){ INIT }
 *   T is a type, in parentheses, followed by an initializer
 * 
 *   Explanation:
 *      The type T should be const-qualified.
 *      These must be space between the marco name and the () of the compound literal.
 *      Otherwise, this would be interpreted as the start of a definition of a function-like macro.
 *      A backspace character "\"" at the very end of the line can be used to continue the macro definition to the next line.
 *      There must be no ";" at the end of the macro definition.
 *      Remember, it is all just text replacement.
 */

#define CORVID_NAME /**/            \
    (char const *const[corvid_num]) \
    {                               \
        [magpie] = "magpie",        \
        [raven] = "raven",          \
        [jay] = "jay",              \
    }

int main(void)
{
    for (unsigned i = 0; i < corvid_num; ++i)
    {
        printf("Corvid %u is the %s\n", i, CORVID_NAME[i]);
    }

    return EXIT_SUCCESS;
}
