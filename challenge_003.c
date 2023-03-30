#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include "prime.c"

int main(){
    int t;
    int n;
    scanf("%d",&t);
    for(int _ = 0; _ < t; _++){
        scanf("%d",&n);
        List *factors;
        factors = prime_factors(n);
        printf("%d\n", (*(*factors).queue).value);
    }
    return 0;
}