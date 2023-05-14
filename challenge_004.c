//
// Created by titouan on 11/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


bool palindromic_nb(int n) {
    int length = (int) log10((double) n);

    char n_str[length];
    sprintf(n_str, "%d", n);

    for (int i = 0; i <= length / 2; i++) {
        if (n_str[i] != n_str[length - i]) {
            return false;
        }
    }

    return true;
}



int main() {
    int max_palindrome, curr_test;
    int min_j;


    max_palindrome = 0;
    min_j = 100;

    for (int i = 999; i >= 100; i--) {
        if (999 * i < max_palindrome) {
            break;
        }

        for (int j = 999; j >= min_j; j--) {
            curr_test = j * i;
            if (curr_test < max_palindrome) {
                break;
            }
            if (palindromic_nb(curr_test)) {
                min_j = j;
                max_palindrome = curr_test;
                break;
            }
        }
    }
    printf("%d\n", max_palindrome);


    return EXIT_SUCCESS;
}
