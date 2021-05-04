#include "../inc/arr.h"

ssize_t	arr_add(t_arr *arr, void *data, size_t index)
{
	uint8_t	*mem_pos;
	uint8_t	*mem_tmp;

	if (arr->len == arr->alloc_size)
	{
		if (!(arr_grow(arr, arr->alloc_size * 2)))
			return (CR_FAIL);
	}
	mem_pos = arr->data;
	mem_pos += index * arr->elem_size;
	mem_tmp = arr->data;
	mem_tmp += (index + 1) * arr->elem_size;
	mem_move(mem_tmp, mem_pos, arr->elem_size * (arr->len - index));
	memcpy(mem_pos, data, arr->elem_size);
	arr->len++;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ADD
**
**	Add a new member to any index in an array. If index exceeds member
**	len, new member is added to the end of the array.
**
**  ----------------------------------------------------------------------------
*/
