#include "../inc/arr.h"

void	*arr_get_first(t_arr *arr)
{
	return (arr_get(arr, 0));
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_GET_FIRST
**
**	Pull the first member from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
