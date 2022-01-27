#include "linked_list.h"
#include "linked_list_item.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

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

append(int_item);
append(float_item);
append(char_item);
append(size_t_item);
append(string_item);

getTail(int_item);
getTail(float_item);
getTail(char_item);
getTail(size_t_item);
getTail(string_item);

pop(int_item);
pop(float_item);
pop(char_item);
pop(size_t_item);
pop(string_item);

remove(int_item);
remove(float_item);
remove(char_item);
remove(size_t_item);
remove(string_item);

invert(int_item);
invert(float_item);
invert(char_item);
invert(size_t_item);
invert(string_item);

copyList(int_item);
copyList(float_item);
copyList(char_item);
copyList(size_t_item);
copyList(string_item);

destroy_item(int_item);
destroy_item(float_item);
destroy_item(char_item);
destroy_item(size_t_item);
destroy_item(string_item);

destroy(int_item);
destroy(float_item);
destroy(char_item);
destroy(size_t_item);
destroy(string_item);
