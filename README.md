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

## List of modules

- **memory** - memory-related stuff (safe allocation, copy, swap)
- **utils** - utility functions (wait, safe fopen)
- **string** - string utilities (safe input with buffer cleaning at the end, copy, reverse, encrypt with caesar's cipher, etc.)
- **io** - io utilities (i.e. buffer cleaning)
- **algorithms** - various algorithms (searching, sorting, shuffling)

### memory
Contains memory related stuff, like safe allocation, swap and copy functions.

Example usage:
```c
#include <llib/llib_memory.h> //make sure to update your include path if you use this notation

//safe allocation
int* ptr = (int*) allocate(sizeof(int));
//no need to check for NULL since the function already does

//swap two values
int a = 5;
int b = 3;
swap(&a, &b, sizeof(int));

//copy memory
int arr1[] = {1, 2, 3, 4};
int arr2[10];
copyMemory(arr1, arr1 + sizeof(arr1), arr2, arr2 + 10);
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

## Usage

Here is an example of how to use the whole "llib" library:

```c
#include <llib/llib.h> //make sure to update your include path

int main(void)
{
    // Your code here
    return 0;
}
```
