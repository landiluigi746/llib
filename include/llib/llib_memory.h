/**
 * Header file for llib memory stuff
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_MEMORY_H__
#define LLIB_MEMORY_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
#endif

/**
 * @brief Checks if the given pointer is null
 * If yes, exits the program with an error message.
 * Intended to use when a null pointer is fatal.
 * 
 * @param ptr The pointer to check
 */
void checkNullPtr(const void* ptr);

/**
 * @brief Allocates size bytes and returns a pointer to it
 * If the allocation fails, exits the program.
 * 
 * @param size Number of bytes to allocate
 * 
 * @returns Pointer to the allocated memory
 */
void* allocate(size_t size);

/**
 * @brief Deallocates the memory pointer by ptr
 * 
 * @param ptr Pointer to the memory to deallocate
 */
void deallocate(void* ptr);

/**
 * @brief Reallocates the memory pointer by ptr to size
 * If the reallocation fails, exits the program.
 * 
 * @param ptr Pointer to the memory to reallocate
 * @param size Number of bytes of the new allocated memory
 * @returns Pointer to the new allocated memory
 */
void* reallocate(void* ptr, size_t size);

/**
 * @brief Sets the content of the memory pointed by ptr to value
 * 
 * @param ptr Pointer to the memory
 * @param size Size of the memory
 * @param value Value to set
 */
void setMemory(void* ptr, size_t size, uint8_t value);

/**
 * @brief Copies the content of the segment src-srcSize into the segment dst-dstSize
 * 
 * @param src Source segment
 * @param dst Destination segment
 * @param srcSize Size of the source segment
 * @param dstSize Size of the destination segment
 */
void copyMemory(const void* src, void* dst, size_t srcSize, size_t dstSize);

/**
 * @brief Copies the content of the array src to the array dst.
 * 
 * @param src Source array
 * @param dst Destination array
 * @param sizeof_t Size of each element in the array
 * @param size Number of elements in the array
 */
void copyArray(const void* src, void* dst, size_t sizeof_t, size_t size);

/**
 * @brief Allocates size bytes, initializes it with value and returns a pointer to it
 * 
 * @param size Number of bytes to allocate
 * @param value Value to initialize
 * 
 * @returns Pointer to the allocated memory
 */
void* allocateInit(size_t size, uint8_t value);

/**
 * @brief Swaps the content of two pointers
 * Assumes that the size of the elements by the pointers is the same
 * 
 * @param a First pointer
 * @param b Second pointer
 * @param sizeof_t Size of the element pointed by the pointers
 */
void swap(void* a, void* b, size_t sizeof_t);

/**
 * @brief Macro that simulates dst = src.
 * Intended to use instead of a copyMemory(src, dst, size, size)
 * 
 * @param dst Destination pointer
 * @param src Source pointer
 * @param size Number of bytes
 */
#define ASSIGN(dst, src, size) copyMemory(src, dst, size, size)

#ifdef __cplusplus
}
#endif

#endif // !LLIB_MEMORY_H__