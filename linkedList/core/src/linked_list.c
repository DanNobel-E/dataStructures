#include "linked_list.h"
#include "list_items.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define append(typename)                                           \
    typename *append_##typename(typename * *head, typename * item) \
    {                                                              \
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

#define removeHead(typename)                    \
    int removeHead_##typename(typename * *head) \
    {                                           \
                                                \
        int result = -1;                        \
        if (pop_##typename(head) != NULL)       \
        {                                       \
            result = 0;                         \
        }                                       \
                                                \
        return result;                          \
    }

#define removeTail(typename)                    \
    int removeTail_##typename(typename * *head) \
    {                                           \
                                                \
        int result = -1;                        \
        if (getTail_##typename(head) != NULL)   \
        {                                       \
            result = 0;                         \
        }                                       \
                                                \
        return result;                          \
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

removeHead(int_item);
removeHead(float_item);
removeHead(char_item);
removeHead(size_t_item);
removeHead(string_item);

removeTail(int_item);
removeTail(float_item);
removeTail(char_item);
removeTail(size_t_item);
removeTail(string_item);

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
