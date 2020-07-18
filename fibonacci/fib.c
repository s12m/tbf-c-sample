#include "fib.h"
#include <stdlib.h>

static size_t fib_with_memo(const size_t n, size_t memo[]) {
    if (n >= 2 && memo[n] == 0) {
        memo[n] = fib_with_memo(n - 1, memo) + fib_with_memo(n - 2, memo);
    }
    return memo[n];
}

size_t fib(const size_t n) {
    size_t *memo = (size_t *)calloc(n + 1, sizeof(size_t));
    memo[1] = 1;

    size_t result = fib_with_memo(n, memo);
    free(memo);
    return result;
}
