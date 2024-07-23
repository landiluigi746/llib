/**
 * Implementation file for llib darray
 * 
 * Author: landiluigi746
 * Date: 2024-07-23
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_darray.h>
#include <time.h>

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
    darraySort(darr, compareInts, ASCENDING);

    //delete the darray
    darrayDelete(darr);

    printf("Done\n");

    return 0;
}