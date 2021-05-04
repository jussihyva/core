#include "../inc/arr.h"

void	*arr_get_last(t_arr *arr)
{
	return (arr_get(arr, arr->len - 1));
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_GET_LAST
**
**	Pull the last member from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
