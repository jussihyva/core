#ifndef MAP_H
# define MAP_H
#ifdef __cplusplus
# include "map_class.h"
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief A hash map implementation library.
///
///////////////////////////////////////////////////////////////////////////////

# include "../../../inc/types.h"

///////////////////////////////////////////////////////////////////////////////

t_ret		map_new(
				t_map *src,
				t_size capacity,
				t_size method,
				t_uint64 (*hash)(const char *));

void		map_free(
				t_map *src);

t_ret		map_add(
				t_map *dst,
				void *src,
				const char *key);

void		*map_get(
				t_map *src,
				const char *key);

t_ret		map_del(
				t_map *src,
				const char *key);

t_ret		map_grow(
				t_map *src);

t_bool		map_null(
				t_map *src);

t_bool		map_null_node(
				t_map_node *n);

t_uint64	map_hash_fast(
				const char *key);

t_uint64	map_probe_quadratic(
				t_uint64 x);

t_uint64	map_resize_quadratic(
				t_uint64 capacity);

t_uint64	map_probe_linear(
				t_uint64 x);

t_uint64	map_resize_linear(
				t_uint64 capacity);

void		map_print(
				t_map *m);

void		map_iter(
				t_map *src,
				t_ssize (*f)(void *, t_size));

char		*map_parse(
				t_map *src,
				void *dst,
				char *(*f)(void *, void *, const char *key));

///////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
#endif
