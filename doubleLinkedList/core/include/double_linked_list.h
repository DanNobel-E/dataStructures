#pragma once

#include "list_item.h"

#define LIST_NODE double_list_node_t *

#define list_append(head, item, typename) append_##typename(head, item)
#define list_get_element_at(head, index, typename) getAt_##typename(head, index)
#define list_get_tail(head, typename) getTail_##typename(head)
#define list_pop(head, typename) pop_##typename(head)
#define list_remove(head, item, typename) remove_##typename(head, item)
#define list_remove_at(head, index, typename) removeAt_##typename(head, index)
#define list_remove_head(head, typename) removeHead_##typename(head)
#define list_remove_tail(head, typename) removeTail_##typename(head)
#define list_insert_before(head, target_item, item_to_insert, typename) insertBefore_##typename(head, target_item, item_to_insert)
#define list_insert_after(head, target_item, item_to_insert, typename) insertAfter_##typename(head, target_item, item_to_insert)
#define list_contains(head, item, typename) contains_##typename(head, item)
#define list_count(head, typename) count_##typename(head)
#define list_shuffle(head, typename) shuffle_##typename(head)
#define list_copy_and_shuffle(head, typename) copyShuffle_##typename(head)

#define declare_append(head, item, typename) \
    typename *append_##typename(head, item)

#define declare_getAt(head, index, typename) \
    typename *getAt_##typename(head, index)

#define declare_getTail(head, typename) \
    typename *getTail_##typename(head)

#define declare_pop(head, typename) \
    typename *pop_##typename(head)

#define declare_remove(head, item, typename) \
    typename *remove_##typename(head, item)

#define declare_removeAt(head, index, typename) \
    typename *removeAt_##typename(head, index)

#define declare_removeHead(head, typename) \
    int removeHead_##typename(head)

#define declare_removeTail(head, typename) \
    int removeTail_##typename(head)

#define declare_insertBefore(head, target_item, item_to_insert, typename) \
    int insertBefore_##typename(head, target_item, item_to_insert)

#define declare_insertAfter(head, target_item, item_to_insert, typename) \
    int insertAfter_##typename(head, target_item, item_to_insert)

#define declare_contains(head, item, typename) \
    int contains_##typename(head, item)

#define declare_count(head, typename) \
    int count_##typename(head)

#define declare_shuffle(head, typename) \
    typename *shuffle_##typename(head)

#define declare_copyShuffle(head, typename) \
    typename *copyShuffle_##typename(head)

declare_append(int_item **head, int_item *item, int_item);
declare_append(float_item **head, float_item *item, float_item);
declare_append(char_item **head, char_item *item, char_item);
declare_append(size_t_item **head, size_t_item *item, size_t_item);
declare_append(string_item **head, string_item *item, string_item);

declare_getAt(int_item **head, const int index, int_item);
declare_getAt(float_item **head, const int index, float_item);
declare_getAt(char_item **head, const int index, char_item);
declare_getAt(size_t_item **head, const int index, size_t_item);
declare_getAt(string_item **head, const int index, string_item);

declare_getTail(int_item **head, int_item);
declare_getTail(float_item **head, float_item);
declare_getTail(char_item **head, char_item);
declare_getTail(size_t_item **head, size_t_item);
declare_getTail(string_item **head, string_item);

declare_pop(int_item **head, int_item);
declare_pop(float_item **head, float_item);
declare_pop(char_item **head, char_item);
declare_pop(size_t_item **head, size_t_item);
declare_pop(string_item **head, string_item);

declare_remove(int_item **head, int_item *item, int_item);
declare_remove(float_item **head, float_item *item, float_item);
declare_remove(char_item **head, char_item *item, char_item);
declare_remove(size_t_item **head, size_t_item *item, size_t_item);
declare_remove(string_item **head, string_item *item, string_item);

declare_removeAt(int_item **head, const int index, int_item);
declare_removeAt(float_item **head, const int index, float_item);
declare_removeAt(char_item **head, const int index, char_item);
declare_removeAt(size_t_item **head, const int index, size_t_item);
declare_removeAt(string_item **head, const int index, string_item);

declare_removeHead(int_item **head, int_item);
declare_removeHead(float_item **head, float_item);
declare_removeHead(char_item **head, char_item);
declare_removeHead(size_t_item **head, size_t_item);
declare_removeHead(string_item **head, string_item);

declare_removeTail(int_item **head, int_item);
declare_removeTail(float_item **head, float_item);
declare_removeTail(char_item **head, char_item);
declare_removeTail(size_t_item **head, size_t_item);
declare_removeTail(string_item **head, string_item);

declare_insertBefore(int_item **head, int_item *target_item, int_item *item_to_insert, int_item);
declare_insertBefore(float_item **head, float_item *target_item, float_item *item_to_insert, float_item);
declare_insertBefore(char_item **head, char_item *target_item, char_item *item_to_insert, char_item);
declare_insertBefore(size_t_item **head, size_t_item *target_item, size_t_item *item_to_insert, size_t_item);
declare_insertBefore(string_item **head, string_item *target_item, string_item *item_to_insert, string_item);

declare_insertAfter(int_item **head, int_item *target_item, int_item *item_to_insert, int_item);
declare_insertAfter(float_item **head, float_item *target_item, float_item *item_to_insert, float_item);
declare_insertAfter(char_item **head, char_item *target_item, char_item *item_to_insert, char_item);
declare_insertAfter(size_t_item **head, size_t_item *target_item, size_t_item *item_to_insert, size_t_item);
declare_insertAfter(string_item **head, string_item *target_item, string_item *item_to_insert, string_item);

// double_list_node_t *list_append(double_list_node_t **head, double_list_node_t *item);

// double_list_node_t *list_get_element_at(double_list_node_t **head, const int index);

// double_list_node_t *list_get_tail(double_list_node_t **head);

// double_list_node_t *list_pop(double_list_node_t **head);

// double_list_node_t *list_remove(double_list_node_t **head, double_list_node_t *item);

// double_list_node_t *list_remove_at(double_list_node_t **head, const int index);

// int list_remove_head(double_list_node_t **head);

// int list_remove_tail(double_list_node_t **head);

// int list_insert_before(double_list_node_t **head, double_list_node_t *target_item, double_list_node_t *item_to_insert);

// int list_insert_after(double_list_node_t **head, double_list_node_t *target_item, double_list_node_t *item_to_insert);

// int list_contains(double_list_node_t **head, double_list_node_t *item);

declare_contains(int_item **head, int_item *item, int_item);
declare_contains(float_item **head, float_item *item, float_item);
declare_contains(char_item **head, char_item *item, char_item);
declare_contains(size_t_item **head, size_t_item *item, size_t_item);
declare_contains(string_item **head, string_item *item, string_item);

declare_count(int_item **head, int_item);
declare_count(float_item **head, float_item);
declare_count(char_item **head, char_item);
declare_count(size_t_item **head, size_t_item);
declare_count(string_item **head, string_item);

// int list_count(double_list_node_t **head);

declare_shuffle(int_item **head, int_item);
declare_shuffle(float_item **head, float_item);
declare_shuffle(char_item **head, char_item);
declare_shuffle(size_t_item **head, size_t_item);
declare_shuffle(string_item **head, string_item);

declare_copyShuffle(int_item **head, int_item);
declare_copyShuffle(float_item **head, float_item);
declare_copyShuffle(char_item **head, char_item);
declare_copyShuffle(size_t_item **head, size_t_item);
declare_copyShuffle(string_item **head, string_item);

// double_list_node_t *list_shuffle(double_list_node_t **head);

// double_list_node_t *list_copy_and_shuffle(double_list_node_t **head);