# CORE - Useful abstractions for the C language

The library is currently in an alpha stage. Not recommended for production use.

## Description

The Core library is a collection fast and useful tools to extend the standard C
functionality. This project is a product of student's  studies in the 42 coding
school and as such, follows the Norme coding standard (described below) and uses
a minimum amount of libc functions because many of these functions are forbidden
in the school projects. Thus many of these standard functions have been
re-created for this library. Since all of the functions are written in pure ISO
compliant C, someof the functions cannot be as efficient as the library
equivalents. The most important of these functions is memcpy since it underlies
the performance of most other functions. The memcopy function `mem_cpy` provided
in the library and used by the library functions is optimized as much as we were
able and achieves about 60% of the library memcpy's performance under critical
load.  Libc memcpy is, however, an intrinsic instruction, meaning it's the
fastest possible copying procedure provided by the CPU itself. Thus it's
unrealistic to presume similar performance can be achieved with C code. However
there has been great effort put in performance throughout the library, so
swapping the `mem_cpy` function to libc `memcpy` project wide will net maximum
performance from the library. We might make a separate branch where this swap
has been made.

The Norme is the coding standard of the 42 school. It imposes a very strict set
of rules on code formatting and prohibits certain language features which are
deemed unsafe or that obfuscate code. Also it imposes a limit in function length
and restricts it to 25 lines. This restricion is actually a great tool in order
to learn how to split logic in managebale chucnks, but in certain rare
situations it might lead to code that is broken up in a manner that doesn't make
much sense. This is, however, a ruleset that the library follows in order to be
compatible with school projects in the 42 school. The Norme can be found at the
root of this repo.

We accpet contributions from anyone, especially other 42 students! IF you find
anything useful in the library, please feel free to take and use it as you
wish!

## Objectives

-	User friendly interfaces.
-	Fast and reliable.
-	Minimum side effects.
-	Explicitness rather than compactness.
-	Readable and well documented source code.
-	Modular abstractions.

## Features

-	A system for allocating sized memory blocks ie. blocks of memory that carry
	their size within the object. These memory blocks are easy to resize and
	manipulate since user doesn't need to carry the size information.
-	A system for tracking memory allocations (with backtrace of position in
	the program akin to valgrind or -fsanitize).
-	A system for better error tracking and debug messaging.
-	Different program wide policies for error recovery.
-	Fast and useful containers and data-structures with uniform function naming
	and conventions.
-	Re-creations of standard libc functions with readable source code which can
	be beneficial for learning purposes.
-	Standard printf and format functionality (functions `print` and `format`).
	These functions don't have all the features from the standard printf, but
	have additional features spesific to the datatypes in this library.
-	Math, linear algebra, graph etc. functionality.

## Contexts

### Array

A dynamic array implementation.

### Cstring

String operations for normal c-style strings.

### Graph

A graph implementation with node and edge abstractions using a hash map
data-structure.

### Linera Algebra

Linear algebra functions for general use, including types commonly used in
graphics programming.

### Map

A hash map implementation.

### Math

Math functions.

### Memory

Functions for copying, moving and allocating memory.

### Print

Formatted printing and string conversion functions.

### Ptr Array

A dyncamic pointer array implementation.

### String

Fast string functions.
