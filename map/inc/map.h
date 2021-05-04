/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/04 17:36:38 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMAP_H
# define LIBMAP_H
# include "../../inc/core.h"
# define CR_MAP_START_CAPACITY 4
# define CR_MAP_LOAD_FACTOR 0.4
# define CR_MAP_HASH map_hash_1
# define CR_MAP_PROBE map_probe_quad_pow2
# define CR_MAP_RESIZE map_resize_pow2
# define CR_MAP_NULL_NODE (t_map_node) {NULL, NULL}

// Hash table using quadratic probing.
// Probing function: P(x) = (x^2 + x) / 2
// Map capacity = 2^x
// Max load factor = 0.4

typedef struct		s_map_node
{
	const char		*key;
	void			*data;
}					t_map_node;

typedef struct		s_map
{
	t_map_node		*node;
	size_t			capacity;
	size_t			count;
	double			load_factor;
	uint64_t		(*hash)(const char *);
	uint64_t		(*probe)(uint64_t);
	uint64_t		(*resize)(uint64_t);
}					t_map;

ssize_t		map_add(t_map *dst, void *src, const char *key);
ssize_t		map_get(void *dst, t_map *src, const char *key);
t_map		map_new(void);
ssize_t		map_grow(t_map *src);
ssize_t		map_null_node(t_map_node *n);
uint64_t	map_hash_1(const char *key);
uint64_t	map_probe_quad_pow2(uint64_t x);
uint64_t	map_resize_pow2(uint64_t capacity);

#endif
