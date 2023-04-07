#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include "linked_list.c"


List* prime_factors(int n) {
    List *prime_factors = create_list();
    
    double sqrt_n = pow((double)n, 0.5);

    while (n % 2 == 0) {
        n = n / 2;
        append(prime_factors, 2);
    }

    for (int i = 3; i <= sqrt_n; i+=2) {
        while (n % i == 0) {
            n = n / i;
            append(prime_factors, i);
        }
        if (n == 1) break;
    }

    if (n > 1) append(prime_factors, n);

    return prime_factors;
}


List* prime_list_bool(int n) {
    List *is_prime = init_list(1, n + 1);

    List *primes = create_list();


    (is_prime->head)->value = 0;
    ((is_prime->head)->next)->value = 0;
    

    ListElement *curr_test = ((is_prime->head)->next)->next;
    ListElement *multiple_of_test;

    for (int i = 2; i <= sqrt(n); i++) {
        if (curr_test->value == 1) {
            append(primes, i);
            multiple_of_test = curr_test;
            int n_step = (n-i) / i;
            for (int _ = 0; _ < n_step; _++) {
                for (int j = 0; j < i; j++) {
                    multiple_of_test = multiple_of_test->next;
                }
                multiple_of_test->value = 0;
            }
        }
        curr_test = curr_test->next;
    }

    return is_prime;
}


List *primes_bellow(int n) {
    List *is_prime = prime_list_bool(n);

    List *primes = create_list();

    ListElement *curr_n = is_prime->head; 

    for (int i = 1; i <= n; i++) {
        curr_n = curr_n->next;
        if (curr_n->value == 1) {
            append(primes, i);
        }
    }

    return primes;
}
