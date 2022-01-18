
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"
#include "list_items.h"

int main()
{
    int_item *my_linked_list = NULL; // Init list

    int_item *items[5]; // Init items
    // const char *default_string = "Item_";
    // char default_string_buffer[5];
    // strcpy(default_string_buffer, default_string);
    // char index[2];
    // char result_strings[5][10];

    for (int i = 0; i < 5; i++)
    {
        // _itoa(i, index, 10);
        // strcpy(result_strings[i], default_string_buffer);
        // strcat(result_strings[i], index);
        items[i] = instantiate_item(i, int_item);
        list_append(&my_linked_list, items[i], int_item);
    }

    print_list(my_linked_list, int_item);

    // invert list

    int_item *inverted_list = list_invert(&my_linked_list, int_item);

    print_list(my_linked_list, int_item);
    print_list(inverted_list, int_item);

    inverted_list = list_copy_and_invert(&my_linked_list, int_item);

    print_list(my_linked_list, int_item);
    print_list(inverted_list, int_item);

    // remove node from list

    list_remove(&my_linked_list, items[2], int_item);
    list_remove(&my_linked_list, items[0], int_item);
    list_remove(&my_linked_list, items[4], int_item);

    print_list(my_linked_list, int_item);

    return 0;
}