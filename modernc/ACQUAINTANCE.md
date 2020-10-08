# Compile
```
$ gcc-10 -g -std=c18 -Wall -lm -o 1.1 1.1.c
    c18 is the compiler program
    -Wall tells it to warn us about anthing that it finds unusual
    -o tells it to store the compiler output in a file named 1.1 or anthing you like
    -lm tells it to add some standard mathematical functions if necessary
```

# Format Identifier
```
Level       Name            Other       Category        Where           printf
0           size_t                      Unsigned        <stddef.h>      "%zu" "%zx"
0           double                      Floating        Built in        "%e" "%f" "%g" "%a"
0           signed          int         Signed          Built in        "%d"
0           unsigned                    Unsigned        Built in        "%u" "%x"
0           bool            _Bool       Unsigned        <stdbool.h>     "%d" as 0 or 1
1           ptrdiff_t                   Signed          <stddef.h>      "%td"
1           char const *                String          Build in        "%s"
1           char                        Character       Built in        "%c"
1           void *                      Pointer         Built in        "%p"
2           unsigned        char        Unsigned        Built in        "%hhu" "%02hhx"
```
# Base Types
```
            Class                   Systematic name             Other name                  Rank
------------------------------------------------------------------------------------------------
                                    _Bool                       bool                        0
                                    unsigned char                                           1
                                    unsigned short                                          2
                    Unsigned        unsigned int                unsigned                    3
                                    unsigned long                                           4
                                    unsigned long long                                      5   
Integers            ---------------------------------------------------------------------------- 
                                    char                                                    1
                    [Un]signed      signed char                                             1
                                    signed short                short                       2
                    ----------------------------------------------------------------------------  
                                    signed int                  signed or int               3
                    Signed          signed long                 long                        4
                                    signed long long            long long                   5
------------------------------------------------------------------------------------------------  
                                    float
                    Real            double
                                    long double
Floating pint       ----------------------------------------------------------------------------
                                    float _Complex              float complex
                    Complex         double _Complex             double complex
                                    long double _Complex        long double complex
------------------------------------------------------------------------------------------------
```
# Some semantic arithmetic types for specialized use cases
```
Type            Header          Context of definition           Meaning
site_t          stddef.h                                        type for "sizes" and cardinalites
ptrdiff_t       stddef.h                                        type for size differences
uintmax_t       stdint.h                                        maximum width usigned integer, preprocessor
intmax_t        stdint.h                                        maximun width signed integer, preprocessor
time_t          time.h          time(0), difftime(t1, t0)       calendar time in seconds since epoch
clock_t         time.h          clock()                         processor time
```
