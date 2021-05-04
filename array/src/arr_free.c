#include "../inc/arr.h"

ssize_t	arr_free(t_arr *arr)
{
	free(arr->data);
	*arr = CR_ARR_NULL;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_FREE
**
**	Deallocate a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
