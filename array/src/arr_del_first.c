#include "../inc/arr.h"

ssize_t	arr_del_first(t_arr *arr)
{
	if (!(arr_del(arr, 0)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_DEL_FIRST
**
**	Delete the first member from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
