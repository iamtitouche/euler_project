//
// Created by titouan on 31/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main() {
	int lenght = 1;
	int n_prime = 0;
	int n_numbers = 1;
	int size_list_primes = 100000000;
	bool *prime_bool = prime_list(size_list_primes);

	while ((double) n_prime / n_numbers >= 0.1 || n_prime == 0) {
		lenght += 2;
		if ((ulong) lenght * lenght >= size_list_primes) {
			size_list_primes += 1000000000;
			free(prime_bool);
			prime_bool = prime_list(size_list_primes);
		}
		int n_to_test = lenght * (lenght - 1) + 1;
		if (prime_bool[n_to_test]) {
			n_prime++;
		}
		for (int _ = 0; _ < 2; _++) {
			n_to_test -= lenght - 1;
			if (prime_bool[n_to_test]) {
				n_prime++;
			}
		}
		n_numbers += 4;
	}

	printf("Answer : %d\n", lenght);

	return EXIT_SUCCESS;
}
