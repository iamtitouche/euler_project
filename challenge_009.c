//
// Created by titouan on 11/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
    int a, b, c, n = 1000;
    int b_limit;

    for (a = 0; a <= n / 3; a++) {
        b_limit = (1000 - a) / 2;

        for (b = a + 1; b <= b_limit; b++) {

            c = (int) pow(a*a + b*b, 0.5);

            if (c > b && a + b + c == n && a*a + b*b == c*c) {
                int product = a * b * c;
                printf("Answer : %d\n", product);
                return EXIT_SUCCESS;
            }
        }
    }

    return EXIT_SUCCESS;
}