#include "../inc/core.h"

ssize_t	print_char(void *data, size_t i)
{
	char	*ptr;

	ptr = data;
	printf("%c", *ptr);
	return (i);
}

int	main(void)
{
	t_arr	arr;

	arr = arr_new(sizeof(char));
	arr_assign(&arr, "abcdefg", 3);
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

