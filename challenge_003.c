#include <stdio.h>
#include <stdlib.h>
#include "prime.h"


int main(){
    ulong n = 600851475143;

    prime_factor *curr_factor = prime_factors(n);

    while (curr_factor->next != NULL) {
        curr_factor = curr_factor->next;
    }

    printf("Answer : %ld\n", curr_factor->value);

    return EXIT_SUCCESS;
}