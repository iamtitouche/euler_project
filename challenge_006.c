//
// Created by titouan on 11/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int sum = 0, sum_of_squares = 0, n = 100;

    for (int i = 0; i <= n; i++) {
        sum += i;
        sum_of_squares += pow(i, 2);
    }

    int result = pow(sum, 2) - sum_of_squares;
    printf("Answer : %d\n", result);

    return EXIT_SUCCESS;
}
