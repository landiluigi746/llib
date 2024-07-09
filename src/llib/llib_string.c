/**
 * Implementation file for llib string
 * 
 * Author: landiluigi746
 * Date: 2024-07-09
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_string.h>

size_t ll_strlen(const char* str)
{
    if(str == NULLPTR)
        return 0;

    size_t count = 0;

    while(*str++ != '\0')
        count++;
    
    return count;
}

char* ll_strdup(const char* src)
{
    checkNullPtr(src);

    size_t count = 0, len = ll_strlen(src);
    char* duplicate = (char*) allocate(len + 1);

    while(*(src + count) != '\0')
    {
        *(duplicate + count) = *(src + count);
        ++count;
    }

    *(duplicate + count) = '\0';

    return duplicate;
}

int ll_strcmp(const char* str1, const char* str2)
{
    if(str1 != NULLPTR && str2 == NULLPTR)
        return 1;

    if(str1 == NULLPTR && str2 != NULLPTR)
        return -1;

    if((str1 == NULLPTR && str2 == NULLPTR) || str1 == str2)
        return 0;

    while(*str1 == *str2)
    {
        if(*str1 == '\0' || *str2 == '\0')
            return 0;

        ++str1;
        ++str2;
    }

    return ((*str1 - *str2) > 0) ? 1 : -1;
}

int ll_strncmp(const char* str1, const char* str2, size_t cmpCount)
{
    if(str1 != NULLPTR && str2 == NULLPTR)
        return 1;
    
    if(str1 == NULLPTR && str2 != NULLPTR)
        return -1;
    
    if((str1 == NULLPTR && str2 == NULLPTR) || str1 == str2)
        return 0;
    
    while(*str1 == *str2 && cmpCount > 0)
    {
        if(*str1 == '\0' || *str2 == '\0')
            return 0;
        
        ++str1;
        ++str2;
        --cmpCount;
    }
    
    return ((*str1 - *str2) > 0) ? 1 : -1;
}

string* strCreate(size_t capacity)
{
    string* str = (string*) allocate(sizeof(string));

    *str = (string){
        .buf = allocate(sizeof(char) * capacity),
        .len = 0,
        .capacity = capacity
    };

    return str;
}

string* strCreateFrom(const char* src)
{
    char* dup = ll_strdup(src);
    size_t len = ll_strlen(src);

    string* str = (string*) allocate(sizeof(string));

    *str = (string){
        .buf = dup,
        .len = len,
        .capacity = len + 1
    };

    return str;
}

string* strDuplicate(const string* src)
{
    string* str = strCreate(src->capacity);
    strCopy(src->buf, str);

    return str;
}

void strResize(string* str, size_t newCapacity)
{
    if(str == NULLPTR)
        return;
    
    if(str->buf == NULLPTR)
        str->buf = allocate(sizeof(char) * newCapacity);
    else
        str->buf = reallocate(str->buf, sizeof(char) * str->capacity);

    if(newCapacity < str->capacity)
    {
        str->len = newCapacity;
        str->buf[str->len] = '\0';
    }

    str->capacity = newCapacity;

    return;
}

void strDelete(string* str)
{
    deallocate(str->buf);
    deallocate(str);

    return;
}

size_t strInput(string* str)
{
    if(str->buf == NULLPTR)
        return 0;

    int c;
    size_t count = 0;

    while(count < str->capacity - 1 && (c = getchar()) != EOF && c != '\n')
        *(str->buf + count++) = (char)c;

    *(str->buf + count) = '\0';
    str->len = count;

    if(count == str->capacity - 1)
        clearInBuf();

    return count;
}

size_t strCopy(const char* src, string* dst)
{
    if(src == NULLPTR || dst == NULLPTR)
        return 0;
    
    size_t count = 0;

    while(*(src + count) != '\0' && count < dst->capacity - 1)
    {
        *(dst->buf + count) = *(src + count);
        ++count;
    }

    *(dst->buf + count) = '\0';
    dst->len = count;

    return count;
}

size_t strNCopy(const char* src, size_t copyCount, string* dst)
{
    if(src == NULLPTR || dst->buf == NULLPTR)
        return 0;

    size_t count = 0;

    while(*(src + count) != '\0' && count < copyCount && count < dst->capacity)
    {
        *(dst->buf + count) = *(src + count);
        ++count;
    }

    *(dst->buf + count) = '\0';
    dst->len = count;

    return count;
}

int strCompare(const string* str1, const string* str2)
{
    return ll_strcmp(str1->buf, str2->buf);
}

int strNCompare(const string* str1, const string* str2, size_t cmpCount)
{
    return ll_strncmp(str1->buf, str2->buf, cmpCount);
}

void strReverse(string* str, size_t limit)
{
    if(str->buf == NULLPTR)
        return;

    char* left = str->buf;
    char* right = str->buf + (min(str->len, limit) - 1);

    while(left < right)
    {
        swap(left, right, sizeof(char));

        ++left;
        --right;
    }

    return;
}

int strFind(const string* str, const char* strToFind)
{
    if(str->buf == NULLPTR || strToFind == NULLPTR)
        return NOT_FOUND;

    size_t i, findLen = ll_strlen(strToFind);

    if(str->len < findLen)
        return NOT_FOUND;

    for(i = 0; (i < str->len - findLen + 1) /*&& *(str->buf + i) != '\0'*/; i++)
    {
        if(ll_strcmp((str->buf + i), strToFind) == 0)
            return i;
    }

    return NOT_FOUND;
}

size_t strConcat(string* str1, const char* str2)
{
    if(str1->buf == NULLPTR || str2 == NULLPTR)
        return 0;
    
    size_t count = 0;
    char* start = str1->buf + str1->len;
    
    while(count < str1->capacity - 1 && *str2 != '\0')
        *(start + count++) = *str2++;
    
    *(start + count) = '\0';
    str1->len += count;

    return count;
}

void strCipher(string* str, size_t count)
{
    char* start = str->buf;

    if(start == NULLPTR)
        return;

    //avoid useless operations if there is nothing to encrypt
    if(count == 0 || count % ('~' - '!' + 1) == 0)
        return;

    count = count % ('~' - '!' + 1);

    while(*start != '\0')
    {
        if(!iscntrl(*start))
        {
            if((*start >= '!' && *start <= '~' - count))
                *start += count;
            else
                *start -= 94 - count;
        }
        
        ++start;
    }

    return;
}

void strDecipher(string* str, size_t count)
{
    char* start = str->buf;

    if(start == NULLPTR)
        return;

    //avoid useless operations if there is nothing to decrypt
    if(count == 0 || count % ('~' - '!' + 1) == 0)
        return;
    
    count = count % ('~' - '!' + 1);

    while(*start != '\0')
    {
        if(!iscntrl(*start))
        {
            if((*start >= '!' + count && *start <= '~'))
                *start -= count;
            else
                *start += 94 - count;
        }
        
        ++start;
    }

    return;
}