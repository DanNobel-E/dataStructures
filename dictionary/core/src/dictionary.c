#include "dictionary.h"

//functions implementation
table_new(int);
table_new(float);
table_new(char);
table_new(size_t);
table_new(string);

insert(int);
insert(float);
insert(char);
insert(size_t);
insert(string);

change_value(int);
change_value(float);
change_value(char);
change_value(size_t);
change_value(string);

search(int);
search(float);
search(char);
search(size_t);
search(string);

search_head(int);
search_head(float);
search_head(char);
search_head(size_t);
search_head(string);

remove(int);
remove(float);
remove(char);
remove(size_t);
remove(string);

print_keys(int);
print_keys(float);
print_keys(char);
print_keys(size_t);
print_keys(string);

print(int);
print(float);
print(char);
print(size_t);
print(string);

destory_node(int);
destory_node(float);
destory_node(char);
destory_node(size_t);
destory_node(string);

destory_table(int);
destory_table(float);
destory_table(char);
destory_table(size_t);
destory_table(string);

size_t dictionary_djb33x_hash(const char *key, const size_t keylen)
{
    size_t hash = 5381;
    for (size_t i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

void dictionary_print_values_int(int_table *table)
{
    if (table)
    {
        for (int i = 0; i < table->hashmap_size; i++)
        {
            dictionary_node_int *current_node = table->nodes[i];
            while (current_node)
            {
                printf("Value: %d\n", current_node->object);
                current_node = current_node->next;
            }
        }
    }
}

void dictionary_print_values_float(float_table *table)
{
    if (table)
    {
        for (int i = 0; i < table->hashmap_size; i++)
        {
            dictionary_node_float *current_node = table->nodes[i];
            while (current_node)
            {
                printf("Value: %f\n", current_node->object);
                current_node = current_node->next;
            }
        }
    }
}

void dictionary_print_values_char(char_table *table)
{
    if (table)
    {
        for (int i = 0; i < table->hashmap_size; i++)
        {
            dictionary_node_char *current_node = table->nodes[i];
            while (current_node)
            {
                printf("Value: %c\n", current_node->object);
                current_node = current_node->next;
            }
        }
    }
}

void dictionary_print_values_size_t(size_t_table *table)
{
    if (table)
    {
        for (int i = 0; i < table->hashmap_size; i++)
        {
            dictionary_node_size_t *current_node = table->nodes[i];
            while (current_node)
            {
                printf("Value: %zu\n", current_node->object);
                current_node = current_node->next;
            }
        }
    }
}

void dictionary_print_values_string(string_table *table)
{

    if (table)
    {
        for (int i = 0; i < table->hashmap_size; i++)
        {
            dictionary_node_string *current_node = table->nodes[i];
            while (current_node)
            {
                printf("Value: %s\n", current_node->object);
                current_node = current_node->next;
            }
        }
    }
}
