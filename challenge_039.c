//
// Created by titouan on 13/06/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
	int max_count = 0;
	int best_p = 0;

	for (int p = 3; p < 1000; p++) {
		int count = 0;
		for (int a = 1; a <= p / 3; a++) {
			for (int b = a; b <= p; b++) {
				if (pow(a, 2) + pow(b, 2) == pow(p - a - b, 2)) {
					count++;
				}
			}
		}
		if (count > max_count) {
			best_p = p;
			max_count = count;
		}
	}

	printf("Answer : %d\n", best_p);

	return EXIT_SUCCESS;
}