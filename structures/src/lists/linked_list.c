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

void linked_list_push(linked_list_t* list, linked_list_node_t* node) {
    if (list == NULL) {
        return;
    }
    if (node == NULL) {
        return;
    }

    linked_list_node_t* iter = list->head;
    if (iter == NULL) {
        list->head = node;
        return;
    } else {
        while (iter->next != NULL) {
            iter = iter->next;
        }
        iter->next = node;
    }
}

linked_list_node_t* linked_list_pop(linked_list_t* list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->head == NULL) {
        return NULL;
    }

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
