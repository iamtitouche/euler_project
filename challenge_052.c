//
// Created by titouan on 21/05/23.
//
#include <stdlib.h>
#include "nb_string.h"

int main() {
    int n = 0;
    bool found = false;

    do {
        n += 1;
        found = true;
        for (int i = 2; i < 6; i++) {
            if (!are_anagrams(n, i * n)) {
                found = false;
                break;
            }
        }
    } while (!found);


    printf("Answer : %d\n", n);


    return EXIT_SUCCESS;
}
