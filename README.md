# llib

[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/landiluigi746/llib/LICENSE)
[![Language: C](https://img.shields.io/badge/Language-C-blue)](https://github.com/topics/c)

🔧📚 Utility library for C 📝💻

The "llib" library is a collection of standalone modules created for the purpose of reducing the need to rewrite similar code and providing alternative implementations of the standard library. This project was developed for fun and as a learning experience and also as a little challenge.

The library is composed by a series of sub-modules for better code structure and most of them are standalone, so you can just use the module you need.

Every module header is fully commented and can be used as a reference.

Inspired by https://github.com/barrust/c-utils and https://github.com/goToMain/c-utils/.

**Note**: If you want need the premake5 project, you can find it [here](https://github.com/landiluigi746/llib/tree/premake_prj)

## 📥 Installation 📤

To use the "llib" library, you have two alternatives:
- simply clone the repository and include the necessary header files in your project;
- use single modules by downloading their .h file in the include/llib directory and .c file in the src/llib directory.
- compile llib as a static library and include the .a file in your project.

Make sure to link the library (or the modules) during compilation and update your include path.

## List of modules and examples 🔎

- [memory](#memory) - memory-related stuff (safe allocation, copy, swap)
- [utils](#utils) - utility functions (wait, safe fopen)
- [string](#string) - string struct and related functions (create, delete, copy, compare, concat, input, etc.)
- [io](#io) - io utilities (i.e. buffer cleaning)
- [algorithms](#algorithms) - various algorithms (searching, sorting, shuffling)
- [list](#list) - doubly linked list struct and related basic functions (push, pop, search, remove)
- [darray](#darray) - dynamic-array struct and related functions (push, pop, resize)

You can find examples in the examples directory and compile them using `make examples`.

### memory
Contains memory related stuff, like safe allocation, swap and copy functions.

[Example code here](examples/memory.c)

### utils
Contains utility functions, like wait, safe fopen

[Example code here](examples/utils.c)

### string
Contains string struct and related functions, like create, delete, copy, compare, concat, input, etc.
Also contains utility functions for normal char arrays.
Note: this module isn't standalone. You will also need [memory](#memory) and [io](#io) to use it.

[Example code here](examples/string.c)

### io
Contains io utility functions, like input with buffer cleaning.

[Example code here](examples/io.c)

### algorithms
Contains implementations of several useful algorithms for arrays, including:
- linear and binary search for arrays;
- sorting (currently merge sort, planning on implementing other algorithms);
- shuffling

Note: this module isn't standalone. You will also need [memory](#memory) to use it.

[Example code here](examples/algorithms.c)

### list
Provides a list struct implemented as a doubly linked list and related basic functions, like push, pop, search and delete
Note this module isn't standalone. You will also need [memory](#memory) to use it.

[Example code here](examples/list.c)

### darray
Provides a darray (dynamic-array) struct, a sort of a clone of C++'s std::vector and related functions.
Note: this module isn't standalone. You will also need [memory](#memory) and [algorithms](#algorithms) to use it.

[Example code here](examples/darray.c)