/**
 * Header file for llib i/o stuff
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_IO_H__
#define LLIB_IO_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

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

/**
 * @brief Clears stdin by discarding every 
 * character until a '\n' or EOF is detected
 */
void clearInBuf(void);

/**
 * @brief Reads input from stdin based on the specified format and stores it at the provided address.
 * Automatically clears the buffer at the end.
 *
 * @param format The format string for reading input.
 * @param address Pointer to the memory location where the input will be stored.
 *
 * @return The number of input items successfully matched and assigned.
 */
int input(const char* format, void* address);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !LLIB_IO_H__