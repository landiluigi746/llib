/**
 * Header file for llib utils
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_UTILS_H__
#define LLIB_UTILS_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
 * @brief Waits for (approximately) milliseconds milliseconds using
 * clock from time.h
 * 
 * @param milliseconds Milliseconds to wait
*/
void wait(uint32_t milliseconds);

/**
 * @brief Returns a FILE pointer to a file opened with given fileName
 * in given fileMode. If the opening fails, exits the program
 * 
 * @param fileName Name of the file to open
 * @param fileMode Mode of the file
*/
FILE* openFile(const char* fileName, const char* fileMode);

#ifdef __cplusplus
}
#endif

#endif // !LLIB_UTILS_H__