#include "../inc/arr.h"

ssize_t	arr_parse(t_arr *dst, t_arr *src,
		ssize_t (*f)(t_arr *, void *))
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

/*
**  ----------------------------------------------------------------------------
**
**	ARR_PARSE
**
**	Iterate array `src` so that for each member a parse function is executed
**	The parse function is user-defined and parses each member so that rersults
**	are added in `dst`.
**
**  ----------------------------------------------------------------------------
*/
