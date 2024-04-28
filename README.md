# llib

Utility library for C

The "llib" library is a collection of standalone modules created for the purpose of reducing the need to rewrite similar code and providing alternative implementations of the standard library. This project was developed for fun and as a learning experience and also as a little challenge.

The library is composed by a series of sub-modules for better code structure and most of them are standalone, so you can just use the module you need.

Inspired by https://github.com/barrust/c-utils and https://github.com/goToMain/c-utils/.

## Installation

To use the "llib" library, you have two alternatives:
- simply clone the repository and include the necessary header files in your project;
- use single modules by downloading their .h file in the include/llib directory and .c file in the src/llib directory.

Make sure to link the library (or the modules) during compilation and update your include path.

## List of modules and examples

- [memory](#memory) - memory-related stuff (safe allocation, copy, swap)
- [utils](#utils) - utility functions (wait, safe fopen)
- [string](#string) - string utilities (safe input with buffer cleaning at the end, copy, reverse, encrypt with caesar's cipher, etc.)
- [io](#io) - io utilities (i.e. buffer cleaning)
- [algorithms](#algorithms) - various algorithms (searching, sorting, shuffling)

The modules are fully commented and can be used as a reference.
You can use the examples to test your code.

### memory
Contains memory related stuff, like safe allocation, swap and copy functions.

Example usage:
```c
#include <llib/llib_memory.h> //make sure to update your include path if you use this notation

//safe allocation
int* ptr = (int*) allocate(sizeof(int));
//no need to check for NULL since the function already does

//deallocate
deallocate(ptr);

//swap two values
int a = 5;
int b = 3;
swap(&a, &b, sizeof(int));

//copy memory
int arr1[] = {1, 2, 3, 4};
size_t size1 = sizeof(arr1) / sizeof(arr1[0]);
int arr2[10];
size_t size2 = 10;
copyMemory(arr1, arr1 + size1, arr2, arr2 + size2);

//copy array (when arrays are the same size)
int arr3[] = {1, 2, 3, 4, 5, 6};
int arr4[6];
size_t size = 6;
copyArray(arr3, arr4, sizeof(int), size);
```

### utils
Contains utility functions, like wait, safe fopen

Example usage:
```c
#include <llib/llib_utils.h> //make sure to update your include path if you use this notation

wait(1000); //wait for 1 second (1000 milliseconds)

FILE* fptr = openFile("myFile.txt", "w");
//no need to check for NULL
```

### string
Contains safe string utilities, like input, copy, encrypt etc.
Note: this module isn't standalone. You will also need **memory** and **io** to use it.

Example usage:
```c
#include <llib/llib_string.h>

//safe string input
char buf[100];
size_t len = strInput(buf, 100);

//concatenation
const char* str1 = "Hello";
const char* str2 = "World";
char dest[100];
size_t len = strConcat(str1, str2, dest, sizeof(dest));

//encrypt (the second parameter is the number of characters to shift)
char str3[] = "string";
strCipher(str3, 15);
puts(str3); //output: $%#x}v

//decrypt
strDecipher(str3, 15);
puts(str3); //output: string

//safe copy
const char* src = "copyString";
char dst[5];
size_t dstLen = strCopy(src, dst, sizeof(dst));
puts(dst); //output: copy
```

### io
Contains io utility functions, like input with buffer cleaning.

Example usage:
```c
#include <llib/llib_io.h>

//input with buffer cleaning
int x;
input("%d", &x); //input takes the format and a single address

//buffer cleaning when using standard input
int y;
char c;

scanf("%d", &y);
clearInBuf(); //clear the input buffer

scanf("%c", &c);
```

### algorithms
Contains implementations of several useful algorithms, including:
- linear and binary search;
- sorting (currently merge sort, planning on implementing other algorithms);
- shuffling
Note: this module isn't standalone. You will also need **memory** to use it.

Example usage:
```c
#include <llib/llib_algorithms.h>

//comparator function
int compareInts(const void* A, const void* B)
{
    return *(int*)A - *(int*)B;
}

//sorting and binary search
int arr[] = {2, 1, 4, 5, 6, 3};
size_t size = sizeof(arr) / sizeof(arr[0]);
sort(arr, sizeof(int), size, &compareInts, ASCENDING);

int val = 5;
int index = bSearch(arr, sizeof(int), size, &val, &compareInts, ASCENDING);

//shuffling
shuffle(arr, sizeof(int), size);

//we can also search for all the occurrences in an array of a value
int arr2[] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8};
size = sizeof(arr2) / sizeof(arr2[0]);
size_t occurrences[10];
/*  params: array, size of each element, number of elements, value, comparator function, 
    order, occurrences array, size of occurrences array */
size_t count = bSearchOccurrences(arr2, sizeof(int), size, &val, &compareInts, ASCENDING, occurrences, 10);
```