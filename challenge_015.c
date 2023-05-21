//
// Created by titouan on 11/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "binomial.h"


int main() {
    ulong result = binomial_coefficient(20, 40);

    printf("Answer : %ld\n", result);

    return EXIT_SUCCESS;
}
