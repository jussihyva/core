///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Delete first element in a dynamic array.
///
/// If the element has pointers to allocated memory, those have to be handled
/// by the user.
///
/// \param src Source array.
/// \return Index or return error.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_del_first(
		t_array *src)
{
	t_ret	ret;

	ret = arr_del(src, 0);
	if (ret < 0)
		return (ret);
	return (src->len);
}
