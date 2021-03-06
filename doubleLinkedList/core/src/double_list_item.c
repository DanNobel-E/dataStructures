#include "double_list_item.h"

//functions implementation
new (int, int_item);
new (float, float_item);
new (char, char_item);
new (size_t, size_t_item);
new (const char *, string_item);

printList(int_item, int_item);
printList(float_item, float_item);
printList(char_item, char_item);
printList(size_t_item, size_t_item);
printList(string_item, string_item);

void print_int_item(int_item item)
{

    printf("%d\n", item.object);
}

void print_float_item(float_item item)
{

    printf("%f\n", item.object);
}

void print_char_item(char_item item)
{

    printf("%c\n", item.object);
}

void print_size_t_item(size_t_item item)
{

    printf("%zu\n", item.object);
}

void print_string_item(string_item item)
{

    printf("%s\n", item.object);
}