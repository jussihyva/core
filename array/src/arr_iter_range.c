/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Iterate a range in a dynamic array and apply f to each element.
 *
 * An iterator function that takes a user defined function f as a parameter
 * and applies f to each element iterated. Range of iteration is defined
 * to be from the variables start to end passed as arguments. If f returns a
 * value < 1, iteration stops.
 *
 * \param src Source array.
 * \param start Start index of the range to be iterated.
 * \param end End index of the range to be iterated.
 * \param f A function to be applied to each iterated element.
 *
 * \return Amount of elements iterated on success or 0 on failure.
 *
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_iter_range(t_arr *src, size_t start, size_t end,
		ssize_t (*f)(void *, size_t))
{
	size_t	i;
	void	*tmp;

	i = start;
	if (arr_null(src)
	|| start > src->len
	|| end > src->len
	|| start < end)
		return (CR_FAIL);
	while (i < end)
	{
		tmp = arr_get(src, i);
		if (!(f(tmp, i)))
			return ((ssize_t)i);
		i++;
	}
	return ((ssize_t)i);
}
