//
// Created by titouan on 15/05/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "combinations.h"
#include "prime.h"


u_int64_t change_digits(u_int64_t n, int n_size, char new_digit, int *indexes, int n_digit_to_change) {
	char n_str[n_size];
	sprintf(n_str,"%ld", n);

	char j = n_str[indexes[0]];

	for (int i = 1; i < n_digit_to_change; i++) {
		if (n_str[indexes[i]] != j) {
			return 0;
		}
	}

	for (int i = 0; i < n_digit_to_change; i++) {
		n_str[indexes[i]] = new_digit;
	}

	u_int64_t result = atoi(n_str);

	return result;
}

int main() {
	ulong n_max = 99999999;
	int n_primes = 0;

	char digits[10] = "0123456789";

	ulong prime;
	bool *prime_bool = prime_list(n_max);
	ulong *primes = prime_list_from_booleans(prime_bool, n_max + 1, &n_primes);

	printf("Dernier premier %ld\n", primes[n_primes - 1]);

	int count;
	combination *comb;
	ulong test_prime;

	for (ulong i = 5; i < 8; i++) {
		prime = primes[i];
		int n_digit = (int) log10(prime) + 1;
		for (int n_digit_to_change = 1; n_digit_to_change < n_digit; n_digit_to_change++) {
			comb = get_first_combination(n_digit_to_change, n_digit);
			while (comb != NULL) {
				count = 1;
				for (int j = 0; j < 10; j++) {
					test_prime = change_digits(prime, n_digit, digits[j], comb->indices, n_digit_to_change);
					if (test_prime == 0) {
						break;
					}
					if (prime_bool[test_prime] && test_prime != prime) {
						count++;
						if (count == 6) {
							printf("Count = 6, %ld\n", prime);
						}
						if (count == 8) {
							printf("Answer : %ld\n", prime);
							return EXIT_SUCCESS;
						}
					}
				}
				combination *tmp = comb;
				comb = get_following_combination(comb, n_digit);
				free(tmp);
			}
		}
	}
}

