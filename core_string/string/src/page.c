# include "../../../inc/core.h"

t_page	page(t_size size)
{
	t_page	new;

	new = arr(size, sizeof(t_str));
	return (new);
}

