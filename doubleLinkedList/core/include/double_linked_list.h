#pragma once

#include "double_list_item.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

#define DLIST_NODE double_list_node_t *

//defining declarations signatures
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

    #define declare_destroy_item(item, typename) \
    void destroy_##typename(item)
    
#define declare_destroy(head, typename) \
    void destroy_list_##typename(head)

//defining functions signatures
#define dlist_append(head, item, typename) append_##typename(head, item)
#define dlist_get_element_at(head, index, typename) getAt_##typename(head, index)
#define dlist_get_tail(head, typename) getTail_##typename(head)
#define dlist_pop(head, typename) pop_##typename(head)
#define dlist_remove(head, item, typename) remove_##typename(head, item)
#define dlist_remove_at(head, index, typename) removeAt_##typename(head, index)
#define dlist_insert_before(head, target_item, item_to_insert, typename) insertBefore_##typename(head, target_item, item_to_insert)
#define dlist_insert_after(head, target_item, item_to_insert, typename) insertAfter_##typename(head, target_item, item_to_insert)
#define dlist_contains(head, item, typename) contains_##typename(head, item)
#define dlist_count(head, typename) count_##typename(head)
#define dlist_shuffle(head, typename) shuffle_##typename(head)
#define dlist_destroy_item(item, typename) destroy_##typename(item)
#define dlist_destroy(head, typename) destroy_list_##typename(head)

//functions generic implementation
#define append(typename)                                           \
    typename *append_##typename(typename * *head, typename * item) \
    {                                                              \
        if (!item)                                                 \
        {                                                          \
            return NULL;                                           \
        }                                                          \
        typename *tail = getTail_##typename(head);                 \
        if (!tail)                                                 \
        {                                                          \
            *head = item;                                          \
        }                                                          \
        else                                                       \
        {                                                          \
            tail->node.next = (DLIST_NODE)item;                    \
        }                                                          \
        item->node.prev = (DLIST_NODE)tail;                        \
        item->node.next = NULL;                                    \
        return item;                                               \
    }

#define getAt(typename)                                           \
    typename *getAt_##typename(typename * *head, const int index) \
    {                                                             \
                                                                  \
        if (index < 0 || index >= count_##typename(head))         \
        {                                                         \
                                                                  \
            return NULL;                                          \
        }                                                         \
                                                                  \
        int counter = 0;                                          \
        typename *current_node = *head;                           \
                                                                  \
        while (counter != index)                                  \
        {                                                         \
            current_node = (typename *)(current_node->node.next); \
            counter++;                                            \
        }                                                         \
                                                                  \
        return current_node;                                      \
    }

#define getTail(typename)                                         \
    typename *getTail_##typename(typename * *head)                \
    {                                                             \
        typename *current_node = *head;                           \
        typename *last_node = NULL;                               \
        while (current_node)                                      \
        {                                                         \
            last_node = current_node;                             \
            current_node = (typename *)(current_node->node.next); \
        }                                                         \
        return last_node;                                         \
    }

#define pop(typename)                             \
    typename *pop_##typename(typename * *head)    \
    {                                             \
        typename *current_head = *head;           \
        if (!current_head)                        \
        {                                         \
            return NULL;                          \
        }                                         \
        *head = (typename *)((*head)->node.next); \
        current_head->node.next = NULL;           \
        if (*head)                                \
        {                                         \
                                                  \
            (*head)->node.prev = NULL;            \
        }                                         \
        return current_head;                      \
    }

#define remove(typename)                                             \
    typename *remove_##typename(typename * *head, typename * item)   \
    {                                                                \
                                                                     \
        if (!contains_##typename(head, item))                        \
        {                                                            \
                                                                     \
            if (item == *head)                                       \
            {                                                        \
                pop_##typename(head);                                \
            }                                                        \
            else if (item == getTail_##typename(head))               \
            {                                                        \
                typename *item_prev = (typename *)(item->node.prev); \
                                                                     \
                item_prev->node.next = NULL;                         \
                item->node.prev = NULL;                              \
            }                                                        \
            else                                                     \
            {                                                        \
                typename *item_prev = (typename *)(item->node.prev); \
                typename *item_next = (typename *)(item->node.next); \
                                                                     \
                item_prev->node.next = item->node.next;              \
                item_next->node.prev = item->node.prev;              \
                                                                     \
                item->node.prev = NULL;                              \
                item->node.next = NULL;                              \
            }                                                        \
                                                                     \
            return item;                                             \
        }                                                            \
                                                                     \
        return NULL;                                                 \
    }

#define removeAt(typename)                                           \
    typename *removeAt_##typename(typename * *head, const int index) \
    {                                                                \
                                                                     \
        typename *item = getAt_##typename(head, index);              \
                                                                     \
        if (!item)                                                   \
        {                                                            \
                                                                     \
            return item;                                             \
        }                                                            \
                                                                     \
        if (item == *head)                                           \
        {                                                            \
            pop_##typename(head);                                    \
        }                                                            \
        else if (item == getTail_##typename(head))                   \
        {                                                            \
            typename *item_prev = (typename *)(item->node.prev);     \
                                                                     \
            item_prev->node.next = NULL;                             \
            item->node.prev = NULL;                                  \
        }                                                            \
        else                                                         \
        {                                                            \
            typename *item_prev = (typename *)(item->node.prev);     \
            typename *item_next = (typename *)(item->node.next);     \
                                                                     \
            item_prev->node.next = item->node.next;                  \
            item_next->node.prev = item->node.prev;                  \
                                                                     \
            item->node.prev = NULL;                                  \
            item->node.next = NULL;                                  \
        }                                                            \
                                                                     \
        return item;                                                 \
    }

#define insertBefore(typename)                                                                       \
    int insertBefore_##typename(typename * *head, typename * target_item, typename * item_to_insert) \
    {                                                                                                \
                                                                                                     \
        if (!contains_##typename(head, item_to_insert))                                              \
        {                                                                                            \
            return -1;                                                                               \
        }                                                                                            \
                                                                                                     \
        if (!contains_##typename(head, target_item))                                                 \
        {                                                                                            \
            if (target_item == *head)                                                                \
            {                                                                                        \
                item_to_insert->node.prev = NULL;                                                    \
                item_to_insert->node.next = (DLIST_NODE)*head;                                       \
                (*head)->node.prev = (DLIST_NODE)item_to_insert;                                     \
                *head = item_to_insert;                                                              \
            }                                                                                        \
            else                                                                                     \
            {                                                                                        \
                typename *target_prev = (typename *)(target_item->node.prev);                        \
                target_item->node.prev = (DLIST_NODE)item_to_insert;                                 \
                item_to_insert->node.next = (DLIST_NODE)target_item;                                 \
                                                                                                     \
                item_to_insert->node.prev = (DLIST_NODE)target_prev;                                 \
                target_prev->node.next = (DLIST_NODE)item_to_insert;                                 \
            }                                                                                        \
                                                                                                     \
            return 0;                                                                                \
        }                                                                                            \
                                                                                                     \
        return -1;                                                                                   \
    }

#define insertAfter(typename)                                                                       \
    int insertAfter_##typename(typename * *head, typename * target_item, typename * item_to_insert) \
    {                                                                                               \
                                                                                                    \
        if (!contains_##typename(head, item_to_insert))                                             \
        {                                                                                           \
            return -1;                                                                              \
        }                                                                                           \
                                                                                                    \
        if (!contains_##typename(head, target_item))                                                \
        {                                                                                           \
            if (target_item == getTail_##typename(head))                                            \
            {                                                                                       \
                append_##typename(head, item_to_insert);                                            \
            }                                                                                       \
            else                                                                                    \
            {                                                                                       \
                typename *target_next = (typename *)(target_item->node.next);                       \
                target_item->node.next = (DLIST_NODE)item_to_insert;                                \
                item_to_insert->node.prev = (DLIST_NODE)target_item;                                \
                                                                                                    \
                item_to_insert->node.next = (DLIST_NODE)target_next;                                \
                target_next->node.prev = (DLIST_NODE)item_to_insert;                                \
            }                                                                                       \
                                                                                                    \
            return 0;                                                                               \
        }                                                                                           \
                                                                                                    \
        return -1;                                                                                  \
    }

#define contains(typename)                                        \
    int contains_##typename(typename * *head, typename * item)    \
    {                                                             \
                                                                  \
        typename *current_node = *head;                           \
                                                                  \
        while (current_node)                                      \
        {                                                         \
            if (current_node == item)                             \
            {                                                     \
                return 0;                                         \
            }                                                     \
                                                                  \
            current_node = (typename *)(current_node->node.next); \
        }                                                         \
        return -1;                                                \
    }

#define count(typename)                                           \
    int count_##typename(typename * *head)                        \
    {                                                             \
                                                                  \
        int result = 0;                                           \
        typename *current_node = *head;                           \
                                                                  \
        while (current_node)                                      \
        {                                                         \
            result++;                                             \
            current_node = (typename *)(current_node->node.next); \
        }                                                         \
                                                                  \
        return result;                                            \
    }

#define shuffle(typename)                                               \
    typename *shuffle_##typename(typename * *head)                      \
    {                                                                   \
        if (count_##typename(head) == 1)                                \
        {                                                               \
            return *head;                                               \
        }                                                               \
                                                                        \
        typename *result = NULL;                                        \
        typename *current_node = NULL;                                  \
        typename *random_node = NULL;                                   \
                                                                        \
        const int size = count_##typename(head);                        \
        for (int i = 0; i < size - 1; i++)                              \
        {                                                               \
                                                                        \
            int r = rand() % ((size - 1) - i);                          \
            current_node = getAt_##typename(head, i);                   \
            random_node = getAt_##typename(head, i + 1 + r);            \
                                                                        \
            typename *tmp_prev = (typename *)(current_node->node.prev); \
            typename *tmp_next = (typename *)(current_node->node.next); \
                                                                        \
            typename *c_prev = (typename *)(current_node->node.prev);   \
            typename *c_next = (typename *)(current_node->node.next);   \
                                                                        \
            typename *r_prev = (typename *)(random_node->node.prev);    \
            typename *r_next = (typename *)(random_node->node.next);    \
                                                                        \
            int consec = (r + 1 + i) - i;                               \
                                                                        \
            if (r_prev)                                                 \
            {                                                           \
                if (consec != 1)                                        \
                {                                                       \
                    r_prev->node.next = (DLIST_NODE)current_node;       \
                }                                                       \
            }                                                           \
                                                                        \
            if (r_next)                                                 \
            {                                                           \
                r_next->node.prev = (DLIST_NODE)current_node;           \
            }                                                           \
                                                                        \
            if (c_prev)                                                 \
            {                                                           \
                c_prev->node.next = (DLIST_NODE)random_node;            \
            }                                                           \
                                                                        \
            if (c_next)                                                 \
            {                                                           \
                if (consec != 1)                                        \
                {                                                       \
                                                                        \
                    c_next->node.prev = (DLIST_NODE)random_node;        \
                }                                                       \
            }                                                           \
                                                                        \
            if (consec == 1)                                            \
            {                                                           \
                current_node->node.prev = (DLIST_NODE)random_node;      \
            }                                                           \
            else                                                        \
            {                                                           \
                current_node->node.prev = (DLIST_NODE)r_prev;           \
            }                                                           \
                                                                        \
            current_node->node.next = (DLIST_NODE)r_next;               \
                                                                        \
            random_node->node.prev = (DLIST_NODE)tmp_prev;              \
                                                                        \
            if (consec == 1)                                            \
            {                                                           \
                random_node->node.next = (DLIST_NODE)current_node;      \
            }                                                           \
            else                                                        \
            {                                                           \
                random_node->node.next = (DLIST_NODE)tmp_next;          \
            }                                                           \
                                                                        \
            if (i == 0)                                                 \
            {                                                           \
                                                                        \
                *head = random_node;                                    \
                result = *head;                                         \
            }                                                           \
        }                                                               \
        return result;                                                  \
    }

#define destroy_item(typename)                \
    void destroy_##typename(typename * *item) \
    {                                         \
        if (*item)                            \
        {                                     \
            free(*item);                      \
            *item = NULL;                     \
        }                                     \
    }

#define destroy(typename)                                             \
    void destroy_list_##typename(typename * *head)                    \
    {                                                                 \
        if (*head)                                                    \
        {                                                             \
            typename *current_node = *head;                           \
            typename *prev_node = NULL;                               \
            while (current_node)                                      \
            {                                                         \
                                                                      \
                prev_node = current_node;                             \
                current_node = (typename *)(current_node->node.next); \
                destroy_##typename(&prev_node);                       \
            }                                                         \
                                                                      \
            *head = NULL;                                             \
        }                                                             \
    }

//functions declarations
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

declare_shuffle(int_item **head, int_item);
declare_shuffle(float_item **head, float_item);
declare_shuffle(char_item **head, char_item);
declare_shuffle(size_t_item **head, size_t_item);
declare_shuffle(string_item **head, string_item);

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
