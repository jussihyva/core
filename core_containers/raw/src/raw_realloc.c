#include "../../../inc/core.h"

t_ret	raw_realloc(t_raw *m, t_size new_size)
{
	m-> data = realloc(m->data, new_size);
	if (!m->data)
		return (CR_MALLOC_FAIL);
	return (CR_SUCCESS);
}
