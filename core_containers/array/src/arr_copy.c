///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Copy elements from src to dst.
///
/// Checks that element sizes match between the arrays and copies from src to
/// dst. Overrides any data in dst.
///
/// \param dst Destination array.
/// \param src Source array.
/// \return Elements copied or return error.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_copy(
		t_array *dst,
		t_array *src)
{
	t_byte	*raw_start;
	t_ret	ret;

	if (arr_null(src))
		return (CR_ERROR_INPUT);
	if (dst->raw.size <= src->len * src->elem_size)
	{
		ret = raw_realloc(&dst->raw, src->len * src->elem_size);
		if (ret < 0)
			return (ret);
	}
	raw_start = dst->raw.data;
	dst->raw.data = mcpy(
			raw_start,
			src->raw.data,
			src->len * src->elem_size);
	dst->len = src->len;
	return (dst->len);
}
