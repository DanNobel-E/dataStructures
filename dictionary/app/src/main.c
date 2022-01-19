
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dictionary.h"

int main()
{
    // init hashtable
    const size_t table_size = 2;
    int_table *table = dictionary_table_new(table_size,int);

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
        dictionary_insert(table, result_strings[i], strlen(result_strings[i]),i,int);
    }

    // Try to insert keys already inserted
    dictionary_insert(table, "Key_0", strlen(result_strings[0]),7,int);
    dictionary_insert(table, "Key_0", strlen(result_strings[0]),0,int);

    dictionary_print_keys(table,int);

    // Try search algo
    int_node *node = dictionary_search(table, "Key_f", strlen(result_strings[2]),int);
    if (node)
    {
        printf("\n%s\n", node->key);
    }

    int_node *head_node = dictionary_search_keyList_head(table, result_strings[7], strlen(result_strings[5]),int);
    if (head_node)
    {
        printf("\n%s\n", head_node->key);
    }

    // Try remove algo
    int_node *removed_node = dictionary_remove(table, result_strings[0], strlen(result_strings[0]),int);
    if (removed_node)
    {
        printf("\n%s\n\n", removed_node->key);
    }

    dictionary_print(table,int);

    return 0;
}