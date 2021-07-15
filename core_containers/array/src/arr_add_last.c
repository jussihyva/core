///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Add a new element to the end of a dynamic array.
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

t_ret	arr_add_last(t_array *dst, void *elem)
{
	t_byte	*raw_pos;
	t_ret	ret;

	if (dst->len == dst->raw.size / dst->elem_size)
	{
		ret = raw_realloc(&dst->raw, dst->raw.size * 2);
		if (ret < 0)
			return (ret);
	}
	raw_pos = dst->raw.data;
	raw_pos += dst->len * dst->elem_size;
	raw_pos = mcpy(raw_pos, elem, dst->elem_size);
	dst->len++;
	return (dst->len);
}
