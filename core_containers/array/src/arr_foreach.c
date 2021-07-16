///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Simple foreach iterator with minimal f- function.
///
/// An iterator function that takes a user defined function f as a parameter
/// and applies f to each element iterated.
///
/// \param src Source array.
/// \param f A function to be applied to each iterated element.
///
/// \return Index or return error.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/array.h"

t_ret	arr_foreach(
			t_array *src,
			void (*f)(void *))
{
	t_size	i;
	void	*tmp;

	if (arr_null(src))
		return (CR_ERROR_INPUT);
	i = 0;
	while (i < src->len)
	{
		tmp = arr_get(src, i);
		f(tmp);
		i++;
	}
	return (i);
}
