///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Join multiple arrays.
///
/// \param
///
/// \return
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_join_mult(
		t_array *dst,
		t_size count,
		...)
{
	va_list	ap;
	t_array	*tmp;
	t_ret	ret;

	if (!dst || arr_null(dst))
		return (CR_ERROR_INPUT);
	va_start(ap, count);
	while (count--)
	{
		tmp = va_arg(ap, t_array *);
		if (!tmp || arr_null(tmp))
			return (CR_ERROR_INPUT);
		ret = arr_join(dst, tmp);
		if (ret < 0)
			return (ret);
	}
	va_end(ap);
	return (dst->len);
}
