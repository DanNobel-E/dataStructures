#pragma once

#include "clove.h"
#include "double_linked_list.h"
#include "double_list_item.h"
#include <stdlib.h>

#define srand() srand(1)

CLOVE_TEST(DLinkedList_AppendHeadNull)
{

    int_item *dlinked_list = NULL;

    int_item *item = NULL;

    int_item *head = dlist_append(&dlinked_list, item, int_item);

    CLOVE_NULL(head);
}

CLOVE_TEST(DLinkedList_AppendHead)
{

    int_item *dlinked_list = NULL;

    int_item *item = item_new(0, int_item);

    int_item *head = dlist_append(&dlinked_list, item, int_item);

    CLOVE_PTR_EQ(head, dlinked_list);
    CLOVE_INT_EQ(head->object, dlinked_list->object);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_AppendElement)
{

    int_item *dlinked_list = NULL;

    int_item *item_0 = item_new(0, int_item);
    int_item *item_1 = item_new(1, int_item);

    int_item *head = dlist_append(&dlinked_list, item_0, int_item);
    int_item *tail = dlist_append(&dlinked_list, item_1, int_item);
    int_item *dlist_tail = dlist_get_tail(&dlinked_list, int_item);

    CLOVE_PTR_EQ(tail, dlist_tail);
    CLOVE_INT_EQ(tail->object, dlist_tail->object);

    CLOVE_PTR_EQ(head, dlist_tail->node.prev);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_AppendElementFail)
{

    int_item *dlinked_list = NULL;

    int_item *item_0 = item_new(0, int_item);
    int_item *item_1 = NULL;

    int_item *head = dlist_append(&dlinked_list, item_0, int_item);
    int_item *tail = dlist_append(&dlinked_list, item_1, int_item);

    CLOVE_NULL(tail);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_SUITE(DoubleLinkedList_Append)
{

    CLOVE_SUITE_TESTS(DLinkedList_AppendHeadNull, DLinkedList_AppendHead, DLinkedList_AppendElement, DLinkedList_AppendElementFail);
}

CLOVE_TEST(DLinkedList_GetElementAt)
{

    int_item *dlinked_list = NULL;

    int_item *items[3];

    for (int i = 0; i < 3; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *item = dlist_get_element_at(&dlinked_list, 1, int_item);

    CLOVE_PTR_EQ(items[1], item);
    CLOVE_INT_EQ(items[1]->object, item->object);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_GetElementAtHead)
{

    int_item *dlinked_list = NULL;

    int_item *head = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *tail = dlist_append(&dlinked_list, item_new(1, int_item), int_item);

    int_item *got_head = dlist_get_element_at(&dlinked_list, 0, int_item);

    CLOVE_PTR_EQ(head, got_head);
    CLOVE_INT_EQ(head->object, got_head->object);
    CLOVE_PTR_EQ(dlinked_list, got_head);
    CLOVE_INT_EQ(dlinked_list->object, got_head->object);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_GetElementAtTail)
{

    int_item *dlinked_list = NULL;

    int_item *head = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *tail = dlist_append(&dlinked_list, item_new(1, int_item), int_item);

    int_item *got_tail = dlist_get_element_at(&dlinked_list, 1, int_item);

    CLOVE_PTR_EQ(tail, got_tail);
    CLOVE_INT_EQ(tail->object, got_tail->object);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_GetElementAtOutOfBoundsIndex)
{

    int_item *dlinked_list = NULL;

    int_item *items[3];

    for (int i = 0; i < 3; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *item_0 = dlist_get_element_at(&dlinked_list, 5, int_item);
    int_item *item_1 = dlist_get_element_at(&dlinked_list, -1, int_item);

    CLOVE_NULL(item_0);
    CLOVE_NULL(item_1);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_GetElementFromNullList)
{

    int_item *dlinked_list = NULL;

    int_item *item = dlist_get_element_at(&dlinked_list, 0, int_item);

    CLOVE_NULL(item);
}

CLOVE_TEST(DLinkedList_GetTail)
{

    int_item *dlinked_list = NULL;

    int_item *items[5];

    for (int i = 0; i < 5; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *tail = dlist_get_tail(&dlinked_list, int_item);

    CLOVE_PTR_EQ(items[4], tail);
    CLOVE_INT_EQ(items[4]->object, tail->object);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_GetTailFail)
{

    int_item *dlinked_list = NULL;

    int_item *tail = dlist_get_tail(&dlinked_list, int_item);

    CLOVE_NULL(tail);
}

CLOVE_SUITE(DoubleLinkedList_GetElement)
{

    CLOVE_SUITE_TESTS(DLinkedList_GetElementAt, DLinkedList_GetElementAtHead, DLinkedList_GetElementAtTail, DLinkedList_GetElementAtOutOfBoundsIndex,
                      DLinkedList_GetElementFromNullList, DLinkedList_GetTail, DLinkedList_GetTailFail);
}

CLOVE_TEST(DLinkedList_PopElement)
{
    int_item *dlinked_list = NULL;

    int_item *items[5];

    for (int i = 0; i < 5; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *item = dlist_pop(&dlinked_list, int_item);

    CLOVE_PTR_EQ(items[0], item);
    CLOVE_INT_EQ(items[0]->object, item->object);

    CLOVE_PTR_EQ(items[1], dlinked_list);
    CLOVE_INT_EQ(items[1]->object, dlinked_list->object);
    CLOVE_NULL(items[1]->node.prev);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&item, int_item);
}

CLOVE_TEST(DLinkedList_PopLastElement)
{

    int_item *dlinked_list = NULL;

    int_item *item = dlist_append(&dlinked_list, item_new(0, int_item), int_item);

    int_item *popped_item = dlist_pop(&dlinked_list, int_item);

    CLOVE_PTR_EQ(item, popped_item);
    CLOVE_INT_EQ(item->object, popped_item->object);
    CLOVE_NULL(dlinked_list);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&popped_item, int_item);
}

CLOVE_TEST(DLinkedList_PopFail)
{

    int_item *dlinked_list = NULL;

    int_item *item = dlist_pop(&dlinked_list, int_item);

    CLOVE_NULL(item);
}

CLOVE_SUITE(DoubleLinkedList_Pop)
{

    CLOVE_SUITE_TESTS(DLinkedList_PopElement, DLinkedList_PopLastElement, DLinkedList_PopFail);
}

CLOVE_TEST(DLinkedList_RemoveElement)
{

    int_item *dlinked_list = NULL;

    int_item *items[5];

    for (int i = 0; i < 5; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *item = dlist_remove(&dlinked_list, items[1], int_item);

    CLOVE_PTR_EQ(items[1], item);
    CLOVE_INT_EQ(items[1]->object, item->object);
    CLOVE_PTR_EQ(items[2], items[0]->node.next);
    CLOVE_PTR_EQ(items[0], items[2]->node.prev);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&item, int_item);
}

CLOVE_TEST(DLinkedList_RemoveLastElement)
{

    int_item *dlinked_list = NULL;

    int_item *item = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *removed = dlist_remove(&dlinked_list, item, int_item);

    CLOVE_PTR_EQ(item, removed);
    CLOVE_INT_EQ(item->object, removed->object);
    CLOVE_NULL(dlinked_list);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&removed, int_item);
}

CLOVE_TEST(DLinkedList_RemoveNotContainedElementFromNullList)
{

    int_item *dlinked_list = NULL;

    int_item *item = item_new(0, int_item);

    int_item *removed = dlist_remove(&dlinked_list, item, int_item);

    CLOVE_NULL(removed);
    dlist_destroy_item(&item, int_item);
}

CLOVE_TEST(DLinkedList_RemoveNotContainedElement)
{

    int_item *dlinked_list = NULL;

    int_item *item_0 = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *item_1 = item_new(1, int_item);

    int_item *removed = dlist_remove(&dlinked_list, item_1, int_item);

    CLOVE_NULL(removed);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&item_1, int_item);
}

CLOVE_TEST(DLinkedList_RemoveHead)
{

    int_item *dlinked_list = NULL;

    int_item *head = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *tail = dlist_append(&dlinked_list, item_new(1, int_item), int_item);

    int_item *removed = dlist_remove(&dlinked_list, head, int_item);

    CLOVE_PTR_EQ(head, removed);
    CLOVE_INT_EQ(head->object, removed->object);
    CLOVE_PTR_EQ(tail, dlinked_list);
    CLOVE_INT_EQ(tail->object, dlinked_list->object);
    CLOVE_NULL(tail->node.prev);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&removed, int_item);
}

CLOVE_TEST(DLinkedList_RemoveTail)
{

    int_item *dlinked_list = NULL;

    int_item *head = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *tail = dlist_append(&dlinked_list, item_new(1, int_item), int_item);

    int_item *removed = dlist_remove(&dlinked_list, tail, int_item);

    CLOVE_PTR_EQ(tail, removed);
    CLOVE_INT_EQ(tail->object, removed->object);
    CLOVE_NULL(head->node.next);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&removed, int_item);
}

CLOVE_TEST(DLinkedList_RemoveAt)
{

    int_item *dlinked_list = NULL;

    int_item *items[5];

    for (int i = 0; i < 5; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *item = dlist_remove_at(&dlinked_list, 1, int_item);

    CLOVE_PTR_EQ(items[1], item);
    CLOVE_INT_EQ(items[1]->object, item->object);
    CLOVE_PTR_EQ(items[2], items[0]->node.next);
    CLOVE_PTR_EQ(items[0], items[2]->node.prev);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&item, int_item);
}

CLOVE_TEST(DLinkedList_RemoveAtLastElement)
{

    int_item *dlinked_list = NULL;

    int_item *item = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *removed = dlist_remove_at(&dlinked_list, 0, int_item);

    CLOVE_PTR_EQ(item, removed);
    CLOVE_INT_EQ(item->object, removed->object);
    CLOVE_NULL(dlinked_list);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&removed, int_item);
}

CLOVE_TEST(DLinkedList_RemoveAtIndexOutofBounds)
{

    int_item *dlinked_list = NULL;

    int_item *items[3];

    for (int i = 0; i < 3; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *item_0 = dlist_remove_at(&dlinked_list, 5, int_item);
    int_item *item_1 = dlist_remove_at(&dlinked_list, -1, int_item);

    CLOVE_NULL(item_0);
    CLOVE_NULL(item_1);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_RemoveAtHead)
{

    int_item *dlinked_list = NULL;

    int_item *head = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *tail = dlist_append(&dlinked_list, item_new(1, int_item), int_item);

    int_item *removed = dlist_remove_at(&dlinked_list, 0, int_item);

    CLOVE_PTR_EQ(head, removed);
    CLOVE_INT_EQ(head->object, removed->object);
    CLOVE_PTR_EQ(tail, dlinked_list);
    CLOVE_INT_EQ(tail->object, dlinked_list->object);
    CLOVE_NULL(tail->node.prev);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&removed, int_item);
}

CLOVE_TEST(DLinkedList_RemoveAtTail)
{

    int_item *dlinked_list = NULL;

    int_item *head = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *tail = dlist_append(&dlinked_list, item_new(1, int_item), int_item);

    int_item *removed = dlist_remove_at(&dlinked_list, 1, int_item);

    CLOVE_PTR_EQ(tail, removed);
    CLOVE_INT_EQ(tail->object, removed->object);
    CLOVE_NULL(head->node.next);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&removed, int_item);
}

CLOVE_TEST(DLinkedList_RemoveAtFromNullList)
{

    int_item *dlinked_list = NULL;

    int_item *removed = dlist_remove_at(&dlinked_list, 0, int_item);

    CLOVE_NULL(removed);
}

CLOVE_SUITE(DoubleLinkedList_Remove)
{

    CLOVE_SUITE_TESTS(DLinkedList_RemoveElement, DLinkedList_RemoveLastElement, DLinkedList_RemoveNotContainedElement, DLinkedList_RemoveNotContainedElementFromNullList,
                      DLinkedList_RemoveHead, DLinkedList_RemoveTail, DLinkedList_RemoveAt, DLinkedList_RemoveAtLastElement, DLinkedList_RemoveAtHead,
                      DLinkedList_RemoveAtTail, DLinkedList_RemoveAtIndexOutofBounds, DLinkedList_RemoveAtFromNullList);
}

CLOVE_TEST(DLinkedList_InsertBefore)
{

    int_item *dlinked_list = NULL;

    int_item *items[3];

    for (int i = 0; i < 3; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *item_to_insert = item_new(3, int_item);
    int result = dlist_insert_before(&dlinked_list, items[2], item_to_insert, int_item);
    int_item *inserted = dlist_get_element_at(&dlinked_list, 2, int_item);

    CLOVE_INT_EQ(0, result);

    CLOVE_PTR_EQ(item_to_insert, inserted);
    CLOVE_INT_EQ(item_to_insert->object, inserted->object);

    CLOVE_PTR_EQ(items[2], item_to_insert->node.next);
    CLOVE_PTR_EQ(items[1], item_to_insert->node.prev);

    CLOVE_PTR_EQ(inserted, items[1]->node.next);
    CLOVE_PTR_EQ(inserted, items[2]->node.prev);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_InsertBeforeHead)
{

    int_item *dlinked_list = NULL;

    int_item *head = dlist_append(&dlinked_list, item_new(0, int_item), int_item);

    int_item *item_to_insert = item_new(1, int_item);
    int result = dlist_insert_before(&dlinked_list, head, item_to_insert, int_item);
    int_item *inserted = dlist_get_element_at(&dlinked_list, 0, int_item);

    CLOVE_INT_EQ(0, result);

    CLOVE_PTR_EQ(item_to_insert, inserted);
    CLOVE_PTR_EQ(dlinked_list, inserted);
    CLOVE_INT_EQ(item_to_insert->object, inserted->object);
    CLOVE_INT_EQ(dlinked_list->object, inserted->object);

    CLOVE_PTR_EQ(head, inserted->node.next);
    CLOVE_PTR_EQ(inserted, head->node.prev);
    CLOVE_NULL(inserted->node.prev);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_InsertAfter)
{

    int_item *dlinked_list = NULL;

    int_item *items[3];

    for (int i = 0; i < 3; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *item_to_insert = item_new(3, int_item);
    int result = dlist_insert_after(&dlinked_list, items[1], item_to_insert, int_item);
    int_item *inserted = dlist_get_element_at(&dlinked_list, 2, int_item);

    CLOVE_INT_EQ(0, result);

    CLOVE_PTR_EQ(item_to_insert, inserted);
    CLOVE_INT_EQ(item_to_insert->object, inserted->object);

    CLOVE_PTR_EQ(items[2], item_to_insert->node.next);
    CLOVE_PTR_EQ(items[1], item_to_insert->node.prev);

    CLOVE_PTR_EQ(inserted, items[1]->node.next);
    CLOVE_PTR_EQ(inserted, items[2]->node.prev);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_InsertAfterTail)
{

    int_item *dlinked_list = NULL;

    int_item *head = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *tail = dlist_append(&dlinked_list, item_new(1, int_item), int_item);

    int_item *item_to_insert = item_new(2, int_item);
    int result = dlist_insert_after(&dlinked_list, tail, item_to_insert, int_item);
    int_item *inserted = dlist_get_element_at(&dlinked_list, 2, int_item);

    CLOVE_INT_EQ(0, result);

    CLOVE_PTR_EQ(item_to_insert, inserted);
    CLOVE_INT_EQ(item_to_insert->object, inserted->object);

    CLOVE_PTR_EQ(inserted, tail->node.next);
    CLOVE_PTR_EQ(tail, inserted->node.prev);
    CLOVE_NULL(inserted->node.next);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_InsertInNullList)
{

    int_item *dlinked_list = NULL;

    int_item *item_to_insert = item_new(1, int_item);

    int result_0 = dlist_insert_before(&dlinked_list, dlist_get_element_at(&dlinked_list, 0, int_item), item_to_insert, int_item);
    int result_1 = dlist_insert_after(&dlinked_list, dlist_get_element_at(&dlinked_list, 0, int_item), item_to_insert, int_item);

    CLOVE_INT_EQ(-1, result_0);
    CLOVE_INT_EQ(-1, result_1);
    CLOVE_NULL(dlinked_list);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&item_to_insert, int_item);
}

CLOVE_TEST(DLinkedList_InsertAroundElementNotInList)
{

    int_item *dlinked_list = NULL;

    int_item *head = dlist_append(&dlinked_list, item_new(0, int_item), int_item);
    int_item *tail = dlist_append(&dlinked_list, item_new(1, int_item), int_item);
    int_item *item = item_new(2, int_item);

    int_item *item_to_insert = item_new(3, int_item);

    int result_0 = dlist_insert_before(&dlinked_list, item, item_to_insert, int_item);
    int result_1 = dlist_insert_after(&dlinked_list, item, item_to_insert, int_item);

    CLOVE_INT_EQ(-1, result_0);
    CLOVE_INT_EQ(-1, result_1);
    CLOVE_NULL(item->node.next);
    CLOVE_NULL(item->node.prev);

    CLOVE_NULL(item_to_insert->node.next);
    CLOVE_NULL(item_to_insert->node.prev);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&item, int_item);
    dlist_destroy_item(&item_to_insert, int_item);
}

CLOVE_TEST(DLinkedList_InsertElementAlreadyInListAround)
{

    int_item *dlinked_list = NULL;

    int_item *items[5];

    for (int i = 0; i < 5; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    // Adjacent element
    int result_0 = dlist_insert_before(&dlinked_list, items[2], items[3], int_item);
    int result_1 = dlist_insert_after(&dlinked_list, items[2], items[1], int_item);

    // Not adjacent element
    int result_2 = dlist_insert_before(&dlinked_list, items[3], items[1], int_item);
    int result_3 = dlist_insert_after(&dlinked_list, items[1], items[3], int_item);

    CLOVE_INT_EQ(-1, result_0);
    CLOVE_INT_EQ(-1, result_1);
    CLOVE_INT_EQ(-1, result_2);
    CLOVE_INT_EQ(-1, result_3);

    CLOVE_NULL(dlinked_list->node.prev);
    CLOVE_PTR_EQ(items[1], dlinked_list->node.next);
    CLOVE_PTR_EQ(dlinked_list, items[1]->node.prev);
    CLOVE_PTR_EQ(items[2], items[1]->node.next);
    CLOVE_PTR_EQ(items[1], items[2]->node.prev);
    CLOVE_PTR_EQ(items[3], items[2]->node.next);
    CLOVE_PTR_EQ(items[2], items[3]->node.prev);
    CLOVE_PTR_EQ(items[4], items[3]->node.next);
    CLOVE_PTR_EQ(items[3], items[4]->node.prev);
    CLOVE_NULL(items[4]->node.next);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_SUITE(DoubleLinkedList_Insert)
{

    CLOVE_SUITE_TESTS(DLinkedList_InsertBefore, DLinkedList_InsertBeforeHead, DLinkedList_InsertAfter, DLinkedList_InsertAfterTail,
                      DLinkedList_InsertInNullList, DLinkedList_InsertAroundElementNotInList, DLinkedList_InsertElementAlreadyInListAround);
}

CLOVE_TEST(DLinkedList_Contains)
{

    int_item *dlinked_list = NULL;

    int_item *items[3];

    for (int i = 0; i < 3; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int result = dlist_contains(&dlinked_list, items[1], int_item);

    CLOVE_INT_EQ(0, result);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_NotContains)
{

    int_item *dlinked_list = NULL;

    int_item *items[3];

    for (int i = 0; i < 3; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int_item *item = item_new(3, int_item);

    int result = dlist_contains(&dlinked_list, item, int_item);

    CLOVE_INT_EQ(-1, result);

    dlist_destroy(&dlinked_list, int_item);
    dlist_destroy_item(&item, int_item);
}

CLOVE_TEST(DLinkedList_NotContainsNullList)
{

    int_item *dlinked_list = NULL;

    int_item *item = item_new(3, int_item);

    int result = dlist_contains(&dlinked_list, item, int_item);

    CLOVE_INT_EQ(-1, result);

    dlist_destroy_item(&item, int_item);
}

CLOVE_TEST(DLinkedList_Count)
{

    int_item *dlinked_list = NULL;

    int_item *items[3];

    for (int i = 0; i < 3; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    int result = dlist_count(&dlinked_list, int_item);

    CLOVE_INT_EQ(3, result);

    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_CountNullList)
{

    int_item *dlinked_list = NULL;

    int result = dlist_count(&dlinked_list, int_item);

    CLOVE_INT_EQ(0, result);
}

CLOVE_SUITE(DoubleLinkedList_Utils)
{

    CLOVE_SUITE_TESTS(DLinkedList_Contains, DLinkedList_NotContains, DLinkedList_NotContainsNullList, DLinkedList_Count, DLinkedList_CountNullList);
}

CLOVE_TEST(DLinkedList_Shuffle)
{

    int_item *dlinked_list = NULL;

    int_item *items[3];

    for (int i = 0; i < 3; i++)
    {
        items[i] = item_new(i, int_item);
        dlist_append(&dlinked_list, items[i], int_item);
    }

    srand();

    int_item *shuffled_list = dlist_shuffle(&dlinked_list, int_item);

    CLOVE_PTR_EQ(dlinked_list, shuffled_list);
    CLOVE_PTR_EQ(items[2], dlist_get_element_at(&shuffled_list, 0, int_item));
    CLOVE_PTR_EQ(items[0], dlist_get_element_at(&shuffled_list, 1, int_item));
    CLOVE_PTR_EQ(items[1], dlist_get_element_at(&shuffled_list, 2, int_item));

    dlist_destroy(&shuffled_list, int_item);
    dlist_destroy(&dlinked_list, int_item);
}

CLOVE_TEST(DLinkedList_ShuffleOneElementList)
{

    int_item *dlinked_list = NULL;

    int_item * item= dlist_append(&dlinked_list,item_new(0,int_item),int_item);

    srand();

    int_item *shuffled_list = dlist_shuffle(&dlinked_list, int_item);

    CLOVE_PTR_EQ(dlinked_list,shuffled_list);
    CLOVE_PTR_EQ(item,shuffled_list);


    dlist_destroy(&shuffled_list, int_item);
    dlist_destroy(&dlinked_list, int_item);

}

CLOVE_TEST(DLinkedList_ShuffleNullList)
{

    int_item *dlinked_list = NULL;

    srand();

    int_item *shuffled_list = dlist_shuffle(&dlinked_list, int_item);

    CLOVE_NULL(shuffled_list);

}

CLOVE_SUITE(DoubleLinkedList_Shuffle)
{

    CLOVE_SUITE_TESTS(DLinkedList_Shuffle, DLinkedList_ShuffleOneElementList, DLinkedList_ShuffleNullList);
}

CLOVE_TEST(DListItem_InstantiateIntItem)
{

    int_item *item = item_new(0, int_item);

    CLOVE_INT_EQ(0, item->object);

    dlist_destroy_item(&item, int_item);
}

CLOVE_TEST(DListItem_InstantiateFloatItem)
{

    float_item *item = item_new(0.1f, float_item);

    CLOVE_FLOAT_EQ(0.1f, item->object);

    dlist_destroy_item(&item, float_item);
}

CLOVE_TEST(DListItem_InstantiateCharItem)
{

    char_item *item = item_new('a', char_item);

    CLOVE_INT_EQ('a', item->object);

    dlist_destroy_item(&item, char_item);
}

CLOVE_TEST(DListItem_InstantiateSizeTItem)
{

    size_t_item *item = item_new(0LL, size_t_item);

    CLOVE_LLONG_EQ(0LL, item->object);

    dlist_destroy_item(&item, size_t_item);
}

CLOVE_TEST(DListItem_InstantiateStringItem)
{

    string_item *item = item_new("hello", string_item);

    CLOVE_STRING_EQ("hello", item->object);

    dlist_destroy_item(&item, string_item);
}

CLOVE_SUITE(DoubleListItem)
{

    CLOVE_SUITE_TESTS(DListItem_InstantiateIntItem, DListItem_InstantiateFloatItem, DListItem_InstantiateCharItem, DListItem_InstantiateSizeTItem,
                      DListItem_InstantiateStringItem);
}
