//
// Created by titouan on 13/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int count_distinct_divisors(unsigned long n) {
    int count = 0;
    for (unsigned long i = 1; i <= pow(n, 0.5); i++) {
        if (n % i == 0) {
            count++;
            if (n / i != i) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    unsigned long n = 1;

    int i = 2;

    while (count_distinct_divisors(n) < 500) {
        n += i;
        i++;
    }

    printf("Answer : %ld\n", n);

    return EXIT_SUCCESS;
}