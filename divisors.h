//
// Created by titouan on 12/05/23.
//
#include <stdbool.h>
#include <math.h>
#ifndef EULER_PROJECT_DIVISORS_H
#define EULER_PROJECT_DIVISORS_H


int sum_of_proper_divisors(int n) {
    int sum = 0;

    for (int i = 1; i <= pow(n, 0.5); i++) {
        if (n % i == 0) {
            sum += i;
            if (n / i != i && n / i != n) {
                sum += n / i;
            }
        }
    }

    return sum;
}


bool is_abundant(int n) {
    return n < sum_of_proper_divisors(n);
}


#endif //EULER_PROJECT_DIVISORS_H
