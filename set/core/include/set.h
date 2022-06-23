#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct set_node_t
{
 const char *key;
 size_t key_len;
 struct set_node_t *next;
}set_node_t;

typedef struct set_table_t
{
 set_node_t **nodes;
 size_t hashmap_size ;
}set_table_t;

/*
 *returns an hashing value of the given string, following djb33x algorithm
 *@return hash value of the current key.
 *
 *@param key key string to hash.
 *@param keylen length in byte of the key to hash.
 */
size_t set_djb33x_hash(const char *key, const size_t keylen);

/*
 *generates a set table of hashmap_size node lists.
 *@return a pointer to generated set table.
 *
 *@param hashmap_size size used to clamp hashmap values. New table will count hashmap_size key lists.
 */
set_table_t *set_table_new (const size_t hashmap_size );

/*
 *Insterts a new key on given set table.
 *@return pointer to list node which contains the new key.
 *
 *@param table pointer to set table where to insert new key.
 *@param key new key to insert.
 *@param keylen lenght in bytes of the new key.
 */
set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len);

/*
 *Searches if the given table contains the given key. 
 *@return pointer to list node of the searched key.
 *
 *@param table pointer to set table where to search given key.
 *@param key key to search for.
 *@param keylen lenght in bytes of the searched key.
 */
set_node_t *set_search(set_table_t *table,const char *key, const size_t key_len);

/*
 *
 *@return pointer to list head node of the searched key.
 *
 *@param table pointer to set table where to search key list head.
 *@param key key to search for.
 *@param keylen lenght in bytes of the searched key.
 */
set_node_t *set_search_keyList_head(set_table_t *table,const char *key, const size_t key_len);

/*
 *If current key is contained in given table, removes it and returns the related list node. 
 *@return pointer to list node of the removed key.
 *
 *@param table pointer to set table where to remove given key.
 *@param key key to remove.
 *@param keylen lenght in bytes of the key to remove.
 */
set_node_t *set_remove(set_table_t *table, const char *key, const size_t key_len);

/*
 *Frees memory allocated by the given set node.
 *
 *@param node_ptr pointer to set node to destroy.
 */
void set_node_destroy(set_node_t **node_ptr);

/*
 *Frees memory allocated by the given set table.
 *
 *@param table_ptr pointer to set table to destroy.
 */
void set_table_destroy(set_table_t **table_ptr);

/*
 *Prints all the keys in the given table.
 *
 *@param table table to print.
 */
void set_print_keys(set_table_t* table);

