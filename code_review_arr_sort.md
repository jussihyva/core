I seek critique on a sorting implementation for a dynamic array data-structure.

## Design decisions

- Uses the quicksort algorithm.
- Uses an optimized XOR swap for swapping the elements. XOR swap doesn't need
  extra memory and is optimized to do the swapping in up to 512 bit chunks.
- Takes the comparison method as a function pointer.

## Request input regarding

- What to comapre it to speedwise?
- Should I implement several other sorting strategies depending on the size of
  the input? What methods could be better for different sizes?
- Any bugs?

## Relevant links:

Dynamic array implementation:
https://github.com/juliuskoskela/core/tree/master/core_containers/array

XOR-swap implementation:
https://github.com/juliuskoskela/core/blob/master/core_standard/memory/src/mswap.c


## Code

### Sorting

```c

static void	arr_sort_recurse(t_array *src,
	t_ssize low,
	t_ssize high,
	t_ssize (*f)(void *, void *))
{
	t_ssize	pivot;
	t_ssize	a;
	t_ssize	b;

	if (low >= high)
		return ;
	pivot = low;
	a = low;
	b = high;
	while (a < b)
	{
		while (a <= high && f(arr_get(src, a), arr_get(src, pivot)) <= 0)
			a++;
		while (b >= low && f(arr_get(src, b), arr_get(src, pivot)) > 0)
			b--;
		if (a < b)
			mswap(arr_get(src, a), arr_get(src, b), src->elem_size);
	}
	mswap(arr_get(src, pivot), arr_get(src, b), src->elem_size);
	arr_sort_recurse(src, low, b - 1, f);
	arr_sort_recurse(src, b + 1, high, f);
}

void	arr_sort(t_array *src, t_ssize (*f)(void *, void *))
{
	arr_sort_recurse(src, 0, src->len - 1, f);
}

```

### Test main

Requires Core-library:
https://github.com/juliuskoskela/core

```c

#include "core/inc/core.h"
#include <time.h>

t_ssize	CMP(void *a, void *b)
{
	int	*ai;
	int	*bi;

	ai = a;
	bi = b;
	if (*ai <= *bi)
		return (0);
	return (1);
}

t_ssize	PRINT(void *data, t_size i)
{
	int	*ptr = data;
	print("%d ", *ptr);
	return (i);
}

static void	shuffle(t_array *arr, int n)
{
	t_int64	i;
	t_int64	j;
	t_int64	*s;
	t_int64	*t;

	if (n < 1)
		return ;
	srand(time(NULL));
	i = 0;
	while (i < n - 1)
	{
		j = i + rand() / (RAND_MAX / (n - i) + 1);
		s = arr_get(arr, i);
		t = arr_get(arr, j);
		mswap(s, t, sizeof(t_int64));
		i++;
	}
}

t_array	generate(int size)
{
	t_array	out;
	t_size	i;

	out = arr_new(size, sizeof(t_int64));
	i = 0;
	while (i < size)
	{
		arr_add_last(&out, &i);
		i++;
	}
	shuffle(&out, size);
	return (out);
}

int	main(int argc, char **argv)
{
	t_array	a1;
	
	a1 = generate(s_toi(argv[1]));
	arr_iter(&a1, PRINT);
	print("\nlist size = %d\n", a1.len);
	arr_sort(&a1, CMP);
	arr_iter(&a1, PRINT);
}

```
