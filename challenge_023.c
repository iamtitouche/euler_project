//
// Created by titouan on 12/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "divisors.h"


bool is_sum_of_two_abundant(int n) {
    int j;
    for (int i = 1; i <= n / 2; i++) {
        j = n - i;
        if (is_abundant(i) && is_abundant(j)) {
            return true;
        }
    }
    return false;
}

int main() {
    int sum = 0;

    for (int i = 1; i <= 28123; i++) {
        if (!is_sum_of_two_abundant(i)) {
            sum += i;
        }
    }

    printf("Answer : %d\n", sum);

    return EXIT_SUCCESS;
}