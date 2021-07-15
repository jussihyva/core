#include "../inc/string.h"

t_ret	page_new(t_page *src, t_size size)
{
	t_ret	ret;

	ret = arr_new(src, size, sizeof(t_str));
	return (ret);
}
