#ifndef digraph_TYPES_H
# define digraph_TYPES_H
#ifdef __cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///
/// digraph_types.h
///
/// \authors Julius Koskela, Satu Koskinen
///
/// \brief Header for directed graph typedefs.
///
///////////////////////////////////////////////////////////////////////////////

# include <pthread.h>
# include "../../inc/core.h"

///////////////////////////////////////////////////////////////////////////////
///
/// Typedef - Enums
///
///////////////////////////////////////////////////////////////////////////////

typedef enum e_print_type
{
	PATH,
	TAB,
	DOT
}	t_print_type;

typedef enum e_contexts
{
	EDGE,
	NODE,
	GRAPH,
	SUBGRAPH,
	CLUSTER
}	t_contexts;

///////////////////////////////////////////////////////////////////////////////
///
/// Typedef - Attributes
///
///////////////////////////////////////////////////////////////////////////////

typedef struct s_attr
{
	const char	*type;
	const char	*value;
}	t_attr;

typedef struct s_attr_graph
{
	const char	*label;
	t_uint32	colour;
}	t_attr_graph;

typedef struct s_attr_node
{
	const char	*label;
	t_uint32	colour;
	t_int64		capacity;
	t_int64		value;
}	t_attr_node;

typedef struct s_attr_edge
{
	const char	*label;
	t_uint32	colour;
	t_int64		capacity;
	t_int64		value;
}	t_attr_edge;

///////////////////////////////////////////////////////////////////////////////
///
/// Typedef - Sets
///
///////////////////////////////////////////////////////////////////////////////

typedef struct s_digraph_node_set
{
	t_parray	nodes;
}	t_digraph_node_set;

typedef struct s_digraph_edge_set
{
	t_parray	edges;
}	t_digraph_edge_set;

///////////////////////////////////////////////////////////////////////////////
///
/// Typedef - Adjaceny Matrix
///
///////////////////////////////////////////////////////////////////////////////

typedef struct s_digraph_amat
{
	t_digraph_node_set	all;
	t_bool				*matrix;
	t_size				size;
}	t_digraph_amat;

///////////////////////////////////////////////////////////////////////////////
///
/// Typedef - Directed Graph
///
///////////////////////////////////////////////////////////////////////////////

typedef struct s_digraph_node
{
	const char		*name;
	t_parray		e_in;
	t_parray		e_out;
	t_bool			valid;
	t_attr_node		*attr;
}	t_digraph_node;

typedef struct s_digraph_edge
{
	t_digraph_node	*u;
	t_digraph_node	*v;
	t_bool			valid;
	t_attr_edge		*attr;
}	t_digraph_edge;

typedef struct s_digraph
{
	t_map			nodes;
	t_size			ncount;
	t_size			ecount;
	t_attr_graph	*attr;
}	t_digraph;

///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
#endif
