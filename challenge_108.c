//
// Created by titouan on 02/06/23.
//
#include <stdio.h>
#include <stdlib.h>


int main() {
	int count = 0;

	int n = 4;

	while (count <= 1000) {
		count = 0;
		for (int x = n + 1; x <= 2 * n; x++) {
			if ((x * n) % (x - n) == 0) {
				count++;
			}
		}
		n++;
	}

	printf("Answer : %d\n", count);

	return EXIT_SUCCESS;
}
