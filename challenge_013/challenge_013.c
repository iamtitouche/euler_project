#include <stdlib.h>
#include <stdio.h>
#include "../large_integer.h"

int main() {
    //large_integer *sum;

    char *n_str = malloc(49 * sizeof(char));
    large_integer *sum = create_large_integer(0);

    FILE *fptr;
    fptr = fopen("numbers.txt","r");

    for (int _ = 0; _ < 100; _++) {
	    fscanf(fptr, "%s\n", n_str);
	    large_integer *n = create_large_integer_from_str(n_str, 50);
	    sum = sum_large_integers(n, sum);
    }

    fclose(fptr);


    printf("Answer : ");
    for (int i = sum->length-1; i >= sum->length-10; i--) {
	    printf("%d", sum->digits[i]);
    }
    printf("\n");

    return EXIT_SUCCESS;
}