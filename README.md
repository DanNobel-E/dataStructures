# DataStructures

## Description
Data structures C library with generic implementation using preprocessor directives.

On current release:

* Linked Lists
* Doubly Linked Lists
* Sets
* Dictionaries



## Linked List

#### About

#### Functions



## Doubly Linked List

#### About

#### Functions



## Set

#### About

#### Functions
| **Name** | **Params**| **Return** | **Description** |
|----------|-----------|------------|-----------------|
| **set_djb33x_hash** | *key*: key string to hash. <br/><br/> *keylen*: length in byte of the key to hash. | Hash value of the current key. | returns an hashing value of the given string, following djb33x algorithm. |
| **set_table_new** | *hashmap_size*: size used to clamp hashmap values. New table will count hashmap_size key lists. | A pointer to generated set table. | Generates a set table of hashmap_size node lists. |
| **set_insert** | *table*: pointer to set table where to insert new key. <br/><br/> *key*: new key to insert. <br/><br/> *keylen*: lenght in bytes of the new key. | A pointer to the set node which contains the new key. | Insterts a new key on given set table. |
| **set_search** | *table*: pointer to set table where to search given key. <br/><br/> *key*: key to search for. <br/><br/> *keylen*: lenght in bytes of the searched key. | A pointer to the set node of the searched key. | Searches if the given table contains the given key. |
| **set_search_keyList_head** | *table*: pointer to set table where to search key list head. <br/><br/> *key*: key to search for. <br/><br/> *keylen*: lenght in bytes of the searched key.  | A pointer to the set head node of the searched key. | Returns the head of the key list which contains the given key, according to table hashmap size. |
| **set_remove** | *table*: pointer to set table where to remove given key. <br/><br/> *key*: key to remove. <br/><br/> *keylen*: lenght in bytes of the key to remove. | A pointer to the set node of the removed key. | If current key is contained in given table, removes it and returns the related list node.  |
| **set_node_destroy** | *node_ptr*: pointer to set node to destroy. | - | Frees memory allocated by the given set node. |
| **set_table_destroy** | *table_ptr*: pointer to set table to destroy. | - | Frees memory allocated by the given set table. |
| **set_print_keys** | *table*: table to print. | - | Prints all the keys in the given table. |

## Dictionary

#### About

#### Functions
