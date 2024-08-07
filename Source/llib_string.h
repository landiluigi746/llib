/**
 * Header file for llib string-related stuff
 * 
 * Author: landiluigi746
 * Date: 2024-07-09
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_STRING_H__
#define LLIB_STRING_H__

#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>
#include <llib_io.h>
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

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * Struct for a string
 * 
 * Not meant to be used directly, use the related functions
 * 
 * Do not confuse this with a C-clone of std::string
 * In fact, std::string typically resizes its internal buffer when needed,
 * but this string struct does not do that.
 * 
 * It is meant to be used as a simple wrapper around a char*
 */
typedef struct
{
    char* buf;
    size_t len;
    size_t capacity;
} string;

/* Utility functions */
size_t ll_strlen(const char* str);
char* ll_strdup(const char* src);
int ll_strcmp(const char* str1, const char* str2);
int ll_strncmp(const char* str1, const char* str2, size_t cmpCount);

/**
 * @brief Create a new string from a char array
 * 
 * @param src The char array
 * 
 * @returns Pointer to the new string
 */
string* strCreateFrom(const char* src);

/**
 * @brief Create a new string
 * 
 * @param capacity The capacity of the string
 * 
 * @returns Pointer to the new string
 */
string* strCreate(size_t capacity);

/**
 * @brief Duplicate a string
 * 
 * @param src The string to duplicate
 * 
 * @returns Pointer to the new string
 */
string* strDuplicate(const string* src);

/**
 * @brief Resize a string
 * 
 * @param str The string to resize
 * @param newCapacity The new capacity of the string
 */
void strResize(string* str, size_t newCapacity);

/**
 * @brief Delete a string
 * 
 * @param str The string to delete
 */
void strDelete(string* str);

/**
 * @brief Print to a string
 * 
 * @param str The string to print to
 * @param fmt The format string
 * 
 * @returns The length of the formatted string or -1 on NULLPTR string
 */
int strPrintf(string* str, const char* fmt, ...);

/**
 * @brief Get input from the user
 * 
 * @param str The string to store the input in
 * 
 * @returns The length of the input
 * 
 * Make sure to have a buffer where the input will be stored
 */
size_t strInput(string* str);

/**
 * @brief Copy a string
 * 
 * @param src The string (char array) to copy
 * @param dst The destination (struct string) string
 * 
 * @returns The length of the copied string
 */
size_t strCopy(const char* src, string* dst);

/**
 * @brief Copy a string
 * 
 * @param src The string (char array) to copy
 * @param dst The destination (struct string) string
 * @param copyCount The number of characters to copy
 * 
 * @returns The length of the copied string
 */
size_t strNCopy(const char* src, size_t copyCount, string* dst);

/**
 * @brief Compare two strings
 * 
 * @param str1 The first string
 * @param str2 The second string
 * 
 * @returns -1 if str1 < str2, 0 if str1 == str2, 1 if str1 > str2
 */
int strCompare(const string* str1, const string* str2);

/**
 * @brief Compare two strings
 * 
 * @param str1 The first string
 * @param str2 The second string
 * @param cmpCount The number of characters to compare
 * 
 * @returns -1 if str1 < str2, 0 if str1 == str2, 1 if str1 > str2
 */
int strNCompare(const string* str1, const string* str2, size_t cmpCount);

/**
 * @brief Reverse a string
 * 
 * @param str The string to reverse
 * @param limit The number of characters to reverse
 */
void strReverse(string* str, size_t limit);

/**
 * @brief Find a substring in a string
 * 
 * @param str The string to search
 * @param strToFind The substring to search for
 * 
 * @returns The index of the first occurrence of strToFind in str or NOT_FOUND if not found
 */
int strFind(const string* str, const char* strToFind);

/**
 * @brief Concatenate two strings
 * 
 * @param str1 The first string (struct string), will be modified
 * @param str2 The second string (char array), will be appended to str1
 *
 * @returns The length of the concatenated string
 */
size_t strConcat(string* str1, const char* str2);

/**
 * @brief Encrypt a string
 * 
 * @param str The string to encrypt
 * @param count The number of characters to encrypt
 */
void strCipher(string* str, size_t count);

/**
 * @brief Decrypt a string
 * 
 * @param str The string to decrypt
 * @param count The number of characters to decrypt
 */
void strDecipher(string* str, size_t count);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !LLIB_STRING_H__