#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


typedef struct ListElement{
    int value;
    struct ListElement *next;
    struct ListElement *prev;

} ListElement;


typedef struct List{
    int lenght;
    ListElement *head;
    ListElement *queue;
} List;


List* create_list() {
    List *list = malloc(sizeof(List));
    list->lenght = 0;
    list->head = NULL;
    list->queue = NULL;
    return list;
}


ListElement* create_list_element(int value) {
    ListElement *element = malloc(sizeof(ListElement));
    (*element).value = value;
    (*element).next = NULL;
    (*element).prev = NULL;
    return element;
}


ListElement* get_element_by_index(List* list, int index) {
    ListElement *curr_element;
    if (index <= (*list).lenght / 2) {
        curr_element = (*list).head;
        for (int _ = 0; _ < index; _++) {
            curr_element = (*curr_element).next;
        }
    }
    else if (index < (*list).lenght) {
        int n_step = (*list).lenght - index - 1;
        curr_element = (*list).queue;
        for (int _ = 0; _ < n_step; _++) {
            curr_element = (*curr_element).prev;
        }
    }
    return curr_element;
}

void append(List* list_pt, int value) {
    ListElement *new_element = create_list_element(value);
    if ((*list_pt).lenght == 0) {
        (*list_pt).head = new_element;
    }
    else {
        (*new_element).prev = (*list_pt).queue;
        (*(*list_pt).queue).next = new_element;
    }
    (*list_pt).queue = new_element;
    (*list_pt).lenght++;
}

List* init_list(int value, int size) {
    List *list = create_list();
    for (int _ = 0; _ < size; _++) {
        append(list, value);
    }
    return list;
}


void print_list(List* list) {
    printf("Size of List : %d\nContent of List is :", (*list).lenght);
    ListElement *curr_element = (*list).head;
    for (int i = 0; i < list->lenght - 1; i++) {
        printf("%d ", (*curr_element).value);
        curr_element = (*curr_element).next;
    }
    printf("%d\n", curr_element->value);
}



List* concatenate(List *list_1, List *list_2) {
    if (list_1->lenght == 0) {
        return list_2;
    }
    else if (list_2->lenght == 0) {
        return list_1;
    }
    
    (list_1->queue)->next = (*list_2).head;
    (list_2->head)->prev = (*list_1).queue;
    list_1->queue = list_2->queue;
    list_1->lenght += list_2->lenght;

    return list_1;
}

/*
void pivot_sort(List *list) {
    int pivot = (list->head)->value;
    
    List *bellow_pivot = create_list();
    List *above_pivot = create_list();

    ListElement *curr_cell = (list->head)->next;

    while (curr_cell != NULL) {
        if (curr_cell->value <= pivot) {
            append(bellow_pivot, curr_cell->value);
        }
        else append(above_pivot, curr_cell->value);
        
        curr_cell = curr_cell->next;
    }
}
*/

void remove_by_reference(List *list_pt, ListElement *element) {
    if (list_pt->lenght == 1) {
        list_pt->head = NULL;
        list_pt->queue = NULL;
    }
    else {
        if (element == list_pt->head) {
            ListElement *next = element->next;
            list_pt->head = next;
            next->prev = NULL;
        }
        else if ((*element).next == NULL) {
            ListElement *previous = element->prev;
            list_pt->queue = previous;
            previous->next = NULL;
        }
        else {
            ListElement *previous = element->prev;
            ListElement *next = element->next;
            previous->next = next;
            next->prev = previous;
        }
    }
    free(element);
    list_pt->lenght--;
}
