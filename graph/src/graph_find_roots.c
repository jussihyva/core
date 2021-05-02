#include "../inc/graph.h"

ssize_t graph_find_roots(t_graph *g, t_arr *roots)
{
	t_graph_node	*tmp;
	size_t			i;

	i = 0;
	while (i < g->nodes.len)
	{
		tmp = arr_get(&g->nodes, i);
		if (tmp->in.len == 0)
			arr_add_last(roots, tmp);
		i++;
	}
	if (roots->len)
		return (CR_SUCCESS);
	return (CR_FAIL);
}
