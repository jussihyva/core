///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Free a directed graph.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

void	free_node(const void *data)
{
	t_digraph_node	*ptr;

	ptr = (t_digraph_node *)data;
	parr_free(&ptr->e_in);
	parr_free(&ptr->e_out);
	free((char *)ptr->name);
	free(ptr);
}

void	free_edge(const void *data)
{
	t_digraph_edge	*ptr;

	ptr = (t_digraph_edge *)data;
	free(ptr);
}

void	digraph_free(t_digraph *src)
{
	t_digraph_node_set	destroy_n;
	t_digraph_edge_set	destroy_e;

	digraph_new_node_set(&destroy_n);
	digraph_new_edge_set(&destroy_e);
	digraph_collect_nodes(src, &destroy_n);
	digraph_collect_edges(src, &destroy_e);
	parr_foreach(&destroy_n.nodes, free_node);
	parr_foreach(&destroy_e.edges, free_edge);
	map_free(&src->nodes);
	digraph_free_node_set(&destroy_n);
	digraph_free_edge_set(&destroy_e);
}
