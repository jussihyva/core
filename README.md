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
the performance of most other functions. The rawcopy function `mcpy` provided
in the library and used by the library functions is optimized as much as we were
able and achieves about 60% of the library memcpy's performance under critical
load.  Libc memcpy is, however, an intrinsic instruction, meaning it's the
fastest possible copying procedure provided by the CPU itself. Thus it's
unrealistic to presume similar performance can be achieved with C code. However
there has been great effort put in performance throughout the library, so
swapping the `mcpy` function to libc `memcpy` project wide will net maximum
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

-   User friendly interfaces.
-   Fast and reliable.
-   Minimum side effects.
-   Explicitness rather than compactness.
-   Readable and well documented source code.
-   Modular abstractions.

## Features

-   A system for allocating sized memory blocks ie. blocks of memory that carry
    their size within the object. These memory blocks are easy to resize and
    manipulate since user doesn't need to carry the size information.
-   A system for tracking memory allocations (with backtrace of position in
    the program akin to valgrind or -fsanitize).
-   A system for better error tracking and debug messaging.
-   Different program wide policies for error recovery.
-   Fast and useful containers and data-structures with uniform function naming
    and conventions.
-   Re-creations of standard libc functions with readable source code which can
    be beneficial for learning purposes.
-   Standard printf and format functionality (functions `print` and `format`).
    These functions don't have all the features from the standard printf, but
    have additional features spesific to the datatypes in this library.
-   Math, linear algebra, graph etc. functionality.

## Patterns

The library focuses on consistency so understanding the general patterns used in the library
make it easy to read and use.

### Function Structure


#### Parameter Order

```c
// All functions have dst --> src parameter order.
t_ret	map_add(t_map *dst, void *src, const char *key);
```

#### New & Free

Function names containing the word `new` are allocators and have to be coupled
with a corresponding `free` function.

```c

int main(void)
{
	t_array	arr;

	// Allocate array
	if (arr_new(&arr, 1, sizeof(int)) < 0)
		return (0);
	// Use array
	arr_free(&arr);
}
```

#### Add & Get & Take & Del

All functions in this group all have 3 spesific definions for accessing and element
at a spesific index or the last or the first element. These functions check for
bounds and return NULL on failure.

```c
arr_get(&arr, 0); // Get element at index 0
arr_take_last(&arr); // Get last element
arr_get_first(&arr); // Get first element
```

Difference between get and take is that take functions also delete the element in the `src`.
If the container holds the actual data and not a pointer to it, this means that allocated
memory must be passed as a parameter.

### Function Usage

#### Return Values

Common return types.

```c

// The enum `e_return_type` contains error values as negative integers.
enum e_return_type
{
	// ...
	CR_ERROR_BOUNDS = -4,
	CR_ERROR_MALLOC,
	CR_ERROR_INPUT,
	CR_FAIL,
	CR_SUCCESS = 0
};

// Boolean type.
typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

// Signed return type. Type implies this should be checked and possibly
// contains an error code.
typedef t_ssize	t_ret;

```

Function returns a `t_ret` signed type. Generic success is CR_SUCCESS = 0. CR_FAIL = -1 is generic failure. Below -1 are spesific error codes such as -2 = CR_MALLOC FAIL etc. 0 and
positive integers are thus available to represent different things on success
such as bytes copied or elements iterated.

```c
// Iterates f over dst and returns amount of elements iterated or negative
// on failure.
t_ret  arr_iter(t_array *dst, t_ssize (*f)(void *, t_size));

```
Function returns boolean t_bool which has the states TRUE = 1 and FALSE = 0.
Usually used by functions that ask a question about the input data and don't
have side effects such as allocating new memory.

```c
// Check if c is an alphanumeric character and return TRUE or False
// respectively.
t_bool  is_alpha(int c);
```
Functions that return a pointer or NULL. These are used when we want a
pointer to existing memory ie. an opaque pointer without allocating new
memory or making a copy.
```c
// Returns a pointer to the last element of the array.
void  *arr_get_last(t_array *src);
```

As opposed to...

```c
// Copy last element to allocated memory pointed by `dst`. Return bytes copied
// on success or negative error condition on failure.
t_ret  arr_take_last(void *dst, t_array *src);

```

## Core Containers

Different container data-structures.

### Raw

A raw memory container. Useful for constructing other data-structures or for raw
memory manipulation with bounds checking and other tools.

```c

typedef struct  s_raw
{
    t_byte      *data;  // Pointer to the start of the memory area.
    t_size      size;   // Size of the memory area.
}               t_raw;

typedef t_raw   t_hraw; // An opaque memory handle.

```

### Array

A dynamic array container. Stores everything in a contiguous block of memory and
resizes as necessary. Fast, easy to use and great for when the final size of
data is unknown. May use excess memory.

```c

typedef struct  s_array
{
    t_raw       raw;        // A sized t_raw memory block.
    t_size      len;        // Amount of elements in the array.
    t_size      elem_size;  // Size of the array element.
}               t_array;

```

### Parray

A dynamic pointer array container. Manages a dynamic array of pointers and
offers various tools for manipulating the array.

```c

typedef struct  s_parray
{
    void        **data; // Array of stored pointers.
    t_size      len;    // Amount of elements in the array.
    t_size      size;   // Amount of allocated pointers in the array.
}               t_parray;

```

### List

*Not yet implemented*

A linked list structure with the focus on adding to the start and to the end of
the list, serving both as a queue and a stack.

### Map

A hash map implementation. Uses open addressing and resizes automatically. Uses
linear probing by default, but probing method, load factor, resize function and
hash function can easily be swapped.

```c

typedef struct  s_map_node              // Key value pair.
{
    const char  *key;
    void        *data;
}               t_map_node;

typedef struct  s_map
{
    t_map_node  *node;                  // Memory area for map nodes.
    t_size      capacity;               // Current capacity of the map.
    t_size      count;                  // Amount of stored elements.
    double      load_factor;            // Resize if count == capacity * load factor
    t_uint64    (*hash)(const char *);  // Hash function used.
    t_uint64    (*probe)(t_uint64);     // Probing function.
    t_uint64    (*resize)(t_uint64);    // Resizing function.
}               t_map;

```

## Core Standard

Basic functionality for i/o and memory management and manipulation.

### Print

A recreation of the printf function with reduced capabilities, but some
capabilities spesific to the core library. Also contains different interfaces
for fromatting string, file i/o etc.

### Memory

Raw memory manipulation. Re-creations of memcpy family of functions with some
unique additions.

## Core String

Both standard c-string manipulation akin to string.h from libc, as well as an
optional string implementation in which the string size is stored in the string
itself and which uses different methods for much faster string manipulation.

### Cstring

Standard c-style string manipulation.

### String

A fast string implementation which carries the lenth of the string as well as
the allocated area separately in order to be more performant and mroe safe at
the expense of memory used. Also provides a string pointer datatype which allows
opaque access to a source string.

## Core Math

Mathematical algorithms and routines.

### Basic

Basic mathematical algorithms and functions.

### Linear Algebra

Functions and datatypes related to linear algebra.

## Core Graph

A generic graph implementation.

```c

typedef t_map       t_graph;    // Graph uses a hash map to store nodes.
typedef t_parray    t_edges;    // Edge array alias.
typedef t_parray    t_nodes;    // Node array alias.

typedef struct s_graph_node
{
    const char  *key;           // Key is also stroed as part of graph node.
    t_edges     in;             // Inbound edges.
    t_edges     out;            // Outboudn edges.
    t_bool      valid;          // Node has valid and invalid states.
    void        *attr;          // Additional associated data.
}               t_graph_node;

typedef struct s_graph_edge
{
    t_graph_node    *u;         // From node.
    t_graph_node    *v;         // To node.
    t_bool          valid;      // State.
    void            *attr;      // Additional associated data.
}                   t_graph_edge;

```

## Core System

A system for debugging, memory tracking and error messaging.

