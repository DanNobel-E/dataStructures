#include "set.h"

size_t djb33x_hash(const char *key, const size_t keylen)
{
    size_t hash = 5381;
    for (size_t i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

set_table_t *set_table_new(const size_t hashmap_size)
{
    if (hashmap_size <= 0)
    {
        return NULL;
    }

    set_table_t *table = malloc(sizeof(set_table_t));
    if (!table)
    {
        return NULL;
    }
    table->hashmap_size = hashmap_size;
    table->nodes = calloc(table->hashmap_size, sizeof(set_node_t *));
    if (!table->nodes)
    {
        free(table);
        return NULL;
    }
    return table;
}

set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len)
{
    if (!table)
    {

        return NULL;
    }

    if (set_search(table, key, key_len))
    {
        return NULL;
    }

    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    set_node_t *head = table->nodes[index];
    table->nodes[table->hashmap_size]= NULL;
    char * key_copy= malloc(sizeof(char)*key_len);
    strcpy_s(key_copy,key_len+1,key);

    if (!head)
    {
        table->nodes[index] = malloc(sizeof(set_node_t));
        if (!table->nodes[index])
        {
            free(key_copy);
            return NULL;
        }
        table->nodes[index]->key = key_copy;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->next = NULL;
        return table->nodes[index];
    }

    set_node_t *new_item = malloc(sizeof(set_node_t));
    if (!new_item)
    {
        free(key_copy);
        return NULL;
    }
    
    new_item->key = key_copy;
    new_item->key_len = key_len;
    new_item->next = NULL;
    set_node_t *tail = head;
    while (head)
    {
        tail = head;
        head = head->next;
    }
    tail->next = new_item;
    return new_item;
}

set_node_t *set_search(set_table_t *table, const char *key, const size_t key_len)
{
    if (!table)
    {

        return NULL;
    }

    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    set_node_t *keylist_current_node = table->nodes[index];

    while (keylist_current_node)
    {

        if (!strcmp(key, keylist_current_node->key) && key_len == keylist_current_node->key_len)
        {

            return keylist_current_node;
        }

        keylist_current_node = keylist_current_node->next;
    }

    return NULL;
}

set_node_t *set_search_keyList_head(set_table_t *table, const char *key, const size_t key_len)
{
    if (!table)
    {

        return NULL;
    }

    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    set_node_t *keylist_head = table->nodes[index];

    return keylist_head;
}

set_node_t *set_remove(set_table_t *table, const char *key, const size_t key_len)
{

    set_node_t *key_node = set_search(table, key, key_len);

    if (!key_node)
    {

        return NULL;
    }

    set_node_t *keyList_head = set_search_keyList_head(table, key, key_len);
    set_node_t *prev_node = NULL;

    if (key_node == keyList_head)
    {

        size_t hash = djb33x_hash(key, key_len);
        size_t index = hash % table->hashmap_size;
        table->nodes[index] = key_node->next;
        key_node->next = NULL;
        return key_node;
    }

    while (keyList_head)
    {
        prev_node = keyList_head;
        keyList_head = keyList_head->next;
        if (key_node == keyList_head)
        {

            prev_node->next = key_node->next;
            key_node->next = NULL;
            return key_node;
        }
    }

    return NULL;
}

void set_print_keys(set_table_t *table)
{

    if (table)
    {
        for (int i = 0; i < table->hashmap_size; i++)
        {
            set_node_t *current_node = table->nodes[i];
            while (current_node)
            {
                printf("%s\n", current_node->key);
                current_node = current_node->next;
            }
        }
    }
}

void set_node_destroy(set_node_t **node_ptr)
{
    free((*node_ptr)->key);
    free(*node_ptr);
    *node_ptr = NULL;
}

void set_table_destroy(set_table_t **table_ptr)
{

    if (*table_ptr)
    {

        for (int i = 0; i < (*table_ptr)->hashmap_size; i++)
        {
            set_node_t *current_node = (*table_ptr)->nodes[i];
            set_node_t *prev_node = NULL;

            while (current_node)
            {
                prev_node = current_node;
                current_node = current_node->next;
                set_node_destroy(&prev_node);
            }
        }
        free(*table_ptr);
        *table_ptr = NULL;
    }
}
