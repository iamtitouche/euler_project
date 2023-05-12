//
// Created by titouan on 11/05/23.
//
#include <stdio.h>
#include <stdlib.h>


int main(){
    int n = 1000, sum = 0;

    for (int i = 3; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    printf("Answer : %d\n", sum);

    return EXIT_SUCCESS;
}
