/******************************************************************************
 *
 * \authors Satu Koskinen, Julius Koskela
 *
 * \brief Find edge between src and dst
 *
 * \param g Source graph.
 * \param src_name Name of the source node.
 * \param dst_name Name of the destimation node.
 *
 * \return Pointer to the edge found or NULL if no edge was found.
 *
 *****************************************************************************/

#include "../inc/digraph.h"

t_digraph_edge	*digraph_find_edge(
					t_digraph *src,
					const char *src_name,
					const char *dst_name)
{
	t_digraph_node	*node;
	t_digraph_edge	*out;
	t_size	i;

	node = digraph_find_node(src, src_name);
	i = 0;
	while (i < node->e_out.len)
	{
		out = parr_get(&node->e_out, i);
		if (s_cmp(out->v->name, dst_name) == 0)
			return (out);
		i++;
	}
	return (NULL);
}
