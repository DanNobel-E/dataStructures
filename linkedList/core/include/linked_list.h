#pragma once

#include "linked_list_item.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define LIST_NODE list_node_t *

//defining declarations signatures
#define declare_append(head, item, typename) \
    typename *append_##typename(head, item)

#define declare_getTail(head, typename) \
    typename *getTail_##typename(head)

#define declare_pop(head, typename) \
    typename *pop_##typename(head)

#define declare_remove(head, item, typename) \
    typename *remove_##typename(head, item)

#define declare_invert(head, typename) \
    typename *invert_##typename(head)

#define declare_copyList(head, typename) \
    typename *copyList_##typename(head)

#define declare_destroy_item(item, typename) \
    void destroy_##typename(item)

#define declare_destroy(head, typename) \
    void destroy_list_##typename(head)

//defining functions signatures
#define list_append(head, item, typename) append_##typename(head, item)
#define list_get_tail(head, typename) getTail_##typename(head)
#define list_pop(head, typename) pop_##typename(head)
#define list_remove(head, item, typename) remove_##typename(head, item)
#define list_invert(head, typename) invert_##typename(head)
#define list_copy_and_invert(head, typename) copyList_##typename(head)
#define list_destroy_item(item, typename) destroy_##typename(item)
#define list_destroy(head, typename) destroy_list_##typename(head)

//functions generic implementation
#define append(typename)                                           \
    typename *append_##typename(typename * *head, typename * item) \
    {                                                              \
                                                                   \
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
            tail->node.next = (LIST_NODE)item;                     \
        }                                                          \
        item->node.next = NULL;                                    \
        return item;                                               \
    }

#define getTail(typename)                                         \
    typename *getTail_##typename(typename * *head)                \
    {                                                             \
        typename *current_node = *head;                           \
        if (!current_node)                                        \
        {                                                         \
            return NULL;                                          \
        }                                                         \
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
        return current_head;                      \
    }

#define remove(typename)                                            \
    typename *remove_##typename(typename * *head, typename * item)  \
    {                                                               \
                                                                    \
        typename *current_node = *head;                             \
        typename *prev_node = NULL;                                 \
                                                                    \
        while (current_node)                                        \
        {                                                           \
                                                                    \
            if (current_node == item)                               \
            {                                                       \
                                                                    \
                if (current_node == *head)                          \
                {                                                   \
                    pop_##typename(head);                           \
                }                                                   \
                else if (current_node == getTail_##typename(head))  \
                {                                                   \
                                                                    \
                    prev_node->node.next = NULL;                    \
                }                                                   \
                else                                                \
                {                                                   \
                    prev_node->node.next = current_node->node.next; \
                    current_node->node.next = NULL;                 \
                }                                                   \
                                                                    \
                return current_node;                                \
            }                                                       \
                                                                    \
            prev_node = current_node;                               \
            current_node = (typename *)(current_node->node.next);   \
        }                                                           \
                                                                    \
        return NULL;                                                \
    }

#define invert(typename)                                       \
    typename *invert_##typename(typename * *head)              \
    {                                                          \
        typename *current_node = *head;                        \
        typename *prev_node = NULL;                            \
        typename *next_node = NULL;                            \
                                                               \
        while (current_node)                                   \
        {                                                      \
            next_node = (typename *)(current_node->node.next); \
            current_node->node.next = (LIST_NODE)prev_node;    \
            prev_node = current_node;                          \
            current_node = next_node;                          \
        }                                                      \
                                                               \
        (*head) = prev_node;                                   \
                                                               \
        return (*head);                                        \
    }

#define copyList(typename)                                            \
    typename *copyList_##typename(typename * *head)                   \
    {                                                                 \
        typename *result = NULL;                                      \
        typename *current_node = *head;                               \
        typename *current_node_new = malloc(sizeof(typename));        \
        typename *prev_node = NULL;                                   \
        typename *next_node = NULL;                                   \
                                                                      \
        while (current_node_new)                                      \
        {                                                             \
                                                                      \
            memcpy(current_node_new, current_node, sizeof(typename)); \
                                                                      \
            if (!(current_node->node.next))                           \
            {                                                         \
                next_node = NULL;                                     \
            }                                                         \
            else                                                      \
            {                                                         \
                next_node = malloc(sizeof(typename));                 \
            }                                                         \
                                                                      \
            current_node_new->node.next = (LIST_NODE)prev_node;       \
                                                                      \
            prev_node = current_node_new;                             \
                                                                      \
            current_node_new = next_node;                             \
                                                                      \
            current_node = (typename *)(current_node->node.next);     \
        }                                                             \
                                                                      \
        result = prev_node;                                           \
                                                                      \
        return result;                                                \
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
