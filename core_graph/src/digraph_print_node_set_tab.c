///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Print nodes tabulated.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

static void	print_tab_node(const void *src)
{
	const t_digraph_node	*node;

	node = src;
	print("| %-7s| %-7llu| %-7llu| %-7d|\n", node->name, node->e_in.len, node->e_out.len, node->valid);
}

void	digraph_print_node_set_tab(t_digraph_node_set *src)
{
	print("| Node   | In     | Out    | Valid  |\n");
	print("|--------|--------|--------|--------|\n");
	parr_foreach(&src->nodes, print_tab_node);
}
