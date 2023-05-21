//
// Created by titouan on 21/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "binomial.h"


int main() {
    int count = 0;

    ulong binomial_coef;

    for (int n = 1; n <= 100; n++) {
        for (int r = 2; r <= n / 2; r++) {
            binomial_coef = binomial_coefficient(r, n);
            if (binomial_coef > 1000000) {
                if (2 * r == n) {
                    count++;
                }
                else {
                    count += 2;
                }
            }
        }
    }

    printf("Answer %d\n", count);

    return EXIT_SUCCESS;
}
