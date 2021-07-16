#include "../inc/list.h"

t_ret	list_add_first(
		t_list **src,
		void *data)
{
	t_list	*ptr;

	ptr = list_new(data);
	if (!ptr)
		return (CR_ERROR_MALLOC);
	ptr->next = *src;
	*src = ptr;
	return (CR_SUCCESS);
}
