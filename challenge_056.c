//
// Created by titouan on 21/05/23.
//
#include <stdlib.h>
#include "large_integer.h"

int main() {
    large_integer *integer;

    int max_sum = 0;
    int tmp;

    for (int a = 1; a < 100; a++) {
        for (int b = 1; b < 100; b++) {
            integer = large_power_of_int(a, b);
            tmp = sum_of_digits(integer);

            if (tmp > max_sum) {
                max_sum = tmp;
            }
        }
    }

    printf("Answer  : %d\n", max_sum);

    return EXIT_SUCCESS;
}