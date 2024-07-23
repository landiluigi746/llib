/**
 * Example of using the memory
 * 
 * Author: landiluigi746
 * Date: 2024-07-09
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_memory.h>

int main(void)
{
    //safe allocation
    int* ptr = (int*) allocate(sizeof(int));
    //no need to check for NULL since the function already does

    //deallocate
    deallocate(ptr);

    //swap two values
    int a = 5;
    int b = 3;
    swap(&a, &b, sizeof(int));

    //copy memory
    int arr1[] = {1, 2, 3, 4};
    int arr2[10];
    copyMemory(arr1, arr2, sizeof(arr1), sizeof(arr2));

    //copy array
    int arr3[] = {1, 2, 3, 4, 5, 6};
    int arr4[6];
    copyArray(arr3, arr4, sizeof(int), sizeof(arr3), sizeof(arr4));

    //set memory
    setMemory(arr3, sizeof(int), 0);

    printf("a = %d, b = %d\n", a, b);
    
    return 0;
}