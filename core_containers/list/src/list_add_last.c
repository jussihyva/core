#include "../inc/list.h"

t_ret	list_add_last(t_list **src, void *data)
{
	t_list	*ptr;

	ptr = *src;
	if (*src == NULL)
	{
		*src = list_new(data);
		if (*src == NULL)
			return (CR_ERROR_MALLOC);
	}
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = list_new(data);
	}
	return (CR_SUCCESS);
}
