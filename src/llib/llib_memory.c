/**
 * Implementation file for llib memory
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_memory.h>

void checkNullPtr(const void* ptr)
{
    if(ptr == NULLPTR)
    {
        printf("Error! Null pointer caught by checkNullPtr()!\n");
        exit(EXIT_FAILURE);
    }

    return;
}

void* allocate(size_t size)
{
    void* ptr = malloc(size);
    checkNullPtr(ptr);
    return ptr;
}

void deallocate(void* ptr)
{
    free(ptr);
    return;
}

void* reallocate(void* ptr, size_t size)
{
    void* newPtr = realloc(ptr, size);
    checkNullPtr(newPtr);
    return newPtr;
}

void setMemory(void* ptr, size_t size, uint8_t value)
{
    if(ptr == NULLPTR)
        return;

    byte* start = (byte*) ptr;

    while(size--)
        *start++ = value;
    
    return;
}

void copyMemory(const void* src, void* dst, size_t srcSize, size_t dstSize)
{
    if(src == NULLPTR || dst == NULLPTR || src == dst || srcSize == 0 || dstSize == 0)
        return;

    const byte* s = (const byte*) src;
    byte* d = (byte*) dst;

    while(srcSize-- > 0 && dstSize-- > 0 && s != d)
        *d++ = *s++;

    return;
}

void copyArray(const void* src, void* dst, size_t sizeof_t, size_t size)
{
    if(src == NULLPTR || dst == NULLPTR)
        return;
    
    const byte* s = (const byte*) src;
    byte* d = (byte*) dst;

    while(size--)
    {
        ASSIGN(d, s, sizeof_t);
        d += sizeof_t;
        s += sizeof_t;
    }

    return;
}

void* allocateInit(size_t size, uint8_t value)
{
    void* ptr = allocate(size);
    byte* start = (byte*) ptr;

    while(size--)
        *start++ = value;

    return ptr;
}

void swap(void* a, void* b, size_t sizeof_t)
{
    if(a == NULLPTR || b == NULLPTR)
        return;

    byte* a_ptr = (byte*) a;
    byte* b_ptr = (byte*) b;
    byte* temp_ptr = (byte*) allocate(sizeof_t);

    ASSIGN(temp_ptr, a_ptr, sizeof_t); //storing value of a in temp
    ASSIGN(a_ptr, b_ptr, sizeof_t); //storing value of b in a
    ASSIGN(b_ptr, temp_ptr, sizeof_t); //storing value of temp in b

    deallocate(temp_ptr);

    return;
}