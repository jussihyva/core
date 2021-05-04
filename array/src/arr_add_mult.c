#include "../inc/arr.h"

ssize_t	arr_add_mult(t_arr *arr, size_t count, ...)
{
	va_list	ap;

	va_start(ap, count);
	while (count--)
	{
		if (!(arr_add_last(arr, va_arg(ap, void *))))
			return (CR_FAIL);
	}
	va_end(ap);
	return ((ssize_t)arr->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ADD_MULT
**
**	Add `count` members to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
