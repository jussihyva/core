#include "../inc/list.h"

t_list	*list_new(void *data)
{
	t_list	*out;

	out = malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	out->data = data;
	out->next = NULL;
	return (out);
}
