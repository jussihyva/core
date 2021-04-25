#include "../inc/core.h"
#include <time.h>

const size_t	iters = 100000000;

int			test_clock(char *test_name, void *alloc_param, int (*f)(void *))
{	
	clock_t begin = clock();
	f(alloc_param);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%s\n%f\n", test_name, time_spent);
	return (1);
}

int			test1(void *param)
{
	t_arr	*test;
	size_t	i;

	test = param;
	i = 0;
	while (i < iters)
	{
		arr_add_last(test, &i);
		i++;
	}
	return (1);
}

int			test2(void *param)
{
	size_t	*test;
	size_t	i;

	i = 0;
	test = param;
	while (i < iters)
	{
		test[i] = i;
		i++;
	}
	return (1);
}

int			main(void)
{	
	t_arr	test1_param;
	size_t	*test2_param;

	test1_param = arr_new(sizeof(size_t));
	arr_alloc(&test1_param, iters);
	test2_param = (size_t *)malloc(sizeof(size_t) * iters);
	test_clock("Add elements to t_arr", &test1_param, test1);
	test_clock("Assign elements to preallocated c-array", test2_param, test2);
	arr_free(&test1_param);
	free(test2_param);
}
