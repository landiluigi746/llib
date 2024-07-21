/**
 * Implementation file for llib list
 * 
 * Author: landiluigi746
 * Date: 2024-07-22
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_list.h>

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

void listPushBack(list* li, const void* data)
{
    if (li == NULLPTR || data == NULLPTR)
        return;

    node* no = (node*) allocate(sizeof(node));

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
    if(li == NULLPTR)
        return;
    
    if(li->size == 0)
        return;
    
    node* prev = li->tail->prev;
    deallocate(li->tail);
    li->tail = prev;
    li->tail->next = NULLPTR;

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

void listRemove(list* li, int index)
{
    if(li == NULLPTR || index < 0 || index >= (int)li->size)
        return;

    size_t i = 0;
    node* curr;
    node* tmp;

    if(index == 0)
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
        curr = (index < li->size >> 1) ? li->head : li->tail;
        for(i = 0; i < index; i++, curr = (index < li->size >> 1) ? curr->next : curr->prev);
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    tmp = curr;
    deallocate(tmp);

    --(li->size);

    return;
}

int listGetIndex(list* li, const node* no)
{
    if(li == NULLPTR || no == NULLPTR)
        return NOT_FOUND;
    
    size_t i;
    node* curr = li->head;

    for(i = 0; i < li->size; i++, curr = curr->next)
        if(curr == no)
            return i;

    return NOT_FOUND;
}