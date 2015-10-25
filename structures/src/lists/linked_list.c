#include "linked_list.h"

#include <stdlib.h>

linked_list_node_t* create_linked_list_node(void * value) {
    linked_list_node_t* node = malloc(sizeof(linked_list_node_t));
    node->next = NULL;
    node->value = value;
    return node;
}

linked_list_t* create_linked_list() {
    linked_list_t* list = malloc(sizeof(linked_list_t));
    list->head = NULL;
    return list;
}

int linked_list_count(linked_list_t* list) {
    if (list->head == NULL) {
        return 0;
    }

    int count = 1;
    linked_list_node_t* iter = list->head;
    while (iter->next != NULL) {
        count = count + 1;
        iter = iter->next;
    }

    return count;
}

linked_list_node_t* linked_list_last(linked_list_t* list) {
    if (list->head == NULL) {
        return NULL;
    }

    linked_list_node_t* iter = list->head;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    return iter;
}

void linked_list_push(linked_list_t* list, linked_list_node_t* node) {
    if (list->head == NULL) {
        list->head = node;
        return;
    }

    linked_list_node_t* iter = list->head;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    iter->next = node;
}

linked_list_node_t* linked_list_pop(linked_list_t* list) {
    if (list->head->next == NULL) {
        linked_list_node_t* node = list->head;
        list->head = NULL;
        return node;
    }

    linked_list_node_t* prev = list->head;
    linked_list_node_t* iter = list->head->next;
    while (iter->next != NULL) {
        prev = iter;
        iter = iter->next;
    }

    list->head = prev;
    list->head->next = NULL;
    return iter;
}
