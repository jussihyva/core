///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Print an adjacency matrix.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

static void	print_amat_header(t_digraph_node_set *all)
{
	t_digraph_node	*v;
	t_size		i;

	print("| A   |");
	i = 0;
	while (i < all->nodes.len)
	{
		v = parr_get(&all->nodes, i);
		print(" %-3s |", v->name);
		i++;
	}
	print("\n");
}

static void print_amat_divider(t_digraph_node_set *nodes)
{
	t_size		i;

	i = 0;
	while (i < nodes->nodes.len + 1)
	{
		print("|-----");
		i++;
	}
	print("|\n");
}

void	digraph_print_amat(t_digraph_amat *mat)
{
	t_digraph_node	*v;
	t_size		i;
	t_size		j;

	print_amat_header(&mat->all);
	print_amat_divider(&mat->all);
	i = 0;
	while (i < mat->size)
	{
		v = parr_get(&mat->all.nodes, i);
		print("| %-3s |", v->name);
		j = 0;
		while (j < mat->size)
		{
			print(" %d   |", mat->matrix[i * mat->size + j]);
			j++;
		}
		print("\n");
		i++;
	}
}
