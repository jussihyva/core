/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/16 03:13:55 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "../../str/inc/str.h"
# define MAP_STOP -1
# define MAP_CONT 1
# define MAP_FAIL 0
# define MAP_SUCCESS 1
# define MAP_WRITE 0
# define MAP_APPEND 1
# define MAP_PREPEND -1
# define MAP_STRING NULL

typedef struct	s_map
{
	void		**data;
	size_t		len;
	size_t		size;
}				t_map;

/*
**	---------------------------------------------------------------------------
**
**	General
*/

t_map			map_new(size_t size);
int				map_free(t_map *arr);
int				map_grow(t_map *arr, size_t new_size);
int				map_null(t_map *arr);

/*
**	---------------------------------------------------------------------------
**
**	Add or delete member(s)
*/

int				map_add(t_map *arr, void *node, size_t index);
int				map_add_first(t_map *arr, void *node);
int				map_add_last(t_map *arr, void *node);
int				map_add_mult(t_map *arr, size_t len, ...);
int				map_assign(t_map *dst, void **src, size_t size);
int				map_del(t_map *arr, size_t index);
int				map_del_first(t_map *arr);
int				map_del_last(t_map *arr);

/*
**	---------------------------------------------------------------------------
**
**	Get or take a member
*/

void			*map_get(t_map *arr, size_t index);
void			*map_get_first(t_map *arr);
void			*map_get_last(t_map *arr);
void			*map_take(t_map *arr, size_t index);
void			*map_take_first(t_map *arr);
void			*map_take_last(t_map *arr);

/*
**	---------------------------------------------------------------------------
**
**	Manipulation
*/

int				map_copy(t_map *dst, t_map *src);
int				map_join(t_map *dst, size_t len, ...);
int				map_split(t_map *dst, t_map *src);
int				map_rotate(t_map *arr, ssize_t steps);

/*
**	---------------------------------------------------------------------------
**
**	Templates
*/

int				map_dup(t_map *dst, t_map *src, size_t size);
int				map_read_file(t_map *dst, char *filename);
int				map_write_file(char *dst, t_map *src, ssize_t flag,
				int (*f)(void **, void *));
int				map_write(t_map *dst, t_map *src,
				int (*f)(void **, void *));
int				map_search(t_map *dst, t_map *src, void *key,
				void *(*f)(void *, void *));
void			*map_find(t_map *src, void *key,
				void *(*f)(void *, void *));
int				map_iterate(t_map *arr,
				int (*f)(void **, size_t));
int				map_parse(t_map *dst, t_map *src,
				int (*f)(t_map *, void *));

#endif
