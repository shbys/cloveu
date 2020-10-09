#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Pointers do not directly contain the infomration.
 * Pointers are opaque objects.
 * Pointers are valid, null, or indeterminate.
 * Initialization or assignment with 0 makes a pointer null, and the address of it is (nil).
 * In logical expressions, pointers evaluate to false if they are null.
 * Always initialize pointers.
*/

// null pointer
char const *const p2nothing = 0;

/**
 * This pointer is indeterminate.
 * Because it is uninitialize, its state is indeterminate.
 * Any use of it would do you harm
 * and leave your program in an undefined state.
 * If we can't enuse a pointer is valid,
 * we must at least ensure that it is set to null.
*/
char const *const p2invalid;

// Below pointer is not null, it points to an empty string.
char const *const p2empty = "";

/**
 * p2string         char const *const
 *                  ↓
 *                  "some text"
*/

char const *const p2string = "some text";

/**
 *                  [0]             [1]             [2]
 * jay0             char 'j'        char 'a'        char 'y'
*/

char jay0[] = "jay";

int main(void)
{
    printf("empty pointer content = %s, the address is %p\n", p2empty, p2empty);

    if (!p2nothing)
    {
        printf("null pointer 0 is null, the address is %p\n", p2nothing);
    }

    return EXIT_SUCCESS;
}