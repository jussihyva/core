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
/// \return 1 on success 0 on failure.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ssize	arr_del(t_array *src, t_size index)
{
	t_byte	*raw_start;
	t_byte	*raw_end;
	t_size	rem;
	t_size	i;

	if (index >= src->len)
		return (CR_FAIL);
	if (index == src->len -1)
	{
		src->len--;
		return (CR_SUCCESS);
	}
	rem = src->len * src->elem_size
		- (index + 1) * src->elem_size;
	raw_start = src->raw.data;
	raw_start += index * src->elem_size;
	raw_end = src->raw.data;
	raw_end += (index + 1) * src->elem_size;
	i = 0;
	while (i < rem)
	{
		*raw_start++ = *raw_end++;
		i++;
	}
	src->len--;
	return (CR_SUCCESS);
}
