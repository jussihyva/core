#include "../../../inc/core.h"

t_hmem	mem_chr(t_mem src, t_mem b)
{
	t_hmem	res;
	size_t	i;

	res.data = NULL;
	res.size = 0;
	i = 0;
	while (i < src.size)
	{
		if (memcmp(&src.data[i], b.data, b.size) == 0)
		{
			res = hmem_range(src, i, src.size);
			return (res);
		}
		i++;
	}
	return (res);
}