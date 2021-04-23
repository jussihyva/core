#include "inc/core.h"
#include <time.h>

const size_t	iters = 100000000;

int			test(int (*f)())
{	
	clock_t begin = clock();
	f();
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("TIME: %f\n", time_spent);
	return (1);
}

int			test1()
{
	t_arr	test;
	size_t	*ptr;
	size_t	i;

	test = arr_new(1, sizeof(size_t));
	i = 0;
	while (i < iters)
	{
		arr_add_last(&test, &i);
		i++;
	}
	ptr = arr_get_last(&test);
	printf("%zu\n", *ptr);
	return (1);
}


int			test2()
{
	size_t	*test;
	size_t	i;

	i = 0;
	test = (size_t *)malloc(sizeof(size_t) * iters);
	while (i < iters)
	{
		test[i] = i;
		i++;
	}
	printf("%zu\n", test[iters - 1]);
	return (1);
}

int			main(void)
{
	test(test1);
	test(test2);
}
