#include "linked_list.h"
#include "test_utilities.h"

#include <stdio.h>

int test_list_create_list() {
    linked_list_t* list = create_linked_list();

    RETURN_ERROR_IF_FALSE(list != NULL);
    RETURN_ERROR_IF_FALSE(list->head == NULL);

    return SUCCESS;
}

int test_list_create_list_node() {
    linked_list_node_t* node = create_linked_list_node(NULL);

    RETURN_ERROR_IF_FALSE(node != NULL);
    RETURN_ERROR_IF_FALSE(node->next == NULL);
    RETURN_ERROR_IF_FALSE(node->value == NULL);

    return SUCCESS;
}

int test_list_push_from_empty() {
    linked_list_t* list = create_linked_list();
    linked_list_node_t* node = create_linked_list_node(NULL);
    linked_list_push(list, node);

    RETURN_ERROR_IF_FALSE(list->head != NULL);
    RETURN_ERROR_IF_FALSE(list->head->next == NULL);
    RETURN_ERROR_IF_FALSE(list->head->value == NULL);

    return SUCCESS;
}

int test_list_push_two() {
    linked_list_t* list = create_linked_list();
    linked_list_node_t* node1 = create_linked_list_node(NULL);
    linked_list_node_t* node2 = create_linked_list_node(NULL);
    linked_list_push(list, node1);
    linked_list_push(list, node2);

    RETURN_ERROR_IF_FALSE(list->head != NULL);
    RETURN_ERROR_IF_FALSE(list->head == node1);
    RETURN_ERROR_IF_FALSE(list->head->next != NULL);
    RETURN_ERROR_IF_FALSE(list->head->next == node2);
    RETURN_ERROR_IF_FALSE(list->head->value == NULL);
    RETURN_ERROR_IF_FALSE(list->head->next->value == NULL);

    return SUCCESS;
}

int test_list_push_one_pop_one() {
    linked_list_t* list = create_linked_list();
    linked_list_node_t* node = create_linked_list_node(NULL);
    linked_list_push(list, node);
    linked_list_node_t* returned_node = linked_list_pop(list);

    RETURN_ERROR_IF_FALSE(list != NULL);
    RETURN_ERROR_IF_FALSE(list->head == NULL);
    RETURN_ERROR_IF_FALSE(returned_node == node);
    RETURN_ERROR_IF_FALSE(node->next == NULL);
}

int main(int argc, char *argv[])
{
    RETURN_ERROR_IF_FAILED(test_list_create_list());
    RETURN_ERROR_IF_FAILED(test_list_create_list_node());
    RETURN_ERROR_IF_FAILED(test_list_push_from_empty());
    RETURN_ERROR_IF_FAILED(test_list_push_two());
    RETURN_ERROR_IF_FAILED(test_list_push_one_pop_one());

    return SUCCESS;
}
