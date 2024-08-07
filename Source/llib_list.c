/**
 * Implementation file for llib list
 * 
 * Author: landiluigi746
 * Date: 2024-07-22
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_list.h>

//macro to simplify comparisons based on order
#define CMP_RESULT(a, b) ((order == ASCENDING) ? compare(a, b) : compare(b, a))

node* nodeCreate(void)
{
    return allocateInit(sizeof(node), 0);
}

list* listCreate(void)
{
    return allocateInit(sizeof(list), 0);
}

void listDelete(list* li)
{
    if(li == NULLPTR)
        return;

    node* curr = li->head;
    node* next = NULLPTR;

    while(curr != NULLPTR)
    {
        next = curr->next;
        deallocate(curr);
        curr = next;
    }

    *li = (list){0};

    deallocate(li);

    return;
}

list* listDuplicate(list* li)
{
    if(li == NULLPTR)
        return NULLPTR;
    
    list* dup = listCreate();

    size_t i;
    node* curr = li->head;
    
    for(i = 0; i < li->size; ++i, curr = curr->next)
        listPushBack(dup, curr->data);
    
    dup->size = li->size;

    return dup;
}

void listPushBack(list* li, const void* data)
{
    if (li == NULLPTR || data == NULLPTR)
        return;

    node* no = nodeCreate();

    *no = (node){
        .data = (void*)data,
        .prev = li->tail,
        .next = NULLPTR
    };

    if (li->size == 0)
        li->head = no;
    else
        li->tail->next = no;

    li->tail = no;
    ++(li->size);

    return;
}

void listPopBack(list* li)
{
    if(li == NULLPTR || li->size == 0)
        return;
    
    node* temp = li->tail;
    li->tail = li->tail->prev;

    if(li->tail != NULLPTR)
        li->tail->next = NULLPTR;
    
    deallocate(temp);
    --(li->size);

    if(li->size == 0)
        li->head = NULLPTR;

    return;
}

node* listSearch(list* li, const void* data, int (*compare)(const void*, const void*))
{
    if(li == NULLPTR || data == NULLPTR || compare == NULLPTR)
        return NULLPTR;

    size_t i;
    node* curr = li->head;

    for(i = 0; i < li->size; i++, curr = curr->next)
        if(compare(curr->data, data) == 0)
            return curr;
    
    return NULLPTR;
}

void listInsert(list* li, int index, const void* data)
{
    if(li == NULLPTR || data == NULLPTR || index < 0 || index > (int)li->size)
        return;
    
    size_t i;
    node* curr = nodeCreate();
    node* temp;

    *curr = (node){
        .data = (void*)data,
        .next = NULLPTR,
        .prev = NULLPTR
    };

    if(li->size == 0)
    {
        li->head = curr;
        li->tail = curr;
    }
    else if(index == 0)
    {
        curr->next = li->head;
        curr->next->prev = curr;
        li->head = curr;
    }
    else if(index == li->size)
    {
        curr->prev = li->tail;
        curr->prev->next = curr;
        li->tail = curr;
    }
    else
    {
        if(index < li->size >> 1)
        {
            temp = li->head;
            for(i = 1; i < index; ++i, temp = temp->next);
        }
        else
        {
            temp = li->tail;
            for(i = 0; i < (int)li->size - index; ++i, temp = temp->prev);
        }

        curr->prev = temp;
        curr->next = temp->next;
        curr->prev->next = curr;
        curr->next->prev = curr;
    }

    ++(li->size);

    return;
}

void listRemove(list* li, int index)
{
    if(li == NULLPTR || index < 0 || index >= (int)li->size)
        return;

    size_t i = 0;
    node* curr;

    if(li->size == 1)
    {
        curr = li->head;
        li->head = NULLPTR;
        li->tail = NULLPTR;
    }
    else if(index == 0)
    {
        curr = li->head;
        li->head = li->head->next;
        li->head->prev = NULLPTR;
    }
    else if(index == li->size - 1)
    {
        curr = li->tail;
        li->tail = li->tail->prev;
        li->tail->next = NULLPTR;
    }
    else
    {
        if(index < li->size >> 1)
        {
            curr = li->head;
            for(i = 1; i < index; ++i, curr = curr->next);
        }
        else
        {
            curr = li->tail;
            for(i = 1; i < (int)li->size - index; ++i, curr = curr->prev);
        }

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    deallocate(curr);

    --(li->size);

    return;
}

int listGetNodeIndex(list* li, const node* no)
{
    if(li == NULLPTR || no == NULLPTR)
        return NOT_FOUND;
    
    size_t i;

    if(no == li->head)
        return 0;
    else if(no == li->tail)
        return li->size - 1;

    node* curr = li->head;

    for(i = 0; i < li->size; i++, curr = curr->next)
        if(curr == no)
            return i;

    return NOT_FOUND;
}

void listSort(list* li, int (*compare)(const void*, const void*), int order)
{
    if(li == NULLPTR || li->size < 2 || compare == NULLPTR)
        return;

    if(order != ASCENDING && order != DESCENDING)
        order = ASCENDING;

    size_t i;
    node* curr;

    node* tempNode = li->head;
    void* tempNodeData;

    for(i = 0; i < li->size; i++, tempNode = tempNode->next)
    {
        curr = tempNode;
        tempNodeData = tempNode->data;

        while(curr->prev != NULLPTR && CMP_RESULT(curr->prev->data, tempNodeData) > 0)
        {
            curr->data = curr->prev->data;
            curr = curr->prev;
        }

        curr->data = tempNodeData;
    }
    
    return;
}
