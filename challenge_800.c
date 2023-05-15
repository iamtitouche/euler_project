//
// Created by titouan on 15/05/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "prime.h"

int main() {
    int p = 2, q = 3;
    int n = 800800;
    int n_primes = 0;
    int count = 0;

    while (p * log(q) + q * log(p) <= n * log(n)) {
        q++;
    }


    bool *prime_bool = prime_list(q);
    int *primes = prime_list_from_booleans(prime_bool, q + 1, &n_primes);

    for (int i = 0; i < n_primes - 1; i++) {
        p = primes[i];
        for (int j = i + 1; j < n_primes; j++) {
            q = primes[j];
            if (p * log(q) + q * log(p) <= n * log(n)) {
                count++;
            }
            else {
                break;
            }
        }
    }

    printf("Answer : %d\n", count);
}
