#include "double_linked_list.h"
#include "list_item.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

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
            tail->node.next = (DLIST_NODE)item;                                \
        }                                                          \
        item->node.prev = (DLIST_NODE)tail;                                    \
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

#define pop(typename)                           \
    typename *pop_##typename(typename * *head)  \
    {                                           \
        typename *current_head = *head;         \
        if (!current_head)                      \
        {                                       \
            return NULL;                        \
        }                                       \
        *head = (typename *)((*head)->node.next); \
        current_head->node.next = NULL;         \
        if (*head)                              \
        {                                       \
                                                \
            (*head)->node.prev = NULL;          \
        }                                       \
        return current_head;                    \
    }

#define remove(typename)                                           \
    typename *remove_##typename(typename * *head, typename * item) \
    {                                                              \
                                                                   \
        if (!contains_##typename(head, item))                  \
        {                                                          \
                                                                   \
            if (item == *head)                                     \
            {                                                      \
                pop_##typename(head);                              \
            }                                                      \
            else if (item == getTail_##typename(head))             \
            {                                                      \
                typename *item_prev = (typename *)(item->node.prev);             \
                                                                   \
                item_prev->node.next = NULL;                       \
                item->node.prev = NULL;                            \
            }                                                      \
            else                                                   \
            {                                                      \
                typename *item_prev = (typename *)(item->node.prev);             \
                typename *item_next = (typename *)(item->node.next);             \
                                                                   \
                item_prev->node.next = item->node.next;            \
                item_next->node.prev = item->node.prev;            \
                                                                   \
                item->node.prev = NULL;                            \
                item->node.next = NULL;                            \
            }                                                      \
                                                                   \
            return item;                                           \
        }                                                          \
                                                                   \
        return NULL;                                               \
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
            typename *item_prev = (typename *)(item->node.prev);                   \
                                                                     \
            item_prev->node.next = NULL;                             \
            item->node.prev = NULL;                                  \
        }                                                            \
        else                                                         \
        {                                                            \
            typename *item_prev = (typename *)(item->node.prev);                   \
            typename *item_next = (typename *)(item->node.next);                   \
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
                item_to_insert->node.next = (DLIST_NODE)*head;                                                   \
                (*head)->node.prev = (DLIST_NODE)item_to_insert;                                                 \
                *head = item_to_insert;                                                              \
            }                                                                                        \
            else                                                                                     \
            {                                                                                        \
                typename *target_prev = (typename *)(target_item->node.prev);                        \
                target_item->node.prev = (DLIST_NODE)item_to_insert;                                             \
                item_to_insert->node.next = (DLIST_NODE)target_item;                                             \
                                                                                                     \
                item_to_insert->node.prev = (DLIST_NODE)target_prev;                                             \
                target_prev->node.next = (DLIST_NODE)item_to_insert;                                             \
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
                target_item->node.next = (DLIST_NODE)item_to_insert;                                            \
                item_to_insert->node.prev = (DLIST_NODE)target_item;                                            \
                                                                                                    \
                item_to_insert->node.next = (DLIST_NODE)target_next;                                            \
                target_next->node.prev = (DLIST_NODE)item_to_insert;                                            \
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
        typename *result = NULL;                                        \
        typename *current_node = NULL;                                  \
        typename *random_node = NULL;                                   \
                                                                        \
        time_t t = time(NULL);                                          \
        srand(t);                                                       \
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
                    r_prev->node.next = (DLIST_NODE)current_node;                   \
                }                                                       \
            }                                                           \
                                                                        \
            if (r_next)                                                 \
            {                                                           \
                r_next->node.prev = (DLIST_NODE)current_node;                       \
            }                                                           \
                                                                        \
            if (c_prev)                                                 \
            {                                                           \
                c_prev->node.next = (DLIST_NODE)random_node;                        \
            }                                                           \
                                                                        \
            if (c_next)                                                 \
            {                                                           \
                if (consec != 1)                                        \
                {                                                       \
                                                                        \
                    c_next->node.prev = (DLIST_NODE)random_node;                    \
                }                                                       \
            }                                                           \
                                                                        \
            if (consec == 1)                                            \
            {                                                           \
                current_node->node.prev = (DLIST_NODE)random_node;                  \
            }                                                           \
            else                                                        \
            {                                                           \
                current_node->node.prev = (DLIST_NODE)r_prev;                       \
            }                                                           \
                                                                        \
            current_node->node.next = (DLIST_NODE)r_next;                           \
                                                                        \
            random_node->node.prev = (DLIST_NODE)tmp_prev;                          \
                                                                        \
            if (consec == 1)                                            \
            {                                                           \
                random_node->node.next = (DLIST_NODE)current_node;                  \
            }                                                           \
            else                                                        \
            {                                                           \
                random_node->node.next = (DLIST_NODE)tmp_next;                      \
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

#define copyShuffle(typename)                                         \
    typename *copyShuffle_##typename(typename * *head)                \
    {                                                                 \
        typename *result = NULL;                                      \
        typename *current_node = NULL;                                \
        typename *current_node_new = NULL;                            \
        int size = count_##typename(head);                            \
                                                                      \
        time_t t = time(NULL);                                        \
        srand(t);                                                     \
                                                                      \
        while (count_##typename(head))                                \
        {                                                             \
            int r = rand() % count_##typename(head);                  \
                                                                      \
            current_node = getAt_##typename(head, r);                 \
            current_node_new = malloc(sizeof(typename));              \
                                                                      \
            memcpy(current_node_new, current_node, sizeof(typename)); \
                                                                      \
            current_node_new->node.prev = NULL;                       \
            current_node_new->node.next = NULL;                       \
                                                                      \
            if (count_##typename(head) == size)                       \
            {                                                         \
                                                                      \
                result = current_node_new;                            \
            }                                                         \
            else                                                      \
            {                                                         \
                append_##typename(&result, current_node_new);         \
            }                                                         \
                                                                      \
            removeAt_##typename(head, r);                             \
            free(current_node);                                       \
        }                                                             \
                                                                      \
        return result;                                                \
    }

append(int_item);
append(float_item);
append(char_item);
append(size_t_item);
append(string_item);

getAt(int_item);
getAt(float_item);
getAt(char_item);
getAt(size_t_item);
getAt(string_item);

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

removeAt(int_item);
removeAt(float_item);
removeAt(char_item);
removeAt(size_t_item);
removeAt(string_item);

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

insertBefore(int_item);
insertBefore(float_item);
insertBefore(char_item);
insertBefore(size_t_item);
insertBefore(string_item);

insertAfter(int_item);
insertAfter(float_item);
insertAfter(char_item);
insertAfter(size_t_item);
insertAfter(string_item);

contains(int_item);
contains(float_item);
contains(char_item);
contains(size_t_item);
contains(string_item);

count(int_item);
count(float_item);
count(char_item);
count(size_t_item);
count(string_item);

shuffle(int_item);
shuffle(float_item);
shuffle(char_item);
shuffle(size_t_item);
shuffle(string_item);

copyShuffle(int_item);
copyShuffle(float_item);
copyShuffle(char_item);
copyShuffle(size_t_item);
copyShuffle(string_item);
