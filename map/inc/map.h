/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief A hash map implementation library.
 *
 *****************************************************************************/

#ifndef MAP_H
# define MAP_H
# include <string.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_map_node
{
	const char		*key;
	void			*data;
}					t_map_node;

typedef struct s_map
{
	t_map_node		*node;
	size_t			capacity;
	size_t			count;
	double			load_factor;
	uint64_t		(*hash)(const char *);
	uint64_t		(*probe)(uint64_t);
	uint64_t		(*resize)(uint64_t);
}					t_map;

t_map		map_new(void);
ssize_t		map_free(t_map *src);
ssize_t		map_add(t_map *dst, void *src, const char *key);
void		*map_get(t_map *src, const char *key);
ssize_t		map_del(t_map *src, const char *key);
ssize_t		map_grow(t_map *src);
ssize_t		map_null(t_map *src);
ssize_t		map_null_node(t_map_node *n);
uint64_t	map_hash_1(const char *key);
uint64_t	map_probe_quad_pow2(uint64_t x);
uint64_t	map_resize_pow2(uint64_t capacity);
uint64_t	map_probe_linear(uint64_t x);
uint64_t	map_resize_linear(uint64_t capacity);
void		map_print(t_map *m);
void		map_iter(t_map *src, ssize_t (*f)(void *, size_t));
char		*map_parse(t_map *src, void *dst,
				char *(*f)(void *, void *, const char *key));

#endif
