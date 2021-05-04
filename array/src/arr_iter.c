/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Iterate a dynamic array and apply f to each element.
 *
 * An iterator function that takes a user defined function f as a parameter
 * and applies f to each element iterated. If f returns a
 * value < 1, iteration stops.
 *
 * \param src Source array.
 * \param f A function to be applied to each iterated element.
 *
 * \return Amount of elements iterated on success or 0 on failure.
 *
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_iter(t_arr *arr,
		ssize_t (*f)(void *, size_t))
{
	size_t	i;
	void	*tmp;

	if (arr_null(arr))
		return (CR_FAIL);
	i = 0;
	while (i < arr->len)
	{
		tmp = arr_get(arr, i);
		if ((f(tmp, i)) == CR_STOP)
			return ((ssize_t)i);
		i++;
	}
	return ((ssize_t)i);
}
