/**
 * Implementation file for llib algorithms
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#include <llib_algorithms.h>

//macro to simplify comparisons based on order
#define CMP_RESULT(a, b) ((order == ASCENDING) ? compare(a, b) : compare(b, a))

int lSearch(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*))
{
    if(base == NULLPTR || compare == NULLPTR || value == NULLPTR || sizeof_t == 0)
        return NOT_FOUND;

    size_t i;
    const byte* start = (const byte*)base;

    for(i = 0; i < size; i++)
        if(compare((start + i * sizeof_t), value) == 0)
            return i;

    return NOT_FOUND;
}

int bSearch(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*), int order)
{
    if(base == NULLPTR || compare == NULLPTR || value == NULLPTR || sizeof_t == 0)
        return NOT_FOUND;

    int left = 0, right = size - 1, mid, compareResult;
    const byte* start = (const byte*)base;

    if(order != ASCENDING && order != DESCENDING)
        order = ASCENDING;

    while(left <= right)
    {
        mid = (left + right) >> 1;
        compareResult = CMP_RESULT((start + mid * sizeof_t), value);

        if(compareResult == 0)
            return mid;
        else if(compareResult > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return NOT_FOUND;
}

size_t lSearchOccurrences(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*), size_t* occurrences, size_t occurrencesSize)
{
    if(base == NULLPTR || compare == NULLPTR || value == NULLPTR || sizeof_t == 0 || occurrences == NULLPTR)
        return 0;

    size_t i, count = 0;
    const byte* start = (const byte*) base;

    if(occurrencesSize == 0)
        return 0;

    /*  
        simply loop through the array and check if the value is found.
        if found, add the index to the occurrences array
    */
    for(i = 0; i < size; i++)
        if(compare(start + i * sizeof_t, value) == 0 && count < occurrencesSize)
            *(occurrences + count++) = i;

    return count;
}

size_t bSearchOccurrences(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*), int order, size_t* occurrences, size_t occurrencesSize)
{
    if(base == NULLPTR || compare == NULLPTR || value == NULLPTR || sizeof_t == 0 || occurrences == NULLPTR || occurrencesSize == 0)
        return 0;
    
    if(order != ASCENDING && order != DESCENDING)
        order = ASCENDING;

    int index;
    int left, right, count = 0;
    const byte* start = (const byte*) base;

    index = bSearch(base, sizeof_t, size, value, compare, order);

    if(index != NOT_FOUND)
    {
        /*  
            if bSearch found the value, add the index to the occurrences array,
            and then, since we know that the array is sorted (so if there are any other
            occurrences of the value they are immediately to the left or right),
            we continue searching from there, starting from the left and the right of the found index.
        */

        *(occurrences + count++) = index;

        left = index - 1;
        right = index + 1;

        while(left >= 0 && CMP_RESULT(start + left * sizeof_t, value) == 0 && count < occurrencesSize)
            *(occurrences + count++) = left--;
        
        while(right < size && CMP_RESULT(start + right * sizeof_t, value) == 0 && count < occurrencesSize)
            *(occurrences + count++) = right++;
    }

    return count;
}

/**
 * @brief Merges two sorted arrays into one sorted array.
 * Used by sort() in the merge part
 * 
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param left Index of the first element in the left array.
 * @param mid Index of the mid element in the left array.
 * @param right Index of the last element in the right array.
 * @param compare Pointer to the comparison function.
 * @param order ASCENDING if the array should be sorted in ascending order, DESCENDING otherwise.
 */
static void merge(void* base, size_t sizeof_t, size_t left, size_t mid, size_t right, int (*compare)(const void*, const void*), int order)
{
    size_t size1 = mid - left + 1;
    size_t size2 = right - mid;

    size_t offsetI;
    size_t offsetJ;
    size_t offsetK;

    byte* start = (byte*) base;

    byte* leftBegin = start + left * sizeof_t;
    byte* rightBegin = start + (mid + 1) * sizeof_t;

    byte* leftPart = (byte*) allocate(size1 * sizeof_t);
    byte* rightPart = (byte*) allocate(size2 * sizeof_t);

    copyArray(leftBegin, leftPart, sizeof_t, size1, size1); //copy the left halve into leftPart
    copyArray(rightBegin, rightPart, sizeof_t, size2, size2); //copy the right halve into rightPart

    size_t i = left, j = 0, k = 0;

    //merge the two parts
    while(j < size1 && k < size2)
    {
        offsetI = i * sizeof_t;
        offsetJ = j * sizeof_t;
        offsetK = k * sizeof_t;
        //if(leftPart[j] <= rightPart[k])
        if(CMP_RESULT(leftPart + offsetJ, rightPart + offsetK) <= 0)
        {
            ASSIGN((start + offsetI), (leftPart + offsetJ), sizeof_t); //start[i] = leftPart[j];
            ++j;
        }
        else
        {
            ASSIGN((start + offsetI), (rightPart + offsetK), sizeof_t); //start[i] = rightPart[j];
            ++k;
        }

        ++i;
    }

    //copy the remaining elements (if there are any) of the left part
    while(j < size1)
    {
        ASSIGN((start + i * sizeof_t), (leftPart + j * sizeof_t), sizeof_t); //start[i] = leftPart[j];
        ++j;
        ++i;
    }

    //copy the remaining elements (if there are any) of the right part
    while(k < size2)
    {
        ASSIGN((start + i * sizeof_t), (rightPart + k * sizeof_t), sizeof_t); //start[i] = rightPart[j];
        ++k;
        ++i;
    }

    deallocate(leftPart);
    deallocate(rightPart);

    return;
}

void sort(void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*), int order)
{
    if(base == NULLPTR || compare == NULLPTR || sizeof_t == 0 || size < 2)
        return;

    if(order != ASCENDING && order != DESCENDING)
        order = ASCENDING;

    size_t left, mid, right, subSize;

    //bottom up merge sort to avoid recursive calls
    for(subSize = 1; subSize < size; subSize *= 2)
    {
        for(left = 0; left < size; left += subSize * 2)
        {
            mid = left + subSize - 1;
            right = min(left + subSize * 2 - 1, size - 1);

            if(mid < right)
                merge(base, sizeof_t, left, mid, right, compare, order);
        }
    }


    return;
}

void reverse(void* base, size_t sizeof_t, size_t size)
{
    if(base == NULLPTR || sizeof_t == 0)
        return;

    byte* start = (byte*) base;
    size_t left = 0, right = size - 1;

    while(left < right)
    {
        swap(start + left * sizeof_t, start + right * sizeof_t, sizeof_t);

        ++left;
        --right;
    }

    return;
}

int isSorted(const void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*), int order)
{
    if(base == NULLPTR || compare == NULLPTR || sizeof_t == 0)
        return 0;

    size_t i, offset;
    const byte* start = (const byte*)base;

    if(order != ASCENDING && order != DESCENDING)
        order = ASCENDING;

    for(i = 0; i < size - 1; i++)
    {
        offset = i * sizeof_t;

        if(CMP_RESULT((start + offset), (start + offset + sizeof_t)) > 0)
            return 0;
    }

    return 1;
}

void shuffle(void* base, size_t sizeof_t, size_t size)
{
    if(base == NULLPTR || sizeof_t == 0)
        return;

    size_t i, randIdx;
    byte* start = (byte*)base;

    for(i = 0; i < size; i++)
    {
        randIdx = rand() % (i + 1);
        swap((start + i * sizeof_t), (start + randIdx * sizeof_t), sizeof_t);
    }

    return;
}

int findMin(const void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*))
{
    if(base == NULLPTR || sizeof_t == 0)
        return NOT_FOUND;
    
    size_t i;
    size_t minIdx = 0;
    const byte* start = (const byte*)base;

    for(i = 0; i < size; i++)
        if(i != minIdx && compare((start + i * sizeof_t), (start + minIdx * sizeof_t)) < 0)
            minIdx = i;

    return (int)minIdx;
}

int findMax(const void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*))
{
    if(base == NULLPTR || compare == NULLPTR || sizeof_t == 0)
        return NOT_FOUND;
    
    size_t i;
    size_t maxIdx = 0;
    const byte* start = (const byte*)base;

    for(i = 0; i < size; i++)
        if(i != maxIdx && compare((start + i * sizeof_t), (start + maxIdx * sizeof_t)) > 0)
            maxIdx = i;

    return (int)maxIdx;
}