///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Delete an element from a specific index.
///
/// If the element has pointers to allocated memory, those have to be handled
/// by the user. Checks for out of bounds index.
///
/// \param src Source array.
/// \param index Index of the element to be deleted.
/// \return Index or return error.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

static void	bytecpy(
		t_byte *a,
		t_byte *b,
		t_size len)
{
	while (len--)
		*a++ = *b++;
}

t_ret	arr_del(
		t_array *src,
		t_size index)
{
	t_byte	*raw_start;
	t_byte	*raw_end;
	t_size	rem;

	if (index >= src->len)
		return (CR_ERROR_BOUNDS);
	if (index == src->len - 1)
	{
		src->len--;
		return (src->len);
	}
	rem = src->len * src->elem_size
		- (index + 1) * src->elem_size;
	raw_start = src->raw.data;
	raw_start += index * src->elem_size;
	raw_end = src->raw.data;
	raw_end += (index + 1) * src->elem_size;
	bytecpy(raw_start, raw_end, rem);
	src->len--;
	return (src->len);
}
