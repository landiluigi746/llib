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
 * 
 * Not meant to be used directly, use the related functions
 * It's kinda like a C-clone of C++'s std::vector.
 */
typedef struct {
    void* data;
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
 * 
 * @param darr The darray to pop data from
 */
void darrayPopBack(darray* darr);

/**
 * @brief Push data to the beginning of the darray
 * 
 * @param darr The darray to push data to
 * @param data The data to push
 */
void darraySet(darray* darr, size_t index, const void* newData);

/**
 * @brief Get data from the darray
 * 
 * @param darr The darray to get data from
 * @param index The index of the data
 * @returns The data at the index
 */
void* darrayGet(darray* darr, size_t index);

/**
 * @brief Sort the darray using the given comparison function
 * If the order is neither ASCENDING or DESCENDING, ASCENDING is assumed
 * 
 * @param darr The darray to sort
 * @param compare The comparison function
 * @param order ASCENDING or DESCENDING
 */
void darraySort(darray* darr, int (*compare)(const void*, const void*), int order);

#ifdef __cplusplus
}
#endif

#endif // !LLIB_DARRAY_H__