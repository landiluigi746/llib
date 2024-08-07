/**
 * Header file for llib darray
 * 
 * Author: landiluigi746
 * Date: 2024-07-23
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_DARRAY_H__
#define LLIB_DARRAY_H__

#include <stdint.h>
#include <stdbool.h>
#include <llib/llib_memory.h>

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
 * Struct for a darray
 * It's kinda like a C-clone of C++'s std::vector.
 * 
 * Not meant to be used directly, use the related functions
 */
typedef struct {
    byte* data;
    size_t elementSize;
    size_t size;
    size_t capacity;
} darray;

/**
 * @brief Create a new darray
 * 
 * @param elementSize Size of each element in the darray
 * @param capacity Capacity of the darray
 * 
 * @returns Pointer to the new darray
 */
darray* darrayCreate(size_t elementSize, size_t capacity);

/**
 * @brief Macro that creates a new darray with given type and capacity
 * It's useful if you don't know the size of the elements beforehand
 * 
 * @param type The type of the elements in the darray
 * @param capacity The capacity of the darray
 */
#define DARRAY(type, capacity) darrayCreate(sizeof(type), capacity)

/**
 * @brief Delete a darray
 * 
 * @param darr The darray to delete
 */
void darrayDelete(darray* darr);

/**
 * @brief Resize a darray
 * If the new capacity is smaller than the current size, the excess data is discarded
 * 
 * @param darr The darray to resize
 * @param newCapacity The new capacity of the darray
 */
void darrayResize(darray* darr, size_t newCapacity);

/**
 * @brief Push data to the end of the darray
 * 
 * @param darr The darray to push data to
 * @param data The data to push
 */
void darrayPushBack(darray* darr, const void* data);

/**
 * @brief Pop data from the end of the darray
 * If the darray is empty, nothing happens
 * 
 * @param darr The darray to pop data from
 */
void darrayPopBack(darray* darr);

/**
 * @brief Insert data at a specific index
 * If the index is out of bounds, nothing happens
 * 
 * @param darr The darray to insert data into
 * @param index The index to insert at
 * @param data The data to insert
 */
void darrayInsertAt(darray* darr, size_t index, const void* data);

/**
 * @brief Insert data in order
 * 
 * @param darr The darray to insert data into
 * @param data The data to insert
 * @param compare The comparison function
 */
void darrayInsertInOrder(darray* darr, const void* data, int (*compare)(const void*, const void*));

/**
 * @brief Remove data from the darray
 * If the index is out of bounds, nothing happens
 * 
 * @param darr The darray to remove data from
 * @param index The index of the data to remove
 */
void darrayRemove(darray* darr, size_t index);

/**
 * @brief Set data at a specific index
 * If the index is out of bounds, nothing happens
 * 
 * @param darr The darray to set data in
 * @param index The index to set data at
 * @param newData The data to set
 */
void darraySet(darray* darr, size_t index, const void* newData);

/**
 * @brief Get data from the darray
 * If the index is out of bounds, NULLPTR is returned
 * 
 * @param darr The darray to get data from
 * @param index The index of the data
 * @returns Pointer to the data at the index
 */
void* darrayGet(darray* darr, size_t index);

/**
 * Algorithms functions
 * 
 * These functions simply are wrappers around the llib_algorithms.h functions.
 * 
 * For more info, see llib_algorithms.h
 */

/**
 * @brief Sort the darray using the given comparison function
 * If the order is neither ASCENDING or DESCENDING, ASCENDING is assumed
 * @see llib_algorithms.h sort()
 * 
 * @param darr The darray to sort
 * @param compare The comparison function
 * @param order The order to sort in
 */
void darraySort(darray* darr, int (*compare)(const void*, const void*), int order);

/**
 * @brief Search the darray for data using linear search
 * @see llib_algorithms.h lSearch()
 * 
 * @param darr The darray to search
 * @param data The data to search for
 * @param compare The comparison function
 * 
 * @returns The index of the data if found, -1 otherwise
 */
int darrayLSearch(darray* darr, const void* data, int (*compare)(const void*, const void*));

/**
 * @brief Search the darray for data using binary search
 * If the order is neither ASCENDING or DESCENDING, ASCENDING is assumed
 * @see llib_algorithms.h bSearch()
 * 
 * @param darr The darray to search
 * @param data The data to search for
 * @param compare The comparison function
 * @param order The order the darray is sorted in (ASCENDING or DESCENDING)
 * 
 * @returns The index of the data if found, -1 otherwise
 */
int darrayBSearch(darray* darr, const void* data, int (*compare)(const void*, const void*), int order);

/**
 * @brief Search in the darray for occurrences of data using linear search
 * @see llib_algorithms.h lSearchOccurrences()
 * 
 * @param darr The darray to search
 * @param data The data to search for
 * @param compare The comparison function
 * @param occurrences The array to store the occurrences in
 * @param occurrencesSize The size of the array
 * 
 * @returns The number of occurrences
 */
size_t darrayLSearchOccurrences(darray* darr, const void* data, int (*compare)(const void*, const void*), size_t* occurrences, size_t occurrencesSize);

/**
 * @brief Search in the darray for occurrences of data using binary search
 * If the order is neither ASCENDING or DESCENDING, ASCENDING is assumed
 * @see llib_algorithms.h bSearchOccurrences()
 * 
 * @param darr The darray to search
 * @param data The data to search for
 * @param compare The comparison function
 * @param order The order the darray is sorted in (ASCENDING or DESCENDING)
 * @param occurrences The array to store the occurrences in
 * @param occurrencesSize The size of the array
 * 
 * @returns The number of occurrences
 */
size_t darrayBSearchOccurrences(darray* darr, const void* data, int (*compare)(const void*, const void*), int order, size_t* occurrences, size_t occurrencesSize);

#ifdef __cplusplus
}
#endif

#endif // !LLIB_DARRAY_H__