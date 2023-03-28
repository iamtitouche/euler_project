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


int main() {

    int n;
    List *factors;
    ListElement *curr_f;

    for (n = 2; n <= 35; n++) {
        factors = prime_factors(n);
        printf("Prime facors of %d are : ", n);
        curr_f = (*factors).head;
        for (int i = 0; i < (*factors).lenght; i++) {
            printf("%d ", (*curr_f).value);
            curr_f = (*curr_f).next;
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}