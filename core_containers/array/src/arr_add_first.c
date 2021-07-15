///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Add a new element to the beginning of a dynamic array.
///
/// If the array is not sufficiently big a new memory area double the
/// alloc_size of the previous one is allocated.
///
/// \param dst Destination array.
/// \param elem Element to be added.
/// \return 1 on success 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_add_first(t_array *dst, void *elem)
{
	t_ret	ret;

	if (!(arr_add(dst, elem, 0)))
	{
		ret = arr_add(dst, elem, 0);
		if (ret < 0)
			return (ret);
	}
	return (dst->len);
}
