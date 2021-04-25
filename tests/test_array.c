#include "../inc/core.h"

ssize_t	arr_assign(t_arr *dst, void *data, size_t len)
{
	if (arr_null(dst) || dst->alloc_size > 0)
		return (CR_FAIL);
	dst->data = data;
	dst->reserv_size = len;
	dst->len = len;
	return (CR_SUCCESS);
}

ssize_t	print_char(void *data, size_t i)
{
	char	*ptr;

	ptr = data;
	printf("%c", *ptr);
	return (i);
}

int main(void)
{
	t_arr	b;
	char	c;
	char	str[10] = "123456789";

	c = 'a';
	b = arr_new(sizeof(char));
	arr_assign(&b, str, 10);
	printf("\nlen: %zu alloc_size: %zu elem_size: %zu\n",
			b.len, b.alloc_size, b.elem_size);
	arr_del_last(&b);
	arr_del_last(&b);
	arr_add_last(&b, &c);
	arr_iter(&b, print_char);
	printf("\nlen: %zu alloc_size: %zu elem_size: %zu\n",
			b.len, b.alloc_size, b.elem_size);
	arr_free(&b);
}
