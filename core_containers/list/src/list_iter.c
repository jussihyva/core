#include "../inc/list.h"

void	list_iter(
		t_list *src,
		void (*f)(void **data))
{
	while (src)
	{
		f(&src->data);
		src = src->next;
	}
}
