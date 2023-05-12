//
// Created by titouan on 11/05/23.
//
#include <stdio.h>
#include <stdlib.h>

int count_distinct_divisors(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int triangle = 1;
    int i = 1;

    while (count_distinct_divisors(triangle) < 500) {
        i++;
        triangle += i;
    }

    printf("Answer : %d\n", triangle);

    return EXIT_SUCCESS;
}
