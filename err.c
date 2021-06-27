



#include "inc/core.h"

#define VALID 1
#define INVALID 0

typedef struct s_info
{
	t_size	size;
	t_byte	*data;
}	t_info;

t_info	info_new(t_size size)
{
	t_info	new;

	new.size = size;
	new.data = malloc(size);
	if (!new.data)
		new.size = 0;
	return (new);
}

t_uint8	check(void *ptr)
{
	t_size	*cast;

	cast = ptr;
	if (*cast == 0)
		return (0);
	return (1);
}

int main(void)
{
	t_info	new;

	new = info_new(0);
	print("sizeof struct = %llu\n", sizeof(t_info));
	if (check(&new) == VALID)
		print("IS VALID\n");
	else
		print("IS INVALID");
}
