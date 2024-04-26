#include <llib/llib_algorithms.h>

#define MIN_SORT_RUN 4096

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
int lSearch(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*))
{
    int i, offset;
    const byte* start = (const byte*)base;

    for(i = 0; i < size; i++)
    {
        offset = i * sizeof_t;

        if(compare((start + offset), value) == 0)
            return i;
    }

    return NOT_FOUND;
}

/**
 * @brief Binary search algorithm.
 *
 * @param base Pointer to the base address of the sorted array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * @param value Pointer to the value to be searched.
 * @param compare Pointer to the comparison function.
 *
 * @return Index of the element if found, or -1 if not found.
 */
int bSearch(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*))
{
    int left = 0, right = size - 1, mid, compareResult;
    const byte* start = (const byte*)base;

    while(left <= right)
    {
        mid = (left + right) >> 1;
        compareResult = compare((start + mid * sizeof_t), value);

        if(compareResult == 0)
            return mid;
        else if(compareResult > 0)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return NOT_FOUND;
}

/**
 * @brief Sorts the array in the range [left..right] using a simple variant of Shell Sort algorithm.
 * Used by sort()
 * 
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param left Index of the first element in the range.
 * @param right Index of the last element in the range.
 * @param compare Pointer to the comparison function.
 */
static void shellSort(void* base, size_t sizeof_t, size_t left, size_t right, int (*compare)(const void*, const void*))
{
    size_t i, j, gap = 1, offset1, offset2;
    size_t size = right - left;

    byte* start = (byte*)base;
    byte* temp_ptr = (byte*) allocate(sizeof_t);

    //determine the gap
    while(gap < size / 3)
        gap = gap * 3 + 1;

    //sort the array
    while(gap > 0)
    {
        for(i = gap; i < size; i++)
        {
            j = (left + i) * sizeof_t;
            ASSIGN(temp_ptr, (start + j), sizeof_t); //copy the value at j into a temp variable
            //copyMemory(start + j, start + j + sizeof_t, temp_ptr, temp_ptr + sizeof_t);
            offset1 = (left + gap) * sizeof_t;
            offset2 = gap * sizeof_t;

            //shift the elements
            while(j >= offset1 && compare((start + j - offset2), temp_ptr) > 0)
            {
                ASSIGN((start + j), (start + j - offset2), sizeof_t);
                //copyMemory((start + j - offset2), (start + j - offset2 + sizeof_t), (start + j), (start + j - offset2));
                j -= offset2;
            }

            ASSIGN((start + j), temp_ptr, sizeof_t); //put the value in the right place
            //copyMemory(temp_ptr, temp_ptr + sizeof_t, (start + j), (start + j + sizeof_t));
        }

        gap /= 3;
    }

    deallocate(temp_ptr);

    return;
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
 */
static void merge(void* base, size_t sizeof_t, size_t left, size_t mid, size_t right, int (*compare)(const void*, const void*))
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

    ASSIGN(leftPart, leftBegin, size1 * sizeof_t); //copy the left halve into leftPart
    ASSIGN(rightPart, rightBegin, size2 * sizeof_t); //copy the right halve into rightPart

    size_t i = left, j = 0, k = 0;

    //merge the two parts
    while(j < size1 && k < size2)
    {
        offsetI = i * sizeof_t;
        offsetJ = j * sizeof_t;
        offsetK = k * sizeof_t;
        //if(leftPart[j] <= rightPart[k])
        if(compare(leftPart + offsetJ, rightPart + offsetK) <= 0)
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

/**
 * @brief Sorts an array using a simple variant of Tim Sort algorithm.
 *
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * @param compare Pointer to the comparison function.
 */
void sort(void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*))
{
    size_t left, mid, right, subSize;

    const size_t runSize = min(MIN_SORT_RUN, size >> 2);

    for(left = 0; left < size; left += runSize)
    {
        right = min(left + runSize, size);
        shellSort(base, sizeof_t, left, right, compare);
    }

    for(subSize = runSize; subSize < size; subSize *= 2)
    {
        for(left = 0; left < size; left += subSize * 2)
        {
            mid = left + subSize - 1;
            right = min(left + subSize * 2 - 1, size - 1);

            if(mid < right)
                merge(base, sizeof_t, left, mid, right, compare);
        }
    }

    return;
}

/**
 * @brief Checks if an array is sorted.
 *
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * @param compare Pointer to the comparison function.
 *
 * @returns 1 if the array is sorted, 0 otherwise.
 */
int isSorted(const void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*))
{
    int i, offset;
    const byte* start = (const byte*)base;

    for(i = 0; i < size - 1; i++)
    {
        offset = i * sizeof_t;

        if(compare((start + offset), (start + offset + sizeof_t)) > 0)
            return 0;
    }

    return 1;
}

/**
 * @brief Shuffles an array using the Fisher-Yates algorithm.
 * 
 * @param base Pointer to the base address of the array.
 * @param sizeof_t Size of each element in the array.
 * @param size Number of elements in the array.
 * 
 * @warning Call srand for randomness before using this function
 */
void shuffle(void* base, size_t sizeof_t, size_t size)
{
    int i, randIdx, offset1, offset2;
    byte* start = (byte*)base;

    for(i = 0; i < size; i++)
    {
        randIdx = rand() % (i + 1);

        offset1 = i * sizeof_t;
        offset2 = randIdx * sizeof_t;


        swap((start + offset1), (start + offset2), sizeof_t);
    }

    return;
}