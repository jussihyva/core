#include "../inc/system.h"
#include "../inc/system_internal.h"

t_mem	core_mem_cpy(t_mem dst, t_mem src, t_size size)
{
	if (size > dst.size)
		dst.data = mem_cpy(dst.data, src.data, dst.size);
	else
		dst.data = mem_cpy(dst.data, src.data, size);
	return (dst);
}

t_mem	core_mem_add(t_mem dst, t_mem src)
{
	t_mem	new;
	t_byte
	new = core_malloc(dst.size + src.size);
	mem_cpy(new.data, src.data, src.size);
	return (dst);
}
