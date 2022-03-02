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
 *Check collision with level borders.
 *@return 0 value if collision happens.
 *
 *@param key
 *@param keylen
 */
size_t set_djb33x_hash(const char *key, const size_t keylen);

/*
 *Check collision with level borders.
 *@return 0 value if collision happens.
 *
 *@param hashmap_size
 */
set_table_t *set_table_new (const size_t hashmap_size );

/*
 *Check collision with level borders.
 *@return 0 value if collision happens.
 *
 *@param table
 *@param key
 *@param keylen
 */
set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len);

/*
 *Check collision with level borders.
 *@return 0 value if collision happens.
 *
 *@param table
 *@param key
 *@param keylen
 */
set_node_t *set_search(set_table_t *table,const char *key, const size_t key_len);

/*
 *Check collision with level borders.
 *@return 0 value if collision happens.
 *
 *@param table
 *@param key
 *@param keylen
 */
set_node_t *set_search_keyList_head(set_table_t *table,const char *key, const size_t key_len);

/*
 *Check collision with level borders.
 *@return 0 value if collision happens.
 *
 *@param table
 *@param key
 *@param keylen
 */
set_node_t *set_remove(set_table_t *table, const char *key, const size_t key_len);

/*
 *Check collision with level borders.
 *
 *@param node_ptr
 */
void set_node_destroy(set_node_t **node_ptr);

/*
 *Check collision with level borders.
 *
 *@param table_ptr
 */
void set_table_destroy(set_table_t **table_ptr);

/*
 *Check collision with level borders.
 *
 *@param table
 */
void set_print_keys(set_table_t* table);

