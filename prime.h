//
// Created by titouan on 11/05/23.
//

#ifndef EULER_PROJECT_PRIME_H
#define EULER_PROJECT_PRIME_H

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


typedef struct prime_factor {
    ulong value;
    int multiplicity;
    struct prime_factor* next;
}prime_factor;


 prime_factor* prime_factors(ulong n) {
     prime_factor *first_factor, *curr_factor = NULL;
     double sqrt_n = pow((double) n, 0.5);

    while (n % 2 == 0 && n > 0) {
        if (!curr_factor) {
            curr_factor = malloc(sizeof(prime_factor));
            first_factor = curr_factor;
            curr_factor->value = 2;
            curr_factor->multiplicity = 1;
            curr_factor->next = NULL;
        }
        else {
            curr_factor->multiplicity++;
        }
        n = n / 2;
    }


    for (int i = 3; i <= sqrt_n; i += 2) {
        while (n % i == 0) {
            if (!curr_factor) {
                curr_factor = malloc(sizeof(prime_factor));
                first_factor = curr_factor;
                curr_factor->value = i;
                curr_factor->multiplicity = 1;
                curr_factor->next = NULL;
            }
            else {
                if (curr_factor->value == i) {
                    curr_factor->multiplicity++;
                }
                else {
                    prime_factor *new_factor = malloc(sizeof(prime_factor));
                    new_factor->value = i;
                    new_factor->multiplicity = 1;
                    new_factor->next = NULL;
                    curr_factor->next = new_factor;
                    curr_factor = new_factor;
                }
            }
            n = n / i;
        }
        if (n == 1) break;
    }

    if (n > 1) {
        if (!curr_factor) {
            first_factor = malloc(sizeof(prime_factor));
            first_factor->value = n;
            first_factor->multiplicity = 1;
            first_factor->next = NULL;
        }
        else {
            prime_factor *new_factor = malloc(sizeof(prime_factor));
            new_factor->value = n;
            new_factor->multiplicity = 1;
            new_factor->next = NULL;
            curr_factor->next = new_factor;
        }
    }

    return first_factor;
}


bool* prime_list(int n) {
     bool *prime_bool = malloc((n + 1) * sizeof(bool));

     prime_bool[0] = false;
     prime_bool[1] = false;
     prime_bool[2] = true;

     for (int i = 3; i <= n - 1; i += 2) {
         prime_bool[i] = true;
         prime_bool[i + 1] = false;
     }

     prime_bool[n] = (n % 2 == 1);

     double sqrt_n = pow(n, 0.5);

     for (int i = 3; i <= sqrt_n; i += 2) {
         if (prime_bool[i]) {
             for (int j = 2 * i; j <= n; j += i) {
                 prime_bool[j] = false;
             }
         }
     }

     return prime_bool;
 }

#endif //EULER_PROJECT_PRIME_H


