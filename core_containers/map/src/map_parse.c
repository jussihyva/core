///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Special iterator context parse.
///
/// Return NULL from f to stop iteration.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/map.h"
#include "../../../inc/core.h"

char	*map_parse(
	t_map *src,
	void *dst,
	char *(*f)(void *, void *, const char *key))
{
	t_map_node	node;
	t_size		i;

	i = 0;
	while (i < src->capacity)
	{
		if (!map_null_node(&src->node[i]))
		{
			node = src->node[i];
			if (!(f(dst, node.data, node.key)))
				return ((char *)node.key);
		}
		i++;
	}
	node = src->node[i - 1];
	return ((char *)node.key);
}
