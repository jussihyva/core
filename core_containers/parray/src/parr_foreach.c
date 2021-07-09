///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Iterate over each element of the pointer array.
///
/// \param src Source array.
/// \param f Pointer to a function to be executed on each element.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/parr.h"

void	parr_foreach(t_parray *src, void (*f)(const void *))
{
	t_size	i;

	i = 0;
	while (i < src->len)
	{
		f(parr_get(src, i));
		i++;
	}
}
