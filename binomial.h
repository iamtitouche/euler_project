//
// Created by titouan on 21/05/23.
//

#ifndef EULER_PROJECT_BINOMIAL_H
#define EULER_PROJECT_BINOMIAL_H


#include "prime.h"


ulong binomial_coefficient(int k, int n) {
    int size_num, size_den;
    if (k >= n-k) {
        size_num = n - k;
        size_den = n - k - 1;
    }
    else {
        size_num = k;
        size_den = k - 1;
    }
    int *num_values = malloc(size_num * sizeof(int));
    for (int i = 0; i < size_num; i++) {
        num_values[i] = n - i;
    }


    int *den_values = malloc((size_den) * sizeof(int));

    for (int i = 0; i < size_den; i++) {
        den_values[i] = 2 + i;
    }


    int *den_factors = NULL;
    int last_size = 0;
    int curr_index;
    prime_factor *factors;
    prime_factor *curr_factor;
    int n_factors;

    for (int i = 0; i < size_den; i++) {
        factors = prime_factors((ulong) den_values[i]);
        curr_factor = factors;

        n_factors = 0;
        while (curr_factor != NULL) {
            n_factors += curr_factor->multiplicity;
            curr_factor = curr_factor->next;
        }

        if (!den_factors) {
            den_factors = malloc(n_factors * sizeof(int));
        }
        else {
            den_factors = realloc(den_factors, (last_size + n_factors) * sizeof(int));
        }

        curr_index = last_size;

        curr_factor = factors;
        while (curr_factor != NULL) {
            for (int j = 0; j < curr_factor->multiplicity; j++) {
                den_factors[curr_index] = curr_factor->value;
                curr_index++;
            }
            curr_factor = curr_factor->next;
        }

        last_size += n_factors;
    }


    for (int i = 0; i < size_num; i++) {
        for (int j = 0; j < last_size; j++) {
            if (den_factors[j] != 0 && den_factors[j] != 1 && num_values[i] % den_factors[j] == 0) {
                num_values[i] /= den_factors[j];
                den_factors[j] = 0;
            }
            if (num_values[i] == 1) {break;}
        }
    }

    ulong result = 1;

    for (int i = 0; i < size_num; i++) {
        result *= num_values[i];
    }

    return result;
}

#endif //EULER_PROJECT_BINOMIAL_H
