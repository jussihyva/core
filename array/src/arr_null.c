#include "../inc/arr.h"

ssize_t	arr_null(t_arr *arr)
{
	if (memcmp(arr, &CR_ARR_NULL, sizeof(t_arr)) == 0)
		return (CR_SUCCESS);
	return (CR_FAIL);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_NULL
**
**	Checks if the array is a NULL array.
**
**  ----------------------------------------------------------------------------
*/
