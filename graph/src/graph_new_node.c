/*******************************************************************************
 * \brief Create a new graph g
 * \return 1 on success 0 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

t_graph_node *graph_new_node(const char *key, void *attr)
{
	t_graph_node	*n;

	n = (t_graph_node *)malloc(sizeof(t_graph_node));
	n->key = key;
	n->in = arr_new(1, sizeof(t_graph_edge));
	n->out = arr_new(1, sizeof(t_graph_edge));
	if (arr_null(&n->in) || arr_null(&n->out))
		return (NULL);
	n->attr = attr;
	return (n);
}
