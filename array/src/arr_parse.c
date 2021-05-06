/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Iterate the array for each element for parsing.
 *
 * Iterates over each element of the src array. At each iteration a user
 * defined function f is called and dst array as well as current member passed
 * as parameters. Intended usage is for parsing each member and putting the
 * results in the dst array. Iteration can be stopped by returning a
 * non-positive integer from f.
 *
 * \param dst Destination array.
 * \param src Source array.
 * \param f Function f to be called for each member.
 *
 * \return Amount of elements iterated on success 0 on failure.
 *
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_parse(t_array *dst, t_array *src,
		ssize_t (*f)(t_array *, void *))
{
	size_t	i;
	void	*data;

	if (arr_null(src) || arr_null(dst))
		return (CR_FAIL);
	i = 0;
	while (i < src->len)
	{
		data = arr_get(src, i);
		if (!(f(dst, data)))
			return ((ssize_t)i);
		i++;
	}
	return ((ssize_t)i);
}
