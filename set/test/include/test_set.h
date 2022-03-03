#include "clove.h"
#include "set.h"

CLOVE_TEST(Set_TableNewZeroSize)
{
    set_table_t *table = set_table_new(0);

    CLOVE_NULL(table);
}

CLOVE_TEST(Set_TableNewSizeOutOfBounds)
{
    set_table_t *table = set_table_new(-1);

    CLOVE_NULL(table);
}

CLOVE_TEST(Set_InsertOnNullTable)
{
    set_table_t *table = set_table_new(-1);

    set_node_t *node = set_insert(table, "Key_0", strlen("Key_0"));

    CLOVE_NULL(table);
    CLOVE_NULL(node);
}

CLOVE_TEST(Set_InsertOneKeyOneHash)
{
    set_table_t *table = set_table_new(1);

    set_node_t *node = set_insert(table, "Key_0", strlen("Key_0"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node, table->nodes[0]);
    CLOVE_STRING_EQ("Key_0", table->nodes[0]->key);
    CLOVE_NULL(table->nodes[0]->next);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_InsertTwoKeysOneHash)
{
    set_table_t *table = set_table_new(1);

    set_node_t *node_0 = set_insert(table, "Key_0", strlen("Key_0"));
    set_node_t *node_1 = set_insert(table, "Key_1", strlen("Key_1"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[0]);
    CLOVE_STRING_EQ("Key_0", table->nodes[0]->key);
    CLOVE_PTR_EQ(node_1, table->nodes[0]->next);
    CLOVE_STRING_EQ("Key_1", table->nodes[0]->next->key);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_InsertOneKeysTwoHash)
{
    set_table_t *table = set_table_new(2);

    set_node_t *node = set_insert(table, "Key_0", strlen("Key_0"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node, table->nodes[1]);
    CLOVE_STRING_EQ("Key_0", table->nodes[1]->key);
    CLOVE_NULL(table->nodes[1]->next);
    CLOVE_NULL(table->nodes[0]);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_InsertTwoKeysTwoHash)
{
    set_table_t *table = set_table_new(2);

    set_node_t *node_0 = set_insert(table, "Key_0", strlen("Key_0"));
    set_node_t *node_1 = set_insert(table, "Key_1", strlen("Key_1"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[1]);
    CLOVE_STRING_EQ("Key_0", table->nodes[1]->key);
    CLOVE_PTR_EQ(node_1, table->nodes[0]);
    CLOVE_STRING_EQ("Key_1", table->nodes[0]->key);
    CLOVE_NULL(table->nodes[0]->next);
    CLOVE_NULL(table->nodes[1]->next);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_InsertThreeKeysTwoHash)
{
    set_table_t *table = set_table_new(2);

    set_node_t *node_0 = set_insert(table, "Key_0", strlen("Key_0"));
    set_node_t *node_1 = set_insert(table, "Key_1", strlen("Key_1"));
    set_node_t *node_2 = set_insert(table, "Key_2", strlen("Key_2"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[1]);
    CLOVE_STRING_EQ("Key_0", table->nodes[1]->key);
    CLOVE_PTR_EQ(node_1, table->nodes[0]);
    CLOVE_STRING_EQ("Key_1", table->nodes[0]->key);
    CLOVE_PTR_EQ(node_2, table->nodes[1]->next);
    CLOVE_STRING_EQ("Key_2", table->nodes[1]->next->key);
    CLOVE_NULL(node_2->next);
    CLOVE_NULL(table->nodes[2]);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_InsertAlreadyExistingKeyOneHash)
{
    set_table_t *table = set_table_new(1);

    set_node_t *node_0 = set_insert(table, "Key_0", strlen("Key_0"));
    set_node_t *node_1 = set_insert(table, "Key_0", strlen("Key_0"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[0]);
    CLOVE_STRING_EQ("Key_0", table->nodes[0]->key);
    CLOVE_NULL(table->nodes[0]->next);
    CLOVE_NULL(node_1);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_InsertAlreadyExistingKeyMultipleHash)
{
    set_table_t *table = set_table_new(5);

    set_node_t *node_0 = set_insert(table, "Key_0", strlen("Key_0"));
    set_node_t *node_1 = set_insert(table, "Key_0", strlen("Key_0"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(node_0, table->nodes[1]);
    CLOVE_STRING_EQ("Key_0", table->nodes[1]->key);
    CLOVE_NULL(table->nodes[1]->next);
    CLOVE_NULL(table->nodes[0]);
    CLOVE_NULL(table->nodes[2]);
    CLOVE_NULL(table->nodes[3]);
    CLOVE_NULL(table->nodes[4]);
    CLOVE_NULL(node_1);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_SearchOnNullTable)
{
    set_table_t *table = set_table_new(-1);

    set_node_t *inserted = set_insert(table, "Key_0", strlen("Key_0"));

    set_node_t *searched = set_search(table, "Key_0", strlen("Key_0"));

    CLOVE_NULL(table);
    CLOVE_NULL(inserted);
    CLOVE_NULL(searched);
}

CLOVE_TEST(Set_SearchOnSingleHash)
{
    set_table_t *table = set_table_new(1);

    set_node_t *nodes[4];
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
        nodes[i] = set_insert(table, result_strings[i], strlen(result_strings[i]));
    }

    set_node_t *searched = set_search(table, "Key_2", strlen("Key_2"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[2], searched);
    CLOVE_STRING_EQ(nodes[2]->key, searched->key);
    CLOVE_PTR_EQ(searched, table->nodes[0]->next->next);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_SearchOnMultipleHash)
{
    set_table_t *table = set_table_new(2);

    set_node_t *nodes[4];
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
        nodes[i] = set_insert(table, result_strings[i], strlen(result_strings[i]));
    }

    set_node_t *searched_1 = set_search(table, "Key_1", strlen("Key_1"));
    set_node_t *searched_2 = set_search(table, "Key_2", strlen("Key_2"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[1], searched_1);
    CLOVE_PTR_EQ(nodes[2], searched_2);
    CLOVE_STRING_EQ(nodes[1]->key, searched_1->key);
    CLOVE_STRING_EQ(nodes[2]->key, searched_2->key);
    CLOVE_PTR_EQ(searched_1, table->nodes[0]);
    CLOVE_PTR_EQ(searched_2, table->nodes[1]->next);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_SearchFailsOnKey)
{
    set_table_t *table = set_table_new(1);

    set_node_t *inserted = set_insert(table, "Key_0", strlen("Key_0"));

    set_node_t *searched = set_search(table, "Key_3", strlen("Key_3"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(inserted, table->nodes[0]);
    CLOVE_STRING_EQ(inserted->key, table->nodes[0]->key);
    CLOVE_NULL(searched);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_SearchFailsOnKeyLen)
{
    set_table_t *table = set_table_new(1);

    set_node_t *inserted = set_insert(table, "Key_0", strlen("Key_0"));

    set_node_t *searched = set_search(table, "Key_0", strlen("Key_01"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(inserted, table->nodes[0]);
    CLOVE_STRING_EQ(inserted->key, table->nodes[0]->key);
    CLOVE_NULL(searched);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_SearchHeadKeyOnNullTable)
{
    set_table_t *table = set_table_new(-1);

    set_node_t *inserted = set_insert(table, "Key_0", strlen("Key_0"));

    set_node_t *searched = set_search_keyList_head(table, "Key_0", strlen("Key_0"));

    CLOVE_NULL(table);
    CLOVE_NULL(inserted);
    CLOVE_NULL(searched);
}

CLOVE_TEST(Set_SearchHeadKeyOnSingleHash)
{
    set_table_t *table = set_table_new(1);

    set_node_t *nodes[4];
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
        nodes[i] = set_insert(table, result_strings[i], strlen(result_strings[i]));
    }

    set_node_t *searched = set_search_keyList_head(table, "Key_2", strlen("Key_2"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[0], searched);
    CLOVE_STRING_EQ(nodes[0]->key, searched->key);
    CLOVE_NOT_NULL(table->nodes[0]->next);


    set_table_destroy(&table);
}

CLOVE_TEST(Set_SearchHeadKeyOnMultipleHash)
{
    set_table_t *table = set_table_new(2);

    set_node_t *nodes[4];
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
        nodes[i] = set_insert(table, result_strings[i], strlen(result_strings[i]));
    }

    set_node_t *searched_0 = set_search_keyList_head(table, "Key_1", strlen("Key_1"));
    set_node_t *searched_1 = set_search_keyList_head(table, "Key_2", strlen("Key_2"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[0], searched_1);
    CLOVE_PTR_EQ(nodes[1], searched_0);
    CLOVE_STRING_EQ(nodes[0]->key, searched_1->key);
    CLOVE_STRING_EQ(nodes[1]->key, searched_0->key);
    CLOVE_PTR_EQ(searched_1, table->nodes[1]);
    CLOVE_PTR_EQ(searched_0, table->nodes[0]);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_RemoveOnNullTable)
{
    set_table_t *table = set_table_new(-1);

    set_node_t *inserted = set_insert(table, "Key_0", strlen("Key_0"));

    set_node_t *removed = set_remove(table, "Key_0", strlen("Key_0"));

    CLOVE_NULL(table);
    CLOVE_NULL(inserted);
    CLOVE_NULL(removed);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_RemoveNotInsertedKey)
{
    set_table_t *table = set_table_new(1);

    set_node_t *inserted = set_insert(table, "Key_0", strlen("Key_0"));

    set_node_t *removed = set_remove(table, "Key_1", strlen("Key_1"));

    CLOVE_NOT_NULL(table);
    CLOVE_NOT_NULL(inserted);
    CLOVE_NULL(removed);

    set_table_destroy(&table);
}

CLOVE_TEST(Set_RemoveLastElement)
{
    set_table_t *table = set_table_new(1);

    set_node_t *inserted = set_insert(table, "Key_0", strlen("Key_0"));

    set_node_t *removed = set_remove(table, "Key_0", strlen("Key_0"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(inserted, removed);
    CLOVE_STRING_EQ(inserted->key, removed->key);

    set_table_destroy(&table);
    set_node_destroy(&removed);

}

CLOVE_TEST(Set_RemoveHeadKey)
{
    set_table_t *table = set_table_new(1);

    set_node_t *nodes[4];
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
        nodes[i] = set_insert(table, result_strings[i], strlen(result_strings[i]));
    }

    set_node_t *removed = set_remove(table, "Key_0", strlen("Key_0"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[0], removed);
    CLOVE_STRING_EQ(nodes[0]->key, removed->key);
    CLOVE_PTR_EQ(nodes[1], table->nodes[0]);
    CLOVE_STRING_EQ(nodes[1]->key,  table->nodes[0]->key);
    CLOVE_NULL(removed->next);


    set_table_destroy(&table);
    set_node_destroy(&removed);

}

CLOVE_TEST(Set_RemoveSuccess)
{
    set_table_t *table = set_table_new(2);

    set_node_t *nodes[4];
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
        nodes[i] = set_insert(table, result_strings[i], strlen(result_strings[i]));
    }

    set_node_t *removed = set_remove(table, "Key_2", strlen("Key_2"));

    CLOVE_NOT_NULL(table);
    CLOVE_PTR_EQ(nodes[2], removed);
    CLOVE_STRING_EQ(nodes[2]->key, removed->key);
    CLOVE_NULL(table->nodes[1]->next);
    CLOVE_NULL(removed->next);


    set_table_destroy(&table);
    set_node_destroy(&removed);
}

CLOVE_SUITE(Test_Set)
{

    CLOVE_SUITE_TESTS(Set_TableNewZeroSize, Set_TableNewSizeOutOfBounds, Set_InsertOnNullTable, Set_InsertOneKeyOneHash, Set_InsertTwoKeysOneHash,
                      Set_InsertOneKeysTwoHash, Set_InsertTwoKeysTwoHash, Set_InsertThreeKeysTwoHash, Set_InsertAlreadyExistingKeyOneHash,
                      Set_InsertAlreadyExistingKeyMultipleHash, Set_SearchOnNullTable, Set_SearchOnSingleHash, Set_SearchOnMultipleHash,
                      Set_SearchFailsOnKey, Set_SearchFailsOnKeyLen, Set_SearchHeadKeyOnNullTable, Set_SearchHeadKeyOnSingleHash, Set_SearchHeadKeyOnMultipleHash,
                      Set_RemoveOnNullTable, Set_RemoveNotInsertedKey, Set_RemoveLastElement, Set_RemoveHeadKey, Set_RemoveSuccess);
}