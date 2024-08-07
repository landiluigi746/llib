/**
 * Header file for llib list
 * 
 * Author: landiluigi746
 * Date: 2024-07-22
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_LIST_H__
#define LLIB_LIST_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <llib_memory.h>

/**
 * llib defines
*/
#ifndef LLIB_UTIL_DEFINES
#define LLIB_UTIL_DEFINES

#define NULLPTR NULL
#define NOT_FOUND -1
#define min(a, b) (a) < (b) ? a : b
#define max(a, b) (a) > (b) ? a : b
typedef unsigned char byte;

#endif // !LLIB_UTIL_DEFINES

#if !defined(ASCENDING) && !defined(DESCENDING)
#define ASCENDING 0
#define DESCENDING 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Struct for a node in a doubly linked list
 * 
 * 
 */
typedef struct node_s
{
    void* data;
    struct node_s* prev;
    struct node_s* next;
} node;

/**
 * @brief Create a new empty node (with no data and no links)
 * 
 * @returns Pointer to the new node
 */
node* nodeCreate(void);

/**
 * Struct for a doubly linked list, 0-indexed
 * 
 * Not meant to be used directly, use the related functions
 * Use the related functions instead
 */
typedef struct
{
    node* head;
    node* tail;
    size_t size;
} list;

/**
 * @brief Create a new list
 * 
 * @return Pointer to the new list
 */
list* listCreate(void);

/**
 * @brief Delete a list
 * 
 * @param li The list to delete
 */
void listDelete(list* li);

/**
 * @brief Duplicate a list
 * 
 * @param li The list to duplicate
 * 
 * @returns The duplicated list
 */
list* listDuplicate(list* li);

/**
 * @brief Push a node to the end of the list
 * 
 * @param li The list
 * @param data The data to push
 */
void listPushBack(list* li, const void* data);

/**
 * @brief Pop a node from the end of the list
 * 
 * @param li The list
 */
void listPopBack(list* li);

/**
 * @brief Search for a node in the list
 * 
 * @param li The list
 * @param data The data to search for
 * @param compare The comparison function
 * 
 * @returns Pointer to the node if found, NULLPTR otherwise
 */
node* listSearch(list* li, const void* data, int (*compare)(const void*, const void*));

/**
 * @brief Insert a node at a specified index
 * 
 * @param li The list
 * @param index The index to insert the node at
 * @param data The data to insert
 */
void listInsert(list* li, int index, const void* data);

/**
 * @brief Remove a node from the list
 * 
 * @param li The list
 * @param index The index of the node to remove
 */
void listRemove(list* li, int index);

/**
 * @brief Get the index of a node in the list
 * 
 * @param li The list
 * @param no The node
 * 
 * @returns The index of the node, NOT_FOUND if not found
 */
int listGetNodeIndex(list* li, const node* no);

/**
 * @brief Sort the list using Insertion Sort
 * If order is neither ASCENDING nor DESCENDING, ASCENDING is assumed
 * 
 * @param li The list
 * @param compare The comparison function
 * @param order ASCENDING if the list should be sorted in ascending order, DESCENDING otherwise
 */
void listSort(list* li, int (*compare)(const void*, const void*), int order);

#ifdef __cplusplus
}
#endif

#endif // !LLIB_LIST_H__