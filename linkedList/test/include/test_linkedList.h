#pragma once

#include "clove.h"
#include "linked_list.h"
#include "list_items.h"

CLOVE_TEST(LinkedList_AppendHeadNull)
{

    int_item *linked_list = NULL;

    int_item *item = NULL;

    int_item *head = list_append(&linked_list, item, int_item);

    CLOVE_NULL(head);
}

CLOVE_TEST(LinkedList_AppendHead)
{

    int_item *linked_list = NULL;

    int_item *item = item_new(0, int_item);

    int_item *head = list_append(&linked_list, item, int_item);

    CLOVE_PTR_EQ(head, linked_list);
    CLOVE_INT_EQ(head->object, linked_list->object);

    list_destroy(&linked_list, int_item);
}

CLOVE_TEST(LinkedList_AppendElement)
{

    int_item *linked_list = NULL;

    int_item *item_0 = item_new(0, int_item);
    int_item *item_1 = item_new(1, int_item);

    int_item *head = list_append(&linked_list, item_0, int_item);
    int_item *tail = list_append(&linked_list, item_1, int_item);
    int_item *list_tail = list_get_tail(&linked_list, int_item);

    CLOVE_PTR_EQ(tail, list_tail);
    CLOVE_INT_EQ(tail->object, list_tail->object);

    list_destroy(&linked_list, int_item);
}

CLOVE_TEST(LinkedList_AppendElementFail)
{

    int_item *linked_list = NULL;

    int_item *item_0 = item_new(0, int_item);
    int_item *item_1 = NULL;

    int_item *head = list_append(&linked_list, item_0, int_item);
    int_item *tail = list_append(&linked_list, item_1, int_item);

    CLOVE_NULL(tail);

    list_destroy(&linked_list, int_item);
}

CLOVE_TEST(LinkedList_GetTail)
{

    int_item *linked_list = NULL;

    int_item *items[5];

    for (int i = 0; i < 5; i++)
    {
        items[i] = item_new(i, int_item);
        list_append(&linked_list, items[i], int_item);
    }

    int_item *tail = list_get_tail(&linked_list, int_item);

    CLOVE_PTR_EQ(items[4], tail);
    CLOVE_INT_EQ(items[4]->object, tail->object);

    list_destroy(&linked_list, int_item);
}

CLOVE_TEST(LinkedList_GetTailFail)
{

    int_item *linked_list = NULL;

    int_item *tail = list_get_tail(&linked_list, int_item);

    CLOVE_NULL(tail);
}

CLOVE_TEST(LinkedList_PopElement)
{
    int_item *linked_list = NULL;

    int_item *items[5];

    for (int i = 0; i < 5; i++)
    {
        items[i] = item_new(i, int_item);
        list_append(&linked_list, items[i], int_item);
    }

    int_item *item = list_pop(&linked_list, int_item);

    CLOVE_PTR_EQ(items[0], item);
    CLOVE_INT_EQ(items[0]->object, item->object);

    list_destroy(&linked_list, int_item);
    list_destroy_item(&item, int_item);
}

CLOVE_TEST(LinkedList_PopLastElement)
{

    int_item *linked_list = NULL;

    int_item *item = list_append(&linked_list, item_new(0, int_item), int_item);

    int_item *popped_item = list_pop(&linked_list, int_item);

    CLOVE_PTR_EQ(item, popped_item);
    CLOVE_INT_EQ(item->object, popped_item->object);
    CLOVE_NULL(linked_list);

    list_destroy(&linked_list, int_item);
    list_destroy_item(&popped_item, int_item);
}

CLOVE_TEST(LinkedList_PopFail)
{

    int_item *linked_list = NULL;

    int_item *item = list_pop(&linked_list, int_item);

    CLOVE_NULL(item);
}

CLOVE_TEST(LinkedList_RemoveElement)
{

    int_item *linked_list = NULL;

    int_item *items[5];

    for (int i = 0; i < 5; i++)
    {
        items[i] = item_new(i, int_item);
        list_append(&linked_list, items[i], int_item);
    }

    int_item *item = list_remove(&linked_list, items[1], int_item);

    CLOVE_PTR_EQ(items[1], item);
    CLOVE_INT_EQ(items[1]->object, item->object);
    CLOVE_PTR_EQ(items[2], items[0]->node.next);

    list_destroy(&linked_list, int_item);
    list_destroy_item(&item, int_item);
}

CLOVE_TEST(LinkedList_RemoveLastElement)
{

    int_item *linked_list = NULL;

    int_item *item = list_append(&linked_list, item_new(0, int_item), int_item);
    int_item *removed = list_remove(&linked_list, item, int_item);

    CLOVE_PTR_EQ(item, removed);
    CLOVE_INT_EQ(item->object, removed->object);
    CLOVE_NULL(linked_list);

    list_destroy(&linked_list, int_item);
    list_destroy_item(&removed, int_item);
}

CLOVE_TEST(LinkedList_RemoveNotContainedElementFromNullList)
{

    int_item *linked_list = NULL;

    int_item *item = item_new(0, int_item);

    int_item *removed = list_remove(&linked_list, item, int_item);

    CLOVE_NULL(removed);
    list_destroy_item(&item, int_item);
}

CLOVE_TEST(LinkedList_RemoveNotContainedElement)
{

    int_item *linked_list = NULL;

    int_item *item_0 = list_append(&linked_list, item_new(0, int_item), int_item);
    int_item *item_1 = item_new(1, int_item);

    int_item *removed = list_remove(&linked_list, item_1, int_item);

    CLOVE_NULL(removed);

    list_destroy(&linked_list, int_item);
    list_destroy_item(&item_1, int_item);
}

CLOVE_TEST(LinkedList_RemoveHead)
{

    int_item *linked_list = NULL;

    int_item *head = list_append(&linked_list, item_new(0, int_item), int_item);
    int_item *tail = list_append(&linked_list, item_new(1, int_item), int_item);

    int_item *removed = list_remove(&linked_list, head, int_item);

    CLOVE_PTR_EQ(head, removed);
    CLOVE_INT_EQ(head->object, removed->object);
    CLOVE_PTR_EQ(tail, linked_list);
    CLOVE_INT_EQ(tail->object, linked_list->object);

    list_destroy(&linked_list, int_item);
    list_destroy_item(&removed, int_item);
}

CLOVE_TEST(LinkedList_RemoveTail)
{

    int_item *linked_list = NULL;

    int_item *head = list_append(&linked_list, item_new(0, int_item), int_item);
    int_item *tail = list_append(&linked_list, item_new(1, int_item), int_item);

    int_item *removed = list_remove(&linked_list, tail, int_item);

    CLOVE_PTR_EQ(tail, removed);
    CLOVE_INT_EQ(tail->object, removed->object);
    CLOVE_NULL(head->node.next);

    list_destroy(&linked_list, int_item);
    list_destroy_item(&removed, int_item);
}

CLOVE_SUITE(LinkedList)
{

    CLOVE_SUITE_TESTS(LinkedList_AppendHeadNull, LinkedList_AppendHead, LinkedList_AppendElement, LinkedList_AppendElementFail, LinkedList_GetTail,
                      LinkedList_GetTailFail, LinkedList_PopElement, LinkedList_PopLastElement, LinkedList_PopFail, LinkedList_RemoveElement,
                      LinkedList_RemoveLastElement, LinkedList_RemoveNotContainedElement, LinkedList_RemoveNotContainedElementFromNullList, 
                      LinkedList_RemoveHead, LinkedList_RemoveTail);
}

CLOVE_TEST(ListItem_InstantiateIntItem)
{

    int_item *item = item_new(0, int_item);

    CLOVE_INT_EQ(0, item->object);

    list_destroy_item(&item, int_item);
}

CLOVE_TEST(ListItem_InstantiateFloatItem)
{

    float_item *item = item_new(0.1f, float_item);

    CLOVE_FLOAT_EQ(0.1f, item->object);

    list_destroy_item(&item, float_item);
}

CLOVE_TEST(ListItem_InstantiateCharItem)
{

    char_item *item = item_new('a', char_item);

    CLOVE_INT_EQ('a', item->object);

    list_destroy_item(&item, char_item);
}

CLOVE_TEST(ListItem_InstantiateSizeTItem)
{

    size_t_item *item = item_new(0LL, size_t_item);

    CLOVE_LLONG_EQ(0LL, item->object);

    list_destroy_item(&item, size_t_item);
}

CLOVE_TEST(ListItem_InstantiateStringItem)
{

    string_item *item = item_new("hello", string_item);

    CLOVE_STRING_EQ("hello", item->object);

    list_destroy_item(&item, string_item);
}

CLOVE_SUITE(ListItem)
{

    CLOVE_SUITE_TESTS(ListItem_InstantiateIntItem, ListItem_InstantiateFloatItem, ListItem_InstantiateCharItem, ListItem_InstantiateSizeTItem,
                      ListItem_InstantiateStringItem);
}
