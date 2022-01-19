
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "set.h"

int main()
{
    // init hashtable
    const size_t table_size = 2;
    set_table_t *table = set_table_new(table_size);

    const char *default_string = "Key_";
    char default_string_buffer[4];
    strcpy(default_string_buffer, default_string);
    char index[2];
    char result_strings[10][10];

    for (int i = 0; i < 10; i++)
    {
        _itoa(i, index, 10);
        strcpy(result_strings[i], default_string_buffer);
        strcat(result_strings[i], index);
        set_insert(table, result_strings[i], strlen(result_strings[i]));
    }

    // Try to insert keys already inserted
    set_insert(table, "Key_0", strlen(result_strings[0]));
    set_insert(table, "Key_0", strlen(result_strings[0]));

    set_print_keys(table);

    // Try search algo
    set_node_t *node = set_search(table, "Key_f", strlen(result_strings[2]));
    if (node)
    {
        printf("\n%s\n", node->key);
    }

    set_node_t *head_node = set_search_keyList_head(table, result_strings[7], strlen(result_strings[5]));
    if (head_node)
    {
        printf("\n%s\n", head_node->key);
    }

    // Try remove algo
    set_node_t *removed_node = set_remove(table, result_strings[0], strlen(result_strings[0]));
    if (removed_node)
    {
        printf("\n%s\n\n", removed_node->key);
    }

    set_print_keys(table);

    set_node_destroy(&removed_node);
    set_table_destroy(&table);

    return 0;
}