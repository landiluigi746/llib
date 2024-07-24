/**
 * Example of using the darray
 * 
 * Author: landiluigi746
 * Date: 2024-07-23
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_darray.h>

//function to print the darray
void printDarray(darray* darr)
{
    printf("Darray\n");
    
    size_t i;
    
    printf("[");
    for(i = 0; i < darr->size; ++i)
        printf(" %d%c", *(int*)darrayGet(darr, i), (i < darr->size - 1) ? ',' : ' ');
    printf("]\n");

    printf("\n");

    return;
}

//comparator function
int compareInts(const void* A, const void* B)
{
    return *(int*)A - *(int*)B;
}

#define SIZE 32

int main(void)
{
    //create a darray (use the macro for simplicity)
    darray* darr = DARRAY(int, SIZE);
    int i;

    //add some values
    //the darray will grow automatically
    for(i = 0; i < SIZE * 2; i++)
        darrayPushBack(darr, &i);

    //print the darray
    printDarray(darr);

    //pop some values
    for(i = 0; i < SIZE / 2; i++)
        darrayPopBack(darr);
    
    printDarray(darr);

    //resize the darray
    darrayResize(darr, SIZE);

    //set some values
    int val1 = 1, val2 = 2;
    darraySet(darr, 3, &val1);
    darraySet(darr, 7, &val2);

    printDarray(darr);

    //get some values
    printf("The value at index 3 is %d\n", *(int*)darrayGet(darr, 3));
    printf("The value at index 7 is %d\n", *(int*)darrayGet(darr, 7));

    //sort the darray
    darraySort(darr, &compareInts, ASCENDING);

    //insert a value in order
    int val3 = 3;
    darrayInsertInOrder(darr, &val3, &compareInts);
    printDarray(darr);

    //remove some values
    darrayRemove(darr, 3);
    darrayRemove(darr, 7);
    printDarray(darr);

    //insert some values at specific index
    int val4 = 4, val5 = 5;
    darrayInsertAt(darr, 3, &val4);
    darrayInsertAt(darr, 7, &val5);
    printDarray(darr);

    //resize the darray
    darrayResize(darr, SIZE / 2);
    printDarray(darr);

    //search the darray (linear search)
    int index = darrayLSearch(darr, &val1, &compareInts);
    printf("Linear search: The value %d is at index %d\n", val1, index);

    //search the darray (binary search, make sure the darray is sorted)
    darraySort(darr, &compareInts, ASCENDING);
    index = darrayBSearch(darr, &val1, &compareInts, ASCENDING);
    printf("Binary search: The value %d is at index %d\n", val1, index);

    //search the darray for occurrences
    size_t occurrences[5];
    size_t occurrencesSize = 5;
    size_t occurrencesFound = darrayLSearchOccurrences(darr, &val1, &compareInts, occurrences, occurrencesSize);
    printf("Linear search: The value %d was found %d times\n", val1, occurrencesFound);

    //search the darray for occurrences
    darraySort(darr, &compareInts, ASCENDING);
    occurrencesFound = darrayBSearchOccurrences(darr, &val1, &compareInts, ASCENDING, occurrences, occurrencesSize);
    printf("Binary search: The value %d was found %d times\n", val1, occurrencesFound);

    //delete the darray
    darrayDelete(darr);

    printf("Done\n");

    return 0;
}