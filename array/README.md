# Dynamic Array

A multi-purpose dynamic array implementation for the C language.

A dynamic array is an array which grows automatically without the need to
explicitly reallocate and copy data over. This implementation provieds
functionality to create and manipulate a dynamic array in an efficient
manner. This implementation emulates the functionality of a C++ std::vector.

## Design

-   Dynamic resizing. Doubles the size of the array when maximum size
    is reached.
-   Datatype agnostic. When creating the array user specifies an element size
    for the array (preferrably using the sizeof operator).
-   Data is kept straight in memory for fast iteration. This is not a pointer
    array, all the data is in the array itself avoiding fragmentation.
-   Provides get and add methods, but also let's user typecast the arrays data
    portion and iterate it directly for maximum performance.
-   Alrady allocated memory can be assigned to the array without copying. Array
    will use the allocated memory and manipulate it directly unless it runs out.

## Typedefs

```c

typedef struct  s_arr
{
    uint8_t     *data;
    size_t      len;
    size_t      alloc_size;
    size_t      reserv_size;
    size_t      elem_size;
}               t_arr;

```

`len` refers to the number of members in the array. `alloc_size` is the amount of
allocated space for `elem_size` sized objects. `reserv_size` is the amount of space
available in case pre-allocated memory was assigned to the array. These values
should never be manipulated by the user but they can be accessed and checked easily.

## Functions

These are general descriptions about the functions in the library and their
intended usage. For a detailed description refer to the source-code file
of each function.

### General

```c
t_arr           arr_new(size_t elem_size);
ssize_t         arr_alloc(t_arr *src, size_t alloc_size);
ssize_t         arr_free(t_arr *src);
ssize_t         arr_grow(t_arr *src, size_t newsize);
ssize_t         arr_null(t_arr *arr);
```

`arr_new` is the only function that creates a new array. After usage that array has
to be freed using arr_free. If the user wants to grow the size of the array
manually, `arr_grow` can be used. Normally resizing is handled internally though so
arr_grow should only be used in special cases. In case of an error a null array
might be assigned. To check if an array is null, function `arr_null` can be used.

### Manipulating the Elements

```c
ssize_t         arr_assign(t_arr *dst, void *data, size_t len);
ssize_t         arr_add(t_arr *src, void *node, size_t index);
ssize_t         arr_add_first(t_arr *src, void *node);
ssize_t         arr_add_last(t_arr *src, void *node);
ssize_t         arr_add_mult(t_arr *src, size_t count, ...);
ssize_t         arr_put(t_arr *dst, void *src, size_t size);
ssize_t         arr_del(t_arr *src, size_t index);
ssize_t         arr_del_first(t_arr *src);
ssize_t         arr_del_last(t_arr *src);
void            *arr_get(t_arr *src, size_t index);
void            *arr_get_first(t_arr *src);
void            *arr_get_last(t_arr *src);
void            *arr_take(void *dst, t_arr *src, size_t index);
void            *arr_take_first(void *dst, t_arr *src);
void            *arr_take_last(void *dst, t_arr *src);
```

This group of functions is used to manipulate elements in the array. Find
differs from search such that find matches one element whereas search matches
all elements in the array `key`. Get means getting a pointer to an element,
whereas take gets the element and deletes it (called pop in some
implementations).

### Manipulating the Array

```c

ssize_t         arr_find(t_arr *src, void *key);
ssize_t         arr_search(t_arr *src, t_arr *key);
ssize_t         arr_copy(t_arr *dst, t_arr *src);
ssize_t         arr_join(t_arr *dst, t_arr *src);
ssize_t         arr_join_mult(t_arr *dst, size_t count, ...);
ssize_t         arr_rotate(t_arr *arr, ssize_t steps);
ssize_t         arr_iter(t_arr *src,
                ssize_t (*f)(void *, size_t));
ssize_t         arr_iter_range(t_arr *src, size_t start, size_t end,
                ssize_t (*f)(void *, size_t));
ssize_t         arr_parse(t_arr *dst, t_arr *src,
                ssize_t (*f)(t_arr *, void *));

```

This group of functions is used to manipulte or iterate the array in various
ways.

-------------------------------------------------------------------------------
