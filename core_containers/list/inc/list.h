#ifndef LIST_H
# define LIST_H

#include "../../../inc/types.h"
#include "../../../inc/stdinc.h"
#include "../../../inc/const.h"

t_list	*list_new(void *data);

t_ret	list_add_last(
			t_list **src,
			void *data);

t_ret	list_add_first(
			t_list **src,
			void *data);

void	*list_get_last(t_list *src);

void	*list_get_first(t_list *src);

void	list_iter(
			t_list *src,
			void (*f)(void **data));

void	list_sort(
			t_list **src,
			t_ssize (*f)(void *, void *));

#endif