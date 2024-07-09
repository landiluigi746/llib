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

    //copy array (when arrays are the same size)
    int arr3[] = {1, 2, 3, 4, 5, 6};
    int arr4[6];
    size_t size = 6;
    copyArray(arr3, arr4, sizeof(int), size);
    
    return 0;
}