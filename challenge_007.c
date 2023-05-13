//
// Created by titouan on 13/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main(){
    int n = 1000000;
    int count = 0;
    bool *indexes_are_primes = prime_list(n);

    for (int i = 0; i <= n; i++) {
        if (indexes_are_primes[i]) {
            count++;
            if (count == 10001) {
                printf("Answer : %d\n", i);
            }
        }
    }

    return EXIT_SUCCESS;
}
