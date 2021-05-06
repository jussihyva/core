/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief A hash map implementation library.
 *
 ******************************************************************************/

#ifndef LIBMAP_H
# define LIBMAP_H

# include <string.h>
# include <inttypes.h>

typedef struct		s_map_node
{
	const char		*key;
	void			*data;
}					t_map_node;

/**
 * \struct A has map structure
 */
typedef struct		s_map
{
	/*@{*/
	t_map_node		*node; /**< Memory to hold map nodes.*/
	size_t			capacity; /**< Current max capacity of the hash map.*/
	size_t			count; /**< Current node count of the hash map.*/
	double			load_factor; /**< Load factor to indicate at which treshold to resize.*/
	uint64_t		(*hash)(const char *); /**< A hash function*/
	uint64_t		(*probe)(uint64_t); /**< Quadratic probing founction*/
	uint64_t		(*resize)(uint64_t); /**< Resizing function.*/
	/*@}*/
}					t_map;

t_map		map_new(void);
ssize_t		map_add(t_map *dst, void *src, const char *key);
void		*map_get(t_map *src, const char *key);
ssize_t		map_del(t_map *src, const char *key);
ssize_t		map_grow(t_map *src);
ssize_t		map_null(t_map *src);
ssize_t		map_null_node(t_map_node *n);
uint64_t	map_hash_1(const char *key);
uint64_t	map_probe_quad_pow2(uint64_t x);
uint64_t	map_resize_pow2(uint64_t capacity);
void		map_print(t_map *m);

#endif
