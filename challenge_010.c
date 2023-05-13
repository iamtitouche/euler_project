//
// Created by titouan on 13/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main(){
    int n = 2000000;
    ulong sum = 0;
    bool *indexes_are_primes = prime_list(n);

    for (int i = 0; i <= n; i++) {
        if (indexes_are_primes[i]) {
            printf(" : %d\n", i);
            sum += i;
        }
    }

    printf("Answer : %ld\n", sum);

    return EXIT_SUCCESS;
}

