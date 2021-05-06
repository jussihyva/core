#include <stdio.h>
#include <string.h>
#include "../inc/core.h"
#include "../graph/inc/graph.h"

# define NONE -1
# define NO_ATTR NULL
# define TRUE 1
# define FALSE 0
# define SOURCE -1
# define SINK -2

typedef struct		s_node_attr
{
	const char		*name;
}					t_node_attr;

typedef struct		s_edge_attr
{
	size_t			attributes;
}					t_edge_attr;

ssize_t print_edge(void *data, size_t i)
{
	t_graph_edge	*tmp;
	t_node_attr		*src_attr;
	t_node_attr		*dst_attr;

	tmp = data;
	src_attr = tmp->src->attr;
	dst_attr = tmp->dst->attr;
	printf("%-30s=>    %-30s\n", src_attr->name, dst_attr->name);
	return ((ssize_t)i);
}

ssize_t print_node(void *data, size_t i)
{
	t_graph_node	*tmp;
	t_node_attr		*attr;

	tmp = data;
	attr = tmp->attr;
	printf("%s\n", attr->name);
	// printf("In edges:\n");
	// arr_iter(&tmp->in, print_edge);
	// printf("Out edges:\n");
	// arr_iter(&tmp->out, print_edge);
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
	t_graph	g;
	t_arr	breadth_first_search;
	t_arr	depth_first_search;
	t_arr	shortest_path;

	g = graph_new();
	if (graph_null(&g))
		return (0);

	graph_add_node(&g, graph_new_node("00", &(t_node_attr){"Introduction"}));
	graph_add_node(&g, graph_new_node("m00", &(t_node_attr){"Math Introduction"}));
	graph_add_node(&g, graph_new_node("qp01", &(t_node_attr){"Quantum Physics 1"}));
	graph_add_node(&g, graph_new_node("qp02", &(t_node_attr){"Quantum Physics 2"}));
	graph_add_node(&g, graph_new_node("qp03", &(t_node_attr){"Quantum Physics 3"}));
	graph_add_node(&g, graph_new_node("qpc01", &(t_node_attr){"Quantum Chromodynamics 1"}));
	graph_add_node(&g, graph_new_node("qpc02", &(t_node_attr){"Quantum Chromodynamics 2"}));
	graph_add_node(&g, graph_new_node("ch01", &(t_node_attr){"Chemistry 1"}));
	graph_add_node(&g, graph_new_node("ch02", &(t_node_attr){"Chemistry 2"}));
	graph_add_node(&g, graph_new_node("ch03", &(t_node_attr){"Chemistry 3"}));
	graph_add_node(&g, graph_new_node("cs01", &(t_node_attr){"Computer Science 1"}));
	graph_add_node(&g, graph_new_node("cs02", &(t_node_attr){"Computer Science 2"}));
	graph_add_node(&g, graph_new_node("csw01", &(t_node_attr){"Computer Science Workshop 1"}));
	graph_add_node(&g, graph_new_node("csw02", &(t_node_attr){"Computer Science Workshop 2"}));

	graph_add_edge(&g, "00", "m00", NULL);
	graph_add_edge(&g, "m00", "qp01", NULL);
	graph_add_edge(&g, "qp01", "qp02", NULL);
	graph_add_edge(&g, "qp02", "qp03", NULL);
	graph_add_edge(&g, "qp02", "qpc01", NULL);
	graph_add_edge(&g, "qpc01", "qpc02", NULL);
	graph_add_edge(&g, "m00", "ch01", NULL);
	graph_add_edge(&g, "ch01", "ch02", NULL);
	graph_add_edge(&g, "ch02", "ch03", NULL);
	graph_add_edge(&g, "00", "cs01", NULL);
	graph_add_edge(&g, "cs01", "cs02", NULL);
	graph_add_edge(&g, "cs01", "csw01", NULL);
	graph_add_edge(&g, "cs02", "csw02", NULL);

	depth_first_search = graph_dfs(&g, "00", NULL);
	printf("\nDepth First Search\n\n");
	arr_iter(&depth_first_search, print_edge);

	breadth_first_search = graph_bfs(&g, "00", "csw02");
	printf("\nBreadth First Search\n\n");
	arr_iter(&breadth_first_search, print_edge);

	shortest_path = graph_find_shortest_path(&g, "00", "csw02");
	printf("\nFind shortest path [00] => [csw02]\n");
	arr_iter(&shortest_path, print_node);

	arr_free(&breadth_first_search);
	arr_free(&depth_first_search);
	arr_free(&shortest_path);
}
