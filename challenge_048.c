//
// Created by titouan on 14/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "large_integer.h"

int main() {
    large_integer *sum = malloc(sizeof(large_integer));

    sum->length = 1;
    sum->digits = malloc(sum->length * sizeof(int));
    sum->digits[0] = 1;

    large_integer *n;

    for (int i = 2; i <= 1000; i++) {
        n = large_power_of_int(i, i);
        sum = sum_large_integers(sum, n);
    }

    printf("Answer : ");

    for (int i = 9; i >= 0; i--) {
        printf("%d", sum->digits[i]);
    }

    printf("\n");

    return EXIT_SUCCESS;
}
