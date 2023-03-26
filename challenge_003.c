#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int t; 
    scanf("%d",&t);
    for(int _ = 0; _ < t; _++){
        long n; 
        scanf("%ld",&n);
        long sum = 0;
        long a = 1;
        long b = 1;
        long tmp;
        while (b <= n) {
            if (b % 2 == 0) {
                sum += b;
            }
            tmp = b;
            b += a;
            a = tmp;
        }
        printf("%lld\n", sum);
    }
    return 0;
}