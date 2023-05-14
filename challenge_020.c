//
// Created by titouan on 14/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "large_integer.h"

int main() {
    large_integer *n = malloc(sizeof(large_integer));

    n->length = 1;
    n->digits = malloc( n->length * sizeof(int));
    n->digits[0] = 1;

    for (int i = 2; i <= 100; i++) {
        n = multiply_by_int(n, i);
    }

    int sum = 0;
    for (int i = 0; i < n->length; i++) {
        sum += n->digits[i];
    }

    printf("Answer : %d\n", sum);

    return EXIT_SUCCESS;
}