#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * Recursion
*/

size_t gcd2(size_t a, size_t b)
{
    assert(a <= b);
    if (!a)
    {
        return b;
    }
    size_t rem = b % a;
    return gcd2(rem, a);
}

size_t gcd(size_t a, size_t b)
{
    assert(a);
    assert(b);
    if (a < b)
    {
        return gcd2(a, b);
    }
    else
    {
        return gcd2(b, a);
    }
}

size_t fib(size_t n)
{
    if (n < 3)
    {
        return 1;
    }
    else
    {

        return fib(n - 1) + fib(n - 2);
    }
}

size_t fib_cache_rec(size_t n, size_t cache[n])
{
    if (!cache[n - 1])
    {
        cache[n - 1] = fib_cache_rec(n - 1, cache) + fib_cache_rec(n - 2, cache);
    }
    return cache[n - 1];
}

size_t fib_cache(size_t n)
{
    if (n + 1 <= 3)
        return 1;
    size_t cache[n];
    cache[0] = 1;
    cache[1] = 1;
    for (size_t i = 2; i < n; ++i)
    {
        cache[i] = 0;
    }
    return fib_cache_rec(n, cache);
}