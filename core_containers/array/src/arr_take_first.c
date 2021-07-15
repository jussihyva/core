///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Take the first element from an array.
///
/// Take is a combination of get and del. A pointer to an allocated memory dst
/// sufficient to hold the results has to be passed as a parameter.
///
/// \param dst Destination memory.
/// \param src source array.
///
/// \return Index or return error.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_take_first(
		void *dst,
		t_array *src)
{
	t_ret	ret;

	ret = arr_take(dst, src, 0);
	if (ret < 0)
		return (ret);
	return (src->len);
}
