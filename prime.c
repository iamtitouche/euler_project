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
    
    int curr_n = n;

    while (curr_n % 2 == 0) {
        curr_n = curr_n / 2;
        append(prime_factors, 2);
    }

    for (int i = 3; i <= curr_n; i+=2) {
        while (curr_n % i == 0) {
            curr_n = curr_n / i;
            append(prime_factors, i);
        }
        if (curr_n == 1 || pow(i, 2) > n) {
            break;
        }
    }

    if ((*prime_factors).lenght == 0) {
        append(prime_factors, n);
    }
    
    return prime_factors;
}

int main() {
    int n = 49;
    List *factors = prime_factors(n);

    ListElement *curr_f = (*factors).head;
    for (int i = 0; i < (*factors).lenght; i++) {
        printf("%d\n", (*curr_f).value);
        curr_f = (*curr_f).next;
    }


     n = 27;
    factors = prime_factors(n);

    curr_f = (*factors).head;
    for (int i = 0; i < (*factors).lenght; i++) {
        printf("%d\n", (*curr_f).value);
        curr_f = (*curr_f).next;
    }


    n = 145;
    factors = prime_factors(n);

    curr_f = (*factors).head;
    for (int i = 0; i < (*factors).lenght; i++) {
        printf("%d\n", (*curr_f).value);
        curr_f = (*curr_f).next;
    }

    return EXIT_SUCCESS;
}