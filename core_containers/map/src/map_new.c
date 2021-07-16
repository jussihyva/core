///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Create a new hash map.
///
/// Input capacity might be bigger than what given as parameter since hash
/// map needs to conform to different resizing divisions depending on
/// resizing methods.
///
/// Available resizing methods:
///
/// Linear
/// Quadratic
///
/// \param src Hash map to be allocated.
/// \param capacity Starting capacity
///
///////////////////////////////////////////////////////////////////////////////

#include "../../../inc/core.h"

static void	map_set_params(
		t_map *src,
		t_size capacity,
		t_size method,
		t_uint64 (*hash)(const char *))
{
	if (method == CR_MAP_LINEAR)
	{
		src->probe = map_probe_linear;
		src->resize = map_resize_linear;
		src->load_factor = 0.4;
	}
	else if (method == CR_MAP_QUADRATIC)
	{
		src->probe = map_probe_quadratic;
		src->resize = map_probe_quadratic;
		src->load_factor = 0.4;
	}
	src->hash = hash;
	src->capacity = src->probe(capacity);
}

t_ret	map_new(
	t_map *src,
	t_size capacity,
	t_size method,
	t_uint64 (*hash)(const char *))
{
	t_size	i;

	map_set_params(src, capacity, method, hash);
	src->node = (t_map_node *)minit(sizeof(t_map_node) * src->capacity);
	if (!src->node)
	{
		*src = (t_map){NULL, 0, 0, 0.0, NULL, NULL, NULL};
		return (CR_ERROR_MALLOC);
	}
	i = 0;
	while (i < src->capacity)
	{
		src->node[i] = (t_map_node){NULL, NULL, FALSE};
		i++;
	}
	src->count = 0;
	return (CR_SUCCESS);
}
