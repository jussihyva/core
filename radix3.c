#include "inc/core.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inc/core.h"

void radixSort(int* a, int N)
{
    const int INT_BIT_SIZE = sizeof(int) << 3;
	const int RADIX = 0x100;
	const int MASK = RADIX-1;
	const int MASK_BIT_LENGTH = 8;
    int *result = malloc(N * sizeof(int));
	int *buckets = malloc(RADIX * sizeof(int));
	int *startIndex = malloc(RADIX * sizeof(int));
    int flag = 0;
	int key = 0;
    t_bool hasNeg = FALSE;


    while (flag < INT_BIT_SIZE)
	{
        for (int i = 0; i < N; ++i)
		{
            key = (a[i] & (MASK << flag)) >> flag;
            if(key < 0)
			{
                key += MASK;
                hasNeg = TRUE;
            }
            ++buckets[key];
        }
        startIndex[0] = 0;
        for (int j = 1; j < RADIX; ++j)
			startIndex[j] = startIndex[j - 1] + buckets[j - 1];
        for (int i = N-1; i >= 0; --i)
		{
            key = (a[i] & (MASK << flag)) >> flag;
            if(key < 0)
				key += MASK;
            result[startIndex[key] + --buckets[key]] = a[i];
        }
        memcpy(a, result, N * sizeof(int));
        flag += MASK_BIT_LENGTH;
    }
    if(hasNeg)
	{
        int indexOfNeg = 0;
        for (int i = 0; i < N; i++)
		{
            if(a[i] < 0)
			{
                indexOfNeg = i;
                break ;
            }
        }
        memcpy(a,result+indexOfNeg,(N-indexOfNeg)*sizeof(int));
        memcpy(a+(N-indexOfNeg),result,indexOfNeg*sizeof(int));
    }
    free(result);
    free(buckets);
    free(startIndex);
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
	radixSort((int *)arg, size);
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
