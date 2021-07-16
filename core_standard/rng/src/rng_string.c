#include "../inc/rng.h"

void	rng_string(char *dst, t_size len)
{
	t_size	i;

	i = 0;
	while(i < len + 1)
	{
		dst[i] = (char)rng_range('A', 'X');
		i++;
	}
	dst[i] = '\0';
}
