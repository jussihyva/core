#include "../../inc/core.h"

void	mem_print(t_mem src)
{
	size_t	i;

	i = 0;
	while (i < src.size - 1)
	{
		if (i % 8 == 0)
			print("\n");
		print("%#03x ", src.data[i]);
		i++;
	}
	if (i % 8 == 0)
			print("\n");
	print("%#03x ", src.data[i]);
}
