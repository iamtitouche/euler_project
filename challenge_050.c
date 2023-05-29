//
// Created by titouan on 29/05/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "prime.h"


int main() {
	int j = 22;
	int result = 953;
	bool smallest_pos_too_large = false;

	bool *prime = prime_list(1000000);

	int n_primes = 0;
	ulong *primes = prime_list_from_booleans(prime, (ulong) 1000001, &n_primes);

	while (!smallest_pos_too_large) {
		smallest_pos_too_large = true;
		int i_min = 0, i_max = j - 1;

		ulong sum = 0;
		for (int i = i_min; i <= i_max; i ++) {
			sum += primes[i];
		}

		if (sum < 1000000) {
			smallest_pos_too_large = false;
		}

		while (sum < 1000000) {
			if (prime[sum]) {
				result = sum;
			}

			sum = sum - primes[i_min] + primes[i_max + 1];
			i_min++;
			i_max++;
		}

		j += 1;
	}


	printf("Answer : %d\n", result);

	return EXIT_SUCCESS;
}