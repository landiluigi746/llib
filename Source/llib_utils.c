/**
 * Implementation file for llib algorithms
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#include <llib_utils.h>

void wait(uint32_t milliseconds)
{
    clock_t start = clock();
    while((clock() - start) < milliseconds);
    return;
}

FILE* openFile(const char* fileName, const char* fileMode)
{
    FILE* filePtr = fopen(fileName, fileMode);

    if(filePtr == NULLPTR)
    {
        perror("Error while opening file!\n");
        exit(EXIT_FAILURE);
    }

    return filePtr;
}