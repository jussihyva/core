#include "../inc/graph.h"

t_graph_node	*graph_find_node(t_graph *g, const ssize_t id)
{
	t_graph_node	*tmp;
	size_t	i;

	i = 0;
	while (i < g->nodes.len)
	{
		tmp = arr_get(&g->nodes, i);
		if (tmp->id == id)
			return (tmp);
		i++;
	}
	return (NULL);
}
