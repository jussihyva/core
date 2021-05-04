#include "../inc/arr.h"

ssize_t	arr_del_last(t_arr *arr)
{
	if (!(arr_del(arr, arr->len - 1)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_DEL_LAST
**
**	Delete the last member from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
