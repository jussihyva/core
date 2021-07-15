///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Take an element from specified index in a dynamic array.
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

t_ret	arr_take(
		void *dst,
		t_array *src,
		t_size index)
{
	void	*tmp;
	t_ret	ret;
	if (index >= src->len)
		return (CR_ERROR_BOUNDS);
	tmp = arr_get(src, index);
	dst = mcpy(dst, tmp, src->elem_size);
	ret = arr_del(src, index);
	if (ret < 0)
		return (ret);
	return (src->len);
}
