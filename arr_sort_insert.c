///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Sort array
///
/// \param src Source array
/// \param f Comparison method.
///
///////////////////////////////////////////////////////////////////////////////

#include "inc/core.h"
#include <time.h>

void	arr_sort_insertion(t_array *src,
		t_size start,
		t_size end,
		void *key,
		t_ssize (*f)(void *, void *))
{
	t_ssize	i;
	t_ssize	j;

	i = start + 1;
	while (i < end)
	{
		mcpy(key, arr_get(src, i), src->elem_size);
		j = i - 1;
		while (j >= start && f(arr_get(src, j), key) > 0)
		{
			mcpy(arr_get(src, j + 1), arr_get(src, j), src->elem_size);
			j--;
		}
		mcpy(arr_get(src, j + 1), key, src->elem_size);
		i++;
	}
}

void	arr_isort(t_array *src, 
		t_ssize (*f)(void *, void *))
{
	void	*key;
	
	key = malloc(src->elem_size);
	arr_sort_insertion(src, 0, src->len, key, f);
	free(key);
}


t_ssize CMP(void * a, void * b)
{
	if (!a || !b)
		return (0);
	return (*(int*)a - *(int*)b);
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
	arr_isort(&a1, CMP);
	arr_iter(&a1, PRINT);
}
