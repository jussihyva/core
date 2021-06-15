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
	return (time_spent);
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int	test(void *arg, t_size size)
{
	qsort((int *)arg, size, sizeof(int), cmpfunc);
	return (1);
}

static void	shuffle(int *arr, int n)
{
	t_int64	i;
	t_int64	j;

	if (n < 1)
		return ;
	srand(time(NULL));
	i = 0;
	while (i < n - 1)
	{
		j = i + rand() / (RAND_MAX / (n - i) + 1);
		mswap(&arr[i], &arr[j], sizeof(int));
		i++;
	}
}

int	*rand_arr(int size)
{
	int	*out;
	t_size	i;

	out = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		out[i] = i;
		i++;
	}
	shuffle(out, size);
	return (out);
}

int main (int argc, char **argv)
{
	int *values;
	t_size	size;
	t_size	permutations;
	double	total;
	t_size	i;

	total = 0;
	permutations = s_toi(argv[1]);
	size = s_toi(argv[2]);
	i = 0;
	while (i < size)
	{
		values = rand_arr(s_toi(argv[1]));
		total += test_clock("LIBC QSORT",
			values,
			s_toi(argv[1]),
			test);
		free(values);
		i++;
	}
	print("LIBC QSORT\n");
	print("SIZE %llu\n", size);
	print("PERMS %llu\n", permutations);
	print("AVERAGE TIME %f\n", total / permutations);
	return(0);
}
