#include <stdio.h>
#include <string.h>
#include "../inc/core.h"

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
	na0 = (t_node_attr) {"S", NONE, NONE};
	n = (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, SOURCE, &na0};
	source = graph_add_node(&g, n);
	na1 = (t_node_attr) {"T", NONE, NONE};
	n = (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, SINK, &na1};
	sink = graph_add_node(&g, n);
	na2 = (t_node_attr) {"R0", 3, 3};
	n = (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, 0, &na2};
	room1 = graph_add_node(&g, n);
	na3 = (t_node_attr) {"R1", 4, 4};
	n = (t_graph_node) {CR_ARR_NULL, CR_ARR_NULL, 1, &na3};
	room2 = graph_add_node(&g, n);

	ea0 = (t_edge_attr) {1};
	graph_add_edge(&g, source, room1, &ea0);
	ea1 = (t_edge_attr) {1};
	graph_add_edge(&g, source, room2, &ea1);
	ea2 = (t_edge_attr) {1};
	graph_add_edge(&g, room2, sink, &ea2);
	ea3 = (t_edge_attr) {1};
	graph_add_edge(&g, room1, sink, &ea3);

	bfs = arr_new(1, sizeof(t_graph_node));
	graph_bfs(&bfs, graph_find_node(&g, SOURCE));
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
