#pragma once

#include "list_items.h"

#define LIST_NODE list_node_t *

#define list_append(head, item, typename) append_##typename(head, item)
#define list_get_tail(head, typename) getTail_##typename(head)
#define list_pop(head, typename) pop_##typename(head)
#define list_remove(head, item, typename) remove_##typename(head, item)
#define list_remove_head(head, typename) removeHead_##typename(head)
#define list_remove_tail(head, typename) removeTail_##typename(head)
#define list_invert(head, typename) invert_##typename(head)
#define list_copy_and_invert(head, typename) copyList_##typename(head)
#define list_destroy_item(item, typename) destroy_##typename(item)
#define list_destroy(head, typename) destroy_list_##typename(head)



#define declare_append(head, item, typename) \
    typename *append_##typename(head, item)

#define declare_getTail(head, typename) \
    typename *getTail_##typename(head)

#define declare_pop(head, typename) \
    typename *pop_##typename(head)

#define declare_remove(head, item, typename) \
    typename *remove_##typename(head, item)

#define declare_removeHead(head, typename) \
    int removeHead_##typename(head)

#define declare_removeTail(head, typename) \
    int removeTail_##typename(head)

#define declare_invert(head, typename) \
    typename *invert_##typename(head)

#define declare_copyList(head, typename) \
    typename *copyList_##typename(head)

#define declare_destroy_item(item, typename) \
    void destroy_##typename(item)
    
#define declare_destroy(head, typename) \
    void destroy_list_##typename(head)

declare_append(int_item **head, int_item *item, int_item);
declare_append(float_item **head, float_item *item, float_item);
declare_append(char_item **head, char_item *item, char_item);
declare_append(size_t_item **head, size_t_item *item, size_t_item);
declare_append(string_item **head, string_item *item, string_item);

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

declare_invert(int_item **head, int_item);
declare_invert(float_item **head, float_item);
declare_invert(char_item **head, char_item);
declare_invert(size_t_item **head, size_t_item);
declare_invert(string_item **head, string_item);

declare_copyList(int_item **head, int_item);
declare_copyList(float_item **head, float_item);
declare_copyList(char_item **head, char_item);
declare_copyList(size_t_item **head, size_t_item);
declare_copyList(string_item **head, string_item);

declare_destroy_item(int_item **item, int_item);
declare_destroy_item(float_item **item, float_item);
declare_destroy_item(char_item **item, char_item);
declare_destroy_item(size_t_item **item, size_t_item);
declare_destroy_item(string_item **item, string_item);

declare_destroy(int_item **head, int_item);
declare_destroy(float_item **head, float_item);
declare_destroy(char_item **head, char_item);
declare_destroy(size_t_item **head, size_t_item);
declare_destroy(string_item **head, string_item);
