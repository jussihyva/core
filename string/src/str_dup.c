#include "../../inc/core.h"

t_str	str_dup(const char *src)
{
	t_str	new;

	new = str_new(s_len(src));
	s_cpy(new, src);
	return(new);
}
