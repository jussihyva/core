#include <stdio.h>
#include <string.h>
#include "../inc/core.h"
#include "../graph/inc/graph.h"

# define CR_GRAPH_NULL (t_graph) {NULL, CR_ARR_NULL}
# define CR_GRAPH_EDGE_NULL (t_graph_edge) {NULL, NULL, NULL}
# define CR_GRAPH_NODE_NULL (t_graph_node) \
			{CR_PARR_NULL, CR_PARR_NULL, NULL}
# define NONE -1
# define NO_ATTR NULL
# define TRUE 1
# define FALSE 0
# define SOURCE -1
# define SINK -2

typedef struct		s_node_attr
{
	char			*name;
	ssize_t			max_capacity;
	ssize_t			curr_capacity;
}					t_node_attr;

typedef struct		s_edge_attr
{
	size_t			dist;
}					t_edge_attr;

ssize_t print_node(void *data, size_t i)
{
	t_graph_node	*tmp;
	t_node_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	printf("%s max[%ld] curr[%ld]\n", attr->name,
			attr->max_capacity, attr->curr_capacity);
	return (i);
}

ssize_t	free_node(void *data, size_t i)
{
	t_graph_node	*tmp;

	tmp = data;
	arr_free(&tmp->in);
	arr_free(&tmp->out);
	return (i);
}
//-----------------------------------------------------------------------------

int main(void)
{
	t_graph g;
	t_arr	bfs;
	t_arr	dfs;
	t_graph_node n;
	t_node_attr na0;
	t_node_attr na1;
	t_node_attr na2;
	t_node_attr na3;
	t_edge_attr ea0;
	t_edge_attr ea1;
	t_edge_attr ea2;
	t_edge_attr ea3;
	ssize_t source;
	ssize_t sink;
	ssize_t room1;
	ssize_t room2;

	graph_new(&g, "Flow Graph");
	graph_add_node(&g, (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, SOURCE, &(t_node_attr) {"S", NONE, NONE}});
	graph_add_node(&g, (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, SINK, &(t_node_attr) {"T", NONE, NONE}});
	graph_add_node(&g, (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, 0, &(t_node_attr) {"R0", 3, 3}});
	graph_add_node(&g, (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, 1, &(t_node_attr) {"R1", 4, 4}});
	graph_add_node(&g, (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, 2, &(t_node_attr) {"R2", 2, 2}});
	graph_add_node(&g, (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, 3, &(t_node_attr) {"R3", 4, 4}});
	graph_add_node(&g, (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, 4, &(t_node_attr) {"R4", 5, 5}});

	graph_add_edge(&g, SOURCE, 0, &(t_edge_attr) {1});
	graph_add_edge(&g, SOURCE, 1, &(t_edge_attr) {1});
	graph_add_edge(&g, SOURCE, 2, &(t_edge_attr) {1});
	graph_add_edge(&g, 0, 3, &(t_edge_attr) {1});
	graph_add_edge(&g, 3, 4, &(t_edge_attr) {1});
	graph_add_edge(&g, 2, 3, &(t_edge_attr) {1});
	graph_add_edge(&g, 2, 4, &(t_edge_attr) {1});
	graph_add_edge(&g, 4, SINK, &(t_edge_attr) {1});

	bfs = arr_new(1, sizeof(t_graph_node));
	graph_find_shortest_path(&bfs, graph_find_node(&g, SOURCE), graph_find_node(&g, SINK));
	printf("\nBreadth First Search\n\n");
	arr_iter(&bfs, print_node);

	dfs = arr_new(1, sizeof(t_graph_node));
	graph_dfs(&dfs, graph_find_node(&g, SOURCE));
	printf("\nDepth First Search\n\n");
	arr_iter(&dfs, print_node);
	arr_iter(&g.nodes, free_node);
	arr_free(&bfs);
	arr_free(&dfs);
	arr_free(&g.nodes);
}
