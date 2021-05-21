# include "../../../inc/core.h"

void	str_free(t_str *str)
{
	mem_free(&str->mem);
	str->len = 0;
}

