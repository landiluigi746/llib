/**
 * Header file for llib algorithms
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_ALGORITHMS_H__
#define LLIB_ALGORITHMS_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
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

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define ASCENDING 0
#define DESCENDING 1

/**
 * @brief Linear search algorithm.
 *
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * @param value Pointer to the value to be searched.
 * @param compare Pointer to the comparison function.
 *
 * @returns Index of the element if found, or -1 if not found.
 */
int lSearch(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*));

/**
 * @brief Binary search algorithm.
 * If order is neither ASCENDING nor DESCENDING, ASCENDING is assumed.
 *
 * @param base Pointer to the base address of the sorted array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * @param value Pointer to the value to be searched.
 * @param order ASCENDING if the array should be sorted in ascending order, DESCENDING otherwise.
 * @param compare Pointer to the comparison function.
 *
 * @return Index of the element if found, or -1 if not found.
 */
int bSearch(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*), int order);

/**
 * @brief Linear search for occurrences of a value in an array.
 * 
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * @param value Pointer to the value to be searched.
 * @param compare Pointer to the comparison function.
 * @param occurrences Pointer to the array where the occurrences will be stored.
 * @param occurrencesSize Size of the occurrences array.
 * 
 * @returns Number of occurrences of the value if found, or 0 if not found.
 */
size_t lSearchOccurrences(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*), size_t* occurrences, size_t occurrencesSize);

/**
 * @brief Binary search for occurrences of a value in an array.
 * If order is neither ASCENDING nor DESCENDING, ASCENDING is assumed.
 * 
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * @param value Pointer to the value to be searched.
 * @param compare Pointer to the comparison function.
 * @param order ASCENDING if the array should be sorted in ascending order, DESCENDING otherwise.
 * @param occurrences Pointer to the array where the occurrences will be stored.
 * @param occurrencesSize Size of the occurrences array.
 * 
 * @returns Number of occurrences of the value if found, or 0 if not found.
 */
size_t bSearchOccurrences(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*), int order, size_t* occurrences, size_t occurrencesSize);

/**
 * @brief Sorts an array using Merge Sort algorithm.
 * If order is neither ASCENDING nor DESCENDING, ASCENDING is assumed.
 * 
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * @param compare Pointer to the comparison function.
 * @param order ASCENDING if the array should be sorted in ascending order, DESCENDING otherwise.
 */
void sort(void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*), int order);

/**
 * @brief Reverses an array.
 * 
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 */
void reverse(void* base, size_t sizeof_t, size_t size);

/**
 * @brief Checks if an array is sorted.
 * If order is neither ASCENDING nor DESCENDING, ASCENDING is assumed.
 *
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * @param compare Pointer to the comparison function.
 * @param order ASCENDING if the array should be sorted in ascending order, DESCENDING otherwise.
 *
 * @returns 1 if the array is sorted, 0 otherwise.
 */
int isSorted(const void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*), int order);

/**
 * @brief Shuffles an array using the Fisher-Yates algorithm.
 * 
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * 
 * @warning Call srand for randomness before using this function
 */
void shuffle(void* base, size_t sizeof_t, size_t size);

#ifdef __cplusplus
}
#endif

#endif // !LLIB_ALGORITHMS_H__