#include "inc/core.h"
#include <time.h>

void radix_sort_u32(int *arr, int *aux, t_size n)
{
	t_size cnt0[256] = { 0 };
	t_size cnt1[256] = { 0 };
	t_size cnt2[256] = { 0 };
	t_size cnt3[256] = { 0 };
	t_size i;

	for (i = 0 ; i < n ; ++i)
	{
		t_uint32 k = arr[i];

		t_uint8 k0 = (k >> 0) & 0xFF;
		t_uint8 k1 = (k >> 8) & 0xFF;
		t_uint8 k2 = (k >> 16) & 0xFF;
		t_uint8 k3 = (k >> 24) & 0xFF;

		++cnt0[k0];
		++cnt1[k1];
		++cnt2[k2];
		++cnt3[k3];
	}
	t_size a0 = 0;
	t_size a1 = 0;
	t_size a2 = 0;
	t_size a3 = 0;
	for (int j = 0 ; j < 256 ; ++j)
	{
		t_size b0 = cnt0[j];
		t_size b1 = cnt1[j];
		t_size b2 = cnt2[j];
		t_size b3 = cnt3[j];
		cnt0[j] = a0;
		cnt1[j] = a1;
		cnt2[j] = a2;
		cnt3[j] = a3;
		a0 += b0;
		a1 += b1;
		a2 += b2;
		a3 += b3;
	}
	for (i = 0 ; i < n ; ++i)
	{
		t_uint32 k = arr[i];
		t_uint8 k0 = (k >> 0) & 0xFF;
		t_size dst = cnt0[k0]++;
		aux[dst] = arr[i];
	}
	mcpy(arr, aux, sizeof(int) * n);
	for (i = 0 ; i < n ; ++i)
	{
		t_uint32 k = arr[i];
		t_uint8 k1 = (k >> 8) & 0xFF;
		t_size dst = cnt1[k1]++;
		aux[dst] = arr[i];
	}
	mcpy(arr, aux, sizeof(int) * n);
	for (i = 0 ; i < n ; ++i)
	{
		t_uint32 k = arr[i];
		t_uint8 k2 = (k >> 16) & 0xFF;
		t_size dst = cnt2[k2]++;
		aux[dst] = arr[i];
	}
	mcpy(arr, aux, sizeof(int) * n);
	for (i = 0 ; i < n ; ++i)
	{
		t_uint32 k = arr[i];
		t_uint8 k3 = (k >> 24) & 0xFF;
		t_size dst = cnt3[k3]++;
		aux[dst] = arr[i];
	}
}

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

int cmpfunc(const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int	test(void *arg, t_size size)
{
	int	*aux = malloc(sizeof(int) * size);
	radix_sort_u32((int *)arg, aux, size);
	free(aux);
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

int	sorted(int *arr, t_size size)
{
	t_size i;

	i = 0;
	while (i < size - 1)
	{
		print("%d\n", arr[i]);
		if (arr[i] > arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int main (int argc, char **argv)
{
	int *values;
	t_size	size;
	t_size	permutations;
	double	total;
	int	so;
	t_size	i;

	total = 0;
	permutations = s_toi(argv[1]);
	size = s_toi(argv[2]);
	so = 0;
	i = 0;
	while (i < size)
	{
		values = rand_arr(s_toi(argv[1]));
		total += test_clock("LIBC QSORT",
			values,
			s_toi(argv[1]),
			test);
		so += sorted(values, size);
		free(values);
		i++;
	}
	if (so > 0)
		print("KO\n");
	else
	{
		print("OK\n");
		print("LIBC QSORT\n");
		print("SIZE %llu\n", size);
		print("PERMS %llu\n", permutations);
		print("AVERAGE TIME %f\n", total / permutations);
	}
	return(0);
}
