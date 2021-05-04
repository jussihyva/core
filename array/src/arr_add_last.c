#include "../inc/arr.h"

ssize_t	arr_add_last(t_arr *arr, void *data)
{
	uint8_t	*mem_pos;

	if (arr->len == arr->alloc_size)
	{
		if (!(arr_grow(arr, arr->alloc_size * 2)))
			return (CR_FAIL);
	}
	mem_pos = arr->data;
	mem_pos += arr->len * arr->elem_size;
	mem_pos = memcpy(mem_pos, data, arr->elem_size);
	arr->len++;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ADD_LAST
**
**	Add a new member to the end of a dynamic string. If the string is not
**	sufficiently big a new memory area double the alloc_size of the previous one
**	is allocated. One extra member is added to the allocation for the case
**	that the string has alloc_size 0.
**
**  ----------------------------------------------------------------------------
*/
