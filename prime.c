#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include "linked_list.c"



List* prime_factors(int n) {
    List *prime_factors = create_list();
    
    double sqrt_n = pow((double)n, 0.5);

    while (n % 2 == 0) {
        n = n / 2;
        append(prime_factors, 2);
    }

    for (int i = 3; i <= sqrt_n; i+=2) {
        while (n % i == 0) {
            n = n / i;
            append(prime_factors, i);
        }
        if (n == 1) break;
    }

    if (n > 1) append(prime_factors, n);

    return prime_factors;
}

