#pragma once

#include <stdlib.h>

#define string const char *

#define dictionary_node_t(typename)              \
    typedef struct dictionary_node_##typename    \
    {                                            \
        const char *key;                         \
        size_t key_len;                          \
        struct dictionary_node_##typename *next; \
        typename object;                         \
    }                                            \
    dictionary_node_##typename;

#define dictionary_table_t(typename)           \
    typedef struct dictionary_table_##typename \
    {                                          \
        dictionary_node_##typename **nodes;    \
        size_t hashmap_size;                   \
    }                                          \
    dictionary_table_##typename;

#define int_table dictionary_table_int
#define float_table dictionary_table_float
#define char_table dictionary_table_char
#define size_t_table dictionary_table_size_t
#define string_table dictionary_table_string

#define int_node dictionary_node_int
#define float_node dictionary_node_float
#define char_node dictionary_node_char
#define size_t_node dictionary_node_size_t
#define string_node dictionary_node_string

#define dictionary_table_new(size, typename) table_new_##typename(size);
#define dictionary_insert(table, key, key_len, value, typename) insert_##typename(table, key, key_len, value);
#define dictionary_change_value(table, key, key_len, value, typename) change_value_##typename(table, key, key_len, value);
#define dictionary_search(table, key, key_len, typename) search_##typename(table, key, key_len);
#define dictionary_search_keyList_head(table, key, key_len, typename) search_head_##typename(table, key, key_len);
#define dictionary_remove(table, key, key_len, typename) remove_##typename(table, key, key_len);
#define dictionary_print_keys(table, typename) print_keys_##typename(table);
#define dictionary_print(table, typename) print_##typename(table);
#define dictionary_destroy_node(node_ptr, typename) destroy_node_##typename(node_ptr);
#define dictionary_destroy_table(table_ptr, typename) destroy_table_##typename(table_ptr);

#define declare_table_new(size, typename) \
    dictionary_table_##typename *table_new_##typename(size);

#define declare_insert(table, key, key_len, value, typename) \
    dictionary_node_##typename *insert_##typename(table, key, key_len, value);

#define declare_change_value(table, key, key_len, value, typename) \
    dictionary_node_##typename *change_value_##typename(table, key, key_len, value);

#define declare_search(table, key, key_len, typename) \
    dictionary_node_##typename *search_##typename(table, key, key_len);

#define declare_search_head(table, key, key_len, typename) \
    dictionary_node_##typename *search_head_##typename(table, key, key_len);

#define declare_remove(table, key, key_len, typename) \
    dictionary_node_##typename *remove_##typename(table, key, key_len);

#define declare_print_keys(table, typename) \
    void print_keys_##typename(table);

#define declare_print(table, typename) \
    void print_##typename(table);

#define declare_destroy_node(node_ptr, typename) \
    void destroy_node_##typename(node_ptr);

#define declare_destroy_table(table_ptr, typename) \
    void destroy_table_##typename(table_ptr);

dictionary_node_t(int);
dictionary_node_t(float);
dictionary_node_t(char);
dictionary_node_t(size_t);
dictionary_node_t(string);

dictionary_table_t(int);
dictionary_table_t(float);
dictionary_table_t(char);
dictionary_table_t(size_t);
dictionary_table_t(string);

size_t dictionary_djb33x_hash(const char *key, const size_t keylen);

declare_table_new(const size_t hashmap_size, int);
declare_table_new(const size_t hashmap_size, float);
declare_table_new(const size_t hashmap_size, char);
declare_table_new(const size_t hashmap_size, size_t);
declare_table_new(const size_t hashmap_size, string);

declare_insert(int_table *table, const char *key, const size_t key_len, int value, int);
declare_insert(float_table *table, const char *key, const size_t key_len, float value, float);
declare_insert(char_table *table, const char *key, const size_t key_len, char value, char);
declare_insert(size_t_table *table, const char *key, const size_t key_len, size_t value, size_t);
declare_insert(string_table *table, const char *key, const size_t key_len, string vaue, string);

declare_change_value(int_table *table, const char *key, const size_t key_len, int value, int);
declare_change_value(float_table *table, const char *key, const size_t key_len, float value, float);
declare_change_value(char_table *table, const char *key, const size_t key_len, char value, char);
declare_change_value(size_t_table *table, const char *key, const size_t key_len, size_t value, size_t);
declare_change_value(string_table *table, const char *key, const size_t key_len, string vaue, string);

declare_search(int_table *table, const char *key, const size_t key_len, int);
declare_search(float_table *table, const char *key, const size_t key_len, float);
declare_search(char_table *table, const char *key, const size_t key_len, char);
declare_search(size_t_table *table, const char *key, const size_t key_len, size_t);
declare_search(string_table *table, const char *key, const size_t key_len, string);

declare_search_head(int_table *table, const char *key, const size_t key_len, int);
declare_search_head(float_table *table, const char *key, const size_t key_len, float);
declare_search_head(char_table *table, const char *key, const size_t key_len, char);
declare_search_head(size_t_table *table, const char *key, const size_t key_len, size_t);
declare_search_head(string_table *table, const char *key, const size_t key_len, string);

declare_remove(int_table *table, const char *key, const size_t key_len, int);
declare_remove(float_table *table, const char *key, const size_t key_len, float);
declare_remove(char_table *table, const char *key, const size_t key_len, char);
declare_remove(size_t_table *table, const char *key, const size_t key_len, size_t);
declare_remove(string_table *table, const char *key, const size_t key_len, string);

declare_print_keys(int_table *table, int);
declare_print_keys(float_table *table, float);
declare_print_keys(char_table *table, char);
declare_print_keys(size_t_table *table, size_t);
declare_print_keys(string_table *table, string);

void dictionary_print_values_int(int_table *table);
void dictionary_print_values_float(float_table *table);
void dictionary_print_values_char(char_table *table);
void dictionary_print_values_size_t(size_t_table *table);
void dictionary_print_values_string(string_table *table);

declare_print(int_table *table, int);
declare_print(float_table *table, float);
declare_print(char_table *table, char);
declare_print(size_t_table *table, size_t);
declare_print(string_table *table, string);

declare_destroy_node(int_node **node_ptr, int);
declare_destroy_node(float_node **node_ptr, float);
declare_destroy_node(char_node **node_ptr, char);
declare_destroy_node(size_t_node **node_ptr, size_t);
declare_destroy_node(string_node **node_ptr, string);

declare_destroy_table(int_table **table_ptr, int);
declare_destroy_table(float_table **table_ptr, float);
declare_destroy_table(char_table **table_ptr, char);
declare_destroy_table(size_t_table **table_ptr, size_t);
declare_destroy_table(string_table **table_ptr, string);

