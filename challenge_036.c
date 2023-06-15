//
// Created by titouan on 15/06/23.
//
#include <stdlib.h>
#include <stdio.h>
#include "large_integer.h"
//#include "nb_string.h"


int main() {
	int sum = 12;
	printf("Answer : %d \n", sum);

	large_integer *binai = binary_from_int(sum);
	printf("Answer : %d \n", sum);

	print_large_integer(binai);


	/*for (int i = 1; i < 1000000; i++) {
		if (palindromic_nb(i)) {
			if () {
				sum += i;
			}
		}
	}*/


	printf("Answer : %d \n", sum);

	return EXIT_SUCCESS;
}
