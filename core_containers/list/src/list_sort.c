#include "../inc/list.h"

static t_list	*list_sort_merge(
		t_list *a,
		t_list *b,
		t_ssize (*f)(void *, void *))
{
    t_list	*result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
    if (f(a->data, b->data) > 0)
	{
        result = a;
        result->next = list_sort_merge(a->next, b, f);
    }
    else
	{
        result = b;
        result->next = list_sort_merge(a, b->next, f);
    }
    return (result);
}

static void list_sort_split(
		t_list *src,
		t_list **a,
		t_list **b)
{
    t_list *fast;
    t_list *slow;

	slow = src;
    fast = src->next;
    while (fast != NULL)
	{
        fast = fast->next;
        if (fast != NULL)
		{
            slow = slow->next;
            fast = fast->next;
        }
    }
    *a = src;
    *b = slow->next;
    slow->next = NULL;
}

void list_sort(
		t_list **src,
		t_ssize (*f)(void *, void *))
{
    t_list *head = *src;
    t_list *a;
    t_list *b;

    if ((head == NULL) || (head->next == NULL))
        return ;

    list_sort_split(head, &a, &b);
    list_sort(&a, f);
    list_sort(&b, f);
    *src = list_sort_merge(a, b, f);
}
