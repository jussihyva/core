/**
 *
 * \authors Julius Koskela
 *
 * \brief A graph implementation.
 *
 */

#ifndef GRAPH_H
# define GRAPH_H
# include "../../inc/core.h"

typedef t_map		t_graph;
typedef t_array		t_edges;
typedef t_array		t_nodes;

typedef struct		s_graph_node
{
	const char		*key;
	t_edges			in;
	t_edges			out;
	uint8_t			valid : 1;
	void			*attr;
}					t_graph_node;

typedef struct		s_graph_edge
{
	t_graph_node	*u;
	t_graph_node	*v;
	uint8_t			valid : 1;
	void			*attr;
}					t_graph_edge;

t_graph			graph_new();
ssize_t			graph_add_node(t_graph *g, const char *key, void *attr);
t_graph_node	*graph_find_node(t_graph *g, const char *key);
ssize_t			graph_add_edge(t_graph *g, const char *s_key,
					const char *t_key, void *attr);
ssize_t			graph_cmp_nodes(const void *n1, const void *n2);
ssize_t			graph_find_roots(t_graph *g, t_array *roots);
t_edges			graph_bfs(t_graph *g, const char *s_key, const char *t_key);
t_edges			graph_dfs(t_graph *g, const char *s_key, const char *t_key);
t_nodes			graph_find_shortest_path(t_graph *g,
					const char *s_key, const char *t_key);
ssize_t			graph_edge_backtrack(t_array *breadcrumbs, t_array *edge_list);
ssize_t			graph_null(t_graph *g);
t_graph_edge	*graph_find_edge(t_graph *g,
					const char *s_key, const char *t_key);
ssize_t			graph_node_valid(void *data, size_t i);

#endif
