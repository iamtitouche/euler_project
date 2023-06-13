//
// Created by titouan on 13/06/23.
//
#include <stdlib.h>
#include <stdio.h>

int main() {
	int n = 500;

	long result = 8 * n * (n + 1) * (2 * n + 1) / 3 + 2 * n * (n + 1) + 1 + 4 * n;

	printf("Answer : %ld\n", result);
	return EXIT_SUCCESS;
}
