#include "../../../inc/core.h"

t_pstr	str_chr(t_str src, t_pstr b)
{
	return (mem_chr(src.mem, b));
}
