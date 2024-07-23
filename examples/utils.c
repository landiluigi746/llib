/**
 * Example of using the utils
 * 
 * Author: landiluigi746
 * Date: 2024-07-09
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_utils.h>

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