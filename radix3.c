#include "inc/core.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inc/core.h"

int radix = 4;

int getMax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int *array, int size, int place)
{
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++)
  {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];
  for (int i = 0; i < max; ++i)
    count[i] = 0;
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];
  for (int i = size - 1; i >= 0; i--)
  {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }
  mcpy(array, output, sizeof(int) * size);
}

void radixsort(int array[], int size)
{
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d  ", array[i]);
  printf("\n");
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
	radixsort((int *)arg, size);
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
