#include "../inc/graph.h"

ssize_t	graph_node_valid(void *data, size_t i)
{
	t_graph_node *n;

	n = data;
	n->valid = 1;
	return ((ssize_t)i);
}