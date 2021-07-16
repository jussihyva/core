#ifndef digraph_H
# define digraph_H
#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///
/// digraph.h
///
/// \authors Julius Koskela, Satu Koskinen
///
/// \brief Header for directed graph functions.
///
///////////////////////////////////////////////////////////////////////////////

# include <pthread.h>
# include "../../inc/core.h"
# include "digraph_types.h"

///////////////////////////////////////////////////////////////////////////////
///
/// Functions - Graph General
///
///////////////////////////////////////////////////////////////////////////////

t_bool			digraph_new(
					t_digraph *g,
					t_attr_graph *attr);

void			digraph_free(
					t_digraph *src);

t_bool			digraph_add_node(
					t_digraph *dst,
					const char *name,
					t_attr_node *attr);

t_bool			digraph_add_edge(
					t_digraph *dst,
					const char *u_name,
					const char *v_name,
					t_attr_edge *attr);

t_digraph_node	*digraph_find_node(
					t_digraph *src,
					const char *name);

t_digraph_edge	*digraph_find_edge(
					t_digraph *src,
					const char *s_name,
					const char *t_name);

t_bool			digraph_del_node(
					t_digraph *src,
					const char *name);

t_bool			digraph_del_edge(
					t_digraph *src,
					const char *u_name,
					const char *v_name);

t_bool			digraph_collect_nodes(
					t_digraph *src,
					t_digraph_node_set *dst);

t_bool			digraph_collect_edges(
					t_digraph *src,
					t_digraph_edge_set *dst);

t_ssize			digraph_node_reset(
					void *data,
					t_size i);

///////////////////////////////////////////////////////////////////////////////
///
/// Functions - Graph Algorithm
///
///////////////////////////////////////////////////////////////////////////////

t_bool			digraph_depth_first_search(
					t_digraph *src,
					t_digraph_edge_set *dst,
					const char *s_name,
					const char *t_name);

t_bool			digraph_breadth_first_search(
					t_digraph *src,
					t_digraph_edge_set *dst,
					const char *s_name,
					const char *t_name);

t_bool			digraph_breadth_first_search_mt(
					t_digraph *src,
					t_digraph_edge_set *dst,
					const char *s_name,
					const char *t_name);

t_bool			digraph_find_roots(
					t_digraph *src,
					t_digraph_node_set *dst);

t_bool			digraph_find_shortest_path(
					t_digraph *src,
					t_digraph_node_set *dst,
					const char *s_name,
					const char *t_name);

t_bool			digraph_rng_fill(
					t_digraph *src,
					t_size ncount,
					t_size ecount);

///////////////////////////////////////////////////////////////////////////////
///
/// Functions - Graph Transformation
///
///////////////////////////////////////////////////////////////////////////////

t_bool			digraph_to_amat(
					t_digraph *src,
					t_digraph_amat *dst);

///////////////////////////////////////////////////////////////////////////////
///
/// Functions - Node Set
///
///////////////////////////////////////////////////////////////////////////////

t_bool			digraph_new_node_set(
					t_digraph_node_set *n);

void			digraph_clear_node_set(
					t_digraph_node_set *src);

void			digraph_free_node_set(
					t_digraph_node_set *src);

///////////////////////////////////////////////////////////////////////////////
///
/// Functions - Edge Set
///
///////////////////////////////////////////////////////////////////////////////

t_bool			digraph_new_edge_set(
					t_digraph_edge_set *e);

void			digraph_free_edge_set(
					t_digraph_edge_set *src);

t_bool			digraph_edge_set_backtrack(
					t_digraph_edge_set *src,
					t_digraph_node_set *dst,
					const char *t_name,
					t_ssize (*f)(t_digraph_edge *));

t_bool			digraph_collect_inbound_edges(
					t_digraph_node *src,
					t_digraph_edge_set *dst);

t_bool			digraph_collect_outbound_edges(
					t_digraph_node *src,
					t_digraph_edge_set *dst);

void			digraph_clear_edge_set(
					t_digraph_edge_set *src);

///////////////////////////////////////////////////////////////////////////////
///
/// Functions - Adjacency Matrix
///
///////////////////////////////////////////////////////////////////////////////

t_bool			digraph_new_amat(
					t_digraph_amat *m,
					t_size size);

void			digraph_free_amat(
					t_digraph_amat *src);

///////////////////////////////////////////////////////////////////////////////
///
/// Functions - Printing
///
///////////////////////////////////////////////////////////////////////////////

void			digraph_print_amat(
					t_digraph_amat *mat);

void			digraph_print_edge_set_dot(
					t_digraph_edge_set *src);

void			digraph_print_node_set_path(
					t_digraph_node_set *src);

void			digraph_print_node_set_tab(
					t_digraph_node_set *src);

void			digraph_print_node_set(
					t_digraph_node_set *src,
					t_print_type flag);

void			digraph_print_edge_set(
					t_digraph_edge_set *src,
					t_print_type flag);

///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
#endif
