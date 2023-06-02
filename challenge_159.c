//
// Created by titouan on 31/05/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "prime.h"


int digital_root(int n) {
	int answer = n;

	while (answer >= 10) {
		int size = (int) log10(answer) +1;

		char n_str[size];
		sprintf(n_str, "%d", answer);

		answer = 0;

		for (int i = 0; i < size; i++) {
			if (n_str[i] == '1') {
				answer++;
			}
			else if (n_str[i] == '2') {
				answer+=2;
			}
			else if (n_str[i] == '3') {
				answer+=3;
			}
			else if (n_str[i] == '4') {
				answer+=4;
			}
			else if (n_str[i] == '5') {
				answer+=5;
			}
			else if (n_str[i] == '6') {
				answer+=6;
			}
			else if (n_str[i] == '7') {
				answer+=7;
			}
			else if (n_str[i] == '8') {
				answer+=8;
			}
			else if (n_str[i] == '9') {
				answer+=9;
			}
		}
	}

	return answer;
}


int main() {
	int i = 2, n_max = 999999;
	ulong sum = 0;

	int *mdrs = calloc((n_max + 1), sizeof(int));
	mdrs[0] = -1;
	mdrs[1] = -1;

	for (i = 2; i <= n_max; i++) {
		int curr_drs = digital_root(i);
		int max_drs = curr_drs;
		int size = 0;

		ulong *prime_array = factors_array((ulong) i, &size, false);

		if (prime_array[0] != (ulong) i) {
			for (int j = 0; j < size; j++) {
				int factor = prime_array[j];

				curr_drs = mdrs[factor] + mdrs[i / factor];
				if (curr_drs > max_drs) {
					max_drs = curr_drs;
				}
			}
		}
		//printf("mdrs(%d) = %d\n", i, max_drs);

		mdrs[i] = max_drs;
		sum += max_drs;
	}

	printf("Answer : %ld\n", sum);

	return EXIT_SUCCESS;
}
