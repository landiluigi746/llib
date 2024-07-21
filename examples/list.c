#include <llib/llib.h>

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
        printf("%llu: %d\n", i, *(int*)curr->data);

    printf("\n");

    return;
}

int main(void)
{
    //create a list
    list* li = listCreate();
    int vals[] = {1, 2, 3, 4, 5, 6, 7}; //test values

    //add some values
    listPushBack(li, &vals[0]);
    listPushBack(li, &vals[1]);
    listPushBack(li, &vals[2]);
    listPushBack(li, &vals[3]);
    listPushBack(li, &vals[4]);
    listPushBack(li, &vals[5]);

    //print the list
    printList(li);

    //pop the last value
    listPopBack(li);

    printList(li);

    //get the index of some values
    printf("index of %d: %d\n", vals[3], listGetIndex(li, listSearch(li, &vals[3], &compareInts)));
    printf("index of %d: %d\n", vals[6], listGetIndex(li, listSearch(li, &vals[6], &compareInts)));

    //remove some values
    listRemove(li, 2);
    listRemove(li, 0);

    printList(li);

    //delete the list
    listDelete(li);

    printf("Done!\n");

    return 0;
}