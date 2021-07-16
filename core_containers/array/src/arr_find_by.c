///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Find an index of a element according to a user defined method.
///
/// Finds the index of an element that corresponds to a key passed as a
/// parameter. How the key associates to the element is defined by a user in
/// the function f passed as a parameter. F has to take two pointers to void
/// as parameters of which the first one will be the key and the second one the
/// next element in the array. F has to return 1 if a key matches the element
/// at which point the function will terminate and return the index.
///
/// \param src Source array.
/// \param key A key of any type which will be matched to an element.
/// \param f A pointer to a function which returns 1 if an element assosiactes
/// to a key.
/// \return Index or return error.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_find_by(
		t_array *src,
		const void *key,
		t_ssize (*f)(const void *, const void *))
{
	t_size	i;
	void	*tmp;

	if (arr_null(src))
		return (CR_ERROR_INPUT);
	i = 0;
	while (i < src->len)
	{
		tmp = arr_get(src, i);
		if ((f(key, tmp)) == CR_SUCCESS)
			return (i);
		i++;
	}
	return (CR_ERROR_BOUNDS);
}
