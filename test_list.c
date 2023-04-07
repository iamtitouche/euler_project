#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include "prime.c"


int main(void) {

    List *list = primes_bellow(1000);

    print_list(list);



    return EXIT_SUCCESS;
}