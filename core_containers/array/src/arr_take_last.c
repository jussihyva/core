///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Take the last element from an array.
///
/// Take is a combination of get and del. A pointer to an allocated memory dst
/// sufficient to hold the results has to be passed as a parameter.
///
/// \param dst Destination memory.
/// \param src source array.
///
/// \return Pointer to dst.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_take_last(
		void *dst,
		t_array *src)
{
	t_ret	ret;

	ret = arr_take(dst, src, src->len - 1);
	if (ret < 0)
		return (ret);
	return (src->len);
}
