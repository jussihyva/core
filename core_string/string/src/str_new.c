#include "../inc/string.h"

t_ret	str_new(t_str *src, t_size len)
{
	t_ret	ret;

	ret = raw_new(&src->raw, len + 1);
	if (ret < 0)
	{
		return (ret);
	}
	src->len = len;
	src->raw.data[0] = '\0';
	return (CR_SUCCESS);
}
