//
// Created by titouan on 15/05/23.
//

#ifndef EULER_PROJECT_COMBINATIONS_H
#define EULER_PROJECT_COMBINATIONS_H

#include <stdlib.h>
#include <stdio.h>

typedef struct combination {
    int length;
    int *indices;
}combination;


//Fonction get_all_combination
//Renvoie les combinaison de n_element entiers compris entre 0 et n_max - 1
//Une combinaison ne tient pas compte de l'ordre des valeurs cependant les entiers dans chaque
//combinaisons seront triés dans l'ordre croissant

combination* get_first_combination(int n_element, int n_max) {
    combination *result = malloc(sizeof(combination));
    result->length = n_element;
    result->indices = malloc(result->length * sizeof(int));

    for (int i = 0; i < n_element; i++) {
        result->indices[i] = i;
    }

    return result;
};

combination* get_following_combination(combination* previous, int n_max) {
    if (previous->indices[previous->length - 1] < n_max - 1) {
        combination *result = malloc(sizeof(combination));
        result->length = previous->length;
        result->indices = malloc(previous->length * sizeof(int));
        for (int i = 0; i < result->length - 1; i++) {
            result->indices[i] = previous->indices[i];
        }
        result->indices[previous->length - 1] = previous->indices[previous->length - 1] + 1;
        return result;
    }

    int *indices = malloc(previous->length * sizeof(int));
    int shift_up = 0;

    while (shift_up < previous->length - 1 && previous->indices[shift_up] + 1 == previous->indices[shift_up + 1]) {
        indices[shift_up] = previous->indices[shift_up];
        shift_up++;
    }

    if (shift_up == previous->length - 1) {
        free(indices);
        return NULL;
    }

    combination *result = malloc(sizeof(combination));
    result->length = previous->length;
    result->indices = indices;
    result->indices[shift_up] = previous->indices[shift_up] + 1;

    int shift_down = shift_up + 1;
    for (int i = shift_down; i < result->length; i++) {
        result->indices[i] = result->indices[i - 1] + 1;
    }


    return result;
}


void print_combination(combination* comb) {
    for (int i = 0; i < comb->length; i++) {
        printf("%d ", comb->indices[i]);
    }
    printf("\n");
}


#endif //EULER_PROJECT_COMBINATIONS_H
