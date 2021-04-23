# Dynamic Array

A multi-purpose dynamic array implementation for the C language.

## Design

-   Dynamic resizing. Doubles the size of the array when maximum size
    is reached.
- 	Datatype agnostic. When creating the array user specifies an element size
	for the array (preferrably using the sizeof operator).
-	Data is kept straight in memory for fast iteration. This is not a pointer
	array, all the data is in the array.data!
- 	Provides getters and setters, but also let's user typecast the arrays data
	portion and iterate it directly for maximum performance.

## Typedefs and Macros

```c

typedef struct  s_map
{
    void        **data;
    size_t      len;
    size_t      size;
    size_t      elem_size;
}               t_map;

```

`Len` refers to the number of members in the array. `Size` is the amount of
allocated space for `elem_size` sized objects. These values should never be manipulated
by the user but they can be accessed and checked easily.

## Functions

These are general descriptions about the functions in the library and their
intended usage. For a detailed description refer to the source code file
of each function.

### General

```c
t_arr			arr_new(size_t arrsize, size_t elem_size);
ssize_t			arr_free(t_arr *src);
ssize_t			arr_grow(t_arr *src, size_t newsize);
ssize_t			arr_null(t_arr *src);
```

`arr_new` is the only function that creates a new array. After usage that array has
to be freed using arr_free. If the user wants to grow the size of the array
manually, `arr_grow` can be used. Normally resizing is handled internally though so
arr_grow should only be used in special cases. In case of an error a null array
might be assigned. To check if an array is null, function `arr_null` can be used.

### Manipulating the Elements

```c
ssize_t			arr_add(t_arr *src, void *node, size_t index);
ssize_t			arr_add_first(t_arr *src, void *node);
ssize_t			arr_add_last(t_arr *src, void *node);
ssize_t			arr_add_mult(t_arr *src, size_t count, ...);
ssize_t			arr_put(t_arr *dst, void *src, size_t size);
ssize_t			arr_del(t_arr *src, size_t index);
ssize_t			arr_del_first(t_arr *src);
ssize_t			arr_del_last(t_arr *src);
ssize_t			arr_find(t_arr *src, void *key);
ssize_t			arr_search(t_arr *src, t_arr *key);
void			*arr_get(t_arr *src, size_t index);
void			*arr_get_first(t_arr *src);
void			*arr_get_last(t_arr *src);
void			*arr_take(void *dst, t_arr *src, size_t index);
void			*arr_take_first(void *dst, t_arr *src);
void			*arr_take_last(void *dst, t_arr *src);
```

This group of functions is used to manipulate elements in the array. Find
differs from search such that find matches one element whereas search matches
all elements in the array `key`. Get means getting a pointer to an element,
whereas take gets the element and deletes it (called pop in some
implementations).

### Manipulating the Array

```c

ssize_t			arr_copy(t_arr *dst, t_arr *src);
ssize_t			arr_join(t_arr *dst, t_arr *src);
ssize_t			arr_join_mult(t_arr *dst, size_t count, ...);
ssize_t			arr_rotate(t_arr *arr, ssize_t steps);
ssize_t			arr_read_file(t_arr *dst, char *filename);
ssize_t			arr_iter(t_arr *src,
				ssize_t (*f)(void *, size_t));
ssize_t			arr_iter_range(t_arr *src, size_t start, size_t end,
				ssize_t (*f)(void *, size_t));
ssize_t			arr_parse(t_arr *dst, t_arr *src,
				ssize_t (*f)(t_arr *, void *));

```

This group of functions is used to manipulte or iterate the array in various
ways.

-------------------------------------------------------------------------------

Copyright 2021 Julius Koskela

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

-------------------------------------------------------------------------------
