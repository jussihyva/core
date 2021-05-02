#include "../inc/arr.h"

ssize_t	arr_find_by(t_arr *arr,
		const void *key,
		ssize_t (*f)(const void *, const void *))
{
	size_t	i;
	void	*tmp;

	if (arr_null(arr))
		return (CR_FAIL);
	i = 0;
	while (i < arr->len)
	{
		tmp = arr_get(arr, i);
		if ((f(key, tmp)) == CR_SUCCESS)
			return ((ssize_t)i);
		i++;
	}
	return (CR_FAIL);
}
