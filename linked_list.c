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
    (*list).lenght = 0;
    (*list).head = NULL;
    (*list).queue = NULL;
    return list;
}

ListElement* create_list_element(int value) {
    ListElement *element = malloc(sizeof(ListElement));
    (*element).value = value;
    (*element).next = NULL;
    (*element).prev = NULL;
    return element;
}

void append(List *list_pt, int value) {
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

void remove_by_reference(List *list_pt, ListElement *element) {
    if ((*list_pt).lenght == 1) {
        (*list_pt).head = NULL;
        (*list_pt).queue = NULL;
    }
    else {
        if (element == (*list_pt).head) {
            ListElement *next = (*element).next;
            (*list_pt).head = next;
            (*next).prev = NULL;
        }
        else if ((*element).next == NULL) {
            ListElement *previous = (*element).prev;
            (*list_pt).queue = previous;
            (*previous).next = NULL;
        }
        else {
            ListElement *previous = (*element).prev;
            ListElement *next = (*element).next;
            (*previous).next = next;
            (*next).prev = previous;
        }
    }
    free(element);
    (*list_pt).lenght--;
}
