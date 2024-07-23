#include <llib/llib_darray.h>
#include <llib/llib_algorithms.h>

static void darrayInternalGrowth(darray* darr)
{
    if(darr->data == NULLPTR)
        darr->data = allocate(darr->elementSize);
    
    if(darr->size >= darr->capacity)
    {
        darr->capacity *= 2;
        darr->data = reallocate(darr->data, darr->capacity * darr->elementSize);
    }

    return;
}

darray* darrayCreate(size_t elementSize, size_t capacity)
{
    if(elementSize == 0)
        return NULLPTR;

    darray* darr = allocate(sizeof(darray));
    void* data = (capacity > 0) ? allocate(capacity * elementSize) : NULLPTR;

    *darr = (darray){
        .data = data,
        .elementSize = elementSize,
        .size = 0,
        .capacity = capacity
    };

    return darr;
}

void darrayDelete(darray* darr)
{
    if(darr == NULLPTR)
        return;

    deallocate(darr->data);
    deallocate(darr);

    return;
}

void darrayResize(darray* darr, size_t newCapacity)
{
    if(darr == NULLPTR || darr->elementSize == 0)
        return;
    
    if(darr->data == NULLPTR)
        darr->data = allocate(darr->elementSize * newCapacity);
    
    if(darr->capacity != newCapacity)
    {
        darr->data = reallocate(darr->data, darr->elementSize * newCapacity);

        if(darr->size > newCapacity)
            darr->size = newCapacity;
    }

    darr->capacity = newCapacity;

    return;
}

void darrayPushBack(darray* darr, const void* data)
{
    if(darr == NULLPTR || darr->elementSize == 0 || data == NULLPTR)
        return;
    
    darrayInternalGrowth(darr);

    ASSIGN((darr->data + (darr->size++ * darr->elementSize)), data, darr->elementSize);

    return;
}

void darrayPopBack(darray* darr)
{
    if(darr == NULLPTR || darr->data == NULLPTR || darr->size == 0 || darr->elementSize == 0)
        return;
    
    --(darr->size);

    return;
}

void darraySet(darray* darr, size_t index, const void* newData)
{
    if(darr == NULLPTR || darr->data == NULLPTR || darr->elementSize == 0 || index >= darr->size)
        return;
    
    ASSIGN((darr->data + index * darr->elementSize), newData, darr->elementSize);

    return;
}

void* darrayGet(darray* darr, size_t index)
{
    if(darr == NULLPTR || darr->data == NULLPTR || darr->elementSize == 0 || index >= darr->size)
        return NULLPTR;
    
    return (darr->data + index * darr->elementSize);
}

void darraySort(darray* darr, int (*compare)(const void*, const void*), int order)
{
    if(darr == NULLPTR)
        return;
    
    sort(darr->data, darr->elementSize, darr->size, compare, order);

    return;
}