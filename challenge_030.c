//
// Created by titouan on 13/06/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int sum_powers_of_digits(int n, int power) {
        int a, result = 0;

	while (n != 0) {
		a = n % 10;
		result += (int) pow(a, power);
		n = n / 10;
	}

	return result;
}

int main() {
	
	int sum = 0;
	for (int i = 10; i <= 413343; i++) {
		if (i == sum_powers_of_digits(i, 5)) {
			sum += i;
		}
	}

	printf("Answer : %d\n", sum);

	return EXIT_SUCCESS;
}
