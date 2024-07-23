/**
 * Example of using the string
 * 
 * Author: landiluigi746
 * Date: 2024-07-09
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_string.h>

int main(void)
{
    //string creation
    string* str = strCreate(10);

    //print to a string
    string* strp = strCreate(10);
    strPrintf(strp, "%d this string is longer than 10 characters", 1);
    puts(strp->buf); //output: 1 this st

    //string input
    string* buf = strCreate(100);
    size_t len = strInput(buf);

    //concatenation
    string* str1 = strCreateFrom("Hello");
    const char* str2 = "World";
    len = strConcat(str1, str2);

    //encrypt (the second parameter is the number of characters to shift)
    string* str3 = strCreateFrom("string");
    strCipher(str3, 15);
    puts(str3->buf); //output: $%#x}v

    //decrypt
    strDecipher(str3, 15);
    puts(str3->buf); //output: string

    //copy
    const char* src = "copyString";
    string* dst = strCreate(5);
    size_t dstLen = strCopy(src, dst);
    puts(dst->buf); //output: copy

    //string deletion
    strDelete(str);
    strDelete(strp);
    strDelete(buf);
    strDelete(str1);
    strDelete(str3);
    strDelete(dst);

    return 0;
}