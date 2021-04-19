/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:58:10 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBARR_H
# define LIBARR_H
# include "../../inc/core.h"

typedef struct	s_arr
{
	uint8_t		*data;
	size_t		count;
	size_t		size;
	size_t		memsize;
}				t_arr;

/*
**	---------------------------------------------------------------------------
**
**	General
*/

t_arr			arr_new(size_t arrsize, size_t memsize);
ssize_t			arr_free(t_arr *src);
ssize_t			arr_grow(t_arr *src, size_t newsize);
ssize_t			arr_null(t_arr *src);

/*
**	---------------------------------------------------------------------------
**
**	Add or delete member(s)
*/

ssize_t			arr_add(t_arr *src, void *node, size_t index);
ssize_t			arr_add_first(t_arr *src, void *node);
ssize_t			arr_add_last(t_arr *src, void *node);
ssize_t			arr_add_mult(t_arr *src, size_t count, ...);
ssize_t			arr_put(t_arr *dst, void *src, size_t size);
ssize_t			arr_del(t_arr *src, size_t index);
ssize_t			arr_del_first(t_arr *src);
ssize_t			arr_del_last(t_arr *src);
ssize_t			arr_find(t_arr *src, void *key);
ssize_t			arr_search(t_arr *src, t_arr *key);

/*
**	---------------------------------------------------------------------------
**
**	Get or take a member
*/

void			*arr_get(t_arr *src, size_t index);
void			*arr_get_first(t_arr *src);
void			*arr_get_last(t_arr *src);
void			*arr_take(void *dst, t_arr *src, size_t index);
void			*arr_take_first(void *dst, t_arr *src);
void			*arr_take_last(void *dst, t_arr *src);

/*
**	---------------------------------------------------------------------------
**
**	Manipulation
*/

ssize_t			arr_copy(t_arr *dst, t_arr *src);
ssize_t			arr_join(t_arr *dst, size_t count, ...);
ssize_t			arr_rotate(t_arr *arr, ssize_t steps);

/*
**	---------------------------------------------------------------------------
**
**	Templates
*/

ssize_t			arr_read_file(t_arr *dst, char *filename);
ssize_t			arr_iter(t_arr *src,
				ssize_t (*f)(void *, size_t));
ssize_t			arr_iter_range(t_arr *src, size_t start, size_t end,
				ssize_t (*f)(void *, size_t));
ssize_t			arr_parse(t_arr *dst, t_arr *src,
				ssize_t (*f)(t_arr *, void *));

#endif
