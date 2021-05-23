#include "../../../inc/core.h"

t_hstr	hstr_range(t_str src, size_t s, size_t t)
{
	t_raw	raw;

	raw = raw_assign(src.raw.data, src.raw.size);
	return (hraw_range(raw, s, t));
}
