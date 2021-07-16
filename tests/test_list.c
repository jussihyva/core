#include "inc/core.h"

void lprint(void **data)
{
	print("%s\n", *data);
}

t_ssize	cmp(void *a, void *b)
{
	return (s_cmp(a, b));
}

int	main(void)
{
	char *str = "FIRST NODE";
	char *str2 = "SECOND NODE";
	char *str3 = "THIRD NODE";
	t_list	*lst;

	lst = NULL;
	list_add_last(&lst, str);
	list_add_last(&lst, str2);
	list_add_first(&lst, str3);
	/*char *ret = list_get_first(lst);*/
	/*print("%s\n", ret);*/
	list_sort(&lst, cmp);
	list_iter(lst, lprint);
}
