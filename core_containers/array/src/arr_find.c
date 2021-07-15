///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Find an index of an element.
///
/// Finds the index of an element passed as an argument from the array src.
///
/// \param src Source array.
/// \param key The element to be searched.
/// \return Index or return error.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_find(
		t_array *src,
		void *key)
{
	void	*value;
	t_size	i;

	i = 0;
	while (1)
	{
		if (i == src->len)
			break ;
		value = arr_get(src, i);
		if (mcmp(key, value, src->elem_size) == 0)
			return (i);
		i++;
	}
	return (CR_ERROR_BOUNDS);
}
