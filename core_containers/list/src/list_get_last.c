#include "../inc/list.h"

void	*list_get_last(t_list *src)
{
	if (!src->next)
		return (src->data);
	return (list_get_last(src->next));
}
