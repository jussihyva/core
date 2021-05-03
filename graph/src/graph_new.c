#include "../inc/graph.h"

ssize_t graph_new(t_graph *g, char *name)
{
	g->name = name;
	g->nodes = arr_new(100, sizeof(t_graph_node));
	return (CR_SUCCESS);
}
