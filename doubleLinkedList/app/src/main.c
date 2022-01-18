#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "double_linked_list.h"
#include "list_item.h"


int main()
{
    string_item *my_linked_list = NULL;

    string_item *items[5];
    const char *default_string = "Item_";
    char default_string_buffer[5];
    strcpy(default_string_buffer, default_string);
    char index[2];
    char result_strings[5][10];

    for (int i = 0; i < 5; i++)
    {
        _itoa(i, index, 10);
        strcpy(result_strings[i], default_string_buffer);
        strcat(result_strings[i], index);
        items[i] = instantiate_item(result_strings[i],string_item);
        list_append(&my_linked_list, items[i], string_item);
    }

    string_item *new_item_0 = instantiate_item("Item_5", string_item);
    string_item *new_item_1 = instantiate_item("Item_6",string_item);

    // Try list_contains
    if (!list_contains(&my_linked_list, new_item_0,string_item))
    {
        printf("Yes\n\n");
    }
    else
    {
        printf("No\n\n");
    }

    // Try insert after/before

    list_insert_before(&my_linked_list, items[0],new_item_0, string_item);
    list_insert_after(&my_linked_list, items[4], new_item_1, string_item);

    print_list(my_linked_list, string_item);

    // Try list_remove/remove_at

    list_remove(&my_linked_list, items[4], string_item);
    list_remove_at(&my_linked_list, 3, string_item);

    print_list(my_linked_list, string_item);

    // Try list_shuffle

    //string_item_t *shuffled_list = (string_item_t *)list_shuffle((double_list_node_t **)&my_linked_list);
    string_item *shuffled_list = list_shuffle(&my_linked_list, string_item);

    print_list(shuffled_list, string_item);

    return 0;
}