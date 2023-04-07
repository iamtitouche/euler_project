#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>



int main() {
    int t;
    int n;
    int max;
    int res;
    scanf("%d",&t);

    for(int _ = 0; _ < t; _++) {
        max = 1;
        res = 0;
        scanf("%d",&n);

        for (int i = 2; i <= n; i++) {
            max *= i;
        }

        for (int i = 1; i <= max; i++) {
            for (int j = 1;  j <= n; j++) {
                if (i % j != 0) {
                    break;
                }
                else if (j == n) {
                    res = i;
                    break;
                }

            }
            if (res != 0) break;

        }

        printf("%d\n", res);

    }
    return EXIT_SUCCESS;
}