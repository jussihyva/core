#include "../../../inc/core.h"

t_hstr	str_chr(t_str src, char c)
{
	t_hmem	b;

	b = (t_hmem) {(t_byte *)&c, 1};
	return (mem_chr(src.mem, b));
}
