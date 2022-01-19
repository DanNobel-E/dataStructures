#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define table_new(typename)                                                               \
    dictionary_table_##typename *table_new_##typename(size_t hashmap_size)                \
    {                                                                                     \
        dictionary_table_##typename *table = malloc(sizeof(dictionary_table_##typename)); \
        if (!table)                                                                       \
        {                                                                                 \
            return NULL;                                                                  \
        }                                                                                 \
        table->hashmap_size = hashmap_size;                                               \
        table->nodes = calloc(table->hashmap_size, sizeof(dictionary_node_##typename *)); \
        if (!table->nodes)                                                                \
        {                                                                                 \
            free(table);                                                                  \
            return NULL;                                                                  \
        }                                                                                 \
        return table;                                                                     \
    }

#define insert(typename)                                                                                                                      \
    dictionary_node_##typename *insert_##typename(dictionary_table_##typename * table, const char *key, const size_t key_len, typename value) \
    {                                                                                                                                         \
                                                                                                                                              \
        if (!table)                                                                                                                           \
        {                                                                                                                                     \
            return NULL;                                                                                                                      \
        }                                                                                                                                     \
                                                                                                                                              \
        if (search_##typename(table, key, key_len))                                                                                           \
        {                                                                                                                                     \
            return NULL;                                                                                                                      \
        }                                                                                                                                     \
                                                                                                                                              \
        size_t hash = dictionary_djb33x_hash(key, key_len);                                                                                   \
        size_t index = hash % table->hashmap_size;                                                                                            \
        dictionary_node_##typename *head = table->nodes[index];                                                                               \
        if (!head)                                                                                                                            \
        {                                                                                                                                     \
            table->nodes[index] = malloc(sizeof(dictionary_node_##typename));                                                                 \
            if (!table->nodes[index])                                                                                                         \
            {                                                                                                                                 \
                return NULL;                                                                                                                  \
            }                                                                                                                                 \
            table->nodes[index]->key = key;                                                                                                   \
            table->nodes[index]->key_len = key_len;                                                                                           \
            table->nodes[index]->object = value;                                                                                              \
            table->nodes[index]->next = NULL;                                                                                                 \
            return table->nodes[index];                                                                                                       \
        }                                                                                                                                     \
                                                                                                                                              \
        dictionary_node_##typename *new_item = malloc(sizeof(dictionary_node_##typename));                                                    \
        if (!new_item)                                                                                                                        \
        {                                                                                                                                     \
            return NULL;                                                                                                                      \
        }                                                                                                                                     \
        new_item->key = key;                                                                                                                  \
        new_item->key_len = key_len;                                                                                                          \
        new_item->object = value;                                                                                                             \
        new_item->next = NULL;                                                                                                                \
        dictionary_node_##typename *tail = head;                                                                                              \
        while (head)                                                                                                                          \
        {                                                                                                                                     \
            tail = head;                                                                                                                      \
            head = head->next;                                                                                                                \
        }                                                                                                                                     \
        tail->next = new_item;                                                                                                                \
        return new_item;                                                                                                                      \
    }

#define change_value(typename)                                                                                                                      \
    dictionary_node_##typename *change_value_##typename(dictionary_table_##typename * table, const char *key, const size_t key_len, typename value) \
    {                                                                                                                                               \
                                                                                                                                                    \
        dictionary_node_##typename *key_node = search_##typename(table, key, key_len);                                                              \
        if (key_node)                                                                                                                               \
        {                                                                                                                                           \
                                                                                                                                                    \
            key_node->object = value;                                                                                                               \
            return key_node;                                                                                                                        \
        }                                                                                                                                           \
                                                                                                                                                    \
        return NULL;                                                                                                                                \
    }

#define search(typename)                                                                                                      \
    dictionary_node_##typename *search_##typename(dictionary_table_##typename * table, const char *key, const size_t key_len) \
    {                                                                                                                         \
        if (!table)                                                                                                           \
        {                                                                                                                     \
            return NULL;                                                                                                      \
        }                                                                                                                     \
        size_t hash = dictionary_djb33x_hash(key, key_len);                                                                   \
        size_t index = hash % table->hashmap_size;                                                                            \
        dictionary_node_##typename *keylist_current_node = table->nodes[index];                                               \
                                                                                                                              \
        while (keylist_current_node)                                                                                          \
        {                                                                                                                     \
                                                                                                                              \
            if (!strcmp(key, keylist_current_node->key) && key_len == keylist_current_node->key_len)                          \
            {                                                                                                                 \
                                                                                                                              \
                return keylist_current_node;                                                                                  \
            }                                                                                                                 \
                                                                                                                              \
            keylist_current_node = keylist_current_node->next;                                                                \
        }                                                                                                                     \
                                                                                                                              \
        return NULL;                                                                                                          \
    }

#define search_head(typename)                                                                                                      \
    dictionary_node_##typename *search_head_##typename(dictionary_table_##typename * table, const char *key, const size_t key_len) \
    {                                                                                                                              \
        if (!table)                                                                                                                \
        {                                                                                                                          \
            return NULL;                                                                                                           \
        }                                                                                                                          \
        size_t hash = dictionary_djb33x_hash(key, key_len);                                                                        \
        size_t index = hash % table->hashmap_size;                                                                                 \
        dictionary_node_##typename *keylist_head = table->nodes[index];                                                            \
                                                                                                                                   \
        return keylist_head;                                                                                                       \
    }

#define remove(typename)                                                                                                      \
    dictionary_node_##typename *remove_##typename(dictionary_table_##typename * table, const char *key, const size_t key_len) \
    {                                                                                                                         \
                                                                                                                              \
        dictionary_node_##typename *key_node = search_##typename(table, key, key_len);                                        \
                                                                                                                              \
        if (!key_node)                                                                                                        \
        {                                                                                                                     \
                                                                                                                              \
            return NULL;                                                                                                      \
        }                                                                                                                     \
                                                                                                                              \
        dictionary_node_##typename *keyList_head = search_head_##typename(table, key, key_len);                               \
        dictionary_node_##typename *prev_node = NULL;                                                                         \
                                                                                                                              \
        if (key_node == keyList_head)                                                                                         \
        {                                                                                                                     \
                                                                                                                              \
            size_t hash = dictionary_djb33x_hash(key, key_len);                                                               \
            size_t index = hash % table->hashmap_size;                                                                        \
            table->nodes[index] = key_node->next;                                                                             \
            key_node->next = NULL;                                                                                            \
            return key_node;                                                                                                  \
        }                                                                                                                     \
                                                                                                                              \
        while (keyList_head)                                                                                                  \
        {                                                                                                                     \
            prev_node = keyList_head;                                                                                         \
            keyList_head = keyList_head->next;                                                                                \
            if (key_node == keyList_head)                                                                                     \
            {                                                                                                                 \
                                                                                                                              \
                prev_node->next = key_node->next;                                                                             \
                key_node->next = NULL;                                                                                        \
                return key_node;                                                                                              \
            }                                                                                                                 \
        }                                                                                                                     \
                                                                                                                              \
        return NULL;                                                                                                          \
    }

#define print_keys(typename)                                                \
    void print_keys_##typename(dictionary_table_##typename * table)         \
    {                                                                       \
        if (table)                                                          \
        {                                                                   \
            for (int i = 0; i < table->hashmap_size; i++)                   \
            {                                                               \
                dictionary_node_##typename *current_node = table->nodes[i]; \
                while (current_node)                                        \
                {                                                           \
                    printf("Key: %s\n", current_node->key);                 \
                    current_node = current_node->next;                      \
                }                                                           \
            }                                                               \
        }                                                                   \
    }

#define print(typename)                                        \
    void print_##typename(dictionary_table_##typename * table) \
    {                                                          \
                                                               \
        print_keys_##typename(table);                          \
        dictionary_print_values_##typename(table);             \
    }

#define destory_node(typename)                                           \
    void destroy_node_##typename(dictionary_node_##typename * *node_ptr) \
    {                                                                    \
        free(*node_ptr);                                                 \
        *node_ptr = NULL;                                                \
    }

#define destory_table(typename)                                                    \
    void destroy_table_##typename(dictionary_table_##typename * *table_ptr)        \
    {                                                                              \
        if (*table_ptr)                                                            \
        {                                                                          \
                                                                                   \
            for (int i = 0; i < (*table_ptr)->hashmap_size; i++)                   \
            {                                                                      \
                dictionary_node_##typename *current_node = (*table_ptr)->nodes[i]; \
                dictionary_node_##typename *prev_node = NULL;                      \
                while (current_node)                                               \
                {                                                                  \
                    prev_node = current_node;                                      \
                    current_node = current_node->next;                             \
                    destroy_node_##typename(&prev_node);                           \
                }                                                                  \
            }                                                                      \
                                                                                   \
            free(*table_ptr);                                                      \
            *table_ptr = NULL;                                                     \
        }                                                                          \
    }

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
