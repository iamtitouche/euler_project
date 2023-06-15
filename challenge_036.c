//
// Created by titouan on 15/06/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "large_integer.h"
#include "nb_string.h"


int main() {
	int sum = 0;

	for (int i = 1; i < 1000000; i++) {
		if (palindromic_nb(i)) {
			if (palindromic_large_nb(binary_from_int(i))) {
				sum += i;
			}
		}
	}

	printf("Answer : %d \n", sum);

	return EXIT_SUCCESS;
}
