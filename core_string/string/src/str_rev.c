# include "../../../inc/core.h"

void	str_rev(t_str *src)
{
	t_size	half;
	t_size	i;
	t_size	j;

	half = src->len / 2;
	i = 0;
	j = src->len - 1;
	while (i < half)
	{
		mswap(&src->mem.data[i], &src->mem.data[j], sizeof(char));
		i++;
		j--;
	}
}

