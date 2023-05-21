//
// Created by titouan on 21/05/23.
//

#ifndef EULER_PROJECT_NB_STRING_H
#define EULER_PROJECT_NB_STRING_H

#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int* count_digits(int n) {
    int size = (int) log10(n) +1;

    char n_str[size];
    sprintf(n_str, "%d", n);

    int *digit_count = calloc(10, sizeof(int));

    for (int i = 0; i < size; i++) {
        if (n_str[i] == '0') {
            digit_count[0]++;
        }
        else if (n_str[i] == '1') {
            digit_count[1]++;
        }
        else if (n_str[i] == '2') {
            digit_count[2]++;
        }
        else if (n_str[i] == '3') {
            digit_count[3]++;
        }
        else if (n_str[i] == '4') {
            digit_count[4]++;
        }
        else if (n_str[i] == '5') {
            digit_count[5]++;
        }
        else if (n_str[i] == '6') {
            digit_count[6]++;
        }
        else if (n_str[i] == '7') {
            digit_count[7]++;
        }
        else if (n_str[i] == '8') {
            digit_count[8]++;
        }
        else if (n_str[i] == '9') {
            digit_count[9]++;
        }
    }

    return digit_count;
}


bool are_anagrams(int n, int m) {
    int *digit_count_1 = count_digits(n);
    int *digit_count_2 = count_digits(m);

    for (int i = 0; i < 10; i++) {
        if (digit_count_1[i] != digit_count_2[i]) {
            return false;
        }
    }

    return true;
}

#endif //EULER_PROJECT_NB_STRING_H
