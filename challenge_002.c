#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t;
    long int n;
    long int a, b, tmp;
    long int sum;
    scanf("%d",&t);
    for(int _ = 0; _ < t; _++) {
        scanf("%ld",&n);
        sum = 0;
        a = 1;
        b = 1;
        tmp;
        while (b <= n) {
            if (b % 2 == 0) {
                sum += b;
            }
            tmp = b;
            b += a;
            a = tmp;
        }
        printf("%ld\n", sum);
    }
    return 0;
}