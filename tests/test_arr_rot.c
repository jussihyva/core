#include "../inc/core.h"

t_ssize	print_char(void *data, t_size i)
{
	char	*ptr;

	ptr = data;
	printf("%c", *ptr);
	return (i);
}

int	main(void)
{
	t_array	arr;
	char	c;

	c = 'A';
	arr = arr_new(sizeof(char));
	arr_assign(&arr, "abcdefg", 3);
	arr_add_last(&arr, &c);
	arr_iter(&arr, print_char);
	printf("\n");
	arr_rotate(&arr, 1);
	arr_iter(&arr, print_char);
	printf("\n");
	arr_rotate(&arr, 1);
	arr_iter(&arr, print_char);
	printf("\n");
	arr_rotate(&arr, 1);
	arr_iter(&arr, print_char);
	printf("\n");
	arr_free(&arr);
}

