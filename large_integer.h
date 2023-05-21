//
// Created by titouan on 14/05/23.
//

#ifndef EULER_PROJECT_LARGE_INTEGER_H
#define EULER_PROJECT_LARGE_INTEGER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Création du type large_integer
//Le paramètre length est le nombre de chiffres qui composent l'entier
//Le paramètre digits est un array d'entier (int) compris entre 0 et 9 inclus qui correspondent au décimale de poids faible d'abord
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


//Fonction sum_large_integers
//Renvoie un pointeur vers un large_integer calculé comme la somme des large_integer d'addresses a et b
large_integer* sum_large_integers(large_integer *a, large_integer *b) {
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

//Fonction multiply_by_int
//Renvoie un pointeur vers un large_integer calculé comme le produit d'un large_integer d'addresse number et un petit entier factor
large_integer* multiply_by_int(large_integer *number, int factor) {
    int carried_out = 0;
    int tmp;

    large_integer *result = malloc(sizeof(large_integer));
    result->length = number->length;
    result->digits = malloc( result->length * sizeof(int));

    int i;
    for (i = 0; i < result->length; i++) {
        tmp = number->digits[i] * factor + carried_out;
        result->digits[i] = tmp % 10;
        carried_out = tmp / 10;
    }

    if (carried_out != 0) {
        result->length += (int) log10((double) carried_out) + 1;
        result->digits = realloc(result->digits, result->length * sizeof(int));
    }

    for (i = i; i < result->length; i++) {
        result->digits[i] = carried_out % 10;
        carried_out /= 10;
    }

    return result;
}


//Fonction create_large_integer
//Crée un large_integer dont la valeur et celle de l'entier n (int) passé en paramètre et renvoie l'addresse de ce large_integer
large_integer* create_large_integer(int n) {
    large_integer *number = malloc(sizeof(large_integer));

    number->length = (int) log10((double ) n) + 1;
    number->digits = malloc( number->length * sizeof(int));

    for (int i = 0; i < number->length; i++) {
        number->digits[i] = n % 10;
        n /= 10;
    }

    return number;
}

//Fonction large_power_of_int
//Fonction "Brut Force" de calcul d'une puissance entière power (int) d'un entier n (int)
//Renvoie un pointeur de large_integer
//Cette Fonction a une grande complexité en temps, on codera plus tard une fonction équivalente utilisant un algorithme d'exonentiation rapide
//qui sera cependant plus complexe en mémoire
large_integer* large_power_of_int(int n, int power) {
    large_integer *result = create_large_integer(n);

    for (int i = 1; i < power; i++) {
        result = multiply_by_int(result, n);
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


int sum_of_digits(large_integer *number) {
    int sum = 0;

    for (int i = 0; i < number->length; i++) {
        sum += number->digits[i];
    }

    return sum;
}


#endif //EULER_PROJECT_LARGE_INTEGER_H
