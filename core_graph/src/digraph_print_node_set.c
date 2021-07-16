///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Print nodes tabulated.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

void	digraph_print_node_set(
		t_digraph_node_set *src,
		t_print_type flag)
{
	if (flag == PATH)
		digraph_print_node_set_path(src);
	else if (flag == TAB)
		digraph_print_node_set_tab(src);
}