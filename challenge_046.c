//
// Created by sadount on 15/05/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "prime.h"


int main() {
    int n_limit = 10000;
    bool *prime_bool = prime_list(10000);
    int prime;
    float sqrt_i2;
    bool found = true;
    int result = 0;

    for (int i = 3; i <= n_limit; i += 2) {
        sqrt_i2 = pow(i / 2, 0.5);
        if (!found) {
            result = i - 2;
            break;
        }
        found = false;
        for (int j = 0; j <= sqrt_i2; j++) {
            prime = i - 2 * j * j;
            if (prime > 1 && prime_bool[prime]) {
                printf("I = %d, P : %d, J = %d\n", i, prime, j);
                found = true;
                break;
            }
        }
    }

    printf("Answer : %d\n", result);

}

