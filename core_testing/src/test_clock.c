#include "../../inc/core.h"

double	test_clock(void *params, void (*f)(void *))
{
	clock_t begin = clock();
	f(params);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	return (time_spent);
}
