#include "../../../inc/core.h"

t_ret	raw_realloc(t_raw *m, t_size new_size)
{
	t_raw	new;

	raw_new(&new, new_size);
	if (new_size < m->size)
		mcpy(new.data, m->data, new_size);
	else
		mcpy(new.data, m->data, m->size);
	raw_free(m);
	*m = new;
	return (new.size);
}
