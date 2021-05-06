/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/06 04:28:50 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H
# include "../../inc/core.h"
# include "../../array/inc/arr.h"
# define SOURCE -1
# define SINK -2

typedef struct		s_graph_node
{
	t_array			in;
	t_array			out;
	const char		*key;
	void			*attr;
}					t_graph_node;

typedef struct		s_graph_edge
{
	t_graph_node	*src;
	t_graph_node	*dst;
	void			*attr;
}					t_graph_edge;

typedef t_map t_graph;

t_graph			graph_new(void);
ssize_t			graph_null(t_graph *g);
t_graph_node 	*graph_new_node(const char *key, void *attr);
ssize_t			graph_add_node(t_graph *g, t_graph_node *n);
ssize_t			graph_add_edge(t_graph *g, const char *src_key, const char *dst_key, void *attr);
ssize_t			graph_cmp_nodes(const void *n1, const void *n2);
t_graph_node	*graph_find_node(t_graph *g, const char *key);
ssize_t			graph_find_roots(t_graph *g, t_array *roots);
t_array			graph_bfs(t_graph *g, const char *src_key, const char *dst_key);
t_array			graph_dfs(t_graph *g, const char *src_key, const char *dst_key);
t_array 			graph_find_shortest_path(t_graph *g, const char *src_key, const char *dst_key);
ssize_t			graph_edge_backtrack(t_array *breadcrumbs, t_array *edge_list);

#endif
