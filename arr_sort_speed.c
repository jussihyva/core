#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inc/core.h"

double	test_clock(
		char *test_name,
		void *alloc_param,
		t_size size,
		int (*f)(void *, t_size))
{
	clock_t begin = clock();
	f(alloc_param, size);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	/*printf("%s\n%f\n", test_name, time_spent);*/
	return (time_spent);
}

t_ssize cmpfunc (void * a, void * b)
{
   return ( *(int*)a - *(int*)b );
}

int	test(void *arg, t_size size)
{
	arr_sort((t_array *)arg, cmpfunc);
	return (1);
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

t_array	rand_arr(t_size size)
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

int	sorted(t_array *arr)
{
	t_size	i;
	int		*a;
	int		*b;
	i = 0;
	while (i < arr->len - 1)
	{
		a = arr_get(arr, i);
		b = arr_get(arr, i + 1);
		if (*a > *b)
			return (1);
		i += 2;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_array values;
	t_size	permutations;
	t_size	size;
	t_size	i;
	int		so;
	double	total;

	total = 0;
	so = 0;
	permutations = s_toi(argv[1]);
	size = s_toi(argv[2]);
	i = 0;
	while (i < permutations)
	{
		values = rand_arr(size);
		total += test_clock("CORE ARR_SORT",
			&values,
			s_toi(argv[1]),
			test);
		so += sorted(&values);
		arr_free(&values);
		i++;
	}
	print("SIZE %llu\n", size);
	print("PERMS %llu\n", permutations);
	print("AVERAGE TIME %f\n", total / permutations);
	if (so == 0)
		print("OK\n");
	else
		print("KO\n");
	return(0);
}

