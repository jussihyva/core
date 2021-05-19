#include "../../inc/core.h"

void	str_write(t_str str)
{
	if (!(write(1, str.mem.data, str.len)))
		return ;
}
