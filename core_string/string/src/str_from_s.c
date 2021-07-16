#include "../inc/string.h"

t_ret	str_from_s(t_str *dst, char *src)
{
	t_ret	ret;
	t_size	len;

	len = s_len(src);
	ret = str_new(dst, len);
	if (ret < 0)
	{
		return (ret);
	}
	dst->raw.data = mcpy(dst->raw.data, src, len);
	dst->raw.data[dst->len] = '\0';
	return (CR_SUCCESS);
}
