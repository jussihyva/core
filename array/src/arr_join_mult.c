/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Join multiple arrays.
 *
 * \param
 *
 * \return
 *
 ******************************************************************************/

#include "../inc/arr.h"
#include "../../inc/core.h"

ssize_t	arr_join_mult(t_array *dst, size_t len, ...)
{
	va_list	ap;
	t_array	*tmp;

	va_start(ap, len);
	while (len--)
	{
		tmp = va_arg(ap, t_array *);
		if (arr_null(tmp))
			return (CR_FAIL);
		if (!(arr_join(dst, tmp)))
			return (CR_FAIL);
	}
	va_end(ap);
	return ((ssize_t)dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_JOIN_MULT
**
**	Join `len` amount of arrays to the source array `dst`.
**
**  ----------------------------------------------------------------------------
*/
