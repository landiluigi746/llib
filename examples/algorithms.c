#include <llib/llib_algorithms.h>

//comparator function
int compareInts(const void* A, const void* B)
{
    return *(int*)A - *(int*)B;
}

int main(void)
{
    //sorting and binary search
    int arr[] = {2, 1, 4, 5, 6, 3};
    size_t size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, sizeof(int), size, &compareInts, ASCENDING);

    int val = 5;
    int index = bSearch(arr, sizeof(int), size, &val, &compareInts, ASCENDING);

    //shuffling
    shuffle(arr, sizeof(int), size);

    //we can also search for all the occurrences in an array of a value
    int arr2[] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8};
    size = sizeof(arr2) / sizeof(arr2[0]);
    size_t occurrences[10];
    size_t sizeOccurences = sizeof(occurrences) / sizeof(occurrences[0]);
    /*  params: array, size of each element, number of elements, value, comparator function, 
        order, occurrences array, size of occurrences array */
    size_t count = bSearchOccurrences(arr2, sizeof(int), size, &val, &compareInts, ASCENDING, occurrences, sizeOccurences);

    return 0;
}