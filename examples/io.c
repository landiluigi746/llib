/**
 * Example using the io
 * 
 * Author: landiluigi746
 * Date: 2024-07-09
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_io.h>

int main(void)
{    
    //input with buffer cleaning
    int x;
    input("%d", &x); //input takes the format and a single address

    //buffer cleaning when using standard input
    int y;
    char c;

    scanf("%d", &y);
    clearInBuf(); //clear the input buffer

    //now we can use "%c" instead of " %c" beacuse the '\n' character is automatically cleared
    scanf("%c", &c);

    return 0;
}