#include "../../../inc/core.h"

void	pstr_write(t_hstr str)
{
	if (!(write(1, str.data, str.size)))
		return ;
}