#include "../inc/arr.h"

ssize_t	arr_add_first(t_arr *arr, void *data)
{
	if (!(arr_add(arr, data, 0)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ADD_FIRST
**
**	Add a new member to the beginning of a dynamic string. If the string is not
**	sufficiently big a new memory area double the alloc_size of the previous one
**	is allocated. One extra member is added to the allocation for the case
**	that the string has alloc_size 0.
**
**  ----------------------------------------------------------------------------
*/
