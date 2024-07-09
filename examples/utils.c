#include <llib/llib_utils.h>
#include <stdio.h>

int main(void)
{
    wait(1000); //wait for 1 second (1000 milliseconds)

    FILE* fptr = openFile("myFile.txt", "w");
    //no need to check for NULL

    fprintf(fptr, "Hello World!\n");
    fclose(fptr);

    return 0;
}