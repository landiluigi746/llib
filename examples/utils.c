#include <llib/llib_utils.h>
#include <stdio.h>

int main(void)
{
    PAIR(int, int) p = {1, 2};
    printf("first: %d | second: %d\n", p.first, p.second);

    wait(1000); //wait for 1 second (1000 milliseconds)

    FILE* fptr = openFile("myFile.txt", "w");
    //no need to check for NULL

    fprintf(fptr, "Hello World!\n");
    fclose(fptr);

    return 0;
}