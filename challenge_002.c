//
// Created by titouan on 11/05/23.
//
#include <stdio.h>
#include <stdlib.h>


int main(){
    int n = 1, m = 2, sum = 0, tmp;

    while (m <= 4000000) {
        if (m % 2 == 0) {
            sum += m;
        }
        tmp = n;
        n = m;
        m = n + tmp;
    }
    printf("Answer : %d\n", sum);

    return EXIT_SUCCESS;
}