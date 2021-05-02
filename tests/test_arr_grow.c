#include "../inc/core.h"












ssize_t	print_uint64(void *data, size_t i)
{
	uint64_t	*ptr;

	ptr = data;
	printf("%zu\n", *ptr);
	return (i);
}

void	test_arr_grow()
{
	t_arr	test_1;
	uint64_t	x;
	test_1 = arr_new(1, sizeof(uint64_t));
	x = 0;
	size_t i = 0;
	while (i < 100)
	{
		arr_add_last(&test_1, &x);
		i++;
		x += 100;
	}
	arr_iter(&test_1, print_uint64);
}

int main(void)
{
	test_arr_grow();
}