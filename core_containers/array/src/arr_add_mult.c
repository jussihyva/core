///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Add multiple elements to a dynamic array.
///
/// Adds a variable amount of elements to a dynamic array passed as arguments.
/// Number of arguments have to be defined in the count variable.
///
/// \param count Number of elements passed as arguments.
/// \param first Destination array.
/// \param va_list Arrays to be joined.
/// \return 1 on success 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_add_mult(
		t_array *dst,
		t_size count,
		...)
{
	va_list	ap;
	void	*arg;
	t_ret	ret;

	va_start(ap, count);
	while (count--)
	{
		arg = va_arg(ap, void *);
		if (!arg)
			return (CR_ERROR_BOUNDS);
		ret = arr_add_last(dst, arg);
		if (ret < 0)
			return (ret);
	}
	va_end(ap);
	return (dst->len);
}
