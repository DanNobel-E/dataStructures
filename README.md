# DataStructures

## Description
Data structures C library with generic implementation using preprocessor directives.

On current release:

* Linked Lists
* Doubly Linked Lists
* Sets
* Dictionaries


## Linked List

### About
> A **Linked List** is a collection of elements where each node owns a reference to the next one, head to tail.

### More
*Generic implementation* with five already implemented types for **list_item**:

* *int*
* *float*
* *char*
* *size_t*
* *string*

You can add new list item types by calling macros: 

* **item_t(*typename*)**
* **ptr_item_t(*typename*)**

where *typename* refers to an existing C native type or struct. 

### Functions
| **Name** | **Params**| **Return** | **Description** |
|----------|-----------|------------|-----------------|
| **item_new** | *value*: object value associated to the creating list item. <br/><br/> *typename*: type of the list item to create. | A pointer to the created list item. | Allocates memory for a list item of type typenam and returns its pointer. |
| **item_print_list** | *list*: pointer to list head item. <br/><br/> *typename*: list items type. | void | Prints all objects of the given list. |
| **list_append** | *head*: pointer to list's head pointer. <br/><br/> *item*: item to append. <br/><br/> *typename*: list items type. | A pointer to list's new item. | Appends a new item on list's tail. |
| **list_get_tail** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | A pointer to list's tail. | Get given list's tail item. |
| **list_pop** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | A pointer to popped item. | Pops out and returns the first list's item. Popped item next node bocomes list's new head node. |
| **list_invert** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | A pointer to list's new head. | Inverts all list's nodes links, putting list's tail as head and vice versa. |
| **list_copy_and_invert** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | A pointer to new list's head. | Makes a copy of all items in the given list. Then inverts their links. |
| **list_remove** | *head*: pointer to list's head pointer. <br/><br/> *item*: item to remove. <br/><br/> *typename*: list items type. | A pointer to the removed item. | Checks if the given item is contained in the given list. If it does, the item gets removed and list's node links are recalculeted. |
| **list_destroy_item** | *item*: pointer to item pointer. <br/><br/> *typename*: item type. | void | Frees memory allocated by the given item. |
| **list_destroy** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | void | Frees memory allocated by all list's items. |


## Doubly Linked List

### About
> A **Doubly Linked List** is a linked list where each element owns a reference to both its next and previous neighbour node.

### More
*Generic implementation* with five already implemented types for **list_item**:

* *int*
* *float*
* *char*
* *size_t*
* *string*

You can add new list item types by calling macros: 

* **item_t(*typename*)**
* **ptr_item_t(*typename*)**

where *typename* refers to an existing C native type or struct. 

### Functions
| **Name** | **Params**| **Return** | **Description** |
|----------|-----------|------------|-----------------|
| **item_new** | *value*: object value associated to the creating list item. <br/><br/> *typename*: type of the list item to create. | A pointer to the created list item. | Allocates memory for a list item of type typenam and returns its pointer. |
| **item_print_list** | *list*: pointer to list head item. <br/><br/> *typename*: list items type. | void | Prints all objects of the given list. |
| **dlist_append** | *head*: pointer to list's head pointer. <br/><br/> *item*: item to append. <br/><br/> *typename*: list items type. | A pointer to list's new item. | Appends a new item on list's tail. |
| **dlist_get_element_at** | *head*: pointer to list's head pointer. <br/><br/> *index*: index of the element to get. <br/><br/> *typename*: list items type. | A pointer to list's item at the given index. | If given index is allowed, get list's item at the given index. |
| **dlist_get_tail** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | A pointer to list's tail. | Get given list's tail item. |
| **dlist_pop** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | A pointer to popped item. | Pops out and returns the first list's item. Popped item next node bocomes list's new head node. |
| **dlist_insert_before** | *head*: pointer to list's head pointer. <br/><br/> *target_item*: token item to point where to place the new item. <br/><br/> *item_to_insert*: item to insert before target_item.  <br/><br/> *typename*: list items type. | A pointer to list's new item. | If target_item is contained by the list and item_to_insert is not, inserts item_to_insert before target_item and recalculates list's nodes links. |
| **dlist_insert_after** | *head*: pointer to list's head pointer. <br/><br/> *target_item*: token item to point where to place the new item. <br/><br/> *item_to_insert*: item to insert after target_item.  <br/><br/> *typename*: list items type. | A pointer to list's new item. | If target_item is contained by the list and item_to_insert is not, inserts item_to_insert after target_item and recalculates list's nodes links. |
| **dlist_contains** | *head*: pointer to list's head pointer. *item*: item to check. <br/><br/> *typename*: list items type. | True if the given list contains the given item, false otherwise. | Tells if a specified item is cointained in the given list. |
| **dlist_count** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | Number of list items in the given list. | Gives informations about the number of elements of the given list. |
| **dlist_shuffle** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | A pointer to list's new head. | Shuffles the given list, randomizing list's nodes connections. |
| **dlist_remove** | *head*: pointer to list's head pointer. <br/><br/> *item*: item to remove. <br/><br/> *typename*: list items type. | A pointer to the removed item. | Checks if the given item is contained in the given list. If it does, the item gets removed and list's node links are recalculeted. |
| **dlist_remove_at** | *head*: pointer to list's head pointer. <br/><br/> *index*: index of the element to remove. <br/><br/> *typename*: list items type. | A pointer to the removed item. | Checks if the given index is allowed. If true, the list item at given index gets removed and list's node links are recalculeted. |
| **dlist_destroy_item** | *item*: pointer to item pointer. <br/><br/> *typename*: item type. | void | Frees memory allocated by the given item. |
| **dlist_destroy** | *head*: pointer to list's head pointer. <br/><br/> *typename*: list items type. | void | Frees memory allocated by all list's items. |



## Set

### About
> A **Set** is a list of quickly searchable values where each element is hashed to allow fast retrieval.

### Functions
| **Name** | **Params**| **Return** | **Description** |
|----------|-----------|------------|-----------------|
| **set_djb33x_hash** | *key*: key string to hash. <br/><br/> *keylen*: length in byte of the key to hash. | Hash value of the current key. | returns an hashing value of the given string, following djb33x algorithm. |
| **set_table_new** | *hashmap_size*: size used to clamp hashmap values. New table will count hashmap_size key lists. | A pointer to generated set table. | Generates a set table of hashmap_size node lists. |
| **set_insert** | *table*: pointer to set table where to insert new key. <br/><br/> *key*: new key to insert. <br/><br/> *keylen*: lenght in bytes of the new key. | A pointer to the set node which contains the new key. | Insterts a new key on given set table. |
| **set_search** | *table*: pointer to set table where to search given key. <br/><br/> *key*: key to search for. <br/><br/> *keylen*: lenght in bytes of the searched key. | A pointer to the set node of the searched key. | Searches if the given table contains the given key. |
| **set_search_keyList_head** | *table*: pointer to set table where to search key list head. <br/><br/> *key*: key to search for. <br/><br/> *keylen*: lenght in bytes of the searched key.  | A pointer to the set head node of the searched key. | Returns the head of the key list which contains the given key, according to table hashmap size. |
| **set_remove** | *table*: pointer to set table where to remove given key. <br/><br/> *key*: key to remove. <br/><br/> *keylen*: lenght in bytes of the key to remove. | A pointer to the set node of the removed key. | If current key is contained in given table, removes it and returns the related set node.  |
| **set_node_destroy** | *node_ptr*: pointer to set node to destroy. | void | Frees memory allocated by the given set node. |
| **set_table_destroy** | *table_ptr*: pointer to set table to destroy. | void | Frees memory allocated by the given set table. |
| **set_print_keys** | *table*: table to print. | void | Prints all the keys in the given table. |

## Dictionary

### About
> A **Dictionary** is a unique kind of set, where each hashed key is linked to a value.

### More
*Generic implementation* with five already implemented types for **dictionary_node** and **dictionary_table**:

* *int*
* *float*
* *char*
* *size_t*
* *string*

You can add new node/table types by calling macros: 

* **dictionary_node_t(*typename*)**
* **dictionary_table_t(*typename*)**

where *typename* refers to an existing C native type or struct. 

### Functions
| **Name** | **Params**| **Return** | **Description** |
|----------|-----------|------------|-----------------|
| **dictionary_djb33x_hash** | *key*: key string to hash. <br/><br/> *keylen*: length in byte of the key to hash. | Hash value of the current key. | returns an hashing value of the given string, following djb33x algorithm. |
| **dictionary_table_new** | *hashmap_size*: size used to clamp hashmap values. New table will count hashmap_size key lists. <br/><br/> *typename*: type of dictionary values. | A pointer to generated dictionary table. | Generates a dictionary table of hashmap_size node lists. |
| **dictionary_insert** | *table*: pointer to dictionary table where to insert new key. <br/><br/> *key*: new key to insert. <br/><br/> *keylen*: lenght in bytes of the new key. <br/><br/> *value*: value to access with the specified key. <br/><br/> *typename*: type of dictionary values.| A pointer to the dictionary node which contains the new key. | Insterts a new key on a given dictionary table. |
| **dictionary_change_value** | *table*: pointer to dictionary table where to change a value. <br/><br/> *key*: access key of the value to change. <br/><br/> *keylen*: lenght in bytes of the key. <br/><br/> *value*: new value of the given key. <br/><br/> *typename*: type of dictionary values. | A pointer to the dictionary node which contains the key of the overwritten value. | Overwrites the value of the given key with a new one. |
| **dictionary_search** | *table*: pointer to dictionary table where to search given key. <br/><br/> *key*: key to search for. <br/><br/> *keylen*: lenght in bytes of the searched key. <br/><br/> *typename*: type of dictionary values. | A pointer to the dictionary node of the searched key. | Searches if the given table contains the given key. |
| **dictionary_search_head** | *table*: pointer to dictionary table where to search key list head. <br/><br/> *key*: key to search for. <br/><br/> *keylen*: lenght in bytes of the searched key. <br/><br/> *typename*: type of dictionary values. | A pointer to the dictionary head node of the searched key. | Returns the head of the key list which contains the given key, according to table hashmap size. |
| **dictionary_remove** | *table*: pointer to dictionary table where to remove given key. <br/><br/> *key*: key to remove. <br/><br/> *keylen*: lenght in bytes of the key to remove. <br/><br/> *typename*: type of dictionary values. | A pointer to the dictionary node of the removed key. | If current key is contained in given table, removes it and returns the related dictionary node.  |
| **dictionary_destroy_node** | *node_ptr*: pointer to dictionary node to destroy. <br/><br/> *typename*: type of dictionary values.| void | Frees memory allocated by the given dictionary node. |
| **dictionary_destroy_table** | *table_ptr*: pointer to dictionary table to destroy. <br/><br/> *typename*: type of dictionary values. | void | Frees memory allocated by the given dictionary table. |
| **dictionary_print_keys** | *table*: table to print. <br/><br/> *typename*: type of dictionary values. | void | Prints all the keys in the given table. |
| **dictionary_print** | *table*: table to print. <br/><br/> *typename*: type of dictionary values. | void | Prints each key in the given table alongside its matching value. |


## Tests

Tests provided by using [Clove](https://github.com/fdefelici/clove-unit) test unit library.
