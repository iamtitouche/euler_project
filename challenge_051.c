//
// Created by titouan on 15/05/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "combinations.h"

int main() {
    combination *comb = get_first_combination(4, 7);

    while (comb != NULL) {
        print_combination(comb);
        comb = get_following_combination(comb, 7);
    }
}
