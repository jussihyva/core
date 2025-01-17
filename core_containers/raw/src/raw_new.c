#include "../../../inc/core.h"

t_ret	raw_new(t_raw *src, t_size bytes)
{
	src->data = malloc(bytes);
	if (!src->data)
	{
		src->size = 0;
		return (CR_ERROR_MALLOC);
	}
	src->size = bytes;
	return (CR_SUCCESS);
}
