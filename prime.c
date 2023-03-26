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
    
    while (n % 2 == 0) {
        n = n / 2;
        append(prime_factors, 2);
    }

    for (int i = 3; i <= pow(n, 1/2) + 1; i+=2) {
        while (n % i == 0) {
            n = n / i;
            append(prime_factors, i);
        }

    }
    if (n != 1) {
        append(prime_factors, n);
    }
    
    return prime_factors;
}

int main() {
    int n = 18;
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