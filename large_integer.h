//
// Created by titouan on 14/05/23.
//

#ifndef EULER_PROJECT_LARGE_INTEGER_H
#define EULER_PROJECT_LARGE_INTEGER_H
#include <stdio.h>
#include <stdlib.h>

typedef struct large_integer {
    int length;
    int *digits;
}large_integer;

large_integer* double_value(large_integer *number) {
    int carried_out = 0;
    int tmp;
    large_integer *result = malloc(sizeof(large_integer));
    result->length = number->length;
    result->digits = malloc( result->length * sizeof(int));

    for (int i = 0; i < number->length; i++) {
        tmp = 2 * number->digits[i] + carried_out;
        result->digits[i] = tmp%10;
        carried_out = tmp / 10;
    }

    if (carried_out != 0) {
        result->length++;
        result->digits = realloc(result->digits, result->length * sizeof(int));
        result->digits[result->length - 1] = carried_out;
    }

    return result;
}

large_integer* sum(large_integer *a, large_integer *b) {
    int carried_out = 0;
    int tmp;

    if (a->length < b->length) {
        large_integer *c = a;
        a = b;
        b = c;
    }

    large_integer *result = malloc(sizeof(large_integer));
    result->length = a->length;
    result->digits = malloc( result->length * sizeof(int));

    int i;
    for (i = 0; i < b->length; i++) {
        tmp = a->digits[i] + b->digits[i] + carried_out;
        result->digits[i] = tmp%10;
        carried_out = tmp / 10;
    }

    if (carried_out != 0) {
        if (b->length == a->length) {
            result->length++;
            result->digits = realloc(result->digits, result->length * sizeof(int));
            result->digits[b->length] = carried_out;
            return result;
        }
    }

    for (int j = i; j < result->length; j++) {
        tmp = a->digits[j] + carried_out;
        result->digits[j] = tmp % 10;
        carried_out = tmp / 10;
    }

    if (carried_out != 0) {
        result->length++;
        result->digits = realloc(result->digits, result->length * sizeof(int));
        result->digits[result->length - 1] = carried_out;
    }

    return result;
}

/*
char* large_integer_to_str(large_integer *number) {
    char str[number->length + 1];

    for (int i = 0; i < number->length; i--) {
        sprintf(&str[i], "%d", number->digits[number->length - 1 - i]);
    }

    return str;
}*/


void print_large_integer(large_integer *number) {
    for (int i = number->length - 1; i >= 0; i--) {
        printf("%d", number->digits[i]);
    }
    printf("\n#\n");
}


#endif //EULER_PROJECT_LARGE_INTEGER_H
