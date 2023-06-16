//
// Created by titouan on 16/06/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int sum_fact_of_digits_is_n(int n, int *factorials) {
	int size = (int) log10(n) +1;

	char n_str[size];
	sprintf(n_str, "%d", n);

	int sum = 0;

	for (int i = 0; i < size; i++) {
		if (sum > n) {
			return false;
		}
		if (n_str[i] == '0') {
			sum++;
		}
		else if (n_str[i] == '1') {
			sum++;
		}
		else if (n_str[i] == '2') {
			sum += factorials[2];
		}
		else if (n_str[i] == '3') {
			sum += factorials[3];
		}
		else if (n_str[i] == '4') {
			sum += factorials[4];
		}
		else if (n_str[i] == '5') {
			sum += factorials[5];
		}
		else if (n_str[i] == '6') {
			sum += factorials[6];
		}
		else if (n_str[i] == '7') {
			sum += factorials[7];
		}
		else if (n_str[i] == '8') {
			sum += factorials[8];
		}
		else if (n_str[i] == '9') {
			sum += factorials[9];
		}
	}

	return sum == n;
}

int main() {
	int *factorials = malloc(10 * sizeof(int));
	int sum = 0;

	factorials[0] = 1;

	for (int i = 1; i <= 9; i++) {
		factorials[i] = i * factorials[i - 1];
	}


	for (int n = 10; n <= factorials[9] * 8; n++) {
		if (sum_fact_of_digits_is_n(n, factorials)) {
			sum += n;
		}

	}

	printf("Answer : %d\n", sum);
	return EXIT_SUCCESS;
}
