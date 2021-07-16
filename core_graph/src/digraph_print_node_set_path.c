///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Print nodes tabulated.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

void	digraph_print_node_set_path(
		t_digraph_node_set *src)
{
	t_digraph_node	*v;
	t_size		i;

	i = 0;
	while (i < src->nodes.len - 1)
	{
		v = parr_get(&src->nodes, i);
		print("%s -> ", v->name);
		i++;
	}
	v = parr_get(&src->nodes, i);
	print("%s\n", v->name);
}
