#ifndef _LINKED_LIST_H__
#define _LINKED_LIST_H__

struct linked_list_node {
    struct linked_list_node* next;
    void* value;
};
typedef struct linked_list_node linked_list_node_t;

linked_list_node_t* create_linked_list_node(void* value);


struct linked_list {
    struct linked_list_node* head;
};
typedef struct linked_list linked_list_t;

linked_list_t* create_linked_list();


void linked_list_push(linked_list_t* list, linked_list_node_t* node);

linked_list_node_t* linked_list_pop(linked_list_t* list);

#endif
