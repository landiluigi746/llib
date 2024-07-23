/**
 * Example of using the list
 * 
 * Author: landiluigi746
 * Date: 2024-07-22
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_list.h>

//comparator function
int compareInts(const void* A, const void* B)
{
    return *(int*)A - *(int*)B;
}

//utility function to print the list
void printList(list* li)
{   
    size_t i;
    node* curr = li->head;

    printf("List\n");

    for(i = 0; i < li->size; i++, curr = curr->next)
        printf("index %llu: %d\n", i, *(int*)curr->data);

    printf("\n");

    return;
}

int main(void)
{
    //create a list
    list* li = listCreate();
    int vals[] = {1, 2, 3, 4, 5, 6, 7}; //test values
    int size = (int) sizeof(vals) / sizeof(vals[0]);
    int i;

    //add some values
    for(i = 0; i < size - 1; i++)
        listPushBack(li, &vals[i]);
    
    //print the list
    printList(li);

    //pop the last value
    listPopBack(li);

    printList(li);

    //get the index of some values
    printf("index of %d: %d\n", vals[3], listGetNodeIndex(li, listSearch(li, &vals[3], &compareInts)));
    printf("index of %d: %d\n", vals[6], listGetNodeIndex(li, listSearch(li, &vals[6], &compareInts)));

    //remove some values at specified index
    listRemove(li, 2);
    listRemove(li, 0);

    printList(li);

    //insert some values
    listInsert(li, 0, &vals[3]);
    listInsert(li, li->size, &vals[6]);
    listInsert(li, (li->size >> 1) + 1, &vals[0]);

    printList(li);

    //sort the list
    listSort(li, &compareInts, ASCENDING);
    printList(li);

    //delete the list
    listDelete(li);

    printf("Done!\n");

    return 0;
}