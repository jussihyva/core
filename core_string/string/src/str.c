#include "../../../inc/core.h"

t_str	str(char *str)
{
	t_str	new;
	t_size	len;

	len = s_len(str);
	new = str_new(len);
	new.mem.data = mcpy(new.mem.data, str, len);
	new.mem.data[new.len] = '\0';
	return (new);
}
