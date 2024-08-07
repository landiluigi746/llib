/**
 * Implementation file for llib i/o
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#include <llib_io.h>

void clearInBuf(void)
{
    int c;
    while((c = getchar()) != EOF && c != '\n');
    return;
}

int input(const char* format, void* address)
{
    int result = scanf(format, address);
    clearInBuf();

    return result;
}