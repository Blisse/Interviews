#include "linked_list.h"

#include <stdio.h>
#include <stdbool.h>

int assert_true(bool condition) {
    if (condition) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int result = 0;

    linked_list_t* list = create_linked_list();

    result |= assert_true(list->head == NULL);

    if (result == 0) {
        printf("Failed tests.");
        return 0;
    }
    return 1;
}
