//
// Created by titouan on 13/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "prime.h"

bool is_divisible_by_all_integers(int n, int max) {
    for (int i = 1; i <= max; i++) {
        if (n % i != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int step = 30 * 7 * 11 * 13 * 17 * 19;
    ulong n = step;

    while (!is_divisible_by_all_integers(n, 20)) {
        n += step;
    }

    printf("Answer : %ld\n", n);

    return EXIT_SUCCESS;
}