/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/03 02:01:09 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGRAPH_H
# define LIBGRAPH_H
# include "../../inc/core.h"
# include "../../array/inc/arr.h"

typedef struct		s_graph_node
{
	t_arr			in;
	t_arr			out;
	ssize_t			id;
	void			*attr;
}					t_graph_node;

typedef struct		s_graph_edge
{
	t_graph_node	*src;
	t_graph_node	*dst;
	void			*attr;
}					t_graph_edge;

typedef struct		s_graph
{
	char			*name;
	t_arr			nodes;
}					t_graph;

ssize_t			graph_new(t_graph *g, char *name);
ssize_t			graph_add_node(t_graph *g, t_graph_node n);
ssize_t			graph_add_edge(t_graph *g,
				size_t src_index, size_t dst_index, void *attr);
ssize_t			graph_cmp_nodes(const void *n1, const void *n2);
t_graph_node	*graph_find_node(t_graph *g, const ssize_t id);
ssize_t			graph_find_roots(t_graph *g, t_arr *roots);
ssize_t			graph_bfs(t_arr *bfs_queue, t_graph_node *root);
ssize_t			graph_dfs(t_arr *dfs_queue, t_graph_node *root);

#endif
