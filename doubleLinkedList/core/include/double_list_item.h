#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//defining structs signatures and fields
typedef struct double_list_node_t
{
    struct double_list_node_t *prev;
    struct double_list_node_t *next;
} double_list_node_t;

#define item_t(typename)         \
    struct item_##typename       \
    {                            \
        double_list_node_t node; \
        typename object;         \
    };

#define ptr_item_t(typename)     \
    struct item_ptr_##typename   \
    {                            \
        double_list_node_t node; \
        const typename *object;  \
    };

//defining structs implementation names
#define int_item struct item_int
#define float_item struct item_float
#define char_item struct item_char
#define size_t_item struct item_size_t
#define string_item struct item_ptr_char

//defining declarations signatures
#define declare_new(value, typename) \
    typename *new_##typename(value)

#define declare_printList(list_type, typename) \
    void printList_##typename(list_type)

//defining functions signatures
#define item_new(value, typename) new_##typename(value)
#define item_print_list(list, typename) printList_##typename(list)

//functions generic implementation
    #define new(value, typename)                       \
    typename *new_##typename(value v)              \
    {                                              \
        typename *item = malloc(sizeof(typename)); \
        if (!item)                                 \
        {                                          \
            return NULL;                           \
        }                                          \
        item->object = v;                          \
        item->node.next = NULL;                    \
        item->node.prev = NULL;                    \
        return item;                               \
    }

#define printList(list_type, typename)           \
    void printList_##typename(list_type * list)  \
    {                                            \
        list_type *item = list;                  \
        while (item)                             \
        {                                        \
            print_##typename(*item);             \
            item = (list_type *)item->node.next; \
        }                                        \
                                                 \
        printf("\n\n");                          \
    }


//struct definition
item_t(int);
item_t(float);
item_t(char);
item_t(size_t);

ptr_item_t(char);

//functions declarations
declare_new(int n, int_item);
declare_new(float f, float_item);
declare_new(char c, char_item);
declare_new(size_t n, size_t_item);
declare_new(const char *string, string_item);

declare_printList(int_item *list, int_item);
declare_printList(float_item *list, float_item);
declare_printList(char_item *list, char_item);
declare_printList(size_t_item *list, size_t_item);
declare_printList(string_item *list, string_item);

void print_int_item(int_item item);
void print_float_item(float_item item);
void print_char_item(char_item item);
void print_size_t_item(size_t_item item);
void print_string_item(string_item item);
