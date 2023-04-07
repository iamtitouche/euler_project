#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


bool palindromic_nb(int n) {
    int lenght = (int) log10((double) n);


    char n_str[lenght];
    sprintf(n_str, "%d", n);


    for (int i = 0; i <= lenght / 2; i++) {
        if (n_str[i] != n_str[lenght - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    int n;
    int max_palindrome, curr_test;
    int min_j;
    int sup;
    scanf("%d",&t);

    for(int a0 = 0; a0 < t; a0++){
        max_palindrome = 0;
        min_j = 0;
        scanf("%d",&n);

        for (int i = 999; i > 0; i--) {
            if (999 * i < max_palindrome) {
                break;
            }
            
            if (999 > n / i) {
                sup = n / i;
            }
            else {
                sup = 999;
            }

            for (int j = sup; j >= min_j; j--) {
                curr_test = j * i;
                if (curr_test < max_palindrome) {
                    break;
                }
                if (palindromic_nb(curr_test) && curr_test < n) {
                        min_j = j;
                        max_palindrome = curr_test;
                    break;
                }
            }
        }
        printf("%d\n", max_palindrome);
    }
    return EXIT_SUCCESS;
}