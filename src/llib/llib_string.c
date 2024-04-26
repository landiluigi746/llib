#include <llib/llib_string.h>

/**
 * @brief Takes a string in input and stores every char
 * in string until it's full or the string ends.
 * Automatically clears the input buffer.
 * 
 * @param string String where the input is stored
 * @param capacity Capacity of the string
 * 
 * @returns The number of stored characters
 */
size_t strInput(char* string, size_t capacity)
{
    if(string == NULLPTR)
        return 0;

    int c;
    size_t count = 0;
    char* stringEnd = string + capacity - 1;

    while((string + count) < stringEnd && (c = getchar()) != EOF && c != '\n')
        *(string + count++) = (char)c;

    *(string + count) = '\0';

    if((string + count) == stringEnd)
        clearInBuf();

    return count;
}

/**
 * @brief Finds the length of string
 * 
 * @param string String to check
 * 
 * @returns Length of string
 */
size_t strLength(const char* string)
{
    if(string == NULLPTR)
        return 0;

    size_t count = 0;

    while(*string++ != '\0')
        ++count;

    return count;
}

/**
 * @brief Copies the content of a string into another string
 * 
 * @param srcStr Source string
 * @param srcSize Count of characters to copy
 * @param dstStr Destination string
 * @param dstSize Size of the destination string
 * 
 * @returns Count of characters copied (including terminator)
 */
size_t strCopy(const char* srcStr, size_t srcSize, char* dstStr, size_t dstSize)
{
    if(srcStr == NULLPTR || dstStr == NULLPTR)
        return 0;

    size_t count = 0;
    
    char const* srcEnd = srcStr + srcSize - 1;
    char const* dstEnd = dstStr + dstSize - 1;

    while(*(srcStr + count) != '\0' && (srcStr + count) < srcEnd && (dstStr + count) < dstEnd)
    {
        *(dstStr + count) = *(srcStr + count);
        ++count;
    }

    *(dstStr + count) = '\0';

    return count;
}

/**
 * @brief Compare two strings alphabetically
 * 
 * @param string1 String 1
 * @param string2 String 2
 * 
 * @returns -1 if string1 < string2, 0 if string1 == string2, 1 if string1 > string2
 */
int strCompare(const char* string1, const char* string2)
{
    if(string1 == NULLPTR || string2 == NULLPTR)
        return 0;

    while(*string1 != '\0' && *string2 != '\0')
    {
        if(*string1 > *string2)
            return 1;
        else if(*string1 < *string2)
            return -1;

        ++string1;
        ++string2;
    }

    return 0;
}

/**
 * @brief Reverses a string of length characters
 * 
 * @param string String to reverse
 * @param length Length of string
 */
void strReverse(char* string, size_t length)
{
    if(string == NULLPTR)
        return;

    char* left = string;
    char* right = string + length - 1;

    while(left < right)
    {
        swap(left, right, sizeof(char));

        ++left;
        --right;
    }

    return;
}

/**
 * @brief Finds the first occurrence of strToFind in string
 * 
 * @param string String to search in
 * @param length Length of string
 * @param strToFind String to search for
 * 
 * @returns Index of the first occurrence or -1 if not found
 */
int strFind(const char* string, size_t length, const char* strToFind)
{
    if(string == NULLPTR || strToFind == NULLPTR)
        return NOT_FOUND;

    size_t i;

    for(i = 0; i < length - 1 && *(string + i) != '\0'; i++)
    {
        if(strCompare((string + i), strToFind) == 0)
            return i;
    }

    return NOT_FOUND;
}

/**
 * @brief Concatenates two strings (string1 and string2) in dest
 * 
 * @param string1 String 1
 * @param str1len Length of string 1
 * @param string2 String 2
 * @param str2len Length of string 2
 * @param dest Destination string
 * @param destSize Size of destination string
 * 
 * @returns Length of the concatenated string
 */
int strConcat(const char* string1, size_t str1len, const char* string2, size_t str2len, char* dest, size_t destSize)
{
    if(string1 == NULLPTR || string2 == NULLPTR || dest == NULLPTR)
        return 0;
    
    size_t count = 0;
    char const* destEnd = dest + destSize - 1;

    while((dest + count) < destEnd && *string1 != '\0')
        *(dest + count++) = *string1++;
    
    while((dest + count) < destEnd && *string2 != '\0')
        *(dest + count++) = *string2++;
    
    *(dest + count) = '\0';

    return count;
}

/**
 * @brief Encrypts a string using Caesar's cipher
 * 
 * @param string String to encrypt
 * @param count Number of characters to shift
 */
void strCipher(char* string, size_t count)
{
    if(string == NULLPTR)
        return;

    if(count > '~' - '!')
        count = 1;

    while(*string != '\0')
    {
        if(iscntrl(*string))
            goto next;

        if((*string >= '!' && *string <= '~' - count))
            *string += count;
        else
            *string -= 94 - count;

        next:
            ++string;
    }

    return;
}

/**
 * @brief Decrypts a string using Caesar's cipher
 * 
 * @param string String to decrypt
 * @param count Number of characters to unshift
 */
void strDecipher(char* string, size_t count)
{
    if(string == NULLPTR)
        return;

    if(count > '~' - '!')
        count = 1;

    while(*string != '\0')
    {
        if(iscntrl(*string))
            goto next;

        if((*string >= '!' + count && *string <= '~'))
            *string -= count;
        else
            *string += 94 - count;

        next:
            ++string;
    }

    return;
}