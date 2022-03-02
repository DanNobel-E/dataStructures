#include "clove.h"
#include "dictionary.h"

CLOVE_TEST(Dictionary_TableNewZeroSize)
{
    int_table *table = dictionary_table_new(0, int);

    CLOVE_NULL(table);
}

CLOVE_TEST(Dictionary_TableNewSizeOutOfBounds)
{
    int_table *table = dictionary_table_new(-1, int);

    CLOVE_NULL(table);
}

CLOVE_TEST(Dictionary_InsertOnNullTable)
{
    int_table *table = dictionary_table_new(-1, int);

    int_node *node = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    CLOVE_NULL(table);
    CLOVE_NULL(node);
}

CLOVE_TEST(Dictionary_InsertOneKeyOneHash)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *node = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node, table->nodes[0]);
    CLOVE_STRING_EQ("Key_0", table->nodes[0]->key);
    CLOVE_INT_EQ(0, table->nodes[0]->object);
    CLOVE_NULL(table->nodes[0]->next);
    CLOVE_NULL(table->nodes[1]);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_InsertTwoKeysOneHash)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *node_0 = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);
    int_node *node_1 = dictionary_insert(table, "Key_1", strlen("Key_1"), 1, int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[0]);
    CLOVE_STRING_EQ("Key_0", table->nodes[0]->key);
    CLOVE_INT_EQ(0, table->nodes[0]->object);

    CLOVE_PTR_EQ(node_1, table->nodes[0]->next);
    CLOVE_STRING_EQ("Key_1", table->nodes[0]->next->key);
    CLOVE_INT_EQ(1, table->nodes[0]->next->object);

    CLOVE_NULL(table->nodes[1]);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_InsertOneKeysTwoHash)
{
    int_table *table = dictionary_table_new(2, int);

    int_node *node = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node, table->nodes[1]);
    CLOVE_STRING_EQ("Key_0", table->nodes[1]->key);
    CLOVE_INT_EQ(0, table->nodes[1]->object);

    CLOVE_NULL(table->nodes[1]->next);
    CLOVE_NULL(table->nodes[0]);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_InsertTwoKeysTwoHash)
{
    int_table *table = dictionary_table_new(2, int);

    int_node *node_0 = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);
    int_node *node_1 = dictionary_insert(table, "Key_1", strlen("Key_1"), 1, int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[1]);
    CLOVE_STRING_EQ("Key_0", table->nodes[1]->key);
    CLOVE_INT_EQ(0, table->nodes[1]->object);

    CLOVE_PTR_EQ(node_1, table->nodes[0]);
    CLOVE_STRING_EQ("Key_1", table->nodes[0]->key);
    CLOVE_INT_EQ(1, table->nodes[0]->object);

    CLOVE_NULL(table->nodes[0]->next);
    CLOVE_NULL(table->nodes[1]->next);
    CLOVE_NULL(table->nodes[2]);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_InsertThreeKeysTwoHash)
{
    int_table *table = dictionary_table_new(2, int);

    int_node *node_0 = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);
    int_node *node_1 = dictionary_insert(table, "Key_1", strlen("Key_1"), 1, int);
    int_node *node_2 = dictionary_insert(table, "Key_2", strlen("Key_2"), 2, int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[1]);
    CLOVE_STRING_EQ("Key_0", table->nodes[1]->key);
    CLOVE_INT_EQ(0, table->nodes[1]->object);

    CLOVE_PTR_EQ(node_1, table->nodes[0]);
    CLOVE_STRING_EQ("Key_1", table->nodes[0]->key);
    CLOVE_INT_EQ(1, table->nodes[0]->object);

    CLOVE_PTR_EQ(node_2, table->nodes[1]->next);
    CLOVE_STRING_EQ("Key_2", table->nodes[1]->next->key);
    CLOVE_INT_EQ(2, table->nodes[1]->next->object);

    CLOVE_NULL(node_2->next);
    CLOVE_NULL(table->nodes[2]);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dicitonary_InsertAlreadyExistingKeyOneHash)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *node_0 = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);
    int_node *node_1 = dictionary_insert(table, "Key_0", strlen("Key_0"), 1, int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[0]);
    CLOVE_STRING_EQ("Key_0", table->nodes[0]->key);
    CLOVE_INT_EQ(0, table->nodes[0]->object);

    CLOVE_NULL(table->nodes[0]->next);
    CLOVE_NULL(table->nodes[1]);
    CLOVE_NULL(node_1);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_InsertAlreadyExistingKeyMultipleHash)
{
    int_table *table = dictionary_table_new(5, int);

    int_node *node_0 = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);
    int_node *node_1 = dictionary_insert(table, "Key_0", strlen("Key_0"), 1, int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[1]);
    CLOVE_STRING_EQ("Key_0", table->nodes[1]->key);
    CLOVE_INT_EQ(0, table->nodes[1]->object);

    CLOVE_NULL(table->nodes[1]->next);
    CLOVE_NULL(table->nodes[0]);
    CLOVE_NULL(table->nodes[2]);
    CLOVE_NULL(table->nodes[3]);
    CLOVE_NULL(table->nodes[4]);
    CLOVE_NULL(node_1);

    dictionary_destroy_table(&table, int);
}

CLOVE_SUITE(Test_DictionaryInitialization)
{

    CLOVE_SUITE_TESTS(Dictionary_TableNewZeroSize, Dictionary_TableNewSizeOutOfBounds, Dictionary_InsertOnNullTable, Dictionary_InsertOneKeyOneHash,
                      Dictionary_InsertOneKeysTwoHash, Dictionary_InsertTwoKeysOneHash, Dictionary_InsertTwoKeysTwoHash, Dictionary_InsertThreeKeysTwoHash,
                      Dicitonary_InsertAlreadyExistingKeyOneHash, Dictionary_InsertAlreadyExistingKeyMultipleHash);
}

CLOVE_TEST(Dictionary_ChangeValueOnNullTable)
{
    int_table *table = dictionary_table_new(-1, int);

    int_node *node = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);
    int_node *changed = dictionary_change_value(table, "Key_0", strlen("Key_0"), 10, int);

    CLOVE_NULL(table);
    CLOVE_NULL(node);
    CLOVE_NULL(changed);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_ChangeValueOnNotInsertedKey)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *node = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);
    int_node *changed = dictionary_change_value(table, "Key_1", strlen("Key_1"), 10, int);

    CLOVE_NOT_NULL(table);
    CLOVE_NOT_NULL(node);
    CLOVE_PTR_EQ(table->nodes[0], node)
    CLOVE_STRING_EQ(table->nodes[0]->key, node->key)
    CLOVE_INT_EQ(table->nodes[0]->object, node->object)
    CLOVE_INT_EQ(0, node->object);
    CLOVE_NULL(changed);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_ChangeValueSuccess)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *node = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);
    int_node *changed = dictionary_change_value(table, "Key_0", strlen("Key_0"), 10, int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node, changed);
    CLOVE_STRING_EQ(node->key, changed->key);
    CLOVE_INT_EQ(node->object, changed->object);
    CLOVE_INT_EQ(10, node->object);
    CLOVE_INT_EQ(10, changed->object);

    dictionary_destroy_table(&table, int);
}

CLOVE_SUITE(Test_DictionaryChangeValue)
{
    CLOVE_SUITE_TESTS(Dictionary_ChangeValueOnNullTable, Dictionary_ChangeValueOnNotInsertedKey, Dictionary_ChangeValueSuccess);
}

CLOVE_TEST(Dicitonary_SearchOnNullTable)
{
    int_table *table = dictionary_table_new(-1, int);

    int_node *inserted = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    int_node *searched = dictionary_search(table, "Key_0", strlen("Key_0"), int);

    CLOVE_NULL(table);
    CLOVE_NULL(inserted);
    CLOVE_NULL(searched);
}

CLOVE_TEST(Dictionary_SearchOnSingleHash)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *nodes[4];
    const char *default_string = "Key_";
    char default_string_buffer[4];
    strcpy_s(default_string_buffer, 5, default_string);
    char index[2];
    char result_strings[4][10];

    for (int i = 0; i < 4; i++)
    {
        _itoa_s(i, index, 2, 10);
        strcpy_s(result_strings[i], 5, default_string_buffer);
        strcat_s(result_strings[i], 8, index);
        nodes[i] = dictionary_insert(table, result_strings[i], strlen(result_strings[i]), i, int);
    }

    int_node *searched = dictionary_search(table, "Key_2", strlen("Key_2"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[2], searched);
    CLOVE_STRING_EQ(nodes[2]->key, searched->key);
    CLOVE_INT_EQ(nodes[2]->object, searched->object);

    CLOVE_PTR_EQ(searched, table->nodes[0]->next->next);
    CLOVE_NULL(table->nodes[1]);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_SearchOnMultipleHash)
{
    int_table *table = dictionary_table_new(2, int);

    int_node *nodes[4];
    const char *default_string = "Key_";
    char default_string_buffer[4];
    strcpy_s(default_string_buffer, 5, default_string);
    char index[2];
    char result_strings[4][10];

    for (int i = 0; i < 4; i++)
    {
        _itoa_s(i, index, 2, 10);
        strcpy_s(result_strings[i], 5, default_string_buffer);
        strcat_s(result_strings[i], 8, index);
        nodes[i] = dictionary_insert(table, result_strings[i], strlen(result_strings[i]), i, int);
    }

    int_node *searched_1 = dictionary_search(table, "Key_1", strlen("Key_1"), int);
    int_node *searched_2 = dictionary_search(table, "Key_2", strlen("Key_2"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[1], searched_1);
    CLOVE_PTR_EQ(nodes[2], searched_2);
    CLOVE_STRING_EQ(nodes[1]->key, searched_1->key);
    CLOVE_STRING_EQ(nodes[2]->key, searched_2->key);
    CLOVE_INT_EQ(nodes[1]->object, searched_1->object);
    CLOVE_INT_EQ(nodes[2]->object, searched_2->object);

    CLOVE_PTR_EQ(searched_1, table->nodes[0]);
    CLOVE_PTR_EQ(searched_2, table->nodes[1]->next);
    CLOVE_NULL(table->nodes[2]);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_SearchFailsOnKey)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *inserted = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    int_node *searched = dictionary_search(table, "Key_3", strlen("Key_3"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(inserted, table->nodes[0]);
    CLOVE_STRING_EQ(inserted->key, table->nodes[0]->key);
    CLOVE_INT_EQ(inserted->object, table->nodes[0]->object);

    CLOVE_NULL(searched);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dicitonary_SearchFailsOnKeyLen)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *inserted = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    int_node *searched = dictionary_search(table, "Key_0", strlen("Key_01"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(inserted, table->nodes[0]);
    CLOVE_STRING_EQ(inserted->key, table->nodes[0]->key);
    CLOVE_INT_EQ(inserted->object, table->nodes[0]->object);

    CLOVE_NULL(searched);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_SearchHeadKeyOnNullTable)
{
    int_table *table = dictionary_table_new(-1, int);

    int_node *inserted = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    int_node *searched = dictionary_search_keyList_head(table, "Key_0", strlen("Key_0"), int);

    CLOVE_NULL(table);
    CLOVE_NULL(inserted);
    CLOVE_NULL(searched);
}

CLOVE_TEST(Dictionary_SearchHeadKeyOnSingleHash)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *nodes[4];
    const char *default_string = "Key_";
    char default_string_buffer[4];
    strcpy_s(default_string_buffer, 5, default_string);
    char index[2];
    char result_strings[4][10];

    for (int i = 0; i < 4; i++)
    {
        _itoa_s(i, index, 2, 10);
        strcpy_s(result_strings[i], 5, default_string_buffer);
        strcat_s(result_strings[i], 8, index);
        nodes[i] = dictionary_insert(table, result_strings[i], strlen(result_strings[i]), i, int);
    }

    int_node *searched = dictionary_search_keyList_head(table, "Key_2", strlen("Key_2"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[0], searched);
    CLOVE_STRING_EQ(nodes[0]->key, searched->key);
    CLOVE_INT_EQ(nodes[0]->object, searched->object);
    CLOVE_NOT_NULL(table->nodes[0]->next);
    CLOVE_NULL(table->nodes[1]);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_SearchHeadKeyOnMultipleHash)
{
    int_table *table = dictionary_table_new(2, int);

    int_node *nodes[4];
    const char *default_string = "Key_";
    char default_string_buffer[4];
    strcpy_s(default_string_buffer, 5, default_string);
    char index[2];
    char result_strings[4][10];

    for (int i = 0; i < 4; i++)
    {
        _itoa_s(i, index, 2, 10);
        strcpy_s(result_strings[i], 5, default_string_buffer);
        strcat_s(result_strings[i], 8, index);
        nodes[i] = dictionary_insert(table, result_strings[i], strlen(result_strings[i]), i, int);
    }

    int_node *searched_0 = dictionary_search_keyList_head(table, "Key_1", strlen("Key_1"), int);
    int_node *searched_1 = dictionary_search_keyList_head(table, "Key_2", strlen("Key_2"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[0], searched_1);
    CLOVE_PTR_EQ(nodes[1], searched_0);
    CLOVE_STRING_EQ(nodes[0]->key, searched_1->key);
    CLOVE_STRING_EQ(nodes[1]->key, searched_0->key);
    CLOVE_INT_EQ(nodes[0]->object, searched_1->object);
    CLOVE_INT_EQ(nodes[1]->object, searched_0->object);

    CLOVE_PTR_EQ(searched_1, table->nodes[1]);
    CLOVE_PTR_EQ(searched_0, table->nodes[0]);
    CLOVE_NULL(table->nodes[2]);

    dictionary_destroy_table(&table, int);
}

CLOVE_SUITE(Test_DictionarySearch)
{
    CLOVE_SUITE_TESTS(Dicitonary_SearchOnNullTable, Dictionary_SearchOnSingleHash,
                      Dictionary_SearchOnMultipleHash, Dictionary_SearchFailsOnKey, Dicitonary_SearchFailsOnKeyLen, Dictionary_SearchHeadKeyOnNullTable,
                      Dictionary_SearchHeadKeyOnSingleHash, Dictionary_SearchHeadKeyOnMultipleHash);
}

CLOVE_TEST(Dictionary_RemoveOnNullTable)
{
    int_table *table = dictionary_table_new(-1, int);

    int_node *inserted = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    int_node *removed = dictionary_remove(table, "Key_0", strlen("Key_0"), int);

    CLOVE_NULL(table);
    CLOVE_NULL(inserted);
    CLOVE_NULL(removed);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_RemoveNotInsertedKey)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *inserted = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    int_node *removed = dictionary_remove(table, "Key_1", strlen("Key_1"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_NOT_NULL(inserted);
    CLOVE_NULL(removed);

    dictionary_destroy_table(&table, int);
}

CLOVE_TEST(Dictionary_RemoveLastElement)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *inserted = dictionary_insert(table, "Key_0", strlen("Key_0"), 0, int);

    int_node *removed = dictionary_remove(table, "Key_0", strlen("Key_0"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(inserted, removed);
    CLOVE_STRING_EQ(inserted->key, removed->key);
    CLOVE_INT_EQ(inserted->object, removed->object);

    CLOVE_NULL(table->nodes[0]);

    dictionary_destroy_table(&table, int);
    dictionary_destroy_node(&removed, int);
}

CLOVE_TEST(Dictionary_RemoveHeadKey)
{
    int_table *table = dictionary_table_new(1, int);

    int_node *nodes[4];
    const char *default_string = "Key_";
    char default_string_buffer[4];
    strcpy_s(default_string_buffer, 5, default_string);
    char index[2];
    char result_strings[4][10];

    for (int i = 0; i < 4; i++)
    {
        _itoa_s(i, index, 2, 10);
        strcpy_s(result_strings[i], 5, default_string_buffer);
        strcat_s(result_strings[i], 8, index);
        nodes[i] = dictionary_insert(table, result_strings[i], strlen(result_strings[i]), i, int);
    }

    int_node *removed = dictionary_remove(table, "Key_0", strlen("Key_0"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[0], removed);
    CLOVE_STRING_EQ(nodes[0]->key, removed->key);
    CLOVE_INT_EQ(nodes[0]->object, removed->object);

    CLOVE_PTR_EQ(nodes[1], table->nodes[0]);
    CLOVE_STRING_EQ(nodes[1]->key, table->nodes[0]->key);
    CLOVE_INT_EQ(nodes[1]->object, table->nodes[0]->object);

    CLOVE_NULL(removed->next);
    CLOVE_NULL(table->nodes[1]);

    dictionary_destroy_table(&table, int);
    dictionary_destroy_node(&removed, int);
}

CLOVE_TEST(Dictionary_RemoveSuccess)
{
    int_table *table = dictionary_table_new(2, int);

    int_node *nodes[4];
    const char *default_string = "Key_";
    char default_string_buffer[4];
    strcpy_s(default_string_buffer, 5, default_string);
    char index[2];
    char result_strings[4][10];

    for (int i = 0; i < 4; i++)
    {
        _itoa_s(i, index, 2, 10);
        strcpy_s(result_strings[i], 5, default_string_buffer);
        strcat_s(result_strings[i], 8, index);
        nodes[i] = dictionary_insert(table, result_strings[i], strlen(result_strings[i]), i, int);
    }

    int_node *removed = dictionary_remove(table, "Key_2", strlen("Key_2"), int);

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[2], removed);
    CLOVE_STRING_EQ(nodes[2]->key, removed->key);
    CLOVE_INT_EQ(nodes[2]->object, removed->object);

    CLOVE_NULL(table->nodes[1]->next);
    CLOVE_NULL(removed->next);
    CLOVE_NULL(table->nodes[2]);

    dictionary_destroy_table(&table, int);
    dictionary_destroy_node(&removed, int);
}

CLOVE_SUITE(Test_DictionaryRemove)
{
    CLOVE_SUITE_TESTS(Dictionary_RemoveOnNullTable, Dictionary_RemoveLastElement,
                      Dictionary_RemoveNotInsertedKey, Dictionary_RemoveHeadKey, Dictionary_RemoveSuccess);
}