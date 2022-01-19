
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list.h"
#include "list_items.h"

int main()
{
    int_item *my_linked_list = NULL; // Init list

    int_item *items[5]; // Init items

    for (int i = 0; i < 5; i++)
    {
        items[i] = item_new(i, int_item);
        list_append(&my_linked_list, items[i], int_item);
    }

    item_print_list(my_linked_list, int_item);

    // invert list

    int_item *inverted_list = list_invert(&my_linked_list, int_item);

    item_print_list(my_linked_list, int_item);
    item_print_list(inverted_list, int_item);

    inverted_list = list_copy_and_invert(&my_linked_list, int_item);

    item_print_list(my_linked_list, int_item);
    item_print_list(inverted_list, int_item);

    // remove node from list

    list_remove(&my_linked_list, items[2], int_item);
    list_remove(&my_linked_list, items[0], int_item);
    list_remove(&my_linked_list, items[4], int_item);

    item_print_list(my_linked_list, int_item);

    list_destroy_item(&items[0],int_item);
    list_destroy_item(&items[2],int_item);
    list_destroy_item(&items[4],int_item);
    list_destroy(&inverted_list, int_item);
    list_destroy(&my_linked_list,int_item);


    return 0;
}