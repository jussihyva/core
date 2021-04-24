# Dynamic Array

A multi-purpose dynamic array implementation for the C language.

## Design

-   Dynamic resizing. Doubles the size of the array when maximum size
    is reached.
-   Datatype agnostic. Contains only pointers to array members.
-   Clear allocation and deallocation of the array structure. Only the
    constructor `parr_new` returns an array to help clarity.
-   All other functions apart from the constructor work by passing
    all parameters (also the destination variable) by reference.
-   Since most functions are not returning the array or a pointer the
    return value is used to return something useful. Usually the amount
    of operations executed on success or a `CR_FAIL` on failure.
-   Library provides basic functionality to work with the array and
    useful templates for user defined functionality. These templates take in
    lambda functions (function pointers) and the idea is for the user to define
    those separately according to the template lambda expressions.

## Typedefs and Macros

```c

typedef struct  s_parr
{
    void        **data;
    size_t      len;
    size_t      size;
}               t_parr;

```

`Count` refers to the number of members in the array. `Size` is the size of the
allocated memory associated with the array. Neither should ever be manipulated
by the user but they can be accessed and checked easily.

The following macros are provided:

```c

// CR_STOP array iteration.
# define CR_CR_STOP -1
// Just for clarity. Any value != CR_CR_STOP will let iteration to CR_CONTINUE.
# define CR_CR_CONT 1
// Something went wrong.
# define CR_FAIL -1
// A flag for parr_write_file (write over file)
# define CR_WRITE 0
// A flag for parr_write_file (append to file)
# define CR_APPEND 1
// A flag for parr_write_file (prepend to file)
# define CR_PREPEND -1
// A flag to signify array contents are NULL terminated strings.
# define CR_STRING NULL

```

## Functions

These are general descriptions about the functions in the library and their
intended usage. For a detailed description refer to the source code file
of each function.

### General

```c

t_parr           parr_new(size_t size);
int             parr_free(t_parr *arr);
int             parr_grow(t_parr *arr, size_t new_size);
int             parr_null(t_parr *arr);

```

`CR_new` is the only function that creates a new array. After usage that array has
to be freed using parr_free. If the user wants to grow the size of the array
manually, `parr_grow` can be used. Normally resizing is handled internally though so
parr_grow should only be used in special cases. In case of an error a null array
might be assigned. To check if an array is null, function `parr_null` can be used.

### Add & Delete

```c

int             parr_add(t_parr *arr, void *data, size_t index);
int             parr_add_first(t_parr *arr, void *data);
int             parr_add_last(t_parr *arr, void *data);
int             parr_add_mult(t_parr *arr, size_t len, ...);
int             parr_assign(t_parr *dst, void **src, size_t size);
int             parr_del(t_parr *arr, size_t index);
int             parr_del_first(t_parr *arr);
int             parr_del_last(t_parr *arr);

```

This group of functions is used to add and delete members from an array.  The
functions without a postfix (such as `parr_add`) manipulate data in a defined index.
The rest are templated to add to the end or start of the array, to add multiple
things into an array or to add a normal array to an array.

### Get & Take

```c

void            *parr_get(t_parr *arr, size_t index);
void            *parr_get_first(t_parr *arr);
void            *parr_get_last(t_parr *arr);
void            *parr_take(t_parr *arr, size_t index);
void            *parr_take_first(t_parr *arr);
void            *parr_take_last(t_parr *arr);

```

This group of functions is used to fetch a single member from an array.  A `get`
style function just fetches the member whereas a `take` style function also
removes the fetched member from the list.

### Manipulate

```c

int             parr_copy(t_parr *dst, t_parr *src);
int             parr_join(t_parr *dst, size_t len, ...);
int             parr_split(t_parr *dst, t_parr *src);

```

This group of functions is used to manipulte the pointers in an array in
different ways. These functions don't touch the actual data, only the pointers.

### Templates

```c

int             parr_dup(t_parr *dst, t_parr *src, size_t size);
int             parr_read_file(t_parr *dst, char *filename);
int             parr_write_file(char *dst, t_parr *src, ssize_t flag,
                int (*f)(void **, void *));
int             parr_write(t_parr *dst, t_parr *src,
                int (*f)(void **, void *));
int             parr_search(t_parr *dst, t_parr *src, void *key,
                void *(*f)(void *, void *));
void            *parr_find(t_parr *src, void *key,
                void *(*f)(void *, void *));
int             parr_iterate(t_parr *arr,
                int (*f)(void **, size_t));
int             parr_parse(t_parr *dst, t_parr *src,
                int (*f)(t_parr *, void *));

```

These are function templates that iterate the array in different ways or make
assumptions about the datatype associated with the array (such as reading
or writing to/from a file assume strings).

## Lambda Expressions

The lambda expressions used in the template functions represent user defined
actions that work on the data stored in the array. This modular concept helps us
structure code, reuse code and to avoid writing and debugging while loops.

This lambda expression is used in `parr_iterate`.

```c

// Lamda expression.
int (*f)(void **, size_t);

// Example defintion.
int             print_string(void **data, size_t i)
{
    char        *ptr;

    ptr = *data;
    printf("[%s\n", i, ptr);
    return (i);
}

```

This lambda expression is used in `parr_write` and `write_file`.

```c

// Lambda expression.
int (*f)(void **, void *);

// Example defintion.
int             serialize(void **dst, void *src)
{
    char        *dst_cast;
    t_person    *src_cast;

    src_cast = src;
    dst_cast = malloc(sizeof(char) * 100);
    sprintf(dst_cast, "%s,%s,%d",
            src_cast->firstname,
            src_cast->lastname,
            src_cast->age);
    *dst = dst_cast;
    return (CR_CONTINUE);
}

```

This is the lambda expression for `parr_parse`.

```c

// Lambda expression.
int (*f)(t_parr *, void *);

// Example defintion.
int             deserialize(t_parr *dst, void *data)
{
    t_person    *person;
    char        **words;

    if (!(person = (t_person *)malloc(sizeof(t_person))))
        return (CR_STOP);
    words = s_split((char *)data, ',');
    person->firstname = words[0];
    person->lastname = words[1];
    person->age = atoi(words[2]);
    free(words[2]);
    free(words);
    parr_add_last(dst, person);
    return (CR_CONTINUE);
}

```

This is the lambda expression for `parr_search` and `parr_find`.

```c

// Lambda expression.
void *(*f)(void *, void *);

// Example defintion.
void            *match_lastname(void *key, void *val)
{
    char        *key_cast;
    t_person    *val_cast;

    key_cast = key;
    val_cast = val;
    if (s_cmp(val_cast->lastname, key_cast) == 0)
        return ((void *)val_cast);
    return (NULL);
}

```
## Usage Examples

There are test programs inside the `tests` folder. Refer to those to get more
clarity about the usage of the library.

Hope you like it, happy coding! :)

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

