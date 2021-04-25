#include "../inc/arr.h"

ssize_t	arr_alloc(t_arr *src, size_t alloc_size)
{
	if (alloc_size == 0)
		return (CR_FAIL);
	src->len = 0;
	src->alloc_size = alloc_size;
	src->reserv_size = 0;
	src->data = (uint8_t *)malloc(src->elem_size * alloc_size);
	if (!src->data)
	{
		perror("Array allocation failed in arr_new!\n");
		return (CR_FAIL);
	}
	return ((ssize_t)src->alloc_size);
}